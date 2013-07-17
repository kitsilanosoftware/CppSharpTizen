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
 * @file			FMediaAudioOut.h
 * @brief			This is the header file for the %AudioOut class.
 *
 * This header file contains the declarations of the %AudioOut class.
 */

#ifndef _FMEDIA_AUDIO_OUT_H_
#define _FMEDIA_AUDIO_OUT_H_

#include <FBaseByteBuffer.h>
#include <FMediaAudioTypes.h>
#include <FMediaAudioManagerTypes.h>
#include <FMediaIAudioOutEventListener.h>

namespace Tizen { namespace Media
{

/**
 * @class		AudioOut
 * @brief		This class plays raw audio data.
 *
 * @since		2.0
 *
 * @remarks
 * The maximum number of %AudioOut instances is limited by Media::MediaCapability class. This number is a system wide count so that the application must not be able to construct more instances than the maximum number permitted.
 *
 * The %AudioOut class plays raw audio data and provides methods for:
 * - Playing PCM data in various audio sample types
 * - Controlling volume
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/playing_pcm_audio.htm">Playing PCM Audio</a>.
 *
 * The following example demonstrates how to use the %AudioOut class.
 *
 *
 * @code
 * #include <FBase.h>
 * #include <FIo.h>
 * #include <FApp.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Io;
 * using namespace Tizen::Media;
 *
 * #define MAX_BUFFER_COUNT	3
 *
 * class AudioOutSample
 *	 : public Tizen::Media::IAudioOutEventListener
 * {
 * public:
 *	 result Start(void);
 *	 void Stop(void);
 *
 * protected:
 *	 virtual void OnAudioOutBufferEndReached(Tizen::Media::AudioOut& src);
 *	 virtual void OnAudioOutErrorOccurred(Tizen::Media::AudioOut& src, result r) {}
 *	 virtual void OnAudioOutInterrupted(Tizen::Media::AudioOut& src) {}
 *	 virtual void OnAudioOutReleased(Tizen::Media::AudioOut& src) {}
 *	 virtual void OnAudioOutAudioFocusChanged(Tizen::Media::AudioOut& src) {}
 *
 * private:
 *	 AudioOut __audioOut;
 *	 File __file;
 *	 ByteBuffer __buffer[MAX_BUFFER_COUNT];
 *	 int __bufIndex;
 * };
 *
 * result
 * AudioOutSample::Start(void)
 * {
 *	 FileAttributes attr;
 *	 String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.pcm";
 *	 result r;
 *	 int minBufferSize;
 *
 *	 // Opens the input file
 *	 __file.Construct(filePath, L"rb");
 *
 *	 // Constructs the AudioOut instance with a listener
 *	 r = __audioOut.Construct(*this);
 *	 if (IsFailed(r))
 *	 {
 *		 return r;
 *	 }
 *
 *	 // Prepares the AudioOut instance
 *	 // Considers the input data as signed 16-bit, stereo, 44100 Hz PCM data
 *	 __audioOut.Prepare(AUDIO_TYPE_PCM_S16_LE, AUDIO_CHANNEL_TYPE_STEREO, 44100);
 *	 minBufferSize = __audioOut.GetMinBufferSize();
 *
 *	 // Constructs the pcm buffer and enqueue the buffer to the __audioOut
 *	 for (int i = 0; i < MAX_BUFFER_COUNT; i++)
 *	 {
 *		 __buffer[i].Construct(minBufferSize);
 *		 __file.Read(__buffer[i]);
 *		 __audioOut.WriteBuffer(__buffer[i]);
 *	 }
 *	 __bufIndex = 0;
 *
 *	 // Starts playing
 *	 r = __audioOut.Start();
 *	 if (IsFailed(r))
 *	 {
 *		 return r;
 *	 }
 *
 *	 return E_SUCCESS;
 * }
 *
 * void
 * AudioOutSample::Stop(void)
 * {
 *	 __audioOut.Stop();
 *	 __audioOut.Unprepare();
 * }
 *
 * void
 * AudioOutSample::OnAudioOutBufferEndReached(Tizen::Media::AudioOut& src)
 * {
 *	 result r = E_SUCCESS;
 *
 *	 r = __file.Read(__buffer[__bufIndex % MAX_BUFFER_COUNT]);
 *	 if (IsFailed(r))
 *	 {
 *		 // Handles end of file event
 *
 *		 return;
 *	 }
 *
 *	 src.WriteBuffer(__buffer[__bufIndex % MAX_BUFFER_COUNT]);
 *	 __bufIndex++;
 * }
 *
 *
 * @endcode
 */

class _OSP_EXPORT_ AudioOut
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 */
	AudioOut(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 * All allocated resources are released by this method.
	 * This method must be called in the same thread as the Construct() method.
	 *
	 * @since		2.0
	 *
	 * @see			Construct()
	 */
	virtual ~AudioOut(void);

public:
	/**
	* Initializes this instance of %AudioOut with the specified listener.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	listener											An instance of IAudioOutEventListener
	* @exception	E_SUCCESS										The method is successful.
	* @exception	E_SYSTEM											A system error has occurred.
	* @exception	E_OUT_OF_MEMORY         The memory is insufficient. 
	* @exception	E_RESOURCE_UNAVAILABLE		The %AudioOut's resources are unavailable.
	*/
	result Construct(IAudioOutEventListener& listener);

	/**
	* Prepares an audio output device with the defined settings.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	audioSampleType					The type of the audio sample
	* @param[in]	audioChannelType					The type of the audio channel
	* @param[in]	audioSampleRate					The audio sample rate in Hertz (Hz)
	* @exception	E_SUCCESS									The method is successful.
	* @exception	E_INVALID_STATE					This instance is in an invalid state for this method.
	* @exception	E_SYSTEM										A system error has occurred.
	* @exception	E_INVALID_ARG							A specified input parameter is invalid.
	* @exception	E_UNSUPPORTED_FORMAT		The specified audio sample type is not supported.
	* @see			Unprepare()
	*/
	result Prepare(AudioSampleType audioSampleType, AudioChannelType audioChannelType, int audioSampleRate);

	/**
	* Prepares an audio output device with the defined settings with the audio stream type.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	audioStreamType					The type of the audio stream
	* @param[in]	audioSampleType					The type of the audio sample
	* @param[in]	audioChannelType					The type of the audio channel
	* @param[in]	audioSampleRate					The audio sample rate in Hertz (Hz)
	* @exception	E_SUCCESS								The method is successful.
	* @exception	E_INVALID_STATE					This instance is in an invalid state for this method.
	* @exception   E_DEVICE_FAILED              		The device failed with unknown reason.
	* @exception	E_INVALID_ARG						A specified input parameter is invalid.
	* @exception	E_UNSUPPORTED_FORMAT		The specified audio sample type is not supported.
	* @see			Unprepare()
	*/
	result Prepare(AudioStreamType audioStreamType, AudioSampleType audioSampleType, AudioChannelType audioChannelType, int audioSampleRate);

	/**
	* Closes the audio output device.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_SYSTEM							A system error has occurred.
	* @see			Prepare()
	*/
	result Unprepare(void);

	/**
	* Writes into the data buffer containing the audio data to be played to this audio output device. @n
	* When the end of the buffer is reached, the application gets the notification through IAudioOutEventListener.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	userData							A pointer of the buffer containing the PCM data block
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_SYSTEM							A system error has occurred.
	* @exception	E_INVALID_ARG				The specified input parameter is invalid.
	* @exception	E_OVERFLOW						The specified input instance has overflowed.
	* @see			Start()
    * @see	        IAudioOutEventListener::OnAudioOutBufferEndReached()
	*/
	result WriteBuffer(const Tizen::Base::ByteBuffer& userData);

	/**
	* Starts the specified audio output device.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	* @exception	E_SYSTEM							A system error has occurred.
	* @see			Stop()
	*/
	result Start(void);

	/**
	* Stops or pauses the playing of the audio output device. @n
	* The current position of the playback is stored internally and the playback will restart from this position
	* when Start() is called again.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_SYSTEM							A system error has occurred.
	* @remarks		Use Start() to resume the playback from the current playback position.
    * @see	        IAudioOutEventListener::OnAudioOutBufferEndReached()
	*/
	result Stop(void);

	/**
	* Resets the audio output device. @n
	* All pending and current data buffers in the queue are removed immediately without any notification. The
	* state is changed to ::AUDIOOUT_STATE_PREPARED.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_SYSTEM							A system error has occurred.
	*/
	result Reset(void);

	/**
	* Gets the state of the current audio output device.
	*
	* @since		2.0
	*
	* @return		The state of current audio output
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_SYSTEM							A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	AudioOutState GetState(void) const;

	/**
	* Gets the maximum size of buffer that can be used with WriteBuffer(). @n
	* This maximum value is set by Prepare() and reset to @c 0 by Unprepare().
	*
	* @since		2.0
	*
	* @return		The maximum size of buffer, @n
	*				else @c -1 if an error occurs
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_SYSTEM							A system error has occurred.
	* @remarks		
	*				- The return value is available after calling the Prepare() method.
	* 				- The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetMaxBufferSize(void) const;

	/**
	* Gets the minimum size of buffer that can be used with WriteBuffer(). @n
	* This minimum value is set by Prepare() and reset to @c 0 by Unprepare().
	*
	* @since		2.0
	*
	* @return		The minimum size of buffer, @n
	*				else @c -1 if an error occurs
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_SYSTEM							A system error has occurred.
	* @remarks		
	*				- The return value is available after calling the Prepare() method.
	* 				- The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetMinBufferSize(void) const;

	/**
	* Gets the optimized sample type of the audio output device.
	*
	* @since		2.0
	*
	* @return		The audio encoding type
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_SYSTEM							A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	AudioSampleType GetOptimizedSampleType(void) const;

	/**
	* Gets the optimized channel type of the audio output device.
	*
	* @since		2.0
	*
	* @return		The audio channel type
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_SYSTEM							A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	AudioChannelType GetOptimizedChannelType(void) const;

	/**
	* Gets the optimized sample rate of the audio output device.
	*
	* @since		2.0
	*
	* @return		The sample rate in Hertz (Hz)
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_SYSTEM							A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetOptimizedSampleRate(void) const;

	/**
	* Sets the volume level of the audio output device.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	volume				The new value for volume @n
	*									The range of this parameter is from @c 0 to @c 100 and it is proportional to the current media sound volume level in setting.
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_OUT_OF_RANGE			The specified volume is out of range.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @remarks		This method must be called after Prepare().
	* @see			GetVolume()
	*/
	result SetVolume(int volume);

	/**
	* Gets the current volume level of this audio output.
	*
	* @since		2.0
	*
	* @return		The current volume level, @n
	*				else @c -1 if an error occurs @n
	*				This return value ranges from @c 0 to @c 100.
	* @exception	E_SUCCESS						The method is successful.
	* @exception	E_INVALID_STATE	 	This instance is in an invalid state for this method.
	* @remarks		
	*				- The specific error code can be accessed using the GetLastResult() method.
	* 				- This method must be called after calling the Prepare() method.
	* @see			SetVolume()
	*/
	int GetVolume(void) const;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since		2.0
	 */
	AudioOut(const AudioOut& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since		2.0
	 */
	AudioOut& operator =(const AudioOut& rhs);

	friend class _AudioOutImpl;
	class _AudioOutImpl* __pAudioOutImpl;
};

}} // Tizen::Media

#endif
