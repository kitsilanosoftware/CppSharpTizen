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
 * @file   FMediaVideoFrameExtractor.h
 * @brief  This is the header file for the %VideoFrameExtractor class.
 *
 * This header file contains the declarations of the %VideoFrameExtractor class.
 */

#ifndef _FMEDIA_VIDEO_FRAME_EXTRACTOR_H_
#define _FMEDIA_VIDEO_FRAME_EXTRACTOR_H_

#include <FBaseObject.h>
#include <FMediaImageBuffer.h>
#include <FMediaRecorderTypes.h>

namespace Tizen { namespace Media {

/**
 * @class  VideoFrameExtractor
 * @brief  This class is used to extract video frame from video file.
 *
 * @since		2.0
 *
 * The %VideoFrameExtractor class is used to extract video frame from video file.
 *
 * The following example demonstrates how to use the %VideoFrameExtractor class to extract video frame from video file.
 *
 * @code
 * #include <FMedia.h>
 * #include <FApp.h>
 * #include <FGraphics.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Media;
 * using namespace Tizen::Graphics;
 *
 *  result

 * TestVideoFrameExtractor(void)
 * {
 *    VideoFrameExtractor extractor;
 *    String path = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.mp4";
 *    result r = extractor.Construct(path, MEDIA_PIXEL_FORMAT_BGRA8888);
 *    long duration = extractor.GetDuration();
 *
 *    // Extracts video frames from the video file

 *    for (int i = 0; i < 10; i++)
 *    {
 *        ImageBuffer* pImage = extractor.GetFrameN(duration*i/10);
 *
 *        // Adds some codes that handles extracted video frame
 *
 *        delete pImage;
 *    }
 *    return E_SUCCESS;
 * }
 * @endcode
 */
class _OSP_EXPORT_ VideoFrameExtractor
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 *
	 * @see    Construct()
	 */
	VideoFrameExtractor(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 *
	 * @see    Construct()
	 */
	virtual ~VideoFrameExtractor(void);

	/**
	 * Initializes this instance of %VideoFrameExtractor with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return     An error code
	 * @param[in]  filePath              The video file path
	 * @param[in]  pixelFormat           The pixel format of output image data.
	 * @exception  E_SUCCESS             The method is successful.
	 * @exception  E_INVALID_ARG         A specified input parameter is invalid.
	 * @exception  E_UNSUPPORTED_FORMAT  The specified format is not supported.
	 * @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	 * @exception  E_FILE_NOT_FOUND      The specified file cannot be found or accessed.
	 */
	result Construct(const Tizen::Base::String &filePath, MediaPixelFormat pixelFormat);

	/**
	 * Gets the width of the video frame.
	 *
	 * @since		2.0
	 *
	 * @return  The width of video frame
	 */
	int GetWidth(void) const;

	/**
	 * Gets the height of the video frame.
	 *
	 * @since		2.0
	 *
	 * @return  The height of the video frame
	 */
	int GetHeight(void) const;

	/**
	 * Gets the duration of the video in millisecond.
	 *
	 * @since		2.0
	 *
	 * @return  The duration of the video in millisecond
	 */
	long GetDuration(void) const;

	/**
	 * Extracts video frame at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return     A pointer to ImageBuffer containing the extracted video frame
	 * @param[in]  timestamp             The timestamp of video frame to extract
	 * @exception  E_SUCCESS             The method is successful.
	 * @exception  E_OUT_OF_RANGE        The specified @c timestamp is out of range.
	 * @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	 * @exception  E_OPERATION_FAILED    Video frame at given position is not found or extraction is failed.
	 * @exception  E_UNSUPPORTED_FORMAT  The specified pixel format is not supported.
	 * @remarks
	 *           - The specific error code can be accessed using the GetLastResult() method.
	 *           - The extracted frame may not be exact frame of given timestamp,
	 *             so that the same frame can be returned even if the timestamp is different.
	 *           - Frames near the end of contents may not be extracted if no key-frame is found after timestamp.
	 */
	ImageBuffer* GetFrameN(long timestamp);

	/**
	 * Extracts video thumbnail from the specified position.
	 *
	 * @since		2.0
	 *
	 * @return     A pointer to ImageBuffer containing the extracted video frame
	 * @param[in]  path                  The video file path
	 * @param[in]  timestamp             The timestamp of video frame that want to extract
	 * @param[in]  pixelFormat           The pixel format of output image data.
	 * @exception  E_SUCCESS             The method is successful.
	 * @exception  E_INVALID_ARG         A specified input parameter is invalid.
	 * @exception  E_OUT_OF_RANGE        The specified @c timestamp is out of range.
	 * @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	 * @exception  E_OPERATION_FAILED    Video frame at given position is not found or extraction is failed.
	 * @exception  E_UNSUPPORTED_FORMAT  The specified pixel format is not supported.
	 * @remarks
	 *           - The specific error code can be accessed using the GetLastResult() method.
	 *           - The extracted frame may not be exact frame of given timestamp,
	 *             so that the same frame can be returned even if the timestamp is different.
	 *           - Frames near the end of contents may not be extracted if no key-frame is found after timestamp.
	 */
	static ImageBuffer* GetFrameN(const Tizen::Base::String& path, MediaPixelFormat pixelFormat, long timestamp);

	/**
	* Gets the current recording rotation of the video data.
	*
	* @since 2.1
	*
	* @return The recording rotation information of the current video data
	*/
	RecordingRotation GetRecordingRotation(void) const;


private:
	/**
	 * This is the copy constructor for this class.
	 */
	VideoFrameExtractor(const VideoFrameExtractor& rhs);

	/**
	 * This is the assignment operator.
	 */
	VideoFrameExtractor& operator =(const VideoFrameExtractor& rhs);

private:
	friend class _VideoFrameExtractorImpl;
	class _VideoFrameExtractorImpl* __pImpl;
};

}} // Tizen::Media

#endif // _FMEDIA_VIDEO_FRAME_EXTRACTOR_H_

