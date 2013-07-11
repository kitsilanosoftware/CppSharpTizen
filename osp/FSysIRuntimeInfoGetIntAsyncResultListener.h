//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
 
/**
* @file FSysIRuntimeInfoGetIntAsyncResultListener.h
* @brief          This is the header file for the %IRuntimeInfoGetIntAsyncResultListener interface.
*
* This header file contains the declarations of the %IRuntimeInfoGetIntAsyncResultListener interface.
*/
 
#ifndef _FSYS_IRUNTIME_INFO_GET_INT_ASYNC_RESULT_LISTENER_H_
#define _FSYS_IRUNTIME_INFO_GET_INT_ASYNC_RESULT_LISTENER_H_
 
#include <FBaseResult.h>
#include <FBaseRtIEventListener.h>
 
namespace Tizen { namespace System
{
 
/**
* @interface     IRuntimeInfoGetIntAsyncResultListener
* @brief          This interface defines the result listener for an asynchronous method call to the RuntimeInfo class.
*
* @since 2.0
*
* The %IRuntimeInfoGetIntAsyncResultListener interface defines the result listener for an asynchronous method call to the RuntimeInfo class. An instance of this interface is removed automatically by platform, after result is notified. 
*
*/
class _OSP_EXPORT_ IRuntimeInfoGetIntAsyncResultListener
           : public virtual Tizen::Base::Runtime::IEventListener
{
public:
           /**
           * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
           *
           * @since 2.0
           */
           virtual ~ IRuntimeInfoGetIntAsyncResultListener (void) {}
           /**
           * Called when a result received from an asynchronous method call is a key of type @c int.
           *
           * @since 2.0
           *
           * @param[in]    value     The @c int type runtime information
           * @param[in]    r          An error code
           * @exception E_SUCCESS The result is successful.
           * @exception E_SYSTEM The method cannot proceed due to a severe system error.
           */
           virtual void OnResultReceivedForGetValueAsync(int value, result r) = 0;
 
protected:
           //
           // This method is for internal use only.
           // Using this method can cause behavioral, security-related, and consistency-related issues in the application.
           //
           // @since 2.0
           virtual void IGetValueAsyncResultListener_Reserved1 (void){}
 
           //
           // This method is for internal use only.
           // Using this method can cause behavioral, security-related, and consistency-related issues in the application.
           //
           // @since 2.0
           virtual void IGetValueAsyncResultListener_Reserved2 (void){}
 
           //
           // This method is for internal use only.
           // Using this method can cause behavioral, security-related, and consistency-related issues in the application.
           //
           // @since 2.0
           virtual void IGetValueAsyncResultListener_Reserved3 (void){}
 
}; // IRuntimeInfoGetIntAsyncResultListener
 
} } // Tizen::System
#endif // _FSYS_IRUNTIME_INFO_GET_INT_ASYNC_RESULT_LISTENER_H_

