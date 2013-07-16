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
 * @file	FUiControl.h
 * @brief	This is the header file for the %Control class.
 *
 * This header file contains the declarations of the %Control class.
 */

#ifndef _FUI_CONTROL_H_
#define _FUI_CONTROL_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FGrpCanvas.h>
#include <FGrpColor.h>
#include <FGrpPoint.h>
#include <FGrpRectangle.h>
#include <FUiIFocusEventListener.h>
#include <FUiIKeyEventListener.h>
#include <FUiITouchEventListener.h>
#include <FUiITouchModeChangedEventListener.h>
#include <FUiIDragDropEventListener.h>
#include <FUiIDragDropEventListenerF.h>
#include <FUiCompositeMode.h>
#include <FUiIPropagatedKeyEventListener.h>
#include <FUiIPropagatedTouchEventListener.h>

namespace Tizen { namespace Ui { namespace Animations {
class ControlAnimator;
class VisualElement;
}}}

namespace Tizen { namespace Ui {

class AccessibilityContainer;
class Container;
class _ControlImpl;
class TouchGestureDetector;

/**
 * @class	Control
 * @brief	This class is the abstract base class of all the UI control classes.
 *
 * @since	2.0
 *
 * @remarks	In order for a control to be displayed, it must first be bound to a window of the underlying window system. The control's window is
 * created when it (or its ancestor) is added to a valid control containment hierarchy. A containment hierarchy is valid if and
 * only if the root of the hierarchy is an instance of the Window class.
 *
 * The %Control class is the abstract base class of all user interface elements. It encapsulates a
 * "window" of the underlying window system, and provides the infrastructure necessary for the
 * elements to respond to user inputs. The %Control class also determines how a key event is dispatched
 * and processed.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/controls.htm">UI Controls</a>.
 *
 *
 * The following examples demonstrate how to use the %Control class.
 *
 * Size and Position
 *
 * @code
 * // Sets the size
 * pControl->SetSize(100, 100); // 100 pixels wide and 100 pixels long
 *
 * // Sets the position
 * pControl->SetPosition(5, 5); // Control is drawn 5 pixels down and 5 pixels left from the top-left corner of its parent
 * @endcode
 *
 * Draw and Show
 *
 * @code
 * // Gets a instance of Canvas
 * Canvas* pCanvas = pControl->GetCanvasN();
 *
 * // Fills the canvas with white color
 * pCanvas->Clear(Tizen::Graphics::Color(255, 255, 255));
 *
 * // Shows changes on screen
 * pControl->Invalidate(true);
 *
 * delete pCanvas;
 * @endcode
 *
 * Key and input focus
 *
 * @code
 * // Implements MyKeyEventListener
 * IKeyEventListener* pKeyListener = new MyKeyEventListener();
 * pControl->SetFocus();
 *
 * // The added key listener should be deleted after use
 * pControl->AddKeyEventListener(*pKeyListener);
 * @endcode
 *
 */
class _OSP_EXPORT_ Control
	: public Tizen::Base::Object
{

public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Control(void);

	/**
	 * Adds the IFocusEventListener instance to the %Control instance. @n
	 * The added listener gets notified when the control gains or loses its focus.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @see			RemoveFocusEventListener()
	 */
	void AddFocusEventListener(IFocusEventListener& listener);

	/**
	 * Adds the IKeyEventListener instance to the %Control instance. @n
	 * The added listener gets notified when a key is pressed, released, or long pressed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener    The event listener to add
	 * @see			RemoveKeyEventListener()
	 */
	void AddKeyEventListener(IKeyEventListener& listener);

	/**
	 * Adds the ITouchEventListener instance to the %Control instance. @n
	 * The added listener gets notified when a touch event such as a press or a release is fired.
	 *
	 * @since		 2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @see			RemoveTouchEventListener()
	 */
	void AddTouchEventListener(ITouchEventListener& listener);

	/**
	 * Adds the ITouchModeChangedEventListener instance to the %Control instance. @n
	 * The added listener gets notified when the device's touch mode is changed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @see			RemoveTouchModeChangedEventListener()
	 */
	void AddTouchModeChangedEventListener(Tizen::Ui::ITouchModeChangedEventListener& listener);

	/**
	 * Adds the IDragDropEventListener instance to the %Control instance. @n
	 * The added listener gets notified when a drag or a drop happens in the control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @see			RemoveDragDropEventListener()
	 */
	void AddDragDropEventListener(IDragDropEventListener& listener);

	/**
	 * Adds the IDragDropEventListenerF instance to the %Control instance. @n
	 * The added listener gets notified when a drag or a drop happens in the control.
	 *
	 * @since		2.1
	 *
	 * @param[in]	listener	The event listener to add
	 * @see			RemoveDragDropEventListenerF()
	 */
	void AddDragDropEventListener(IDragDropEventListenerF& listener);

	/**
	 * Removes the focus listener instance. @n
	 * The removed listener is not notified even when focus events are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to remove
	 * @see			AddFocusEventListener()
	 */
	void RemoveFocusEventListener(IFocusEventListener& listener);

	/**
	 * Removes the key event listener instance. @n
	 * The removed listener is not notified even when key events are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to remove
	 * @see			AddKeyEventListener()
	 */
	void RemoveKeyEventListener(IKeyEventListener& listener);

	/**
	 * Removes the touch event listener instance. @n
	 * The removed listener is not notified even when touch events are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to remove
	 * @see			AddTouchEventListener()
	 */
	void RemoveTouchEventListener(ITouchEventListener& listener);

	/**
	 * Removes the touch mode changed event listener instance. @n
	 * The removed listener is not notified even when the touch mode changed events are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to remove
	 * @see			AddTouchModeChangedEventListener()
	 */
	void RemoveTouchModeChangedEventListener(Tizen::Ui::ITouchModeChangedEventListener& listener);

	/**
	 * Adds the IDragDropEventListener instance to the %Control instance. @n
	 * The added listener gets notified when a drag or a drop happens in the control.
	 *
	 * @since		 2.0
	 *
	 * @param[in]	listener	The event listener to add
	 * @see			Tizen::Ui::IDragDropEventListener::OnTouchDragged()
	 * @see			Tizen::Ui::IDragDropEventListener::OnTouchDropped()
	 * @see			RemoveDragDropEventListener()
	 */
	void RemoveDragDropEventListener(IDragDropEventListener& listener);

	/**
	 * Adds the IDragDropEventListenerF instance to the %Control instance. @n
	 * The added listener gets notified when a drag or a drop happens in the control.
	 *
	 * @since		 2.1
	 *
	 * @param[in]	listener	The event listener to add
	 * @see			Tizen::Ui::IDragDropEventListenerF::OnTouchDraggedF()
	 * @see			Tizen::Ui::IDragDropEventListenerF::OnTouchDroppedF()
	 * @see			RemoveDragDropEventListenerF()
	 */
	void RemoveDragDropEventListenerF(IDragDropEventListenerF& listener);

	/**
	 * Overrides this method to provide user-specific initialization code before the control is added to a container.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_FAILURE	The method has failed.
	 * @remarks		This method is called when the control is about to be added to a container.
	 * @remarks		To cancel adding this control to the parent, return @c E_FAILURE in this method.
	 * @see			OnTerminating()
	 */
	virtual result OnInitializing(void);

	/**
	 * Overrides this method to provide user-specific termination code.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_FAILURE	The method has failed.
	 * @remarks
	 *             - This method is called right before the control is removed from the container, or Destroy() method is called.
	 * 		       - To cancel the removal or Destroy() operation, return any exception other than @c E_SUCCESS.
	 * @see			OnInitializing()
	 */
	virtual result OnTerminating(void);

	/**
	 */

	/**
	 * Called asynchronously when the user event that is sent by SendUserEvent() method is
	 * dispatched to the control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	requestId	The user-defined event ID
	 * @param[in]	pArgs  A pointer to the argument list
	 * @see			SendUserEvent()
	 */
	virtual void OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs);

