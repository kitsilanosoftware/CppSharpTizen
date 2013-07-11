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
 * @file	FUiCtrlScrollPanel.h
 * @brief	This is the header file for the %ScrollPanel class.
 *
 * This header file contains the declarations of the %ScrollPanel class.
 */

#ifndef _FUI_CTRL_SCROLL_PANEL_H_
#define _FUI_CTRL_SCROLL_PANEL_H_

#include <FBaseString.h>
#include <FBaseTypes.h>
#include <FUiCtrlForm.h>
#include <FUiCtrlInputTypes.h>
#include <FUiCtrlPanel.h>
#include <FUiCtrlIScrollEventListener.h>
#include <FUiCtrlScrollPanelTypes.h>
#include <FUiCtrlTableViewTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @class	ScrollPanel
 * @brief	This class implements a scrollable container class.
 *
 * @since	2.0
 *
 * The %ScrollPanel class is a Panel with automatic scroll bars.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_panels.htm">Panels</a>.
 *
 * The following example demonstrates how to use the %ScrollPanel class.
 *
 * @code
// Sample code for ScrollPanelSample.h
#include <FUi.h>

class ScrollPanelSample
	: public Tizen::Ui::Controls::Form
{
public:
	ScrollPanelSample(void)
	: __pScrollPanel(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

private:
	Tizen::Ui::Controls::ScrollPanel* __pScrollPanel;
};
 *	@endcode
 *
 *	@code
// Sample code for ScrollPanelSample.cpp
#include <FGraphics.h>

#include "ScrollPanelSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
ScrollPanelSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
ScrollPanelSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of ScrollPanel
	__pScrollPanel = new ScrollPanel();
	__pScrollPanel->Construct(Rectangle(100, 250, 400, 300));
	__pScrollPanel->SetBackgroundColor(Color::GetColor(COLOR_ID_YELLOW));

	// Creates an instance of Button and an instance of EditField
	Button* pButton = new Button();
	pButton->Construct(Rectangle(0, 80, 200, 150), L"Button");

	EditField* pEdit = new EditField();
	pEdit->Construct(Rectangle(0, 250, 200, 150));
	pEdit->SetText(L"Edit");

	// Adds the button and the edit field to the ScrollPanel
	__pScrollPanel->AddControl(*pButton);
	__pScrollPanel->AddControl(*pEdit);

	// Adds the ScrollPanel to the form
	AddControl(*__pScrollPanel);

	return r;
}
 * @endcode
 */

