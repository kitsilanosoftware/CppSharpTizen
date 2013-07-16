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
 * @file    FUiCtrlFooter.h
 * @brief	This is the header file for the %Footer class.
 *
 * This header file contains the declarations of the %Footer class.
 */

#ifndef _FUI_CTRL_FOOTER_H_
#define _FUI_CTRL_FOOTER_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FGrpBitmap.h>
#include <FGrpColor.h>
#include <FGrpRectangle.h>
#include <FUiControl.h>
#include <FUiIActionEventListener.h>
#include <FUiCtrlButtonItem.h>
#include <FUiCtrlFooterItem.h>
#include <FUiCtrlForm.h>


namespace Tizen { namespace Ui { namespace Controls
{
class _FooterImpl;
/**
 * @enum	FooterStyle
 *
 * Defines the possible styles of a %Footer control.
 *
 * @since	2.0
 */
enum FooterStyle
{
	FOOTER_STYLE_BUTTON_TEXT,   		/**< The text button style */
	FOOTER_STYLE_BUTTON_ICON,     	  	/**< The icon button style */
	FOOTER_STYLE_BUTTON_ICON_TEXT,    	/**< The icon and text button style */
	FOOTER_STYLE_SEGMENTED_TEXT,   		/**< The text segmented style */
	FOOTER_STYLE_SEGMENTED_ICON,   		/**< The icon segmented style */
    FOOTER_STYLE_SEGMENTED_ICON_TEXT, 	/**< The icon and text segmented style */
	FOOTER_STYLE_TAB               		/**< The tab style */
};

/**
 * @class   Footer
 * @brief	This class is an implementation of a %Footer control.
 *
 * @since   2.0
 *
 * The %Footer class displays a multi-purpose area at the bottom of the screen. It is used to switch between different application
 * "views", or to host buttons for performing user-defined actions.
 *
 *For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_footer.htm">Footer</a>.
 *
 *The following examples demonstrate how to use the %Footer class.
 * - Constructing a footer
 * When creating a %Form, specify the FORM_STYLE_FOOTER parameter in the Form::Construct() method.
 *
 * @code
 * // Initializes
 * bool
 * TestForm::Initialize(void)
 * {
 *      Construct(FORM_STYLE_NORMAL | FORM_STYLE_INDICATOR | FORM_STYLE_FOOTER);
 * }
 * @endcode
 *
 * - Using the footer
 * Gets the footer with the GetFooter() method, and sets the footer style
 *
 * @code
 * bool
 * TestForm::Initialize(void)
 * {
 *      Footer* pFooter = GetFooter();
 *      pFooter->SetStyle(FOOTER_STYLE_SEGMENTED_TEXT);
 * }
 * @endcode
 *
 * - Adding items to the footer:
 * Adds FooterItems or ButtonItems according to the footer style. The action ID registered in the Construct() method is notified
 * when items are touched.
 *
 * @code
 *  bool
 * TestForm::Initialize(void)
 * {
 *      FooterItem footerItem;
 *      footerItem.Construct(ID_FOOTER_ITEM);
 *      footerItem.SetText("FooterItem");
 *
 *      pFooter->AddItem(footerItem);
 *
 *      ButtonItem buttonItem;
 *      buttonItem.Construct(BUTTON_ITEM_STYLE_ICON, ID_HEADER_BUTTON);
 *      buttonItem.SetIcon(BUTTON_ITEM_STATUS_NORMAL, __pBitmap);
 *
 *      pFooter->SetButton(BUTTON_POSITION_LEFT, buttonItem);
 *
 * }
 * @endcode
 *
 * -Using the back button
 * The image of back button is internally set by UI framework.
 *
 * @code
 * bool
 * TestForm::Initialize(void)
 * {
 *      pFooter->SetBackButton();
 * }
 * @endcode
 */
class _OSP_EXPORT_ Footer
	: public Tizen::Ui::Control
{
public:
	/**
	 * Adds the specified footer item.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   item                The footer item to add
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_MAX_EXCEEDED      The number of items has exceeded the maximum limit.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid. @n
	 *									The specified item is not constructed.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks
	 *			- The %Footer control does not throw any exception even though the same action ID is assigned to multiple items. @n
	 *			However, the content of the specified item is copied to the %Footer control.
	 *			- Depending on the style of the %Footer control, several types of items can be added or inserted.
	 */
	result AddItem(const FooterItem& item);


	/**
	 * Inserts the footer item at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   itemIndex           The index where the item must be inserted
	 * @param[in]   item                The footer item object to insert
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_MAX_EXCEEDED      The number of items has exceeded the maximum limit.
	 * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the data structure. @n
	 *									The index is greater than or equal to the number of elements or less than @c 0.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid. @n
	 *									The specified item is not constructed.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks
	 *			- The %Footer control does not throw any exception even though the same action ID is assigned to multiple items. @n
	 *			However, the content of the specified item is copied to the %Footer control.
	 *			- Depending on the style of the %Footer control, several types of items can be added or inserted.
	 */
	result InsertItemAt(int itemIndex, const FooterItem& item);


	/**
	 * Checks whether a button item is set at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the button item is set at the specified position, @n
	 *				else @c false
	 * @param[in]   position            The position of the button item
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsButtonSet(ButtonPosition position) const;


	/**
	 * Checks whether the back button item is set.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the back button item is set, @n
	 *				else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsBackButtonSet(void) const;


	/**
	 * Checks whether the tab edit mode is enabled.
	 *
	 * @since		2.0
	 *
	 * @return      @c true if the tab edit mode is set, @n
	 *				else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 */
	bool IsTabEditModeEnabled(void) const;


	/**
	 * Gets the color of the button item for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return      The color of the button item, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]   status              The status of the button item
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetButtonColor()
	 */
	Tizen::Graphics::Color GetButtonColor(ButtonItemStatus status) const;


	/**
	 * Gets the text color of the button item for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return      The text color of the button item, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]   status              The status of the button item
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetButtonTextColor()
	 */
	Tizen::Graphics::Color GetButtonTextColor(ButtonItemStatus status) const;


	/**
	 * Gets the state of the specified button item.
	 *
	 * @since		2.0
	 *
	 * @return      The state of the button item at the specified position
	 * @param[in]   position			The position of the button item
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
	 *									There is no button set at the specified position.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	ButtonItemStatus GetButtonStatus(ButtonPosition position) const;


	/**
	 * Gets the state of the back button.
	 *
	 * @since       2.0
	 *
	 * @return      The state of the back button, @n
	 *				else @c BUTTON_ITEM_STATUS_NORMAL if an error occurs.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
	 *									The back button is not set.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	ButtonItemStatus GetBackButtonStatus(void) const;


	/**
	 * Gets the color of the footer item for the specified item state.
	 *
	 * @since		2.0
	 *
	 * @return      The color of the item, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]   status    			The item status
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 * @see         SetItemColor()
	 */
	Tizen::Graphics::Color GetItemColor(FooterItemStatus status) const;


	/**
	 * Gets the number of footer items.
	 *
	 * @since		2.0
	 *
	 * @return      The number of footer items, @n
	 *              else @c -1 if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetItemCount(void) const;


	/**
	 * Gets the state of the specified footer item.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   itemIndex         	The index of the item
	 * @param[out]  status            	The state of the item at the specified index
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the data structure. @n
	 *									The index is greater than or equal to the number of elements or less than zero.
	 */
	result GetItemStatus(int itemIndex, FooterItemStatus& status) const;


	/**
	 * Gets the text color of the footer item for the specified item state.
	 *
	 * @since		2.0
	 *
	 * @return      The text color of the item, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]   status              The item status
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetItemTextColor(FooterItemStatus status) const;


	/**
	 * Gets the style of the %Footer control.
	 *
	 * @since		2.0
	 *
	 * @return      The footer style, @n
	 *				else @c FOOTER_STYLE_BUTTON_TEXT if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	FooterStyle GetStyle(void) const;


	/**
	 * Gets the index of the currently selected item.
	 *
	 * @since		2.0
	 *
	 * @return      The selected item index,@n
	 *              else @c -1 if an error occurs
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The operation is not supported when the style of the %Footer control is
	 *										::FOOTER_STYLE_BUTTON_TEXT, ::FOOTER_STYLE_BUTTON_ICON
	 *										or ::FOOTER_STYLE_BUTTON_ICON_TEXT.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetSelectedItemIndex(void) const;


	/**
	 * Gets the color of the footer.
	 *
	 * @since		2.0
	 *
	 * @return      The color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetColor(void) const;


	/**
	 * Removes all the button items.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks		The back button will be also removed.
	 */
	result RemoveAllButtons(void);


	/**
	 * Removes the button item at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   position        The position of the button item to remove
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     If no button item is set at the specified position, the method will return @c E_SUCCESS.
	 */
	result RemoveButtonAt(ButtonPosition position);


	/**
	 * Removes the back button item.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     If the back button item is not set, the method will return @c E_SUCCESS.
	 */
	result RemoveBackButton(void);


	/**
	 * Removes all the footer items.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The left, right, and back button items are not removed.
	 */
	result RemoveAllItems(void);


	/**
	 * Removes the item at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   itemIndex			The index of the item to remove
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure. @n
	 *									The index is greater than or equal to the number of elements or less than @c 0.
	 * @exception   E_SYSTEM			A system error has occurred.
	 */
	result RemoveItemAt(int itemIndex);


	/**
	 * Sets the background bitmap image.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   pBitmap              The background image
	 * @exception   E_SUCCESS            The method is successful.
	 * @exception   E_SYSTEM             A system error has occurred.
	 */
	result SetBackgroundBitmap(const Tizen::Graphics::Bitmap* pBitmap);


	/**
	 * Sets the button item at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   position                	The position at which to set the specified button item.
	 * @param[in]   button                      The button item to set
	 * @exception   E_SUCCESS                   The method is successful.
	 * @exception   E_INVALID_ARG          	 	A specified input parameter is invalid. @n
	 *									        The specified item is not constructed.
	 * @exception	E_INVALID_OPERATION			The current state of the instance prohibits the execution of the specified operation.@n
	 *											There are more than 2 footer items.
	 * @exception   E_UNSUPPORTED_OPERATION     The operation is not supported when the style of the %Footer control is ::FOOTER_STYLE_TAB.
	 * @exception   E_SYSTEM                    A system error has occurred.
	 * @remarks	If there is an existing button item at the specified position, it is replaced with the new item.
	 *              However, the contents of the specified item are copied to the %Footer control.
	 */
	result SetButton(ButtonPosition position, const ButtonItem& button);


	/**
	 * Sets the button item color for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	status          The status of the button item
	 * @param[in]	color           The button item color to set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @see         GetButtonColor()
	 */
	result SetButtonColor(ButtonItemStatus status, const Tizen::Graphics::Color& color);


	/**
	 * Enables or disables the button item at the specified position.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   position             	The button item position
	 * @param[in]   enable                  Set to @c true to enable the specified button item, @n
	 *										else @c false
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_OPERATION  	The current state of the instance prohibits the execution of the specified operation. @n
	 *									    There is no button set at the specified position.
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result SetButtonEnabled(ButtonPosition position, bool enable);


	/**
	 * Enables or disables the back button.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   enable                  Set to @c true to enable the back button, @n
	 *										else @c false
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_OPERATION  	The current state of the instance prohibits the execution of the specified operation. @n
	 *									    The back button item is not set.
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result SetBackButtonEnabled(bool enable);


	/**
	 * Sets the button item text color for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   status          The status of the button item
	 * @param[in]   color           The button item text color to set
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @see         GetButtonTextColor()
	 */
	result SetButtonTextColor(ButtonItemStatus status, const Tizen::Graphics::Color& color);

	/**
	 * Sets the badge icon of the specified ButtonItem.
	 *
	 * @since   	2.0
	 *
	 * @return   	An error code
	 * @param[in]   position      				The button item position
	 * @param[in]   pBadgeIcon             		The bitmap for the icon
	 * @exception   E_SUCCESS           		The method is successful.
	 * @exception 	E_UNSUPPORTED_OPERATION 	This operation is not supported. @n
	 *      		The operation is not supported when the style of the %Footer control is ::FOOTER_STYLE_TAB.
	 */
	result SetButtonBadgeIcon(ButtonPosition position, const Tizen::Graphics::Bitmap* pBadgeIcon);


	/**
	 * Sets the numbered badge icon of the specified ButtonItem.
	 *
	 * @since    	2.0
	 *
	 * @return   	An error code
	 * @param[in]   position           			The button item position
	 * @param[in]   number             			The number value that should be displayed as the badge icon
	 * @exception   E_SUCCESS          			The method is successful.
	 * @exception   E_INVALID_ARG          		The specified @c number must be in the range defined by @c 0 and @c 99999.
	 * @exception   E_UNSUPPORTED_OPERATION   	This operation is not supported. @n
	 *             	The operation is not supported when the style of the %Footer control is ::FOOTER_STYLE_TAB.
	 * @remarks  	To remove the numbered badge icon from an item, pass @c 0 as the value of @c number.
	 */
	result SetButtonNumberedBadgeIcon(ButtonPosition position, int number);


	/**
	 * Sets the back button.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS                     The method is successful.
	 * @exception   E_INVALID_OPERATION           The current state of the instance prohibits the execution of the specified operation. @n
	 *                                            There are more than 2 footer items.
	 * @exception   E_UNSUPPORTED_OPERATION       This operation is not supported. @n
	 *										The operation is not supported when the style of the %Footer control is ::FOOTER_STYLE_TAB. @n
	 *                                            This device does not support the software back button.
	 * @exception   E_SYSTEM                      A system error has occurred.
	 * @remarks
	 *			- When the back button is pressed, OnFormBackRequested() of IFormBackEventListener is called.
	 *			- If the right button is already set, then the button is replaced with the back button.
	 * @see         Tizen::Ui::Controls::IFormBackEventListener
	 */
	result SetBackButton(void);


	/**
	 * Sets the content of the footer item at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   itemIndex         	The index at which to set the specified item
	 * @param[in]   item             	The item
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the data structure. @n
	 *									The index is greater than or equal to the number of elements or less than @c 0.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid. @n
	 *								    The specified item is not constructed.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The %Footer control does not throw any exception even though the same action ID is assigned to multiple items. @n
	 *              However, the content of the specified item is copied to the %Footer control.
	 */
	result SetItemAt(int itemIndex, const FooterItem& item);


	/**
	 * Sets the item color for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	status                  The item status
	 * @param[in]	color                   The item color to set
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception	E_SYSTEM	            A system error has occurred.
	 * @see         GetItemColor()
	 */
	result SetItemColor(FooterItemStatus status, const Tizen::Graphics::Color& color);


	/**
	 * Sets the item state at the specified index in the footer.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   itemIndex				The index of the item
	 * @param[in]   enable					Set to @c true to enable the item state, @n
	 *                              		else @c false
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_OUT_OF_RANGE   		The specified index is outside the bounds of the data structure. @n
	 *										The index is greater than or equal to the number of elements or less than zero.
	 * @exception	E_INVALID_OPERATION	 	The current state of the instance prohibits the execution of the specified operation. @n
	 *										The specified item is currently selected.
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result SetItemEnabled(int itemIndex, bool enable);


	/**
	 * Sets the badge icon of the specified tab style footer item.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   itemIndex               The index of the item to set the badge icon
	 * @param[in]   pBadgeIcon              The bitmap for the icon
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_RANGE          The specified index is outside the bounds of the data structure. @n
	 *										The index is greater than or equal to the number of elements or less than @c 0.
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result SetItemBadgeIcon(int itemIndex, const Tizen::Graphics::Bitmap* pBadgeIcon);


	/**
	 * Sets the numbered badge icon of the specified footer item.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   itemIndex               The item index
	 * @param[in]   number                  The number value that must be displayed as the badge icon
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_INVALID_ARG           The specified @c number must be in the range defined by @c 0 and @c 99999.
	 * @exception   E_OUT_OF_RANGE          The specified index is outside the bounds of the data structure. @n
	 *										The index is greater than or equal to the number of elements or less than @c 0.
	 * @exception   E_SYSTEM                A system error has occurred.
	 * @remarks     To remove the numbered badge icon from an item, pass @c 0 as the value of @c number.
	 */
	result SetItemNumberedBadgeIcon(int itemIndex, int number);


	/**
	 * Sets the item text color for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   status              The item status
	 * @param[in]   color               The item text color to set
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 */
	result SetItemTextColor(FooterItemStatus status, const Tizen::Graphics::Color& color);


	/**
	 * Selects the item at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   itemIndex               The index of the item to select
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_RANGE          The specified index is out of the range of the data structure. @n
	 *										The specified index is either greater than or equal to the number of items or is less than zero.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified operation. @n
	 *                                      The item at the specified index is disabled.
	 * @exception   E_UNSUPPORTED_OPERATION The operation is not supported if the %Footer control style is ::FOOTER_STYLE_BUTTON_TEXT,
	 *                                      ::FOOTER_STYLE_BUTTON_ICON or ::FOOTER_STYLE_BUTTON_ICON_TEXT.
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result SetItemSelected(int itemIndex);


	/**
	 * Sets the color of the footer.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   color				The footer color to set
	 * @exception   E_SUCCESS			The method is successful.
	 */
	result SetColor(const Tizen::Graphics::Color& color);


	/**
	 * Sets the style of the footer.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   style			    The footer style to set
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks		All items and buttons will be removed if the style is changed.
	 */
	result SetStyle(FooterStyle style);


	/**
	 * Enables or disables the tab edit mode.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   enable                  Set to @c true to enable the edit mode, @n
	 *                                      else @c false
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The operation is supported when the style of the %Footer control style is ::FOOTER_STYLE_TAB.
	 */
	result SetTabEditModeEnabled(bool enable);


	/**
	 * Adds an action event listener instance.
	 * OnActionPerformed() of the added listener is called when the user selects an item.
	 *
	 * @since		2.0
	 *
	 * @param[in]   listener	The event listener to add
	 * @remarks		When the user collapses the tab style %Footer control which is in the expanded mode by pressing the more button,
	 *				OnActionPerformed() is called for the currently selected tab item.
	 */
	void AddActionEventListener(Tizen::Ui::IActionEventListener& listener);


	/**
	 * Removes an action event listener instance.
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to remove
	 */
	void RemoveActionEventListener(Tizen::Ui::IActionEventListener& listener);


	/**
	* Gets the position and size of the specified button item.
	*
	* @since		2.0
	*
	* @return      	The position and size of the button item at the specified position.
	* @param[in]   	position            	The position of the button item
	* @exception   	E_SUCCESS               The method is successful.
	* @exception   	E_INVALID_OPERATION    	The current state of the instance prohibits the execution of the specified operation. @n
	*                                     	There is no button set at the specified position.
	* @remarks     	The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Graphics::Rectangle GetButtonBounds(ButtonPosition position) const;

	/**
	 * Gets the position and size of the specified button item.
	 *
	 * @since		2.1
	 *
	 * @return      	The position and size of the button item at the specified position.
	 * @param[in]   	position            	The position of the button item
	 * @exception   	E_SUCCESS               The method is successful.
	 * @exception   	E_INVALID_OPERATION    	The current state of the instance prohibits the execution of the specified operation. @n
	 *                                     	There is no button set at the specified position.
	 * @remarks     	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::FloatRectangle GetButtonBoundsF(ButtonPosition position) const;


protected:
	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This is the default constructor for this class.
	// @since		2.0
	//
	Footer(void);


	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This is the destructor for this class.
	// @since		2.0
	//
	virtual ~Footer(void);


private:
	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// Initializes this instance of Footer with the specified parameter.
	//
	// @since       2.0
	// @return		An error code
	// @exception	E_SUCCESS		        The method is successful.
	// @exception	E_SYSTEM		        A system error has occurred.
	//
	result Construct(void);

	Footer(const Footer& rhs);
	Footer& operator =(const Footer& rhs);

private:
	friend class _FormImpl;
	friend class _FooterImpl;

};

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_FOOTER_H_
