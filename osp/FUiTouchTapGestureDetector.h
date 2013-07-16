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
 * @file			FUiTouchTapGestureDetector.h
 * @brief		This is the header file for the %TouchTapGestureDetector class.
 *
 * This header file contains the declarations of the %TouchTapGestureDetector class.
 *
 */

#ifndef _FUI_TOUCH_TAP_GESTURE_DETECTOR_H_
#define _FUI_TOUCH_TAP_GESTURE_DETECTOR_H_

#include <FUiTouchGestureDetector.h>

namespace Tizen { namespace Ui
{

class ITouchTapGestureEventListener;

/**
 * @class		TouchTapGestureDetector
 * @brief		This class stores the information of a tap gesture detector.
 *
 * @since 2.0
 *
 * @final        This class is not intended for extension.
 *
 * The %TouchTapGestureDetector class supports changing conditions of tap gesture, and provides information about tap gesture detector.
 *
 */
class _OSP_EXPORT_ TouchTapGestureDetector
	: public Tizen::Ui::TouchGestureDetector
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	TouchTapGestureDetector(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~TouchTapGestureDetector(void);

	/**
	 * Initializes this instance of %TouchTapGestureDetector.
	 *
	 * @since 2.0
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result Construct(void);

	/**
	* Adds the ITouchTapGestureEventListener instance to the tap gesture detector instance. @n
	* The added listener gets notified when a gesture is recognized.
	*
	* @since 2.0
	*
	* @return			An error code
	* @param[in]	listener						The event listener to add
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_OBJ_ALREADY_EXIST	The listener is already added.
	* @see					RemoveTapGestureEventListener()
	*/
	result AddTapGestureEventListener(Tizen::Ui::ITouchTapGestureEventListener& listener);

	/**
	* Removes the ITouchTapGestureEventListener instance from the tap gesture detector instance.
	*
	* @since 2.0
	*
	* @return			An error code
	* @param[in]	listener						The listener to remove
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_OBJ_NOT_FOUND	The specified @c listener is not found.
	* @see					AddTapGestureEventListener()
	*/
	result RemoveTapGestureEventListener(Tizen::Ui::ITouchTapGestureEventListener& listener);

	/**
	* Sets the tap count required for the recognition of tap gesture.
	*
	* @since 2.0
	*
	* @param[in]		count								The tap count
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG				The specified @c tap count is less than @c 0.
	* @remarks		The default value is @c 2.
	* @see				GetTapCount()
	*
	*/
	result SetTapCount(int count);

	/**
	 * Gets the tap count required for the recognition of tap gesture.
	 *
	 * @since 2.0
	 *
	 * @return			The tap count
	 * @exception	E_SUCCESS					The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an error occurs, this method returns @c -1.
	 * @see			SetTapCount()
	 */
	int GetTapCount(void) const;

	/**
	* Sets the time interval between taps.
	*
	* @since 2.0
	*
	* @param[in]		interval							The time interval between taps
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG				The specified @c interval is less than @c 0.
	* @remarks		If the interval between touches is longer than @c interval, the sequence of touch actions is not recognized as a tap gesture. The default value is @c 330.
	* @see				GetTapInterval()
	*
	*/
	result SetTapInterval(int interval);

	/**
	 * Gets the time interval between taps.
	 *
	 * @since 2.0
	 *
	 * @return			The time interval between taps
	 * @exception	E_SUCCESS					The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an error occurs, this method returns @c -1.
	 * @see			SetTapInterval()
	 */
	int GetTapInterval(void) const;

	/**
	* Sets the finger count for the recognition of tap gesture at the same time.
	*
	* @since 2.0
	*
	* @param[in]		count								The finger count for long press gesture
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG				The specified @c count is less than @c 0.
	* @remarks		If the touch count at the same time is less than @c count, the sequence of touch actions is not recognized as a tap gesture. The default value is @c 1. @n
	*				It is recommended to check the maximum touch count of a device before changing the touch count of a gesture detector.
	*				You can set the gesture touch count to more than the maximum device touch count, but the gesture recognition may not work as you expected.
	* @see			GetTouchCount()
	*
	*/
	result SetTouchCount(int count);

	/**
	* Gets the finger count for the recognition of tap gesture at the same time.
	*
	* @since 2.0
	*
	* @return			The finger count for tap gesture
	* @exception		E_SUCCESS					The method is successful.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @remarks		If an error occurs, this method returns @c -1.
	* @see				GetTouchCount()
	*
	*/
	int GetTouchCount(void) const;

	/**
	*  Sets the allowed displacement between touches for the recognition of tap gesture.
	*
	* @since 2.0
	*
	* @param[in]		allowance						The allowed displacement between touches
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG				The specified @c allowance is less than @c 0.
	* @exception		E_INVALID_CONDITION			%Touch count is more than @c 2.
	* @remarks		The tap gesture is recognized when touches are pressed within the given allowed displacement from the first touch point. The default allowance is @c 10. @n
	*						MoveAllowance is effective only when touch count is @c 1. If touch count is more than 1, MoveAllowance is ignored.
	* @see				GetMoveAllowance()
	*
	*/
	result SetMoveAllowance(int allowance);

	/**
	*  Sets the allowed displacement between touches for the recognition of tap gesture.
	*
	* @since 2.1
	*
	* @param[in]		allowance						The allowed displacement between touches
	* @exception		E_SUCCESS					The method is successful.
	* @exception		E_INVALID_ARG				The specified @c allowance is less than @c 0.
	* @exception		E_INVALID_CONDITION			%Touch count is more than @c 2.
	* @remarks		The tap gesture is recognized when touches are pressed within the given allowed displacement from the first touch point. The default allowance is @c 10. @n
	*						MoveAllowance is effective only when touch count is @c 1. If touch count is more than 1, MoveAllowance is ignored.
	* @see				GetMoveAllowance()
	*
	*/
	result SetMoveAllowance(float allowance);

	/**
	 * Gets ths allowed displacement between touches for the recognition of tap gesture.
	 *
	 * @since 2.0
	 *
	 * @return			The allowed displacement between touches
	 * @exception	E_SUCCESS					The method is successful.
	 * @remarks		If an error occurs, this method returns @c -1.
	 * @see			SetMoveAllowance()
	 */
	int GetMoveAllowance(void) const;

	/**
	 * Gets ths allowed displacement between touches for the recognition of tap gesture.
	 *
	 * @since 2.1
	 *
	 * @return			The allowed displacement between touches
	 * @exception	E_SUCCESS					The method is successful.
	 * @remarks		If an error occurs, this method returns @c -1.
	 * @see			SetMoveAllowance()
	 */
	float GetMoveAllowanceF(void) const;
private:
	//
	// This is the copy constructor for this class.
	//
	TouchTapGestureDetector(const TouchTapGestureDetector& rhs);

	//
	// Assigns the value of the specified instance to the current instance of %TouchTapGestureDetector.
	//
	TouchTapGestureDetector& operator =(const TouchTapGestureDetector& rhs);

protected:
	friend class _TouchTapGestureDetectorImpl;
}; // TouchTapGestureDetector

}} // Tizen::Ui

#endif	//_FUI_TOUCH_TAP_GESTURE_DETECTOR_H_