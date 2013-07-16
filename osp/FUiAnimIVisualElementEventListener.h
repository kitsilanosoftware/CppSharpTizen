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
 * @file	FUiAnimIVisualElementEventListener.h
 * @brief	This is the header file for the %IVisualElementEventListener interface.
 *
 * This header file contains the declarations of the %IVisualElementEventListener interface.
 */

#ifndef _FUIANIM_IVISUAL_ELEMENT_EVENT_LISTENER_H_
#define _FUIANIM_IVISUAL_ELEMENT_EVENT_LISTENER_H_

#include <FBase.h>
#include <FGrpFloatRectangle.h>
#include <FGrpFloatMatrix4.h>

namespace Tizen { namespace Ui { namespace Animations
{

class VisualElement;

/**
* @interface          IVisualElementEventListener
* @brief This interface implements the event listener for the events generated by VisualElement.
*
* @since          2.0
*
* The %IVisualElementEventListener interface is for receiving events on status change of VisualElement. The class that processes a status change event of %VisualElement
* implements this interface, and the instance created with that class is registered with %VisualElement, using the VisualElement::SetVisualElementEventListener() method.
*
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/visualelement_eventhandling.htm">Event Handling</a>.
*
*/
class _OSP_EXPORT_ IVisualElementEventListener
	: public Tizen::Base::Runtime::IEventListener
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IVisualElementEventListener(void) {}

public:

	/**
	 * Called when the child is attached to VisualElement. @n
	 * Overrides the %OnChildAttached() method to provide user-specific code just after the child is attached to the %VisualElement.
	 * This method is invoked when @c child is attached to @c source by @c AttachChild, @c InsertChild, @c ChangeZOder.
	 *
	 * @since		2.0
	 *
	 * @param[in]	parent		The parent instance
	 * @param[in]	child		The child instance
	 * @see 		VisualElement::AttachChild()
	 * @see 		VisualElement::InsertChild()
	 */
	virtual void OnChildAttached(Tizen::Ui::Animations::VisualElement& parent, Tizen::Ui::Animations::VisualElement& child) = 0;


	/**
	 * Called when the child is detached to VisualElement. @n
	 * Overrides the %OnChildDetached() method to provide user-specific code just after the child is detached from the %VisualElement.
	 * This method is invoked when @c child is detached from @c source by @c DetachChild, @c InsertChild, or @c ChangeZOder.
	 *
	 * @since		2.0
	 *
	 * @param[in]	parent		The parent instance
	 * @param[in]	child		The child instance
	 * @see 		VisualElement::DetachChild()
	 */
	virtual void OnChildDetached(Tizen::Ui::Animations::VisualElement& parent, Tizen::Ui::Animations::VisualElement& child) = 0;


	/**
	 * Called when VisualElement is attached to the parent. @n
	 * Overrides the %OnAttached() method to provide user-specific code just after the %VisualElement is attached to the parent.
	 * This method is invoked when @c source is attached to @c parent by @c AttachChild, @c InsertChild, @c ChangeZOder.
	 *
	 * @since		2.0
	 *
	 * @param[in]	child		The child instance
	 * @param[in]	parent		The parent instance
	 * @see 		VisualElement::AttachChild()
	 * @see 		VisualElement::InsertChild()
	 */
	virtual void OnAttached(Tizen::Ui::Animations::VisualElement& child, Tizen::Ui::Animations::VisualElement& parent) = 0;


	/**
	 * Called when VisualElement is detached to the parent. @n
	 * Overrides the %OnDetached() method to provide user-specific code just after the %VisualElement is detached from the parent.
	 * This method is invoked when @c source is detached from @c parent by @c DetachChild, @c InsertChild, or @c ChangeZOder.
	 *
	 * @since		2.0
	 *
	 * @param[in]	child		The child instance
	 * @param[in]	parent		The parent instance
	 * @see 		VisualElement::DetachChild()
	 */
	virtual void OnDetached(Tizen::Ui::Animations::VisualElement& child, Tizen::Ui::Animations::VisualElement& parent) = 0;


