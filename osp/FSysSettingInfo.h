//
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
 * @file	FSysSettingInfo.h
 * @brief	This is the header file for the %SettingInfo class.
 *
 * This header file contains the declarations of the %SettingInfo class.
 */

#ifndef _FSYS_SETTING_INFO_H_
#define _FSYS_SETTING_INFO_H_

#include <FBaseString.h>
#include <FBaseUuId.h>
#include <FBaseColIList.h>
#include <FSysISettingEventListener.h>
#include <FSysISettingInfoSetValueAsyncResultListener.h>

namespace Tizen { namespace System
{

/**
 * @class	SettingInfo
 * @brief	This class provides methods for managing setting information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %SettingInfo class provides methods to managing the variety user setting elements. Please refer <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">SettingInfo key</a>.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">Settings Information</a>.
 *
 * The following example demonstrates how to use the %SettingInfo class.
 *
 *
 * @code
 * #include <FBase.h>
 * #include <FSystem.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::System;
 *
 * result
 * MyClass::GetSettingInfomation(void)
 * {
 *	 result r = E_SUCCESS;
 *
 *	 String key(L"http://tizen.org/setting/location.gps");
 *	 bool gpsEnabled = false;
 *
 *	 r = SettingInfo::GetValue(key, gpsEnabled);
 *	 TryCatch(r == E_SUCCESS, , "MySettingInfo: To get a value is failed");
 *
 *	 return E_SUCCESS;
 *
 *	CATCH:
 *	 return r;
 * }
 * @endcode
 *
 */
class _OSP_EXPORT_ SettingInfo
	: public Tizen::Base::Object
{

public:
	/**
	 * Gets the specific Tizen::Base::String type setting information based on the specified
	 * designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information @n
	 * @param[out]	value		The setting information of type Tizen::Base::String
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key exists. However, it is not supported by this device.
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, Tizen::Base::String& value);

	/**
	 * Gets the specific integer type setting information based on the specified
	 * designators (keys).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information @n
	 * @param[out]	value		The setting information of type integer
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key exists. However, it is not supported by this device.
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, int& value);

	/**
	 * Gets the specific @c long @c long type setting information based on the specified
	 * designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key		The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[out]	value		The setting information of type @c long @c long
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key exists. However, it is not supported by this device.
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, long long& value);

	/**
	 * Gets the specific double type setting information based on the specified
	 * designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key		The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[out]	value		The setting information of type double
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key exists. However, it is not supported by this device.
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, double& value);

	/**
	 * Gets the specific @c bool type setting information based on the specified
	 * designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information @n
	 * @param[out]	value		The setting information of type bool
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key exists. However, it is not supported by this device.
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, bool& value);

	/**
	 * Gets the specific UuId type setting information based on the specified
	 * designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[out]	value		The setting information of type UuId
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key exists. However, it is not supported by this device.
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, Tizen::Base::UuId& value);

	/**
	 * Checks whether specific designator(key) is supported or not.
	 *
	 * @since 2.0
	 *
	 * @return @c true if the key is supported, @n
	 * 	else @c false
	 * @param[in]	key The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information
	 *
	 */
	static bool HasKey(const Tizen::Base::String& key);

	/**
	 * Sets the specific @c bool type setting information based on the specified designators (key).
	 *
	 * @since 2.0
	 *
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/setting
	 *
	 * @return	An error code
	 * @param[in]	key			The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[in]	value			The setting information of type bool
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGED_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c value is invalid value.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key exists. However, it is not supported by this device.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result SetValue(const Tizen::Base::String& key, bool value);

	/**
	 * Sets the specific @c int type setting information based on the specified designators (key).
	 *
	 * @since 2.0
	 *
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/setting
	 *
	 * @return	An error code
	 * @param[in]	key			The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[in]	value			The setting information of type int
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGED_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c value is invalid value.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key exists. However, it is not supported by this device.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result SetValue(const Tizen::Base::String& key, int value);

	/**
	 * Sets the specific Tizen::Base::String type setting information based on the specified designators (key).
	 *
	 * @since 2.0
	 *
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/setting
	 *
	 * @return	An error code
	 * @param[in]	key			The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[in]	value			The setting information of type Tizen::Base::String
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGED_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c value is invalid value.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key exists. However, it is not supported by this device.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result SetValue(const Tizen::Base::String& key, Tizen::Base::String value);

	/**
	 * Sets the system wallpaper.
	 *
	 * @since	2.0
	 *
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/setting
	 *
	 * @return	An error code
	 * @param[in]	filePath		The file path of the wallpaper
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_FILE_NOT_FOUND	The entry for the specified wallpaper file or the file path cannot be found.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */

	static result SetWallpaper(const Tizen::Base::String& filePath);

	/**
	 * Sets the system ringtone.
	 *
	 * @since	2.0
	 *
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/setting
	 *
	 * @return	An error code
	 * @param[in]	filePath		The file path of the ringtone
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_FILE_NOT_FOUND	The entry for the specified wallpaper file or the file path cannot be found.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result SetRingtone(const Tizen::Base::String& filePath);

	/**
	 * Sets the sound volume level.
	 *
	 * @since	2.0
	 *
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/setting
	 *
	 * @return	An error code
	 * @param[in]	soundCategory		The sound volume category
	 * @param[in]	level			The sound volume level of the designated category
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c soundCategory is invalid.
	 * @exception	E_OUT_OF_RANGE		The specified @c level is outside the bounds of @c soundCategory.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result SetVolume(const Tizen::Base::String& soundCategory, int level);

	/**
	 * Adds the setting event listener. @n
	 * This listener is called when a setting value is changed.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @param[in] listener			The setting event listener
	 * @exception E_SUCCESS			The method is successful.
	 * @exception E_OBJ_ALREADY_EXIST 	The listener is already added.
	 * @exception E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @see	 RemoveSettingEventListener() 
	 */
	static result AddSettingEventListener(ISettingEventListener& listener);

	/**
	 * Removes the setting event listener.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @param[in] listener			The setting event listener
	 * @exception E_SUCCESS			The method is successful.
	 * @exception E_OBJ_NOT_FOUND		The listener is not added.
	 * @exception E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @see	 AddSettingEventListener()
	 */
	static result RemoveSettingEventListener(ISettingEventListener& listener);

	/**
	 * Gets the specific @c bool type setting information based on the specified designators (key).
	 *
	 * @since 2.0
	 *
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/settingmanager.read @n
	 *		(%http://tizen.org/privilege/systemsetting.read is deprecated.)
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[out]	value			The setting information of type bool
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGED_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key exists. However, it is not supported by this device.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetValueForPrivilegedKey(const Tizen::Base::String& key, bool& value);

	/**
	 * Sets the specific @c bool type setting information based on the specified designators (key).
	 *
	 * @since 2.0
	 *
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/settingmanager.write @n
	 *		(%http://tizen.org/privilege/systemsetting.write is deprecated.)
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[in]	value			The setting information of type bool
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGED_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c value is invalid value.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key exists. However, it is not supported by this device.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result SetValueForPrivilegedKey(const Tizen::Base::String& key, bool value);

	/**
	 * Sets the specific @c bool type setting information based on the specified designators (key) asynchronously.
	 *
	 * @since 2.0
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/settingmanager.write @n
	 *		(%http://tizen.org/privilege/systemsetting.write is deprecated.)
	 *
	 * @return	An error code
	 * @param[in]	key			The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[in]	value			The setting information of type bool
	 * @param[in]	listener 		The result listener.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGED_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c value is invalid value.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key is existed, However it is not supported by this device.
	 * @exception	E_IN_PROGRESS		The specified key is under processing or invalid state.
	 * @exception	E_SYSTEM		Either of the following conditions has occured:
	 *					- The method cannot proceed due to a severe system error.
	 *					- This error can occur and Wi-Fi Direct™ is not activated if the @c key is %http://tizen.org/setting/network.wifi.direct and Wi-Fi is activated.-
Direct™ is not activated if the @c key is %http://tizen.org/setting/network.wifi.direct and Wi-Fi is activated.

	 */
	static result SetValueAsyncForPrivilegedKey(const Tizen::Base::String& key, bool value, ISettingInfoSetValueAsyncResultListener* listener);

	/**
	 * Sets the specific @c bool type setting information based on the specified designators (key) asynchronously.
	 *
	 * @since 2.0
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/setting
	 *
	 * @return	An error code
	 * @param[in]	key			The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[in]	value			The setting information of type bool
	 * @param[in]	listener 		The result listener.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGED_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c value is invalid value.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key is existed, However it is not supported by this device.
	 * @exception	E_IN_PROGRESS		The specified key is under processing or invalid state.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result SetValueAsync(const Tizen::Base::String& key, bool value, ISettingInfoSetValueAsyncResultListener* listener);


	/**
	 * Sets the specific Tizen::Base::String type setting information based on the specified designators (key).
	 *
	 * @since 2.0
	 *
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/settingmanager.write @n
	 *		(%http://tizen.org/privilege/systemsetting.write is deprecated.)
	 *
	 * @return	An error code
	 * @param[in]	key			The <a href="../org.tizen.native.appprogramming/html/guide/system/settings_info.htm">key name</a> of the setting information
	 * @param[in]	value			The setting information of type Tizen::Base::String
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGED_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG		The specified @c value is invalid value.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_UNSUPPORTED_OPERATION	The specified @c key exists. However, it is not supported by this device.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result SetValueForPrivilegedKey(const Tizen::Base::String& key, Tizen::Base::String value);

	/**
	 * Resets current device. @n
	 * All data is removed and device is initialized.
	 *
	 * @since 2.0
	 *
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/settingmanager.write @n
	 *		(%http://tizen.org/privilege/systemsetting.write is deprecated.)
	 *
	 * @return	An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGED_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result ResetToFactoryDefault(void);

	/**
	 */
	static result SetSettingEventListener(ISettingEventListener* pListener);


private:
	/**
	 * This is the default constructor for this class. This default constructor is intentionally
 declared as private so that only the platform can create an instance.
	 */
	SettingInfo(void);

	/**
	 * This is the destructor for this class.  This destructor overrides Tizen::Base::Object::~Object().
	 */
	virtual ~SettingInfo(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	SettingInfo(const SettingInfo& value);

	/**
	 *  The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	SettingInfo& operator =(const SettingInfo& value);

private:
	friend class _SettingInfoImpl;
	class _SettingInfoImpl* __pSettingInfoImpl;
}; // SettingInfo

} } // Tizen::System

#endif // _FSYS_SETTING_INFO_H_