	/**
	 * Deallocates this instance after removing all child controls of this control.
	 *
	 * @since 2.1
	 *
	 * @exception	E_SUCCESS	The method is successful.
	 * @remarks		The control is deleted from memory. Before it is deleted, OnTerminating() is called if it is attached to the main tree.
	 * @remarks		If OnTerminating() method is overridden and returns an exception, that exception is propagated.
	 * @see			Tizen::Ui::Control:OnTerminating()
	 */
	result Destroy(void);

	/**
	 * Checks whether the control is movable.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the control is movable, @n
	 *				else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		When control is not movable SetPosition() and SetBounds() return @c E_UNSUPPORTED_OPERATION.
	 * @see			SetPosition()
	 * @see			SetBounds()
	 */
	bool IsMovable(void) const;

	/**
	 * Checks whether the control is resizable.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the control is resizable, @n
	 *				else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		Even if this method returns @c true, the size can be changed internally.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		When control is not resizable,
	 *				SetSize(), SetBounds(), SetMinimumSize() and SetMaximumSize() return @c E_UNSUPPORTED_OPERATION.
	 * @see			SetSize()
	 * @see			SetBounds()
	 * @see			SetMinimumSize()
	 * @see			SetMaximumSize()
	 */
	bool IsResizable(void) const;

	/**
	 * Gets the position and the size of the control.
	 *
	 * @since		2.0
	 *
	 * @return		An instance of the Tizen::Graphics::Rectangle that represents the position of top-left corner,
	 *				the width, and the height of the control
	 * @remarks		The shape of the control is rectangular that is defined by the top-left point,
	 *				and the width or height. The position
	 *				of the top-left point is relative to the top-left corner of the parent container.
	 * @see			SetBounds()
	 */
	Tizen::Graphics::Rectangle GetBounds(void) const;

	/**
	 * Gets the position and the size of the control.
	 *
	 * @since		2.1
	 *
	 * @return		An instance of the Tizen::Graphics::FloatRectangle that represents the position of top-left corner,
	 *				the width, and the height of the control
	 * @remarks		The shape of the control is rectangular that is defined by the top-left point,
	 *				and the width or height. The position
	 *				of the top-left point is relative to the top-left corner of the parent container.
	 * @see			SetBounds()
	 */
	Tizen::Graphics::FloatRectangle GetBoundsF(void) const;

	/**
	 * Gets the position and the size of the control.
	 *
	 * @since		2.0
	 *
	 * @param[out]	x		The x position of top-left corner of the control
	 * @param[out]	y		The y position of top-left corner of the control
	 * @param[out]	width	The width of the rectangular region
	 * @param[out]	height	The height of the rectangular region
	 * @remarks		The shape of the control is regarded as a rectangle that is defined
	 *				by the top-left point and the width or height.
	 *				The position of the top-left point is relative to the top-left corner of
	 *				the parent container.
	 * @see			SetBounds()
	 */
	void GetBounds(int& x, int& y, int& width, int& height) const;

	/**
	 * Gets the position and the size of the control.
	 *
	 * @since		2.1
	 *
	 * @param[out]	x		The x position of top-left corner of the control
	 * @param[out]	y		The y position of top-left corner of the control
	 * @param[out]	width	The width of the rectangular region
	 * @param[out]	height	The height of the rectangular region
	 * @remarks		The shape of the control is regarded as a rectangle that is defined
	 *				by the top-left point and the width or height.
	 *				The position of the top-left point is relative to the top-left corner of
	 *				the parent container.
	 * @see			SetBounds()
	 */
	void GetBounds(float& x, float& y, float& width, float& height) const;

	/**
	 * Gets the position of the control's top-left corner.
	 *
	 * @since		2.0
	 *
	 * @return		The position of the control's top-left corner
	 * @remarks		The position of top-left corner is relative to the top-left corner of its parent container.
	 * @see			GetBounds()
	 */
	Tizen::Graphics::Point GetPosition(void) const;

	/**
	 * Gets the position of the control's top-left corner.
	 *
	 * @since		2.1
	 *
	 * @return		The position of the control's top-left corner
	 * @remarks		The position of top-left corner is relative to the top-left corner of its parent container.
	 * @see			GetBounds()
	 */
	Tizen::Graphics::FloatPoint GetPositionF(void) const;

	/**
	 * Gets the position of the control's top-left corner.
	 *
	 * @since		2.0
	 *
	 * @param[out]	x The x position of the control's top-left corner
	 * @param[out]	y The y position of the control's top-left corner
	 * @remarks		The position of top-left corner is relative to the top-left corner of its parent container.
	 * @see			GetBounds()
	 */
	void GetPosition(int& x, int& y) const;

	/**
	 * Gets the position of the control's top-left corner.
	 *
	 * @since		2.1
	 *
	 * @param[out]	x The x position of the control's top-left corner
	 * @param[out]	y The y position of the control's top-left corner
	 * @remarks		The position of top-left corner is relative to the top-left corner of its parent container.
	 * @see			GetBounds()
	 */
	void GetPosition(float& x, float& y) const;

	/**
	 * Gets the size of the control.
	 *
	 * @since		2.0
	 *
	 * @return		The size of the control
	 * @see			GetBounds()
	 */
	Tizen::Graphics::Dimension GetSize(void) const;

	/**
	 * Gets the size of the control.
	 *
	 * @since		2.1
	 *
	 * @return		The size of the control
	 * @see			GetBounds()
	 */
	Tizen::Graphics::FloatDimension GetSizeF(void) const;

	/**
	 * Gets the size of the control.
	 *
	 * @since		2.0
	 *
	 * @param[out]	width	The width of the control
	 * @param[out]	height	The height of the control
	 * @see         GetBounds()
	 */
	void GetSize(int& width, int& height) const;

	/**
	 * Gets the size of the control.
	 *
	 * @since		2.1
	 *
	 * @param[out]	width	The width of the control
	 * @param[out]	height	The height of the control
	 * @see         GetBounds()
	 */
	void GetSize(float& width, float& height) const;

	/**
	 * Gets the x position of the control. @n
	 * The position of control is relative to the top-left corner of its parent container.
	 *
	 * @since		2.0
	 *
	 * @return		The x position of the control
	 * @see			GetBounds()
	 * @see			GetPosition()
	 * @see			GetY()
	 */
	int GetX(void) const;

	/**
	 * Gets the x position of the control. @n
	 * The position of control is relative to the top-left corner of its parent container.
	 *
	 * @since		2.1
	 *
	 * @return		The x position of the control
	 * @see			GetBounds()
	 * @see			GetPosition()
	 * @see			GetYF()
	 */
	float GetXF(void) const;

	/**
	 * Gets the y position of the control. @n
	 * The position of control is relative to the top-left corner of its parent container.
	 *
	 * @since		2.0
	 *
	 * @return		The y position of the control
	 * @see			GetBounds()
	 * @see			GetPosition()
	 * @see			Get()
	 */
	int GetY(void) const;

