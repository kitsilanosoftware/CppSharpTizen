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
* @file			FUiITouchCustomGestureEventListener.h
* @brief		This is the header file for the %ITouchCustomGestureEventListener interface.
*
* This header file contains the declarations of the %ITouchCustomGestureEventListener interface.
*/

#ifndef _FUI_ITOUCH_CUSTOM_GESTURE_EVENT_LISTENER_H_
#define _FUI_ITOUCH_CUSTOM_GESTURE_EVENT_LISTENER_H_

#include <FUiITouchGestureEventListener.h>

namespace Tizen { namespace Ui
{

/**
 * @interface		ITouchCustomGestureEventListener
 * @brief		This interface is used as the argument to the touch custom gesture event listener.
 * @since 2.0
 *
 * The %ITouchCustomGestureEventListener interface is the listener interface for receiving custom gesture events.
 * The class that processes a custom gesture event implements this interface, and the instance created with that class is registered with a
 * gesture detector, using the TouchGestureDetector::AddGestureEventListener() method. When the custom gesture event occurs, a method of that instance is
 * invoked.
 *
 */
class _OSP_EXPORT_ ITouchCustomGestureEventListener
	: virtual public ITouchGestureEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since 2.0
	*/
	virtual ~ITouchCustomGestureEventListener(void) {}

	/**
	* Called when a custom gesture detection is started.
	*
	* @since 2.0
	*
	* @param[in]   gestureDetector		The custom gesture detector instance
	*/
	virtual void OnCustomGestureStarted(Tizen::Ui::TouchGestureDetector& gestureDetector) = 0;

	/**
	* Called when a custom gesture is detected and is in progress.
	*
	* @since 2.0
	*
	* @param[in]   gestureDetector 		The custom gesture detector instance
	*/
	virtual void OnCustomGestureChanged(Tizen::Ui::TouchGestureDetector& gestureDetector) = 0;

	/**
	* Called when a custom gesture detection is finished.
	*
	* @since 2.0
	*
	* @param[in]   gestureDetector 		The custom gesture detector instance
	*/
	virtual void OnCustomGestureFinished(Tizen::Ui::TouchGestureDetector& gestureDetector) = 0;

	/**
	* Called when a custom gesture detection is canceled.
	*
	* @since 2.0
	*
	* @param[in]   gestureDetector 		The custom gesture detector instance
	*/
	virtual void OnCustomGestureCanceled(Tizen::Ui::TouchGestureDetector& gestureDetector) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Following method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchCustomGestureEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Following method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchCustomGestureEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Following method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchCustomGestureEventListener_Reserved3(void) {}
}; // ITouchCustomGestureEventListener

}} // Tizen::Ui

#endif // _FUI_ITOUCH_CUSTOM_GESTURE_EVENT_LISTENER_H_
