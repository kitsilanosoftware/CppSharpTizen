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
 * @file			FMediaVideoRecorder.h
 * @brief			This is the header file for the %VideoRecorder class.
 *
 * This header file contains the declarations of the %VideoRecorder class.
 */

#ifndef _FMEDIA_VIDEO_RECORDER_H_
#define _FMEDIA_VIDEO_RECORDER_H_

#include <FMediaVideoRecorderTypes.h>
#include <FMediaIVideoRecorderEventListener.h>
#include <FMediaCamera.h>
#include <FMediaTypes.h>

namespace Tizen { namespace Media
{

class _VideoRecorderImpl;

/**
 * @class	VideoRecorder
 * @brief	This class records a video.
 *
 * @since		2.0
 *
 * The %VideoRecorder class provides video recording from the camera device. All the input sources must be
 * controlled independently from the video recording operation. The supported codecs and resolutions are
 * device-dependent and the available list can be retrieved using the methods available in this class.
 * The recording operation is limited by the maximum time or size.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/recording_video.htm">Recording Video</a>.
 *
 * The following example demonstrates how to use the %VideoRecorder class.
 *
 * @code
 * #include <FBase.h>
 * #include <FGraphics.h>
 * #include <FUi.h>
 * #include <FApp.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Graphics;
 * using namespace Tizen::Ui;
 * using namespace Tizen::Ui::Controls;
 * using namespace Tizen::Media;
 *
 * class VideoRecorderSample
 *     : public Tizen::Ui::Controls::Form
 *     , public Tizen::Media::ICameraEventListener
 *     , public Tizen::Media::IVideoRecorderEventListener
 * {
 * public:
 *     VideoRecorderSample(void);
 *     result Start(void);
 *     void Stop(void);
 *
 * protected:
 *     // ICameraEventListener
 *     virtual void OnCameraAutoFocused(bool completeCondition) {}
 *     virtual void OnCameraCaptured(Tizen::Base::ByteBuffer &capturedData, result r) {}
 *     virtual void OnCameraErrorOccurred(CameraErrorReason err) {}
 *     virtual void OnCameraPreviewed(Tizen::Base::ByteBuffer &previewedData, result r) {}
 *
 *     // IVideoRecorderEventListener
 *     virtual void OnVideoRecorderCanceled(result r) {}
 *     virtual void OnVideoRecorderClosed(result r) {}
 *     virtual void OnVideoRecorderEndReached(RecordingEndCondition endCondition) {}
 *     virtual void OnVideoRecorderErrorOccurred( RecorderErrorReason r) {}
 *     virtual void OnVideoRecorderPaused(result r) {}
 *     virtual void OnVideoRecorderStarted(result r) {}
 *     virtual void OnVideoRecorderStopped(result r) {}
 *
 * private:
 *     Camera __camera;
 *     VideoRecorder __recorder;
 *     OverlayRegion *__pOverlay;
 * };
 *
 *
 * VideoRecorderSample::VideoRecorderSample(void)
 * {
 *     __pOverlay = null;
 * }
 *
 * result
 * VideoRecorderSample::Start(void)
 * {
 *     result r = E_SUCCESS;
 *     Tizen::Graphics::Rectangle rect(0, 0, 320, 240);
 *     BufferInfo bufferInfo;
 *     String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.mp4";
 *
 *     __pOverlay = GetOverlayRegionN(rect, OVERLAY_REGION_TYPE_PRIMARY_CAMERA);
 *     if (__pOverlay == null)
 *     {
 *         return GetLastResult();
 *     }
 *
 *      __pOverlay->GetBackgroundBufferInfo(bufferInfo);
 *
 *      r = __camera.Construct(*this);
 *      if (IsFailed(r))
 *     {
 *          goto CATCH;
 *     }
 *
 *      r = __camera.PowerOn();
 *      if (IsFailed(r))
 *     {
 *          goto CATCH;
 *     }
 *
 *      r = __recorder.Construct(*this, __camera);
 *      if (IsFailed(r))
 *     {
 *          goto CATCH;
 *     }
 *
 *      r = __camera.StartPreview(&bufferInfo, false);
 *      if (IsFailed(r))
 *     {
 *          goto CATCH;
 *     }
 *
 *      r = __recorder.CreateVideoFile(filePath, true);
 *      if (IsFailed(r))
 *     {
 *          goto CATCH;
 *     }
 *
 *      r = __recorder.Record();
 *      if (IsFailed(r))
 *     {
 *          goto CATCH;
 *     }
 *
 *      return E_SUCCESS;
 *
 * CATCH:
 *      if (__pOverlay)
 *      {
 *          delete __pOverlay;
 *          __pOverlay = null;
 *      }
 *      return r;
 * }
 *
 * void
 * VideoRecorderSample::Stop(void)
 * {
 *     __recorder.Stop();
 *     __camera.StopPreview();
 *     __camera.PowerOff();
 *     if (__pOverlay)
 *     {
 *         delete __pOverlay;
 *         __pOverlay = null;
 *     }
 * }
 *
 *
 * @endcode
 *
 */
class _OSP_EXPORT_ VideoRecorder
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks	The object is not fully constructed after this constructor is called. For full construction,
	 * the Construct() method must be called right after calling this constructor.
	 */
	VideoRecorder(void);

