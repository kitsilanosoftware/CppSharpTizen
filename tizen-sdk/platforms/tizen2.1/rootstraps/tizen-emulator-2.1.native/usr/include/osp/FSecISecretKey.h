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
 * @file			FSecISecretKey.h
 * @brief		This is the header file for the %ISecretKey interface.
 *
 * This header file contains the declarations of the %ISecretKey interface.
 */
#ifndef _FSEC_ISECRET_KEY_H_
#define _FSEC_ISECRET_KEY_H_

#include <FSecIKey.h>


namespace Tizen { namespace Security
{

/**
 * @interface	ISecretKey
 * @brief		 This interface provides methods that help in setting the buffer for the key. These methods also extract the encoding format of the key.
 *
 * @since		2.0
 *
 * The %ISecretKey interface provides methods that help in setting the buffer for the key. These methods also extract the encoding format of the key. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_mgmt_and_csprng.htm">Key Management and CSPRNG</a>.
 *
 */
class _OSP_EXPORT_ ISecretKey
	: public virtual IKey
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes @n
	 * are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~ISecretKey(void){}

	/**
	 * Gets the name of the primary encoding format of this key.
	 *
	 * @since		2.0
	 *
	 * @return		The primary encoding format of the key
	 */
	virtual Tizen::Base::String GetFormat(void) const = 0;

	/**
	 * Gets the secret key in its primary encoding format.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetEncodedN(void) const = 0;

	/**
	 * Sets the secret key buffer.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	keyBuffer				An instance of Tizen::Base::ByteBuffer
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c keyBuffer is invalid.
	 */
	virtual result SetKey(const Tizen::Base::ByteBuffer& keyBuffer) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void ISecretKey_Reserved1(void) {}

}; //ISecretKey

} } //Tizen::Security

#endif //_FSEC_ISECRET_KEY_H_
