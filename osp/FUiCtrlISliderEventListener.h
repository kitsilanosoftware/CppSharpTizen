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
 * @file		FUiCtrlISliderEventListener.h
 * @brief		This is the header file for the %ISliderEventListener interface.
 *
 * This header file contains the declarations of the %ISliderEventListener interface. @n
 * If a change event is generated, a method of this interface is called. @n
 * So, if the applications perform tasks related to change events, use the methods of this interface.
 *
 */
#ifndef _FUI_CTRL_ISLIDER_EVENT_LISTENER_H_
#define _FUI_CTRL_ISLIDER_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseObject.h>

namespace Tizen { namespace Ui { namespace Controls
{
class Slider;

/**
 * @interface	ISliderEventListener
 * @brief		This interface implements the listener for all slider events.
 *
 * @since		2.0
 *
 * The %ISliderEventListener interface is the listener interface for receiving Slider events, which are fired when the slider knob moves.
 * The class that processes a slider event implements this interface, and the instance created with that class is registered with
 * a UI control, using the control's AddSliderEventListener() method. When the slider event occurs, the OnSliderBarMoved()
 *  method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_slider.htm">Slider</a>.
 */
class ISliderEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~ISliderEventListener(void) {}

	/**
	 * Called when the Slider bar moves.
	 *
	 * @since     2.0
	 *
	 * @param[in] source	The source of the event
	 * @param[in] value     The current value indicated by the knob
	 * @remarks   This event is fired when the knob is moved until the user releases the knob.
	 */
	virtual void OnSliderBarMoved(Tizen::Ui::Controls::Slider& source, int value) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since      2.0
	//
	virtual void ISliderEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since      2.0
	//
	virtual void ISliderEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since      2.0
	//
	virtual void ISliderEventListener_Reserved3(void) {}

};	// ISliderEventListener

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ISLIDER_EVENT_LISTENER_H_
