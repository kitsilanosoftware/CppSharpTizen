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
 * @file     FUixVisionFaceComponentsPosition.h
 * @brief    This is the header file for the %FaceComponentsPosition class.
 *
 * This header file contains the declarations of the %FaceComponentsPosition class.
 */

#ifndef _FUIX_VISION_FACE_COMPONENTS_POSITION_H_
#define _FUIX_VISION_FACE_COMPONENTS_POSITION_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FGrpPoint.h>
#include <FGrpRectangle.h>

namespace Tizen { namespace Uix { namespace Vision
{

/**
 * @class    FaceComponentsPosition
 * @brief    This class encapsulates the extracted face component's information that is processed by the FaceDetector class.
 *
 * @since    2.0
 *
 * @remarks    @b Header @b %file: @b \#include @b <FUix.h> @n
 *             @b Library : @b osp-face
 *
 * The %FaceComponentsPosition class encapsulates the extracted face component's information that is processed by the FaceDetector class.
 *
 * This class provides the following functionalities: @n
 * - Getting/Setting the position of a face.
 * - Getting/Setting the position of the eyes.
 * - Getting/Setting the position of the mouth.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/face_detector_recognizer.htm">Face Detector and Recognizer</a>.
 */

class _OSP_EXPORT_ FaceComponentsPosition
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * Initializes this instance of %FaceComponentsPosition with all its attributes set to @c -1.
	 *
	 * @since      2.0
	 *
	 * @remarks    The attributes are set to @c -1 when initialized.
	 */
	FaceComponentsPosition(void);

	/**
	 * Initializes this instance of %FaceComponentsPosition with the specified parameter.
	 *
	 * @since        2.0
	 *
	 * @param[in]    faceRect          The face position that can be obtained using the FaceDetector::DetectFacesN() method
	 */
	FaceComponentsPosition(const Tizen::Graphics::Rectangle& faceRect);

	/**
	 * Initializes this instance of %FaceComponentsPosition with the specified parameters.
	 *
	 * @since        2.0
	 *
	 * @param[in]    faceRect       The face position that can be obtained using the FaceDetector::DetectFacesN() method
	 * @param[in]    leftEyePos     The eye position on the left that can be obtained using the FaceDetector::ExtractFaceComponentsN() method
	 * @param[in]    rightEyePos    The eye position on the right that can be obtained using the FaceDetector::ExtractFaceComponentsN() method
	 */
	FaceComponentsPosition(const Tizen::Graphics::Rectangle& faceRect, const Tizen::Graphics::Point& leftEyePos, const Tizen::Graphics::Point& rightEyePos);

	/**
	 * This is the destructor for this class. @n
	 * The resources are deallocated by this method.
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since    2.0
	 */
	virtual ~FaceComponentsPosition(void);


	/**
	 * Gets the position of the face.
	 *
	 * @since      2.0
	 *
	 * @return     The position of the face
	 * @remarks    The value of all the attributes is set to @c -1 if their value is not set to @c -1 during initialization.
	 */
	Tizen::Graphics::Rectangle GetFacePosition(void) const;

	/**
	 * Gets the position of the eyes.
	 *
	 * @since         2.0
	 *
	 * @param[out]    leftEyePos     The eye position on the left
	 * @param[out]    rightEyePos    The eye position on the right
	 * @remarks       The value of @c leftEyePos and @c rightEyePos is set to @c -1 if it is not set to @c -1 during initialization.
	 */
	void GetEyePosition(Tizen::Graphics::Point& leftEyePos, Tizen::Graphics::Point& rightEyePos) const;

	/**
	 * Gets the position of the mouth.
	 *
	 * @since      2.0
	 *
	 * @return     The position of the mouth
	 * @remarks    The value of all the attributes is set to @c -1 if their value is not set to @c -1 during initialization.
	 */
	Tizen::Graphics::Rectangle GetMouthPosition(void) const;

	/**
	 * Sets the position of the face.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    faceRect         The face position that can be obtained using the FaceDetector::DetectFacesN() method @n
	 *                                The value of the x and y positions for the @c faceRect parameter must be greater than or equal to @c 0. @n
	 *                                The value of the width and height for the @c faceRect parameter must be greater than @c 0.
	 * @exception    E_SUCCESS        The method is successful.
	 * @exception    E_INVALID_ARG    The specified input parameter is invalid.
	 * @see          FaceDetector::ExtractFaceComponentsN()
	 */
	result SetFacePosition(const Tizen::Graphics::Rectangle& faceRect);

	/**
	 * Sets the position of the eyes.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    leftEyePos       The eye position on the left @n
	 *                                This position can be obtained using the FaceDetector::ExtractFaceComponentsN() method.
	 * @param[in]    rightEyePos      The eye position on the right @n
	 *                                This position can be obtained using the FaceDetector::ExtractFaceComponentsN() method. @n
	 *                                The position of the eyes must be greater than or equal to @c 0. @n
	 *                                The position of @c rightEyePos must be greater than the position of @c leftEyePos.
	 * @exception    E_SUCCESS        The method is successful.
	 * @exception    E_INVALID_ARG    A specified input parameter is invalid.
	 */
	result SetEyePosition(const Tizen::Graphics::Point& leftEyePos, const Tizen::Graphics::Point& rightEyePos);

	/**
	 * Sets the position of the mouth.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    mouthRect        The position of the mouth that can be obtained using the FaceDetector::ExtractFaceComponentsN()
	 *                                method
	 * @exception    E_SUCCESS        The method is successful. @n
	 *                                The value of the x and y positions for the @c mouthRect parameter must be greater than or equal to @c 0. @n
	 *                                The value of the width and height for the @c mouthRect parameter must be greater than @c 0.
	 * @exception    E_INVALID_ARG    The specified input parameter is invalid.
	 */
	result SetMouthPosition(const Tizen::Graphics::Rectangle& mouthRect);

	/**
	 * This is the copy constructor for the %FaceComponentsPosition class. @n
	 * Initializes this instance of %FaceComponentsPosition with the specified parameter.
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since        2.0
	 *
	 * @param[in]	rhs	An instance of %FaceComponentsPosition
	 */
	FaceComponentsPosition(const FaceComponentsPosition& rhs);

	/**
	 * Assigns the value of the indicated %FaceComponentsPosition object to the current instance. @n
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since        2.0
	 *
	 * @param[in]    rhs	An instance of %FaceComponentsPosition
	 */
	FaceComponentsPosition& operator =(const FaceComponentsPosition& rhs);

// Member variable
private:
	Tizen::Graphics::Rectangle __faceRect;
	Tizen::Graphics::Point __eyeRight;
	Tizen::Graphics::Point __eyeLeft;
	Tizen::Graphics::Rectangle __mouthRect;

}; // FaceComponentsPosition

} } } // Tizen::Uix::Vision

#endif