	/**
	 * This is the destructor for this class. @n
	 * All allocated resources are deallocated by this method. This method must be called in the same thread in
	 * which the Construct() method is called.This polymorphic destructor should be overridden if required. This way,
	 * the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 *
	 */
	virtual ~VideoRecorder(void);

	/**
	* Initializes this instance of %VideoRecorder with an associated listener and an input source.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	listener			An event listener object
	* @param[in]	camera				A Camera object for the input source
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	* @exception	E_DEVICE_BUSY		The recorder is under use by other application or already used in this application.
	* @exception	E_UNSUPPORTED_OPERATION	This video recorder usage is not supported.
	*/
	result Construct(IVideoRecorderEventListener& listener, const Camera& camera);

	/**
	* Creates a video file for a recording.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since		2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompIoPathPage "here".
	* @endif
	* @privilege	%http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @param[in]	destMediaPath				The destination for the file that is written @n
	*										The available paths start with prefixes retrieved from the functions such as: @n
	*											Tizen::App::App::GetInstance()->GetAppRootPath() @n
	*											Tizen::System::Environment::GetMediaPath() @n
	*											Tizen::System::Environment::GetExternalStoragePath()
	* @param[in]	overwrite	                Set to @c true to overwrite the file, @n
	*											else @c false
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_RESOURCE_UNAVAILABLE		The required file path is unavailable.
	* @exception	E_FILE_ALREADY_EXIST		The specified file already exists.
	* @exception	E_STORAGE_FULL				The storage is full.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		The application can register newly created files into the Contents database using Tizen::Content::ContentManager::CreateContent().
	* @see          Close()
	*/
	result CreateVideoFile(const Tizen::Base::String& destMediaPath, bool overwrite);

	/**
	* Closes the video file. @n
	* This is a synchronous method.
	*
	* @since		2.0
	* @privilege    %http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			CreateVideoFile()
	*/
	result Close(void);

	/**
	* Records the video file. @n
	* Resumes the recording if Pause() has been called.
	*
	* @since		2.0
	* @privilege    %http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_DEVICE_BUSY			The recorder is under use by other application.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks      This method must be called after the input media source is started (for example, Camera::StartPreview()).
	* @see			Stop()
	*/
	result Record(void);

	/**
	* Stops the recording.
	*
	* @since		2.0
	* @privilege    %http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			Record()
	* @see			Pause()
	*/
	result Stop(void);

	/**
	* Pauses the recording. @n
	* To resume the recording after the %Pause() method is called, Record() must be called.
	*
	* @since		2.0
	* @privilege    %http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	    The application does not have the privilege to call this method.
	* @see			Stop()
	*/
	result Pause(void);

	/**
	* Cancels the recording operation without saving the data.
	*
	* @since		2.0
	* @privilege	%http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		When this method is called, the state is changed to ::RECORDER_STATE_STOPPING. @n
	*				After IVideoRecorderEventListener::OnVideoRecorderCanceled() is called, the state is changed to
	*				@c RECORDER_STATE_STOPPED.
	* @see			Record()
	* @see			Stop()
	*/
	result Cancel(void);

	/**
	* Gets the state of a recorder.
	*
	* @since		2.0
	*
	* @return		The current state of the video recorder
	* @see			CreateVideoFile()
	* @see			Close()
	* @see			Record()
	* @see			Stop()
	* @see			Pause()
	* @see			RecorderState
	*/
	RecorderState GetState(void) const;

