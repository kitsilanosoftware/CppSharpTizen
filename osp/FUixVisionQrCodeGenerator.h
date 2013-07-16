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
 * @file     FUixVisionQrCodeGenerator.h
 * @brief    This is the header file for the %QrCodeGenerator class.
 *
 * This header file contains the declarations of the %QrCodeGenerator class.
 */

#ifndef _FUIX_VISION_QR_CODE_GENERATOR_H_
#define _FUIX_VISION_QR_CODE_GENERATOR_H_
#include <FBaseObject.h>
#include <FGrpBitmap.h>
#include <FBase.h>
#include <FMedia.h>
#include "FUixVisionQrCodeTypes.h"


namespace Tizen { namespace Uix { namespace Vision
{

/**
 * @class    QrCodeGenerator
 * @brief    This class provides methods to generate a QR code image.
 *
 * @since    2.1
 *
 * The %QrCodeGenerator class provides methods to generate a QR code image.
 *
 * The following example demonstrates how to use the %QrCodeGenerator class.
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
 * {
 * public:
 * 	MyClass();
 * 	~MyClass();
 * 	result TestQrCodeGenerator(void);
 * };
 * 
 * result
 * MyClass::TestQrCodeGenerator(void)
 * {
 * 	result r;
 * 	QrCodeGenerator qrGen;
 * 	qrGen.Construct();
 * 
 * 	int width(0), height(0);
 * 	r = qrGen.EncodeToFile("Hello Tizen!",
 * 			QR_CODE_MODE_UTF8,
 * 			QR_CODE_ERROR_CORRECTION_LEVEL_Q,
 * 			true,
 * 			"/opt/usr/media/Images/temp.png",
 * 			Tizen::Media::IMG_FORMAT_PNG,
 * 			width,
 * 			height);
 * 	return r;
 * }
 * @endcode
 */
class _OSP_EXPORT_ QrCodeGenerator
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
    QrCodeGenerator(void);

    /**
     * This is the destructor for this class. @n
     * The resources are deallocated by this method.
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since    2.1
     */
    ~QrCodeGenerator(void);

    /**
     * Initializes this instance of %QRCodeGenerator. @n
     * Every application must call %Construct() before calling any other methods of %QRCodeGenerator.
     *
     * @since        2.1
     *
     * @feature      %http://tizen.org/feature/vision.qrcode_generation
     *
     * @exception    E_SUCCESS          The method is successful.
     * @exception    E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature. 
     * For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
     * @remarks      Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
     */
    result Construct(void);

    /**
     * Gets a list of supported image file formats.
     *
     * @since        2.1
	 *
     * @return       A list of supported image file formats
     */
    static Tizen::Base::Collection::IListT<Tizen::Media::ImageFormat>* GetSupportedImageFileFormatsListN(void);

    /**
     * Encodes a QR code into a file.
     *
     * @since        2.1
     *
     * @return       An error code
     * @param[in]    message                The text to encode to QR code image
     * @param[in]    mode                   The input text encoding format (QR_CODE_MODE_ALPHANUMERIC, QR_CODE_MODE_BYTE, QR_CODE_MODE_UTF8)
     * @param[in]    errorCorrectionLevel   The QR code error correction level
     * @param[in]    compatibility          The compatibility mode with zxing library for UTF-8 codes mode when mode is selected with QR_MODE_UTF8
     * @param[in]    imageFilePath          The file path of the generated QR code image
     * @param[in]    imageFormat            The image file format of the generated QR code image
     * @param[out]   width                  The width of the generated QR code image
     * @param[out]   height                 The height of the generated QR code image
     * @exception    E_SUCCESS              The method is successful.
     * @exception    E_INVALID_ARG          A specified input parameter is invalid.
     * @exception    E_FILE_NOT_FOUND       The specified file cannot be found or accessed.
     *
     * @remarks      QR code encoding for UTF-8 is not standardized as yet.
     *               So we support UTF-8 encoding/decoding compatibility to zxing(http://code.google.com/p/zxing/) library.
     */
    result EncodeToFile(const Tizen::Base::String& message, QrCodeMode mode, QrCodeErrorCorrectionLevel errorCorrectionLevel, bool compatibility, const Tizen::Base::String& imageFilePath, Tizen::Media::ImageFormat imageFormat, int& width, int& height);

    /**
     * Encodes a QR code into a byte buffer.
     *
     * @since        2.1
     *
     * @return       A pointer to the Tizen::Base::ByteBuffer instance containing the generated QR code image
     * @param[in]    message                  The text to encode to QR code image
     * @param[in]    mode                     The input text encoding format (QR_CODE_MODE_ALPHANUMERIC, QR_CODE_MODE_BYTE, QR_CODE_MODE_UTF8)
     * @param[in]    error_level              The QR code error correction level
     * @param[in]    compatibility            The compatibility mode with zxing library for UTF-8 codes mode when mode is selected with QR_CODE_MODE_UTF8
     * @param[out]   width                    The width of the generated QR code image
     * @param[out]   height                   The height of the generated QR code image
     * @exception    E_SUCCESS                The method is successful.
     * @exception    E_INVALID_ARG            A specified input parameter is invalid.
     *
     * @remarks      QR code encoding for UTF-8 is not standardized as yet.
     *               So we support UTF-8 encoding/decoding compatibility to zxing(http://code.google.com/p/zxing/) library.
     */
    Tizen::Base::ByteBuffer* EncodeToBufferN(const Tizen::Base::String& message, QrCodeMode mode, QrCodeErrorCorrectionLevel error_level, bool compatibility, int& width, int& height);


private:
    /**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     */
    QrCodeGenerator(const QrCodeGenerator& in);

    /**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     */
    QrCodeGenerator& operator=(const QrCodeGenerator& in);

private:
    class _QrCodeGeneratorImpl* __pQrCodeGeneratorImpl;
    friend class _QrCodeGeneratorImpl;
};

} } } //Tizen::Uix::Vision

#endif // _FUIX_VISION_QR_CODE_GENERATOR_H_
