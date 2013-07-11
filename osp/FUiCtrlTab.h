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
 * @file	FUiCtrlTab.h
 * @brief	This is the header file for the %Tab class.
 *
 * This header file contains the declarations of the %Tab class and its helper classes.
 */

#ifndef _FUI_CTRL_TAB_H_
#define _FUI_CTRL_TAB_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FGrpBitmap.h>
#include <FGrpRectangle.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiCtrlForm.h>
#include <FUiIActionEventListener.h>

namespace Tizen { namespace Ui
{
class IActionEventListener;
}}

namespace Tizen { namespace Ui { namespace Controls
{
class _PublicActionEvent;


/**
 * @if OSPDEPREC
 * @class	Tab
 * @brief	 <i> [Deprecated] </i> This class is an implementation of a %Tab control.
 *
 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
 * @since	2.0
 *
 * @remarks     Note that tabs are part of a Form control, not a Frame control. This means that each tab item cannot be a form. You can associate a Panel
 *				control or a ScrollPanel control to each tab item.
 *
 * The %Tab class is an implementation of a %Tab control.
 * %Tab control displays the user selection in the form of a horizontal list. Each
 * item of %Tab control consists of its text string and optional bitmap image.
 * Items can be added to an itemlist of the tab model with AddItem(). Items can
 * be inserted into an itemlist by InsertItemAt(), updated into an itemlist by SetItemAt(),
 * removed from an itemlist by RemoveItemAt(), etc. It is possible to customize the
 * background image of the tab shelf, and the image of the currently selected tab item.
 * A badge icon can also be used to give more information for each tab item.
 *
 * Example:
 *
 * @image html ui_controls_tab.png
 *
 *
 * This is the simple UI application that uses a %Tab control.
 *
 *
 * @code
//Sample code for TabSample.h

#include <FUi.h>

class TabSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
{
public:
	TabSample(void)
	: __pTab(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	// IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private:
	Tizen::Ui::Controls::Tab* __pTab;
};
 *	@endcode
 *
 *	@code
// Sample code for TabSample.cpp
#include "TabSample.h"

using namespace Tizen::Ui::Controls;

bool
TabSample::Initialize()
{
	Construct(FORM_STYLE_NORMAL|FORM_STYLE_TEXT_TAB);
	return true;
}

result
TabSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Gets an instance of Tab
	__pTab = GetTab();

	// Adds items to the tab
	__pTab->AddItem(L"First", 0);
	__pTab->AddItem(L"Second", 1);
	__pTab->AddActionEventListener(*this);

	return r;
}

// IActionEventListener implementation
void
TabSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case 0:
		{
			// ....
		}
		break;
	case 1:
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
class _OSP_EXPORT_ Tab
	: public Tizen::Ui::Control
{
public:
	/**
	 * @if OSPDEPREC
	 * Adds a listener instance.
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 * @endif
	 */
	void AddActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * @if OSPDEPREC
	 * Removes a listener instance.
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 * @endif
	 */
	void RemoveActionEventListener(Tizen::Ui::IActionEventListener& listener);

public:
	/**
	 * @if OSPDEPREC
	 * Adds an item consisting of the specified text string.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   text            The text string of the item
	 * @param[in]	actionId		The action ID for this item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM		A system error has occurred, or @n
	 *								the total number of items has exceed the %Tab control's maximum item count.
	 * @remarks		The @c actionId range is @c 0-999. @n
	 *				The maximum number of items for %Tab with text style is @c 9. @n
	 *				The maximum number of items for icon style %Tab is @c 8.
	 * @remarks     This method can only be used when the %Form control has the FORM_STYLE_TEXT_TAB style.
	 * @endif
	 */
	result AddItem(const Tizen::Base::String& text, int actionId);

	/**
	 * @if OSPDEPREC
	 * Adds an item consisting of the title icon and the specified text string.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	titleIcon	    The bitmap for the title icon
	 * @param[in]	text			The text string of the item
	 * @param[in]	actionId		The specified @c actionId for this item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred, or @n
	 *								the total number of items has exceed the %Tab control's maximum item count.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				The maximum number of items for %Tab with text style is @c 9. @n
	 *              The maximum number of items for icon style %Tab is @c 8. @n
	 *				This method can only be used when the %Form control has the FORM_STYLE_TEXT_TAB style.
	 * @remarks     If the size of bitmap is greater than the default size , the bitmap is scaled down.
	 * @endif
	 */
	result AddItem(const Tizen::Graphics::Bitmap& titleIcon, const Tizen::Base::String& text, int actionId);

	/**
	 * @if OSPDEPREC
	 * Adds the item that consists of the specified icon.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	icon	        The bitmap for the icon
	 * @param[in]	actionId		The specified @c actionId for this item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM		A system error has occurred, or @n
	 *								the total number of items has exceed the %Tab control's maximum item count.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				The maximum number of items for %Tab with text style is @c 9. @n
	 *				The maximum number of items for icon style %Tab is @c 8. @n
	 *              This method can only be used when the Form control has the FORM_STYLE_ICON_TAB style. @n
	 *				If the size of the bitmap is greater than the default size, the bitmap is scaled down.
	 * @endif
	 */
	result AddItem(const Tizen::Graphics::Bitmap& icon, int actionId);

