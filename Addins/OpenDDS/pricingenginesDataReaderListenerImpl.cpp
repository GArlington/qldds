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
// This file was generated automatically by qldds_gensrc.py.  If you edit this file
// manually then your changes will be lost the next time gensrc runs.

// This source code file was generated from the following stub:
//      Users/mkipnis/Dev/qldds/gensrc/stubs/stub.opendds.body

#include "pricingenginesDataReaderListenerImpl.hpp"

#include <qldds_convert_utils.h>

namespace pricingengines {

void qlAnalyticCapFloorEngineDataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlAnalyticCapFloorEngineDataReader_var obj_dr
     = pricingengines::qlAnalyticCapFloorEngineDataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlAnalyticCapFloorEngineDataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlAnalyticCapFloorEngine obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlAnalyticCapFloorEngine ( 
              obj.ObjectId.in(),
              obj.HandleModel.in(),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlAnalyticCapFloorEngine: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlAnalyticCapFloorEngineDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlAnalyticCapFloorEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlAnalyticCapFloorEngineDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlAnalyticCapFloorEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlAnalyticCapFloorEngineDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlAnalyticCapFloorEngineDataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlAnalyticCapFloorEngineDataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlAnalyticCapFloorEngineDataReaderListenerImpl::on_subscription_matched\n")));
}

void qlAnalyticCapFloorEngineDataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlAnalyticCapFloorEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlAnalyticCapFloorEngineDataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlAnalyticCapFloorEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlAnalyticCapFloorEngineDataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlAnalyticCapFloorEngineDataReaderListenerImpl::on_reading_start\n")));
}

void qlAnalyticCapFloorEngineDataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlAnalyticCapFloorEngineDataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlAnalyticCapFloorEngineDataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlAnalyticCapFloorEngine& )
{
  return true;
}

bool qlAnalyticCapFloorEngineDataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlAnalyticCapFloorEngine&, std::string& )
{
  return true;
}

void qlAnalyticCapFloorEngineDataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlAnalyticCapFloorEngine&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlAnalyticCapFloorEngineDataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlAnalyticCapFloorEngineDataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlAnalyticCapFloorEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlAnalyticCapFloorEngineDataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlAnalyticCapFloorEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlBinomialPricingEngineDataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlBinomialPricingEngineDataReader_var obj_dr
     = pricingengines::qlBinomialPricingEngineDataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlBinomialPricingEngineDataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlBinomialPricingEngine obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlBinomialPricingEngine ( 
              obj.ObjectId.in(),
              obj.EngineID.in(),
              obj.ProcessID.in(),
              static_cast<long>(obj.TimeSteps),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlBinomialPricingEngine: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlBinomialPricingEngineDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBinomialPricingEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBinomialPricingEngineDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBinomialPricingEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBinomialPricingEngineDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBinomialPricingEngineDataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlBinomialPricingEngineDataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBinomialPricingEngineDataReaderListenerImpl::on_subscription_matched\n")));
}

void qlBinomialPricingEngineDataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBinomialPricingEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBinomialPricingEngineDataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBinomialPricingEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBinomialPricingEngineDataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBinomialPricingEngineDataReaderListenerImpl::on_reading_start\n")));
}

void qlBinomialPricingEngineDataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBinomialPricingEngineDataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlBinomialPricingEngineDataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlBinomialPricingEngine& )
{
  return true;
}

bool qlBinomialPricingEngineDataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlBinomialPricingEngine&, std::string& )
{
  return true;
}

void qlBinomialPricingEngineDataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlBinomialPricingEngine&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBinomialPricingEngineDataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlBinomialPricingEngineDataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBinomialPricingEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlBinomialPricingEngineDataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBinomialPricingEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlBlackCalculatorDataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlBlackCalculatorDataReader_var obj_dr
     = pricingengines::qlBlackCalculatorDataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlBlackCalculatorDataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlBlackCalculator obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlBlackCalculator ( 
              obj.ObjectId.in(),
              obj.OptionType.in(),
              static_cast<double>(obj.Strike),
              static_cast<double>(obj.AtmForwardValue),
              static_cast<double>(obj.StdDev),
              static_cast<double>(obj.Deflator),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlBlackCalculator: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlBlackCalculatorDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculatorDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackCalculatorDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculatorDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackCalculatorDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculatorDataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlBlackCalculatorDataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculatorDataReaderListenerImpl::on_subscription_matched\n")));
}

void qlBlackCalculatorDataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculatorDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackCalculatorDataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculatorDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackCalculatorDataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackCalculatorDataReaderListenerImpl::on_reading_start\n")));
}

void qlBlackCalculatorDataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackCalculatorDataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlBlackCalculatorDataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlBlackCalculator& )
{
  return true;
}

bool qlBlackCalculatorDataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlBlackCalculator&, std::string& )
{
  return true;
}

void qlBlackCalculatorDataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlBlackCalculator&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculatorDataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlBlackCalculatorDataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculatorDataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlBlackCalculatorDataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculatorDataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlBlackCalculator2DataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlBlackCalculator2DataReader_var obj_dr
     = pricingengines::qlBlackCalculator2DataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlBlackCalculator2DataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlBlackCalculator2 obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlBlackCalculator2 ( 
              obj.ObjectId.in(),
              obj.PayoffID.in(),
              static_cast<double>(obj.AtmForwardValue),
              static_cast<double>(obj.StdDev),
              static_cast<double>(obj.Deflator),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlBlackCalculator2: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlBlackCalculator2DataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculator2DataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackCalculator2DataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculator2DataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackCalculator2DataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculator2DataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlBlackCalculator2DataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculator2DataReaderListenerImpl::on_subscription_matched\n")));
}

void qlBlackCalculator2DataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculator2DataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackCalculator2DataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculator2DataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackCalculator2DataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackCalculator2DataReaderListenerImpl::on_reading_start\n")));
}

void qlBlackCalculator2DataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackCalculator2DataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlBlackCalculator2DataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlBlackCalculator2& )
{
  return true;
}

bool qlBlackCalculator2DataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlBlackCalculator2&, std::string& )
{
  return true;
}

void qlBlackCalculator2DataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlBlackCalculator2&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculator2DataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlBlackCalculator2DataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculator2DataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlBlackCalculator2DataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCalculator2DataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlBlackCapFloorEngineDataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlBlackCapFloorEngineDataReader_var obj_dr
     = pricingengines::qlBlackCapFloorEngineDataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlBlackCapFloorEngineDataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlBlackCapFloorEngine obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlBlackCapFloorEngine ( 
              obj.ObjectId.in(),
              obj.YieldCurve.in(),
              obj.VolTS.in(),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlBlackCapFloorEngine: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlBlackCapFloorEngineDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackCapFloorEngineDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackCapFloorEngineDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngineDataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlBlackCapFloorEngineDataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngineDataReaderListenerImpl::on_subscription_matched\n")));
}

void qlBlackCapFloorEngineDataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackCapFloorEngineDataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackCapFloorEngineDataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackCapFloorEngineDataReaderListenerImpl::on_reading_start\n")));
}

void qlBlackCapFloorEngineDataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackCapFloorEngineDataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlBlackCapFloorEngineDataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlBlackCapFloorEngine& )
{
  return true;
}

bool qlBlackCapFloorEngineDataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlBlackCapFloorEngine&, std::string& )
{
  return true;
}

void qlBlackCapFloorEngineDataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlBlackCapFloorEngine&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngineDataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlBlackCapFloorEngineDataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlBlackCapFloorEngineDataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlBlackCapFloorEngine2DataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlBlackCapFloorEngine2DataReader_var obj_dr
     = pricingengines::qlBlackCapFloorEngine2DataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlBlackCapFloorEngine2DataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlBlackCapFloorEngine2 obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlBlackCapFloorEngine2 ( 
              obj.ObjectId.in(),
              obj.YieldCurve.in(),
              obj.Vol ,
              obj.DayCounter.in(),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlBlackCapFloorEngine2: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlBlackCapFloorEngine2DataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngine2DataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackCapFloorEngine2DataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngine2DataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackCapFloorEngine2DataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngine2DataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlBlackCapFloorEngine2DataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngine2DataReaderListenerImpl::on_subscription_matched\n")));
}

void qlBlackCapFloorEngine2DataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngine2DataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackCapFloorEngine2DataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngine2DataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackCapFloorEngine2DataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackCapFloorEngine2DataReaderListenerImpl::on_reading_start\n")));
}

void qlBlackCapFloorEngine2DataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackCapFloorEngine2DataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlBlackCapFloorEngine2DataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlBlackCapFloorEngine2& )
{
  return true;
}

bool qlBlackCapFloorEngine2DataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlBlackCapFloorEngine2&, std::string& )
{
  return true;
}

