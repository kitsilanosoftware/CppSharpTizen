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
 * @file	FUiCtrlIExpandableEditAreaEventListener.h
 * @brief	This is the header file for the %IExpandableEditAreaEventListener interface.
 *
 * This header file contains the declarations of the %IExpandableEditAreaEventListener interface.
 */
#ifndef _FUI_CTRL_IEXPANDABLE_EDIT_AREA_EVENT_LISTENER_H_
#define _FUI_CTRL_IEXPANDABLE_EDIT_AREA_EVENT_LISTENER_H_

// includes
#include <FBaseRtIEventListener.h>
#include <FUiCtrlExpandableEditArea.h>

namespace Tizen { namespace Ui
{
class Control;
} } // Tizen::Ui

// namespace declaration
namespace Tizen { namespace Ui { namespace Controls
{
 /**
  * @interface	IExpandableEditAreaEventListener
  * @brief	    This interface defines a listener for the %ExpandableEditArea events.
  *
  * @since	    2.0
  *
  * The %IExpandableEditAreaEventListener interface is the listener interface for receiving %ExpandableEditArea events.
  *
  * For more information on the class features,
  * see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_exp_editarea.htm">ExpandableEditArea</a>.
  *
  */
class _OSP_EXPORT_ IExpandableEditAreaEventListener
	: public Tizen::Base::Runtime::IEventListener
{

// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since        2.0
	 */
	virtual ~IExpandableEditAreaEventListener(void) {}


// Operations
public:
	/**
	 * Called when a new line is added to ExpandableEditArea.
	 *
	 * @since       2.0
	 *
	 * @param[in]   source	        The source of the event
	 * @param[in]   newLineCount	The new line count
	 */
	virtual void OnExpandableEditAreaLineAdded(Tizen::Ui::Controls::ExpandableEditArea& source, int newLineCount) = 0;

	/**
	 * Called when a line is removed from ExpandableEditArea.
	 *
	 * @since       2.0
	 *
	 * @param[in]   source	        The source of the event
	 * @param[in]   newLineCount	The new line count
	 */
	virtual void OnExpandableEditAreaLineRemoved(Tizen::Ui::Controls::ExpandableEditArea& source, int newLineCount) = 0;


// Reserves
protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	//	 This method is reserved and may change its name at any time without prior notice.
	//
	//	 @since      2.0
	//
	virtual void IExpandableEditAreaEventListener_Reserved1(void) { }

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	//	 This method is reserved and may change its name at any time without prior notice.
	//
	//	 @since      2.0
	//
	virtual void IExpandableEditAreaEventListener_Reserved2(void) { }

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	//	 This method is reserved and may change its name at any time without prior notice.
	//
	//	 @since      2.0
	//
	virtual void IExpandableEditAreaEventListener_Reserved3(void) { }
};  // IExpandableEditAreaEventListener

}}} // Tizen::Ui::Controls

#endif //_FUI_CTRL_IEXPANDABLE_EDIT_AREA_EVENT_LISTENER_H_
