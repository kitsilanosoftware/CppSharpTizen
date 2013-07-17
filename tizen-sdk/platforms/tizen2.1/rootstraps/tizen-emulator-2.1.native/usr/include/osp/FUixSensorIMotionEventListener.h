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
 * @file	FUixSensorIMotionEventListener.h
 * @brief	This is the header file for the %IMotionEventListener interface.
 *
 * This header file contains the declarations of the %IMotionEventListener interface.
 */

#ifndef _FUIX_SENSOR_IMOTION_EVENT_LISTENER_H_
#define _FUIX_SENSOR_IMOTION_EVENT_LISTENER_H_

#include <FUixSensorMotionCommon.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Uix { namespace Sensor
{

/**
 * @interface   IMotionEventListener
 * @brief       This interface is an event listener for the motion sensing events.
 *
 * @since       2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FUix.h> @n
 *              @b Library : @b osp-uix
 *
 * The %IMotionEventListener interface is a listener interface for the motion sensing events.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/device_motions.htm">Device Motions</a>.
 */

class _OSP_EXPORT_ IMotionEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
    /**
     * This is the destructor for this class.
	 *
     * @since    2.0
     */
    virtual ~IMotionEventListener(void){}

public:
	/**
	 * Called when the snap event is detected. @n
	 * When a snap event occurs, and if its type is registered by an application, then the event is triggered.
	 *
	 * @since       2.0
	 *
	 * @param[in]   snapType    The type of the snap @n
	 *                          This is one of the types in Tizen::Uix::Sensor::MotionSnapType.
	 */
	virtual void OnSnapDetected(MotionSnapType snapType) = 0;

	/**
	 * Called when the double-tap event is detected. @n
	 * When a double-tap event occurs, and if its type is registered by an application, then the event is triggered.
	 *
	 * @since   2.0
	 *
	 * @see     Tizen::Uix::Sensor::MotionType
	 */
	virtual void OnDoubleTapDetected(void) = 0;

	/**
	 * Called when the shake event is detected. @n
	 * When a shake event occurs, and if its type is registered by an application, then the event is triggered.
	 *
	 * @since       2.0
	 *
	 * @param[in]   motionState     The type of the event state @n
	 *                              This is one of the states in Tizen::Uix::Sensor::MotionState.
	 */
	virtual void OnShakeDetected(MotionState motionState) = 0;

	/**
		* Called when the move-to-ear event is detected. @n
		* When a move-to-ear event occurs, and if its type is registered by an application, then the event is triggered.
		*
		* @since   2.1
		*
		* @see     Tizen::Uix::Sensor::MotionType
		*/

	    virtual void OnMoveToEarDetected(void) {}

protected:

    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
    //
    virtual void IMotionEventListener_Reserved1(void) {}

    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
    //
    virtual void IMotionEventListener_Reserved2(void) {}
}; // IMotionEventListener

} } } // Tizen::Uix::Sensor

#endif //_FUIX_SENSOR_IMOTION_EVENT_LISTENER_H_
