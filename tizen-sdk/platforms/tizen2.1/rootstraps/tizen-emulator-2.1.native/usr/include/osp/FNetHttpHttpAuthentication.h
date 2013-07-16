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
 * @file		FNetHttpHttpAuthentication.h
 * @brief		This is the header file for the %HttpAuthentication class.
 *
 * This header file contains the declarations of the %HttpAuthentication class.
 */

#ifndef _FNET_HTTP_HTTP_AUTHENTICATION_H_
#define _FNET_HTTP_HTTP_AUTHENTICATION_H_

#include <FNetHttpHttpTypes.h>
#include <FNetHttpHttpHeader.h>
#include <FNetHttpHttpMessage.h>
#include <FNetHttpHttpCredentials.h>

namespace Tizen { namespace Net { namespace Http
{
class HttpTransaction;
class _HttpAuthenticationImpl;

/**
 * @class	HttpAuthentication
 * @brief	This class encapsulates an HTTP authentication.
 *
 * @since	2.0
 *
 * The %HttpAuthentication class encapsulates the HTTP authentication activity of the client over the duration of a single transaction.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_connectivity.htm">HTTP Guide</a>.
 *
 * The following example demonstrates how to use the %HttpAuthentication class.
 *
 * @code

#include <FBase.h>
#include <FNet.h>

using namespace Tizen::Base;
using namespace Tizen::Net::Http;

void
MyTransactionEventListener::OnTransactionHeaderCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction, int headerLen, bool authRequired)
{
	if (authRequired)
	{
		HttpAuthentication* pAuth = httpTransaction.OpenAuthenticationInfoN();
		String basicName("Name");
		String basicpass("Pass");
		HttpCredentials* pCredential = new HttpCredentials(basicName, basicpass);
		String* pRealm = pAuth->GetRealmN();
		NetHttpAuthScheme scheme = pAuth->GetAuthScheme();
		if (scheme == NET_HTTP_AUTH_WWW_BASIC || scheme == NET_HTTP_AUTH_PROXY_BASIC)
		{
			HttpTransaction* pNewTransaction =  pAuth->SetCredentials(*pCredential);
		}
	}
}

 * @endcode
 */
class _OSP_EXPORT_ HttpAuthentication
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since			2.0
	 */
	~HttpAuthentication(void);

	/**
	 * Gets the realm value received.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/http
	 *
	 * @return			The realm value
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception		E_SYSTEM            A system error has occurred.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String* GetRealmN(void) const;

	/**
	 * Gets the authentication scheme received.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/http
	 *
	 * @return			The authentication scheme, @n
	 *					else @c -1 if an error occurs
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_SYSTEM				A system error has occurred.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	NetHttpAuthScheme GetAuthScheme(void) const;

	/**
	 * Sets the credentials required for setting the "WWW-Authenticate" header in the HttpRequest class.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/http
	 *
	 * @return			The new transaction pointer
	 * @param[in]		credentials				The credentials
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_STATE			The method invoked is invalid.
	 * @exception		E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception		E_SYSTEM				A system error has occurred.
	 * @exception		E_AUTHENTICATION		The authentication has failed.
	 * @exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks			This method is used to set the username and password for the given domain and the authentication
	 *					scheme on the reception of the IHttpTransactionEventListener::OnTransactionHeaderCompleted() callback.
	 *					The specific error code can be accessed using the GetLastResult() method.
	 */
	HttpTransaction* SetCredentials(HttpCredentials& credentials);

private:
	/**
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	HttpAuthentication(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs	An instance of %HttpAuthentication
	 */
	HttpAuthentication(const HttpAuthentication& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]		rhs				An instance of %HttpAuthentication
	 */
	HttpAuthentication& operator =(const HttpAuthentication& rhs);

private:
	_HttpAuthenticationImpl* __pHttpAuthenticationImpl;
	friend class _HttpAuthenticationImpl;

}; // HttpAuthentication

} } } //Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_AUTHENTICATION_H_
