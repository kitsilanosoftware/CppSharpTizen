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
 * @file		FUiKeyEventManager.h
 * @brief		This is the header file for the %KeyEventManager class.
 *
 * This header file contains the declarations of the %KeyEventManager class.
 */

#ifndef _FUI_KEY_EVENT_MANAGER_H_
#define _FUI_KEY_EVENT_MANAGER_H_

#include <FBaseObject.h>
#include <FBaseErrors.h>
#include <FUiIKeyEventListener.h>

namespace Tizen { namespace Base { namespace Runtime
{
class _IEvent;
class IEventArg;
}}}

namespace Tizen {namespace Ui
{
class Control;

/**
 * @class	KeyEventManager
 * @brief	This class manages the key events that are fired within the context of this application.
 *
 * @since	2.0
 *
 * @final        This class is not intended for extension.
 *
 * The %KeyEventManager class listens to all key events that are generated within the application's context.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/event_listener.htm">Event Listeners</a>.
 */
class _OSP_EXPORT_ KeyEventManager
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Osp::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~KeyEventManager(void);

	/**
	 * Gets the pointer to the current key event manager.
	 *
	 * @since	 	2.0
	 *
	 * @return		The current %KeyEventManager instance
	 */
	static KeyEventManager* GetInstance(void);

	/**
	 * Adds an application-wide %IKeyEventListener instance. @n
	 * The added listeners get notified when a key is pressed, released, or long pressed within the context of this application.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	listener    The event listener to be added
	 * @remarks     The listener is called after the key event is delivered to the focused control's key event listeners, but before the
	 *              key event is passed onto the focused control itself. @n
	 *              Moreover, if the key needs to be consumed by the control itself, the added listeners will not be notified.
	 * @see         RemoveKeyEventListener ()
	 */
	void AddKeyEventListener(IKeyEventListener& listener);

	/**
	 * Removes the %IKeyEventListener instance. @n
	 * The removed listener is not notified even when the key events are fired.
	 *
	 * @since		2.0
	 *
	 * @return		listener		The current application-wide key event listener to be removed
	 * @see			AddKeyEventListener()
	 */
	void RemoveKeyEventListener(IKeyEventListener& listener);

protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	KeyEventManager(void);

	/**
	 * Initializes this instance of %KeyEventManager.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result Construct(void);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	KeyEventManager(const KeyEventManager& value);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	KeyEventManager& operator =(const KeyEventManager& value);

	static void InitializeInstance(void);

}; // KeyEventManager

}} // Tizen::Ui

#endif // _FUI_KEY_EVENT_MANAGER_H_
