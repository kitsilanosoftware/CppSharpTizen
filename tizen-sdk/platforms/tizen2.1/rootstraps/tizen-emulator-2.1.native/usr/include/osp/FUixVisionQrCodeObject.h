//
// Open Service Platform
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
 * @file     FUixVisionQrCodeObject.h
 * @brief    This is the header file for the %QrCodeObject class.
 *
 * This header file contains the declarations of the %QrCodeObject class.
 */

#ifndef _FUIX_VISION_QR_CODE_OBJECT_H_
#define _FUIX_VISION_QR_CODE_OBJECT_H_

#include <FUixVisionQrCodeTypes.h>
#include <FBaseObject.h>
#include <FBase.h>
#include <FGraphics.h>

namespace Tizen { namespace Uix { namespace Vision
{

/**
 * @class    QrCodeObject
 * @brief    This class represents a single QR code object recognized by QrCodeRecognizer and provides the method to access information of the recognized QR code object.
 *
 * @since    2.1
 *
 * The %QrCodeObject class represents a single QR code object recognized by QrCodeRecognizer and provides the method to access information of the recognized QR code object.
 */

class _OSP_EXPORT_ QrCodeObject
    : public Tizen::Base::Object
{

public:

    /**
     * Gets a unique identifier of the recognized QR code object in a scene.
     *
     * @since        2.1
     *
     * @return       A unique identifier of the recognized QR code object in a scene
     */
    int GetId(void) const;

    /**
     * Gets a version of the recognized QR code object.
     *
     * @since        2.1
     *
     * @return       A version of the recognized QR code object
     */
    int GetVersion(void) const;

    /**
     * Gets an error correction level of the recognized QR code object.
     *
     * @since        2.1
     *
     * @return       An error correction level of the recognized QR code object
     */
    Tizen::Uix::Vision::QrCodeErrorCorrectionLevel GetErrorCorrectionLevel(void) const;

    /**
     * Gets a text of the QR code object.
     *
     * @since        2.1
     *
     * @return       A text of the QR code object
     */
    Tizen::Base::String GetText(void) const;

    /**
     * Gets a transformation matrix 4x4 for 3D pose of the recognized QR code object.
     *
     * @since        2.1
     *
     * @return       A pointer to transformation matrix 4x4 for object position
     */
    const Tizen::Graphics::FloatMatrix4* GetTransformMatrix(void) const;

    /**
     * Gets a transformed quadrilateral of the recognized QR code object.
     *
     * @since        2.1
     *
     * @return       The array list of 4 points of the quadrilateral of the recognized QR code object
     */
    const Tizen::Base::Collection::IListT<Tizen::Graphics::FloatPoint>* GetRectangle(void) const;

    /**
     * Compares the calling instance with a specified instance.
     *
     * @since        2.1
     *
     * @return       @c true if the specified instance of Tizen::Base::Object is equal to the calling %QrCodeObject instance, @n
     *               else @c false
     * @param[in]    obj                 The object to compare
     */
    virtual bool Equals(const Tizen::Base::Object& obj) const;

    /**
     * Gets the hash value of a current instance.
     *
     * @since     2.1
     *
     * @return    The hash value of the current instance
     */
    virtual int GetHashCode(void) const;

private:
    /**
     * This is the default constructor for this class.
     * The implementation of this constructor is declared as private to prohibit construction of the object by user.
     *
     * @since    2.1
     */
    QrCodeObject(void);

    /**
     * This is the destructor for this class. @n
     *
     * @since    2.1
     */
    ~QrCodeObject(void);

    /**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     */
    QrCodeObject(const QrCodeObject&);

    /**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     */
    QrCodeObject& operator=(const QrCodeObject&);

private:
    class _QrCodeObjectImpl* __pQrCodeObjectImpl;
    friend class _QrCodeObjectImpl;
};

} } } //Tizen::Uix::Vision
#endif // _FUIX_VISION_QR_CODE_OBJECT_H_
