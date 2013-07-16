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
* @file FUiCtrlTableViewSimpleGroupItem.h
* @brief This is the header file for the %TableViewSimpleGroupItem class.
*
* This header file contains the declarations of the %TableViewSimpleGroupItem class and its helper classes.
*/

#ifndef _FUI_CTRL_TABLE_VIEW_SIMPLE_GROUP_ITEM_H_
#define _FUI_CTRL_TABLE_VIEW_SIMPLE_GROUP_ITEM_H_

#include <FUiCtrlTableViewGroupItem.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
* @class	TableViewSimpleGroupItem
* @brief    This class defines common behavior of %TableViewSimpleGroupItem.
*
* @since 2.0
*
* The %TableViewSimpleGroupItem class displays a table view group item.
* The basic layout of the %TableViewSimpleGroupItem instance is text and a bitmap arranged horizontally in one line. The bitmap can be omitted while text must be given.
*/

class _OSP_EXPORT_ TableViewSimpleGroupItem
	: public TableViewGroupItem
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	TableViewSimpleGroupItem(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~TableViewSimpleGroupItem(void);

	/**
	 * Initializes this instance of %TableViewSimpleGroupItem with the specified parameter.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	itemSize            The size of the item
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Graphics::Dimension& itemSize);

	/**
	 * Initializes this instance of %TableViewSimpleGroupItem with the specified parameter.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	layout              The layout for both of the portrait and landscape modes
	 * @param[in]	itemSize            The size of the item
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::Dimension& itemSize);

	/**
	 * Initializes this instance of %TableViewSimpleGroupItem with the specified parameter.
	 *
	 * @since 2.1
	 *
	 * @return		An error code
	 * @param[in]	itemSize            The size of the item
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Graphics::FloatDimension& itemSize);

	/**
	 * Initializes this instance of %TableViewSimpleGroupItem with the specified parameter.
	 *
	 * @since 2.1
	 *
	 * @return		An error code
	 * @param[in]	layout              The layout for both of the portrait and landscape modes
	 * @param[in]	itemSize            The size of the item
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::FloatDimension& itemSize);

	/**
	 * Sets the text string and bitmap image for %TableViewSimpleGroupItem.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	text				The text string to add
	 * @param[in]	pBitmap				The bitmap image to display
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result SetItemContents(const Tizen::Base::String& text, const Tizen::Graphics::Bitmap* pBitmap = null);

	/**
	 * Sets the color of the text.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	color				The text color
	 * @param[in]	status				The item drawing state
	 * @exception	 E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @see			GetTextColor()
	 */
	result SetTextColor(const Tizen::Graphics::Color& color, TableViewItemDrawingStatus status = TABLE_VIEW_ITEM_DRAWING_STATUS_NORMAL);

	/**
	 * Gets the color of the text.
	 *
	 * @since 2.0
	 *
	 * @return		The text color
	 * @param[in]	status				The item drawing state
	 * @see			SetTextColor()
	 */
	Tizen::Graphics::Color GetTextColor(TableViewItemDrawingStatus status = TABLE_VIEW_ITEM_DRAWING_STATUS_NORMAL) const;

	/**
	 * Sets the size of the text.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	size                The size of the text
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG       The specified input parameter is invalid.
	 * @see     GetTextSize()
	 */
	result SetTextSize(int size);

	/**
	 * Gets the size of the text.
	 *
	 * @since 2.0
	 *
	 * @return  The size of the text
	 * @see     SetTextSize()
	 */
	int GetTextSize(void) const;

private:
	friend class _TableViewItemImpl;

	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	TableViewSimpleGroupItem(const TableViewSimpleGroupItem& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	TableViewSimpleGroupItem& operator =(const TableViewSimpleGroupItem& rhs);
}; // TableViewSimpleGroupItem

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_TABLE_VIEW_SIMPLE_GROUP_ITEM_H_
