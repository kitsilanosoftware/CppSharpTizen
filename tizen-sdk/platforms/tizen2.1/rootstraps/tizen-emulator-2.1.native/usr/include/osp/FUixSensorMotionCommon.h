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
 * @file	FUixSensorMotionCommon.h
 * @brief	This is the header file for the declarations of the enumerations of the Sensor namespace.
 *
 * This header file contains the declarations of the enumerations of the Sensor namespace.
 */

#ifndef _FUIX_SENSOR_MOTION_COMMON_H_
#define _FUIX_SENSOR_MOTION_COMMON_H_

namespace Tizen { namespace Uix { namespace Sensor
{

/**
 * @enum	MotionType
 *
 * Defines the types of motions provided.
 *
 * @since	2.0
 *
 * @see     Motion::SetEnabled()
 */
enum MotionType
{
	MOTION_TYPE_NONE = 0x0000,      /**< The motion type: None */
	MOTION_TYPE_SNAP = 0x0001,      /**< The motion type: Snap */
	MOTION_TYPE_SHAKE = 0x0002,     /**< The motion type: Shake */
	MOTION_TYPE_DOUBLETAP = 0x0004, /**< The motion type: Tap */
	MOTION_TYPE_MOVE_TO_EAR = 0x0008, /**< The motion type: Move to ear @b Since: @b 2.1 */
	MOTION_TYPE_ALL = 0xFFFF,       /**< The motion type: All */
};

/**
 * @enum  MotionState
 *
 * Defines the state of motions. @n
 * Some event can only be found in a subset of states described below.
 *
 * @since	2.0
 *
 * @see     IMotionEventListener::OnShakeDetected()
 */
enum MotionState
{
	MOTION_STARTED,     /**< The specified motion has just started */
	MOTION_INPROGRESS,  /**< The specified motion is happening */
	MOTION_ENDED,       /**< The specified motion has just ended */
	MOTION_CANCELLED,   /**< The specified motion has just canceled */
};

/**
 * @enum  MotionSnapType
 *
 * Defines the types of snap provided.
 *
 * @since	2.0
 *
 * @see     IMotionEventListener::OnSnapDetected()
 */
enum MotionSnapType
{
	MOTION_SNAP_X_POSITIVE, /**< Snaps to positive X */
	MOTION_SNAP_X_NEGATIVE, /**< Snaps to negative X */
	MOTION_SNAP_Y_POSITIVE, /**< Snaps to positive Y */
	MOTION_SNAP_Y_NEGATIVE, /**< Snaps to negative Y */
	MOTION_SNAP_Z_POSITIVE, /**< Snaps to positive Z */
	MOTION_SNAP_Z_NEGATIVE, /**< Snaps to negative Z */
};

} } } // Tizen::Uix::Sensor

#endif //_FUIX_SENSOR_MOTION_COMMON_H_
