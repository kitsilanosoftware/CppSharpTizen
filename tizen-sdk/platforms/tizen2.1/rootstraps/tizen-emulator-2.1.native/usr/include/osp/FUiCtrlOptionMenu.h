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
 * @file	FUiCtrlOptionMenu.h
 * @brief	This is the header file for the %OptionMenu class.
 *
 * This header file contains the declarations of the %OptionMenu class and its helper classes.
 */

#ifndef _FUI_CTRL_OPTION_MENU_H_
#define _FUI_CTRL_OPTION_MENU_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FUiWindow.h>
#include <FUiIActionEventListener.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @if OSPDEPREC
 * @class	OptionMenu
 * @brief 	<i> [Deprecated] </i> This class defines a common behavior for an %OptionMenu control.
 *
 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
 * @since		2.0
 *
 * The %OptionMenu class defines a common behavior for an %OptionMenu control.
 * An %OptionMenu is used to present users with multiple options. Hierarchical menu
 * of depth 2 can be constructed. Option menu consists of main items and sub-items.
 * Unlike ContextMenu, menus cannot display bitmaps.
 *
 * If an application wants to perform tasks when a menu item is selected, it must
 * implement IActionEventListener and register the listener by calling %OptionMenu's
 * AddActionEventListener() method. It will then receive action ID associated
 * with the menu item.
 * Note that %OptionMenu cannot be used in a Popup.
 *
 * Example:
 *
 * @image html ui_controls_optionmenu.png
 *
 * This is the simple UI application which uses an %OptionMenu control.
 *
 * @code
 // Sample code for OptionMenuSample.h
 #include <FUi.h>

class OptionMenuSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
{
public:
	bool Initialize(void) ;
	void ShowOptionMenu(void);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private:
	static const int ID_OPTIONKEY = 100;
	static const int ID_OPTIONMENU_ITEM1  = 101;
	static const int ID_OPTIONMENU_ITEM2 = 102;

	Tizen::Ui::Controls::OptionMenu* __pOptionMenu;
};
 * @endcode
 *
 * @code
// Sample code for OptionMenuSample.cpp
#include "OptionMenuSample.h"

using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
OptionMenuSample::Initialize()
{
	Construct(FORM_STYLE_OPTIONKEY|FORM_STYLE_NORMAL);
	return true;
}

result
OptionMenuSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of OptionMenu
	__pOptionMenu = new OptionMenu();
	__pOptionMenu->Construct();
	__pOptionMenu->AddItem("Item1",ID_OPTIONMENU_ITEM1);
	__pOptionMenu->AddItem("Item2",ID_OPTIONMENU_ITEM2);
	SetOptionkeyActionId(ID_OPTIONKEY);
	AddOptionkeyActionListener(*this);

	return r;
}

result
OptionMenuSample::OnTerminating(void)
{
	result r = E_SUCCESS;
	delete __pOptionMenu;
	return r;
}

void
OptionMenuSample::ShowOptionMenu(void)
{
	__pOptionMenu->SetShowState(true);
	__pOptionMenu->Show();
}

// IActionEventListener implementation
void
OptionMenuSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_OPTIONKEY:
		{
			ShowOptionMenu();
		}
		break;
	case ID_OPTIONMENU_ITEM1:
		{
			// ....
		}
		break;
	case ID_OPTIONMENU_ITEM2:
		{
			// ....
		}
		break;
	default:
		break;
	}
}
 * @endcode
 * @endif
 */
