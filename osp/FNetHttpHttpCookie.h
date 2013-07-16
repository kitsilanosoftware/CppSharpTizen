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
 * @file		FNetHttpHttpCookie.h
 * @brief		This is the header file for the %HttpCookie class.
 *
 * This header file contains the declarations of the %HttpCookie class.
 */

#ifndef _FNET_HTTP_HTTP_COOKIE_H_
#define _FNET_HTTP_HTTP_COOKIE_H_

#include <FBaseUtil.h>
#include <FBaseColArrayList.h>
#include <FNetHttpHttpTypes.h>
#include <FNetHttpHttpHeader.h>
#include <FNetHttpHttpMessage.h>

namespace Tizen { namespace Net { namespace Http
{
class _HttpCookieImpl;
/**
 * @class	HttpCookie
 * @brief	This class provides a %Http cookie.
 *
 * @since	2.0
 *
 * The %HttpCookie class provides a %Http cookie. The %HttpCookie instance encapsulates the cookie received by the server in a particular HttpResponse instance.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_connectivity.htm">HTTP Guide</a>.
 *
 * The following example demonstrates how to use the %HttpCookie class.
 *
 * @code

#include <FBase.h>
#include <FNet.h>

using namespace Tizen::Base;
using namespace Tizen::Net::Http;
using namespace Tizen::Base::Collection;

void
MyTransactionEventListener::OnTransactionHeaderCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction, int headerLen, bool bAuthRequired)
{
	IList* pCookieList = null;
	HttpCookie* pCookie = null;
	HttpTransaction* pTransaction = const_cast<HttpTransaction*>(&(httpTransaction));
	HttpResponse* pResponse = pTransaction->GetResponse();
	HttpHeader* pHeader = pResponse->GetHeader();

	String* pRawHeader = null;
	pRawHeader = pHeader->GetRawHeaderN();

	pCookieList = pResponse->GetCookies();
	for (int i = 0; i < pCookieList->GetCount(); i++)
	{
		pCookie = static_cast<HttpCookie*>(pCookieList->GetAt(i));
		String domain = pCookie->GetDomain();
		String version = pCookie->GetVersion();
		String path = pCookie->GetPath();
		String expire = pCookie->GetExpires();
		String cookieName = pCookie->GetCookieName();
		String cookieValue = pCookie->GetCookieValue();
	}

	delete pRawHeader;
}

 * @endcode
 */
class _OSP_EXPORT_ HttpCookie
	: public Tizen::Base::Object
{

public:
	/**
	* Gets the domain name of the cookie.
	*
	* @since		2.0
	*
	* @return      The domain name of the cookie, @n
	*				else an empty string if no domain name is received in the cookie
	*/
	Tizen::Base::String GetDomain(void) const;

	/**
	* Gets the path name of the cookie.
	*
	* @since		2.0
	*
	* @return      The path name of the cookie, @n
	*				else an empty string if no path name is received in the cookie
	*/
	Tizen::Base::String GetPath(void) const;

	/**
	* Gets the version of the cookie.
	*
	* @since		2.0
	*
	* @return      The version of the cookie, @n
	*				else an empty string if no version is received in the cookie
	*/
	Tizen::Base::String GetVersion(void) const;

	/**
	* Gets the expiration date and time of the cookie.
	*
	* @since		2.0
	*
	* @return      The expiration date and time of the cookie, @n
	*				else an empty string if no expiration date and time is received in the cookie
	*/
	Tizen::Base::String GetExpires(void) const;

	/**
	* Checks whether the cookie is secured.
	*
	* @since		2.0
	*
	* @return      @c true if the cookie is secured, @n
	*				else @c false
	*/
	bool IsSecure(void) const;

	/**
	* Gets the name of the cookie.
	*
	* @since		2.0
	*
	* @return      The name of the cookie
	*/
	Tizen::Base::String GetCookieName(void) const;

	/**
	* Gets the value of the cookie.
	*
	* @since		2.0
	*
	* @return      The value of the cookie
	*/
	Tizen::Base::String GetCookieValue(void) const;

	/**
	* Gets the comment URL of the cookie.
	*
	* @since		2.0
	*
	* @return      The comment URL of the cookie, @n
	*				else an empty string if no comment URL is received in the cookie
	*/
	Tizen::Base::String GetCommentUrl(void) const;

	/**
	* Gets the comment on the cookie.
	*
	* @since		2.0
	*
	* @return		The comment on the cookie, @n
	*				else an empty string if no comment is received in the cookie
	*/
	Tizen::Base::String GetComment(void) const;

	/**
	* Checks whether the 'HttpOnly' flag is set in the cookie.
	*
	* @since		2.0
	*
	* @return		@c true if the 'HttpOnly' flag is set, @n
	*				else @c false
	*/
	bool IsHttpOnly(void) const;

	/**
	* Gets the port list.
	*
	* @since		2.0
	*
	* @return		The port list, which is a comma separated series of digits, @n
	*				else an empty string if no port list is received
	*/
	Tizen::Base::String GetPorts(void) const;

	/**
	* Gets the maximum age of the cookie.
	*
	* @since		2.0
	*
	* @return      The maximum age of the cookie, @n
	*				else @c -1 if no maximum age is received in the cookie
	*/
	int GetMaxAge(void) const;

	/**
	* Checks whether the 'Discard' flag is set in the cookie.
	*
	* @since		2.0
	*
	* @return      @c true if the 'Discard' flag is set, @n
	*					else @c false
	*/
	bool GetDiscard(void) const;

private:
	/**
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	HttpCookie(void);

	/**
	 * This destructor is intentionally declared as private so that only the platform can delete an instance.
	 */
	~HttpCookie(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs		An instance of %HttpCookie
	 */
	HttpCookie(const HttpCookie& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %HttpCookie
	 */
	HttpCookie& operator =(const HttpCookie& rhs);

private:
	friend class _HttpCookieImpl;
	_HttpCookieImpl* __pHttpCookieImpl;

}; // HttpCookie

} } } //Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_COOKIE_H_
