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
 * @file   FMediaAudioEqualizer.h
 * @brief  This is the header file for the %AudioEqualizer class.
 *
 * This header file contains the declarations of the %AudioEqualizer class.
 */

#ifndef _FMEDIA_AUDIO_EQUALIZER_H_
#define _FMEDIA_AUDIO_EQUALIZER_H_

#include <FBaseObject.h>
#include <FMediaPlayer.h>

namespace Tizen { namespace Media
{
/**
 * @class AudioEqualizer
 * @brief This class is used to apply audio equalizer settings.
 *
 * @since		2.0
 *
 * @final This class is not intended for extension.
 *
 * @remarks		The functionality includes querying and setting the levels of the different frequency bands.
 *
 * The following example demonstrates how to use the %AudioEqualizer class.
 *
 * @code
 *
 * #include <FBase.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Media;
 *
 * class EqualizerSample
 *     : public Tizen::Media::IPlayerEventListener
  * {
 * public:
 *     result Initialize(void);
 *     result Play(void);
 *     result Equalize(void);
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
 *
 * private:
 *     Player __player;
 *     AudioEqualizer __audioEqualizer;
 * };
 *
 * result
 * EqualizerSample::Initialize(void)
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
 *	   __audioEqualizer.Construct(__player)
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
 * EqualizerSample::Play(void)
 * {
  * result r = E_SUCCESS;
  * r = __player.Play();
  * return r;
 * }
 *
 * result
 * EqualizerSample::Equalize(void)
 * {
 *	  result r = E_SUCCESS;
 *    int count;
 *    int level;
 *    int minValue;
 *    int maxValue;
 *
 *	  count = __audioEqualizer.GetBandCount();
 *
 *	  for (int index = 0; index < count; index++)
 *	  {
 *	    r = __audioEqualizer.GetBandLevelRange(index, minValue, maxValue);
 *      if (IsFailed(r))
 *      {
 *      	return r;
 *      }
 *   	level = (minValue + maxValue) / 2;
 *		r = __audioEqualizer.SetBandLevel(index, level);
 *      if (IsFailed(r))
 *     	{
 *      	return r;
 *     	}
 * 	  }
 *	  return r;
 * }
 *
 *
 * void
 * EqualizerSample::Stop(void)
 * {
 *     __audioEqualizer.ResetAllToDefault();
 *     __player.Stop();
 *     __player.Close();
 * }
 *
 * @endcode
 */

class _OSP_EXPORT_ AudioEqualizer
	: public Tizen::Base::Object
{
public:
	/**
	* The object is not fully constructed after this constructor is called. @n 
	* For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since		2.0
	*
	*/
	AudioEqualizer(void);
	
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*
	*/
	virtual ~AudioEqualizer(void);

	/**
	* Initializes this instance of %AudioEqualizer with the given Player.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in] 	player       				The player instance that the equalizer will be applied
	* @exception	E_SUCCESS					The method is successful.
	* @exception 	E_OUT_OF_MEMORY    			The memory is insufficient.
	* @exception	E_INVALID_ARG				The specified input parameter is invalid.
	* @exception 	E_UNSUPPORTED_OPERATION 	This device does not support the audio equalizer feature.
	* @remarks If @c player is deleted, then this instance cannot be used properly.
	*/
	result Construct(Player& player);

	/**
	* Gets the count of bands that equalizer supports.
	*
	* @since		2.0
	*
	* @return	 	The count of bands, @n
	*					else @c -1 if it fails
	* @exception	E_SUCCESS								The method is successful.
	* @exception 	E_INVALID_OPERATION					The associated audio instance is no longer valid.
	* @remarks    	The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetBandCount(void) const;

	/**
	* Gets the level range of the frequency band.
	*
	* @since		2.0
	*
	* @return	 		An error code
	* @param[in]		index			    			Index of the frequency band @n
	*												Index starts from 0.
	* @param[out]	minValue             			The minimum level of the frequency band specified by @c index
	* @param[out]	maxValue            			The maximum level of the frequency band specified by @c index
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG   			The specified input parameter is invalid.
	* @exception 		E_INVALID_OPERATION		The associated audio instance is no longer valid.
	* @see GetBandCount()
	*/
	result GetBandLevelRange(int index, int& minValue, int& maxValue) const;

	/**
	* Sets the level of the frequency band specified by @c index.
	*
	* @since		2.0
	*
	* @return			An error code
	* @param[in]		index							Index of the frequency band @n
	*												Index starts from 0.
	* @param[in]		level		    					The level to which the frequency band should be set
	* @exception		E_SUCCESS					The method is successful.
    * @exception		E_OUT_OF_RANGE		The level value does not lie within minimum and maximum range of frequency band.
	* @exception		E_INVALID_ARG   			The specified input parameter is invalid.
	* @exception 		E_INVALID_OPERATION		The associated audio instance is no longer valid.
	* @see GetBandCount()
	*/
	result SetBandLevel(int index, int level);

	/**
	* Sets the level of all the frequency bands
	*
	* @since		2.0
	*
	* @return			An error code
	* @param[in]		pLevels						The pointer of the level array which has settings of all the frequency bands
	* @exception		E_SUCCESS					The method is successful.
    * @exception		E_OUT_OF_RANGE		The level values do not lie within minimum and maximum range of frequency bands.
    * @exception    	E_INVALID_ARG   			The specified input parameter is invalid. List is either empty or does not have level settings for all frequency bands.
	* @exception 		E_INVALID_OPERATION		The associated audio instance is no longer valid.
	*/
	result SetAllBandsLevel(const Tizen::Base::Collection::IListT<int>* pLevels);

	/**
	* Gets the level of frequency band specified by @c index.
	*
	* @since		2.0
	*
	* @return	    	An error code
	* @param[in]		index               			Index of the frequency band @n
	*												Index starts from 0.
	* @param[out]	level              				The level of the frequency band specified by @c index
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG       		The specified input parameter is invalid.
	* @exception 		E_INVALID_OPERATION		The associated audio instance is no longer valid.
	*/
	result GetBandLevel(int index, int& level) const;

	/**
	* Gets the center frequency of the frequency band specified by index.
	*
	* @since		2.0
	*
	* @return	 		An error code
	* @param[in]		index               			Index of the frequency band @n
	*											Index starts from 0.
	* @param[out]	frequency          		 	The center frequency in Hz of the frequency band specified by @c index
	* @exception		E_SUCCESS		    		The method is successful.
	* @exception		E_INVALID_ARG			The specified input parameter is invalid.
	* @exception 		E_INVALID_OPERATION		The associated audio instance is no longer valid.
	*/
	result GetBandCenterFrequency(int index, int& frequency) const;
	
	/**
	* Clears the equalizer effect and resets all bands to the default values.
	*
	* @since		2.0
	*
	* @return	 		An error code
	* @exception		E_SUCCESS		    			The method is successful.
	* @exception 		E_INVALID_OPERATION	The associated audio instance is no longer valid.
	*/
	result ResetAllToDefault(void);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since		2.0
	 *
	 */
	AudioEqualizer(const AudioEqualizer& rhs);
	
	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since		2.0
	 *
	 */
	AudioEqualizer& operator =(const AudioEqualizer& rhs);
	
	class _AudioEqualizerImpl* __pAudioEqualizerImpl;
};

}} // Tizen::Media

#endif 

