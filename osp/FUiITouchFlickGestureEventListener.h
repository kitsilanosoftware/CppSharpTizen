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
 * @file			FUiITouchFlickGestureEventListener.h
 * @brief		This is the header file for the %ITouchFlickGestureEventListener interface.
 *
 * This header file contains the declarations of the %ITouchFlickGestureEventListener interface.
 */

#ifndef _FUI_ITOUCH_FLICK_GESTURE_EVENT_LISTENER_H_
#define _FUI_ITOUCH_FLICK_GESTURE_EVENT_LISTENER_H_

#include <FUiITouchGestureEventListener.h>
#include <FUiTouchFlickGestureDetector.h>

namespace Tizen { namespace Ui
{

/**
 * @class		ITouchFlickGestureEventListener
 * @brief		This interface implements the listener for the touch flick gesture events.
 * @since 2.0
 *
 * The %ITouchFlickGestureEventListener interface is the listener interface for receiving flick gesture events.
 * The class that processes a flick gesture event implements this interface, and the instance created with that class is registered with a
 * flick gesture detector, using the gesture detector's AddFlickGestureEventListener() method. When the flick gesture event occurs, a method of that instance is
 * invoked.
 *
 */
class _OSP_EXPORT_ ITouchFlickGestureEventListener
	: virtual public ITouchGestureEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~ITouchFlickGestureEventListener(void) {}

	/**
	 * Called when a flick gesture is detected.
	 *
	 * @since 2.0
	 *
	 * @param[in]   gestureDetector		The flick gesture detector instance
	 */
	virtual void OnFlickGestureDetected(Tizen::Ui::TouchFlickGestureDetector& gestureDetector) = 0;

	/**
	 * Called when a flick gesture detection is canceled.
	 *
	 * @since 2.0
	 *
	 * @param[in]   gestureDetector		The flick gesture detector instance
	 */
	virtual void OnFlickGestureCanceled(Tizen::Ui::TouchFlickGestureDetector& gestureDetector) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Following method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchFlickGestureEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Following method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchFlickGestureEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Following method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchFlickGestureEventListener_Reserved3(void) {}
}; // ITouchFlickGestureEventListener

}} // Tizen::Ui

#endif // _FUI_ITOUCH_FLICK_GESTURE_EVENT_LISTENER_H_