	/**
	 * Gets the y position of the control. @n
	 * The position of control is relative to the top-left corner of its parent container.
	 *
	 * @since		2.1
	 *
	 * @return		The y position of the control
	 * @see			GetBounds()
	 * @see			GetPosition()
	 * @see			GetXF()
	 */
	float GetYF(void) const;

	/**
	 * Gets the width of the control.
	 *
	 * @since		2.0
	 *
	 * @return		The width of the control
	 * @see			GetBounds()
	 * @see			GetSize()
	 * @see			GetHeight()
	 */
	int GetWidth(void) const;

	/**
	 * Gets the width of the control.
	 *
	 * @since		2.1
	 *
	 * @return		The width of the control
	 * @see			GetBounds()
	 * @see			GetSizeF()
	 * @see			GetHeightF()
	 */
	float GetWidthF(void) const;

	/**
	 * Gets the height of the control.
	 *
	 * @since		2.0
	 *
	 * @return		The height of the control
	 * @see			GetBounds()
	 * @see			GetSize()
	 * @see			GetWidth()
	 */
	int GetHeight(void) const;

	/**
	 * Gets the height of the control.
	 *
	 * @since		2.1
	 *
	 * @return		The height of the control
	 * @see			GetBounds()
	 * @see			GetSizeF()
	 * @see			GetWidthF()
	 */
	float GetHeightF(void) const;

	/**
	 * Gets the minimum size of the control.
	 *
	 * @since		2.0
	 *
	 * @return		The minimum size of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The first call of the method returns the system-defined minimum size.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Dimension GetMinimumSize(void) const;

	/**
	 * Gets the minimum size of the control.
	 *
	 * @since		2.1
	 *
	 * @return		The minimum size of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The first call of the method returns the system-defined minimum size.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::FloatDimension GetMinimumSizeF(void) const;

	/**
	 * Gets the maximum size of the control.
	 *
	 * @since		2.0
	 *
	 * @return		The maximum size of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The first call of the method returns the system-defined maximum size.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Dimension GetMaximumSize(void) const;

	/**
	 * Gets the maximum size of the control.
	 *
	 * @since		2.1
	 *
	 * @return		The maximum size of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The first call of the method returns the system-defined maximum size.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::FloatDimension GetMaximumSizeF(void) const;

	/**
	 * Gets a font of the control.
	 *
	 * @since 2.0
	 *
	 * @return                   The font name set in the control  @n
	 *                                         else an empty string if the font is not set
	 * @see         SetFont()
	 */
	Tizen::Base::String GetFont(void) const;

	/**
	 * Sets the position and size of the control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect					The new bounds of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_OPERATION		The control has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		The size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			IsMovable()
	 * @see			IsResizable()
	 * @see			GetMinimumSize()
	 * @see			GetMaximumSize()
	 * @see			SetPosition()
	 * @see			SetSize()
	 */
	result SetBounds(const Tizen::Graphics::Rectangle& rect);

	/**
	 * Sets the position and size of the control.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect					The new bounds of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_OPERATION		The control has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		The size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			IsMovable()
	 * @see			IsResizable()
	 * @see			GetMinimumSize()
	 * @see			GetMaximumSize()
	 * @see			SetPosition()
	 * @see			SetSiz()
	 */
	result SetBounds(const Tizen::Graphics::FloatRectangle& rect);

	/**
	 * Sets the position and size of the control. @n
	 * The position is set at (x, y), and the @c width and @c height parameters contain
	 * the width and height values of the object, respectively.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	x						The new x position of the control
	 * @param[in]	y						The new y position of the control
	 * @param[in]	width					The new width of the control
	 * @param[in]	height					The new height of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_OPERATION		The control has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		The size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			IsMovable()
	 * @see			IsResizable()
	 * @see			GetMinimumSize()
	 * @see			GetMaximumSize()
	 * @see			SetPosition()
	 * @see			SetSize()
	 */
	result SetBounds(int x, int y, int width, int height);

	/**
	 * Sets the position and size of the control. @n
	 * The position is set at (x, y), and the @c width and @c height parameters contain
	 * the width and height values of the object, respectively.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	x						The new x position of the control
	 * @param[in]	y						The new y position of the control
	 * @param[in]	width					The new width of the control
	 * @param[in]	height					The new height of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_OPERATION		The control has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is neither movable nor resizable.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		The size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			IsMovable()
	 * @see			IsResizable()
	 * @see			GetMinimumSize()
	 * @see			GetMaximumSize()
	 * @see			SetPosition()
	 * @see			SetSize()
	 */
	result SetBounds(float x, float y, float width, float height);

	/**
	 * Sets the relative position of the control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	position				The new position
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_OPERATION		The control has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is not movable.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		The position of the control are relative to the top-left corner of its parent.
	 * @see			IsMovable()
	 * @see			SetBounds()
	 */
	result SetPosition(const Tizen::Graphics::Point& position);

	/**
	 * Sets the relative position of the control.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	position				The new position
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_OPERATION		The control has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is not movable.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		The position of the control are relative to the top-left corner of its parent.
	 * @see			IsMovable()
	 * @see			SetBounds()
	 */
	result SetPosition(const Tizen::Graphics::FloatPoint& position);

	/**
	 * Sets the position of the control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[in]	x						The new x position of the control
	 * @param[in]	y						The new y position of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_OPERATION		The control has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is not movable.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		The x,y position of the control are relative to the top-left corner of its parent.
	 * @see			IsMovable()
	 * @see			SetBounds()
	 */
	result SetPosition(int x, int y);

	/**
	 * Sets the position of the control.
	 *
	 * @since		2.1
	 * @return		An error code
	 * @param[in]	x						The new x position of the control
	 * @param[in]	y						The new y position of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_INVALID_OPERATION		The control has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is not movable.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		The x,y position of the control are relative to the top-left corner of its parent.
	 * @see			IsMovable()
	 * @see			SetBounds()
	 */
	result SetPosition(float x, float y);

	/**
	 * Sets the size of the control. @n
	 * The @c width and @c height parameters contain the width and height values of the object, respectively.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	size					The new width and height
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The control has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is not resizable.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		The size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			IsResizable()
	 * @see			GetMinimumSize()
	 * @see			GetMaximumSize()
	 * @see			SetBounds()
	 */
	result SetSize(const Tizen::Graphics::Dimension& size);

	/**
	 * Sets the size of the control.
	 * The @c width and @c height parameters contain the width and height values of the object, respectively.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	size					The new width and height
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The control has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is not resizable.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		The size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			IsResizable()
	 * @see			GetMinimumSize()
	 * @see			GetMaximumSize()
	 * @see			SetBounds()
	 */
	result SetSize(const Tizen::Graphics::FloatDimension& size);

	/**
	 * Sets the size of the control. @n
	 * The @c width and @c height parameters contain the width and height values of the object, respectively.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	width					The new width of the control
	 * @param[in]	height					The new height of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The control has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is not resizable.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		The size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			IsResizable()
	 * @see			GetMinimumSize()
	 * @see			GetMaximumSize()
	 * @see			SetBounds()
	 */
	result SetSize(int width, int height);

	/**
	 * Sets the size of the control.
	 * The @c width and @c height parameters contain the width and height values of the object, respectively.
	 *
	 * @since	2.1
	 *
	 * @return		An error code
	 * @param[in]	width					The new width of the control
	 * @param[in]	height					The new height of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The control has not been constructed as yet.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is not resizable.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		The size of the control must be within the range defined by the minimum size and the maximum size.
	 * @see			IsResizable()
	 * @see			GetMinimumSize()
	 * @see			GetMaximumSize()
	 * @see			SetBounds()
	 */
	result SetSize(float width, float height);

