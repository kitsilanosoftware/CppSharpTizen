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
* @file		FMediaIAudioRouteEventListener.h
* @brief		This is the header file for the %IAudioRouteEventListener interface.
*
* This header files contains the declarations of the %IAudioRouteEventListener interface and its associated classes.
*
*/
#ifndef _FMEDIA_IAUDIO_ROUTE_EVENT_LISTENER_H_
#define _FMEDIA_IAUDIO_ROUTE_EVENT_LISTENER_H_

#include <FMediaAudioRouteInfo.h>
#include "FBaseRtIEventListener.h"

namespace Tizen { namespace Media
{
/**
 * @interface	IAudioRouteEventListener
 * @brief This interface provides a listener that receives events associated with the active audio device or available audio devices.
 *
 * @since		2.0
 *
 * The %IAudioRouteEventListener interface specifies the methods used to notify the changes in active audio device or in available audio devices.
 *  There are many audio devices in the device. Thus If the application wants to know the currently active audio device or available audio devices,
 *  it has to listen to this interface.
 */
class _OSP_EXPORT_ IAudioRouteEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since		2.0
	*/
	virtual ~IAudioRouteEventListener(void) { }

	/**
	*	Called when active audio route changes.
	*
	*	@since		2.0
	*	@param[in]			route					An instance of AudioRouteInfo that is active currently
	*/
	virtual void OnActiveAudioRouteChanged(const AudioRouteInfo& route) = 0;

	/**
	*	Called when an available audio route is added.
	*
	*	@since		2.0
	*	@param[in]			route					An instance of AudioRouteInfo for which the routing status is changed
	*/
	virtual void OnAudioRouteAdded(const AudioRouteInfo& route) = 0;

	/**
	*	Called when an audio route is removed.
	*
	*	@since		2.0
	*	@param[in]			route					An instance of AudioRouteInfo for which the routing status is changed
	*/
	virtual void OnAudioRouteRemoved(const AudioRouteInfo& route) = 0;
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
	virtual void IAudioRouteEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since		2.0
	//
	virtual void IAudioRouteEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since		2.0
	//
	virtual void IAudioRouteEventListener_Reserved3(void) {}

};
}}	//Tizen::Media
#endif
