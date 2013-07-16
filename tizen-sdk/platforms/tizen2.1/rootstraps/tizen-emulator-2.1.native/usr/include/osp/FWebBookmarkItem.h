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
 * @file		FWebBookmarkItem.h
 * @brief		This is the header file for the %BookmarkItem class.
 *
 * This header file contains the declarations of the %BookmarkItem class.
 */

#ifndef _FWEB_BOOKMARK_ITEM_H_
#define _FWEB_BOOKMARK_ITEM_H_

#include <FBaseString.h>

namespace Tizen { namespace Graphics
{
class Bitmap;
}} // Tizen::Graphics

namespace Tizen { namespace Web
{
class _BookmarkItemImpl;

/**
 * A unique ID. This ID is unique within a local storage only. @n
 * @c RecordId is assigned by the local storage when a record is saved to the storage.
 * 
 *
 * @since		2.1
 */
typedef int RecordId;

/**
 * The root folder ID. @n
 * In fact, it is a symbolic value because the root folder record does not exist physically.
 *
 * @since		2.1
 */
const RecordId ROOT_FOLDER_ID = -1;

/**
* @class		BookmarkItem
* @brief		This class is used for accessing a bookmark item stored in the WebBookmark class.
*
* @since		2.1
*
* @final		This class is not intended for extension.
*
* The %BookmarkItem class provides access to the WebBookmark class.
* Each item contains the title, the URL of the page, the item type, and the parent folder ID.
*/
class _OSP_EXPORT_ BookmarkItem
	: public Tizen::Base::Object
{
public:

	/**
	 * Copying of objects using this copy constructor is allowed.
	 * This is the copy constructor for the %BookmarkItem class. @n
	 * It creates an instance of %BookmarkItem with the values of the specified instance.
	 *
	 * @since		2.1
	 *
	 * @param[in] rhs An instance of %BookmarkItem
	 */
	BookmarkItem(const BookmarkItem& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.1
	 */
	virtual ~BookmarkItem(void);

	/**
	 * Gets the title from the current bookmark item.
	 *
	 * @since		2.1
	 *
	 * @return		The title of the current bookmark item
	 */
	Tizen::Base::String GetTitle(void) const;

	/**
	 * Gets the URL from the current bookmark item.
	 *
	 * @since		2.1
	 *
	 * @return		The URL of the current bookmark item @n
	 * 				If the item type is folder, this method will return an empty string.
	 * @see	IsFolder()
	 */
	Tizen::Base::String GetUrl(void) const;

	/**
	 * Gets the favicon image from the current bookmark item.
	 *	 
	 * @since		2.1
	 *
	 * @return		The image
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	Either of the following conditions has occurred: @n
	 *						- The method cannot proceed due to a severe system error. @n
	 *						- The method has failed because it does not work on a service application.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Bitmap* GetFaviconN(void) const;

	/**
	 * Gets the parent folder ID of the current bookmark item. 
	 *
	 * @since		2.1
	 *
	 * @return		The parent folder ID of the current bookmark item @n
	 *				If the current bookmark item is the one in topmost level, this method will return ::ROOT_FOLDER_ID.
	 */
	RecordId GetParentFolderId(void) const;

	/**
	 * Checks whether the type of the current bookmark item is folder or not.
	 *
	 * @since		2.1
	 *
	 * @return		@c true if the type of the current bookmark item is folder, @n
	 *					else @c false
	 */
	bool IsFolder(void) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since		2.1
	 *
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Compares two instances of the %BookmarkItem class.
	 *
	 * @since		2.1
	 *
	 * @return		@c true if the two instances match, or if and only if the two instances contain the same elements, @n
	 *					else @c false @n
	 * @param[in]	obj				The object to compare with the current instance
 	 * @see	Tizen::Base::Object::Equals()
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed. 
	 *
	 * @since		2.1
	 *
	 * @param[in]	rhs			The instance of the %BookmarkItem class to assign from
	 */
	BookmarkItem& operator =(const BookmarkItem& rhs);

private:
	//
	// This default constructor is intentionally declared as private to implement the Singleton semantic
	//
	// @remarks	This constructor is hidden.
	//
	BookmarkItem(void);

private:
	_BookmarkItemImpl* __pBookmarkItemImpl;

	friend class _BookmarkItemImpl;

	friend class _WebBookmarkImpl;
};

}}
#endif // _FWEB_BOOKMARK_ITEM_H_
