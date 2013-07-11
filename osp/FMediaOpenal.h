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
 * @file		FMediaOpenal.h
 * @brief		This is the header file for the %Openal namespace.
 *
 * This header file contains the declarations of the %Openal namespace.
 *
 */
#ifndef _FMEDIA_OPENAL_H_
#define _FMEDIA_OPENAL_H_

/**
 * @if OSPDEPREC
 * @namespace	Tizen::Media::Openal
 * @brief		<i> [Deprecated]  </i>This namespace contains interfaces for %OpenAL.
 * @deprecated   This namespace is deprecated because libopenal/libalut open source libraries are supported directly on Tizen.
 * @since		2.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FMediaOpenal.h> or @b \#include @b <AL/al.h>, @b <AL/alc.h>, @b <AL/alex.h> and @b <AL/alut.h> @n
 *			  @b Library: @b openal and @b alut
 * @remarks	The capture functions are not supported.
 *
 *
 * The %OpenAL namespace provides %OpenAL (Version 1.1) methods and utilities.
 * %OpenAL is a cross platform three-dimensional audio method. It can also be referred as a software interface to audio hardware.
 * The primary purpose of %OpenAL is to allow an application to position audio sources in three dimensional spaces around a listener, producing reasonable spatialization of the sources for the audio system.
 * %OpenAL is appropriate for many audio applications, but is specifically designed for gaming audio.
 * The %OpenAL namespace provides %OpenAL Utility Toolkit (ALUT) features.
 *
 * For more information, see the <a href="http://connect.creativelabs.com/openal/default.aspx"  target="_blank">Creative Labs Web site</a>.
 * @endif
 */
namespace Tizen { namespace Media
{
namespace Openal
{

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>
#include <AL/alut.h>

}}} // Tizen::Media

#endif
