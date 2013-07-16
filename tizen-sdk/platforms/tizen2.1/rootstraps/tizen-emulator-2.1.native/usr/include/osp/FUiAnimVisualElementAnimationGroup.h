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
 * @file	FUiAnimVisualElementAnimationGroup.h
 * @brief	This is the header file for the %VisualElementAnimationGroup class.
 *
 * This header file contains the declarations of the %VisualElementAnimationGroup class.
 */

#ifndef _FUI_ANIM_VISUAL_ELEMENT_ANIMATION_GROUP_H_
#define _FUI_ANIM_VISUAL_ELEMENT_ANIMATION_GROUP_H_

#include <FUiAnimVisualElementAnimation.h>


namespace Tizen { namespace Ui { namespace Animations
{

class _VisualElementAnimationGroupImpl;

/**
 * @class	VisualElementAnimationGroup
 * @brief	This class is used to group a set of animations together.
 *
 * @since 	2.0
 *
 * The %VisualElementAnimationGroup class is used to group a set of animations together.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/groups.htm">Groups</a>.
 */
class _OSP_EXPORT_ VisualElementAnimationGroup
	: public VisualElementAnimation
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since 	2.0
	 *
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	VisualElementAnimationGroup(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since 	2.0
	 */
	virtual ~VisualElementAnimationGroup(void);


	/**
	 * This is the copy constructor for the %VisualElementAnimationGroup class.
	 *
	 * @since	2.0
	 *
	 * @param[in]	animationGroup	An instance of %VisualElementAnimationGroup
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	VisualElementAnimationGroup(const VisualElementAnimationGroup& animationGroup);


	/**
	 * Assigns the value of the specified instance to the current instance of %VisualElementAnimationGroup.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %VisualElementAnimationGroup
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	VisualElementAnimationGroup& operator =(const VisualElementAnimationGroup& rhs);


	/**
	 * Checks whether the specified instance and current instance of %VisualElementAnimationGroup have equal animation values.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the animation of the two instances of %VisualElementAnimationGroup are equal, @n
	 *			else @c false
	 * @param[in]	rhs		An instance of %VisualElementAnimationGroup
	 */
	bool operator ==(const VisualElementAnimationGroup& rhs) const;


	/**
	 * Checks whether the specified instance and current instance of %VisualElementAnimationGroup have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the values of the animations of the two instances of %VisualElementAnimationGroup are not equal, @n
	 *			else @c false
	 * @param[in]	rhs		An instance of %VisualElementAnimationGroup
	 */
	bool operator !=(const VisualElementAnimationGroup& rhs) const;


	/**
	 * Checks whether the value of the current instance of %VisualElementAnimationGroup equals the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the value of the current instance equals the value of the specified instance, @n
	 *               else @c false
	 * @param[in]	obj		An instance of %VisualElementAnimationGroup
	 * @remarks     The %VisualElementAnimationGroup class has a semantic value that means this method checks whether the two instances have the same animation.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;


	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return	The hash value of the current instance
	 * @remarks    The two equal instances must return the same hash value.
	 *		For better performance, the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the copied instance of the class.
	 *
	 * @since   2.0
	 *
	 * @return 	An instance of VisualElementAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual VisualElementAnimation* CloneN(void) const;


	/**
	 * Gets the number of animations currently stored in a group.
	 *
	 * @since 	2.0
	 *
	 * @return	The total number of animations stored in a group
	 * @remarks		If an error occurs, the return value is @c -1. @n
	 * 				An element of %VisualElementAnimationGroup is counted as one.
	 */
	int GetAnimationCount(void) const;


	/**
	 * Adds the specified @c animation to the animation group without key name.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	animation 		An instance of VisualElementAnimation
	 * @exception 	E_SUCCESS 		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @see		RemoveAnimationAt()
	 */
	result AddAnimation(const VisualElementAnimation& animation);


	/**
	 * Removes an animation from the group.
	 *
	 * @since 	2.0
	 *
	 * @return 	An error code
	 * @param[in]	index			The index of the animation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c index is not found.
	 * @see		AddAnimation()
	 */
	result RemoveAnimationAt(int index);


	/**
	 * Removes all the animations from the animation group.
	 *
	 * @since 	2.0
	 *
	 * @see		AddAnimation()
	 * @see		RemoveAnimationAt()
	 */
	void RemoveAllAnimations(void);


	/**
	 * Gets an animation from the group.
	 *
	 * @since	2.0
	 *
	 * @return 	An animation for the specified @c index in the animation group, @n
	 *			else @c null if the animation does not exist
	 * @param[in]	index			The index of the animation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is out of range.
	 * @exception	E_OBJ_NOT_FOUND		The animation is not found.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 * 				This method allocates a Tizen::Ui::Animations::VisualElementAnimation.
	 *				It is the developer's responsibility to deallocate the animation after use.
	 * @see		AddAnimation()
	 * @see		RemoveAnimationAt()
	 * @see		RemoveAllAnimations()
	 */
	VisualElementAnimation* GetAnimationAtN(int index) const;


protected:

	friend class _VisualElementAnimationGroupImpl;
};		// VisualElementAnimationGroup


}}}		// Tizen::Ui::Animations

#endif  // _FUI_ANIM_VISUAL_ELEMENT_ANIMATION_GROUP_H_
