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
 * @file FUiCtrlTableViewItem.h
 * @brief This is the header file for the %TableViewItem class.
 *
 * This header file contains the declarations of the %TableViewItem class and its helper classes.
 */

#ifndef _FUI_CTRL_TABLE_VIEW_ITEM_H_
#define _FUI_CTRL_TABLE_VIEW_ITEM_H_

#include <FUiCtrlTableViewItemBase.h>

namespace Tizen { namespace Ui { namespace Controls
{
class TableViewContextItem;

/**
 * @class   TableViewItem
 * @brief   This class defines common behavior for a %TableViewItem.
 *
 * @since 2.0
 *
 * The %TableViewItem class is a base class which represents a table view item which is the unit of handling of TableView.
 *
 */

class _OSP_EXPORT_ TableViewItem
	: public TableViewItemBase
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. Hence, the Construct() method must be called after calling this constructor.
	 *
	 * @since 2.0
	 */
	TableViewItem(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~TableViewItem(void);

	/**
	 * Initializes this instance of %TableViewItem with the specified parameter.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] itemSize          The size of the item
	 * @param[in] style             The style of Annex
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Graphics::Dimension& itemSize, TableViewAnnexStyle style = TABLE_VIEW_ANNEX_STYLE_NORMAL);

	/**
	 * Initializes this instance of %TableViewItem with the specified parameter.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] layout            The layout for both of the portrait and landscape modes
	 * @param[in] itemSize          The size of the item
	 * @param[in] style             The style of Annex
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::Dimension& itemSize, TableViewAnnexStyle style = TABLE_VIEW_ANNEX_STYLE_NORMAL);

	/**
	 * Initializes this instance of %TableViewItem with the specified parameter.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] portraitLayout    The layout for portrait mode
	 * @param[in] landscapeLayout   The layout for landscape mode
	 * @param[in] itemSize          The size of the item
	 * @param[in] style             The style of Annex
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, const Tizen::Graphics::Dimension& itemSize, TableViewAnnexStyle style = TABLE_VIEW_ANNEX_STYLE_NORMAL);

	/**
	 * Sets context item that is displayed when an item is swept.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in] pItem             The object of TableViewContextItem
	 * @remarks  If context item is not set, TableView() does not display context item and an item sweep event is generated when an item is swept.
	 *           pItem must be deleted by applications when it is no longer used.
	 */
	void SetContextItem(const TableViewContextItem* pItem);

	/**
	 * Get the width of the annex area.
	 *
	 * @since 2.0
	 *
	 * @return  The width of the annex
	 * @param[in] style             The style of the annex
	 * @remarks  The width of the annex area is different among annex styles.
	 */
	static int GetAnnexWidth(TableViewAnnexStyle style);

private:
	friend class _TableViewItemImpl;

	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	TableViewItem(const TableViewItem& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	TableViewItem& operator =(const TableViewItem& rhs);
}; //TableViewItem

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_TABLE_VIEW_ITEM_H_
