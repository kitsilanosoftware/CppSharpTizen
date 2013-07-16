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
* @file				FMediaIPlayerProgressiveDownloadListener.h
* @brief			This is the header file for the %IPlayerProgressiveDownloadListener interface.
*
* This header files contains the declarations of the %IPlayerProgressiveDownloadListener interface.
*
*/
#ifndef _FMEDIA_IPLAYER_PROGRESSIVE_DOWNLOAD_LISTENER_H_
#define _FMEDIA_IPLAYER_PROGRESSIVE_DOWNLOAD_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Media
{
/**
* @interface	IPlayerProgressiveDownloadListener
* @brief		This interface provides a listener that receives events associated with the progressive download playback.
*
* @since		2.0
*
* The %IPlayerProgressiveDownloadListener interface specifies the methods used to notify when the application starts, or completes progressive download.
*/
class _OSP_EXPORT_ IPlayerProgressiveDownloadListener
		: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since		2.0
	*/
	virtual ~IPlayerProgressiveDownloadListener(void) { }

	/**
	* Called when the progressive download has started.
	*
	* @since		2.0
	*
	* @param[in]	player					An instance of Player that fires the event
	*/
	virtual void OnPlayerProgressiveDownloadStarted(Player& player) = 0;

	/**
	* Called when the progressive download is in progress.
	*
	* @since		2.0
	*
	* @param[in]	player					An instance of Player that fires the event
	* @param[in]	downloadedSize		The total downloaded size in bytes
	* @param[in]	totalSize				The total size in bytes
	*/
	virtual void OnPlayerProgressiveDownloadInProgress(Player& player, int downloadedSize, int totalSize) = 0;


	/**
	* Called when the progressive download has completed.
	*
	* @since		2.0
	*
	* @param[in]	player					An instance of Player that fires the event
	* @param[in]	r						The result of progressive download
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_STORAGE_FULL			The storage is full.
	* @exception	E_INACCESSIBLE_PATH		The file path is invalid to store media data.
	*/
	virtual void OnPlayerProgressiveDownloadCompleted(Player& player, result r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since		2.0
	//
	virtual void IPlayerProgressiveDownloadEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since		2.0
	//
	virtual void IPlayerProgressiveDownloadEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since		2.0
	//
	virtual void IPlayerProgressiveDownloadEventListener_Reserved3(void) {}

};
}}			//Tizen::Media
	#endif
