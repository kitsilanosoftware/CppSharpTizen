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
* @file			FWebWebBookmark.h
* @brief		This is the header file for the %WebBookmark class.
*
* This header file contains the declarations of the %WebBookmark class.
*/

#ifndef _FWEB_WEB_BOOKMARK_H_
#define _FWEB_WEB_BOOKMARK_H_

#include <FBaseString.h>
#include <FWebBookmarkItem.h>

namespace Tizen { namespace Graphics
{
class Bitmap;
}} // Tizen::Graphics

namespace Tizen { namespace Web
{
class _WebBookmarkImpl;

/**
 * @class		WebBookmark
 * @brief		This class provides methods to manage bookmark items of the browser.
 *
 * @since		2.1
 *
 * @final		This class is not intended for extension.
 *
 * The %WebBookmark class provides methods to get bookmark information of the browser and organize it.
 * The bookmark system has hierarchical structure with the parent folder ID supporting multiple folders and the bookmark items are represented by the BookmarkItem class. @n
 * If you use these APIs to backup and restore the bookmark, add bookmark items and folders recursively from the topmost level.
 */
class _OSP_EXPORT_ WebBookmark
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.1
	 */
	WebBookmark(void);

	/**
	 * This destructor overrides Osp::Base::Object::~Object().
	 *
	 * @since		2.1
 	 */
	virtual ~ WebBookmark(void);

	/**
	 * Initializes this instance of %WebBookmark.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Adds a bookmark folder.
	 *
	 * @since		2.1
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/bookmark.write
	 *
	 * @return		An error code
	 * @param[in]	title			The title of bookmark item
	 * @param[out]	folderId		The current folder ID
	 * @param[in]	parentId		The parent folder ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									 - The specified title is an empty string. @n
	 *									 - The specified @c parentId is invalid.
	 * @exception	E_OBJ_ALREADY_EXIST	A folder with the same title and parent ID already exists.
	 * @exception	E_SYSTEM			The method has failed.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @see	BookmarkItem::GetParentFolderId()
	 */
	result AddFolder(const Tizen::Base::String& title, RecordId& folderId, RecordId parentId = ROOT_FOLDER_ID);


	/**
	 * Adds bookmark contents.
	 *
	 * @since		2.1
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/bookmark.write
	 *
	 * @return		An error code
	 * @param[in]	title			The title of bookmark item
	 * @param[in]	url				The URL of bookmark item
	 * @param[out]	bookmarkId		The current bookmark ID
	 * @param[in]	parentId		The parent folder ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *									 - The specified @c title is an empty string. @n
	 *									 - The specified @c url is an empty string. @n
	 *									 - The specified @c parentId is invalid.
	 * @exception	E_OBJ_ALREADY_EXIST	A folder with the same title and parent ID already exists.
	 * @exception	E_SYSTEM			The method has failed.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @see	BookmarkItem::GetParentFolderId()
	 */
	result AddBookmark(const Tizen::Base::String& title, const Tizen::Base::String& url, RecordId& bookmarkId, RecordId parentId = ROOT_FOLDER_ID);

	/**
	 * Sets a favicon.
	 *
	 * @since		2.1
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/bookmark.write
	 *
	 * @return		An error code
	 * @param[in]	bookmarkId		The bookmark ID
	 * @param[in]	favicon			The favicon image
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c bookmarkId is invalid.
	 * @exception	E_INVALID_DATA		The specified @c favicon data is invalid.
	 * @exception	E_SYSTEM			The method has failed.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @see	BookmarkItem::GetFaviconN()
	 */
	result SetFavicon(RecordId bookmarkId, const Tizen::Graphics::Bitmap& favicon);

	/**
	 * Gets the bookmark item pointed to by the specified @c index.
	 *
	 * @since		2.1
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/bookmark.read
	 *
	 * @return		The bookmark item at the specified @c index
	 * @param[in]	index			The index of an element @n
	 *								The value of the @c index must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	const BookmarkItem* GetItemAt(int index) const;

	/**
	 * Gets the total number of items.
	 *
	 * @since		2.1
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/bookmark.read
	 *
	 * @return		The total number of items
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetItemCount(void) const;

	/**
	 * Removes all elements.
	 *
	 * @since		2.1
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/bookmark.write
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method has failed.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 */
	result RemoveAll(void);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	rhs				The instance of the %WebBookmark class to copy from
	// @remarks		This constructor is hidden.
	//
	WebBookmark(const WebBookmark & rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	rhs				An instance of %WebBookmark
	// @remarks		The method is declared but not implemented.
	//
	WebBookmark& operator=(const WebBookmark& rhs);

private:
	_WebBookmarkImpl * __pWebBookmarkImpl;

	friend class _WebBookmarkImpl;
}; // WebBookmark

}} // Tizen::Web
#endif // _FWEB_WEB_BOOKMARK_H_

