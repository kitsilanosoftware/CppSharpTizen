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
 * @file		FWebJsonJsonNull.h
 * @brief		This is the header file for the %JsonNull class.
 *
 * This header file contains the declarations of the %JsonNull class.
 * The class represents the JSON value of type @c null.
 */
#ifndef _FWEB_JSON_JSON_NULL_H_
#define _FWEB_JSON_JSON_NULL_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FWebJsonIJsonValue.h>

namespace Tizen { namespace Web { namespace Json
{
class _JsonNullImpl;
}}} // Tizen::Web::Json

namespace Tizen { namespace Web { namespace Json
{

/**
 * @class	JsonNull
 * @brief	This class represents the JSON value of type @c null.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %JsonNull class represents the JSON value of type @c null.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/json_namespace.htm">JSON Guide</a>.

 *
 */
class _OSP_EXPORT_ JsonNull
	: public IJsonValue
	, public Tizen::Base::Object
{
public:
	/**
	 * This is  the default constructor for this class.
	 *
	 * @since	2.0
	 */
	JsonNull(void);

	/**
	 * Copying of objects using this copy constructor is allowed. @n
	 * Initializes a new instance of %JsonNull to the specified @c value.
	 *
	 * @since	2.0
	 *
	 * @param[in]	value   An instance of %JsonNull
	 */
	JsonNull(const JsonNull& value);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~JsonNull(void);

	/**
	 *	Checks whether the value of the specified instance equals the value of the current instance.
	 *
	 *	@since		2.0
	 *
	 *	@return			             @c true if the value of the current instance equals the value of the specified instance, @n
	                                 else @c false
	 *	@param[in]	obj	             The object to compare with the current instance of %JsonNull
	 *	@remarks                     The method returns @c false if the specified object is not %JsonNull.
	 *  @see		Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 *	Gets the hash value of the current instance.
	 *
	 *	@since		2.0
	 *
	 *	@return		An integer value indicating the hash value of the current instance
	 *	@remarks    The two equal instances should return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 *				@n
	 *				The default implementation of this method returns the address of the current instance.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the type of the object (Always JSON_NULL)
	 *
	 * @since		2.0
	 *
	 * @return  The JSON type
	 */
	JsonType GetType(void) const;

	/**
	 *	Converts the value of the calling object from %JsonNull to a string.
	 *
	 *	@since	2.0
	 *
	 *	@return	A string representing the value of the current instance.
	 */
	Tizen::Base::String ToString(void) const;

	/**
	 * Assigns the value of the specified instance of %JsonNull to the current instance of %JsonNull.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs	An instance of %JsonNull
	 */
	JsonNull& operator =(const JsonNull& rhs);

	/**
	 *	Checks whether the values of the two %JsonNull objects are equal.
	 *
	 *	@since		2.0
	 *
	 *	@return			@c true if the values of the objects are equal, @n
	                    else @c false
	 *	@param[in]	rhs		A %JsonNull instance to compare with the current instance
	 */
	bool operator ==(const JsonNull& rhs) const;


	/**
	 *	Checks whether the values of the two %JsonNull objects are not equal.
	 *
	 *	@since		2.0
	 *
	 *	@return			    @c true if the values of the objects are not equal, @n
	                        else @c false
	 *	@param[in]	rhs		A %JsonNull instance to compare with the current instance
	 */
	bool operator !=(const JsonNull& rhs) const;

private:
	_JsonNullImpl* __pJsonNullImpl;

	friend class _JsonNullImpl;
}; // JsonNull

}}} // Tizen::Web::Json
#endif // _FWEB_JSON_JSON_NULL_H_
