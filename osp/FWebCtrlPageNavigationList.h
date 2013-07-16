//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
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
 * @file		FWebCtrlPageNavigationList.h
 * @brief		This is the header file for the %PageNavigationList class.
 *
 * This header file contains the declarations of the %PageNavigationList class.
 */
#ifndef _FWEB_CTRL_PAGE_NAVIGATION_LIST_H_
#define _FWEB_CTRL_PAGE_NAVIGATION_LIST_H_

#include <FBaseObject.h>
#include <FBaseColIList.h>


namespace Tizen { namespace Web { namespace Controls
{
class _PageNavigationListImpl;
}}} // Tizen::Web::Controls

namespace Tizen { namespace Web
{
class HistoryItem;
}} // Tizen::Web

namespace Tizen { namespace Web { namespace Controls
{

/**
 * @class		PageNavigationList
 * @brief		This class contains the back and forward list for a %Web control.
 *
 * @since		2.0
 *
 * The %PageNavigationList class provides the back and forward list for a %Web control.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/controls_namespace.htm">Web Controls Guide</a>.
 */
class _OSP_EXPORT_ PageNavigationList
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~PageNavigationList(void);

	/**
	 * Gets the current history item.
	 *
	 * @since		2.0
	 *
	 * @return		The current history item, @n
	 *					else @c null if no history item exists
	 */
	const Tizen::Web::HistoryItem* GetCurrentItem(void) const;

	/**
	 * Gets the index of the current history item.
	 *
	 * @since		2.0
	 *
	 * @return		The index of the currently viewed page in the web page navigation list, @n
	 *					else @c -1 if no history item exists
	 */
	int GetCurrentIndex(void) const;

	/**
	 * Gets the history item pointed to by the specified @c index.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the history item at the specified @c index
	 * @param[in]	index			The index of an element @n
	 *								The value of the index must be greater than or equal to @c 0.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const Tizen::Web::HistoryItem* GetItemAt(int index) const;

	/**
	 * Gets the total number of the history items.
	 *
	 * @since		2.0
	 *
	 * @return		The total number of items
	 */
	int GetItemCount(void) const;

private:
	//
	// This constructor is intentionally declared as private so that only the platform can create an instance.
	//
	// @remarks		This constructor is hidden.
	//
	PageNavigationList(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	item			The instance of the %PageNavigationList class to copy from
	// @remarks		This constructor is hidden.
	//
	PageNavigationList(const PageNavigationList& item);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	item			The instance of the %PageNavigationList class to assign from
	// @remarks		This operator is hidden.
	//
	PageNavigationList& operator =(const PageNavigationList& item);

private:
	_PageNavigationListImpl* __pPageNavigationListImpl;

	friend class _PageNavigationListImpl;

	friend class _WebImpl;
}; // PageNavigationList

}}} // Tizen::Web::Controls
#endif // _FWEB_CTRL_PAGE_NAVIGATION_LIST_H_
