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
 * @file	FUiCtrlContextMenu.h
 * @brief	This is the header file for the %ContextMenu class.
 *
 * This header file contains the declarations of the %ContextMenu class and its helper classes.
 */

#ifndef _FUI_CTRL_CONTEXT_MENU_H_
#define _FUI_CTRL_CONTEXT_MENU_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FGrpBitmap.h>
#include <FGrpRectangle.h>
#include <FUiWindow.h>
#include <FUiContainer.h>
#include <FUiIActionEventListener.h>

namespace Tizen { namespace Graphics
{
class Bitmap;
};
};

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum ContextMenuStyle
 *
 * Defines the %ContextMenu style.
 *
 * @since	2.0
 */
enum ContextMenuStyle
{
	CONTEXT_MENU_STYLE_LIST,/**< The style of the vertical list of image + text */
	CONTEXT_MENU_STYLE_GRID,/**< The style of the grid of buttons */
	CONTEXT_MENU_STYLE_ICON /**<@if OSPDEPREC @deprecated This enumeration field is deprecated because this style can be implemented using the CONTEXT_MENU_STYLE_GRID style @endif */
} ;

/**
 * @enum ContextMenuItemStatus
 *
 * Defines the possible states of the %ContextMenu control item.
 *
 * @since 2.0
 */
enum ContextMenuItemStatus
{
	CONTEXT_MENU_ITEM_STATUS_NORMAL,		/**< The normal state */
	CONTEXT_MENU_ITEM_STATUS_PRESSED,		/**< The pressed state  */
	CONTEXT_MENU_ITEM_STATUS_HIGHLIGHTED	/**< The highlighted state */
};

/**
 * @enum ContextMenuAnchorDirection
 *
 * Defines the direction of the %ContextMenu control.
 *
 * @since 2.0
 */
enum ContextMenuAnchorDirection
{
	CONTEXT_MENU_ANCHOR_DIRECTION_LEFTWARD,	/**< The anchor arrow direction is leftward */
	CONTEXT_MENU_ANCHOR_DIRECTION_RIGHTWARD,/**< The anchor arrow direction is rightward */
	CONTEXT_MENU_ANCHOR_DIRECTION_UPWARD,	/**< The anchor arrow direction is upward */
	CONTEXT_MENU_ANCHOR_DIRECTION_DOWNWARD,	/**< The anchor arrow direction is downward */
	CONTEXT_MENU_ANCHOR_DIRECTION_AUTO		/**< The anchor arrow direction is auto */
};

/**
 * @class	ContextMenu
 * @brief This class defines the common behavior of a %ContextMenu control.
 *
 * @since	2.0
 *
 * The %ContextMenu class displays a special purpose window that is used to present users with context-sensitive options.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_contextmenus.htm">ContextMenu</a>.
 *
 * The following example demonstrates how to use the %ContextMenu class.

 *
 * @code
// Sample code for ContextMenuSample.h
#include <FUi.h>
class ContextMenuSample
	: public Tizen::Ui::Controls::Form
    , public Tizen::Ui::IActionEventListener
{
public:
	ContextMenuSample(void)
	:__pContextMenu(null){}

	bool Initialize(void);
	void ShowContextMenu(bool show);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private:
	static const int ID_CONTEXTMENU_ITEM1 = 101;
	static const int ID_CONTEXTMENU_ITEM2 = 102;
	static const int ID_BTN_SHOW_CONTEXTMENU = 103;

	Tizen::Ui::Controls::ContextMenu *__pContextMenu;
};

 *	@endcode
 *
 *	@code

// Sample code for ContextMenuSample.cpp
#include <FGraphics.h>

#include "ContextMenuSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
ContextMenuSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
ContextMenuSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of ContextMenu
	__pContextMenu = new ContextMenu();
	__pContextMenu->Construct(Point(400, 150), CONTEXT_MENU_STYLE_LIST);

	__pContextMenu->AddItem(L"Item1", ID_CONTEXTMENU_ITEM1);
	__pContextMenu->AddItem(L"Item2", ID_CONTEXTMENU_ITEM2);
	__pContextMenu->AddActionEventListener(*this);

	// Creates an instance of Button to show the context menu
	Button* pButton = new Button();
	pButton->Construct(Rectangle(50, 50, 400, 100), L"Show ContextMenu");
	pButton->SetActionId(ID_BTN_SHOW_CONTEXTMENU);
	pButton->AddActionEventListener(*this);

	// Adds the button to the form
	AddControl(*pButton);

	return r;
}

// Sets the anchor position of the context menu
void
ContextMenuSample::ShowContextMenu(bool show)
{
	__pContextMenu->SetPosition(Point(300, 200));

	// Change to desired show state
	__pContextMenu->SetShowState(show);

	//Calls Show() of the control
	if (show)
	{
		__pContextMenu->Show();
	}
	else
	{
		Invalidate(true);
	}
}

result
ContextMenuSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates the __pContextMenu
	delete __pContextMenu;

	return r;
}

// IActionEventListener implementation
void
ContextMenuSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_CONTEXTMENU_ITEM1:
		{
			// ....
		}
		break;
	case ID_CONTEXTMENU_ITEM2:
		{
			// ....
		}
		break;
	case ID_BTN_SHOW_CONTEXTMENU:
		{
			ShowContextMenu(true);
		}
		break;
	default:
		break;
	}
}
 * @endcode
 *
 */
