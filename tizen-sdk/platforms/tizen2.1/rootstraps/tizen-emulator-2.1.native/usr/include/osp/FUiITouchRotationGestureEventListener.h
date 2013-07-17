//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
* @file			FUiITouchRotationGestureEventListener.h
* @brief		This is the header file for the %ITouchRotationGestureEventListener interface.
*
* This header file contains the declarations of the %ITouchRotationGestureEventListener interface.
*/
#ifndef _FUI_ITOUCH_ROTATION_GESTURE_EVENT_LISTENER_H_
#define _FUI_ITOUCH_ROTATION_GESTURE_EVENT_LISTENER_H_

#include <FUiTouchRotationGestureDetector.h>
#include <FUiITouchGestureEventListener.h>

namespace Tizen { namespace Ui
{

/**
 * @interface		ITouchRotationGestureEventListener
 * @brief		This interface implements the listener for the touch rotation gesture events.
 *
 * @since 2.0
 *
 * The %ITouchRotationGestureEventListener interface is the listener interface for receiving pinch gesture events.
 * The class that processes a rotation gesture event implements this interface, and the instance created with that class is registered with a
 * rotation gesture detector, using the TouchRotationGestureDetector::AddRotationGestureEventListener() method. When the rotation gesture event occurs, a method of that instance is
 * invoked.
 *
 */
class _OSP_EXPORT_ ITouchRotationGestureEventListener
   : virtual public ITouchGestureEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since				2.0
	 */
	virtual ~ITouchRotationGestureEventListener(void) {}

	/**
	* Called when a rotation gesture detection is started.
	*
	* @since 2.0
	*
	* @param[in]   gestureDetector                       The rotation gesture detector instance
	*/
	virtual void OnRotationGestureStarted(Tizen::Ui::TouchRotationGestureDetector& gestureDetector) = 0;

	/**
	* Called when a rotation gesture is detected and is in progress.
	*
	* @since 2.0
	*
	* @param[in]   gestureDetector                       The rotation gesture detector instance
	*/
	virtual void OnRotationGestureChanged(Tizen::Ui::TouchRotationGestureDetector& gestureDetector) = 0;

	/**
	* Called when a rotation gesture detection is finished.
	*
	* @since 2.0
	*
	* @param[in]   gestureDetector                       The rotation gesture detector instance
	*/
	virtual void OnRotationGestureFinished(Tizen::Ui::TouchRotationGestureDetector& gestureDetector) = 0;

	/**
	* Called when a rotation gesture detection is canceled.
	*
	* @since 2.0
	*
	* @param[in]   gestureDetector                       The rotation gesture detector instance
	*/
	virtual void OnRotationGestureCanceled(Tizen::Ui::TouchRotationGestureDetector& gestureDetector) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchRotationGestureEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchRotationGestureEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchRotationGestureEventListener_Reserved3(void) {}
}; // ITouchRotationGestureEventListener

}} // Tizen::Ui

#endif //_FUI_ITOUCH_ROTATION_GESTURE_EVENT_LISTENER_H_
