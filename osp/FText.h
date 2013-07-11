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
 * @file		FText.h
 * @brief		This is the header file for the %Text namespace.
 *
 * This header file contains the declarations of the %Text namespace.
 */

#ifndef _FTEXT_H_
#define _FTEXT_H_

#include <FTextEncoding.h>
#include <FTextUtf8Encoding.h>
#include <FTextAsciiEncoding.h>
#include <FTextLatin1Encoding.h>
#include <FTextGsmEncoding.h>
#include <FTextUcs2Encoding.h>
#include <FTextEncoder.h>
#include <FTextDecoder.h>
#include <FTextUtf8Encoder.h>
#include <FTextUtf8Decoder.h>


/**
 * @namespace	Tizen::Text
 * @brief			This namespace contains classes that encode and decode characters.
 *
 * @since			2.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FText.h> @n
 *						@b Library: @b osp-appfw
 *
 * The %Text namespace contains the Encoding class, which is the base class for encoding and decoding many character encodings, such as UTF-8, UCS-2, Latin-1, GSM, and ASCII. It also contains the Decoder and Encoder classes for converting text blocks. The main purpose of this namespace is to support inter-
 * operability between the various existing languages and scripts.
 * %Text is a data consisting of a sequence of characters.
 * It is also defined as a series of characters that can be displayed on a
 * display terminal or printed on paper for human reading.
 *
 * For more information on the %Text namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/text/text.htm">Text Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Text namespace.
 * @image html text_using_the_apis_classdiagram.png
 *
 *
 *
 */

namespace Tizen { namespace Text
{

}} // Tizen::Text

#endif //_FTEXT_H_
