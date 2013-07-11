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
 * @file			FMediaIImageEventListener.h
 * @brief			This is the header file for the %IImageDecodeUrlEventListener interface.
 *
 * This header file contains the declarations of the %IImageDecodeUrlEventListener interface.
 */

#ifndef _FMEDIA_IIMAGE_EVENT_LISTENER_H_
#define _FMEDIA_IIMAGE_EVENT_LISTENER_H_

#include <FBase.h>
#include <FGraphics.h>
#include <FMediaImageTypes.h>

namespace Tizen { namespace Media
{

/**
 * @interface	IImageDecodeUrlEventListener
 * @brief		This interface provides a listener that receives events associated with the Image::DecodeUrl() method.
 *
 * @since		2.0
 *
 * The %IImageDecodeUrlEventListener interface provides a listener that receives events associated with the Image::DecodeUrl() method, including specifying the methods used to get the decoded bitmap data from the remote URL.
 * The %Image::DecodeUrl() method works asynchronously. Therefore, it is important to implement this listener to ensure that the decoding flows correctly.
 * When an operation of each method is completed, an event is generated and a method of this interface is called.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/viewing_processing_still_images.htm">Viewing and Processing Still Images</a>.
 */
class _OSP_EXPORT_ IImageDecodeUrlEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	* This is the destructor for this class.
	*
	* @since		2.0
	*/
	virtual ~IImageDecodeUrlEventListener(void) {}

	/**
	* Called when a Image::DecodeUrl() operation is completed.
	*
	* @since		2.0
	*
	* @param[in]	reqId		  The requested ID
	* @param[in]	pBitmap		  The downloaded bitmap data
	* @param[in]	r			  The result of the upload
	* @param[in]	errorCode	  The error code
	* @param[in]	errorMessage  The error message
	* @remarks	The Image object must not be deleted in this event listener. @n@n
	*			This method passes auto-scaled bitmap, @n
	*			so the dimension can be different to the requested dimension when the passed bitmap is locked.
	* @see		Image::DecodeUrl()
	*/
	virtual void OnImageDecodeUrlReceived(RequestId reqId, Tizen::Graphics::Bitmap* pBitmap, result r, const Tizen::Base::String errorCode, const Tizen::Base::String errorMessage) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IImageDecodeUrlEventListener_Reserved1(void){}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IImageDecodeUrlEventListener_Reserved2(void){}

}; // class IImageDecodeUrlEventListener

};
};   // Tizen::Media

#endif
