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
 * @file		FMediaImageUtil.h
 * @brief		This is the header file for the %ImageUtil class.
 *
 * This header file contains the declarations of the %ImageUtil class.
 */

#ifndef _FMEDIA_IMAGE_UTIL_H_
#define _FMEDIA_IMAGE_UTIL_H_

#include <FBase.h>
#include <FGraphics.h>

#include <FMediaTypes.h>
#include <FMediaImageTypes.h>

namespace Tizen { namespace Media
{

class _ImageUtilImpl;

/**
 * @class	 ImageUtil
 * @brief	 This class provides methods for converting the color space of the image, flipping, rotating, and resizing.
 *
 * @since	 2.0
 *
 * The %ImageUtil class provides methods for %Image pixel format conversion and %Image scaling, such as resizing, rotating, and flipping.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/viewing_processing_still_images.htm">Viewing and Processing Still Images</a>.
 *
 * The following example demonstrates how to use the %ImageUtil class.
 *
 * @code

#include <FBase.h>
#include <FIo.h>
#include <FApp.h>
#include <FGraphics.h>
#include <FMedia.h>

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Media;

result
ImageUtilSample(void)
{
	ByteBuffer yuvBuf, rgbBuf;
	Bitmap bitmap;
	Image image;
	int width = 320, height = 240;
	int yuvBufSize = width * height * 3 / 2;
	int rgbBufSize = width * height * 4;
	byte *pBuf = null;
	Dimension dim(width, height);
	String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.jpg";

	pBuf = new byte[yuvBufSize];

	// Fills source buffer with a 2x2 checkboard
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			pBuf[j * width + i] = (((i >= width / 2) + (j >= height / 2)) & 1) ? 255 : 0; // Y
		}
	}
	memset(pBuf + width * height, 128, width * height / 4);	  // Cb
	memset(pBuf + width * height * 5 / 4, 128, width * height / 4);  // Cr

	// Creates yuv and rgb buffers
	yuvBuf.Construct(pBuf, 0, yuvBufSize, yuvBufSize);
	yuvBuf.SetPosition(0);
	yuvBuf.SetLimit(yuvBufSize);

	rgbBuf.Construct(rgbBufSize);
	rgbBuf.SetPosition(0);
	rgbBuf.SetLimit(rgbBufSize);

	image.Construct();

	// Converts pixel format
	ImageUtil::ConvertPixelFormat(yuvBuf, rgbBuf, MEDIA_PIXEL_FORMAT_YUV420P, MEDIA_PIXEL_FORMAT_BGRA8888, dim);

	// Makes a Bitmap with converted rgb data
	bitmap.Construct(rgbBuf, dim, BITMAP_PIXEL_FORMAT_ARGB8888, BUFFER_SCALING_NONE);
	image.EncodeToFile(bitmap, IMG_FORMAT_JPG, filePath, true);

	delete pBuf;
	return E_SUCCESS;
}

 * @endcode
 *
 */

class _OSP_EXPORT_ ImageUtil
{

public:
	/**
	*   Converts the pixel format of the image.
	*
	*   @since	   2.0
	*
	*   @return	 An error code
	*   @param[in]	srcBuf					   The source buffer
	*   @param[out]	destBuf					  The destination buffer
	*   @param[in]	srcPixelFormat			   The source pixel format
	*   @param[in]	destPixelFormat			  The destination pixel format
	*   @param[in]	dim						  The width and height of the source and destination images @n
	*											 The value of the width and height must be greater than or equal to @c 1.
	*   @exception   E_SUCCESS					The method is successful.
	*   @exception   E_UNSUPPORTED_FORMAT		 The specified format is not supported.
	*   @exception   E_INVALID_ARG				The specified width and height are invalid, or the size of @c srcBuf or @c destBuf is insufficient.
	*   @exception   E_INVALID_DATA			   A source image data in the buffer is invalid.
	*   @exception   E_OUT_OF_MEMORY			  The memory is insufficient.
	*   @exception   E_SYSTEM					 A system error has occurred.
	*   @remarks
	*			  - The supported pixel formats are @c MEDIA_PIXEL_FORMAT_RGB565LE, @c MEDIA_PIXEL_FORMAT_BGRA8888, and @c MEDIA_PIXEL_FORMAT_YUV420P. @n
	*			    The conversion is possible between: @n
	*				   - @c MEDIA_PIXEL_FORMAT_YUV420P and @c MEDIA_PIXEL_FORMAT_RGB565LE. @n
	*				   - @c MEDIA_PIXEL_FORMAT_YUV420P and @c MEDIA_PIXEL_FORMAT_BGRA8888. @n
	*			  - The position and limit of @c destBuf are set along with the size of the converted data.
	*/
	static result ConvertPixelFormat(const Tizen::Base::ByteBuffer& srcBuf, Tizen::Base::ByteBuffer& destBuf, MediaPixelFormat srcPixelFormat, MediaPixelFormat destPixelFormat, const Tizen::Graphics::Dimension& dim);

