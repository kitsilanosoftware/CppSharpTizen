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
 * @file		FUiCtrlITokenFilter.h
 * @brief		This is the header file for the %ITokenFilter interface.
 *
 * This header file contains the declarations of the %ITokenFilter interface.
 */
#ifndef _FUI_CTRL_ITOKEN_FILTER_H_
#define _FUI_CTRL_ITOKEN_FILTER_H_

// includes
#include <FBaseRtIEventListener.h>

// namespace declaration
namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @interface	ITokenFilter
 * @brief		This interface defines the token filter.
 *
 * @since   2.0
 *
 * The %ITokenFilter interface is the listener interface for replacing tokenized input in the ExpandableEditArea.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_exp_editarea.htm">ExpandableEditArea</a>.
 *
 */
class _OSP_EXPORT_ ITokenFilter
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 * @since  2.0
	 */
	virtual ~ITokenFilter(void) {}

// Operation
public:
	/**
	 * Checks whether the text tokenized by the ExpandableEditArea instance must be replaced.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the text of the current token needs to be replaced, @n
	 *              else @c false
	 * @param[in]	token       The text of the current token
	 * @param[out]	replacement	The user-defined replacement text
	 */
	virtual bool ReplaceToken(const Tizen::Base::String& token, Tizen::Base::String& replacement) = 0;


// Reserves
protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since      2.0
	//
	virtual void ITokenFilter_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since      2.0
	//
	virtual void ITokenFilter_Reserved2(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since      2.0
	//
	virtual void ITokenFilter_Reserved3(void) { }
}; // ITokenFilter

}}}      //Tizen::Ui::Controls
#endif //_FUI_CTRL_ITOKEN_FILTER_H_
