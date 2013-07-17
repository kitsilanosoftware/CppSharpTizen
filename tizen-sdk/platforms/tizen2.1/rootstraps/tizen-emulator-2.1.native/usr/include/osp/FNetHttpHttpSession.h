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
 * @file		FNetHttpHttpSession.h
 * @brief		This is the header file for the %HttpSession class.
 *
 * This header file contains the declarations of the %HttpSession class.
 */

#ifndef _FNET_HTTP_HTTP_SESSION_H_
#define _FNET_HTTP_HTTP_SESSION_H_

#include <FBaseString.h>
#include <FNetHttpHttpTypes.h>
#include <FNetHttpHttpTransaction.h>
#include <FNetHttpHttpHeader.h>
#include <FNetHttpHttpCookieStorageManager.h>
#include <FNetHttpHttpAuthentication.h>
#include <FNetNetConnection.h>

namespace Tizen { namespace Net { namespace Http
{
class _HttpSessionImpl;
/**
 * @class	HttpSession
 * @brief	This class represents an HTTP session.
 *
 * @since	2.0
 *
 * The %HttpSession class represents an HTTP session. The session encapsulates the client's HTTP activity over the duration of the client's execution. It is a set of transactions using the same
 * connection settings (such as proxy). The client may use several sessions concurrently if desired.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_session.htm">HTTP Session</a>.

 * The following example demonstrates how to use the %HttpSession class.
 *
 * @code

    #include <FBase.h>
    #include <FNet.h>

    using namespace Tizen::Base;
    using namespace Tizen::Net::Http;

    void
    TestHttpSession(void)
    {
        result r = E_SUCCESS;

        HttpSession* pSession = null;
        HttpTransaction* pTransaction = null;
        String* pProxyAddr = null;
        String hostAddr = L"http://www.tizen.org";

        pSession = new HttpSession();

        // HttpSession construction.
        r = pSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, pProxyAddr ,hostAddr, null);

        // Open a new HttpTransaction.
        pTransaction = pSession->OpenTransactionN();
    }

 * @endcode
 */

class _OSP_EXPORT_ HttpSession
	: public Tizen::Base::Object
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since       2.0
	 *
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be called explicitly to initialize the instance.
	 */
	HttpSession(void);

	/**
	 * Initializes this instance of %HttpSession with the specified parameters. @n
	 * Opens a session using the default @c netConnection.
	 *
	 * @since           2.0
	 *
	 * @return			An error code
	 * @param[in]		sessionMode			The session mode to open the session
	 * @param[in]		pProxyAddr				A proxy address @n
	 *											The specified @c pProxyAddr must be a valid URL. If @c pProxyAddr is @c null, %HttpSession uses the system
	 *											default proxy address.
	 * @param[in]		hostAddr				A host address @n
	 *											The specified @c hostAddr must be a valid URL. If session mode is NET_HTTP_SESSION_MODE_MULTIPLE_HOST,
	 *											@c hostAddr is ignored (In case of multiple host mode, @c hostAddr is set to HttpRequest::SetUri()).
	 * @param[in]		pCommonHeader			An instance of HttpHeader @n
	 *											This is a common header used in all the transactions included in this session.
	 * @param[in]		flag					Set to @c NET_HTTP_COOKIE_FLAG_ALWAYS_AUTOMATIC if the cookies must be handled automatically, @n
	 *											else @c NET_HTTP_COOKIE_FLAG_ALWAYS_MANUAL if the cookies must be handled manually
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_INVALID_CONNECTION	The net connection is invalid.
	 * @exception		E_MAX_EXCEEDED		The number of currently opened sessions has exceeded the maximum limit.
	 * @exception		E_INVALID_PROXY		The specified proxy address is invalid.
	 * @exception		E_UNKNOWN				An unknown error has occurred.
	 * @exception		E_SYSTEM				An internal error has occurred.
	 * @exception		E_INVALID_ADDRESS		The host address is invalid.
	 * @remarks			In the NORMAL and PIPELINING session modes, all the transactions within this sessions are submitted through the same connection. While
	 *					only one transaction is processed at a time in the Normal mode, multiple transactions can be pipelined in the Pipelining mode. In the
	 *					normal mode, in order to submit the next transaction, the previous transaction must be complete.
	 */
	result Construct(NetHttpSessionMode sessionMode, const Tizen::Base::String* pProxyAddr, const Tizen::Base::String& hostAddr, const HttpHeader* pCommonHeader, NetHttpCookieFlag flag = NET_HTTP_COOKIE_FLAG_ALWAYS_MANUAL);

