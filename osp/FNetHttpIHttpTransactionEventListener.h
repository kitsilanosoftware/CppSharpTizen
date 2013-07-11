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
 * @file		FNetHttpIHttpTransactionEventListener.h
 * @brief		This is the header file for the %IHttpTransactionEventListener interface.
 *
 * This header file contains the declarations of the %IHttpTransactionEventListener interface.
 */

#ifndef _FNET_HTTP_IHTTP_TRANSACTION_EVENT_LISTENER_H_
#define _FNET_HTTP_IHTTP_TRANSACTION_EVENT_LISTENER_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Net { namespace Http
{
class HttpSession;
class HttpTransaction;
/**
 * @interface	IHttpTransactionEventListener
 * @brief		This interface provides listeners for the HTTP transaction events.
 *
 * @since       2.0
 *
 * @remarks	If a user-defined class is derived from multiple classes including this interface, a compile error for using an ambiguous base class can occur. @n
 *          In this case, type casting is required to declare an explicit base class for the user-defined class.
 *
 * The %IHttpTransactionEventListener interface provides listeners for the HTTP transaction events. To use this listener, you must add it to the HttpTransaction instance
 * through the AddListener() method. If an HTTP transaction event is generated, a method of this class is called.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_transaction.htm">HTTP Transaction</a>.
 */

class _OSP_EXPORT_ IHttpTransactionEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since   2.0
	 */
	virtual ~IHttpTransactionEventListener(void) {}

public:
	/**
	 * Called to notify when the content body of the response has been received.
	 *
	 * @since       2.0
	 *
	 * @param[in]	httpSession					The session information of the %Http transaction event
	 * @param[in]	httpTransaction				The transaction information of the %Http transaction event
	 * @param[in]	availableBodyLen			The length of the available body of the %Http transaction
	 * @see			HttpResponse::ReadBodyN()
	 */
	virtual void OnTransactionReadyToRead(HttpSession& httpSession, HttpTransaction& httpTransaction, int availableBodyLen) = 0;

	/**
	 * Called to notify when the process of transaction has been aborted.
	 *
	 * @since       2.0
	 *
	 * @param[in]	httpSession					The session information of the %Http transaction event
	 * @param[in]	httpTransaction				The transaction information of the %Http transaction event
	 * @param[in]	r							The cause of the error
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_IO						The method has failed to read the data.
	 * @exception	E_TIMEOUT					An attempt to connect to the server has timed out.
	 * @exception	E_NETWORK_UNAVAILABLE		The network is unavailable.
	 * @exception	E_HOST_UNREACHABLE			The network cannot be reached from this host at this time.
	 * @exception	E_SYSTEM					An internal error has occurred.
	 * @exception	E_UNKNOWN					An unknown error has occurred.
	 * @exception	E_NOT_RESPONDING			There is no response.
	 * @exception	E_INVALID_CONTENT			The content is invalid.
	 * @exception	E_CONNECTION_RESET			The network connection has been reset.
	 * @exception	E_HTTP_USER					The HTTP user is canceled.
	 * @exception	E_NO_CERTIFICATE			The client certificate is required to connect to the server.
	 * @exception	E_UNSUPPORTED_SERVICE		The service is not allowed.
	 * @exception	E_USER_AGENT_NOT_ALLOWED	The user agent is not allowed.
	 * @exception	E_RESOURCE_UNAVAILABLE		The network resource is unavailable.
	 * @remarks     If the E_NO_CERTIFICATE exception is thrown, start the AppControl(L"tizen.certificatemanager") for getting the selected client certificate. @n
	 *              For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_certmgr.htm">here</a>.
	 */
	virtual void OnTransactionAborted(HttpSession& httpSession, HttpTransaction& httpTransaction, result r) = 0;

	/**
	 * Called to add chunks to the request.
	 *
	 * @since       2.0
	 *
	 * @param[in]	httpSession					The session information of the %Http transaction event
	 * @param[in]	httpTransaction				The transaction information of the %Http transaction event
	 * @param[in]	recommendedChunkSize		The length of the chunked %Http transaction
	 * @remarks     To enable this listener, HttpTransaction::EnableTransactionReadyToWrite() must be called.
	 * @see			HttpRequest::WriteBody()
	 */
	virtual void OnTransactionReadyToWrite(HttpSession& httpSession, HttpTransaction& httpTransaction, int recommendedChunkSize) = 0;

	/**
	 * Called to notify when the header of response has been received.
	 *
	 * @since       2.0
	 *
	 * @param[in]	httpSession					The session information of the %Http transaction event
	 * @param[in]	httpTransaction				The transaction information of the %Http transaction event
	 * @param[in]	headerLen					The length of the %Http transaction's header
	 * @param[in]	bAuthRequired				Set to @c true if the transaction requires authentication, @n
	 *											else @c false
	 * @see			HttpResponse::GetHeader()
	 */
	virtual void OnTransactionHeaderCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction, int headerLen, bool bAuthRequired) = 0;

	/**
	 * Called to notify when the process of transaction has been completed.
	 *
	 * @since       2.0
	 *
	 * @param[in]	httpSession					The session information of the %Http transaction event
	 * @param[in]	httpTransaction				The transaction information of the %Http transaction event
	 * @see			HttpResponse::GetHeader()
     * @see     	HttpResponse::ReadBodyN()
	 */
	virtual void OnTransactionCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction) = 0;

	/**
	 * Called to accept input from the user on whether to resume or pause the transaction in case the certificate is not verified.
	 *
	 * @since           2.0
	 *
	 * @param[in]		httpSession				The session information of the %Http transaction event
	 * @param[in]		httpTransaction			The transaction information of the %Http transaction event
	 * @param[in]		pCert					The certificate information
	 * @see				HttpTransaction::Resume()
     * @see         	HttpTransaction::Pause()
	 */
	virtual void OnTransactionCertVerificationRequiredN(HttpSession& httpSession, HttpTransaction& httpTransaction, Tizen::Base::String* pCert) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IHttpTransactionEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IHttpTransactionEventListener_Reserved2(void) {}

};

} } } // Tizen::Net::Http
#endif // _FNET_HTTP_IHTTP_TRANSACTION_EVENT_LISTENER_H_
