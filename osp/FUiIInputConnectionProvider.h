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
 * @file		FUiIInputConnectionProvider.h
 * @brief	This is the header file for the %IInputConnectionProvider class.
 *
 * This header file contains the declarations of the %IInputConnectionProvider class.
 *
 *
 */

#ifndef _FUI_IINPUT_CONNECTION_PROVIDER_H_
#define _FUI_IINPUT_CONNECTION_PROVIDER_H_

#include <FOspConfig.h>

namespace Tizen { namespace Base {
class String;
}} // Tizen::Base

namespace Tizen { namespace Ui {

class InputConnection;

/**
 * @class	IInputConnectionProvider
 * @brief	This is the header file for the %IInputConnectionProvider class.
 * This header file contains the declarations of the %IInputConnectionProvider class.
 * It's possible to not work the callback depending on the current active Input Method.
 * @since 2.0
 *
 * The %IInputConnectionProvider interface defines methods for processing between the InputConnection and the input method.
 */
class _OSP_EXPORT_ IInputConnectionProvider
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IInputConnectionProvider(void) {}

	/**
	 * Called when the text needs to be deleted.
	 *
	 * @since 2.0
	 * @param[in]       source                  The source of the event
	 * @param[in]       offset                   The position to be deleted before the current cursor position.
	 * @param[in]       charCount             The number of characters to be deleted.
	 */
	virtual void DeleteSurroundingText(Tizen::Ui::InputConnection& source, int offset, int charCount) = 0;

	/**
	 * Called when the input method requests the previous text.
	 *
	 * @since 2.0
	 * @param[in] 	source		The source of the event
	 * @param[out] 	text			The text to be sent to the Input Method.
	 * @param[out] 	cursorPosition	The current cursor position to be sent to the Input Method.
	 * @remarks      The text will be used for processing the auto-capitalization/auto-period. At least three letters in front of the cursor are required.
	 */
	virtual void GetPreviousText(Tizen::Ui::InputConnection& source, Tizen::Base::String& text, int& cursorPosition) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IInputConnectionProvider_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IInputConnectionProvider_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IInputConnectionProvider_Reserved3(void) {}
}; // IInputConnectionProvider

}} // Tizen::Ui
#endif // _FUI_IINPUT_CONNECTION_PROVIDER_H_