void qlBlackCapFloorEngine2DataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlBlackCapFloorEngine2&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngine2DataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlBlackCapFloorEngine2DataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngine2DataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlBlackCapFloorEngine2DataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackCapFloorEngine2DataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlBlackScholesCalculatorDataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlBlackScholesCalculatorDataReader_var obj_dr
     = pricingengines::qlBlackScholesCalculatorDataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlBlackScholesCalculatorDataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlBlackScholesCalculator obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlBlackScholesCalculator ( 
              obj.ObjectId.in(),
              obj.OptionType.in(),
              static_cast<double>(obj.Strike),
              static_cast<double>(obj.Spot),
              static_cast<double>(obj.Growth),
              static_cast<double>(obj.StdDev),
              static_cast<double>(obj.Deflator),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlBlackScholesCalculator: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlBlackScholesCalculatorDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculatorDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackScholesCalculatorDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculatorDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackScholesCalculatorDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculatorDataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlBlackScholesCalculatorDataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculatorDataReaderListenerImpl::on_subscription_matched\n")));
}

void qlBlackScholesCalculatorDataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculatorDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackScholesCalculatorDataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculatorDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackScholesCalculatorDataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackScholesCalculatorDataReaderListenerImpl::on_reading_start\n")));
}

void qlBlackScholesCalculatorDataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackScholesCalculatorDataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlBlackScholesCalculatorDataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlBlackScholesCalculator& )
{
  return true;
}

bool qlBlackScholesCalculatorDataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlBlackScholesCalculator&, std::string& )
{
  return true;
}

void qlBlackScholesCalculatorDataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlBlackScholesCalculator&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculatorDataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlBlackScholesCalculatorDataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculatorDataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlBlackScholesCalculatorDataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculatorDataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlBlackScholesCalculator2DataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlBlackScholesCalculator2DataReader_var obj_dr
     = pricingengines::qlBlackScholesCalculator2DataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlBlackScholesCalculator2DataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlBlackScholesCalculator2 obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlBlackScholesCalculator2 ( 
              obj.ObjectId.in(),
              obj.PayoffID.in(),
              static_cast<double>(obj.Spot),
              static_cast<double>(obj.Growth),
              static_cast<double>(obj.StdDev),
              static_cast<double>(obj.Deflator),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlBlackScholesCalculator2: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlBlackScholesCalculator2DataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculator2DataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackScholesCalculator2DataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculator2DataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackScholesCalculator2DataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculator2DataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlBlackScholesCalculator2DataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculator2DataReaderListenerImpl::on_subscription_matched\n")));
}

void qlBlackScholesCalculator2DataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculator2DataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackScholesCalculator2DataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculator2DataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackScholesCalculator2DataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackScholesCalculator2DataReaderListenerImpl::on_reading_start\n")));
}

void qlBlackScholesCalculator2DataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackScholesCalculator2DataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlBlackScholesCalculator2DataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlBlackScholesCalculator2& )
{
  return true;
}

bool qlBlackScholesCalculator2DataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlBlackScholesCalculator2&, std::string& )
{
  return true;
}

void qlBlackScholesCalculator2DataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlBlackScholesCalculator2&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculator2DataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlBlackScholesCalculator2DataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculator2DataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlBlackScholesCalculator2DataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackScholesCalculator2DataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlBlackSwaptionEngineDataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlBlackSwaptionEngineDataReader_var obj_dr
     = pricingengines::qlBlackSwaptionEngineDataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlBlackSwaptionEngineDataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlBlackSwaptionEngine obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlBlackSwaptionEngine ( 
              obj.ObjectId.in(),
              obj.YieldCurve.in(),
              obj.VolTS.in(),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlBlackSwaptionEngine: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlBlackSwaptionEngineDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackSwaptionEngineDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackSwaptionEngineDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngineDataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlBlackSwaptionEngineDataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngineDataReaderListenerImpl::on_subscription_matched\n")));
}

void qlBlackSwaptionEngineDataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackSwaptionEngineDataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackSwaptionEngineDataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackSwaptionEngineDataReaderListenerImpl::on_reading_start\n")));
}

void qlBlackSwaptionEngineDataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackSwaptionEngineDataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlBlackSwaptionEngineDataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlBlackSwaptionEngine& )
{
  return true;
}

bool qlBlackSwaptionEngineDataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlBlackSwaptionEngine&, std::string& )
{
  return true;
}

void qlBlackSwaptionEngineDataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlBlackSwaptionEngine&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngineDataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlBlackSwaptionEngineDataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlBlackSwaptionEngineDataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlBlackSwaptionEngine2DataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlBlackSwaptionEngine2DataReader_var obj_dr
     = pricingengines::qlBlackSwaptionEngine2DataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlBlackSwaptionEngine2DataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlBlackSwaptionEngine2 obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlBlackSwaptionEngine2 ( 
              obj.ObjectId.in(),
              obj.YieldCurve.in(),
              obj.Vol ,
              obj.DayCounter.in(),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlBlackSwaptionEngine2: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlBlackSwaptionEngine2DataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngine2DataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackSwaptionEngine2DataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngine2DataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBlackSwaptionEngine2DataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngine2DataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlBlackSwaptionEngine2DataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngine2DataReaderListenerImpl::on_subscription_matched\n")));
}

void qlBlackSwaptionEngine2DataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngine2DataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackSwaptionEngine2DataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngine2DataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBlackSwaptionEngine2DataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackSwaptionEngine2DataReaderListenerImpl::on_reading_start\n")));
}

void qlBlackSwaptionEngine2DataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBlackSwaptionEngine2DataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlBlackSwaptionEngine2DataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlBlackSwaptionEngine2& )
{
  return true;
}

bool qlBlackSwaptionEngine2DataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlBlackSwaptionEngine2&, std::string& )
{
  return true;
}

void qlBlackSwaptionEngine2DataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlBlackSwaptionEngine2&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngine2DataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlBlackSwaptionEngine2DataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngine2DataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlBlackSwaptionEngine2DataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBlackSwaptionEngine2DataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlBondEngineDataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlBondEngineDataReader_var obj_dr
     = pricingengines::qlBondEngineDataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlBondEngineDataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlBondEngine obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlBondEngine ( 
              obj.ObjectId.in(),
              obj.YieldCurve.in(),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlBondEngine: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlBondEngineDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBondEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBondEngineDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBondEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlBondEngineDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBondEngineDataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlBondEngineDataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBondEngineDataReaderListenerImpl::on_subscription_matched\n")));
}

void qlBondEngineDataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBondEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBondEngineDataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBondEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlBondEngineDataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBondEngineDataReaderListenerImpl::on_reading_start\n")));
}

void qlBondEngineDataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlBondEngineDataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlBondEngineDataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlBondEngine& )
{
  return true;
}

bool qlBondEngineDataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlBondEngine&, std::string& )
{
  return true;
}

void qlBondEngineDataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlBondEngine&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBondEngineDataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlBondEngineDataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBondEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlBondEngineDataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlBondEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlDiscountingSwapEngineDataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlDiscountingSwapEngineDataReader_var obj_dr
     = pricingengines::qlDiscountingSwapEngineDataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlDiscountingSwapEngineDataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlDiscountingSwapEngine obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlDiscountingSwapEngine ( 
              obj.ObjectId.in(),
              obj.YieldCurve.in(),
              static_cast<bool>(obj.IncludeSettlDate),
              qldds_utils::from_iso_string_to_oh_property(obj.SettlementDate.in()),
              qldds_utils::from_iso_string_to_oh_property(obj.NpvDate.in()),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlDiscountingSwapEngine: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlDiscountingSwapEngineDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlDiscountingSwapEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlDiscountingSwapEngineDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlDiscountingSwapEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlDiscountingSwapEngineDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlDiscountingSwapEngineDataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlDiscountingSwapEngineDataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlDiscountingSwapEngineDataReaderListenerImpl::on_subscription_matched\n")));
}

void qlDiscountingSwapEngineDataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlDiscountingSwapEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlDiscountingSwapEngineDataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlDiscountingSwapEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlDiscountingSwapEngineDataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlDiscountingSwapEngineDataReaderListenerImpl::on_reading_start\n")));
}

void qlDiscountingSwapEngineDataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlDiscountingSwapEngineDataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlDiscountingSwapEngineDataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlDiscountingSwapEngine& )
{
  return true;
}

bool qlDiscountingSwapEngineDataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlDiscountingSwapEngine&, std::string& )
{
  return true;
}

void qlDiscountingSwapEngineDataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlDiscountingSwapEngine&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlDiscountingSwapEngineDataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlDiscountingSwapEngineDataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlDiscountingSwapEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlDiscountingSwapEngineDataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlDiscountingSwapEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}

