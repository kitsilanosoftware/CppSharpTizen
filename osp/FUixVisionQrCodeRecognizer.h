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
 * @file     FUixVisionQrCodeRecognizer.h
 * @brief    This is the header file for the %QrCodeRecognizer class.
 *
 * This header file contains the declarations of the %QrCodeRecognizer class.
 */
#ifndef _FUIX_VISION_QR_CODE_RECOGNIZER_H_
#define _FUIX_VISION_QR_CODE_RECOGNIZER_H_
#include <FBaseObject.h>
#include <FUixVisionQrCodeObject.h>
#include <FBase.h>
#include <FGraphics.h>

namespace Tizen { namespace Uix { namespace Vision
{
/**
 * @class    QrCodeRecognizer
 * @brief    This class provides methods to recognize a QR code image.
 *
 * @since    2.1
 *
 * The %QrCodeRecognizer class provides methods to generate a QR code image.
 *
 * The following example demonstrates how to use the %QrCodeRecognizer class.
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
 * class MyClass
 * 	: ICameraEventListener
 * {
 * public:
 * 	MyClass();
 * 	~MyClass();
 * 	result Initialize(void);
 * 
 * 	// Called when camera auto focus occurred
 * 	void OnCameraAutoFocused(bool completeCondition);
 * 	// Called when camera preview occurred
 * 	void OnCameraPreviewed(Tizen::Base::ByteBuffer& previewedData, result r);
 * 	// Called when camera captured image
 * 	void OnCameraCaptured(Tizen::Base::ByteBuffer& capturedData, result r);
 * 	// Called when camera  error occurred
 * 	void OnCameraErrorOccurred(Tizen::Media::CameraErrorReason r);
 * 
 * private:
 * 	QrCodeRecognizer*		__pQrRecognizer;
 * };
 * 
 * result
 * MyClass::Initialize(void)
 * {
 * 	result r;
 * 
 * 	// Creates and initializes recognition engine
 * 	__pQrRecognizer = new Tizen::Uix::Vision::QrCodeRecognizer();
 * 	r = __pQrRecognizer->Construct();
 * 
 * 	//Image size must be same as camera preview size
 * 	r = __pQrRecognizer->SetImageSize(640, 480);
 * 
 * 	return r;
 * }
 * 
 * // We suppose camera to be initialized with Tizen::Graphics::PIXEL_FORMAT_YCbCr420_PLANAR format
 * void
 * MyClass::OnCameraPreviewed(Tizen::Base::ByteBuffer& previewedData, result r)
 * {
 * 	// Processing of the camera image follows
 * 	__pQrRecognizer->ProcessImage(previewedData);
 * 
 * 	// Loops through all recognized QRs
 * 	for (int i = 0; i < __pQrRecognizer->GetRecognizedObjectCount(); i++)
 * 	{
 * 		const QrCodeObject *o = __pQrRecognizer->GetRecognizedObject(i);
 * 		String qrText = o->GetText();
 * 	}
 * }
 *
 * @endcode
 */
class _OSP_EXPORT_ QrCodeRecognizer
    : public Tizen::Base::Object
{
public:

    /**
     * This is the default constructor for this class. @n
     * The object is not fully constructed after this constructor is called. @n
     * For full construction, the Construct() method must be called right after calling this constructor.
     *
     * @since    2.1
     */
    QrCodeRecognizer(void);

    /**
     * This is the destructor for this class. @n
     * The resources are deallocated by this method.
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since    2.1
     */
    ~QrCodeRecognizer(void);

    /**
     * Initializes this instance of %QrCodeRecognizer. @n
     * Every application must call %Construct() before calling any other methods of %QrCodeRecognizer.
     *
     * @since        2.1
     *
     * @feature      %http://tizen.org/feature/vision.qrcode_recognition
     *
     * @exception    E_SUCCESS          The method is successful.
     * @exception    E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature. 
     * For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
     * @remarks      Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
     */
    result Construct(void);

    /**
     * Sets the width and height of an input image.
     *
     * @since        2.1
     *
     * @return       An error code
     *
     * @param[in]    width               The width of the frame in pixels
     * @param[in]    height              The height of the frame in pixels
     * @exception    E_SUCCESS           The method is successful.
     * @exception    E_INVALID_ARG       A specified input parameter is invalid.
     * @remarks      This method must be called once before calling ProcessImage().
     */
    result SetImageSize(int width, int height);

    /**
     * Processes an input image for recognition.
     *
     * @since        2.1
     *
     * @return       An error code
     *
     * @param[in]    imageBuffer        The input image buffer @n
     *                                  It must be allocated outside and have size of (width*height) set by SetImageSize().
     * @exception    E_SUCCESS          The method is successful.
     * @exception    E_INVALID_ARG      The specified @c imageBuffer is not allocated or the size of @c imageBuffer is not equal to the input image size set by SetImageSize().
     * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
     * @see          SetImageSize(int, int)
     */
    result ProcessImage(const Tizen::Base::ByteBuffer& imageBuffer);

    /**
     * Gets the expected ROI (Region of Interest) of the recognized QR code for focusing.
     *
     * @since        2.1
     *
     * @return       An error code
     * @param[out]   roi                 The expected ROI (Region of Interest) of the recognized QR code
     * @exception    E_SUCCESS           The method is successful.
     * @exception    E_INVALID_ARG       The specified input parameter is invalid.
     *
     * @remarks      The ROI is used to reset camera focus to get better image and it can be obtained after calling ProcessImage() at least once.
     */
    result GetFocusRoi(Tizen::Graphics::Rectangle& roi);

    /**
     * Gets a count of the recognized QR code object.
     *
     * @since        2.1
     *
     * @return       A count of the recognized QR code object
     *
     * @remarks      The recognized QR code object has index value from @c 0 to (count of the recognized QR code objects - 1)
     * @see          GetRecognizedObject(int)
     */
    int GetRecognizedObjectCount(void);

    /**
     * Gets the recognized QR code object to get information.
     *
     * @since        2.1
     *
     * @return       A pointer to QrCodeObject that includes all information about the recognized QR code object
     * @param[in]    index          The index of the recognized QR code object @n
     *                              Valid range of this parameter is @c 0 to (count of the recognized QR code objects - 1).
     * @exception    E_SUCCESS      The method is successful.
     *
     * @see          GetRecognizedObjectCount()
     */
    const QrCodeObject* GetRecognizedObject(int index) const;


private:
    /**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     */
    QrCodeRecognizer(const QrCodeRecognizer& in);

    /**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     */
    QrCodeRecognizer& operator=(const QrCodeRecognizer& in);

private:
    class _QrCodeRecognizerImpl* __pQrCodeRecognizerImpl;
    friend class _QrCodeRecognizerImpl;

};

} } } //Tizen::Uix::Vision

#endif // _FUIX_VISION_QR_CODE_RECOGNIZER_H_
