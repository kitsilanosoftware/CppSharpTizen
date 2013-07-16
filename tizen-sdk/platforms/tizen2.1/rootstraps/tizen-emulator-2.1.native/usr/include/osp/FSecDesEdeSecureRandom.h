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
 * @file		FSecDesEdeSecureRandom.h
 * @brief	This is the header file for the %DesEdeSecureRandom class.
 *
 * This header file contains the declarations of the %DesEdeSecureRandom class.
 */
#ifndef _FSEC_DESEDE_SECURE_RANDOM_H_
#define _FSEC_DESEDE_SECURE_RANDOM_H_

#include <FSecISecureRandom.h>


namespace Tizen { namespace Security
{

/**
 * @class	DesEdeSecureRandom
 * @brief	This class provides a secure random object with the Data Encryption Standard in the Encrypt-Decrypt-Encrypt (DES-EDE) mode.
 *
 * @since	2.0
 *
 * The %DesEdeSecureRandom class generates a secure random object to deterministically seed cryptographic algorithms. The Data Encryption Standard (DES)
 * method generates user-defined number of random bytes in the Encrypt-Decrypt-Encrypt mode. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 * @see		ISecureRandom
 * @see		AesSecureRandom
 * @see		DesSecureRandom
 */
class _OSP_EXPORT_ DesEdeSecureRandom
	: public virtual ISecureRandom
	, public Tizen::Base::Object
{

public:
	/**
	 *	This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	DesEdeSecureRandom(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~DesEdeSecureRandom(void);

	/**
	 * Generates a user-defined number of random bytes.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @param[in]   numBytes			The number of random bytes to generate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified @c numBytes is @c 0 or negative.
	 *	@exception	E_SYSTEM			A system error has occurred. @n 
	 *									The method has failed to operate with the OpenSSL library, or the Tizen::Base::ByteBuffer operation has failed.
	 */
	virtual Tizen::Base::ByteBuffer* GenerateRandomBytesN(int numBytes);

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	DesEdeSecureRandom(const DesEdeSecureRandom& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	DesEdeSecureRandom& operator =(const DesEdeSecureRandom& rhs);

private:
	class _DesEdeSecureRandomImpl* __pDesEdeSecureRandomImpl;
	friend  class _DesEdeSecureRandomImpl;

}; //DesEdeSecureRandom

} } //Tizen::Security

#endif // _FSEC_DESEDE_SECURE_RANDOM_H_
