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
 * This header file contains the declarations of JSON functionalities for composing JSON-encoded file.
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
 * The %JsonWriter class contains the declarations of JSON functionalities for composing JSON-encoded files.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/json_namespace.htm">JSON Guide</a>.
 *
 * The following example shows how to use %JsonWriter methods.
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
	 * Serializes the JSON-encoded data from %IJsonValue to a file.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since		2.0
	 * @if OSPCOMPAT
	 * @compatibility  This method has compatibility issues with OSP compatible applications. @n
	 * 			     				  For more information, see @ref CompIoPathPage "here".
	 * @endif
	 *
	 * @param[in]		pValue			JSON value to be encoded.
	 * @param[out]		filePath		The JSON file path
	 * @return		An error code
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_DATA		The specified @c pValue is @c null.
	 * @exception		E_INVALID_ARG		The specified @c filePath is incorrect.
	 * @exception		E_FAILURE		The method has failed.
	 */
	static result Compose(const IJsonValue* pValue, Tizen::Base::String& filePath);

	/**
	 * Serializes the JSON-encoded data from %IJsonValue to a buffer
	 *
	 * @since		2.0
	 *
	 * @param[in]		pValue			JSON value to be encoded.
	 * @param[in]		bufferLength		Json encoded data buffer length.
	 * @param[out]		pBuffer			The buffer with Json encoded data.
	 * @return		An error code
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_DATA		The specified @c pValue is @c null.
	 * @exception		E_FAILURE		The method has failed.
	 */
	static result Compose(const IJsonValue* pValue, void* pBuffer, int bufferLength);

	/**
	 * Serializes the JSON-encoded data from %IJsonValue to %ByteBuffer.
	 *
	 * @since		2.0
	 *
	 * @param[in]		pValue			JSON value to be encoded.
	 * @param[out]		buffer			The buffer with JSON-encoded data
	 * @return		An error code
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_DATA		The specified @c pValue is @c null.
	 * @exception		E_FAILURE		The method has failed.
	 * @remarks	ByteBuffer parameter has to be constructed with a non zero capacity before calling this method.
	 */
	static result Compose(const IJsonValue* pValue, Tizen::Base::ByteBuffer& buffer);

private:
	//
	// This default constructor is intentionally declared as private because this class cannot be constructed
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
