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
 * @file			FSecSecretKey.h
 * @brief		This is the header file for the %SecretKey class.
 *
 * This header file contains the declarations of the %SecretKey class.
 */
#ifndef _FSEC_SECRET_KEY_H_
#define _FSEC_SECRET_KEY_H_

#include <FSecIKey.h>
#include <FSecISecretKey.h>


namespace Tizen { namespace Security
{

/**
 *	@class		SecretKey
 *	@brief		This class specifies a secret key.
 *
 * @since	    2.0
 *
 *  The %SecretKey class manages a secret key, which is used in symmetric ciphers, such as Advanced Encryption Standard (AES), Data Encryption Standard (DES), and Triple Data Encryption Standard (3DES). @n
 *
 *  For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 *	@see	    IKey
 *	@see	    ISecretKey
 *	@see	    SecretKeyGenerator
 *	@see	    ISecretKeyGenerator
 */
class _OSP_EXPORT_ SecretKey
	: public virtual IKey
	, public virtual ISecretKey
	, public Tizen::Base::Object
{

public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since      2.0
	 */
	SecretKey(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since      2.0
	 */
	virtual ~SecretKey(void);

	/**
	 *	Gets the name of the primary encoding format of the current instance of %SecretKey.
	 *
	 * @since       2.0
	 *
	 *	@return		The primary encoding format of a key
	 */
	virtual Tizen::Base::String GetFormat(void) const;

	/**
	 *	Gets the secret key in its primary encoding format.
	 *
	 *	@since           2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class, @n
	 *					else @c null if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetEncodedN(void) const;

	/**
	 *	Sets the secret key buffer.
	 *
	 *	@since           2.0
	 *
	 *	@return		An error code
	 *	@param[in]	keyBuffer				An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG           The specified @c keyBuffer is invalid.
	 */
	virtual result SetKey(const Tizen::Base::ByteBuffer& keyBuffer);

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	SecretKey(const SecretKey& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	SecretKey& operator =(const SecretKey& rhs);

private:
	Tizen::Base::ByteBuffer __keyBytes;

	class _SecretKeyImpl* __pSecretKeyImpl;
	friend class _SecretKeyImpl;

};  //SecretKey

} } // Tizen::Security

#endif //_FSEC_SECRET_KEY_H_
