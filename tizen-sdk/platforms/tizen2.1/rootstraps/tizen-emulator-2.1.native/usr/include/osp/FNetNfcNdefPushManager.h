//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
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
#include <FAppTypes.h>

namespace Tizen { namespace Base
{
class String;
} }

namespace Tizen { namespace Base { namespace Collection
{
class IMap;
}
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
 * @since    2.0
 *
 * @final    This class is not intended for extension.
 *
 * The %NdefPushManager class is the class for pushing an NDEF message to a device.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 *
 * The following example demonstrates how to use the %NdefPushManager class.
 *
 * @code
 * // MyClass.h
 * #include <FNet.h>

 * class MyClass
 * 	: public Tizen::Net::Nfc::INfcManagerEventListener
 *  	, public Tizen::Net::Nfc::INdefPushManagerListener
 *  	, public Tizen::Net::Nfc::INfcDeviceDiscoveryEventListener
 *  {
 *  public:
 *  	// The method declarations are hidden for the sake of simplicity
 *
 *  private:
 *  	Tizen::Net::Nfc::NfcManager*      __pNfcManager;
 *  	Tizen::Net::Nfc::NdefPushManager* __pNdefPushManager;
 *  };
 *
 * // MyClass.cpp
 * #include "MyClass.h"
 *
 * using namespace Tizen::Net::Nfc;
 *
 * MyClass::MyClass(void)
 * 	: __pNfcManager(null)
 *  	, __pNdefPushManager(null)
 * {
 * 	__pNfcManager = new NfcManager();
 * 	__pNdefPushManager = new NdefPushManager();
 * }
 *
 * MyClass::~MyClass(void)
 * {
 * 	// Removes the device discovery event listener instance.
 * 	__pNfcManager->RemoveDeviceDiscoveryEventListener(*this);
 *
 * 	delete __pNfcManager;
 *  	delete __pNdefPushManager;
 * }
 *
 * void
 * MyClass::PushNdefMessageSample(void)
 * {
 * 	// Creates the NfcManager instance and registers the manager event listener
 * 	__pNfcManager->Construct(*this);
 *
 * 	// Adds the device discovery event listener instance for the device discovery events.
 * 	__pNfcManager->AddDeviceDiscoveryEventListener(*this);
 *
 *  	// Sets a listener for receiving the result of pushing an NDEF message.
 * 	__pNdefPushManager->SetNdefPushManagerListener(this);
 * }
 *
 *  // This method is invoked when a NFC device is detected
 * void
 * MyClass::OnNfcDeviceDetected(void)
 * {
 * 	NdefMessage message;
 * 	// Fills up the NdefMessage object here
 *
 * 	__pNdefPushManager->Push(message);
 * }
 *
 *  // This method is invoked when the NFC device is lost
 * void
 * MyClass::OnNfcDeviceLost(void)
 * {
 *
 * }
 *
 *  // This method is invoked when the push operation to the target device is completed.
 * void
 * MyClass::OnNdefPushMessageSent(result r)
 * {
 * 	if (r == E_SUCCESS)
 * 	{
 * 		// Pushing NdefMessage is successful
 * 	}
 * }
 * @endcode
 */
class _OSP_EXPORT_ NdefPushManager
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since       2.0
	 */
	NdefPushManager(void);

	/**
	 * This destructor overrides Object::~Object().
	 *
	 * @since       2.0
	 */
	~NdefPushManager(void);

	/**
	 * Sets a listener for receiving the result of pushing an NDEF message.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.p2p
	 * @feature     %http://tizen.org/feature/network.nfc
	 *
	 * @return      An error code
	 * @param[in]   pListener               An instance of %INdefPushManagerListener. @n
	 *                                      If it is null, it will reset the listener.
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_OPERATION_FAILED      The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks     Before calling this method, check whether the feature is supported by 
	 *              Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	result SetNdefPushManagerListener(INdefPushManagerListener* pListener);

	/**
	 * Pushes the NDEF message.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.p2p
	 * @feature     %http://tizen.org/feature/network.nfc
	 *
	 * @return      An error code
	 * @param[in]   message                 The NDEF message to send
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_DEVICE_BUSY           The device is processing preceding job.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
	 *                                      For example, the NFC feature is not activated or a peer device is not
	 *                                      attached.
	 * @exception   E_INVALID_ARG           The input @c message is invalid. @n
	 *                                      For example, it does not contain any NDEF records.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_OPERATION_FAILED      The operation has failed.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks     Before calling this method, check whether the feature is supported by 
	 *              Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	result Push(const NdefMessage& message);

	/**
	 * Activates the Reserved Push feature that sends the preselected NDEF message to the connected NFC peer device on
	 * behalf of the application.
	 *
	 * @since       2.1
	 * @privlevel   platform
	 * @privilege   %http://tizen.org/privilege/nfcmanager
	 * @feature     %http://tizen.org/feature/network.nfc and %http://tizen.org/feature/network.nfc.reserved_push @n
	 *              Both the features are required.
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, Reserved Push is already activated.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error.
	 * @remarks     Before calling this method, check whether the feature is supported by 
	 *              Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see         <a href="../org.tizen.native.appprogramming/html/guide/net/nfc_reserved_push.htm">
	 *              The NFC Reserved Push guide</a>	 
	 */
	result ActivateReservedPush(void);

	/**
	 * Deactivates the Reserved Push feature that sends the preselected NDEF message to the connected NFC peer device on
	 * behalf of the application.
	 *
	 * @since       2.1
	 * @privlevel   platform
	 * @privilege   %http://tizen.org/privilege/nfcmanager
	 * @feature     %http://tizen.org/feature/network.nfc and %http://tizen.org/feature/network.nfc.reserved_push @n
	 *              Both the features are required.
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, Reserved Push is already deactivated.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error.
 	 * @remarks     Before calling this method, check whether the feature is supported by 
 	 *              Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see         <a href="../org.tizen.native.appprogramming/html/guide/net/nfc_reserved_push.htm">
	 *              The NFC Reserved Push guide</a> 	 
	 */
	result DeactivateReservedPush(void);

