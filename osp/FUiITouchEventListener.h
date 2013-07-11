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
* @file		FUiITouchEventListener.h
* @brief	This is the header file for the %ITouchEventListener interface.
*
* This header file contains the declarations of the %ITouchEventListener interface.
*/

#ifndef _FUI_ITOUCH_EVENT_LISTENER_H_
#define _FUI_ITOUCH_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseTypes.h>
#include <FGraphics.h>
#include <FUiTouch.h>

namespace Tizen { namespace Ui
{

class Control;

/**
 * @interface		ITouchEventListener
 * @brief			This interface is used as the argument to the touch event listener.
 *
 * @since			2.0
 *
 * The %ITouchEventListener interface is the listener interface for receiving touch events.
 * The class that processes a touch event implements this interface, and the instance created with that class is registered with a
 * UI control, using the control's AddTouchEventListener() method. When the touch event occurs, a method of that instance is
 * invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/event_listener.htm">Event Listeners</a>.
 */
class _OSP_EXPORT_ ITouchEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 *
	 */
	virtual ~ITouchEventListener(void) {}

	/**
	 * Called when an entity is touch pressed.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo & touchInfo) = 0;

	/**
	 * @if OSPDEPREC
	 * Called when an entity is touched and held for a long time.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This callback is deprecated.
	 * If you want to listen to "long press" touch event, it is recommended to use TouchLongPressGestureDetector class.
	 * @since		2.0
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 * @endif
	 */
	virtual void OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo) {}

	/**
	 * Called when an entity is touch released.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo) = 0;

	/**
	 * Called when an entity is touch moved.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo) = 0;

	/**
	 * @if OSPDEPREC
	 * Called when an entity is touched and double-pressed.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This callback is deprecated.
	 * If you want to listen to "double press" touch event, it is recommended to use TouchTapGestureDetector class.
	 * @since		2.0
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 * @endif
	 */
	virtual void OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo) {}

	/**
	 * Called when the user has touched down on a control, drags finger out of control's bounds, and then drags finger back in to the control's bounds.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo) = 0;

	/**
	 * Called when the user touches down on a control and drags finger out of control's bounds
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo) = 0;

	/**
	 * Called when the touch is canceled.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchCanceled(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo) {}

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void ITouchEventListener_Reserved3(void) {}

}; // ITouchEventListener

}} // Tizen::Ui

#endif // _FUI_ITOUCH_EVENT_LISTENER_H_
