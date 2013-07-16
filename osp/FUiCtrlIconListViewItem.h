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
 * @file	FUiCtrlIconListViewItem.h
 * @brief	This is the header file for the %IconListViewItem class.
 *
 * This header file contains the declarations of the %IconListViewItem class and its helper classes.
 */

#ifndef _FUI_CTRL_ICON_LIST_VIEW_ITEM_H_
#define _FUI_CTRL_ICON_LIST_VIEW_ITEM_H_

//includes
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FGrpBitmap.h>
#include <FUiCtrlControlsTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{

class IconListView;
class _IconListItemProviderAdaptor;
class _IconListViewItemImpl;

/**
 * @class	IconListViewItem
 * @brief   This class defines the common behavior of a %IconListViewItem control.
 *
 * @since	2.0
 *
 * The %IconListViewItem class displays an IconListView item. It comprises of bitmap images and text. The value is set using the %IconListView control.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 */
class _OSP_EXPORT_ IconListViewItem
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct(const Tizen::Graphics::Bitmap&, const Tizen::Base::String*, const Tizen::Graphics::Bitmap*, const Tizen::Graphics::Bitmap*) method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	IconListViewItem(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~IconListViewItem(void);

public:
	/**
	 * Initializes this instance of %IconListViewItem with the specified parameters.
	 *
	 * @since   2.0
	 *
	 * @return	An error code
	 * @param[in] bitmap				The default bitmap image
	 * @param[in] pText					The item text
	 * @param[in] pSelectedBitmap		The displayed bitmap image when an item is selected
	 * @param[in] pHighlightedBitmap	The displayed bitmap image when an item is highlighted
	 * @exception E_SUCCESS				The method is successful.
	 * @exception E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks	If @c pSelectedBitmap or @c pHighlightedBitmap is @c null, @c bitmap plays its role.
	 */
	result Construct(const Tizen::Graphics::Bitmap& bitmap, const Tizen::Base::String* pText = null, const Tizen::Graphics::Bitmap* pSelectedBitmap = null, const Tizen::Graphics::Bitmap* pHighlightedBitmap = null);

	/**
	 * Sets the overlay bitmap image as an element to the item.
	 *
	 * @since 2.0
	 *
	 * @return     An error code
	 * @param[in] overlayBitmapId  		The overlay bitmap ID
	 * @param[in] pOverlayBitmap       	The pointer of the overlay bitmap image
	 * @param[in] horizontalAlignment 	The horizontal alignment of overlay bitmap
	 * @param[in] verticalAlignment   	The vertical alignment of overlay bitmap
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_INVALID_ARG         A specified input parameter is invalid.
	 * @exception E_SYSTEM              A system error has occurred.
	 * @remarks	When @c pOverlayBitmap is set as @c null, the overlay bitmap of the specified location will be erased.
	 */
	result SetOverlayBitmap(int overlayBitmapId, const Tizen::Graphics::Bitmap* pOverlayBitmap, HorizontalAlignment horizontalAlignment, VerticalAlignment verticalAlignment);

private:
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	IconListViewItem(const IconListViewItem& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	IconListViewItem& operator =(const IconListViewItem& rhs);

private:
	friend class IconListView;
	friend class _IconListItemProviderAdaptor;
	friend class _IconListViewItemImpl;

	// This value is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	_IconListViewItemImpl* __pImpl;
}; //IconListViewItem

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ICON_LIST_VIEW_ITEM_H_
