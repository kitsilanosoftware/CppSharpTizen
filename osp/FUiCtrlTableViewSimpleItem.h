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
* @file FUiCtrlTableViewSimpleItem.h
* @brief This is the header file for the %TableViewSimpleItem class.
*
* This header file contains the declarations of the %TableViewSimpleItem class and its helper classes.
*/

#ifndef _FUI_CTRL_TABLE_VIEW_SIMPLE_ITEM_H_
#define _FUI_CTRL_TABLE_VIEW_SIMPLE_ITEM_H_

#include <FUiCtrlTableViewItem.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @class   TableViewSimpleItem
 * @brief   This class defines common behavior for a %TableViewSimpleItem.
 *
 * @since 2.0
 *
 * The %TableViewSimpleItem class is a class which represents a table view item which has one label and one bitmap.
 *
 */

class _OSP_EXPORT_ TableViewSimpleItem
	: public TableViewItem
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the %Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	TableViewSimpleItem(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~TableViewSimpleItem(void);

	/**
	 * Initializes this instance of %TableViewSimpleItem with the specified parameter.
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
	 * Initializes this instance of TableViewItem with the specified parameter.
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
	 * Initializes this instance of %TableViewSimpleItem with the specified parameter.
	 *
	 * @since 2.1
	 *
	 * @return  An error code
	 * @param[in] itemSize          The size of the item
	 * @param[in] style             The style of Annex
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Graphics::FloatDimension& itemSize, TableViewAnnexStyle style = TABLE_VIEW_ANNEX_STYLE_NORMAL);

	/**
	 * Initializes this instance of TableViewItem with the specified parameter.
	 *
	 * @since 2.1
	 *
	 * @return  An error code
	 * @param[in] layout            The layout for both of the portrait and landscape modes
	 * @param[in] itemSize          The size of the item
	 * @param[in] style             The style of Annex
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::FloatDimension& itemSize, TableViewAnnexStyle style = TABLE_VIEW_ANNEX_STYLE_NORMAL);

	/**
	 * Sets the text string and bitmap image for %TableViewSimpleItem.
	 *
	 * @since 2.0
	 *
	 * @return An error code
	 * @param[in] text                                         The text string to add
	 * @param[in] pBitmap                         The bitmap image to display
	 * @exception E_SUCCESS                                The method is successful.
	 * @exception E_OUT_OF_MEMORY   The memory is insufficient.
	 */
	result SetItemContents(const Tizen::Base::String& text, const Tizen::Graphics::Bitmap* pBitmap = null);

	/**
	 * Sets the color of the text.
	 *
	 * @since 2.0
	 *
	 * @return  An error code
	 * @param[in]   color               The text color
	 * @param[in]    status              The item drawing state
	 * @see     GetTextColor()
	 */
	void SetTextColor(const Tizen::Graphics::Color& color, TableViewItemDrawingStatus status = TABLE_VIEW_ITEM_DRAWING_STATUS_NORMAL);

	/**
	 * Gets the color of the text.
	 *
	 * @since 2.0
	 *
	 * @return        The text color,
	 * @param[in]    status                                   The item drawing state
	 * @see           SetTextColor()
	 */
	Tizen::Graphics::Color GetTextColor(TableViewItemDrawingStatus status = TABLE_VIEW_ITEM_DRAWING_STATUS_NORMAL) const;

	/**
	 * Sets the size of the text.
	 *
	 * @since 2.0
	 *
	 * @return        An error code
	 * @param[in]    size                The size of the text
	 * @exception    E_SUCCESS           The method is successful.
	 * @exception    E_INVALID_ARG       The given text size is less than 1.
	 * @see     GetTextSize()
	 */
	result SetTextSize(int size);

	/**
	 * Gets the size of the text.
	 *
	 * @since 2.0
	 *
	 * @return  The size of the text,
	 * @see     SetTextSize()
	 */
	int GetTextSize(void) const;

private:
	friend class _TableViewItemImpl;

	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	TableViewSimpleItem(const TableViewSimpleItem& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	TableViewSimpleItem& operator =(const TableViewSimpleItem& rhs);
}; // TableViewSimpleItem

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_TABLE_VIEW_SIMPLE_ITEM_H_
