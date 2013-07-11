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
 * @file		FUiTouchGestureDetector.h
 * @brief		This is the header file for the %TouchGestureDetector class.
 *
 * This header file contains the declarations of the %TouchGestureDetector class.
 *
 */
#ifndef _FUI_TOUCH_GESTURE_DETECTOR_H_
#define _FUI_TOUCH_GESTURE_DETECTOR_H_

#include <FBaseObject.h>
#include <FUiTouch.h>

namespace Tizen { namespace Ui
{

/**
 * @enum TouchGestureDetectorState
 *
 * Defines the state of a gesture detector.
 *
 * @since 2.0
 */
enum TouchGestureDetectorState
{
	GESTURE_DETECTOR_STATE_READY,	 				/**< The gesture detector is ready to recognize the gesture  */
	GESTURE_DETECTOR_STATE_STARTED,			/**< The gesture detector first recognizes the continuous gesture  */
	GESTURE_DETECTOR_STATE_CHANGED,			/**< A subsequent change happens to the continuous gesture  */
	GESTURE_DETECTOR_STATE_FINISHED,			/**< The discrete gesture is recognized or the continuous gesture ends  */
	GESTURE_DETECTOR_STATE_FAILED,	 			/**< The gesture detector fails in recognizing the gesture 	*/
};

class Control;
class ITouchGestureEventListener;
class _TouchGestureDetectorImpl;

/**
 * @class		TouchGestureDetector
 * @brief		This class stores the information of a gesture detector.
 *
 * @since 2.0
 *
 * The %TouchGestureDetector class defines a common behavior for gesture detectors and provides information about gesture detector.
 *
 */
 class _OSP_EXPORT_ TouchGestureDetector
	: public Tizen::Base::Object
{
public:
	/**
	* The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since 2.0
	*/
	TouchGestureDetector(void);

	/**
	* This destructor overrides Osp::Base::Object::~Object().
	*
	* @since 2.0
	*/
	virtual ~TouchGestureDetector(void);

public:
	/**
	* Initializes this instance of %TouchGestureDetector.
	*
	* @since 2.0
	*
	* @exception	E_SUCCESS			The method is successful.
	*/
	result Construct(void);

	/**
	* Gets the control which the gesture detector is attached to.
	* If an error occurs, this method returns @c null.
	*
	* @since 2.0
	*
	* @return							The control which the gesture detector is attached to.
	* @exception	E_SUCCESS			The method is successful.
	*/
	 Control* GetControl(void) const;

	/**
	 * Enables or disables delaying touch event on Control.
 	 * The %TouchGestureDetector receives touch events prior to a UI control to which it is added.
 	 * Depending on a gesture that it tries to recognize, it is decided whether touch events need to be delivered to the UI control.
	 * If touch events must not be delivered to the UI control while gesture recognition is in progress, call this method with @c false argument.
	 * When the recognition finishes as success, delivering delayed touch events is dependent on IsCancelTouchEventOnSuccessEnabled().
	 * When the recognition finishes as fail, all delayed touch events are fired sequentially.
	 * The default value is @c false.
	 *
	 * @since 2.0
	 *
	 * @return							An error code
	 * @param[in]	enable 				Whether to delay events
	 * @exception	E_SUCCESS			The method is successful.
	 * @see					IsDelayTouchEventEnabled()
	 * @see					SetCancelTouchEventOnSuccessEnabled()
	 */
	result SetDelayTouchEventEnabled(bool enable);

	/**
	* Checks whether delaying touch event to Control is enabled.
	*
	* @since 2.0
	*
	* @return			@c true if delaying touch event is enabled, @n
	*					else @c false if delaying touch event is disabled
	* @exception	E_SUCCESS			The method is successful.
	* @see					SetDelayTouchEventEnabled()
	*/
	bool IsDelayTouchEventEnabled(void) const;

	/**
	* Enables or disables canceling touch event after a gesture is recognized.
	* If canceling touch event is enabled and a gesture is recognized, touch events which have been queued are not delivered to a UI control and discarded.
	* The default value is @c false.
	*
	* @since 2.0
	*
	* @return			An error code
	* @param[in]	enable	 	Whether to cancel touch event
	* @exception	E_SUCCESS			The method is successful.
	* @see					IsCancelTouchEventOnSuccessEnabled()
	* @see 					SetDelayTouchEventEnabled()
	*/
	result SetCancelTouchEventOnSuccessEnabled(bool enable);

	/**
	* Checks whether touch events are canceled after a gesture is recognized.
	*
	* @since 2.0
	*
	* @return			@c true if canceling touch event is enabled, @n
	*					else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @see					SetCancelTouchEventOnSuccessEnabled()
	*/
	bool IsCancelTouchEventOnSuccessEnabled(void) const;

	/**
	* Sets priority between gesture detectors.
	*
	* @since 2.0
	*
	* @return			An error code
	* @param[in]	gestureDetector			The gesture detector
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_ARG				The @c gestureDetector is invalid.
	* @remarks			If you want to set relationship between gesture detectors, call this method.
	*					If @c gestureDetector fails in recognizing a gesture, the gesture detector which waits for it starts the processing of recognizing.
	*					If @c gestureDetector succeeds in recognizing a gesture,
	*					the state of the gesture detector which waits for it changes to GESTURE_DETECTOR_STATE_FAIL.
	*/
	result StartOnFailureOf(const TouchGestureDetector& gestureDetector);

	/**
	 * Called when touch is pressed in the Control which the gesture detector is attached to.
	 *
	 * @since 2.0
	 *
	 * @param[in]  	source							The source of the event
	 * @param[in]   	touchInfo					The touch event information
	 */
	virtual void OnTouchPressed(Tizen::Ui::Control& source, const Tizen::Ui::TouchEventInfo& touchInfo);

	/**
	 * Called when touch is moved in the Control which the gesture detector is attached to.
	 *
	 * @since 2.0
	 *
	 * @param[in]   	source						The source of the event
	 * @param[in]   	touchInfo					The touch event information
	 */
	virtual void OnTouchMoved(Tizen::Ui::Control& source, const Tizen::Ui::TouchEventInfo& touchInfo);

	/**
	 * Called when touch is released in the Control which the gesture detector is attached to.
	 *
	 * @since 2.0
	 *
	 * @param[in]   source						The source of the event
	 * @param[in]   touchInfo					The touch event information
	 */
	virtual void OnTouchReleased(Tizen::Ui::Control& source, const Tizen::Ui::TouchEventInfo& touchInfo);

	/**
	 * Called when touch is canceled in the Control which the gesture detector is attached to.
	 *
	 * @since 2.0
	 *
	 * @param[in]   source						The source of the event
	 * @param[in]   touchInfo					The touch event information
	 */
	virtual void OnTouchCanceled(Tizen::Ui::Control& source, const Tizen::Ui::TouchEventInfo& touchInfo);

protected:
	/**
	* Sets the current state of gesture detector.
	* You can call this method only inherit %TouchGestureDetector directly.
	*
	* @since 2.0
	*
	* @return							An error code
	* @param[in]	state				Gesture detector state
	* @exception	E_SUCCESS			The method is successful.
	* @see					GetDetectorState()
	*/
	result SetDetectorState(Tizen::Ui::TouchGestureDetectorState state);

	/**
	* Gets the current state of gesture detector.
	* If an error occurs, this method returns @c GESTURE_DETECTOR_STATE_READY.
	*
	* @since 2.0
	*
	* @return							The current state of gesture detector
	* @exception	E_SUCCESS			The method is successful.
	* @see					SetDetectorState()
	*/
	Tizen::Ui::TouchGestureDetectorState GetDetectorState(void) const;

	 /**
	* Adds the IGestureEventListener instance to the gesture detector instance. @n
	* The added listener gets notified when a gesture is recognized.
	*
	* @since 2.0
	*
	* @return									An error code
	* @param[in]	listener					The event listener to add
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_OBJ_ALREADY_EXIST	The listener is already added.
	* @see					RemoveGestureEventListener()
	*/
	result AddGestureEventListener(Tizen::Ui::ITouchGestureEventListener& listener);

	/**
	* Removes the gesture listener instance.
	*
	* @since 2.0
	*
	* @return									An error code
	* @param[in]	listener					The listener to remove
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_OBJ_NOT_FOUND	The @c listener is not found.
	* @see					AddGestureEventListener()
	*/
	result RemoveGestureEventListener(Tizen::Ui::ITouchGestureEventListener& listener);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	TouchGestureDetector(const TouchGestureDetector& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	TouchGestureDetector& operator =(const TouchGestureDetector& rhs);

protected:
	friend class _TouchGestureDetectorImpl;

	//
	// This variable is for internal use only. Using this variable can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	_TouchGestureDetectorImpl* __pTouchGestureDetectorImpl;
}; // TouchGestureDetector

}} // Tizen::Ui

#endif	//_FUI_TOUCH_GESTURE_DETECTOR_H_