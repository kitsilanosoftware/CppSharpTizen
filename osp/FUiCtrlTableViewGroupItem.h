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
 * @file	FUiCtrlTableViewGroupItem.h
 * @brief	This is the header file for the %TableViewGroupItem class.
 *
 * This header file contains the declarations of the %TableViewGroupItem class and its helper classes.
 */

#ifndef _FUI_CTRL_TABLE_VIEW_GROUP_ITEM_H_
#define _FUI_CTRL_TABLE_VIEW_GROUP_ITEM_H_

#include <FUiCtrlTableViewItemBase.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
* @class	TableViewGroupItem
* @brief    This class defines common behavior of %TableViewGroupItem.
*
* @since 2.0
*
* The %TableViewGroupItem class displays a table view group item. The %TableViewGroupItem can have any layout of Controls or Containers as children.
*/

class _OSP_EXPORT_ TableViewGroupItem
	: public TableViewItemBase
{
public:
	/**
	* The object is not fully constructed after this constructor is called. @n
	* For full construction, the %Construct() method must be called right after calling this constructor.
	*
	* @since 2.0
	*/
	TableViewGroupItem(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since 2.0
	*/
	virtual ~TableViewGroupItem(void);

	/**
	* Initializes this instance of %TableViewGroupItem with the specified parameter.
	*
	* @since 2.0
	*
	* @return		An error code
	* @param[in]    itemSize            The size of the item
	* @exception    E_SUCCESS           The method is successful.
	* @exception    E_INVALID_ARG		A specified input parameter is invalid.
	*/
	result Construct(const Tizen::Graphics::Dimension& itemSize);

	/**
	* Initializes this instance of %TableViewGroupItem with the specified parameter.
	*
	* @since 2.0
	*
	* @return		An error code
	* @param[in]    layout              The layout for both of the portrait and landscape modes
	* @param[in]    itemSize            The size of the item
	* @exception    E_SUCCESS           The method is successful.
	* @exception    E_INVALID_ARG		A specified input parameter is invalid.
	*/
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::Dimension& itemSize);

	/**
	* Initializes this instance of %TableViewGroupItem with the specified parameter.
	*
	* @since 2.0
	*
	* @return		An error code
	* @param[in]    portraitLayout      The layout for portrait mode
	* @param[in]    landscapeLayout     The layout for landscape mode
	* @param[in]    itemSize            The size of the item
	* @exception    E_SUCCESS           The method is successful.
	* @exception    E_INVALID_ARG		A specified input parameter is invalid.
	*/
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, const Tizen::Graphics::Dimension& itemSize);

	/**
	* Initializes this instance of %TableViewGroupItem with the specified parameter.
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]    itemSize            The size of the item
	* @exception    E_SUCCESS           The method is successful.
	* @exception    E_INVALID_ARG		A specified input parameter is invalid.
	*/
	result Construct(const Tizen::Graphics::FloatDimension& itemSize);

	/**
	* Initializes this instance of %TableViewGroupItem with the specified parameter.
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]    layout              The layout for both of the portrait and landscape modes
	* @param[in]    itemSize            The size of the item
	* @exception    E_SUCCESS           The method is successful.
	* @exception    E_INVALID_ARG		A specified input parameter is invalid.
	*/
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::FloatDimension& itemSize);

	/**
	* Initializes this instance of %TableViewGroupItem with the specified parameter.
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]    portraitLayout      The layout for portrait mode
	* @param[in]    landscapeLayout     The layout for landscape mode
	* @param[in]    itemSize            The size of the item
	* @exception    E_SUCCESS           The method is successful.
	* @exception    E_INVALID_ARG		A specified input parameter is invalid.
	*/
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, const Tizen::Graphics::FloatDimension& itemSize);

private:
	friend class _TableViewItemImpl;

	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	TableViewGroupItem(const TableViewGroupItem& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	TableViewGroupItem& operator =(const TableViewGroupItem& rhs);
}; // TableViewGroupItem

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_TABLE_VIEW_GROUP_ITEM_H_
