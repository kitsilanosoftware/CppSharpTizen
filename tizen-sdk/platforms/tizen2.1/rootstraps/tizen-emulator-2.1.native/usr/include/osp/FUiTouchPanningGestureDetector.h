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
 * @file			FUiTouchPanningGestureDetector.h
 * @brief		This is the header file for the %TouchPanningGestureDetector class.
 *
 * This header file contains the declarations of the %TouchPanningGestureDetector class.
 *
 */

#ifndef _FUI_TOUCH_PANNING_GESTURE_DETECTOR_H_
#define _FUI_TOUCH_PANNING_GESTURE_DETECTOR_H_

#include <FUiTouchGestureDetector.h>

namespace Tizen { namespace Ui
{

class ITouchPanningGestureEventListener;

/**
 * @class		TouchPanningGestureDetector
 * @brief		This class stores the information of a panning gesture detector.
 *
 * @since 2.0
 *
 * @final        This class is not intended for extension.
 *
 * The %TouchPanningGestureDetector class supports changing condition of panning gesture, and provides information about panning gesture detector.
 *
 */
class _OSP_EXPORT_ TouchPanningGestureDetector
	: public Tizen::Ui::TouchGestureDetector
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	TouchPanningGestureDetector(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~TouchPanningGestureDetector(void);

	/**
	 * Initializes this instance of %TouchPanningGestureDetector.
	 *
	 * @since 2.0
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result Construct(void);

	/**
	* Adds the ITouchPanningGestureEventListener instance to the panning gesture detector instance. @n
	* The added listener gets notified when a gesture is recognized.
	*
	* @since 2.0
	*
	* @return			An error code
	* @param[in]	listener						The event listener to add
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_OBJ_ALREADY_EXIST	The listener is already added.
	* @see					RemovePanningGestureEventListener()
	*/
	result AddPanningGestureEventListener(Tizen::Ui::ITouchPanningGestureEventListener& listener);

	/**
	* Removes the ITouchPanningGestureEventListener instance from the panning gesture detector instance.
	*
	* @since 2.0
	*
	* @return			An error code
	* @param[in]	listener						The listener to remove
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_OBJ_NOT_FOUND	The specified @c listener is not found.
	* @see					AddPanningGestureEventListener()
	*/
	result RemovePanningGestureEventListener(Tizen::Ui::ITouchPanningGestureEventListener& listener);

	/**
	* Gets the list of the touched points represented by TouchInfo.
	*
	* @since 2.0
	*
	* @return		A list of the TouchInfo
	* @exception	E_SUCCESS					The method is successful.
	* @remarks	If an error occurs, this method returns @c null.
	* @see				Tizen::Ui::TouchInfo
	*/
	Tizen::Base::Collection::IList* GetTouchInfoListN(void) const;

	/**
	* Sets the finger count for the recognition of panning gesture at the same time.
	*
	* @since 2.0
	*
	* @param[in]		count								The finger count for panning gesture
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
	* Gets the finger count for the recognition of panning gesture at the same time.
	*
	* @since 2.0
	*
	* @return			The finger count for panning gesture
	* @exception		E_SUCCESS					The method is successful.
	* @remarks		If an error occurs, this method returns @c -1.
	* @see				SetTouchCount()
	*
	*/
	int GetTouchCount(void) const;

private:
	//
	// This is the copy constructor for this class.
	//
	TouchPanningGestureDetector(const TouchPanningGestureDetector& rhs);

	//
	// Assigns the value of the specified instance to the current instance of %TouchPanningGestureDetector.
	//
	TouchPanningGestureDetector& operator =(const TouchPanningGestureDetector& rhs);

protected:
	friend class _TouchPanningGestureDetectorImpl;
}; // TouchPanningGestureDetector

} } // Tizen::Ui

#endif	//_FUI_TOUCH_PANNING_GESTURE_DETECTOR_H_
