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
 * @file			FMediaIAudioStreamFilter.h
 * @brief			This is the header file for the %IAudioStreamFilter interface.
 *
 * This header file contains the declarations of the %IAudioStreamFilter interface.
 */

#ifndef _FMEDIA_IAUDIO_STREAM_FILTER_H_
#define _FMEDIA_IAUDIO_STREAM_FILTER_H_

namespace Tizen { namespace Media
{
class AudioFrame;

/**
 * @interface	IAudioStreamFilter
 * @brief		This interface represents a filter that processes an audio stream data.
 *
 * @since		2.1
 *
 * The %IAudioStreamFilter interface represents a filter that processes an audio stream data.
*/
class _OSP_EXPORT_ IAudioStreamFilter
{

public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when
	* the destructor of this interface is called.
	*
	* @since		2.1
	*/
	virtual ~IAudioStreamFilter(void) {}

	/**
	*	Processes an audio stream.
	*
	* @since		2.1
	*
	* @param[in,out]	frame	A frame object containing the audio frame data
	* @remarks This method should not contain any operations that harm thread safety or performance degradation.
	*/
	virtual void ProcessAudioStream(AudioFrame& frame) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.1
	//
	virtual void IAudioStreamFilter_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.1
	//
	virtual void IAudioStreamFilter_Reserved2(void) {}
};

}}// Tizen::Media

#endif
