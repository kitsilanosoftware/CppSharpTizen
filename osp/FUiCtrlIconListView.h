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
// distributed under the License is distributed on an ¡±AS IS¡± BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FUiCtrlIconListView.h
 * @brief	This is the header file for the %IconListView class.
 *
 * This header file contains the declarations of the %IconListView class and its helper classes.
 */

#ifndef _FUI_CTRL_ICON_LIST_VIEW_H_
#define _FUI_CTRL_ICON_LIST_VIEW_H_

//Includes
#include <FGrpFloatRectangle.h>
#include <FOspConfig.h>
#include <FUiContainer.h>
#include <FUiCtrlControlsTypes.h>
#include <FUiCtrlIconListViewTypes.h>
#include <FUiCtrlIIconListViewItemEventListener.h>
#include <FUiCtrlIIconListViewItemProvider.h>
#include <FUiCtrlIScrollEventListener.h>
#include <FUiCtrlIScrollEventListenerF.h>
#include <FUiCtrlListViewTypes.h>
#include <FUiCtrlScrollPanelTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @class	IconListView
 * @brief   This class defines the common behavior for a %IconListView control.
 *
 * @since	2.0
 *
 * The %IconListView class displays a 2-dimentional list of bitmap images and icons.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 *
 * The following example demonstrates how to use the %IconListView class.
 *
 * @code
//Sample code for IconListViewSample.h
#include <FUi.h>

class IconListViewSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IIconListViewItemProvider
	, public Tizen::Ui::Controls::IIconListViewItemEventListener
{
public:
	IconListViewSample(void)
	: __pIconListView(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IIconListViewItemEventListener
	virtual void OnIconListViewItemStateChanged(Tizen::Ui::Controls::IconListView &view, int index, Tizen::Ui::Controls::IconListViewItemStatus status);

	//IIconListViewItemProvider
	virtual Tizen::Ui::Controls::IconListViewItem* CreateItem(int index);
	virtual bool DeleteItem(int index, Tizen::Ui::Controls::IconListViewItem* pItem);
	virtual int GetItemCount(void);

private:
	Tizen::Graphics::Bitmap* __pHome;
	Tizen::Graphics::Bitmap* __pMsg;
	Tizen::Graphics::Bitmap* __pAlarm;

	Tizen::Ui::Controls::IconListView* __pIconListView;
};
 *	@endcode
 *
 *	@code
//Sample code for IconListViewSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "IconListViewSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
IconListViewSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
IconListViewSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of IconListView
	__pIconListView = new IconListView();
	__pIconListView->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height),
			Dimension(100, 100), ICON_LIST_VIEW_STYLE_NORMAL, ICON_LIST_VIEW_SCROLL_DIRECTION_VERTICAL);
	__pIconListView->SetItemProvider(*this);
	__pIconListView->AddIconListViewItemEventListener(*this);

	// Adds the icon list view to the form
	AddControl(__pIconListView);

	// Gets instances of Bitmap
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	__pHome  = pAppResource->GetBitmapN(L"home.png");
	__pMsg = pAppResource->GetBitmapN(L"message.png");
	__pAlarm  = pAppResource->GetBitmapN(L"alarm.png");

	return r;
}

result
IconListViewSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates bitmaps
	delete __pHome;
	delete __pMsg;
	delete __pAlarm;

	return r;
}

int
IconListViewSample::GetItemCount(void)
{
	return 3;
}

IconListViewItem*
IconListViewSample::CreateItem(int index)
{
	// Creates an instance of IconListViewItem
	IconListViewItem* pIconListview = new IconListViewItem();

	// Creates an instance of String
	String* pStr = new String();

	switch (index % 3)
	{
	case 0:
		{
			*pStr = L"Home";
			pIconListview->Construct(*__pHome, pStr);
		}
		break;
	case 1:
		{
			*pStr = L"Msg";
			pIconListview->Construct(*__pMsg, pStr);
		}
		break;
	case 2:
		{
			*pStr = L"Alarm";
			pIconListview->Construct(*__pAlarm, pStr);
		}
		break;
	}

	// Deallocates the string
	delete pStr;

	return pIconListview;
}

bool
IconListViewSample::DeleteItem(int index, IconListViewItem* pItem)
{
	delete pItem;
	return true;
}

