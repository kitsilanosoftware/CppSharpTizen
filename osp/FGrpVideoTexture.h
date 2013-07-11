//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FGrpVideoTexture.h
 * @brief	This is the header file for the %VideoTexture class.
 *
 * This header file contains the declarations of the %VideoTexture class.
 *
 */

#ifndef _FGRP_VIDEO_TEXTURE_H_
#define _FGRP_VIDEO_TEXTURE_H_

#include <FBaseObject.h>

namespace Tizen { namespace Graphics { namespace Opengl
{

class IVideoTextureUpdateListener;

/**
 * @class	VideoTexture
 * @brief	This class provides a method to bind a video frame to OpenGL-ES Texture.
 *		With this feature, you can easily draw a video frame on OpenGL-ES Textures with consistency.
 *
 * @since 2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %VideoTexture class provides a texture by which you can draw a video frame on OpenGL-ES texture.
 *
 */
class _OSP_EXPORT_ VideoTexture
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method be called right after calling this constructor.
	 *
	 * @since 2.0
	 *
	 */
	VideoTexture(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~VideoTexture(void);

	/**
	 * Initializes this instance of %VideoTexture with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	textureId	Texture ID which points to the texture associated with the video frame. The testure ID must be generated from glGenTextures().
	 * @param[in]	width	The width of the input texture. The width must be greater than @c 32, and smaller or equal than GL_MAX_TEXTURE_SIZE.
	 * @param[in]	height	The height of the input texture. The height must be greater than @c 32, and smaller or equal than GL_MAX_TEXTURE_SIZE
	 * @exception	E_SUCCESS	Construction is successfully done.
	 * @exception	E_OUT_OF_RANGE	The width or height is bigger than GL_MAX_TEXTURE_SIZE You can get max size of current device to call glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxSize).
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_OPERATION The target device does not support full features for %VideoTexture.
	 * @exception	E_INVALID_STATE	Getting egl information failed. It is necessary to bind egl context by using eglMakeCurrent funtion.
	 * @remarks 	There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	result Construct(int textureId, int width, int height);

	/**
	 * Binds the most recent frame to the texture.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	Binding is successfully done.
	 * @exception	E_INVALID_STATE	Any video frames are not ready in the texture. If IVideoTextureUpdateListener is already registered, please check whether the functions have been called.
	 */
	result BindTexture(void);

	/**
	 * Adds a listener invoked when a video frame is ready.
	 *
	 * @since 2.0
	 *
	 * @param[in]	listener	The listener invoked.
	 * @see			RemoveVideoTextureUpdateListener()
	 */
	void AddVideoTextureUpdateListener(IVideoTextureUpdateListener& listener);

	/**
	 * Removes the specified listener.
	 *
	 * @since 2.0
	 *
	 * @param[in]	listener	The listener to be removed.
	  @see			AddVideoTextureUpdateListener()
	 */
	void RemoveVideoTextureUpdateListener(IVideoTextureUpdateListener& listener);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	rhs	The source from which this instance is copied
	//
	VideoTexture(const VideoTexture& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	rhs	An instance of %VideoTexture
	//
	VideoTexture& operator =(const VideoTexture& rhs);

private:
	friend class _VideoTextureImpl;

	class _VideoTextureImpl* __pImpl;
}; // VideoTexture

}}} // Tizen::Graphics

#endif //_FGRP_VIDEO_TEXTURE_H_
