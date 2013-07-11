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
 * @file	FUiCtrlSearchBar.h
 * @brief	This is the header file for the %SearchBar class.
 *
 * This header file contains the declarations of the %SearchBar class.
 */

#ifndef _FUI_CTRL_SEARCH_BAR_H_
#define _FUI_CTRL_SEARCH_BAR_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FUiControl.h>
#include <FUiCtrlEditTypes.h>
#include <FUiIActionEventListener.h>
#include <FUiIKeypadEventListener.h>
#include <FUiILanguageEventListener.h>
#include <FUiITextBlockEventListener.h>
#include <FUiITextEventListener.h>

namespace Tizen { namespace Graphics
{
class Rectangle;
}} // Tizen::Graphics

namespace Tizen { namespace Ui { namespace Controls
{

class ISearchBarEventListener;

/**
 * @enum    SearchFieldStatus
 *
 * Defines the possible states of the search field of the search bar.
 *
 * @since	2.0
 */
enum SearchFieldStatus
{
	SEARCH_FIELD_STATUS_NORMAL,         /**< The normal state */
	SEARCH_FIELD_STATUS_HIGHLIGHTED,    /**< The focus-highlighted state */
	SEARCH_FIELD_STATUS_DISABLED        /**< The disabled state */
};

/**
 * @enum    SearchBarButtonStatus
 *
 * Defines the possible states of the search bar button.
 *
 * @since	2.0
 */
enum SearchBarButtonStatus
{
	SEARCH_BAR_BUTTON_STATUS_NORMAL = 0,        /**< The normal status */
	SEARCH_BAR_BUTTON_STATUS_PRESSED,           /**< The selected status */
	SEARCH_BAR_BUTTON_STATUS_HIGHLIGHTED,       /**< The highlighted status */
	SEARCH_BAR_BUTTON_STATUS_DISABLED           /**< The disabled status */
};

/**
 * @enum	SearchBarMode
 *
 * Defines the possible modes of the search bar.
 *
 * @since	2.0
 */
enum SearchBarMode
{
	SEARCH_BAR_MODE_NORMAL,     /**< The normal mode */
	SEARCH_BAR_MODE_INPUT       /**< The input mode */
};

/**
 * @class	SearchBar
 * @brief	This class is an implementation of a search bar.
 *
 * @since	2.0
 *
 * The %SearchBar class displays an editable search field for entering keywords and an optional button that is displayed in the
 * input mode.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_searchbar.htm">SearchBar</a>.
 *
 * The following example demonstrates how to use the %SearchBar class.
 *
 * @code
// Sample code for SearchBarSample.h
#include <FUi.h>

class SearchBarSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::ISearchBarEventListener
	, public Tizen::Ui::Controls::IListViewItemEventListener
	, public Tizen::Ui::Controls::IListViewItemProvider
	, public Tizen::Ui::ITextEventListener
{
public:
	SearchBarSample(void)
	: __pSearchBar(null)
	, __pSearchBarListView(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	// ISearchBarEventListener
	virtual void OnSearchBarModeChanged(Tizen::Ui::Controls::SearchBar& source, Tizen::Ui::Controls::SearchBarMode mode);
	virtual void OnSearchBarContentAreaResized(Tizen::Ui::Controls::SearchBar& source, Tizen::Graphics::Dimension& size) {};
	virtual void OnTextValueChanged(const Tizen::Ui::Control& source);
	virtual void OnTextValueChangeCanceled(const Tizen::Ui::Control& source){};

	// IListViewItemEventListener
	virtual void OnListViewContextItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state);
	virtual void OnListViewItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status);
	virtual void OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction);

	//IListViewItemProvider
	virtual Tizen::Ui::Controls::ListItemBase* CreateItem (int index, int itemWidth);
	virtual bool DeleteItem (int index, Tizen::Ui::Controls::ListItemBase *pItem, int itemWidth);
	virtual int GetItemCount(void);

private:
	static const int ID_FORMAT_STRING = 500;

	Tizen::Ui::Controls::SearchBar*	__pSearchBar;
	Tizen::Ui::Controls::ListView*	__pSearchBarListView;
};
 * @endcode
 *
 * @code
// Sample code for SearchBarSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "SearchBarSample.h"

using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
SearchBarSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
SearchBarSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of SearchBar
	__pSearchBar = new SearchBar();
	__pSearchBar->Construct(Rectangle(0, 0, GetClientAreaBounds().width, 110));
	__pSearchBar->SetText(L"Click here! ");
	__pSearchBar->AddSearchBarEventListener(*this);
	__pSearchBar->AddTextEventListener(*this);

	// Creates an instance of ListView
	__pSearchBarListView = new ListView();
	__pSearchBarListView->Construct(Rectangle(0, 110, GetClientAreaBounds().width, GetClientAreaBounds().height - 110), true, false);
	__pSearchBarListView->SetItemProvider(*this);
	__pSearchBarListView->AddListViewItemEventListener(*this);
	__pSearchBarListView->SetTextOfEmptyList(L"No search result");
	__pSearchBarListView->SetShowState(false);
	__pSearchBar->SetContent(__pSearchBarListView);

	// Adds controls to the form
	AddControl(*__pSearchBar);

	return r;
}

// ISearchBarEventListener implementation
void
SearchBarSample::OnSearchBarModeChanged(Tizen::Ui::Controls::SearchBar& source, Tizen::Ui::Controls::SearchBarMode mode)
{
	Rectangle clientRect = GetClientAreaBounds();
	__pSearchBar->SetText(L"");

	if(mode == SEARCH_BAR_MODE_INPUT)
	{
		SetActionBarsVisible(FORM_ACTION_BAR_FOOTER, false);
		__pSearchBar->SetContentAreaSize(Dimension(clientRect.width, clientRect.height));
		__pSearchBarListView->SetSize(Dimension(clientRect.width, clientRect.height));
		__pSearchBarListView->UpdateList();
	}
	else
	{
		SetActionBarsVisible(FORM_ACTION_BAR_FOOTER, true);
		__pSearchBarListView->UpdateList();
		__pSearchBarListView->SetShowState(false);
		__pSearchBar->SetText(L"Click here!");
	}
	Invalidate(true);
}

void
SearchBarSample::OnTextValueChanged(const Tizen::Ui::Control& source)
{
	if(__pSearchBarListView)
	{
		__pSearchBarListView->UpdateList();
		__pSearchBarListView->ScrollToItem(0);
		__pSearchBarListView->SetShowState(true);
	}
	Invalidate(true);
}

// IListViewItemEventListener implementation
 void
 SearchBarSample::OnListViewContextItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state)
 {
 	// ....
 }

 void
 SearchBarSample::OnListViewItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status)
 {
 	// ....
 }

 void
 SearchBarSample::OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction)
 {
 	// ....
 }

//IListViewItemProvider
ListItemBase*
SearchBarSample::CreateItem (int index, int itemWidth)
{
	// Creates an instance of CustomItem
	CustomItem* pItem = new CustomItem();
	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;

	// Gets texts of the search bar
	String inputText = null;
	inputText = __pSearchBar->GetText();

	if(inputText.CompareTo(L"a") == 0 || inputText.CompareTo(L"A") == 0 )
	{
		switch (index % 3)
		{
		case 0:
			{
				pItem->Construct(Dimension(itemWidth,100), style);
				pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"ajo", true);
			}
			break;
		case 1:
			{
				pItem->Construct(Dimension(itemWidth,100), style);
				pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"aeun", true);
			}
			break;
		case 2:
			{
				pItem->Construct(Dimension(itemWidth,100), style);
				pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"abee", true);
			}
			break;
		default:
			break;
		}
	}
	else if (inputText.CompareTo(L"b") == 0 || inputText.CompareTo(L"B") == 0)
	{
		switch (index%3)
		{
		case 0:
			{
				pItem->Construct(Dimension(itemWidth,100), style);
				pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"bonge", true);
			}
			break;
		case 1:
			{
				pItem->Construct(Dimension(itemWidth,100), style);
				pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"bnpyo", true);
			}
			break;
		case 2:
			{
				pItem->Construct(Dimension(itemWidth,100), style);
				pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"bkueon", true);
			}
			break;
		default:
			break;
		}
	}
	else
	{
		pItem->Construct(Dimension(itemWidth,100), style);
		pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"default", true);
	}

	return pItem;
}

bool
SearchBarSample::DeleteItem (int index, Tizen::Ui::Controls::ListItemBase *pItem, int itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}

int
SearchBarSample::GetItemCount(void)
{
	return 3;
}
 * @endcode
 *
 */

class _OSP_EXPORT_ SearchBar
	: public Tizen::Ui::Control
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	SearchBar(void);

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~SearchBar(void);

