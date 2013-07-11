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
 * @file	FSysSystemInfo.h
 * @brief	This is the header file for the %SystemInfo class.
 *
 * This header file contains the declarations of the %SystemInfo class.
 */

#ifndef _FSYS_SYSTEM_INFO_H_
#define _FSYS_SYSTEM_INFO_H_

#include <FBaseString.h>
#include <FBaseUuId.h>
#include <FBaseColIList.h>

namespace Tizen { namespace System
{

/**
 * @enum	SystemInfoValueType
 *
 * Defines the data type for the %SystemInfo class.
 *
 * @since	2.0
 */
enum SystemInfoValueType
{
	VALUE_TYPE_STRING,	// This enum value is deprecated. Instead of using this enum value, use SYSTEM_INFO_VALUE_TYPE_STRING.
	VALUE_TYPE_INTEGER,	// This enum value is deprecated. Instead of using this enum value, use SYSTEM_INFO_VALUE_TYPE_INTEGER.
	VALUE_TYPE_DOUBLE,	// This enum value is deprecated. Instead of using this enum value, use SYSTEM_INFO_VALUE_TYPE_DOUBLE.
	VALUE_TYPE_UUID,	// This enum value is deprecated. Instead of using this enum value, use SYSTEM_INFO_VALUE_TYPE_UUID.
	SYSTEM_INFO_VALUE_TYPE_STRING = VALUE_TYPE_STRING,	/**< The Tizen::Base::String type */
	SYSTEM_INFO_VALUE_TYPE_INTEGER = VALUE_TYPE_INTEGER,	/**< The Tizen::Base::Integer type */
	SYSTEM_INFO_VALUE_TYPE_DOUBLE = VALUE_TYPE_DOUBLE,	/**< The Tizen::Base::Double type */
	SYSTEM_INFO_VALUE_TYPE_UUID = VALUE_TYPE_UUID,		/**< The Tizen::Base::UuId type */
};

/**
 * @class	SystemInfo
 * @brief	This class provides methods for getting system information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %SystemInfo class provides system information, such as the API and platform versions, supported device features,
 * and screen dimensions.
 * To get the information, you must provide the <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo.htm">SystemInfo key</a>.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo.htm">System Information</a>.
 *
 * The following example demonstrates how to use the %SystemInfo class.
 *
 * @code
 * #include <FBase.h>
 * #include <FSystem.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::System;
 *
 * result
 * MyClass::GetSystemInfomation(void)
 * {
 *	 result r = E_SUCCESS;
 *
 *	 String key(L"http://tizen.org/system/duid");
 *	 String deviceUniqueId;
 *
 *	 r = SystemInfo::GetValue(key, deviceUniqueId);
 *	 TryCatch(r == E_SUCCESS, , "MySystemInfo: To get a value is failed");
 *
 *	 return E_SUCCESS;
 *
 *	CATCH:
 *	 return r;
 * }
 * @endcode
 *
 */
class _OSP_EXPORT_ SystemInfo
	: public Tizen::Base::Object
{

public:
	/**
	 * Gets the specific Tizen::Base::String type system information based on the specified designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo.htm">key name</a> of the system information @n
	 * @if OSPCOMPAT
	 *			The following key values are updated: @n
	 *			- @b Since: @b 2.0 Refer <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo.htm">here</a>.
	 *				@xmlonly <pcheck kind="value" since="2.0">telephony, input.keyboard.layout, screen.size, screen.coordinatesystem.physical, screen.coordinatesystem.logical, platform.core.cpu.arch, platform.core.fpu.arch, platform.name, modelname, duid, map.provider</pcheck> @endxmlonly
	 *			- @b Deprecated All the key values provided prior to %Tizen 2.0 are deprecated. For more detailed information, refer 
	 *			 <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo_deprecated.htm">here</a>.
	 * @endif
	 * @param[out]	value			The system information of type Tizen::Base::String
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, Tizen::Base::String& value);

	/**
	 * Gets the specific integer type system information based on the specified designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo.htm">key name</a> of the system information @n
	 * @if OSPCOMPAT
	 *			The following key values are updated: @n
	 *			- @b Since: @b 2.0 Refer <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo.htm">here</a>.
	 *				@xmlonly <pcheck kind="value" since="2.0">multipointtouch.pointcount, sound.media.volume.max, sound.notification.volume.max, sound.ringtone.volume.max, sound.system.volume.max, screen.bpp, screen.height, screen.width, screen.dpi</pcheck> @endxmlonly 
	 *			- @b Deprecated All the key values provided prior to %Tizen 2.0 are deprecated. For more detailed information, refer 
	 *			 <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo_deprecated.htm">here</a>.
	 * @endif
	 * @param[out]	value			The integer type system information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, int& value);

	/**
	 * Gets the specific double type system information based on the specified designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo.htm">key name</a> of the system information
	 * @param[out]	value			The @c double type system information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, double& value);

	/**
	 * Gets the specific UuId type system information based on the specified designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo.htm">key name</a> of the system information
	 * @param[out]	value			The UuId type system information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, Tizen::Base::UuId& value);

	/**
	 * Gets the specific system information based on the specified key and data type of the information.
	 *
	 * @since	2.0
	 *
	 * @return	A system information list
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo.htm">key name</a> of the system information @n
	 * @if OSPCOMPAT
	 *		The following key values are updated @n
	 *			- @b Deprecated All the key values provided prior to %Tizen 2.0 are deprecated. For more detailed information, refer 
	 *			 <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo_deprecated.htm">here</a>.
	 * @endif
	 * @param[in]	type			The data type of the information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Base::Collection::IList* GetValuesN(const Tizen::Base::String& key, SystemInfoValueType type);

	/**
	 * Gets the specific boolean type system information based on the specified designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo.htm">key name</a> of the system information @n
	 * @if OSPCOMPAT
	 *			The following key values are updated: @n
	 *			- @b Since: @b 2.0 Refer <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo.htm">here</a>.
	 *				@xmlonly <pcheck kind="value" since="2.0">bluetooth, camera, camera.front, camera.front.flash, camera.back, camera.back.flash, location, location.wps, location.gps, microphone, nfc, sensor.barometer, sensor.barometer.wakeup, sensor.accelerometer, sensor.accelerometer.wakeup, sensor.magnetometer, sensor.magnetometer.wakeup, sensor.gyroscope, sensor.gyroscope.wakeup, sensor.photometer, sensor.photometer.wakeup, sensor.tiltmeter, sensor.tiltmeter.wakeup, sensor.proximity, sensor.proximity.wakeup, usb.host, usb.accessory, input.keyboard, wifi, wifi.direct, opengles.version.1_1, opengles.version.2_0, screen.desktopmode, screen.output.rca, screen.output.hdmi, fmradio, speech.recognition, sip.voip</pcheck> @endxmlonly 
	 *			- @b Deprecated All the key values provided prior to %Tizen 2.0 are deprecated. For more detailed information, refer 
	 *			 <a href="../org.tizen.native.appprogramming/html/guide/system/sysinfo_deprecated.htm">here</a>.
	 * @endif
	 * @param[out]	value			The @c bool type system information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, bool& value);

	/**
	 * Gets the platform version in the "[Major].[Minor].[Build Version]" format.
	 *
	 * @since 2.0
	 *
	 * @privilege	%http://tizen.org/privilege/platforminfo
	 *
	 * @return	An error code
	 * @param[out]	platformVersion		The platform version
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetPlatformVersion(Tizen::Base::String& platformVersion);

	/**
	 * Gets the Native API version in the "[Major].[Minor]" format.
	 *
	 * @since 2.0
	 *
	 * @privilege	%http://tizen.org/privilege/platforminfo
	 *
	 * @return	An error code
	 * @param[out]	nativeApiVersion	The Native API version
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetNativeApiVersion(Tizen::Base::String& nativeApiVersion);

	/**
	 * Gets the WEB API version in the "[Major].[Minor]" format.
	 *
	 * @since 2.0
	 *
	 * @privilege	%http://tizen.org/privilege/platforminfo
	 *
	 * @return	An error code
	 * @param[out]	webApiVersion		The %Tizen API version
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetWebApiVersion(Tizen::Base::String& webApiVersion);

private:
	/**
	 * This is the default constructor for this class. This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	SystemInfo(void);

	/**
	 * This is the destructor for this class. This destructor overrides Tizen::Base::Object::~Object().
	 */
	virtual ~SystemInfo(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	SystemInfo(const SystemInfo& value);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	SystemInfo& operator =(const SystemInfo& value);

private:
	friend class _SystemInfoImpl;
	class _SystemInfoImpl* __pSystemInfoImpl;
}; // SystemInfo

} } // Tizen::System

#endif //_FSYS_SYSTEM_INFO_H_
