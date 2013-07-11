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
 * @file			FMediaTonePlayer.h
 * @brief			This is the header file for the %TonePlayer class.
 *
 * This header file contains the declarations of the %TonePlayer class.
 */

#ifndef _FMEDIA_TONE_PLAYER_H_
#define _FMEDIA_TONE_PLAYER_H_

#include <FBaseColIList.h>
#include <FMediaAudioTypes.h>
#include <FMediaTone.h>
#include <FMediaAudioManagerTypes.h>
#include <FMediaITonePlayerEventListener.h>

namespace Tizen { namespace Media
{
class _TonePlayerImpl;
/**
 * @class		TonePlayer
 * @brief		This class plays the tone(s).
 *
 * @since		2.0
 *
 * @remarks
 * The maximum number of the %TonePlayer instance is limited by Media::MediaCapability class. This number is a system wide count so that the application should not be able to construct instances more than the maximum number.
 *
 * The %TonePlayer class provides methods for:
 * - Playing the tone(s)
 * - Controlling a tone player instance
 *
 * The following example demonstrates how to use the %TonePlayer class for playing a single tone and a list of tones.
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
 * class TonePlayerSample
 *	 : public ITonePlayerEventListener
 * {
 * public:
 *	 result PlayTone(void);
 *	 result PlayToneList(void);
 *	 void Stop(void);
 *
 * protected:
 *   virtual void 	OnTonePlayerAudioFocusChanged (Tizen::Media::TonePlayer &src) {}
 *	 virtual void OnTonePlayerEndOfTone(TonePlayer& src) {}
 *	 virtual void OnTonePlayerInterrupted(TonePlayer& src) {}
 *	 virtual void OnTonePlayerReleased(TonePlayer& src) {}
 *	 virtual void OnTonePlayerErrorOccurred(TonePlayer& src, result r) {}
 *
 * private:
 *	 TonePlayer __player;
 *	 LinkedList __toneList;
 * };
 *
 * result
 * TonePlayerSample::PlayTone(void)
 * {
 *	 result r = E_SUCCESS;
 *	 Tone *pTone = null;
 *
 *	 pTone = new Tone(DTMF_PRESET_S, 2000);
 *
 *	 __toneList.Add(*pTone);
 *
 *	 // Constructs the TonePlayer
 *	 __player.Construct(*this);
 *
 *	 // Opens TonePlayer with a single tone
 *	 __player.Open(*pTone, 5);
 *	 r = __player.Play();
 *	 if (IsFailed(r))
 *	 {
 *		 goto CATCH;
 *	 }
 *
 *	 return E_SUCCESS;
 *
 * CATCH:
 *	 __toneList.RemoveAll(true);
 *	 return r;
 * }
 *
 * result
 * TonePlayerSample::PlayToneList(void)
 * {
 *	 result r = E_SUCCESS;
 *
 *	 // Adds some tones to the tone list
 *	 __toneList.Add(*(new Tone(DTMF_PRESET_1, 2000)));
 *	 __toneList.Add(*(new Tone(2000, 5000, 3000)));
 *	 __toneList.Add(*(new Tone(DTMF_PRESET_8, 500)));
 *	 __toneList.Add(*(new Tone(0, 0, 1500)));  // Silence
 *	 __toneList.Add(*(new Tone(10000, 14000, 2500)));
 *
 *	 __player.Construct(*this);
 *
 *	 // Opens TonePlayer with a tone list
 *	 __player.Open(__toneList, 2);
 *
 *	 r = __player.Play();
 *	 if (IsFailed(r))
 *	 {
 *		 goto CATCH;
 *	 }
 *
 *	 return E_SUCCESS;
 *
 * CATCH:
 *	 __toneList.RemoveAll(true);
 *	 return r;
 * }
 *
 * void
 * TonePlayerSample::Stop(void)
 * {
 *	 __player.Stop();
 *	 __player.Close();
 *	 __toneList.RemoveAll(true);
 * }
 *
 * @endcode
 */

class _OSP_EXPORT_ TonePlayer
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be
	 *				called explicitly to initialize this instance
	 * @see			Construct()
	 */
	TonePlayer(void);