	/**
	 * Sets the minimum size of the control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	newMinDim				The new minimum size of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is not resizable.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		This method can affect the maximum size and the current size of the control. @n
	 *				The control needs to be redrawn to reflect the change in its size. @n
	 *				If the current maximum size or the control size is smaller than the new minimum size,
	 *				it becomes the same as the new minimum size.
	 * @see			IsResizable()
	 */
	result SetMinimumSize(const Tizen::Graphics::Dimension& newMinDim);

	/**
	 * Sets the minimum size of the control.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	newMinDim				The new minimum size of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is not resizable.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		This method can affect the maximum size and the current size of the control. @n
	 *				The control needs to be redrawn to reflect the change in its size. @n
	 *				If the current maximum size or the control size is smaller than the new minimum size,
	 *				it becomes the same as the new minimum size.
	 * @see			IsResizable()
	 */
	result SetMinimumSize(const Tizen::Graphics::FloatDimension& newMinDim);

	/**
	 * Sets the maximum size of the control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	newMaxDim					The new maximum size of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is not resizable.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		This method can affect the minimum size and the current size of the control. @n
	 *				The control needs to be redrawn to reflect the change in its size. @n
	 *				If the current minimum size or the control size is greater than the new maximum size,
	 *				it becomes the same as the new maximum size.
	 * @see			IsResizable()
	 */
	result SetMaximumSize(const Tizen::Graphics::Dimension& newMaxDim);

	/**
	 * Sets the maximum size of the control.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	newMaxDim					The new maximum size of the control
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	This control is not resizable.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		This method can affect the minimum size and the current size of the control. @n
	 *				The control needs to be redrawn to reflect the change in its size. @n
	 *				If the current minimum size or the control size is greater than the new maximum size,
	 *				it becomes the same as the new maximum size.
	 * @see			IsResizable()
	 */
	result SetMaximumSize(const Tizen::Graphics::FloatDimension& newMaxDim);

	/**
	 * Converts the specified screen position to the position in control's coordinate system.
	 *
	 * @since 2.0
	 *
	 * @return	The position relative to the top-left corner of the control's client-area
	 * @param[in]	screenPosition	The position relative to the top-left corner of the screen
	 * @see		ConvertToScreenPosition()
	 */
	Tizen::Graphics::Point ConvertToControlPosition(const Tizen::Graphics::Point& screenPosition) const;

	/**
	 * Converts the specified screen position to the position in control's coordinate system.
	 *
	 * @since 2.1
	 *
	 * @return	The position relative to the top-left corner of the control's client-area
	 * @param[in]	screenPosition	The position relative to the top-left corner of the screen
	 * @see		ConvertToScreenPosition()
	 */
	Tizen::Graphics::FloatPoint ConvertToControlPosition(const Tizen::Graphics::FloatPoint& screenPosition) const;

	/**
	 * Converts the specified position in the control's coordinate system to the screen position.
	 *
	 * @since 2.0
	 *
	 * @return      The position relative to the top-left corner of the screen
	 * @param[in]   controlPosition		The position relative to the top-left corner of the control's client-area
	 * @see         ConvertToControlPosition()
	 */
	Tizen::Graphics::Point ConvertToScreenPosition(const Tizen::Graphics::Point& controlPosition) const;

	/**
	 * Converts the specified position in the control's coordinate system to the screen position.
	 *
	 * @since 2.1
	 *
	 * @return      The position relative to the top-left corner of the screen
	 * @param[in]   controlPosition		The position relative to the top-left corner of the control's client-area
	 * @see         ConvertToControlPosition()
	 */
	Tizen::Graphics::FloatPoint ConvertToScreenPosition(const Tizen::Graphics::FloatPoint& controlPosition) const;

	/**
	 * Sets the font of the control.
	 *
	 * @since 2.0
	 *
	 * @return	An error code
	 * @param[in]	fontName			The app font name or system font name @n
	 *						The app font name is retrieved using Tizen::Graphics::Font::GetFaceName(Tizen::Base::String& filepath). @n
	 *						The system font name is retrieved using Tizen::Graphics::Font::GetSystemFontListN().
	 *						Sets an empty string to reset.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_FILE_NOT_FOUND		The specified font cannot be found or accessed.
	 * @remarks	At first, the value of @c fontName is considered app font name if it matches one of the face names of the font files which are located in @b '/res/font'.
	 *		If not, the value of @c fontName is considered system font name if it matches one of the retrieved values using Tizen::Graphics::Font::GetSystemFontListN().
	 * @remarks	The control first attempts to find the control font. If it fails, then it searches for the application default font and the system font, in sequence.
	 * @see		GetFont()
	 */
	result SetFont(const Tizen::Base::String& fontName);

	/**
	 * Checks whether the specified @c point is inside the control.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the specified @c point is inside the control, @n
	 *				else @c false
	 * @param[in]	point The point to check
	 * @remarks		The specified @c point must be defined relative to the top-left corner of the control.
	 */
	bool Contains(const Tizen::Graphics::Point& point) const;

	/**
	 * Checks whether the specified @c point is inside the control.
	 *
	 * @since		2.1
	 *
	 * @return		@c true if the specified @c point is inside the control, @n
	 *				else @c false
	 * @param[in]	point The point to check
	 * @remarks		The specified @c point must be defined relative to the top-left corner of the control.
	 */
	bool Contains(const Tizen::Graphics::FloatPoint& point) const;

	/**
	 * Checks whether the specified point is inside the control.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the specified point is inside the control, @n
	 *				else @c false
	 * @param[in]	x The x position of the point to check
	 * @param[in]	y The y position of the point to check
	 * @remarks		The specified point must be defined relative to the top-left corner of the control.
	 */
	bool Contains(int x, int y) const;

	/**
	 * Checks whether the specified point is inside the control.
	 *
	 * @since		2.1
	 *
	 * @return		@c true if the specified point is inside the control, @n
	 *				else @c false
	 * @param[in]	x The x position of the point to check
	 * @param[in]	y The y position of the point to check
	 * @remarks		The specified point must be defined relative to the top-left corner of the control.
	 */
	bool Contains(float x, float y) const;

	/**
	 * Draws child controls recursively.
	 *
	 * @since                    2.0
	 *
	 * @return                  An error code
	 * @exception    E_SUCCESS           The method is successful.
	 * @exception    E_INVALID_OPERATION    The current state of the instance prohibits the execution of the specified operation. @n
	 *                                                                                             Note: This control cannot be displayed.
	 * @exception    E_SYSTEM                              A system error has occurred.
	 * @remarks	This method calls OnDraw() immediately in a synchronous way.
	 * @see                      Show()
	 */
	result Draw(void);

	/**
	 */

	/**
	 * Draws the control.
	 *
	 * @since 2.0
	 *
	 * @param[in]	recursive		Set to @c true to draw child controls recursively, @n
	 *										else @c false
	 * @return	An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *		Note: This control cannot be displayed.
	 * @exception	E_SYSTEM                              A system error has occurred.
	 * @remarks	This method calls OnDraw() immediately in a synchronous way.
	 * @see		Show()
	 */
	result Draw(bool recursive);

