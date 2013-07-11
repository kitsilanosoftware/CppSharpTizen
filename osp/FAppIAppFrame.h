//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file			FAppIAppFrame.h
 * @brief			This is the header file for the %IAppFrame interface.
 *
 * This header file contains the declarations of the %IAppFrame interface.
 */

#ifndef _FAPP_IAPP_FRAME_H_
#define _FAPP_IAPP_FRAME_H_

namespace Tizen { namespace Graphics { class Canvas; } }
namespace Tizen { namespace Ui { class IKeyEventListener; } }
namespace Tizen { namespace Ui { class ITouchEventListener; } }
namespace Tizen { namespace Ui { class IWindowEventListener; } }
namespace Tizen { namespace Ui { namespace Controls { class Frame; } } }

namespace Tizen { namespace App
{

/**
 * @interface	IAppFrame
 * @brief		This interface provides methods for the application frame.
 *
 * @since	2.0
 *
 * The %IAppFrame interface provides methods for the application frame. A frame is the outermost boundary of the application UI.
 */
class IAppFrame
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IAppFrame(void) {}

	/**
	 * Gets the values of the frame's canvas.
	 *
	 * @since	2.0
	 *
	 * @return	A pointer to the Tizen::Graphics::Canvas class
	 */
	virtual Tizen::Graphics::Canvas* GetCanvasN(void) const = 0;

	/**
	 * Adds a key event listener to the frame.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	listener	A Tizen::Ui::IKeyEventListener instance to add
	 * @exception	E_SUCCESS			The method is successful.
	 */
	virtual result AddKeyEventListener(Tizen::Ui::IKeyEventListener& listener) = 0;

	/**
	 * Removes an existing key event listener from the frame.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	listener	A Tizen::Ui::IKeyEventListener instance to remove
	 * @exception	E_SUCCESS	The method is successful.
	 */
	virtual result RemoveKeyEventListener(Tizen::Ui::IKeyEventListener& listener) = 0;

	/**
	 * Adds a touch event listener to the frame.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	listener	A Tizen::Ui::ITouchEventListener instance to add
	 * @exception	E_SUCCESS			The method is successful.
	 */
	virtual result AddTouchEventListener(Tizen::Ui::ITouchEventListener& listener) = 0;

	/**
	 * Removes an existing touch event listener from the frame.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	listener	A Tizen::Ui::ITouchEventListener instance to add
	 * @exception	E_SUCCESS	The method is successful.
	 */
	virtual result RemoveTouchEventListener(Tizen::Ui::ITouchEventListener& listener) = 0;

	/**
	 * Adds a window event listener to the frame.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	listener	A Tizen::Ui::IWindowEventListener instance to remove
	 * @exception	E_SUCCESS			The method is successful.
	 */
	virtual result AddWindowEventListener(Tizen::Ui::IWindowEventListener& listener) = 0;

	/**
	 * Removes an existing window event listener from the frame.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	listener	A Tizen::Ui::IWindowEventListener instance to remove
	 * @exception	E_SUCCESS	The method is successful.
	 */
	virtual result RemoveWindowEventListener(Tizen::Ui::IWindowEventListener& listener) = 0;

	/**
	 * Gets the frame of the application.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to Tizen::Ui::Controls::Frame if successful, @n
	 *              else @c null
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_UNSUPPORTED_OPERATION	This method cannot be supported.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Ui::Controls::Frame* GetFrame(void) = 0;

}; // IAppFrame

} } // Tizen::App

#endif // _FAPP_IAPP_FRAME_H_
