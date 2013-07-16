//
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
 * @file		FCntPlayList.h
 * @brief		This is the header file for the %PlayList class.
 *
 * This header file contains the declarations of the %PlayList class.
 */

#ifndef _FCNT_CONTENT_PLAYLIST_H_
#define _FCNT_CONTENT_PLAYLIST_H_

#include <FBaseString.h>
#include <FCntTypes.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}

namespace Tizen { namespace Content
{

class _PlayListImpl;

/**
 *	@class          PlayList
 *	@brief          This class provides methods for a playlist information.
 *
 *	@since         2.0
 *
 *	@final       This class is not intended for extension.
 *
 *	The %PlayList class provides methods to access a playlist information.
 *	The methods of this class are immediately access to the database and update.
 *
 *	The following example demonstrates how to use the %PlayList class.
 *
 *	@code
 *	#include <FContent.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *	using namespace Tizen::Content;
 *
 *	void
 *	MyClass::Test(void)
 *	{
 *		// Get an instance of PlayList
 *		PlayList playList;
 *		result r = playList.Construct("my_playlist_1");
 *		if (IsFailed(r))
 *		{
 *
 *		}
 *
 *		IList* pList = playList.GetContentInfoListN();
 *		if (IsFailed(r))
 *		{
 *
 *		}
 *
 *		// Delete resource
 *		pList->RemoveAll(true);
 *		delete pList;
 *	}
 *
 *	@endcode
 *
 */
class _OSP_EXPORT_ PlayList
	: public Tizen::Base::Object
{

public:

	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	PlayList(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~PlayList(void);

	/**
	 * Initializes this instance of %PlayList with the specified parameter.
	 *
	 * @since 2.0
	 *
	 * @return    An error code
	 * @param[in] playListName The playlist name
	 * @exception E_SUCCESS              The method is successful.
	 * @exception E_INVALID_ARG        The specified input parameter is invalid.
	 * @exception E_OUT_OF_MEMORY  The memory is insufficient.
	 * @exception E_SERVICE_BUSY       The database is busy.
	 * @exception E_DATABASE       The method cannot access the database.
	 */
	result Construct(const Tizen::Base::String& playListName);

	/**
	 * Gets the count of playlist items.
	 *
	 * @since 2.0
	 *
	 * @return    The item count
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_SERVICE_BUSY       The database is busy.
	 * @exception E_DATABASE              The method cannot access the database.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetPlayListItemCount(void) const;

	/**
	 * Gets the list of playlist items.
	 *
	 * @since 2.0
	 *
	 * @return    The list that contains playlist items as ContentInfo class
	 * @exception E_SUCCESS              The method is successful.
	 * @exception E_OUT_OF_MEMORY  The memory is insufficient.
	 * @exception E_SERVICE_BUSY       The database is busy.
	 * @exception E_DATABASE               The method cannot access the database.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetContentInfoListN(void) const;

	/**
	 * Adds the item to the playlist.
	 *
	 * @since 2.0
	 *
	 * @return    An error code
	 * @param[in] contentId The content ID
	 * @exception E_SUCCESS          The method is successful.
	 * @exception E_INVALID_ARG    The specified input parameter is invalid.
	 * @exception E_SERVICE_BUSY   The database is busy.
	 * @exception E_DATABASE           The method cannot access the database.
	 * @see AddItems(const Tizen::Base::Collection::IList&)
	 */
	result AddItem(const ContentId& contentId);

	/**
	 * Adds the items to the playlist.
	 *
	 * @since 2.0
	 *
	 * @return    An error code
	 * @param[in] contentIdList The list that contains ContentId
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG    The specified input parameter is invalid.
	 * @exception E_SERVICE_BUSY   The database is busy.
	 * @exception E_DATABASE          The method cannot access the database.
	 * @see AddItem(const ContentId&)
	 */
	result AddItems(const Tizen::Base::Collection::IList& contentIdList);

	/**
	 * Removes the item from the playlist.
	 *
	 * @since 2.0
	 *
	 * @return    An error code
	 * @param[in] contentId The content ID
	 * @exception E_SUCCESS            The method is successful.
	 * @exception E_INVALID_ARG      The specified input parameter is invalid.
	 * @exception E_OBJ_NOT_FOUND The specified @c contentId is not found.
	 * @exception E_SERVICE_BUSY     The database is busy.
	 * @exception E_DATABASE            The method cannot access the database.
	 * @see RemoveItems(const Tizen::Base::Collection::IList&)
	 */
	result RemoveItem(const ContentId& contentId);

	/**
	 * Removes the items from the playlist.
	 *
	 * @since 2.0
	 *
	 * @return    An error code
	 * @param[in] contentIdList The list that contains ContentId
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_INVALID_ARG       The specified input parameter is invalid.
	 * @exception E_OBJ_NOT_FOUND   The specified @c contentId in the list is not found.
	 * @exception E_SERVICE_BUSY       The database is busy.
	 * @exception E_DATABASE               The method cannot access the database.
	 * @see RemoveItem(const ContentId&)
	 */
	result RemoveItems(const Tizen::Base::Collection::IList& contentIdList);  

	/**
	 * Gets the playlist name.
	 *
	 * @since 2.0
	 *
	 * @return    The playlist name
	 */
	Tizen::Base::String GetPlayListName(void) const;   

	/**
	 * Sets the playlist name.
	 *
	 * @since 2.0
	 *
	 * @return     An error code
	 * @param[in] playListName      The playlist name
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception E_OUT_OF_MEMORY  The memory is insufficient.
	 * @exception E_SERVICE_BUSY  The database is busy.
	 * @exception E_DATABASE          The method cannot access the database.
	 */
	result SetPlayListName(const Tizen::Base::String& playListName);

	/**
	 * Gets the play order.
	 *
	 * @since 2.0
	 *
	 * @return    The play order
	 * @param[in] contentId The content ID
	 * @exception E_SUCCESS            The method is successful.
	 * @exception E_INVALID_ARG      The specified input parameter is invalid.
	 * @exception E_OBJ_NOT_FOUND The specified @c contentId is not found.
	 * @exception E_SERVICE_BUSY      The database is busy.
	 * @exception E_DATABASE              The method cannot access the database.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetPlayOrder(const ContentId& contentId) const;

private:

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	PlayList(const PlayList& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	PlayList& operator =(const PlayList& rhs);

	friend class _PlayListImpl;
	_PlayListImpl* __pImpl;

	Tizen::Base::String __playListName;

	friend class _PlayListManagerImpl;

	result ConstructPlayList(const Tizen::Base::String& playListName);

};  // class PlayList

}}  // Tizen::Content

#endif  // _FCNT_CONTENT_PLAYLIST_H_
