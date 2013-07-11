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
* @file		FUiIDragDropEventListener.h
* @brief	This is the header file for the %IDragDropEventListener interface.
*
* This header file contains the declarations of the %IDragDropEventListener interface.
*/
#ifndef _FUI_IDRAG_DROP_EVENT_LISTENER_H_
#define _FUI_IDRAG_DROP_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseTypes.h>
#include <FGraphics.h>

namespace Tizen { namespace Ui
{

class Control;

/**
 * @interface	IDragDropEventListener
 * @brief		This interface implements the listener for a drag and drop event.
 *
 * @since		2.0
 *
 * The %IDragDropEventListener interface is the listener interface for receiving drag and drop events.
 * The class that processes a drag and drop event implements this interface, and the instance created with that class is
 * registered with a UI control, using the control's AddDragDropEventListener() method. When the drag and drop event occurs, a
 * method of that instance is invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/event_listener.htm">Event Listeners</a>.
 */
class _OSP_EXPORT_ IDragDropEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	 //
	 // This method is for internal use only.
	 // Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	 //
	 // This is the destructor for this class.
	 //
	 // @since			2.0
	 //
	virtual ~IDragDropEventListener(void) {}

	/**
	 * Called when an entity is dragged.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	startPosition	The start position
	 * @param[in] 	currentPosition	The current position
	 */
	virtual void OnTouchDragged(const Tizen::Ui::Control& source,
		const Tizen::Graphics::Point& startPosition, const Tizen::Graphics::Point& currentPosition) = 0;

	/**
	 * Called when an entity is dropped.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	startPosition	The start position
	 * @param[in] 	currentPosition	The current position
	 */
	virtual void OnTouchDropped(const Tizen::Ui::Control& source,
		const Tizen::Graphics::Point& startPosition, const Tizen::Graphics::Point& currentPosition) = 0;

protected:
	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IDragDropEventListener_Reserved1(void) {}

	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IDragDropEventListener_Reserved2(void) {}

	// Reserved virtual methods for later extension
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void IDragDropEventListener_Reserved3(void) {}
}; // IDragDropEventListener

} }    // Tizen::Ui

#endif // _FUI_IDRAG_DROP_EVENT_LISTENER_H_
