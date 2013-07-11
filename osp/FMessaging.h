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
 * @file		FMessaging.h
 * @brief	This is the header file for the %Messaging namespace.
 *
 * This header file contains the declarations and descriptions of the %Messaging namespace.
 */

#ifndef _FMESSAGING_H_
#define _FMESSAGING_H_

//include
#include <FMsgTypes.h>
#include <FMsgSmsMessage.h>
#include <FMsgMmsMessage.h>
#include <FMsgEmailMessage.h>
#include <FMsgPushMessage.h>
#include <FMsgSmsManager.h>
#include <FMsgMmsManager.h>
#include <FMsgEmailManager.h>
#include <FMsgPushManager.h>
#include <FMsgRecipientList.h>
#include <FMsgISmsListener.h>
#include <FMsgIMmsListener.h>
#include <FMsgIEmailListener.h>

#include <FMsgISmsMessageEventListener.h>
#include <FMsgIPushEventListener.h>
#include <FMsgIPushManagerListener.h>

/**
 * @namespace	Tizen::Messaging
 * @brief		This namespace contains classes and interfaces for messaging services.
 * @since		2.0
 *
 * @remarks		@b Header @b %file : @b \#include @b <FMessaging.h> @n
 *						@b Library : @b osp-messaging
 *
 * The %Messaging namespace accesses the messaging capabilities of the device. @n
 * It provides classes and interfaces for the following: @n
 * - SMS: create, send, receive, and retrieve
 * - MMS: create and send
 * - email: create and send
 * - push: receive
 *
 * For more information on the %Messaging namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/messaging/messaging.htm">Messaging Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Messaging namespace.
 * @image html messaging_using_the_apis_classdiagram.png
 *
 */
namespace Tizen
{
	namespace Messaging
	{

	};
}; // Tizen::Messaging

#endif // _FMESSAGING_H_
