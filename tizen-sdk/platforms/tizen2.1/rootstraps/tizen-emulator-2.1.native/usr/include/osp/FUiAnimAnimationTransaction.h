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
 * @file	FUiAnimAnimationTransaction.h
 * @brief	This is the header file for the %AnimationTransaction class.
 *
 * This header file contains the declarations of the %AnimationTransaction class.
 */

#ifndef _FUI_ANIM_ANIMATION_TRANSACTION_H_
#define _FUI_ANIM_ANIMATION_TRANSACTION_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>

#include <FUiAnimAnimationBase.h>
#include <FUiAnimVisualElementAnimation.h>
#include <FUiAnimIAnimationTransactionEventListener.h>


namespace Tizen { namespace Ui { namespace Animations
{

class IVisualElementAnimationTimingFunction;
class IVisualElementAnimationValueInterpolator;

/**
 * @class	AnimationTransaction
 * @brief	This class defines the transaction operations of the animation.
 *
 * @since	2.0
 *
 * The %AnimationTransaction class enables the applications to define animation transactions that make a set of animations on one or more animators to start or stop at the same time.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/transactions.htm">Transactions</a>.
 *
 */
class _OSP_EXPORT_ AnimationTransaction
{
public:

	/**
	 * Initializes a transaction set. @n
	 * Calls ControlAnimator::StartUserAnimation() or calls VisualElement::AddAnimation()
	 * after calling the %Begin() method and before calling the CommitTransaction() method.
	 * Nesting of the transaction set is allowed.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 */
	static result Begin(void);


	/**
	 * Initializes a transaction set. @n
	 * Calls ControlAnimator::StartUserAnimation() or calls VisualElement::AddAnimation()
	 * after calling the %Begin() method and before calling the CommitTransaction() method.
	 * Nesting of the transaction set is allowed.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	transactionId		The transaction ID @n
	 *                                  Use this transaction ID for further operations related to this transaction.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 */
	static result Begin(int& transactionId);


	/**
	 * Commits a set of animation start commands that are added during the current transaction.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 */
	static result Commit(void);


	/**
	 * Stops the transaction. @n
	 * All the nested transactions also will be stopped.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	transactionId	The transaction ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_INVALID_ARG	The specified input parameter is invalid.
	 */
	static result Stop(int transactionId);


	/**
	 * Discards all inactive transactions.
	 *
	 * @since	2.0
	 *
	 * @return  	An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @see		Begin()
	 */
	static result Discard(void);


	/**
	 * Gets the status of the specified transaction.
	 *
	 * @since		2.0
	 *
	 * @return		The state of the transaction
	 * @param[in]	transactionId	The transaction ID
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 */
	static AnimationTransactionStatus GetStatus(int transactionId);


	/**
	 * Sets a default event listener to listen to the events of transactions. @n
	 * The set listener can listen to the events on the specified event dispatcher's context when they are fired.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	pListener		The listener to add
	 * @exception	E_SUCCESS		The method is successful.
	 * @remarks		Only one event listener can be set. @n
	 *              If @c pListener is @c null, the listener already set is unregistered. @n
	 *              An application must deregister the registered listener if the listener object needs to be deleted.
	 * @see			SetCurrentTransactionEventListener()
	 */
	static result SetTransactionEventListener(IAnimationTransactionEventListener* pListener);


	/**
	 * Sets a listener instance to listen to the events of a current transaction. @n
	 * The set listener can listen to the events on the specified event dispatcher's context when they are fired.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	pListener		The listener to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @remarks		If the listener is set using this method, the set default listener is not called.
	 * @see 		SetTransactionEventListener()
	 */
	static result SetCurrentTransactionEventListener(IAnimationTransactionEventListener* pListener);


