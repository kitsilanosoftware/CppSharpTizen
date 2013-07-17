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
 * @file		FSecPkcsPkcs08Attribute.h
 * @brief		This is the header file for the %Pkcs08Attribute class.
 *
 * This header file contains the declarations of the %Pkcs08Attribute class.
 */

#ifndef _FSEC_PKCS_PKCS_08_ATTRIBUTE_H_
#define _FSEC_PKCS_PKCS_08_ATTRIBUTE_H_

#include <FBaseByteBuffer.h>
#include <FBaseResult.h>
#include <FSecPkcsPkcs08AttributeValue.h>

namespace Tizen { namespace Security { namespace Pkcs
{

/**
 * @class		Pkcs08Attribute
 * @brief		This class implements the functionalities specified by the %Pkcs08Attribute class.
 *
 * @since		2.1
 *
 * The %Pkcs08Attribute class implements the functionalities specified by the %Pkcs08Attribute class. An Attribute object consists
 *					of an attribute type (specified by an object identifier) and one or more attribute values. It acts as a
 *					container for adding, inserting, removing, and encoding X.509 AttributeValue.
 *
 */

class _OSP_EXPORT_ Pkcs08Attribute
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.1
	 */
	Pkcs08Attribute(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~Pkcs08Attribute(void);

	/**
	 * Initializes this instance of %Pkcs08Attribute with the Tizen::Base::ByteBuffer that contains the X.509 attribute @n
	 * structure in ASN.1 DER format.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	encodedData				The DER encoded Tizen::Base::ByteBuffer containing the X.509 attribute structure
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::ByteBuffer& encodedData);

	/**
	 * Initializes this instance of %Pkcs08Attribute with the specified attribute type.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	attributeType			The object identifier of a particular X.509 attribute type @n Object IDs (for example, oid for name is 2.5.4.41) are defined by standard attribute bodies.
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result Construct(const Tizen::Base::String& attributeType);

	/**
	 * Gets the attribute type. @n
	 * The %GetAttributeType() method implements GetAttributeType that returns the attribute type of this attribute instance.
	 *
	 * @since		2.1
	 *
	 * @return		Containing the object ID of attribute type in string format like 2.5.4.41
	 *
	 */
	Tizen::Base::String GetAttributeType(void) const;

	/**
	 * Adds an attribute value in the attribute value list.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	attributeValue			An instance of Pkcs08AttributeValue to add an attribute in the list
	 */
	result AddAttributeValue(const Pkcs08AttributeValue& attributeValue);

	/**
	 * Removes an attribute value from the attribute value list.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	attributeValue			An instance of Pkcs08AttributeValue to remove an attribute from the list
	 */
	result RemoveAttributeValue(const Pkcs08AttributeValue& attributeValue);

	/**
	 * Returns an array list containing the attribute values of type Pkcs08AttributeValue.
	 *
	 * @since		2.1
	 *
	 * @return		A reference to an ArrayList containing the list of attribute values
	 */
	const Tizen::Base::Collection::ArrayList& GetAttributeValues(void) const;

	/**
	 * Gets the encoded form of Pkcs08Attribute.
	 * It is assumed that each %Pkcs08Attribute will have only a single form of encoding, for example ASN.1 DER.
	 *
	 * @since		2.1
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *						else @c null if an error occurs
	 *
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_SYSTEM						The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* GetEncodedDataN(void) const;

private:
	// This copy constructor is intentionally declared as private to prohibit @n
	// copying of objects by users.
	//
	// @since		2.1
	Pkcs08Attribute(const Pkcs08Attribute& rhs);

	// The implementation of this copy assignment operator is intentionally blank and @n
	// declared as private to prohibit copying of objects.
	//
	// @since		2.1
	Pkcs08Attribute& operator =(const Pkcs08Attribute& rhs);

private:
	class _Pkcs08AttributeImpl* __pPkcs08AttributeImpl;
	friend class _Pkcs08AttributeImpl;

}; //Pkcs08Attribute

}}} // Tizen::Security::Pkcs

#endif // _FSEC_PKCS_PKCS_08_ATTRIBUTE_H_
