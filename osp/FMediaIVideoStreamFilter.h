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
 * @file			FMediaIVideoStreamFilter.h
 * @brief			This is the header file for the %IVideoStreamFilter interface.
 *
 * This header file contains the declarations of the %IVideoStreamFilter interface.
 */

#ifndef _FMEDIA_IVIDEO_STREAM_FILTER_H
#define _FMEDIA_IVIDEO_STREAM_FILTER_H

namespace Tizen { namespace Media
{
class VideoFrame;

/**
 * @interface	IVideoStreamFilter
 * @brief		This interface represents a filter that processes the video stream data.
 *
 * @since		2.1
 *
 * The %IVideoStreamFilter interface represents a filter that processes the video stream data.
 *
 */
class _OSP_EXPORT_ IVideoStreamFilter
{

public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when
	* the destructor of this interface is called.
	*
	* @since		2.1
	*/
	virtual ~IVideoStreamFilter(void) {}

	/**
	*	Process a video frame.
	*
	* @since		2.1
	*
	* @param[in,out]	frame		A frame object containing the video frame data
	* @remarks This method should not contain any operations that harm thread safety or cause performance degradation.
	*/
	virtual void ProcessVideoStream(VideoFrame& frame) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.1
	//
	virtual void IVideoStreamFilter_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.1
	//
	virtual void IVideoStreamFilter_Reserved2(void) {}
};

}}// Tizen::Media

#endif
