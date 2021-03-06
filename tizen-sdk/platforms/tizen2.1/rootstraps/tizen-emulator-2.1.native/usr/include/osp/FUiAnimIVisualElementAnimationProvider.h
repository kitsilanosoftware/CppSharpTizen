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
 * @file	FUiAnimIVisualElementAnimationProvider.h
 * @brief	This is the header file for the %IVisualElementAnimationProvider interface.
 *
 * This header file contains the declarations of the %IVisualElementAnimationProvider interface.
 */

#ifndef _FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_PROVIDER_H_
#define _FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_PROVIDER_H_

#include <FOspConfig.h>

namespace Tizen { namespace Base {
class String;
}}	// Tizen::Base

namespace Tizen { namespace Ui { namespace Animations
{

class VisualElement;
class VisualElementAnimation;

/**
* @interface	IVisualElementAnimationProvider
* @brief	This interface implements the provider for the events generated by the VisualElement.
*
* @since	2.0
*
* The %IVisualElementAnimationProvider interface customizes implicit animations. The class that needs to override default implicit animations must implement this interface, and
* the instance created with that class is registered with VisualElement, using the VisualElement::SetAnimationProvider() method.
* When the properties defined in %VisualElement and its descendants are changed, the CreateAnimationForProperty() method of this interface is invoked.
*
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/animating_uicontrols.htm">Implicit and Explicit Animations</a>.
*
*/
class _OSP_EXPORT_ IVisualElementAnimationProvider
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IVisualElementAnimationProvider(void) {}

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
	virtual Tizen::Ui::Animations::VisualElementAnimation* CreateAnimationForProperty(Tizen::Ui::Animations::VisualElement& target, const Tizen::Base::String& property) = 0;


protected:
	// Reserved virtual methods for later extension.
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementAnimationProvider_Reserved1(void) {}


	// Reserved virtual methods for later extension.
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementAnimationProvider_Reserved2(void) {}


	// Reserved virtual methods for later extension.
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementAnimationProvider_Reserved3(void) {}


	// Reserved virtual methods for later extension.
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementAnimationProvider_Reserved4(void) {}


	// Reserved virtual methods for later extension.
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementAnimationProvider_Reserved5(void) {}
};		// IVisualElementAnimationProvider


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_IVISUAL_ELEMENT_ANIMATION_PROVIDER_H_
