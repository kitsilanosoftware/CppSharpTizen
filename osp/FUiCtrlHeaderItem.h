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
 * @file	FUiCtrlHeaderItem.h
 * @brief	This is the header file for the %HeaderItem class.
 *
 * This header file contains the declarations of the %HeaderItem class.
 */
#ifndef _FUI_CTRL_HEADER_ITEM_H_
#define _FUI_CTRL_HEADER_ITEM_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FBaseTypes.h>
#include <FGrpBitmap.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @enum 	HeaderItemStatus
 *
 * Defines the possible statuses of a %HeaderItem control.
 *
 * @since	2.0
 */
enum HeaderItemStatus
{
	HEADER_ITEM_STATUS_NORMAL,  	/**< The normal status */
	HEADER_ITEM_STATUS_PRESSED,     /**< The pressed status */
	HEADER_ITEM_STATUS_SELECTED,    /**< The selected status */
	HEADER_ITEM_STATUS_HIGHLIGHTED, /**< The highlighted status */
	HEADER_ITEM_STATUS_DISABLED		/**< The disabled status */
};

/**
 * @class	HeaderItem
 * @brief	This class is an implementation of a %HeaderItem control.
 *
 * @since	2.0
 *
 * The %HeaderItem class is a helper class that specifies the properties of the Header item.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_header.htm">Header</a>.
 */
class _OSP_EXPORT_ HeaderItem
	: public Tizen::Base::Object
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	HeaderItem(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~HeaderItem(void);


	/**
	 * Initializes this instance of %HeaderItem with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]	actionId	    The action ID of this item
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   The specified input parameter is invalid. @n
	 *								The action ID of the specified item must be a positive integer.
	 */
	result Construct(int actionId);


	/**
	 * Gets the action ID of the %HeaderItem control.
	 *
	 * @since		2.0
	 *
	 * @return      The action ID, @n
	 *				else @c -1 if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetActionId(void) const;


	/**
	 * Gets the text of the %HeaderItem control.
	 *
	 * @since		2.0
	 *
	 * @return		The item text, @n
	 *				else an empty string if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetText(void) const;


	/**
	 * Sets the action ID of the %HeaderItem control.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]	actionId		    The specified action ID for this item
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       The specified input parameter is invalid. @n
	 *									The action ID of the specified item must be a positive integer.
	 */
	result SetActionId(int actionId);


	/**
	 * Sets the background bitmap of the %HeaderItem control.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   status              The item status
	 * @param[in]   pBitmap             The background bitmap to set, @n
	 *                                  else @c null if no bitmap is to be displayed
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     If the size of the bitmap is greater than the size of the item, the bitmap is scaled down.
	 */
	result SetBackgroundBitmap(HeaderItemStatus status, const Tizen::Graphics::Bitmap* pBitmap);


	/**
	 * Sets the icon of the header item.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   status              The status of the header item
	 * @param[in]   pIcon               The icon to be set, @n
	 *			                        else @c null if no icon is to be set
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks     If the size of the bitmap is greater than the default size, the bitmap is scaled down. @n
	 *              The bitmap specified for the @c HEADER_ITEM_STATUS_NORMAL will be applied for all other statuses unless different bitmaps are explicitly
	 *				set for those by using this method. @n
	 *              Note that the specified bitmaps are ignored if the style of the Header control is not @c HEADER_STYLE_TITLE_BUTTON. @n
	 *              Furthermore, the title button does not support @c HEADER_ITEM_STATUS_SELECTED status and the bitmap for the status is also ignored.
	 */
	result SetIcon(HeaderItemStatus status, const Tizen::Graphics::Bitmap* pIcon);


	/**
	 * Sets the text of the %HeaderItem control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   text		        The text to be set
	 * @exception   E_SUCCESS           The method is successful.
	 * @remarks		If the text cannot be displayed in a line, then the text is automatically displayed in two lines and the ellipsis is applied if the text
	 *				is longer than two lines. @n
	 *				Use @htmlonly '\n' @endhtmlonly to denote the end of the line.
	 */
	result SetText(const Tizen::Base::String& text);


private:
	HeaderItem(const HeaderItem& headerItem);
	HeaderItem& operator =(const HeaderItem& headerItem);


private:
	friend class _HeaderImpl;
	friend class _HeaderItemImpl;

	class _HeaderItemImpl * __pImpl;

};

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_HEADER_ITEM_H_
