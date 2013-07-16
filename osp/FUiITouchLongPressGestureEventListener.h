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
 * @file			FUiITouchLongPressGestureEventListener.h
 * @brief		This is the header file for the %ITouchLongPressGestureEventListener interface.
 *
 * This header file contains the declarations of the %ITouchLongPressGestureEventListener interface.
 */

#ifndef _FUI_ITOUCH_LONG_PRESS_GESTURE_EVENT_LISTENER_H_
#define _FUI_ITOUCH_LONG_PRESS_GESTURE_EVENT_LISTENER_H_

#include <FUiTouchLongPressGestureDetector.h>
#include <FUiITouchGestureEventListener.h>

namespace Tizen { namespace Ui
{

/**
 * @interface		ITouchLongPressGestureEventListener
 * @brief		This interface implements the listener for the touch long press gesture events.
 *
 * @since 2.0
 *
 * The %ITouchLongPressGestureEventListener interface is the listener interface for receiving long press gesture events.
 * The class that processes a long press gesture event implements this interface, and the instance created with that class is registered with a
 * long press gesture detector, using the TouchLongPressGestureDetector::AddLongPressGestureEventListener() method. When the long press gesture event occurs, a method of that instance is
 * invoked.
 */
class _OSP_EXPORT_ ITouchLongPressGestureEventListener
	: virtual public ITouchGestureEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~ITouchLongPressGestureEventListener(void) {}

	/**
	 * Called when a long press gesture is detected.
	 *
	 * @since 2.0
	 *
	 * @param[in]   gestureDetector			The long press gesture detector instance
	 */
	virtual void OnLongPressGestureDetected(Tizen::Ui::TouchLongPressGestureDetector& gestureDetector) = 0;

	/**
	 * Called when a long press detection is canceled.
	 *
	 * @since 2.0
	 *
	 * @param[in]   gestureDetector			The long press gesture detector instance
	 */
	virtual void OnLongPressGestureCanceled(Tizen::Ui::TouchLongPressGestureDetector& gestureDetector) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchLongPressGestureEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchLongPressGestureEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchLongPressGestureEventListener_Reserved3(void) {}
}; // ITouchLongPressGestureEventListener

}} // Tizen::Ui

#endif // _FUI_ITOUCH_LONG_PRESS_GESTURE_EVENT_LISTENER_H_
