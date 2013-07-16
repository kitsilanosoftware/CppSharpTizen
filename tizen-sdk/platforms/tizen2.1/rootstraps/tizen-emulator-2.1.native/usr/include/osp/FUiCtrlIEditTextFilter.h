//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FUiCtrlIEditTextFilter.h
 * @brief	This is the header file for the %IEditTextFilter interface.
 *
 * This header file contains the declarations of the %IEditTextFilter interface.
 *
 */
#ifndef _FUI_CTRL_IEDIT_TEXT_FILTER_H_
#define _FUI_CTRL_IEDIT_TEXT_FILTER_H_

#include <FOspConfig.h>

namespace Tizen {namespace Ui { namespace Controls
{

/**
 * @interface	IEditTextFilter
 * @brief		This interface defines the text filter.
 *
 * @since		2.1
 *
 * The %IEditTextFilter interface is the listener interface for handling texts, for example, from EditFields.
 * The class that processes a text event implements this interface, and the instance created with that class is registered with a
 * UI control, using the control(EditArea, EditField, ExpandableEditArea, Keypad, SearchBar)'s SetEditTextFilter() method.
 *
 */

class _OSP_EXPORT_ IEditTextFilter
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called
	 * when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IEditTextFilter(void) {}

	/**
	 * Checks whether the text to be pasted from the %Clipboard needs to be replaced by other text.
	 *
	 * @since       2.1
	 *
	 * @return      @c true if the pasted text needs to be replaced, @n
	 *              else @c false
	 * @param[in]		pastedText    The pasted text
	 * @param[out]	replacedText	The user-defined replacement text
	 */
	virtual bool ValidatePastedText(const Tizen::Base::String& pastedText, Tizen::Base::String& replacedText) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IEditTextFilter_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IEditTextFilter_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IEditTextFilter_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IEditTextFilter_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IEditTextFilter_Reserved5(void) {}
}; // IEditTextFilter

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_IEDIT_TEXT_FILTER_H_

