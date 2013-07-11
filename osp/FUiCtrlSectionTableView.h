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
 * @file FUiCtrlSectionTableView.h
 * @brief This is the header file for the %SectionTableView class.
 *
 * This header file contains the declarations of the %SectionTableView class and its helper classes.
 */

#ifndef _FUI_CTRL_SECTION_TABLE_VIEW_H_
#define _FUI_CTRL_SECTION_TABLE_VIEW_H_

#include <FGrpRectangle.h>
#include <FGrpColor.h>
#include <FUiContainer.h>
#include <FUiCtrlTableViewTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{
class ISectionTableViewItemProvider;
class ISectionTableViewItemEventListener;
class IFastScrollListener;
class IScrollEventListener;

/**
 * @class SectionTableView
 * @brief   This class defines common behavior for a %SectionTableView control.
 *
 * @since 2.0
 *
 * The %SectionTableView class defines common behavior for a %SectionTableView control.
 * @code
//Sample code for SectionTableViewSample.h
#include <FUi.h>

class SectionTableViewSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::ISectionTableViewItemProvider
	, public Tizen::Ui::Controls::ISectionTableViewItemEventListener
{
public:
	SectionTableViewSample(void)
	: __pSectionTableView(null)
	, __pContextItem(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// ISectionTableViewItemEventListener
	virtual void OnSectionTableViewItemStateChanged(Tizen::Ui::Controls::SectionTableView& tableView, int sectionIndex, int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem, Tizen::Ui::Controls::TableViewItemStatus status);
	virtual void OnSectionTableViewContextItemActivationStateChanged(Tizen::Ui::Controls::SectionTableView& tableView, int sectionIndex, int itemIndex, Tizen::Ui::Controls::TableViewContextItem* pContextItem, bool activated);

	// ISectionTableViewItemProvider
	virtual int GetSectionCount(void);
	virtual int GetItemCount(int sectionIndex);
	virtual bool HasSectionHeader(int sectionIndex);
	virtual bool HasSectionFooter(int sectionIndex);
	virtual Tizen::Base::String GetSectionHeader(int sectionIndex);
	virtual Tizen::Base::String GetSectionFooter(int sectionIndex);
	virtual int GetDefaultItemHeight(void);
	virtual Tizen::Ui::Controls::TableViewItem* CreateItem(int sectionIndex, int itemIndex, int itemWidth);
	virtual bool DeleteItem(int sectionIndex, int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem);
	virtual void UpdateItem(int sectionIndex, int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem);

private:
	Tizen::Ui::Controls::SectionTableView* __pSectionTableView;
};
 *  @endcode
 *
 *  @code

//Sample code for SectionTableViewSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "SectionTableViewSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Ui::Controls;

bool
SectionTableViewSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
SectionTableViewSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of TableView
	__pSectionTableView = new TableView();
	__pSectionTableView->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height), true, TABLE_VIEW_SCROLL_BAR_STYLE_FADE_OUT);
	__pSectionTableView->SetItemProvider(*this);
	__pSectionTableView->AddTableViewItemEventListener(*this);

	// Adds the TableView to the form
	AddControl(*__pSectionTableView);
	return r;
}

result
SectionTableViewSample::OnTerminating(void)
{
	return E_SUCCESS;
}

// ISectionTableViewItemEventListener implementation
void
SectionTableViewSample::OnSectionTableViewItemStateChanged(SectionTableView& tableView, int sectionIndex, int itemIndex, TableViewItem* pItem, TableViewItemStatus status)
{
	// ....
}

void
SectionTableViewSample::OnSectionTableViewContextItemActivationStateChanged(SectionTableView& tableView, int sectionIndex, int itemIndex, TableViewContextItem* pContextItem, bool activated)
{
	// ....
}

// ISectionTableViewItemProvider implementation
int
SectionTableViewSample::GetSectionCount(void)
{
	return 10;
}

int
SectionTableViewSample::GetItemCount(int sectionIndex)
{
	return 5;
}

bool
SectionTableViewSample::HasSectionHeader(int sectionIndex)
{
	true;
}

bool
SectionTableViewSample::HasSectionFooter(int sectionIndex)
{
	true;
}

String
SectionTableViewSample::GetSectionHeader(int sectionIndex)
{
	String text;
	text.Format(30, L"Section header %d", sectionIndex);

	return text;
}

String
SectionTableViewSample::GetSectionFooter(int sectionIndex)
{
	String text;
	text.Format(30, L"Section footer %d", sectionIndex);

	return text;
}

int
SectionTableViewSample::GetDefaultItemHeight(void)
{
	return 100;
}

TableViewItem*
SectionTableViewSample::CreateItem(int sectionIndex, int itemIndex, int itemWidth)
{
	TableViewAnnexStyle style = TABLE_VIEW_ANNEX_STYLE_NORMAL;
	TableViewItem* pItem = new TableViewItem();

	switch (itemIndex % 5)
	{
	case 0:
		style = TABLE_VIEW_ANNEX_STYLE_NORMAL;
		break;
	case 1:
		style = TABLE_VIEW_ANNEX_STYLE_MARK;
		break;
	case 2:
		style = TABLE_VIEW_ANNEX_STYLE_ONOFF_SLIDING;
		break;
	case 3:
		style = TABLE_VIEW_ANNEX_STYLE_DETAILED;
		break;
	case 4:
		style = TABLE_VIEW_ANNEX_STYLE_RADIO;
		break;
	default:
		break;
	}

	pItem->Construct(Dimension(itemWidth, GetDefaultItemHeight()), style);

	String text;
	text.Format(30, L"TableViewItem %d", itemIndex);

	Label* pLabel = new Label();
	pLabel->Construct(Rectangle(0, 0, itemWidth, GetDefaultItemHeight(), text);

	pItem->AddControl(*pLabel);

	return pItem;

}

bool
SectionTableViewSample::DeleteItem(int sectionIndex, int itemIndex, TableViewItem* pItem)
{
	delete pItem;

	return true;
}

void
SectionTableViewSample::UpdateItem(int sectionIndex, int itemIndex, TableViewItem* pItem)
{
	// ....
}
* @endcode
*
*/

