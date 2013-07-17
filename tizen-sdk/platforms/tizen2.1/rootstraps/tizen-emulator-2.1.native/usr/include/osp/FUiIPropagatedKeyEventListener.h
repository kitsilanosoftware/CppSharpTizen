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
 * @file FUiIPropagatedKeyEventListener.h
 * @brief          This is the header file for the %IPropagatedKeyEventListener interface.
 *
 * This header file contains the declarations of the %IPropagatedKeyEventListener interface.
 */

#ifndef _FUI_IPROPAGATED_KEY_EVENT_LISTENER_H_
#define _FUI_IPROPAGATED_KEY_EVENT_LISTENER_H_

namespace Tizen { namespace Ui
{

class Control;
class KeyEventInfo;

/**
 * @interface	IPropagatedKeyEventListener
 * @brief		This interface is used as an argument for the propagated key event listener.
 *
 * @since		2.1
 *
 * The %IPropagatedKeyEventListener interface is the listener interface for receiving propagated key events.
 * The class that processes a propagated key event implements this interface, and the instance created with that class is registered with a
 * UI control, using the Control::SetPropagatedKeyEventListener() method. When the key event occurs, a method of that instance that is derived from %IPropagatedKeyEventListener is
 * invoked.
 * The propagated key event listeners work according to the event previewing and bubbling concept. @n
 * When a key event occurs, as a previewing notification it is routed from the top-most Window, which is usually a Frame,
 * to a control which is the parent of the control where the event occurs. Then, as a bubbling notification it is routed from
 * the control to the top-most Window.
 * In both previewing and bubbling paths, event routing can be controlled by the value returned by the listener. Returning @c true, which means
 * the event is processed in the listener of the notified control, stops further routing. Returning @c false allows the next event listener
 * to listen to the event.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/event_listener.htm">Event Listeners</a>.
 */
class _OSP_EXPORT_ IPropagatedKeyEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IPropagatedKeyEventListener(void){}

	/**
	 * Called during the bubbling step when a key is pressed.
	 *
	 * @since                     2.1
	 *
	 * @return                              Whether the key event is processed by the listener or not
	 * @param[in]     source                        The source of the event
	 * @param[in]     keyEventInfo        The key event information
	 */
	virtual bool OnKeyPressed(Control& source, const KeyEventInfo& keyEventInfo) = 0;

	/**
	 * Called during the bubbling step when a key is released.
	 *
	 * @since                     2.1
	 *
	 * @return                              Whether the key event is processed by the listener or not
	 * @param[in]     source                        The source of the event
	 * @param[in]     keyEventInfo            The key event information
	 */
	virtual bool OnKeyReleased(Control& source, const KeyEventInfo& keyEventInfo) = 0;

	/**
	 * Called during the previewing step when a key is pressed.
	 *
	 * @since                                         2.1
	 *
	 * @return                              Whether the key event is processed by the listener or not
	 * @param[in]   source                        The source of the event
	 * @param[in]   keyEventInfo                    The key event information
	 */
	virtual bool OnPreviewKeyPressed(Control& source, const KeyEventInfo& keyEventInfo) = 0;

	/**
	 * Called during the previewing step when a key is released.
	 *
	 * @since                                         2.1
	 *
	 * @return                              Whether the key event is processed by the listener or not
	 * @param[in]   source                        The source of the event
	 * @param[in]   keyEventInfo                    The key event information
	 */
	virtual bool OnPreviewKeyReleased(Control& source, const KeyEventInfo& keyEventInfo) = 0;

	/**
	 * Called before the OnPreviewKeyPressed() or OnPreviewKeyReleased() method is called, allowing the application to modify the KeyEventInfo instance. @n
	 * Before previewing and bubbling paths, the %TranslateKeyEventInfo() method is called once.
	 *
	 * @since                     2.1
	 *
	 * @return                              Whether the KeyEventInfo instance is modified or not
	 * @param[in]     source                        The source of the event
	 * @param[in,out]     keyEventInfo            The key event information that can be converted by this method
	 */
	virtual bool TranslateKeyEventInfo(Control& source, KeyEventInfo& keyEventInfo) { return false; }

protected:
	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IPropagatedKeyEventListener_Reserved1(void) {}

	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IPropagatedKeyEventListener_Reserved2(void) {}

	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IPropagatedKeyEventListener_Reserved3(void) {}

	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IPropagatedKeyEventListener_Reserved4(void) {}

	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IPropagatedKeyEventListener_Reserved5(void) {}
}; //IPropagatedKeyEventListener

}} // Tizen::Ui
#endif // _FUI_IPROPAGATED_KEY_EVENT_LISTENER_H_