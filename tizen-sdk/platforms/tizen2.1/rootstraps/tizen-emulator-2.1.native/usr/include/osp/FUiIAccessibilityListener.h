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
 * @file	FUiIAccessibilityListener.h
 * @brief	This is the header file for the %IAccessibilityListener interface.
 *
 * This header file contains the declarations of the %IAccessibilityListener interface.
 */

#ifndef _FUI_IACCESSIBILITY_LISTENER_H_
#define _FUI_IACCESSIBILITY_LISTENER_H_

#include <FOspConfig.h>
#include <FBaseRtIEventListener.h>
#include <FUiAccessibilityTypes.h>

namespace Tizen { namespace Ui
{
class AccessibilityElement;
class Control;

/**
* @interface	IAccessibilityListener
* @brief This interface is the listener interface for accessibility screen reader.
*
* @since		2.0
*
* This %IAccessibilityListener interface defines methods for accessibility screen reader.
*
*/
class _OSP_EXPORT_ IAccessibilityListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	* This polymorphic destructor should be overridden if required. @n
	* This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since		2.0
	*/
	virtual ~IAccessibilityListener(void) {}

	/**
	* Called when the accessibility element gets a focus.
	*
	* @since		2.0
	* @param[in] control	The control that has an accessibility element
	* @param[in] element	The element
	*/
	virtual void OnAccessibilityFocusIn(const Control& control, const AccessibilityElement& element) = 0;

	/**
	* Called when the accessibility element losts a focus.
	*
	* @since		2.0
	* @param[in] control	The control that has an accessibility element
	* @param[in] element	The element
	*/
	virtual void OnAccessibilityFocusOut(const Control& control, const AccessibilityElement& element) = 0;

	/**
	* Called when the accessibility element is operated.
	*
	* @since		2.0
	* @param[in] control	The control that has an accessibility element
	* @param[in] element	The element
	*/
	virtual void OnAccessibilityActionPerformed(const Control& control, const AccessibilityElement& element) = 0;

	/**
	* Called when the accessibility screen status is changed.
	*
	* @since		2.0
	* @param[in] control	The control that has an accessibility element
	* @param[in] element	The focused element
	* @param[in] status	The changed status
	*/
	virtual void OnAccessibilityScreenReaderStatusChanged(const Control& control, const AccessibilityElement& element, AccessibilityScreenReaderStatus status) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Following method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IAccessibilityListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Following method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IAccessibilityListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Following method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IAccessibilityListener_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Following method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IAccessibilityListener_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Following method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IAccessibilityListener_Reserved5(void) {}
}; // IAccessibilityListener

}} // Tizen::Ui
#endif // _FUI_IACCESSIBILITY_LISTENER_H_