class _OSP_EXPORT_ SectionTableView
	: public Tizen::Ui::Container
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. Hence, the Construct() method must be called after calling this constructor.
	 *
	 * @since 2.0
	 */
	SectionTableView(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~SectionTableView(void);

	/**
	 * Initializes this instance of %SectionTableView with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] rect    An instance of the Graphics::Rectangle class
	 *                              This instance represents the x and y coordinates of the left top corner of the created %SectionTableView along with the width and height.
	 * @param[in] itemDivider       Set to @c true to display an item divider, @n
	 *                              else @c false
	 * @param[in] scrollStyle       The style of %SectionTableView scroll bar style
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid, or either the rect.width or rect.height parameter has a negative value.
	 *
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, bool itemDivider, TableViewScrollBarStyle scrollStyle);

	/**
	 * Sets the item provider that creates and deletes items for the section style table view.
	 *
	 * @since 2.0
	 *
	 * @param[in] pProvider                                  The item provider to create and delete items
	 * @remarks If an item provider is not set for the table view, the table view does not work.
	 *          The specified provider should be allocated in heap memory.
	 */
	void SetItemProvider(ISectionTableViewItemProvider* pProvider);

	/**
	 * Sets the color of a section.
	 *
 	 * @since 2.0
	 *
	 * @param[in] color    The section color
	 * @remarks This method works only when the style of the %SectionTableView control is TABLE_VIEW_STYLE_SECTION.
	 */
	void SetSectionColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of a section.
	 *
	 * @since 2.0
	 *
	 * @return The section color
	 */
	Tizen::Graphics::Color GetSectionColor(void) const;

	/**
	 * Sets the grouped look is enabled.
	 *
	 * @since 2.0
	 *
	 * @param[in] enable   The enabled/disabled status
	 */
	void SetGroupedLookEnabled(bool enable);

	/**
	 * Returns whether the grouped look is enabled or not.
	 *
	 * @since 2.0
	 *
	 * @return @c true if the grouped look is enabled, else @c false
	 */
	bool IsGroupedLookEnabled(void) const;

	/**
	 * Adds a listener instance that listens to state changes of table view items. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] listener      The event listener to add
	 * @exception E_SUCCESS                                           The method is successful.
	 * @exception E_OBJ_ALREADY_EXIST       The listener is already added.
	 * @remarks   The specified listener should be allocated in heap memory.
	 */
	result AddSectionTableViewItemEventListener(ISectionTableViewItemEventListener& listener);

	/**
	 * Removes a listener instance that listens to state changes of table view items. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] listener   The event listener to remove
	 * @exception    E_SUCCESS                             The method is successful.
	 * @exception    E_OBJ_NOT_FOUND                  The listener is not found.
	 */
	result RemoveSectionTableViewItemEventListener(ISectionTableViewItemEventListener& listener);

	/**
	 * Adds a listener instance that listens to state changes of a fast scroll. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] listener   The event listener to add
	 * @exception    E_SUCCESS                             The method is successful.
	 * @exception    E_INVALID_OPERATION    The current state of the instance prohibits the execution of the specified operation.
	 * @exception    E_OBJ_ALREADY_EXIST     The listener is already added.
	 * @remarks   The specified listener should be allocated in heap memory.
	 */
	result AddFastScrollListener(IFastScrollListener& listener);

	/**
	 * Removes a listener instance that listens to state changes of a fast scroll. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] listener   The event listener to remove
	 * @exception    E_SUCCESS                             The method is successful.
	 * @exception    E_INVALID_OPERATION    The current state of the instance prohibits the execution of the specified operation.
	 * @exception    E_OBJ_NOT_FOUND                  The listener is not found.
	 */
	result RemoveFastScrollListener(IFastScrollListener& listener);

	/**
	 * Adds a listener instance that listens to state changes of a scroll event. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] listener          The event listener to add
	 * @see     IScrollEventListener::OnScrollEndReached()
	 * @see     RemoveScrollEventListener()
	 * @exception    E_SUCCESS                             The method is successful.
	 * @exception    E_INVALID_OPERATION    The current state of the instance prohibits the execution of the specified operation.
	 * @exception    E_OBJ_ALREADY_EXIST     The listener is already added.
	 * @remarks   The specified listener should be allocated in heap memory.
	 */
	result AddScrollEventListener(IScrollEventListener& listener);

	/**
	 * Removes a listener instance that listens to state changes of a scroll event. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] listener   The event listener to remove
	 * @see  IScrollEventListener::OnScrollEndReached()
	 * @see     AddScrollEventListener()
	 * @exception    E_SUCCESS                             The method is successful.
	 * @exception    E_INVALID_OPERATION    The current state of the instance prohibits the execution of the specified operation.
	 * @exception    E_OBJ_NOT_FOUND                  The listener is not found.
	 */
	result RemoveScrollEventListener(IScrollEventListener& listener);

	/**
	 * Sets the text index of the fast scroll.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] text              The text of the index
	 * @param[in] useSearchIcon  Set to @c true to show the magnifying icon, @n
	 *                              else @c false
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception E_INVALID_OPERATION      The current state of the instance prohibits the execution of the specified operation.
	 */
	result SetFastScrollIndex(const Tizen::Base::String& text, bool useSearchIcon);

	/**
	 * Gets the section and item indexes of the top item.
	 *
	 * @since 2.0
	 *
	 * @return        An error code
	 * @param[out]  sectionIndex               The section index
	 * @param[out]  itemIndex                  The item index
	 * @exception   E_SUCCESS                  The method is successful.
	 * @exception   E_OBJ_NOT_FOUND            Top drawn item is not found.
	 */
	result GetTopDrawnItemIndex(int& sectionIndex, int& itemIndex) const;

	/**
	 * Gets the section and item indexes of the bottom item.
	 *
	 * @since 2.0
	 *
	 * @return        An error code
	 * @param[out]  sectionIndex               The section index
	 * @param[out]  itemIndex                  The item index
	 * @exception   E_SUCCESS                  The method is successful.
	 * @exception   E_OBJ_NOT_FOUND            Bottom drawn item is not found.
	 */
	result GetBottomDrawnItemIndex(int& sectionIndex, int& itemIndex) const;

	/**
	 * Scrolls to the item at the specified index.
	 * The specified item is drawn at the position specified by the item alignment.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] sectionIndex					The section index
	 * @param[in] itemIndex						The item index
	 * @param[in] itemAlignment					The item alignment
	 * @exception E_SUCCESS						The method is successful.
	 * @exception E_OUT_OF_RANGE					A specified input parameter is invalid.
	 */
	result ScrollToItem(int sectionIndex, int itemIndex, TableViewScrollItemAlignment itemAlignment = TABLE_VIEW_SCROLL_ITEM_ALIGNMENT_TOP);

	/**
	 * Checks or unchecks the item at the specified index.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] sectionIndex					The section index
	 * @param[in] itemIndex						The item index
	 * @param[in] check							Set to @c true to select the item, @n
	 *											else @c false
	 * @exception E_SUCCESS   The method is successful.
	 * @exception E_OUT_OF_RANGE            A specified input parameter is invalid.
	 * @exception E_INVALID_OPERATION      The item is disabled.
	 * @remarks This method works only when the annex style of the item allows selection.
	 */
	result SetItemChecked(int sectionIndex, int itemIndex, bool check);

	/**
	 * Returns whether the item at the specified index is selected or not.
	 *
	 * @since 2.0
	 *
	 * @return @c true if the item is selected, @n
	 *   else @c false
	 * @param[in] sectionIndex					The section index
	 * @param[in] itemIndex						The item index
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_OUT_OF_RANGE A specified input parameter is invalid.
	 * @remarks This method returns @c false, if the annex style of the item does not allow selection.
	 */
	bool IsItemChecked(int sectionIndex, int itemIndex) const;

	/**
	 * Enables or disables the item at the specified index.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @param[in] sectionIndex					The section index
	 * @param[in] itemIndex						The item index
	 * @param[in] enable							Set to @c true to enable the specified item, @n
	 *											else @c false
	 * @exception E_SUCCESS   The method is successful.
	 * @exception E_OUT_OF_RANGE  A specified input parameter is invalid.
	 */
	result SetItemEnabled(int sectionIndex, int itemIndex, bool enable);

	/**
	 * Returns whether the item at the specified index is enabled or disabled.
	 *
	 * @since 2.0
	 *
	 * @return @c true if the item is enabled, @n
	 *   else @c false
	 * @param[in] sectionIndex					The section index
	 * @param[in] itemIndex						The item index
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_OUT_OF_RANGE A specified input parameter is invalid.
	 */
	bool IsItemEnabled(int sectionIndex, int itemIndex) const;

	/**
	 * Counts the total number of sections.
	 *
	 * @since 2.0
	 *
	 * @return The total number of sections
	 */
	int GetSectionCount(void) const;

	/**
	 * Counts all the items of the specified section.
	 *
	 * @since 2.0
	 *
	 * @return The total number of items in the specified section
	 * @param[in] sectionIndex					The section index
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_OUT_OF_RANGE A specified input parameter is invalid.
	 */
	int GetItemCountAt(int sectionIndex) const;

	/**
	 * Updates the specified item. @n
	 * For instance, TABLE_VIEW_REFRESH_TYPE_ITEM_ADD is used when a new item needs to be added and TABLE_VIEW_REFRESH_TYPE_ITEM_REMOVE is used when an item is deleted from the
	 * table view. Moreover, TABLE_VIEW_REFRESH_TYPE_ITEM_MODIFY is used when the content of an existing item has changed and it needs to be updated.
	 * Note that calling this method with TABLE_VIEW_REFRESH_TYPE_ITEM_MODIFY invokes item provider's UpdateItem() for the given index in sequence.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @param[in] sectionIndex         The section index
	 * @param[in] itemIndex            The item index
	 * @param[in] type                 The item to be added, removed, or modified
	 * @exception E_SUCCESS   The method is successful.
	 * @exception E_OUT_OF_RANGE  A specified input parameter is invalid.
	 * @remarks If the specified item. itemIndex is -1, then the method is applied to the section item with the given index.
	 *   Note that if TABLE_VIEW_REFRESH_TYPE_ITEM_REMOVE option is used to a section item, all the items in the section (including the section item itself) are
	 *   removed from the table view.
	 */
	result RefreshItem(int sectionIndex, int itemIndex, TableViewRefreshType type);

	/**
	 * Updates all the items of a table view.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @remarks This method clears all the items in the table view and invokes the methods of the item provider again to update the table view.
	 */
	void UpdateTableView(void);

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since 2.0
	 *
	 * @param[in] position   The position of the item
	 * @param[out] sectionIndex The section index of the item on specified position
	 * @param[out] itemIndex  The item index of the item on specified position
	 * @remarks This method sets both of sectionIndex and itemIndex to -1 if no item is found at the given position.
	 */
	result GetItemIndexFromPosition(const Tizen::Graphics::Point& position, int& sectionIndex, int& itemIndex) const;

	/**
	 * Sets the color of a division line between items.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @param[in] color    The division line color
	 */
	void SetItemDividerColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of a division line between items.
	 *
	 * @since 2.0
	 *
	 * @return  The color of a division line
	 */
	Tizen::Graphics::Color GetItemDividerColor(void) const;

	/**
	 * Sets the background color of this control.
	 *
	 * @since 2.0
	 *
	 * @param[in] color       The background color
	 * @remarks The background bitmap has priority over the background color. When both the background bitmap and the background color are specified,
	 *   only the bitmap image is displayed.
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the background color of this control.
	 *
	 * @since 2.0
	 *
	 * @return The background color
	 */
	Tizen::Graphics::Color GetBackgroundColor(void) const;

	/**
	 * Sets the scroll input handling mode.
	 *
	 * @since 2.0
	 *
	 * @param[in] mode  The scroll input handling mode
	 * @see         GetScrollInputMode()
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

	/*
	 * Scrolls the list contents with the amount of pixels.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in]   pixel					 The amount of pixels to scroll
	 * @exception   E_SUCCESS			 The method is successful.
	 * @exception   E_OUT_OF_RANGE	 The specified @c pixel is out of range.
	 * @remarks If you call ScrollByPixel() with negative @c pixel when position of scroll is already top of contents then it will return E_OUT_OF_RANGE.
	 *			   Likewise, in case of positive @c pixel on the bottom position of scroll it will also return E_OUT_OF_RANGE.
	 */
	result ScrollByPixel(int pixel);

	/*
	 * Gets the current scroll position
	 *
	 * @since 2.0
	 */
	int GetCurrentScrollPosition(void) const;

	/*
	 * Enables or disables the scroll of SectionTableView items.
	 *
	 * @since 2.0
	 */
	void SetScrollEnabled(bool enable);

	/*
	 * Checks whether the scroll is enabled or disabled.
	 *
	 * @since 2.0
	 */
	bool IsScrollEnabled(void) const;

private:
	friend class _TableViewImpl;

	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	SectionTableView(const SectionTableView& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	SectionTableView& operator =(const SectionTableView& rhs);
}; // SectionTableView

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_SECTION_TABLE_VIEW_H_
