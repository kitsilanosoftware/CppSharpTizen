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
 *	@file		FSecCryptoSha1Hash.h
 *	@brief		This is the header file for the %Sha1Hash class.
 *
 *	This header file contains the declarations of the %Sha1Hash class.
 */
#ifndef _FSEC_CRYPTO_SHA1_HASH_H_
#define _FSEC_CRYPTO_SHA1_HASH_H_

#include <FSecCryptoIHash.h>

struct env_md_ctx_st;


namespace Tizen { namespace Security { namespace Crypto
{

/**
 *	@class		Sha1Hash
 *	@brief		This class implements the SHA-1 hash algorithm.
 *
 *	@since		2.0
 *
 *	The %Sha1Hash class implements the SHA-1 hash algorithm. @n
 *
 *  For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/hashing.htm">Hashing</a>.
 *
 *	@see	IHash
 *	@see	Md5Hash
 *	@see	Sha2Hash
 */
class _OSP_EXPORT_ Sha1Hash
	: public virtual IHash
	, public Tizen::Base::Object
{

public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since		2.0
	 */
	Sha1Hash(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since		2.0
	 */
	virtual ~Sha1Hash(void);

	/**
	 *	Sets the hash algorithm. @n
	 *	The %SetAlgorithm() method is not supported by this class. Do not call this method. @n
	 *	If this method is called, it returns @c E_UNSUPPORTED_ALGORITHM.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	algorithm				The name of the hash algorithm @n
	 *										For example "SHA2/224", "SHA2/256", "SHA2/386", or "SHA2/512".
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The algorithm is not supported.
	 *	@remarks	Do not call this method. It is not supported.
	 */
	virtual result SetAlgorithm(const Tizen::Base::String& algorithm);

	/**
	 *	Gets the hashes of a data (single-part).
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	input					An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the OpenSSL library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetHashN(const Tizen::Base::ByteBuffer& input) const;

	/**
	 *	Initializes a multiple-part hash operation.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the OpenSSL library.
	 */
	virtual result Initialize(void);

	/**
	 *	Updates a multiple-part hash operation while processing another data part.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	input					An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the OpenSSL library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 */
	virtual result Update(const Tizen::Base::ByteBuffer& input);

	/**
	 *	Finalizes a multiple-part hash operation.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the OpenSSL library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* FinalizeN(void);

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	Sha1Hash(const Sha1Hash& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	Sha1Hash& operator =(const Sha1Hash& rhs);

private:
	env_md_ctx_st* __pEvpMdCtx;

	class _Sha1HashImpl* __pSha1HashImpl;
	friend class _Sha1HashImpl;

}; //Sha1Hash

} } } //Tizen::Security::Crypto

#endif //_FSEC_CRYPTO_SHA1_HASH_H_
