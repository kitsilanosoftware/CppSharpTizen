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
 * @file	FGrpCanvasTexture.h
 * @brief	This is the header file for the %CanvasTexture class.
 *
 * This header file contains the declarations of the %CanvasTexture class.
 *
 */

#ifndef _FGRP_CANVAS_TEXTURE_H_
#define _FGRP_CANVAS_TEXTURE_H_

#include <FBaseObject.h>

namespace Tizen { namespace Graphics {
class Canvas;
}}

namespace Tizen { namespace Graphics { namespace Opengl
{

/**
 * @class	CanvasTexture
 * @brief	This class provides a method to bind 2D Canvas and OpenGL-ES Texture.
 *		With this feature, you can easily draw 2D primitives on OpenGL-ES Textures with consistency.
 *
 * @since 2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %CanvasTexture class provides a canvas by which you can draw 2D primitives on OpenGL-ES texture.
 *
 */
class _OSP_EXPORT_ CanvasTexture
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method be called right after calling this constructor.
	 *
	 * @since 2.0
	 *
	 */
	CanvasTexture(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~CanvasTexture(void);

	/**
	 * Initializes this instance of %CanvasTexture with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	textureId	Texture ID which points to the texture associated with the 2D canvas. The testure ID must be generated from glGenTextures().
	 * @param[in]	width	The width of the input texture. The width must be greater than @c 0, and smaller or equal than GL_MAX_TEXTURE_SIZE.
	 * @param[in]	height	The height of the input texture. The height must be greater than @c 0, and smaller or equal than GL_MAX_TEXTURE_SIZE
	 * @exception	E_SUCCESS	Construction is successfully done.
	 * @exception	E_INVALID_ARG	Input parameter is invalid.
	 * @exception	E_UNSUPPORTED_OPERATION The target device does not support full features for %CanvasTexture.
	 * @exception	E_INVALID_STATE	Getting egl information failed. It is necessary to bind egl context by using eglMakeCurrent funtion.
	 * @remarks 	There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	result Construct(int textureId, int width, int height);

	/**
	 * Returns a 2D Canvas which is associated with the Texture of %CanvasTexture.
	 *
	 * @since 2.0
	 *
	 * @return	The 2D canvas of the %CanvasTexture, @n
	 *		else @c null if an exception occurs.
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OPERATION_FAILED	Fail to construct the canvas properly, due to some reason of system.
	 */
	Tizen::Graphics::Canvas* GetCanvasN(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	rhs	The source from which this instance is copied
	//
	CanvasTexture(const CanvasTexture& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	rhs	An instance of %CanvasTexture
	//
	CanvasTexture& operator =(const CanvasTexture& rhs);

private:
	friend class _CanvasTextureImpl;

	class _CanvasTextureImpl* __pImpl;
}; // CanvasTexture

}}} // Tizen::Graphics::Opengl

#endif //_FGRP_CANVAS_TEXTURE_H_
