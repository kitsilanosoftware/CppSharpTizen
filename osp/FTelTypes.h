//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
 * @file    FTelTypes.h
 * @brief   This is the header file for the enumerations of the Tizen::Telephony namespace.
 *
 * This header file contains the definitions of the enumerations of the Tizen::Telephony namespace.
 */
#ifndef _FTEL_ENUM_H_
#define _FTEL_ENUM_H_

namespace Tizen { namespace Telephony
{
/**
 * @enum    CallType
 *
 * Defines the type of the current call.
 *
 * @since   2.0
 */
enum CallType
{
	TYPE_UNDEFINED_CALL = -1,   /**< No defined type */
	TYPE_VOICE_CALL = 0,        /**< The voice call type */
	TYPE_VIDEO_CALL             /**< The video call type */
};

/**
 * @enum    CallStatus
 *
 * Defines the current status of calls.
 *
 * @since   2.0
 */
enum CallStatus
{
	CALL_STATUS_UNDEFINED = -1, /**< No defined type */
	CALL_STATUS_IDLE = 0,       /**< No call is in progress */
	CALL_STATUS_ACTIVE,         /**< @if OSPDEPREC @deprecated This enum value is deprecated because an active status is divided into three, that is, communicating, ringing, dialing, and holding @endif */
	CALL_STATUS_COMMUNICATING,  /**< Voice or video calls are in progress */
	CALL_STATUS_RINGING,        /**< An incoming voice or video call */
	CALL_STATUS_DIALING,        /**< An outgoing voice or video call */
	CALL_STATUS_HOLDING         /**< A call on holding status */
};

}} // Tizen::Telephony
#endif // _FTEL_ENUM_H_
