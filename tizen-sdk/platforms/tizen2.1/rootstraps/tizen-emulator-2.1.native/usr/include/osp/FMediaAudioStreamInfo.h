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
 * @file			FMediaAudioStreamInfo.h
 * @brief			This is the header file for the %AudioStreamInfo class.
 *
 * This header file contains the declarations of the %AudioStreamInfo class.
 */

#ifndef _FMEDIA_AUDIO_STREAM_INFO_H_
#define _FMEDIA_AUDIO_STREAM_INFO_H_

#include <FBaseObject.h>
#include <FMediaAudioTypes.h>
#include <FMediaTypes.h>

namespace Tizen { namespace Media
{
/**
 * @class	 AudioStreamInfo
 * @brief	 This class provides methods to get audio stream information.
 *
 * @since		2.0
 *
 * The %AudioStreamInfo class provides methods to get audio stream information, such as codec type, bit rate, sample rate, and channel count.
 *
 */

class _OSP_EXPORT_ AudioStreamInfo
	: public Tizen::Base::Object
{
public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*/
	virtual ~AudioStreamInfo(void);

public:
	/**
	* Gets the encoding type of an audio stream.
	*
	* @since		2.0
	*
	* @return		The value of the encoding type
	*
	*/
	CodecType GetCodecType(void) const;

	/**
	* Gets the bit rate of an audio.
	*
	* @since		2.0
	*
	* @return			 The audio bit rate in bits per second (bps)
	*/
	int GetBitRate(void) const;

	/**
	* Gets the sampling rate of an audio.
	*
	* @since		2.0
	*
	* @return			 The audio sampling rate in Hertz (Hz)
	*/
	int GetSampleRate(void) const;

	/**
	* Gets the audio channel of an audio.
	*
	* @since		2.0
	*
	* @return			 The audio channel type
	*/
	AudioChannelType GetChannelType(void) const;

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since		2.0
	*
	* @return		The copy of this instance
	* @param[in] rhs An instance of %AudioStreamInfo
	*/
	AudioStreamInfo(const AudioStreamInfo & rhs);

	/**
	* Copying of objects using this copy assignment operator is allowed.
	*
	* @since		2.0
	*
	* @return The reference of this instance
	* @param[in] rhs An instance of %AudioStreamInfo
	*/
	AudioStreamInfo & operator =(const AudioStreamInfo & rhs);

	/**
	* Compares the specified instance of Tizen::Base::Object with the calling instance of %AudioStreamInfo.
	*
	* @since		2.0
	*
	* @return   @c true if the value of the specified instance equals the value of the current instance, @n
	*			else @c false
	* @param[in]	rhs	 The object to compare with the current instance
	*/
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	* Gets the hash value of the current instance.
	*
	* @since		2.0
	*
	* @return   The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @param [in]	codecType	The value of encoding type @n
	* @param [in]	bitrate		The audio bit rate in bits per second (bps) @n
	* @param [in]	sampleRate	The audio sample rate in Hertz (Hz) @n
	* @param [in]	channel		The audio channel type @n
	*/
	AudioStreamInfo(CodecType codecType, int bitrate, int sampleRate, AudioChannelType channel);

private:
	class _AudioStreamInfoImpl *__pAudioStreamInfoImpl;
	friend class _PlayerImpl;
};

}}//Tizen::Media

#endif