	/**
	 * Checks whether the Reserved Push feature is activated.
	 *
	 * @since       2.1
	 *
	 * @return      @c true if Reserved Push is activated, @n
	 *              else @c false
	 */
	bool IsReservedPushActivated(void) const;

	/**
	 * Gets information of all the Reserved Push candidates. @n Each element of the result Tizen::Base::Collection::IMap consists of the package ID
	 * of the application that registered the NDEF message and the description about the registered NDEF message.
	 *
	 * @since       2.1
	 *
	 * @return      An IMapT containing the pairs of package ID and message description if successful, @n
	 *              else @c null
	 * @remarks     The key of the returned Tizen::Base::Collection::IMap should be casted to Tizen::App::PackageId pointer and the value should
	 *              be casted to Tizen::Base::String pointer.
	 */
	Tizen::Base::Collection::IMap* GetReservedPushCandidatesN(void) const;

	/**
	 * Picks out an NDEF message among all the Reserved Push candidates by the application ID. @n The selected NDEF message is
	 * pushed when a peer device is detected.
	 *
	 * @since       2.1
	 * @privlevel   platform
	 * @privilege   %http://tizen.org/privilege/nfcmanager
	 * @feature     %http://tizen.org/feature/network.nfc and %http://tizen.org/feature/network.nfc.reserved_push @n
	 *              Both the features are required.
	 *
	 * @return      An error code
	 * @param[in]   packageId               The package ID of the application that registered the NDEF message to push
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OBJ_NOT_FOUND         The specified @c packageId is not found in the Reserved Push candidate list.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error.
	 *
	 * @remarks     
	 *              - The only one message can be selected to push. So the previously selected message will be replaced
	 *                by the new one.
	 *              - Before calling this method, check whether the feature is supported by
 	 *                Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see         <a href="../org.tizen.native.appprogramming/html/guide/net/nfc_reserved_push.htm">
	 *              The NFC Reserved Push guide</a>
	 */
	result PickReservedPushMessage(const Tizen::App::PackageId& packageId);

	/**
	 * Gets the owner application ID of the picked NDEF message among all the Reserved Push candidates.
	 *
	 * @since       2.1
	 * @feature     %http://tizen.org/feature/network.nfc and %http://tizen.org/feature/network.nfc.reserved_push @n
	 *              Both the features are required.
	 *
	 * @return      The package ID of the application which is the owner of the picked Reserved Push message @n
	 *              else an empty string if an error occurs
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OBJ_NOT_FOUND         There is no element in the Reserved Push candidate list.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error.
	 * @remarks
	 *              - The specific error code can be accessed using the GetLastResult() method.
	 *              - Before calling this method, check whether the feature is supported by 
	 *                Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see         <a href="../org.tizen.native.appprogramming/html/guide/net/nfc_reserved_push.htm">
	 *              The NFC Reserved Push guide</a>	 
	 */
	Tizen::App::PackageId GetPickedReservedPushMessage(void) const;

	/**
	 * Registers an NDEF message as a Reserved Push candidate. @n
	 * If the message is picked out among the candidates, it is pushed to the detected peer device when the home screen
	 * or the main menu is on top of the screen in the local device.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.p2p
	 * @feature     %http://tizen.org/feature/network.nfc and %http://tizen.org/feature/network.nfc.reserved_push @n
	 *              Both the features are required.
	 *
	 * @return      An error code
	 * @param[in]   message                 The NDEF message to register
	 * @param[in]   description             The description for the NDEF message to register @n
	 *                                      This description can be used in Reserved Push UI, for example, UI for
	 *                                      getting user consent to send the registered message.
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The input @c message is invalid. @n
	 *                                      For example, it does not contain any NDEF records.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error.
	 * @remarks
	 *              - An application can register only one NDEF message. So the previously registered message will be
	 *                replaced by the new one.
	 *              - The registered NDEF message is pushed only if it is selected by the user through the Setting
	 *                application.
	 *              - Before calling this method, check whether the feature is supported by 
	 *                Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see         <a href="../org.tizen.native.appprogramming/html/guide/net/nfc_reserved_push.htm">
	 *              The NFC Reserved Push guide</a>	 
	 */
	static result RegisterNdefPushMessage(const NdefMessage& message, const Tizen::Base::String& description);

	/**
	 * Unregisters an NDEF message from the Reserved Push candidates.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.p2p
	 * @feature     %http://tizen.org/feature/network.nfc and %http://tizen.org/feature/network.nfc.reserved_push @n
	 *              Both the features are required.
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                The method cannot proceed due to a severe system error.
	 * @remarks     Before calling this method, check whether the feature is supported by 
	 *              Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see         <a href="../org.tizen.native.appprogramming/html/guide/net/nfc_reserved_push.htm">
	 *              The NFC Reserved Push guide</a>	 
	 */
	static result UnregisterNdefPushMessage(void);

private:
	//
	// The implementation of this copy constructor is intentionally blank to prohibit copying of objects.
	//
	NdefPushManager(const NdefPushManager& value);

	//
	// The implementation of this copy assignment operator is intentionally blank to prohibit copying of objects.
	//
	NdefPushManager& operator =(const NdefPushManager& value);

private:
	_NdefPushManagerImpl* __pImpl;

	friend class _NdefPushManagerImpl;
}; // NdefPushManager

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_NDEF_PUSH_MANAGER_H_
