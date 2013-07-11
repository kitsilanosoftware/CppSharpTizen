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
 * @file		FNetHttpHttpTransaction.h
 * @brief		This is the header file for the %HttpTransaction class.
 *
 * This header file contains the declarations of the %HttpTransaction class.
 */

#ifndef _FNET_HTTP_HTTP_TRANSACTION_H_
#define _FNET_HTTP_HTTP_TRANSACTION_H_

#include <FNetHttpHttpTypes.h>
#include <FNetHttpHttpRequest.h>
#include <FNetHttpHttpResponse.h>
#include <FNetHttpHttpAuthentication.h>
#include <FNetHttpIHttpTransactionEventListener.h>
#include <FNetHttpIHttpEntity.h>
#include <FNetHttpIHttpProgressEventListener.h>

namespace Tizen { namespace Net { namespace Http
{
class _HttpTransactionImpl;
/**
 * @class	HttpTransaction
 * @brief	This class manages the HTTP transaction that encapsulates a request and a response.
 *
 * @since	2.0
 *
 * The %HttpTransaction class manages the HTTP transaction that encapsulates a request and a response.
 * A transaction represents an interaction between the HTTP client and the HTTP origin server.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_transaction.htm">HTTP Transaction</a>.
 *
 * The following example demonstrates how to use the %HttpTransaction class.
 *
 * @code
 *
    #include <FBase.h>
    #include <FNet.h>

    using namespace Tizen::Base;
    using namespace Tizen::Net::Http;

    void
    TestHttpTransaction(void)
    {
        result r = E_SUCCESS;

        HttpSession* pSession = null;
        HttpTransaction* pTransaction = null;
        String* pProxyAddr = null;
        String hostAddr(L"http://www.tizen.org");

        pSession = new HttpSession();
        r = pSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, pProxyAddr ,hostAddr, null);

        // Open a new HttpTransaction.
        pTransaction = pSession->OpenTransactionN();

        r = pTransaction->AddHttpTransactionListener(*this);

        HttpRequest* pRequest = pTransaction->GetRequest();
        r = pRequest->SetUri(L"http://www.tizen.org");
        r = pRequest->SetMethod(NET_HTTP_METHOD_GET);

        // Submit the HttpTransaction.
        r = pTransaction->Submit();
    }

 * @endcode
 */

class _OSP_EXPORT_ HttpTransaction
	: public Tizen::Base::Object
{

public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since   2.0
	 */
	virtual ~HttpTransaction(void);

public:
	/**
	 * Submits the HTTP request.
	 *
	 * @since           2.0
	 * @privilege		%http://tizen.org/privilege/http
	 *
	 * @return			An error code
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception		E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									    At least one of Uri, Method, Header, and Body is invalid.
	 * @exception		E_INVALID_HEADER	The header is @c null.
	 * @exception       E_INVALID_STATE		The method invoked is invalid.
	 * @exception		E_OUT_OF_RANGE		The submitted data is out of range.
	 * @exception		E_MAX_EXCEEDED		The number of active transactions has exceeded the maximum limit.
	 * @exception		E_INVALID_PROXY		The proxy server address is invalid.
	 * @exception		E_DNS				The DNS query has failed.
	 * @exception		E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @exception		E_EMPTY_BODY		The body is empty in a POST method case.
	 * @exception		E_INVALID_SESSION	The session is invalid.
	 * @exception		E_AUTHENTICATION	The authentication has failed.
	 * @exception		E_UNKNOWN			An unknown error has occurred.
	 * @exception		E_SYSTEM			A system error has occurred.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks			The appropriate request header and body must be set using HttpRequest before using this method.
	 *					If the session is in a non-pipeline mode, be sure not to submit a transaction before the previous transaction is completed.
	 * @see				HttpHeader
	 */
	result Submit(void);

	/**
	 * Gets the authentication information.
	 *
	 * @since       2.0
	 * @privilege	%http://tizen.org/privilege/http
	 *
	 * @return		A pointer to HttpAuthentication
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	HttpAuthentication* OpenAuthenticationInfoN(void);

	/**
	 * Gets a pointer to the HttpRequest related to the transaction. @n
	 * Setting a request header, method, URI, and body can be done by using the @c pHttpRequest pointer.
	 *
	 * @since       2.0
	 *
	 * @return		The HttpRequest object pointer, @n
	 *				else @c null in case of an invalid condition
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_STATE     The method invoked is invalid.
	 * @exception	E_INVALID_DATA      The request is not valid.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			Tizen::Net::Http::HttpRequest
	 */
	HttpRequest* GetRequest(void) const;

	/**
	 * Gets a pointer to the HttpResponse related to the transaction. @n
	 * Getting a response header and body can be done by using the @c pHttpResponse pointer.
	 *
	 * @since       2.0
	 *
	 * @return		The HttpResponse object pointer, @n
	 *				else @c null if the response is not received
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The method invoked is invalid.
	 * @exception	E_INVALID_DATA      The response is not received.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			HttpResponse
	 */
	HttpResponse* GetResponse(void) const;

	/**
	 * Adds the IHttpTransactionEventListener instance. @n
	 * The added listener can listen to events as they are fired.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	listener			The IHttpTransactionEventListener instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The method invoked is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_ALREADY_EXIST	The listener is already added.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, @n
	 * 									because the caller thread is a worker thread.
	 */
	result AddHttpTransactionListener(IHttpTransactionEventListener& listener);

	/**
	 * Removes the IHttpTransactionEventListener instance.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	listener			The IHttpTransactionEventListener instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The method invoked is invalid.
	 * @exception	E_OBJ_NOT_FOUND		The specified instance is not found within the indicated range, or
	 *									the listener is already removed.
	 */
	result RemoveHttpTransactionListener(IHttpTransactionEventListener& listener);

	/**
	 * Sets the IHttpProgressEventListener instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	listener			The IHttpProgressEventListener instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The method invoked is invalid.
	 */
	result SetHttpProgressListener(IHttpProgressEventListener& listener);

	/**
	 * Sets a user object to the instance of %HttpTransaction.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	pUserData			The user data to set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The method invoked is invalid.
	 */
	result SetUserObject(const Tizen::Base::Object* pUserData);

	/**
	 * Gets a user object that is set to the instance of %HttpTransaction.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 */
	Tizen::Base::Object* GetUserObject(void) const;

	/**
	 * Enables OnTransactionReadyToWrite.
	 *
	 * @since       2.0
	 *
	 * @return		@c true if the OnTransactionReadyToWrite listener is active, @n
	 *				else @c false
	 */
	bool EnableTransactionReadyToWrite(void);

	/**
	 * Resumes the transaction after the IHttpTransactionEventListener::OnTransactionCertVerificationRequiredN() event is invoked. @n
	 * As described in the IHttpTransactionEventListener section, the above event occurs in case of the uncertified server certificate.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The current state of the instance prohibits the execution of the specified operation.
	 */
	result Resume(void);

	/**
	 * Pauses the transaction after the IHttpTransactionEventListener::OnTransactionCertVerificationRequiredN() event is invoked. @n
	 * As described in the IHttpTransactionEventListener section, the above event occurs in case of the uncertified server certificate.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		The current state of the instance prohibits the execution of the specified operation.
	 */
	result Pause(void);

	/**
	 *	Sets a client certificate to connect the server.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	certificateId		The selected client certificate to set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks     Start the AppControl(L"tizen.certificatemanager") for getting the selected client certificate. @n
	 *              For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_certmgr.htm">here</a>.
	 */
	result SetClientCertificate(int certificateId);

	/**
	 *	Sets the timeout in seconds that is the timeout for waiting the transaction. @n
	 *	A timeout value of zero means an infinite timeout.
	 *
	 *  @since		2.0
	 *
	 *	@return		An error code
	 *  @param[in]	timeout					A timeout for transaction
	 *	@exception	E_SUCCESS				The method is successful.
	 *  @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 *  @exception	E_INVALID_STATE			The transaction is already submitted, or
	 *                                      the transaction is already closed.
	 */
	result SetTimeout(int timeout);

private:
	/**
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	HttpTransaction(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %HttpTransaction
	 */
	HttpTransaction(const HttpTransaction& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs				An instance of %HttpTransaction
	 */
	HttpTransaction& operator =(const HttpTransaction& rhs);

private:
	friend class _HttpTransactionImpl;
	_HttpTransactionImpl* __pHttpTransactionImpl;

}; // HttpTransaction

} } } // Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_TRANSACTION_H_
