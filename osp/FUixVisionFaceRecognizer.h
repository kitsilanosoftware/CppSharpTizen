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
 * @file     FUixVisionFaceRecognizer.h
 * @brief    This is the header file for the %FaceRecognizer class.
 *
 * This header file contains the declarations of the %FaceRecognizer class.
 */

#ifndef _FUIX_VISION_FACE_RECOGNIZER_H_
#define _FUIX_VISION_FACE_RECOGNIZER_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FGrpBitmapCommon.h>
#include <FGrpPixelFormat.h>
#include <FUixVisionFaceTypes.h>
#include <FUixVisionFaceBuffer.h>
#include <FUixVisionFaceComponentsPosition.h>
#include <FUixVisionFaceRecognitionInfo.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
} }

namespace Tizen { namespace Base { namespace Collection
{
class IList;
template< class Type > class IListT;
template< class KeyType, class ValueType > class IMapT;
} } }

namespace Tizen { namespace Graphics
{
class Bitmap;
class Dimension;
class Rectangle;
} }

namespace Tizen { namespace Uix { namespace Vision
{
class _FaceRecognizerImpl;

/**
 * @class    FaceRecognizer
 * @brief    This class provides methods to recognize a face in an image or a video.
 *
 * @since    2.0
 *
 * @remarks  @b Header @b %file: @b \#include @b <FUix.h> @n
 *           @b Library : @b osp-face
 *
 * The %FaceRecognizer class provides the ability to automatically recognize faces in a still image or video stream.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/face_detector_recognizer.htm">Face Detector and Recognizer</a>.
 *
 * The following example demonstrates how to use the %FaceRecognizer class.
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
 * MyClass::TestFaceRecognize(void)
 * {
 *     ByteBuffer* pByteBuffer1 = null, * pByteBuffer2 = null;
 *     int width1 = 0, height1 = 0, width2 = 0, height2 = 0;
 *     result r;
 *
 *     Image * pImage = new Image();
 *     r = pImage->Construct();
 *
 *     String path1(L"test1.bmp");
 *     String path2(L"test2.bmp");
 *
 *     pByteBuffer1 = pImage->DecodeToBufferN(path1, BITMAP_PIXEL_FORMAT_RGB565,width1,height1 );
 *     pByteBuffer2 = pImage->DecodeToBufferN(path2, BITMAP_PIXEL_FORMAT_RGB565,width2,height2 );
 *
 *     //Deletes the image object
 *     delete pImage;
 *
 *     if (pByteBuffer1 && pByteBuffer2)
 *     {
 *         FaceRecognizer faceRecog;
 *         r = faceRecog.Construct();
 *         const Tizen::Base::Collection::IList* pFaceDetectList1 = faceRecog.ExtractFaceInfoFromStillImageN(*pByteBuffer1, Dimension(width1,height1), BITMAP_PIXEL_FORMAT_RGB565);
 *         const Tizen::Base::Collection::IList* pFaceDetectList2 = faceRecog.ExtractFaceInfoFromStillImageN(*pByteBuffer2, Dimension(width2,height2), BITMAP_PIXEL_FORMAT_RGB565);
 *
 *         if(pFaceDetectList1 == null || pFaceDetectList2 == null)
 *         {
 *             delete pByteBuffer1;
 *             delete pByteBuffer2;
 *             return GetLastResult();
 *         }
 *
 *         FaceRecognitionInfo* pFInfo1 = null, *pFInfo2 = null;
 *         for(int i=0; i < pFaceDetectList1->GetCount(); i++)
 *         {
 *             pFInfo1 = (Tizen::Uix::FaceRecognitionInfo*)pFaceDetectList1->GetAt(i);
 *             for(int j=0; j < pFaceDetectList2->GetCount(); j++)
 *             {
 *                 pFInfo2 = (Tizen::Uix::FaceRecognitionInfo*)pFaceDetectList2->GetAt(j);
 *                 if(faceRecog.IsMatching(*pFInfo1, *pFInfo2))
 *                 {
 *                     Tizen::Graphics::Rectangle rect1 = (Tizen::Graphics::Rectangle)pFInfo1->GetFacePosition();
 *                 }
 *             }
 *         }
 *
 *         delete pByteBuffer1;
 *         delete pByteBuffer2;
 *     }
 *     return r;
 * }
 * @endcode
 */
class _OSP_EXPORT_ FaceRecognizer
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
	FaceRecognizer(void);