	/**
	* Gets the current recording time.
	*
	* @since		2.0
	*
	* @return		The current recording time in milliseconds, @n
	*				else @c -1 if the recording has not started as yet
	*/
	long GetRecordingTime(void) const;

	/**
	* Gets the current recording size.
	*
	* @since		2.0
	*
	* @return		A @c long value indicating the current recording size in bytes, @n
	*				else @c -1 if the recording has not started as yet
	*/
	long GetRecordingSize(void) const;

	/**
	* Sets the time limit for the recording in milliseconds.
	*
	* @since		2.0
	* @privilege    %http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @param[in]	msTime				The maximum recording time in milliseconds @n
	*									The time must be greater than @c 0.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_RANGE		The specified time is out of range.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The default time is @c 60 seconds.
	* @see			GetMaxRecordingTime()
	*/
	result SetMaxRecordingTime(long msTime);

	/**
	* Gets the time limit of the recording in milliseconds.
	*
	* @since		2.0
	*
	* @return		A @c long value indicating the maximum recording time in milliseconds, @n
	*				else @c -1 if the recording has not started as yet
	* @see			SetMaxRecordingTime()
	*/
	long GetMaxRecordingTime(void) const;

	/**
	* @if OSPDEPREC
	* Sets the codec for the recorder. @n
	* Initially, the default codec from the internal configuration is set.
	*
	* @brief <i> [Deprecated]  </i>
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the SetFormat(CodecType audioCodec, CodecType videoCodec, MediaContainerType container) method that
	* sets the audio/video codec and container together.
	* @since		2.0
	* @privilege    %http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @param[in]	codec					The codec name @n
	*										It must be one of the strings listed by GetSupportedCodecListN(). @n
	*										GetSupportedCodecListN() returns the list of strings in the following formats: @n
	*										- "VIDEO_CODEC_H263" @n
	*										- "VIDEO_CODEC_MPEG4SP" @n
	*										The returned strings are different depending on each device. @n
	*										The following string is always operated upon. This value is different
	*										for each device. @n
	*										"VIDEO_CODEC_DEFAULT": the default codec
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_UNSUPPORTED_CODEC		The specified codec is not supported.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			GetCodec()
	* @endif
	*/
	result SetCodec(const Tizen::Base::String& codec);

	/**
	* @if OSPDEPREC
	* Gets the codec for the recorder.
	*
	* @brief <i> [Deprecated]  </i>
	* @deprecated	This method is deprecated. @n
	    * Instead of using this method, use the GetFormat(CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container) const
	* method that gets the audio/video codec and container together.
	* @since		2.0
	*
	* @return		The current codec
	* @see			SetCodec()
	* @see			GetSupportedCodecListN()
	* @endif
	*/
	Tizen::Base::String GetCodec(void) const;

	/**
	* @if OSPDEPREC
	* Gets the list of supported video recorder codecs. @n
	* Each item in the list is a Tizen::Base::String value.
	*
	* @brief <i> [Deprecated]  </i>
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the GetSupportedAudioCodecListN() and GetSupportedVideoCodecListN() methods.
	* @since		2.0
	*
	* @return       The list of strings that represents the supported video recorder codecs, @n
	*				else @c null if no codec is supported or if an exception occurs
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*               The return value must be released by the caller. @n
	*               All items in the list must be released by the caller.
	* @see			SetCodec()
	* @see			GetCodec()
	* @endif
	*/
	Tizen::Base::Collection::IList* GetSupportedCodecListN(void) const;

	/**
	* Gets the list of supported audio codecs. @n
	* Each item in the list has a ::CodecType value.
	*
	* @since		2.0
	*
	* @return       A list of supported audio codecs, @n
	*				else @c null if no codec is supported or if an exception occurs
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*               The return value must be released by the caller.
	* @see			SetFormat( CodecType audioCodec, CodecType videoCodec, MediaContainerType container )
	* @see			GetFormat( CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container ) const
	*/
	Tizen::Base::Collection::IListT <CodecType>* GetSupportedAudioCodecListN(void) const;

	/**
	* Gets the list of supported video codecs. @n
	* Each item in the list has a ::CodecType value.
	*
	* @since		2.0
	*
	* @return       A list of supported video codecs, @n
	*				else @c null if no codec is supported or if an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*               The return value must be released by the caller.
	* @see			SetFormat( CodecType audioCodec, CodecType videoCodec, MediaContainerType container )
	* @see			GetFormat( CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container ) const
	*/
	Tizen::Base::Collection::IListT <CodecType>* GetSupportedVideoCodecListN(void) const;

