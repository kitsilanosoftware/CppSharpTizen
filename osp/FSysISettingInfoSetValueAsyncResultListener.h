//
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

/*
 * @file	FSysISettingInfoSetValueAsyncResultListener.h
 * @brief	This is the header file for the %ISettingInfoSetValueAsyncResultListener interface.
 *
 * This header file contains the declarations of the %ISettingInfoSetValueAsyncResultListener interface.
 */

#ifndef _FSYS_ISETTING_INFO_SET_VALUE_ASYNC_RESULT_LISTENER_H_
#define _FSYS_ISETTING_INFO_SET_VALUE_ASYNC_RESULT_LISTENER_H_

#include <FBaseResult.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace System
{

/**
 * @interface	ISettingInfoSetValueAsyncResultListener
 * @brief	This interface defines the result listener for an asynchronous setting change method call.
 *
 * @since 2.0
 *
 * The %ISettingInfoSetValueAsyncResultListener interface must be registered and implemented by an application to receive result for an asynchronous setting change method call.
 *
 */
class _OSP_EXPORT_ ISettingInfoSetValueAsyncResultListener
	: public virtual Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the destructor for this class. This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~ISettingInfoSetValueAsyncResultListener(void) {}
	
	/**
	 * Called when a result is received for an asynchronous setting change method call.
	 *
	 * @since 2.0
	 *
	 * @param[in] key The key name of the changed setting information
	 * @param[in] r An error code
	 * @exception E_SUCCESS The result is successful.
	 * @exception E_SYSTEM	The method cannot proceed due to severe system error.
	 */
	
	virtual void OnResultReceivedForSetValueAsync(const Tizen::Base::String& key, result r) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnISettingInfoSetValueAsyncResultListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnISettingInfoSetValueAsyncResultListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnISettingInfoSetValueAsyncResultListener_Reserved3(void) {}
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnISettingInfoSetValueAsyncResultListener_Reserved4(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnISettingInfoSetValueAsyncResultListener_Reserved5(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnISettingInfoSetValueAsyncResultListener_Reserved6(void) {}
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnISettingInfoSetValueAsyncResultListener_Reserved7(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnISettingInfoSetValueAsyncResultListener_Reserved8(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void OnISettingInfoSetValueAsyncResultListener_Reserved9(void) {}

}; // ISettingEventListener

} } // Tizen::System

#endif // _FSYS_ISETTING_INFO_SET_VALUE_ASYNC_RESULT_LISTENER_H_
