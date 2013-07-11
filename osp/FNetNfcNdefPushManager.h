//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/**
 * @file    FNetNfcNdefPushManager.h
 * @brief   This is the header file for the %NdefPushManager class.
 *
 * This header file contains the declarations of the %NdefPushManager class.
 */
#ifndef _FNET_NFC_NDEF_PUSH_MANAGER_H_
#define _FNET_NFC_NDEF_PUSH_MANAGER_H_

#include <FBaseObject.h>
#include <FBaseResult.h>

namespace Tizen { namespace Base
{
class String;
} }

namespace Tizen { namespace Net { namespace Nfc
{

class INdefPushManagerListener;
class NdefMessage;
class _NdefPushManagerImpl;

/**
 * @class    NdefPushManager
 * @brief    This is the class for pushing an NDEF message to a device.
 *
 * @since 2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %NdefPushManager class is the class for pushing an NDEF message to a device.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 *
 */
class _OSP_EXPORT_ NdefPushManager
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	NdefPushManager(void);

	/**
	 * This destructor overrides Object::~Object().
	 *
	 * @since 2.0
	 */
	~NdefPushManager(void);

	/**
	 * Sets a listener for receiving the result of pushing an NDEF message.
	 *
	 * @since 2.0
	 * @privilege   %http://tizen.org/privilege/nfc.p2p
	 *
	 * @return      An error code
	 * @param[in]   pListener               An instance of %INdefPushManagerListener. @n
	 * 										If it is null, it will reset the listener.
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception	E_OPERATION_FAILED		The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 */
	result SetNdefPushManagerListener(INdefPushManagerListener* pListener);

	/**
	* Pushes the NDEF message.
	*
	* @since 2.0
	* @privilege	%http://tizen.org/privilege/nfc.p2p
	*
	* @return		An error code
	* @param[in]	message					The NDEF message to be sent
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_DEVICE_BUSY			The device is processing preceding job.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_STATE			This instance is in an invalid state. @n
	*										For example, the NFC feature is not activated @n
	*										or a peer device is not attached.
	* @exception	E_INVALID_ARG			The input @c message is invalid. @n
	*										For example, it does not contain any NDEF records.
	* @exception	E_OPERATION_FAILED		The operation has failed.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @remarks
	*/
	result Push(const NdefMessage& message);


	/**
	 * Registers an NDEF message to be pushed if the home screen or the main menu is on top of the screen in the local
	 * device when a peer device is detected.
	 *
	 * @since 2.0
	 * @privilege   %http://tizen.org/privilege/nfc.p2p
	 *
	 * @return      An error code
	 * @param[in]   message                 The NDEF message to be registered
	 * @param[in]   description             The description for the NDEF message to be registered @n
	 *                                      This description is used in Reserved Push UI, for example, UI for getting
	 *                                      user consent to send the registered message.
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The input @c message is invalid. @n
	 *                                      For example, it does not contain any NDEF records.
	 * @exception   E_UNSUPPORTED_OPERATION The method has failed because the device does not support the NFC or the
	 *                                      Reserved Push feature.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     An application can register only one NDEF message. So the previously registered message will be
	 *              replaced by the new one.@n
	 *              The registered NDEF message is pushed only if it is selected by the user through the Setting
	 *              application.
	 */
	static result RegisterNdefPushMessage(const NdefMessage& message, const Tizen::Base::String& description);

	/**
	 * Unregisters an NDEF message if the NDEF message to be pushed is registered.
	 *
	 * @since 2.0
	 * @privilege   %http://tizen.org/privilege/nfc.p2p
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The method has failed because the device does not support the NFC feature
	 *                                      or the Reserved Push feature.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	static result UnregisterNdefPushMessage(void);

private:
	/**
	* The implementation of this copy constructor is intentionally blank to prohibit copying of objects.
	*
	* @since 2.0
	*/
	NdefPushManager(const NdefPushManager& value);

	/**
	* The implementation of this copy assignment operator is intentionally blank to prohibit copying of objects.
	*
	* @since 2.0
	*/
	NdefPushManager& operator =(const NdefPushManager& value);

private:
	_NdefPushManagerImpl* __pImpl;

	friend class _NdefPushManagerImpl;
}; // NdefPushManager

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_NDEF_PUSH_MANAGER_H_
