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
 * @file	FUiCtrlCustomListItemFormat.h
 * @brief	This is the header file for the %CustomListItemFormat class.
 *
 * This header file contains the declarations of the %CustomListItemFormat class and its helper classes.
 */

#ifndef _FUI_CTRL_CUSTOM_LIST_ITEM_FORMAT_H_
#define _FUI_CTRL_CUSTOM_LIST_ITEM_FORMAT_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @if OSPDEPREC
 * @class	CustomListItemFormat
 * @brief		<i> [Deprecated] </i> This class defines the common behavior of an item format of a CustomList control.
 *
 * @deprecated	This class is deprecated. There is no need to use this class.
 * @since		2.0
 *
 * The %CustomListItemFormat class defines the common behavior of an item format of a CustomList control.
 * A custom list item is composed of elements, which can be texts and bitmaps.
 * A custom list item format determines the configuration of elements of a list item
 * and the position and the size of a custom list item.
 *
 * Note that %CustomListItemFormat needs to be created on a heap and it must be
 * deleted explicitly after use. However, CustomListItem must
 * be manually deleted because items are removed from memory by the List when
 * it is destroyed.
 *
 * Refer to CustomListItem.
 * @endif
 */
class _OSP_EXPORT_ CustomListItemFormat
	: public Tizen::Base::Object
{
public:
	/**
	 * @if OSPDEPREC
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the CustomListItemFormat::Construct() method must be called right after calling this constructor.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since		2.0
	 * @endif
	 */
	CustomListItemFormat(void);

	/**
	 * @if OSPDEPREC
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since		2.0
	 * @endif
	 */
	virtual ~CustomListItemFormat(void);

public:
	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %CustomListItemFormat.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @endif
	 */
	result Construct(void);

	/**
	 * @if OSPDEPREC
	 * Adds the %CustomListElement with bounds equal to @c rect.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	elementId	 The ID of the element
	 * @param[in]	rect	The bounds of the element
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @endif
	 */
	result AddElement(int elementId, const Tizen::Graphics::Rectangle& rect);

	/**
	 * @if OSPDEPREC
	 * Adds the %CustomListElement with bounds equal to @c rect and size of the text @c textSize.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	elementId		The ID of the element
	 * @param[in]	rect			The bounds of the element
	 * @param[in]	textSize		The size of the text
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @endif
	 */
	result AddElement(int elementId, const Tizen::Graphics::Rectangle& rect, int textSize);

	/**
	 * @if OSPDEPREC
	 * Adds the %CustomListElement with bounds equal to @c rect, specifying the size of text and the color of text.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in] elementId          The ID of the element
	 * @param[in] rect               The bounds of the element
	 * @param[in] textSize           The size of the text
	 * @param[in] normalTextColor    The color of the text in the normal status
	 * @param[in] focusedTextColor   The color of the text in the focused status
	 * @exception	E_SUCCESS          The method is successful.
	 * @exception	E_SYSTEM           A system error has occurred.
	 * @endif
	 */
	result AddElement(int elementId, const Tizen::Graphics::Rectangle& rect, int textSize, const Tizen::Graphics::Color& normalTextColor, const Tizen::Graphics::Color& focusedTextColor);

	/**
	 * @if OSPDEPREC
	 * Adds the %CustomListElement with bounds equal to @c rect, specifying the size of text and the color of text.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in] elementId              The ID of the element
	 * @param[in] rect                   The bounds of the element
	 * @param[in] textSize               The size of the text
	 * @param[in] normalTextColor        The color of the text in the normal status
	 * @param[in] focusedTextColor       The color of the text in the focused status
	 * @param[in] highlightedTextColor   The color of the text in the highlighted status
	 * @exception   E_SUCCESS              The method is successful.
	 * @exception   E_SYSTEM               A system error has occurred.
	 * @endif
	 */
	result AddElement(int elementId, const Tizen::Graphics::Rectangle& rect, int textSize, const Tizen::Graphics::Color& normalTextColor, const Tizen::Graphics::Color& focusedTextColor, const Tizen::Graphics::Color& highlightedTextColor);

	/**
	 * @if OSPDEPREC
	 * Gets the position and size of the element.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since			2.0
	 *
	 * @return		The bounds of the element, @n
	 *				else a rectangle of (0, 0, -1, -1) if there is no element matching the specified ID
	 * @param[in]	elementId	 The ID of the element
	 * @endif
	 */
	Tizen::Graphics::Rectangle GetElement(int elementId) const;

	/**
	 * @if OSPDEPREC
	 * Gets the ID of the first element.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since		2.0
	 *
	 * @return      The ID of the first element, @n
	 *              else @c -1 if a system error occurs
	 * @endif
	 */
	int GetFirstElementId(void) const;

	/**
 	 * @if OSPDEPREC
	 * Gets the ID of the next element of the specified element.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since		2.0
	 *
	 * @return      The ID of the next element of the specified element, @n
	 *              else @c -1 if there is no element next to the element specified by @c elementId
	 * @param[in] elementId		The ID of the element
	 * @endif
	 */
	int GetNextElementId(int elementId) const;

	/**
	 * @if OSPDEPREC
	 * Gets the ID of the first element of all enabled items.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since		2.0
	 *
	 * @return		The ID of the first enabled element, @n
	 *				else @c -1 if no element is enabled
 	 * @endif
	 */
	int GetFirstEnabledElementId(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the ID of the next enabled element after the specified element.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since		2.0
	 *
	 * @return		The ID of the next enabled element, @n
	 *				else @c -1 if no element after the specified element is enabled
	 * @param[in] elementId		The ID of the element
	 * @endif
	 */
	int GetNextEnabledElementId(int elementId) const;

	/**
	 * @if OSPDEPREC
	 * Gets the ID of the previous enabled element ID of the specified element.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since		2.0
	 *
	 * @return		The ID of the previous enabled element, @n
	 *				else @c -1 if no element before the specified element is enabled
	 * @param[in] elementId		The ID of the element
	 * @endif
	 */
	int GetPreviousEnabledElementId(int elementId) const;

	/**
	 * @if OSPDEPREC
	 * Sets the event status for the specified element.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since			2.0
	 *
	 * @param[in] elementId		The ID of the element
	 * @param[in]   enable          Set to @c true to allow the specified element to handle the events, @n
	 *                              else @c false
	 * @endif
	 */
	void SetElementEventEnabled(int elementId, bool enable);

	/**
	 * @if OSPDEPREC
	 * Checks whether the event status is enabled for the specified element.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated. There is no need to use this class.
	 * @since			2.0
	 *
	 * @return		@c true if the event status is enabled, @n
	 *				else @c false
	 * @param[in] elementId		The ID of the element
	 * @endif
	 */
	bool IsElementEventEnabled(int elementId);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	CustomListItemFormat(const CustomListItemFormat& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	CustomListItemFormat& operator =(const CustomListItemFormat& rhs);

private:

	class _CustomListItemFormatImpl* __pCustomListItemFormatImpl;

	friend class _CustomListItemImpl;
	friend class _CustomListImpl;
	friend class _ExpandableListImpl;
	friend class _SlidableListImpl;
	friend class _GroupedListImpl;
	friend class _SlidableGroupedListImpl;
}; //CustomListItemFormat

}}} //Tizen::Ui::Controls

#endif // _FUI_CTRL_CUSTOM_LIST_ITEM_FORMAT_H_
