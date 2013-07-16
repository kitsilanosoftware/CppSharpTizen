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
 * @file	FUiAnimParallelAnimationGroup.h
 * @brief	This is the header file for the %ParallelAnimationGroup class.
 *
 * This header file contains the declarations of the %ParallelAnimationGroup class.
 */

#ifndef _FUI_ANIM_PARALLEL_ANIMATION_GROUP_H_
#define _FUI_ANIM_PARALLEL_ANIMATION_GROUP_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>

#include <FUiAnimAnimationBase.h>
#include <FUiAnimAnimationGroup.h>


namespace Tizen { namespace Ui { namespace Animations
{


/**
 * @class	ParallelAnimationGroup
 * @brief	This class is used to group a set of animations together.
 *
 * @since	2.0
 *
 * @final   This class is not intended for extension.
 *
 * The %ParallelAnimationGroup class is used to group a set of animations together in parallel.
 */
class _OSP_EXPORT_ ParallelAnimationGroup
	: public AnimationGroup
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	ParallelAnimationGroup(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~ParallelAnimationGroup(void);


	/**
	 * This is the copy constructor for the %ParallelAnimationGroup class.
	 *
	 * @since	2.0
	 *
	 * @param[in]	animationGroup	An instance of %ParallelAnimationGroup
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	ParallelAnimationGroup(const ParallelAnimationGroup& animationGroup);


	/**
	 * Assigns the value of the specified instance to the current instance of %ParallelAnimationGroup.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %ParallelAnimationGroup
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	ParallelAnimationGroup& operator =(const ParallelAnimationGroup& rhs);


	/**
	 * Checks whether the specified instance and the current instance of %ParallelAnimationGroup have equal animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the animation of the two instances of %ParallelAnimationGroup have equal values, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %ParallelAnimationGroup
	 */
	bool operator ==(const ParallelAnimationGroup& rhs) const;


	/**
	 * Checks whether the specified instance and the current instance of %ParallelAnimationGroup have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %ParallelAnimationGroup are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %ParallelAnimationGroup
	 */
	bool operator !=(const ParallelAnimationGroup& rhs) const;


	/**
	 * Checks whether the value of the current instance of %ParallelAnimationGroup equals the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the current instance is equal to the value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj		An instance of %ParallelAnimationGroup
	 * @remarks     The %ParallelAnimationGroup class has a semantic value. @n
	 *				This means that this method checks whether the two instances have the same animation.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;


	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		The hash value of the current instance
	 * @remarks     The two equal instances must return the same hash value. For better performance, the used hash function must generate a random
	 *				distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;


	/**
	 * Removes all the animations from the animation group.
	 *
	 * @since	2.0
	 */
	virtual void RemoveAllAnimations(void);


	/**
	 * Gets the total number of animations currently stored in a group.
	 *
	 * @since	2.0
	 *
	 * @return      The total number of animations stored in a group
	 */
	virtual int GetAnimationCount(void) const;


	/**
	 * Adds an animation to the animation group. @n
	 * Each animation target can have only one animation.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	animTarget			The animation target type @n
	 *                                  The animation is applied to the specified animation target type.
	 * @param[in]	animation			An object of type AnimationBase
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks If an animation is added to a target type that already has an animation associated with it, the old animation is overwritten with the new animation.
	 */
	result AddAnimation(AnimationTargetType animTarget, const AnimationBase& animation);


	/**
	 * Removes an animation from the animation group with the specified animation target.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	animTarget		The animation target
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception	E_OBJ_NOT_FOUND	The animation with the specified animation target does not exist in the animation group.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result RemoveAnimation(AnimationTargetType animTarget);


	/**
	 * Gets the animation object for the specified animation target.
	 *
	 * @since		2.0
	 *
	 * @return      An animation for the specified animation target in the animation group, @n
	 *				else @c null if the animation target is empty
	 * @param[in]	animTarget		The animation target type to get an animation object
	 */
	AnimationBase* GetAnimationN(AnimationTargetType animTarget) const;


	/**
	 * Checks whether an animation is added for the specified target type.
	 *
	 * @since	2.0
	 *
	 * @return      @c true if an animation is associated with the specified target type, @n
	 *              else @c false
	 * @param[in]	animTarget		The animation target type
	 */
	bool IsAnimationAdded(AnimationTargetType animTarget);


	/**
	 * Gets the type information of this instance.
	 *
	 * @since      2.0
	 *
	 * @return     The type information of this instance
	 */
	virtual AnimationGroupType GetType(void) const;


protected:

	friend class _ParallelAnimationGroupImpl;


	//
	// This variable is for internal use only. Using this variable can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This variable is for internal usage.
	//
	// @since	2.0
	//
	class _ParallelAnimationGroupImpl* _pParallelAnimationGroupImpl;
};		// ParallelAnimationGroup


}}}		// Tizen::Ui::Animations

#endif  // _FUI_ANIM_PARALLEL_ANIMATION_GROUP_H_
