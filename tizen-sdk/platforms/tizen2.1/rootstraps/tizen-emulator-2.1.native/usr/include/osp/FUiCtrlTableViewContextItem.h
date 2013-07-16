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
* @file FUiCtrlTableViewContextItem.h
* @brief This is the header file for the %TableViewContextItem class.
*
* This header file contains the declarations of the %TableViewContextItem class and its helper classes.
*/

#ifndef _FUI_CTRL_TABLE_VIEW_CONTEXT_ITEM_H_
#define _FUI_CTRL_TABLE_VIEW_CONTEXT_ITEM_H_

#include <FUiCtrlTableViewItemBase.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
* @class TableViewContextItem
* @brief This class defines common behavior for a %TableViewContextItem.
*
* @since 2.0
*
* The %TableViewContextItem class is a class which represents a context item for TableView.
* A context item is shown when a table view item is swept, if %TableViewContextItem is set to the table view item.
*
*/

class _OSP_EXPORT_ TableViewContextItem
	: public TableViewItemBase
{
public:
	/**
	* The object is not fully constructed after this constructor is called. @n
	* For full construction, the %Construct() method must be called right after calling this constructor.
	*
	* @since 2.0
	*/
	TableViewContextItem(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since 2.0
	*/
	virtual ~TableViewContextItem(void);

	/**
	* Initializes this instance of %TableViewContextItem with the specified parameter.
	*
	* @since 2.0
	*
	* @return  An error code
	* @param[in] itemSize          The size of the item
	* @exception E_SUCCESS         The method is successful.
	* @exception E_OUT_OF_MEMORY   The memory is insufficient.
	*/
	result Construct(const Tizen::Graphics::Dimension& itemSize);

	/**
	* Initializes this instance of %TableViewContextItem with the specified parameter.
	*
	* @since 2.1
	*
	* @return  An error code
	* @param[in] itemSize          The size of the item
	* @exception E_SUCCESS         The method is successful.
	* @exception E_OUT_OF_MEMORY   The memory is insufficient.
	*/
	result Construct(const Tizen::Graphics::FloatDimension& itemSize);

private:
	friend class _TableViewItemImpl;

	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	TableViewContextItem(const TableViewContextItem& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	TableViewContextItem& operator =(const TableViewContextItem& rhs);
}; // TableViewContextItem

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_TABLE_VIEW_CONTEXT_ITEM_H_