	/**
	 * Shows the control on the screen.
	 *
	 * @since		2.0
	 * @final	Although this method is virtual, it should not be overridden.
     * If overridden, it may not work as expected.
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									Note: This control cannot be displayed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		Do not override this method.
	 */
	virtual result Show(void);

	/**
	 * Invalidates the control.
	 *
	 * @since 2.0
	 *
	 * @param[in]	recursive	Set to @c true to invalidate child controls recursively, @n
	 *							else @c false
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									Note: This control cannot be displayed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		OnDraw() is not called immediately, but called asynchronously just before the screen is updated.
	 * @see 		InvalidateBounds()
	 * @see 		Show()
	 */
	void Invalidate(bool recursive);

	/**
	 * Invalidates the control of the specified position and size.
	 *
	 * @since 2.0
	 *
	 * @param[in]    bounds                 The position relative to the top-left corner of the control
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation. @n
	 *                                                                                             Note: This control cannot be displayed.
	 * @remarks  The specific error code can be accessed using the GetLastResult() method.
	 * @see 		Invalidate()
	 * @see 		Show()
	 */
	void InvalidateBounds(const Tizen::Graphics::Rectangle& bounds);

	/**
	 * Invalidates the control of the specified position and size.
	 *
	 * @since 2.1
	 *
	 * @param[in]    bounds                 The position relative to the top-left corner of the control
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation. @n
	 *                                                                                             Note: This control cannot be displayed.
	 * @remarks  The specific error code can be accessed using the GetLastResult() method.
	 * @see 		Invalidate()
	 * @see 		Show()
	 */
	void InvalidateBounds(const Tizen::Graphics::FloatRectangle& bounds);

	/**
	 * Draws the control asynchronously.
	 *
	 * @since		2.0
	 *
	 * @param[in]	show	Set to @c true to also show the %Control, @n
	 * 						else @c false
	 * @remarks		This method posts a draw event in the event queue. @n
	 *				Drawing requested by %RequestRedraw() occurs when the draw event is fired to the control.
	 */
	void RequestRedraw(bool show = true) const;

	/**
	 * Creates and returns a graphics canvas whose bounds (that is, position and size) are equal to those
	 * of the control.
	 *
	 * @since		2.0
	 *
	 * @return		The graphic canvas of the control, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @remarks		The method allocates a Tizen::Graphics::Canvas whose bounds are equal to that of the control.
	 *				It is the developer's responsibility to deallocate the canvas after use.
	 *				The canvas is guaranteed to be valid only if the properties of the parent controls of the canvas remain unchanged.
	 *				Therefore, one must delete previously allocated canvas and create a new canvas using the %GetCanvasN() method
	 *				if the size or position of the control is changed.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The Frame and Form (and between different Form instances) share a single frame-buffer. Therefore,
	 *				if custom drawing is performed on the graphic canvas of Frame and Form
	 *				then it will appear on the screen regardless of which control is currently visible on the screen.
	 * @see			GetCanvasN(const Tizen::Graphics::Rectangle& bounds) const
	 * @see			GetCanvasN(int x, int y, int width, int height) const
	 * @code
	 * result
	 * MyForm::OnDraw(void)
	 * {
	 *     result r = E_SUCCESS;
	 *     Canvas* pCanvas = GetCanvasN();
	 *     if (pCanvas != null)
	 *     {
	 *         // add your drawing code here
	 *     }
	 *     if (pCanvas)
	 *         delete pCanvas;
	 *         // Do not call Show(). It will be called automatically after OnDraw() callback.
	 *     return r;
	 * }
	 * @endcode
	 */
	Tizen::Graphics::Canvas* GetCanvasN(void) const;

	/**
	 * Creates and returns a graphic canvas of the control of the specified position and size.
	 *
	 * @since		2.0
	 *
	 * @return		The graphic canvas of the control, @n
	 *				else @c null if an exception occurs
	 * @param[in]	bounds		The bounds of the graphic canvas
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified bounds does not intercept with the bounds of the control.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @remarks		Only the graphic canvas of displayable controls can be obtained.
	 *				If the specified area is not inside the control,
	 *				the graphics canvas of overlapped area between the control and the specified bound is returned. @n
	 * @remarks		The method allocates an Tizen::Graphics::Canvas whose bounds are equal to that of the control.
	 *				It is the developer's responsibility to deallocate the canvas after use.
	 *				The canvas is guaranteed to be valid only if the properties of the parent controls of the canvas remain unchanged.
	 *				Therefore, one must delete previously allocated canvas and create a new canvas using the %GetCanvasN() method
	 *				if the size or position of the control is changed.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The Frame and Form (and between different Form instances) share a single frame-buffer. Therefore,
	 *				if custom drawing is performed on the graphic canvas of Frame and Form
	 *				then it will appear on the screen regardless of which control is currently visible on the screen.
	 * @see			GetCanvasN(void) const
	 * @see			GetCanvasN(int x, int y, int width, int height) const
	 */
	Tizen::Graphics::Canvas* GetCanvasN(const Tizen::Graphics::Rectangle& bounds) const;

	/**
	 * Creates and returns a graphic canvas of the control of the specified position and size.
	 *
	 * @since		2.1
	 *
	 * @return		The graphic canvas of the control, @n
	 *				else @c null if an exception occurs
	 * @param[in]	bounds		The bounds of the graphic canvas
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified bounds does not intercept with the bounds of the control.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @remarks		Only the graphic canvas of displayable controls can be obtained.
	 *				If the specified area is not inside the control,
	 *				the graphics canvas of overlapped area between the control and the specified bound is returned. @n
	 * @remarks		The method allocates an Tizen::Graphics::Canvas whose bounds are equal to that of the control.
	 *				It is the developer's responsibility to deallocate the canvas after use.
	 *				The canvas is guaranteed to be valid only if the properties of the parent controls of the canvas remain unchanged.
	 *				Therefore, one must delete previously allocated canvas and create a new canvas using the %GetCanvasN() method
	 *				if the size or position of the control is changed.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The Frame and Form (and between different Form instances) share a single frame-buffer. Therefore,
	 *				if custom drawing is performed on the graphic canvas of Frame and Form
	 *				then it will appear on the screen regardless of which control is currently visible on the screen.
	 * @see			GetCanvasN(void) const
	 * @see			GetCanvasN(float x, float y, float width, float height) const
	 */
	Tizen::Graphics::Canvas* GetCanvasN(const Tizen::Graphics::FloatRectangle& bounds) const;

	/**
	 * Creates and returns a graphic canvas of the specified position and size in the control.
	 *
	 * @since		2.0
	 *
	 * @return		The graphic canvas of the control, @n
	 *				else @c null if an exception occurs
	 * @param[in]	x  The x position relative to the top-left corner of the control
	 * @param[in]	y  The y position relative to the top-left corner of the control
	 * @param[in]	width   The width of a graphic canvas
	 * @param[in]	height  The height of a graphic canvas
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified bounds do not intercept with the bounds of the control.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @remarks		Only the graphic canvas of displayable controls can be obtained.
	 *				If the specified area is not inside the control,
	 *				the graphics canvas of the overlapped area between the control and the specified bound is returned. @n
	 * @remarks		The method allocates an Tizen::Graphics::Canvas whose bounds are equal to that of the control.
	 *				It is the developer's responsibility to deallocate the canvas after use.
	 *				The canvas is guaranteed to be valid only if properties of the parent controls of the canvas remain unchanged.
	 *				Therefore, one must delete the previously allocated canvas and create a new canvas using the %GetCanvasN() method
	 *				if the size or position of the control is changed.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The Frame and Form (and between different Form instances) share a single frame-buffer. Therefore,
	 *				if custom drawing is performed on the graphic canvas of Frame and Form
	 *				then it will appear on the screen regardless of which control is currently visible on the screen.
	 * @see			GetCanvasN(void) const
	 * @see			GetCanvasN(const Tizen::Graphics::Rectangle& bounds) const
	 */
	Tizen::Graphics::Canvas* GetCanvasN(int x, int y, int width, int height) const;

