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
 * @file		FNetHttpHttpResponse.h
 * @brief		This is the header file for the %HttpResponse class.
 *
 * This header file contains the declarations of the %HttpResponse class.
 */

#ifndef _FNET_HTTP_HTTP_RESPONSE_H_
#define _FNET_HTTP_HTTP_RESPONSE_H_

#include <FBaseColLinkedList.h>
#include <FNetHttpHttpTypes.h>
#include <FNetHttpHttpHeader.h>
#include <FNetHttpHttpMessage.h>
#include <FNetHttpHttpCookie.h>

namespace Tizen { namespace Net { namespace Http
{
class HttpTransaction;
class _HttpResponseImpl;
/**
 * @class	HttpResponse
 * @brief	This class represents a response message.
 *
 * @since   2.0
 *
 * The %HttpResponse class represents a response message that stores a status code, the status text, and the server version information, as well as
 * the message headers and body supplied by the HttpMessage base class.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_connectivity.htm">HTTP Guide</a>.
 *
 * The following example demonstrates how to use the %HttpResponse class.
 *
 * @code

    #include <FBase.h>
    #include <FNet.h>

    using namespace Tizen::Base;
    using namespace Tizen::Net::Http;

    void
    MyTransactionEventListener::OnTransactionReadyToRead(const Tizen::Net::Http::HttpSession& httpSession,
                             const Tizen::Net::Http::HttpTransaction& httpTransaction, int availableBodyLen)
    {
        HttpResponse* pResponse = httpTransaction.GetResponse();

        if (pResponse->GetHttpStatusCode() == HTTP_STATUS_OK)
        {
            ByteBuffer* pBody = null;
            String statusText = pResponse->GetStatusText();
            String version = pResponse->GetVersion();
            pBody = pResponse->ReadBodyN();
            delete pBody;
        }
    }

 * @endcode
 */
//////////////////////////////////////////////////////////////////////////
class _OSP_EXPORT_ HttpResponse
	: public HttpMessage
{

public:
	/**
	 * @if OSPDEPREC
	 * Gets the status code from the response header.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated. Instead of using this method, it is recommended to use the GetHttpStatusCode() method that returns the status code as an integer type.
	 * @since       2.0
	 *
	 * @return		The status code, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_STATE			Invoke this method before receiving a response header.
	 * @exception	E_INVALID_DATA			The status code is not defined.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The @c statusText gives a short textual description of the status code. It is placed after the status code on the first line of the
	 *				response. The specific error code can be accessed using the GetLastResult() method.
	 * @see			NetHttpStatusCode
	 * @see			SetStatusCode()
	 * @endif
	 */
	NetHttpStatusCode GetStatusCode(void) const;

	/**
	 * Gets the HTTP status code from the response header.
	 *
	 * @since       2.0
	 *
	 * @return		The status code, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_STATE				Invoke this method before receiving a response header.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The @c statusText gives a short textual description of the status code. It is placed after the status code on the first line of the
	 *				response.
	 * @see			SetHttpStatusCode()
	 */
	int GetHttpStatusCode(void) const;

	/**
	 * Gets a short textual description of the status code from the response header. @n
	 * This description is placed after the status code on the first line of the response.
	 *
	 * @since       2.0
	 *
	 * @return		The status description, @n
	 *				else an empty string when the status text is not defined
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_STATE				Invoke this method before receiving a response header.
	 * @exception	E_INVALID_DATA				The status text is not defined.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetStatusText()
	 */
	Tizen::Base::String GetStatusText(void) const;

	/**
	 * Gets the version of the protocol used by the server from the response header.
	 *
	 * @since       2.0
	 *
	 * @return		The protocol version, @n
	 *				else an empty string when the version is not defined
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_INVALID_STATE				Invoke this method before receiving a response header.
	 * @exception	E_INVALID_DATA				The version is not defined.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetVersion()
	 */
	Tizen::Base::String GetVersion(void) const;

	/**
	 * Gets the HttpHeader object of a response header.
	 *
	 * @since       2.0
	 *
	 * @return		The header object, @n
	 *				else @c null if the header is not received
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_HEADER			The header is @c null.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual HttpHeader* GetHeader(void) const;

	/**
	 * Gets the message body of the response.
	 *
	 * @since       2.0
	 *
	 * @return		The response body object
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			Invoke this method before receiving a response body.
	 * @exception	E_EMPTY_BODY			The requested body is empty.
	 * @exception	E_OUT_OF_RANGE			The specified @c data size exceeds the maximum range.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_IO					The method has failed to read the data.
	 * @exception	E_UNKNOWN				An unknown error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		This method can be invoked several times until there is no more data.
	 */
	virtual Tizen::Base::ByteBuffer* ReadBodyN(void);

	/**
	 * Gets the list of cookies received in the response.
	 *
	 * @since       2.0
	 *
	 * @return		A list containing HttpCookie instances, @n
	 *				else @c null if no cookie is received in the response
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The method invoked is invalid in this state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetCookies(void) const;

protected:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since       2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize the instance.
	 */
	HttpResponse(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~HttpResponse(void);

	/**
	 * Initializes this instance of %HttpResponse with the specified parameter.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	httpTransaction			The HTTP transaction
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_ARG			The specified input parameter is @c null.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result Construct(const HttpTransaction& httpTransaction);

protected:
	/**
	 * @if OSPDEPREC
	 * Sets the status code from the response header.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated This method is deprecated. Instead of using this method, it is recommended to use the SetHttpStatusCode() method that sets
	 * the status code as integer type.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	statusCode				The status code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @remarks		The @c statusCode element is a 3-digit integer result code of the attempt to understand and satisfy the request. The first digit of the
	 *				@c statusCode defines the class of response. The last two digits do not have any categorization role.
	 * @see			GetStatusCode()
	 * @endif
	 */
	result SetStatusCode(NetHttpStatusCode statusCode);

	/**
	 * Sets the status code from the response header.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	statusCode				The status code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @remarks		The @c statusCode element is a 3-digit integer result code of the attempt to understand and satisfy the request. The first digit of the
	 *				@c statusCode defines the class of response. The last two digits do not have any categorization role.
	 * @see			GetHttpStatusCode()
	 */
	result SetHttpStatusCode(int statusCode);

	/**
	 * Sets the status text from the response header.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	statusText				The status description
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is @c null.
	 * @remarks		The @c statusText gives a short textual description of the status code. This description is placed after the status code on the first
	 *				line of the response.
	 * @see			GetStatusText()
	 */
	result SetStatusText(const Tizen::Base::String& statusText);

	/**
	 * Sets the version of the protocol used by the server from the response header.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	httpVersion				The protocol version
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is @c null.
	 * @see			GetVersion()
	 */
	result SetVersion(const Tizen::Base::String& httpVersion);

	/**
	 * Sets the response body.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	body					The message body data
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE			The method invoked is invalid in this state.
	 * @remarks		This method can be invoked several times until there is no more data to write.
	 */
	virtual result WriteBody(const Tizen::Base::ByteBuffer& body);

	/**
	 * Reads the data from the data communicated.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	headerLen				The header length to read
	 * @param[in]	bodyLen					The body length to read
	 * @param[out]	rcvHeaderLen			The received header length
	 * @param[out]	rcvBodyLen				The received body length
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_IO					The method has failed to read the data.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_INVALID_SESSION		The session handle is invalid.
	 * @exception	E_INVALID_TRANSACTION	The transaction handle is invalid.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_OUT_OF_RANGE			The read data exceeds the maximum range.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *										The comparer has failed to compare keys.
	 * @exception	E_INVALID_HEADER        An invalid header is received in response.
	 */
	result Read(int headerLen, int bodyLen, int& rcvHeaderLen, int& rcvBodyLen);

	/**
	 * Saves the cookie received in the response to %HttpResponse.
	 *
	 * @since           2.0
	 *
	 * @return			An error code
	 * @param[in]		pHeader					A response header
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_STATE			The method invoked is invalid in this state.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks			Transaction events use this method to set the cookie received in the response.
	 * @see				GetCookies()
	 */
	result SetCookie(Tizen::Net::Http::HttpHeader* pHeader);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs   An instance of %HttpResponse
	 */
	HttpResponse(const HttpResponse& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs				An instance of %HttpResponse
	 */
	HttpResponse& operator =(const HttpResponse& rhs);

private:
	friend class _HttpResponseImpl;
	_HttpResponseImpl* __pHttpResponseImpl;

}; // HttpResponse

} } } // Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_RESPONSE_H_
