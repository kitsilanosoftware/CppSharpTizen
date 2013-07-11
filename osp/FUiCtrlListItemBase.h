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
 * @file	FUiCtrlListItemBase.h
 * @brief	This is the header file for the %ListItemBase class.
 *
 * This header file contains the declarations of the %ListItemBase class and its helper classes.
 */

#ifndef _FUI_CTRL_LIST_ITEM_BASE_H_
#define _FUI_CTRL_LIST_ITEM_BASE_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FGrpBitmap.h>
#include <FGrpRectangle.h>
#include <FUiCtrlListContextItem.h>
#include <FUiCtrlListViewTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{

class _ListItemBaseImpl;

/**
 * @class   ListItemBase
 * @brief   This class defines common behavior for a %ListItemBase.
 *
 * @since   2.0
 *
 * The %ListItemBase class is a base class, which represents a list item which is the unit of handling of the ListView or
 * GroupedListView classes.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 */

class _OSP_EXPORT_ ListItemBase
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~ListItemBase(void);

	/**
	 * Sets the background image of the item which is displayed when the item is in specified state.
	 *
	 * @since   2.0
	 *
	 * @return  An error code
	 * @param[in] status            The item drawing state
	 * @param[in] pBitmap           The background bitmap image
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @remarks	The background bitmap has priority over the background color. When both the background bitmap and the background color are specified,
	 *			only the bitmap is displayed.
	 */
	result SetBackgroundBitmap(ListItemDrawingStatus status, const Tizen::Graphics::Bitmap* pBitmap);

	/**
	 * Sets the background color of the item which is displayed when the item is in specified state.
	 *
	 * @since   2.0
	 *
	 * @return  An error code
	 * @param[in] status            The item drawing state
	 * @param[in] color             The background color
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @remarks 	The background bitmap has priority over the background color. When both the background bitmap and the background color are specified, only the bitmap is displayed. @n
	 *			The background color of the item is not applied when the item is inserted into the GroupedListView of section style.
	 */
	result SetBackgroundColor(ListItemDrawingStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Gets the background color of the item that is displayed when the item is in the specified state.
	 *
	 * @since   2.0
	 *
	 * @return  The background color of the item
	 * @param[in] status        The item drawing state, @n
	 *							else RGBA(0, 0, 0, 0) if an error has occurs
	 * @see     SetBackgroundColor()
	 */
	Tizen::Graphics::Color GetBackgroundColor(ListItemDrawingStatus status) const;

	/**
	 * Sets ContextItem that is displayed when an item is swept.
	 *
	 * @since   2.0
	 *
	 * @return  An error code
	 * @param[in] pItem             The %ListContextItem instance
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @remarks  If the context item is not set, ListView() or GroupedListView() does not display the context item and an item sweep event is generated when an
	 *			item is swept. @n
	 *          The specified @c pItem should be deleted by the applications when it is no longer used.
	 */
	result SetContextItem(const ListContextItem* pItem);

	/**
	 * Sets the description text.
	 *
	 * @since   2.0
	 *
	 * @return  An error code
	 * @param[in] text              Description text
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetDescriptionText(const Tizen::Base::String& text);

	/**
	 * Sets the color of the description text.
	 *
	 * @since   2.0
	 *
	 * @return  An error code
	 * @param[in] color             The color of the description text
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetDescriptionTextColor(const Tizen::Graphics::Color& color);

	/**
	 * Sets the progress value of a list item.
	 *
	 * @since   2.0
	 *
	 * @return  An error code
	 * @param[in] value             The progress value of the list item @n
	 *                              The valid values are integers from @c 0 to @c 100.
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetProgressValue(int value);

	/**
	 * Sets the margin of the progress bar.
	 *
	 * @since   2.0
	 *
	 * @return  An error code
	 * @param[in] leftMargin        The left margin of the progress bar
	 * @param[in] rightMargin       The right margin of the progress bar
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetProgressMargins(int leftMargin, int rightMargin);

	/**
	 * Gets the width of the annex area.
	 *
	 * @since	2.0
	 *
	 * @return  The width of the annex
	 * @param[in] style             The style of the annex
	 * @remarks  The width of the annex area is different among annex styles.
	 */
	static int GetAnnexWidth(ListAnnexStyle style);

protected:
	friend class _ListItemBaseImpl;

protected:
	//
	// This default constructor is intentionally declared as private so that only the platform can create an instance.
	// @since	2.0
	//
	ListItemBase(void);

	//
	// Initializes this instance of ListItem with the specified parameter.
	//
	// @since   2.0
	//
	// @return  An error code
	//
	// @param[in] itemSize          The size of the item
	// @param[in] style             The style of Annex
	// @exception E_SUCCESS         The method is successful.
	// @exception E_SYSTEM          A system error has occurred.
	//
	result Construct(const Tizen::Graphics::Dimension& itemSize, ListAnnexStyle style);

	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void ListItemBase_Reserved1(void) {}
	virtual void ListItemBase_Reserved2(void) {}
	virtual void ListItemBase_Reserved3(void) {}

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	ListItemBase(const ListItemBase& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	ListItemBase& operator =(const ListItemBase& rhs);

protected:
	_ListItemBaseImpl* _pImpl;
}; // ListItemBase

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_LIST_ITEM_BASE_H_