	/**
	 * @if OSPDEPREC
	 * Inserts the item that consists of only a text string at the specified index.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index           The index of the item
	 * @param[in]	text            The text string of the item
	 * @param[in]	actionId        The specified @c actionId for this item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred, or @n
	 *								the total number of items has exceed the %Tab control's maximum item count.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				The maximum number of items for %Tab with text style is @c 9. @n
	 *				The maximum number of items for icon style %Tab is @c 8.
	 * @remarks     This method can only be used when the Form control has the FORM_STYLE_TEXT_TAB style.
	 * @endif
	 */
	result InsertItemAt(int index, const Tizen::Base::String& text, int actionId);

	/**
	 * @if OSPDEPREC
	 * Inserts the item that consists of the title icon and specified text string at the specified index.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index           The index of the item
	 * @param[in]	titleIcon	    The bitmap for the title icon
	 * @param[in]	text			The text string of the item
	 * @param[in]	actionId		The specified @c actionId for this item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred, or @n
	 *								the total number of items has exceed the %Tab control's maximum item count.
	 * @remarks	    The @c actionId range is @c 0-999.
	 * @remarks     The maximum number of items for %Tab with text style is @c 9. @n
	 *              The maximum number of items for icon style %Tab is @c 8. @n
	 *				This method can only be used when the %Form control has the FORM_STYLE_TEXT_TAB style. @n
	 *				If the size of bitmap is greater than the default size, the bitmap is scaled down.
	 * @endif
	 */
	result InsertItemAt(int index, const Tizen::Graphics::Bitmap& titleIcon, const Tizen::Base::String& text, int actionId);

	/**
	 * @if OSPDEPREC
	 * Inserts the item which consists of the title icon and specified text string at the specified index.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The index of the item
	 * @param[in]	icon	        The Bitmap for the Icon
	 * @param[in]	actionId		The specified @c actionId for this item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred, or @n
	 *								the total number of items has exceed the %Tab control's maximum item count.
	 * @remarks	    The @c actionId range is @c 0-999.
	 * @remarks		The maximum number of items for %Tab with text style is @c 9. @n
	 *				The maximum number of items for icon style %Tab is @c 8. @n
	 *				This method can only be used when the Form control has the FORM_STYLE_ICON_TAB style. @n
	 *				If the size of bitmap is greater than the default size, the bitmap is scaled down.
	 * @endif
	 */
	result InsertItemAt(int index, const Tizen::Graphics::Bitmap& icon, int actionId);

	/**
	 * @if OSPDEPREC
	 * Sets the item that consists of only a text string at the specified index.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The index of the item
	 * @param[in]	text			The text string of the item
	 * @param[in]	actionId		The specified @c actionId for this item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				This method can only be used when the Form control has the FORM_STYLE_TEXT_TAB style.
	 * @endif
	 */
	result SetItemAt(int index, const Tizen::Base::String& text, int actionId);

	/**
	 * @if OSPDEPREC
	 * Sets the item that consists of the title icon and the specified text string at the given index.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index           The index of the item
	 * @param[in]	titleIcon       The bitmap for the title icon
	 * @param[in]	text            The text string of the item
	 * @param[in]	actionId		The action ID for the item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				This method can only be used when the Form control has the FORM_STYLE_TEXT_TAB style. @n
	 *				If the size of bitmap is greater than the default size, the bitmap is scaled down.
	 * @endif
	 */
	result SetItemAt(int index, const Tizen::Graphics::Bitmap& titleIcon, const Tizen::Base::String& text, int actionId);

	/**
	 * @if OSPDEPREC
	 * Sets the item that consists of only a title icon at the specified index.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The index of the item
	 * @param[in]	icon	        The bitmap for the icon
	 * @param[in]	actionId		The action ID for the item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				This method can only be used when the Form control has the FORM_STYLE_ICON_TAB style. @n
	 *				If the size of bitmap is greater than the default size, the bitmap is scaled down.
	 * @endif
	 */
	result SetItemAt(int index, const Tizen::Graphics::Bitmap& icon, int actionId);

	/**
	 * @if OSPDEPREC
	 * Removes item at the given index from the tab.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index		    The index of the item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @endif
	 */
	result RemoveItemAt(int index);

	/**
	 * @if OSPDEPREC
	 * Removes all the items from the tab.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result RemoveAllItems(void);

	/**
	 * @if OSPDEPREC
	 * Sets the badge icon of the specified item.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	actionId		The specified @c actionId for this item
	 * @param[in]	pBadgeIcon	    The bitmap for the icon
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c actionId is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks	    The @c actionId range is @c 0-999. @n
	 *				If the size of bitmap is greater than the default size, the bitmap is scaled down.
	 * @endif
	 */
	result SetBadgeIcon(int actionId, const Tizen::Graphics::Bitmap* pBadgeIcon);

