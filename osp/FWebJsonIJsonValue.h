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
 * @file		FWebJsonIJsonValue.h
 * @brief		This is the header file for the %IJsonValue interface for the JSON (generic) value.
 *
 * This header file contains the definitions of the basic JSON types and declarations for
 * getting the type of a JSON value.
 */
#ifndef _FWEB_JSON_IJSON_VALUE_H_
#define _FWEB_JSON_IJSON_VALUE_H_

#include <FOspConfig.h>

namespace Tizen { namespace Web { namespace Json
{

/**
 * @enum JsonType
 *
 * Defines the JSON value types.
 *
 * @since	2.0
 */
enum JsonType
{
	JSON_TYPE_STRING,   /**< The JSON string type*/
	JSON_TYPE_NUMBER,   /**< The JSON number type*/
	JSON_TYPE_OBJECT,   /**< The JSON object type*/
	JSON_TYPE_ARRAY,    /**< The JSON array type*/
	JSON_TYPE_BOOL,     /**< The JSON bool type*/
	JSON_TYPE_NULL      /**< The JSON null type*/
};

/**
 * @interface	IJsonValue
 * @brief	This interface represents a Json value.
 *
 * @since	2.0
 *
 * The %IJsonValue interface abstracts a Json value class of a Json value type (string, bool, number, array, object, and null type).
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/json_namespace.htm">JSON Guide</a>.
 */
class _OSP_EXPORT_ IJsonValue
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IJsonValue(void) {}

	/**
	 * Gets the type of the object contained.
	 *
	 * @since	 2.0
	 *
	 * @return   The JSON type
	 */
	virtual JsonType GetType(void) const = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IJsonValue_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IJsonValue_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IJsonValue_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IJsonValue_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IJsonValue_Reserved5(void) {}

}; // IJsonValue

}}} // Tizen::Web::Json
#endif // _FWEB_JSON_IJSON_VALUE_H_
