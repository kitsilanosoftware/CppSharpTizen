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
 * @file		FWebJsonJsonBool.h
 * @brief		This is the header file for the %JsonBool class.
 *
 * This header file contains the declarations of the %JsonBool class.
 * This class represents the JSON value of type @c bool.
 */
#ifndef _FWEB_JSON_JSON_BOOL_H_
#define _FWEB_JSON_JSON_BOOL_H_

#include <FBaseBoolean.h>
#include <FBaseString.h>
#include <FWebJsonIJsonValue.h>

namespace Tizen { namespace Web { namespace Json
{
class _JsonBoolImpl;
}}} // Tizen::Web::Json

namespace Tizen { namespace Web { namespace Json
{

/**
 * @class	JsonBool
 * @brief	This class represents the JSON value of type @c bool.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %JsonBool class represents the JSON value of type @c bool.
 * 
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/json_namespace.htm">JSON Guide</a>.
 *
 *
 */
class _OSP_EXPORT_ JsonBool
	: public IJsonValue
	, public Tizen::Base::Boolean
{
public:
	/**
	 * Initializes this instance of %JsonBool with the specified parameter.
	 *
	 * @since	2.0
	 *
	 * @param[in]	value   The input bool value to initialize the %JsonBool object
	 */
	JsonBool(bool value);

	/**
	 * Initializes a new boolean object to the input string represented by @c value. @n
	 * If the input string is "true" (value is case insensitive), the object is initialized to @c true,
	 * else, the value is initialized to @c false.
	 *
	 * @since	2.0
	 *
	 *  @param[in]	value   An instance of Tizen::Base::String
	 */
	JsonBool(const Tizen::Base::String& value);

	/**
	 * Initializes this instance of %JsonBool with the specified parameter.
	 *
	 *  @since			2.0
	 *
	 * @param[in]	value   A boolean value to initialize the %JsonBool instance
	 */
	JsonBool(const Boolean& value);

	/**
	 * Copying of objects using this copy constructor is allowed. @n
	 * Initializes a new instance of the %JsonBool class to the specified @c value.
	 *
	 *  @since			2.0
	 *
	 * @param[in]	value   An instance of %JsonBool
	 */
	JsonBool(const JsonBool& value);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *  @since			2.0
	 */
	virtual ~JsonBool(void);

	/**
	 * Gets the type of this class (always @c JSON_BOOL).
	 *
	 * @since		2.0
	 *
	 * @return  The JSON type
	 * @see         JsonType
	 */
	JsonType GetType(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs	An instance of %JsonBool
	 */
	JsonBool& operator =(const JsonBool& rhs);

private:
	_JsonBoolImpl* __pJsonBoolImpl;

	friend class _JsonBoolImpl;
}; // JsonBool

}}} // Tizen::Web::Json
#endif // _FWEB_JSON_JSON_BOOL_H_
