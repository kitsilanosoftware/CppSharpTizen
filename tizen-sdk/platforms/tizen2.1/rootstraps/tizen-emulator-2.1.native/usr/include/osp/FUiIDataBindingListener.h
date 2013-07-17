//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FUiIDataBindingListener.h
 * @brief	This is the header file for the %IDataBindingListener interface.
 *
 * This header file contains the declarations of the %IDataBindingListener interface.
 */

#ifndef _FUI_IDATA_BINDING_LISTENER_H_
#define _FUI_IDATA_BINDING_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FUiDataBindingTypes.h>

namespace Tizen { namespace Ui
{

/**
* @interface      	IDataBindingListener
* @brief 			This interface is the listener interface for receiving data binding-related events.
*
* @since 2.0
*
* The %IDataBindingListener interface defines methods for receiving data binding-related events.
*/
class _OSP_EXPORT_ IDataBindingListener
	: public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IDataBindingListener(void) {};

	/**
	* Called when the data transfer for source is completed by the data binding.
	*
	* @since 2.0
	*
	* @param[in]    bindingId        The binding ID
	* @param[in]    controlName      The name of binding target control
	* @param[in]    propertyName     The name of binding target property
	*/
	virtual void OnDataBindingSourceUpdated(const Tizen::Base::String& bindingId, const Tizen::Base::String& controlName
										   , const Tizen::Base::String& propertyName) = 0;

	/**
	* Called when the data transfer for target is completed by the data binding.
	*
	* @since 2.0
	*
	* @param[in]    bindingId       The binding ID
	* @param[in]    controlName     The name of binding target control
	* @param[in]    propertyName    The name of binding target property
	*/
	virtual void OnDataBindingTargetUpdated(const Tizen::Base::String& bindingId, const Tizen::Base::String& controlName
										   , const Tizen::Base::String& propertyName) = 0;


	/**
	* Called when a validation has failed during data transfer.
	*
	* @since 2.0
	*
	* @param[in]    bindingId       The binding ID
	* @param[in]    controlName     The name of binding target control
	* @param[in]    propertyName    The name of binding target property
	* @param[in]    destType        The data binding destination type
	*/
	virtual void OnDataBindingValidationFailed(const Tizen::Base::String& bindingId, const Tizen::Base::String& controlName
											  , const Tizen::Base::String& propertyName, DataBindingDestinationType destType) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IDataBindingListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IDataBindingListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IDataBindingListener_Reserved3(void) {}

}; // IDataBindingListener;

}} // Tizen::Ui
#endif // _FUI_IDATA_BINDING_LISTENER_H_