	/**
	 * Called when the transform matrix is about to be changed. @n
	 * Overrides the %OnTransformChanging() method to provide the user-specific code before the transform matrix is changed.
	 * This method is invoked when the transform matrix of @c source is about to be changed by invoking @c SetTransformMatrix.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	source			The VisualElement to change
	 * @param[in,out]	newTransform	The new transform matrix
	 * @remarks		If this method returns @c E_SUCCESS, @c source will be applied with @c newTransform matrix, else will be cancelled.
	 */
	virtual result OnTransformChanging(Tizen::Ui::Animations::VisualElement& source, Tizen::Graphics::FloatMatrix4& newTransform) = 0;


	/**
	 * Called when the transform matrix is changed. @n
	 * Overrides the %OnTransformChanged() method to provide the user-specific code just after the transform matrix is changed.
	 * This method is invoked when the transform matrix of @c source is changed by invoking @c SetTransformMatrix.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source			The VisualElement change applied
	 * @param[in]	previousTransform	The previous transform matrix
	 */
	virtual void OnTransformChanged(Tizen::Ui::Animations::VisualElement& source, const Tizen::Graphics::FloatMatrix4& previousTransform) = 0;


	/**
	 * Called when the children transform matrix is about to be changed. @n
	 * Overrides the %OnChildrenTransformChanging() method to provide user-specific code before the children transform matrix is changed.
	 * This method is invoked when the children transform matrix of @c source is about to be changed by invoking @c SetChildrenTransformMatrix.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	source			The VisualElement to change
	 * @param[in,out]	newTransform	The new transform matrix
 	 * @remarks		If this method returns @c E_SUCCESS, @c source will be applied with @c newTransform matrix, else will be cancelled.
	 */
	virtual result OnChildrenTransformChanging(Tizen::Ui::Animations::VisualElement& source, Tizen::Graphics::FloatMatrix4& newTransform) = 0;


	/**
	 * Called when the children transform matrix is changed. @n
	 * Overrides the %OnChildrenTransformChanged() method to provide user-specific code just after the children transform matrix is changed.
	 * This method is invoked when the children transform matrix of @c source is changed by invoking @c SetChildrenTransformMatrix.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source			The VisualElement change applied
	 * @param[in]	previousTransform	The previous transform matrix
	 */
	virtual void OnChildrenTransformChanged(Tizen::Ui::Animations::VisualElement& source, const Tizen::Graphics::FloatMatrix4& previousTransform) = 0;


	/**
	 * Called when the bounds are about to be changed. @n
	 * Overrides the %OnBoundsChanging() method to provide user-specific code before the bounds are changed.
	 * This method is invoked when the bounds @c source is about to be changed by invoking @c SetBounds.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	source			The VisualElement to change
	 * @param[in,out]	newBounds		The new bounds
	 * @remarks		If this method does not return @c E_SUCCESS, @c source is not applied with @c newBounds rectangle.
	 */
	virtual result OnBoundsChanging(Tizen::Ui::Animations::VisualElement& source, Tizen::Graphics::FloatRectangle& newBounds) = 0;


	/**
	 * Called when the bounds are changed. @n
	 * Overrides the %OnBoundsChanged() method to provide user-specific code just after the bounds are changed.
	 * This method is invoked when the bounds of @c source is changed by invoking @c SetBounds.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source			The VisualElement change applied
	 * @param[in]	previousBounds		The previous bounds
	 */
	virtual void OnBoundsChanged(Tizen::Ui::Animations::VisualElement& source, const Tizen::Graphics::FloatRectangle& previousBounds) = 0;


	/**
	 * Called when the show state is changed. @n
	 * Overrides the %OnShowStateChanged() method to provide user-specific code when the show state is changed.
	 * This method is invoked when the show state of @c source is changed by invoking @c SetShowState.
	 *
	 * @since		2.0
	 *
	 * @param[in]	source			An instance whose show state is changed
	 * @param[in]	previousShowState	The previous show state
	 */
	virtual void OnShowStateChanged(Tizen::Ui::Animations::VisualElement& source, bool previousShowState) = 0;


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
	virtual void IVisualElementEventListener_Reserved1(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementEventListener_Reserved2(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementEventListener_Reserved3(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementEventListener_Reserved4(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementEventListener_Reserved5(void) {}
};		// IVisualElementEventListener


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_IVISUAL_ELEMENT_EVENT_LISTENER_H_
