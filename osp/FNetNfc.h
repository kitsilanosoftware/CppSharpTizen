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
 * @file    FNetNfc.h
 * @brief   This is the header file for the %Nfc namespace.
 *
 * This header file contains the declarations and descriptions of the %Nfc namespace.
 */
#ifndef _FNET_NFC_H_
#define _FNET_NFC_H_

#include <FNetNfcNfcTypes.h>
#include <FNetNfcNdefRecordType.h>
#include <FNetNfcNdefRecord.h>
#include <FNetNfcNdefMessage.h>
#include <FNetNfcNfcTag.h>
#include <FNetNfcTagConnection.h>
#include <FNetNfcNdefTagConnection.h>
#include <FNetNfcNfcManager.h>
#include <FNetNfcNdefPushManager.h>
#include <FNetNfcINfcTagDiscoveryEventListener.h>
#include <FNetNfcINdefMessageDiscoveryEventListener.h>
#include <FNetNfcINfcManagerEventListener.h>
#include <FNetNfcITagConnectionListener.h>
#include <FNetNfcINdefTagConnectionListener.h>
#include <FNetNfcINfcDeviceDiscoveryEventListener.h>
#include <FNetNfcINdefPushManagerListener.h>

namespace Tizen { namespace Net
{
/**
 * @namespace   Tizen::Net::Nfc
 * @brief       This namespace contains the classes and interfaces for the Near Field Communication (NFC) services.
 * @since       2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FNet.h> @n
 *              @b Library : @b osp-nfc @n
 *
 * The %Nfc namespace contains the various classes and interfaces for the Near Field Communication (NFC) programming that
 * enables the devices to share information within a distance of less than @c 4 centimeters.
 *
 * For more information on the NFC namespace features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 *
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Nfc namespace.
 * @image html net_nfc_using_the_apis_classdiagram.png
 *
 */
namespace Nfc
{
} } } // Tizen::Net::Nfc
#endif // _FNET_NFC_H_
