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
* @file     FUiSystemUtil.h
* @brief    This is the header file for the %SystemUtil class.
*
* This header file contains the declarations of the %SystemUtil class.
*
*/

#ifndef _FUI_SYSTEM_UTIL_H_
#define _FUI_SYSTEM_UTIL_H_

#include <FUiIKeyEventListener.h>

namespace Tizen { namespace Graphics
{
class Bitmap;
class Point;
class FloatPoint;
}}

namespace Tizen { namespace Ui
{

/**
* @enum         KeyEventType
*
* Defines key event types.
*
* @since 2.0
*/
enum KeyEventType
{
           KEY_EVENT_TYPE_PRESSED,           /**< Key pressed event type */
           KEY_EVENT_TYPE_RELEASED,          /**< Key released event type */
};

/**
* @enum         TouchEventType
*
* Defines touch event types.
*
* @since 2.0
*/
enum TouchEventType
{
           TOUCH_EVENT_TYPE_PRESSED,           /**< Touch pressed event type */
           TOUCH_EVENT_TYPE_RELEASED,          /**< Touch released event type */
           TOUCH_EVENT_TYPE_MOVED             /**< Touch moved event type */
};

/**
* @class SystemUtil
* @brief This class is for system utililty such as touch, key, and capturing screen. It provides
*        functionalities to simulate user inputs.
* @since 2.0
* @final           This class is not intended for extension.
*
* The %SystemUtil class provides methods to generate user's input events such as
*        touch and key events for helping test application and to capture current screen.
*/
class _OSP_EXPORT_ SystemUtil
{
public:
           /**
           * Generates a key event.
           *
           * @since 2.0
           *
           * @privlevel          platform
           * @privilege %http://tizen.org/privilege/inputmanager
           *
           * @return                   An error code
           * @param[in]     keyEvent             The event type of the key to generate
           * @param[in]     keyCode     The code of the key
           * @exception                   E_SUCCESS        The method is successful.
           * @exception      E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
           * @exception                   E_OPERATION_FAILED         An error has occurred in the underlying system.
           * @exception               E_INVALID_ARG  The specified @c keyEvent or @c keyCode is not supported.
           */
           static result GenerateKeyEvent(KeyEventType keyEvent, KeyCode keyCode);

           /**
           * Generates a touch event.
           *
           * @since 2.0
           *
           * @privlevel          platform
           * @privilege %http://tizen.org/privilege/inputmanager
           *
           * @return                   An error code
           * @param[in]     touchEvent          The event type of the touch to generate
           * @param[in]     point                 The point on which the touch occurs
           * @exception                   E_SUCCESS        The method is successful.
           * @exception      E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
           * @exception                   E_OPERATION_FAILED         An error has occurred in the underlying system.
           * @exception     E_INVALID_ARG  The specified @c touchEvent is not supported.
           */
           static result GenerateTouchEvent(TouchEventType touchEvent, const Tizen::Graphics::Point& point);

           /**
           * Generates a touch event.
           *
           * @since 2.0
           *
           * @privlevel          platform
           * @privilege %http://tizen.org/privilege/inputmanager
           *
           * @return                   An error code
           * @param[in]     touchEvent          The event type of the touch to generate
           * @param[in]     point                 The point on which the touch occurs
           * @exception                   E_SUCCESS        The method is successful.
           * @exception      E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
           * @exception                   E_OPERATION_FAILED         An error has occurred in the underlying system.
           * @exception     E_INVALID_ARG  The specified @c touchEvent is not supported.
           */
           static result GenerateTouchEvent(TouchEventType touchEvent, const Tizen::Graphics::FloatPoint& point);

           /**
           * Captures a screen.
           *
           * @since 2.0
           *
           * @privlevel          platform
           * @privilege %http://tizen.org/privilege/inputmanager
           *
           * @return                   A pointer to the captured screen bitmap, @n
           * else @c null if it fails to capture screen
           * @exception                   E_SUCCESS        The method is successful.
           * @exception      E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
           * @exception                   E_OPERATION_FAILED         An error has occurred in the underlying system.
           * @remarks There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
           * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
           * The returned bitmap must be deleted by the application after use.
           */
          static Tizen::Graphics::Bitmap* CaptureScreenN(void);

private:
           //
           // This default constructor is intentionally declared as private because this class cannot be constructed.
           //
           SystemUtil(void);

           //
           // The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
           //
           SystemUtil(const SystemUtil& rhs);

           //
           // The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
           //
           SystemUtil& operator =(const SystemUtil& rhs);

           //
           // This is a destructor for this class.
           // This destructor is intentionally declared as private because this class cannot be constructed.
           //
           ~SystemUtil(void);

}; //SystemUtil

}} //Tizen::Ui
#endif

