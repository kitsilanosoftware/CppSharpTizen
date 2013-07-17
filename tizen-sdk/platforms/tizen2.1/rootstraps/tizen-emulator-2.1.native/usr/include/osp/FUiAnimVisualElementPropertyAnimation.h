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
 * @file	FUiAnimVisualElementPropertyAnimation.h
 * @brief	This is the header file for the %VisualElementPropertyAnimation class.
 *
 * This header file contains the declarations of the %VisualElementPropertyAnimation class.
 */

#ifndef _FUI_ANIM_VISUAL_ELEMENT_PROPERTY_ANIMATION_H_
#define _FUI_ANIM_VISUAL_ELEMENT_PROPERTY_ANIMATION_H_

#include <FUiAnimVisualElementValueAnimation.h>

namespace Tizen { namespace Ui { namespace Animations
{


class _VisualElementPropertyAnimationImpl;

/**
 * @class	VisualElementPropertyAnimation
 * @brief	This class is for property animation.
 *
 * @since	2.0
 *
 * The %VisualElementPropertyAnimation class defines the basic property animation.
 */
class _OSP_EXPORT_ VisualElementPropertyAnimation
	: public VisualElementValueAnimation
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
	VisualElementPropertyAnimation(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~VisualElementPropertyAnimation(void);


	/**
	 * This is the copy constructor for the %VisualElementPropertyAnimation class.
	 *
	 * @since	2.0
	 *
	 * @param[in]	animation	An instance of %VisualElementPropertyAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	VisualElementPropertyAnimation(const VisualElementPropertyAnimation& animation);


	/**
	 * Assigns the value of the specified instance to the current instance of %VisualElementPropertyAnimation.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %VisualElementPropertyAnimation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception 	E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	VisualElementPropertyAnimation& operator =(const VisualElementPropertyAnimation& rhs);


	/**
	 * Checks whether the specified instance and current instance of %VisualElementPropertyAnimation have equal animation values.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the animation of the two instances of %VisualElementPropertyAnimation are equal, @n
	 *			else @c false
	 * @param[in]	rhs		An instance of %VisualElementPropertyAnimation
	 */
	bool operator ==(const VisualElementPropertyAnimation& rhs) const;


	/**
	 * Checks whether the specified instance and current instance of %VisualElementPropertyAnimation have different animation values.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the values of the animations of the two instances of %VisualElementPropertyAnimation are not equal, @n
	 *			else @c false
	 * @param[in]	rhs		An instance of %VisualElementPropertyAnimation
	 */
	bool operator !=(const VisualElementPropertyAnimation& rhs) const;


	/**
	 * Checks whether the value of the current instance of %VisualElementPropertyAnimation equals the value of the specified instance.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the value of the current instance equals the value of the specified instance, @n
	 * 			else @c false
	 * @param[in]	obj		An instance of %VisualElementPropertyAnimation
	 * @remarks     The %VisualElementPropertyAnimation class has a semantic value that means this method checks whether the two instances have the same animation.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;


	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return	The hash value of the current instance
	 * @remarks		The two equal instances must return the same hash value.
	 *				For better performance, the used hash function must generate a random distribution for all inputs.
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
	 * Sets the property for the animation.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	property		The property name to which the animation is applied
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @see		GetPropertyName()
	 */
	result SetPropertyName(const Tizen::Base::String& property);


	/**
	 * Gets the string of property to which the animation is applied.
	 *
	 * @since	2.0
	 *
	 * @return	A string of property
	 * @see		SetPropertyName()
	 */
	Tizen::Base::String GetPropertyName(void) const;


protected:

	friend class _VisualElementPropertyAnimationImpl;
};		// VisualElementPropertyAnimation


}}}		// Tizen::Ui::Animations

#endif  // _FUI_ANIM_VISUAL_ELEMENT_PROPERTY_ANIMATION_H_
