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
 * @file		FAppTypes.h
 * @brief		This is the header file for the enumerations of the App class.
 *
 *	This header file contains the declarations of the enumerations of the App class.
 * @see			Application
 */

#ifndef _FAPP_TYPES_H_
#define _FAPP_TYPES_H_

#include <FBaseString.h>

namespace Tizen { namespace App
{

/**
 * The package ID
 *
 * @since	2.0
 */
typedef Tizen::Base::String PackageId;

/**
 * The application ID
 *
 * @since	2.0
 */
typedef Tizen::Base::String AppId;

/**
 * @if OSPDEPREC
 * The application secret
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This type is deprecated because the associated App::GetAppSecret() method is deprecated.
 *
 * @since	2.0
 * @endif
 */
typedef Tizen::Base::String AppSecret;

/**
 * @enum	AppState
 * Defines the various states of an application's life cycle.
 *
 * @since	2.0
 */
enum AppState
{
	INITIALIZING,   /**< The application has been launched */
	RUNNING,        /**< The application has been initialized and is currently being executed */
	TERMINATING,    /**< The application is about to exit and releases its resources and saves its preferences */
	TERMINATED  /**< The application has been destroyed */
};

/**
 * @enum	AppUiState
 * Defines the UI state of an application.
 *
 * @since		2.0
 */
enum AppUiState
{
	APP_UI_STATE_FOREGROUND = 0x01,             /**< The application is completely visible on foreground */
	APP_UI_STATE_PARTIAL_BACKGROUND = 0x02,     /**< The application is partially hidden by another window, such as a system pop-up */
	APP_UI_STATE_BACKGROUND = 0x04              /**< The application is completely hidden by a full-screen window, usually by another application or an application control */
};

/**
 * @enum	AppCtrlResult
 * Defines the application control result.
 *
 * @since	2.0
 */
enum AppCtrlResult
{
	APP_CTRL_RESULT_SUCCEEDED = 0x00,	/**< The application operation is successful */
	APP_CTRL_RESULT_FAILED = 0x01,		/**< The application operation has failed */
	APP_CTRL_RESULT_CANCELED = 0x02,	/**< The application operation is canceled by the callee application */
	APP_CTRL_RESULT_TERMINATED = 0x04,	/**< The callee application is terminated without sending the result */
	APP_CTRL_RESULT_ABORTED = 0x08,		/**< The application operation is aborted by the platform */
};

/**
 * @if OSPDEPREC
 * The application launch request ID. @n
 * Represents the application launch arguments in App::App::OnUserEventReceivedN().
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is deprecated. From %Tizen API version 2.1, App::App::OnUserEventReceivedN()
 * 				is not invoked for the request from application and %AppLaunchRequestId is not used anymore.
 *				Instead, use IAppControlProviderEventListener.
 * @since	2.0
 *
 * @see     App::App::OnUserEventReceivedN()
 * @endif
 */
const long AppLaunchRequestId = (-0xFFFF);

/**
 * @if OSPDEPREC
 * Defines the launch type - normal launch.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * 				Instead of using this variable, it is recommended to use IAppControlProviderEventListener to acquire the launch information.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APP_LAUNCH_NORMAL;

/**
 * @if OSPDEPREC
 * Defines the launch type - conditional launch.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * 				Instead of using this variable, it is recommended to use IAppLaunchConditionEventListener to acquire the conditional launch information.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APP_LAUNCH_CONDITIONAL;

}} // Tizen::App

#endif // _FAPP_TYPES_H_