class _OSP_EXPORT_ ContextMenu
	: public Tizen::Ui::Window
{
public:
// Lifecycle
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 *
	 */
	ContextMenu(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 *
	 */
	virtual ~ContextMenu(void);

	/**
	 * Initializes this instance of %ContextMenu with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point	        The x and y coordinates of the anchor of %ContextMenu
	 * @param[in]	style			The context menu style
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::Point& point, ContextMenuStyle style);

	/**
	 * Initializes this instance of %ContextMenu with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point			The x and y coordinates of the anchor of the %ContextMenu control
	 * @param[in]	style			The context menu style
	 * @param[in]	direction		The anchor arrow direction
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::Point& point, ContextMenuStyle style, ContextMenuAnchorDirection direction);

	/**
	 * Adds a listener instance.
	 * The added listener can listen to events on the given context of the event dispatcher when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 */
	void AddActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * Removes the specified listener instance.
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 */
	void RemoveActionEventListener(Tizen::Ui::IActionEventListener& listener);


// Operation
	/**
	 * Appends the specified item at the end of the %ContextMenu control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in] 	normalBitmap		The normal bitmap of the item
	 * @param[in] 	pPressedBitmap		The pressed bitmap of the item
	 * @param[in]	actionId		    The action ID for this item
	 * @exception	E_SUCCESS 		    The method is successful.
	 * @exception	E_MAX_EXCEEDED	    The number of items has exceeded the maximum limit.
	 * @exception	E_SYSTEM		    A system error has occurred.
	 * @remarks		This method can only be used when the style of the context menu is CONTEXT_MENU_STYLE_GRID.
	 */
	result AddItem(const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pPressedBitmap, int actionId);

    /**
     * Appends the specified item at the end of the %ContextMenu control.
     *
     * @since 		2.0
	 *
     * @return      An error code
     * @param[in]   normalBitmap        The normal bitmap of the item
     * @param[in]   pPressedBitmap      The pressed bitmap of the item
     * @param[in]   pHighlightedBitmap  The highlighted bitmap of the item
     * @param[in]   actionId            The action ID for this item
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_MAX_EXCEEDED      The number of items has exceeded the maximum limit.
     * @exception   E_SYSTEM            A system error has occurred.
     * @remarks     This method can only be used when the style of the context menu is CONTEXT_MENU_STYLE_GRID. @n
     *				When a user navigates the user interface using the directional keys, the selected UI control is highlighted and the control takes the
	 *				focus.
     */
	result AddItem(const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pPressedBitmap, const Tizen::Graphics::Bitmap* pHighlightedBitmap, int actionId);

	/**
	 * Appends the specified item at the end of the %ContextMenu control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in] 	text			The string of the item to be appended
	 * @param[in]	actionId		The specified action ID for this item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_MAX_EXCEEDED	The number of items has exceeded the maximum limit.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result AddItem(const Tizen::Base::String& text, int actionId);

	/**
	 * Appends the specified item at the end of the %ContextMenu control.
	 *
	 * @since 		2.0
	 *
	 * @return		An error code
	 * @param[in] 	text				The string of the item to be appended
	 * @param[in]	actionId			The specified action ID for this item
	 * @param[in] 	normalBitmap        The normal bitmap of the item
     * @param[in] 	pPressedBitmap      The pressed bitmap of the item
     * @param[in] 	pHighlightedBitmap  The highlighted bitmap of the item
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_MAX_EXCEEDED		The total number of items has exceeded the maximum limit.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		This method can only be used when the style of the context menu is CONTEXT_MENU_STYLE_LIST.
	 */
	result AddItem(const Tizen::Base::String& text, int actionId, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pPressedBitmap = null, const Tizen::Graphics::Bitmap* pHighlightedBitmap = null);

	/**
	 * Inserts the specified item at the given index of the %ContextMenu control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in] 	index			The location
	 * @param[in] 	normalBitmap	The normal bitmap of the item
	 * @param[in] 	pPressedBitmap	The pressed bitmap of the item
	 * @param[in]	actionId		The specified action ID for this item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_MAX_EXCEEDED	The number of items has exceeded the maximum limit.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than the number of items in %ContextMenu.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method can only be used when the style of the context menu is CONTEXT_MENU_STYLE_GRID. @n
	 * 				The %ContextMenu control can have a maximum of 3 icons.
	 */
	result InsertItemAt(int index, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pPressedBitmap, int actionId);

    /**
     * Inserts the specified item at the given index of the %ContextMenu control.
     *
     * @since 		2.0
	 *
     * @return		An error code
     * @param[in]	index                      The location
     * @param[in]	normalBitmap               The normal bitmap of the item
     * @param[in]	pPressedBitmap             The pressed bitmap of the item
     * @param[in]	pHighlightedBitmap         The highlighted bitmap of the item
     * @param[in]	actionId                   The specified action ID for this item
     * @exception	E_SUCCESS                  The method is successful.
     * @exception	E_MAX_EXCEEDED             The number of items has exceeded the maximum limit.
     * @exception	E_OUT_OF_RANGE             The specified @c index is less than @c 0 or greater than the number of items in %ContextMenu.
     * @exception	E_SYSTEM                   A system error has occurred.
     * @remarks		This method can only be used when the style of the context menu is CONTEXT_MENU_STYLE_GRID. @n
     * @remarks		When a user navigates the user interface using the directional keys, the selected UI control is highlighted and the control takes the focus.
	 */
	result InsertItemAt(int index, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pPressedBitmap, const Tizen::Graphics::Bitmap* pHighlightedBitmap, int actionId);

	/**
	 * Inserts the specified item at the given index of the %ContextMenu control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   index			The location
	 * @param[in]   text			The string of the item to set
	 * @param[in]	actionId		The specified action ID for this item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_MAX_EXCEEDED	The number of items has exceeded the maximum limit.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than the number of items in %ContextMenu.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result InsertItemAt(int index, const Tizen::Base::String& text, int actionId);

	/**
	 * Inserts the specified item at the given index of the %ContextMenu control.
	 *
	 * @since 		2.0
	 *
	 * @return		An error code
	 * @param[in] 	index				The location
	 * @param[in] 	text				The string of the item to set
	 * @param[in]	actionId			The specified action ID for this item
	 * @param[in] 	normalBitmap        The normal bitmap of the item
     * @param[in] 	pPressedBitmap      The pressed bitmap of the item
     * @param[in] 	pHighlightedBitmap  The highlighted bitmap of the item
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_MAX_EXCEEDED		The number of items has exceeded the maximum limit.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is less than @c 0 or greater than the number of items in %ContextMenu.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		This method can only be used when the style of the context menu is CONTEXT_MENU_STYLE_LIST.
	 */
	result InsertItemAt(int index, const Tizen::Base::String& text, int actionId, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pPressedBitmap = null, const Tizen::Graphics::Bitmap* pHighlightedBitmap = null);

	/**
	 * Sets the specified item at the given index of the %ContextMenu control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in] 	index				The location
	 * @param[in] 	normalBitmap		The normal bitmap of the item
	 * @param[in] 	pPressedBitmap		The pressed bitmap of the item
	 * @param[in]	actionId		    The action ID for this item
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_OUT_OF_RANGE	    The specified @c index is less than @c 0 or greater than the number of items in %ContextMenu.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     This method can only be used when the style of the context menu is CONTEXT_MENU_STYLE_GRID.
	 */
	result SetItemAt(int index, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pPressedBitmap, int actionId);

	/**
	 * Sets the specified item at the given index of the %ContextMenu control.
	 *
	 * @since           2.0
	 *
	 * @return        An error code
     * @param[in]     index                      The location
     * @param[in]     normalBitmap               The normal bitmap of the item
     * @param[in]     pPressedBitmap             The pressed bitmap of the item
     * @param[in]     pHighlightedBitmap         The highlighted bitmap of the item
     * @param[in]     actionId                   The action ID for this item
     * @exception     E_SUCCESS                  The method is successful.
     * @exception     E_OUT_OF_RANGE             The specified @c index is less than @c 0 or greater than the number of items in %ContextMenu.
     * @exception     E_SYSTEM                   A system error has occurred.
     * @remarks       This method can only be used when the style of the context menu is CONTEXT_MENU_STYLE_GRID. @n
     * @remarks       When a user navigates the user interface using the directional keys, @n
     *                the selected UI control is highlighted and the control takes the focus.
	 */
	result SetItemAt(int index, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pPressedBitmap, const Tizen::Graphics::Bitmap* pHighlightedBitmap, int actionId);

	/**
	 * Sets the specified item at the given index of the %ContextMenu control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in] 	index			The location
	 * @param[in] 	text			The string of the item to set
	 * @param[in]	actionId		The action ID for this item
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index less than @c 0 or greater than the number of items in %ContextMenu.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetItemAt(int index, const Tizen::Base::String& text, int actionId);

	/**
	 * Sets the specified item at the given index of the %ContextMenu control.
	 *
	 * @since 		2.0
	 *
	 * @return		An error code
	 * @param[in] 	index				The location
	 * @param[in] 	text				The string of the item to set
	 * @param[in]	actionId			The action ID for this item
	 * @param[in] 	normalBitmap        The normal bitmap of the item
	 * @param[in] 	pPressedBitmap      The pressed bitmap of the item
	 * @param[in] 	pHighlightedBitmap  The highlighted bitmap of the item
	 * @exception	E_SUCCESS 			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index less than @c 0 or greater than the number of items in %ContextMenu.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks    	This method can only be used when the style of the context menu is CONTEXT_MENU_STYLE_LIST.
	 */
	result SetItemAt(int index, const Tizen::Base::String& text, int actionId, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pPressedBitmap = null, const Tizen::Graphics::Bitmap* pHighlightedBitmap = null);

	/**
	 * Removes the item at the specified index from the %ContextMenu control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in] 	index			The location
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result RemoveItemAt(int index);

	/**
	 * Removes all items from the %ContextMenu control.
	 *
	 * @since		2.0
	 *
	 * @exception	E_SUCCESS 		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result RemoveAllItems(void);

	/**
	 * Gets the number of items of the %ContextMenu control.
	 *
	 * @since	2.0
	 *
	 * @return	The number of items registered for %ContextMenu, @n
	 * 			else @c -1 if an error occurs
	 */
	int GetItemCount(void) const;

	/**
	 * Gets the index of the item with the specified action ID.
	 *
	 * @since		2.0
	 *
	 * @return		The index of the item, @n
	 * 				else @c -1 if an error occurs
	 * @param[in] 	actionId	The action ID
	 */
	int GetItemIndexFromActionId(int actionId) const;

	/**
	 * Gets the action ID of the item at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return		The action ID of the item, @n
	 * 				else @c -1 if the specified index is invalid
	 * @param[in]   index		The index of the item
	 */
	int GetItemActionIdAt(int index) const;

	/**
	 * Gets the item text color of the %ContextMenu control for the specified status.
	 *
	 * @since 		2.0
	 *
	 * @return      The item text color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]   status		The item status
	 */
	Tizen::Graphics::Color GetItemTextColor(ContextMenuItemStatus status) const;

	/**
	 * Sets the item text color of the %ContextMenu control for the specified status.
	 *
	 * @since 		2.0
	 *
	 * @return      An error code
	 * @param[in]   status				The item status
	 * @param[in]   color				The item text color to be set
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception   E_SYSTEM			A system error has occurred.
	 */
	result SetItemTextColor(ContextMenuItemStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Sets the position of the anchor.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	position			The new position
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		The x and y coordinates of the anchor are defined in the coordinate space of its parent,
	 *				which means that @c x and @c y must be defined relative to the top-left corner (0,0) of its parent.
	 */
	result SetAnchorPosition(const Tizen::Graphics::Point& position);

	/**
	 * Gets the position of the anchor.
	 *
	 * @since		2.0
	 *
	 * @return		The position of the anchor
	 * @remarks		The coordinate of the anchor position is defined from the top-left corner of its parent Container.
	 */
	Tizen::Graphics::Point GetAnchorPosition(void) const;

	/**
	 * Gets the color of the %ContextMenu control.
	 *
	 * @since		2.0
	 *
	 * @return		The color of %ContextMenu control, @n
	 * 				else RGBA(0, 0, 0, 0) if an error occurs
	 * @see			SetColor()
	 */
	Tizen::Graphics::Color GetColor(void) const;

	/**
	 * Sets the color of the %ContextMenu control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	color				The color to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetColor()
	 */
	result SetColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the item color for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		The color of %ContextMenu control, @n
	 *  			else RGBA(0, 0, 0, 0) if an error occurs
	 * @param[in]	status				The menu item status
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid. @n
	 * 									The item color for CONTEXT_MENU_ITEM_STATUS_NORMAL is not supported.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 * 				The item color for the CONTEXT_MENU_ITEM_STATUS_NORMAL status is always the same as the color of the %ContextMenu control.
	 * @see			SetItemColor()
	 */
	Tizen::Graphics::Color GetItemColor(ContextMenuItemStatus status) const;

	/**
	 * Sets the item color for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	status				The menu item status
	 * @param[in]	color				The color to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid. @n
	 * 									The item color for CONTEXT_MENU_ITEM_STATUS_NORMAL is not supported.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The item color for the CONTEXT_MENU_ITEM_STATUS_NORMAL status is always the same as the color of the %ContextMenu control.
	 * @see			GetItemColor()
	 */
	result SetItemColor(ContextMenuItemStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Gets maximum number of visible items.
	 *
	 * @since		2.0
	 *
	 * @return		The maximum number of visible items, @n
	 * 				else @c -1 if an error occurs
	 * @see			SetMaxVisibleItemsCount()
	 */
	int GetMaxVisibleItemsCount(void) const;

	/**
	 * Sets maximum number of visible items.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	maxItemsCount		The maximum number of the visible menu items
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c parameter is out of possible range.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		@c maxItemsCount should be greater than @c 0 and less than @c 8. The default value for
	 * 				the maximum number of the visible menu items is @c 4.
	 * @see			GetMaxVisibleItemsCount()
	 */
	result SetMaxVisibleItemsCount(int maxItemsCount);

protected:
	friend class _ContextMenuImpl;
private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.0
	//
	//
	ContextMenu(const ContextMenu& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.0
	//
	//
	ContextMenu& operator =(const ContextMenu& rhs);
}; // ContextMenu

}}} // Tizen::Ui: Control

#endif // _FUI_CTRL_CONTEXT_MENU_H_