	/**
	 * This is the destructor for this class. @n
	 * All the allocated resources are released by this method. @n
	 * This method must be called in the same thread as the Construct() method.
	 *
	 * @since		2.0
	 *
	 * @see			Construct()
	 */
	virtual ~TonePlayer(void);

	/**
	* Initializes this instance of %TonePlayer with the specified listener.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	listener										An instance of ITonePlayerEventListener
	* @exception	E_SUCCESS									The method is successful.
	* @exception	E_RESOURCE_UNAVAILABLE	The tone player's resources are unavailable.
	* @exception 	E_OUT_OF_MEMORY       	The memory is insufficient. 
	* @exception	E_SYSTEM										A system error has occurred.
	*/
	result Construct(Tizen::Media::ITonePlayerEventListener& listener);

	/**
	* Opens the specified list of tones.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	toneList			A list of Tone instances
	* @param[in]	repeatCount			The number of times the list of tones should be played @n
	*									This number is greater than or equal to @c 1.
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_OBJ_NOT_FOUND		The specified tone instance cannot be found in the list.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_OUT_OF_RANGE			The count is out of range.
	* @exception	E_SYSTEM							A system error has occurred.
	* @remarks		The item(s) of the specified @c toneList should be an instance(s) of Tone.
	* @see			Close()
	*/
	result Open(const Tizen::Base::Collection::IList& toneList, int repeatCount = 1);

	/**
	* Opens the specified tone.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	tone				The tone instance
	* @param[in]	repeatCount			The number of times a tone should be played @n
	*									This number is greater than or equal to @c 1.
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_OUT_OF_RANGE			The count is out of range.
	* @exception	E_SYSTEM							A system error has occurred.
	* @see			Close()
	*/
	result Open(const Tizen::Media::Tone& tone, int repeatCount = 1);

	/**
	* Plays the playback or resumes the playback if Pause() has been called. @n
	* In case of the TONE_PLAYER_STATE_END_OF_TONE state, the tone(s) can be played again.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY				The device is busy for other operations.
	* @exception	E_SYSTEM							A system error has occurred.
	* @remarks		The playback starts from the current position. If playback is paused, playback restarts from
	*				the last position.
	* @see			Stop(), Pause()
	*/
	result Play(void);

	/**
	* Stops the playback.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_SYSTEM							A system error has occurred.
	* @see			Play(), Pause()
	*/
	result Stop(void);

	/**
	* Pauses the playback. @n
	* To resume the paused playback, call Play().
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_SYSTEM							A system error has occurred.
	* @see			Play(), Stop()
	*/
	result Pause(void);


	/**
	* Sets the volume level.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	volume				The new value for volume @n
	*									The range of this parameter is @c 0 to @c 100 and it is proportional to the current media sound volume level in setting.
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_OUT_OF_RANGE			The specified @c volume parameter is out of range.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @see			GetVolume()
	*/
	result SetVolume(int volume);

	/**
	* Gets the current volume level
	*
	* @since		2.0
	*
	* @return		The current volume level @n
	*				The range of this return value is @c 0 to @c 100.
	* @remarks		If the @c volume is not set, the default volume @c 50 is returned.
	* @see			SetVolume()
	*/
	int GetVolume(void) const;

	/**
	* Closes the tone player.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_SYSTEM							A system error has occurred.
	* @see			Open()
	*/
	result Close(void);

	/**
	* Gets the current state of the tone player instance.
	*
	* @since		2.0
	*
	* @return		The current state of the tone player
	*/
	TonePlayerState GetState(void) const;

	/**
	* Sets audio stream type for tone playback
	*
	* @since		2.0
	*
	* @return       	  An error code
	* @param[in]    type                    			An audio stream type
	* @exception    E_SUCCESS					The method is successful.
	* @exception    E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception    E_INVALID_ARG				A specified input parameter is invalid.
	* @remarks	This method should be called before Open().
	*/
	result SetAudioStreamType(AudioStreamType type);

private:
	TonePlayer(const TonePlayer& rhs);
	TonePlayer& operator =(const TonePlayer& rhs);

	friend class _TonePlayerImpl;
	_TonePlayerImpl* __pTonePlayerImpl;
};

}} // Tizen::Media

#endif