	/**
	 * @if OSPDEPREC
	 * Gets the number of items in the specified tab.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		The number of items in the tab
	 * @endif
	 */
	int GetItemCount(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the index of the item at the specified action ID.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		The index of the item, @n
	 *			    else @c -1 if an error occurs
	 * @param[in]	actionId		The action ID of the item
	 * @remarks		The @c actionId range is @c 0-999.
	 * @endif
	 */
	int GetItemIndexFromActionId(int actionId) const;

	/**
	 * @if OSPDEPREC
	 * Gets the action ID of the item at the specified index.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		The action ID of the item, @n
	 *              else @c -1 if @c index is less than @c 0 or greater than the item count of tab
	 * @param[in]	index		The index of the item
	 * @endif
	 */
	int GetItemActionIdAt(int index) const;

	/**
	 * @if OSPDEPREC
	 * Sets the selected item for the specified index.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @param[in]   index   The index of the item
	 * @endif
	 */
	void SetSelectedItem(int index);

	/**
	 * @if OSPDEPREC
	 * Gets the index of the selected item from the tab.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return      The index of the item, @n
	 *				else @c -1 if an error occurs
	 * @endif
	 */
	int GetSelectedItemIndex(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the edit-enabled mode.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @param[in]	enable	Set to @c true to enable edit mode, @n
	 *						else @c false
	 * @endif
	 */
	void SetEditModeEnabled(bool enable);

	/**
	 * @if OSPDEPREC
	 * Checks whether the edit mode is set.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		@c true if the edit mode is set, @n
	 *				else @c false
	 * @endif
	 */
	bool IsEditModeEnabled(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the background bitmap of the tab.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return	    An error code
	 * @param[in]	bitmap			The background bitmap
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The background bitmap is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result SetBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * @if OSPDEPREC
	 * Sets the background bitmap of the focused item.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	bitmap			The background bitmap of the focused item
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG	The background bitmap is invalid.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result SetFocusedItemBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * @if OSPDEPREC
	 * Sets the text color of the tab.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @param[in]	textColor		The color to be set
	 * @endif
	 */
	void SetTextColor(const Tizen::Graphics::Color& textColor);

	/**
	 * @if OSPDEPREC
	 * Gets the text color of the tab.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since			2.0
	 *
	 * @return			The text color
	 * @endif
	 */
	Tizen::Graphics::Color GetTextColor(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the text color for the selected item of the tab.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since			2.0
	 *
	 * @param[in]		textColor		The color to be set
	 * @endif
	 */
	void SetSelectedTextColor(const Tizen::Graphics::Color& textColor);

	/**
	 * @if OSPDEPREC
	 * Gets the text color for the selected item of the tab.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since			2.0
	 *
	 * @return			The text color
	 * @endif
	 */
	Tizen::Graphics::Color GetSelectedTextColor(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the color of the text when the %Tab item is highlighted.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since           2.0
	 *
	 * @return          The highlighted text color
	 * @remarks         When a user navigates the user interface using the directional keys, the focused UI control is highlighted.
	 * @endif
	 */
	Tizen::Graphics::Color GetHighlightedTextColor(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the color of the text when the tab item is highlighted.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since	2.0
	 *
	 * @param[in]	color	The color to be set
	 * @remarks	When a user navigates the user interface using the directional keys, the focused UI control is highlighted.
	 * @endif
	 */
	void SetHighlightedTextColor(const Tizen::Graphics::Color& color);

	/**
	 * @if OSPDEPREC
	 * Sets the background bitmap of the highlighted tab item.
	 *
	 * @brief	 <i> [Deprecated] </i>
	 * @deprecated  This class is deprecated because the use of the %Tab control is no longer recommended.
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]	bitmap            The background bitmap of the focused item
	 * @exception	E_SUCCESS         The method is successful.
	 * @exception	E_INVALID_ARG     The background bitmap is invalid.
	 * @exception	E_SYSTEM          A system error has occurred.
	 * @remarks		The background bitmap must use the 9-patched bitmap.
	 * @remarks		When a user navigates the user interface using the directional keys, the focused UI control is highlighted.
	 * @endif
	 */
	result SetHighlightedItemBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);


	//void SetStyle(int style);

private:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	// @since         2.0
	//
	Tab(void);

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	// @since         2.0
	//
	virtual ~Tab(void);

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Initializes this instance of %Tab with the specified parameter.
	//
	// @since         2.0
	// @return		An error code
	// @param[in]	tabHandle		The handle of the tab
	// @exception	E_SUCCESS       The method is successful.
	// @exception	E_SYSTEM		A system error has occurred.
	//
	result Construct(void);

	//
	// Stores __BitmapItem.
	//
	Tizen::Base::Collection::ArrayList __items;

private:
	friend class _TabImpl;

};

}}} //Tizen::Ui::Controls

#endif // _FUI_CTRL_TAB_H_
