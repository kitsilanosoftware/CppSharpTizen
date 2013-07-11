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
 * @file		FNetHttpHttpHeader.h
 * @brief		This is the header file for the %HttpHeader class.
 *
 * This header file contains the declarations of the %HttpHeader class.
 */

#ifndef _FNET_HTTP_HTTP_HEADER_H_
#define _FNET_HTTP_HTTP_HEADER_H_

#include <FBaseResult.h>
#include <FBaseString.h>
#include <FBaseColMultiHashMap.h>
#include <FBaseColIEnumerator.h>
#include <FNetHttpHttpTypes.h>

namespace Tizen { namespace Net { namespace Http
{
class _HttpHeaderImpl;
/**
 * @class	HttpHeader
 * @brief	This class encapsulates the header fields associated with a message.
 *
 * @since	2.0
 *
 *  The %HttpHeader class is a collection of header fields associated with an HTTP message. The header fields can be added, read, modified, and
 *	removed. Also, each field can have multiple values. This class provides easy access to the header.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_connectivity.htm">HTTP Guide</a>.
 */

class _OSP_EXPORT_ HttpHeader
	: public Tizen::Base::Object
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since           2.0
	 *
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	HttpHeader(void);

	/**
	 * Initializes an instance of %HttpHeader with the values of the specified instance.
	 *
	 * @since       2.0
	 *
	 * @param[in]	pHeader					An instance of %HttpHeader
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks		The parameter @c pHeader can be @c null.
	 *				The specific error code can be accessed using the GetLastResult() method.
	 */
	HttpHeader(const HttpHeader* pHeader);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~HttpHeader(void);

public:
	/**
	 * Adds a named field, which is a <@c fieldName, @c fieldValue> pair, to the current instance of %HttpHeader.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	fieldName				A field name
	 * @param[in]	fieldValue				A field value
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c fieldName is an empty string.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_OBJ_ALREADY_EXIST		The specified @c fieldName already exists. @n
	 *										The <@c fieldName, @c fieldValue> pair already exists.
	 * @remarks		The field is created on the first instance when this method is used for a particular field name.
	 *				On subsequent calls, the same field is extended to have several parts, with a new part created to hold the supplied value.
	 *				If you need to submit a request in the chunked mode, you need to explicitly add the header field named
	 *				"Transfer-Encoding" with the value @c chunked. Otherwise, the non-chunked mode is used as the default value.
	 * @see			RemoveField()
	 */
	result AddField(const Tizen::Base::String& fieldName, const Tizen::Base::String& fieldValue);

	/**
	 * Removes all the fields with the specified field name.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	fieldName				The field name to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c fieldName is an empty string.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c fieldName is not found in the current instance of %HttpHeader. @n
	 *										The header field with the specified @c fieldName is not found.
	 * @see				AddField()
	 */
	result RemoveField(const Tizen::Base::String& fieldName);

	/**
	 * Removes only the specified <@c fieldName, @c fieldValue> pair from the current instance of %HttpHeader.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	fieldName				The field name to remove
	 * @param[in]	fieldValue				The field value to remove with the specified @c fieldName
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c fieldName is an empty string.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c fieldName is not found in the current instance of %HttpHeader. @n
	 *						The header field with the specified field name and field value is not found.
	 * @see				AddField()
	 */
	result RemoveField(const Tizen::Base::String& fieldName, const Tizen::Base::String& fieldValue);

	/**
	 * Removes all the fields of the current instance of %HttpHeader.
	 *
	 * @since       2.0
	 */
	void RemoveAll(void);

	/**
	 * Gets a raw header string.
	 *
	 * @since           2.0
	 *
	 * @return			A raw header string
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception		E_INVALID_HEADER		This header object does not contain any header field.
	 * @exception		E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String* GetRawHeaderN(void) const;

	/**
	 * Gets a list of all the field names in the current instance of %HttpHeader.
	 *
	 * @since           2.0
	 *
	 * @return			A list that contains all the field names as string values
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception		E_INVALID_HEADER		This header object does not contain any header field.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetFieldNamesN(void) const;

	/**
	 * Gets the field values corresponding to the specified field name.
	 *
	 * @since       2.0
	 *
	 * @return		An enumerator containing all the string values of the specified field name
	 * @param[in]	fieldName				A field name
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c fieldName is an empty string.
	 * @exception	E_OBJ_NOT_FOUND			The specified @c fieldName is not found in the current instance of %HttpHeader. @n
	 *										The header field with the specified @c fieldName is not found.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IEnumerator* GetFieldValuesN(const Tizen::Base::String& fieldName) const;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs   An instance of %HttpHeader
	 */
	HttpHeader(const HttpHeader& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since       2.0
	 *
	 * @param[in]	rhs			An instance of %HttpHeader
	 */
	HttpHeader& operator =(const HttpHeader& rhs);

private:
	friend class _HttpHeaderImpl;
	_HttpHeaderImpl* __pHttpHeaderImpl;

}; // HttpHeader

} } } //Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_HEADER_H_
