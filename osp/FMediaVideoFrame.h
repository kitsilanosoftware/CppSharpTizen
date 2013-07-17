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
 * @file			FMediaVideoFrame.h
 * @brief			This is the header file for the %VideoFrame class.
 *
 * This header file contains the declarations of the %VideoFrame class.
 */

#ifndef _FMEDIA_VIDEO_FRAME_H_
#define _FMEDIA_VIDEO_FRAME_H_

#include <FBase.h>
#include <FMediaTypes.h>

namespace Tizen { namespace Media
{

/**
 * @class	VideoFrame
 * @brief	This class has the video frame data.
 *
 * @final	This class is not intended for extension.
 *
 * @since		2.1
 *
 * The %VideoFrame class has the video frame data.
 * The frame has several plane components which represents each color of YUV. @n
 * This object is delivered to the application by IVideoStreamFilter::ProcessVideoStream() when the video is being streamed.
 *
 * The following example demonstrates how to use the %VideoFrame class.
 *
 * @code
 * #include <FBase.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Graphics;
 * using namespace Tizen::Ui;
 * using namespace Tizen::Ui::Controls;
 * using namespace Tizen::Media;
 *
 * class VideoFrameSample
 *     : public Tizen::Ui::Controls::Form
 *     , public Tizen::Media::ICameraEventListener
 *     , public Tizen::Media::IVideoStreamFilter
 * {
 * public:
 *     VideoFrameSample(void);
 *     result Start(void);
 *     void Stop(void);
 *
 * protected:
 *     virtual void OnCameraAutoFocused(bool completeCondition) {}
 *     virtual void OnCameraPreviewed( Tizen::Base::ByteBuffer& previewedData, result r) {}
 *     virtual void OnCameraCaptured( Tizen::Base::ByteBuffer& capturedData, result r) {}
 *     virtual void OnCameraErrorOccurred(CameraErrorReason r ) {}
 *     virtual void ProcessVideoStream(VideoFrame &frame);
 *
 * private:
 *     Camera __camera;
 *     OverlayRegion * __pOverlay;
 * };
 *
 * VideoFrameSample::VideoFrameSample(void)
 * {
 *     __pOverlay = null;
 * }
 *
 * result
 * VideoFrameSample::Start(void)
 * {
 *     result r = E_SUCCESS;
 *     Rectangle rect(0, 0, 320, 240);
 *     bool modified = false;
 *     bool isValid = false;
 *     BufferInfo bufferInfo;
 *
 *     r = __camera.Construct(*this, CAMERA_PRIMARY);
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     r = __camera.PowerOn();
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     r = __camera.AddVideoStreamFilter(*this);
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     isValid = OverlayRegion::EvaluateBounds(OVERLAY_REGION_EVALUATION_OPTION_LESS_THAN, rect, modified);
 *     if (isValid != true)
 *     {
 *         return GetLastResult();
 *     }
 *
 *     // Gets OverlayRegion from this Form
 *     __pOverlay = GetOverlayRegionN(rect, OVERLAY_REGION_TYPE_PRIMARY_CAMERA);
 *     if (__pOverlay == null)
 *     {
 *         return GetLastResult();
 *     }
 *
 *     __pOverlay->GetBackgroundBufferInfo(bufferInfo);
 *
 *     r = __camera.StartPreview(&bufferInfo, true);
 *     if (IsFailed(r))
 *     {
 *         goto CATCH;
 *     }
 *
 *     return E_SUCCESS;
 * CATCH:
 *     if (__pOverlay)
 *     {
 *         delete __pOverlay;
 *         __pOverlay = null;
 *     }
 *     return r;
 *  }
 *
 * void
 * VideoFrameSample::Stop(void)
 * {
 *     __camera.StopPreview();
 *     __camera.PowerOff();
 *     if (__pOverlay)
 *     {
 *         delete __pOverlay;
 *         __pOverlay = null;
 *     }
 * }
 *
 * void
 * VideoFrameSample::ProcessVideoStream(VideoFrame &frame)
 * {
 *     MediaPixelFormat format = frame.GetPixelFormat();
 *     int count = frame.GetPlaneCount();
 *     int width = frame.GetWidth();
 *     int height = frame.GetHeight();
 *
 *     for (int i=0; i<count; i++)
 *     {
 *        switch(frame.GetPlaneType(i))
 *        {
 *        case VIDEO_PLANE_TYPE_Y:
 *           // Manipulates Y plane.
 *           break;
 *        case VIDEO_PLANE_TYPE_U:
 *           // Manipulates U plane.
 *            break;
 *        case VIDEO_PLANE_TYPE_V:
 *           // Manipulates V plane.
 *           break;
 *        case VIDEO_PLANE_TYPE_YUV:
 *           // Manipulates YUV plane, which YUV data exists in linear memory space. Check pixel format to detect the order of YUV data.
 *           break;
 *        case VIDEO_PLANE_TYPE_UV:
 *           // Manipulates UV plane, which UV data exists in linear memory space. Check pixel format to detect the order or UV data.
 *           break;
 *        default:
 *           break;
 *     }
 * }
 *
 * @endcode
 *
 *
 */
class _OSP_EXPORT_ VideoFrame
	: public Tizen::Base::Object
{
public:
	/**
	 *
	 * Gets the plane count that the frame data has.
	 *
	 * @since		2.1
	 *
	 * @return           The plane count
	 *
	 */
	int GetPlaneCount(void) const;

	/**
	 *
	 * Gets the video plane type at a specified index from the frame.
	 *
	 * @since		2.1
	 *
	 * @return       The video plane type, @n
	 *               else ::VIDEO_PLANE_TYPE_NONE if an error occurred
	 * @param[in]	index				The index at which the value is read
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_RANGE				The specified index is out of range.
	 * @remarks	
	 *			- The index should be less than the plane count.
	 *			- The specific error code can be accessed using the GetLastResult() method.
	 *
	 */
	VideoPlaneType GetPlaneType(int index) const;

	/**
	 *
	 * Gets the plane data at a specified index from the frame.
	 *
	 * @since		2.1
	 *
	 * @return       The plane data, @n
	 *               else @c null if an error occurred
	 * @param[in]	index				The index at which the value is read
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_RANGE				The specified index is out of range.
	 * @remarks	
	 *			- The index should be less than the plane count.
	 *          	- The buffer in ByteBuffer is shared with VideoFrame instance.
	 *			- The specific error code can be accessed using the GetLastResult() method.
	 *
	 */
	Tizen::Base::ByteBuffer* GetPlaneData(int index) const;

	/**
	 *
	 * Gets the bytes count per a line of a specified index plane.
	 *
	 * @since		2.1
	 *
	 * @return       The number of bytes per a line of the plane, @n
	 *               else @c 0 if an error occurred
	 * @param[in]	index				The index at which the value is read
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_RANGE				The specified index is out of range.
	 * @remarks	
	 *			- The index should be less than the plane count.
	 *			- The specific error code can be accessed using the GetLastResult() method.
	 *
	 */
	int GetBytesCountPerLine(int index) const;

	/**
	 *
	 * Gets the width of the frame.
	 *
	 * @since		2.1
	 *
	 * @return       The width of the frame
	 *
	 */
	int GetWidth(void) const;

	/**
	 *
	 * Gets the height of the frame.
	 *
	 * @since		2.1
	 *
	 * @return       The height of the frame
	 *
	 */
	int GetHeight(void) const;

	/**
	 *
	 * Gets the pixel format of the frame.
	 *
	 * @since		2.1
	 *
	 * @return       The pixel format of the frame
	 *
	 */
	MediaPixelFormat GetPixelFormat(void) const;

private:
	/**
	 * This is the default constructor for this class. @n
	 * The object is not fully constructed after this constructor is called. @n For full construction,
	 * the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.1
	 */
	VideoFrame(void);

	/**
	 * This is the destructor for this class. @n
	 * All allocated resources are deallocated by this method. This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~VideoFrame(void);

	/**
	 * Constructs the instance of this class. @n
	 *
	 * @since	2.1
	 *
	 * @return	    An error code
	 * @exception	E_SUCCESS	The method is successful.
	 *
	 */
	result Construct(void);

	/**
	  * This is the copy constructor for this class.
	  *
	  * @since		2.1
	  *
	  * @remarks	    The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	  */
	VideoFrame(const VideoFrame& rhs);

	/**
	  * This is the copy assignment operator for this class.
	  *
	  * @since		2.1
	  *
	  * @remarks	    The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	  *
	  */
	VideoFrame& operator =(const VideoFrame& rhs);

	friend class _VideoStreamCoordinator;
	friend class _VideoFrameImpl;
	class _VideoFrameImpl* __pImpl;

};

}}// Tizen::Media

#endif
