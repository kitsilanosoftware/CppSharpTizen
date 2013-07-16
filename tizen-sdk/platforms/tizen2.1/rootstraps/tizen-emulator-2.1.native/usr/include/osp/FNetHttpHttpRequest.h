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
 * @file		FNetHttpHttpRequest.h
 * @brief		This is the header file for the %HttpRequest class.
 *
 * This header file contains the declarations of the %HttpRequest class.
 */

#ifndef _FNET_HTTP_HTTP_REQUEST_H_
#define _FNET_HTTP_HTTP_REQUEST_H_

#include <FNetHttpHttpMessage.h>
#include <FNetHttpHttpTypes.h>
#include <FNetHttpHttpHeader.h>
#include <FNetHttpIHttpEntity.h>

namespace Tizen { namespace Net { namespace Http
{
class HttpTransaction;
class _HttpRequestImpl;

/////////////////////////////////////////////////////////////////////////////
/**
 * @class	HttpRequest
 * @brief	This class represents a request message.
 *
 * @since   2.0
 *
 * The %HttpRequest class represents an HTTP request message that stores a method (for example, HTTP GET), a URI, and the other message headers
 * and the body supplied by the HttpMessage base class.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_connectivity.htm">HTTP Guide</a>.
 *
 * The following example demonstrates how to use the %HttpRequest class.
 *
 * @code
 *
    #include <FBase.h>
    #include <FNet.h>

    using namespace Tizen::Base;
    using namespace Tizen::Net::Http;

    void
    TestHttpRequest(void)
    {
        result r = E_SUCCESS;
        HttpSession* pSession = null;
        HttpTransaction* pTransaction = null;
        String hostAddr(L"http://www.tizen.org");

        pSession = new HttpSession();
        r = pSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, null, hostAddr, null);

        pTransaction = pSession->OpenTransactionN();
        r = pTransaction->AddHttpTransactionListener(*this);

        // Get the request instance.
        HttpRequest* pRequest = pTransaction->GetRequest();

        // Set the method.
        NetHttpMethod method = NET_HTTP_METHOD_POST;
        r = pRequest->SetMethod(method);

        // Set the uri.
        r = pRequest->SetUri(L"http://www.tizen.org/test");

        HttpHeader* pHeader = null;
        pHeader = pRequest->GetHeader();

        // Add the content-length to header.
        r = pHeader->AddField(L"Content-Length", L"1024");
    }

 * @endcode
 */
class _OSP_EXPORT_ HttpRequest
	: public HttpMessage
{

public:
	/**
	 * Sets an HTTP method of the request header. @n
	 * The default method is @c NET_HTTP_METHOD_GET.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	method				An HTTP method
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception   E_INVALID_STATE		The corresponding transaction is already submitted.
	 * @remarks		The detailed descriptions of the HTTP methods are as follows: @n
	 *				1) The OPTIONS method represents a request for information about the communication options available on the request/response chain
	 *				identified by the Request-URI. This method may include a message body to make more detailed queries. To do so, specify the Content-Length
	 *				(or Transfer-Encoding), and Content-Type header fields. However, if the server does not support this, the server may discard the body. @n
	 *				2) The GET method retrieves whatever information is identified by the Request-URI. @n
	 *				3) The HEAD method is identical to GET except that the server must not return a response message body. The GET and HEAD methods do
	 *              not include a message body. @n
	 *				4) The POST method is used to request that the origin server accepts the entity enclosed in the request as a new subordinate of the
	 *				resource identified by the Request-URI. @n
	 *				5) The PUT method requests that the enclosed entity be stored under the supplied Request-URI. @n
	 *				When you are using the POST or PUT methods, be sure to specify the Content-Length header field, which is the message body length. @n
	 *				6) The DELETE method requests that the origin server deletes the resource identified by the Request-URI.
	 * @see			GetMethod()
	 */
	result SetMethod(NetHttpMethod method);

	/**
	 * Sets a custom method of the request header.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	method				An HTTP method
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception   E_INVALID_STATE		The corresponding transaction is already submitted.
	 * @remarks		This method can be used to user-defined methods as well as HTTP 1.1 methods like 'GET, PUT, POST, HEAD etc'.
	 * @see			GetCustomMethod()
	 */
	result SetCustomMethod(const Tizen::Base::String& method);

	/**
	 * Sets an HTTP version of the request header.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	version				An HTTP version
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception   E_INVALID_STATE		The corresponding transaction is already submitted.
	 * @see			GetVersion()
	 */
	result SetVersion(HttpVersion version);

	/**
	 * Sets a URI of the request header.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	uri					The raw URI @n
	 *									The URI must be a valid URI.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c uri is invalid.
	 * @exception   E_INVALID_STATE		The corresponding transaction is already submitted.
	 * @remarks		The URI must be encoded properly according to RFC 2396 before using this method.
	 *				The ending slash is a required part of a URL specifying a directory.
	 * @see			Tizen::Base::Utility::Uri
	 * @see			GetUri()
	 */
	result SetUri(const Tizen::Base::String& uri);

	/**
	 * Sets the request message body.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	body						The message body data
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_INVALID_SESSION			The session handle is invalid.
	 * @exception	E_INVALID_TRANSACTION		The transaction handle is invalid.
	 * @exception	E_OUT_OF_RANGE				The submitted body size is out of range.
	 * @exception	E_INVALID_STATE				Either of the following conditions has occurred: @n
	 *										  - The corresponding transaction is already submitted. @n
	 *										  - A chunked mode is not enabled.
	 * @exception	E_UNKNOWN					An unknown error has occurred.
	 * @remarks		This method can be used in two different situations. @n
	 *				@li Before submitting the request: @n
	 *				In this case, this method can be called several times consecutively, and all the bodies are appended together in the message queue until
	 *				the HttpTransaction::Submit() method is called. Set the message body, when the POST or PUT method is used. @n
	 *				@li After receiving an ADDCHUNK event: @n
	 *				In this case, this method must be invoked only once at a time. The recommended chunk size is given in IHttpTransactionEventListener::OnTransactionReadyToWrite().
	 * @see			SetMethod()
	 * @see			NetHttpMethod
	 */
	virtual result WriteBody(const Tizen::Base::ByteBuffer& body);

	/**
	 * Sets the request entity.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	entity						An instance of IHttpEntity to send
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_INVALID_SESSION			The session handle is invalid.
	 * @exception	E_INVALID_TRANSACTION		The transaction handle is invalid.
	 * @exception	E_OUT_OF_RANGE				The body size is out of range.
	 * @exception	E_INVALID_STATE				The WriteBody() method is already called.
	 * @remarks		The instance of IHttpEntity is used by the internal platform.
	 *              Do not delete or change the instance of %IHttpEntity before the IHttpTransactionEventListener::OnTransactionCompleted() or IHttpTransactionEventListener::OnTransactionAborted() method is called.
	 */
	result SetEntity(IHttpEntity& entity);

	/**
	 * Gets the HttpHeader object of the HTTP request.
	 *
	 * @since       2.0
	 *
	 * @return		The header object of the HTTP request, @n
	 *				else @c null if the header is not set properly
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_HEADER			The header is @c null.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		This method is used to access the header associated with a transaction's request. The handle is obtained from the %HttpRequest object
	 *				associated with the transaction. Adding, modifying, or removing a header field is done using this header handle.
	 */
	virtual HttpHeader* GetHeader(void) const;

	/**
	 * Sets the string to be sent in the cookie header field of %HttpRequest.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	cookieString			The cookie string @n
	 *										For example, Cookie: cookie-name1=cookie-value1;cookie-name2=cookie-value2.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The method invoked is invalid in this state.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result SetCookie(const Tizen::Base::String& cookieString);

	/**
	 * Gets the cookie header field of %HttpRequest.
	 *
	 * @since       2.0
	 *
	 * @return		The cookie string
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The cookie is empty.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetCookie(void) const;

	/**
	 * Sets the Accept-Encoding header field of %HttpRequest. @n
	 * This header can be used to specify certain Content-Encoding which are acceptable for the response.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	encoding					The accept encoding  @n
	 *											Three encodings ("identity", "gzip", "deflate") are supported. @n
	 *											If @c encoding is a empty string, an Accept-Encoding header containing all supported encodings will be set.
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified @c encoding is invalid.
	 * @exception	E_INVALID_STATE				The corresponding transaction is already submitted.
	 * @see			GetAcceptEncoding()
	 */
	result SetAcceptEncoding(const Tizen::Base::String& encoding);

protected:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since       2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 * @see			Construct()
	 */
	HttpRequest(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~HttpRequest(void);

	/**
	 * Initializes this instance of %HttpRequest with the specified parameters.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	httpTransaction				The HTTP transaction
	 * @param[in]	pCommonHeader				A header object that stores the common header
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is @c null.
	 * @exception	E_INVALID_OPERATION			The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred.
	 */
	result Construct(const HttpTransaction& httpTransaction, const HttpHeader* pCommonHeader);

	/**
	 * Gets an HTTP method of the request header.
	 *
	 * @since		2.0
	 *
	 * @return		HTTP method
	 * @see			SetMethod()
	 */
	NetHttpMethod GetMethod(void) const;

	/**
	 * Gets a custom method of the request header.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[out]	method				The name of custom method
	 * @exception	E_SUCCESS			The method is successful.
	 * @see			SetCustomMethod()
	 */
	result GetCustomMethod(Tizen::Base::String& method) const;

	/**
	 * Gets an HTTP version of the request header.
	 *
	 * @since       2.0
	 *
	 * @return		A version of HTTP
	 * @see			SetVersion()
	 */
	HttpVersion GetVersion(void) const;

	/**
	 * Gets a URI of the request header.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[out]	uri						The raw URI
	 * @exception	E_SUCCESS				The method is successful.
	 * @see			SetUri()
	 */
	result GetUri(Tizen::Base::String& uri) const;

	/**
	 * Gets the message body associated with an HTTP Request.
	 *
	 * @since       2.0
	 *
	 * @return		The response body object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_EMPTY_BODY			The requested body is empty.
	 * @exception	E_OUT_OF_MEMORY			The ByteBuffer size is smaller than the request body size.
	 * @exception   E_INVALID_STATE			The method invoked is invalid in this state.
	 * @exception	E_OUT_OF_RANGE			The @c data size exceeds the maximum range.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		Be sure to @c Flip() the @c body, which is Tizen::Base::ByteBuffer, before reading any data in the %Tizen::Base::ByteBuffer instance.
	 */
	virtual Tizen::Base::ByteBuffer* ReadBodyN(void);

	/**
	 * Gets the Accept-Encoding header field of %HttpRequest.
	 *
	 * @since		2.0
	 *
	 * @return		The accept encoding
	 *
	 * @see			SetAcceptEncoding()
	 */
	Tizen::Base::String GetAcceptEncoding(void) const;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs   An instance of %HttpRequest
	 */
	HttpRequest(const HttpRequest& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs				An instance of %HttpRequest
	 */
	HttpRequest& operator =(const HttpRequest& rhs);

private:
	friend class _HttpRequestImpl;
	_HttpRequestImpl* __pHttpRequestImpl;

}; // HttpRequest

} } } // Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_REQUEST_H_
