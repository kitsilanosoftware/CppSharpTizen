//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file			FUiITouchTapGestureEventListener.h
 * @brief		This is the header file for the %ITouchTapGestureEventListener interface.
 *
 * This header file contains the declarations of the %ITouchTapGestureEventListener interface.
 */

#ifndef _FUI_ITOUCH_TAP_GESTURE_EVENT_LISTENER_H_
#define _FUI_ITOUCH_TAP_GESTURE_EVENT_LISTENER_H_

#include <FUiTouchTapGestureDetector.h>
#include <FUiITouchGestureEventListener.h>

namespace Tizen { namespace Ui
{

/**
 * @class		ITouchTapGestureEventListener
 * @brief		This interface implements the listener for the touch tap gesture events.
 *
 * @since 2.0
 *
 * The %ITouchTapGestureEventListener interface is the listener interface for receiving tap gesture events.
 * The class that processes a tap gesture event implements this interface, and the instance created with that class is registered with a
 * tap gesture detector, using the gesture detector's AddTapGestureEventListener() method. When the tap gesture event occurs, a method of that instance is
 * invoked.
 *
 */
class _OSP_EXPORT_ ITouchTapGestureEventListener
	: virtual public ITouchGestureEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~ITouchTapGestureEventListener(void) {}

	/**
	 * Called when a tap gesture is detected.
	 *
	 * @since 2.0
	 *
	 * @param[in]   gestureDetector    The tap gesture detector instance
	 */
	virtual void OnTapGestureDetected(Tizen::Ui::TouchTapGestureDetector& gestureDetector) = 0;

	/**
	 * Called when a tap gesture detection is canceled.
	 *
	 * @since 2.0
	 *
	 * @param[in]   gestureDetector    The tap gesture detector instance
	 */
	virtual void OnTapGestureCanceled(Tizen::Ui::TouchTapGestureDetector& gestureDetector) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchTapGestureEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchTapGestureEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchTapGestureEventListener_Reserved3(void) {}
}; // ITouchTapGestureEventListener

}} // Tizen::Ui

#endif //_FUI_ITOUCH_TAP_GESTURE_EVENT_LISTENER_H_
