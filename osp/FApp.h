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
 * @file			FApp.h
 * @brief			This is the header file for the %App namespace.
 *
 * This header file contains the declarations of the %App namespace.
 */

#ifndef _FAPP_H_
#define _FAPP_H_

#include <FAppTypes.h>
#include <FAppApp.h>
#include <FAppAppControl.h>
#include <FAppAppManager.h>
#include <FAppAppRegistry.h>
#include <FAppAppResource.h>
#include <FAppDataControlProviderManager.h>
#include <FAppIAppCheckPointEventListener.h>
#include <FAppIAppControlEventListener.h>
#include <FAppIAppControlListener.h>
#include <FAppIAppFrame.h>
#include <FAppIMapDataControlProviderEventListener.h>
#include <FAppIMapDataControlResponseListener.h>
#include <FAppISqlDataControlProviderEventListener.h>
#include <FAppISqlDataControlResponseListener.h>
#include <FAppMapDataControl.h>
#include <FAppNotificationManager.h>
#include <FAppServiceApp.h>
#include <FAppSqlDataControl.h>
#include <FAppUiApp.h>
#include <FAppAppControlProviderManager.h>
#include <FAppIAppControlProviderEventListener.h>
#include <FAppIAppLaunchConditionEventListener.h>
#include <FAppAppSetting.h>
#include <FAppIAppSettingEventListener.h>
#include <FAppIActiveAppEventListener.h>
#include <FAppIAppControlResponseListener.h>

#include <FAppPkg.h>

/**
 * @namespace	Tizen::App
 * @brief		This namespace contains classes for application development.
 * @since	2.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FApp.h> @n
 *				@b Library : @b osp-appfw
 *
 * The %App namespace contains the classes for application development, including application life-cycle management, usage of
 * functionality exported by other applications through AppControl, and access to application registry and resources. Tizen
 * also provides various macros for debugging purposes.
 * @n
 * For more information on the %App namespace features and the macros, see <a href="../org.tizen.native.appprogramming/html/guide/app/app_namespace.htm">App Guide</a> and <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/debugging_macros.htm">Debugging Macros</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %App namespace.
 *
 * @image html app_namespace_classdiagram.png
 */

namespace Tizen { namespace App
{

} } // Tizen::App

#endif // _FAPP_H_
