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
* @file		FSecPrivacyManager.h
* @brief	This is the header file for the %PrivacyManager class.
*
* This header file contains the declarations of the %PrivacyManager class.
*/
 
#ifndef _FSEC_PRIVACY_MANAGER_H_
#define _FSEC_PRIVACY_MANAGER_H_
 
#include <FBaseObject.h>
#include <FAppTypes.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}

namespace Tizen { namespace Security
{
 
class PrivacyInfo;
 
/**
 * @class	  PrivacyManager
 * @brief	  This class gets the privacy information and manages an application's privacy settings.
 *
 * @since   2.1
 *
 * @final   This class is not intended for extension.
 *
 * The %PrivacyManager class lets an application to get or save application's privacy settings.
 */
 
class _OSP_EXPORT_ PrivacyManager
	: public Tizen::Base::Object
{
public:
 
	/**
	 * Gets the privacy manager instance.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to the %PrivacyManager instance, @n
	 *				else @c null if it fails
	 *
	 * @exception	E_SUCCESS		  The method is successful.
	 * @exception	E_SYSTEM		   The method cannot proceed due to a severe system error.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static PrivacyManager* GetInstance(void);
 
	/**
	 * Gets a list of packages which access user's privacy information.
	 *
	 * @since		2.1
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/privacymanager.read
	 *
	 * @return		A pointer to the list of application packages (PackageId) which access user's privacy information, @n
	 *				else @c null if an error occurs
	 *
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetPrivacyAppPackageListN(void) const;
 
	/**
	 * Gets a list of privacy information of a package.
	 *
	 * @since		2.1
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/privacymanager.read
	 *
	 * @return		A pointer to the privacy information list (Privacyinfo), @n
	 *				else @c null if an error occurs
	 * @param[in]	packageId				The package ID
	 *
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 *
	 * @remarks		 The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetPrivacyInfoListN(const Tizen::App::PackageId& packageId) const;

	/**
	 * Sets the specific privacy setting of a package
	 *
	 * @since		2.1
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/privacymanager.write
	 *
	 * @return		An error code
	 * @param[in]	packageId				The package ID
	 * @param[in]	privacyInfo				The privacy setting to be set
	 *
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c packageId is not found in privacy database or @n
	 *										the package did not be defined to access to the privacy information.
	 * @exception	E_INVALID_ARG			The specified @c packageId length is invalid.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 *
	 */
	result SetAppPackagePrivacy(const Tizen::App::PackageId& packageId, const PrivacyInfo& privacyInfo);
 
private:
 
	//
	// This default constructor is intentionally declared as private to implement the %Singleton semantic.
	//
	// @since		   2.1
	//
	PrivacyManager(void);
 
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since		   2.1
	//
	PrivacyManager(const PrivacyManager& rhs);
 
	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since		   2.1
	//
	PrivacyManager& operator =(const PrivacyManager& rhs);
 
	//
	// This destructor is intentionally declared as private to implement the %Singleton semantic.
	//
	// @since		   2.1
	//
	virtual ~PrivacyManager(void);
 
private:
 
	class _PrivacyManagerImpl* __pPrivacyManagerImpl;
	friend class _PrivacyManagerImpl;
 
}; // PrivacyManager
 
}} // Tizen::Security
 
#endif // _FSEC_PRIVACY_MANAGER_H_
