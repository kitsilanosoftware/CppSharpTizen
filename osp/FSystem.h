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
 * @file	FSystem.h
 * @brief	This is the header file for the %System namespace.
 *
 * This header file contains the declarations of the %System namespace.
 *
 */

#ifndef _FSYSTEM_H_
#define _FSYSTEM_H_

// Alarm
#include <FSysAlarm.h>
#include <FSysIAlarmEventListener.h>

// SystemTime
#include <FSysSystemTime.h>

// Vibrator
#include <FSysVibrator.h>

// System Information
#include <FSysSystemInfo.h>

// Runtime Information
#include <FSysRuntimeInfo.h>
#include <FSysIRuntimeInfoGetIntAsyncResultListener.h>
#include <FSysIRuntimeInfoGetLonglongAsyncResultListener.h>

// Setting Information
#include <FSysSettingInfo.h>
#include <FSysISettingEventListener.h>
#include <FSysISettingInfoSetValueAsyncResultListener.h>

// Power Manager
#include <FSysIBatteryEventListener.h>
#include <FSysIScreenEventListener.h>
#include <FSysIChargingEventListener.h>
#include <FSysPowerManager.h>

// Device State
#include <FSysDeviceManager.h>
#include <FSysIDeviceEventListener.h>

// Environment
#include <FSysEnvironment.h>

namespace Tizen
{
/**
 * @namespace	Tizen::System
 * @brief	This namespace contains classes and interfaces for %System.
 * @since	2.0
 *
 * @remarks    @b Header @b %file: @b \#include @b <FSystem.h> @n
 *				@b Library : @b osp-appfw
 *
 * The %System namespace provides system management features, such as system time, alarm, vibrator, power, and device management.
 * It also provides the system, setting, and runtime information.
 *
 * For more information on the %System namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/system/system_namespace.htm">System Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %System namespace.
 *
 * @image html system_namespace_classdiagram.png
 *
 */
namespace System
{}; // System
}; // Tizen

#endif // _FSYSTEM_H_
