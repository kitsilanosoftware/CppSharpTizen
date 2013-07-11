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
 * @file	FUiCtrlButtonItem.h
 * @brief	This is the header file for the %ButtonItem class.
 *
 * This header file contains the declarations of the %ButtonItem class.
 */
#ifndef _FUI_CTRL_BUTTON_ITEM_H_
#define _FUI_CTRL_BUTTON_ITEM_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FBaseTypes.h>
#include <FGrpBitmap.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @enum 	ButtonItemStatus
 *
 * Defines the possible states of the button item.
 *
 * @since	2.0
 */
enum ButtonItemStatus
{
	BUTTON_ITEM_STATUS_NORMAL,  	/**< The normal status */
	BUTTON_ITEM_STATUS_PRESSED,     /**< The selected status */
	BUTTON_ITEM_STATUS_HIGHLIGHTED, /**< The highlighted status */
	BUTTON_ITEM_STATUS_DISABLED		/**< The disabled status */
};

/**
 * @enum 	ButtonPosition
 *
 * Defines the possible positions of the button item.
 *
 * @since	2.0
 */
enum ButtonPosition
{
	BUTTON_POSITION_LEFT = 0,       /**< The position of the button is towards the left of the object */
	BUTTON_POSITION_RIGHT           /**< The position of the button is towards the right of the object */
};

/**
 * @enum 	ButtonItemStyle
 *
 * Defines the possible styles of the button item.
 *
 * @since 	2.0
 */
enum ButtonItemStyle
{
	BUTTON_ITEM_STYLE_TEXT = 0,     /**< The text %ButtonItem style */
	BUTTON_ITEM_STYLE_ICON          /**< The icon %ButtonItem style */
};

/**
 * @class	ButtonItem
 * @brief	This class is an implementation of %ButtonItem.
 *
 * @since	2.0
 *
 * The %ButtonItem class is a helper class that specifies the
 * properties of button items in a Footer or Header.
 */
class _OSP_EXPORT_ ButtonItem
	: public Tizen::Base::Object
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	ButtonItem(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~ButtonItem(void);


	/**
	 * Initializes this instance of %ButtonItem with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]	style		    The style of the button item
	 * @param[in]	actionId	    The action ID of the button item
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   A specified input parameter is invalid. @n
	 *                              The specified @c actionId of the specified item must be a positive integer.
	 */
	result Construct(ButtonItemStyle style, int actionId);


	/**
	 * Gets the action ID of the button item.
	 *
	 * @since		2.0
	 *
	 * @return      The action ID, @n
	 *              else @c -1 if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetActionId(void) const;


	/**
	 * Gets the text of the button item.
	 *
	 * @since		2.0
	 *
	 * @return	    The item text, @n
	 *              else an empty string if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetText(void) const;


	/**
	 * Sets the action ID of the button item.
	 *
	 * @since		2.0
     *
	 * @return      An error code
	 * @param[in]	actionId	      The action ID of the button item
	 * @exception   E_SUCCESS         The method is successful.
	 * @exception   E_INVALID_ARG     A specified input parameter is invalid. @n
	 *                                The specified @c actionId of the specified item must be a positive integer.
	 */
	result SetActionId(int actionId);


	/**
	 * Sets the background bitmap image of the button item.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   status              The item status
	 * @param[in]   pBitmap             The background bitmap image to be set, @n
	 *                                  else @c null if no bitmap image is displayed
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	 * @remarks     If the size is greater than the default size, the bitmap image is scaled accordingly.
	 */
	result SetBackgroundBitmap(ButtonItemStatus status, const Tizen::Graphics::Bitmap* pBitmap);


	/**
	 * Sets the icon of the button item for the specified state.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   status              The item status
	 * @param[in]   pIcon               The icon to be set, @n
	 *					                else @c null if no icon is displayed
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	 * @remarks     If the style of %ButtonItem is BUTTON_ITEM_STYLE_TEXT, the method returns E_INVALID_OPERATION. @n
	 *              If an icon is not set for a state, the icon for BUTTON_ITEM_STATUS_NORMAL is used.
	 */
	result SetIcon(ButtonItemStatus status, const Tizen::Graphics::Bitmap* pIcon);


	/**
	 * Sets the text of %ButtonItem.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   text		        The text to be set
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation. @n
	 *                                  The style of %ButtonItem is BUTTON_ITEM_STYLE_ICON.
	 * @remarks		If the text cannot be displayed in a line, then the text is automatically displayed in two lines and the ellipsis is applied if the text
	 *				is longer than two lines. @n
	 *				Use @htmlonly '\n' @endhtmlonly to denote the end of the first line.
	 */
	result SetText(const Tizen::Base::String& text);


private:
	ButtonItem(const ButtonItem& rhs);
	ButtonItem& operator =(const ButtonItem& rhs);

private:
	friend class _FooterImpl;
	friend class _HeaderImpl;
	friend class _ButtonItemImpl;

	class _ButtonItemImpl* __pImpl;
};

}}} //Tizen::Ui::Controls

#endif // _FUI_CTRL_BUTTON_ITEM_H_