	/**
	 * Initializes this instance of the %SearchBar control with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			An instance of the Graphics::Rectangle class @n
	 *								This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *								the width and height of the control.
	 * @param[in]	searchBarButton	Set to @c true to display the search bar button, @n
	 *                              else @c false
	 * @param[in]	keypadAction	The keypad action
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG	A specified input parameter is invalid, or @n
	 *								the action ID of the specified item must be a positive integer.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     It is recommended that %SearchBar should be placed at the top-left corner of Form's client area.
	 * @remarks     By default, a "Cancel" button is displayed if @c searchBarButton is set to @c true. When the user presses the cancel button,
	 *              the %SearchBar control returns to SEARCH_BAR_MODE_NORMAL automatically.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, bool searchBarButton = true, KeypadAction keypadAction = KEYPAD_ACTION_SEARCH);

	/**
	 * Gets the content of Control.
	 *
	 * @since		2.0
	 *
	 * @return		The control that is displayed in the content area of %SearchBar in the SEARCH_BAR_MODE_INPUT mode, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Ui::Control* GetContent(void) const;

	/**
	 * Sets the content control.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since		2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *						For more information, see @ref CompSetContentPage "here"
	 * @endif
	 * @return      An error code
	 * @param[in]   pContent			The control that is to be displayed in the content area of the search bar
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									The following controls cannot be set as the content: @n
	 *									@li All classes derived from the Window class
	 *									@li All picker classes (For example, DateTimePicker)
	 *									@li Form
	 *									@li Keypad
	 *									@li OverlayPanel
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specified content control is displayed when the mode of the %SearchBar control is changed to SEARCH_BAR_MODE_INPUT.
	 * @see			GetContentAreaSize()
	 * @see			AddSearchBarEventListener()
	 * @see			ISearchBarEventListener
	 */
	result SetContent(const Tizen::Ui::Control* pContent);
	/**
	 * @page               CompSetContentPage        Compatibility for SetContent()
	 * @section            CompSetContentPage IssueSection          Issues
	 * Implementing this method in OSP compatible applications has the following issue: @n
	 * SetContent() method passes the ownership of Content control to SearchBar in OSP,
	 * whereas the Content control ownership remains with the caller in Tizen.
	 *
	 * @section            CompSetContentPage SolutionSection               Resolutions
	 * In Tizen, the caller should delete the previous Content control, if this method is called more than once.
	 */

