//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
 * @file		FSecPkcsPkcs08AttributeValue.h
 * @brief		This is the header file for the %Pkcs08AttributeValue class.
 *
 * This header file contains the declarations of the %Pkcs08AttributeValue class.
 */

#ifndef _FSEC_PKCS_PKCS_08_ATTRIBUTE_VALUE_H_
#define _FSEC_PKCS_PKCS_08_ATTRIBUTE_VALUE_H_

#include <FBaseByteBuffer.h>
#include <FBaseResult.h>
#include <FSecPkcsTypes.h>

namespace Tizen { namespace Security { namespace Pkcs
{

/**
 * @class		Pkcs08AttributeValue
 * @brief		This class implements the functionalities specified by the %Pkcs08AttributeValue class.
 * 
 * @since		2.1
 *
 * The %Pkcs08AttributeValue class implements the functionalities specified by the %Pkcs08AttributeValue class.
 * The %Pkcs08AttributeValue object consists of an attribute value and a tag value.
 *
 */
class _OSP_EXPORT_ Pkcs08AttributeValue
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.1
	 */
	Pkcs08AttributeValue(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~Pkcs08AttributeValue(void);

	/**
	 * Initializes this instance of %Pkcs08AttributeValue with the Tizen::Base::ByteBuffer that contains the AttributeValue @n
	 * (contain tag, that is, Ans1_Type and the value).
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	encodedData				The DER encoded Tizen::Base::ByteBuffer of AttributeValue
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& encodedData);

	/**
	 * Initializes this instance of %Pkcs08AttributeValue with the specified parameters. @n
	 * The %Construct() method initializes the attribute value instance based on the byte buffer passed.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	value					An instance of Tizen::Base::ByteBuffer holding raw value
	 * @param[in]	tag						A tag holding the tag type @n This tag number is assigned by ASN1 standards for @n
	 *													basic data types.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& value, const Pkcs08TagValue tag);

	/**
	 * Gets a reference to Tizen::Base::ByteBuffer that contains the attribute value.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to Tizen::Base::ByteBuffer containing raw value
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const Tizen::Base::ByteBuffer& GetValue(void) const;

	/**
	 * Gets the tag value of an attribute. @n
	 * This tag number is assigned by ASN1 standards for basic data types.
	 *
	 * @since		2.1
	 *
	 * @return		The tag value that is assigned by ASN1 standards for basic data types
	 */
	Pkcs08TagValue GetTag(void) const;

	/**
	 * Gets a pointer to Tizen::Base::ByteBuffer that contains the attribute value in encoded format. @n
	 * It is assumed that each Pkcs08Attribute will have only a single form of encoding, for example, ASN.1 DER.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *						else @c null if an error occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* GetEncodedDataN(void) const;

private:
	// This copy constructor is intentionally declared as private to prohibit @n
	// copying of objects by users.
	//
	// @since		2.1
	Pkcs08AttributeValue(const Pkcs08AttributeValue& rhs);

	// The implementation of this copy assignment operator is intentionally blank and @n
	// declared as private to prohibit copying of objects.
	//
	// @since		2.1
	Pkcs08AttributeValue& operator =(const Pkcs08AttributeValue& rhs);

private:
	class _Pkcs08AttributeValueImpl* __pPkcs08AttributeValueImpl;
	friend class _Pkcs08AttributeValueImpl;

}; //Pkcs08AttributeValue

}}} //Tizen::Security::Pkcs

#endif // _FSEC_PKCS_PKCS_08_ATTRIBUTE_VALUE_H_
