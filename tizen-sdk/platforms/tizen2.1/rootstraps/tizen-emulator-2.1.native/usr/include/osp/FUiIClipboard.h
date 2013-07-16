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
 * @file	FUiIClipboard.h
 * @brief	This is the header file for the %IClipboard interface.
 *
 * This header file contains the declarations of the %IClipboard interface and its helper classes.
 */

#ifndef _FUI_ICLIPBOARD_H_
#define _FUI_ICLIPBOARD_H_

#include <FUiClipboardItem.h>

namespace Tizen { namespace Ui
{
//
// This class is for internal use only. Using this method can cause behavioral, security-related,
// and consistency-related issues in the application.
//
// @interface	IClipboard
// @brief       This interface defines the operations of %IClipboard.
//
// @since	    2.0
//
// The %IClipboard interface defines the operations of clipboard.
class _OSP_EXPORT_ IClipboard
{
public:
	//
	// This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	//
	// @since   2.0
	//
	virtual ~IClipboard(void) {}

public:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Copies the specified item to the system Clipboard.
	//
	// @since       2.0
	//
	// @return      An error code
	// @param[in]   item            The item to be saved in the system clipboard
	// @exception   E_SUCCESS       The method is successful.
	// @exception   E_INVALID_ARG   A specified input parameter is invalid.
	// @exception   E_SYSTEM        A system error has occurred.
	// @remarks     The method returns E_INVALID_ARG if the specified item is
	//              not constructed.@n
	//              For the text and image data type, the data itself is copied
	//              by the method and kept by the system clipboard.
	//
	virtual result CopyItem(const ClipboardItem& item) = 0;

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Gets a collection of items that matches the specified data types from the
	// system clipboard.
	//
	// @since       2.0
	//
	// @return      The pointer to an IList which contains a collection of ClipboardItem, @n
	//              else @c null if an error occurs
	// @param[in]   dataTypes       The types of items. Multiple data types can be
	//                              combined using bitwise OR (Tizen::Ui::ClipboardDataType).
	// @exception   E_SUCCESS       The method is successful.
	// @exception   E_OBJ_NOT_FOUND The items of the specified data are not found.
	// @exception   E_SYSTEM        A system error has occurred.
	// @remarks     The specific error code can be accessed using the GetLastResult() method. @n
	//              This method returns the pointer to an IList which contains
	//              a collection of ClipboardItem. The returned pointer to IList
	//              and all elements in IList must be deleted by applications.@n
	//              The items in IList are sorted in the reverse order in which
	//              they are copied to the system clipboard. So, the first
	//              item in IList is the latest one among them. @n
	//              @c dataType can be a combination of ClipboardDataType.
	//
	virtual Tizen::Base::Collection::IList* RetrieveItemsN(unsigned long dataTypes) = 0;

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Gets the latest item for the specified data types from the system clipboard.
	//
	// @since       2.0
	//
	// @return      The pointer to a ClipboardItem, @n
	//              else @c null if an error occurs
	// @param[in]   dataTypes       The types of items. Multiple data types can be
	//                              combined using bitwise OR (Tizen::Ui::ClipboardDataType).
	// @exception   E_SUCCESS       The method is successful.
	// @exception   E_OBJ_NOT_FOUND The item of the specified data types is not found.
	// @exception   E_SYSTEM        A system error has occurred.
	// @remarks     The specific error code can be accessed using the GetLastResult() method. @n
	//              This method returns the pointer to a ClipboardItem. The
	//              returned ClipboardItem must be deleted by applications.@n
	//              If there is no matched item in the system clipboard, this method
	//              returns @c null. @n
	//              @c dataType can be a combination of ClipboardDataType.
	//
	virtual Tizen::Ui::ClipboardItem* RetrieveLatestItemN(unsigned long dataTypes) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IClipboard_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IClipboard_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IClipboard_Reserved3(void) {}
}; // IClipboard

}} // Tizen::Ui

#endif //_FUI_ICLIPBOARD_H_
