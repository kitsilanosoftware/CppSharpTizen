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
// WITHOUT  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FGrpIGlRenderer.h
 * @brief	This is the header file for the %IGlRenderer class.
 *
 * This header file contains the declarations of the %IGlRenderer class.
 *
 */

#ifndef _FGRP_GL_RENDERER_H_
#define _FGRP_GL_RENDERER_H_

#include <FOspConfig.h>

namespace Tizen { namespace Graphics { namespace Opengl
{

/**
 * @class	IGlRenderer
 * @brief	This virtual class defines the interface for GlPlayer to draw 3D scene.
 *
 * @since 2.0
 *
 * The %IGlRenderer virtual class defines the interface for GlPlayer to draw 3D scene.
 */
class _OSP_EXPORT_ IGlRenderer
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this.
	 *
	 * @since 2.0
	 *
	 */
	virtual ~IGlRenderer(void) {}

	/**
	 * Initializes GL status and allocates necessary resources for the current Renderer such as shader, texture and so on.
	 *
	 * @since 2.0
	 * @return	@c true if this method successfully initializes the GL status and allocate resources, such as shader and textures, @n
	 else @c false if this method meets some errors or exceptions
	 *
	 */
	virtual bool InitializeGl(void) = 0;

	/**
	 * Terminates the Renderer to unload shader and release allocated resources.
	 *
	 * @since 2.0
	 * @return	@c true if this method successfully terminates the GL status and releases all the resources, such as shader and textures, @n
	 else @c false if this method meets some errors or exceptions
	 *
	 */
	virtual bool TerminateGl(void) = 0;

	/**
	 * Draws a scene. @n
	 * Users overload the %Draw() method and calls necessary operations for drawing a scene in this system.
	 *
	 * @since 2.0
	 * @return	@c true if this method successfully draws a scene with gl functions, @n
	 else @c false if this method meets some errors or exceptions
	 *
	 */
	virtual bool Draw(void) = 0;

	/**
	 * Pauses the GlPlayer instance. @n
	 * Users overload the %Pause() method and calls necessary operations for the pause of the system, including release of resources.
	 *
	 * @since 2.0
	 * @return	@c true if this method successfully does intended operations for pause state, @n else @c false if this method meets some errors or exceptions
	 *
	 */
	virtual bool Pause(void) = 0;

    /**
     * Resumes the GlPlayer instance. @n
	 * Users overload the %Resume method and calls necessary operations for the resume of the system, including allocation of resources.
     *
     * @since 2.0
	 * @return	@c true if this method successfully does intended operations for resume state, @n else @c false if this method meets some errors or exceptions
     *
     */
	virtual bool Resume(void) = 0;

	/**
	 * Gets the target control width.
	 *
	 * @since 2.0
	 *
	 * @return	The width of target control
	 * @remarks The control width is determined when you register %IGlRenderer to %GlPlayer with the GlPlayer::SetIGlRenderer() method. Therefore, developers have to declare an integer variable for control width to implement this method.
	 *
	 */
	virtual int GetTargetControlWidth(void) = 0;

	/**
	 * Gets the target control height.
	 *
	 * @since 2.0
	 *
	 * @return	The height of target control
	 * @remarks The control height is determined when you register %IGlRenderer to %GlPlayer with the GlPlayer::SetIGlRenderer() method. Therefore, developers have to declare an integer variable for control height to implement this method.
	 *
	 */
	virtual int GetTargetControlHeight(void) = 0;

	/**
	 * Sets the target control width.
	 *
	 * @since 2.0
	 *
	 * @param[in]	width	The width of target control
	 * @remarks The control width is determined when you register %IGlRenderer to %GlPlayer with the GlPlayer::SetIGlRenderer() method. Therefore, developers have to declare an integer variable for control width to implement this method.
	 *
	 */
	virtual void SetTargetControlWidth(int width) = 0;

	/**
	 * Gets the target control height.
	 *
	 * @since 2.0
	 *
	 * @param[in]	height	The height of target control
	 * @remarks The control height is determined when you register %IGlRenderer to %GlPlayer with the GlPlayer::SetIGlRenderer() method. Therefore, developers have to declare an integer variable for control height to implement this method.
	 *
	 */
	virtual void SetTargetControlHeight(int height) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	//
	virtual void IGlRenderer_Reserved1(void) {}
	virtual void IGlRenderer_Reserved2(void) {}
	virtual void IGlRenderer_Reserved3(void) {}

}; // IGlRenderer

}}} // Tizen::Graphics::Opengl

#endif //_FGRP_GL_RENDERER_H_