class _OSP_EXPORT_ OptionMenu
	: public Tizen::Ui::Window
{
public:
	/**
	 * @if OSPDEPREC
	 * The object is not fully constructed after this constructor is called.  @n
	 * For full construction, the OptionMenu::Construct() method must be called right after calling this constructor.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 * @endif
	 */
	OptionMenu(void);

	/**
	 * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 * @endif
	 */
	virtual ~OptionMenu(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %OptionMenu.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				This method has failed.
	 * @endif
	 */
	result Construct(void);

	/**
	 * @if OSPDEPREC
	 * Adds a listener instance to receive action events from this control. @n
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @endif
	 */
	void AddActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Removes the specified action event listener so that it no longer receives events from this control.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @param[in]	listener	The event listener to remove
	 * @endif
	 */
	void RemoveActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Appends new item to the end of %OptionMenu.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	text			The item to append
	 * @param[in]	actionId		The action ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		This method has failed.
	 * @remarks     %OptionMenu can have a maximum of @c 12 main items.
	 * @endif
	 */
	result AddItem(const Tizen::Base::String& text, int actionId);

	/**
	 * @if OSPDEPREC
	 * Inserts a specific item at the given index of %OptionMenu.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	mainIndex		The main index
	 * @param[in]	text			The item to set
	 * @param[in]	actionId		The item ID
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM		The method has failed.
	 * @remarks     %OptionMenu can have a maximum of @c 12 main items.
	 * @endif
	 */
	result InsertItemAt(int mainIndex, const Tizen::Base::String& text, int actionId);

	/**
	 * @if OSPDEPREC
	 * Sets a specific item at the given index of %OptionMenu.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	mainIndex		The main index
	 * @param[in]   text			The string of the item to set
	 * @param[in]	actionId		The item ID
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM	    The method has failed.
	 * @endif
	 */
	result SetItemAt(int mainIndex, const Tizen::Base::String& text, int actionId);

	/**
	 * @if OSPDEPREC
	 * Removes the item of the specified index from %OptionMenu.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	mainIndex		The main index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM		This method has failed.
	 * @endif
	 */
	result RemoveItemAt(int mainIndex);

	/**
	 * @if OSPDEPREC
	 * Gets the number of items registered for %OptionMenu.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		The number of items registered for %OptionMenu
	 * @endif
	 */
	int GetItemCount(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item with the specified action ID.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		The index of the item
	 * @param[in]   actionId	The action ID of the item
	 * @endif
	 */
	int GetItemIndexFromActionId(int actionId) const;

	/**
	 * @if OSPDEPREC
	 * Gets the action ID of the item at the specified index.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return			The action ID of the item
	 * @param[in]	mainIndex		The index of the item
	 * @endif
	 */
	int GetItemActionIdAt(int mainIndex) const;

	/**
	 * @if OSPDEPREC
	 * Appends new sub-item to the end of %OptionMenu.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	mainIndex		The index of the main item
	 * @param[in]	text			The string of item to append
	 * @param[in]	actionId		The item ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM		This method has failed.
	 * @remarks     %OptionMenu can have a maximum of @c 32 sub-items.
	 * @endif
	 */
	result AddSubItem(int mainIndex, const Tizen::Base::String& text, int actionId);

	/**
	 * @if OSPDEPREC
	 * Inserts a specific sub-item at the given index of %OptionMenu.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	mainIndex		The index of the main item
	 * @param[in]	subIndex		The index of the sub-item
	 * @param[in]   text			The string of the item to set
	 * @param[in]	actionId		The action ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM		This method has failed.
	 * @remarks     %OptionMenu can have a maximum of @c 32 sub-items.
	 * @endif
	 */
	result InsertSubItemAt(int mainIndex, int subIndex, const Tizen::Base::String& text, int actionId);

	/**
	 * @if OSPDEPREC
	 * Sets a specific sub-item at the given index of %OptionMenu.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	mainIndex		The index of the main item
	 * @param[in]	subIndex		The index of the sub-item
	 * @param[in]   text			The string of the item to set
	 * @param[in]	actionId		The action ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM		This method has failed.
	 * @endif
	 */
	result SetSubItemAt(int mainIndex, int subIndex, const Tizen::Base::String& text, int actionId);

	/**
	 * @if OSPDEPREC
	 * Removes the sub-item of the specified index from %OptionMenu.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	mainIndex		The index of the main item
	 * @param[in]	subIndex		The index of the sub-item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is less than @c 0 or greater than @c 12.
	 * @exception	E_SYSTEM		This method has failed.
	 * @endif
	 */
	result RemoveSubItemAt(int mainIndex, int subIndex);

	/**
	 * @if OSPDEPREC
	 * Gets the number of sub-items registered for %OptionMenu.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		The number of sub-items registered for %OptionMenu
	 * @param[in]	mainIndex		The index of the main item
	 * @endif
	 */
	int GetSubItemCount(int mainIndex) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the sub-item at the specified action ID.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		The index of the item
	 * @param[in]	actionId		The action ID of the item
	 * @endif
	 */
	int GetSubItemIndexFromActionId(int actionId) const;

	/**
	 * @if OSPDEPREC
	 * Gets the action ID of the sub-item at the specified index.
	 *
	 * @brief 	<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %OptionMenu control is no longer recommended.
	 * @since			2.0
	 *
	 * @return		The action ID of the item
	 * @param[in]	mainIndex		The index of the main item
	 * @param[in]	subIndex		The index of the sub-item
	 * @endif
	 */
	int GetSubItemActionIdAt(int mainIndex, int subIndex) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	OptionMenu(const OptionMenu&);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	OptionMenu& operator =(const OptionMenu&);

	friend class _OptionMenuImpl;
}; // OptionMenu

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_OPTION_MENU_H_
