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
* @file FUiCtrlTableViewItemBase.h
* @brief This is the header file for the %TableViewItemBase class.
*
* This header file contains the declarations of the %TableViewItemBase class and its helper classes.
*/

#ifndef _FUI_CTRL_TABLE_VIEW_ITEM_BASE_H_
#define _FUI_CTRL_TABLE_VIEW_ITEM_BASE_H_

#include <FOspConfig.h>
#include <FUiContainer.h>
#include <FUiCtrlTableViewTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @class TableViewItemBase
 * @brief    This class defines common behavior for a %TableViewItemBase.
 *
 * @since 2.0
 *
 * The %TableViewItemBase class is a base class which represents a table view item which is the unit of handling of TableView.
 *
 */

class _OSP_EXPORT_ TableViewItemBase
	: public Tizen::Ui::Container
{
public:
	/**
	 * Sets the background image of the item which is displayed when the item is in specified state.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] pBitmap           The background bitmap image
	 * @param[in] status            The item drawing state
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_OUT_OF_MEMORY          The memory is insufficient.
	 * @remarks The background bitmap has priority over the background color. When both the background bitmap and the background color are specified, only the bitmap is displayed.
	 */
	result SetBackgroundBitmap(const Tizen::Graphics::Bitmap* pBitmap, TableViewItemDrawingStatus status = TABLE_VIEW_ITEM_DRAWING_STATUS_NORMAL);

	/**
	 * Sets the background color of the item which is displayed when the item is in specified state.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] color             The background color
	 * @param[in] status            The item drawing state
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color, TableViewItemDrawingStatus status = TABLE_VIEW_ITEM_DRAWING_STATUS_NORMAL);

	/**
 	 * Gets the background color of the item which is displayed when the item is in the specified state.
	 *
	 * @since 2.0
	 *
	 * @return  The background color of the item
	 * @param[in] status            The item drawing state
	 *
	 * @remarks  If an error occurs, this method returns RGBA(0, 0, 0, 0).
	 * @see     SetBackgroundColor()
	 */
	Tizen::Graphics::Color GetBackgroundColor(TableViewItemDrawingStatus status = TABLE_VIEW_ITEM_DRAWING_STATUS_NORMAL) const;

	/**
	 * Enables or disables the individual selection of a control.
	 *
	 * @since 2.0
	 *
	 * @return        An error code
	 * @param[in] pControl          The child control to be selected individually.
	 * @param[in] enable            Set to @c true to enable the individual selection of a control, else @c false
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 */
	result SetIndividualSelectionEnabled(const Tizen::Ui::Control* pControl, bool enable);

	/**
	 * Returns whether the individual selection of a control is enabled or not.
	 *
	 * @since 2.0
	 *
	 * @return @c true if the individual selection of a control is enabled, else @c false
	 * @param[in] pControl          The target control.
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 */
	bool IsIndividualSelectionEnabled(const Tizen::Ui::Control* pControl);

protected:
	//
	// This class is constructible only as a subobject of a derived class.
	//
	// @since 2.0
	//
	TableViewItemBase(void);

	//
	// This class is destructible only as a subobject of a derived class.
	//
	// @since 2.0
	//
	virtual ~TableViewItemBase(void);

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The following method is reserved, and its name can be changed at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void TableViewItemBase_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The following method is reserved, and its name can be changed at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void TableViewItemBase_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The following method is reserved, and its name can be changed at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void TableViewItemBase_Reserved3(void) {}

private:
	friend class _TableViewItemImpl;

	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	TableViewItemBase(const TableViewItemBase& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	TableViewItemBase& operator =(const TableViewItemBase& rhs);
}; // TableViewItemBase

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_TABLE_VIEW_ITEM_BASE_H_
