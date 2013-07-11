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
 * @file		FUiIOrientationEventListener.h
 * @brief		This is the header file for the %IOrientationEventListener interface.
 *
 * This header file contains the declarations of the %IOrientationEventListener interface. @n
 * If an orientation event is generated, a method of this class is called. @n
 * So, if an application performs tasks related to the orientation event, use the methods of this class.
 *
 */

#ifndef _FUI_IORIENTATION_EVENT_LISTENER_H_
#define _FUI_IORIENTATION_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Ui
{
class Control;

/**
 * @enum Orientation
 *
 * Defines the constants used to identify the orientations that a control supports.
 *
 * @since  2.0
 */
enum Orientation
{
	ORIENTATION_NONE,                       /**< The control has no orientation style */
	ORIENTATION_PORTRAIT,                   /**< The control has vertical orientation style */
	ORIENTATION_LANDSCAPE,                  /**< The control has horizontal orientation style */
	ORIENTATION_PORTRAIT_REVERSE,       /**< The control has vertical upside-down orientation style */
	ORIENTATION_LANDSCAPE_REVERSE,          /**< The control has horizontal reverse orientation style */
	ORIENTATION_AUTOMATIC = 6,                  /**< The control has vertical, horizontal, and horizontal reverse orientation styles */
	ORIENTATION_AUTOMATIC_FOUR_DIRECTION = 8,   /**< The control has four-directional orientation style */
};

/**
 * @enum OrientationStatus
 *
 * Defines the constants used to identify the current orientation of a control.
 *
 * @since   2.0
 */
enum OrientationStatus
{
	ORIENTATION_STATUS_NONE = 0,                                            /**< The control orientation status is not determined @if OSPCOMPAT @b Since: @b 2.0 @endif */
	ORIENTATION_STATUS_PORTRAIT = ORIENTATION_PORTRAIT,                     /**< The control is set to vertical orientation */
	ORIENTATION_STATUS_LANDSCAPE = ORIENTATION_LANDSCAPE,                   /**< The control is set to horizontal orientation */
	ORIENTATION_STATUS_PORTRAIT_REVERSE = ORIENTATION_PORTRAIT_REVERSE,     /**< The control is set to vertical upside-down orientation */
	ORIENTATION_STATUS_LANDSCAPE_REVERSE = ORIENTATION_LANDSCAPE_REVERSE,   /**< The control is set to horizontal reverse orientation */
};

/**
 * @interface		IOrientationEventListener
 * @brief			This interface implements the listener for orientation events.
 *
 * @since			2.0
 *
 * The %IOrientationEventListener interface is the listener interface for receiving orientation events.
 * The class that processes an orientation event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddOrientationEventListener() method. When the orientation event occurs, the
 * OnOrientationChanged() method of that instance is invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_form.htm">Form</a>.
 */
class _OSP_EXPORT_ IOrientationEventListener
	: public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since			2.0
	 */
	virtual ~IOrientationEventListener(void) {}

	/**
	 * Called when an orientation event occurs.
	 *
	 * @since	2.0
	 *
	 * @param[in]   source				The source of the event
	 * @param[in]   orientationStatus	The information about the orientation event
	 * @remarks		The orientation changed event is fired on %Control for which orientation mode change has been enabled by calling SetOrientation().
	 * @see		Tizen::Ui::Controls::Frame
	 * @see		Tizen::Ui::Controls::Form
	 */
	virtual void OnOrientationChanged(const Tizen::Ui::Control& source, Tizen::Ui::OrientationStatus orientationStatus) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IOrientationEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IOrientationEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void IOrientationEventListener_Reserved3(void) {}
}; // IOrientationEventListener

}} // Tizen::Ui

#endif // _FUI_IORIENTATION_EVENT_LISTENER_H_
