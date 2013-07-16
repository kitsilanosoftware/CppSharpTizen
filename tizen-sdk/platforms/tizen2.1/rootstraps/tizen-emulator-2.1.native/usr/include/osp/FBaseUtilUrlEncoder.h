//
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
 * @file		FBaseUtilUrlEncoder.h
 * @brief		This is the header file for the %UrlEncoder class.
 *
 * This header file contains the declarations of the %UrlEncoder class.
 */

#ifndef _FBASE_UTIL_URL_ENCODER_H_
#define _FBASE_UTIL_URL_ENCODER_H_

// includes
#include <FBaseString.h>


namespace Tizen { namespace Base { namespace Utility
{
/**
 * @class	UrlEncoder
 * @brief	This class provides a method for encoding a string using a specific encoding scheme.
 *
 * @since 2.0
 *
 * The %UrlEncoder class provides a method for encoding a string using a specific encoding scheme.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/url_encoder_decoder.htm">UrlEncoder and UrlDecoder</a>.
 *
 * The following example demonstrates how to use the %UrlEncoder class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Utility;
 *
 *	void
 *	MyClass::UrlEncoderSample(void)
 *	{
 *		result r = E_SUCCESS;
 *		String str1(L"url encoding test?");
 *		String str2;
 *
 *		// Encodes the input string
 *		r = UrlEncoder::Encode(str1, L"UTF-8", str2);
 *	}
 * @endcode
 */


class _OSP_EXPORT_ UrlEncoder
{
public:
	/**
	* Encodes an input string using a specific encoding scheme. @n
	* It encodes all unsafe characters of a string.
	*
	* @since 2.0
	*
	* @return		An error code
	* @param[in] 	str							An instance of String to encode
	* @param[in] 	encodingScheme 	 			The supported encoding scheme
	* @param[out] 	encodedStr 	 				The encoded string
	* @exception 	E_SUCCESS 					The method is successful.
	* @exception 	E_INVALID_ARG  				A specified input parameter is invalid.
	* @exception		E_SYSTEM					A system error has occurred.
	* @exception 	E_UNSUPPORTED_TYPE  		The specified encoding scheme is not supported.
	* @exception 	E_INVALID_ENCODING_RANGE  	The specified string contains code points that are outside the bounds of the character encoding scheme.
	* @remarks	This method is used for encoding. It encodes input string into an
	* application/x-www-form-urlencoded	format using a specific encoding scheme. This method uses the specified
	* encoding scheme to obtain the bytes for unsafe characters.
	*@see		UrlDecoder
	*/
	static result Encode(const Tizen::Base::String& str, const Tizen::Base::String& encodingScheme, Tizen::Base::String& encodedStr);

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*/
	UrlEncoder(void);

	/*
	 * This destructor is intentionally declared as private so that only the platform can delete an instance.
	 */
	virtual ~UrlEncoder(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs	An instance of %UrlEncoder
	 */
	UrlEncoder(const UrlEncoder& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs	An instance of %UrlEncoder
	 */
	UrlEncoder& operator =(const UrlEncoder& rhs);
}; // UrlEncoder

}}} // Tizen::Base::Utility
#endif // _FBASE_UTIL_URL_ENCODER_H_
