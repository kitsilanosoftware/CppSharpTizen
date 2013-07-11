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
 * @file		FWebJsonJsonNumber.h
 * @brief		This is the header file for the %JsonNumber class.
 *
 * This header file contains the declarations of the %JsonNumber class.
 * The class represents the JSON value of type number.
 *
 */
#ifndef _FWEB_JSON_JSON_NUMBER_H_
#define _FWEB_JSON_JSON_NUMBER_H_

#include <FBaseDouble.h>
#include <FWebJsonIJsonValue.h>

namespace Tizen { namespace Web { namespace Json
{
class _JsonNumberImpl;
}}} // Tizen::Web::Json

namespace Tizen { namespace Web { namespace Json
{

/**
 * @class	JsonNumber
 * @brief	This class represents the JSON value of type number.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %JsonNumber class represents the type of the JSON number.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/json_namespace.htm">JSON Guide</a>.

 *
 */
class _OSP_EXPORT_ JsonNumber
	: public IJsonValue
	, public Tizen::Base::Double
{
public:
	/**
	 * Initializes this instance of %JsonNumber with the specified parameter.
	 *
	 * @since	2.0
	 *
	 * @param[in]	value   The value of type @c double
	 */
	JsonNumber(double value = 0.0L);

	/**
	 * Initializes this instance of %JsonNumber with the specified parameter.
	 *
	 * @since	2.0
	 *
	 * @param[in]	value   The value of type integer
	 */
	JsonNumber(int value);

	/**
	 * Copying of objects using this copy constructor is allowed. @n
	 * This constructor initializes a new instance of the %JsonNumber class with the value from another instance.
	 *
	 * @since			2.0
	 *
	 * @param[in]	value   An instance of JsonNumber
	 */
	JsonNumber(const JsonNumber& value);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~JsonNumber(void);

	/**
	 * Gets the type of JSON number.
	 *
	 * @since		2.0
	 *
	 * @return     The type of JSON number
	 * @see         JsonType
	 */
	JsonType GetType(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed. 
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs	An instance of %JsonNumber
	 */
	JsonNumber& operator =(const JsonNumber& rhs);

private:
	_JsonNumberImpl* __pJsonNumberImpl;

	friend class _JsonNumberImpl;
}; // JsonNumber

}}} // Tizen::Web::Json
#endif // _FWEB_JSON_JSON_NUMBER_H_
