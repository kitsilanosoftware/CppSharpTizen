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
 * @file		FWebJsonJsonString.h
 * @brief		This is the header file for the %JsonString class.
 *
 * This header file contains the declarations of the %JsonString class.
 * The class represents the JSON value of type string.
 */
#ifndef _FWEB_JSON_JSON_STRING_H_
#define _FWEB_JSON_JSON_STRING_H_

#include <FBaseString.h>
#include <FWebJsonIJsonValue.h>

namespace Tizen { namespace Web { namespace Json
{
class _JsonStringImpl;
}}} // Tizen::Web::Json

namespace Tizen { namespace Web { namespace Json
{

/**
 * @class	JsonString
 * @brief	This class represents the JSON value of type string.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %JsonString class represents the JSON value of type string.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/json_namespace.htm">JSON Guide</a>.

 *
 */
class _OSP_EXPORT_ JsonString
	: public IJsonValue
	, public Tizen::Base::String
{
public:
	/**
	 * Initializes this instance of %JsonString with the specified parameter.
	 *
	 * @since		2.0
	 *
	 * @param[in]	pValue	A pointer to an array of UTF-8 characters
	 */
	JsonString(const char* pValue);

	/**
	 * Initializes this instance of %JsonString with the specified parameter.
	 *
	 * @since		2.0
	 *
	 * @param[in]	value	A reference to %String
	 */
	JsonString(const Tizen::Base::String& value);

	/**
	 *	Initializes this instance of %JsonString with the specified Unicode string.
	 *
	 *  @since		2.0
	 *
	 *  @param[in]	pValue		A pointer to an array of Unicode characters
	 */
	JsonString(const wchar_t* pValue);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs	An instance of %JsonString
	 */
	JsonString(const Tizen::Web::Json::JsonString& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~JsonString(void);

	/**
	 * Gets the type of the JSON string.
	 *
	 * @since		2.0
	 *
	 * @return      The type of the JSON string
	 * @see         JsonType
	 */
	JsonType GetType(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed. 
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs A reference to the %JsonString instance to copy
	 */
	JsonString& operator =(const Tizen::Web::Json::JsonString& rhs);

private:
	_JsonStringImpl* __pJsonStringImpl;

	friend class _JsonStringImpl;
}; // JsonString

}}} // Tizen::Web::Json
#endif // _FWEB_JSON_JSON_STRING_H_
