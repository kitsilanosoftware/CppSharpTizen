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
 * @file		FWebJsonJsonParser.h
 * @brief		This is the header file for the %JsonParser class.
 *
 * This header file contains the declarations of the JSON functionalities for parsing the JSON-encoded file.
 */
#ifndef _FWEB_JSON_JSON_PARSER_H_
#define _FWEB_JSON_JSON_PARSER_H_

#include <FBaseByteBuffer.h>

namespace Tizen { namespace Web { namespace Json
{
class IJsonValue;
class _JsonParserImpl;
}}} // Tizen::Web::Json

namespace Tizen { namespace Web { namespace Json
{

/**
 * @class	JsonParser
 * @brief	This class contains the declarations of the JSON functionalities for parsing the JSON-encoded file.
 *
 * @since	2.0
 *
 * The %JsonParser class contains the declarations of the JSON functionalities for parsing the JSON-encoded files.
 * 
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/json_namespace.htm">JSON Guide</a>.
 *
 * The following example demonstrates how to use the %JsonParser methods.
 *
 * @code
 * Sample Data - JsonSample.json
 *	{"List": {
 *				"debug": "on",
 *				"window": {
 *							"title": "Is an Icon List",
 *							"name": "main_window",
 *							"width": 500,
 *							"height": 500
 *						},
 *				"image": {
 *							"src": "Images/fun.png",
 *							"name": "fun1"
 *						},
 *				"text": {
 *							"data": "Click Here",
 *							"size": 36,
 *							"style": "bold",
 *							"name": "text1"
 *						},
 *				"properties": [
 *								{"alignment" : "center"},
 *								{"transperancy":"80"}
 *							]
 *	}}
 *
 *	#include <FWebJson.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Utility;
 *	using namespace Tizen::Web::Json;
 *
 *	void
 *	MyClass::JsonParserSample(void)
 *	{
 *		// Parses from File
 *		String fileName(L"/Home/JsonSample.json");
 *		IJsonValue* pValue = JsonParser::ParseN(fileName);
 *		if( pValue == null )
 *		{
 *			AppLog("ErrorCode %s", GetLastResult());
 *		}
 *		else
 *		{
 *			// Uses the pValue to know what is the type
 *			if( pValue->GetType() == JSON_TYPE_OBJECT )
 *			{
 *				JsonObject* pJsonObj = static_cast<JsonObject*>(pValue);//use pJsonObj to access key-value pairs
 *				pJsonObj->RemoveAll(true);
 *			}
 *			else if( pValue->GetType() == JSON_TYPE_ARRAY )
 *			{
 *				JsonArray* pJsonArray = static_cast<JsonArray*>(pValue);//use pJsonArray to access values
 *				pJsonArray->RemoveAll(true);
 *			}
 *			delete pValue;
 *		}
 *
 *		// Parses from char*
 *		const char* jBuf = "{\"Key\":1,\"Key1\":{\"Key2\":\"val\",\"Key3\":\"val1\"},\"Key4\":[\"val2\",\"val3\"]}";
 *		String str(jBuf);
 *		int length = str.GetLength();
 *		IJsonValue* pValue1 = JsonParser::ParseN(jBuf, length);
 *
 *		// Converts the pValue1 to JsonObject
 *		JsonObject* pJsonObject = static_cast<JsonObject*>(pValue1);
 *		pJsonObject->RemoveAll(true);
 *		delete pJsonObject;
 *
 *		// Parses from ByteBuffer
 *		ByteBuffer *pBuf = StringUtil::StringToUtf8N( str );
 *		IJsonValue* pValue2 = JsonParser::ParseN(*pBuf);
 *
 *		// Converts the pValue2 to JsonObject
 *		pJsonObject = static_cast<JsonObject*>(pValue2);
 *		pJsonObject->RemoveAll(true);
 *		delete pJsonObject;
 *		delete pBuf;
 *	}
 * @endcode
 */
class _OSP_EXPORT_ JsonParser
{
public:
	/**
	 * Parses a JSON-encoded file to IJsonValue (node).
	 *
	 * @since			2.0
	 *
	 * @return                             A JSON value of type JsonArray or JsonObject, @n
	 *                                     else @c null if the JSON data of the file is invalid
	 * @param[in] filePath                 The path of the JSON-encoded file
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified file path is incorrect, or the file is not found.
	 * @exception	E_INVALID_DATA			The input JSON data is invalid, or the buffer is empty.
	 * @exception	E_MAX_EXCEEDED			The input JSON data exceeds the maximum length.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	 * @exception	E_FILE_NOT_FOUND		The specified @c filePath cannot be found.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static IJsonValue* ParseN(const Tizen::Base::String& filePath);

	/**
	 * Parses a JSON-encoded buffer to IJsonValue (node).
	 *
	 * @since			2.0
	 *
	 * @return                         A JSON value of type JsonArray or JsonObject, @n
	 *                                 else @c null if the JSON data of the file is invalid
	 * @param[in] pBuffer              A JSON-encoded buffer
	 * @param[in]	bufferLength	   A JSON-encoded buffer length
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			Either of the following conditions has occurred:
	 *									- The specified @c pBuffer is @c null.
	 *									- The specified @c bufferLength is zero or negative.
	 * @exception	E_INVALID_DATA			The input JSON data is invalid, or the buffer is empty.
	 * @exception	E_MAX_EXCEEDED			The input JSON data exceeds the maximum length.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static IJsonValue* ParseN(const void* pBuffer, int bufferLength);

	/**
	 * Parses a JSON-encoded Tizen::Base::ByteBuffer to IJsonValue (node).
	 *
	 * @since			2.0
	 *
	 * @return                                A JSON value of type JsonArray or JsonObject, @n
	 *                                        else @c null if the JSON data of the file is invalid
	 * @param[in] buffer                       A JSON-encoded byte buffer
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_DATA			The input JSON data is invalid, or the buffer is empty.
	 * @exception	E_MAX_EXCEEDED			The input JSON data exceeds the maximum length.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	static IJsonValue* ParseN(const Tizen::Base::ByteBuffer& buffer);

private:
	//
	// This default constructor is intentionally declared as private because this class cannot be constructed.
	//
	// @remarks		This constructor is hidden.
	//
	JsonParser(void);

	//
	// This is the destructor for this class.
	//
	// @remarks		This constructor is hidden.
	//
	virtual ~JsonParser(void);

private:
	_JsonParserImpl* __pJsonParserImpl;

	friend class _JsonParserImpl;
}; // JsonParser

}}} // Tizen::Web::Json
#endif // _FWEB_JSON_JSON_PARSER_H_
