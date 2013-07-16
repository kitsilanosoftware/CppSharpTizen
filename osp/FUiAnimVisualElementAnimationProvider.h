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
 * @file	FUiAnimVisualElementAnimationProvider.h
 * @brief	This is the header file for the %VisualElementAnimationProvider class.
 *
 * This header file contains the declarations of the %VisualElementAnimationProvider class.
 */

#ifndef _FUI_ANIM_VISUAL_ELEMENT_ANIMATION_PROVIDER_H_
#define _FUI_ANIM_VISUAL_ELEMENT_ANIMATION_PROVIDER_H_

#include <FBase.h>
#include <FUiAnimIVisualElementAnimationProvider.h>

namespace Tizen { namespace Ui { namespace Animations
{


/**
* @class	VisualElementAnimationProvider
* @brief	This class implements the provider for the events generated by VisualElement.
*
* @since	2.0
*
* The %VisualElementAnimationProvider class customizes the implicit animations. The class that needs to override default implicit animations must implement this interface, and
* the instance created with that class is registered with VisualElement, using the VisualElement::SetAnimationProvider() method.
* When the properties defined in %VisualElement and its descendants are changed, the CreateAnimationForProperty() method of this interface is invoked.
*/

class _OSP_EXPORT_ VisualElementAnimationProvider
	: virtual public IVisualElementAnimationProvider
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	VisualElementAnimationProvider(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~VisualElementAnimationProvider(void);


public:
	/**
	 * Invoked for creating an animation when the property is changed.
	 *
	 * @since		2.0
	 *
	 * @return		A VisualElementAnimation instance for @c property
	 * @param[in]	target			The VisualElement instance that needs implicit animation
	 * @param[in]	property		The property of this instance for which animation is required
	 * @remarks		If implicit animation for @c property is not required, return @c null.
	 */
	virtual VisualElementAnimation* CreateAnimationForProperty(VisualElement& target, const Tizen::Base::String& property);


private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.0
	//
	VisualElementAnimationProvider(const VisualElementAnimationProvider& value);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.0
	//
	VisualElementAnimationProvider& operator =(const VisualElementAnimationProvider& value);
};		// VisualElementAnimationProvider


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_VISUAL_ELEMENT_ANIMATION_PROVIDER_H_

