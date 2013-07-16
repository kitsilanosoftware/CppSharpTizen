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
 * @file	    FUiTouchEventInfo.h
 * @brief		This is the header file for the %TouchEventInfo class.
 *
 * This header file contains the declarations of the %TouchEventInfo class.
 *
 */

#ifndef _FUI_TOUCH_EVENT_INFO_H_
#define _FUI_TOUCH_EVENT_INFO_H_

#include <FBaseObject.h>
#include <FGrpPoint.h>
#include <FGrpFloatPoint.h>

namespace Tizen { namespace Base { namespace Runtime
{
class IEventArg;
} } }

namespace Tizen { namespace Ui
{

class _TouchEventInfoImpl;

/**
 *	@enum	TouchStatus
 *
 *	Defines constants used to identify touch status.
 *
 * @since	2.0
 */
enum TouchStatus
{
	TOUCH_PRESSED,          /**< The touch pressed event type	*/
	TOUCH_LONG_PRESSED,     /**< The touch long pressed event type	*/
	TOUCH_RELEASED,         /**< The touch released event type	*/
	TOUCH_MOVED,            /**< The touch moved event type	*/
	TOUCH_DOUBLE_PRESSED,   /**< The touch double pressed event type	*/
	TOUCH_FOCUS_IN,         /**< The touch focus-in event type	*/
	TOUCH_FOCUS_OUT,        /**< The touch focus-out event type	*/
	TOUCH_CANCELED,	/**< The touch canceled event type	*/
};

/**
 * @class		TouchEventInfo
 * @brief		This class stores the information of each touch events.
 *
 * @since		2.0
 *
 * @final        This class is not intended for extension.
 *
 * The %TouchEventInfo class provides the touch event information: touch position, status, ID, and so on.
 * @see	ITouchEventListener::OnTouchPressed()
 * @see 	ITouchEventListener::OnTouchReleased()
 * @see	ITouchEventListener::OnTouchMoved()
 * @see	ITouchEventListener::OnTouchFocusIn()
 * @see	ITouchEventListener::OnTouchFocusOut()
 * @if OSPDEPREC
 * @see	ITouchEventListener::OnTouchLongPressed()
 * @see	ITouchEventListener::OnTouchDoublePressed()
 * @endif
 *
 */
class _OSP_EXPORT_ TouchEventInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	TouchEventInfo(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~TouchEventInfo(void);

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	//
	// Initializes this instance of %TouchEventInfo with the specified parameters.
	//
	// @since		2.0
	// @return		An error code
	// @param[in] 	eventArg  		The touch event argument
	//
	result Construct(const Tizen::Base::Runtime::IEventArg& eventArg);

	/**
	 * Gets the ID of the current touch event.
	 *
	 * @since	2.0
	 *
	 * @return	The ID of the current touch event
	 */
	unsigned long GetPointId(void) const;

	/**
	 * Gets the start position of the touch event.
	 *
	 * @since	2.0
	 *
	 * @return	The start position of the touch event
	 */
	Tizen::Graphics::Point GetStartPosition(void) const;

	/**
	 * Gets the start position of the touch event.
	 *
	 * @since	2.1
	 *
	 * @return	The start position of the touch event
	 */
	Tizen::Graphics::FloatPoint GetStartPositionF(void) const;

	/**
	 * Gets the current position of the touch event.
	 *
	 * @since	2.0
	 *
	 * @return	The current position of the touch event
	 */
	Tizen::Graphics::Point GetCurrentPosition(void) const;

	/**
	 * Gets the current position of the touch event.
	 *
	 * @since	2.1
	 *
	 * @return	The current position of the touch event
	 */
	Tizen::Graphics::FloatPoint GetCurrentPositionF(void) const;

	/**
	 * Gets the touch status.
	 *
	 * @since	2.0
	 *
	 * @return  The touch status
	 */
	TouchStatus GetTouchStatus(void) const;

	/**
	 * Checks whether the touch status is flick.
	 *
	 * @since	2.0
	 *
	 * @return 	@c true if the touch status is flick, @n
	 *  		else @c false
	 */
	bool IsFlicked(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	TouchEventInfo(const TouchEventInfo&);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	TouchEventInfo& operator =(const TouchEventInfo&);

private:
	_TouchEventInfoImpl* __pTouchEventInfoImpl;
}; // TouchEventInfo

} } //Tizen::Ui

#endif // _FUI_TOUCH_EVENT_INFO_H_
