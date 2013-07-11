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
 * @file	FUixMotion.h
 * @brief	This is the header file for the %Motion class.
 *
 * This header file contains the declarations of the %Motion class.
 */

#ifndef _FUIX_SENSOR_MOTION_H_
#define _FUIX_SENSOR_MOTION_H_

#include <FUixSensorMotionCommon.h>
#include <FUixSensorIMotionEventListener.h>
#include <FBaseObject.h>
#include <FBaseDataType.h>

namespace Tizen { namespace Uix { namespace Sensor
{

class _MotionImpl;

/**
 * @class	Motion
 * @brief	This class is used to probe the state or to receive an event about the conceptual states of the device's movement.
 *
 * @since	2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FUix.h> @n
 *              @b Library : @b osp-uix
 *
 * The %Motion class allows an application to know about the movement of the device. The information is given in 2 ways:
 * the application probes the state or the application registers a listener and receives an event when a movement is observed.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/device_motions.htm">Device Motions</a>.
 *
 * The following example demonstrates how to use the %Motion class to register a motion event listener and receive motion events.
 *
 * @code
 * class MotionExample : public Tizen::Uix::IMotionEventListener
 * {
 * public:
 *   result Initialize();
 *
 *   // IMotionEventListener
 *   void OnDoubleTapDetected(void);
 *   void OnShakeDetected(Tizen::Uix::Sensor::MotionState motionState);
 *   void OnSnapDetected(Tizen::Uix::Sensor::MotionSnapType snapType);
 *
 * private:
 *   Tizen::Uix::Motion* pMotion;
 * };
 *
 * result MotionExample::Initialize(void)
 * {
 *   pMotion = new Motion();
 *   pMotion->Construct(*this);
 *   pMotion->SetEnabled(MOTION_TYPE_DOUBLETAP | MOTION_TYPE_SHAKE);
 *
 *   return E_SUCCESS;
 * }
 *
 * void
 * MotionExample::OnDoubleTapDetected(void)
 * {
 *	// ....
 * }
 *
 * void
 * MotionExample::OnShakeDetected(MotionState motionState)
 * {
 *	// ....
 * }
 *
 * void
 * MotionExample::OnSnapDetected(MotionSnapType snapType)
 * {
 *   // In this example, since Snap is not enabled, this listener will not be called.
 * }
 * @endcode
 */

class _OSP_EXPORT_ Motion
	: public Tizen::Base::Object
{
// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since   2.0
	 */
	Motion(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since   2.0
	 */
	virtual ~Motion(void);

//Operation
public:
	/**
	 * Initializes this instance of %Motion with the specified listener.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   listener                    An instance of IMotionEventListener
	 * @exception   E_SUCCESS                   The method is successful.
	 * @exception   E_OUT_OF_MEMORY             The memory is insufficient.
	 * @exception   E_INVALID_STATE             This instance is in an invalid state.
	 * @exception   E_MAX_EXCEEDED              The application has reached the maximum number of motion instances.
	 * @exception   E_UNSUPPORTED_OPERATION     The motion detection is not supported.
	 */
	result Construct(IMotionEventListener& listener);

	/**
	 * Sets the motion event type. @n
	 * If this method is not called, then by default all the motion event types will be captured by the listener.
	 * If the motion events are not be captured, this method can be called with @c type set to @c MOTION_TYPE_NONE.
	 *
	 * @since       2.0
	 *
	 * @param[in]   type                The type of motions that are captured by a listener @n
	 *                                  Multiple motion types of type Tizen::Uix::Sensor::MotionType can be combined using the logical OR operator.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance has not been constructed as yet.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.  @if OSPCOMPAT @b Since: @b 2.0 @endif
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	void SetEnabled(unsigned long type);

	/**
	 * Checks whether the specified @c MotionType is supported. @n
	 * @c MOTION_TYPE_NONE and @c MOTION_TYPE_ALL are invalid, and @c false will be returned for these types.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the specified motion type is supported, @n
	 *              else @c false
	 * @param[in]   type    The type of the motion to query
	 */
	bool IsSupported(MotionType type) const;

private:
	Motion(const Motion& value);
	Motion& operator =(const Motion& value);

private:
	_MotionImpl* __pMotionImpl;
	friend class _MotionImpl;

}; // Motion

} } } // Tizen::Uix::Sensor

#endif //_FUIX_SENSOR_MOTION_H_