	/**
	 * Creates and returns a graphic canvas of the specified position and size in the control.
	 *
	 * @since		2.1
	 *
	 * @return		The graphic canvas of the control, @n
	 *				else @c null if an exception occurs
	 * @param[in]	x  The x position relative to the top-left corner of the control
	 * @param[in]	y  The y position relative to the top-left corner of the control
	 * @param[in]	width   The width of a graphic canvas
	 * @param[in]	height  The height of a graphic canvas
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified bounds do not intercept with the bounds of the control.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @remarks		Only the graphic canvas of displayable controls can be obtained.
	 *				If the specified area is not inside the control,
	 *				the graphics canvas of the overlapped area between the control and the specified bound is returned. @n
	 * @remarks		The method allocates an Tizen::Graphics::Canvas whose bounds are equal to that of the control.
	 *				It is the developer's responsibility to deallocate the canvas after use.
	 *				The canvas is guaranteed to be valid only if properties of the parent controls of the canvas remain unchanged.
	 *				Therefore, one must delete the previously allocated canvas and create a new canvas using the %GetCanvasN() method
	 *				if the size or position of the control is changed.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		The Frame and Form (and between different Form instances) share a single frame-buffer. Therefore,
	 *				if custom drawing is performed on the graphic canvas of Frame and Form
	 *				then it will appear on the screen regardless of which control is currently visible on the screen.
	 * @see			GetCanvasN(void) const
	 * @see			GetCanvasN(const Tizen::Graphics::FloatRectangle& bounds) const
	 */
	Tizen::Graphics::Canvas* GetCanvasN(float x, float y, float width, float height) const;

	/**
	 * Checks whether the control is currently visible on the screen.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the control is currently visible on the screen, @n
	 *				else @c false
	 * @remarks		If this method is called before the control is added to a parent, @c false is returned.
	 * @see			GetShowState()
	 * @see			SetShowState()
	 */
	bool IsVisible(void) const;

	/**
	 * Gets the current show state of the control.
	 *
	 * @since		2.0
	 *
	 * @return		The show state of the control
	 * @remarks		Even if the control's state is "show", the control may not be visible.
	 * @see			SetShowState()
	 * @see			IsVisible()
	 */
	bool GetShowState(void) const;

	/**
	 * Sets the show state of the control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	state				The new show state
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 *									Note: This control cannot be displayed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		Do not override this method.
	 * @remarks		Even if this method is invoked, the control is not drawn or shown. @n
	 *				To display the control, use the Invalidate() methods. @n
	 *				Once the control's show state is set to @c false,
	 *				the show state needs to be set to @c true again before you invalidate the control.
	 * @see			GetShowState()
	 * @see			Invalidate()
	 */
	result SetShowState(bool state);

	/**
	 * Gets the dedicated %VisualElement instance for this control.
	 *
	 * @since		2.0
	 *
	 * @return		An instance of the VisualElement
	 * @remarks		If an application developer modifies the state of the returned VisualElement
	 *				and the host control is not aware of this change, then the control may behave egregiously.
	 *				It is highly recommended to restore the %VisualElement state to avoid such conflicts.
	 */
	Tizen::Ui::Animations::VisualElement* GetVisualElement(void) const;

	/**
	 * Gets the parent of the control.
	 *
	 * @since		2.0
	 *
	 * @return		The current parent of the control
	 */
	Container* GetParent(void) const;

	/**
	 * Gets the name of the control.
	 *
	 * @since		2.0
	 *
	 * @return		The name of the control
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * Sets the name of the control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	name	The name of the control
	 */
	void SetName(const Tizen::Base::String& name);

	/**
	 * Checks whether the control is focusable.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if control is focusable, @n
	 *				else @c false
	 * @remarks		The focus ability of the container classes like Panel is @c false by default.
	 */
	bool IsFocusable(void) const;

	/**
	 * Sets the focus ability of the control. @n
	 * Non-Focusable controls cannot take the key focus.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 *									Note: The control does not permit to change its focus ability.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The focus ability of the container classes like Panel is @c false by default.
	 * @remarks		The RadioGroup class does not render the UI.
	 *				Therefore, RadioGroup::SetFocusable() returns @c E_SYSTEM.
	 */
	result SetFocusable(bool focusable);

	/**
	 * Checks whether the control currently has the input focus.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the control currently has the input focus, @n
	 *				else @c false
	 * @remarks		If this method is called before the control is added to a parent, @c false is returned.
	 * @see			SetFocus()
	 */
	bool HasFocus(void) const;

	/**
	 * Sets the focus to the control. @n
	 * This method is called if the control needs to listen to user input events such as key pressed.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 *									Note: This control cannot be displayed.
	 * @exception	E_INVALID_CONDITION	The control is not contained in, or is not the top z-order frame or form.
	 * @remarks		Do not override this method.
	 */
	result SetFocus(void);

	/**
	 * Checks whether the control is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the control is enabled, @n
	 *				else @c false
	 * @remarks		If this method is called before the control is added to a parent, @c false is returned.
	 * @see			SetEnabled()
	 */
	bool IsEnabled(void) const;

	/**
	 * Enables or disables the control. @n
	 * Only an enabled control can respond to the user input. By default, the control is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	enable				The new state of the object
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		Do not override this method.
	 */
	result SetEnabled(bool enable);

	/**
	 * Checks whether the device is in touch mode. @n
	 * When the user interacts with the device by touching it, the device is in touch mode.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the device is in touch mode, @n
	 *				else @c false
	 * @remarks		This method returns @c false, for devices with QWERTY keyboard.
	 *				The user can navigate the UI using directional keys.
	 */
	bool IsInTouchMode(void) const;

	/**
	 * Enables or disables the drag operation in the %Control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable	Set to @c true to enable the drag operation, @n
	 *						else @c false
	 * @see			SetDropEnabled()
	 */
	void SetDragEnabled(bool enable);

	/**
	 * Enables or disables the drop operations in the %Control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable  Set to @c true to enable drop operations, @n
	 *				else @c false
	 * @remarks		To receive drop event, control's drag property has to be enabled.
	 * @see			SetDragEnabled()
	 */
	void SetDropEnabled(bool enable);

	/**
	 * Sends a user event to the control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	requestId The user-defined event ID
	 * @param[in]	pArgs  A pointer to the argument list
	 * @remarks		This method posts a user event in the event queue
	 *				and returns immediately to support asynchronous actions of the framework.
	 * @see			OnUserEventReceived()
	 */
	void SendUserEvent(RequestId requestId, const Tizen::Base::Collection::IList* pArgs) const;

