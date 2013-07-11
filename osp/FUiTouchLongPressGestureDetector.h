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
 * @file			FUiTouchLongPressGestureDetector.h
 * @brief		This is the header file for the %TouchLongPressGestureDetector class.
 *
 * This header file contains the declarations of the %TouchLongPressGestureDetector class.
 *
 */

#ifndef _FUI_TOUCH_LONG_PRESS_GESTURE_DETECTOR_H_
#define _FUI_TOUCH_LONG_PRESS_GESTURE_DETECTOR_H_

#include <FUiTouchGestureDetector.h>

namespace Tizen { namespace Ui
{

class ITouchLongPressGestureEventListener;

/**
 * @class		TouchLongPressGestureDetector
 * @brief		This class stores the information of a long press gesture detector.
 *
 * @since 2.0
 *
 * @final        This class is not intended for extension.
 *
 * The %TouchLongPressGestureDetector class supports changing conditions of long press gesture, and provides information about long press gesture detector.
 *
 */
class _OSP_EXPORT_ TouchLongPressGestureDetector
	: public Tizen::Ui::TouchGestureDetector
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	TouchLongPressGestureDetector(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~TouchLongPressGestureDetector(void);

	/**
	 * Initializes this instance of %TouchLongPressGestureDetector.
	 *
	 * @since 2.0
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result Construct(void);

	/**
	 * Adds the ITouchLongPressGestureEventListener instance to the long press gesture detector instance. @n
	 * The added listener gets notified when a gesture is recognized.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]	listener						The event listener to add
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST	The listener is already added.
	 * @see					RemoveLongPressGestureEventListener()
	 */
	result AddLongPressGestureEventListener(Tizen::Ui::ITouchLongPressGestureEventListener& listener);

	/**
	 * Removes the ITouchLongPressGestureEventListener instance from the long press gesture detector instance.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]	listener						The listener to remove
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c listener is not found.
	 * @see					AddLongPressGestureEventListener()
	 */
	result RemoveLongPressGestureEventListener(Tizen::Ui::ITouchLongPressGestureEventListener& listener);

	/**
	 * Sets the duration needed for the recognition of long press gesture.
	 *
	 * @since 2.0
	 *
	 * @param[in]		duration							The time duration
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_ARG				The specified @c duration is less than @c 0.
	 * @remarks		The default value is @c 500 milliseconds.
	 * @see				GetDuration()
	 *
	 */
	result SetDuration(int duration);

	/**
	 * Gets the duration needed for the recognition of long press gesture.
	 *
	 * @since 2.0
	 *
	 * @return			The time duration
	 * @exception	E_SUCCESS					The method is successful.
	 * @remarks		If an error occurs, this method returns -1.
	 * @see			SetDuration()
	 */
	int GetDuration(void) const;

	/**
	 * Sets the allowed displacement of touch move for the recognition of long press gesture.
	 *
	 * @since 2.0
	 *
	 * @param[in]		allowance						The allowed move displacement
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_ARG				The specified @c allowance is less than @c 0.
	 * @remarks		The long press gesture is recognized when touch is pressed and moved within the given allowed displacement from the first touch point for the given duration.
	 * 						The default allowance is @c 10.
	 * @see				GetMoveAllowance()
	 *
	 */
	result SetMoveAllowance(int allowance);

	/**
	 * Gets the allowed move bounds.
	 *
	 * @since 2.0
	 *
	 * @return			The allowed move bounds
	 * @exception		E_SUCCESS					The method is successful.
	 * @remarks		If an error occurs, this method returns -1.
	 * @see				SetMoveAllowance()
	 *
	 */
	int GetMoveAllowance(void) const;

	/**
	 * Sets the finger count for the recognition of long press gesture at the same time.
	 *
	 * @since 2.0
	 *
	 * @param[in]		count								The finger count for long press gesture
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_ARG				The specified @c count is less than @c 0.
	 * @remarks		The default value is @c 1.
	 *				It is recommended to check the maximum touch count of a device before changing the touch count of a gesture detector.
	 *				You can set the gesture touch count to more than the maximum device touch count, but the gesture recognition may not work as you expected.
	 * @see				GetTouchCount()
	 *
	 */
	result SetTouchCount(int count);

	/**
	 * Gets the finger count for the recognition of long press gesture at the same time.
	 *
	 * @since 2.0
	 *
	 * @return			The finger count for long press gesture
	 * @exception		E_SUCCESS					The method is successful.
	 * @remarks		If an error occurs, this method returns -1.
	 * @see				GetTouchCount()
	 *
	 */
	int GetTouchCount(void) const;

private:
	//
	// This is the copy constructor for this class.
	//
	TouchLongPressGestureDetector(const TouchLongPressGestureDetector& rhs);

	//
	// Assigns the value of the specified instance to the current instance of %TouchLongPressGestureDetector.
	//
	TouchLongPressGestureDetector& operator =(const TouchLongPressGestureDetector& rhs);

protected:
	friend class _TouchLongPressGestureDetectorImpl;
}; // TouchLongPressGestureDetector

}} // Tizen::Ui

#endif	//_FUI_TOUCH_LONG_PRESS_GESTURE_DETECTOR_H_