class _OSP_EXPORT_ ScrollPanel
	: public Panel
{

// Lifecycle
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 */
	ScrollPanel(void);


	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 *
	 */
	virtual ~ScrollPanel(void);


	/**
	 * Initializes this instance of %ScrollPanel with the specified rectangular region.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect		    	The location and size of the %ScrollPanel control
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception 	E_INVALID_ARG		The given width or height is less than 0.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks 		By default, the scroll direction is vertical and the scroll area is resized automatically.
	 * @see			Tizen::Ui::Container
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect);


	/**
	 * Initializes this instance of %ScrollPanel and child controls with the specified resource ID @n
	 *
	 * This method first attempts to find the resource file in the folder that corresponds to the current screen resolution. @n
	 * If it fails to find the resource file, it searches in other folders in the following order when CoordinateSystem is Logical in the application manifest file @n
	 * the density folder that corresponds to the current screen size category  "res/screen-size-normal/" folder.
	 *
	 * @since 2.0
	 *
	 * @return           An error code
	 * @param[in]  resourceId              The resource ID describing the %ScrollPanel control
	 * @exception  E_SUCCESS               The method is successful.
	 * @exception  E_FILE_NOT_FOUND        The specified file cannot be found.
	 * @exception  E_INVALID_FORMAT        The specified XML format is invalid.
	 * @exception  E_OPERATION_FAILED      The operation has failed.
	 */
	result Construct(const Tizen::Base::String& resourceId);

	/**
	 * Initializes this instance of %ScrollPanel with the specified rectangular region.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	rect				The location and size of the %ScrollPanel control
	 * @param[in]	scrollDirection				The scroll direction of %ScrollPanel
	 * @param[in]	autoResizingEnable				Whether to resize the client area automatically
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception 	E_INVALID_ARG		The given width or height is less than 0.
	 * @see			Tizen::Ui::Container
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, ScrollPanelScrollDirection scrollDirection, bool autoResizingEnable);


	/**
	 * Initializes this instance of %ScrollPanel with the specified layout and rectangular region.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	layout				The layout for both the portrait and landscape mode
	 * @param[in]	rect				The location and size of the %ScrollPanel control
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception 	E_INVALID_ARG		@c layout is already bound to another container, or the given width or the height is less than 0.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks 		By default, the scroll direction is vertical and the scroll area is resized automatically.
	 * @see			Tizen::Ui::Container
	 */
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::Rectangle& rect);


	/**
	 * Initializes this instance of %ScrollPanel with the specified layout and rectangular region.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	layout				The layout for both the portrait and landscape mode
	 * @param[in]	rect				The location and size of the %ScrollPanel control
	 * @param[in]	scrollDirection				The scroll direction of %ScrollPanel
	 * @param[in]	autoResizingEnable				Whether to resize the client area automatically
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception 	E_INVALID_ARG		@c layout is already bound to another container, or the given width or height is less than 0.
	 * @see			Tizen::Ui::Container
	 */
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::Rectangle& rect, ScrollPanelScrollDirection scrollDirection, bool autoResizingEnable);


	/**
	 * Initializes this instance of %ScrollPanel with the specified layouts and rectangular region.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	portraitLayout		The layout for the portrait mode
	 * @param[in]	landscapeLayout		The layout for the landscape mode
	 * @param[in]	rect				The location and size of the %ScrollPanel control
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception 	E_INVALID_ARG		@c portraitLayout or @c landscapeLayout is already bound to another container, or the given width or height is less than 0.
	 * @exception	E_SYSTEM	    	A system error has occurred.
	 * @remarks 		By default, the scroll direction is vertical and the scroll area is resized automatically.
	 * @see			Tizen::Ui::Container
	 */
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, const Tizen::Graphics::Rectangle& rect);


	/**
	 * Initializes this instance of %ScrollPanel with the specified layouts and rectangular region.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	portraitLayout		The layout for the portrait mode
	 * @param[in]	landscapeLayout		The layout for the landscape mode
	 * @param[in]	rect				The location and size of the %ScrollPanel control
	 * @param[in]	scrollDirection				The scroll direction of %ScrollPanel
	 * @param[in]	autoResizingEnable				Whether to resize the client area automatically
	 * @exception	E_SUCCESS	    	The method is successful.
	 * @exception 	E_INVALID_ARG		@c portraitLayout or @c landscapeLayout is already bound to another container, or the given width or height is less than 0.
	 * @see			Tizen::Ui::Container
	 */
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, const Tizen::Graphics::Rectangle& rect, ScrollPanelScrollDirection scrollDirection, bool autoResizingEnable);


	/**
	 * Adds a listener instance that listens to the state changes of a scroll event. @n
	 * The added listener can listen to the events on the given event dispatcher's context when they are fired.
	 *
	 * @since       		2.0
	 *
	 * @param[in]	listener The listener to add
	 * @exception	E_SUCCESS	The method is successful.
 	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @see				IScrollEventListener::OnScrollEndReached()
	 * @see				RemoveScrollEventListener()
	 */
	void AddScrollEventListener(IScrollEventListener& listener);


	/**
	 * Removes a listener instance that listens to the state changes of a scroll event. @n
	 * The removed listener cannot listen to the events when they are fired.
	 *
	 * @since          	2.0
	 *
	 * @param[in]  	listener   The listener to remove
	 * @see			IScrollEventListener::OnScrollEndReached()
	 * @see			AddScrollEventListener()
	 */
	void RemoveScrollEventListener(IScrollEventListener& listener);


	/**
	 * Gets the scroll position.
	 *
	 * @since		2.0
	 *
	 * @return		The scroll position
	 */
	int GetScrollPosition(void) const;


	/**
	 * @if OSPDEPREC
	 * Sets the scroll position.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated. Instead of using this method, use the SetScrollPosition(int, bool), which supports animated scroll.
	 * @since		2.0
	 *
	 * @param[in]	position		The scroll position
	 * @endif
	 */
	void SetScrollPosition(int position);

	/**
	 * Sets the scroll position.
	 *
	 * @since 2.0
	 *
	 * @param[in]	position		The scroll position in pixel
	 * @param[in]	withAnimation		@c true to scroll the %ScrollPanel smoothly. @n
	 * 													else @c false.
	 *
	 */
	void SetScrollPosition(int position, bool withAnimation);

	/**
	 * Scrolls to the bottom of %ScrollPanel.
	 *
	 * @since		2.0
	 */
	void ScrollToBottom(void) const;


	/**
	 * Scrolls to the top of %ScrollPanel.
	 *
	 * @since		2.0
	 */
	void ScrollToTop(void) const;


	/**
	 * Closes the overlay Window for supporting the overlay keypad.
	 *
	 * @since		2.0
	 *
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result CloseOverlayWindow(void);


	/**
	 * Gets the bounds of the client area.
	 *
	 * @since		2.0
	 *
	 * @return		The bounds of the client area
	 *
	 */
	Tizen::Graphics::Rectangle GetClientAreaBounds(void) const;


	/**
	 * Sets the width of the client area.
	 *
	 * @since 2.0
	 *
	 * @return                   An error code
	 * @param[in]     width                        The width of the client area to set
	 * @exception     E_SUCCESS                   The method is successful.
	 * @exception     E_INVALID_ARG             @c width is less than the width of %ScrollPanel
	 * @exception     E_INVALID_OPERATION    The width of the client area cannot be set when auto resizing of the client area is off, or the scroll direction is vertical.
	 *
	 */
	result SetClientAreaWidth(int width);


	/**
	 * Sets the height of the client area.
	 *
	 * @since 2.0
	 *
	 * @return                   An error code
	 * @param[in]     height                        The height of the client area to set
	 * @exception     E_SUCCESS                   The method is successful.
	 * @exception     E_INVALID_ARG             @c height is less than the height of %ScrollPanel
	 * @exception     E_INVALID_OPERATION    The height of the client area cannot be set when auto resizing of the client area is off, or the scroll direction is horizontal.
	 *
	 */
	result SetClientAreaHeight(int height);


	/**
	 * Gets the scroll direction of the %ScrollPanel.
	 *
	 * @since 2.0
	 *
	 * @return        Direction of %ScrollPanel
	 *
	 */
	ScrollPanelScrollDirection GetScrollDirection(void) const;


	/**
	 * Gets how the scroll area the %ScrollPanel is resized.
	 *
	 * @since 2.0
	 *
	 * @return        Whether to resize the client area automatically
	 *
	 */
	bool IsScrollAreaAutoResizingEnabled(void) const;


	/**
	 * Enables or disables scrolling by page, where page size is determined by the size of the %ScrollPanel.
	 *
	 * @since 2.0
	 *
	 * @param[in]     enable		Set to @c true to enable page scroll.
	 *
	 */
	void SetPageScrollEnabled(bool enable);


	/**
	 * Checks whether scrolling by page feature is enabled.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the page scroll is enabled. @n
	 * 						else @c false.
	 *
	 */
	bool IsPageScrollEnabled(void) const;


	/**
	 * Sets the visibility of scroll bar.
	 *
	 * @since 2.0
	 *
	 * @param[in]	visible		Set to @c true to show scroll bar. @n
	 *										else @c false.
	 *
	 */
	void SetScrollBarVisible(bool visible);


	/**
	 * Gets the visibility of scroll bar.
	 *
	 * @since 2.0
	 *
	 */
	bool IsScrollBarVisible(void) const;


	/**
	 * Sets the scroll input handling mode.
	 *
	 * @since 2.0
	 *
	 * @param[in] mode  The scroll input handling mode
	 *  @see         GetScrollInputMode()
	 */
	void SetScrollInputMode(ScrollInputMode mode);


	/**
	 * Gets the scroll input handling mode.
	 *
	 * @since 2.0
	 *
	 * @return     The scroll input handling mode
	 * @see         SetScrollInputMode()
	 */
	ScrollInputMode GetScrollInputMode(void) const;


protected:

	friend class _ScrollPanelImpl;

	// Reserved virtual methods for later extension

	// The following methods are reserved and may change its name at any time without prior notice.
	virtual void ScrollPanel_Reserved1(void) {}

	virtual void ScrollPanel_Reserved2(void) {}

	virtual void ScrollPanel_Reserved3(void) {}

private:
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	ScrollPanel(const ScrollPanel& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	ScrollPanel& operator =(const ScrollPanel& rhs);

}; // ScrollPanel

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_SCROLL_PANEL_H_
