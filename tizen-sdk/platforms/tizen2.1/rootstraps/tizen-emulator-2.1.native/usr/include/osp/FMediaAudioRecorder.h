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
 * @file		FMediaAudioRecorder.h
 * @brief		 This is the header file for the %AudioRecorder class.
 *
 * This header file contains the declarations of the %AudioRecorder class.
 */

#ifndef _FMEDIA_AUDIO_RECORDER_H_
#define _FMEDIA_AUDIO_RECORDER_H_

#include <FMediaAudioRecorderTypes.h>
#include <FMediaIAudioRecorderEventListener.h>
#include <FMediaTypes.h>

namespace Tizen { namespace Media
{

class _AudioRecorderImpl;
class IAudioStreamFilter;

/**
 * @class	AudioRecorder
 * @brief	This class records the audio data into a file.
 *
 * @since		2.0
 *
 * The %AudioRecorder class records the audio data from an input device source to the storage device. The
 * selection of the input device source depends upon the current device status. For example, if a headset device is
 * connected, it is selected as an input source. The audio recording format, the maximum recording time, and the
 * maximum recording size can be set using the methods available in this class.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/recording_audio.htm">Recording Audio</a>.
 *
 * The following example demonstrates how to use the %AudioRecorder class.
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
 * class AudioRecorderSample
 *     : public IAudioRecorderEventListener
 * {
 * public:
 *     result Start(void);
 *     void Stop(void);
 *
 * protected:
 *     virtual void OnAudioRecorderStopped(result r) {}
 *     virtual void OnAudioRecorderCanceled(result r) {}
 *     virtual void OnAudioRecorderPaused(result r) {}
 *     virtual void OnAudioRecorderStarted(result r) {}
 *     virtual void OnAudioRecorderEndReached(RecordingEndCondition endCondition) {}
 *     virtual void OnAudioRecorderClosed(result r) {}
 *     virtual void OnAudioRecorderErrorOccurred(RecorderErrorReason r) {}
 *
 * private:
 *     AudioRecorder __recorder;
 * };
 *
 * result
 * AudioRecorderSample::Start(void)
 * {
 *     result r;
 *     String destFilePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.amr";
 *
 *     r = __recorder.Construct(*this);
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     r = __recorder.CreateAudioFile(destFilePath, true);
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     r = __recorder.Record();
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     return E_SUCCESS;
 * }
 *
 * void
 * AudioRecorderSample::Stop(void)
 * {
 *     __recorder.Stop();
 *     __recorder.Close();
 * }
 *
 * @endcode
 *
 */

class _OSP_EXPORT_ AudioRecorder
	: public Tizen::Base::Object
{

public:
	/**
	 * This is the default constructor for this class. @n
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 */
	AudioRecorder(void);

	/**
	 * This is the destructor for this class. @n
	 * All allocated resources are released by this method. This method must be called in the same thread in
	 * which the Construct() method is called. @n This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 *
	 */
	virtual ~AudioRecorder(void);


public:
	/**
	* Initializes this instance of %AudioRecorder with the specified listener.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	listener			An instance of IAudioRecorderEventListener
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_OUT_OF_MEMORY	    The memory is insufficient.
	* @exception	E_UNSUPPORTED_OPERATION	This audio recorder usage is not supported.
	* @exception	E_DEVICE_BUSY		The recorder is under use by other application or already used in this application.
	*/
	result Construct(IAudioRecorderEventListener& listener);

	/**
	* Creates an audio file for the recording.
	*
	* @since		2.0
	*
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return		An error code
	* @param[in]	destMediaPath			The file destination to write @n
	*										The available paths start with prefixes retrieved from the functions such as: @n
	*										Tizen::App::App::GetInstance()->GetAppRootPath() @n
	*										Tizen::System::Environment::GetMediaPath() @n
	*										Tizen::System::Environment::GetExternalStoragePath()
	* @param[in]	overwrite	            Set to @c true to overwrite a file if it already exists, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_RESOURCE_UNAVAILABLE	The required path is unavailable.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_STORAGE_FULL			The storage is full.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The application can register newly created files into the Contents database using Tizen::Content::ContentManager::CreateContent().
	* @see Close()
	*/
	result CreateAudioFile(const Tizen::Base::String& destMediaPath, bool overwrite);

	/**
	* Closes a file.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks      This method is synchronous.
	* @see			CreateAudioFile()
	*/
	result Close(void);

	/**
	* Records an audio file.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return	    An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_DEVICE_BUSY			The recorder is under use by other application.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			Stop()
        * @see	        Pause()
	*/
	result Record(void);

	/**
	* Stops a recording.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			Record()
        * @see	        Pause()
	*/
	result Stop(void);

	/**
	* Pauses a recording. @n
	* To resume a recording after the %Pause() method is called, the Record() method must be called.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
        * @see	        Stop()
	*/
	result Pause(void);

	/**
	* Cancels a recording operation without saving the data.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return	    An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks	
	*			- If this method is called, the state is changed to ::RECORDER_STATE_STOPPING.
	*			- After IAudioRecorderEventListener::OnAudioRecorderCanceled() is called, the state is changed
	*			to ::RECORDER_STATE_STOPPED.
	* @see		Record()
        * @see	    Stop()
	*/
	result Cancel(void);

	/**
	* Gets the state of an audio recorder.
	*
	* @since		2.0
	*
	* @return	    The current state of an audio recorder
        * @see   	    Close()
        * @see	        Record()
        * @see	        Stop()
        * @see	        Pause()
	*/
	RecorderState GetState(void) const;

	/**
	* Gets the current recording time.
	*
	* @since		2.0
	*
	* @return	    The value indicating the current recording time in milliseconds, @n
	*				else @c -1 if the recording has not started as yet
	*/
	long GetRecordingTime(void) const;

	/**
	* Gets the current recording size.
	*
	* @since		2.0
	*
	* @return		The value indicating the current recording size in bytes, @n
	*				else @c -1 if the recording has not started as yet
	*/
	long GetRecordingSize(void) const;

	/**
	* Sets the recording time limit for a file in milliseconds.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return		An error code
	* @param[in]	msTime		The maximum recording time in milliseconds @n
	*							The time must be greater than @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_RANGE			The specified time is out of range.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The default time is @c 60 seconds.
	* @see			GetMaxRecordingTime()
	*/
	result SetMaxRecordingTime(long msTime);

	/**
	* Gets the recording time limit of a file in milliseconds.
	*
	* @since		2.0
	*
	* @return		A @c long value indicating the maximum recording time in milliseconds
	* @see			SetMaxRecordingTime()
	*/
	long GetMaxRecordingTime(void) const;

	/**
	* @if OSPDEPREC
	* Sets the audio format of an audio recorder. @n
	* Initially, the default format is set using the internal configuration.
	*
	* @brief <i> [Deprecated]  </i>
	* @deprecated	This method is deprecated. Instead of this method, use the SetFormat(CodecType audioCodec, MediaContainerType container) method
	* 				that sets the audio codec and container together.
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return		An error code
	* @param[in]	format		The audio format to set @n
	*							::AUDIORECORDING_FORMAT_DEFAULT sets the system's default recording format.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			GetFormat()
	* @endif
	*/
	result SetFormat(AudioRecordingFormat format);

	/**
	* @if OSPDEPREC
	* Gets the audio recording format of an audio recorder.
	*
	* @brief <i> [Deprecated]  </i>
	* @deprecated	This method is deprecated. Instead of this method, use the GetFormat(CodecType& audioCodec,
	* MediaContainerType& container) const method that gets the audio codec and container together.
	* @since		2.0
	*
	* @return		The audio recording format, @n
	*               else default format if SetFormat() is not called before calling this method
	* @see			SetFormat()
	* @endif
	*/
	AudioRecordingFormat GetFormat(void) const;

	/**
	* Sets the audio codec and the container of an audio recorder. @n
	* Initially, the default codec and the container format are set using the internal configuration.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return		An error code
	* @param[in]	audioCodec				The audio codec to set
	* @param[in]	container				The media container to set
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_UNSUPPORTED_CODEC		The specified codec is not supported.
	* @exception	E_UNSUPPORTED_FORMAT	The specified container format is not supported.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		If the specified container does not support the specified codec, @c E_UNSUPPORTED_FORMAT may be returned.
	* @see			GetFormat( CodecType& audioCodec, MediaContainerType& container ) const
	*/
	result SetFormat(CodecType audioCodec, MediaContainerType container);

	/**
	* Gets the audio codec and container of an audio recorder.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[out]	audioCodec			The retrieved audio codec
	* @param[out]	container			The retrieved container
	* @exception	E_SUCCESS			The method is successful.
	* @remarks		If SetFormat(CodecType audioCodec, MediaContainerType container) is not called before calling
	*				this method, the default codec and container are retrieved. @n
	*				This method always returns @c E_SUCCESS.
	* @see			SetFormat( CodecType audioCodec, MediaContainerType container )
	*/
	result GetFormat(CodecType& audioCodec, MediaContainerType& container) const;

	/**
	* Gets a list of the supported audio codecs. @n
	* Each list's item has a ::CodecType value.
	*
	* @since		2.0
	*
	* @return       A list of supported audio codecs, @n
	*				else @c null if no codec is supported or if an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks		
	*			- The specific error code can be accessed using the GetLastResult() method.
	* 			- The return value must be released by the caller.
	* @see			SetFormat(CodecType audioCodec, MediaContainerType container)
        * @see	        GetFormat(CodecType& audioCodec, MediaContainerType& container) const
	*/
	Tizen::Base::Collection::IListT <CodecType>* GetSupportedCodecListN(void) const;

	/**
	* Gets a list of the supported containers. @n
	* Each list's item has a ::MediaContainerType value.
	*
	* @since		2.0
	*
	* @return       A list of supported container list, @n
	*				else @c null if no container is supported or if an exception occurs
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- The return value must be released by the caller.
	* @see			SetFormat(CodecType audioCodec, MediaContainerType container)
        * @see	        GetFormat(CodecType& audioCodec, MediaContainerType& container) const
	*/
	Tizen::Base::Collection::IListT <MediaContainerType>* GetSupportedContainerListN(void) const;

	/**
	* Sets the audio recording quality of the audio recorder.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return		An error code
	* @param[in]	quality				The audio recording quality of the audio recorder @n
	*									The default value is ::RECORDING_QUALITY_MEDIUM.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_INVALID_ARG		The specified @c quality is not supported.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @see			GetQuality()
	*/
	result SetQuality(RecordingQuality quality);

	/**
	* Gets the audio recording quality of the audio recorder.
	*
	* @since		2.0
	*
	* @return		The current audio recording quality of the audio recorder
	* @see			SetQuality()
	*/
	RecordingQuality GetQuality(void) const;

	/**
	* Sets the mute state of an audio recorder.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return		An error code
	* @param[in]	mute                The mute state @n
	*									By default, the mute state is disabled.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The audio recording continues even though the audio recorder is in the mute state.
	* @see			IsMuted()
	*/
	result SetMute(bool mute);

	/**
	* Checks whether the mute state is enabled for an audio recorder.
	*
	* @since		2.0
	*
	* @return		@c true if the audio recorder is not recording any sound, @n
	*				else @c false
	* @see			SetMute()
	*/
	bool IsMuted(void) const;

	/**
	* Adds a stream filter to process the audio stream data while recording.
	*
	* @since		2.1
	* @privlevel	public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return		An error code
	* @param[in]	filter			An instance of IAudioStreamFilter
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OBJ_ALREADY_EXIST     The filter already exists.
	* @exception	E_OUT_OF_MEMORY	    The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
        * @remarks 	IAudioStreamFilter::ProcessAudioStream() is called when the audio frame is ready.
	*/
	result AddAudioStreamFilter(IAudioStreamFilter& filter);

	/**
	* Removes a stream filter to stop processing the audio stream data.
	*
	* @since		2.1
	* @privlevel	public
	* @privilege    %http://tizen.org/privilege/audiorecorder
	*
	* @return		An error code
	* @param[in]	filter			An instance of IAudioStreamFilter
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OBJ_NOT_FOUND        The filter is not found.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	*/
	result RemoveAudioStreamFilter(IAudioStreamFilter& filter);

private:
	/**
	 * This is the copy constructor for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks	    The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 * @see			Construct()
	 */
	AudioRecorder(const AudioRecorder&);
	/**
	 * This is the copy assignment operator for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks	    The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 */
	AudioRecorder& operator =(const AudioRecorder& audioRecorder);

	friend class _AudioRecorderImpl;
	_AudioRecorderImpl* __pImpl;

};

}}// Tizen::Media

#endif
