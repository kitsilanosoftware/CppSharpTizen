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
 * @file	FSysDeviceManager.h
 * @brief	This is the header file for the %DeviceManager class.
 *
 * This header file contains the declarations of the %DeviceManager class.
 *
 *
 */

#ifndef _FSYS_DEVICE_MANAGER_H_
#define _FSYS_DEVICE_MANAGER_H_

#include <FBaseObject.h>

namespace Tizen { namespace System
{

class IDeviceEventListener;

/**
* @enum		DeviceType
* Defines the type of the supported devices.
*
* @since	2.0
*
*/
enum DeviceType
{
	BluetoothHeadset,	// This enum value is deprecated. Instead of using this enum value, use DEVICE_TYPE_BLUETOOTH_HEADSET.
	Charger,		// This enum value is deprecated. Instead of using this enum value, use DEVICE_TYPE_CHARGER.
	UsbClient,		// This enum value is deprecated. Instead of using this enum value, use DEVICE_TYPE_USB_CLIENT.
	TvOut,			// This enum value is deprecated. Instead of using this enum value, use DEVICE_TYPE_TV_OUT.
	WiredHeadset,		// This enum value is deprecated. Instead of using this enum value, use DEVICE_TYPE_WIRED_HEADSET.
	WiredHeadphone,		// This enum value is deprecated. Instead of using this enum value, use DEVICE_TYPE_WIRED_HEADPHONE.
	StorageCard,		// This enum value is deprecated. Instead of using this enum value, use DEVICE_TYPE_STORAGE_CARD.
	Keyboard,		// This enum value is deprecated. Instead of using this enum value, use DEVICE_TYPE_KEYBOARD.
	DEVICE_TYPE_BLUETOOTH_HEADSET = BluetoothHeadset,	/**< Bluetooth headset */
	DEVICE_TYPE_CHARGER = Charger,				/**< Charger*/
	DEVICE_TYPE_USB_CLIENT = UsbClient,			/**< USB client */
	DEVICE_TYPE_TV_OUT = TvOut,				/**< TV out */
	DEVICE_TYPE_WIRED_HEADSET = WiredHeadset,		/**< Wired headset */
	DEVICE_TYPE_WIRED_HEADPHONE = WiredHeadphone,		/**< Wired headphone */
	DEVICE_TYPE_STORAGE_CARD = StorageCard,			/**< Storage card */
	DEVICE_TYPE_KEYBOARD = Keyboard,			/**< Hardware Built-in keyboard */
	DEVICE_TYPE_HDMI,					/**< HDMI @if OSPCOMPAT @b Since @  2.0 @endif */
};

/**
 * @class	DeviceManager
 * @brief	This class provides methods for device management.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %DeviceManager class provides listener to handle events for various external device,
 * such as a Bluetooth headset, HDMI, and headphone.
 * This class also gets the current state of the device. You cannot create an instance of this class directly.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/system/device_management.htm">External Device Management</a>.
 *
 * @see IDeviceEventListener
 *
 */
class _OSP_EXPORT_ DeviceManager
	: public Tizen::Base::Object
{

public:
	/**
	 * Gets the specific device state.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with %Tizen API versions @b prior @b to @b 2.0. @n
	 *			For more information, see @ref DeviceManagerGetStatePage "here".
	 * @endif
	 *
	 * @param[in]	deviceType	The value from the enumerator DeviceType indicating the device
	 * @param[out]	state		The device <a href="../org.tizen.native.appprogramming/html/guide/system/device_management.htm">state</a> of type Tizen::Base::String
	 *
	 * @return	An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG		The specified @c deviceType is not valid.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c deviceType is not supported on this model.
	 */
	static result GetState(DeviceType deviceType, Tizen::Base::String& state);

	/**
	 * @if OSPCOMPAT
	 * @page DeviceManagerGetStatePage Compatibility for GetState()
	 * @section DeviceManagerGetStatePageIssueSection Issues
	 * Implementation of this method in %Tizen API version prior to 2.0 has the following issue: @n
	 * The GetState() method does not return E_DEVICE_UNAVAILABLE anymore. The E_DEVICE_UNAVAILABLE exception is removed.
	 * @section DeviceManagerGetStatePageIssueSection Resolutions
	 * The E_UNSUPPORTED_OPERATION exception is added since 2.0. So, use E_UNSUPPORTED_OPERATION instead of E_DEVICE_UNAVAILABLE.
	 * @endif
	 */

	/**
	 * Adds a device event listener.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with %Tizen API versions @b prior @b to @b 2.0. @n
	 *			For more information, see @ref DeviceManagerAddDeviceEventListenerPage "here".
	 * @endif
	 *
	 * @return	An error code
	 * @param[in]	deviceType		The types of a device
	 * @param[in]	listener		The device event listener
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG		The specified @c deviceType is not valid.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c deviceType and @c listener are already registered.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c deviceType is not supported on this model.
	 */
	static result AddDeviceEventListener(DeviceType deviceType, IDeviceEventListener& listener);

	/**
	 * @if OSPCOMPAT
	 * @page DeviceManagerAddDeviceEventListenerPage Compatibility for AddDeviceEventListener()
	 * @section DeviceManagerAddDeviceEventListenerPageIssueSection Issues
	 * Implementation of this method in %Tizen API version prior to 2.0 has the following issue: @n
	 * This AddDeviceEventListener() method does not return E_DEVICE_UNAVAILABLE anymore. The E_DEVICE_UNAVAILABLE exception is removed.
	 * @section DeviceManagerAddDeviceEventListenerPageIssueSection Resolutions
	 * The E_UNSUPPORTED_OPERATION exception is added since 2.0. So, use E_UNSUPPORTED_OPERATION instead of E_DEVICE_UNAVAILABLE exception.
	 * @endif
	 */

	/**
	 * Removes a device event listener from all types of devices.
	 *
	 * @since	2.0
 	 *
	 * @return	An error code
	 * @param[in]	deviceType		The types of a device
	 * @param[in]	listener		The device event listener
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception	E_INVALID_ARG		The specified @c deviceType is not valid.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c deviceType and @c listener are not registered.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c deviceType is not supported on this model.
	 */
	static result RemoveDeviceEventListener(DeviceType deviceType, IDeviceEventListener& listener);

	/**
	 * @if OSPCOMPAT
	 * @page DeviceManagerRemoveDeviceEventListenerPage Compatibility for RemoveDeviceEventListener()
	 * @section DeviceManagerRemoveDeviceEventListenerPageIssueSection Issues
	 * Implementation of this method in %Tizen API version prior to 2.0 has the following issue: @n
	 * This RemoveDeviceEventListener() method does not return E_DEVICE_UNAVAILABLE anymore. The E_DEVICE_UNAVAILABLE exception is removed.
	 * @section DeviceManagerRemoveDeviceEventListenerPageIssueSection Resolutions
	 * The E_UNSUPPORTED_OPERATION exception is added since 2.0. So, use E_UNSUPPORTED_OPERATION instead of E_DEVICE_UNAVAILABLE exception.
	 * @endif
	 */

	/**	 
	 * Removes all device event listeners.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 */
	static result RemoveAllDeviceEventListeners(void);

private:
	/**
	 * This is the default constructor for this class. This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	DeviceManager(void);

	/**
	 * This is the destructor for this class. This destructor overrides Tizen::Base::Object::~Object(). @n
	 */
	virtual ~DeviceManager(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	DeviceManager(const DeviceManager& value);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	DeviceManager& operator =(const DeviceManager& value);

private:
	friend class _DeviceManagerImpl;
	class _DeviceManagerImpl* __pDeviceManagerImpl;

}; // DeviceManager

} } // Tizen::System
#endif // _FSYS_DEVICE_MANAGER_H_
