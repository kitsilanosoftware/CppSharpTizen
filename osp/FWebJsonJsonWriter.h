//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
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
 * @file		FWebJsonJsonWriter.h
 * @brief		This is the header file for composing a JSON-encoded file.
 *
 * This header file contains the declarations of the JSON functionalities for composing JSON-encoded file.
 */
#ifndef _FWEB_JSON_JSON_WRITER_H_
#define _FWEB_JSON_JSON_WRITER_H_

#include <FBaseString.h>
#include <FBaseByteBuffer.h>

namespace Tizen { namespace Web { namespace Json
{
class IJsonValue;
class _JsonWriterImpl;
}}} // Tizen::Web::Json

namespace Tizen { namespace Web { namespace Json
{

/**
 * @class	JsonWriter
 * @brief	This class contains the declarations of the JSON functionalities for composing JSON-encoded file.
 *
 * @since	2.0
 *
 * The %JsonWriter class contains the declarations of the JSON functionalities for composing JSON-encoded files.
 * 
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/json_namespace.htm">JSON Guide</a>.
 *
 * The following example demonstrates how to use the %JsonWriter methods.
 *
 * @code
 *	#include <FWebJson.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Web::Json;
 *
 *	void
 *	MyClass::JsonWriterSample(void)
 *	{
 *		String *pKey1 = new String(L"Key1");
 *		String *pKey2 = new String(L"Key2");
 *		JsonString *pJsonValue1 = new JsonString(L"Value1");
 *		JsonString *pJsonValue2 = new JsonString(L"Value2");
 *		JsonObject *pJsonObject = new JsonObject();
 *		pJsonObject->Construct();
 *		pJsonObject->Add(pKey1, pJsonValue1);
 *		pJsonObject->Add(pKey2, pJsonValue2);
 *
 *		//Composes to File
 *		String fileName(L"/Home/JsonComposeSample.json");
 *		result r = JsonWriter::Compose( pJsonObject, fileName );
 *		if( r != E_SUCCESS )
 *		{
 *			AppLog("Compose failed");
 *		}
 *
 *		//Composes to char*
 *		char* pComposeBuf = new char[40];
 *		r = JsonWriter::Compose( pJsonObject, pComposeBuf, 40 );
 *
 *		//Composes to ByteBuffer
 *		ByteBuffer *pBuffer = new ByteBuffer();
 *		pBuffer->Construct(40);
 *		r = JsonWriter::Compose(pJsonObject, *pBuffer);
 *
 *		pJsonObject->RemoveAll(true);
 *		delete pJsonObject;
 *		delete pBuffer;
 *	}
 * @endcode
 */
class _OSP_EXPORT_ JsonWriter
{
public:
	/**
	 * Serializes the JSON-encoded data from IJsonValue to a file.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]		pValue			The JSON value to encode
	 * @param[out]		filePath		The JSON file path
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_DATA		The specified @c pValue is @c null.
	 * @exception		E_INVALID_ARG		The specified @c filePath is incorrect.
	 * @exception		E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	 * @exception		E_STORAGE_FULL		The disk space is full.
	 * @exception		E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result Compose(const IJsonValue* pValue, Tizen::Base::String& filePath);

	/**
	 * Serializes the JSON-encoded data from IJsonValue to a buffer.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]		pValue			The JSON value to encode
	 * @param[in]		bufferLength		The JSON-encoded data buffer length
	 * @param[out]		pBuffer			The buffer with JSON-encoded data
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_ARG	Either of the following conditions has occurred:
	 *								- The specified @c pBuffer is @c null.
	 *								- The specified bufferLength is negative.
	 * @exception		E_INVALID_DATA		The specified @c pValue is @c null.
	 */
	static result Compose(const IJsonValue* pValue, void* pBuffer, int bufferLength);

	/**
	 * Serializes the JSON-encoded data from IJsonValue to Tizen::Base::ByteBuffer.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]		pValue			The JSON value to encode
	 * @param[out]		buffer			The buffer with JSON-encoded data
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_DATA		The specified @c pValue is @c null.
	 * @remarks	The ByteBuffer parameter has to be constructed with a non-zero capacity before calling this method.
	 */
	static result Compose(const IJsonValue* pValue, Tizen::Base::ByteBuffer& buffer);

	/**
	 * Serializes the JSON-encoded data from IJsonValue to Tizen::Base::ByteBuffer with unescaped wide characters.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]		pValue			The JSON value to encode
	 * @param[out]		buffer			The buffer with JSON-encoded data
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_DATA		The specified @c pValue is @c null.
	 * @remarks	The ByteBuffer parameter has to be constructed with a non-zero capacity before calling this method.
	 */
	static result ComposeUnescapeUnicode(const IJsonValue* pValue, Tizen::Base::ByteBuffer& buffer);

private:
	//
	// This default constructor is intentionally declared as private because this class cannot be constructed.
	//
	// @remarks		This constructor is hidden.
	//
	JsonWriter(void);

	//
	// This is the destructor for this class.
	//
	// @remarks		This constructor is hidden.
	//
	virtual ~JsonWriter(void);

private:
	_JsonWriterImpl* __pJsonWriterImpl;

	friend class _JsonWriterImpl;
}; // JsonWriter

}}} // Tizen::Web::Json
#endif // _FWEB_JSON_JSON_WRITER_H_
