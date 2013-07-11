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
 * @file	FUiCtrlCustomItem.h
 * @brief	This is the header file for the %CustomItem class.
 *
 * This header file contains the declarations of the %CustomItem class and its helper classes.
 */

#ifndef _FUI_CTRL_CUSTOM_ITEM_H_
#define _FUI_CTRL_CUSTOM_ITEM_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FGrpBitmap.h>
#include <FGrpEnrichedText.h>
#include <FGrpRectangle.h>
#include <FUiCtrlControlsTypes.h>
#include <FUiCtrlICustomElement.h>
#include <FUiCtrlListItemBase.h>
#include <FUiCtrlListViewTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{

class _CustomItemImpl;

/**
 * @class	CustomItem
 * @brief    This class defines the common behavior for %CustomItem.
 *
 * @since	2.0
 *
 * The %CustomItem class displays a list item, which is the unit of handling a ListView or GroupedListView. It provides customized formatting of specific list items.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 *
 */

class _OSP_EXPORT_ CustomItem
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
	CustomItem(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~CustomItem(void);

	/**
	 * Initializes this instance of %CustomItem with the specified parameters.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] itemSize          The size of the item
	 * @param[in] style             The style of the annex
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::Dimension& itemSize, ListAnnexStyle style);

	/**
	 * Adds an instance of EnrichedText as an element to the %CustomItem control.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] rect              The bounds of the element
	 * @param[in] elementId         The element ID
	 * @param[in] text              The instance of EnrichedText
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result AddElement(const Tizen::Graphics::Rectangle& rect, int elementId, const Tizen::Graphics::EnrichedText& text);

	/**
	 * Adds the text as an element to the %CustomItem control.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] rect              The bounds of the element
	 * @param[in] elementId         The element ID
	 * @param[in] text              The text string to add
	 * @param[in] textSliding       Set to @c true to allow a long text to slide, @n
	 *                              else @c false
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @remarks	If the width of the specified @c text exceeds the width of the element and @c textSliding is set to @c true, the text slides
	 *          automatically when the user long-presses.
	 */
	result AddElement(const Tizen::Graphics::Rectangle& rect, int elementId, const Tizen::Base::String& text, bool textSliding = true);

	/**
	 * Adds the text as an element to the %CustomItem control.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] rect                  The bounds of the element
	 * @param[in] elementId             The element ID
	 * @param[in] text                  The text string to add
	 * @param[in] textSize              The size of the text
	 * @param[in] normalTextColor       The color of the text in the normal status
	 * @param[in] pressedTextColor	    The color of the text in the pressed status
	 * @param[in] highlightedTextColor  The color of the text in the highlighted status
	 * @param[in] textSliding           Set to @c true to allow a long text to slide, @n
	 *                                  else @c false
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_INVALID_ARG         A specified input parameter is invalid.
	 * @exception E_SYSTEM              A system error has occurred.
	 * @remarks  The default size of text is 38 on a WVGA screen, 22 on a HVGA screen and 20 on a WQVGA screen.
	 */
	result AddElement(const Tizen::Graphics::Rectangle& rect, int elementId, const Tizen::Base::String& text, int textSize, const Tizen::Graphics::Color& normalTextColor, const Tizen::Graphics::Color& pressedTextColor, const Tizen::Graphics::Color& highlightedTextColor, bool textSliding = true);

	/**
	 * Adds the bitmap image as an element to the %CustomItem control.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] rect                  The bounds of the element
	 * @param[in] elementId             The element ID
	 * @param[in] normalBitmap          The bitmap image displayed when the item is in normal status
	 * @param[in] pPressedBitmap        The bitmap image displayed when the item is pressed
	 * @param[in] pHighlightedBitmap    The bitmap image displayed when the item is highlighted
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_INVALID_ARG         A specified input parameter is invalid.
	 * @exception E_SYSTEM              A system error has occurred.
	 */
	result AddElement(const Tizen::Graphics::Rectangle& rect, int elementId, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pPressedBitmap = NULL, const Tizen::Graphics::Bitmap* pHighlightedBitmap = NULL);

	/**
	 * Adds the custom drawing element to the %CustomItem control.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @param[in] rect              The bounds of the element
	 * @param[in] elementId         The element ID
	 * @param[in] element           The custom element
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result AddElement(const Tizen::Graphics::Rectangle& rect, int elementId, const ICustomElement& element);

	/**
	 * Removes the element from the %CustomItem control.
	 *
	 * @since	2.0
	 *
	 * @return  An error code
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result RemoveAllElements(void);

	/**
	* Removes the element with the specified element ID.
	*
	* @since	2.0
	*
	* @return	An error code
	* @param[in] elementId			The element ID
	* @exception E_SUCCESS			The method is successful.
	* @exception E_INVALID_ARG		A specified input parameter is invalid.
	* @exception E_SYSTEM			A system error has occurred.
	*/
	result RemoveElement(int elementId);

	/**
	 * Sets the selection type of an element.
	 *
	 * @since	2.0
	 *
	 * @param[in] elementId         The element ID
	 * @param[in] enable            Set to @c true to make only the element selected when touched, @n
	 *                              else @c false
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG     A specified input parameter is invalid.
	 * @exception E_SYSTEM          A system error has occurred.
	 * @remarks	Based on the selection type of an element, the area within which the background color changes is different when an element is touched.
	 */
	result SetElementSelectionEnabled(int elementId, bool enable);

	/**
	 * Sets the horizontal alignment of text in the specified element.
	 *
	 * @since   2.0
	 *
	 * @param[in] elementId         The element ID
	 * @param[in] alignment			The horizontal alignment of text
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_INVALID_ARG         A specified input parameter is invalid.
	 * @exception E_INVALID_OPERATION   The specified element does not handle text.@n
	 *									The specified element does not contain text.
	 * @exception E_SYSTEM              A system error has occurred.
	 */
	result SetElementTextHorizontalAlignment(int elementId, HorizontalAlignment alignment);

	/**
	 * Sets the vertical alignment of text in the specified element.
	 *
	 * @since   2.0
	 *
	 * @param[in] elementId         The element ID
	 * @param[in] alignment			The vertical alignment of text
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_INVALID_ARG         A specified input parameter is invalid.
	 * @exception E_INVALID_OPERATION   The specified element does not handle text.@n
	 *									The specified element does not contain text.
	 * @exception E_SYSTEM              A system error has occurred.
	 */
	result SetElementTextVerticalAlignment(int elementId, VerticalAlignment alignment);

	/**
	 * Sets the auto-link mask.
	 *
	 * @since   2.0
	 *
	 * @return  An error code
	 * @param[in] elementId     The element ID
	 * @param[in] mask          The auto-link mask @n
	 *							Multiple link types can be combined using bitwise OR operator (see Tizen::Base::Utility::LinkType). @n
	 *							For more information, see <a href="../org.tizen.native.appprogramming/html/guide/ui/auto_link_detection.htm">AutoLink Detection</a>.
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_INVALID_ARG         A specified input parameter is invalid.
	 * @exception E_INVALID_OPERATION   The specified element does not handle text.
	 * @exception E_SYSTEM              A system error has occurred.
	 * @remarks	When @c mask is set to @c 0, the auto-link detection is disabled.
	 * @see Tizen::Base::Utility::LinkType
	 */
	result SetElementAutoLinkMask(int elementId, unsigned long mask);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	CustomItem(const CustomItem& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	CustomItem& operator =(const CustomItem& rhs);
}; // CustomItem

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_CUSTOM_ITEM_H_

