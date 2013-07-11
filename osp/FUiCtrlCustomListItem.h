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
 * @file	FUiCtrlCustomListItem.h
 * @brief	This is the header file for the %CustomListItem class.
 *
 * This header file contains the declarations of the %CustomListItem class and its helper classes.
 */

#ifndef _FUI_CTRL_CUSTOM_LIST_ITEM_H_
#define _FUI_CTRL_CUSTOM_LIST_ITEM_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FUiCtrlICustomListElement.h>

namespace Tizen { namespace Ui { namespace Controls
{
class _CustomListItemImpl;
class CustomListItemFormat;
/**
 * @if OSPDEPREC
 * @class	  CustomListItem
 * @brief   <i> [Deprecated] </i> This class defines the common behavior of an item of the CustomList control.
 *
 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class.
 * @since		2.0
 *
 * The %CustomListItem class represents a custom list item which is the unit of
 * handling of a custom list. A custom list item is composed of one or more elements,
 * which can be texts and bitmaps. Custom drawable elements are also supported via
 * ICustomListElement. The value of the elements is set using %CustomListItem.
 *
 * Note that %CustomListItem needs to be created on a heap. CustomListItems will be deleted automatically
 * when the CustomList is destroyed. If you want to remove certain list items, you must use RemoveItemAt().
 *
 * Refer to CustomListItemFormat.
 *
 * @endif
 */
class _OSP_EXPORT_ CustomListItem
	: public Tizen::Base::Object
{
public:
	/**
	 * @if OSPDEPREC
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 *
	 * @since		2.0
	 * @endif
	 */
	CustomListItem(void);

	/**
	 * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since		2.0
	 * @endif
	 */
	virtual ~CustomListItem(void);

public:
	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %CustomListItem with the specified parameter.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since					2.0
	 *
	 * @return	An error code
	 * @param[in]	itemHeight			The height of %CustomListItem
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result Construct(int itemHeight);

	/**
	 * @if OSPDEPREC
	 * Sets the format of %CustomListItem.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since			2.0
	 *
	 * @param[in]	itemFormat		An instance of %CustomListItemFormat
	 * @remarks Do not delete @c itemFormat before the associated %CustomListItem is removed from %CustomList, because %CustomListItemFormat is constantly
	 *			used while %CustomListItem is added to CustomList.
	 * @endif
	 */
	void SetItemFormat(const CustomListItemFormat& itemFormat);

	/**
	 * Gets the format of %CustomListItem.
	 *
	 * @since			2.0
	 *
	 * @return	A pointer to CustomListItemFormat, @n
	 *			else @c null if a system error occurs
	 */
	const CustomListItemFormat* GetItemFormat(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the background bitmap image which is displayed when the item is focused.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since			2.0
	 *
	 * @param[in] bitmap		The background bitmap image
	 * @remarks  The specified bitmap is automatically scaled to the size of an associated item.
	 * @see SetNormalItemBackgroundBitmap()
	 * @endif
	 */
	void SetFocusedItemBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * @if OSPDEPREC
	 * Sets the background image of the item which is displayed when the item is in normal state.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since			2.0
	 *
	 * @param[in] bitmap	 The background bitmap image
	 * @remarks The specified bitmap is automatically scaled to the size of an+B6 associated item.
	 * @see SetFocusedItemBackgroudBitmap()
	 * @endif
	 */
	void SetNormalItemBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * @if OSPDEPREC
	 * Sets the highlighted background image on the rectangle of each list item.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since           2.0
	 *
	 * @param[in]   bitmap   The background image
	 * @remarks     When a user navigates the user interface using the directional keys, @n
	 *                  the selected UI control is highlighted and takes the focus.
	 * @endif
	 */

	void SetHighlightedItemBackgroundBitmap(const Tizen::Graphics::Bitmap& bitmap);

	/**
 	 * @if OSPDEPREC
	 * Sets the text of the element for %CustomListItem.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	elementId	The ID of the element
	 * @param[in] text            The text string to be added
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks		To display text in multi-lines or to denote the end of line use '\\n'.
	 * @endif
	 */
	result SetElement(int elementId, const Tizen::Base::String& text);

	/**
 	 * @if OSPDEPREC
	 * Sets the bitmap of the element for %CustomListItem.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in]	elementId	The ID of the element
	 * @param[in]	normalBitmap        The bitmap displayed when the item is in the normal state
	 * @param[in]   pFocusedBitmap  The bitmap displayed when the item is focused
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @endif
	 */
	result SetElement(int elementId, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pFocusedBitmap);


	/**
	 * @if OSPDEPREC
	 * Sets the bitmap of the element for %CustomListItem.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since        2.0
	 *
	 * @return     An error code
	 * @param[in]  elementId          The ID of the element
	 * @param[in]   normalBitmap        The bitmap displayed when the item is in the normal state
	 * @param[in]  pFocusedBitmap     The bitmap displayed when the item is selected
	 * @param[in]  pHighlightedBitmap The bitmap displayed when the item is highlighted
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @endif
	 */
	result SetElement(int elementId, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pFocusedBitmap, const Tizen::Graphics::Bitmap* pHighlightedBitmap);

	/**
 	 * @if OSPDEPREC
	 * Sets the custom element for %CustomListItem.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since					2.0
	 *
	 * @return		An error code
	 * @param[in]	elementId	 The ID of the element
	 * @param[in]	element			 The custom element
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     Do not delete @c element before the associated %CustomListItem is removed from CustomList, @n
	 *              as ICustomListElement is constantly used while %CustomListItem is added to %CustomList. @n
	 *            Call RefreshItem() to draw the custom element that has been set with this method.
	 * @endif
	 */
	result SetElement(int elementId, const ICustomListElement& element);

	/**
	 * @if OSPDEPREC
	 * Sets the element ID of the checkbox of %CustomListItem.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	elementId	 The ID of the element
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @endif
	 */
	result SetCheckBox(int elementId);

	/**
	 * @if OSPDEPREC
	 * Sets the percent value of %CustomListItem.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]   value       The percent value of %CustomListItem @n
	 *		             The valid range of integers is from @c 0 to @c 100
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception   E_SYSTEM	A system error has occurred.
	 * @endif
	 */
	result SetValue(int value);

	/**
	 * @if OSPDEPREC
	 * Gets the percentage value of %CustomListItem.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated   This class is deprecated. Instead of using this class, use CustomItem class
	 * @since			2.0
	 *
	 * @return		The percentage value, @n
	 *              else @c -1 if a system error occurs
	 * @endif
	 */
	int GetValue(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	CustomListItem(const CustomListItem& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	CustomListItem& operator =(const CustomListItem& rhs);

private:

	CustomListItemFormat* __pCustomListItemFormat;
	_CustomListItemImpl* __pCustomListItemImpl;

	friend class _CustomListImpl;
	friend class _CustomListItemImpl;
	friend class _ExpandableListImpl;
	friend class _SlidableListImpl;
	friend class _GroupedListImpl;
	friend class _SlidableGroupedListImpl;
	friend class _ListImpl;

	friend class _CustomListItemDataProvider;
	friend class _SlidableListItemProvider;
	friend class _ListBaseImpl;
	friend class _GroupedListItemDataProvider;
	friend class _ExpandableListItemDataProvider;
	friend class _SlidableGroupedListItemProvider;
	friend class _ListItemDataProvider;
}; //CustomListItem

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_CUSTOM_LIST_ITEM_H_
