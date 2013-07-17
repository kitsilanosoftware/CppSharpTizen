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
 * @file			FUiTouchPinchGestureDetector.h
 * @brief		This is the header file for the %TouchPinchGestureDetector class.
 *
 * This header file contains the declarations of the %TouchPinchGestureDetector class.
 *
 */

#ifndef _FUI_TOUCH_PINCH_GESTURE_DETECTOR_H_
#define _FUI_TOUCH_PINCH_GESTURE_DETECTOR_H_

#include <FUiTouchGestureDetector.h>
#include <FGrpPoint.h>
#include <FGrpFloatPoint.h>

namespace Tizen { namespace Ui
{

class ITouchPinchGestureEventListener;

/**
 * @class		TouchPinchGestureDetector
 * @brief		This class stores the information of a pinch gesture detector.
 *
 * @since 2.0
 *
 * @final        This class is not intended for extension.
 *
 * The %TouchPinchGestureDetector class provides information about pinch gesture detector.
 *
 */
class _OSP_EXPORT_ TouchPinchGestureDetector
	: public Tizen::Ui::TouchGestureDetector
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	TouchPinchGestureDetector(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~TouchPinchGestureDetector(void);

	/**
	 * Initializes this instance of %TouchPinchGestureDetector.
	 *
	 * @since 2.0
	 * @feature     %http://tizen.org/feature/multi_point_touch.pinch_zoom
	 *
	 * @return                                                  An error code
	 * @exception    E_SUCCESS                             The method is successful.
	 * @exception    E_OUT_OF_MEMORY                  The memory is insufficient.
	 * @exception    E_UNSUPPORTED_OPERATION    The Emulator or target device does not support the required feature. @b Since: @b 2.1
	 *                                      For more information, see
	 *                                      <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">
	 *                                      Application Filtering</a>.
	 * @remarks     Before calling this method, check whether the feature is supported by
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	*/
	result Construct(void);


	/**
	* Adds the ITouchPinchGestureEventListener instance to the pinch gesture detector instance. @n
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
	result AddPinchGestureEventListener(Tizen::Ui::ITouchPinchGestureEventListener& listener);

	/**
	* Removes the ITouchPinchGestureEventListener instance from the pinch gesture detector instance.
	*
	* @since 2.0
	*
	* @return			An error code
	* @param[in]	listener						The listener to remove
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_OBJ_NOT_FOUND	The specified @c listener is not found.
	* @see					AddRotationGestureEventListener()
	*/
	result RemovePinchGestureEventListener(Tizen::Ui::ITouchPinchGestureEventListener& listener);

	/**
	 * Gets the center position of two touch points.
	 *
	 * @since 2.0
	 *
	 * @return			The center point
	 * @exception	E_SUCCESS					The method is successful.
	 * @remarks		If an error occurs, this method returns Point(-1, -1).
	 */
	Tizen::Graphics::Point GetCenterPoint(void) const;

	/**
	 * Gets the center position of two touch points.
	 *
	 * @since 2.1
	 *
	 * @return			The center point
	 * @exception	E_SUCCESS					The method is successful.
	 * @remarks		If an error occurs, this method returns Point(-1, -1).
	 */
	Tizen::Graphics::FloatPoint GetCenterPointF(void) const;

	/**
	 * Gets the scale factor among touched points.
	 *
	 * @since 2.0
	 *
	 * @return			The scale factor among touched points
	 * @remarks		Gets the scale factor for a pinch gesture in progress.
	 */
	int GetScale(void) const;

	/**
	 * Gets the scale factor among touched point
	 *
	 * @since 2.1
	 *
	 * @return			The scale factor among touched points
	 * @remarks		Gets the scale factor for a pinch gesture in progress.
	 */
	float GetScaleF(void) const;

private:
	//
	// This is the copy constructor for this class.
	//
	TouchPinchGestureDetector(const TouchPinchGestureDetector& rhs);

	//
	// Assigns the value of the specified instance to the current instance of %TouchPinchGestureDetector.
	//
	TouchPinchGestureDetector& operator =(const TouchPinchGestureDetector& rhs);

protected:
	friend class _TouchPinchGestureDetectorImpl;
}; // TouchPinchGestureDetector

}} // Tizen::Ui

#endif	//_FUI_TOUCH_PINCH_GESTURE_DETECTOR_H_