	/**
	*   Resizes the image.
	*
	*   @since	   2.0
	*
	*   @return	 An error code
	*   @param[in]   srcBuf						The source buffer
	*   @param[out]  destBuf						The destination buffer
	*   @param[in]   srcDim						The width and height of the source image @n
	*											The value of the width and height must be greater than or equal to @c 1.
	*   @param[in]   destDim						The width and height of the destination image @n
	*											The value of the width and height must be greater than or equal to @c 1.
	*   @param[in]   pixelFormat					The source and destination pixel format
	*   @exception   E_SUCCESS				   The method is successful.
	*   @exception   E_UNSUPPORTED_FORMAT		The specified format is not supported.
	*   @exception   E_INVALID_ARG			   The specified width and height are invalid, or the size of @c srcBuf or @c destBuf is insufficient.
	*   @exception   E_INVALID_DATA			  A source image data in the buffer is invalid.
	*   @exception   E_OUT_OF_MEMORY			 The memory is insufficient.
	*   @exception   E_SYSTEM					A system error has occurred.
	*   @remarks
	*			  - The supported pixel formats are @c MEDIA_PIXEL_FORMAT_RGB565LE, @c MEDIA_PIXEL_FORMAT_BGRA8888, and @c MEDIA_PIXEL_FORMAT_YUV420P.
	*			  - The position and limit of @c destBuf are set along with the size of the resized data. @n
	*			    The minimum resolution is 16x16.
	*/
	static result Resize(const Tizen::Base::ByteBuffer& srcBuf, Tizen::Base::ByteBuffer& destBuf, const Tizen::Graphics::Dimension& srcDim, const Tizen::Graphics::Dimension& destDim, MediaPixelFormat pixelFormat);

	/**
	*   Rotates the image.
	*
	*   @since	   2.0
	*
	*   @return	 An error code
	*   @param[in]   srcBuf						The source buffer
	*   @param[out]  destBuf						The destination buffer
	*   @param[in]   dim							The width and height of the source image @n
	*											The value of the width and height must be equal to or greater than @c 1.
	*   @param[in]   rotate						The rotation type
	*   @param[in]   pixelFormat					The source and destination pixel formats
	*   @exception   E_SUCCESS					The method is successful.
	*   @exception  E_UNSUPPORTED_FORMAT			The specified format is not supported.
	*   @exception   E_INVALID_ARG				The specified width and height are invalid, or the size of @c srcBuf or @c destBuf is insufficient.
	*   @exception   E_INVALID_DATA				A source image data in the buffer is invalid.
	*   @exception   E_OUT_OF_MEMORY				The memory is insufficient.
	*   @exception   E_SYSTEM					A system error has occurred.
	*   @remarks
	*			  - The supported pixel formats are @c MEDIA_PIXEL_FORMAT_RGB565LE, @c MEDIA_PIXEL_FORMAT_BGRA8888, and @c MEDIA_PIXEL_FORMAT_YUV420P.
	*			  - The position and limit of @c destBuf are set along with the size of the rotated data. @n
	*			    The dimension of the destination buffer must be calculated by an application.
	*   @see			ImageRotationType
	*/
	static result Rotate(const Tizen::Base::ByteBuffer& srcBuf, Tizen::Base::ByteBuffer& destBuf, const Tizen::Graphics::Dimension& dim, ImageRotationType rotate, MediaPixelFormat pixelFormat);

	/**
	*   Flips the image.
	*
	*   @since	   2.0
	*
	*   @return	 An error code
	*   @param[in]   srcBuf						The source buffer
	*   @param[out]  destBuf						The destination buffer
	*   @param[in]   dim							The width and height of the source and destination images @n
	*											The value of the width and height must be equal to or greater than @c 1.
	*   @param[in]   flip						The flip type
	*   @param[in]   pixelFormat					The source and destination pixel formats
	*   @exception   E_SUCCESS					The method is successful.
	*   @exception   E_UNSUPPORTED_FORMAT		The specified format is not supported.
	*   @exception   E_INVALID_ARG				The specified width and height are invalid, or the size of @c srcBuf or @c destBuf is insufficient.
	*   @exception   E_INVALID_DATA				A source image data in the buffer is invalid.
	*   @exception   E_OUT_OF_MEMORY				The memory is insufficient.
	*   @exception   E_SYSTEM					A system error has occurred.
	*   @remarks
	*			  - The supported pixel formats are @c MEDIA_PIXEL_FORMAT_RGB565LE, @c MEDIA_PIXEL_FORMAT_BGRA8888, and @c MEDIA_PIXEL_FORMAT_YUV420P.
	*			  - The position and limit of @c destBuf are set along with the size of the flipped data.
	*   @see			ImageFlipType
	*/
	static result Flip(const Tizen::Base::ByteBuffer& srcBuf, Tizen::Base::ByteBuffer& destBuf, const Tizen::Graphics::Dimension& dim, ImageFlipType flip, MediaPixelFormat pixelFormat);

private:

	/**
	* This default constructor is intentionally declared as private because
	* this class cannot be constructed.
	*/
	ImageUtil(void);

	/**
	* This destructor is intentionally declared as private because this class
	* cannot be constructed.
	*/
	virtual ~ImageUtil(void);

	/**
	* The implementation of this copy constructor is intentionally blank
	* and declared as private to prohibit copying of objects.
	*/
	ImageUtil(const ImageUtil& image);

	/**
	* The implementation of this copy assignment operator is intentionally blank
	* and declared as private to prohibit copying of objects.
	*/
	ImageUtil& operator =(const ImageUtil& image);

}; // class ImageUtil

}} // Tizen::Media

#endif // _FMEDIA_IMAGEUTIL_H_

