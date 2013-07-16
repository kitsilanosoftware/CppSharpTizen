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
 * @file	FGrpBufferInfo.h
 * @brief	This is the header file for the %BufferInfo class.
 *
 * This header file contains the declarations of the %BufferInfo class.
 *
 */

#ifndef _FGRP_BUFFER_INFO_H_
#define _FGRP_BUFFER_INFO_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>

#include <FGrpRectangle.h>
#include <FGrpPixelFormat.h>
#include <FGrpBitmapCommon.h>

namespace Tizen { namespace Graphics
{
/**
 * @class	BufferInfo
 * @brief	This class encapsulates the extra information for canvases and bitmaps.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %BufferInfo class provides Canvas and Bitmap related information, such as the dimension and pixel information.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/graphics/bufferinfo.htm">Buffer Information</a>.
 *
 *
 */
class _OSP_EXPORT_ BufferInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	BufferInfo(void);

	/**
	 * This is the copy constructor for the %BufferInfo class.
	 *
	 * @since 2.0
	 *
	 * @param[in]          rhs         An instance of %BufferInfo
	 */
	BufferInfo(const BufferInfo& rhs);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~BufferInfo(void);

	/**
	 * This is the default assignment operator for this class.
	 *
	 * @since 2.0
	 *
	 * @param[in]          rhs         An instance of %BufferInfo
	 */
	BufferInfo& operator =(const BufferInfo& rhs);

	/**
	 *	Checks whether the value of the specified instance equals the value of the current instance.
	 *
	 * @since 2.0
	 *
	 *	@return			@c true if the value of the current instance equals the value of the specified instance, @n
	 *           else @c false
	 *	@param[in]	rhs	The object to compare with the current instance
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 *	Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 *	@return		An integer value indicating the hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

public:
	/**
	 * The width of the buffer's logical dimensions in pixels.
	 *
	 * @since	2.0
	 */
	int width;

	/**
	 * The height of the buffer's logical dimensions in pixels.
	 *
	 * @since	2.0
	 */
	int height;

	/**
	 * The length of the buffer scan-line in bytes.
	 *
	 * @since	2.0
	 */
	int pitch;

	/**
	 * The bits per pixel of the buffer.
	 *
	 * @since	2.0
	 */
	int bitsPerPixel;

	/**
	 * The color format of the buffer.
	 *
	 * @since	2.0
	 */
	PixelFormat pixelFormat;

	/**
	 * A pointer to the actual locked pixel bits.
	 *
	 * @since	2.0
	 */
	void* pPixels;

private:
	friend class _BufferInfoImpl;

	//
	// This variable is for internal use only.
	// Using this variable can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	//
	class _BufferInfoImpl * __pImpl;

}; // BufferInfo

}} // Tizen::Graphics

#endif //_FGRP_BUFFER_INFO_H_
