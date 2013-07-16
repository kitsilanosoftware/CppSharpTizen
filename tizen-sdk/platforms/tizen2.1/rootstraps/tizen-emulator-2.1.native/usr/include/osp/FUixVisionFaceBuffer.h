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
 * @file     FUixVisionFaceBuffer.h
 * @brief    This is the header file for the %FaceBuffer class.
 *
 * This header file contains the declarations of the %FaceBuffer class.
 */

#ifndef _FUIX_VISION_FACE_BUFFER_H_
#define _FUIX_VISION_FACE_BUFFER_H_

#include <FBaseObject.h>
#include <FGrpDimension.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
} }

namespace Tizen { namespace Uix { namespace Vision
{

/**
 * @class    FaceBuffer
 * @brief    This class encapsulates the information processed by the FaceDetector and FaceRecognizer classes.
 *
 * @since    2.0
 *
 * @remarks    @b Header @b %file: @b \#include @b <FUix.h> @n
 *             @b Library : @b osp-face
 *
 * The %FaceBuffer class encapsulates the information processed by the FaceDetector and FaceRecognizer classes.
 * It contains proper data format that can be used in the face related methods. The user can get the face buffer from
 * FaceDetector::PreprocessDataN().
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/face_detector_recognizer.htm">Face Detector and Recognizer</a>.
 *
 */

class _OSP_EXPORT_ FaceBuffer
	: public Tizen::Base::Object
{

public:
	/**
	 * This is the destructor for this class. @n
	 * The resources are deallocated by this method.
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since    2.0
	 */
	virtual ~FaceBuffer(void);

// Operation

	/**
	 * Gets the width and height of the face data.
	 *
	 * @since     2.0
	 *
	 * @return    The dimension of the face data
	 */
	Tizen::Graphics::Dimension GetDimension(void) const;


	/**
	 * Gets the buffer that contains the face data.
	 *
	 * @since     2.0
	 *
	 * @return    A pointer to the buffer containing the face data
	 */
	const Tizen::Base::ByteBuffer* GetBuffer(void) const;

private:
	/**
	 * This is the default constructor for this class.
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	FaceBuffer(void);
	/**
	 * This constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	FaceBuffer(const Tizen::Base::ByteBuffer& buffer, const Tizen::Graphics::Dimension& dim);
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	FaceBuffer(const FaceBuffer& value);
	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	FaceBuffer& operator =(const FaceBuffer& value);

private:
	Tizen::Base::ByteBuffer* __pBuffer;
	Tizen::Graphics::Dimension __resolution;

	friend class FaceDetector;

}; // FaceBuffer

} } } // Tizen::Uix::Vision

#endif // _FUIX_VISION_FACE_BUFFER_H_
