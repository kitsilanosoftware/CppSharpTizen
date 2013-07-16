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
 * @file	FUiWindow.h
 * @brief	This is the header file for the %Window class.
 *
 * This header file contains the declarations of the %Window class.
 */

#ifndef _FUI_WINDOW_H_
#define _FUI_WINDOW_H_

#include <FBaseTypes.h>
#include <FUiContainer.h>
#include <FUiIWindowEventListener.h>

namespace Tizen { namespace Ui { namespace Animations {
class DisplayContext;
}}}

namespace Tizen { namespace Ui
{

class _WindowImpl;

/**
 * @enum WindowState
 *
 * Defines the state of %Window.
 *
 * @since	2.0
 */
enum WindowState
{
	WINDOW_STATE_INITIALIZED = 0x0000,      /**< The initial state of the window */
	WINDOW_STATE_ACTIVATED = 0x0001,        /**< The state indicates that the window is the topmost window */
	WINDOW_STATE_DEACTIVATED = 0x0002,      /**< The state indicates that the window is not the topmost window */
};

/**
 * @enum WindowZOrderGroup
 *
 * Defines the Z order group of %Window.
 *
 * @since 2.0
 */
enum WindowZOrderGroup
{
	WINDOW_Z_ORDER_GROUP_HIGHEST,        /**< The highest group for windows such as the call screen */
	WINDOW_Z_ORDER_GROUP_HIGH,           /**< The high group for windows such as the lock screen */
	WINDOW_Z_ORDER_GROUP_NORMAL,         /**< The default group of apps */
};

/**
 * @class	Window
 * @brief	This class provides abstract top-level 'window' objects.
 *
 * @since	2.0
 *
 * The %Window class is an abstract base class.
 * The %Window is a top-level window such as Controls::Frame, Controls::MessageBox, and Controls::Popup.
 * The descendants of a %Window can exist outside of their applications's bounds.
 *
 */
class _OSP_EXPORT_ Window
	: public Container
{

public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Window(void) = 0;

public:
	/**
	 * Adds the listener instance. @n
	 * The added listener can listen to events on when they are fired.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener    The event listener to add
	 * @see				RemoveWindowEventListener()
	 */
	void AddWindowEventListener(Tizen::Ui::IWindowEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since			2.0
	 *
	 * @param[in]	listener    The listener to remove
	 * @see				AddWindowEventListener()
	 */
	void RemoveWindowEventListener(Tizen::Ui::IWindowEventListener& listener);

	/**
	 * Shows the %Window.
	 *
	 * @since			2.0
	 *
	 * @final     Although this method is virtual, it should not be overridden.
     * If overridden, it may not work as expected.
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, or
	 *          						 	this control is not 'displayable'.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual result Show(void);

	/**
	 * Sets the owner of the window.
	 * The visibility of a window has dependency on the visibility of the owner window.
	 *
	 * @since 2.0
	 *
	 * @param[in]    pControl      The control
	 * @remarks       The ownership of @c pControl is not transferred to this instance. It is the developer's responsibility to deallocate @c pControl even after calling this method.
	 */
	void SetOwner(Tizen::Ui::Control *pControl);

	/**
	 * Gets the owner of the window.
	 *
	 * @since 2.1
	 *
	 * @return    The owner of the window
	 * @see    SetOwner()
	 */
	Tizen::Ui::Control* GetOwner(void) const;

	/**
	 * Sets the Z order group of %Window.
	 *
	 * @since 2.0
	 *
	 * @privlevel      platform
	 * @privilege      %http://tizen.org/privilege/uimanager
	 *
	 * @return         An error code
	 * @param[in]      windowZOrderGroup    The Z order group of %Window
	 * @exception      E_SUCCESS            The method is successful.
	 * @exception      E_PRIVILEGE_DENIED   The application does not have the privilege to call this method.
	 * @remarks        If this method is not explicitly called, the Z order group of %Window is set to #WINDOW_Z_ORDER_GROUP_NORMAL.
	 */
	result SetZOrderGroup(WindowZOrderGroup windowZOrderGroup);

	/**
	 * Gets the current state of the window.
	 *
	 * @since			2.0
	 *
	 * @return		The current state of the window
	 */
	WindowState GetWindowState(void) const;

	/**
	 * Gets the display context of the window.
	 *
	 * @since 2.0
	 *
	 * @return		A pointer to the DisplayContext instance
	 */
	Tizen::Ui::Animations::DisplayContext* GetDisplayContext(void) const;

protected:
	/**
	 * Initializes this instance of %Window with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   rect                                      The rectangle bounds to set
	 * @param[in]   resizable                                Set to @c true to make the window resizable, @n
	 *                                  else @c false
	 * @param[in]   movable                                          Set to @c true to make the window movable, @n
	 *                                  else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG            A specified input parameter is invalid.
	 * @remarks     This method must be called from the derived classes's construct methods.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see IsResizable()
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, bool resizable = true, bool movable = true);

	/**
	 * Initializes this instance of %Window with the specified parameters.
	 *
	 * @since 2.1
	 *
	 * @return      An error code
	 * @param[in]   rect                                      The rectangle bounds to set
	 * @param[in]   resizable                                Set to @c true to make the window resizable, @n
	 *                                  else @c false
	 * @param[in]   movable                                          Set to @c true to make the window movable, @n
	 *                                  else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG            A specified input parameter is invalid.
	 * @remarks     This method must be called from the derived classes's construct methods.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see IsResizable()
	 */
	result Construct(const Tizen::Graphics::FloatRectangle& rect, bool resizable = true, bool movable = true);

	/**
	 * Initializes this instance of %Window with the specified layout and rectangular region.
	 *
	 * @since 2.0
	 *
	 * @return                  An error code
	 * @param[in]   layout                                   The layout for both the portrait and landscape mode
	 * @param[in]   rect                                      The location and size of the %window
	 * @param[in]   resizable                                Set to @c true to make the window resizable, @n
	 *                                  else @c false
	 * @param[in]   movable                                          Set to @c true to make the window movable, @n
	 *                                  else @c false
	 * @exception   E_SUCCESS                The method is successful.
	 * @exception   E_INVALID_ARG            A specified input parameter is invalid.
	 * @remarks     This method must be called from the derived classes's construct methods.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see IsResizable()
	 * @see Tizen::Ui::Layout
	 * @see Tizen::Ui::Container::GetLayoutN()
	 */
	 result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::Rectangle& rect, bool resizable = true, bool movable = true);

	/**
	 * Initializes this instance of %Window with a specified layout and rectangular region.
	 *
	 * @since 2.1
	 *
	 * @return                  An error code
	 * @param[in]   layout                                   The layout for both the portrait and landscape mode
	 * @param[in]   rect                                      The location and size of the window
	 * @param[in]   resizable                                Set to @c true to make the window resizable, @n
	 *                                  else @c false
	 * @param[in]   movable                                          Set to @c true to make the window movable, @n
	 *                                  else @c false
	 * @exception   E_SUCCESS                The method is successful.
	 * @exception   E_INVALID_ARG            A specified input parameter is invalid.
	 * @remarks
	 *			- This method must be called from the derived classes's construct methods.
	 *			- If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see IsResizable()
	 * @see Tizen::Ui::Layout
	 * @see Tizen::Ui::Container::GetLayoutN()
	 */
	 result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::FloatRectangle& rect, bool resizable = true, bool movable = true);

