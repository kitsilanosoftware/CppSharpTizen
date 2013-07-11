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
 * @file		FUiCtrlFrame.h
 * @brief	This is the header file for the %Frame class.
 *
 * This header file contains the declarations of the %Frame class.
 */
#ifndef _FUI_CTRL_FRAME_H_
#define _FUI_CTRL_FRAME_H_

#include <FBaseTypes.h>
#include <FUiWindow.h>
#include <FUiIOrientationEventListener.h>
#include <FUiCtrlFrameTypes.h>

namespace Tizen { namespace Ui { namespace Animations {
class FrameAnimator;
} } } // Tizen::Ui::Animations

namespace Tizen { namespace App {
class _AppFrame;
} } // Tizen::App

namespace Tizen { namespace Ui { namespace Controls
{

class Form;
class IFrameEventListener;

/**
 * @class	Frame
 * @brief	This class provides the main frame window for an application.
 *
 * @since	2.0
 *
 * The %Frame class provides the main frame window for an application.
 * A frame is the main top-level window of an application. It is the ultimate parent
 * of all application controls.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_frame.htm">Frame</a>.
 *
 * The following example demonstrates how to use the %Frame class
 *
 * @code
	// Gets a pointer of the frame
	Frame *pFrame = UiApp::GetInstance()->GetAppFrame()->GetFrame();

	// Creates an instance of canvas
	Canvas* pCanvas = new Canvas();
	pCanvas->Construct();
	pCanvas->DrawText(Point(30, 30), L"FrameSample");

	// Calls Invalidate();
	pFrame->Invalidate(true);
 * @endcode
 *
 */
class _OSP_EXPORT_ Frame
	: public Tizen::Ui::Window
{
public:
// Lifecycle
	/**
	 *	This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	Frame(void);

	/**
	 *	This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~Frame(void);

	/**
	 * Initializes this instance of %Frame with the specified parameter.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       The specified input parameter is invalid.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation (that
	 *									is, the method is called on an instance that is constructed).
	 * @exception	E_MAX_EXCEEDED      The number of Frames and Forms exceeds the system limitation.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks	The maximum number of Forms that an application can construct is limited by available memory.
	 */
	result Construct(void);

	/**
	 * Initializes this instance of %Frame with the specified position and size.
	 *
	 * @since 2.0
	 *
	 * @return	An error code
	 * @param[in]	rect	An instance of the Rectangle class @n
	 *				This instance represents the x and y coordinates of the top-left corner @n
	 *                             of the created window along with its width and height. @n
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation (that
	 *									is, the method is called on an instance that is constructed).
	 * @exception	E_MAX_EXCEEDED	The number of Frames and Forms exceeds the system limitation.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks	The maximum number of Forms that an application can construct is limited by available memory.
	 * @remarks	The specified position and size are only applied when the show mode is not #FRAME_SHOW_MODE_FULL_SCREEN.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect);

// Operation
public:
	/**
	 * Adds an IOrientationEventListener instance. @n
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to be added
	 * @remarks 	When OnOrientationChanged() event is fired, re-position and draw the child controls, but do not explicitly call
	 *				the Show() method.
	 * @see			RemoveOrientationEventListener()
	 */
	void AddOrientationEventListener(Tizen::Ui::IOrientationEventListener& listener);

	/**
	 * Adds an IFrameEventListener instance. @n
	 * The added listener can listen to events on the given event dispatcher's context when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to be added
	 * @see			RemoveFrameEventListener()
	 */
	void AddFrameEventListener(Tizen::Ui::Controls::IFrameEventListener& listener);

	/**
	 * Removes an IOrientationEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener 	The listener to be removed
	 * @see			AddOrientationEventListener()
	 */
	void RemoveOrientationEventListener(Tizen::Ui::IOrientationEventListener& listener);

	/**
	 * Removes an IFrameEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener 		The listener to be removed
	 * @see			AddFrameEventListener()
	 */
	void RemoveFrameEventListener(Tizen::Ui::Controls::IFrameEventListener& listener);

// Accessor
public:
	/**
	 * Gets the current %Form control of the %Frame control.
	 *
	 * @since		2.0
	 *
	 * @return		The current Form, @n
	 *				else @c null if there is no %Form
	 * @see			SetCurrentForm()
	 */
	Form* GetCurrentForm(void) const;

	/**
	 * Sets the specified Form control as the current %Form of the %Frame control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	form			The form to be set as the current form of the %Frame control
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 *								The specified @c form is not a child control of the %Frame control.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		If a form is set as the current form, it becomes the topmost form amongst its siblings. @n
	 *         		SetCurrentForm() does not call Invalidate() internally, so if the current form needs to be drawn
	 *				immediately, Invalidate() should be called after SetCurrentForm().
	 *				Only Frame whose show mode is @c FRAME_SHOW_MODE_FULL_SCREEN can set a Form which has the style of @c FORM_STYLE_INDICATOR as the current form.
	 */
	result SetCurrentForm(const Form& form);

	/**
	 * Gets the background color of the %Frame control.
	 *
	 * @since	2.0
	 *
	 * @return  The background color of the %Frame control
	 */
	Tizen::Graphics::Color GetBackgroundColor(void) const;

	/**
	 * Sets the background color of the %Frame control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	color 	The background color
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * Sets the orientation mode of a frame.
	 *
	 * @since		2.0
	 *
	 * @param[in] 	orientation		The orientation mode of the %Frame control
	 * @remarks	    To see the change in the orientation mode, the corresponding frame must be the topmost frame in the z-order hierarchy.
	 *				hierarchy.
	 */
	void SetOrientation(Tizen::Ui::Orientation orientation);

	/**
	 * Gets the orientation mode of the frame.
	 *
	 * @since	2.0
	 *
	 * @return  The orientation mode of the frame
	 */
	Tizen::Ui::Orientation GetOrientation(void) const;

	/**
	 * Gets the current orientation status of the frame.
	 *
	 * @since	2.0
	 *
	 * @return	The orientation status
	 * @remarks	The method returns ORIENTATION_STATUS_NONE if the %Frame control is not drawn.
	 *          Once it is drawn, the orientation of the %Frame control is set to portrait and the method
	 *          returns ORIENTATION_STATUS_PORTRAIT if the application has not specified its orientation.
	 */
	Tizen::Ui::OrientationStatus GetOrientationStatus(void) const;

	/**
	 * Gets the FrameAnimator of %Frame.
	 *
 	 * @since		2.0
	 *
	 * @return		%FrameAnimator, @n
	 *				else @c null if this instance is not constructed as yet
	 */
	Tizen::Ui::Animations::FrameAnimator* GetFrameAnimator(void) const;

	/**
	 * Sets the mode to show the %Frame control.
	 *
	 * @since 2.0
	 *
	 * @return	An error code
	 * @param[in] mode	The mode to show the %Frame control
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 * @remarks	The default mode is #FRAME_SHOW_MODE_FULL_SCREEN.
	 */
	result SetShowMode(FrameShowMode mode);

	/**
	 * Gets the mode to show the %Frame control.
	 *
	 * @since 2.0
	 *
	 * @return	The mode to show the %Frame control
	 * @remarks	The default mode is #FRAME_SHOW_MODE_FULL_SCREEN.
	 */
	FrameShowMode GetShowMode(void) const;

protected:
	friend class _FrameImpl;

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void Frame_Reserved1(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void Frame_Reserved2(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void Frame_Reserved3(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void Frame_Reserved4(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void Frame_Reserved5(void) { }

private:
	Frame(const Frame&);
	Frame& operator =(const Frame&);
}; // Frame

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_FRAME_H_
