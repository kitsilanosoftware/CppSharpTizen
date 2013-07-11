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
 * @file	FUiITouchGestureEventListener.h
 * @brief	This is the header file for the %ITouchGestureEventListener interface.
 *
 * This header file contains the declarations of the %ITouchGestureEventListener interface.
 */

#ifndef _FUI_ITOUCH_GESTURE_EVENT_LISTENER_H_
#define _FUI_ITOUCH_GESTURE_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Ui
{

/**
 * @class		ITouchGestureEventListener
 * @brief		This is a base interface that all gesture event listeners must implement.
 *
 * @since 2.0
 *
 * The %ITouchGestureEventListener interface is a base interface that all gesture event listeners must implement.
 * The event listener can listen when the specific event occurs. The event listener
 * has several methods, and each method is called when a specific event occurs.
 *
 */
class _OSP_EXPORT_ ITouchGestureEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~ITouchGestureEventListener(void) {}

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchGestureEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchGestureEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchGestureEventListener_Reserved3(void) {}
}; // ITouchGestureEventListener

}} // Tizen::Ui

#endif // _FUI_ITOUCH_GESTURE_EVENT_LISTENER_H_
