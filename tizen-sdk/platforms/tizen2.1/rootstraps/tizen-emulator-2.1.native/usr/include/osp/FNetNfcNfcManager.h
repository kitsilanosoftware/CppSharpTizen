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
 * @file    FNetNfcNfcManager.h
 * @brief   This is the header file for the %NfcManager class.
 *
 * This header file contains the declarations of the %NfcManager class.
 */
#ifndef _FNET_NFC_NFC_MANAGER_H_
#define _FNET_NFC_NFC_MANAGER_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FNetNfcNfcTypes.h>

namespace Tizen { namespace Net { namespace Nfc
{

class INfcManagerEventListener;
class INfcTransactionEventListener;
class INfcTagDiscoveryEventListener;
class INdefMessageDiscoveryEventListener;
class INfcDeviceDiscoveryEventListener;
class NdefMessage;
class NdefRecordType;
class TagConnection;
class _NfcManagerImpl;

/**
 * @class    NfcManager
 * @brief    This is the manager class for the NFC features.
 *
 * @since    2.0
 *
 * The %NfcManager class is the manager class for NFC features that includes the methods for enabling and disabling the
 * NFC feature of the device and the mechanism for establishing a connection with the detected tag. It is also used to
 * detect the NFC tags and NDEF messages. @n
 * There are two ways to get the TagConnection instance established with the detected tag. @n
 * @li Use the INfcTagDiscoveryEventListener::OnNfcTagDetectedN() method that is invoked immediately when the target
 *     tag is detected.
 * @li Invoke the GetCurrentTagConnectionN() method after the tag is detected.
 *
 * If the target tag is lost, the INfcTagDiscoveryEventListener::OnNfcTagLost() method is called and the old
 * TagConnection instance becomes invalid. Therefore, the operations performed by the TagConnection class are not
 * processed anymore. Moreover, the TagConnection instance cannot be used again even if the same tags are detected
 * again by the device.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 *
 * The following example demonstrates how to use the %NfcManager class.
 *
 * @code
 * // MyClass.h
 * #include <FNet.h>
 *
 * class MyClass
 * 	: public Tizen::Net::Nfc::INfcManagerEventListener
 * 	, public Tizen::Net::Nfc::INfcTagDiscoveryEventListener
 * 	, public Tizen::Net::Nfc::INdefMessageDiscoveryEventListener
 * {
 * public:
 * 	// The method declarations are hidden for the sake of simplicity
 *
 * private:
 * 	Tizen::Net::Nfc::NfcManager*      __pNfcManager;
 * 	Tizen::Net::Nfc::TagConnection*   __pConnection;
 * };
 *
 * // MyClass.cpp
 * #include "MyClass.h"
 *
 * using namespace Tizen::Net::Nfc;
 *
 * MyClass::MyClass(void)
 * 	: __pNfcManager(null)
 * 	, __pConnection(null)
 * {
 * 	__pNfcManager = new NfcManager();
 * }
 *
 * MyClass::~MyClass(void)
 * {
 * 	// Removes the tag discovery event listener for all the NFC tag types
 * 	__pNfcManager->RemoveTagDiscoveryEventListener(*this, NFC_TAG_TYPE_ALL);
 * 	// Removes the NDEF message discovery event listener for all the TNF types
 * 	__pNfcManager->RemoveNdefMessageDiscoveryEventListener(*this, NdefRecordType(NDEF_TNF_ALL));
 *
 * 	delete __pNfcManager;
 * }
 *
 * void
 * MyClass::DiscoverySample(void)
 * {
 * 	// Creates the NfcManager instance and registers the manager event listener
 * 	__pNfcManager->Construct(*this);
 *
 * 	if (__pNfcManager->IsTagConnected())
 * 	{
 * 		// This is the way to get the connection already established with the detected tag
 * 		__pConnection = __pNfcManager->GetCurrentTagConnectionN();
 *
 * 		// Performs connection operations here
 * 	}
 *
 * 	// Adds the tag discovery event listener for all the NFC tag types
 * 	// This is the method to establish the connection with tags that are detected hereafter
 * 	__pNfcManager->AddTagDiscoveryEventListener(*this, NFC_TAG_TYPE_ALL);
 *
 * 	// Adds the NDEF message discovery event listener for all the TNF types
 * 	// This is the method to get NDEF messages that are detected hereafter
 * 	__pNfcManager->AddNdefMessageDiscoveryEventListener(*this, NdefRecordType(NDEF_TNF_ALL));
 * }
 *
 * // This method is invoked when a new tag is detected
 * void
 * MyClass::OnNfcTagDetectedN(TagConnection* pConnection)
 * {
 * 	__pConnection = pConnection;
 *
 * 	// Performs connection operations here
 * }
 *
 * // This method is invoked when the target tag is lost
 * void
 * MyClass::OnNfcTagLost(void)
 * {
 * 	// The acquired TagConnection should be deallocated
 * 	delete __pConnection;
 * }
 *
 * // This method is invoked when a new NDEF message is detected
 * void
 * MyClass::OnNdefMessageDetectedN(NdefMessage* pMessage)
 * {
 * 	// Manipulates the received message here
 *
 * 	// Deallocates the received NdefMessage
 * 	pMessage->RemoveAllRecords(true);
 * 	delete pMessage;
 * }
 * @endcode
 */
class _OSP_EXPORT_ NfcManager
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since       2.0
	 *
	 * @remarks     After creating an instance of this class, the Construct() method must be called explicitly to
	 *              initialize this instance.
	 * @see         Construct()
	 */
	NfcManager(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~NfcManager(void);

	/**
	 * Initializes this instance of %NfcManager with the specified @c listener.
	 *
	 * @since       2.0
	 * @feature     %http://tizen.org/feature/network.nfc
	 *
	 * @return      An error code
	 * @param[in]   listener                The INfcManagerEventListener instance to add
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     Before calling this method, check whether the feature is supported by 
	 *              Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	result Construct(INfcManagerEventListener& listener);

	/**
	 * Activates the NFC feature of the device.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.admin
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_IN_PROGRESS           The activation process is in progress.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the NFC feature is already activated.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @see         INfcManagerEventListener::OnNfcActivated()
	 */
	result Activate(void);

	/**
	 * Deactivates the NFC feature of the device.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.admin
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_IN_PROGRESS           The deactivation process is in progress.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified
	 *                                      operation. @n
	 *                                      For example, the NFC feature is already deactivated.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @see         INfcManagerEventListener::OnNfcDeactivated()
	 */
	result Deactivate(void);

	/**
	 * Checks whether the NFC feature is activated.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the NFC feature is activated, @n
	 *              else @c false
	 */
	bool IsActivated(void) const;

	/**
	 * Checks whether the NFC tag is currently connected with the device.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the NFC tag is currently connected, @n
	 *              else @c false
	 */
	bool IsTagConnected(void) const;

	/**
	 * Gets the tag connection with the currently detected tag.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.tag
	 *
	 * @return      The tag connection with the currently detected tag, @n
	 *              else @c null if no tag is connected or if the connection fails
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_STATE         This instance is in an invalid state. @n
	 *                                      For example, this instance has not been constructed as yet or the NFC
	 *                                      feature is not activated.
	 * @exception   E_CONNECTION_FAILED     The connection to the tag is closed or has failed.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks
	 *              - The NdefTagConnection class can inherit the TagConnection class if the currently detected tag
	 *                supports the NDEF operations. To check whether the %TagConnection class is inherited, use the
	 *                TagConnection::IsNdefConnection() method.
	 *              - The specific error code can be accessed using the GetLastResult() method.
	 */
	TagConnection* GetCurrentTagConnectionN(void) const;

	/**
	 * Adds the specified %INfcTagDiscoveryEventListener instance for the tag events with the specified tag type.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.tag
	 *
	 * @return      An error code
	 * @param[in]   listener                The listener to add
	 * @param[in]   type                    The tag type for which the listener is added
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OBJ_ALREADY_EXIST     The listener with the specified type is already added.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     This method can be invoked several times with different Tizen::Net::Nfc::NfcTagType values for the
	 *              same listener instance. In this case, the listener is called if the specified type of the target
	 *              tag matches with any one of the registered type.
	 */
	result AddTagDiscoveryEventListener(INfcTagDiscoveryEventListener& listener, NfcTagType type);

	/**
	 * Removes the specified %INfcTagDiscoveryEventListener instance. @n
	 * The removed listener cannot listen to the events that are fired.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.tag
	 *
	 * @return      An error code
	 * @param[in]   listener                The listener to remove
	 * @param[in]   type                    The tag type for which the listener is removed
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OBJ_NOT_FOUND         The listener with the specified type is not found.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result RemoveTagDiscoveryEventListener(INfcTagDiscoveryEventListener& listener, NfcTagType type);

	/**
	 * Adds the specified %INdefMessageDiscoveryEventListener instance for the events related to an NDEF message that
	 * includes the NDEF record with the specified type.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.common
	 *
	 * @return      An error code
	 * @param[in]   listener                The listener to add
	 * @param[in]   type                    The type of the NDEF record for which the listener is added
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c type is invalid. @n
	 *                                      For example, the name of the record type is an empty string if the name
	 *                                      format is NDEF_TNF_WELL_KNOWN, NDEF_TNF_MIME_MEDIA, NDEF_TNF_ABSOLUTE_URI,
	 *                                      or NDEF_TNF_EXTERNAL.
	 * @exception   E_OBJ_ALREADY_EXIST     The listener with the specified type is already added.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks
	 *              - This method can be invoked several times with different NdefRecordType values for the same
	 *                listener instance. In this case, the listener is called if the record type in the detected NDEF
	 *                records matches with one of the registered types.
	 *              - In case of the MIME %Media type as Type Name Format (TNF), asterisks can be used in the type name
	 *                for wildcard matching, such as @htmlonly "image&#47;*" @endhtmlonly.
	 */
	result AddNdefMessageDiscoveryEventListener(INdefMessageDiscoveryEventListener& listener, const NdefRecordType& type);

	/**
	 * Removes the specified %INdefMessageDiscoveryEventListener instance. @n
	 * The removed listener cannot listen to the events that are fired.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.common
	 *
	 * @return      An error code
	 * @param[in]   listener                The listener to remove
	 * @param[in]   type                    The type of the NDEF record for which the listener is removed
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c type is invalid. @n
	 *                                      For example, the name of the record type is an empty string if the name
	 *                                      format is NDEF_TNF_WELL_KNOWN, NDEF_TNF_MIME_MEDIA, NDEF_TNF_ABSOLUTE_URI,
	 *                                      or NDEF_TNF_EXTERNAL.
	 * @exception   E_OBJ_NOT_FOUND         The listener with the specified type is not found.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result RemoveNdefMessageDiscoveryEventListener(INdefMessageDiscoveryEventListener& listener, const NdefRecordType& type);

	/**
	 * Adds the specified %INfcDeviceDiscoveryEventListener instance for the device discovery events.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.p2p
	 *
	 * @return      An error code
	 * @param[in]   listener                The listener to add
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OBJ_ALREADY_EXIST     The listener has already been added.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result AddDeviceDiscoveryEventListener(INfcDeviceDiscoveryEventListener& listener);

	/**
	 * Removes the specified %INfcDeviceDiscoveryEventListener instance. @n
	 * The removed listener cannot listen to the events that are fired.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.p2p
	 *
	 * @return      An error code
	 * @param[in]   listener                The listener to remove
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OBJ_NOT_FOUND         The listener is not found.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result RemoveDeviceDiscoveryEventListener(INfcDeviceDiscoveryEventListener& listener);

	/**
	 * Checks whether peer device has been detected.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if peer device has been detected, @n
	 *              else @c false
	 */
	bool IsDeviceDetected(void) const;


	/**
	 * Gets the NDEF message cached when the tag is detected.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.common
	 * @feature     %http://tizen.org/feature/network.nfc
	 *
	 * @return      The cached %NdefMessage instance, @n
	 *              else @c null if the method is not successful
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_ILLEGAL_ACCESS        This operation is not allowed. @n
	 *                                      This exception is currently not in use.
	 * @exception   E_INVALID_FORMAT        The cached data cannot be converted to the NDEF message.
	 * @exception   E_OUT_OF_MEMORY         The memory is insufficient.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks
	 *              - The input NdefMessage instance should be deleted by the application after it is used, even
	 *                outside this method. The NdefMessage::RemoveAllRecords() method should be called with @c true as
	 *                the input value immediately before the NdefMessage instance is deleted.
	 *              - The specific error code can be accessed using the GetLastResult() method.
	 *              - Before calling this method, check whether the feature is supported by 
	 *                Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see         <a href="../org.tizen.native.appprogramming/html/guide/net/conditional_nfc_app_launch.htm">
	 *              The Conditional NFC App Launch guide</a>
	 * @see         Tizen::App::AppManager::RegisterAppLaunch
	 */
	static NdefMessage* GetCachedNdefMessageN(void);

	/**
	 * Enables or disables the Conditional NFC %App Launch pop-up. @n
	 * The pop-up includes all kinds of UI components that the system raises about NFC as well as a pop-up for
	 * selecting the launching application when a tag is detected.
	 *
	 * @since       2.0
	 * @privlevel   public
	 * @privilege   %http://tizen.org/privilege/nfc.common
	 * @feature     %http://tizen.org/feature/network.nfc
	 *
	 * @return      An error code
	 * @param[in]   enable                  Set to @c true to enable the Conditional NFC %App Launch pop-up, @n
	 *                                      else @c false
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The Emulator or target device does not support the required feature.
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception   E_USER_NOT_CONSENTED    The user blocks an application from calling this method. @b Since: @b 2.1
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks
	 *              - Note that this method is used to enable or disable the launch pop-up when the application is in
	 *                the foreground. Although the application disables the launch pop-up by invoking this method, it
	 *                is automatically enabled when the application goes to the background. The launch pop-up is
	 *                enabled by default.
	 *              - Before calling this method, check whether the feature is supported by 
	 *                Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 * @see         <a href="../org.tizen.native.appprogramming/html/guide/net/conditional_nfc_app_launch.htm">
	 *              The Conditional NFC App Launch guide</a>
	 */
	static result SetLaunchPopupEnabled(bool enable);

private:
	//
	// The implementation of this copy constructor is intentionally blank to prohibit copying of objects.
	//
	NfcManager(const NfcManager& value);

	//
	// The implementation of this copy assignment operator is intentionally blank to prohibit copying of objects.
	//
	NfcManager& operator =(const NfcManager& value);

private:
	_NfcManagerImpl* __pImpl;

	friend class _NfcManagerImpl;
}; // NfcManager

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_NFC_MANAGER_H_
