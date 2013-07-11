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
 * @file	FUiCtrlAnimationFrame.h
 * @brief	This is the header file for the %AnimationFrame class.
 *
 * This header file contains the declarations of the %AnimationFrame class and its helper classes.
 */

#ifndef _FUI_CTRL_ANIMATION_FRAME_H_
#define _FUI_CTRL_ANIMATION_FRAME_H_

#include <FBaseObject.h>
#include <FGrpBitmap.h>

namespace Tizen { namespace Ui { namespace Controls
{

class _AnimationFrameImpl;

/**
 * @class	AnimationFrame
 * @brief	This class defines the common behavior of an %AnimationFrame control.
 *
 * @since	2.0
 *
 * The %AnimationFrame class defines the common behavior of an %AnimationFrame control.
 * An animation frame includes an image to be displayed and its duration.
 * The duration indicates how long the image is displayed when the animation is playing.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_animation.htm">Animation</a>.
 *
 */
class _OSP_EXPORT_ AnimationFrame
	: public Tizen::Base::Object
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	AnimationFrame(void);

	/**
	 * Initializes this instance of %AnimationFrame with the specified parameters. @n
	 * It creates an instance of %AnimationFrame with the specified image and duration.
	 *
	 * @since		2.0
	 *
	 * @param[in]   frame		The bitmap to be displayed
	 * @param[in]   duration	The duration in milliseconds for which the bitmap is displayed
	 */
	AnimationFrame(const Tizen::Graphics::Bitmap& frame, long duration);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	~AnimationFrame(void);

	/**
	 *	Sets the bitmap to be displayed during animation play.
	 *
	 * @since		2.0
	 *
	 * @param[in]	frame		The bitmap to be displayed
	 */
	void SetFrame(const Tizen::Graphics::Bitmap& frame);

	/**
	 * Gets the bitmap to be displayed.
	 *
	 * @since		2.0
	 *
	 * @return		The bitmap
	 */
	const Tizen::Graphics::Bitmap* GetFrame(void) const;

	/**
	 * Sets the duration for which the bitmap is displayed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	duration		The duration in milliseconds for which the bitmap is displayed
	 */
	void SetDuration(long duration);

	/**
	 * Gets the duration for which the bitmap is displayed.
	 *
	 * @since	2.0
	 *
	 * @return	The duration value
	 */
	long GetDuration(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	AnimationFrame(const AnimationFrame& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	AnimationFrame& operator =(const AnimationFrame& rhs);

private:
	_AnimationFrameImpl* __pAnimationFrameImpl;

};  // AnimationFrame

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ANIMATION_FRAME_H_