	/**
	 * Initializes this instance of %HttpSession with the specified parameters. @n
	 * Opens a session using the specified protocol.
	 *
	 * @since           2.0
	 *
	 * @return			An error code
	 * @param[in]		netConnection			A NetConnection instance
	 * @param[in]		sessionMode				The session mode to open the session
	 * @param[in]		pProxyAddr				A proxy address @n
	 *											The specified @c pProxyAddr must be a valid URL. If @c pProxyAddr is @c null, %HttpSession uses the system
	 *											default proxy address.
	 * @param[in]		hostAddr				A host address @n
	 *											The specified @c hostAddr must be a valid URL.
	 * @param[in]		pCommonHeader			An instance of HttpHeader @n
	 *											This is a common header used in all the transactions included in this session.
	 * @param[in]		flag					Set to @c NET_HTTP_COOKIE_FLAG_ALWAYS_AUTOMATIC if the cookies must be handled automatically, @n
	 *											else @c NET_HTTP_COOKIE_FLAG_ALWAYS_MANUAL if the cookies must be handled manually
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception		E_INVALID_CONNECTION	The specified @c netConnection is invalid.
	 * @exception		E_MAX_EXCEEDED			Unable to setup new connection due to too many existing connections.
	 * @exception		E_INVALID_PROXY			The specified @c pProxyAddr is invalid.
	 * @exception		E_UNKNOWN				An unknown error has occurred.
	 * @exception		E_SYSTEM				An internal error has occurred.
	 * @exception		E_INVALID_ADDRESS		The host address is invalid.
	 * @remarks			In the NORMAL and PIPELINING session mode, all the transactions within this session will be submitted through the same connection.
	 *					While only one transaction is processed at a time in the Normal mode, multiple transactions can be pipelined in the Pipelining mode.
	 *					In the normal mode, in order to submit the next transaction, the previous transaction must be complete.
	 */
	result Construct(const NetConnection& netConnection, NetHttpSessionMode sessionMode, const Tizen::Base::String* pProxyAddr, const Tizen::Base::String& hostAddr, const HttpHeader* pCommonHeader, NetHttpCookieFlag flag = NET_HTTP_COOKIE_FLAG_ALWAYS_MANUAL);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~HttpSession(void);

public:
	/**
	 * Opens a transaction.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/http
	 *
	 * @return		A pointer to a new HttpTransaction, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_MAX_EXCEEDED			The maximum number of transactions has been reached.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The corresponding event listener must also be added in the same thread. A single transaction can be opened in a session at a time. After closing an open transaction, another
	 *				transaction can be opened.
	 */
	HttpTransaction* OpenTransactionN(void);

	/**
	* Opens a transaction with authentication information.
	*
	* @since			2.0
	* @privlevel		public
	* @privilege		%http://tizen.org/privilege/http
	*
	* @return		The pointer to a new HttpTransaction, @n
	*				else @c null if an error occurs
	* @param[in]	auth                    The authentication information
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_MAX_EXCEEDED			The maximum number of transactions has been reached.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @remarks		The corresponding event listener must also be added in the same thread. A single transaction at a time can be opened in a session. After closing an open transaction, another
	*				transaction can be opened.
	*/
	HttpTransaction* OpenTransactionN(const HttpAuthentication& auth);

	/**
	 * Cancels the specified transaction. @n
	 * This method is followed by the CloseTransaction() method.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/http
	 *
	 * @return		An error code
	 * @param[in]	httpTransaction             The HttpTransaction to cancel
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OPERATION_CANCELED		The specified transaction has already been canceled.
	 * @exception	E_INVALID_STATE				The method invoked is invalid.
	 * @exception	E_INVALID_TRANSACTION		The specified @c httpTransaction is invalid.
	 * @exception	E_UNKNOWN					An unknown error has occurred.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The canceled transaction is no longer considered active. Also, re-opening the transaction is not allowed.
	 */
	result CancelTransaction(HttpTransaction& httpTransaction);

	/**
	 * Closes the specified transaction.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/http
	 *
	 * @return		An error code
	 * @param[in]	httpTransaction			The HttpTransaction to close
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The specified transaction is not found within the indicated range, or @n
	 *										The specified transaction is already deleted.
	 * @exception	E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_INVALID_SESSION		The session is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 */
	result CloseTransaction(HttpTransaction& httpTransaction);

	/**
	 * Closes all the transactions.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/http
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OBJ_NOT_FOUND			The specified transaction is not found within the indicated range, or @n
	 *										the specified transaction is already deleted.
	 * @exception	E_INVALID_SESSION		The session is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 */
	result CloseAllTransactions(void);

	/**
	* Sets the value to redirect the HTTP request automatically (the value is @c false by default).
	*
	* @since		2.0
	*
	* @return       An error code
	* @param[in]	enable					Set to @c true to redirect the HTTP request automatically, @n
	*                                       else @c false
	* @exception    E_SUCCESS               The method is successful.
	* @exception    E_INVALID_STATE			The method invoked is invalid.
	* @exception    E_SYSTEM                A system error has occurred.
	*/
	result SetAutoRedirectionEnabled(bool enable);

	/**
	* Checks whether the HTTP redirection is automatic.
	*
	* @since		2.0
	*
	* @return       @c true if the HTTP redirection is automatic, @n
	*				else @c false
	* @exception    E_SUCCESS           The method is successful.
	* @exception    E_SYSTEM            A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	bool IsAutoRedirectionEnabled(void) const;

	/**
	 * Gets the number of active transactions in the current instance of %HttpSession.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/http
	 *
	 * @return      An integer value indicating the number of currently active transactions, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The transactions in the state between Submitted and Cancelled (or Closed) are considered to be active transactions.
	 */
	int GetActiveTransactionCount(void) const;

	/**
	 * Gets the maximum number of transactions, the current instance of %HttpSession can have.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/http
	 *
	 * @return      An integer value indicating the maximum number of transactions allowed @n
	 *              In NET_HTTP_SESSION_MODE_MULTIPLE_HOST mode, the return value is zero.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		In NET_HTTP_SESSION_MODE_MULTIPLE_HOST mode, the platform does not limit the number of maximum HttpTransaction that %HttpSession can have. @n
	 */
	int GetMaxTransactionCount(void) const;

	/**
	 * Gets the pointer to HttpCookieStorageManager.
	 *
	 * @since       2.0
	 *
	 * @return		The pointer to HttpCookieStorageManager, @n
	 *              else @c null if an error occurs
	 */
	HttpCookieStorageManager* GetCookieStorageManager(void) const;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs		An instance of %HttpSession
	 */
	HttpSession(const HttpSession& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 * Do @b not use directly.
	 *
	 * @param[in]	rhs			An instance of %HttpSession
	 */
	HttpSession& operator =(const HttpSession& rhs);

private:
	friend class _HttpSessionImpl;
	_HttpSessionImpl* __pHttpSessionImpl;

}; // HttpSession

} } } // Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_SESSION_H_
