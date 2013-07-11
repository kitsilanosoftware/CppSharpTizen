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
 * @since 2.0
 *
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
	 * @return	Return true when this function successfully initialize the GL status and allocate resources, such as shader and textures. Otherwise, when this function meets some errors or exceptions, then return false.
	 *
	 */
	virtual bool InitializeGl(void) = 0;

	/**
	 * Terminate the Renderer to unload shader and release allocated resources.
	 *
	 * @since 2.0
	 * @return	Return true when this function successfully terminate the GL status and release all the resources, such as shader and textures. Otherwise, when this function meets some errors or exceptions, then return false.
	 *
	 */
	virtual bool TerminateGl(void) = 0;

	/**
	 * This function is called when GlPlayer draws a scene.
	 * Users overload this function and calls necessary operations for drawing a scene in this system.
	 *
	 * @since 2.0
	 * @return	Return true when this function successfully draws a scene with gl functions. Otherwise, when this function meets some errors or exceptions, then return false.
	 *
	 */
	virtual bool Draw(void) = 0;

	/**
	 * This function is called when GlPlayer is paused.
	 * Users overload this function and calls necessary operations for the pause of the system, including release resources.
	 *
	 * @since 2.0
	 * @return	Return true when this function successfully does intended operations for Pause state. Otherwise, when this function meets some errors or exceptions, then return false.
	 *
	 */
	virtual bool Pause(void) = 0;

        /**
         * This function is called when GlPlayer is resumed.
	 * Users overload this function and calls necessary operations for the resume of the system, including allocation resources.
         *
         * @since 2.0
	 * @return	Return true when this function successfully does intended operations for Resume state. Otherwise, when this function meets some errors or exceptions, then return false.
         *
         */
	virtual bool Resume(void) = 0;

	/**
	 * Get the target control width.
	 *
	 * @since 2.0
	 *
	 * @return	Return the width of Target control.
	 * @remarks The control width is determined when you register %IGlRenderer to %GlPlayer with GlPlayer::SetIGlRenderer() function. Therefore, developers have to declare a integer variable for control width to implement this function.
	 *
	 */
	virtual int GetTargetControlWidth(void) = 0;

	/**
	 * Get the target control height.
	 *
	 * @since 2.0
	 *
	 * @return	Return the height of Target control.
	 * @remarks The control height is determined when you register %IGlRenderer to %GlPlayer with GlPlayer::SetIGlRenderer() function. Therefore, developers have to declare a integer variable for control height to implement this function.
	 *
	 */
	virtual int GetTargetControlHeight(void) = 0;

	/**
	 * Set the target control width.
	 *
	 * @since 2.0
	 *
	 * @param[in]	width	Width of Target control.
	 * @remarks The control width is determined when you register %IGlRenderer to %GlPlayer with GlPlayer::SetIGlRenderer() function. Therefore, this function is used in GlPlayer::SetIGlRenderer function, and developers have to declare a integer variable for control width to implement this function.
	 *
	 */
	virtual void SetTargetControlWidth(int width) = 0;

	/**
	 * Get the target control height.
	 *
	 * @since 2.0
	 *
	 * @param[in]	height	Height of Target control.
	 * @remarks The control height is determined when you register %IGlRenderer to %GlPlayer with GlPlayer::SetIGlRenderer() function. Therefore, this function is used in GlPlayer::SetIGlRenderer function, and developers have to declare a integer variable for control height to implement this function.
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
