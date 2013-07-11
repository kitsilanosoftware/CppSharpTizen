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
 * @file    FTelephony.h
 * @brief   This is the header file for the %Telephony namespace.
 *
 * This header file contains the declarations and descriptions of the %Telephony namespace.
 */
#ifndef _FTELEPHONY_H_
#define _FTELEPHONY_H_


#include <FTelTypes.h>
#include <FTelCallInfo.h>
#include <FTelCallManager.h>
#include <FTelNetworkInfo.h>
#include <FTelNetworkStatus.h>
#include <FTelNetworkManager.h>
#include <FTelSimInfo.h>
#include <FTelITelephonyCallEventListener.h>

#include <FTelITelephonyNetworkEventListener.h>



/**
 * @namespace   Tizen::Telephony
 * @brief       This namespace contains classes and interfaces of the %Telephony service.
 * @since       2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FTelephony.h> @n
 *              @b Library : @b osp-telephony
 *
 * The %Telephony namespace is one of the main namespaces of the Tizen framework.
 * It provides classes and methods that enable an application to
 * access the telephony capabilities of the device, such as call facility (call information and status),
 * network query services, and SIM module.
 *
 * For more information on the %Telephony namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/telephony/telephony.htm">Telephony Guide</a>.
 *
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Telephony namespace.
 * @image html telephony_using_the_apis_classdiagram.png
 *
 **/

namespace Tizen { namespace Telephony
{
}} // Tizen::Telephony
#endif // _FTELEPHONY_H_
