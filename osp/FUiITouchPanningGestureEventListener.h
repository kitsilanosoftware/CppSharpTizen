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
 * @file			FUiITouchPanningGestureEventListener.h
 * @brief		This is the header file for the %ITouchPanningGestureEventListener interface.
 *
 * This header file contains the declarations of the %ITouchPanningGestureEventListener interface.
 */
#ifndef _FUI_ITOUCH_PANNING_GESTURE_EVENT_LISTENER_H_
#define _FUI_ITOUCH_PANNING_GESTURE_EVENT_LISTENER_H_

#include <FUiTouchPanningGestureDetector.h>
#include <FUiITouchGestureEventListener.h>

namespace Tizen { namespace Ui
{

/**
 * @class		ITouchPanningGestureEventListener
 * @brief		This interface implements the listener for the touch panning gesture events.
 *
 * @since 2.0
 *
 * The %ITouchPanningGestureEventListener interface is the listener interface for receiving panning gesture events.
 * The class that processes a panning gesture event implements this interface, and the instance created with that class is registered with a
 * panning gesture detector, using the gesture detector's AddPanningGestureEventListener() method. When the panning gesture event occurs, a method of that instance is
 * invoked.
 *
 */
class _OSP_EXPORT_ ITouchPanningGestureEventListener
  : virtual public ITouchGestureEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~ITouchPanningGestureEventListener(void) {}

	/**
	 * Called when a panning gesture detection is started.
	 *
	 * @since 2.0
	 *
	 * @param[in]   gestureDetector                       The panning gesture detector instance
	 */
	virtual void OnPanningGestureStarted(Tizen::Ui::TouchPanningGestureDetector& gestureDetector) = 0;

	/**
	 * Called when a panning gesture is detected and is in progress.
	 *
	 * @since 2.0
	 *
	 * @param[in]   gestureDetector                       The panning gesture detector instance
	 */
	virtual void OnPanningGestureChanged(Tizen::Ui::TouchPanningGestureDetector& gestureDetector) = 0;

	/**
	 * Called when a panning gesture detection is finished.
	 *
	 * @since 2.0
	 *
	 * @param[in]   gestureDetector                       The panning gesture detector instance
	 */
	virtual void OnPanningGestureFinished(Tizen::Ui::TouchPanningGestureDetector& gestureDetector) = 0;

	/**
	 * Called when a panning gesture detection is canceled.
	 *
	 * @since 2.0
	 *
	 * @param[in]   gestureDetector                       The panning gesture detector instance
	 */
	virtual void OnPanningGestureCanceled(Tizen::Ui::TouchPanningGestureDetector& gestureDetector) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchPanningGestureEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchPanningGestureEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchPanningGestureEventListener_Reserved3(void) {}
}; //ITouchPanningGestureEventListener

}} // Tizen::Ui

#endif //_FUI_ITOUCH_PANNING_GESTURE_EVENT_LISTENER_H_