	/**
	 * Updates the content area of the %SearchBar control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	show					Set to @c true to perform show on the content area, @n
	 *										else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *										The current mode of %SearchBar prohibits the execution of the method.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The method performs Invalidate() on the content area.
	 */
	result UpdateContentArea(bool invalidate = true);

	/**
	 * Sets the visibility state of the content area.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	visible				Set to @c true to make the content area visible, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			IsContentAreaVisible()
	 */
	result SetContentAreaVisible(bool visible);

	/**
	 * Checks whether the content area is visible.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the content area is visible, @n
	 *				else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @see			SetContentAreaVisible()
	 */
	bool IsContentAreaVisible(void) const;

	/**
	 * Sets the size of the content area of the %SearchBar control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	size				The size of the content area
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid. @n
	 *                                  The width and height of @c size must be greater than or equal to @c 0.
	 * @remarks		The content area must be resized when the orientation of the form is changed once the size of the content area is changed.
	 * @see         GetContentAreaSize()
	 */
	result SetContentAreaSize(const Tizen::Graphics::Dimension& size);

	/**
	 * Gets the size of the content area of the %SearchBar control.
	 *
	 * @since		2.0
	 *
	 * @return		The size of the content area
	 * @remarks		The content area is the area where the 'content' of the %SearchBar control is displayed. The size of the content areas can
	 *              be changed at runtime.
	 * @see         AddSearchBarEventListener()
	 * @see         ISearchBarEventListener
	 */
	Tizen::Graphics::Dimension GetContentAreaSize(void) const;

// Modes
	/**
	 * Gets the search bar mode.
	 *
	 * @since		2.0
	 *
	 * @return      The search bar mode
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetMode()
	 */
	SearchBarMode GetMode(void) const;

	/**
	 * Checks whether the search bar mode is locked.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the mode is locked, @n
	 *				else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetModeLock()
	 */
	bool IsModeLocked(void) const;