	/**
	 * Stops the current UI event dispatch sequence by indicating the current input event is consumed.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated   This method is deprecated. Instead of using this method, use IPropagatedKeyEventListener or IPropagatedTouchEventListener to consume event. @n To propagate the event, return @c true inside the implementation of IPropagatedKeyEventListener or IPropagatedTouchEventListener.
	 * @since                  2.0
	 *
	 * @return                 An error code
	 * @exception E_SUCCESS                                   The method is successful.
	 * @exception E_SYSTEM                                     A system error has occurred.
	 * @remarks              If this method is invoked during an UI event (key or touch) propagation sequence,
	 *                                        the method will stop the propagation and consequently the system will not be notified of the event.@n
	 *                                        The method will not have any effect if no UI event is being dispatched. @n
	 *                                        It is recommended that this method is called within IKeyEventListener or
	 *                                        ITouchEventListener to stop the event from propagating to the next step.
	 */
	result ConsumeInputEvent(void);

	/**
	 * Gets the control animator of the current instance of %Control.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to ControlAnimator, @n
	 *				else @c null if this instance is not constructed or not added to a parent or non-animatable
	 */
	Tizen::Ui::Animations::ControlAnimator* GetControlAnimator(void) const;

	/**
	 * Adds the gesture detector to the %Control. @n
	 * The added gesture detector receives touch events prior to %Control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This API is deprecated.
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	gestureDetector					The gesture detector
	 * @exception 	E_SUCCESS			The method is successful.
	 * @see			RemoveGestureDetector()
	 */
	result AddGestureDetector(const TouchGestureDetector& gestureDetector);

	/**
	 * Adds a gesture detector to the %Control. @n
	 * The added gesture detector receives touch events prior to %Control.
	 *
	 * @since 2.1
	 *
	 * @return      An error code
	 * @param[in]   pGestureDetector         A pointer to gesture detector
	 * @exception   E_SUCCESS                The method is successful.
	 * @exception   E_INVALID_ARG            The specified @c pGestureDetector is @c null.
	 * @see		  RemoveGestureDetector()
	 */
	result AddGestureDetector(TouchGestureDetector* pGestureDetector);

	/**
	 * Removes the gesture detector from the %Control.
	 *
	 * @brief       <i> [Deprecated] </i>
	 * @deprecated  This API is deprecated.
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param[in]		gestureDetector		The gesture detector
	 * @exception 	E_SUCCESS			The method is successful.
	 * @see			AddGestureDetector()
	 */
	result RemoveGestureDetector(const TouchGestureDetector& gestureDetector);

	/**
	 * Removes a gesture detector from the %Control.
	 *
	 * @since 2.1
	 *
	 * @return      An error code
	 * @param[in]   pGestureDetector		A pointer to gesture detector
	 * @exception   E_SUCCESS              The method is successful.
	 * @exception   E_INVALID_ARG   		The specified @c pGestureDetector is @c null.
	 * @see         AddGestureDetector()
	 */
	result RemoveGestureDetector(TouchGestureDetector* pGestureDetector);

	/**
 	 * @if OSPDEPREC
	 * Gets the composite mode for merging with other controls.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because changing composition mode is not allowed any more.
	 * @since		2.0
	 *
	 * @return		The composite mode
	 * @exception	E_SUCCESS				The method is successful.
	 * @remarks		Since API version 2.1, this method only returns COMPOSITE_MODE_ALPHA_BLENDING.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Tizen::Ui::CompositeMode GetCompositeMode(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the composite mode for merging with other controls.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated  This method is deprecated because changing composition mode is not allowed any more.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	compositeMode			The composite mode
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported.
	 * @remarks	In Tizen, only @c COMPOSITE_MODE_ALPHA_BLENDING is allowed.
	 *		Otherwise, this method returns @c E_UNSUPPORTED_OPERATION.
 	 * @endif
	 */
	result SetCompositeMode(Tizen::Ui::CompositeMode compositeMode);

	/**
 	 * @if OSPDEPREC
	 * Gets the chroma key color value that is used for the control composition.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated because chromakey color is not supported any more.
	 * @since		2.0
	 *
	 * @return		The chroma key color
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported.
	 * @remarks	In Tizen, this method always fails and returns Tizen::Graphics::Color(0, 0, 0, 0).
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 * @endif
	 */
	Tizen::Graphics::Color GetChromaKeyColor(void) const;

	/**
	 * @if OSPDEPREC
	 * Sets the chroma key color value that is used for the control composition.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated because chromakey color is not supported any more.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	chromaKeyColor			The chroma key color
	 * @exception	E_UNSUPPORTED_OPERATION	The method is not supported.
	 * @remarks	In Tizen, this method always fails.
	 * @endif
	 */
	result SetChromaKeyColor(Tizen::Graphics::Color chromaKeyColor);

	/**
	 * Sets the bounds of the content area.
	 *
	 * @since                    2.1
	 *
	 * @param[in]    rect      The bounds of the content area
	 * @see                      GetContentAreaBounds()
	 */
	void SetContentAreaBounds(const Tizen::Graphics::Rectangle& rect);

	/**
	 * Sets the bounds of the content area.
	 *
	 * @since                    2.1
	 *
	 * @param[in]    rect      The bounds of the content area
	 * @see                      GetContentAreaBoundsF()
	 */
	void SetContentAreaBounds(const Tizen::Graphics::FloatRectangle& rect);

	/**
	 * Gets the bounds of the content area.
	 *
	 * @since                     2.1
	 *
	 * @return        The bounds of the content area
	 * @see                      SetContentAreaBounds()
	 */
	Tizen::Graphics::Rectangle GetContentAreaBounds(void) const;

	/**
	 * Gets the bounds of the content area.
	 *
	 * @since                     2.1
	 *
	 * @return        The bounds of the content area
	 * @see                      SetContentAreaBoundsF()
	 */
	Tizen::Graphics::FloatRectangle GetContentAreaBoundsF(void) const;

	/**
	 * Captures the composited scene of the %Panel control.
	 *
	 * @since		2.0
	 *
	 * @return		A Tizen::Graphics::Bitmap instance that captures the current composited scene of the Panel control, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION		This method is not supported.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		This method is not supported in the following class that is derived from Panel class:
	 *				@li OverlayPanel
	 * @remarks		The bounds of the %Panel control must be within the client area of the Form control to get a valid composited scene.
	 */
	Tizen::Graphics::Bitmap* GetCapturedBitmapN(void) const;

	/**
	 * Gets the position and the size of the invalidated bounds.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of Tizen::Graphics::Rectangle that represents the position of top-left corner,
	 *                                        the width, and the height of the invalidated bounds
	 */
	Tizen::Graphics::Rectangle GetInvalidatedBounds(void) const;

	/**
	 * Gets the position and the size of the invalidated bounds.
	 *
	 * @since 2.1
	 *
	 * @return		An instance of Tizen::Graphics::Rectangle that represents the position of top-left corner,
	 *                                        the width, and the height of the invalidated bounds
	 */
	Tizen::Graphics::FloatRectangle GetInvalidatedBoundsF(void) const;

	/**
	 * Enables or disables the multi-point touch of the %Control.
	 *
	 * @since 2.0
	 *
	 * @param[in]	enable				A Boolean flag indicating whether to enable the multi-point touch
	 *
 	 * @see			IsMultipointTouchEnabled()
	 */
	 void SetMultipointTouchEnabled(bool enable);

	/**
	 * Checks whether the multi-point touch is enabled.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the multi-point touch is enabled, @n
	 *				else @c false
	 * @see			SetMultipointTouchEnabled()
	 */
	bool IsMultipointTouchEnabled(void) const;

	/**
	 * Gets the accessibility container.
	 *
	 * @since 2.0
	 *
	 * @return		The accessibility container of the control, if the control supports accessibility feature, @n
	 *				else @c null
	 * @see			AccessibilityContainer::GetOwner()
	 */
	const AccessibilityContainer* GetAccessibilityContainer(void) const;

