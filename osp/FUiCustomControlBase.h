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
 * @file	FUiCustomControlBase.h
 * @brief	This is the header file for the %CustomControlBase class.
 *
 * This header file contains the declarations of the %CustomControlBase class and its helper classes.
 */

#ifndef _FUI_CUSTOM_CONTROL_BASE_H_
#define _FUI_CUSTOM_CONTROL_BASE_H_

#include <FUiContainer.h>

namespace Tizen { namespace Ui
{

class _CustomControlBaseImpl;

/**
 * @if OSPDEPREC
 * @class   CustomControlBase
 * @brief   <i> [Deprecated] </i> This is the base class for the user-defined UI control classes.
 *
 * @deprecated  This class is deprecated. Instead of using this class, use the Container class.
 * @since   2.0
 *
 * The %CustomControlBase class is the base class for the user-defined UI control classes.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_customcontrolbase.htm">CustomControlBase</a>.
 * @endif
 */
class _OSP_EXPORT_ CustomControlBase
	: public Container
{
// Lifecycle
public:
	/**
	 * @if OSPDEPREC
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the Container class.
	 * @since   2.0
	 * @endif
	 */
	virtual ~CustomControlBase(void);

	/**
	 * @if OSPDEPREC
	 * Notifies that the bounds of the control is about to change.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the Container class.
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   oldRect  The old position and size values of the control
	 * @param[in]   newRect  The new position and size values of the control
	 * @remarks     If the method returns an exception, the resulting exception
	 *              is propagated and the control's size is unchanged. @n
	 *              Provide control specific exceptions.
	 * @see         Tizen::Ui::Control::SetBounds()
	 * @see         Tizen::Ui::Control::SetSize()
	 * @endif
	 */
	virtual result PrepareBoundsChange(const Tizen::Graphics::Rectangle& oldRect, const Tizen::Graphics::Rectangle& newRect);

	/**
	 * @if OSPDEPREC
	 * Overrides this method to indicate that the specified @c width and @c height
	 * can be supported or a new @c width and @c height must be applied instead
	 * of the specified values.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the Container class.
	 * @since           2.0
	 *
	 * @return          A Boolean flag that indicates whether the specified @c width
	 *                  and @ height are supported
	 * @param[in, out]  width   The width that needs to  evaluate
	 * @param[in, out]  height  The height that needs to evaluate
	 * @endif
	 */
	virtual bool EvaluateSize(int& width, int& height);

protected:
	/**
	 * @if OSPDEPREC
	 * The object is not fully constructed after this constructor is called. For full construction, one of the %Construct() method must be called right after calling this constructor.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the Container class.
	 * @since	2.0
	 * @endif
	 */
	CustomControlBase(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %CustomControlBase.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the Container class.
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]	rect				The rectangle bounds to set
	 * @param[in]	resizable			Set to @c true to make the control resizable, @n
	 *                                  else @c false
	 * @param[in]	movable				Set to @c true to make the control movable, @n
	 *                                  else @c false
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks     This method must be called from the derived classes's construct methods.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see	IsResizable()
	 * @endif
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, bool resizable = true, bool movable = true);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %CustomControlBase with the specified layout and rectangular region.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the Container class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	layout				The layout for both the portrait and landscape mode
	 * @param[in]	rect				The location and size of the %CustomControlBase
	 * @param[in]	resizable			Set to @c true to make the control resizable, @n
	 *                                  else @c false
	 * @param[in]	movable				Set to @c true to make the control movable, @n
	 *                                  else @c false
	 * @exception	E_SUCCESS	        The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM	        A system error has occurred.
	 * @remarks     This method must be called from the derived classes's construct methods.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see	IsResizable()
	 * @see	Tizen::Ui::Layout
	 * @see	Tizen::Ui::Container::GetLayoutN()
	 * @endif
	 */
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::Rectangle& rect, bool resizable = true, bool movable = true);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %CustomControlBase with the specified layouts and rectangular region.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the Container class.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	portraitLayout		The layout for the portrait mode
	 * @param[in]	landscapeLayout		The layout for the landscape mode
	 * @param[in]	rect				The location and size of the %CustomControlBase
	 * @param[in]	resizable			Set to @c true to make the control resizable, @n
	 *                                  else @c false
	 * @param[in]	movable				Set to @c true to make the control movable, @n
	 *                                  else @c false
	 * @exception	E_SUCCESS	        The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM	        A system error has occurred.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see	IsResizable()
	 * @see	Tizen::Ui::Layout
	 * @see	Tizen::Ui::Container::GetLayoutN()
	 * @see	Tizen::Ui::Container::GetPortraitLayoutN()
	 * @see	Tizen::Ui::Container::GetLandscapeLayoutN()
	 * @endif
	 */
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, const Tizen::Graphics::Rectangle& rect, bool resizable = true, bool movable = true);

private:
	/**
	 * @if OSPDEPREC
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the Container class.
	 * @since	2.0
	 * @endif
	 */
	CustomControlBase(const CustomControlBase& rhs);

	/**
	 * @if OSPDEPREC
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the Container class.
	 * @since	2.0
	 * @endif
	 */
	CustomControlBase& operator =(const CustomControlBase& rhs);

protected:
	friend class _CustomControlBaseImpl;

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void CustomControlBase_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void CustomControlBase_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void CustomControlBase_Reserved3(void) {}
}; // CustomControlBase

}} // Tizen::Ui

#endif // _FUI_CUSTOM_CONTROL_BASE_H_

