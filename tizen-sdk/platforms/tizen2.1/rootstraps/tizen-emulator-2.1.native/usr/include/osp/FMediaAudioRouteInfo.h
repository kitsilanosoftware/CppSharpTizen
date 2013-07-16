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
* @file			FMediaAudioRouteInfo.h
* @brief		This is the header file for the %AudioRouteInfo class.
*
* This header files contains the declarations of the %AudioRouteInfo class and its associated classes.
*
*/
#ifndef _FMEDIA_AUDIO_ROUTE_INFO_H_
#define _FMEDIA_AUDIO_ROUTE_INFO_H_

#include <FMediaAudioManagerTypes.h>

namespace Tizen { namespace Media
{
/**
  *	@class AudioRouteInfo
 * @brief	This class contains audio route information.
 *
 *	@since		2.0
 *
 * @final This class is not intended for extension.
 *
 *	@remarks  Audio routing can be done using this class instances as input/output audio devices.
 *
 * The %AudioRouteInfo class contains audio route information.
 */
class _OSP_EXPORT_ AudioRouteInfo
	:public Tizen::Base::Object
{
public:
	/**
	*	Initializes this instance of %AudioRouteInfo with the specified audio devices.
	*
	*	@since		2.0
	*
	*	@param[in]			in										The input audio device
	*	@param[in]			out									The output audio device
	*	@exception			E_SUCCESS						The method is successful.
	*	@exception			E_OUT_OF_MEMORY		The memory is insufficient to perform the operation.
	*
	*/
	AudioRouteInfo(InputAudioDevice in, OutputAudioDevice out);

	/**
	*	This destructor overrides Tizen::Base::Object::~Object().
	*
	*	@since		2.0
	*
	*/
	virtual ~AudioRouteInfo(void);

	/**
	*	Sets the input audio device.
	*
	*	@since		2.0
	*
	*	@param[in]			in										The input audio device
	*/
	void SetInputAudioDevice(InputAudioDevice in);

	/**
	*	Sets the output audio device.
	*
	*	@since		2.0
	*
	*	@param[in]			out									The output audio device
	*/
	void SetOutputAudioDevice(OutputAudioDevice out);

	/**
	*	Gets the input audio device.
	*
	*	@since		2.0
	*
	*	@return				The input audio device
	*/
	InputAudioDevice GetInputAudioDevice(void) const;

	/**
	*	Gets the output audio device.
	*
	*	@since		2.0
	*
	*	@return				The output audio device
	*/
	OutputAudioDevice GetOutputAudioDevice(void) const;

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since		2.0
	*
	* @return		The copy of this instance
	* @param[in]	rhs	An instance of %AudioRouteInfo
	*/
	AudioRouteInfo(const AudioRouteInfo& rhs);

	/**
	*	Copying of objects using this copy assignment operator is allowed.
	*
	*	@since		2.0
	*
	*	@return				The instance of %AudioRouteInfo
	*	@param[in]			rhs									An instance of %AudioRouteInfo
	*/
	AudioRouteInfo& operator =(const AudioRouteInfo& rhs);

	/**
	*	Compares the specified instance of %AudioRouteInfo with the calling instance.
	*
	*	@since		2.0
	*
	*	@return				@c true if the object is the same, @n
	*						else @c false
	*	@param[in]			obj									The object to compare with the current instance
	*/
	virtual bool Equals(const Object& obj) const;

	/**
	*	Gets the hash code for the %AudioRouteInfo instance.
	*
	*	@since		2.0
	*
	*	@return				The hash code
	*/
	virtual int GetHashCode(void) const;

private:
	class _AudioRouteInfoImpl* __pAudioRouteInfoImpl;
};

}}	//Tizen::Media
#endif