void
IconListViewSample::OnIconListViewItemStateChanged (IconListView &view, int index, IconListViewItemStatus status)
{
	switch (index)
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
 *
 */
class _OSP_EXPORT_ IconListView
	: public Tizen::Ui::Control
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct(const Tizen::Graphics::Rectangle&, const Tizen::Graphics::Dimension&, IconListViewStyle, IconListViewScrollDirection, IconListViewScrollStyle) method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	IconListView(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~IconListView(void);

public:
	/**
	 * Initializes this instance of %IconListView with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @return	An error code
	 * @param[in]	rect				An instance of the Tizen::Graphics::Rectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created %IconListView along with
	 *									the width and height.@n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]   itemBitmapSize		The size of an icon in %IconListView
	 * @param[in]	style				The style set of %IconListView
	 * @param[in]	direction			The direction of scroll
	 * @param[in]	scrollStyle			The scroll style of %IconListView
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier.
	 * @remarks	The number of items to be displayed on a screen is calculated based on %IconListView size, item size, item spacing, and margins. @n
	 *			%IconListView cannot display more than @c 256 items on the screen at once.
	 * @remarks	The actual size of bitmap to be displayed in %IconListView is smaller than the specified size when the border style is @c ICON_LIST_VIEW_ITEM_BORDER_STYLE_SHADOW.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, const Tizen::Graphics::Dimension& itemBitmapSize, IconListViewStyle style = ICON_LIST_VIEW_STYLE_NORMAL, IconListViewScrollDirection direction = ICON_LIST_VIEW_SCROLL_DIRECTION_VERTICAL, IconListViewScrollStyle scrollStyle = ICON_LIST_SCROLL_STYLE_FADE_OUT);

	/**
	 * Initializes this instance of %IconListView with the specified parameters.
	 *
	 * @since   2.1
	 *
	 * @return	An error code
	 * @param[in]	rect				An instance of the Tizen::Graphics::FloatRectangle class @n
	 *									This instance represents the x and y coordinates of the top-left corner of the created %IconListView along with
	 *									the width and height.@n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]   itemBitmapSize		The size of an icon in %IconListView
	 * @param[in]	style				The style set of %IconListView
	 * @param[in]	direction			The direction of scroll
	 * @param[in]	scrollStyle			The scroll style of %IconListView
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier.
	 * @remarks	The number of items to be displayed on a screen is calculated based on %IconListView size, item size, item spacing, and margins. @n
	 *			%IconListView cannot display more than @c 256 items on the screen at once.
	 * @remarks	The actual size of bitmap to be displayed in %IconListView is smaller than the specified size when the border style is @c ICON_LIST_VIEW_ITEM_BORDER_STYLE_SHADOW.
	 */
	result Construct(const Tizen::Graphics::FloatRectangle& rect, const Tizen::Graphics::FloatDimension& itemBitmapSize, IconListViewStyle style = ICON_LIST_VIEW_STYLE_NORMAL, IconListViewScrollDirection direction = ICON_LIST_VIEW_SCROLL_DIRECTION_VERTICAL, IconListViewScrollStyle scrollStyle = ICON_LIST_SCROLL_STYLE_FADE_OUT);

	/**
	 * Sets the item provider that creates and deletes items for the %IconListView control.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]	provider			The item provider to create and delete items
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	If an item provider is not set for %IconListView, it does not work. @n
	 *			The specified @c provider should be allocated in heap memory.
	 */
	result SetItemProvider(IIconListViewItemProvider& provider);

	/**
	 * Adds a listener instance. @n
	 * The added listener can listen to item events when they are fired.
	 *
	 * @since   2.0
	 *
	 * @param[in]	listener			The listener to add
	 */
	void AddIconListViewItemEventListener(IIconListViewItemEventListener& listener);

	/**
	 * Removes a listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since   2.0
	 *
	 * @param[in]	listener			The listener to remove
	 */
	void RemoveIconListViewItemEventListener(IIconListViewItemEventListener& listener);

	/**
	 * Adds a listener instance that listens to state changes of a scroll event. @n
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @since   2.0
	 *
	 * @param[in]	listener			The event listener to add
	 * @see			IScrollEventListener::OnScrollEndReached()
	 * @see			RemoveScrollEventListener()
	 */
	void AddScrollEventListener(IScrollEventListener& listener);

	/**
	 * Adds a listener instance that listens to state changes of a scroll event. @n
	 * The added listener can listen to events on the context of the given event dispatcher when they are fired.
	 *
	 * @since   2.1
	 *
	 * @param[in]	listener			The event listener to add
	 * @see			IScrollEventListenerF::OnScrollEndReached()
	 * @see			RemoveScrollEventListener()
	 */
	void AddScrollEventListener(IScrollEventListenerF& listener);

	/**
	 * Removes a listener instance that listens to state changes of a scroll event. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since   2.0
	 *
	 * @param[in]	listener			The event listener to remove
	 * @see			IScrollEventListener::OnScrollEndReached()
	 * @see			RemoveScrollEventListener()
	 */
	void RemoveScrollEventListener(IScrollEventListener& listener);

	/**
	 * Removes a listener instance that listens to state changes of a scroll event. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since   2.1
	 *
	 * @param[in]	listener			The event listener to remove
	 * @see			IScrollEventListenerF::OnScrollEndReached()
	 * @see			RemoveScrollEventListener()
	 */
	void RemoveScrollEventListener(IScrollEventListenerF& listener);

	/**
	 * Sets the background bitmap of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @param[in]   pBitmap				The background bitmap
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	When @c pBitmap is @c null, %IconListView does not have a background bitmap. The default value for the background bitmap is @c null.
	 * @remarks	The background bitmap has priority over the background color. When both the background bitmap and the background color are specified,
	 *			only the bitmap is displayed.
	 */
	result SetBackgroundBitmap(const Tizen::Graphics::Bitmap* pBitmap);

	/**
	 * Sets the background color of this control.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]	color               The background color
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks	This method sets the alpha value of the specified color to @c 255, when a device does not support @c 32 bit color space.
	 * @remarks	The background bitmap has priority over the background color. When both the background bitmap and the background color are specified,
	 *			only the bitmap is displayed.
	 */
	result SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the background color of this control.
	 *
	 * @since	2.0
	 *
	 * @return	The background color, @n
	 *			else RGBA(0, 0, 0, 0) if an error occurs
	 */
	Tizen::Graphics::Color GetBackgroundColor(void) const;

	/**
	 * Sets the margin of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]	type				The type of margin
	 * @param[in]	value				The marginal value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The number of items to be displayed on a screen is calculated based on %IconListView size, item size, item spacing, and
	 *			margins. %IconListView cannot display more than @c 256 items on screen at once.
	 */
	result SetMargin(MarginType type, int value);

	/**
	 * Sets the margin of %IconListView.
	 *
	 * @since   2.1
	 *
	 * @return	An error code
	 * @param[in]	type				The type of margin
	 * @param[in]	value				The marginal value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The number of items to be displayed on a screen is calculated based on %IconListView size, item size, item spacing, and
	 *			margins. The %IconListView cannot display more than 256 items on screen at once.
	 */
	result SetMargin(MarginType type, float value);

	/**
	 * Gets the margin of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	The marginal value of %IconListView, @n
	 *			else @c -1 if an error occurs
	 * @param[in]	type				The type of margin
	 */
	int GetMargin(MarginType type) const;

	/**
	 * Gets the margin of %IconListView.
	 *
	 * @since   2.1
	 *
	 * @return	The marginal value of %IconListView, @n
	 *			else @c -1 if an error occurs
	 * @param[in]	type				The type of margin
	 */
	float GetMarginF(MarginType type) const;

	/**
	 * Sets the horizontal and vertical spacing between the items.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]   horizontalSpacing	The spacing between items in horizontal direction
	 * @param[in]   verticalSpacing		The spacing between items in vertical direction
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The number of items to be displayed on a screen is calculated based on %IconListView size, item size, item spacing, and
	 *			margins. %IconListView cannot display more than @c 256 items on screen at once.
	 */
	result SetItemSpacing(int horizontalSpacing, int verticalSpacing);

	/**
	 * Sets the horizontal and vertical spacing between the items.
	 *
	 * @since   2.1
	 *
	 * @return	An error code
	 * @param[in]   horizontalSpacing	The spacing between items in horizontal direction
	 * @param[in]   verticalSpacing		The spacing between items in vertical direction
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The number of items to be displayed on a screen is calculated based on %IconListView size, item size, item spacing, and
	 *			margins. The %IconListView cannot display more than 256 items on screen at once.
	 */
	result SetItemSpacing(float horizontalSpacing, float verticalSpacing);

	/**
	 * Gets the horizontal spacing between items of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	The value of space between items in horizontal direction, @n
	 *			else @c -1 if an error occurs
	 */
	int GetItemHorizontalSpacing(void) const;

	/**
	 * Gets the horizontal spacing between items of %IconListView.
	 *
	 * @since   2.1
	 *
	 * @return	The value of space between items in horizontal direction, @n
	 *			else @c -1 if an error occurs
	 */
	float GetItemHorizontalSpacingF(void) const;

	/**
	 * Gets the vertical spacing between items of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	The value of space between items in vertical direction, @n
	 *			else @c -1 if an error occurs
	 */
	int GetItemVerticalSpacing(void) const;

	/**
	 * Gets the vertical spacing between items of %IconListView.
	 *
	 * @since   2.1
	 *
	 * @return	The value of space between items in vertical direction, @n
	 *			else @c -1 if an error occurs
	 */
	float GetItemVerticalSpacingF(void) const;

	/**
	 * Sets the checked status of the specified item of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]   index				The index of the %IconListView item
	 * @param[in]   check				The check status
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @remarks	This method can only be used when the style of the list allows selection.
	 * @remarks	This method only changes the state of the list item. %IconListView needs to be redrawn to reflect the change on the screen.
	 */
	result SetItemChecked(int index, bool check);

	/**
	 * Checks whether the specified @c item is checked.
	 *
	 * @since   2.0
	 *
	 * @return	@c true if the specified @c item is checked, @n
	 *			else @c false
	 * @param[in]   index				The index of the item
	 * @remarks  This method can only be used when the style of the list allows selection.
	 */
	bool IsItemChecked(int index) const;

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since   2.0
	 *
	 * @return	The index of the item, @n
	 *			else @c -1 if there is no list item at the specified position or if the %IconListView instance is invalid
	 * @param[in]   x                   The x position of a point
	 * @param[in]   y                   The y position of a point
	 */
	int GetItemIndexFromPosition(int x, int y) const;

	/**
	 * Gets the index of the item at the specified @c position.
	 *
	 * @since   2.1
	 *
	 * @return	The index of the item, @n
	 *			else @c -1 if there is no list item at the specified position or if the %IconListView instance is invalid
	 * @param[in]   x                   The x position of a point
	 * @param[in]   y                   The y position of a point
	 */
	int GetItemIndexFromPosition(float x, float y) const;

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since   2.0
	 *
	 * @return	The index of the item, @n
	 *			else @c -1 if there is no list item at the specified @c position or if the %IconListView instance is invalid
	 * @param[in]   position            The position of a point
	 */
	int GetItemIndexFromPosition(const Tizen::Graphics::Point& position) const;

	/**
	 * Gets the index of the item at the specified position.
	 *
	 * @since   2.1
	 *
	 * @return	The index of the item, @n
	 *			else @c -1 if there is no list item at the specified @c position or if the %IconListView instance is invalid
	 * @param[in]   position            The position of a point
	 */
	int GetItemIndexFromPosition(const Tizen::Graphics::FloatPoint& position) const;

	/**
	 * Sets the horizontal alignment of the text of an item.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]   alignment			The horizontal alignment of the text
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetTextHorizontalAlignment(HorizontalAlignment alignment);

	/**
	 * Sets the vertical alignment of the text of an item.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]   alignment			The vertical alignment of the text
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetTextVerticalAlignment(IconListViewItemTextVerticalAlignment alignment);

	/**
	 * Gets the horizontal alignment of the text of the %IconListView control.
	 *
	 * @since   2.0
	 *
	 * @return	The horizontal alignment of the text, @n
	 *			else @c ALIGNMENT_LEFT when the %IconListView instance is invalid
	 */
	HorizontalAlignment GetTextHorizontalAlignment(void) const;

	/**
	 * Gets the vertical alignment of the text of the current %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	The vertical alignment of the text of an item, @n
	 *			else @c ICON_LIST_VIEW_ITEM_TEXT_VERTICAL_ALIGNMENT_INSIDE_TOP when the %IconListView instance is invalid
	 */
	IconListViewItemTextVerticalAlignment GetTextVerticalAlignment(void) const;

	/**
	 * Sets the text of the empty list.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]   text                The text of the empty list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetTextOfEmptyList(const Tizen::Base::String& text);

	/**
	 * Gets the text to display when there is no item in the list.
	 *
	 * @since	2.0
	 *
	 * @return  The text to be displayed, @n
	 *			else an empty string if the instance is invalid
	 */
	Tizen::Base::String GetTextOfEmptyList(void) const;

	/**
	 * Sets the color of the text that is displayed when %IconListView contains no item.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]   color               The color of the text
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetTextColorOfEmptyList(const Tizen::Graphics::Color& color);

	/**
	 * Gets the color of the text to display when there is no item in the list.
	 *
	 * @since   2.0
	 *
	 * @return  The color of the text to be displayed, @n
	 *			else RGBA(0, 0, 0, 0) if the instance is invalid
	 */
	Tizen::Graphics::Color GetTextColorOfEmptyList(void) const;

	/**
	 * Sets the text color of the item.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]	status				The drawing status of items
	 * @param[in]	color               The color of the text
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetItemTextColor(IconListViewItemDrawingStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Gets the text color of the item.
	 *
	 * @since   2.0
	 *
	 * @return	The color of the text, @n
	 *			else RGBA(0, 0, 0, 0) if the instance is invalid
	 * @param[in]   status				The drawing status of items
	 */
	Tizen::Graphics::Color GetItemTextColor(IconListViewItemDrawingStatus status) const;

	/**
	 * Sets the size of the text of the %IconListView control.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]	size				The size of the text
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	If the specified @c size is less than the minimum size, this method fails. The minimum font size is @c 6 on devices of high screen density.
	 */
	result SetItemTextSize(int size);

	/**
	 * Sets the size of the text of the %IconListView control.
	 *
	 * @since   2.1
	 *
	 * @return	An error code
	 * @param[in]	size				The size of the text
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	If the specified @c size is less than the minimum size, this method fails. The minimum font size is @c 6 on devices of high screen density.
	 */
	result SetItemTextSize(float size);

	/**
	 * Gets the size of the text of the %IconListView control.
	 *
	 * @since   2.0
	 *
	 * @return  The size of the text of the %IconListView control, @n
	 *			else @c -1 if the instance is invalid
	 */
	int GetItemTextSize(void) const;

	/**
	 * Gets the size of the text of the %IconListView control.
	 *
	 * @since   2.1
	 *
	 * @return  The size of the text of the %IconListView control, @n
	 *			else @c -1 if the instance is invalid
	 */
	float GetItemTextSizeF(void) const;

	/**
	 * Sets the position of the checkbox of the %IconListView control.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]   position			The position of the checkbox of the %IconListView control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									That is, %IconListView cannot get the position of the checkbox when the style is @c ICON_LIST_VIEW_STYLE_NORMAL.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks  This method changes the position of the checkbox image displayed for the "selected" item(s),
	 *			when the style of %IconListView is either @c ICON_LIST_VIEW_STYLE_RADIO or @c ICON_LIST_VIEW_STYLE_MARK.
	 */
	result SetCheckBoxPosition(IconListViewCheckBoxPosition position);

	/**
	 * Gets the position of the checkbox of the %IconListView control.
	 *
	 * @since   2.0
	 *
	 * @return	The position of the checkbox
	 * @remarks	This method returns @c ICON_LIST_VIEW_CHECK_BOX_POSITION_TOP_LEFT when the style of %IconListView is @c ICON_LIST_VIEW_STYLE_NORMAL or
	 *			@c ICON_LIST_VIEW_STYLE_DIVIDE_TEXT.
	 */
	IconListViewCheckBoxPosition GetCheckBoxPosition(void) const;

	/**
	 * Enables or disables touch animation.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]	enable				Set to @c true to enable touch animation, @n
	 *                                  else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	If you want to use a separate selected bitmap, the animation effect must be disabled.
	 * @remarks	In case a touch animation is disabled, the normal bitmap of IconListViewItem is displayed in response to touch interaction if the
	 *			selected bitmap of %IconListViewItem is @c null.
	 */
	result SetTouchAnimationEnabled(bool enable);

	/**
	 * Checks whether touch animation is enabled.
	 *
	 * @since   2.0
	 *
	 * @return	@c true if touch animation is enabled, @n
	 *          else @c false if touch animation is disabled or if the instance is invalid
	 */
	bool IsTouchAnimationEnabled(void) const;

	/**
	 * Scrolls the list contents to the specified @c index.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]	index				The index of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is out of range.
	 */
	result ScrollToItem(int index);

	/*
	 * Scrolls the list contents with the amount of pixels.
	 *
	 * @since 2.1
	 *
	 * @return	An error code
	 * @param[in]	pixel				The amount of pixels to scroll
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c pixel is out of range.
	 * @remarks	If you call ScrollByPixel() with negative @c pixel when position of scroll is already top of contents then it will return @c E_OUT_OF_RANGE.
	 *			Likewise, in case of positive @c pixel on the bottom position of scroll it will also return @c E_OUT_OF_RANGE.
	 */
	result ScrollByPixel(int pixel);

	/*
	 * Scrolls the list contents with the amount of pixels.
	 *
	 * @since 2.1
	 *
	 * @return	An error code
	 * @param[in]	pixel				The amount of pixels to scroll
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c pixel is out of range.
	 * @remarks	If you call ScrollByPixel() with negative @c pixel when position of scroll is already top of contents then it will return @c E_OUT_OF_RANGE.
	 *			Likewise, in case of positive @c pixel on the bottom position of scroll it will also return @c E_OUT_OF_RANGE.
	 */
	result ScrollByPixel(float pixel);

	/**
	 * Refreshes the specified item of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]	index				The index of the %IconListView item
	 * @param[in]	type				The type of change of an item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *	                                That is, %IconListView cannot execute RefreshList() before first drawn.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is out of range.
	 */
	result RefreshList(int index, ListRefreshType type);

	/**
	 * Updates the whole items of a list.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks  This method clears items in the list and re-invokes the methods of the item provider to fill the list.
	 */
	result UpdateList(void);

	/**
	 * Gets the size of bitmap of the item.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[out]	width				The width of bitmap of the item
	 * @param[out]	height				The height of bitmap of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result GetItemBitmapSize(int& width, int& height) const;

	/**
	 * Gets the size of bitmap of the item.
	 *
	 * @since	2.1
	 *
	 * @return	An error code
	 * @param[out]	width				The width of bitmap of the item
	 * @param[out]	height				The height of bitmap of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result GetItemBitmapSize(float& width, float& height) const;

	/**
	 * Gets the size of bitmap of the item.
	 *
	 * @since   2.0
	 *
	 * @return	The size of bitmap of the item, @n
	 *			else (-1, -1) if the instance is invalid
	 */
	Tizen::Graphics::Dimension GetItemBitmapSize(void) const;

	/**
	 * Gets the size of bitmap of the item.
	 *
	 * @since   2.1
	 *
	 * @return	The size of bitmap of the item, @n
	 *			else (-1, -1) if the instance is invalid
	 */
	Tizen::Graphics::FloatDimension GetItemBitmapSizeF(void) const;

	/**
	 * Gets the size of the item.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[out]	width				The width of the item
	 * @param[out]	height				The height of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result GetItemSize(int& width, int& height) const;

	/**
	 * Gets the size of the item.
	 *
	 * @since   2.1
	 *
	 * @return	An error code
	 * @param[out]	width				The width of the item
	 * @param[out]	height				The height of the item
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 */
	result GetItemSize(float& width, float& height) const;

	/**
	 * Gets the size of the item.
	 *
	 * @since   2.0
	 *
	 * @return	The size of the item, @n
	 *			else (-1, -1) if the instance is invalid
	 */
	Tizen::Graphics::Dimension GetItemSize(void) const;

	/**
	 * Gets the size of the item.
	 *
	 * @since   2.1
	 *
	 * @return	The size of the item, @n
	 *			else (-1, -1) if the instance is invalid
	 */
	Tizen::Graphics::FloatDimension GetItemSizeF(void) const;

	/**
	 * Sets the number of item lines to be scrolled for the magnetic scroll of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]	scrollSize			The number of item lines for the magnetic scroll of %IconListView
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c scrollSize is out of range. @n
	 *									The specified @c scrollSize is less than @c 0 or greater than the item count shown along the scroll direction.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	If the @c scrollSize is set to @c 0, %IconListView does not use the magnetic scroll. The initial value is @c 0.
	 */
	result SetMagneticScrollSize(int scrollSize);

	/**
	 * Gets the number of item lines for the magnetic scroll of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	The number of item lines for the magnetic scroll of %IconListView, @n
	 *			else @c -1 if the instance is invalid
	 */
	int GetMagneticScrollSize(void) const;

	/**
	 * Gets the number of items to be displayed per axis of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	The number of items to be displayed per axis, @n
	 *			else @c -1 if the instance is invalid
	 * @remarks	The axis represents "row" when the scroll style is @c ICON_LIST_VIEW_SCROLLSDIRECTION_HORIZONTAL, while it represents "column" when the
	 *			scroll style is @c ICON_LIST_VIEW_SCROLLDIRECTION_VERTICAL.
	 */
	int GetItemCountPerAxis(void) const;

	/**
	 * Sets the items horizontal alignment of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]	alignment			The alignment of items
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The alignment of icon list view is not in the vertical scroll direction.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetItemLayoutHorizontalAlignment(HorizontalAlignment alignment);

	/**
	 * Sets the items vertical alignment of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in]	alignment			The alignment of items
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The alignment of icon list view is not in the horizontal scroll direction.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetItemLayoutVerticalAlignment(VerticalAlignment alignment);

	/**
	 * Gets the items horizontal alignment of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	The alignment of items, @n
	 *			else @c ALIGNMENT_LEFT if the instance is invalid
	 */
	HorizontalAlignment GetItemLayoutHorizontalAlignment(void) const;

	/**
	 * Gets the items vertical alignment of %IconListView.
	 *
	 * @since   2.0
	 *
	 * @return	The alignment of items, @n
	 *			else @c ALIGNMENT_TOP if the instance is invalid
	 */
	VerticalAlignment GetItemLayoutVerticalAlignment(void) const;

	/**
	 * Sets the item border style.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	borderStyle			An item border style
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	*/
	result SetItemBorderStyle(IconListViewItemBorderStyle borderStyle);

	/**
	 * Gets the item border style.
	 *
	 * @since	2.0
	 *
	 * @return	The item border style, @n
	 *			else @c ICON_LIST_VIEW_ITEM_BORDER_STYLE_NONE if an error occurs
	 */
	IconListViewItemBorderStyle GetItemBorderStyle(void) const;

	/**
	 * Sets the bitmap of the empty list.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	pBitmap				The bitmap of the empty list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetBitmapOfEmptyList(const Tizen::Graphics::Bitmap* pBitmap);

	/**
	 * Begins the reordering mode.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM			A system error has occurred.
	 * @see IIconListViewItemEventListener::OnIconListViewItemReordered()
	 */
	result BeginReorderingMode(void);

	/**
	 * Ends the reordering mode.
	 *
	 * @since 2.0
	 *
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM			A system error has occurred.
	 * @see IIconListViewItemEventListener::OnIconListViewItemReordered()
	 */
	result EndReorderingMode(void);

	/**
	 * Checks whether %IconListView is in reordering mode.
	 *
	 * @since 2.0
	 *
	 * @return  @c true if %IconListView is in reordering mode, @n
	 *          else @c false
	 */
	bool IsInReorderingMode(void) const;

	/**
	 * Sets the scroll input handling mode.
	 *
	 * @since 2.1
	 *
	 * @param[in] mode	The scroll input handling mode
	 * @see				GetScrollInputMode()
	 */
	void SetScrollInputMode(ScrollInputMode mode);

	/**
	 * Gets the scroll input handling mode.
	 *
	 * @since 2.1
	 *
	 * @return		The scroll input handling mode
	 * @see			SetScrollInputMode()
	 */
	ScrollInputMode GetScrollInputMode(void) const;

public:
	friend class _IconListViewImpl;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	IconListView(const IconListView& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	IconListView& operator =(const IconListView& rhs);

}; // IconListView

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ICON_LIST_VIEW_H_
