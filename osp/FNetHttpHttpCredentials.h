//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
 * @file		FNetHttpHttpCredentials.h
 * @brief		This is the header file for the %HttpCredentials class.
 *
 * This header file contains the declarations of the %HttpCredentials class.
 */

#ifndef _FNET_HTTP_HTTP_CREDENTIALS_H_
#define _FNET_HTTP_HTTP_CREDENTIALS_H_

#include <FNetHttpHttpTypes.h>

namespace Tizen { namespace Net { namespace Http
{

/////////////////////////////////////////////////////////////////////////////
/**
 * @class	HttpCredentials
 * @brief	This class represents the credentials required for authentication.
 *
 * @since   2.0
 *
 * The %HttpCredentials class represents the credentials required for authentication, that is, the user name and password.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_connectivity.htm">HTTP Guide</a>.
 */
//////////////////////////////////////////////////////////////////////////
class _OSP_EXPORT_ HttpCredentials
	: public Tizen::Base::Object
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since       2.0
	 */
	HttpCredentials(void);

	/**
	 * Initializes an instance of %HttpCredentials with the specified user name and password.
	 *
	 * @since       2.0
	 *
	 * @param[in]	name				The user name string
	 * @param[in]	password			The password string
	 */
	HttpCredentials(const Tizen::Base::String& name, const Tizen::Base::String& password);

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since        2.0
	*
	* @param[in]	rhs	An instance of %HttpCredentials
	*/
	HttpCredentials(const HttpCredentials& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~HttpCredentials(void);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since       2.0
	 *
	 * @param[in]	rhs		An instance of %HttpCredentials
	 */
	HttpCredentials& operator =(const HttpCredentials& rhs);

	/**
	 * Sets the user name for the current instance of %HttpCredentials.
	 *
	 * @since       2.0
	 * @privilege	%http://tizen.org/privilege/http
	 *
	 * @param[in]	name				The user name string
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	result SetName(const Tizen::Base::String& name);

	/**
	 * Sets the password for the current instance of %HttpCredentials.
	 *
	 * @since       2.0
	 * @privilege	%http://tizen.org/privilege/http
	 *
	 * @param[in]	password			The password string
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	result SetPassword(const Tizen::Base::String& password);

	/**
	 * Gets the user name of the current instance of %HttpCredentials.
	 *
	 * @since       2.0
	 * @privilege	%http://tizen.org/privilege/http
	 *
	 * @return			The user name
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * Gets the password of the current instance of %HttpCredentials.
	 *
	 * @since       2.0
	 * @privilege	%http://tizen.org/privilege/http
	 *
	 * @return			The password
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetPassword(void) const;

	/**
	 * Compares the specified instance of %HttpCredentials with the calling instance.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the values match, @n
	 *			    else @c false
	 * @param[in]	rhs     The other Tizen::Base::Object to compare
	 * @see         Tizen::Base::Object::Equals()
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since		2.0
	 *
	 * @return      The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

private:
	Tizen::Base::String __userName;
	Tizen::Base::String __password;

	friend class HttpCredentialsImpl;
	class HttpCredentialsImpl* __pHttpCredentialsImpl;

}; // HttpCredentials

} } } //Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_CREDENTIALS_H_