	/**
	 * Enables or disables the implicit animation on the current transaction. @n
	 * If enabled, implicit animations may be created whenever animatable properties of this instance change.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	enable	Set to @c true to enable the implicit animation, @n
	 *						else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @remarks		The nested transaction created after invoking this method will inherit @c enable as the default value.
	 * @remarks		Deciding whether to enable implicit animation depends on both the flag of transaction and the flag of VisualElement.
	 * 				If both SetVisualElementImplicitAnimationEnabled() and VisualElement::SetImplicitAnimationEnabled() are set to @c true, @n
	 * 				implicit animation is enabled.
	 */
	static result SetVisualElementImplicitAnimationEnabled(bool enable);


	/**
	 * Sets a default event listener to get the status of an animation. @n
	 * The IVisualElementAnimationStatusEventListener listener is called for status changes of animation.
	 * The added listener listens to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	pListener	The pointer of listener instance to set
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @remarks
	 * 				- This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 *           	- If an animation that is listening to an animation status event is removed before starting, then the platform skips to call @n
	 *			      the IVisualElementAnimationStatusEventListener::OnVisualElementAnimationStarted() method and directly calls the IVisualElementAnimationStatusEventListener::OnVisualElementAnimationFinished() method.
	 */
	static result SetVisualElementAnimationStatusEventListener(IVisualElementAnimationStatusEventListener* pListener);


	/**
	 * Sets the default timing function of an animation.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	pTimingFunction		The reference of interpolator instance to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 */
	static result SetVisualElementAnimationTimingFunction(const IVisualElementAnimationTimingFunction* pTimingFunction);


	/**
	 * Sets the default value interpolator of an animation.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	pValueInterpolator	The reference of InterpolatorFunction instance to set
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 */
	static result SetVisualElementAnimationValueInterpolator(const IVisualElementAnimationValueInterpolator* pValueInterpolator);


	/**
	 * Sets the default duration of an animation in the current transaction.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	milliseconds	The duration of the animation in milliseconds
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @exception 	E_INVALID_ARG		The value of the specified parameter is negative or lesser than the offset of the animation.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 * @see		GetVisualElementAnimationDuration()
	 */
	static result SetVisualElementAnimationDuration(long milliseconds);


	/**
	 * Gets the default duration of an animation in milliseconds in the current transaction.
	 *
	 * @since 	2.0
	 *
	 * @return 	The duration value of the animation
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 * @see		SetVisualElementAnimationDuration()
	 */
	static long GetVisualElementAnimationDuration(void);


	/**
	 * Sets the default offset value of an animation. @n
	 * Additionally, the %SetVisualElementAnimationOffset() method alters the start value and duration for which an animation is played.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	milliseconds		The offset value of the animation in milliseconds
	 * @exception 	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @exception 	E_INVALID_ARG		The value of the specified parameter is negative or greater than the duration of the animation.
	 * @remarks 	If the start value of the animation is @c 0.0, the end value is @c 1.0, the duration is @c 100 ms and the offset value is @c 20 ms,
	 *              the actual animation starts at @c 0th ms and plays for @c 80 ms with a start value of @c 0.2. @n
	 *				If @c autoReverse is set to @c true, the Backward animation plays for @c 100ms, from @c 1.0 to @c 0.0.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 * @see 	GetVisualElementAnimationOffset()
	 */
	static result SetVisualElementAnimationOffset(long milliseconds);


	/**
	 * Gets the default offset value in milliseconds after an animation starts.
	 *
	 * @since 	2.0
	 *
	 * @return	The offset value of the animation in milliseconds @n
	 *			The default value of the offset is @c 0.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks 	This is used as the default value for newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 * @see 	SetVisualElementAnimationOffset()
	 */
	static long GetVisualElementAnimationOffset(void);


	/**
	 * Sets the default delay for an animation. @n
	 * The animation starts after the duration of delay has passed.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	milliseconds		The delay for the animation to start in milliseconds
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @exception 	E_INVALID_ARG		The value of the specified parameter is negative.
	 * @remarks 	This method does not alter the start, end, and duration values of the animation.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 * @see 	GetVisualElementAnimationDelay()
	 */
	static result SetVisualElementAnimationDelay(long milliseconds);


