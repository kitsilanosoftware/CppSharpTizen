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
 * @file	FUiCompositeMode.h
 * @brief	This is the header file for the %Container class.
 *
 * This header file contains the declarations of the %Container class.
 */

#ifndef _FUI_COMPOSITE_MODE_H_
#define _FUI_COMPOSITE_MODE_H_

#ifdef COMPOSITE_MODE_NONE
#undef COMPOSITE_MODE_NONE
#endif

namespace Tizen {namespace Ui
{

/**
* @enum CompositeMode
*
* Defines the mode for compositing controls.
*
* @since 2.0
*/
enum CompositeMode
{
	/** Composites two UI controls using alpha-blending */
	COMPOSITE_MODE_ALPHA_BLENDING,

	/** Composites two UI controls in the way that the given chroma key color from one control is made transparent */
	COMPOSITE_MODE_CHROMA_KEY,

	/** Composites two UI controls in the way that one control overwrites another control */
	COMPOSITE_MODE_OVERWRITE,

	/** Does not composite the given control */
	COMPOSITE_MODE_NONE,
};

}} // Tizen::Ui

#endif // _FUI_COMPOSITE_MODE_H_