	/**
	* Gets the list of supported containers. @n
	* Each item in the list has a ::MediaContainerType value.
	*
	* @since		2.0
	*
	* @return       A list of supported containers, @n
	*				else @c null if no container is supported or if an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*               The return value must be released by the caller.
	* @see			SetFormat( CodecType audioCodec, CodecType videoCodec, MediaContainerType container )
	* @see			GetFormat( CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container ) const
	*/
	Tizen::Base::Collection::IListT <MediaContainerType>* GetSupportedContainerListN(void) const;

	/**
	* @if OSPDEPREC
	* Sets the video format of the recorder. @n
	* Initially, the default format from internal configuration is set.
	*
	* @brief <i> [Deprecated]  </i>
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the SetFormat(CodecType audioCodec, CodecType videoCodec, MediaContainerType container) method that sets
	* the audio/video codec and container together.
	* @since		2.0
	* @privilege    %http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @param[in]	format					The video format @n
	*										::VIDEORECORDING_FORMAT_DEFAULT sets the system's default recording format.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @see			GetFormat()
	* @endif
	*/
	result SetFormat(VideoRecordingFormat format);

	/**
	* @if OSPDEPREC
	* Gets the current format that has been set for the recorder.
	*
	* @brief <i> [Deprecated]  </i>
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the GetFormat(CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container) const method
	* that gets the audio/video codec and container together.
	* @since		2.0
	*
	* @return		The current video format, @n
	*               else the default format if SetFormat() is not called before this method
	* @see			SetFormat()
	* @endif
	*/
	VideoRecordingFormat GetFormat(void) const;

	/**
	* @if OSPDEPREC
	* Sets the mode of the recorder.
	*
	* @brief <i> [Deprecated]  </i>
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the SetFormat(CodecType audioCodec, CodecType videoCodec, MediaContainerType container) method that
	* determines whether the video recorder includes the audio codec.
	* @since		2.0
	* @privilege    %http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @param[in]	mode				The mode for the recording @n
	*									The default mode is ::VIDEORECORDER_MODE_VIDEO_WITH_AUDIO.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_INVALID_ARG		The specified @c mode is not supported.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @see			GetMode()
	* @endif
	*/
	result SetMode(VideoRecorderMode mode);

	/**
	* @if OSPDEPREC
	* Gets the mode of the recorder.
	*
	* @brief <i> [Deprecated]  </i>
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the GetFormat(CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container) const
	* method that determines whether the video recorder includes the audio codec.
	* @since		2.0
	*
	* @return		The current mode
	* @see			SetMode()
	* @endif
	*/
	VideoRecorderMode GetMode(void) const;

	/**
	* Sets the audio and video codecs, and the container of the recorder. @n
	* Initially, the default codec and container format are set with the internal configuration.
	*
	* @since		2.0
	* @privilege    %http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @param[in]	audioCodec				The audio codec to set @n
	*										::CODEC_NONE makes the audio stream empty.
	* @param[in]	videoCodec				The video codec to set @n
	*										::CODEC_NONE cannot be set.
	* @param[in]	container				The media container to set
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_UNSUPPORTED_CODEC		The specified codec is not supported.
	* @exception	E_UNSUPPORTED_FORMAT	The specified container format is not supported.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		If the audio codec is ::CODEC_NONE, the audio will be ignored, and only the video stream will be recorded. @n
	*				If the specified container does not support the specified codec, @c E_UNSUPPORTED_FORMAT may be returned.
	* @see			GetFormat( CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container ) const
	*/
	result SetFormat(CodecType audioCodec, CodecType videoCodec, MediaContainerType container);

	/**
	* Gets the audio and video codecs, and the container of the recorder.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[out]	audioCodec			The retrieved audio codec
	* @param[out]	videoCodec			The retrieved video codec
	* @param[out]	container			The retrieved container
	* @exception	E_SUCCESS			The method is successful.
	* @remarks		The default codecs and container are retrieved, if SetFormat( CodecType audioCodec, CodecType
	*				videoCodec, MediaContainerType container) is not called before calling this method. @n
	*				This method always returns E_SUCCESS.
	* @see			SetFormat( CodecType audioCodec, CodecType videoCodec, MediaContainerType container )
	*/
	result GetFormat(CodecType& audioCodec, CodecType& videoCodec, MediaContainerType& container) const;

