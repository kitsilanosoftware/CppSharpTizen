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
 * @file	FMediaGifDecoder.h
 * @brief	This is the header file for the %GifDecoder class.
 *
 * This header file contains the declarations of the %GifDecoder class.
 */

#ifndef _FMEDIA_GIF_DECODER_H_
#define _FMEDIA_GIF_DECODER_H_

#include <FBase.h>
#include <FIo.h>
#include <FGraphics.h>

#include <FMediaTypes.h>

namespace Tizen { namespace Media
{

class _GifDecoderImpl;

/**
 * @class	GifDecoder
 * @brief	This class supports GIF image decoding.
 *
 * @since 2.0
 *
 * The %GifDecoder class provides APIs for GIF image decoding. @n
 * This class also supports animated GIF decoding.
 *
 * The following example demonstrates how to use the %GifDecoder class.
 *
 * @code
 * #include <FBase.h>
 * #include <FGraphics.h>
 * #include <FApp.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Graphics;
 * using namespace Tizen::Media;
 *
 * result
 * GifDecoderSample(void)
 * {
 *	 result r;
 *	 GifDecoder dec;
 *	 long duration;
 *	 Bitmap *pBmp = null;
 *	 String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.gif";
 *
 *	 r = dec.Construct(filePath, MEDIA_PIXEL_FORMAT_BGRA8888);
 *	 if (IsFailed(r))
 *	 {
 *		 return r;
 *	 }
 *
 *	 while ((pBmp = dec.GetNextBitmapN(duration)) != null)
 *	 {
 *		 AppLog("dimension:%dx%d duration=%d", pBmp->GetWidth(), pBmp->GetHeight(), duration);
 *
 *		 delete pBmp;
 *	 }
 *
 *	 return E_SUCCESS;
 * }
 * @endcode
 */
class _OSP_EXPORT_ GifDecoder
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 *
	 * @see	Construct()
	 */
	GifDecoder(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 *
	 * @see	Construct()
	 */
	virtual ~GifDecoder(void);

	/**
	 * Initializes this instance of %GifDecoder with the specified file path and pixel format.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
	 *					For more information, see @ref CompIoPathPage "here".
	 * @endif
	 *
	 * @return	An error code
	 * @param[in]  filePath	The file path of the source image
	 * @param[in]  pixelFormat	The output pixel format of the decoded image
	 * @exception  E_SUCCESS		 The method is successful.
	 * @exception  E_INVALID_DATA	 The input data is invalid.
	 * @exception  E_FILE_NOT_FOUND	 The specified file cannot be found or accessed.
	 * @exception  E_INVALID_ARG	 The specified pixel format is not supported.
	 * @exception  E_OUT_OF_MEMORY	 The memory is insufficient.
	 * @exception  E_SYSTEM			 A system error has occurred.
	 * @remarks	Supported pixel formats are @c MEDIA_PIXEL_FORMAT_RGB565LE, and @c MEDIA_PIXEL_FORMAT_BGRA8888.
	 */
	result Construct(const Tizen::Base::String& filePath, MediaPixelFormat pixelFormat);

	/**
	 * Initializes this instance of %GifDecoder with the specified buffer data and pixel format.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	srcBuf		The source buffer where the image data is stored
	 * @param[in]	pixelFormat	The output pixel format of the decoded image
	 * @exception	E_SUCCESS		  The method is successful.
	 * @exception	E_INVALID_DATA	  The input data is invalid.
	 * @exception	E_INVALID_ARG	  The specified pixel format is not supported.
	 * @exception	E_OUT_OF_MEMORY	  The memory is insufficient.
	 * @exception	E_SYSTEM		  A system error has occurred.
	 * @remarks	Supported pixel formats are @c MEDIA_PIXEL_FORMAT_RGB565LE, and @c MEDIA_PIXEL_FORMAT_BGRA8888.
	 */
	result Construct(const Tizen::Base::ByteBuffer& srcBuf, MediaPixelFormat pixelFormat);

	/**
	 * Gets the width of the image.
	 *
	 * @since	2.0
	 *
	 * @return	The width of the image, @n
	 *			else @c 0 if an error occurs
	 */
	int GetWidth(void) const;

	/**
	 * Gets the height of the image.
	 *
	 * @since	2.0
	 *
	 * @return	The height of the image, @n
	 *			else @c 0 if an error occurs
	 */
	int GetHeight(void) const;

	/**
	 * Decodes and gets the next frame in raw RGB format.
	 *
	 * @since	2.0
	 *
	 * @return	The next decoded frame, @n
	 *			else @c null if no frame is left or an error occurs
	 * @param[out]	duration	The duration of returned frame in milliseconds
	 * @exception	E_SUCCESS		  The method is successful.
	 * @exception   E_INVALID_DATA	  The data of the next frame is invalid.
	 * @exception	E_OUT_OF_MEMORY   The memory is insufficient.
	 * @exception	E_SYSTEM		  A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* GetNextFrameN(long& duration);

	/**
	 * Decodes and gets the next frame in bitmap format.
	 *
	 * @since	2.0
	 *
	 * @return	The next decoded frame, @n
	 *		  else @c null if no frame is left or an error occurs
	 * @param[out]	duration			The duration of returned frame in milliseconds
	 * @param[in]	bufferScaling	   The buffer scaling type of Bitmap
	 * @exception	E_SUCCESS		  The method is successful.
	 * @exception   E_INVALID_DATA	 The data of the next frame is invalid.
	 * @exception	E_OUT_OF_MEMORY	   The memory is insufficient.
	 * @exception	E_SYSTEM		   A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Bitmap* GetNextBitmapN(long& duration, Tizen::Graphics::BufferScaling bufferScaling = Tizen::Graphics::BUFFER_SCALING_AUTO);

private:
	GifDecoder(const GifDecoder& rhs);
	GifDecoder& operator =(const GifDecoder& rhs);

	friend class _GifDecoderImpl;
	class _GifDecoderImpl *__pDecImpl;
}; // class GifDecoder

}} // Tizen::Media

#endif // FMEDIA_GIFDECODER_H_
