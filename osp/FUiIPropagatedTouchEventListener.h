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
 * @file FUiIPropagatedTouchEventListener.h
 * @brief          This is the header file for the %IPropagatedTouchEventListener interface.
 *
 * This header file contains the declarations of the %IPropagatedTouchEventListener interface.
 */

#ifndef _FUI_IPROPAGATED_TOUCH_EVENT_LISTENER_H_
#define _FUI_IPROPAGATED_TOUCH_EVENT_LISTENER_H_

namespace Tizen { namespace Ui {

class Control;
class TouchEventInfo;

/**
 * @interface	IPropagatedTouchEventListener
 * @brief		This interface is used as an argument for the propagated touch event listener.
 *
 * @since                              2.1
 *
 * The %IPropagatedTouchEventListener interface is the listener interface for receiving propagated touch events. @n
 * The class that processes a propagated touch event implements this interface, and the instance created with that class is registered with a
 * UI control, using the Control::SetPropagatedTouchEventListener() method. When the touch event occurs, a method of that instance which is derived from %IPropagatedTouchEventListener is
 * invoked.
 * The propagated touch event listeners work according to the event previewing and bubbling concept. @n
 * When a touch event occurs, as a previewing notification it is routed from the top-most Window, which is usually a Frame,
 * to a control which is the parent of the control where the event occurs. Then, as a bubbling notification it is routed from
 * the control to the top-most Window.
 * In both previewing and bubbling paths, event routing can be controlled by the value returned by the listener. Returning @c true, which means
 * the event is processed in the listener of the notified control, stops further routing. Returning @c false allows the next event listener
 * to listen to the event.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/event_listener.htm">Event Listeners</a>.
 */
class _OSP_EXPORT_ IPropagatedTouchEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IPropagatedTouchEventListener(void){}

	/**
	 * Called during the bubbling step when a touch is pressed.
	 *
	 * @since                     2.1
	 *
	 * @return                              Whether the touch event is processed by the listener or not
	 * @param[in]    source                        The source of the event
	 * @param[in]    touchEventInfo                    The touch event information
	 */
	virtual bool OnTouchPressed(Control& source, const TouchEventInfo& touchEventInfo) = 0;

	/**
	 * Called during the bubbling step when a touch is released.
	 *
	 * @since                     2.1
	 *
	 * @return                              Whether the touch event is processed by the listener or not
	 * @param[in]    source                        The source of the event
	 * @param[in]    touchEventInfo                    The touch event information
	 */
	virtual bool OnTouchReleased(Control& source, const TouchEventInfo& touchEventInfo) = 0;

	/**
	 * Called during the bubbling step when a touch is moved.
	 *
	 * @since                     2.1
	 *
	 * @return                              Whether the touch event is processed by the listener or not
	 * @param[in]    source                        The source of the event
	 * @param[in]    touchEventInfo                    The touch event information
	 */
	virtual bool OnTouchMoved(Control& source, const TouchEventInfo& touchEventInfo) = 0;

	/**
	 * Called during the bubbling step when a touch is canceled.
	 *
	 * @since                     2.1
	 *
	 * @return                              Whether the touch event is processed by the listener or not
	 * @param[in]    source                        The source of the event
	 * @param[in]    touchEventInfo                    The touch event information
	 */
	virtual bool OnTouchCanceled(Control& source, const TouchEventInfo& touchEventInfo) = 0;

	/**
	 * Called during the previewing step when a touch is pressed.
	 *
	 * @since                                         2.1
	 *
	 * @return                              Whether the touch event is processed by the listener or not
	 * @param[in]   source                        The source of the event
	 * @param[in]   touchEventInfo                    The touch event information
	 */
	virtual bool OnPreviewTouchPressed(Control& source, const TouchEventInfo& touchEventInfo) = 0;


	/**
	 * Called during the previewing step when a touch is released.
	 *
	 * @since                                         2.1
	 *
	 * @return                              Whether the touch event is processed by the listener or not
	 * @param[in]   source                        The source of the event
	 * @param[in]   touchEventInfo                    The touch event information
	 */
	virtual bool OnPreviewTouchReleased(Control& source, const TouchEventInfo& touchEventInfo) = 0;

	/**
	 * Called during the previewing step when a touch is moved.
	 *
	 * @since                                         2.1
	 *
	 * @return                              Whether the touch event is processed by the listener or not
	 * @param[in]   source                        The source of the event
	 * @param[in]   touchEventInfo                    The touch event information
	 */
	virtual bool OnPreviewTouchMoved(Control& source, const TouchEventInfo& touchEventInfo) = 0;

protected:
	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IPropagatedTouchEventListener_Reserved1(void) {}

	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IPropagatedTouchEventListener_Reserved2(void) {}

	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IPropagatedTouchEventListener_Reserved3(void) {}

	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IPropagatedTouchEventListener_Reserved4(void) {}

	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IPropagatedTouchEventListener_Reserved5(void) {}
}; // IPropagatedTouchEventListener

}} // Tizen::Ui
#endif // _FUI_IPROPAGATED_TOUCH_EVENT_LISTENER_H_