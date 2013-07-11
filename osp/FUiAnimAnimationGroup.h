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
 * @file	FUiAnimAnimationGroup.h
 * @brief	This is the header file for the %AnimationGroup class.
 *
 * This header file contains the declarations of the %AnimationGroup class and its helper classes.
 */

#ifndef _FUI_ANIM_ANIMATION_GROUP_H_
#define _FUI_ANIM_ANIMATION_GROUP_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>
#include <FUiAnimTypes.h>
#include <FUiAnimAnimationBase.h>

namespace Tizen { namespace Ui { namespace Animations
{

/**
 * @class	AnimationGroup
 * @brief	This class is used to group a set of animations together.
 *
 * @since	2.0
 *
 * The %AnimationGroup class is used to group a set of animations together.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/animating_uicontrols.htm">Animating UI Controls</a>.
 */
class _OSP_EXPORT_ AnimationGroup
	: public Tizen::Base::Object
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~AnimationGroup(void);


	/**
	 * Removes all the animations from the animation group.
	 *
	 * @since	2.0
	 */
	virtual void RemoveAllAnimations(void) = 0;


	/**
	 * Gets the animation count value.
	 *
	 * @since		2.0
	 *
	 * @return      The total number of animations added to the group
	 */
	virtual int GetAnimationCount(void) const = 0;


	/**
	 * Gets the type information of this instance.
	 *
	 * @since      2.0
	 *
	 * @return     The type information of this instance
	 */
	virtual AnimationGroupType GetType(void) const = 0;


protected:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the default constructor for this class.
	//
	// @since	2.0
	//
	AnimationGroup(void);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Assigns the value of the specified instance to the current instance of %AnimationGroup.
	//
	// @since		2.0
	//
	// @param[in]	rhs		An instance of %AnimationGroup
	//
	AnimationGroup& operator =(const AnimationGroup& rhs);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the copy constructor for the %AnimationGroup class.
	//
	// @since	2.0
	//
	// @param[in]	animationGroup	An instance of %AnimationGroup
	//
	AnimationGroup(const AnimationGroup& animationGroup);


	friend class _AnimationGroupImpl;


	//
	// This variable is for internal use only. Using this variable can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// The variable for internal usage.
	//
	// @since  2.0
	//
	class _AnimationGroupImpl* _pAnimationGroupImpl;
};		// AnimationGroup


}}}		// Tizen::Ui::Animations

#endif  // _FUI_ANIM_ANIMATION_GROUP_H_
