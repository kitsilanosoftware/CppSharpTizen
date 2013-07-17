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
 * @file	FSclAccountProvider.h
 * @brief	This is the header file for the %AccountProvider class.
 *
 * This header file contains the declarations of the %AccountProvider class.
 */
#ifndef _FSCL_ACCOUNT_PROVIDER_H_
#define _FSCL_ACCOUNT_PROVIDER_H_

#include <FAppTypes.h>
#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FSclTypes.h>

namespace Tizen { namespace Base
{
class String;
namespace Collection
{
class IList;
}
}}

namespace Tizen { namespace Social
{

/**
 * @class	AccountProvider
 * @brief	This class represents the account provider information.
 * @since	2.1
 *
 * @final	This class is not intended for extension.
 *
 *  The %AccountProvider class provides the account provider information.
 */
class _OSP_EXPORT_ AccountProvider
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * It creates a fully initialized instance of the %AccountProvider class.
	 *
	 * @since	2.1
	 */
	AccountProvider(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since		2.1
	 *
	 * @param[in]	rhs		An instance of %AccountProvider
	 */
	AccountProvider(const AccountProvider& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~AccountProvider(void);

	/**
	 * Checks whether the value of the specified instance is equal to the value of the current instance.
	 *
	 * @since		2.1
	 *
	 * @return		@c true if the value of the specified instance of Tizen::Base::Object is equal to the value of the current instance, @n
	 *					else @c false
	 * @param[in]	rhs		An instance to compare
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.1
	 *
	 * @return	An integer value indicating the hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the app ID of the application that has registered this account provider.
	 *
	 * @since	2.1
	 *
	 * @return	The app ID
	 */
	Tizen::App::AppId GetAppId(void) const;

	/**
	 * Gets a list of capabilities that an account provider owns.
	 *
	 * @since	2.1
	 *
	 * @return	A list of capabilities which are predefined or the vendor-specific String defined as the IRI format, @n
	 * 				else an empty list if there is no capability, or @c null if an exception occurs (String list)
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetCapabilitiesN(void) const;

	/**
	 * Gets the display name of an account provider.
	 *
	 * @since	2.1
	 *
	 * @return	The display name
	 */
	Tizen::Base::String GetDisplayName(void) const;

	/**
	 * Gets the icon path.
	 *
	 * @since	2.1
	 *
	 * @return	The icon path
	 */
	Tizen::Base::String GetIconPath(void) const;

	/**
	 * Gets the small icon path.
	 *
	 * @since	2.1
	 *
	 * @return	The small icon path
	 */
	Tizen::Base::String GetSmallIconPath(void) const;

	/**
	 * Checks whether an account provider supports multiple accounts.
	 *
	 * @since	2.1
	 *
	 * @return	@c true if the account provider supports multiple accounts, @n
	 * 			else @c false
	 */
	bool IsMultipleAccountSupported(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since		2.1
	 *
	 * @param[in]	rhs		An instance of %AccountProvider
	 */
	AccountProvider& operator =(const AccountProvider& rhs);

private:
	friend class _AccountProviderImpl;
	class _AccountProviderImpl* __pAccountProviderImpl;

}; // AccountProvider

}} // Tizen::Social

#endif //_FSCL_ACCOUNT_PROVIDER_H_