	/**
	 * Sets the search bar mode.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   mode                The search bar mode
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or @n
	 *									the mode is locked.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @see			GetMode()
	 * @see			SetModeLock()
	 */
	result SetMode(SearchBarMode mode);

	/**
	 * Sets the lock status of the search bar mode.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   modeLocked          Set to @c true to lock the search bar mode, @n
	 *									else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @see         GetMode()
	 */
	result SetModeLocked(bool modeLocked);

	/**
	 * Gets the action ID of the search bar button.
	 *
	 * @since		2.0
	 *
	 * @return      The action ID, @n
	 *				else @c -1 if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
	 *				By default, the method returns @c -1 if no user defined search bar button is set.
	 */
	int GetButtonActionId(void) const;

	/**
	 * Gets the color of the search bar button for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return		The color of the search bar button, @n
	 *				else RGBA(0,0,0,0) if an error occurs
	 * @param[in]	status				The status of the search bar button
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetButtonColor()
	 */
	Tizen::Graphics::Color GetButtonColor(SearchBarButtonStatus status) const;

	/**
	 * Gets the text color of the search bar button for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return		The text color of the search bar button, @n
	 *				else RGBA(0,0,0,0) if an error occurs
	 * @param[in]   status              The status of the search bar button
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetButtonTextColor(SearchBarButtonStatus status) const;

	/**
	 * Gets the state of the search bar button.
	 *
	 * @since		2.0
	 *
	 * @return		The state of the search bar button
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	SearchBarButtonStatus GetButtonStatus(void) const;

	/**
	 * Sets the user defined search bar button.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]	text			The button text
	 * @param[in]	actionId		The button action ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid, or @n
	 *								the specified @c actionId must be greater than or equal to @c 0.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetButton(const Tizen::Base::String& text, int actionId);

	/**
	 * Sets the enabled status of the search bar button.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	enabled			Set to @c true to enable the search bar button, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetButtonEnabled(bool enabled);

	/**
	 * Sets the color of the search bar button for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	status          The button status
	 * @param[in]	color           The button color to be set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetButtonColor()
	 */
	result SetButtonColor(SearchBarButtonStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Sets the text color of the button of the %SearchBar control for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	status			The button status
	 * @param[in]	color			The button text color to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetButtonTextColor(SearchBarButtonStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Appends the specified character at the end of the text.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	character		The character to be added
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %SearchBar control. @n
	 *              To display the changes, the control must be drawn again.
	 */
	result AppendCharacter(const Tizen::Base::Character& character);

	/**
	 * Appends the specified text at the end of the existing text.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text		The text to be appended
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM    A system error has occurred.
	 * @remarks		To denote the end of a line use '\\n'. @n
	 *              The method modifies the text buffer that is managed by the %SearchBar control. @n
	 *              To display the changes, the control must be drawn again.
	 */
	result AppendText(const Tizen::Base::String& text);


	/**
	 * Sets the text to be displayed.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text			The text to be displayed
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks		To denote the end of a line use '\\n'. @n
	 *              The method modifies the text buffer that is managed by the %SearchBar control. @n
	 *              To display the changes, the control must be drawn again.
	 */
	result SetText(const Tizen::Base::String& text);

	/**
	 * Inserts the character at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The position to insert the character
	 * @param[in]	character		The character to be inserted
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is outside the bounds of the data structure. @n
	 *                              The specified @c index is greater than the number of elements or less than @c 0.
	 * @exception	E_MAX_EXCEEDED	The length of the specified @c text exceeds the system limitation.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %SearchBar control. @n
	 *				To display the changes, the control must be drawn again.
	 */
	result InsertCharacterAt(int index, const Tizen::Base::Character& character);

	/**
	 * Inserts the specified text at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The position at which to insert
	 * @param[in]	text			The text to be inserted
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified @c index is outside the bounds of the data structure. @n
	 *								The specified @c index is greater than the number of elements or less than @c 0.
	 * @exception	E_MAX_EXCEEDED  The length of the specified @c text exceeds the system limitation.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %SearchBar control.
	 *				To display the changes, the control must be drawn again.
	 */
	result InsertTextAt(int index, const Tizen::Base::String& text);

	/**
	 * Deletes the character at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c index is negative.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is outside the bounds of the data structure. @n
	 *                              The specified @c index is greater than the number of elements or less than @c 0.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     The method modifies the text buffer that is managed by the %SearchBar control. @n
	 *              To display the changes, the control must be drawn again.
	 */
	result DeleteCharacterAt(int index);

	/**
	 * Clears the text that is displayed by the %SearchBar control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The method modifies the text buffer that is managed by the %SearchBar control. @n
	 *				To display the changes, the control must be drawn again.
	 */
	result Clear(void);

	/**
	 * Gets the length of the text that is displayed by the %SearchBar control.
	 *
	 * @since		2.0
	 *
	 * @return		The length of the text, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetTextLength(void) const;

	/**
	 * Gets the text that is displayed by the %SearchBar control.
	 *
	 * @since		2.0
	 *
	 * @return		The text displayed by the %SearchBar control, @n
	 *				else an empty string if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetText()
	 */
	Tizen::Base::String GetText(void) const;

	/**
	 * Gets a portion of text that is displayed by the %SearchBar control.
	 *
	 * @since		2.0
	 *
	 * @return		The specified portion of the text, @n
	 *				else an empty string if an error occurs
	 * @param[in]	start	        The starting index of range
	 * @param[in]	end	            The last index of range
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified index is outside the bounds of the data structure, or @n
	 *								either the @c start or @c end parameter is greater than the number of elements or less than @c 0.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetText()
	 */
	Tizen::Base::String GetText(int start, int end) const;

	/**
	 * Gets the limit of the length of the text.
	 *
	 * @since		2.0
	 *
	 * @return		The limit of the text length, @n
	 *				else @c -1 if an error occurs
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
	 *				The default limit length is @c 500.
	 * @see         SetLimitLength()
	 */
	int GetLimitLength(void) const;

	/**
	 * Sets the limit of the length of the text.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	limitLength		The limit text length to be set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or @n
	 *								the specified limit length cannot be @c 0 or negative.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetLimitLength()
	 */
	result SetLimitLength(int limitLength);

	/**
	 * Shows the keypad associated with the %SearchBar control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			HideKeypad()
	 */
	result ShowKeypad(void) const;

	/**
	 * Hides the keypad associated with the %SearchBar control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			ShowKeypad()
	 */
	result HideKeypad(void) const;

	/**
	 * Gets the text size of the search field.
	 *
	 * @since		2.0
	 *
	 * @return      The size of the text, @n
	 *              else @c -1 if an error occurs
	 * @exception   E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM		A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetSearchFieldTextSize()
	 */
	int GetSearchFieldTextSize(void) const;

	/**
	 * Sets the text size of the text field of the %SearchBar control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	size			The text size
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid, or @n
	 *								the specified @c size cannot be a negative value.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetSearchFieldTextSize()
	 */
	result SetSearchFieldTextSize(int size);

	/**
	 * Gets the start and the end index of the currently selected text block.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	start			The start index of the text block
	 * @param[out]	end				The end index of the text block
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The method returns @c start = 0 and @c end = 0 if no text block is selected.
	 * @see			ReleaseBlock()
	 * @see			SetBlockRange()
	 */
	result GetBlockRange(int& start, int& end) const;

	/**
	 * Releases the selection of the current text block.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetBlockRange()
	 * @see			SetBlockRange()
	 */
	result ReleaseBlock(void);

	/**
	 * Sets the block range for the text.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	start	        The start index of the text block
	 * @param[in]	end             The end index of the text block
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is outside the bounds of the data structure, or @n
	 *								either the @c start or @c end parameter is greater than the number of elements or less than @c 0.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			ReleaseBlock()
	 * @see			GetBlockRange()
	 */
	result SetBlockRange(int start, int end);

	/**
	 * Removes the text of the selected text block.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveTextBlock(void);

	/**
	 * Gets the color of the %SearchBar control for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		The color of the %SearchBar control, @n
	 *				else RGBA(0,0,0,0) if an error occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetColor()
	 */
	Tizen::Graphics::Color GetColor(void) const;

	/**
	 * Gets the color of the search field for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		The color, @n
	 *				else RGBA(0,0,0,0) if an error occurs
	 * @param[in]	status			The search field status
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetSearchFieldColor()
	 */
	Tizen::Graphics::Color GetSearchFieldColor(SearchFieldStatus status) const;

	/**
	 * Gets the text color of the search field for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		The text color, @n
	 *				else RGBA(0,0,0,0) if an error occurs
	 * @param[in]	status			The search field status
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetSearchFieldTextColor()
	 */
	Tizen::Graphics::Color GetSearchFieldTextColor(SearchFieldStatus status) const;

	/**
	 * Sets the background bitmap of the %SearchBar control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	bitmap			The background bitmap
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Sets the color of the search bar.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	color			The color
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetColor()
	 */
	result SetColor(const Tizen::Graphics::Color& color);

	/**
	 * Sets the color of the search field for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	status				The state of the search field
	 * @param[in]	color				The text color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetSearchFieldColor()
	 */
	result SetSearchFieldColor(SearchFieldStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Sets the text color of the search field for the specified status.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	status			The state of the search field
	 * @param[in]	color			The text color
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			GetSearchFieldTextColor()
	 */
	result SetSearchFieldTextColor(SearchFieldStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Gets the guide text.
	 *
	 * @since		2.0
	 *
	 * @return		The guide text, @n
	 *				else an empty string if an error occurs
	 * @exception	E_SUCCESS        The method is successful.
	 * @exception	E_SYSTEM         A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetGuideText()
	 */
	Tizen::Base::String GetGuideText(void) const;

	/**
	 * Sets the guide text. @n
	 * This text is displayed when there is no text in the %SearchBar control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	guideText			The guide text
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetGuideText()
	 */
	result SetGuideText(const Tizen::Base::String& guideText);

	/**
	 * Gets the text color of the guide text.
	 *
	 * @since		2.0
	 *
	 * @return		The text color of the guide text, @n
	 *				else RGBA(0,0,0,0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetGuideTextColor()
	 */
	Tizen::Graphics::Color GetGuideTextColor(void) const;

	/**
	 * Sets the text color of the guide text.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	color				The guide text color
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetGuideTextColor()
	 */
	result SetGuideTextColor(const Tizen::Graphics::Color& color);

// Cursor
	/**
	 * Gets the current cursor position index.
	 *
	 * @since		2.0
	 *
	 * @return		The cursor position, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetCursorPosition()
	 */
	int GetCursorPosition(void) const;

	/**
	 * Sets the cursor at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The cursor index
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is outside the bounds of the data structure. @n
	 *								The specified @c index is greater than the number of elements or less than @c 0.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @see			GetCursorPosition()
	 */
	result SetCursorPosition(int index);

	/**
	 * Checks whether the lowercase mode is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the lowercase mode is enabled, @n
	 *				else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetLowerCaseModeEnabled()
	 */
	bool IsLowerCaseModeEnabled(void) const;

	/**
	 * Enables or disables the lowercase mode.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable			Set to @c true to enable the lowercase mode, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @see			IsLowerCaseModeEnabled()
	 */
	void SetLowerCaseModeEnabled(bool enable);

// Ellipsis
	/**
	 * Gets the ellipsis position.
	 *
	 * @since		2.0
	 *
	 * @return		The ellipsis position
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetEllipsisPosition()
	 */
	EllipsisPosition GetEllipsisPosition(void) const;

	/**
	 * Sets the ellipsis position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	position			The ellipsis position
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see			GetEllipsisPosition()
	 */
	result SetEllipsisPosition(EllipsisPosition position);

	/**
	 * Sets the input language.
	 *
	 * @since 2.0
	 *
	 * @return     An error code
	 * @param[in]  languageCode               The language to set
	 * @exception  E_SUCCESS              The method is successful.
	 * @exception  E_OUT_OF_MEMORY                   The memory is insufficient.
	 * @remarks    The application can set the language of the current keypad that is associated with the current %SearchBar. @n
	 *             This method only works if the language to set is supported by the current preloaded keypad.
	 */

	result SetCurrentLanguage(Tizen::Locales::LanguageCode languageCode);

	/**
	 * Gets the current input language.
	 *
	 * @since 2.0
	 *
	 * @return     An error code
	 * @param[out] language               The current input language
	 * @exception     E_SUCCESS                             The method is successful.
	 * @remarks   The application can get the current language of the keypad that is associated with the current %SearchBar.
	 */

	result GetCurrentLanguage(Tizen::Locales::LanguageCode& language) const;

	/**
	 * Gets the keypad action type.
	 *
	 * @since		2.0
	 *
	 * @return		The keypad action
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	KeypadAction GetKeypadAction(void) const;

	/**
	 * Checks whether the text prediction is enabled.
	 *
	 * @since 2.0
	 * @return                @c true if the text prediction is enabled, @n
	 *                                 else @c false
	 * @exception          E_SUCCESS                The method is successful.
	 * @see                      SetTextPredictionEnabled()
	 */
	bool IsTextPredictionEnabled(void) const;

	/**
	 * Enables or disables the text prediction.
	 *
	 * @since 2.0
	 * @param[in]           enable                       Set to @c true to enable the text prediction, @n
	 *                                                                    else @c false
	 * @return                An error code
	 * @exception           E_SUCCESS                The method is successful.
	 * @exception		E_UNSUPPORTED_OPERATION     This operation is not supported.
	 * @see                      IsTextPredictionEnabled()
	 */
	result SetTextPredictionEnabled(bool enable);

	/**
	 * Adds the specified action event listener. @n
	 * The added listener is notified when the user clicks the search bar button.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 * @see			RemoveActionEventListener()
	 */
	void AddActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * Removes the specified action event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 * @see			AddActionEventListener()
	 */
	void RemoveActionEventListener(Tizen::Ui::IActionEventListener& listener);

	/**
	 * Adds the specified text event listener. @n
	 * The added listener can listen to events on the context of the specified event dispatcher when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener		The event listener to be added
	 * @remarks		The added listener is notified when: @n
	 *              @li The user presses a key on the software keypad.
	 *              @li The user selects a word in the candidate list.
	 *              @li The user pastes a text.
	 * @see			RemoveTextEventListener()
	 */
	void AddTextEventListener(Tizen::Ui::ITextEventListener& listener);

	/**
	 * Removes the specified text event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 * @see			AddTextEventListener()
	 */
	void RemoveTextEventListener(Tizen::Ui::ITextEventListener& listener);

	/**
	 * Adds the specified search bar event listener. @n
	 * The added listener can listen to events on the context of the specified event dispatcher when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 * @remarks		The added listener is notified when: @n
	 *              @li The user presses a key on the software keypad.
	 *              @li The user selects a word in the candidate list.
	 *              @li The user pastes a text.
	 * @see			AddSearchBarEventListener()
	 */
	void AddSearchBarEventListener(ISearchBarEventListener& listener);

	/**
	 * Removes the specified search bar event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 * @see         RemoveTextEventListener()
	 */
	void RemoveSearchBarEventListener(ISearchBarEventListener& listener);

	/**
	 * Adds the specified text block event listener.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 * @remarks		Programmatically, modification of the text selection does not cause the text block selection event to fire.
	 * @see			RemoveTextBlockEventListener()
	 */
	void AddTextBlockEventListener(Tizen::Ui::ITextBlockEventListener& listener);

	/**
	 * Removes the specified text block event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 * @see			AddTextBlockEventListener()
	 */
	void RemoveTextBlockEventListener(Tizen::Ui::ITextBlockEventListener& listener);

	/**
	 * Adds the specified keypad event listener. @n
	 * The added listener is notified when the keypad associated with this text editor is opened or closed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be added
	 * @see         RemoveKeypadEventListener()
	 */
	void AddKeypadEventListener(Tizen::Ui::IKeypadEventListener& listener);

	/**
	 * Removes the specified keypad event listener. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to be removed
	 * @see			AddKeypadEventListener()
	 */
	void RemoveKeypadEventListener(Tizen::Ui::IKeypadEventListener& listener);

	/**
	 * Adds a listener instance for language events. @n
	 * The added listener is notified when the input language is changed.
	 *
	 * @since 2.0
	 *
	 * @param[in]  listener               The listener to add
	 * @remarks    The application can recognize when the language is changed from the keypad by adding Tizen::Ui::ILanguageEventListener.
	 * @see            RemoveLanguageEventListener()
	 */

	void AddLanguageEventListener(Tizen::Ui::ILanguageEventListener& listener);

	/**
	 * Removes the specified listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 2.0
	 *
	 * @param[in]  listener               The listener to remove
	 * @see             AddLanguageEventListener()
	 */

	void RemoveLanguageEventListener(Tizen::Ui::ILanguageEventListener& listener);


protected:
	friend class _SearchBarImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	SearchBar(const SearchBar& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	SearchBar& operator =(const SearchBar& rhs);

}; // SearchBar

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_SEARCH_BAR_H_
