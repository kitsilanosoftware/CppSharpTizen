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
 * @file			FMediaAudioRouteManager.h
 * @brief		This is the header file for the %AudioRouteManager class.
 *
 * This header file contains the declarations of the %AudioRouteManager class.
 */

#ifndef _FMEDIA_AUDIO_ROUTE_MANAGER_H_
#define _FMEDIA_AUDIO_ROUTE_MANAGER_H_

#include <FMediaAudioManagerTypes.h>
#include <FMediaIAudioRouteEventListener.h>

namespace Tizen { namespace Media
{
/**
 *	@class AudioRouteManager
 * @brief	This class is used to manage audio routing.
 *
 *	@since		2.0
 *
 * @final This class is not intended for extension.
 *
 *	@remarks   Only one instance of the class works at a time.
 *
 * The following example demonstrates how to use the %AudioRouteManager class.
 *
 * @code
 *
 * #include <FBase.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Base::Collection;
 * using namespace Tizen::Media;
 *
 * class RouteManagerSample
 *     : public Tizen::Media::IPlayerEventListener
 *     ,	public Tizen::Media::IAudioRouteEventListener
  * {
 * public:
 *     result Initialize(void);
 *     result Play(void);
 *     result Route(void);
 *     void Stop(void);
 *
 * protected:
 *     // IPlayerEventListener
 *     virtual void OnPlayerOpened(result r) {}
 *     virtual void OnPlayerEndOfClip(void) {}
 *     virtual void OnPlayerBuffering(int percent) {}
 *     virtual void OnPlayerErrorOccurred(PlayerErrorReason r) {}
 *     virtual void OnPlayerInterrupted(void) {}
 *     virtual void OnPlayerReleased(void) {}
 *     virtual void OnPlayerSeekCompleted(result r) {}
 *     virtual void OnPlayerAudioFocusChanged (void) {}
 *
 *     virtual	void OnActiveAudioRouteChanged(const Tizen::Media::AudioRouteInfo& route)	{}
 *     virtual void OnAudioRouteAdded(const Tizen::Media::AudioRouteInfo& route) {}
 *     virtual void OnAudioRouteRemoved(const Tizen::Media::AudioRouteInfo& route) {}
 *
 *
 * private:
 *     Player __player;
 *     AudioRouteManager *__pAudioRouteManager;
 * };
 *
 * result
 * RouteManagerSample::Initialize(void)
 * {
 *     result r = E_SUCCESS;
 *     String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.mp3";
 *
 *     r = __player.Construct(*this);
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *		   __pAudioRouteManager = AudioRouteManager::GetInstance();
 *	  	 if (!__pAudioRouteManger)
 *	   {
 *	   			return E_OUT_OF_MEMORY;
 *	   	}
 *
 *     r = __player.OpenFile(filePath, false);
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *     return r;
 * }
 *
 *
 * result
 * RouteManagerSample::Play(void)
 * {
  * result r = E_SUCCESS;
  * r = __player.Play();
  * return r;
 * }
 *
 * result
 * RouteManagerSample::Route(void)
 * {
 *	  result r = E_SUCCESS;
 *   IList *pAudioDeviceList = null;
 *   int count;
 *
 *     pAudioDeviceList = __pAudioRouteManager->GetAvailableaudioRouteListN();
 *     count = pAudioDeviceList->GetCount();
 *     if (count)
 *     {
 *     AudioRouteInfo *audioDevice = (AudioRouteInfo *) pAudioDeviceList->GetAt(0);
 *     r = __pAudioRouteManager->SetActiveAudioRoute(*audioDevice);
 *      if (IsFailed(r))
 *     		{
 *      	return r;
 *     		}
 *     	}
 *     	pAudioDeviceList->RemoveAll();
 *     	pAudioDeviceList = null;
 *
 *	  return r;
 * }
 *
 *
 * void
 * RouteManagerSample::Stop(void)
 * {
 *     __player.Stop();
 *     __player.Close();
 * }
 *
 * @endcode
 */

class _OSP_EXPORT_ AudioRouteManager
	:public Tizen::Base::Object
{
public:
	/**
	* 	Gets the audio route manager instance pointer.
	*
	* 	@since		2.0
	*
	*	@privlevel				partner
	*	@privilege				%http://tizen.org/privilege/audiomanager.route
	*
	* 	@return              	A pointer to the audio route manager instance, @n
	*								else @c null if it fails
	*	@exception			E_SUCCESS						The method is successful.
	*	@exception			E_OUT_OF_MEMORY			The memory is insufficient to perform the operation.
	*	@exception			E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* 	@remarks             	The specific error code can be accessed using the GetLastResult() method.
	*/
	static AudioRouteManager* GetInstance(void);

	/**
	*	Sets audio route event listener.
	*
	*	@since		2.0
	*
	*	@privlevel				partner
	*	@privilege				%http://tizen.org/privilege/audiomanager.route
	*
	*	@return					An error code
	*	@param[in]				pListener							The audio route event listener @n
	*																			To unset the listener, pass a @c null value to the listener parameter.
	*	@exception			E_SUCCESS							The method is successful.
	*	@exception			E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	*/
	result SetAudioRouteEventListener(IAudioRouteEventListener* pListener);

	/**
	*	Gets the name of the active bluetooth A2DP device.
	*
	*	@since		2.0
	*
	*	@privlevel				partner
	*	@privilege				%http://tizen.org/privilege/audiomanager.route
	*
	*	@return				The name of active bluetooth A2DP device
	*	@exception			E_SUCCESS							The method is successful.
	*	@exception			E_DEVICE_UNAVAILABLE		A2DP device is not connected or available.
	*	@exception			E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* 	@remarks             	The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Base::String GetActiveBluetoothA2dpName(void) const;

	/**
	*	Gets the active audio stream type
	*
	*	@since		2.0
	*
	*	@privlevel				partner
	*	@privilege				%http://tizen.org/privilege/audiomanager.route
	*
	*	@return					An active audio stream type
	*	@exception			E_SUCCESS						The method is successful.
	*	@exception			E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* 	@remarks             	
	*						- The specific error code can be accessed using the GetLastResult() method.
	*						- @c AUDIO_STREAM_TYPE_NO_SOUND is returned when no sound is playing.
	*/
	AudioStreamType GetActiveAudioStreamType(void) const;

	/**
	*	Gets available audio routes.
	*
	*	@since		2.0
	*
	*	@privlevel				partner
	*	@privilege				%http://tizen.org/privilege/audiomanager.route
	*
	*	@return					The list of available audio routes, @n
	*									else @c null if it fails
	*	@exception			E_SUCCESS						The method is successful.
	*	@exception			E_OUT_OF_MEMORY			The memory is insufficient to make the list.
	*	@exception			E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* 	@remarks             	
	*						- The specific error code can be accessed using the GetLastResult() method.
	*						- The item type of returned list is AudioRouteInfo.
	*/
	Tizen::Base::Collection::IList* GetAvailableAudioRouteListN(void) const;

	/**
	*	Checks the specified @c route availability.
	*
	*	@since		2.0
	*
	*	@privlevel				partner
	*	@privilege				%http://tizen.org/privilege/audiomanager.route
	*
	*	@return					@c true if the audio route is available, @n
	*								else @c false
	*	@param[in]				route									An instance of AudioRouteInfo
	*	@exception			E_SUCCESS						The method is successful.
	*	@exception			E_INVALID_ARG					A specified input parameter is invalid.
	*	@exception			E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* 	@remarks             	The specific error code can be accessed using the GetLastResult() method.
	*/
	bool IsAudioRouteAvailable(const AudioRouteInfo& route) const;

	/**
	*	Sets the active audio route.
	*
	*	@since		2.0
	*
	*	@privlevel				partner
	*	@privilege				%http://tizen.org/privilege/audiomanager.route
	*
	*	@return					An error code
	*	@param[in]				route 								An instance of AudioRouteInfo to set
	*	@exception			E_SUCCESS						The method is successful.
	*	@exception			E_INVALID_ARG					A specified input parameter is invalid.
	*	@exception			E_DEVICE_UNAVAILABLE			The audio route is not available.
	*	@exception			E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	*/
	result SetActiveAudioRoute(const AudioRouteInfo& route);

	/**
	*	Gets the active audio route.
	*
	*	@since		2.0
	*
	*	@privlevel				partner
	*	@privilege				%http://tizen.org/privilege/audiomanager.route
	*
	*	@return					The active audio route
	*	@exception			E_SUCCESS						The method is successful.
	*	@exception			E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* 	@remarks             	
	*						- The specific error code can be accessed using the GetLastResult() method.
	*						- ::INPUT_AUDIO_DEVICE_NONE and ::OUTPUT_AUDIO_DEVICE_NONE are set in AudioRouteInfo if this method fails.
	*/
	AudioRouteInfo GetActiveAudioRoute(void) const;


private:
	/**
	 * This default constructor is intentionally declared as private to implement the Singleton semantic.
	 *
	 * @since		2.0
	 *
	 */
	AudioRouteManager(void);

	/**
	*	This destructor is intentionally declared as private to implement the Singleton semantic.
	*
	*	@since		2.0
	*
	*/
	virtual ~AudioRouteManager(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since		2.0
	 *
	 */
	AudioRouteManager(const AudioRouteManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since		2.0
	 *
	 */
	AudioRouteManager& operator =(const AudioRouteManager& rhs);

	class _AudioRouteManagerImpl* __pAudioRouteManagerImpl;
};

}} // Tizen::Media

#endif
