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
 * @file	FSecPrivilegeInfo.h
 * @brief	This is the header file for the %PrivilegeInfo class.
 *
 * This header file contains the declarations of the %PrivilegeInfo class.
 */

#ifndef _FSEC_PRIVILEGE_INFO_H_
#define _FSEC_PRIVILEGE_INFO_H_
 
#include <FBaseObject.h>
 
namespace Tizen { namespace Security
{

class _PrivilegeInfoImpl;

/**
* @class	PrivilegeInfo
* @brief	This class represents the privilege information.
*
* @since	2.1
*
* @final	This class is not intended for extension.
*
* The %PrivilegeInfo class represents the privilege information.
* %PrivilegeInfo provides methods to retrieve the name and description of privilege.
*
*/

class _OSP_EXPORT_ PrivilegeInfo
	: public Tizen::Base::Object
{
public:

	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since       2.1
	 *
	 * @remarks  After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	PrivilegeInfo(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.1
	 *
	 */
	virtual ~PrivilegeInfo(void);

	/**
	 * Initializes this instance of %PrivilegeInfo with the specified parameters.
	 *
	 * @since         2.1
	 *
	 * @return       An error code
	 * @param[in]   privilegeId                The privilege ID
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG          The specified @c privilegeId is invalid.
	 *
	 */
	result Construct(const Tizen::Base::String& privilegeId);

	/**
	 * Gets a privilege ID.
	 *
	 * @since              2.1
	 *
	 * @return            The privilege ID.
	 *
	 */
	Tizen::Base::String GetId(void) const;

	/**
	 * Gets the localized display name of privilege.
	 *
	 * @since              2.1
	 *
	 * @return            The display name of privilege, else an empty string is returned if there is no value.
	 *
	 */
	Tizen::Base::String GetDisplayName(void) const;

	/**
	 * Gets the localized description of privilege.
	 *
	 * @since              2.1
	 *
	 * @return            The description of privilege, else an empty string is returned if there is no value.
	 *
	 */
	Tizen::Base::String GetDescription(void) const;

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]   rhs         An instance of %PrivilegeInfo
	//
	PrivilegeInfo(const PrivilegeInfo& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]   rhs An instance of %PrivilegeInfo
	//
	PrivilegeInfo& operator =(const PrivilegeInfo& rhs);

private:

	class _PrivilegeInfoImpl * __pImpl;
	friend class _PrivilegeInfoImpl;

}; // PrivilegeInfo

} } // Tizen::Security::PrivilegeInfo

#endif // _FSEC_PRIVILEGE_INFO_H_
