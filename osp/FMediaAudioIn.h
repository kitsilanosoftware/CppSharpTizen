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
 * @file			FMediaAudioIn.h
 * @brief			This is the header file for the %AudioIn class.
 *
 * This header file contains the declarations of the %AudioIn class.
 */

#ifndef _FMEDIA_AUDIO_IN_H_
#define _FMEDIA_AUDIO_IN_H_

#include <FMediaAudioTypes.h>
#include <FMediaIAudioInEventListener.h>

namespace Tizen { namespace Media
{
/**
 * @class	AudioIn
 * @brief		This class records directly from an audio device.
 *
 * @since		2.0
 *
 * The %AudioIn class records directly from an audio device by providing methods for capturing PCM data from an audio input device.
 * An application can capture audio data with the help of an event listener after preparing the %AudioIn class
 * with proper channel count, sample type, and sampling rate.
 * To minimize the overhead of the %AudioIn class,
 * it is recommended that you use optimal channel type, sample type, and sampling rate.
 * These can be retrieved with GetOptimizedChannelType(), GetOptimizedSampleType()
 * and GetOptimizedSampleRate().
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/recording_pcm_audio.htm">Recording PCM Audio</a>.
 *
 * The following example demonstrates how to use the %AudioIn class.
 *
 * @code
 *
 * #include <FBase.h>
 * #include <FIo.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Io;
 * using namespace Tizen::Media;
 *
 * #define MAX_BUFFER_COUNT	  3
 *
 * class AudioInSample
 *	 : public Tizen::Media::IAudioInEventListener
 * {
 * public:
 *	 result Start(void);
 *	 void Stop(void);
 *
 * protected:
 *	 virtual void OnAudioInBufferIsFilled( Tizen::Base::ByteBuffer* pData);
 *	 virtual void OnAudioInErrorOccurred(result r) {}
 *	 virtual void OnAudioInInterrupted(void) {}
 *	 virtual void OnAudioInReleased(void) {}
 *	 virtual void OnAudioInAudioFocusChanged(void) {}
 *
 * private:
 *	 AudioIn __audioIn;
 *	 ByteBuffer __buffer[MAX_BUFFER_COUNT];
 * };
 *
 * result
 * AudioInSample::Start(void)
 * {
 *	 result r;
 *	 int minBufferSize;
 *	 AudioInputDevice inputDevice = AUDIO_INPUT_DEVICE_MIC;
 *	 AudioSampleType sampleType = AUDIO_TYPE_PCM_U8;
 *	 AudioChannelType channelType = AUDIO_CHANNEL_TYPE_STEREO;
 *	 int sampleRate = 8000;
 *
 *	 // Constructs an AudioIn instance
 *	 r = __audioIn.Construct(*this);
 *	 if (IsFailed(r))
 *	 {
 *		 return r;
 *	 }
 *
 *	 // Prepares the AudioIn instance
 *	 r = __audioIn.Prepare(inputDevice, sampleType, channelType, sampleRate);
 *	 if (IsFailed(r))
 *	 {
 *		 return r;
 *	 }
 *
 *	 minBufferSize = __audioIn.GetMinBufferSize();
 *
 *	 for (int i = 0; i < MAX_BUFFER_COUNT; i++)
 *	 {
 *		 // Prepares buffers to store PCM data
 *		 r = __buffer[i].Construct(minBufferSize);
 *		 if (IsFailed(r))
 *		 {
 *			 return r;
 *		 }
 *		 // Adds buffer to the __audioIn
 *		 __audioIn.AddBuffer(&__buffer[i]);
 *		 if (IsFailed(r))
 *		 {
 *			 return r;
 *		 }
 *	 }
 *
 *	 // Starts capturing
 *	 r = __audioIn.Start();
 *	 if (IsFailed(r))
 *	 {
 *		 return r;
 *	 }
 *
 *	 return E_SUCCESS;
 * }
 *
 * void
 * AudioInSample::Stop(void)
 * {
 *	 // Stops and unprepares the __audioIn
 *	 __audioIn.Stop();
 *	 __audioIn.Unprepare();
 * }
 *
 * void
 * AudioInSample::OnAudioInBufferIsFilled( Tizen::Base::ByteBuffer* pData)
 * {
 *	 // Consumes filled data here
 *
 *	 // Clears the buffer
 *	 pData->Clear();
 *
 *	 // Adds the byte buffer to the __audioIn to fill data again
 *	 __audioIn.AddBuffer(pData);
 * }
 *
 *
 * @endcode
 *
 */

class _OSP_EXPORT_ AudioIn
	: public Tizen::Base::Object
{
public:
	/**
	 *	The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 *  @since		2.0
	 *
	 *	@remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 *	@see			Construct()
	 */
	AudioIn(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *	All allocated resources are deallocated with this method. @n
	 *	This method must be called in the same thread as the Construct() method.
	 *
	 *  @since		2.0
	 *
	 *	@see		Construct()
	 */
	virtual ~AudioIn(void);

	/**
	*	Initializes this instance of %AudioIn with the specified IAudioInEventListener. @n
	*	This method creates an instance of %AudioIn in the subsystem.
	*
	*   @since		2.0
	*
	*	@return		An error code
	*	@param[in]	listener					An instance of IAudioInEventListener
	*	@exception	E_SUCCESS					The method is successful.
	*	@exception	E_DEVICE_BUSY				The device cannot be approached because of other operations.
	*	@exception	E_OUT_OF_MEMORY		The memory is insufficient. 
	*	@exception	E_SYSTEM							A system error has occurred.
	*	@remarks Only one instance of %AudioIn is operational at a given time.
	*/
	result Construct(IAudioInEventListener& listener);

	/**
	* @if OSPDEPREC
	*	Prepares the specified audio input device with the application-defined settings. @n
	*   When the caller finishes using the audio input device, the resources must be released by calling the Unprepare() method.
	*
	* @brief <i> [Deprecated]  </i>
	* @deprecated   This method is deprecated because AudioInputDevice is no longer used in %AudioIn class. @n
	*  Instead of using this method, use Prepare(AudioSampleType audioSampleType, AudioChannelType audioChannelType, int audioSampleRate).
	*
	*   @since		2.0
	*
	*	@return		An error code
	*	@param[in]	audioInputDevice						An audio input device
	*	@param[in]	audioSampleType						The type of audio sample
	*	@param[in]	audioChannelType						The audio channel type
	*	@param[in]	audioSampleRate						The audio sample rate in hertz (Hz)
	*	@exception	E_SUCCESS								The method is successful.
	*	@exception	E_INVALID_STATE						This instance is in an invalid state for this method.
	*	@exception	E_SYSTEM								A system error has occurred.
	*	@exception	E_INVALID_ARG							A specified input parameter is invalid.
	*	@exception	E_UNSUPPORTED_FORMAT			The specified audio sample type is not supported.
	*	@see		Unprepare()
	* @endif
	*/
	result Prepare(AudioInputDevice audioInputDevice, AudioSampleType audioSampleType, AudioChannelType audioChannelType, int audioSampleRate);

	/**
	*	Prepares the specified audio input device with the application-defined settings. @n
	*   When the caller finishes using the audio input device, the resources must be released by calling the Unprepare() method.
	*
	*   @since		2.0
	*
	*	@return		An error code
	*	@param[in]	audioSampleType						The type of audio sample
	*	@param[in]	audioChannelType						The audio channel type
	*	@param[in]	audioSampleRate						The audio sample rate in hertz (Hz)
	*	@exception	E_SUCCESS									The method is successful.
	*  @exception  E_DEVICE_FAILED          				The device failed with unknown reason.
	*	@exception	E_INVALID_ARG							A specified input parameter is invalid.
	*	@exception	E_UNSUPPORTED_FORMAT			The specified audio sample type is not supported.
	*	@see		Unprepare()
	*/
	result Prepare(AudioSampleType audioSampleType, AudioChannelType audioChannelType, int audioSampleRate);

	/**
	*	Stops the usage of the input device and releases the allocated resources during the execution of the Prepare() method. @n
	*   Resources allocated during Prepare() are released.
	*
	*   @since		2.0
	*
	*	@return		An error code
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	*	@exception	E_SYSTEM							A system error has occurred.
	*	@see		Prepare()
	*/
	result Unprepare(void);

	/**
	*	Adds an input buffer to the specified audio input device. @n
	*	When the buffer is filled, the %AudioIn class returns the buffer to the caller
	*	by invoking IAudioInEventListener::OnAudioInBufferIsFilled().
	*
	*   @since		2.0
	*
	*	@return			An error code
	*	@param[in]	pByteBuffer								A pointer to the buffer
	*	@exception	E_SUCCESS									The method is successful.
	*	@exception	E_INVALID_ARG							The input parameter is invalid.
	*	@exception	E_INVALID_STATE					This instance is in an invalid state for this method.
	*	@exception	E_SYSTEM										A system error has occurred.
	*	@exception	E_OUT_OF_MEMORY					The memory is insufficient.
	*	@remarks	The data size of @c pByteBuffer must be the same as every call of this method.
	*	@see		Start(), IAudioInEventListener::OnAudioInBufferIsFilled()
	*/
	result AddBuffer(const Tizen::Base::ByteBuffer* pByteBuffer);

	/**
	*	Starts reading the audio data from an audio input device and fills the data into the buffer.
	*
	*   @since		2.0
	*
	*	@return			An error code
	*	@exception	E_SUCCESS							The method is successful.
	*	@exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	*	@exception	E_DEVICE_BUSY					The device cannot be approached because of other operations.
	*	@exception	E_SYSTEM								A system error has occurred.
	*	@remarks	Several buffers must be added to the queue with AddBuffer() before calling this method.
	*	@see		Stop(), IAudioInEventListener::OnAudioInBufferIsFilled()
	*/
	result Start(void);

	/**
	*	Stops using the audio input device. @n
	*	All pending and current buffers that are filled with audio data
	*   at the time of calling this method, are returned to the listener.
	*	Use Start() to start capturing audio input data again.
	*
	*   @since		2.0
	*
	*	@return			An error code
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	*	@exception	E_SYSTEM							A system error has occurred.
	*	@see		Start(), IAudioInEventListener::OnAudioInBufferIsFilled()
	*/
	result Stop(void);

	/**
	*	Resets using the audio input device without returning buffers to the caller. @n
	*	All pending and current buffers are released immediately without any notifications.
	*	The state is changed to AUDIOIN_STATE_PREPARED.
	*
	*   @since		2.0
	*
	*	@return			An error code
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	*	@exception	E_SYSTEM							A system error has occurred.
	*/
	result Reset(void);

	/**
	*	Gets the current state of this instance.
	*
	*   @since		2.0
	*
	*	@return			The state of this instance
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_SYSTEM							A system error has occurred.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	AudioInState GetState(void) const;

	/**
	*	Gets the maximum size of the buffer that can be used with AddBuffer(). @n
	*	This maximum value is set by Prepare() and reset to @c 0 by Unprepare().
	*
	*   @since		2.0
	*
	*	@return			The maximum size of the buffer in bytes, @n
	*				else @c -1 if an error occurs
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	*	@exception	E_SYSTEM							A system error has occurred.
	*	@remarks	The return value is available after calling the Prepare() method.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetMaxBufferSize(void) const;

	/**
	*	Gets the minimum size of the buffer that can be used with AddBuffer(). @n
	*	This minimum value is set by Prepare() and reset to @c 0 by Unprepare().
	*
	*   @since		2.0
	*
	*	@return			The minimum size of the buffer in bytes,	@n
	*				else @c -1 if an error occurs
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	*	@exception	E_SYSTEM							A system error has occurred.
	*	@remarks	The return value is available after calling the Prepare() method.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetMinBufferSize(void) const;

	/**
	*	Gets the optimized sample type of the audio input device.
	*
	*   @since		2.0
	*
	*	@return			The audio encoding type
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_SYSTEM							A system error has occurred.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	AudioSampleType GetOptimizedSampleType(void) const;

	/**
	*	Gets the optimized channel type of the audio input device.
	*
	*   @since		2.0
	*
	*	@return		The audio channel type
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_SYSTEM							A system error has occurred.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	AudioChannelType GetOptimizedChannelType(void) const;

	/**
	*	Gets the optimized sample rate of the audio input device.
	*
	*   @since		2.0
	*
	*	@return		The sample rate in hertz (Hz)
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_SYSTEM							A system error has occurred.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetOptimizedSampleRate(void) const;


private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * 	@since		2.0
	 */
	AudioIn(const AudioIn& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * 	 @since		2.0
	 */
	AudioIn& operator =(const AudioIn& rhs);

	friend class _AudioInImpl;
	class _AudioInImpl* __pAudioInImpl;
};

}} // Tizen::Media

#endif