	/**
	* Sets the quality of the recorder.
	*
	* @since		2.0
	* @privilege    %http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @param[in]	quality				The quality of the recorder @n
	*									The default quality is ::RECORDING_QUALITY_MEDIUM.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_INVALID_ARG		The specified @c quality is not supported.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @see			GetQuality()
	*/
	result SetQuality(RecordingQuality quality);

	/**
	* Gets the quality of the recorder.
	*
	* @since		2.0
	*
	* @return		The current quality
	* @see			SetQuality()
	*/
	RecordingQuality GetQuality(void) const;

	/**
	* Sets the recording resolution of the recorder. @n
	* Initially, the default resolution from the internal configuration is set.
	*
	* @since		2.0
	* @privilege	%http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @param[in]	resolution			The recording resolution @n
	*									It must be one of the listed strings extracted from
	*									GetSupportedRecordingResolutionListN().
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_RANGE		The specified resolution is out of range.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		If the input source is Tizen::Media::Camera, its preview resolution value must be same as that
	*				of this recording resolution.
	* @see			GetRecordingResolution()
	*/
	result SetRecordingResolution(const Tizen::Graphics::Dimension& resolution);

	/**
	* Gets the recording resolution.
	*
	* @since		2.0
	*
	* @return		The recording resolution
	* @see			GetSupportedRecordingResolutionListN()
	*/
	Tizen::Graphics::Dimension GetRecordingResolution(void) const;

	/**
	* Gets a list of the supported video recorder resolutions. @n
	* Each list item is a Tizen::Graphics::Dimension value.
	*
	* @since		2.0
	*
	* @return		A list of strings representing the supported video recorder resolutions, @n
	*				else an empty list if no recording resolution is supported or if an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*				The return value must be released by the calling method. @n
	*				All items in the list must be released by the calling method.
	* @see			SetRecordingResolution()
	* @see			GetRecordingResolution()
	*/
	Tizen::Base::Collection::IList* GetSupportedRecordingResolutionListN(void) const;

	/**
	* Gets the maximum supported frame rate of the input resolution.
	*
	* @since		2.0
	*
	* @return		The maximum frame rate of the input recording resolution
	* @param[in]	dim						The preview resolution of the source
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified input resolution is invalid.
	* @exception	E_SYSTEM				A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult method.
	* @see			Camera::SetPreviewFrameRate()
	*/
	int GetSupportedMaxFrameRate(const Tizen::Graphics::Dimension& dim) const;

	/**
	* Sets the mute state of a recorder.
	*
	* @since		2.0
	* @privilege    %http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @param[in]    mute                Set to @c true to enable the mute state of the recorder, @n
	*									else @c false
	*                                   By default, the mute state is disabled.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The recording continues even in the mute state.
	* @see			IsMuted()
	*/
	result SetMute(bool mute);

	/**
	* Checks whether the mute state of the recorder is enabled.
	*
	* @since		2.0
	*
	* @return		The mute state of the recorder
	* @see			SetMute()
	*/
	bool IsMuted(void) const;

	/**
	* Sets the recording rotation of the recorder.
	*
	* @since		2.0
	* @privilege	%http://tizen.org/privilege/videorecorder
	*
	* @return		An error code
	* @param[in]	rotation 			The rotation of the recorder
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE 	This method is invalid for the current state of this instance.
	* @exception	E_INVALID_ARG		The specified @c rotation is not supported.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		This method add the rotation information to the video file.
	*                     A video player can rotate the surface or the stream using this information to display correctly.
	* @see			GetRecordingRotation()
	*/
	result SetRecordingRotation(RecordingRotation rotation);

	/**
	* Gets the rotation of the recorder.
	*
	* @since		2.0
	*
	* @return		The current recording rotation
	* @see			SetRecordingRotation()
	*/
	RecordingRotation GetRecordingRotation(void) const;

private:
	/**
	 * This is the copy constructor for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks	    The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 * @see			Construct()
	 */
	VideoRecorder(const VideoRecorder& videoRecorder);
	/**
	 * This is the copy assignment operator for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks	    The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 */
	VideoRecorder& operator =(const VideoRecorder& videoRecorder);

	friend class _VideoRecorderImpl;
	_VideoRecorderImpl* __pImpl;
};

}}// Tizen::Media

#endif
