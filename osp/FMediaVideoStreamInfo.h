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
 * @file			FMediaVideoStreamInfo.h
 * @brief			This is the header file for the %VideoStreamInfo class.
 *
 * This header file contains the declarations of the %VideoStreamInfo class.
 */

#ifndef _FMEDIA_VIDEO_STREAM_INFO_H_
#define _FMEDIA_VIDEO_STREAM_INFO_H_

#include <FBaseObject.h>
#include <FMediaTypes.h>

namespace Tizen { namespace Media
{
/**
 * @class	 VideoStreamInfo
 * @brief	 This class provides methods to get video information.
 *
 * @since		2.0
 *
 * The %VideoStreamInfo class provides methods to get video stream information, such as codec type, video width or height, bit rate,
 * and frame rate.
 *
 */

class _OSP_EXPORT_ VideoStreamInfo
	: public Tizen::Base::Object
{
public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*/
	virtual ~VideoStreamInfo(void);

public:
	/**
	* Gets the encoding type of a video.
	*
	* @since		2.0
	*
	* @return			 The value of the encoding type
	*/
	CodecType GetCodecType(void) const;

	/**
	* Gets the width of a video.
	*
	* @since		2.0
	*
	* @return			 The value of the video width
	*/
	int GetWidth(void) const;

	/**
	* Gets the height of a video.
	*
	* @since		2.0
	*
	* @return			 The value of the video height
	*/
	int GetHeight(void) const;

	/**
	* Gets the bit rate of a video.
	*
	* @since		2.0
	*
	* @return			 The video bit rate in bits per second (bps)
	*/
	int GetBitRate(void) const;

	/**
	* Gets the frame rate of a video.
	*
	* @since		2.0
	*
	* @return			 The video frame rate
	*/
	float GetFrameRate(void) const;

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since		2.0
	*
	* @return		The copy of this instance
	* @param[in] rhs An instance of %VideoStreamInfo
	*/
	VideoStreamInfo(const VideoStreamInfo & rhs);

	/**
	* Copying of objects using this copy assignment operator is allowed.
	*
	* @since		2.0
	*
	* @return The reference of this instance
	* @param[in] rhs An instance of %VideoStreamInfo
	*/
	VideoStreamInfo & operator =(const VideoStreamInfo & rhs);

	/**
	* Compares the specified instance of Tizen::Base::Object with the calling instance of %VideoStreamInfo.
	*
	* @since		2.0
	*
	* @return						  @c true if the value of the specified instance equals the value of the current instance, @n
	*		 else @c false
	* @param[in]	   rhs					  The object to compare with the current instance
	*/
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	* Gets the hash value of the current instance.
	*
	* @since		2.0
	*
	* @return						  The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @param [in]	codecType	The value of the encoding type
	* @param [in]	width		The value of the video width
	* @param [in]	height		The value of the video height
	* @param [in]	bitrate		The video bit rate in bits per second (bps)
	* @param [in]	frameRate	The video frame rate
	*/
	VideoStreamInfo(CodecType codecType, int width, int height, int bitrate, float frameRate);

private:
	friend class _PlayerImpl;
	class _VideoStreamInfoImpl *__pVideoStreamInfoImpl;
};

}}//Tizen::Media


#endif
