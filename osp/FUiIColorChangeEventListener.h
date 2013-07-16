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
 * @file		FUiIColorChangeEventListener.h
 * @brief		This is the header file for the %IColorChangeEventListener interface.
 *
 * This header file contains the declarations of the %IColorChangeEventListener interface.
 * If a change event is generated, a method of this interface is called.
 * So, for tasks related to change events, use the methods of this interface.
 *
 */
#ifndef _FUI_ICOLOR_CHANGE_EVENT_LISTENER_H_
#define _FUI_ICOLOR_CHANGE_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseObject.h>

namespace Tizen { namespace Graphics
{
class Color;
}} // Tizen::Graphics;

namespace Tizen { namespace Ui
{

class Control;

/**
 * @interface	IColorChangeEventListener
 * @brief		This interface implements the listener for the color change events.
 *
 * @since		2.0
 *
 * The %IColorChangeEventListener interface is the listener interface for receiving color change events.
 * The class that processes a color change event implements this interface, and the instance created with that class is
 * registered with a UI control, using the control's AddColorChangeEventListener() method. When the color change event occurs,
 * the OnColorChanged() method of that instance is invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_colorpicker.htm">ColorPicker</a>.
 */
class IColorChangeEventListener
	: public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IColorChangeEventListener(void) {}

	/**
	 * Called when there is a change in Color. @n
	 * The %Color instance is passed as an input parameter.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source		The source of the event
	 * @param[in]	color		The color
	 */
	virtual void OnColorChanged(const Tizen::Ui::Control& source, const Tizen::Graphics::Color& color) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since      2.0
	//
	virtual void IColorChangeEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since      2.0
	//
	virtual void IColorChangeEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since      2.0
	//
	virtual void IColorChangeEventListener_Reserved3(void) {}
};	// IColorChangeEventListener

}}	// Tizen::Ui

#endif // _FUI_ICOLOR_CHANGE_EVENT_LISTENER_H_