void qlPricingEngineDataReaderListenerImpl::on_data_available( DDS::DataReader_ptr reader )
  throw (CORBA::SystemException)
{

  try {
   pricingengines::qlPricingEngineDataReader_var obj_dr
     = pricingengines::qlPricingEngineDataReader::_narrow(reader);
   if (CORBA::is_nil (obj_dr.in ())) {
     ACE_ERROR((LM_ERROR,
               ACE_TEXT("(%P|%t) ERROR: ")
               ACE_TEXT("qlPricingEngineDataReaderListenerImpl::on_data_available: _narrow failed.\n")));
  } 

  on_reading_start( reader );

  int count = 0;
  while ( true )
  {
    pricingengines::qlPricingEngine obj;
    DDS::SampleInfo si ;
    DDS::ReturnCode_t status = obj_dr->take_next_sample(obj, si) ;

    if ( status == DDS::RETCODE_OK )
    {
      if ( si.valid_data == true )
      {
         ++count;

         if ( pre_quantlib_addin_call( reader, si, obj ) )
         {
            std::string returnObject;;

            try {

              ACE_Guard<ACE_Mutex> guard( get_ACE_Mutex() );

              returnObject = QuantLibAddinCpp::qlPricingEngine ( 
              obj.ObjectId.in(),
              obj.EngineID.in(),
              obj.ProcessID.in(),
              static_cast<bool>(obj.Permanent),
              obj.Trigger,
              static_cast<bool>(obj.Overwrite) );
              ;
          
            } catch ( std::exception& e )
            {
              on_std_exception( reader, obj, e );
              continue;
            }

            if ( !post_quantlib_addin_call( reader, obj, returnObject ) )
             break; 
         }
      }

    } else if (status == DDS::RETCODE_NO_DATA) {

       on_reading_end( reader, count );

       break;

    }  else {
       std::string err = "ERROR: read qlPricingEngine: Error: ";
       err += status;

       on_dds_reading_error( reader, err );
    }
  }

  } catch (CORBA::Exception& e) {
       on_dds_exception( reader, e );
  }

}

void qlPricingEngineDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus &ms)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPricingEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlPricingEngineDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus &qs )
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPricingEngineDataReaderListenerImpl::on_requested_deadline_missed\n")));
}

void qlPricingEngineDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus &ls )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPricingEngineDataReaderListenerImpl::on_liveliness_changed\n")));
}

void qlPricingEngineDataReaderListenerImpl::on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus &ms )
  throw (CORBA::SystemException)
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPricingEngineDataReaderListenerImpl::on_subscription_matched\n")));
}

void qlPricingEngineDataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& sr)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPricingEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlPricingEngineDataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr reader,
  const DDS::SampleLostStatus& sl)
  throw (CORBA::SystemException)
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPricingEngineDataReaderListenerImpl::on_sample_rejected\n")));
}

void qlPricingEngineDataReaderListenerImpl::on_reading_start( DDS::DataReader_ptr reader )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlPricingEngineDataReaderListenerImpl::on_reading_start\n")));
}

void qlPricingEngineDataReaderListenerImpl::on_reading_end( DDS::DataReader_ptr reader, int count )
{
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("(%P|%t) INFO: ")
             ACE_TEXT("qlPricingEngineDataReaderListenerImpl::on_reading_end with %d items.\n"), count));
}

bool qlPricingEngineDataReaderListenerImpl::pre_quantlib_addin_call( DDS::DataReader_ptr reader, DDS::SampleInfo&, pricingengines::qlPricingEngine& )
{
  return true;
}

bool qlPricingEngineDataReaderListenerImpl::post_quantlib_addin_call( DDS::DataReader_ptr reader, pricingengines::qlPricingEngine&, std::string& )
{
  return true;
}

void qlPricingEngineDataReaderListenerImpl::on_std_exception( DDS::DataReader_ptr reader, pricingengines::qlPricingEngine&, std::exception& e )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPricingEngineDataReaderListenerImpl::on_std_exception %s\n"), e.what() ));
}

void qlPricingEngineDataReaderListenerImpl::on_dds_reading_error( DDS::DataReader_ptr reader, std::string& err )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPricingEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), err.c_str() ));
}

void qlPricingEngineDataReaderListenerImpl::on_dds_exception( DDS::DataReader_ptr reader, CORBA::Exception& exp )
{
  ACE_ERROR((LM_WARNING,
             ACE_TEXT("(%P|%t) WARNING: ")
             ACE_TEXT("qlPricingEngineDataReaderListenerImpl::on_dds_reading_error %s\n"), exp._info().c_str() ));
}
}
