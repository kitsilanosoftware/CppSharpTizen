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
 * @file			FUiTouchRotationGestureDetector.h
 * @brief		This is the header file for the %TouchRotationGestureDetector class.
 *
 * This header file contains the declarations of the %TouchRotationGestureDetector class.
 *
 */

#ifndef _FUI_TOUCH_ROTATION_GESTURE_DETECTOR_H_
#define _FUI_TOUCH_ROTATION_GESTURE_DETECTOR_H_

#include <FUiTouchGestureDetector.h>

namespace Tizen { namespace Ui
{

class ITouchRotationGestureEventListener;

/**
 * @class		TouchRotationGestureDetector
 * @brief		This class stores the information of a rotation gesture detector.
 *
 * @since 2.0
 *
 * @final        This class is not intended for extension.
 *
 * The %TouchRotationGestureDetector class provides information about rotation gesture detector.
 *
 */
class _OSP_EXPORT_ TouchRotationGestureDetector
	: public Tizen::Ui::TouchGestureDetector
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	TouchRotationGestureDetector(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~TouchRotationGestureDetector(void);

	/**
	 * Initializes this instance of %TouchRotationGestureDetector.
	 *
	 * @since 2.0
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result Construct(void);

	/**
	* Adds the ITouchRotationGestureEventListener instance to the rotation gesture detector instance. @n
	* The added listener gets notified when a gesture is recognized.
	*
	* @since 2.0
	*
	* @return			An error code
	* @param[in]	listener						The event listener to add
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_OBJ_ALREADY_EXIST	The listener is already added.
	* @see					RemoveRotationGestureEventListener()
	*/
	result AddRotationGestureEventListener(Tizen::Ui::ITouchRotationGestureEventListener& listener);

	/**
	* Removes the ITouchRotationGestureEventListener instance from the rotation gesture detector instance.
	*
	* @since 2.0
	*
	* @return			An error code
	* @param[in]	listener						The listener to remove
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_OBJ_NOT_FOUND	The specified @c listener is not found.
	* @see					AddRotationGestureEventListener()
	*/
	result RemoveRotationGestureEventListener(Tizen::Ui::ITouchRotationGestureEventListener& listener);

	/**
	* Gets the angle between the previous touch points and the current touch points.
	*
	* @since 2.0
	*
	* @return			The angle between two touch points
	* @exception	E_SUCCESS					The method is successful.
	* @remarks	If an error occurs, this method returns @c -1.
	*/
	float GetAngle(void) const;

	/**
	* Gets the distance between two touch points.
	*
	* @since 2.0
	*
	* @return			The distance between two touch points
	* @exception	E_SUCCESS					The method is successful.
	* @remarks	If an error occurs, this method returns @c -1.
	*/
	int GetDistance(void) const;

	/**
	* Gets the distance between two touch points.
	*
	* @since 2.1
	*
	* @return			The distance between two touch points
	* @exception	E_SUCCESS					The method is successful.
	* @remarks	If an error occurs, this method returns @c -1.
	*/
	float GetDistanceF(void) const;

private:
	//
	// This is the copy constructor for this class.
	//
	TouchRotationGestureDetector(const TouchRotationGestureDetector& rhs);

	//
	// Assigns the value of the specified instance to the current instance of %TouchRotationGestureDetector.
	//
	TouchRotationGestureDetector& operator =(const TouchRotationGestureDetector& rhs);

protected:
	friend class _TouchRotationGestureDetectorImpl;
}; // TouchRotationGestureDetector

} } // Tizen::Ui

#endif	//_FUI_TOUCH_ROTATION_GESTURE_DETECTOR_H_