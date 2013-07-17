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
 * @file    FUixSpeechSpeechToTextTypes.h
 * @brief   This is the header file for the common data types used by the SpeechToText class.
 *
 * This header file contains the declarations of the common data types and constants used by the SpeechToText class.
 */

#ifndef _FUIX_SPEECH_SPEECH_TO_TEXT_TYPES_H_
#define _FUIX_SPEECH_SPEECH_TO_TEXT_TYPES_H_

namespace Tizen { namespace Uix { namespace Speech
{

/**
* @enum SpeechToTextStatus
*
* Defines the SpeechToText status.
*
* @since 2.0
*
* @see ISpeechToTextEventListener::OnSpeechToTextStatusChanged()
*/
enum SpeechToTextStatus
{
    SPEECH_TO_TEXT_STATUS_NONE,         /**< The none status */
    SPEECH_TO_TEXT_STATUS_READY,        /**< The ready status */
    SPEECH_TO_TEXT_STATUS_RECORDING,    /**< The recording status */
    SPEECH_TO_TEXT_STATUS_PROCESSING    /**< The recognition processing status */
};

/**
* @enum SpeechToTextGrammar
*
* Defines the SpeechToText grammar.
*
* @since 2.0
*
* @see SpeechToText::SetGrammar()
*/
enum SpeechToTextGrammar
{
    SPEECH_TO_TEXT_GRAMMAR_FREE,        /**< The key is used for general purpose dictation */
    SPEECH_TO_TEXT_GRAMMAR_WEB_SEARCH   /**< The key is used for recognizing short phrases such as the ones used for %Web search */
};

/**
* @enum SpeechToTextError
*
* Defines the errors in SpeechToText. @n
* When an error occurs, the user can not receive any %SpeechToText result.
*
* @since 2.0
*
* @see ISpeechToTextEventListener::OnSpeechToTextErrorOccurred()
*/
enum SpeechToTextError
{
    SPEECH_TO_TEXT_ERROR_OUT_OF_MEMORY,         /**< The out of memory error */
    SPEECH_TO_TEXT_ERROR_IO_ERROR,              /**< The I/O error */
    SPEECH_TO_TEXT_ERROR_NETWORK_ERROR,         /**< The network connection error */
    SPEECH_TO_TEXT_ERROR_TIME_OUT,              /**< The timeout error */
    SPEECH_TO_TEXT_ERROR_SYSTEM_ERROR,          /**< The system error */
    SPEECH_TO_TEXT_ERROR_UNSUPPORTED_SERVICE    /**< The unsupported service error */
};

} } } // Tizen::Uix::Speech

#endif
