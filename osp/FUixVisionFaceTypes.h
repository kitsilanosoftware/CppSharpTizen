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
 * @file     FUixVisionFaceTypes.h
 * @brief    This is the header file for the declarations of the Tizen::Uix::Vision namespace.
 *
 * This header file contains the declarations of the Tizen::Uix::Vision namespace.
 */

#ifndef _FUIX_VISION_FACE_TYPES_H_
#define _FUIX_VISION_FACE_TYPES_H_

namespace Tizen { namespace Uix { namespace Vision
{

/**
 * @enum     FaceDetectorConfigProperty
 *
 * Defines the configuration properties of a FaceDetector.
 *
 * @since    2.0
 *
 * @see      FaceDetector::GetRange()
 * @see      FaceDetector::GetProperty()
 */
enum FaceDetectorConfigProperty
{
	/**
	 * The maximum number of faces to detect from a video stream. @n
	 * This will be used when FaceDetector::DetectFacesFromVideoStreamN() is called.
	 */
	FACEDETECTOR_MAXNUMBER_VIDEO,

	/**
	 * The maximum number of faces to detect from a still image. @n
	 * This will be used when FaceDetector::DetectFacesFromStillImageN() is called.
	 */
	FACEDETECTOR_MAXNUMBER_IMAGE,

	/**
	 * The minimum ratio of detectable faces is relative to the size of a video stream. @n
	 * The range is from values @c 1 to @c 3, where the value @c 1 has the longest execution time and @c 3
	 * has the shortest execution time. The value @c 1 detects small faces.
	 * Therefore, for an application using a camera or a video file, the value @c 3 is an appropriate option.
	 * The value @c 3 is used when FaceDetector::DetectFacesFromVideoStreamN() is called unless it has been changed earlier
	 * using the FaceDetector::SetProperty() method. @n
	 *
	 * This will be used when %FaceDetector::DetectFacesFromVideoStreamN() is called.
	 */
	FACEDETECTOR_SCALE_VIDEO,

	/**
	 * The minimum ratio of detectable faces is relative to the size of a still image. @n
	 * The range is from values @c 1 to @c 3, where the value @c 1 has the longest execution time and @c 3 has
	 * the shortest execution time. The value @c 1 detects small faces.
	 * Therefore, for an application handling images, the value @c 1 is an appropriate option.
	 * The value @c 1 is used when FaceDetector::DetectFacesFromStillImageN() is called unless it has been changed
	 * earlier using the FaceDetector::SetProperty() method. @n
	 *
	 * This will be used when %FaceDetector::DetectFacesFromStillImageN() is called.
	 */
	FACEDETECTOR_SCALE_IMAGE,

	/**
	 * The maximum number of faces to detect. @n
	 * The value @c 1 is used when DetectFacesN() is called unless it has been changed earlier
	 * using the FaceDetector::SetProperty() method. @n
	 * This will be used when FaceDetector::DetectFacesN() is called.
	 */
	FACEDETECTOR_MAXNUMBER_FACES,

	/**
	 * The minimum ratio of detectable faces relative to the input data. @n
	 * The range is from values @c 1 to @c 3, where the value @c 1 has the longest execution time and @c 3
	 * has the shortest execution time. The value @c 1 detects small faces.
	 * The value @c 3 is used when FaceDetector::DetectFacesN() is called unless it has been changed earlier using
	 * the FaceDetector::SetProperty() method. @n
	 *
	 * This will be used when %FaceDetector::DetectFacesN() is called.
	 */
	FACEDETECTOR_SCALE_FACTOR,
};

/**
 * @enum     FaceRecognizerConfigProperty
 *
 * Defines the configuration properties of a FaceRecognizer.
 *
 * @since    2.0
 *
 * @see      FaceRecognizer::GetRange()
 * @see      FaceRecognizer::GetProperty()
 */
enum FaceRecognizerConfigProperty
{
	/**
	 * The maximum number of faces to extract face information from a video stream. @n
	 * This will be used when FaceRecognizer::ExtractFaceInfoFromVideoStreamN() is called.
	 */
	FACERECOGNIZER_MAXNUMBER_VIDEO,

	/**
	 * The maximum number of faces to extract face information from a still image. @n
	 * This will be used when FaceRecognizer::ExtractFaceInfoFromStillImageN() is called.
	 */
	FACERECOGNIZER_MAXNUMBER_IMAGE,

	/**
	 * The minimum ratio of the detectable faces relative to the size of a video stream. @n
	 * The range is from values @c 1 to @c 3, where the value @c 1 has the longest execution time and @c 3 has
	 * the shortest execution time. The value @c 1 detects small faces.
	 * Therefore, for an application using a camera or a video file, the value @c 3 is an appropriate option.
	 * The value @c 3 is used when ExtractFaceInfoFromVideoStreamN() is called unless it has been changed
	 * earlier using the FaceDetector::SetProperty() method. @n
	 *
	 * This will be used when FaceRecognizer::ExtractFaceInfoFromVideoStreamN() is called.
	 */
	FACERECOGNIZER_SCALE_VIDEO,

	/**
	 * The minimum ratio of the detectable faces relative to the size of a still image. @n
	 * The range is from values @c 1 to @c 3, where the value @c 1 has the longest execution time and @c 3 has
	 * the shortest execution time.
	 * The value @c 1 detects small faces.
	 * Therefore, for an application handling images, the value @c 1 is an appropriate option.
	 * The value @c 1 is used when ExtractFaceInfoFromStillImageN() is called unless it has been changed
	 * earlier using the FaceDetector::SetProperty() method. @n
	 *
	 * This will be used when FaceRecognizer::ExtractFaceInfoFromStillImageN() is called.
	 */
	FACERECOGNIZER_SCALE_IMAGE,
};

/**
 * @enum     FaceDetectionOption
 *
 * Defines the face detection options.
 *
 * @since    2.0
 *
 * @see      FaceDetector::DetectFacesN()
 */
enum FaceDetectionOption
{
	FACE_DETECTION_OPTION_FAST,      /**< The option to detect faces as fast as possible even if the accuracy is low */
	FACE_DETECTION_OPTION_ROBUST,    /**< The option to detect faces as accurate as possible even if it takes more time */
};

/**
 * @enum     EyeState
 *
 * Defines the eye state.
 *
 * @since    2.0
 *
 * @see      FaceRecognizer::GetEyeState()
 */
enum EyeState
{
	EYE_STATE_NONE,           /**< The no eye state, when the eye detect fails */
	EYE_STATE_BOTH_OPEN,      /**< The state when both eyes are open */
	EYE_STATE_BOTH_CLOSED,    /**< The state when both eyes are closed */
};

/**
 * @enum     FacialExpression
 *
 * Defines the facial expressions.
 *
 * @since    2.0
 *
 * @see      FaceRecognizer::RecognizeExpression()
 */
enum FacialExpression
{
	FACIAL_EXPRESSION_NONE,         /**< The no face expression, when the face recognition fails */
	FACIAL_EXPRESSION_NEUTRAL,      /**< The neutral face expression */
	FACIAL_EXPRESSION_ANGRY,        /**< The angry face expression */
	FACIAL_EXPRESSION_HAPPY,        /**< The happy face expression */
	FACIAL_EXPRESSION_SURPRISED,    /**< The surprised face expression */
};

} } } // Tizen::Uix::Vision
#endif
