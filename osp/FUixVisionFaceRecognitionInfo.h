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
 * @file     FUixVisionFaceRecognitionInfo.h
 * @brief    This is the header file for the %FaceRecognitionInfo class.
 *
 * This header file contains the declarations of the %FaceRecognitionInfo class.
 */

#ifndef _FUIX_VISION_FACE_RECOGNITION_INFO_H_
#define _FUIX_VISION_FACE_RECOGNITION_INFO_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FGrpRectangle.h>

namespace Tizen { namespace Base{
class ByteBuffer;
} }

namespace Tizen { namespace Uix { namespace Vision
{
class _FaceRecognizerImpl;

/**
 * @class    FaceRecognitionInfo
 * @brief    This class encapsulates the information class of a recognized face using FaceRecognizer.
 *
 * @since    2.0
 *
 * @remarks  @b Header @b %file: @b \#include @b <FUix.h> @n
 *           @b Library : @b osp-face
 *
 * The %FaceRecognitionInfo class encapsulates the information of a face recognized using the FaceRecognizer class by:
 * - Getting the position of a recognized face.
 * - Getting the facial features of a recognized face.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/face_detector_recognizer.htm">Face Detector and Recognizer</a>.
 */

class _OSP_EXPORT_ FaceRecognitionInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 * The object is not fully constructed after this constructor is called.
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since    2.0
	 */
	FaceRecognitionInfo(void);

	/**
	 * This is the destructor for this class. @n
	 * The resources are deallocated by this method.
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since    2.0
	 */
	virtual ~FaceRecognitionInfo(void);

// Operation
	/**
	 * Initializes this instance of %FaceRecognitionInfo with the specified parameter.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    faceFeatures       The face features obtained from the extract methods in the FaceRecognizer class
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 * @see          FaceRecognizer::ExtractFaceInfoFromVideoStreamN()
	 * @see          FaceRecognizer::ExtractFaceInfoFromStillImageN()
	 */
	result Construct(const Tizen::Base::ByteBuffer& faceFeatures);

	/**
	 * Gets the position of a recognized face.
	 *
	 * @since     2.0
	 *
	 * @return    The position of a recognized face
	 */
	Tizen::Graphics::Rectangle GetFacePosition(void) const;


	/**
	 * Gets the facial features of a recognized face.
	 *
	 * @since     2.0
	 *
	 * @return    The facial features of a recognized face
	 */
	const Tizen::Base::ByteBuffer* GetFaceFeatures(void) const;


private:
	/*
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	FaceRecognitionInfo(const FaceRecognitionInfo& value);
	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	FaceRecognitionInfo& operator =(const FaceRecognitionInfo& value);

	void SetFacePosition(int x, int y, int width, int height);

private:
	Tizen::Graphics::Rectangle __faceRect;
	Tizen::Base::ByteBuffer* __pfaceFeatures;

	friend class _FaceRecognizerImpl;

}; // FaceRecognitionInfo

} } } // Tizen::Uix::Vision

#endif
