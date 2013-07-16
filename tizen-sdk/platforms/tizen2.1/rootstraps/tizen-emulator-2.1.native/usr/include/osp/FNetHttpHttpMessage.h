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
 * @file		FNetHttpHttpMessage.h
 * @brief		This is the header file for the %HttpMessage class.
 *
 * This header file contains the declarations of the %HttpMessage class.
 */

#ifndef _FNET_HTTP_HTTP_MESSAGE_H_
#define _FNET_HTTP_HTTP_MESSAGE_H_

#include <FBaseByteBuffer.h>
#include <FBaseColQueue.h>
#include <FNetHttpHttpHeader.h>

namespace Tizen { namespace Net { namespace Http
{
class _HttpMessageImpl;
/**
 * @class	HttpMessage
 * @brief	This class is the base class for HttpRequest and HttpResponse.
 *
 * @since   2.0
 *
 * The %HttpMessage class represents the HTTP messages for the data exchanged between the client and the server, specifically for a request or a
 * response. Both message types consist of a start line, zero or more header fields, an empty line indicating the end of the header fields, and
 * possibly a message body.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_connectivity.htm">HTTP Guide</a>.
 */

class _OSP_EXPORT_ HttpMessage
	: public Tizen::Base::Object
{

protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	HttpMessage(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~HttpMessage(void);

protected:
	/**
	 * Writes the message body. @n
	 * The %WriteBody() method can be called several times consecutively. All the message bodies are stored in the queue.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	body						The message body data
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified @c body contains an invalid value.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_INVALID_SESSION			The session handle is invalid.
	 * @exception	E_INVALID_TRANSACTION		The transaction handle is invalid.
	 * @exception	E_OUT_OF_RANGE				The size of the specified body is out of range.
	 * @exception   E_INVALID_STATE				The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_UNKNOWN					An unknown error has occurred.
	 * @remarks		This method only considers the data between the position and the limit of the Tizen::Base::ByteBuffer as valid.
	 *				The position and limit has to be set appropriately before invoking this method.
	 * @see			ReadBodyN()
	 */
	virtual result WriteBody(const Tizen::Base::ByteBuffer& body) = 0;

protected:
	/**
	 * Gets the header. @n
	 * The %GetHeader() method is used to access the headers associated with a transaction request or response.
	 * The handle is obtained from either the HttpRequest or the HttpResponse objects associated with the transaction. Adding, modifying, or removing a
	 * header field is done using this header handle.
	 *
	 * @since       2.0
	 *
	 * @return		The pointer to HttpHeader that is to modify, @n
	 *				else @c null if %HttpMessage is not constructed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_HEADER	The header is @c null.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual HttpHeader* GetHeader(void) const = 0;

	/**
	 * Gets the body of the message associated with HttpRequest or HttpResponse.
	 *
	 * @since       2.0
	 *
	 * @return		The message body
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_STATE			The method invoked is invalid. @n
	 *										Invoke this method before receiving a response body.
	 * @exception	E_EMPTY_BODY			The requested body is empty.
	 * @exception	E_OUT_OF_RANGE			The size of the message body is out of range.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_IO					The method has failed to read the data.
	 * @exception	E_UNKNOWN				An unknown error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		Once this method is invoked, the returned message body is removed from the message body queue.
	 *				In other words, the message body queue does not hold all the bodies permanently.
	 * @see			WriteBody()
	 */
	virtual Tizen::Base::ByteBuffer* ReadBodyN(void) = 0;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs   An instance of %HttpMessage
	 */
	HttpMessage(const HttpMessage& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %HttpMessage
	 */
	HttpMessage& operator =(const HttpMessage& rhs);

protected:
	//
	//  This variable is for internal use only. Using this variable can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// The total length of the message body
	//
	// @since       2.0
	//
	unsigned int _totalLen;

	//
	//  This variable is for internal use only. Using this variable can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// The message queue
	//
	// @since       2.0
	//
	Tizen::Base::Collection::Queue _bodyQueue;

	//
	//  This variable is for internal use only. Using this variable can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// The header of the message
	//
	// @since       2.0
	//
	HttpHeader* _pHeader;

	friend class _HttpMessageImpl;
	_HttpMessageImpl* _pHttpMessageImpl;

}; // HttpMessage

} } } // Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_MESSAGE_H_
