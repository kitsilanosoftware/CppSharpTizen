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
 * @file	FUiAnimVisualElement.h
 * @brief	This is the header file for the %VisualElement class.
 *
 * This header file contains the declarations of the %VisualElement class.
 */

#ifndef _FUI_ANIM_VISUAL_ELEMENT_H_
#define _FUI_ANIM_VISUAL_ELEMENT_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FGrpFloatMatrix4.h>
#include <FGrpFloatPoint.h>
#include <FGrpFloatRectangle.h>
#include <FUiVariant.h>
#include <FUiAnimTypes.h>
#include <FUiAnimIVisualElementAnimationProvider.h>
#include <FUiAnimIVisualElementContentProvider.h>
#include <FUiAnimIVisualElementEventListener.h>

namespace Tizen { namespace Graphics {
class Canvas;
}}

namespace Tizen { namespace Ui { namespace Animations
{

class VisualElementSurface;
class _VisualElementImpl;


/**
 * @class	VisualElement
 * @brief	This class is a base class for all displayable objects on screen with animations.
 *
 * @since	2.0
 *
 * The %VisualElement class is a base class for all displayable objects on screen with animations.
 * It encapsulates properties about coordinates (bounds, transform matrix, children transform matrix and so on),
 * contents (content bounds, clipping, opacity, show state and so on) and tree-hierarchy.
 * It also provides infrastructure necessary for animations (AddAnimation(), RemoveAnimation() and so on).
 * A %VisualElement object instantiated by applications works as a model object and may have a cloned counter part for presentation on screen which has a separated life-cycle.
 * The presentation object is managed by system and applications must not change properties of it.
 * Most animations of %VisualElement are applied on presentation objects. Properties set by applications are stored in model objects while properties of presentation objects
 * are changing during implicit or explicit animations.
 *
 * This class also provides interfaces such as IVisualElementContentProvider, IVisualElementEventListener, and IVisualElementAnimationProvider to override default behaviors
 * without inheritances.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/visualelement.htm">Visual Elements</a>.
 *
 */

class _OSP_EXPORT_ VisualElement
	: public Tizen::Base::Object
{
public:
	/**
	 * The lowest drawing group, such as, background element.
	 *
	 * @since		2.0
	 */
	static const int Z_ORDER_GROUP_LOWEST	= -1000;


	/**
	 * The level of the default group.
	 *
	 * @since		2.0
	 */
	static const int Z_ORDER_GROUP_NORMAL	= 0;


	/**
	 * The highest drawing group, such as, top-most element.
	 *
	 * @since		2.0
	 */
	static const int Z_ORDER_GROUP_HIGHEST	= 1000;


	/**
	 *	@enum RenderOperation
	 *	Defines the render operation for %VisualElement. @n
	 *	The contents of %VisualElement will be composited on screen using this operation.
	 */
	enum RenderOperation
	{
		RENDER_OPERATION_BLEND = 0,		/**< The contents will be displayed blended with underlying %VisualElements */
		RENDER_OPERATION_COPY			/**< The contents will be displayed obscuring other underlying %VisualElements */
	};


	/**
	 * The object is not fully constructed after this constructor is called.
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	VisualElement(void);

	/**
	 * Initializes this instance of %VisualElement.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Deallocates this instance and all descendants of %VisualElement.
	 *
	 * @since		2.0
	 *
	 * @remarks		This method must be used to destroy this instance. @n
	 * 				Do not use @c delete operator.
	 * @remarks		This method first destroys children, and then it destroys the parent(this instance).
	 * @remarks		This method will call OnDestructing() callback before deallocating the instance.
	 * @remarks		The destructing sequence is as follows:
	 * 				1. Destroy children recursively.
	 *				2. Calls %OnDestructing() callback.
	 * 				3. Detaches from parent.
	 * 				4. Removes all animations associated with this instance.
	 * 				5. Deallocates this instance.
	 * @see Construct()
	 */
	void Destroy(void);

	/**
	 * Sets the animation provider which creates implicit animations.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in] 	pProvider			The animation provider to create implicit animations
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	This instance does not allow to set an animation provider. @n
	 * 								The animation provider can be set to the model instance only.
	 *
	 * @see		IVisualElementAnimationProvider
	 * @see		GetAnimationProvider()
	 */
	result SetAnimationProvider(IVisualElementAnimationProvider* pProvider);

	/**
	 * Gets the assigned animation provider.
	 *
	 * @since		2.0
	 *
	 * @return	 	The animation provider
	 * @exception	E_INVALID_OPERATION	This instance does not allow to get an animation provider. @n
	 * 								The animation provider can be set to the model instance only.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see		IVisualElementAnimationProvider
	 * @see		SetAnimationProvider()
	 */
	IVisualElementAnimationProvider* GetAnimationProvider(void) const;

	/**
	 * Sets the content provider which customizes information on contents.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	pProvider			The content provider to customize information on content
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	This instance does not allow to set a content provider. @n
	 * 								The content provider can be set to the model instance only.
	 * @see		IVisualElementContentProvider
	 * @see		GetContentProvider()
	 */
	result SetContentProvider(IVisualElementContentProvider* pProvider);

	/**
	 * Gets the assigned content provider.
	 *
	 * @since		2.0
	 *
	 * @return	 	The content provider
	 * @exception	E_INVALID_OPERATION	This instance does not allow to get content provider. @n
	 * 								The content provider can be set to the model instance only.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see		IVisualElementContentProvider
	 * @see		SetContentProvider()
	 */
	IVisualElementContentProvider* GetContentProvider(void) const;

	/**
	 * Sets the %VisualElement event listener.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	pListener			The %VisualElement event listener
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	This instance does not allow to set an event listener. @n
	 * 								The event listener can be set to the model instance only.
	 * @see		IVisualElementEventListener
	 * @see		GetVisualElementEventListener()
	 */
	result SetVisualElementEventListener(IVisualElementEventListener* pListener);

	/**
	 * Gets the assigned %VisualElement event listener.
	 *
	 * @since		2.0
	 *
	 * @return	 	The %VisualElement event listener
	 * @exception	E_INVALID_OPERATION	This instance does not allow to get an event listener. @n
	 * 								The event listener can be set to the model instance only.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see		IVisualElementEventListener
	 * @see		SetVisualElementEventListener()
	 */
	IVisualElementEventListener* GetVisualElementEventListener(void) const;


	/**
	 * Overrides the OnConstructed() method to provide user-specific initialization code.
	 *
	 * @since		2.0
	 *
	 * @remarks		This method is called after the instance is initialized by the Construct() method successfully.
	 * @see Construct()
	 * @see Destroy()
	 * @see OnDestructing()
	 */
	virtual void OnConstructed(void);

	/**
	 * Overrides the OnDestructing() method to provide user-specific termination code.
	 *
	 * @since		2.0
	 *
	 * @remarks		This method is called before deallocating the %VisualElement instance by the Destroy() method.
	 * @see Destroy()
	 * @see Construct()
	 * @see OnConstructed()
	 */
	virtual void OnDestructing(void);

	/**
	 * Called by the GetChildAt() method to check whether this instance contains the @c point specified. @n
	 * If the Tizen::Ui::Animations::IVisualElementAnimationProvider interface is set to this instance,
	 * the Tizen::Ui::Animations::IVisualElementContentProvider::HitTest() callback will be called instead.
	 *
	 * @since		2.0
	 *
	 * @return		The hit test result
	 * @param[in]	point			The hit position in the coordinate space of this instance
	 * @remarks		Hit test results must be one of the following values: @n
	 * 					 - Tizen::Ui::Animations::HitTestResult::HIT_TEST_NOWHERE
	 *					 - Tizen::Ui::Animations::HitTestResult::HIT_TEST_MATCH
	 * @see GetChildAt()
	 * @see IVisualElementContentProvider::HitTest()
	 */
	virtual HitTestResult OnHitTest(const Tizen::Graphics::FloatPoint& point);

	/**
	 * Before the system calls OnDraw() method to fill the contents, the %OnPrepareDraw() method is called to give an opportunity to hook or prepare drawing. @n
	 * If the [IVisualElementContentProvider](@ref Tizen::Ui::Animations::IVisualElementContentProvider) interface is set to this instance,
	 * the [PrepareDraw()](@ref Tizen::Ui::Animations::IVisualElementContentProvider::PrepareDraw) callback will be called instead.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if OnDraw() can be called, @n
	 *              else @c false
	 * @see IVisualElementContentProvider::PrepareDraw()
	 */
	virtual bool OnPrepareDraw(void);

	/**
	 * Called to fill contents on the canvas provided by the system. @n
	 * If the [IVisualElementContentProvider](@ref Tizen::Ui::Animations::IVisualElementContentProvider) is set to this instance,
	 * the [DrawContent()](@ref Tizen::Ui::Animations::IVisualElementContentProvider::DrawContent) callback will be called instead.
	 *
	 * @since		2.0
	 *
	 * @param[in]	canvas			The canvas to fill the contents of %VisualElement
	 * @see IVisualElementContentProvider::DrawContent()
	 */
	virtual void OnDraw(Tizen::Graphics::Canvas& canvas);

	/**
	 * Overrides the %OnCreateAnimationForProperty() method to provide user-specific implicit animation. @n
	 * If the [IVisualElementAnimationProvider](@ref Tizen::Ui::Animations::IVisualElementAnimationProvider) interface is set to this instance,
	 * the [CreateAnimationForProperty()](@ref Tizen::Ui::Animations::IVisualElementAnimationProvider::CreateAnimationForProperty) callback will be called instead.
	 *
	 * @since		2.0
	 *
	 * @return		The VisualElementAnimation instance for the specified property, @n
					else @c null to disable implicit animation for the property
	 * @param[in]	property			The property to animate implicitly
	 * @remarks		The returned [Animation](@ref Tizen::Ui::Animations::VisualElementAnimation) instance must be allocated on the heap if needed. @n
	 * 				If you do not need an implicit animation for the @c property at the time this method is called, return @c null.
	 * @see IVisualElementAnimationProvider::CreateAnimationForProperty()
	 */
	virtual VisualElementAnimation* OnCreateAnimationForProperty(const Tizen::Base::String& property);

	/**
	 * Overrides the %OnGetPropertyRequested() method to provide user-specific properties or to change default behaviors of %VisualElement class. @n
	 * This method is called whenever GetProperty() is called.
	 *
	 * @since		2.0
	 *
	 * @return		The property's value
	 * @param[in]	property			The property name
	 * @see			SetProperty()
	 * @see			GetProperty()
	 * @see			OnSetPropertyRequested()
	 */
	virtual Tizen::Ui::Variant OnGetPropertyRequested(const Tizen::Base::String& property) const;

	/**
	 * Overrides the %OnSetPropertyRequested() method to provide user-specific properties or to change default behaviors of %VisualElement class. @n
	 * This method is called whenever SetProperty() is called.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	property			The property name
	 * @param[in]	value				The value of the property to set
	 * @see			SetProperty()
	 * @see			GetProperty()
	 * @see			OnGetPropertyRequested()
	 */
	virtual result OnSetPropertyRequested(const Tizen::Base::String& property, const Tizen::Ui::Variant& value);

	/**
	 * Gets the parent of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		The parent of the this instance
	 */
	VisualElement* GetParent(void) const;

	/**
	 * Gets a list of children of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		The list of children of this instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an exception occurs, this method returns @c null.
	 */
	Tizen::Base::Collection::IList* GetChildrenN(void) const;

	/**
	 * Gets the count of children.
	 *
	 * @since		2.0
	 *
	 * @return		The count of children
	 */
	int GetChildrenCount(void) const;

	/**
	 * Checks whether this instance is a child or descendant of the specified one.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if this instance is a child or descendant of the specified one, @n
	 * 				else @c false
	 * @param[in]	other				An instance of %VisualElement to test relationship
	 */
	bool IsChildOf(const VisualElement& other) const;

	/**
	 * Attaches a child to this instance. @n
	 * The %AttachChild() method attaches the specified @c child at the highest position in the Z order group of the @c child.
	 * If you need to change Z-Order group, you can change it using the SetZOrderGroup() method.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in] 	child				The %VisualElement instance to attach to this instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The input parameter is incorrect. Either of the following conditions has occurred: @n
	 *									- The specified @c child is not instantiated successfully. @n
	 *									- The specified @c child is this instance. @n
	 *									- The specified @c child is already an ancestor of this instance.
	 * @see		SetZOrderGroup()
	 * @see		InsertChild()
	 * @see		DetachChild()
	 * @see		ChangeZOrder()
	 */
	result AttachChild(const VisualElement& child);

	/**
	 * Inserts a child to this instance. @n
	 * If @c pReference is not @c null, the Z order group of @c child will be changed into that of @c pReference and @c child will be
	 * placed right above or below the @c pReference instance according to the @c above parameter.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in] 	child				The %VisualElement instance to attach to this instance
	 * @param[in] 	pReference			A pointer to the %VisualElement instance that is referenced
	 * @param[in] 	above				Specifies the position of @c child relative to the @c pReference
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The input parameter is incorrect. Either of the following conditions has occurred: @n
	 *									- The specified @c child is not instantiated successfully. @n
	 *									- The specified @c child is this instance. @n
	 *									- The specified @c child and @c pReference are same. @n
	 *									- The specified @c child is already an ancestor of this instance. @n
	 *									- The parent of @c pReference is not this instance if @c pReference is not @c null. @n
	 * @remarks		If @c above is @c true, the @c child will be attached above @c pReference in Z order,
	 *				else it will be attached below the @c pReference %VisualElement. @n
	 *				If @c pReference is @c null, the @c child will be attached at the highest position in the @c child's Z order group,
	 *				else the child will be attached at the lowest position in the @c child's Z order group.
	 * @see		SetZOrderGroup()
	 * @see		AttachChild()
	 * @see		DetachChild()
	 * @see		ChangeZOrder()
	 */
	result InsertChild(const VisualElement& child, const VisualElement* pReference, bool above);

	/**
	 * Detaches a child from this instance.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	child				The %VisualElement instance to detach from this instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c child is not a child of this instance.
	 * @remarks		This method detaches @c child from this instance. If you need to deallocate %VisualElement, call Destroy() method, not C++ delete.
	 * @see 	InsertChild()
	 * @see		AttachChild()
	 */
	result DetachChild(const VisualElement& child);

	/**
	 * Changes Z order of this instance.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	pReference			A pointer to the %VisualElement instance that is referenced
	 * @param[in] 	above				Specifies the position of this instance relative to the @c pReference
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The input parameter is incorrect. Either of the following conditions has occurred: @n
	 *									- This instance does not have a parent (not attached). @n
	 *									- This instance and @c pReference do not have same parent if @c pReference is not @c null. @n
	 *									- The specified @c pReference is this instance. @n
	 * @remarks		If @c above is @c true, this instance will be attached above @c pReference in Z order,
	 *				else it will be attached below the @c pReference %VisualElement. @n
	 *				If @c pReference is @c null, this instance will be attached at the highest position in the Z order group of this instance,
	 *				else the child will be attached at the lowest position in the Z order group of this instance.
	 * @see 	InsertChild()
	 * @see		AttachChild()
	 * @see		DetachChild()
	 */
	result ChangeZOrder(const VisualElement* pReference, bool above);

	/**
	 * Gets the child of the specified @c name. @n
	 * If there are multiple matches of the name, it returns the first match.
	 *
	 * @since		2.0
	 *
	 * @return		The %VisualElement instance having the specified @c name @n
	 *				else @c null if there is not %VisualElement with the specified @c name
	 * @param[in]	name				The name of the %VisualElement
	 * @param[in]	searchDescendants	@c true to find a match among all the descendants of this instance, @n
	 * 									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	 There is no %VisualElement with the specified @c name.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an exception occurs, this method returns @c null.
	 * @see		GetName()
	 * @see		SetName()
	 */
	VisualElement* GetChild(const Tizen::Base::String& name, bool searchDescendants) const;

	/**
	 * Gets the farthest (highest Z order) %VisualElement descendant including this instance that contains a specified @c point. @n
	 * The OnHitTest() method or [HitTest](@ref Tizen::Ui::Animations::IVisualElementContentProvider::HitTest) callback may be called
	 * for descendants of this instance including itself.
	 *
	 * @since		2.0
	 *
	 * @return		The %VisualElement that contains @c point, @n
	 *				else @c null if @c point is completely outside of this instance
	 * @param[in]	point				The position in coordinate space of this instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		There is no %VisualElement containing the specified @c point.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an exception occurs, this method returns @c null.
	 * @remarks		This method assumes that all ancestors of this instance do not clip children.
	 * @see		IVisualElementContentProvider::HitTest()
	 * @see		OnHitTest()
	 * @see		IsClipChildrenEnabled()
	 * @see		SetClipChildrenEnabled()
	 */
	VisualElement* GetChildAt(const Tizen::Graphics::FloatPoint& point) const;

	/**
	 * Adds an animation without key name.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	animation			The animation instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The input parameter is incorrect.
	 * @exception	E_INVALID_OPERATION	This instance is not a model object. @n
	 *									An animation can be added to the model instance only.
	 * @see			RemoveAnimation()
	 * @see			GetAnimationN()
	 */
	result AddAnimation(const VisualElementAnimation& animation);

	/**
	 * Adds an animation with key name.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	keyName				The name of the animation that is used to identify animations @n
	 *									Empty @c keyName is allowed.
	 * @param[in]	animation			The animation instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The input parameter is incorrect.
	 * @exception	E_OBJ_ALREADY_EXIST	An animation with @c keyName already exists.
	 * @exception	E_INVALID_OPERATION	This instance is not a model object. @n
	 *									An animation can be added to the model instance only.
	 * @see			RemoveAnimation()
	 * @see			GetAnimationN()
	 */
	result AddAnimation(const Tizen::Base::String& keyName, const VisualElementAnimation& animation);

	/**
	 * Removes the animation with the specified @c keyName.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	keyName				The name of the animation to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		An animation with @c keyName does not exist.
	 * @see			AddAnimation()
	 * @see			GetAnimationN()
	 */
	result RemoveAnimation(const Tizen::Base::String& keyName);

	/**
	 * Gets the animation playing for the specified property.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the animation
	 * @param[in]	keyName				The name of the animation
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		An animation with @c keyName does not exist.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an exception occurs, this method returns @c null.
	 * @see			AddAnimation()
	 * @see			RemoveAnimation()
	 */
	VisualElementAnimation* GetAnimationN(const Tizen::Base::String& keyName) const;

	/**
	 * Removes all animations.
	 *
	 * @since		2.0
	 *
	 * @see			AddAnimation()
	 * @see			RemoveAnimation()
	 */
	void RemoveAllAnimations(void);

	/**
	 * Adds a rectangle to update region of this instance. @n
	 * The update region represents the portion of the %VisualElement's area that must be redrawn by the OnDraw() method.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	pRectangle			The pointer to the rectangular region that contains the coordinates of the rectangle to add to the update region @n
	 *                       			If @c pRectangle is @c null, entire area is added to the update region.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The contents of this instance is set by the SetSurface() method.
	 * @see			SetSurface()
	 */
	result InvalidateRectangle(const Tizen::Graphics::FloatRectangle* pRectangle);

	/**
	 * Gets the smallest rectangle that completely encloses the update region of this instance. @n
	 * Applications can use the update region in the OnDraw() method to minimize the redrawing area to improve performance.
	 * The %GetUpdateRectangle() method returns an empty rectangle if it is not called inside OnDraw() method.
	 *
	 * @since		2.0
	 *
	 * @return		The rectangle to update
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an exception occurs, this method returns FloatRectangle(0.0, 0.0, -1.0, -1.0).
	 * @see			InvalidateRectangle()
	 */
	Tizen::Graphics::FloatRectangle GetUpdateRectangle(void) const;

	/**
	 * Updates the content area of all the descendants including this instance.
	 * The %Draw() method will call OnDraw() or DrawContent() method only if there are regions invalidated by InvalidateRectangle().
	 * The platform will call this method later automatically if applications do not call explicitly.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is not attached to the maintained tree for displaying. @n
	 * 						For displaying, this instance should be descendant of the root %VisualElement.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @see IVisualElementContentProvider
	 */
	result Draw(void);

	/**
	 * Marks the entire area of this instance to be flushed.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 *
	 * @see		Flush()
	 */
	result SetFlushNeeded(void);

	/**
	 * Creates and returns a graphics canvas whose bounds, position, and size are equal to those of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		The graphic canvas of the %VisualElement, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_OPERATION	The contents of this instance is set by the SetSurface() method.
	 * @exception	E_OUT_OF_RANGE		The size of the %VisualElement instance is @c 0 or smaller.
	 * @remarks		This method allocates a Tizen::Graphics::Canvas whose bounds are equal to that of the %VisualElement.
	 *				It is the developer's responsibility to deallocate the canvas after use.
	 *				The canvas is guaranteed to be valid only if the properties of the parent %VisualElement of the canvas remain unchanged.
	 *				Therefore, one must delete previously allocated canvas and create a new canvas using this method,
	 *				if the size or position of the %VisualElement is changed. @n
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an exception occurs, this method returns @c null.
	 * @see			GetCanvasN(const Tizen::Graphics::Rectangle& bounds)
	 */
	Tizen::Graphics::Canvas* GetCanvasN(void) const;


	/**
	 * Creates and returns a graphic canvas of the specified area.
	 *
	 * @since		2.0
	 *
	 * @return		The graphic canvas of the %VisualElement, @n
	 *				else @c null if an exception occurs
	 * @param[in]	bounds  			The position relative to the top-left corner of the %VisualElement and size
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @exception	E_INVALID_OPERATION	The contents of this instance is set by the SetSurface() method.
	 * @exception	E_OUT_OF_RANGE		The specified @c bounds do not intersect with the bounds of the %VisualElement. @n
	 *									The width and height must be greater than @c 0.
	 * @remarks		Only the graphic canvas of displayable %VisualElement can be obtained.
	 *				If the specified area is not inside the %VisualElement,
	 *				the graphics canvas of overlapped area between the %VisualElement and the specified @c bound is returned. @n
	 * 				This method allocates a Tizen::Graphics::Canvas whose bounds are equal to that of the %VisualElement.
	 *				It is the developer's responsibility to deallocate the canvas after use.
	 *				The canvas is guaranteed to be valid only if the properties of the parent %VisualElement of the canvas remain unchanged.
	 *				Therefore, one must delete previously allocated canvas and create a new canvas using this method,
	 *				if the size or position of the control is changed. @n
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an exception occurs, this method returns @c null.
	 * @see			GetCanvasN()
	 */
	Tizen::Graphics::Canvas* GetCanvasN(const Tizen::Graphics::Rectangle& bounds) const;

	/**
	 * Gets the name of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		The name of this instance
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * Sets the name of this instance.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	name				The name of the %VisualElement instance @n
	 *                                  Empty or duplicated name with other instances are also allowed.
	 */
	void SetName(const Tizen::Base::String& name);

	/**
	 * Gets the value of the %VisualElement's property.
	 *
	 * @since		2.0
	 *
	 * @return		The value of the specified property
	 * @param[in]	property			The %VisualElement's property
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_KEY_NOT_FOUND		The specified @c property is not found.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an exception occurs, this method returns @c Variant::NULL_VARIANT.
	 * @remarks		Additional exceptions can occur according to the behavior of subclasses.
	 * @see			SetProperty()
	 * @see			OnGetPropertyRequested()
	 */
	Variant GetProperty(const Tizen::Base::String& property) const;

	/**
	 * Sets the value of the %VisualElement's property.
	 *
	 * @since		2.0
	 *
	 * @return		The property's value
	 * @param[in]	property			The %VisualElement's property
	 * @param[in]	value				The value of the %VisualElement's property to set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_KEY_NOT_FOUND		The specified @c property is not found.
	 * @remarks		Additional exceptions can occur according to the behavior of subclasses.
	 * @see			GetProperty()
	 * @see			OnSetPropertyRequested()
	 */
	result SetProperty(const Tizen::Base::String& property, const Variant& value);

	/**
	 * Sets the Z order group of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	zOrderGroup			The value of Z order which must be between @c Z_ORDER_GROUP_LOWEST and @c Z_ORDER_GROUP_HIGHEST @n
	 *									The default value is @c Z_ORDER_GROUP_NORMAL.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The @c zOrderGroup is not between @c Z_ORDER_GROUP_LOWEST and @c Z_ORDER_GROUP_HIGHEST.
	 * @remarks		You can choose the @c zOrderGroup value as follows: @n
	 * 				- Tizen::Ui::Animations::Z_ORDER_GROUP_LOWEST @n
	 *				- Tizen::Ui::Animations::Z_ORDER_GROUP_NORMAL @n
	 *				- Tizen::Ui::Animations::Z_ORDER_GROUP_HIGHEST @n
	 * 				Or you can specify an integer value between @c ZORDER_GROUP_LOWEST and @c ZORDER_GROUP_HIGHEST.
	 * @see GetZOrderGroup()
	 */
	result SetZOrderGroup(int zOrderGroup);

	/**
	 * Gets the Z order group of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		The Z order group of this instance
	 * @see SetZOrderGroup()
	 */
	int GetZOrderGroup(void) const;

	/**
	 * Checks whether the redraw-on-resize feature is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the redraw-on-resize feature is enabled, @n
	 * 				else @c false
	 * @remarks		The entire content area will be added to the update region when bounds are changed if redraw-on-resize is enabled. @n
	 *				Otherwise, current contents will be scaled for the new bounds of this instance without redrawing.
	 * @see SetRedrawOnResizeEnabled()
	 */
	bool IsRedrawOnResizeEnabled(void) const;

	/**
	 * Enables or disables the redraw-on-resize feature.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable				Set to @c true if invalidation is needed whenever resized, @n
	 * 									else @c false
	 * @see IsRedrawOnResizeEnabled()
	 */
	void SetRedrawOnResizeEnabled(bool enable);

	/**
	 * Gets the position and the size of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		An instance of the Tizen::Graphics::FloatRectangle that represents the position of top-left corner, @n
	 * 				the width, and the height of this instance. @n It has relative coordinate space to the parent.
	 * @see			SetBounds()
	 */
	Tizen::Graphics::FloatRectangle GetBounds(void) const;

	/**
	 * Sets the position and the size of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	bounds				The new bounds of this instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks		When the size of @c bounds is changed, the entire content area will be added to the update region of this instance if redraw-on-resize feature is enabled.
	 * @see			GetBounds()
	 * @see			IsRedrawOnResizeEnabled()
	 * @see			SetRedrawOnResizeEnabled()
	 */
	result SetBounds(const Tizen::Graphics::FloatRectangle& bounds);

	/**
	 * Gets the position on the Z-axis.
	 *
	 * @since		2.0
	 *
	 * @return		The position on the Z-axis
	 * @see			SetZPosition()
	 */
	float GetZPosition(void) const;

	/**
	 * Sets the position on the Z-axis.
	 *
	 * @since		2.0
	 *
	 * @param[in]	zPosition			The position on the Z-axis
	 * @see			GetZPosition()
	 */
	void SetZPosition(float zPosition);

	/**
	 * Checks whether this instance is visible or not. @n
	 * Even if the show state is @c true, this instance can be invisible when show state of one of the ancestors is @c false.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if this instance is visible, @n
	 * 				else @c false
	 * @see			GetShowState()
	 * @see			SetShowState()
	 */
	bool IsVisible(void) const;

	/**
	 * Gets the show state of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		The show state of the %VisualElement instance, @n
	 * 				else @c false
	 * @remarks		Even if the show state is @c true, the %VisualElement is invisible if it is not attached to a parent.
	 * @see			SetShowState()
	 * @see			IsVisible()
	 */
	bool GetShowState(void) const;

	/**
	 * Sets the show state of this instance.
	 *
	 * @since		2.0
	 *
	 * @param[in]	show				Set to @c true if this instance needs to show, @n
	 * 									else @c false
	 * @see			GetShowState()
	 * @see			IsVisible()
	 */
	void SetShowState(bool show);

	/**
	 * Gets the opacity of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		The opacity of this instance
	 * @see			SetOpacity()
	 */
	float GetOpacity(void) const;

	/**
	 * Sets the opacity of this instance.
	 *
	 * @since		2.0
	 *
	 * @param[in]	opacity				The new opacity which must be within the range [0.0, 1.0]
	 * @remarks		The changing opacity affects all the descendants of this instance.
	 * @see			GetOpacity()
	 */
	void SetOpacity(float opacity);

	/**
	 * Enables or disables the implicit animation. @n
	 * If enabled, implicit animations may be created whenever animatable properties of this instance change.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable	Set to @c true to enable the implicit animation, @n
	 *						else @c false
	 * @remarks		The implicit animation is enabled by default.
	 * @see			IsImplicitAnimationEnabled()
	 */
	void SetImplicitAnimationEnabled(bool enable);

	/**
	 * Checks whether the implicit animation is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the implicit animation is enabled, @n
	 *				else @c false
	 * @see			SetImplicitAnimationEnabled()
	 */
	bool IsImplicitAnimationEnabled(void) const;

	/**
	 * Gets the transform matrix of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		The transform matrix of this instance
	 * @see			SetTransformMatrix()
	 */
	Tizen::Graphics::FloatMatrix4 GetTransformMatrix(void) const;

	/**
	 * Sets the transform matrix of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	transform			The transform matrix
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The input parameter is incorrect. @n
	 * 				The E_INVALID_ARG exception occurs when the specified @c transform is not invertible.
	 * @see			GetTransformMatrix()
	 */
	result SetTransformMatrix(const Tizen::Graphics::FloatMatrix4& transform);

	/**
	 * Gets the transform matrix applied to each child.
	 *
	 * @since		2.0
	 *
	 * @return		The transform matrix applied to each child
	 * @remarks		The transform matrix for children is typically used for the projection matrix to layout children in 3D space.
	 * @see			SetChildrenTransformMatrix()
	 */
	Tizen::Graphics::FloatMatrix4 GetChildrenTransformMatrix(void) const;

	/**
	 * Sets the transform matrix applied to each child.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	transform			The transform matrix
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The input parameter is incorrect. @n
	 * 				The E_INVALID_ARG exception occurs when the specified @c transform is not invertible.
	 * @see			GetChildrenTransformMatrix()
	 */
	result SetChildrenTransformMatrix(const Tizen::Graphics::FloatMatrix4& transform);


	/**
	 * Gets the anchor point for this instance's transform matrix in uniform coordinate space
	 * (0.0 and 1.0 mean left/top and right/bottom of the bounds, respectively).
	 *
	 * @since		2.0
	 *
	 * @return		The anchor point of this instance
	 * @see			SetAnchor()
	 */
	Tizen::Graphics::FloatPoint GetAnchor(void) const;

	/**
	 * Sets the anchor point of this instance's transform matrix in uniform coordinate space
	 * (0.0 and 1.0 mean left/top and right/bottom of the bounds, respectively).
	 *
	 * @since		2.0
	 *
	 * @param[in]	anchor				The anchor point in uniform coordinate space
	 * @see			GetAnchor()
	 */
	void SetAnchor(const Tizen::Graphics::FloatPoint& anchor);

	/**
	 * Gets the Z component of this instance's anchor point for transform matrix.
	 *
	 * @since		2.0
	 *
	 * @return		The Z component of the anchor point
	 * @see			SetAnchorZ()
	 */
	float GetAnchorZ(void) const;

	/**
	 * Sets the Z component of this instance's anchor point for transform matrix.
	 *
	 * @since		2.0
	 *
	 * @param[in]	anchorZ				The Z component of anchor point
	 * @see			GetAnchorZ()
	 */
	void SetAnchorZ(float anchorZ);

	/**
	 * Gets the custom data of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		The user data associated with this instance
	 * @see			SetUserData()
	 */
	void* GetUserData(void) const;

	/**
	 * Sets the custom data of this instance.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	pUserData			The user data associated with this instance
	 * @see			GetUserData()
	 */
	void SetUserData(void* pUserData);

	/**
	 * Sets the contents of this instance with the specified VisualElementSurface. @n
	 * The contents of the @c pSurface is not copied by the %SetSurface() method, but shared with this instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	pSurface			The pointer to VisualElementSurface @n
	 * 									If @c pSurface is @c null, surface will be created internally by system.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	This instance does not allow VisualElementSurface for contents.
	 * @remarks		If applications modify the contents of @c pSurface, the modifications will be applied to all
	 *				the %VisualElements which share same VisualElementSurface. But in this case, applications need to call
	 *				the SetFlushNeeded() method for those %VisualElements because the modifications of the @c pSurface will not be applied on the screen automatically.
	 * @see			GetSurfaceN()
	 */
	result SetSurface(VisualElementSurface* pSurface);

	/**
	 * Gets the VisualElementSurface this instance uses for its contents.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to VisualElementSurface
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an exception occurs, this method returns @c null.
	 * @see			SetSurface()
	 */
	VisualElementSurface* GetSurfaceN(void) const;

	/**
	 * Sets the render operation of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	renderOperation		The new rendering operation
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c renderOperation is out of range.
	 * @see			GetRenderOperation()
	 */
	result SetRenderOperation(RenderOperation renderOperation);

	/**
	 * Gets the render operation of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		The render operation of this instance
	 * @see			SetRenderOperation()
	 */
	RenderOperation GetRenderOperation(void) const;

	/**
	 * Checks whether all the descendants are clipped to the bounds of this instance.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if this instance clips all the descendants, @n
	 *              else @c false
	 * @see			SetClipChildrenEnabled()
	 */
	bool IsClipChildrenEnabled(void) const;

	/**
	 * Enables or disables clipping of all the descendants.
	 *
	 * @since		2.0
	 *
	 * @param[in]	clipChildren		Set to @c true if all the descendants are needed to clip to the bounds of this instance, @n
	 *                              	else @c false
	 * @see			IsClipChildrenEnabled()
	 */
	void SetClipChildrenEnabled(bool clipChildren);

	/**
	 * Converts the specified @c point in @c pFromVisualElement coordinate space to this instance's coordinate space.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in,out]	point				The point to convert
	 * @param[in]		pFromVisualElement	The %VisualElement instance with @c point in its coordinate space
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The input parameter is incorrect.
	 * @remarks			This instance and @c pFromVisualElement must share a common ancestor. @n
	 *					If @c null, it is regarded that @c point is in the screen coordinate space.
	 * @see				ConvertCoordinates(Tizen::Graphics::FloatRectangle& rectangle, const VisualElement* pFromVisualElement)
	 */
	result ConvertCoordinates(Tizen::Graphics::FloatPoint& point, const VisualElement* pFromVisualElement) const;

	/**
	 * Converts the specified @c rectangle in @c pFromVisualElement coordinate space to this instance's coordinate space.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in,out]	rectangle			The rectangle to convert
	 * @param[in]		pFromVisualElement	The %VisualElement instance with @c rectangle in its coordinate space
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The input parameter is incorrect.
	 * @exception		E_SYSTEM			A system error has occurred.
	 * @remarks			This instance and @c pFromVisualElement must share a common parent. @n
	 *					If @c null, it is regarded that @c rectangle is in the screen coordinate space.
	 * @see				ConvertCoordinates(Tizen::Graphics::FloatPoint& point, const VisualElement* pFromVisualElement)
	 */
	result ConvertCoordinates(Tizen::Graphics::FloatRectangle& rectangle, const VisualElement* pFromVisualElement) const;

	/**
	 * Sets the sub-rectangle of contents which this instance must display.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	contentBounds			The sub-rectangle of contents to display in uniform coordinate space
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The width and height of @c contentBounds must be greater than @c 0.0.
	 * @remarks		Default @c contentBounds is FloatRectangle(0.0, 0.0, 1.0, 1.0).
	 * @remarks		If each component of @c contentBounds is not within the range [0.0, 1.0], the integer portion of the coordinates are
	 *				ignored and only fractional part is used which creates a repeating contents.
	 * @see			GetContentBounds()
	 */
	result SetContentBounds(const Tizen::Graphics::FloatRectangle& contentBounds);

	/**
	 * Gets the sub-rectangle of contents which this instance must display.
	 *
	 * @since		2.0
	 *
	 * @return		The sub-rectangle of contents to be displayed in uniform coordinate space
	 * @remarks		Default @c contentBounds is FloatRectangle(0.0, 0.0, 1.0, 1.0).
	 * @see			SetContentBounds()
	 */
	Tizen::Graphics::FloatRectangle GetContentBounds(void) const;

	/**
	 * Acquires the %VisualElement instance for display.
	 *
	 * @since		2.0
	 *
	 * @return		The %VisualElement instance for display(readonly)
	 * @remarks		If this instance is a presentation object, this method returns itself.
	 * @see                ReleasePresentationInstance()
	 */
	const VisualElement* AcquirePresentationInstance(void);

	/**
	 * Releases the %VisualElement instance for display.
	 *
	 * @since		2.0
	 *
	 * @remarks		This method should be called only after AcquirePresentationInstance() call.
	 * @see                AcquirePresentationInstance()
	 */
	void ReleasePresentationInstance(void);

	/**
	 * Acquires the %VisualElement instance for model.
	 *
	 * @since		2.0
	 *
	 * @return		The %VisualElement instance for model(readonly)
	 * @remarks		If this instance is a model object, this method returns itself.
	 * @see                ReleaseModelInstance()
	 */

	const VisualElement* AcquireModelInstance(void);

	/**
	 * Releases the %VisualElement instance for model.
	 *
	 * @since		2.0
	 *
	 * @remarks		This method should be called only after AcquireModelInstance() call.
	 */
	void ReleaseModelInstance(void);

	/**
	 * Flushes %VisualElements on screen.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		Because this method may degrade the performance of system, applications must use this method only when really needed.
	 * @see			SetFlushNeeded()
	 */
	static result Flush(void);


protected:
	/**
	 * This is copy constructor for the %VisualElement class.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs			An instance of %VisualElement
	 * @see		CloneN()
	 */
	VisualElement(const VisualElement& rhs);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks		The delete operator cannot be used to deallocate the %VisualElement instance.
	 * @see		Destroy()
	 */
	virtual ~VisualElement(void);

	/**
	 * Creates and returns a polymorphic copy of this %VisualElement instance for the presentation. @n
	 * All descendants of %VisualElement must implement the %CloneN() method and the copy constructor appropriately. @n
	 * When the %VisualElement instance is created, the framework make a %VisualElement for the presentation with this method.
	 *
	 * @since		2.0
	 *
	 * @return		The clone of this instance
	 */
	virtual VisualElement* CloneN(void) const;


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void VisualElement_Reserved1(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void VisualElement_Reserved2(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void VisualElement_Reserved3(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void VisualElement_Reserved4(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void VisualElement_Reserved5(void) {}


private:

	//
	// The implementation of this assignment constructor is intentionally blank to prohibit assignment of objects.
	//
	// @since		2.0
	//
	VisualElement& operator =(const VisualElement& rhs);


protected:
	_VisualElementImpl* _pVisualElementImpl;

	friend class _VisualElementImpl;
}; 		// VisualElement


}}}		// Tizen::Ui::Animations

#endif //_FUIANIMVISUALELEMENT_H_
