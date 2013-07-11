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
 * @file			FUiTouchFlickGestureDetector.h
 * @brief		This is the header file for the %TouchFlickGestureDetector class.
 *
 * This header file contains the declarations of the %TouchFlickGestureDetector class.
 *
 */
#ifndef _FUI_TOUCH_FLICK_GESTURE_DETECTOR_H_
#define _FUI_TOUCH_FLICK_GESTURE_DETECTOR_H_

#include <FUiTouchGestureDetector.h>

namespace Tizen { namespace Ui
{

class ITouchFlickGestureEventListener;

/**
 * @enum FlickDirection
 *
 * Defines the direction of a flick gesture.
 *
 * @since 2.0
 */
enum FlickDirection
{
	FLICK_DIRECTION_NONE = -1, /**< Undefined flick direction */
	FLICK_DIRECTION_RIGHT, /**<  Rightward flick */
	FLICK_DIRECTION_UP, /**<  Upward flick */
	FLICK_DIRECTION_LEFT, /**<  Leftward flick */
	FLICK_DIRECTION_DOWN /**<  Downward flick */
};

/**
 * @class		TouchFlickGestureDetector
 * @brief		This class stores the information of a flick gesture detector.
 *
 * @since 2.0
 *
 * @final        This class is not intended for extension.
 *
 * The %TouchFlickGestureDetector class supports flicking of touches, and provides information about flick gesture detector.
 *
 */
class _OSP_EXPORT_ TouchFlickGestureDetector
	: public Tizen::Ui::TouchGestureDetector
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
		TouchFlickGestureDetector(void);

	/**
	 * This destructor overrides Osp::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~TouchFlickGestureDetector(void);

public:
	 /**
	 * Initializes this instance of %TouchFlickGestureDetector.
	 *
	 * @since 2.0
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result Construct(void);

	/**
	 * Adds the ITouchFlickGestureEventListener instance to the flick gesture detector instance. @n
	 * The added listener gets notified when a gesture is recognized.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]	listener						The event listener to add
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST	The listener is already added.
	 * @see					RemoveFlickGestureEventListener()
	 */
	result AddFlickGestureEventListener(Tizen::Ui::ITouchFlickGestureEventListener& listener);

	/**
	 * Removes the IFlickGestureEventListener instance from the flick gesture detector instance.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]	listener						The listener to remove
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c listener is not found.
	 * @see					AddFlickGestureEventListener()
	 */
	result RemoveFlickGestureEventListener(Tizen::Ui::ITouchFlickGestureEventListener& listener);

	/**
	 * Gets the distance of flick.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[out] xDistance				The distance in x direction
	 * @param[out] yDistance				The distance in y direction
	 * @exception	E_SUCCESS					The method is successful.
	 * @remarks	If an error occurs, this method returns the x distance of -1 and the y distance of -1.
	 */
	result GetDistance(int& xDistance, int& yDistance) const;

	/**
	 * Gets the duration of flick.
	 *
	 * @since 2.0
	 *
	 * @return			The duration of flick
	 * @exception	E_SUCCESS					The method is successful.
	 * @remarks	If an error occurs, this method returns -1.
	 */
	int GetDuration(void) const;

	/**
	 * Gets the direction of flick.
	 *
	 * @since 2.0
	 *
	 * @return			The direction of flick
	 * @exception	E_SUCCESS					The method is successful.
	 * @remarks	If an error occurs, this method returns FLICK_DIRECTION_NONE.
	 */
	Tizen::Ui::FlickDirection GetDirection(void) const;
private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	TouchFlickGestureDetector(const TouchFlickGestureDetector& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	TouchFlickGestureDetector& operator =(const TouchFlickGestureDetector& rhs);

private:
	friend class _TouchFlickGestureDetectorImpl;
}; // TouchFlickGestureDetector

}} // Tizen::Ui

#endif	//_FUI_TOUCH_FLICK_GESTURE_DETECTOR_H_
