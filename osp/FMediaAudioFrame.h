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
 * @file			FMediaAudioFrame.h
 * @brief			This is the header file for the %AudioFrame class.
 *
 * This header file contains the declarations of the %AudioFrame class.
 */

#ifndef _FMEDIA_AUDIO_FRAME_H_
#define _FMEDIA_AUDIO_FRAME_H_

#include <FBase.h>
#include <FMediaAudioTypes.h>

namespace Tizen { namespace Media
{

/**
 * @class	AudioFrame
 * @brief	This class has the audio frame data.
 *
 * @since		2.1
 *
 * @final	This class is not intended for extension.
 *
 * The %AudioFrame class has the audio frame data.
 * The frame has several plane components. @n
 * This object is delivered to the application by IAudioStreamFilter::ProcessAudioStream() when the audio file is streaming.
 *
 * The following example demonstrates how to use the %AudioFrame class.
 *
 * @code
 * #include <FBase.h>
 * #include <FMedia.h>
 * #include <FApp.h>
 *
 * using namespace Tizen::Media;
 *
 * class AudioFrameSample
 *     : public Tizen::Media::IAudioRecorderEventListener
 *     , public Tizen::Media::IAudioStreamFilter
 * {
 * public:
 *     AudioFrameSample(void);
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
 *     virtual void ProcessAudioStream(AudioFrame &frame);
 *
 * private:
 *     AudioRecorder __recorder;
 * };
 *
 * AudioFrameSample::AudioFrameSample(void)
 * {
 * }
 *
 * result
 * AudioFrameSample::Start(void)
 * {
 *     result r = E_SUCCESS;
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
 *     r = __recorder.AddAudioStreamListener(*this);
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
 *  }
 *
 * void
 * AudioFrameSample::Stop(void)
 * {
 *     __recorder.Stop();
 *     __recorder.Close();
 * }
 *
 * void
 * AudioFrameSample::ProcessAudioStream(AudioFrame &frame)
 * {
 *   // Manipulates the audio frame data
 *   // Gets a peak value from the audio frame.
 *   // This code supports only signed 16-bits sample format.
 *   if (frame.GetPlaneCount() < 1 || frame.GetSampleType() != AUDIO_TYPE_PCM_S16_LE)
 *   {
 *      return;
 *   }
 *   short* pSampleData = (short*)(frame.GetPlaneData(0)->GetPointer())
 *   int minPeakValue = 0;
 *   int maxPeakValue = 0;
 *   int sampleCount = frame.GetPlaneData(0)->GetCapacity() / 2;
 *   for (int i = 0; i<sampleCount; i++)
 *   {
 *        if (pSampleData[i] < minPeakValue)
 *        {
 *            minPeakValue = pSampleData[i];
 *        }
 *        if (pSampleData[i] > maxPeakValue)
 *        {
 *            maxPeakValue = pSampleData[i];
 *        }
 *   }
 * }
 *
 * @endcode
 *
 *
 */
class _OSP_EXPORT_ AudioFrame
	: public Tizen::Base::Object
{
public:

	/**
	 *
	 * Gets the plane count that a frame data has.
	 *
	 *
	 * @return       The plane count
	 *
	 */
	int GetPlaneCount(void) const;

	/**
	 *
	 * Gets the type of an audio channel.
	 *
	 *
	 * @return       The audio channel
	 *
	 */
	AudioChannelType GetChannelType(void) const;

	/**
	 *
	 * Gets the audio sample type.
	 *
	 *
	 * @return       The audio sample type
	 *
	 */
	AudioSampleType GetSampleType(void) const;

	/**
	 *
	 * Gets the audio sampling rate.
	 *
	 *
	 * @return       The audio sampling rate in Hertz (Hz)
	 *
	 */
	int GetSamplingRate(void) const;

	/**
	 *
	 * Gets the plane data at the specified @c index from a frame.
	 *
	 *
	 * @return       The plane data, @n
	 *               else @c null if an error has occurred
	 * @param[in]	index				The index at which the value is read
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_RANGE				The specified @c index is out of range.
	 * @remarks	
	 *			- The @c index should be less than the plane count.
	 *          	- The buffer in Tizen::Base::ByteBuffer is shared with the %AudioFrame instance.
	 *			- The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* GetPlaneData(int index) const;

private:

	/**
	 * This is the default constructor for this class.
	 *
	 * @remarks	The object is not fully constructed after this constructor is called. For full construction,
	 *			the Construct() method must be called right after calling this constructor.
	 */
	AudioFrame(void);

	/**
	 * This is the destructor for this class. @n
	 * All allocated resources are deallocated by this method. This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 */
	virtual ~AudioFrame(void);

	/**
	 * Constructs an instance of this class. @n
	 *
	 *
	 * @return	    An error code
	 * @exception	E_SUCCESS	The method is successful.
	 *
	 */
	result Construct(void);

	/**
	  * This is the copy constructor for this class.
	  *
	  *
	  * @remarks	    The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	  */
	AudioFrame(const AudioFrame& rhs);

	/**
	  * This is the copy assignment operator for this class.
	  *
	  *
	  * @remarks	    The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	  *
	  */
	AudioFrame& operator =(const AudioFrame& rhs);

	friend class _AudioStreamCoordinator;
	friend class _AudioFrameImpl;
	class _AudioFrameImpl* __pImpl;
};

}}// Tizen::Media

#endif
