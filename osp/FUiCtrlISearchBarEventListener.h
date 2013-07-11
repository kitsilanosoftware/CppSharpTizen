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
 * @file		FUiCtrlISearchBarEventListener.h
 * @brief		This is the header file for the %ISearchBarEventListener interface.
 *
 * This header file contains the declarations of the %ISearchBarEventListener interface.
 */
#ifndef _FUI_CTRL_ISEARCH_BAR_EVENT_LISTENER_H_
#define _FUI_CTRL_ISEARCH_BAR_EVENT_LISTENER_H_

// Includes
#include <FBaseRtIEventListener.h>
#include <FUiCtrlSearchBar.h>

// Namespace declaration
namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @interface	ISearchBarEventListener
 * @brief	    This interface implements the listener for the SearchBar events.
 *
 * @since	    2.0
 *
 * The %ISearchBarEventListener interface is the listener interface for receiving SearchBar events.
 * The class that processes a search bar event implements this interface, and the instance created with that class is registered
 *  with a UI control, using the control's AddSearchBarEventListener() method. When the search bar event occurs, the
 *  OnSearchBarModeChanged() method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_searchbar.htm">SearchBar</a>.
 */
class _OSP_EXPORT_ ISearchBarEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~ISearchBarEventListener(void) {}


// Operation
public:
	/**
	 * Called when the mode of the SearchBar is changed.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since		2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *						For more information, see @ref CompSearchModeChangedPage "here"
	 * @endif
	 * @param[in]	source  The source of the event
	 * @param[in]	mode    The current search bar mode.
	 */
	virtual void OnSearchBarModeChanged(Tizen::Ui::Controls::SearchBar& source, SearchBarMode mode) = 0;
	/**
	 * @page               CompSearchModeChangedPage        Compatibility for OnSearchBarModeChanged()
	 * @section            CompSearchModeChangedPage IssueSection          Issues
	 * Implementing this method in OSP compatible applications has following issue: @n
	 * OnSearchBarModeChanged() method modifies the visibility of the current Form's Header in OSP,
	 * whereas current Form's header visibility is not modified in Tizen.
	 *
	 * @section            CompSearchModeChangedPage SolutionSection               Resolutions
	 * It is recommended to use Tizen API. @n
	 */

// Reserves
protected:
	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	//This method is reserved and may change its name at any time without prior notice.
	//
	//@since      2.0
	//
	virtual void ISearchBarEventListener_Reserved1(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	//This method is reserved and may change its name at any time without prior notice.
	//
	//@since      2.0
	//
	virtual void ISearchBarEventListener_Reserved2(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	//This method is reserved and may change its name at any time without prior notice.
	//
	//@since      2.0
	//
	virtual void ISearchBarEventListener_Reserved3(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	//This method is reserved and may change its name at any time without prior notice.
	//
	//@since      2.0
	//
	virtual void ISearchBarEventListener_Reserved4(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	//This method is reserved and may change its name at any time without prior notice.
	//
	//@since      2.0
	//
	virtual void ISearchBarEventListener_Reserved5(void) { }

}; // ISearchBarEventListener

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ISEARCH_BAR_EVENT_LISTENER_H_
