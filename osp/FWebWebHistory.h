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
 * @file		FWebWebHistory.h
 * @brief		This is the header file for the %WebHistory class.
 * @since		2.0
 *
 * This header file contains the declarations of the %WebHistory class.
 */
#ifndef _FWEB_WEB_HISTORY_H_
#define _FWEB_WEB_HISTORY_H_

#include <FBaseObject.h>

namespace Tizen { namespace Web
{
class HistoryItem;
class _WebHistoryImpl;
}} // Tizen::Web

namespace Tizen { namespace Web
{

/**
 * @class		WebHistory
 * @brief		This class contains the pages visited by users in a browser.
 *
 * @since		2.0
 *
 * The %WebHistory class is used to retrieve the pages visited by users in a browser. The visited pages are represented by the HistoryItem class.
 * The WEB_PRIVACY privilege is required to use this class.
 *
 */
class _OSP_EXPORT_ WebHistory
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called.  @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	WebHistory(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~WebHistory(void);

	/**
	 * Initializes this instance of %WebHistory.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Gets the history item pointed to by the specified @c index.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.privacy
	 *
	 * @return		The history item at the specified @c index
	 * @param[in]	index			The index of an element @n
	 *								The value of the index must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const HistoryItem* GetItemAt(int index) const;

	/**
	 * Gets the total number of items.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.privacy
	 *
	 * @return		The total number of items
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetItemCount(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	item			The instance of the %WebHistory class to copy from
	// @remarks		This constructor is hidden.
	//
	WebHistory(const WebHistory& item);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	item			The instance of the %WebHistory class to assign from
	// @remarks		This operator is hidden.
	//
	WebHistory& operator =(const WebHistory& item);

private:
	_WebHistoryImpl* __pWebHistoryImpl;

	friend class _WebHistoryImpl;
}; // WebHistory

}} // Tizen::Web
#endif // _FWEB_WEB_HISTORY_H_
