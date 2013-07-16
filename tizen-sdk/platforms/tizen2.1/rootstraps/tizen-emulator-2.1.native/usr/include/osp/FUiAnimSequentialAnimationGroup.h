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
 * @file	FUiAnimSequentialAnimationGroup.h
 * @brief	This is the header file for the %SequentialAnimationGroup class.
 *
 * This header file contains the declarations of the %SequentialAnimationGroup class.
 */

#ifndef _FUI_ANIM_SEQUENTIAL_ANIMATION_GROUP_H_
#define _FUI_ANIM_SEQUENTIAL_ANIMATION_GROUP_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>

#include <FUiAnimAnimationBase.h>
#include <FUiAnimAnimationGroup.h>


namespace Tizen { namespace Ui { namespace Animations
{


/**
 * @class	SequentialAnimationGroup
 * @brief	This class is used to group a set of animations together.
 *
 * @since	2.0
 *
 * @final   This class is not intended for extension.
 *
 * The %SequentialAnimationGroup class is used to group a set of animations together in sequence.
 */
class _OSP_EXPORT_ SequentialAnimationGroup
	: public AnimationGroup
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 *
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	SequentialAnimationGroup(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~SequentialAnimationGroup(void);


	/**
	 * This is the copy constructor for the %SequentialAnimationGroup class.
	 *
	 * @since	2.0
	 *
	 * @param[in]	animationGroup		An instance of %SequentialAnimationGroup
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	SequentialAnimationGroup(const SequentialAnimationGroup& animationGroup);


	/**
	 * Assigns the value of the specified instance to the current instance of %SequentialAnimationGroup.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs		An instance of %SequentialAnimationGroup
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	SequentialAnimationGroup& operator =(const SequentialAnimationGroup& rhs);


	/**
	 * Checks whether the specified instance and the current instance of %SequentialAnimationGroup have equal animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the animation of the two instances of %SequentialAnimationGroup have equal values, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %SequentialAnimationGroup
	 */
	bool operator ==(const SequentialAnimationGroup& rhs) const;


	/**
	 * Checks whether the specified instance and the current instance of %SequentialAnimationGroup have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the values of the animations of the two instances of %SequentialAnimationGroup are not equal, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %SequentialAnimationGroup
	 */
	bool operator !=(const SequentialAnimationGroup& rhs) const;


	/**
	 * Checks whether the value of the current instance of %SequentialAnimationGroup is equal to the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the current instance is equal to the value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj		An instance of %SequentialAnimationGroup
	 * @remarks     The %SequentialAnimationGroup class has a semantic value. @n
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
	 * Gets the number of animations currently stored in a group.
	 *
	 * @since	2.0
	 *
	 * @return      The total number of animations stored in a group
	 */
	virtual int GetAnimationCount(void) const;


	/**
	 * Adds the specified animation to the animation group.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	animTarget			The animation target type @n
	 *                                  The animation is applied to the specified animation target type.
	 * @param[in]	animation			An instance of AnimationBase
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result AddAnimation(AnimationTargetType animTarget, const AnimationBase& animation);


	/**
	 * Sets the specified @c animation to the animation group.
	 *
	 * @since   2.0
	 *
	 * @return		An error code
	 * @param[in]	index				The index at which the animation is set
	 * @param[in]	animTarget			The AnimationTargetType to which the animation is applied
	 * @param[in]	animation			An instance of AnimationBase
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks If an animation is added to the same index which already has an animation associated with it, the old animation will be overwritten with the new one.
	 */
	result SetAnimationAt(int index, AnimationTargetType animTarget, const AnimationBase& animation);


	/**
	 * Inserts the specified @c animation to the animation group.
	 *
	 * @since   2.0
	 *
	 * @return		An error code
	 * @param[in]   index				The index at which the animation is inserted
	 * @param[in]   animTarget			The AnimationTargetType to which the animation is applied
	 * @param[in]   animation			An instance of AnimationBase
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception   E_OUT_OF_RANGE      The specified @c index is out of range.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result InsertAnimationAt(int index, AnimationTargetType animTarget, const AnimationBase& animation);


	/**
	 * Removes the animation from the animation group at the specified @c index.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	index				An index value in the animation group list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result RemoveAnimationAt(int index);


	/**
	 * Gets the animation object at the specified @c index.
	 *
	 * @since	2.0
	 *
	 * @return      The animation object at the specified @c index value in the animation group, @n
	 *				else @c null if the @c index is invalid
	 * @param[in]	index			The index value in the animation group list
	 */
	AnimationBase* GetAnimationAtN(int index) const;


	/**
	 * Gets the target type of the animation at the specified @c index.
	 *
	 * @since	2.0
	 *
	 * @return      The target type of the animation at the specified @c index value in the animation group, @n
	 *				else @c ANIMATION_TARGET_NONE if the specified @c index is invalid
	 * @param[in]	index			The index value in the animation group list
	 */
	AnimationTargetType GetAnimationTargetTypeAt(int index) const;


	/**
	 * Gets the type information of this instance.
	 *
	 * @since      2.0
	 *
	 * @return     The type information of this instance
	 */
	virtual AnimationGroupType GetType(void) const;


protected:

	friend class _SequentialAnimationGroupImpl;


	//
	// This variable is for internal use only. Using this variable can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This variable is for internal usage.
	//
	// @since        2.0
	//
	class _SequentialAnimationGroupImpl* _pSequentialAnimationGroupImpl;
};		// SequentialAnimationGroup


}}}		// Tizen::Ui::Animations

#endif  // _FUI_ANIM_SEQUENTIAL_ANIMATION_GROUP_H_