	/**
	 * Initializes this instance of %Window with the specified layouts and rectangular region.
	 *
	 * @since 2.0
	 *
	 * @return                  An error code
	 * @param[in]   portraitLayout              The layout for the portrait mode
	 * @param[in]   landscapeLayout           The layout for the landscape mode
	 * @param[in]   rect                                      The location and size of the %Window
	 * @param[in]   resizable                                Set to @c true to make the window resizable, @n
	 *                                  else @c false
	 * @param[in]   movable                                          Set to @c true to make the window movable, @n
	 *                                  else @c false
	 * @exception   E_SUCCESS                The method is successful.
	 * @exception   E_INVALID_ARG            A specified input parameter is invalid.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see IsResizable()
	 * @see Tizen::Ui::Layout
	 * @see Tizen::Ui::Layout
	 * @see Tizen::Ui::Container::GetLayoutN()
	 * @see Tizen::Ui::Container::GetPortraitLayoutN()
	 * @see Tizen::Ui::Container::GetLandscapeLayoutN()
	 */
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, const Tizen::Graphics::Rectangle& rect, bool resizable = true, bool movable = true);

	/**
	 * Initializes this instance of %Window with the specified layouts and rectangular region.
	 *
	 * @since 2.1
	 *
	 * @return                  An error code
	 * @param[in]   portraitLayout              The layout for the portrait mode
	 * @param[in]   landscapeLayout           The layout for the landscape mode
	 * @param[in]   rect                                      The location and size of the %Window
	 * @param[in]   resizable                                Set to @c true to make the window resizable, @n
	 *                                  else @c false
	 * @param[in]   movable                                          Set to @c true to make the window movable, @n
	 *                                  else @c false
	 * @exception   E_SUCCESS                The method is successful.
	 * @exception   E_INVALID_ARG            A specified input parameter is invalid.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see IsResizable()
	 * @see Tizen::Ui::Layout
	 * @see Tizen::Ui::Layout
	 * @see Tizen::Ui::Container::GetLayoutN()
	 * @see Tizen::Ui::Container::GetPortraitLayoutN()
	 * @see Tizen::Ui::Container::GetLandscapeLayoutN()
	 */
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, const Tizen::Graphics::FloatRectangle& rect, bool resizable = true, bool movable = true);

	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	Window(void);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Window(const Window& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Window& operator =(const Window& rhs);

protected:
	friend class _WindowImpl;

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Window_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Window_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Window_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Window_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Window_Reserved5(void) {}
}; // Window

}} // Tizen::Ui

#endif //_FUI_WINDOW_H_
