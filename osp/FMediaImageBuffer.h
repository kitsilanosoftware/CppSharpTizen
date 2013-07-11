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
 * @file   FMediaImageBuffer.h
 * @brief  This is the header file for the %ImageBuffer class.
 *
 * This header file contains the declarations of the %ImageBuffer class.
 */

#ifndef _FMEDIA_IMAGEBUFFER_H_
#define _FMEDIA_IMAGEBUFFER_H_

#include <FMediaImage.h>
#include <FMediaTypes.h>

namespace Tizen { namespace Media
{
/**
 * @class  ImageBuffer
 * @brief  This class is used for handling decoded image data.
 *
 * @since 2.0
 *
 * The %ImageBuffer class is used for handling decoded image data, including image decoding and encoding.
 * @remarks The minimum dimension is 16x16 for JPEG encoding and 8x8 for PNG encoding.
 *
 * The following example demonstrates how to use the %ImageBuffer class to decode and encode image.
 *
 * @code
#include <FMedia.h>
#include <FApp.h>

using namespace Tizen::Base;
using namespace Tizen::Media;

result
TestImageBuffer(void)
{
	result r = E_SUCCESS;
	ImageBuffer img;

	// Constructs an image buffer instance with an image file
	r = img.Construct(Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.bmp");
	if (IsFailed(r))
	{
		return r;
	}
	// Encodes the image buffer into compressed data
	r = img.EncodeToFile(Tizen::App::App::GetInstance()->GetAppRootPath()+L"data/test.jpg", IMG_FORMAT_JPG, true, 70);

	return r;
}
 * @endcode
 */

class _OSP_EXPORT_ ImageBuffer
	: public Tizen::Base::Object
{
public:
	/**
	* This is the default constructor for this class. @n
	* The object is not fully constructed after this constructor is called.
	* For full construction, the Construct() method must be called right after
	* calling this constructor.
	*
	* @since 2.0
	*
	* @see    Construct()
	*/
	ImageBuffer(void);

	/**
	* This is the destructor for this class. @n
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since 2.0
	*
	* @see    Construct()
	*/
	virtual ~ImageBuffer(void);

	/**
	* Initializes this instance of %ImageBuffer with the specified parameters.
	*
	* @since 2.0
	*
	* @return     An error code
	* @param[in]  width                 The width of image
	* @param[in]  height                The height of image
	* @param[in]  pixelFormat           The pixel format of image should be one of values returned from GetSupportedPixelFormatListN()
	* @param[in]  data                  The raw pixel data of image @n If @c data is not @c null then it will be copied into internal buffer of this instance.
	*                                   If @c null then default color data will be filled.
	* @param[in]  length                The size of data
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_INVALID_ARG         A specified input parameter is invalid.
	* @exception  E_UNSUPPORTED_FORMAT  The specified @c pixelFormat is not supported.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @see GetSupportedPixelFormatListN()
	* @remarks    It’s a high probability that the out-of-memory exception occurs. Check the exception as possible if it is E_OUT_OF_MEMORY.
	*             Refer to <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">Exception Check</a> and handle the out-of-memory.
	*/
	result Construct(int width, int height, MediaPixelFormat pixelFormat, const byte* pData = null, int length = 0);

	/**
	* Initializes this instance of %ImageBuffer with the decoded data of the given image path.
	*
	* @since 2.0
	*
	* @return     An error code
	* @param[in]  srcImagePath          The source image path
	* @param[in]  pDecodingRegion       The region that will be decoded @n If this is @c null, then the whole image will be decoded.
	* @param[in]  autoRotate            If @c true then the image will be rotated automatically based on EXIF orientation tag
	*                                   If @c false then the image will be decoded without rotation.
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_INVALID_ARG         A specified input parameter is invalid.
	* @exception  E_UNSUPPORTED_FORMAT  The specified format is not supported.
	* @exception  E_OVERFLOW            The specified input instance exceeds the supported maximum file size or dimension.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @exception  E_FILE_NOT_FOUND      The specified file cannot be found or accessed.
	* @remarks    It’s a high probability that the out-of-memory exception occurs. Check the exception as possible if it is E_OUT_OF_MEMORY.
	*             Refer to <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">Exception Check</a> and handle the out-of-memory.
	*/
	result Construct(const Tizen::Base::String &srcImagePath, const Tizen::Graphics::Rectangle *pDecodingRegion = null, bool autoRotate = true);

	/**
	* Initializes this instance of %ImageBuffer with the decoded data of the given image buffer.
	*
	* @since 2.0
	*
	* @return     An error code
	* @param[in]  srcImageBuf           The buffer that contains compressed image data
	* @param[in]  pDecodingRegion       The region that will be decoded @n If this is @c null, then the whole image will be decoded.
	* @param[in]  autoRotate            If @c true then the image will be rotated automatically based on EXIF orientation tag
	*                                   If @c false then the image will be decoded without rotation.
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_INVALID_ARG         A specified input parameter is invalid.
	* @exception  E_UNSUPPORTED_FORMAT  The specified format is not supported.
	* @exception  E_OVERFLOW            The specified input instance exceeds the supported maximum file size or dimension.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @remarks    It’s a high probability that the out-of-memory exception occurs. Check the exception as possible if it is E_OUT_OF_MEMORY.
	*             Refer to <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">Exception Check</a> and handle the out-of-memory.
	*/
	result Construct(const Tizen::Base::ByteBuffer &srcImageBuf, const Tizen::Graphics::Rectangle *pDecodingRegion = null, bool autoRotate = true);

	/**
	* Initializes this instance of %ImageBuffer with the given bitmap data. @n
	* The %Construct() method copies the raw RGB data from the @c srcBitmap,
	* so the dimension of this instance can be different from that of @c srcBitmap if the @c srcBitmap is an auto-scaled bitmap.
	*
	* @since 2.0
	*
	* @return     An error code
	* @param[in]  srcBitmap             The source bitmap data
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_INVALID_ARG         The specified input parameter is invalid.
	* @exception  E_OVERFLOW            The specified input instance exceeds the supported maximum file size or dimension.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	*/
	result Construct(const Tizen::Graphics::Bitmap &srcBitmap);

	/**
	* Converts an instance of the Tizen::Base::Object class to an instance of %ImageBuffer and then
	* compares it with the calling %ImageBuffer instance.
	*
	* @since 2.0
	*
	* @return     @c true if the value of @c rhs matches the value of the calling %ImageBuffer instance, @n
	*             else @c false
	* @param[in]  rhs   A reference to the Tizen::Base::Object instance that is to compare with the calling %ImageBuffer instance
	* @see        Tizen::Base::Object::Equals()
	*/
	virtual bool Equals(const Object& rhs) const;

	/**
	* Gets the hash value of the current instance by overriding the GetHashCode() method in the Tizen::Base::Object class.
	*
	* @since 2.0
	*
	* @return  The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

	/**
	* Gets the height of the image buffer.
	*
	* @since 2.0
	*
	* @return  The height of the image buffer
	*/
	int GetHeight(void) const;

	/**
	* Gets the width of the image buffer.
	*
	* @since 2.0
	*
	* @return  The width of the image buffer
	*/
	int GetWidth(void) const;

	/**
	* Gets the current pixel format.
	*
	* @since 2.0
	*
	* @return  The pixel format of the media
	*/
	MediaPixelFormat GetPixelFormat(void) const;

	/**
	* Encodes the data of this instance into a byte buffer. @n
	* The supported encoding formats are JPEG, BMP, and PNG.
	*
	* @since 2.0
	*
	* @return     A pointer to the Tizen::Base::ByteBuffer instance containing the encoded image data
	* @param[in]  destImageFormat       The intended image format
	* @param[in]  quality               The encoding quality @n
	*                                   Valid range of this parameter is @c 1 to @c 100.
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_OUT_OF_RANGE        A specified input parameter is out of range.
	* @exception  E_UNSUPPORTED_FORMAT  The specified format is not supported.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @remarks    The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Base::ByteBuffer* EncodeToBufferN(ImageFormat destImageFormat, int quality = 90) const;

	/**
	* Encodes the data of this instance to a file. @n
	* The supported encoding formats are JPEG, BMP, and PNG.
	*
	* @since 2.0
	*
	* @return     An error code
	* @param[in]  destImagePath         The intended name of encoded image file
	* @param[in]  destImageFormat       The intended image format
	* @param[in]  overwrite             Set to @c true to overwrite the file, @n
	*                                   else @c false
	* @param[in]  quality               The encoding quality @n
	*                                   Valid range of this parameter is @c 1 to @c 100.
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_UNSUPPORTED_FORMAT  The specified format is not supported.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @exception  E_ILLEGAL_ACCESS      The specified file cannot be found or accessed.
	* @exception  E_FILE_ALREADY_EXIST  The specified file already exists and the value of @c overwrite is @c false.
	* @exception  E_OUT_OF_RANGE        A specified input parameter is out of range.
	* @remarks    The application should use Tizen::Content::ContentManager::CreateContent() to
	*             register the created file into the Contents database.
	*/
	result EncodeToFile(const Tizen::Base::String &destImagePath, ImageFormat destImageFormat, bool overwrite, int quality = 90) const;

	/**
	* Gets an instance of Tizen::Graphics::Bitmap with the data of this instance.
	*
	* @since 2.0
	*
	* @return     A pointer to the Tizen::Graphics::Bitmap instance
	* @param[in]  pixelFormat           The bitmap pixel format
	* @param[in]  bufferScaling         The buffer scaling type
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_INVALID_ARG         A specified input parameter is invalid.
	* @exception  E_UNSUPPORTED_FORMAT  The specified format is not supported.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @remarks    The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Graphics::Bitmap* GetBitmapN(Tizen::Graphics::BitmapPixelFormat pixelFormat, Tizen::Graphics::BufferScaling bufferScaling) const;

	/**
	* Gets an instance of Tizen::Base::ByteBuffer with the data of this instance.
	*
	* @since 2.0
	*
	* @return     A pointer to the Tizen::Base::ByteBuffer instance
	* @param[in]  pixelFormat           The pixel format
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_INVALID_ARG         The specified input parameter is invalid.
	* @exception  E_UNSUPPORTED_FORMAT  The specified format is not supported.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @remarks    The specific error code can be accessed using the GetLastResult() method.
	* @see GetSupportedPixelFormatListN()
	*/
	Tizen::Base::ByteBuffer* GetByteBufferN(MediaPixelFormat pixelFormat) const;

	/**
	* Creates and returns a copy of this instance.
	*
	* @since 2.0
	*
	* @return     A copy of this instance
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @remarks    The specific error code can be accessed using the GetLastResult() method.
	*/
	virtual ImageBuffer* CloneN(void) const;

	/**
	* Gets a new %ImageBuffer with the converted pixel format of the current image data.
	*
	* @since 2.0
	*
	* @return     A pointer to the %ImageBuffer instance containing the converted %ImageBuffer by specified MediaPixelFormat
	* @param[in]  pixelFormat           The pixel format for returned %ImageBuffer
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_UNSUPPORTED_FORMAT  The specified format is not supported.
	* @exception  E_INVALID_DATA        The current data is invalid for this operation. @n
	*                                   This will happen when the width or height is not even value,
	*                                   and the requested pixel format is sub-sampled pixel format like MEDIA_PIXEL_FORMAT_YUV420P.
	* @remarks    The specific error code can be accessed using the GetLastResult() method.
	* @remarks    It’s a high probability that the out-of-memory exception occurs. Check the exception as possible if it is E_OUT_OF_MEMORY.
	*             Refer to <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">Exception Check</a> and handle the out-of-memory.
	*/
	ImageBuffer* ConvertPixelFormatN(MediaPixelFormat pixelFormat) const;

	/**
	* Gets a resized %ImageBuffer with the current image data. @n
	* The aspect ratio of the data will not be preserved.
	*
	* @since 2.0
	*
	* @return     A pointer to the %ImageBuffer instance containing the resized image data
	* @param[in]  width                 The width of the destination image
	* @param[in]  height                The height of the destination image
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_OUT_OF_RANGE        A specified input parameter is out of range.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @exception  E_INVALID_DATA        The current data is invalid for this operation. @n
	*                                   This will happen when the current pixel format is sub-sampled pixel format like @c MEDIA_PIXEL_FORMAT_YUV420P
	*                                   and the requested @c width or @c height is not even value.
	* @remarks    The specific error code can be accessed using the GetLastResult() method.
	* @remarks    It’s a high probability that the out-of-memory exception occurs. Check the exception as possible if it is E_OUT_OF_MEMORY.
	*             Refer to <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">Exception Check</a> and handle the out-of-memory.
	*/
	ImageBuffer* ResizeN(int width, int height) const;

	/**
	* Gets a horizontally or vertically flipped image from current instance.
	*
	* @since 2.0
	*
	* @return     A pointer to the %ImageBuffer instance containing the flipped image data
	* @param[in]  flipType              The flip type
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_INVALID_ARG         The specified input parameter is invalid.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @remarks    The specific error code can be accessed using the GetLastResult() method.
	* @remarks    It’s a high probability that the out-of-memory exception occurs. Check the exception as possible if it is E_OUT_OF_MEMORY.
	*             Refer to <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">Exception Check</a> and handle the out-of-memory.
	*/
	ImageBuffer* FlipN(ImageFlipType flipType) const;

	/**
	* Gets a rotated image in clockwise direction from current image.
	*
	* @since 2.0
	*
	* @return     A pointer to the %ImageBuffer instance containing the rotated image data
	* @param[in]  rotateType                The rotation type
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_INVALID_ARG         The specified input parameter is invalid.
	* @exception  E_INVALID_DATA        The current data is invalid for this operation. @n
	*                                   This will happen when the current pixel format is sub-sampled pixel format like @c MEDIA_PIXEL_FORMAT_YUYV422
	*                                   and the height is odd value and the requested rotation type is @c IMAGE_ROTATION_90 or @c IMAGE_ROTATION_270.
	* @exception  E_OUT_OF_MEMORY    The memory is insufficient.
	* @remarks    The specific error code can be accessed using the GetLastResult() method.
	* @remarks    It’s a high probability that the out-of-memory exception occurs. Check the exception as possible if it is E_OUT_OF_MEMORY.
	*             Refer to <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">Exception Check</a> and handle the out-of-memory.
	*/
	ImageBuffer* RotateN(ImageRotationType rotateType) const;

	/**
	* Crops the region of the current %ImageBuffer.
	*
	* @since 2.0
	*
	* @return     A pointer to the %ImageBuffer instance containing the cropped image data 
	* @param[in]  x                     The x position
	* @param[in]  y                     The y position
	* @param[in]  width                 The width of the destination image
	* @param[in]  height                The height of the destination image
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_OUT_OF_RANGE        A specified input parameter is out of range.
	* @exception  E_INVALID_DATA        The current data is invalid for this operation. @n
	*                                   This will happen when the current pixel format is sub-sampled pixel format like MEDIA_PIXEL_FORMAT_YUV420P
	*                                   and the requested x, y, width, or height is not even value.
	* @remarks    The specific error code can be accessed using the GetLastResult() method.
	* @remarks    It’s a high probability that the out-of-memory exception occurs. Check the exception as possible if it is E_OUT_OF_MEMORY.
	              Refer to <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">Exception Check</a> and handle the out-of-memory.
	*/
	ImageBuffer* CropN(int x, int y, int width, int height) const;

	/**
	* Gets the image information.
	*
	* @since 2.0
	*
	* @return  An error code
	* @param[in]  srcImagePath          The source image path
	* @param[out] imageFormat           The format of image
	* @param[out] width                 The width of image
	* @param[out] height                The height of image
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_UNSUPPORTED_FORMAT  The specified format is not supported.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @exception  E_FILE_NOT_FOUND      The specified file cannot be found or accessed.
	* @exception  E_SYSTEM              A system error has occurred.
	*/
	static result GetImageInfo(const Tizen::Base::String& srcImagePath, ImageFormat &imageFormat, int &width, int &height);

	/**
	* Gets the image information.
	*
	* @since 2.0
	*
	* @return  An error code
	* @param[in]  srcImageBuf          The buffer that contains compressed image data
	* @param[out]  imageFormat          The format of image
	* @param[out]  width                The width of image
	* @param[out]  height               The height of image
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_UNSUPPORTED_FORMAT  The specified format is not supported.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @exception  E_SYSTEM              A system error has occurred.
	*/
	static result GetImageInfo(const Tizen::Base::ByteBuffer& srcImageBuf, ImageFormat &imageFormat, int &width, int &height);

	/**
	* Gets a list of the supported pixel formats.
	*
	* @since 2.0
	*
	* @return     A list of the pixel formats supported by the %ImageBuffer class, @n
	*             else @c null if an exception occurs
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @exception  E_SYSTEM              A system error has occurred.
	* @remarks    The specific error code can be accessed using the GetLastResult() method.
	* @see	Construct()
	* @see	GetByteBufferN()
	*/
	static Tizen::Base::Collection::IListT<MediaPixelFormat>* GetSupportedPixelFormatListN(void);

private:

	/**
	* The implementation of this copy constructor is intentionally blank
	* and declared as private to prohibit copying of objects.
	*/
	ImageBuffer(const ImageBuffer& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank
	* and declared as private to prohibit copying of objects.
	* Use CloneN() to get an exact copy of this instance.
	* Use Equals() to compare contents of one instance with the other.
	*/
	ImageBuffer& operator =(const ImageBuffer& rhs);

	friend class _ImageBufferImpl;
	class _ImageBufferImpl* __pImpl;

};

}} // Tizen::Media
#endif // _FMEDIA_IMAGEBUFFER_H_