	/**
	 * This is the destructor for this class. @n
	 * The resources are deallocated by this method.
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since    2.0
	 */
	virtual ~FaceRecognizer(void);


// Operation

	/**
	 * Initializes an instance of %FaceRecognizer.
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
	 * @param[out]    steppingDelta              The step size of the property @n
	 *                                           The step size is the smallest increment by which the property can be changed.
	 * @param[out]    defaultVal                 The default value of the property
	 * @exception     E_SUCCESS                  The method is successful.
	 * @exception     E_UNSUPPORTED_OPERATION    The device does not support the specified configuration property.
	 */
	result GetRange(FaceRecognizerConfigProperty configProperty, long& min, long& max, long& steppingDelta, long& defaultVal) const;

	/**
	 * Sets the value of the specified property.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    configProperty             The property to query
	 * @param[in]    value                      The new value of the property
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception    E_UNSUPPORTED_OPERATION    The device does not support the specified configuration property.
	 * @exception    E_OUT_OF_RANGE             The specified @c value is out of range.
	 * @see          GetRange()
	 */
	result SetProperty(FaceRecognizerConfigProperty configProperty, long value);

	/**
	 * Gets the current setting of the specified configuration property.
	 *
	 * @since        2.0
	 *
	 * @return       The value of the property, @n
	 *               else @c -1 if an exception occurs
	 * @param[in]    configProperty             The property to query
	 * @exception    E_SUCCESS                  The method is successful.
	 * @exception    E_UNSUPPORTED_OPERATION    The device does not support the specified configuration property.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	long GetProperty(FaceRecognizerConfigProperty configProperty) const;

	/**
	 * Gets a list of supported pixel formats.
	 *
	 * @since        2.0
	 *
	 * @return       A list of the supported pixel formats that are used in ExtractFaceInfoFromVideoStreamN() @n
	 *               The format is in the form of a string.
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IListT< Tizen::Graphics::PixelFormat >* GetSupportedFormatListN(void) const;

	/**
	 * Extracts the facial template that represents the face from a video.
	 *
	 * @since        2.0
	 *
	 * @return       A list of the FaceRecognitionInfo instances that contain the extracted facial features, @n
	 *               else @c null if an exception occurs @n
	 *               Each list's item has a pointer to the %FaceRecognitionInfo value. @n
	 *               An empty list, if there are no detected faces and there is no error. @n
	 *               The faces are not detected when the faces are too small, or when the video data is not
	 *               clear.
	 *               This is the result of a normal operation.
	 * @param[in]    byteBuffer         A pointer to the buffer containing the video data
	 * @param[in]    dim                The width and height of the video data @n
	 *                                  Both the width and height must be greater than @c 0.
	 * @param[in]    format             The format of the video data @n
	 *                                  It must be one of the pixel formats extracted from GetSupportedFormatListN().
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_INVALID_ARG      A specified input parameter is invalid, or
	 *                                  the specified @c format is invalid.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @exception    E_FAILURE          A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* ExtractFaceInfoFromVideoStreamN(const Tizen::Base::ByteBuffer& byteBuffer, const Tizen::Graphics::Dimension& dim, const Tizen::Graphics::PixelFormat format);

	/**
	 * @if OSPDEPREC
	 * Extracts the facial template that represents the face from the still image.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated This method is deprecated as it may return an improper result.
	 * Instead of using this method, use ExtractFaceInfoFromStillImageN(const Tizen::Base::ByteBuffer& byteBuffer, const Tizen::Graphics::Dimension& dim, Tizen::Graphics::BitmapPixelFormat format).
	 * To optimize the memory usage and processing time, the bitmap scales down an image
	 * by decreasing its resolution in some models, that in turn decreases the accuracy of the face library.
	 * Therefore, the usage of this method using Tizen::Base::ByteBuffer is encouraged.
	 * @since        2.0
	 *
	 * @return       A list of the FaceRecognitionInfo instances that contain the extracted facial features, @n
	 *               else @c null if an exception occurs @n
	 *               Each list's item has a pointer to the %FaceRecognitionInfo value. @n
	 *               An empty list, if there are no detected faces and there is no error. @n
	 *               The faces are not detected when the faces are too small or the image is not clear.
	 *               This is the result of a normal operation.
	 * @param[in]    bitmap             The bitmap file containing the input image data
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @exception    E_FAILURE          A system error has occurred.
	 * @remarks
	 *			  - The specific error code can be accessed using the GetLastResult() method.
	 *			  - BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 * @endif
	 */
	Tizen::Base::Collection::IList* ExtractFaceInfoFromStillImageN(const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Extracts the facial template that represents the face from the still image.
	 *
	 * @since        2.0
	 *
	 * @return       A list of the FaceRecognitionInfo instances that contain the extracted facial features, @n
	 *               else @c null if an exception occurs @n
	 *               Each list's item has a pointer to the %FaceRecognitionInfo value. @n
	 *               An empty list, if there are no detected faces and there is no error. @n
	 *               The faces are not detected when the faces are too small or the image is not clear.
	 *               This is the result of a normal operation.
	 * @param[in]    byteBuffer         The buffer containing the input image data
	 * @param[in]    dim                The width and height of the input image @n
	 *                                  Both the width and height must be greater than @c 0.
	 * @param[in]    format             The color format @n
	 * 							@c BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @exception    E_FAILURE          A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* ExtractFaceInfoFromStillImageN(const Tizen::Base::ByteBuffer& byteBuffer, const Tizen::Graphics::Dimension& dim, Tizen::Graphics::BitmapPixelFormat format);

	/**
	 * Checks whether the two specified faces match.
	 *
	 * @since        2.0
	 *
	 * @return       @c true if the two faces match, @n
	 *               else @c false
	 * @param[in]    face1              The face information of the first face
	 * @param[in]    face2              The face information of the second face
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_INVALID_ARG      A specified input parameter is invalid, or a specified FaceRecognitionInfo is not constructed.
	 * @exception    E_FAILURE          A system error has occurred.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsMatching(const FaceRecognitionInfo& face1, const FaceRecognitionInfo& face2);

	/**
	 * Gets the similarity of the two specified faces.
	 *
	 * @since        2.0
	 *
	 * @return       The degree of similarity in percentage @n
	 *               The range is from @c 0 to @c 100. @c 100 means the faces are the same, and @c 0 means there is no similarity at all between the two faces, @n
	 *               else @c -1 if an exception occurs.
	 * @param[in]    face1              The face information of the first face
	 * @param[in]    face2              The face information of the second face
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_INVALID_ARG      A specified input parameter is invalid, or a specified FaceRecognitionInfo is not constructed.
	 * @exception    E_FAILURE          A system error has occurred.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	int MeasureSimilarity(const FaceRecognitionInfo& face1, const FaceRecognitionInfo& face2);

	/**
	 * Extracts the facial template that represents a face.
	 *
	 * @since        2.0
	 *
	 * @return       The facial features of a recognized face, @n
	 *               else @c null if an exception occurs
	 * @param[in]    preprocessedFaceBuffer    The preprocessed data
	 * @param[in]    faceComponentPos          The facial information that is obtained from the
	 *                                         FaceDetector::ExtractFaceComponentsN() method @n
	 *                                         The specified facial information must contain the eye position. @n
	 *                                         The position of the eyes must be greater than or equal to @c 0.
	 *                                         The position of the eyes must be within @c preprocessedFaceBuffer. @n
	 *							If there are wrong values in the specified facial information, the result cannot be guaranteed even if it returns @c E_SUCCESS. @n
	 *							Therefore, be sure not to change the value of facial information after getting it from FaceDetector::ExtractFaceComponentsN().
	 * @exception    E_SUCCESS                 The method is successful.
	 * @exception    E_INVALID_ARG             A specified input parameter is invalid.
	 * @exception    E_OUT_OF_MEMORY           The memory is insufficient.
	 * @exception    E_SYSTEM                  A system error has occurred.
	 * @exception    E_OPERATION_FAILED        The method has failed to extract the facial information but there is no error reported. @n
	 *                                         This can happen when the detected faces are too small or the input data is not clear.
	 *                                         This is the result of a normal operation.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see          FaceDetector::PreprocessDataN()
	 * @see	         FaceDetector::ExtractFaceComponentsN()
	 */
	Tizen::Base::ByteBuffer* ExtractFeatureN(const FaceBuffer& preprocessedFaceBuffer, const FaceComponentsPosition& faceComponentPos);

	/**
	 * Detects the eye status.
	 *
	 * @since        2.0
	 *
	 * @return       The eye status, @n
	 *               else @c EYE_STATE_NONE if an exception occurs
	 * @param[in]    preprocessedFaceBuffer    The preprocessed data
	 * @param[in]    faceComponentPos          The facial information that is obtained from the FaceDetector::ExtractFaceComponentsN() method @n
	 *                                         The specified facial information must contain the eye position. @n
	 *                                         The position of the eyes must be greater than or equal to @c 0.
	 *                                         The position of the eyes must be within @c preprocessedFaceBuffer. @n
	 *							If there are wrong values in the specified facial information, the result cannot be guaranteed even if it returns @c E_SUCCESS. @n
	 *							Therefore, be sure not to change the value of facial information after getting it from FaceDetector::ExtractFaceComponentsN().
	 * @exception    E_SUCCESS                 The method is successful.
	 * @exception    E_INVALID_ARG             A specified input parameter is invalid.
	 * @exception    E_OUT_OF_MEMORY           The memory is insufficient.
	 * @exception    E_SYSTEM                  A system error has occurred.
	 * @exception    E_OPERATION_FAILED        The method has failed to detect the eye state but there is no error reported. @n
	 *                                         This can happen when the detected faces are too small or the input data is not clear.
	 *                                         This is the result of a normal operation.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see          FaceDetector::PreprocessDataN()
	 */
	EyeState GetEyeState(const FaceBuffer& preprocessedFaceBuffer, const FaceComponentsPosition& faceComponentPos);

	/**
	 * Recognizes the facial expression.
	 *
	 * @since        2.0
	 *
	 * @return       The facial expression, @n
	 *               else @c FACIAL_EXPRESSION_NONE if an exception occurs
	 * @param[in]    preprocessedFaceBuffer    The preprocessed data
	 * @param[in]    faceComponentPos          The facial information that is obtained from the FaceDetector::ExtractFaceComponentsN() method @n
	 *                                         The specified facial information must contain the eye position. @n
	 *                                         The position of the eyes must be greater than or equal to @c 0.
	 *                                         The position of the eyes must be within @c preprocessedFaceBuffer. @n
	 *							If there are wrong values in the specified facial information, the result cannot be guaranteed even if it returns @c E_SUCCESS. @n
	 *							Therefore, be sure not to change the value of facial information after getting it from FaceDetector::ExtractFaceComponentsN().
	 * @exception    E_SUCCESS                 The method is successful.
	 * @exception    E_INVALID_ARG             A specified input parameter is invalid.
	 * @exception    E_OUT_OF_MEMORY           The memory is insufficient.
	 * @exception    E_SYSTEM                  A system error has occurred.
	 * @exception    E_OPERATION_FAILED        The method has failed to extract the facial expression but there is no error reported. @n
	 *                                         This can happen when the detected faces are too small or the input data is not clear.
	 *                                         This is the result of a normal operation.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 * @see          FaceDetector::PreprocessDataN()
	 */
	FacialExpression RecognizeExpression(const FaceBuffer& preprocessedFaceBuffer, const FaceComponentsPosition& faceComponentPos);

	/**
	 * Detects the eye states from a video.
	 *
	 * @since        2.0
	 *
	 * @return       A list of eye states, @n
	 *               else @c null if an exception occurs @n
	 *               Each list's item has an EyeState value. @n
	 *               An empty list, if there are no detected eye states and there is no error. @n
	 *               The eye states are not detected when the faces are too small or the video data is not clear.
	 *               This is the result of a normal operation.
	 * @param[in]    byteBuffer         The buffer containing the video data
	 * @param[in]    dim                The width and height of the video data @n
	 *                                  Both the width and height must be greater than @c 0.
	 * @param[in]    format             The format of the video data @n
	 *                                  It must be one of the pixel formats extracted from GetSupportedFormatListN().
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @exception    E_SYSTEM           A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IMapT< Tizen::Graphics::Rectangle, EyeState >* DetectBlinksFromVideoStreamN(const Tizen::Base::ByteBuffer& byteBuffer, const Tizen::Graphics::Dimension& dim, const Tizen::Graphics::PixelFormat format);


	/**
	 * Detects the eye states from a still image.
	 *
	 * @since        2.0
	 *
	 * @return       The list of eye states, @n
	 *               else @c null if an exception occurs @n
	 *               Each list's item has an EyeState value. @n
	 *               An empty list, if there are no detected eye states and there is no error. @n
	 *               The eye states are not detected when the faces are too small or the video data is not clear.
	 *               This is the result of a normal operation.
	 * @param[in]    byteBuffer         The buffer containing the input image data
	 * @param[in]    dim                The width and height of the input image @n
	 *                                  Both the width and height must be greater than @c 0.
	 * @param[in]    format             The color format defined by Tizen::Graphics::BitmapPixelFormat
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @exception    E_SYSTEM           A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IMapT< Tizen::Graphics::Rectangle, EyeState >* DetectBlinksFromStillImageN(const Tizen::Base::ByteBuffer& byteBuffer, const Tizen::Graphics::Dimension& dim, Tizen::Graphics::BitmapPixelFormat format);

	/**
	 * Recognizes the facial expressions from a video.
	 *
	 * @since        2.0
	 *
	 * @return       A list of facial expressions, @n
	 *               else @c null if an exception occurs @n
	 *               Each list's item has a FacialExpression value. @n
	 *               An empty list, if there are no recognized facial expression and there is no error. @n
	 *               The expressions are not recognized when the faces are too small or the video data is not clear.
	 *               This is the result of a normal operation.
	 * @param[in]    byteBuffer         The buffer containing the video data
	 * @param[in]    dim                The width and height of the video data @n
	 *                                  Both the width and height must be greater than @c 0.
	 * @param[in]    format             The format of the video data @n
	 *                                  It must be one of the pixel formats extracted from GetSupportedFormatListN().
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @exception    E_SYSTEM           A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IMapT< Tizen::Graphics::Rectangle, FacialExpression >* RecognizeExpressionsFromVideoStreamN(const Tizen::Base::ByteBuffer& byteBuffer, const Tizen::Graphics::Dimension& dim, const Tizen::Graphics::PixelFormat format);


	/**
	 * Recognizes the facial expressions from the still image.
	 *
	 * @since        2.0
	 *
	 * @return       A list of the facial expressions, @n
	 *               else @c null if an exception occurs @n
	 *               Each list's item has a FacialExpression value. @n
	 *               An empty list, if there are no recognized facial expression and there is no error. @n
	 *               The expressions are not recognized when the faces are too small or the image is not clear.
	 *               This is the result of a normal operation.
	 * @param[in]    byteBuffer         The buffer containing the input image data
	 * @param[in]    dim                The width and height of the input image @n
	 *                                  Both the width and height must be greater than @c 0.
	 * @param[in]    format             The color format defined by Tizen::Graphics::BitmapPixelFormat
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_INVALID_ARG      A specified input parameter is invalid.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @exception    E_SYSTEM    A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IMapT< Tizen::Graphics::Rectangle, FacialExpression >* RecognizeExpressionsFromStillImageN(const Tizen::Base::ByteBuffer& byteBuffer, const Tizen::Graphics::Dimension& dim, Tizen::Graphics::BitmapPixelFormat format);


private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	FaceRecognizer(const FaceRecognizer& value);
	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	FaceRecognizer& operator =(const FaceRecognizer& value);
	friend class _FaceRecognizerImpl;

private:
	_FaceRecognizerImpl* __pFaceRecognizerImpl;

}; // FaceRecognizer

} } } // Tizen::Uix::Vision

#endif
