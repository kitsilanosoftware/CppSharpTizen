//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FUiIDataBindingDataValidator.h
 * @brief	This is the header file for the %IDataBindingDataValidator interface.
 *
 * This header file contains the declarations of the %IDataBindingDataValidator interface.
 */

#ifndef _FUI_IDATA_BINDING_DATA_VALIDATOR_H_
#define _FUI_IDATA_BINDING_DATA_VALIDATOR_H_

#include <FUiDataBindingTypes.h>

namespace Tizen { namespace Base
{
class String;
class Object;
}}

namespace Tizen { namespace Ui
{

/**
 * @interface     IDataBindingDataValidator
 * @brief	     This interface defines methods for validating the value of transformed data that will be updated to the binding
 *		         target or source.
 *
 * @since 2.0
 *
 * The %IDataBindingDataValidator interface defines methods for validating the value of transformed data that will be updated to the binding.
 */
class _OSP_EXPORT_ IDataBindingDataValidator
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IDataBindingDataValidator(void) {};

	/**
	 * Validates the value of the transformed data that will be updated to the binding target.
	 *
	 * @since 2.0
	 * @return        @c true if the specified value is valid, @n
	 *                    else @c false
	 * @param[in]    bindingId            The binding Id to validate
	 * @param[in]    data     The data to validate
	 */
	virtual bool ValidateDataToTarget(const Tizen::Base::String& bindingId, const Tizen::Base::Object& data) = 0;

	/**
	 * Validates the value of the transformed data that will be updated to the binding source.
	 *
	 * @since 2.0
	 * @return        @c true if the specified value is valid, @n
	 *                    else @c false
	 * @param[in]    bindingId            The binding Id to validate
	 * @param[in]    data     The data to validate
	 */
	virtual bool ValidateDataToSource( const Tizen::Base::String& bindingId, const Tizen::Base::Object& data) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IDataBindingDataValidator_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IDataBindingDataValidator_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IDataBindingDataValidator_Reserved3(void) {}

}; // IDataBindingDataValidator

}} // Tizen::Ui
#endif // _FUI_IDATA_BINDING_DATA_VALIDATOR_H_
