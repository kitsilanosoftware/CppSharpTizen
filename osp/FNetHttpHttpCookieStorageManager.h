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
 * @file		FNetHttpHttpCookieStorageManager.h
 * @brief		This is the header file for the %HttpCookieStorageManager class.
 *
 * This header file contains the declarations of the %HttpCookieStorageManager class.
 */

#ifndef _FNET_HTTP_HTTP_COOKIE_STORAGE_MANAGER_H_
#define _FNET_HTTP_HTTP_COOKIE_STORAGE_MANAGER_H_

#include <FBaseResult.h>
#include <FNetHttpHttpTypes.h>

namespace Tizen { namespace Net { namespace Http
{
class HttpSession;
class _HttpCookieStorageManagerImpl;
/**
 * @class	HttpCookieStorageManager
 * @brief	This class provides a collection of %Http cookies of a particular session.
 *
 * @since   2.0
 *
 * The %HttpCookieStorageManager class instance encapsulates the cookies received by the client in this particular session.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_connectivity.htm">HTTP Guide</a>.
 */
class _OSP_EXPORT_ HttpCookieStorageManager
	: public Tizen::Base::Object
{

public:
	/**
	 * Gets the string to be used in the cookie header of the request corresponding to the requested URL.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	url					The request URL
	 * @param[out]	cookies				The cookie header value @n
	 *						            For example, cookie-name1=cookie-value1;cookie-name2=cookie-value2.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c cookies is an empty string.
	 * @exception	E_INVALID_STATE		The method invoked is invalid.
	 */
	result GetCookies(const Tizen::Base::String& url, Tizen::Base::String& cookies) const;

	/**
	 * Removes all the cookies corresponding to the requested URL from the cookie storage.
	 *
	 * @since		2.0
	 * @privilege	%http://tizen.org/privilege/http
	 *
	 * @return		An error code
	 * @param[in]	url						The requested URL
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c url is an empty string.
	 * @exception	E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	result RemoveCookies(const Tizen::Base::String& url);

	/**
	 * Removes all the cookies from the cookie storage.
	 *
	 * @since		2.0
	 * @privilege	%http://tizen.org/privilege/http
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	result RemoveAllCookies();

private:
	/**
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	HttpCookieStorageManager();

	/**
	 * This default constructor is intentionally declared as private so that only the platform can delete an instance.
	 */
	~HttpCookieStorageManager();

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs   An instance of %HttpCookieStorageManager
	 */
	HttpCookieStorageManager(const HttpCookieStorageManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs		An instance of %HttpCookieStorageManager
	 */
	HttpCookieStorageManager& operator =(const HttpCookieStorageManager& rhs);

private:
	friend class _HttpCookieStorageManagerImpl;
	_HttpCookieStorageManagerImpl* __pHttpCookieStorageManagerImpl;

}; // HttpCookieStorageManager

} } } //Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_COOKIE_STORAGE_MANAGER_H_
