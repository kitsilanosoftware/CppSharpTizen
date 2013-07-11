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
 * @file    FUixSpeechTextToSpeechTypes.h
 * @brief   This is the header file for common data types used by the TextToSpeech class.
 *
 * This header file contains the declarations of the common data types and constants used by the TextToSpeech class.
 */

#ifndef _FUIX_SPEECH_TEXT_TO_SPEECH_TYPES_H_
#define _FUIX_SPEECH_TEXT_TO_SPEECH_TYPES_H_

namespace Tizen { namespace Uix { namespace Speech
{

/**
 * @enum    TextToSpeechRequestMode
 *
 * Defines the request mode.
 *
 * @since 2.0
 *
 * @see     TextToSpeech::Speak()
 */
enum TextToSpeechRequestMode
{
    TEXT_TO_SPEECH_REQUEST_MODE_APPEND,     /**< The new request is added at the queue */
    TEXT_TO_SPEECH_REQUEST_MODE_REPLACE     /**< All requests in the queue are dropped and replaced by the new request */
};

/**
 * @enum    TextToSpeechSpeechRate
 *
 * Defines the level of the speech rate.
 *
 * @since 2.0
 *
 * @see     TextToSpeech::SetSpeechRate()
 */
enum TextToSpeechSpeechRate
{
    TEXT_TO_SPEECH_SPEECH_RATE_SYSTEM_SETTING,  /**< The speech rate from system setting */
    TEXT_TO_SPEECH_SPEECH_RATE_VERY_SLOW,       /**< The very slow speech rate */
    TEXT_TO_SPEECH_SPEECH_RATE_SLOW,            /**< The slow speech rate*/
    TEXT_TO_SPEECH_SPEECH_RATE_NORMAL,          /**< The normal speech rate */
    TEXT_TO_SPEECH_SPEECH_RATE_FAST,            /**< The fast speech rate */
    TEXT_TO_SPEECH_SPEECH_RATE_VERY_FAST        /**< The very fast speech rate */
};

/**
 * @enum    TextToSpeechStatus
 *
 * Defines the status of the Text-To-Speech service.
 *
 * @since 2.0
 *
 * @see     ITextToSpeechEventListener::OnTextToSpeechStatusChanged()
 */
enum TextToSpeechStatus
{
    TEXT_TO_SPEECH_STATUS_NONE,         /**< The none status */
    TEXT_TO_SPEECH_STATUS_READY,        /**< The ready status */
    TEXT_TO_SPEECH_STATUS_SYNTHESIZING, /**< The synthesizing status */
    TEXT_TO_SPEECH_STATUS_PLAYING,      /**< The playing status */
    TEXT_TO_SPEECH_STATUS_PAUSED        /**< The paused status*/
};

/**
 * @enum    TextToSpeechError
 *
 * Defines the errors that occur in the Text-To-Speech service.
 *
 * @since 2.0
 *
 * @see     ITextToSpeechEventListener::OnTextToSpeechErrorOccurred()
 */
enum TextToSpeechError
{
    TEXT_TO_SPEECH_ERROR_OUT_OF_MEMORY,         /**< The out of memory error */
    TEXT_TO_SPEECH_ERROR_IO_ERROR,              /**< The I/O error */
    TEXT_TO_SPEECH_ERROR_NETWORK_ERROR,         /**< The network connection error */
    TEXT_TO_SPEECH_ERROR_TIME_OUT,              /**< The timeout error */
    TEXT_TO_SPEECH_ERROR_SYSTEM_ERROR,          /**< The system error */
    TEXT_TO_SPEECH_ERROR_UNSUPPORTED_SERVICE    /**< The unsupported service error */
};

} } } // Tizen::Uix::Speech

#endif