	/**
	 * Gets the default delay value in milliseconds before an animation starts.
	 *
	 * @since 	2.0
	 *
	 * @return	The delay value in milliseconds @n
	 *		The default value of the delay is @c 0.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 * @see 	SetVisualElementAnimationDelay()
	 */
	static long GetVisualElementAnimationDelay(void);


	/**
	 * Sets the default repeat count for an animation. @n
	 * Repeats an animation for the specified number of times.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	count			The number of times the animation has to repeat
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @exception 	E_INVALID_ARG		The value of the specified parameter is negative.
	 * @remarks 	A delay and offset is applied to an animation only when the animation is played for the first time.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 * @see 	GetVisualElementAnimationRepeatCount()
	 */
	static result SetVisualElementAnimationRepeatCount(long count);


	/**
	 * Gets the default repeat count value of an animation.
	 *
	 * @since 	2.0
	 *
	 * @return	The repeat count value of the animation @n
	 *		The default value of the repeat count is @c 1.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 * @see 	SetVisualElementAnimationRepeatCount()
	 */
	static long GetVisualElementAnimationRepeatCount(void);


	/**
	 * Sets the default AutoReverse property of an animation. @n
	 * If enabled, the forward and backward animation can also be played.
	 *
	 * @since 	2.0
	 *
	 * @param[in] 	autoReverse	Set to @c true to enable the AutoReverse property of the animation, @n
	 *				else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @remarks 	If @c autoReverse is set to @c true, the duration of the animation is doubled.
	 *				If the repeat count is more than @c 1, @c autoReverse is applied to each iteration.
	 *              Note that if @c autoReverse is set to @c true, one forward animation play
	 * 				and one backward animation play is one iteration.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 * @see 	IsVisualElementAnimationAutoReverseEnabled()
	 */
	static result SetVisualElementAnimationAutoReverseEnabled(bool autoReverse);


	/**
	 * Checks whether the auto reverse is enabled.
	 *
	 * @since 	2.0
	 *
	 * @return	@c true if the auto reverse is enabled, @n
	 *		else @c false @n
	 *		The default auto reverse value is @c false.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 * @see 	SetVisualElementAnimationAutoReverseEnabled()
	 */
	static bool IsVisualElementAnimationAutoReverseEnabled(void);


	/**
	 * Sets the default scale ratio of an animation. @n
	 * The %SetVisualElementAnimationScaleRatio() method multiplies the duration, offset and delay using the scale ratio.
	 *
	 * @since 	2.0
	 *
	 * @return	An error code
	 * @param[in] 	scaleRatio		The scale ratio property of the animation
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @exception 	E_INVALID_ARG		The value of the specified parameter is negative.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation or its descendant classes in the current transaction.
	 * @see 	GetVisualElementAnimationScaleRatio()
	 */
	static result SetVisualElementAnimationScaleRatio(float scaleRatio);


	/**
	 * Gets the default scale ratio value of an animation.
	 *
	 * @since 	2.0
	 *
	 * @return	The scale ratio value of the animation @n
	 *		The default value of scale ratio is @c 1.0f.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	An uncommitted transaction does not exist.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks 	This is used as the default value for the newly created VisualElementAnimation class or its descendant classes in the current transaction.
	 * @see 	SetVisualElementAnimationScaleRatio()
	 */
	static float GetVisualElementAnimationScaleRatio(void);


private:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the default constructor for this class.
	//
	// @since	2.0
	//
	AnimationTransaction(void);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the destructor for this class.
	//
	// @since	2.0
	//
	~AnimationTransaction(void);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the copy constructor for the %AnimationTransaction class.
	//
	// @since		2.0
	// @param[in]	transaction		An instance of %AnimationTransaction
	//
	AnimationTransaction(const AnimationTransaction& transaction);


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// Assigns the value of the specified instance to the current instance of %AnimationTransaction.
	//
	// @since		2.0
	//
	// @param[in]	rhs				An instance of %AnimationTransaction
	//
	AnimationTransaction& operator =(const AnimationTransaction& rhs);
};		// AnimationTransaction


}}}		// Tizen::Ui::Animations

#endif  // _FUI_ANIM_ANIMATION_TRANSACTION_H_
