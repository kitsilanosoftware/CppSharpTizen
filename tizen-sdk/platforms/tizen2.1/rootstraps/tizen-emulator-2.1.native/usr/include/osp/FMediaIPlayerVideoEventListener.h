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
 * @file		FMediaIPlayerVideoEventListener.h
 * @brief		This is the header file for the %IPlayerVideoEventListener interface.
 *
 * This header file contains the declarations of the %IPlayerVideoEventListener interface.
 */

#ifndef _FMEDIA_IPLAYER_VIDEO_EVENT_LISTENER_H_
#define _FMEDIA_IPLAYER_VIDEO_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseDataType.h>
#include <FGrpDimension.h>
#include <FGrpBitmapCommon.h>
#include <FMediaPlayerTypes.h>

namespace Tizen { namespace Media
{
class Player;
/**
 * @interface	IPlayerVideoEventListener
 * @brief			This interface provides a listener for the video event.
 *
 * @since		2.0
 *
 * The %IPlayerVideoEventListener interface specifies the method used to get the decoded video frame.
 */

class _OSP_EXPORT_ IPlayerVideoEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since		2.0
	*/
	virtual ~IPlayerVideoEventListener(void) {}

	/**
	*	Called when the video frame is decoded asynchronously.
	*
	*   @since		2.0
	*
	*	@param[in]	 src				An instance of Player that fires the event
	*	@param[in]	 bitmapPixelFormat	A pixel format type of the decoded video frame
	*	@param[in]	 dim				A dimension of the decoded video frame
	*	@param[in]	 pBuffer			A pointer to a decoded video frame buffer
	*	@param[in]	 sizeOfBuffer		A size of a buffer
	*   @param[in]	 r					The cause of the error
	*	@exception	 E_SUCCESS							The method is successful.
	*	@exception	 E_SYSTEM							A system error has occurred.
	*	@exception	 E_INVALID_DATA	                    The video frame has invalid blocks.
	*	@remarks	The lifecycle of @c pBuffer is valid inside this method.
	*	@see		Player::Play()
	*	@see		Player::PlayAndPause()
	*	@see		Player::SeekTo()
	*/
	virtual void OnVideoFrameDecoded(Tizen::Media::Player& src, Tizen::Graphics::BitmapPixelFormat bitmapPixelFormat, const Tizen::Graphics::Dimension& dim, const byte* pBuffer, int sizeOfBuffer, result r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IPlayerVideoEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void IPlayerVideoEventListener_Reserved2(void) {}

};

}}// Tizen::Media

#endif
