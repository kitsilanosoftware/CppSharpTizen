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
 * @file	FGrpIVideoTextureUpdateListener.h
 * @brief	This is the header file for the %IVideoTextureUpdateListener class.
 *
 * This header file contains the declarations of the %IVideoTextureUpdateListener class.
 *
 */

#ifndef _FGRP_IVIDEO_TEXTURE_UPDATE_LISTENER_H_
#define _FGRP_IVIDEO_TEXTURE_UPDATE_LISTENER_H_

namespace Tizen { namespace Graphics { namespace Opengl
{

class VideoTexture;

/**
 * @class	IVideoTextureUpdateListener
 * @brief	This virtual class defines the interface for VideoTexture to register a listener.
 * @since 2.0
 *
 */
class _OSP_EXPORT_ IVideoTextureUpdateListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IVideoTextureUpdateListener(void) {}

	/**
	 * Called when a video frame on the texture is ready.
	 *
	 * @since 2.0
	 *
	 * @param[in]	pVideoTexture	The VideoTexture class.
	 */
	virtual void OnTextureUpdated(VideoTexture* pVideoTexture) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IVideoTextureUpdateListener_Reserved1(void) {}
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IVideoTextureUpdateListener_Reserved2(void) {}
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void IVideoTextureUpdateListener_Reserved3(void) {}
}; // IVideoTextureUpdateListener

}}} // Tizen::Graphics

#endif //_FGRP_IVIDEO_TEXTURE_UPDATE_LISTENER_H_