	/**
	 * Gets the accessibility container.
	 *
	 * @since 2.0
	 *
	 * @return		The accessibility container of the control, if the control supports accessibility feature, @n
	 *				else @c null
	 * @see			AccessibilityContainer::GetOwner()
	 */
	AccessibilityContainer* GetAccessibilityContainer(void);

	/**
	 * Sets a propagated touch event listener to the %Control instance. @n
	 * The registered listener is notified when a touch event occurs in the control. Using the propagated touch event listener, an application can control the touch event routing path.
	 *
	 * @since                    2.1
	 *
	 * @param[in]    pListener                                     The event listener to which the propagated touch events are dispatched
	 * @remarks The specified event listener should be allocated in heap memory.
	 *          To unregister the event listener, pass @c null to @c pListener.

	 */
	void SetPropagatedTouchEventListener(IPropagatedTouchEventListener* pListener);

	/**
	 * Sets a propagated key event listener to the %Control instance.
	 * The registered listener is notified when a key event occurs in the control. Using the propagated key event listener, an application can control the key event routing path.
	 *
	 * @since                    2.1
	 *
	 * @param[in]    pListener                                     The event listener to which the propagated touch events are dispatched
	 * @remarks The specified event listener should be allocated in heap memory.
	 *          To unregister the event listener, pass @c null to @c pListener.

	 */
	void SetPropagatedKeyEventListener(IPropagatedKeyEventListener* pListener);


	/**
	 * Sets the previous focus of the control.
	 *
	 * @since 2.1
	 *
	 * @param[in]	pPreviousFocus	The pointer to the previous focus of the control
	 * @remarks		Focus UI supports linear navigation of controls from top-left to bottom-right direction. This method allows for customizing the default navigation behavior.
	 * @remarks		The platform will not take the ownership of @c pPreviousFocus after this call.
	 * @see			SetNextFocus()
	 * @see			GetPreviousFocus()
	 */
	void SetPreviousFocus(Control* pPreviousFocus);

	/**
	 * Sets the next focus of the control.
	 *
	 * @since 2.1
	 *
	 * @param[in]	pNextFocus	The pointer to the next focus of the control
	 * @remarks		Focus UI supports linear navigation of controls from top-left to bottom-right direction. This method allows for customizing the default navigation behavior.
	 * @remarks		The platform will not take the ownership of @c pNextFocus after this call.
	 * @see			SetPreviousFocus()
	 * @see			GetNextFocus()
	*/
	void SetNextFocus(Control* pNextFocus);

	/**
	 * Gets the previous focus of the control.
	 *
	 * @since 2.1
	 *
	 * @return		The pointer to the previous focus of the control, @n
	 * 				else  @c null if the previous focus of the control is not set
	 * @see		GetNextFocus()
	 * @see		SetNextFocus ()
	*/
	Control* GetPreviousFocus(void) const;


	/**
	 * Gets the next focus of the control.
	 *
	 * @since 2.1
	 *
	 * @return		The pointer to the next focus of the control, @n
	 *				else @c null if the next focus of the control is not set
	 * @see		GetPreviousFocus()
	 * @see		SetPreviousFocus ()
	*/
	Control* GetNextFocus(void) const;

	/**
	 * Sets the touch press threshold of the Control in inch.
	 *
	 * @since		2.1
	 *
	 * @param[in]	distance	The logical threshold to fire touch move event
	 * @remark		A touch move events will start to fire if the move distance exceeds the set allowance value.
	 * For example, Set 0.5 if the distance is 0.5 inch.
	 * This method is offered to control sensitivity of move events.
	*/
	void SetTouchPressThreshold(float distance);

	/**
	 * Gets the touch press threshold of the Control in inch.
	 * If the threshold has not been set, it returns the default value.
	 *
	 * @since                    2.1
	 *
	 * @return    The threshold to fire touch move event
	 */
	float GetTouchPressThreshold(void) const;


	/**
	 * Sets the font of the control with the specified file name.
	 *
	 * @since 2.1
	 *
	 * @return			An error code
	 * @param[in]		fileName					The file name of a font-resource located in @b ‘/res/font’, @n
	 *												else an empty string to reset
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_FILE_NOT_FOUND			The specified font cannot be found or accessed.
	 * @exception		E_UNSUPPORTED_FORMAT		The specified font format is not supported.
	 * @see			GetFontFile()
	*/
	result SetFontFromFile(const Tizen::Base::String& fileName);

	/**
	 * Gets a font file name of the control.
	 *
	 * @since 2.1
	 *
	 * @return				The font name set in the control, @n
	 *						else an empty string if the font is not set
	 * @see				SetFontFromFile()
	*/
	Tizen::Base::String GetFontFile(void) const;

protected:
	/**
	 * Gets the default key event listener.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated.
	 * @since		2.0
	 *
	 * @return		The default key event listener @n
	 *				If no listener has been set or a system error has occurred @c null is returned.
	 * @see			SetDefaultKeyEventListener()
	 */
	IKeyEventListener* GetDefaultkeyEventListener(void) const;

	/**
	 * Gets the default touch event listener.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated   This method is deprecated.
	 * @since               2.0
	 *
	 * @return             The default touch event listener @n
	 *                                 If no listener has been set or a system error has occurred @c null is returned.
	 * @see                         SetDefaultTouchEventListener()
	 */
	ITouchEventListener* GetDefaultTouchEventListener(void) const;

	/**
	 * Sets the default key event listener.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated   This method is deprecated. Instead of using this method, use the SetPropagatedKeyEventListener() method.
	 * @since               2.0
	 *
	 * @return             An error code
	 * @param[in] pDefaultListener               The default key event listener
	 * @exception         E_SUCCESS                               The method is successful.
	 * @exception         E_SYSTEM                                A system error has occurred.
	 * @remarks           The registered listener will be notified to handle the key events
	 *                                 after all application event listeners has been notified.
	 * @see                         GetDefaultkeyEventListener()
	 */
	result SetDefaultKeyEventListener(IKeyEventListener* pDefaultListener);

	/**
	 * Sets the default touch event listener.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated   This method is deprecated. Instead of using this method, use the SetPropagatedTouchEventListener() method.
	 * @since               2.0
	 *
	 * @return             An error code
	 * @param[in] pDefaultListener               The default key event listener
	 * @exception         E_SUCCESS                               The method is successful.
	 * @exception         E_SYSTEM                                A system error has occurred.
	 * @remarks           The registered listener will be notified to handle the touch events
	 *                                 after all application event listeners has been notified.
	 * @see                         GetDefaultTouchEventListener()
	 */
	result SetDefaultTouchEventListener(ITouchEventListener* pDefaultListener);

	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	Control(void);

	/**
	 * This method is for internal use only. Using this method can cause behavioral, security-related,
	 * and consistency-related issues in the application.
	 *
	 * Initializes this instance of %Control.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Frees the resources allocated by Construct().
	 *
	 * @since 2.0
	 */
	void Dispose(void);

protected:
	_ControlImpl* _pControlImpl;

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Control_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Control_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Control_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Control_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//

	virtual void Control_Reserved5(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Control_Reserved6(void) {}

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Control(const Control& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Control& operator =(const Control& rhs);

private:
	friend class _ControlImpl;
}; // Control

}} // Tizen::Ui

#endif // _FUI_CONTROL_H_
