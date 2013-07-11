//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FBaseUtilUrlDecoder.h
 * @brief		This is the header file for the %UrlDecoder class.
 *
 * This header file contains the declarations of the %UrlDecoder class.
 */
#ifndef _FBASE_UTIL_URL_DECODER_H_
#define _FBASE_UTIL_URL_DECODER_H_

// includes
#include <FBaseString.h>


namespace Tizen { namespace Base { namespace Utility
{
/**
 * @class	UrlDecoder
 * @brief	This class provides a method for decoding strings using a specific encoding scheme.
 *
 * @since 2.0
 *
 * The %UrlDecoder class provides a method for decoding strings using a specific encoding scheme.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/url_encoder_decoder.htm">UrlEncoder and UrlDecoder</a>.
 *
 * The following example demonstrates how to use the %UrlDecoder class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Utility;
 *
 *	void
 *	MyClass::UrlDecoderSample(void)
 *	{
 *		result r = E_SUCCESS;
 *		String str1(L"url+encoding+test%3f");
 *		String str2;
 *
 *		// Decodes the input string
 *		r = UrlDecoder::Decode(str1, L"UTF-8", str2);
 *	}
 * @endcode
 */

class _OSP_EXPORT_ UrlDecoder
{
public:
	/**
	* Decodes an encoded string using a specific encoding scheme.
	*
	* @since 2.0
	*
	* @return		An error code
	* @param[in] 	str				 			An instance of String to decode
	* @param[in] 	encodingScheme	 			The supported encoding scheme
	* @param[out]	decodedStr 	 				The decoded string
	* @exception 	E_SUCCESS 					The method is successful.
	* @exception 	E_INVALID_ARG  				A specified input parameter is invalid.
	* @exception 	E_SYSTEM					A system error has occurred.
	* @exception 	E_UNSUPPORTED_TYPE			The specified encoding scheme is not supported.
	* @exception 	E_INVALID_ENCODING_RANGE  	The specified string contains code points that are outside the bounds of the character encoding scheme.
	* @remarks	This method is used for decoding. It decodes an application/x-www-form-urlencoded string using a
	* specific encoding scheme. The supplied encoding scheme is used to determine what characters are represented
	* by any consecutive sequences of the form "%ab", where ab is the two-digit hexadecimal representation of a
	* byte.
	*@see		UrlEncoder
	*/
	static result Decode(const Tizen::Base::String& str, const Tizen::Base::String& encodingScheme, Tizen::Base::String& decodedStr);

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*/
	UrlDecoder(void);

	/*
	 * This destructor is intentionally declared as private so that only the platform can delete an instance.
	 */
	virtual ~UrlDecoder(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs	The instance of the UrlDecoder
	 */
	UrlDecoder(const UrlDecoder& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs	An instance of %UrlDecoder
	 */
	UrlDecoder& operator =(const UrlDecoder& rhs);
}; // UrlDecoder

}}} // Tizen::Base::Utility
#endif // _FBASE_UTIL_URL_DECODER_H_