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
 * @file		FSecCryptoMd5Hmac.h
 * @brief		This is the header file for the %Md5Hmac class.
 *
 * This header file contains the declarations of the %Md5Hmac class.
 */
#ifndef _FSEC_CRYPTO_MD5_HMAC_H_
#define _FSEC_CRYPTO_MD5_HMAC_H_

#include <FSecCryptoIHmac.h>

struct hmac_ctx_st;


namespace Tizen { namespace Security { namespace Crypto
{

/**
 *	@class		Md5Hmac
 *	@brief		This class implements the MD5 HMAC algorithm.
 *
 *	@since		2.0
 *
 *  The %Md5Hmac class implements the basic hash procedure to encrypt messages using the Hash Message Authentication Code (HMAC) algorithm, which provides a hash with a secret key. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/hashing.htm">Hashing</a>.
 *
 *	@see  IHmac
 *  @see  Sha1Hmac
 *  @see  Sha2Hmac
 */
class _OSP_EXPORT_ Md5Hmac
	: public virtual IHmac
	, public Tizen::Base::Object
{

public:
	/**
	 *	This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	Md5Hmac(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~Md5Hmac(void);

	/**
	 *	Sets the HMAC algorithm. @n
	 *	The %SetAlgorithm() method is not supported by this class. Do not call this method.
	 *	If this method is called, it returns @c E_UNSUPPORTED_ALGORITHM.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	algorithm					The name of the HMAC algorithm @n
	 *											For example, "HMACSHA2/224", "HMACSHA2/256", "HMACSHA2/386", or "HMACSHA2/512".
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_UNSUPPORTED_ALGORITHM		The algorithm is not supported.
	 *  @remarks	Do not call this method. It is not supported.
	 */
	virtual result SetAlgorithm(const Tizen::Base::String& algorithm);

	/**
	 *	Sets the secret key.
	 *
	 * @since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	key						An instance of ISecretKey
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified key is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	virtual result SetKey(const Tizen::Security::ISecretKey& key);

	/**
	 *	Gets the HMAC with the specified input.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 *	@param[in]	input					An instance of Tizen::Base::ByteBuffer
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The input Tizen::Base::ByteBuffer is empty or contains invalid data.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the OpenSSL library, or
	 *										the Tizen::Base::ByteBuffer operation has failed.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetHmacN(const Tizen::Base::ByteBuffer& input) const;

	/**
	 *	Initializes a multiple-part HMAC operation.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_KEY_NOT_FOUND			The specified key is not found.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the OpenSSL library.
	 */
	virtual result Initialize(void);

	/**
	 *	Updates a multiple-part HMAC operation while processing another data part.
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
	 *	Finalizes a multiple-part HMAC operation.
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
	Md5Hmac(const Md5Hmac& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	Md5Hmac& operator =(const Md5Hmac& rhs);

private:
	hmac_ctx_st* __pMd5HmacCtx;
	Tizen::Base::ByteBuffer __keyBytes;

	class _Md5HmacImpl* __pMd5HmacImpl;
	friend class _Md5HmacImpl;

}; //Md5Hmac

} } } //Tizen::Security::Crypto

#endif //_FSEC_CRYPTO_MD5_HMAC_H_
