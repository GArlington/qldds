/*
   Copyright (C) 2013 Mike Kipnis

   This file is part of QLDDS, a free-software/open-source library
   for utilization of QuantLib in the distributed envrionment via DDS.

   QLDDS is free software: you can redistribute it and/or modify it
   under the terms of the QLDDS license.  You should have received a
   copy of the license along with this program; if not, please email
   <dev@qldds.org>. The license is also available online at
   <http://qldds.org/qldds-license/>.

   This program is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the license for more details.
*/


#include <BasicDomainParticipant.h>
#include <ace/Get_Opt.h>

#include <NamingServiceUtils.h>

#include "SwaptionServerC.h"

#include "Common.h"

int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  try {

    DDS::DomainParticipantFactory_var dpf = DDS::DomainParticipantFactory::_nil();
    DDS::DomainParticipant_var participant = DDS::DomainParticipant::_nil();

    CORBA::ORB_var orb = CORBA::ORB_init(argc, argv, "SwaptionServerORB");

    // Initialize, and create a DomainParticipant
    dpf = TheParticipantFactoryWithArgs(argc, argv);

    qldds_utils::BasicDomainParticipant volPublisher( dpf, SWAPTION_DOMAIN_ID );
    volPublisher.createPublisher();

    // CORBA Client to facilitate calculator calls
    qldds_utils::NamingService::Client< SwaptionServer::SwaptionCalculator > ns_client1;
    ns_client1.Init( orb, "SwaptionServer1");

    qldds_utils::NamingService::Client< SwaptionServer::SwaptionCalculator > ns_client2;
    ns_client2.Init( orb, "SwaptionServer2");

    ACE_Get_Opt cmd_opts( argc, argv, ":c:" ); 

    int option;
    
    std::vector<std::string> curve_components;

    while ( (option = cmd_opts()) != EOF )
    {
      switch( option )
      { 
        case 'c' :

         std::istringstream f( cmd_opts.opt_arg() );
         std::string s;

         while (std::getline(f, s, '|')) {
           curve_components.push_back(s);
         }

        break;
      }
    } 

	CORBA::StringSeq curve;
    curve.length( curve_components.size() ); 
    
    // Copy curve from std::vector to CORBA string array
    for ( int cc = 0; cc < curve_components.size(); cc++ ) 
    {
      std::cout <<  curve_components[cc] << std::endl;
      curve[cc] = CORBA::string_dup( curve_components[cc].c_str() );
    }

    // for ( int tt = 0; tt<10; tt++ )
    {
      SwaptionServer::Swaption ss;
      CORBA::Double npv;
      CORBA::Double rate;
      CORBA::String_var error;

      ss.curve_components = curve;

      ss.surface_name = CORBA::string_dup( "SwaptionVTSMatrix" );
 
      for ( int month = 1; month<=12; month++ )
      {
        for ( int year = 1; year<=15; year++ )
        {
          std::stringstream swaption_tenor;
          swaption_tenor << month << "M";

          std::stringstream swap_tenor;
          swap_tenor << year << "Y";

          ss.option_period = CORBA::string_dup( swaption_tenor.str().c_str() );
          ss.swap_period = CORBA::string_dup( swap_tenor.str().c_str() );

          bool status;

	  // Round Robin between servers
          if ( (month+year)%2 == 0 )
             status = ns_client1->CalculateATM( ss, npv, rate, error );
          else
             status = ns_client2->CalculateATM( ss, npv, rate, error );
 
          if ( status )
          {
            std::string swaption;
            swaption = swaption_tenor.str();
            swaption += "/"; 
            swaption += swap_tenor.str(); 

            std::cout << "Swaption : " 
                    << std::setprecision(5)  
                    << std::setw(10) << swaption << " | "
                    << std::setw(10) << "NPV=" << std::setw(10) << npv << " | "
                    << std::setw(10) << "Swap Rate=" << std::setw(10) << rate << std::endl;
          }
        }
      }
    }

    std::cout << "Done." << std::endl;

    orb->destroy ();

  } catch (CORBA::Exception& e) {
    e._tao_print_exception("CORBA Exception caught in main():");
    return 0;
  } catch (...)
  {
    std::cerr << "Exception caught in main():" << std::endl;
    return 0;
  }

  TheServiceParticipant->shutdown(); 

  return 0;
}
