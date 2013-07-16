//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
 * @file     FUixVisionFaceDetector.h
 * @brief    This is the header file for the %FaceDetector class.
 *
 * This header file contains the declarations of the %FaceDetector class.
 */

#ifndef _FUIX_VISION_FACE_DETECTOR_H_
#define _FUIX_VISION_FACE_DETECTOR_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FGrpBitmapCommon.h>
#include <FGrpPixelFormat.h>
#include <FUixVisionFaceTypes.h>
#include <FUixVisionFaceBuffer.h>
#include <FUixVisionFaceComponentsPosition.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
} }

namespace Tizen { namespace Base { namespace Collection
{
class IList;
template< class Type > class IListT;
} } }

namespace Tizen { namespace Graphics
{
class Bitmap;
class Dimension;
class Rectangle;
} }

namespace Tizen { namespace Uix { namespace Vision
{
class _FaceDetectorImpl;

/**
 * @class    FaceDetector
 * @brief    This class is used to trace faces in an image or a video.
 *
 * @since    2.0
 *
 * @remarks  @b Header @b %file: @b \#include @b <FUix.h> @n
 *           @b Library : @b osp-face
 *
 * The %FaceDetector class provides the ability to automatically detect and trace faces in a still image or a video stream.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/face_detector_recognizer.htm">Face Detector and Recognizer</a>.
 *
 * The following example demonstrates how to use the %FaceDetector class.
 *
 * @code
 * #include <FBase.h>
 * #include <FUix.h>
 * #include <FGraphics.h>
 * #include <FIo.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Media;
 * using namespace Tizen::Graphics;
 * using namespace Tizen::Io;
 * using namespace Tizen::Uix::Vision;
 *
 * result
 * MyClass::TestFaceDetect(void)
 * {
 *         ByteBuffer* pByteBuffer = null;
 *         int width = 0, height = 0;
 *         result r = E_SUCCESS;
 *
 *         Image* pImage = new Image();
 *         r = pImage->Construct();
 *
 *         String path(L"test.bmp");
 *
 *         pByteBuffer = pImage->DecodeToBufferN(path, BITMAP_PIXEL_FORMAT_RGB565,width,height );
 *
 *         //Deletes the image object
 *         delete pImage;
 *
 *         if (pByteBuffer)
 *         {
 *             //Detects faces
 *             FaceDetector faceDetect;
 *             r = faceDetect.Construct();
 *             const Tizen::Base::Collection::IList* pFaceDetectList = faceDetect.DetectFacesFromStillImageN(*pByteBuffer, Dimension(width,height), BITMAP_PIXEL_FORMAT_RGB565);
 *
 *             if(pFaceDetectList == null)
 *             {
 *                 delete pByteBuffer;
 *                 return GetLastResult();
 *             }
 *
 *             for(int i=0; i < pFaceDetectList->GetCount(); i++)
 *             {
 *                 Tizen::Graphics::Rectangle* pRect = (Tizen::Graphics::Rectangle*)pFaceDetectList->GetAt(i);
 *             }
 *
 *             delete pFaceDetectList;
 *         }
 *
 *         return r;
 * }
 * @endcode
 */
class _OSP_EXPORT_ FaceDetector
	: public Tizen::Base::Object
{

// Lifecycle
public:
	/**
	 * This is the default constructor for this class. @n
	 * The object is not fully constructed after this constructor is called.
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since    2.0
	 */
	FaceDetector(void);

	/**
	 * This is the destructor for this class. @n
	 * The resources are deallocated by this method.
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since    2.0
	 */
	virtual ~FaceDetector(void);


// Operation

	/**
	 * Initializes this instance of %FaceDetector.
	 *
	 * @since        2.0
	 *
	 * @feature      %http://tizen.org/feature/vision.face_recognition
	 * @return       An error code
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_UNSUPPORTED_OPERATION   The target device does not support the face detection feature. @b Since: @b 2.1
	 * For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks      Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	result Construct(void);

	/**
	 * Gets the range and default value of the specified configuration property.
	 *
	 * @since         2.0
	 *
	 * @return        An error code
	 * @param[in]     configProperty             The property to query
	 * @param[out]    min                        The minimum value of the property
	 * @param[out]    max                        The maximum value of the property
	 * @param[out]    steppingDelta              The step size for the property @n
	 *                                           The step size is the smallest increment by which the property can be changed.
	 * @param[out]    defaultVal                 The default value of the property
	 * @exception     E_SUCCESS                  The method is successful.
	 * @exception     E_UNSUPPORTED_OPERATION    The device does not support this property.
	 */
	result GetRange(FaceDetectorConfigProperty configProperty, long& min, long& max, long& steppingDelta, long& defaultVal) const;

	/**
	 * Sets the value of the specified property.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    configProperty             The property to query
	 * @param[in]    value                      The new value of the property
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception    E_UNSUPPORTED_OPERATION    The device does not support this property.
	 * @exception    E_OUT_OF_RANGE             The specified @c value is out of range.
	 * @see          GetRange()
	 */
	result SetProperty(FaceDetectorConfigProperty configProperty, long value);

	/**
	 * Gets the current setting of the specified configuration property.
	 *
	 * @since        2.0
	 *
	 * @return       The value of the property, @n
	 *               else @c -1 if an exception occurs
	 * @param[in]    configProperty             The property to query
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception    E_UNSUPPORTED_OPERATION    The device does not support this property.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	long GetProperty(FaceDetectorConfigProperty configProperty) const;

	/**
	 * Gets a list of supported pixel formats.
	 *
	 * @since        2.0
	 *
	 * @return       A list of the supported pixel formats that are used in the DetectFacesFromVideoStreamN() method @n
	 *               The format is in the form of a string.
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IListT< Tizen::Graphics::PixelFormat >* GetSupportedFormatListN(void) const;

	/**
	 * Searches for faces from a video.
	 *
	 * @since        2.0
	 *
	 * @return       A list of the detected face positions @n
	 *               Each list's item has a pointer of Tizen::Graphics::Rectangle value. @n
	 *               An empty list, if there are no detected faces and there is no error. @n
	 *               The faces are not detected when the faces are too small or the video data is not clear. @n
	 *               This is the result of a normal operation, @n
	 *               else @c null if an exception occurs.
	 * @param[in]    byteBuffer         The buffer containing the video data
	 * @param[in]    dim                The width and height of the video data @n
	 *                                  Both the width and height must be greater than @c 0.
	 * @param[in]    format             The format of video data @n
	 *                                  It must be one of the pixel formats extracted from GetSupportedFormatListN().
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @exception    E_FAILURE          A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* DetectFacesFromVideoStreamN(const Tizen::Base::ByteBuffer& byteBuffer, const Tizen::Graphics::Dimension& dim, const Tizen::Graphics::PixelFormat format);

	/**
	 * @if OSPDEPREC
	 * Detects faces from a still image.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated as it may return an improper result.
	 * Instead of using this method, use DetectFacesFromStillImageN(Tizen::Base::ByteBuffer &, Tizen::Graphics::Dimension &, Tizen::Graphics::BitmapPixelFormat).
	 * To optimize the memory usage and processing time, the bitmap scales down an image by decreasing its resolution in some models,
	 * that in turn decreases the accuracy of the face library. Therefore, the usage of this method using Tizen::Base::ByteBuffer is encouraged.
	 * @since        2.0
	 *
	 * @return       A list of the detected face positions @n
	 *               Each list's item has a pointer of Tizen::Graphics::Rectangle value. @n
	 *               An empty list, if there are no detected faces and there is no error @n
	 *               The faces are not detected when the faces are too small or the image is not clear. @n
	 *               This is the result of a normal operation, @n
	 *               else @c null if an exception occurs.
	 * @param[in]    bitmap             The bitmap file containing the input image data
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @exception    E_FAILURE          A system error has occurred.
	 * @remarks
	 *			  - The specific error code can be accessed using the GetLastResult() method.
	 *			  - BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 * @endif
	 */
	Tizen::Base::Collection::IList* DetectFacesFromStillImageN(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Searches for faces from a still image.
	 *
	 * @since        2.0
	 *
	 * @return       A list of the detected face positions @n
	 *               Each list's item has a pointer of Tizen::Graphics::Rectangle value. @n
	 *               An empty list, if there are no detected faces and there is no error @n
	 *               The faces are not detected when the faces are too small or the image is not clear. @n
	 *               This is the result of a normal operation, @n
	 *               else @c null if an exception occurs.
	 * @param[in]    byteBuffer         The buffer containing the input image data
	 * @param[in]    dim                The width and height of the input image @n
	 *                                  Both the width and height must be greater than @c 0.
	 * @param[in]    format             The color format @n
	 *							@c BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @exception    E_FAILURE          A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.  
	 */
	Tizen::Base::Collection::IList* DetectFacesFromStillImageN(const Tizen::Base::ByteBuffer& byteBuffer, const Tizen::Graphics::Dimension& dim, Tizen::Graphics::BitmapPixelFormat format);


	/**
	 * Converts the input data to a proper data format that can be used in the face related methods.
	 *
	 * @since        2.0
	 *
	 * @return       The preprocessed data, @n
	 *               else @c null if an exception occurs
	 * @param[in]    byteBuffer         The buffer containing the input data
	 * @param[in]    dim                The width and height of the input data @n
	 *                                  Both the width and height must be greater than @c 0.
	 * @param[in]    format             The format of the input data @n
	 *                                  It must be one of the pixel formats extracted from GetSupportedFormatListN().
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @exception    E_SYSTEM           A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	FaceBuffer* PreprocessDataN(const Tizen::Base::ByteBuffer& byteBuffer, const Tizen::Graphics::Dimension& dim, Tizen::Graphics::PixelFormat format);

	/**
	 * Searches for faces from the preprocessed data.
	 *
	 * @since        2.0
	 *
	 * @return       A list of the detected face positions @n
	 *               Each list's item has a pointer of Tizen::Graphics::Rectangle value. @n
	 *               An empty list, if there are no detected faces and there is no error. @n
	 *               The faces are not detected when the faces are too small or the input data is not clear. @n
	 *               This is the result of a normal operation, @n
	 *               else @c null if an exception occurs.
	 * @param[in]    preprocessedFaceBuffer     The preprocessed data @n
	 *                                          The @c preprocessedFaceBuffer must be obtained from PreprocessDataN().
	 * @param[in]    option                     The working option of detecting faces
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception    E_UNSUPPORTED_OPERATION    The specified mode is not supported.
	 * @exception    E_OUT_OF_MEMORY            The memory is insufficient.
	 * @exception    E_SYSTEM                   A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see	         FaceDetectorConfigProperty
	 */
	Tizen::Base::Collection::IList* DetectFacesN(const FaceBuffer& preprocessedFaceBuffer, FaceDetectionOption option = FACE_DETECTION_OPTION_FAST);

	/**
	 * Extracts the facial components information.
	 *
	 * @since        2.0
	 *
	 * @return       The facial components information, @n
	 *               else @c null if an exception occurs
	 * @param[in]    preprocessedFaceBuffer    The preprocessed data @n
	 *                                         The @c preprocessedFaceBuffer must be obtained from PreprocessDataN().
	 * @param[in]    faceRect                  The position of the detected face that is from DetectFacesN() @n
	 *                                         The value of x and y positions for the @c faceRect parameter must be greater than or equal to @c 0. @n
	 *                                         The value of width and height for the @c faceRect parameter must be greater than @c 0. @n
	 *                                         The position of @c faceRect must be within @c preprocessedFaceBuffer.
	 * @exception    E_SUCCESS                 The method is successful.
	 * @exception    E_INVALID_ARG             A specified input parameter is invalid.
	 * @exception    E_SYSTEM                  A system error has occurred.
	 * @exception    E_OPERATION_FAILED        The method has failed to extract the facial information, but there is no error reported. @n
	 *                                         This happens when the detected faces are too small or the input data is not clear. This is the result of a normal operation.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	FaceComponentsPosition* ExtractFaceComponentsN(const FaceBuffer& preprocessedFaceBuffer, const Tizen::Graphics::Rectangle& faceRect);


	/**
	 * Gets the position difference of the face. @n
	 * The %GetFaceMovement() method can be used for tracking the face from a sequential video data.
	 *
	 * @since         2.0
	 *
	 * @return        An error code
	 * @param[in]     prevData              The buffer containing the previous video data
	 * @param[in]     curData               The buffer containing the current video data @n
	 *                                      The size of @c prevData and @c curData must be the same. @n
	 *                                      The @c prevData and @c curData must be gotten from PreprocessDataN().
	 * @param[in]     prevFaceRect          The region of the face inside @c prevData @n
	 *                                      The value of x and y positions for the @c prevFaceRect parameter must be greater than or equal to @c 0. @n
	 *                                      The value of width and height for the @c prevFaceRect parameter must be greater than @c 0. @n
	 *                                      The specified @c prevFaceRect must be within @c prevData.
	 * @param[out]    xDiff                 The x offset that is moved from the previous to current video data
	 * @param[out]    yDiff                 The y offset that is moved from the previous to current video data
	 * @exception     E_SUCCESS             The method is successful.
	 * @exception     E_INVALID_ARG         A specified input parameter is invalid.
	 * @exception     E_OPERATION_FAILED    The method has failed to get the position difference of the specified region, but there is no error reported. @n
	 *                                      In this case, @c xDiff and @c yDiff are returned with @c 0. @n
	 *                                      It can happen when the detected faces are too small or two video data are different even if they contain the same face.
	 *                                      This is the result of a normal operation.
	 * @remarks       The specific error code can be accessed using the GetLastResult() method.
	 * @see	          DetectFacesN()
	 */
	result GetFaceMovement(const FaceBuffer& prevData, const FaceBuffer& curData, const Tizen::Graphics::Rectangle& prevFaceRect, int& xDiff, int& yDiff);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	FaceDetector(const FaceDetector& value);
	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	FaceDetector& operator =(const FaceDetector& value);
	friend class _FaceDetectorImpl;

//Member variables
private:
	_FaceDetectorImpl* __pFaceDetectorImpl;

}; // FaceDetector

} } } // Tizen::Uix::Vision

#endif // _FUIX_VISION_FACE_DETECTOR_H_
