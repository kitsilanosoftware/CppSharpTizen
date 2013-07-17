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
 * @file		FWebHistoryItem.h
 * @brief		This is the header file for the %HistoryItem class.
 *
 * This header file contains the declarations of the %HistoryItem class.
 */
#ifndef _FWEB_HISTORY_ITEM_H_
#define _FWEB_HISTORY_ITEM_H_

#include <FBaseObject.h>
#include <FBaseString.h>

namespace Tizen { namespace Graphics
{
class Bitmap;
}} // Tizen::Graphics

namespace Tizen { namespace Web
{
class _HistoryItemImpl;
class _WebHistoryImpl;
}} // Tizen::Web

namespace Tizen { namespace Web { namespace Controls
{
class _WebImpl;
}}} // Tizen::Web::Controls

namespace Tizen { namespace Web
{

/**
 * @class		HistoryItem
 * @brief		This class is used for accessing a history item stored in the PageNavigationList class or the WebHistory class.
 *
 * @since		2.0
 *
 * The %HistoryItem class provides access to the Controls::PageNavigationList class item and the WebHistory class.
 * Each item contains the title and the URL of the page visited.
 */
class _OSP_EXPORT_ HistoryItem
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~HistoryItem(void);

	/**
	 * Gets the page title of the current history item.
	 *
	 * @since		2.0
	 *
	 * @return	The title of the current history item
	 */
	Tizen::Base::String GetTitle(void) const;

	/**
	 * Gets the URL of the current history item.
	 *
	 * @since		2.0
	 *
	 * @return	The URL of the current history item
	 */
	Tizen::Base::String GetUrl(void) const;

	/**
	 * Gets the favicon image from %HistoryItem.
	 *
	 * @since 	2.0
	 *
	 * @return		The image
	 *
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	Either of the following conditions has occurred: @n
	 *						- The method cannot proceed due to a severe system error. @n
	 *						- The method has failed because it does not work on a service application.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Bitmap* GetFaviconN(void) const;

private:
	//
	// This default constructor is intentionally declared as private to implement the Singleton semantic
	//
	// @remarks		This constructor is hidden.
	//
	HistoryItem(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	item		The instance of the %HistoryItem class to copy from
	// @remarks		This constructor is hidden.
	//
	HistoryItem(const HistoryItem& item);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	item		The instance of the %HistoryItem class to assign from
	// @remarks		This operator is hidden.
	//
	HistoryItem& operator =(const HistoryItem& item);

private:
	_HistoryItemImpl* __pHistoryItemImpl;

	friend class Tizen::Web::Controls::_WebImpl;

	friend class _HistoryItemImpl;

	friend class _WebHistoryImpl;
}; // HistoryItem

}} // Tizen::Web
#endif // _FWEB_HISTORY_ITEM_H_
