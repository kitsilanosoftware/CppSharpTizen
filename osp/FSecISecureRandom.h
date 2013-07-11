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
 * @file		FSecISecureRandom.h
 * @brief		This is the header file for the %ISecureRandom interface.
 *
 * This header file contains the declarations of the %ISecureRandom interface.
 */
#ifndef _FSEC_ISECURE_RANDOM_H_
#define _FSEC_ISECURE_RANDOM_H_

#include <FBaseString.h>
#include <FBaseByteBuffer.h>

namespace Tizen { namespace Security
{

/**
 *	@interface	ISecureRandom
 *	@brief		This interface provides the abstract methods for generating a secure random object.
 *
 *  @since      2.0
 *
 *  The %ISecureRandom interface provides the abstract methods for generating a secure random object. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 *	@see	Tizen::Security::AesSecureRandom
 *	@see	Tizen::Security::DesSecureRandom
 *	@see	Tizen::Security::DesEdeSecureRandom
 */
class _OSP_EXPORT_ ISecureRandom
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~ISecureRandom(void) {}

	/**
	 *	Generates a user-specified number of random bytes.
	 *
	 *	@since		2.0
	 *
	 *	@return		A pointer to the Tizen::Base::ByteBuffer class, @n
	 *				else @c null if an error occurs
	 *	@param[in]	numBytes				The number of random bytes to generate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified @c numBytes is @c 0 or negative.
	 *	@exception	E_SYSTEM				A system error has occurred. @n
	 *										The method has failed to operate with the OpenSSL library, or the Tizen::Base::ByteBuffer operation has failed.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.

	 */
	virtual Tizen::Base::ByteBuffer* GenerateRandomBytesN(int numBytes) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ISecureRandom_Reserved1(void) {}

}; //ISecureRandom

} } //Tizen::Security

#endif // _FSEC_ISECURE_RANDOM_H_
