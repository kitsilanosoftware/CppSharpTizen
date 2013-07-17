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
 * @file	FUiCtrlHeader.h
 * @brief	This is the header file for the %Header class.
 *
 * This header file contains the declarations of the %Header class.
 */
#ifndef _FUI_CTRL_HEADER_H_
#define _FUI_CTRL_HEADER_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FGrpBitmap.h>
#include <FGrpColor.h>
#include <FGrpRectangle.h>
#include <FUiControl.h>
#include <FUiIActionEventListener.h>
#include <FUiCtrlAnimation.h>
#include <FUiCtrlButtonItem.h>
#include <FUiCtrlHeaderItem.h>
#include <FUiCtrlForm.h>

namespace Tizen { namespace Ui { namespace Controls
{
class _HeaderImpl;

/**
 * @enum	HeaderStyle
 *
 * Defines the possible styles of a %Header control.
 *
 * @since	2.0
 */
enum HeaderStyle
{
	HEADER_STYLE_TITLE,     			/**< The title style */
	HEADER_STYLE_TITLE_BUTTON,  		/**< The title button style */
	HEADER_STYLE_SEGMENTED,     		/**< The segmented style */
	HEADER_STYLE_SEGMENTED_WITH_TITLE,  /**< The segmented style with title */
	HEADER_STYLE_TAB,  					/**< The tab style */
	HEADER_STYLE_TAB_WITH_TITLE,  		/**< The tab with title style */
	HEADER_STYLE_BUTTON  				/**< The button style */
};

/**
 * @enum	HeaderAnimationPosition
 *
 * Defines the possible positions of the waiting animation of a header.
 *
 * @since   2.0
 */
enum HeaderAnimationPosition
{
	HEADER_ANIMATION_POSITION_TITLE,        /**< The title animation */
	HEADER_ANIMATION_POSITION_BUTTON_LEFT,  /**< The left button animation */
	HEADER_ANIMATION_POSITION_BUTTON_RIGHT  /**< The right button animation */
};

/**
 * @class	Header
 * @brief	This class is an implementation of a %Header control.
 *
 * @since	2.0
 *
 * The %Header class displays a multi-purpose area at the top of the screen that usually acts as a placeholder for descriptive
 * contents, such as a title of the current screen. It can also contain buttons for performing various user-defined tasks.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_header.htm">Header</a>.
 *
 * The following examples demonstrate how to use the %Header class.
 *
 * - Constructing a header: @n
 * When creating a Form, specify the FORM_STYLE_HEADER parameter in the Form::Construct() method.
 *
 * @code
 * // Initializes
 * bool
 * TestForm::Initialize(void)
 * {
 *      Construct(FORM_STYLE_NORMAL | FORM_STYLE_INDICATOR | FORM_STYLE_HEADER );
 * }
 * @endcode
 *
 * - Using the header: @n
 * Gets the header with the GetHeader() method, and sets the header style.
 *
 * @code
 * bool
 * TestForm::Initialize(void)
 * {
 *      Header* pHeader = GetHeader();
 *      pHeader->SetStyle(HEADER_STYLE_SEGMENTED);
 * }
 * @endcode
 *
 * - Adding items to the header: @n
 * Adds HeaderItems or ButtonItems according to the header style. The action ID registered in the Construct() method is notified
 * when items are touched.
 *
 * @code
 * bool
 * TestForm::Initialize(void)
 * {
 *      HeaderItem headerItem;
 *      headerItem.Construct(ID_HEADER_ITEM);
 *      headerItem.SetText("HeaderItem");
 *
 *      pHeader->AddItem(headerItem);
 *
 *      ButtonItem buttonItem;
 *		buttonItem.Construct(BUTTON_ITEM_STYLE_ICON, ID_HEADER_BUTTON);
 *      buttonItem.SetIcon(BUTTON_ITEM_STATUS_NORMAL, __pBitmap);
 *
 *      pHeader->SetButton(BUTTON_POSITION_LEFT, buttonItem);
 *
 * }
 * @endcode
 *
 * - Setting the header title and description:
 *
 * @code
 * bool
 * TestForm::Initialize(void)
 * {
 *      pHeader->SetTitleText(L"Header Title");
 *      pHeader->SetDescriptionText(L"Description Text");
 * }
 * @endcode
 */
class _OSP_EXPORT_ Header
	: public Tizen::Ui::Control
{

public:
	/**
	 * Adds the specified header item.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   item                The HeaderItem object to add
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_MAX_EXCEEDED      The number of items has exceeded the maximum limit.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid. @n
	 *									The specified item is not constructed.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The %Header control does not throw any exception even though the same action ID is assigned to multiple items. @n
	 *              However, the content of the specified item is copied to the %Header control.
	 */
	result AddItem(const HeaderItem& item);


	/**
	 * Inserts the header item at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   itemIndex           The index where the item should be inserted
	 * @param[in]   item                The HeaderItem object to insert
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_MAX_EXCEEDED      The number of items has exceeded the maximum limit.
	 * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the data structure, or the index is greater than or equal to
	 *								the number of elements or less than @c 0.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid. @n
	 *									The specified @c item is not constructed.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The %Header control does not throw any exception even though the same action ID is assigned to multiple items. @n
	 *              However, the content of the specified item is copied to the %Header control.
	 */
	result InsertItemAt(int itemIndex, const HeaderItem& item);


	/**
	 * Checks whether a button item is set at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the button item is set at the specified position, @n
	 *				else @c false
	 * @param[in]	position			The position of the button item
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsButtonSet(ButtonPosition position) const;


	/**
	 * Gets the state of the specified button item.
	 *
	 * @since		2.0
	 *
	 * @return      The state of the button item at the specified position, @n
	 *				else @c BUTTON_ITEM_STATUS_NORMAL if an error occurs
	 * @param[in]   position			The position of the button item
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									There is no button set at the specified position.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	ButtonItemStatus GetButtonStatus(ButtonPosition position) const;


	/**
	 * Gets the color of the button item for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return		The color of the button item, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]   status				The status of the button item
	 * @exception   E_SUCCESS			The method is successful.
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
	 * @param[in]   status				The status of the button item
	 * @exception   E_SUCCESS			The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetButtonTextColor(ButtonItemStatus status) const;


	/**
	 * Gets the description text of the %Header control that has the title style.
	 *
	 * @since		2.0
	 *
	 * @return		The description text, @n
	 *				else an empty string if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetDescriptionText(void) const;


	/**
	 * Gets the description text color of the %Header control that has the title style.
	 *
	 * @since		2.0
	 *
	 * @return		The description text color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetDescriptionTextColor(void) const;


	/**
	 * Gets the color of the header item for the specified item state.
	 *
	 * @since		2.0
	 *
	 * @return		The color of the item, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]	status				The item status
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			SetItemColor()
	 */
	Tizen::Graphics::Color GetItemColor(HeaderItemStatus status) const;


	/**
	 * Gets the total number of header items.
	 *
	 * @since		2.0
	 *
	 * @return		The total number of header items, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetItemCount(void) const;


	/**
	 * Gets the state of the specified header item.
	 *
	 * @since		2.0
	 *
	 * @return		The item status
	 * @param[in]	itemIndex			The index of the item
	 * @param[out]	status				The item status
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure. @n
	 *									The index is greater than or equal to the number of elements or less than @c 0.
	 */
	result GetItemStatus(int itemIndex, HeaderItemStatus& status) const;


	/**
	 * Gets the text color of the header item for the specified item state.
	 *
	 * @since		2.0
	 *
	 * @return		The item's text color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]	status				The item status
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetItemTextColor(HeaderItemStatus status) const;


	/**
	 * Gets the style of the %Header control.
	 *
	 * @since		2.0
	 *
	 * @return		The %Header control style, @n
	 *				else @c HEADER_STYLE_TITLE if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	HeaderStyle GetStyle(void) const;


	/**
	 * Gets the index of the currently selected item.
	 *
	 * @since		2.0
	 *
	 * @return		The selected item index, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is supported when the style of the %Header control is
	 *												::HEADER_STYLE_SEGMENTED, @n ::HEADER_STYLE_SEGMENTED_WITH_TITLE,
	 												::HEADER_STYLE_TAB or ::HEADER_STYLE_TAB_WITH_TITLE.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetSelectedItemIndex(void) const;


	/**
	 * Gets the title text of the %Header control that has the title style.
	 *
	 * @since		2.0
	 *
	 * @return		The title text, @n
	 *				else an empty string if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetTitleText(void) const;


	/**
	 * Gets the title text color of the %Header control that has the title style.
	 *
	 * @since		2.0
	 *
	 * @return		The title text color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetTitleTextColor(void) const;


	/**
	 * Gets the color of the %Header control.
	 *
	 * @since		2.0
	 *
	 * @return		The header color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetColor(void) const;


	/**
	 * Gets the status of the waiting animation at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return		The animation status
	 * @param[in]	animationPos		The waiting animation position
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 *              This method returns @c ANIMATION_STOPPED, if no animation is in progress at the specified position.
	 * @see			PauseWaitingAnimation()
	 * @see			PlayWaitingAnimation()
	 * @see			StopWaitingAnimation()
	 */
	AnimationStatus GetWaitingAnimationStatus(HeaderAnimationPosition animationPos) const;


	/**
	 * Pauses the waiting animation at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	animationPos			The waiting animation position
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *										No waiting animation is in progress at the specified position.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @see			PlayWaitingAnimation()
	 * @see			StopWaitingAnimation()
	 */
	result PauseWaitingAnimation(HeaderAnimationPosition animationPos);


	/**
	 * Starts the waiting animation at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	animationPos			The waiting animation position
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *										There is no button set at the specified position (except for @c HEADER_ANIMATION_POSITION_TITLE).
	 * @exception   E_SYSTEM				A system error has occurred.
	 * @see			SetButton()
	 * @see			IsButtonSet()
	 * @see			GetWaitingAnimationStatus()
	 * @see			PauseWaitingAnimation()
	 * @see			StopWaitingAnimation()
	 */
	result PlayWaitingAnimation(HeaderAnimationPosition animationPos);


	/**
	 * Removes all the button items.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
	result RemoveAllButtons(void);


	/**
	 * Removes all the %Header control items.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The left button, right button, and back button items are not removed.
	 */
	result RemoveAllItems(void);


	/**
	 * Removes the item at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	itemIndex			The index of the item to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure. @n
	 *									The index is greater than or equal to the number of elements or less than @c 0.
	 * @exception	E_SYSTEM            A system error has occurred.
	 */
	result RemoveItemAt(int itemIndex);


	/**
	 * Removes the button item at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   position        The position of the button item to remove
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     If no button item is set at the specified position, the method returns @c E_SUCCESS.
	 */
	result RemoveButtonAt(ButtonPosition position);


	/**
	 * Sets the background bitmap image.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   pBitmap				The background image
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_SYSTEM			A system error has occurred.
	 */
	result SetBackgroundBitmap(const Tizen::Graphics::Bitmap* pBitmap);


	/**
	 * Sets the button item at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   position			The position at which to set the specified button item
	 * @param[in]   button				The button item to set
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid. @n
	 *									The specified item is not constructed.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks     If there is an existing button item at the specified position, it is replaced with a new item. @n
	 *              The contents of the specified item are copied.
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
	 * @param[in]   position			The button item position
	 * @param[in]   enable				Set to @c true to enable the specified button item, @n
	 *									else @c false to disable
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									There is no button set at the specified position.
	 * @exception   E_SYSTEM            A system error has occurred.
	 */
	result SetButtonEnabled(ButtonPosition position, bool enable);


	/**
	 * Sets the text color of the button item for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   status          The status of the button item
	 * @param[in]   color           The button item text color to set
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred.
	 */
	result SetButtonTextColor(ButtonItemStatus status, const Tizen::Graphics::Color& color);


	/**
	 * Sets the badge icon of the specified ButtonItem.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	position      				The button item position
	 * @param[in]	pBadgeIcon   				The bitmap for the icon
	 * @exception	E_SUCCESS      				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION 	This operation is not supported. @n
	 *            	The operation is not supported when the style of the %Header control is ::HEADER_STYLE_TAB or ::HEADER_STYLE_TAB_WITH_TITLE.
	 */
	result SetButtonBadgeIcon(ButtonPosition position, const Tizen::Graphics::Bitmap* pBadgeIcon);


	/**
	 * Sets the numbered badge icon of the specified ButtonItem.
	 *
	 * @since 	  	2.0
	 *
	 * @return  	An error code
	 * @param[in]	position        	     	The button item position
	 * @param[in]  	number           			The number value that should be displayed as the badge icon
	 * @exception  	E_SUCCESS              		The method is successful.
	 * @exception  	E_INVALID_ARG   			The specified @c number must be in the range defined by @c 0 and @c 99999.
	 * @exception  	E_UNSUPPORTED_OPERATION  	This operation is not supported. @n
	 *           	The operation is not supported when the style of the %Header control is ::HEADER_STYLE_TAB or ::HEADER_STYLE_TAB_WITH_TITLE.
	 * @remarks    	To remove the numbered badge icon from an item, pass @c 0 as the value of @c number.
	 */
	result SetButtonNumberedBadgeIcon(ButtonPosition position, int number);


	/**
	 * Sets the contents of the %Header control item at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   itemIndex           The index at which to set the specified item
	 * @param[in]   item                The item to set
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the data structure. @n
	 *									The index is greater than or equal to the number of elements or less than @c 0.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The contents of the specified item are copied.
	 */
	result SetItemAt(int itemIndex, const HeaderItem& item);


	/**
	 * Sets the badge icon of the specified segmented style header item.
	 *
	 * @since		2.0
	 *
	 * @return			An error code
	 * @param[in]		itemIndex				The item index
	 * @param[in]		pBadgeIcon				The bitmap for the icon
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure. @n
	 *											The index is greater than or equal to the number of elements or less than @c 0.
	 * @exception     	E_UNSUPPORTED_OPERATION The operation is not supported when the style of the %Header control is ::HEADER_STYLE_TITLE.
	 * @exception		E_SYSTEM				A system error has occurred.
	 */
	result SetItemBadgeIcon(int itemIndex, const Tizen::Graphics::Bitmap* pBadgeIcon);


	/**
	 * Sets the numbered badge icon of the specified segmented style header item.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	itemIndex				The item index
	 * @param[in]	number					The number value that should be displayed as the badge icon
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c number must be in the range defined by @c 0 and @c 99999.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure. @n
	 *										The index is greater than or equal to the number of elements or less than @c 0.
	 * @exception   E_UNSUPPORTED_OPERATION The operation is not supported when the style of the %Header control is ::HEADER_STYLE_TITLE.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		To remove the numbered badge icon from an item, pass @c 0 as the value of @c number.
	 */
	result SetItemNumberedBadgeIcon(int itemIndex, int number);


	/**
	 * Sets the item color for the specified state.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	status          The item status
	 * @param[in]	color           The item color to set
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_SYSTEM	    A system error has occurred.
	 * @see         GetItemColor()
	 */
	result SetItemColor(HeaderItemStatus status, const Tizen::Graphics::Color& color);


	/**
	 * Sets the item state at the specified index in the %Header control.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   itemIndex               The index of the item to set
	 * @param[in]   enable                 Set to @c true to enable the item state, @n
	 *                                      else @c false
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_RANGE          The specified index is outside the bounds of the data structure. @n
	 *										The index is greater than or equal to the number of elements or less than @c 0.
	 * @exception   E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified operation. @n
	 *                                      The specified item is currently selected.
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result SetItemEnabled(int itemIndex, bool enable);


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
	result SetItemTextColor(HeaderItemStatus status, const Tizen::Graphics::Color& color);


	/**
	 * Sets the selected item at the specified index.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   itemIndex               The index of the item to select
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_OUT_OF_RANGE          The specified index is outside the bounds of the data structure. @n
	 *										The index is greater than or equal to the number of elements or less than @c 0.
	 * @exception   E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation. @n
	 *                                      The item at the specified index is disabled.
	 * @exception   E_UNSUPPORTED_OPERATION The operation is not supported when the %Header control style is ::HEADER_STYLE_TITLE, @n
	 *                                     	::HEADER_STYLE_TITLE_BUTTON or ::HEADER_STYLE_BUTTON.
	 * @exception   E_SYSTEM                A system error has occurred.
	 */
	result SetItemSelected(int itemIndex);


	/**
	 * Sets the color of the %Header control.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   color               The header color
	 * @exception   E_SUCCESS           The method is successful.
	 */
	result SetColor(const Tizen::Graphics::Color& color);


	/**
	 * Sets the style of the %Header control.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   style		         The header style to set
	 * @exception   E_SUCCESS			 The method is successful.
	 * @exception   E_SYSTEM			 A system error has occurred.
	 * @remarks		All items and buttons will be removed if the style is changed.
	 */
	result SetStyle(HeaderStyle style);


	/**
	 * Sets the title icon of the %Header control that has the title style.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   pIcon                   The title icon to set @n
	 *								        Set to @c null to remove the title icon.
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The operation is supported when the %Header control style is ::HEADER_STYLE_TITLE, @n
	 *                                      ::HEADER_STYLE_SEGMENTED_WITH_TITLE or ::HEADER_STYLE_TAB_WITH_TITLE.
	 * @exception	E_SYSTEM		        A system error has occurred.
	 */
	result SetTitleIcon(const Tizen::Graphics::Bitmap* pIcon);


	/**
	 * Sets the title text of the %Header control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text		            The text to set
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception  	E_UNSUPPORTED_OPERATION The operation is supported when the %Header control style is ::HEADER_STYLE_TITLE, @n
	 *                              		::HEADER_STYLE_SEGMENTED_WITH_TITLE or ::HEADER_STYLE_TAB_WITH_TITLE.
	 * @exception 	E_SYSTEM		        A system error has occurred.
	 * @remarks		If the text cannot be displayed in a line, then the ellipsis is applied at the end. @n
	 *				When the title icon is set along with the title text, the title retains the left alignment.
	 */
	result SetTitleText(const Tizen::Base::String& text);


	/**
	 * Sets the title text color.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   color                   The title text color to set
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The operation is supported when the %Header control style is ::HEADER_STYLE_TITLE, @n
	 *                                      ::HEADER_STYLE_SEGMENTED_WITH_TITLE or ::HEADER_STYLE_TAB_WITH_TITLE.
	 * @exception	E_SYSTEM		        A system error has occurred.
	 */
	result SetTitleTextColor(const Tizen::Graphics::Color& color);


	/**
	 * Sets the description text.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text		            The text to set
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION The current state of the instance does not support the execution of the specified operation. @n
	 *                                      The style of the %Header control is not ::HEADER_STYLE_TITLE.
	 * @exception	E_SYSTEM		        A system error has occurred.
	 * @remarks		If the text cannot be displayed in a line, then the ellipsis is applied at the end. @n
	 *				When the title icon is set along with the title text, the title retains the left alignment.
	 */
	result SetDescriptionText(const Tizen::Base::String& text);


	/**
	 * Sets the description text color.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   color                   The description text color to set
	 * @exception	E_SUCCESS               The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION The current state of the instance does not support the execution of the specified operation. @n
	 *                                      The style of the %Header control is not ::HEADER_STYLE_TITLE.
	 * @exception	E_SYSTEM		        A system error has occurred.
	 */
	result SetDescriptionTextColor(const Tizen::Graphics::Color& color);


	/**
	 * Stops the waiting animation in progress at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	animationPos			The waiting animation position
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception   E_SYSTEM				A system error has occurred.
	 * @remarks		This method returns @c E_INVALID_OPERATION if no waiting animation is in progress at the specified position.
	 * @see			GetWaitingAnimationStatus()
	 * @see			PauseWaitingAnimation()
	 * @see			PlayWaitingAnimation()
	 */
	result StopWaitingAnimation(HeaderAnimationPosition animationPos);


	/**
	 * Adds an IActionEventListener instance. @n
	 * OnActionPerformed() of the added listener is called when the user selects an item.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to add
	 */
	void AddActionEventListener(Tizen::Ui::IActionEventListener& listener);


	/**
	 * Removes an IActionEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]   listener	The event listener to remove
	 */
	void RemoveActionEventListener(Tizen::Ui::IActionEventListener& listener);


	/**
	 * Checks whether the tab edit mode is enabled.
	 *
	 * @since 		2.0
	 *
	 * @return      @c true if the tab edit mode is set, @n
	 *				else @c false
	 */
	bool IsTabEditModeEnabled(void) const;


	/**
	 * Enables or disables the tab edit mode.
	 *
	 * @since 		2.0
	 *
	 * @return      An error code
	 * @param[in]   enable                  Set to @c true to enable the edit mode, @n
	 *                                      else @c false
	 * @exception   E_SUCCESS               The method is successful.
	 * @exception   E_UNSUPPORTED_OPERATION The operation is supported when the style of the %Header control style is ::HEADER_STYLE_TAB @n
	 *                                      or ::HEADER_STYLE_TAB_WITH_TITLE.
	 */
	result SetTabEditModeEnabled(bool enable);


	/**
	* Sets the back button.
	*
	* @since		2.0
	*
	* @return      	An error code
	* @exception   	E_SUCCESS					The method is successful.
	* @exception   	E_INVALID_OPERATION 		The current state of the instance prohibits the execution of the specified operation. @n
	*                                           There are more than 2 header items.
	* @exception    E_UNSUPPORTED_OPERATION  	The operation is supported when the style of the %Header control is ::HEADER_STYLE_BUTTON. @n
	*                                          	This device does not support the software back button.
	* @remarks     	When the back button is pressed, OnFormBackRequested() of IFormBackEventListener is called. @n
	*              	If the right button is already set, then the button is replaced with the back button.
	*/
	result SetBackButton(void);


	/**
	* Checks whether the back button item is set.
	*
	* @since		2.0
	*
	* @return		@c true if the back button item is set, @n
	*            	else @c false
	*/
	bool IsBackButtonSet(void) const;


	/**
	* Removes the back button item.
	*
	* @since		2.0
	*
	*/
	void RemoveBackButton(void);


	/**
	* Enables or disables the back button.
	*
	* @since		2.0
	*
	* @return      	An error code
	* @param[in]   	enable                 	Set to @c true to enable the back button, @n
	*                         				else @c false
	* @exception   	E_SUCCESS               The method is successful.
	* @exception   	E_INVALID_OPERATION    	The current state of the instance prohibits the execution of the specified operation. @n
	*                                		The back button item is not set.
	*/
	result SetBackButtonEnabled(bool enable);


	/**
	* Gets the state of the back button.
	*
	* @since		2.0
	*
	* @return      	The state of the back button, @n
	*              	else @c BUTTON_ITEM_STATUS_NORMAL if an error occurs.
	* @exception   	E_SUCCESS          		The method is successful.
	* @exception   	E_INVALID_OPERATION  	The current state of the instance prohibits the execution of the specified operation. @n
	*            							The back button is not set.
	* @remarks     	The specific error code can be accessed using the GetLastResult() method.
	*/
	ButtonItemStatus GetBackButtonStatus(void) const;


	/**
	* Gets the position and size of the specified button item.
	*
	* @since		2.0
	*
	* @return      	The position and size of the button item at the specified position.
	* @param[in]   	position             	The position of the button item
	* @exception   	E_SUCCESS               The method is successful.
	* @exception   	E_INVALID_OPERATION    	The current state of the instance prohibits the execution of the specified operation. @n
	*                                  		There is no button set at the specified position.
	* @remarks     	The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Graphics::Rectangle GetButtonBounds(ButtonPosition position) const;

	/**
	* Gets the position and size of the specified button item.
	*
	* @since		2.1
	*
	* @return      	The position and size of the button item at the specified position.
	* @param[in]   	position             	The position of the button item
	* @exception   	E_SUCCESS               The method is successful.
	* @exception   	E_INVALID_OPERATION    	The current state of the instance prohibits the execution of the specified operation. @n
	*                                  		There is no button set at the specified position.
	* @remarks     	The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Graphics::FloatRectangle GetButtonBoundsF(ButtonPosition position) const;

	/**
	* Sets the badge icon.
	*
	* @since        2.1
	*
	* @return       An error code
	* @param[in]    pBadgeIcon               The bitmap for the badge icon
	* @exception    E_SUCCESS                The method is successful.
	* @exception    E_INVALID_OPERATION      This operation is invalid. @n
	*                                        The operation is invalid when the style of the %Header control is not ::HEADER_STYLE_TITLE
	*						or ::HEADER_STYLE_SEGMENTED_WITH_TITLE or ::HEADER_STYLE_TAB_WITH_TITLE.
	* @remarks      For icon size details, see <a href="../org.tizen.native.appprogramming/html/guide/ui/control_iconsize.htm">here</a>.
	*/
	result SetTitleBadgeIcon(const Tizen::Graphics::Bitmap* pBadgeIcon);

	/**
	* Sets the numbered badge icon.
	*
	* @since        2.1
	*
	* @return       An error code
	* @param[in]    number                    The number value that should be displayed as the badge icon
	* @exception    E_SUCCESS                 The method is successful.
	* @exception    E_INVALID_ARG             The specified @c number must be in the range defined by @c 0 and @c 99999.
	* @exception    E_INVALID_OPERATION       This operation is invalid. @n
	*                                         The operation is invalid when the style of the %Header control is not ::HEADER_STYLE_TITLE
	*							or ::HEADER_STYLE_SEGMENTED_WITH_TITLE TITLE or ::HEADER_STYLE_TAB_WITH_TITLE.
	* @remarks      To remove the numbered badge icon from an item, pass @c 0 as the value of @c number.
	*/
	result SetTitleNumberedBadgeIcon(int number);


protected:
	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This is the default constructor for this class.
	//
	// @since         2.0
	//
	Header(void);


	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This is the destructor for this class.
	//
	// @since         2.0
	//
	virtual ~Header(void);


private:
	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// Initializes this instance of %Header with the specified parameter.
	//
	// @since		2.0
	// @return		An error code
	// @exception	E_SUCCESS			The method is successful.
	// @exception	E_SYSTEM			A system error has occurred.
	//
	result Construct(void);

	Header(const Header& rhs);
	Header& operator =(const Header& rhs);

private:
	friend class _FormImpl;
	friend class _HeaderImpl;

};

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_HEADER_H_
