//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
* @file    FSecPrivacyInfo.h
* @brief  This is the header file for the %PrivacyInfo class.
*
* This header file contains the declarations of the %PrivacyInfo class.
*/
 
#ifndef _FSEC_PRIVACY_INFO_H_
#define _FSEC_PRIVACY_INFO_H_
 
#include <FBaseObject.h>
 
namespace Tizen { namespace Security
{
 
/**
* @class	PrivacyInfo
* @brief	This class represents the privacy information.
*
* @since	2.1
*
* @final This class is not intended for extension.
*
* The %PrivacyInfo class represents the privacy information.
* %PrivacyInfo provides methods to retrieve the name and description of privilege.
*/
 
class _OSP_EXPORT_ PrivacyInfo
	: public Tizen::Base::Object
{

public:
 
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.1
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	PrivacyInfo(void);
 
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.1
	 *
	 */
	virtual ~PrivacyInfo(void);
 
	/**
	 * Initializes this instance of %PrivacyInfo with the specified parameters.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	privacyId			The privacy ID
	 * @param[in]	enable				Set to @c true to enable the privacy setting, @n
	 *                                  else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c privacyId is invalid or the @c privacyId is not exist.
	 *
	 */
	result Construct(const Tizen::Base::String& privacyId, bool enable = false);
 
	/**
	 * Gets a privacy ID.
	 *
	 * @since		2.1
	 *
	 * @return		The privacy ID.
	 *
	 */
	Tizen::Base::String GetId(void) const;
 
	/**
	 * Checks whether the privacy setting is enabled.
	 *
	 * @since		2.1
	 *
	 * @return		@c true if the privacy setting is enabled, @n
	 * 				else @c false
	 * @see			SetEnabled()
	 */
	bool IsEnabled(void) const;
 
	/**
	 * Enables or disables the privacy setting.
	 *
	 * @since		2.1
	 *
	 * @param[in]	enable			A Boolean value indicating whether the privacy setting is enabled.
	 * @see			IsEnabled()
	 *
	 */
	void SetEnabled(bool enable);
 
	/**
	 * Gets the localized display name of privacy.
	 *
	 * @since		2.1
	 *
	 * @return		The display name of privacy, else an empty string is returned if there is no value.
	 *
	 */
	Tizen::Base::String GetDisplayName(void) const;
 
	/**
	 * Gets the localized description of privacy.
	 *
	 * @since		2.1
	 *
	 * @return		The description of privacy, else an empty string is returned if there is no value.
	 *
	 */
	Tizen::Base::String GetDescription(void) const;
 
private:
 
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]   rhs         An instance of %PrivacyInfo
	//
	PrivacyInfo(const PrivacyInfo& rhs);
 
	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]   rhs          An instance of %PrivacyInfo
	//
	PrivacyInfo& operator =(const PrivacyInfo& rhs);
 
private:
 
	class _PrivacyInfoImpl* __pImpl;
	friend class _PrivacyInfoImpl;
 
}; // PrivacyInfo
 
} } // Tizen::Security
 
#endif // _FSEC_PRIVACY_INFO_H_
 
