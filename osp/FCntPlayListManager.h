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
 * @file		FCntPlayListManager.h
 * @brief		This is the header file for the %PlayListManager class.
 *
 * This header file contains the declarations of the %PlayListManager class.
 */

#ifndef _FCNT_CONTENT_PLAYLIST_MANAGER_H_
#define _FCNT_CONTENT_PLAYLIST_MANAGER_H_

#include <FBaseString.h>
#include <FCntTypes.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}

namespace Tizen { namespace Content
{

class PlayList;
class _PlayListManagerImpl;

/**
 *	@class       PlayListManager
 *	@brief       This class provides methods to manage the playlist.
 *
 *	@since      2.0
 *
 *	@final       This class is not intended for extension.
 *
 *	The %PlayListManager class provides methods to manage the playlist.
 *	The methods of this class are immediately access to the database and update.
 *
 *	The following example demonstrates how to use the %PlayListManager class.
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
 *		// Call an instance of PlayListManager
 *		PlayListManager* pManager = PlayListManager::GetInstance();
 *		if (IsFailed(GetLastResult()))
 *		{
 *
 *		}
 *
 *		IList* pList = pManager->GetAllPlayListNameN();
 *		if (IsFailed(GetLastResult()))
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
 */
class _OSP_EXPORT_ PlayListManager
	: public Tizen::Base::Object
{

public:

	/**
	 * Gets the playlist.
	 *
	 * @since 2.0
	 *
	 * @return     A pointer to the PlayList instance
	 * @param[in] playListName The playlist name
	 * @exception E_SUCCESS             The method is successful.
	 * @exception E_INVALID_ARG       The specified input parameter is invalid.
	 * @exception E_OUT_OF_MEMORY The memory is insufficient.
	 * @exception E_SERVICE_BUSY      The database is busy.
	 * @exception E_DATABASE              The method cannot access the database.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	PlayList* GetPlayListN(const Tizen::Base::String& playListName) const;

	/**
	 * Removes the playlist.
	 *
	 * @since 2.0
	 *
	 * @return     An error code
	 * @param[in] playListName The playlist name
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception E_SERVICE_BUSY  The database is busy.
	 * @exception E_DATABASE          The method cannot access the database.
	 */
	result RemovePlayList(const Tizen::Base::String& playListName);

	/**
	 * Gets the count of all playlists.
	 *
	 * @since 2.0
	 *
	 * @return     The count of all playlists
	 * @exception E_SUCCESS         The method is successful.
	 * @exception E_SERVICE_BUSY  The database is busy.
	 * @exception E_DATABASE          The method cannot access the database.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetAllPlayListCount(void) const;

	/**
	 * Gets all playlist names.
	 *
	 * @since 2.0
	 *
	 * @return      The list that contains playlist names as Tizen::Base::String class
	 * @exception E_SUCCESS              The method is successful.
	 * @exception E_OUT_OF_MEMORY  The memory is insufficient.
	 * @exception E_SERVICE_BUSY       The database is busy.
	 * @exception E_DATABASE               The method cannot access the database.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetAllPlayListNameN(void) const;

	/**
	 * Gets the playlist manager instance.
	 *
	 * @since 2.0
	 *
	 * @return      A pointer to the %PlayListManager instance
	 * @exception E_SUCCESS              The method is successful.
	 * @exception E_OUT_OF_MEMORY  The memory is insufficient.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	static PlayListManager* GetInstance(void);

private:

	static PlayListManager* __pPlayListManager;

	/**
	 * This default constructor is intentionally declared as private to implement the Singleton semantic.
	 */
	PlayListManager(void);

	/**
	 * This destructor is intentionally declared as private to implement the Singleton semantic.
	 */
	virtual ~PlayListManager(void);

	/**
	 * This constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	result Construct(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	PlayListManager(const PlayListManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	PlayListManager & operator =(const PlayListManager& rhs);

	friend class _PlayListManagerImpl;
	_PlayListManagerImpl* __pImpl;

	static void InitSingleton(void);
	static void DestroySingleton(void);

};  // class PlayListManager

}}  // Tizen::Content

#endif  // _FCNT_CONTENT_PLAYLIST_MANAGER_H_
