//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FGrpBitmap.h
 * @brief	This is the header file for the %Bitmap class.
 *
 * This header file contains the declarations of the %Bitmap class. @n
 * The class encapsulates a bitmap, which consists of the pixel data
 * for a graphics image and its attributes.
 *
 */

#ifndef _FGRP_BITMAP_H_
#define _FGRP_BITMAP_H_

#include <FBase.h>

#include <FBaseObject.h>
#include <FBaseByteBuffer.h>
#include <FGrpPoint.h>
#include <FGrpFloatPoint.h>
#include <FGrpDimension.h>
#include <FGrpFloatDimension.h>
#include <FGrpRectangle.h>
#include <FGrpFloatRectangle.h>
#include <FGrpColor.h>
#include <FGrpBufferInfo.h>
#include <FGrpBitmapCommon.h>

namespace Tizen { namespace Media
{
class Image;
} }

namespace Tizen { namespace Graphics
{
class Canvas;

/**
 * @class	Bitmap
 * @brief	This class encapsulates a bitmap.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Bitmap class encapsulates a bitmap, which consists of the pixel data
 * for an image and its attributes.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/graphics/bitmap.htm">Bitmaps</a>.
 *
 *
 */
class _OSP_EXPORT_ Bitmap
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since			2.0
	 * @remarks		After creating an instance of this class, one of the
	 *              Construct() methods must be called explicitly to initialize this instance.
	 *
	 */
	Bitmap(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~Bitmap(void);

	/**
	 * Initializes this instance of %Bitmap by copying a rectangular area of the Frame.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	rect		The rectangular area of the Frame to copy into bitmap @n
	 *							The width and height of the rectangle must be greater than @c 0. @n
	 *							The area defined by @c rect is clipped to the edges of the Frame so that
	 *							the rectangle does not fall outside the edges of the Frame. @n
	 *							The rectangle must not fall outside the edges of the Frame entirely. @n
	 *							If these conditions are not satisfied, an @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */
	result Construct(const Rectangle& rect);

	/**
	 * Initializes this instance of %Bitmap with the specified dimensions and pixel format.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	dim			The dimensions of the bitmap @n
	 *							The width and height must be greater than @c 0.
	 * @param[in]	format		The pixel format
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */
	result Construct(const Dimension& dim, BitmapPixelFormat format);

	/**
	 * Initializes this instance of %Bitmap by copying the specified rectangular area of the specified canvas.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	canvas		The canvas to copy @n
	 *							The canvas must be constructed successfully before it is passed into this method. @n
	 *							If not, an @c E_INVALID_ARG exception is returned.
	 * @param[in]	rect		The rectangular area of the canvas to copy into a bitmap @n
	 *							The width and height of the rectangle must be greater than @c 0. @n
	 *							The rectangle defined by @c rect is clipped to the edges of the canvas so that
	 *							the rectangle does not fall outside the edges of the canvas. @n
	 *							The rectangle must not fall outside the edges of the canvas entirely. @n
	 *							If these conditions are not satisfied, an @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */
	result Construct(const Canvas& canvas, const Tizen::Graphics::Rectangle& rect);

	/**
	 * Initializes this instance of %Bitmap by copying a rectangular area of the specified bitmap.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	bitmap		The source bitmap @n
	 *							The bitmap must be constructed successfully before it is passed into this method. @n
	 *							If not, an @c E_INVALID_ARG exception is returned.
	 * @param[in]	rect		The rectangular area of the source bitmap to copy into this bitmap @n
	 *							The width and height of the rectangle must be greater than @c 0. @n
	 *							The rectangle defined by @c rect is clipped to the edges of the source bitmap so that
	 *							the rectangle does not fall outside the edges of the source bitmap. @n
	 *							The rectangle must not fall outside the edges of the source bitmap entirely. @n
	 *							If these conditions are not satisfied, an @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */
	result Construct(const Bitmap& bitmap, const Tizen::Graphics::Rectangle& rect);

	/**
	 * Initializes this instance of %Bitmap by using a buffer that contains raw data.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]		buffer		The buffer containing raw data
	 * @param[in]	dim			The dimensions of the bitmap @n
	 *							The width and height must be greater than @c 0.
	 * @param[in]	pixelFormat	The pixel format of raw data
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @remarks The position property of ByteBuffer can be changed.
	 *
	 */
	result Construct(const Tizen::Base::ByteBuffer& buffer, const Dimension& dim, BitmapPixelFormat pixelFormat);

	/**
	 * Initializes this instance of %Bitmap by using a buffer that contains raw data.
	 *
	 * @since	2.0
	 *
	 * @return     An error code
	 * @param[in]  buffer          The buffer containing raw data
	 * @param[in]  dim             The dimensions of the bitmap @n
	 *                             The width and height must be greater than @c 0.
	 * @param[in]  pixelFormat     The pixel format of raw data
	 * @param[in]  bufferScaling   The buffer scaling type
	 * @exception  E_SUCCESS       The method is successful.
	 * @exception  E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception  E_UNSUPPORTED_FORMAT The specified format is not supported.
	 * @remarks The position property of %ByteBuffer can be changed.
	 *
	 */
	result Construct(const Tizen::Base::ByteBuffer& buffer, const Dimension& dim, BitmapPixelFormat pixelFormat, BufferScaling bufferScaling);

	/**
	 * Initializes this instance of %Bitmap by copying a rectangular area of the Frame.
	 *
	 * @since			2.1
	 *
	 * @return	An error code
	 * @param[in]	rect		The rectangular area of the frame that is copied into bitmap @n
	 *							The width and height of the rectangle must be greater than @c 0. @n
	 *							The area defined by @c rect is clipped to the edges of the frame so that
	 *							the rectangle does not fall outside the edges of the frame. @n
	 *							The rectangle must not fall outside the edges of the frame entirely. @n
	 *							If these conditions are not satisfied, an @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */
	result Construct(const FloatRectangle& rect);

	/**
	 * Initializes this instance of %Bitmap with the specified dimensions and pixel format.
	 *
	 * @since			2.1
	 *
	 * @return		An error code
	 * @param[in]	dim			The dimensions of the bitmap @n
	 *							The width and height must be greater than @c 0.
	 * @param[in]	format		The pixel format
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */
	result Construct(const FloatDimension& dim, BitmapPixelFormat format);

	/**
	 * Initializes this instance of %Bitmap by copying a specified rectangular area of a specified canvas.
	 *
	 * @since			2.1
	 *
	 * @return		An error code
	 * @param[in]	canvas		The canvas to copy @n
	 *							The canvas must be constructed successfully before it is passed into this method. @n
	 *							If not, an @c E_INVALID_ARG exception is returned.
	 * @param[in]	rect		The rectangular area of the canvas that is copied into a bitmap @n
	 *							The width and height of the rectangle must be greater than @c 0. @n
	 *							The rectangle defined by @c rect is clipped to the edges of the canvas so that
	 *							the rectangle does not fall outside the edges of the canvas. @n
	 *							The rectangle must not fall outside the edges of the canvas entirely. @n
	 *							If these conditions are not satisfied, an @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */
	result Construct(const Canvas& canvas, const FloatRectangle& rect);

	/**
	 * Initializes this instance of %Bitmap by copying a rectangular area of a specified bitmap.
	 *
	 * @since			2.1
	 *
	 * @return		An error code
	 * @param[in]	bitmap		The source bitmap @n
	 *							The bitmap must be constructed successfully before it is passed into this method. @n
	 *							If not, an @c E_INVALID_ARG exception is returned.
	 * @param[in]	rect		The rectangular area of the source bitmap that is copied into this bitmap @n
	 *							The width and height of the rectangle must be greater than @c 0. @n
	 *							The rectangle defined by @c rect is clipped to the edges of the source bitmap so that
	 *							the rectangle does not fall outside the edges of the source bitmap. @n
	 *							The rectangle must not fall outside the edges of the source bitmap entirely. @n
	 *							If these conditions are not satisfied, an @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */
	result Construct(const Bitmap& bitmap, const FloatRectangle& rect);

public:
	/**
	 * Scales the bitmap to the specified width and height.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	dim	    The dimensions of the specified rectangular area @n
	 *						The width and height must be greater than @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 *
	 */
	result Scale(const Dimension& dim);

	/**
	 * Scales the bitmap to a specified width and height.
	 *
	 * @since			2.1
	 *
	 * @return		An error code
	 * @param[in]	dim	    The dimensions of the specified rectangular area @n
	 *						The width and height must be greater than @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 *
	 */
	result Scale(const FloatDimension& dim);

	/**
	 * Merges the specified area of the source bitmap into the calling bitmap at the given Point.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	destPoint		The X and Y coordinate of the top-left corner of the destination area in the calling bitmap instance
	 * @param[in]	srcBitmap		The source bitmap instance to copy from
	 * @param[in]	srcRect		    The rectangular area to copy from the source bitmap @n
	                                The width and height of the rectangle must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		Either of the following conditions has occurred: @n
	 *									- The value of the argument is outside the valid range defined by the method. @n
	 *									- The destX, destY, srcX, or srcY has a negative value. @n
	 *									- The specified @c srcWidth or @c srcHeight is less than @c 0.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */
	result Merge(const Point& destPoint, const Bitmap& srcBitmap, const Rectangle& srcRect);

	/**
	 * Merges a specified area of the source bitmap into the calling bitmap at a given point.
	 *
	 * @since			2.1
	 *
	 * @return		An error code
	 * @param[in]	destPoint		The X and Y coordinate of the top-left corner of the destination area in the calling bitmap instance
	 * @param[in]	srcBitmap		The source bitmap instance to copy from
	 * @param[in]	srcRect		    The rectangular area to copy from the source bitmap @n
	 *                               The width and height of the rectangle must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		Either of the following conditions has occurred: @n
	 *									- The value of the argument is outside the valid range defined by the method. @n
	 *									- The destX, destY, srcX, or srcY has a negative value. @n
	 *									- The specified @c srcWidth or @c srcHeight is less than @c 0.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 *
	 */
	result Merge(const FloatPoint& destPoint, const Bitmap& srcBitmap, const FloatRectangle& srcRect);

	/**
	 * Gets the height of the bitmap.
	 *
	 * @since		2.0
	 *
	 * @return	The height of the bitmap, @n
	 *			else @c -1 if the method fails
	 *
	 */
	int GetHeight(void) const;

	/**
	 * Gets the height of the bitmap.
	 *
	 * @since		2.1
	 *
	 * @return	The height of the bitmap, @n
	 *			else @c -1 if the method fails
	 *
	 */
	float GetHeightF(void) const;

	/**
	 * Gets the actual height of the bitmap.
	 *
	 * @since		2.1
	 *
	 * @return	The actual height of the bitmap, @n
	 *			else @c -1.0f if the method fails
	 *
	 */
	float GetActualHeight(void) const;

	/**
	 * Gets the width of the bitmap.
	 *
	 * @since		2.0
	 *
	 * @return	The width of the bitmap, @n
	 *			else @c -1 if the method fails
	 *
	 */
	int GetWidth(void) const;

	/**
	 * Gets the width of the bitmap.
	 *
	 * @since		2.1
	 *
	 * @return	The width of the bitmap, @n
	 *			else @c -1 if the method fails
	 *
	 */
	float GetWidthF(void) const;

	/**
	 * Gets the actual width of the bitmap.
	 *
	 * @since		2.1
	 *
	 * @return	The actual width of the bitmap, @n
	 *			else @c -1.0f if the method fails
	 *
	 */
	float GetActualWidth(void) const;

	/**
	 * Gets the number of bits per pixel of the bitmap.
	 *
	 * @since		2.0
	 *
	 * @return	The bits per pixel, @n
	 *			else @c -1 if the method fails
	 *
	 */
	int GetBitsPerPixel(void) const;

	/**
	 * Gets the pixel color format of the bitmap.
	 *
	 * @since		2.0
	 *
	 * @return	The pixel color format
	 *
	 */
	BitmapPixelFormat GetPixelColorFormat(void) const;

	/**
	 * Sets the scaling quality to be used for bitmap scaling.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	quality	The scaling quality to use for bitmap scaling.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 *
	 */
	result SetScalingQuality(BitmapScalingQuality quality);

	/**
	 * Gets the current scaling quality.
	 *
	 * @since 2.0
	 *
	 * @return	The scaling quality
	 * @remarks The default value is @c BITMAP_SCALING_QUALITY_LOW.
	 *
	 */
	BitmapScalingQuality GetScalingQuality(void) const;

	/**
	 * Sets the specified color as masking color. @n
	 * All pixels with this color are treated as transparent.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	pColor	The color that is treated as transparent @n
	 *						If the parameter is set to @c null, the masking color is removed from this bitmap. @n
	 *						Only ::BITMAP_PIXEL_FORMAT_RGB565 is supported.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 *
	 */
	result SetMaskingColor(const Color* pColor);

	/**
	 * Gets a masking color.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[out]	color	The color that is treated as transparent
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_DATA	The masking color is not defined.
	 *
	 */
	result GetMaskingColor(Color& color) const;

	/**
	 * Sets the alpha constant.
	 *
	 * @since			2.0
	 * @param[in]	opacity		The opacity of the bitmap @n
	 *				            This value ranges from @c 0 to @c 255.
	 * @remarks The alpha constant is used for the Canvas::DrawBitmap() method.
	 */
	void SetAlphaConstant(int opacity);

	/**
	 * Gets the alpha constant.
	 *
	 * @since		2.0
	 *
	 * @return	The alpha constant, @n
	 *			else @c -1 if the method fails
	 */
	int GetAlphaConstant(void) const;

	/**
	 * Checks whether the instance is nine patched bitmap.
	 *
	 * @since			2.0
	 *
	 * @return    @c true if the instance is nine patched bitmap, @n
	 *	          else @c false
	 */
	bool IsNinePatchedBitmap(void) const;

	/**
	 * Locks a bitmap for direct pixel access. @n
	 * It sets up a bitmap for accessing the pixels directly. Between the calls to Bitmap::Lock and Bitmap::Unlock,
	 * you can write to and read from the bitmap's pixels. After you are done accessing the bitmap's pixels,
	 * you must call Bitmap::Unlock to release the lock.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[out]	info		The extra information of the bitmap
	 * @param[in]	timeout		The time in milliseconds @n
	 *                          This value determines the time the caller waits for the lock to be obtained. @n
	 *							If the lock attempt fails, @c E_TIMEOUT is returned. @n
	 *							The default value is @c INFINITE, which means that the method does not return a value until the lock is acquired.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_TIMEOUT		The operation is not completed within the specified time period.
	 * @exception	E_SYSTEM		An unknown operating system error has occurred.
	 *
	 */
	result Lock(BufferInfo& info, long timeout = INFINITE);

	/**
	 * Unlocks a bitmap. @n
	 * A bitmap that is locked using Bitmap::Lock() must be unlocked using Bitmap::Unlock().
	 * The bitmap buffer can be modified when the bitmap is locked, but is applied only when the bitmap is unlocked.
	 * Therefore, all locked bitmap operations can only be used after the bitmap is unlocked using %Bitmap::Unlock().
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		An unknown operating system error has occurred.
	 *
	 */
	result Unlock(void);

	/**
	 * Gets a non scaled bitmap.
	 *
	 * @since	2.0
	 *
	 * @return	The non scaled bitmap, @n
	 *          else @c null if an exception occurs
	 * @param[in]	buffer		The buffer containing raw data
	 * @param[in]	dim			The dimensions of the bitmap @n
	 *							The width and height must be greater than @c 0.
	 * @param[in]	pixelFormat	The pixel format of raw data
	 * @exception	E_SUCCESS            The method is successful.
	 * @exception	E_INVALID_ARG        The specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_FORMAT The specified format is not supported.
	 *
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	static Bitmap* GetNonScaledBitmapN(const Tizen::Base::ByteBuffer& buffer, const Dimension& dim, BitmapPixelFormat pixelFormat);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Bitmap(const Bitmap& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Bitmap& operator =(const Bitmap& rhs);

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Initializes this instance of %Bitmap by using a buffer that contains raw data.
	//
	// @since	2.0
	//
	// @return     An error code
	// @param[in]  buffer          The buffer containing raw bitmap data
	// @param[in]  dim             The dimensions of the bitmap @n
	//                             The width and height must be greater than @c 0.
	// @param[in]  pixelFormat     The pixel format of the raw bitmap buffer
	// @param[in]  autoScaling     Set to @c true to automatically scale the bitmap, @n
	//									else @c false
	// @exception  E_SUCCESS       The method is successful.
	// @exception  E_INVALID_ARG   A specified input parameter is invalid.
	// @exception  E_UNSUPPORTED_FORMAT The specified format is not supported.
	//
	result Construct(const Tizen::Base::ByteBuffer& buffer, const Dimension& dim, BitmapPixelFormat pixelFormat, bool autoScaling);

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Initializes this instance of %Bitmap by using a buffer that contains raw data.
	//
	// @since	2.0
	//
	// @return     An error code
	// @param[in]  pBuffer         A pointer to the raw bitmap buffer
	// @param[in]  bufferSize      The size of the raw bitmap buffer
	// @param[in]  dim             The dimensions of the bitmap @n
	//                             The width and height must be greater than @c 0.
	// @param[in]  pixelFormat     The pixel format of the raw bitmap buffer
	// @param[in]  autoScaling     Set to @c true to automatically scale the bitmap, @n
	//									else @c false
	// @exception  E_SUCCESS       The method is successful.
	// @exception  E_INVALID_ARG   A specified input parameter is invalid.
	// @exception  E_UNSUPPORTED_FORMAT The specified format is not supported
	//
	result Construct(const byte* pBuffer, int bufferSize, const Dimension& dim, BitmapPixelFormat pixelFormat, bool autoScaling);

	friend class Canvas;
	friend class Tizen::Media::Image;

private:
	friend class _BitmapImpl;

	//
	// This variable is for internal use only.
	// Using this variable can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	//
	class _BitmapImpl* __pImpl;

}; // Bitmap

}} // Tizen::Graphics

#endif //_FGRP_BITMAP_H_
