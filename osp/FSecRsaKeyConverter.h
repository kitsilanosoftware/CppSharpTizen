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
 * @file			FSecRsaKeyConverter.h
 * @brief		This is the header file for the %RsaKeyConverter class.
 *
 * This header file contains the declarations of the %RsaKeyConverter class.
 */

#ifndef _FSEC_RSA_KEY_CONVERTER_H_
#define _FSEC_RSA_KEY_CONVERTER_H_

#include <FSecIPublicKey.h>
#include <FSecIPrivateKey.h>

namespace Tizen { namespace Security
{

/**
 * @enum    RsaKeyFormat
 *
 * Defines the types of rsa key format.
 *
 * @since		2.1
 */
enum RsaKeyFormat
{
	RSA_KEY_FORMAT_PKCS01_PRIVATE_KEY = 0,     /**< The rsa key format is PKCS1 private key */
	RSA_KEY_FORMAT_PKCS01_PUBLIC_KEY = 1,      /**< The rsa key format is PKCS1 public key */
	RSA_KEY_FORMAT_PKCS08_PRIVATE_KEY = 2,     /**< The rsa key format is PKCS8 private key */
	RSA_KEY_FORMAT_X509_PUBLIC_KEY = 3,      /**< The rsa key format is X509 public key */
	RSA_KEY_FORMAT_UNKNOWN = 0xffffffff       /**< The rsa key format is unknown */
}; //RsaKeyFormat;

/**
 *  @class		RsaKeyConverter
 *  @brief		This class provides support for converting the RSA public/private key in multiple key formats and multiple encoding formats.
 *
 *  @since      2.1
 *
 *  The %RsaKeyConverter class provides support for converting the RSA public/private key in multiple key formats and multiple encoding formats. @n
 *				Supported RSA key formats are PKCS1/PKCS8/X509. @n
 *				Supported encoding formats are DER/PEM.
 */

class _OSP_EXPORT_ RsaKeyConverter
{

public:
	/**
	 *	Generates a RSA encoded private key in the passed input RSA key format. @n
	 *	If the input private key is in PEM encoded format, then the output RSA private key will be PEM encoded; if it is in DER encoded format,
	 *	then the output RSA private key will be DER encoded.
	 *
	 *	@since		2.1
	 *
	 *	@return		A pointer to the encoded Tizen::Base::ByteBuffer instance, @n
	 *	                    else @c null if the method fails to convert the private key in the passed input format
	 *	@param[in]	format				An enum value that contains the RSA private key format @n
	 *									Valid values for the supported output RSA private key formats are only @c RSA_KEY_FORMAT_PKCS01_PRIVATE_KEY and @c RSA_KEY_FORMAT_PKCS08_PRIVATE_KEY.
	 *	@param[in]	key					An instance of IPrivateKey
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Base::ByteBuffer* ConvertPrivateKeyFormatN(RsaKeyFormat format, const IPrivateKey& key);

	/**
	 *	Generates a RSA encoded public key in the passed input RSA key format. @n
	 *	If the input public key is in PEM encoded format, then the output RSA public key will be PEM encoded; if it is in DER encoded format,
	 *	then the output RSA public key will be DER encoded.
	 *
	 *	@since		2.1
	 *
	 *	@return		A pointer to the encoded Tizen::Base::ByteBuffer instance, @n
	 *	                        else @c null if the method fails to convert the public key in the passed input format
	 *	@param[in]	format				An enum value that contains the RSA public key format @n
	 *									Valid values for the supported output RSA public key formats are only @c RSA_KEY_FORMAT_PKCS01_PUBLIC_KEY and @c RSA_KEY_FORMAT_X509_PUBLIC_KEY.
	 *	@param[in]	key					An instance of IPublicKey
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *	@remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Base::ByteBuffer* ConvertPublicKeyFormatN(RsaKeyFormat format, const IPublicKey& key);

	/**
	 *	Converts a DER encoded RSA key to the PEM encoded format.
	 *
	 *	@since		2.1
	 *
	 *	@return		A pointer to the PEM encoded Tizen::Base::ByteBuffer instance, @n
	 *                              else @c null if the method fails to convert the key in the PEM encoded format
	 *	@param[in]	format				An enum value that contains the RSA key format of the input key
	 *	@param[in]	key					An instance of IKey
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *	@remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Base::ByteBuffer* ConvertDerToPemN(RsaKeyFormat format, const IKey& key);

	/**
	 *	Converts a PEM encoded RSA key to the DER encoded format.
	 *
	 *	@since		2.1
	 *
	 *	@return		A pointer to the DER encoded Tizen::Base::ByteBuffer instance, @n
	 *                                  else @c null if the method fails to convert the key in the DER encoded format
	 *	@param[in]	format				An enum value that contains the RSA key format of the input key
	 *	@param[in]	key					An instance of IKey
	 *	@exception	E_SUCCESS					The method is successful.
	 *	@exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *  @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Base::ByteBuffer* ConvertPemToDerN(RsaKeyFormat format, const IKey& key);

private:
	//
	// This default constructor is intentionally declared as private because this class cannot be constructed.
	//
	// @since	2.1
	//
	RsaKeyConverter(void);

	//
	// This destructor is intentionally declared as private because this class cannot be constructed.
	//
	// @since	2.1
	//
	~RsaKeyConverter(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.1
	//
	RsaKeyConverter(const RsaKeyConverter& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.1
	//
	RsaKeyConverter& operator =(const RsaKeyConverter& rhs);

private:
	class _RsaKeyConverterImpl* __pRsaKeyConverterImpl;
	friend class _RsaKeyConverterImpl;

};     //RsaKeyConverter

} } //Tizen::Security

#endif // _FSEC_RSA_KEY_CONVERTER_H_
