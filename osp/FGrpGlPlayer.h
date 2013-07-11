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
 * @file	FGrpGlPlayer.h
 * @brief	This is the header file for the %GlPlayer class.
 *
 * This header file contains the declarations of the %GlPlayer class.
 *
 */

#ifndef _FGRP_GL_PLAYER_H_
#define _FGRP_GL_PLAYER_H_

#include <FBaseObject.h>

#include <eglplatform.h>

namespace Tizen { namespace Ui
{
class Control;
} }

namespace Tizen { namespace Graphics { namespace Opengl
{

class IGlRenderer;

/**
 * @enum        EglContextClientVersion
 *
 * Defines the Egl Context Client version of the player.
 *
 * @since 2.0
 *
 */
enum EglContextClientVersion
{
	EGL_CONTEXT_CLIENT_VERSION_1_X,         /**< The version is 1.x */
	EGL_CONTEXT_CLIENT_VERSION_2_X          /**< The version is 2.x */
};

/**
 * @enum        EglAttributesPreset
 *
 * Defines the preset of EGL attributes and configurations.
 *
 * @since 2.0
 *
 */
enum EglAttributesPreset
{
	EGL_ATTRIBUTES_PRESET_DONT_CARE,	/**< Preset Don't care */
	EGL_ATTRIBUTES_PRESET_RGB565,		/**< Preset RGB565 */
	EGL_ATTRIBUTES_PRESET_ARGB8888		/**< Preset ARGB8888 */
};

/**
 * @class	GlPlayer
 * @brief	This class provides a simple template for rendering 3D objects with OpenGL-ES APIs
 * @since 2.0
 * @final	This class is not intended for extension.
 *
 */
class _OSP_EXPORT_ GlPlayer
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 *
	 */
	GlPlayer(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object(void).
	 *
	 * @since 2.0
	 *
	 */
	virtual ~GlPlayer(void);

	/**
	 * Initializes this instance of %GlPlayer.
	 *
	 * @since 2.0
	 * @return	An error code
	 * @param[in]   version	EGL Context Client Version.
	 * @param[in]   control	Target control
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_INVALID_OPERATION	The operation has failed, because of the duplicate call of Construct().
	 *
	 * @remarks Currently, version must be 1(OpenGL-ES 1.x) or 2(OpenGL-ES 2.x)
	 * @remarks Currently, only Tizen::Ui::Controls::Frame and Tizen::Ui::Controls::Form are allowed as the target control, therefore, when the input Target control is not Form or Frame then E_INVALID_ARG exception is occurred.
	 *
	 */
	result Construct(EglContextClientVersion version, Tizen::Ui::Control* pControl);

	/**
	 * Start the %GlPlayer, and initialzie EGL status.
	 *
	 * @since 2.0
	 * @return	An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	Player cannot be started properly due to a severe system error.
	 * @exception	E_INVALID_STATE	The state of player is not suitable for start. For example, it is not allowable to start player when its state is pause.
	 * @exception	E_OPENGL_ERROR	There occurs an EGL error during performing EGL function.
	 *
	 * @remarks	In the case that this returns E_OPENGL_ERROR exception, developers can use eglGetError() to query which EGL error is raised.
	 *
	 */
	result Start(void);

	/**
	 * Pause the %GlPlayer.
	 *
	 * @since 2.0
	 * @return	An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	Player cannot be paused properly due to a severe system error.
	 * @exception	E_INVALID_OPERATION	Fail to perform IGlRenderer::Pause function which is implemented by developers.
	 * @exception	E_INVALID_STATE	The state of player is not suitable for pause. For example, it is not allowable to pause player when it does not start after the initialization yet.
	 *
	 */
	result Pause(void);

	/**
	 * Resume the %GlPlayer.
	 *
	 * @since 2.0
	 * @return	An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	Player cannot be resumed properly due to a severe system error.
	 * @exception	E_INVALID_OPERATION	Fail to perform IGlRenderer::Resume function which is implemented by developers.
	 * @exception	E_INVALID_STATE	The state of player is not suitable for resume. For example, it is not allowable to resume player when its state is stop.
	 *
	 */
	result Resume(void);

	/**
	 * Stop the %GlPlayer, and reset the EGL status.
	 *
	 * @since 2.0
	 * @return	An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	Player cannot be stopped properly due to a severe system error.
	 * @exception	E_INVALID_OPERATION	Fail to perform IGlRenderer::Pause function which is implemented by developers.
	 *
	 * @remarks Before starting to reset the EGL status, this function calls IGlRenderer::Pause() to prevent unexpected behavior.
	 *
	 */
	result Stop(void);

	/**
	 * Redraw the scene.
	 *
	 * @since 2.0
	 * @return	An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OPENGL_ERROR	There occurs an EGL error during performing EGL function.
	 * @exception	E_INVALID_STATE	The state of player is invalid and fails to pause properly.
	 *
	 * @remarks	In the case that this returns E_OPENGL_ERROR exception, developers can use eglGetError() to query which EGL error is raised.
	 *
	 */
	result Redraw(void);

	/**
	 * Set the FPS(frames per second) of the player.
	 *
	 * @since 2.0
	 * @param[in]   fps	frames per second
	 *
	 * @remarks When you give negative integer for fps, then the %GlPlayer try to draw frames as fast as possible.
	 *
	 */
	void SetFps(int fps);

	/**
	 * Set the configuration list of EGL Attributes to initialize the EGL system.
	 *
	 * @since 2.0
	 * @return	An error code
	 * @param[in]   eglConfigList	a list of EGL attributes and their values.
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *
	 * @remarks %GlPlayer initializes the EGL status with the given EGL attributes, which means that system does not guarantees to set EGL configurations with the given attributes but prefers them.
	 * @remarks	The format of eglConfigList is the same with the attribute list as the second input parameter of eglChooseConfig function. To know about the detailed description, refer the reference page of eglChooseConfig: http://www.khronos.org/opengles/documentation/opengles1_0/html/eglChooseConfig.html
	 *
	 */
	result SetEglAttributeList(const EGLint* pEglConfigList);

	/**
	 * Set EGL configuration with the given preset.
	 *
	 * @since 2.0
	 * @return		An error code
	 * @param[in]   preset	Preset for attributes.
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *
	 * @remarks %GlPlayer initializes the EGL status with the given EGL attributes, which means that system does not guarantees to set EGL configurations with the given attributes but prefers them.
	 *
	 */
	result SetEglAttributePreset(EglAttributesPreset preset);

	/**
	 * Set EGL configuration for the given Attribute with the given value.
	 *
	 * @since 2.0
	 * @return		An error code
	 * @param[in]   key	EGL attribute
	 * @param[in]   value	Value for the attribute
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *
	 * @remarks %GlPlayer initializes the EGL status with the given EGL attributes, which means that system does not guarantees to set EGL configurations with the given attributes but prefers them.
	 *
	 */
	result SetEglAttribute(EGLint key, EGLint value);

	/**
	 * Set the Renderer which implements %IGlRenderer interface.
	 *
	 * @since 2.0
	 * @return		An error code
	 * @param[in]   renderer	%IGlRenderer defines how to render the scene.
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_OPERATION	Fail to perform IGlRenderer::InitializeGl function which is implemented by developers.
	 * @see	%IGlRenderer
	 *
	 * @remarks If %GlPlayer already has a renderer, then the previous renderer is replaced by the new one.
	 * @remarks If input parameter is null, then the current renderer of %GlPlayer is detached and %GlPlayer does nothing.
	 * @remarks When the %IGlRenderer is replaced with the input, the GL status have to be initialized for the input %IGlRenderer. For such purpose, when the input %IGlRenderer is attached, the overrided IGlRenderer::InitializedGl() function is called. On the other hands, the previous %IGlRenderer of %GlPlayer is detached after calling the overrided %IGlRenderer::TerminateGL() function.
	 *
	 */
	result SetIGlRenderer(IGlRenderer* pRenderer);

private:
	/*
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since 2.0
	 */
	GlPlayer(const GlPlayer& rhs);

	/*
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since 2.0
	 */
	GlPlayer& operator =(const GlPlayer& rhs);

	friend class _GlPlayerImpl;
	class _GlPlayerImpl* __pImpl;

}; // GlPlayer

}}} // Tizen::Graphics::Opengl

#endif //_FGRP_GL_PLAYER_H_
