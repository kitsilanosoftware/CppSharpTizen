//
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
 * @file			FSecPublicKey.h
 * @brief		This is the header file for the %PublicKey class.
 *
 * This header file contains the declarations of the %PublicKey class.
 */
#ifndef _FSEC_PUBLIC_KEY_H_
#define _FSEC_PUBLIC_KEY_H_

#include <FSecIKey.h>
#include <FSecIPublicKey.h>


namespace Tizen { namespace Security
{

/**
 *	@class		PublicKey
 *	@brief		This class specifies the RSA public key.
 *
 * @since       2.0
 *
 * The %PublicKey class manages a public key, which is used in asymmetric ciphers.
 * The RSA algorithm encrypts the data using the public key. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 *	@see	IKey
 *	@see	IPublicKey
 *	@see	IKeyPairGenerator
 */
class _OSP_EXPORT_ PublicKey
	: public virtual IKey
	, public virtual IPublicKey
	, public Tizen::Base::Object
{
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 * @since       2.0
	 */
	PublicKey(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~PublicKey(void);

	/**
	 *	Gets the name of the primary encoding format of the current instance of %PublicKey.
	 *
	 *	@since       2.0
	 *
	 *	@return		The primary encoding format of the key
	 */
	virtual Tizen::Base::String GetFormat(void) const;

	/**
	 *	Gets the public key in its primary encoding format.
	 *
	 *	@since           2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class, @n
	 *					else @c null if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetEncodedN(void) const;

	/**
	 *	Sets the public key buffer.
	 *
	 *	@since           2.0
	 *
	 *	@return		An error code
	 *	@param[in]	keyBuffer				An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c keyBuffer is invalid.
	 *	@remarks	Only ASN.1 encoding format is supported for input buffer.
	 */
	virtual result SetKey(const Tizen::Base::ByteBuffer& keyBuffer);

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	PublicKey(const PublicKey& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	PublicKey& operator =(const PublicKey& rhs);

private:
	Tizen::Base::String __algorithm;
	Tizen::Base::String __encodedFormat;
	Tizen::Base::ByteBuffer __keyBytes;

	class _PublicKeyImpl* __pPublicKeyImpl;
	friend class _PublicKeyImpl;

}; //PublicKey

} } //Tizen::Security

#endif //_FSEC_PUBLIC_KEY_H_
