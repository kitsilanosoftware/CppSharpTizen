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
* @file			FMediaImage.h
* @brief		This is the header file for the %Image class.
*
* This header file contains the declarations of the %Image class.
*/

#ifndef _FMEDIA_IMAGE_H_
#define _FMEDIA_IMAGE_H_

// include
#include <FBase.h>
#include <FGraphics.h>
#include <FMediaImageTypes.h>
#include <FMediaIImageEventListener.h>

namespace Tizen { namespace Media
{

/**
 * @class	Image
 * @brief	This class is used for handling images.
 *
 * @since	2.0
 * @remarks The minimum dimension is 16x16 for JPEG encoding and 8x8 for PNG encoding.
 *
 * The %Image class is used for handling images, including image decoding, encoding, and conversion. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/viewing_processing_still_images.htm">Viewing and Processing Still Images</a>. @n
 * The following example demonstrates how to use the %Image class for image decoding and encoding.
 *
 * @code
#include <FBase.h>
#include <FIo.h>
#include <FApp.h>
#include <FGraphics.h>
#include <FUi.h>
#include <FMedia.h>

using namespace Tizen::Base;
using namespace Tizen::Io;
using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Media;

class ImageSample
	: public Tizen::Ui::Controls::Form
{
public:
	result TestDecoding(void);
	result TestEncoding(void);
};

result
ImageSample::TestDecoding(void)
{
	result r = E_SUCCESS;
	Image img;
	Bitmap* pBitmap = null;
	Canvas *pCanvas = null;
	String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.jpg";

	img.Construct();

	// Decodes the image
	pBitmap = img.DecodeN(filePath, BITMAP_PIXEL_FORMAT_RGB565);
	if (pBitmap == null)
	{
		goto CATCH;
	}

	// Gets a Canvas instance
	pCanvas = GetCanvasN();
	if (pCanvas == null)
	{
		goto CATCH;
	}

	pCanvas->DrawBitmap(Point(0,0), *pBitmap);
	pCanvas->Show();

	return r;

CATCH:
	if (pCanvas)
	{
		delete pCanvas;
	}
	if (pBitmap)
	{
		delete pBitmap;
	}

	return r;
}

result
ImageSample::TestEncoding(void)
{
	result r = E_SUCCESS;
	Image img;
	Bitmap* pBitmap = null;
	String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.jpg";
	String dstPath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test_out.jpg";

	img.Construct();

	pBitmap = img.DecodeN(filePath, BITMAP_PIXEL_FORMAT_RGB565);
	if (pBitmap == null)
	{
		goto CATCH;
	}

	r = img.EncodeToFile(*pBitmap, IMG_FORMAT_JPG, dstPath, true);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	return r;

CATCH:
	if (pBitmap)
	{
		delete pBitmap;
	}

	return r;
}

 * @endcode
 */

class _OSP_EXPORT_ Image
	: public Tizen::Base::Object
{
public:

	/**
	* This is the default constructor for this class. @n
	* The object is not fully constructed after this constructor is called.
	* For full construction, the Construct() method must be called right after
	* calling this constructor.
	*
	* @since	2.0
	*
	* @see      Construct()
	*/
	Image(void);

	/**
	* This is the destructor for this class. @n
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*
	* @see      Construct()
	*/
	virtual ~Image(void);

public:
	/**
	* Initializes this instance of %Image.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	* @exception	E_SYSTEM		A system error has occurred.
	*/
	result Construct(void);

	/**
	* Decodes an image file into the decoded bitmap container. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP. @n
	* The %DecodeN() method retains the aspect ratio of the original image.
	*
	* @since		2.0
	*
	* @return		A decoded bitmap that is not resized
	* @param[in]	srcImagePath			The local file path of the image file to open
	* @param[in]    pixelFormat				The output pixel format defined by Tizen::Graphics::BitmapPixelFormat
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified pixel format is not supported.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @remarks
	*			  - @c E_OUT_OF_MEMORY can be returned if there is no available memory when decoding a large image.
	*			  - The specific error code can be accessed using the GetLastResult() method.
	*			  - This method returns an auto-scaled bitmap, @n
	*			    so the dimension can be different from the dimension of source image if the returned bitmap is locked.
	*/
	Tizen::Graphics::Bitmap* DecodeN(const Tizen::Base::String& srcImagePath, Tizen::Graphics::BitmapPixelFormat pixelFormat) const;

	/**
	* Decodes an image file into the decoded bitmap container after resizing it as per the specified width and height. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP. @n
	* The %DecodeN() method retains the aspect ratio of the original image. @n
	* It supports only the downscaling of an image.
	*
	* @since		2.0
	*
	* @return		A decoded bitmap data with the specified destination width and height
	* @param[in]	srcImagePath			The local file path of the image file to open
	* @param[in]    pixelFormat				The output pixel format defined by Tizen::Graphics::BitmapPixelFormat
	* @param[in]	destWidth				The intended width of the image @n
	*										An exception is returned if the value is less than @c 0.
	* @param[in]	destHeight				The intended height of the image @n
	*										An exception is returned if the value is less than @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified pixel format is not supported.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_OUT_OF_RANGE			The specified size is out of range.
	* @remarks
	*			  - The specific error code can be accessed using the GetLastResult() method.
	*			  - This method returns an auto-scaled bitmap, @n
	*			    so the dimension can be different from the requested dimension if the returned bitmap is locked.
	*/
	Tizen::Graphics::Bitmap* DecodeN(const Tizen::Base::String& srcImagePath, Tizen::Graphics::BitmapPixelFormat pixelFormat, int destWidth, int destHeight) const;

	/**
	* Decodes an image data into the decoded bitmap container after resizing it as per a specified width and height. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP. @n
	* The %DecodeN() method retains the aspect ratio of the original image.
	*
	* @since		2.1
	*
	* @return		A decoded bitmap data with the specified destination width and height
	* @param[in]	srcImageBuf				The data to decode
	* @param[in]	pixelFormat				The output pixel format defined by Tizen::Graphics::BitmapPixelFormat
	* @param[in]	destWidth				The intended width of the image
	* @param[in]	destHeight				The intended height of the image
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.
	* @exception	E_INVALID_ARG			The specified pixel format is not supported.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OBJ_NOT_FOUND			The specified image buffer cannot be found.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks
	*			  - The specific error code can be accessed using the GetLastResult() method.
	*			  - There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is @c E_OUT_OF_MEMORY or not.
	*			    For more information on how to handle the out-of-memory exception, refer <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	*			  - This method returns an auto-scaled bitmap to support logical coordinate system, so the actual dimension of the returned bitmap can vary depending on the physical dimension of the target device.
	*/
	Tizen::Graphics::Bitmap* DecodeN(const Tizen::Base::ByteBuffer& srcImageBuf, Tizen::Graphics::BitmapPixelFormat pixelFormat, float destWidth, float destHeight) const;

	/**
	* Decodes an image file into the decoded bitmap container after resizing it as per a specified width and height. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP. @n
	* The %DecodeN() method retains the aspect ratio of the original image.
	*
	* @since		2.1
	*
	* @return		A decoded bitmap data with the specified destination width and height
	* @param[in]	srcImagePath			The local file path of the image file to open
	* @param[in]	pixelFormat				The output pixel format defined by Tizen::Graphics::BitmapPixelFormat
	* @param[in]	destWidth				The intended width of the image
	* @param[in]	destHeight				The intended height of the image
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified pixel format is not supported.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @remarks
	*			  - The specific error code can be accessed using the GetLastResult() method.
	*			  - There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is @c E_OUT_OF_MEMORY or not.
	*			    For more information on how to handle the out-of-memory exception, refer <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	*			  - This method returns an auto-scaled bitmap to support logical coordinate system, so the actual dimension of the returned bitmap can vary depending on the physical dimension of the target device.
	*/
	Tizen::Graphics::Bitmap* DecodeN(const Tizen::Base::String& srcImagePath, Tizen::Graphics::BitmapPixelFormat pixelFormat, float destWidth, float destHeight) const;

	/**
	* Decodes an image data into the decoded bitmap as per the specified width and height. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP. @n
	* The %DecodeUrl() method retains the aspect ratio of the original image. @n
	* It supports only the downscaling of an image.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	srcImageUrl			The URL of the remote image to decode
	* @param[in]    pixelFormat			The output pixel format defined by Tizen::Graphics::BitmapPixelFormat
	* @param[in]	destWidth			The intended width of the image @n
	*									An exception is returned if the value is less than @c 0.
	* @param[in]	destHeight			The intended height of the image @n
	*									An exception is returned if the value is less than @c 0.
	* @param[out]   reqId               The request ID
	* @param[in]	listener			An instance of IImageDecodeUrlEventListener
	* @param[in]    timeout				The timeout period in milliseconds @n
	*									Set to @c TIMEOUT_INFINITE to make the @c timeout period infinite.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_DATA		The specified input instance has invalid data.
	* @exception	E_INVALID_ARG		The specified pixel format is not supported.
	* @exception	E_OUT_OF_RANGE		The specified size is out of range.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_NETWORK_FAILED	The network is unavailable.
	* @exception	E_MAX_EXCEEDED		The number of concurrent accesses to the URLs has reached the maximum limit.
	* @remarks
	*			  - The maximum limit for downloading is @c 3.
	*			  - The supported protocol is HTTP.
	*/
	result DecodeUrl(const Tizen::Base::Utility::Uri& srcImageUrl, Tizen::Graphics::BitmapPixelFormat pixelFormat, int destWidth, int destHeight, RequestId& reqId, const IImageDecodeUrlEventListener& listener, long timeout) const;

	/**
	* Decodes an image data into the decoded bitmap container without resizing. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP. @n
	* The %DecodeN() method retains the aspect ratio of the original image.
	*
	* @since		2.0
	*
	* @return		A decoded bitmap data that has not been resized
	* @param[in]	srcImageBuf				The data to decode
	* @param[in]	srcImageFormat			The image format of the input file
	* @param[in]    pixelFormat				The output pixel format defined by Tizen::Graphics::BitmapPixelFormat
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.
	* @exception	E_INVALID_ARG			The specified pixel format is not supported.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OBJ_NOT_FOUND			The specified image buffer cannot be found.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks
	*			  - @c E_OUT_OF_MEMORY is returned if the memory is not available when decoding a large image.
	*			  - The specific error code can be accessed using the GetLastResult() method.
	*			  - This method returns an auto-scaled bitmap, @n
	*			    so the dimension can be different from the dimension of source image if the returned bitmap is locked.
	*/
	Tizen::Graphics::Bitmap* DecodeN(const Tizen::Base::ByteBuffer& srcImageBuf, ImageFormat srcImageFormat, Tizen::Graphics::BitmapPixelFormat pixelFormat) const;

	/**
	* Decodes an image data into the decoded bitmap container after resizing it as per the specified width and height. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP. @n
	* The %DecodeN() method retains the aspect ratio of the original image. @n
	* It supports only the downscaling of an image.
	*
	* @since		2.0
	*
	* @return		A decoded bitmap data with the specified destination width and height
	* @param[in]	srcImageBuf				The data to decode
	* @param[in]	srcImageFormat			The image format of the input file
	* @param[in]	pixelFormat				The output pixel format defined by Tizen::Graphics::BitmapPixelFormat
	* @param[in]	destWidth				The intended width of the image @n
	*										An exception is returned if the value is less than @c 0.
	* @param[in]	destHeight				The intended height of the image @n
	*										An exception is returned if the value is less than @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified pixel format is not supported.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_OBJ_NOT_FOUND			The specified image buffer cannot be found.
	* @exception	E_OUT_OF_RANGE			The specified size is out of range.
	* @remarks
	*			  - The specific error code can be accessed using the GetLastResult() method.
	*			  - This method returns an auto-scaled bitmap, @n
	*			    so the dimension can be different from the requested dimension if the returned bitmap is locked.
	*/
	Tizen::Graphics::Bitmap* DecodeN(const Tizen::Base::ByteBuffer& srcImageBuf, ImageFormat srcImageFormat, Tizen::Graphics::BitmapPixelFormat pixelFormat, int destWidth, int destHeight) const;

	/**
	* Encodes the specified bitmap data into a byte buffer. @n
	* The currently supported encoding formats are JPEG, BMP, and PNG.
	*
	* @since		2.0
	*
	* @return		A byte buffer containing encoded image data
	* @param[in]	srcBitmap				The bitmap data to encode
	* @param[in]	destImageFormat			The intended image format
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_OBJ_NOT_FOUND			The specified bitmap data cannot be found.
	* @remarks
	*			  - The specific error code can be accessed using the GetLastResult() method.
	*			  - This method uses raw RGB data from locked bitmap, @n
	*			    so the dimension of encoded data can be different from the dimension of source bitmap if the bitmap is auto-scaled.
	*/
	Tizen::Base::ByteBuffer* EncodeToBufferN(const Tizen::Graphics::Bitmap& srcBitmap, ImageFormat destImageFormat) const;

	/**
	* Encodes the specified bitmap data into a file. @n
	* The currently supported encoding formats are JPEG, BMP, and PNG.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	srcBitmap				The bitmap data to encode
	* @param[in]	destImageFormat			The intended image format
	* @param[in]	destImagePath			The intended name of encoded image file @n
	*									The available paths start with prefixes retrieved from the functions such as: @n
	*									Tizen::App::App::GetInstance()->GetAppRootPath() @n
	*									Tizen::System::Environment::GetMediaPath() @n
	*									Tizen::System::Environment::GetExternalStoragePath()
	* @param[in]	overwrite				Set to @c true to overwrite the file, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_OBJ_NOT_FOUND			The specified bitmap data cannot be found.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_STORAGE_FULL          The storage is full.
	* @remarks
	*			  - The specific error code can be accessed using the GetLastResult() method.
	* 			  - The application should use Tizen::Content::ContentManager::CreateContent() to register the created file into the Contents database.
	*			  - This method uses raw RGB data from locked bitmap, @n
	*			    so the dimension of encoded data can be different from the dimension of source bitmap if the bitmap is auto-scaled.
	*/
	result EncodeToFile(const Tizen::Graphics::Bitmap& srcBitmap, ImageFormat destImageFormat, const Tizen::Base::String& destImagePath, bool overwrite) const;

	/**
	* Converts the image file to the specified image format. @n
	* This is a synchronous method. The converting formats currently supported are JPEG, BMP, and PNG.
	*
	* @since		2.0
	*
	* @return		The byte buffer containing image data
	* @param[in]	srcImagePath			The local file path of the image file to open
	* @param[in]	destImageFormat			The intended image format
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @remarks	The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Base::ByteBuffer* ConvertN(const Tizen::Base::String& srcImagePath, ImageFormat destImageFormat) const;

	/**
	* @{
	* @if OSPDEPREC
	* Compresses an encoded image file to reduce its size as per the specified limit. @n
	* The only supported compression format is JPEG.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	srcImagePath			The local file path of the image file to open
	* @param[in]	destImagePath			The destination file path @n
	*										If the file already exists, it is overwritten. @n
	*										The available paths start with prefix such as: @n
	*										Tizen::App::App::GetInstance()->GetAppRootPath() @n
	*										Tizen::System::Environment::GetMediaPath() @n
	*										Tizen::System::Environment::GetExternalStoragePath()
	* @param[in]	limitSize				The maximum compressed data size in bytes @n
	*										If the data size is too small, the width and height of the original
	*										image can be reduced. @n The size must be less than the original size
	*										and greater than @c 1024 byte.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_STORAGE_FULL          The file cannot be created because the file has reached its size limit.
	* @exception	E_OUT_OF_RANGE			The specified size is out of range.
	* @endif
	* @}
	*/
	result CompressJpeg(const Tizen::Base::String& srcImagePath, const Tizen::Base::String& destImagePath, int limitSize) const;

	/**
	* @if OSPDEPREC
	* Compresses an encoded image data to the byte buffer to reduce its data size as per the specified limit. @n
	* The only supported compression format is JPEG.
	*
	* @brief <i> [Deprecated] </i>
	* @deprecated  This method is deprecated.
	* @since		2.0
	*
	* @return		A byte buffer containing the compressed image data as per the specified size
	* @param[in]	srcImageBuf				The encoded image source in the byte buffer
	* @param[in]	limitSize				The limit size to compress in bytes @n
	*										The size must be less than the original size and greater than @c 1024 bytes.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OBJ_NOT_FOUND			The specified image buffer cannot be found.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_RANGE			The specified size is out of range.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @endif
	*/
	Tizen::Base::ByteBuffer* CompressJpegN(const Tizen::Base::ByteBuffer& srcImageBuf, int limitSize) const;

	/**
	* Decodes an image data into the decoded byte buffer container without resizing. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP.
	*
	* @since		2.0
	*
	* @return		A decoded byte data that is not resized, @n
	*				else @c null if an exception occurs
	* @param[in]	srcImageBuf				The data to decode
	* @param[in]	srcImageFormat			The image format of the input data
	* @param[in]	pixelFormat				The output pixel format defined by Tizen::Graphics::BitmapPixelFormat
	* @param[out]	imageWidth			The original width of the image @n
	*										An exception is returned if the value is less than @c 0.
	* @param[out]	imageHeight			The original height of the image @n
	*										An exception is returned if the value is less than @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified color format is not supported.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_OBJ_NOT_FOUND			The specified media buffer cannot be found.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Base::ByteBuffer* DecodeToBufferN(const Tizen::Base::ByteBuffer& srcImageBuf, ImageFormat srcImageFormat, Tizen::Graphics::BitmapPixelFormat pixelFormat, int& imageWidth, int& imageHeight) const;

	/**
	* Decodes an image file into the decoded byte buffer container without resizing. @n
	* The currently supported decoding formats are JPEG, GIF, PNG, BMP, TIFF, and WBMP.
	*
	* @since		2.0
	*
	* @return		A decoded byte data that is not resized, @n
	*				else @c null if an exception occurs
	* @param[in]	srcImagePath			The local file path of the image file to decode
	* @param[in]	pixelFormat				The output pixel format defined by Tizen::Graphics::BitmapPixelFormat
	* @param[out]	imageWidth			The original width of the image @n
	*										An exception is returned if the value is less than @c 0.
	* @param[out]	imageHeight			The original height of the image @n
	*										An exception is returned if the value is less than @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified color format is not supported.
	* @exception	E_INVALID_DATA			The specified input instance has invalid data.
	* @exception	E_OVERFLOW				The specified input instance has overflowed.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Base::ByteBuffer* DecodeToBufferN(const Tizen::Base::String& srcImagePath, Tizen::Graphics::BitmapPixelFormat pixelFormat, int& imageWidth, int& imageHeight) const;

	/**
	 * Sets the timeout interval to infinity.
	 *
	 * @since	2.0
	 */
	static const int TIMEOUT_INFINITE = 0;


	/**
	* Gets the format of the image in the specified file.
	*
	* @since		2.0
	*
	* @return		The format of the image
	* @param[in]	srcImagePath			The local path of the image file
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Media::ImageFormat GetImageFormat(const Tizen::Base::String& srcImagePath) const;

	/**
	* Gets the image format from an image buffer.
	*
	* @since		2.0
	*
	* @return		The format of the image
	* @param[in]	srcImageBuf				The Tizen::Base::ByteBuffer containing the image data
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OBJ_NOT_FOUND			The specified image buffer cannot be found.
	* @exception	E_SYSTEM				A system error has occurred.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Media::ImageFormat GetImageFormat(const Tizen::Base::ByteBuffer& srcImageBuf) const;

	/**
	* Checks whether the specified image file has alpha channels. @n
	* Currently only 32-bit PNG images are supported.
	*
	* @since		2.0
	*
	* @return		@c true if the image has alpha channels, @n
	*				else @c false
	* @param[in]	srcImagePath			The local file path of the image file
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_FILE_NOT_FOUND		The specified image file cannot be found.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	bool HasAlphaChannels(const Tizen::Base::String& srcImagePath) const;

	/**
	* Checks whether the specified image buffer has alpha channels. @n
	* Currently only 32-bit PNG images are supported.
	*
	* @since		2.0
	*
	* @return		@c true if the image has alpha channels, @n
	*				else @c false
	* @param[in]	srcImageBuf				The Tizen::Base::ByteBuffer containing the image data
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_OBJ_NOT_FOUND			The specified image buffer cannot be found.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	bool HasAlphaChannels(const Tizen::Base::ByteBuffer& srcImageBuf) const;

private:

	/**
	* The implementation of this copy constructor is intentionally blank
	* and declared as private to prohibit copying of objects.
	*/
	Image(const Image& image);

	/**
	* The implementation of this copy assignment operator is intentionally blank
	* and declared as private to prohibit copying of objects.
	*/
	Image& operator =(const Image& image);

private:
	class _ImageImpl* __pImageImpl;
	friend class _ImageImpl;

}; // class Image

};
};  // Tizen::Media

#endif
