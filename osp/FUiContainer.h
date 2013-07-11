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
 * @file	FUiContainer.h
 * @brief	This is the header file for the %Container class.
 *
 * This header file contains the declarations of the %Container class.
 */

#ifndef _FUI_CONTAINER_H_
#define _FUI_CONTAINER_H_

#include <FBaseTypes.h>
#include <FBaseColLinkedList.h>
#include <FUiControl.h>

namespace Tizen { namespace Ui {

class Layout;
class _ContainerImpl;

/**
 * @class	Container
 * @brief	This class is an abstract base class of all the generic containers of Controls.
 *
 * @since	2.0
 *
 * @remarks As the %Container is an abstract class, use the Tizen::Ui::Controls::Panel class or another class derived from
 * %Container to apply the container functionality.
 *
 * The %Container class is the abstract base class of all generic Control containers. A container is a UI element which can contain
 * other UI elements.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/containers.htm">Containers</a>.
 *

 *
 */
class _OSP_EXPORT_ Container
	: public Control
{

public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Container(void) = 0;

public:
	/**
	 * Adds the control at the end of the list maintained by the container.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	control         The control to be added to the container
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid. @n
	 *                              The specified @c control is an instance of Window, or this control's parent container.
	 * @exception	E_MAX_EXCEEDED	The number of child controls has exceeded the maximum limit.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks		When the control is added, it is placed at the top of the drawing stack maintained by the container.@n
	 *              This means the last control added is drawn last
	 * @remarks		A control becomes displayable only after it has been added to a displayable container. Some methods may not work normally if the methods
	 *				of the control are called before adding the control to a container. After the control is added to a %Container, the OnInitializing()
	 *				method of the control are called before adding the control to a container. After the control is added to a %Container, the
	 *				OnInitializing() method of the control is invoked for the initialization of the control such as creating and adding child controls.
	 * @see			Tizen::Ui::Control::OnInitializing()
	 * @see			Tizen::Ui::Control::OnTerminating()
	 * @code
	 *	{
	 *		// Uses Panel instead of Container, because Container is an abstract class.
	 *		Panel* pPanel = new Panel();
	 *		pPanel->Construct(Rectangle(100, 250, 300, 300));
	 *
	 *		Form* pForm = new Form();
	 *		pForm->Construct(FORM_STYLE_NORMAL|FORM_STYLE_TITLE|FORM_STYLE_INDICATOR);
	 *		pForm->AddControl(*pPanel);
	 *
	 *		//...
	 *		pForm->Invalidate(true);
	 *		//...
	 *	}
	 * @endcode
	 */
	result AddControl(const Control& control);

	/**
	 * Before the system calls OnDraw() method to allow the user to do custom drawing, this method is called to clear the canvas. The user can override this method to change this default behavior.
	 *
	 * @since 2.0
	 *
	 * @see         GetCanvasN()
	 */
	virtual void OnClearBackground(void);

	/**
	 * Called when the container needs to draw itself. @n
	 * Users can override this method to display user-specific drawings. @n
	 * This method is called after the container has drawn itself, but just before the container draws its child controls.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since                              2.0
	 *
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *                       For more information, see @ref CompOnDrawPage "here".
	 * @endif
	 *
	 * @return                  An error code
	 * @exception    E_SUCCESS        The method is successful.
	 * @exception    E_SYSTEM         A system error has occurred.
	 */
	virtual result OnDraw(void);

	/**
	 * @if OSPCOMPAT
	 * @page               CompOnDrawPage        Compatibility for OnDraw()
	 * @section            CompOnDrawPage IssueSection          Issues
	 * Implementing this method in OSP compatible applications has the following issues:   @n
	 * -# The platform draws the control by calling the parent's OnDraw() callback before invoking the control's OnDraw() callback. So, the users can't control the control's drawing behavior by overriding the OnDraw() callback.
	 *
	 * @section            CompOnDrawPage SolutionSection               Resolutions
	 * This issue has been resolved in Tizen.  @n
	 * -# The platform does not call the parent's OnDraw() callback before invoking the control's OnDraw() callback. Therefore, you needs to call 	the parent container's OnDraw() callback in the OnDraw() callback if you override this method.
	 * @endif
	 */

	/**
	 * Called to notify that the control's show state is changing.
	 *
	 * @since       2.0
	 *
	 * @param[in]   showState  The new show state of the control
	 * @see         Osp::Ui::Control::SetShowState()
	 */
	virtual void OnShowStateChanging(bool showState);

	/**
	 * Called to notify that the control's show state is changed.
	 *
	 * @since       2.0
	 *
	 * @param[in]   showState  The new show state of the control
	 * @see         Tizen::Ui::Control::SetShowState()
	 */
	virtual void OnShowStateChanged(bool showState);

	/**
	 * Called to notify that the bounds of the control is changing.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   oldRect  The old position and size values of the control
	 * @param[in]   newRect  The new position and size values of the control
	 * @remarks     If the method returns an exception, the resulting exception
	 *              is propagated and the control's size is unchanged.@n
	 *              Provide control specific exceptions.
	 * @see         Tizen::Ui::Control::SetBounds()
	 * @see         Tizen::Ui::Control::SetSize()
	 */
	virtual result OnBoundsChanging(const Tizen::Graphics::Rectangle& oldRect, const Tizen::Graphics::Rectangle& newRect);

	/**
	 * Called to notify that the bounds of the control is changed.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   oldRect  The old position and size values of the control
	 * @param[in]   newRect  The new position and size values of the control
	 * @see         Tizen::Ui::Control::SetBounds()
	 * @see         Tizen::Ui::Control::SetSize()
	 */
	virtual void OnBoundsChanged(const Tizen::Graphics::Rectangle& oldRect, const Tizen::Graphics::Rectangle& newRect);

	/**
	 * Overrides this method to indicate that the specified @c width and @c height
	 * can be supported or a new @c width and @c height should be applied instead
	 * of the specified values.
	 *
	 * @since           2.0
	 *
	 * @return          A Boolean flag that indicates whether the specified @c width
	 *                  and @ height are supported.
	 * @param[in, out]  evaluatedSize  The width and the height that need to be evaluated.
	 */
	virtual void OnEvaluateSize(Tizen::Graphics::Dimension& evaluatedSize);

	/**
	 * Removes the specified control from the container.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	control         	The child control to be removed
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified instance is not found within the indicated range (that is, the @c control is not found).
	 * @exception	E_SYSTEM        	A system error has occurred.
	 * @remarks		The removed child control is deleted from the memory. Before deletion, OnTerminating() of the child control is called.
	 * @see			Tizen::Ui::Control::OnTerminating()
	 */
	result RemoveControl(const Control& control);

	/**
	 * Removes the specified control from the container.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	index           	The index of the control to be removed
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE  	The specified @c index is out of range.
	 * @exception	E_SYSTEM        	A system error has occurred.
	 * @remarks		The removed child control is deleted from the memory. Before deletion, OnTerminating() of the child control is called.
	 * @see			Tizen::Ui::Control::OnTerminating()
	 */
	result RemoveControl(int index);

	/**
	 * Removes all the controls from the container.
	 *
	 * @since			2.0
	 *
	 * @remarks 		The removed child controls are deleted from the memory. Before deletion, OnTerminating() of the child control is called.
	 * @see				Tizen::Ui::Control::OnTerminating()
	 */
	void RemoveAllControls(void);

	/**
	 * Gets the control at the specified index of the list that is kept by the container.
	 *
	 * @since			2.0
	 *
	 * @return		The control at the specified index of the list, @n
	 *              else @c null if the index is not valid
	 * @param[in]	index   The index of the control
	 */
	Control* GetControl(int index) const;

	/**
	 * Gets the control with the specified name. @n
	 * If there are multiple matches of the name, the first match is returned.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 *
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *                       For more information, see @ref CompGetControlPage "here".
	 * @endif
	 *
	 * @return		The control having the specified name, @n
	 *				else @c null if the name is not valid
	 * @param[in]	name		The name of the control
	 * @param[in]	recursive	Set to @c true to find a match recursively, @n
	 *							else @c false
	 */
	Control* GetControl(const Tizen::Base::String& name, bool recursive = false) const;

	/**
	 * @if OSPCOMPAT
	 * @page               CompGetControlPage        Compatibility for GetControl()
	 * @section            CompGetControlPage IssueSection          Issues
	 * Implementing this method in OSP compatible applications has the following issues:   @n
	 * -# GetControl() method searches for itself first and then child controls in OSP, whereas only @n
	 * child controls are searched for from Tizen.
	 *
	 * @section            CompGetControlPage SolutionSection               Resolutions
	 * This issue has been resolved in Tizen.  @n
	 * @endif
	 */

	/**
	 * Gets the number of the controls in the container.
	 *
	 * @since			2.0
	 *
	 * @return		The number of controls in the container
	 */
	int GetControlCount(void) const;

	/**
	 * Gets a list of the controls of the container.
	 *
	 * @since		2.0
	 *
	 * @return		The list of the controls of the container
	 */
	Tizen::Base::Collection::IList* GetControls(void) const;

	/**
	 * Gets the portrait layout of the container.
	 *
	 * @since			2.0
	 *
	 * @return		The portrait layout of the container, @n
	 *				else @c null if the layout does not exist
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @remarks		The returned layout can be @c null, if it is not set.
	 */
	Layout* GetPortraitLayoutN(void) const;

	/**
	 * Gets the landscape layout of the container.
	 *
	 * @since			2.0
	 *
	 * @return		The landscape layout of the container, @n
	 *				else @c null if the layout does not exist
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @remarks		The returned layout can be @c null, if it is not set.
	 */
	Layout* GetLandscapeLayoutN(void) const;

	/**
	 * Gets the layout of the current orientation.
	 *
	 * @since			2.0
	 *
	 * @return		The layout of the current orientation, @n
	 *				else @c null if the layout does not exist
	 * @exception	E_SUCCESS       	The method is successful.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @remarks		The returned layout can be @c null, if it is not set.
	 */
	Layout* GetLayoutN(void) const;

	/**
	 * Checks whether the specified control is a child or descendant of the container.
	 *
	 * @since				2.0
	 *
	 * @return      @c true if the specified control is within the containment hierarchy of the container, @n
	 *              else @c false
	 * @param[in]	control		The control
	 */
	bool IsAncestorOf(const Control& control) const;

	/**
	 * Sets whether the specified child control must always be above other children.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    control          The child control
	 * @param[in]    alwaysOnTop      The Boolean value indicating that @c control
	 *                                must always be on the top
	 * @exception    E_SUCCESS        The method is successful.
	 * @exception    E_INVALID_ARG    A specified input parameter is invalid.@n
	 *                                The specified control is not a child of this
	 *                                container.
	 * @remarks      If multiple child control are set as "always on top", then
	 *               their relative order is not specified. If the specified child
	 *               control is a container, then all its children inherit this
	 *               property and they are "always on top" of other controls.@n
	 *               If the method is called on a child control with a @c false
	 *               value, then it's state becomes normal. The relative order
	 *               of child controls in normal state is not specified.
	 * @see          IsControlAlwaysOnTop()
	 */
	result SetControlAlwaysOnTop(Tizen::Ui::Control& control, bool alwaysOnTop);

	/**
	 * Sets whether the specified child control must always be below other children.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    control          The child control
	 * @param[in]    alwaysAtBottom   The Boolean value indicating that @c control
	 *                                must always be at the bottom.
	 * @exception    E_SUCCESS        The method is successful.
	 * @exception    E_INVALID_ARG    A specified input parameter is invalid.@n
	 *                                The specified control is not a child of this
	 *                                container.
	 * @remarks      If multiple child control are set as "always at bottom", then
	 *               their relative order is not specified. If the specified child
	 *               control is a container, then all its children inherit this
	 *               property and they become "always at bottom" as well.@n
	 *               If the method is called on a child control with a @c false
	 *               value, then it's state becomes normal. The relative order
	 *               of child controls in normal state is not specified.
	 * @see          IsControlAlwaysAtBottom()
	 */
	result SetControlAlwaysAtBottom(Tizen::Ui::Control& control, bool alwaysAtBottom);

	/**
	 * Checks whether the specified child control is always at the bottom of
	 * the drawing stack.
	 *
	 * @since       2.0
	 *
	 * @return       @c true if the specified child control is set as always at the bottom, @n
	 *                 else @c false
	 * @param[in]    control          The child control
	 * @exception    E_SUCCESS        The method is successful.
	 * @exception    E_INVALID_ARG    A specified input parameter is invalid.@n
	 *                                The specified control is not a child of this
	 *                                container.
	 * @remarks      The specific error code can be accessed using the GetLastResult()
	 *               method.
	 * @see          SetControlAlwaysAtBottom()
	 */
	bool IsControlAlwaysAtBottom(const Tizen::Ui::Control& control) const;

	/**
	 * Checks whether the specified child control is always on the top of
	 * the drawing stack.
	 *
	 * @since        2.0
	 *
	 * @return       @c true if the specified child control is set as always on the top, @n
	 *               else @c false
	 * @param[in]    control          The child control
	 * @exception    E_SUCCESS        The method is successful.
	 * @exception    E_INVALID_ARG    A specified input parameter is invalid. @n
	 *                                The specified control is not a child of this
	 *                                container.
	 * @remarks      The specific error code can be accessed using the GetLastResult()
	 *               method.
	 * @see          SetControlAlwaysOnTop()
	 */
	bool IsControlAlwaysOnTop(const Tizen::Ui::Control& control) const;

protected:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	Container(void);

	/**
	 * Initializes this instance of %Container.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Initializes this instance of %Container.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   rect                                      The rectangle bounds to be set
	 * @param[in]   resizable                                Set to @c true to make the container resizable, @n
	 *                                  else @c false
	 * @param[in]   movable                                          Set to @c true to make the container movable, @n
	 *                                  else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG            A specified input parameter is invalid.
	 * @remarks     This method must be called from the derived classes's construct methods.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see IsResizable()
	*/
	result Construct(const Tizen::Graphics::Rectangle& rect, bool resizable = true, bool movable = true);

	/**
	 * Initializes this instance of %Container with the specified layout and rectangular region.
	 *
	 * @since 2.0
	 *
	 * @return                  An error code
	 * @param[in]   layout                                   The layout for both the portrait and landscape mode
	 * @param[in]   rect                                      The location and size of the %Container
	 * @param[in]   resizable                                Set to @c true to make the container resizable, @n
	 *                                  else @c false
	 * @param[in]   movable                                          Set to @c true to make the container movable, @n
	 *                                  else @c false
	 * @exception   E_SUCCESS                The method is successful.
	 * @exception   E_INVALID_ARG            A specified input parameter is invalid.
	 * @remarks     This method must be called from the derived classes's construct methods.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see IsResizable()
	 * @see Tizen::Ui::Layout
	 * @see Tizen::Ui::Container::GetLayoutN()
	*/
	result Construct(const Tizen::Ui::Layout& layout, const Tizen::Graphics::Rectangle& rect, bool resizable = true, bool movable = true);

	/**
	 * Initializes this instance of %Container with the specified layouts and rectangular region.
	 *
	 * @since 2.0
	 *
	 * @return                  An error code
	 * @param[in]   portraitLayout              The layout for the portrait mode
	 * @param[in]   landscapeLayout           The layout for the landscape mode
	 * @param[in]   rect                                      The location and size of the %Container
	 * @param[in]   resizable                                Set to @c true to make the container resizable, @n
	 *                                  else @c false
	 * @param[in]   movable                                          Set to @c true to make the container movable, @n
	 *                                  else @c false
	 * @exception   E_SUCCESS                The method is successful.
	 * @exception   E_INVALID_ARG            A specified input parameter is invalid.
	 * @remarks     If the @c resizable is @c false, IsResizable() returns @c false.
	 * @see IsResizable()
	 * @see Tizen::Ui::Layout
	 * @see Tizen::Ui::Layout
	 * @see Tizen::Ui::Container::GetLayoutN()
	 * @see Tizen::Ui::Container::GetPortraitLayoutN()
	 * @see Tizen::Ui::Container::GetLandscapeLayoutN()
	*/
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, const Tizen::Graphics::Rectangle& rect, bool resizable = true, bool movable = true);

	/**
	 * Gets the index of the specified control.
	 *
	 * @since			2.0
	 * @return		An error code
	 * @param[in]	control			The control
	 * @param[out]	index			The index of the control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified instance of Control is not found.
	 * @see			SetControlAt()
	 *
	 */
	result GetControlAt(const Control& control, int& index) const;

	/**
	 * Sets the control at the specified index.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]	control         The control
	 * @param[in]	index           The index
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified @c index is out of range.
	 * @exception	E_SYSTEM        A system error has occurred.
	 * @remarks	    The @c control must be first added to this container. @n
	 *				Call the Invalidate() method after this, to apply the change to be shown.
	 * @see         Invalidate(), GetControlAt()
	 *
	 */
	result SetControlAt(const Control& control, int index);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Container(const Container& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Container& operator =(const Container& rhs);

protected:
	friend class _ContainerImpl;

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Container_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Container_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Container_Reserved3(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Container_Reserved4(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void Container_Reserved5(void) {}

}; // Container

}}  //Tizen::Ui

#endif //_FUI_CONTAINER_H_
