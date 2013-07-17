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
 * @file		FUiCtrlGalleryTypes.h
 * @brief		This is the header file for the Gallery enumerations.
 *
 * This header file contains the declarations of the Gallery enumerations.
 *
 * These enumerations define the various properties of a %Gallery control.
 */
#ifndef _FUI_CTRL_GALLERY_ENUM_H_
#define _FUI_CTRL_GALLERY_ENUM_H_

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum GalleryImageRotation
 *
 * Defines the rotation of an image of a Gallery control.
 *
 * @since 2.0
 *
 */
enum GalleryImageRotation
{
	GALLERY_IMAGE_ROTATION_0 = 0,				/**< The no rotation */
	GALLERY_IMAGE_ROTATION_90,					/**< The 90 degree clockwise rotation */
	GALLERY_IMAGE_ROTATION_180,					/**< The clockwise rotation */
	GALLERY_IMAGE_ROTATION_270					/**< The anticlockwise rotation */
};

/**
 * @enum GalleryAnimation
 *
 * Defines the animation type of a Gallery control.
 *
 * @since 2.0
 *
 */
enum GalleryAnimation
{
	GALLERY_ANIMATION_PAGE,							/**< The page turn animation */
	GALLERY_ANIMATION_DISSOLVE,						/**< The dissolve animation */
	GALLERY_ANIMATION_ZOOM							/**< The zoom animation */
};

/**
 * @enum  GalleryRefreshType
 *
 * Defines the update type of a Gallery control.
 *
 * @since 2.0
 *
 */
enum GalleryRefreshType
{
	GALLERY_REFRESH_TYPE_ITEM_ADD = 0,				/**< The refresh type is add */
	GALLERY_REFRESH_TYPE_ITEM_REMOVE,				/**< The refresh type is remove */
	GALLERY_REFRESH_TYPE_ITEM_MODIFY				/**< The refresh type is modify */
};

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_GALLERY_ENUM_H_
