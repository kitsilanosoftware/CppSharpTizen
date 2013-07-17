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
 * @file			FSecAesSecureRandom.h
 * @brief		This is the header file for the %AesSecureRandom class.
 *
 * This header file contains the declarations of the %AesSecureRandom class.
 */
#ifndef _FSEC_AES_SECURE_RANDOM_H_
#define _FSEC_AES_SECURE_RANDOM_H_

#include <FSecISecureRandom.h>


namespace Tizen { namespace Security
{

/**
 *	@class		AesSecureRandom
 *	@brief		This class generates a secure random object with the Advanced Encryption Standard (AES) method.
 *
 *	@since		2.0
 *
 * The %AesSecureRandom class generates a secure random object for seeding cryptographic algorithms.
 * The Advanced Encryption Standard (AES) method generates a user-defined number of random bytes. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 *	@see	ISecureRandom
 *	@see	DesSecureRandom
 *	@see	DesEdeSecureRandom
 */
class _OSP_EXPORT_ AesSecureRandom
	: public virtual ISecureRandom
	, public Tizen::Base::Object
{

public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *	@since		2.0
	 */
	AesSecureRandom(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since		2.0
	 */
	virtual ~AesSecureRandom(void);

	/**
	 *	Generates a user-defined number of random bytes.
	 *
	 *	@since			2.0
	 *
	 *	@return			A pointer to the Tizen::Base::ByteBuffer class, @n
	 *						else @c null if an error occurs
	 *	@param[in]      numBytes				The number of random bytes to generate
	 *	@exception		E_SUCCESS				The method is successful.
	 *	@exception		E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception		E_INVALID_ARG			The specified @c numBytes is @c 0 or negative.
	 * 	@exception	E_SYSTEM			A system error has occurred.
	 *	@remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GenerateRandomBytesN(int numBytes);

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	AesSecureRandom(const AesSecureRandom& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	AesSecureRandom& operator =(const AesSecureRandom& rhs);

private:
	class _AesSecureRandomImpl* __pAesSecureRandomImpl;
	friend class _AesSecureRandomImpl;

}; //AesSecureRandom

} } //Tizen::Security

#endif  //_FSEC_AES_SECURE_RANDOM_H_
