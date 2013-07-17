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
 * @file	FGraphicsOpengl2.h
 * @brief	This is the header file for the %Opengl namespace.
 *
 * This header file contains the declarations of the %Opengl namespace.
 *
 */

/**
 * @defgroup	opengles OpenGL&reg; ES
 * @brief	The list of OpenGL&reg;ES functions.
 */

#ifndef _FGRAPHICS_OPENGL_H_
#define _FGRAPHICS_OPENGL_H_

/**
 * @namespace	Tizen::Graphics::Opengl
 * @brief	This namespace contains interfaces for %OpenGL&reg;.
 *
 * - <a href ="group__opengl.html"> OpenGL&reg; ES</a>
 *
 * @since		2.0
 * @remarks
 *			For OpenGL&reg; ES 1.1: @n
 *			@b Header @b %file: @b \#include @b <FGraphicsOpengl.h> @n
 *			@b Library: @b osp-uifw @n
 *			For OpenGL&reg; ES 2.0: @n
 *			@b Header @b %file: @b \#include @b <FGraphicsOpengl2.h> @n
 *			@b Library: @b osp-uifw @n
 *
 *
 *
 *
 *
 *
 * The %Opengl namespace provides support for rendering high performance 2D and 3D graphic objects using the
 * OpenGL&reg;(Open %Graphics Library) specification. This namespace further supports the EGL, OpenGL&reg; ES 1.1, and
 * OpenGL&reg; ES 2.0 features.
 *
 * For more information on the %Opengl namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/graphics/opengl.htm">OpenGL&reg; Guide</a>.
 *
 *
 */
namespace Tizen { namespace Graphics
{

namespace Opengl
{
#include <egl.h>
#include <eglext.h>
#include <gl2.h>
#include <gl2ext.h>

} // Tizen::Graphics::Opengl

} } // Tizen::Graphics
#endif // _FGRAPHICS_OPENGL_H_
