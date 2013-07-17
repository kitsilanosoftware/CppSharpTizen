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
* @file			FUiITouchPinchGestureEventListener.h
* @brief		This is the header file for the %ITouchPinchGestureEventListener interface.
*
* This header file contains the declarations of the %ITouchPinchGestureEventListener interface.
*/

#ifndef _FUI_ITOUCH_PINCH_GESTURE_EVENT_LISTENER_H_
#define _FUI_ITOUCH_PINCH_GESTURE_EVENT_LISTENER_H_

#include <FUiTouchPinchGestureDetector.h>
#include <FUiITouchGestureEventListener.h>

namespace Tizen { namespace Ui
{

/**
 * @interface		ITouchPinchGestureEventListener
 * @brief		This interface implements the listener for the touch pinch gesture events.
 *
 * @since 2.0
 *
 * The %ITouchPinchGestureEventListener interface is the listener interface for receiving pinch gesture events.
 * The class that processes a pinch gesture event implements this interface, and the instance created with that class is registered with a
 * pinch gesture detector, using the TouchPinchGestureDetector::AddPinchGestureEventListener() method. When the pinch gesture event occurs, a method of that instance is
 * invoked.
 *
 */
class _OSP_EXPORT_ ITouchPinchGestureEventListener
	: virtual public ITouchGestureEventListener
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since 2.0
	*/
	virtual ~ITouchPinchGestureEventListener(void) {}

	/**
	* Called when a pinch gesture detection is started.
	*
	* @since 2.0
	*
	* @param[in]   gestureDetector                       The pinch gesture detector instance
	*/
	virtual void OnPinchGestureStarted(Tizen::Ui::TouchPinchGestureDetector& gestureDetector) = 0;

	/**
	* Called when a pinch gesture is detected and is in progress.
	*
	* @since 2.0
	*
	* @param[in]   gestureDetector                       The pinch gesture detector instance
	*/
	virtual void OnPinchGestureChanged(Tizen::Ui::TouchPinchGestureDetector& gestureDetector) = 0;

	/**
	* Called when a pinch gesture detection is finished.
	*
	* @since 2.0
	*
	* @param[in]   gestureDetector                       The pinch gesture detector instance
	*/
	virtual void OnPinchGestureFinished(Tizen::Ui::TouchPinchGestureDetector& gestureDetector) = 0;

	/**
	* Called when a pinch gesture detection is canceled.
	*
	* @since 2.0
	*
	* @param[in]   gestureDetector                       The pinch gesture detector instance
	*/
	virtual void OnPinchGestureCanceled(Tizen::Ui::TouchPinchGestureDetector& gestureDetector) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchPinchGestureEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchPinchGestureEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchPinchGestureEventListener_Reserved3(void) {}
}; // ITouchPinchGestureEventListener

}} // Tizen::Ui

#endif // _FUI_ITOUCH_PINCH_GESTURE_EVENT_LISTENER_H_
