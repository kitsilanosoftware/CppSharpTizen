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

/**
 * @file	FSecAccessController.h
 * @brief	This is the header file for the %AccessController class.
 *
 * This header file contains the declarations of the %AccessController class.
 */

#ifndef _FSEC_ACCESS_CONTROLLER_H_
#define _FSEC_ACCESS_CONTROLLER_H_

#include <FOspConfig.h>
#include <FAppTypes.h>

namespace Tizen { namespace Security
{

class _PrivilegeManager;

/**
 * @class	AccessController
 * @brief	This class provides a way to check the privilege of privileged API.
 * @since	2.0
 *
 * The %AccessController class provides a way to check the privilege of privileged API.
 */
class _OSP_EXPORT_ AccessController
{

public:

	/**
	 * Checks whether the application has a privilege to invoke the privileged API.
	 *
	 * @since 2.0
	 * @return		An error code
	 * @param[in]	privilege				A value of enumerator of the specified @c privilege
	 * @exception	E_SUCCESS				The method is successful and the request is granted.
	 * @exception	E_DATA_NOT_FOUND		The privilege information does not exist.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
     * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling the method.
	 * @exception	E_SYSTEM				An unexpected system error has occurred.
	 */
	static result CheckPrivilege(int privilege);

    /**
    * Checks whether the application has a privilege to invoke the privileged API.
    *
    * @since 2.1
    * @return		An error code
    * @param[in]	privilege				A string of the specified privilege
    * @exception	E_SUCCESS				The method is successful and the request is granted.
    * @exception	E_INVALID_ARG			The specified @c privilege is invalid privilege string.
    * @exception	E_DATA_NOT_FOUND		The privilege information does not exist.
    * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call the method.
    * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling the method.
    * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
    */
    static result CheckPrivilege(const Tizen::Base::String& privilege);


    /**
    * Checks whether the client application which has @c packageId has a privilege to invoke the privileged API.
    *
    * @since 2.1
    * @privlevel   partner
    * @privilege   %http://tizen.org/privilege/privilegemanager.read
    *
    * @return		An error code
    * @param[in]	packageId					The package ID
    * @param[in]	privilege				A string of the specified privilege
    * @exception	E_SUCCESS				The method is successful and the request is granted.
    * @exception	E_INVALID_ARG			The specified @c privilege is invalid privilege string.
    * @exception	E_DATA_NOT_FOUND		The privilege information does not exist.
    * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call the method.
    * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling the method.
    * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
    */
    static result CheckPrivilege(const Tizen::App::PackageId& packageId, const Tizen::Base::String& privilege);

private:

    /**
     * This default constructor is intentionally declared as private because this class cannot be constructed.
     */
	AccessController(void);

    /**
     * This destructor is intentionally declared as private because this class cannot be constructed.
     */
	~AccessController(void);

    /**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     */
	AccessController(const AccessController& rhs);

    /**
     * The implementation of this copy assignment operator is intentionally blank and delcared as private to prohibit copying of objects.
     */
	AccessController& operator =(const AccessController& rhs);

	static void Initialize(void);

private:
	static _PrivilegeManager* __pPrivilegeManager;

};  // AccessController

}} // Tizen::Security

#endif // _FSEC_ACCESS_CONTROLLER_H_
