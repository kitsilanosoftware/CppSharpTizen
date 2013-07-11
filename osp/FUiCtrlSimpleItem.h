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
 * @file	FUiCtrlSimpleItem.h
 * @brief	This is the header file for the %SimpleItem class.
 *
 * This header file contains the declarations of the %SimpleItem class and its helper classes.
 */

#ifndef _FUI_CTRL_SIMPLE_ITEM_H_
#define _FUI_CTRL_SIMPLE_ITEM_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FGrpBitmap.h>
#include <FGrpRectangle.h>
#include <FUiCtrlListItemBase.h>

namespace Tizen { namespace Ui { namespace Controls
{

class _SimpleItemImpl;

/**
 * @class	SimpleItem
 * @brief    This class defines the common behavior of a %SimpleItem.
 *
 * @since	2.0
 *
 * The %SimpleItem class displays a list item, which is the unit of handling a ListView or GroupedListView. It provides the default
 * formatting of the list items.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 *
 */

class _OSP_EXPORT_ SimpleItem
	: public ListItemBase
{
public:
	/**
	 * The object is not fully constructed after this constructor is
	 * called. For full construction, the Construct() method must be
	 * called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	SimpleItem(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~SimpleItem(void);

	/**
	 * Initializes this instance of %SimpleItem with the specified parameters.
	 *
	 * @since	2.0
	 *
	 * @return    An error code
	 * @param[in] itemSize          The size of the item
	 * @param[in] style             The style of Annex
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::Dimension& itemSize, ListAnnexStyle style);

	/**
	 * Sets the text string and bitmap image for %SimpleItem.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] text              The text string to add
	 * @param[in] pBitmap           The bitmap image to display
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result SetElement(const Tizen::Base::String& text, const Tizen::Graphics::Bitmap* pBitmap = null);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	SimpleItem(const SimpleItem& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	SimpleItem& operator =(const SimpleItem& rhs);
}; // SimpleItem

}}} // Tizen::Ui::Controls

#endif  // _FUI_CTRL_SIMPLE_ITEM_H_
