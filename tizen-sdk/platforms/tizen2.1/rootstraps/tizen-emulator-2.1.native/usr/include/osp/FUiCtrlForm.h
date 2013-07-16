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
 * @file		FUiCtrlForm.h
 * @brief	This is the header file for the %Form class.
 *
 * This header file contains the declarations of the %Form class.
 */
#ifndef _FUI_CTRL_FORM_H_
#define _FUI_CTRL_FORM_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FBaseColLinkedListT.h>
#include <FUiIActionEventListener.h>
#include <FUiContainer.h>
#include <FUiIOrientationEventListener.h>
#include <FUiCtrlControlsTypes.h>
#include <FUiCtrlOverlayRegion.h>

namespace Tizen { namespace Ui
{
class DataBindingContext;
}  } // Tizen::Ui

namespace Tizen { namespace Ui { namespace Controls
{
class Header;
class Footer;
class Tab;
class IFormBackEventListener;

/**
 * @enum FormStyle
 *
 * Defines the %Form control style.
 *
 * @since		2.0
 */
enum FormStyle
{
	FORM_STYLE_NORMAL = 0x00000000,     /**< The basic form style */
	FORM_STYLE_TITLE = 0x00000001,      /**<@if OSPDEPREC @deprecated This enum value is deprecated because the use of the Title control is no longer recommended.@endif */
	FORM_STYLE_INDICATOR = 0x00000002,  /**< The form with the indicator area */
	FORM_STYLE_SOFTKEY_0 = 0x00000010,  /**<@if OSPDEPREC @deprecated This enum value is deprecated because the use of the Softkey control is no longer recommended.@endif */
	FORM_STYLE_SOFTKEY_1 = 0x00000020,  /**<@if OSPDEPREC @deprecated This enum value is deprecated because the use of the Softkey control is no longer recommended.@endif */
	FORM_STYLE_OPTIONKEY = 0x00000040,  /**<@if OSPDEPREC @deprecated This enum value is deprecated because the use of the Optionkey control is no longer recommended.@endif */
	FORM_STYLE_TEXT_TAB = 0x00000100,   /**<@if OSPDEPREC @deprecated This enum value is deprecated because the use of the Tab control is no longer recommended. @endif */
	FORM_STYLE_ICON_TAB = 0x00000200,   /**<@if OSPDEPREC @deprecated This enum value is deprecated because the use of the Tab control is no longer recommended. @endif */
	FORM_STYLE_HEADER = 0x00001000,     /**< The form with a header */
	FORM_STYLE_FOOTER = 0x00002000,      /**< The form with a footer */
	FORM_STYLE_INDICATOR_AUTO_HIDE = 0x00010000   /**< The form with a indicator which is hidden. @b Since: @b 2.1 */
};


/**
 * @if OSPDEPREC
 * @enum Softkey
 *
 * Defines the softkey.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This enum type is deprecated because the use of the Softkey control is no longer recommended.
 * @since		2.0
 * @endif
 */
enum Softkey
{
	SOFTKEY_0,      /**< @if OSPDEPREC The left softkey @endif */
	SOFTKEY_1,      /**< @if OSPDEPREC The right softkey @endif */
	SOFTKEY_COUNT	// This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};


/**
 * @enum FormActionBar
 *
 * Defines the action bars that can be attached to the %Form control.
 *
 * @since   2.0
 */
enum FormActionBar
{
	FORM_ACTION_BAR_INDICATOR = 0x0001, /**< The indicator */
	FORM_ACTION_BAR_HEADER = 0x0002,    /**< The header */
	FORM_ACTION_BAR_FOOTER = 0x0004,     /**< The footer */
	FORM_ACTION_BAR_TAB = 0x0008     /**< The tab */			// Ki-Dong,Hong.Temp
};


/**
 * @class	Form
 * @brief	This class provides a container with general controls.
 *
 * @since	2.0
 *
 * The %Form class displays a full screen container. It can contain user-created controls and system UI components, such
 * as an indicator area, header, and footer. The application can have multiple forms that are all added to a single Frame.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_form.htm">Form</a>.
 *
 * The following example demonstrates how to use the %Form class.
 *
 * @code
	// Creates an instance of Form
	Form* pForm = new Form();
	pForm->Construct(FORM_STYLE_NORMAL| FORM_STYLE_HEADER| FORM_STYLE_FOOTER);

	// Gets a pointer of the frame
	Frame *pFrame = UiApp::GetInstance()->GetAppFrame()->GetFrame();
	pFrame->AddControl(pForm);
	pFrame->SetCurrentForm(pForm);

	// Implements MyActionEventListener
	IActionEventListener* pListener = new MyActionEventListener();

	// Adds a header
	Header * pHeader = GetHeader();
	pHeader->SetTitleText(L"FormSample");

	// Adds a footer
	Footer * pFooter = GetFooter();
	pFooter->SetStyle(FOOTER_STYLE_TAB);
	pFooter->AddActionEventListener(*this);

	// Calls Invalidate() to display the form
	pForm->Invalidate(true)
 * @endcode
 *
 * This is a simple UI application that uses a %Form.
 *@image html ui_controls_form.png
 *
 */
class _OSP_EXPORT_ Form
	: public Tizen::Ui::Container
{
public:
// Lifecycle
	/**
	 * This is the default constructor for this class.
	 * @since   2.0
	 */
	Form(void);

	/**
	 *	This is the destructor for this class.
	 * @since   2.0
	 */
	virtual ~Form(void);

	/**
	 * Initializes this instance of %Form with the specified parameters.
	 *
	 * @since   	2.0
	 *
	 * @return      An error code
	 * @param[in]	formStyle           The form style @n
	 *									Multiple form styles can be combined using bitwise OR.
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 *									- ::FORM_STYLE_HEADER and ::FORM_STYLE_TITLE are specified at the same time.
	 *									- ::FORM_STYLE_FOOTER and ::FORM_STYLE_SOFTKEY_0 are specified at the same time.
	 *									- @c FORM_STYLE_FOOTER and ::FORM_STYLE_SOFTKEY_1 are specified at the same time.
	 *									- @c FORM_STYLE_FOOTER and ::FORM_STYLE_OPTIONKEY are specified at the same time.
	 * @exception   E_MAX_EXCEEDED      The total number of Frames and Forms exceeds the system limitation.
	 * @exception	E_SYSTEM            A system error has occurred.
	 * @remarks     The maximum number of Forms that an application can construct is limited by available memory.
	 * @see         FormStyle
	 */
	result Construct(unsigned long formStyle);


	/**
	 * Initializes this instance of %Form with the specified resource ID. @n
	 * This method first attempts to find the resource file in the folder that corresponds to the current screen resolution. If it fails to find the
	 * appropriate resource file, the method tries searching in other folders. When AutoScaling is enabled, the method first searches the folder that
	 * corresponds to the current screen size category and then searches the "res/screen-size-normal/" folder.
	 *
	 * @since      2.0
	 *
	 * @return     An error code
	 * @param[in]  resourceId              The resource ID describing the %Form control
	 * @exception  E_SUCCESS               The method is successful.
	 * @exception  E_FILE_NOT_FOUND        The specified file cannot be found.
	 * @exception  E_INVALID_FORMAT        The specified XML format is invalid.
	 * @exception  E_OPERATION_FAILED      The operation has failed.
	 */
	result Construct(const Tizen::Base::String& resourceId);

	/**
	 * Initializes this instance of %Form with the form style and layout.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]	layout				The layout for both the portrait and landscape mode
	 * @param[in]   formStyle           The form style @n
	 *									Multiple form styles can be combined using bitwise OR.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid, or
	 *									the specified layout is already bound to another container.
	 * @exception   E_MAX_EXCEEDED      The total number of Frames and Forms exceeds the system limitation.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks
	 *			- The maximum number of Forms that an application can construct is limited by available memory.
	 *			- The children are arranged within the client area bounds of the form area by @c layout.
	 * @see         FormStyle
	 */
	result Construct(const Tizen::Ui::Layout& layout, unsigned long formStyle);

	/**
	 * Initializes this instance of %Form with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]	portraitLayout		The layout for the portrait mode
	 * @param[in]	landscapeLayout		The layout for the landscape mode
	 * @param[in]   formStyle           The form style @n
	 *									Multiple form styles can be combined using bitwise OR.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid, or
	 *									the specified layout is already bound to another container.
	 * @exception   E_MAX_EXCEEDED      The total number of Frames and Forms exceeds the system limitation.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks
	 *			- The maximum number of Forms that an application can construct is limited by available memory.
	 *			- The children are arranged within the bounds of the form area by @c layout.
	 * @see         FormStyle
	 */
	result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, unsigned long formStyle);

// Operation

	/**
	 * Adds an IOrientationEventListener instance. @n
	 * The added listener can listen to the orientation changed events that are fired when the orientation mode of the screen is changed.
	 *
     * @since   2.0
	 *
	 * @param[in]	listener 	The listener to add
	 * @remarks	    The %Form control can only listen to those changes to the orientation mode that are enabled by calling SetOrientation().
	 * @see			RemoveOrientationEventListener()
	 */
	void AddOrientationEventListener(Tizen::Ui::IOrientationEventListener& listener);


	/**
	 * @if OSPDEPREC
	 * Adds an IActionEventListener instance. @n
	 * The added listener can listen to the action events that are fired when an option key is selected.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Optionkey control is no longer recommended.
     * @since   2.0
	 *
	 * @param[in]	listener	The listener to add
	 * @see			RemoveOptionkeyActionListener()
	 * @endif
	 */
	void AddOptionkeyActionListener(Tizen::Ui::IActionEventListener& listener);


	/**
	 * @if OSPDEPREC
	 * Adds an IActionEventListener instance. @n
	 * The added listener can listen to the action events that are fired when a softkey is selected.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
	 * @since   2.0
	 *
	 * @param[in]   softkey		The style of the softkey
	 * @param[in]	listener 	The listener to add
	 * @see			RemoveSoftkeyActionListener()
	 * @endif
	 */
	void AddSoftkeyActionListener(Softkey softkey, Tizen::Ui::IActionEventListener& listener);


	/**
	 * @if OSPDEPREC
	 * Removes an IActionEventListener instance. @n
	 * The removed listener cannot listen to the events when they are fired.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Optionkey control is no longer recommended.
	 * @since       2.0
	 *
	 * @param[in]	listener 	The listener to remove
	 * @see			AddOptionkeyActionListener()
	 * @endif
	 */
	void RemoveOptionkeyActionListener(Tizen::Ui::IActionEventListener& listener);


	/**
	 * Removes an IOrientationEventListener instance. @n
	 * The removed listener cannot listen to the events when they are fired.
	 *
	 * @since   2.0
	 *
	 * @param[in]	listener	The listener to remove
	 *
	 * @see			AddOrientationEventListener()
	 */
	void RemoveOrientationEventListener(Tizen::Ui::IOrientationEventListener& listener);


	/**
	 * @if OSPDEPREC
	 * Removes an IActionEventListener instance. @n
	 * The removed listener cannot listen to the events when they are fired.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
	 * @since   2.0
	 *
	 * @param[in]   softkey		The style of the softkey
	 * @param[in]	listener 	The listener to remove
	 * @see			AddSoftkeyActionListener()
	 * @endif
	 */
	void RemoveSoftkeyActionListener(Softkey softkey, Tizen::Ui::IActionEventListener& listener);


// Accessor
	/**
	 * Gets the background color of the %Form control.
	 *
	 * @since   2.0
	 *
	 * @return	The background color of the %Form control
	 */
	Tizen::Graphics::Color GetBackgroundColor(void) const;


	/**
	 * Gets the bounds of the client area.
	 *
	 * @since   2.0
	 *
	 * @return	The bounds of the client area
	 * @remarks	The client area of the %Form control does not include the title, indicator, header and footer areas.
	 *			header and footer areas.
	 *
	 */
	Tizen::Graphics::Rectangle GetClientAreaBounds(void) const;

	/**
	 * Gets the bounds of the client area.
	 *
	 * @since   2.1
	 *
	 * @return	The bounds of the client area
	 * @remarks	The client area of the %Form control does not include the title, indicator, header and footer areas.
	 *			header and footer areas.
	 *
	 */
	Tizen::Graphics::FloatRectangle GetClientAreaBoundsF(void) const;

	/**
	 * Gets the style of the %Form control.
	 *
	 * @since   2.0
	 *
	 * @return	An @c unsigned @c long value representing the style of the %Form control
	 */
	unsigned long GetFormStyle(void) const;


	/**
	 * Gets the orientation mode of the %Form control.
	 *
	 * @since   2.0
	 *
	 * @return 	The orientation of the %Form control
	 */
	Tizen::Ui::Orientation GetOrientation(void) const;


	/**
	 * Gets the current orientation status of the %Form control.
	 *
     * @since   2.0
	 *
	 * @return	The orientation status of the %Form control, @n
	 *			else @c ORIENTATION_NONE if the %Form control is not the current form of the Frame control
	 */
	Tizen::Ui::OrientationStatus GetOrientationStatus(void) const;


	/**
	 * @if OSPDEPREC
	 * Gets the action ID of the specified softkey.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
	 * @since       2.0
	 *
	 * @return		An integer value representing the action ID
	 * @param[in] 	softkey			The softkey
	 * @endif
	 */
	int GetSoftkeyActionId(Softkey softkey) const;


	/**
	 * @if OSPDEPREC
	 * Gets the text of the specified softkey.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
	 * @since       2.0
	 *
	 * @return		The text of the softkey
	 * @param[in]   softkey			The softkey
	 * @endif
	 */
	Tizen::Base::String GetSoftkeyText(Softkey softkey) const;


	/**
	 * @if OSPDEPREC
	 * Gets the pointer of the Tab control if it exists.
	 *
	 * @brief <i> [Deprecated]  </i>
 	 * @deprecated This method is deprecated because the use of the Tab control is no longer recommended.
     * @since   	2.0
	 *
	 * @return		A pointer to the Tab control, @n
	 *				else @c null if there is no tab
	 * @remarks		The retrieved pointer may be temporary. Therefore, it should not be stored after immediate use.
	 * @endif
	 */
	Tab* GetTab(void) const;


	/**
	 * @if OSPDEPREC
	 * Gets the title of the %Form control.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated because the use of the Title control is no longer recommended. Instead of the %Title control,
	 *				use the Header control.
     * @since   2.0
	 *
	 * @return		The title of the %Form control
	 * @endif
	 */
	Tizen::Base::String GetTitleText(void) const;


	/**
	 * @if OSPDEPREC
	 * Gets the horizontal alignment of the title text.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated because the use of the Title control is no longer recommended. Instead of the %Title control,
	 *				use the Header control.
     * @since   2.0
	 *
	 * @return  The horizontal alignment of the title text
	 * @remarks		By default, the horizontal alignment is center aligned.
	 * @endif
	 */
	HorizontalAlignment GetTitleTextHorizontalAlignment(void) const;

	/**
	 * Checks whether the %Form control has an Indicator.
	 *
	 * @since   2.0
	 *
	 * @return	@c true if the %Form control has a title, @n
	 *			else @c false
	 */
	bool HasIndicator(void) const;


	/**
	 * @if OSPDEPREC
	 * Checks whether the %Form control has an optionkey.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Optionkey control is no longer recommended.
     * @since   2.0
	 *
	 * @return		@c true if the %Form control has an optionkey, @n
	 *				else @c false
	 * @endif
	 */
	bool HasOptionkey(void) const;


	/**
	 * @if OSPDEPREC
	 * Checks whether the %Form control has the specified softkey.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
	 * @since   2.0
	 *
	 * @return		@c true if the %Form control has the specified softkey, @n
	 *				else @c false
	 * @param[in]   softkey			The required softkey
	 * @endif
	 */
	bool HasSoftkey(Softkey softkey) const;


	/**
	 * @if OSPDEPREC
	 * Checks whether the %Form control has a tab.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Tab control is no longer recommended.
     * @since   2.0
	 *
	 * @return	@c true if the %Form control has a tab, @n
	 *			else @c false
	 * @endif
	 */
	bool HasTab(void) const;


	/**
	 * @if OSPDEPREC
	 * Checks whether the %Form control has a title.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated because the use of the Title control is no longer recommended. Instead of the %Title control,
	 *				use the Header control.
     * @since   2.0
	 *
	 * @return		@c true if the %Form control has a title, @n
	 *				else @c false
	 * @endif
	 */
	bool HasTitle(void) const;


	/**
	 * @if OSPDEPREC
	 * Checks whether the softkey is enabled.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
	 * @since   2.0
	 *
	 * @return		@c true if the softkey is enabled, @n
	 *				else @c false
	 * @param[in]   softkey			The softkey
	 * @endif
	 */
	bool IsSoftkeyEnabled(Softkey softkey) const;


	/**
	 * Sets the background color of the %Form control.
	 *
	 * @since   2.0
	 *
	 * @param[in]	color   The background color to set
	 */
	void SetBackgroundColor(const Tizen::Graphics::Color& color);


	/**
	 * Sets the style of the %Form control.
	 *
	 * @since       2.0
	 *
	 * @param[in]   formStyle		The form style to set @n
	 *								This parameter can be a combination of Tizen::Ui::Controls::FormStyle.
	 * @exception	E_SUCCESS		The method is successful @if OSPCOMPAT @b Since: @b 2.0 @endif.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 *								- ::FORM_STYLE_HEADER and ::FORM_STYLE_TITLE are specified at the same time.
	 *								- ::FORM_STYLE_FOOTER and ::FORM_STYLE_SOFTKEY_0 are specified at the same time.
	 *								- @c FORM_STYLE_FOOTER and ::FORM_STYLE_SOFTKEY_1 are specified at the same time.
	 *								- @c FORM_STYLE_FOOTER and ::FORM_STYLE_OPTIONKEY are specified at the same time.
	 * @remarks
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 *				- Note that you must not change the style of %Form control that is constructed with ::FORM_STYLE_TEXT_TAB
	 *				or ::FORM_STYLE_ICON_TAB style.
	 *				- A Form which is added to a container except Frame cannot have the style of ::FORM_STYLE_INDICATOR.
	 */
	void SetFormStyle(unsigned long formStyle);


	/**
	 * @if OSPDEPREC
	 * Sets an action ID of the optionkey.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Optionkey control is no longer recommended.
	 * @since   2.0
	 *
	 * @param[in]   actionId		The action ID of this button instance
	 * @endif
	 */
	void SetOptionkeyActionId(int actionId);


	/**
	 * Sets the orientation of the %Form control.
	 *
	 * @since   2.0
	 *
	 * @feature %http://tizen.org/setting/screen.auto_rotation for the @c ORIENTATION_AUTOMATIC_FOUR_DIRECTION or
	 *			@c ORIENTATION_AUTOMATIC value of @c orientation
	 * @param[in]  orientation                                  The orientation of the %Form control
	 * @exception  E_UNSUPPORTED_OPERATION               The Emulator or target device does not support the required feature. @b Since: @b 2.1 @n
	 * For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 *				- Before calling this method, check whether the feature is supported by
	 *				Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	void SetOrientation(Orientation orientation);


	/**
	 * @if OSPDEPREC
	 * Sets an action ID of each softkey.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
	 * @since   2.0
	 *
	 * @param[in]   softkey			The softkey
	 * @param[in] 	actionId		The action ID to set
	 * @endif
	 */
	void SetSoftkeyActionId(Softkey softkey, int actionId);


	/**
	 * @if OSPDEPREC
	 * Enables or disables the specified softkey.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
	 * @since   2.0
	 *
	 * @param[in]   softkey			The softkey
	 * @param[in]   enable			Set to @c true to enable this softkey @n
	 *							else @c false
	 * @endif
	 */
	void SetSoftkeyEnabled(Softkey softkey, bool enable);


	/**
	 * @if OSPDEPREC
	 * Sets the title icon of the %Form control.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated because the use of the Title control is no longer recommended. Instead of the %Title control,
	 *				use the %Header control.
	 * @since           2.0
	 *
	 * @return			An error code
	 * @param[in] 		pTitleBitmap			The title icon to set, @n
	 *											else @c null if the title icon is removed
	 * @exception		E_SUCCESS 		        The method is successful.
	 * @exception		E_INVALID_OPERATION		The current state of the instance prohibits the execution of a specified operation
	 *											(that is, this control cannot be displayed).
	 * @exception		E_SYSTEM		        A system error has occurred.
	 * @endif
	 */
	result SetTitleIcon(const Tizen::Graphics::Bitmap* pTitleBitmap);


	/**
	 * @if OSPDEPREC
	 * Sets the title of this %Form control.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated because the use of the Title control is no longer recommended. Instead of the %Title control,
	 *				use the Header control.
     * @since   2.0
	 *
	 * @return		An error code
	 * @param[in] 	title				The title to set
	 * @param[in] 	alignment		    The horizontal alignment
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of a specified operation
	 *									(that is, this control cannot be displayed).
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *				- If the size of the text exceeds the displayable area, the text slides automatically.
	 *				- Note that when the title icon is set along with the title text, the title retains the left alignment.
	 * @endif
	 */
	result SetTitleText(const Tizen::Base::String& title, HorizontalAlignment alignment = ALIGNMENT_CENTER);


	/**
	 * @if OSPDEPREC
	 * Sets the icon of the softkey.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
     * @since   2.0
	 *
	 * @param[in] 	softkey		    The softkey
	 * @param[in] 	normalBitmap	The Bitmap of the normal icon
	 * @param[in] 	pPressedBitmap	The Bitmap of the pressed icon
	 * @remarks		If both the icon and text are set for a softkey at the same time, the text takes precedence over the icon.
	 * @endif
	 */
	void SetSoftkeyIcon(Softkey softkey, const Tizen::Graphics::Bitmap& normalBitmap, const Tizen::Graphics::Bitmap* pPressedBitmap);

	/**
	 * @if OSPDEPREC
	 * Sets the text of the specified softkey.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the use of the Softkey control is no longer recommended.
	 * @since   2.0
	 *
	 * @param[in]   softkey	The softkey
	 * @param[in] 	text		The text to set
	 * @remarks
	 *				- If both the icon and text are set for a softkey at the same time, the text takes precedence over the icon.
	 *				- To display text in multi-lines or to denote the end of line, use '\\n'.
	 * @endif
	 */
	void SetSoftkeyText(Softkey softkey, const Tizen::Base::String& text);

	/**
	 * Gets the pointer to the Footer control if it exists.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the Footer control, @n
	 *				else @c null if there is no %Footer
	 * @remarks		The retrieved pointer may be temporary. Therefore, it should not be stored after immediate use. @n
	 *				The optimal size of the control is defined in
	 *				<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 */
	Footer* GetFooter(void) const;


	/**
	 * Gets the pointer to the Header control if it exists.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the Header control, @n
	 *				else @c null if there is no %Header
	 * @remarks		The retrieved pointer may be temporary. Therefore, it should not be
	 *              stored after immediate use. @n
	 *				The optimal size of the control is defined in
	 *				<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 */
	Header* GetHeader(void) const;


	/**
	 * Checks whether the %Form control has a Footer.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the %Form control has a Footer, @n
	 *				else @c false
	 */
	bool HasFooter(void) const;


	/**
	 * Checks whether the %Form control has a Header.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the %Form control has a Header, @n
	 *				else @c false
	 */
	bool HasHeader(void) const;


	/**
	 * Checks whether the Indicator control is visible.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the Indicator control is visible, @n
	 *				else @c false
	 */
	bool IsIndicatorVisible(void) const;


	/**
	 * Checks whether the Header control is visible.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the Header control is visible, @n
	 *				else @c false
	 */
	bool IsHeaderVisible(void) const;


	/**
	 * Checks whether the Footer control is visible.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the Footer control is visible, @n
	 *				else @c false
	 */
	bool IsFooterVisible(void) const;


	/**
	 * Checks whether the Indicator control is translucent.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the Indicator control is translucent, @n
	 *				else @c false
	 */
	bool IsIndicatorTranslucent(void) const;


	/**
	 * Checks whether the Header control is translucent.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the Header control is translucent, @n
	 *				else @c false
	 */
	bool IsHeaderTranslucent(void) const;


	/**
	 * Checks whether the Footer control is translucent.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the Footer control is translucent, @n
	 *              else @c false
	 */
	bool IsFooterTranslucent(void) const;


	/**
	 * Sets the translucency of the action bars.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	actionBars          	The action bars @n
	 *										Multiple action bars can be combined using bitwise OR (see Tizen::Ui::Controls::FormActionBar).
	 * @param[in]	translucent				Set to @c to make the action bars translucent, @n
	 *										else @c false
	 * @exception	E_SUCCESS           	The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of a specified operation, or
	 *										the specified action bars do not exist.
	 * @exception   E_UNSUPPORTED_OPERATION	This operation is not supported.
	 * @exception	E_SYSTEM            	A system error has occurred.
	 * @remarks
	 *				- Modifying the translucency of the action bars causes the client area of the %Form to change.
	 *				- The translucency of multiple action bars can be modified at the same time by using logical OR for several values of FormActionBar.
	 * 				- The method is not supported in 16-bit devices.
	 */
	result SetActionBarsTranslucent(unsigned long actionBars, bool translucent);


	/**
	 * Sets the visibility state of the action bars.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	actionBars          The action bars @n
	 *									Multiple action bars can be combined using bitwise OR.
	 * @param[in]	visible             Set to @c true to make the action bars visible, @n
	 *									else @c false
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation, or
	 *                                  the specified action bars does not exist.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks
	 *				- Modifying the translucency of action bars causes the client area of the %Form to change.
	 *				- The visibility of multiple action bars can be modified at the same time by using logical OR for several values of FormActionBar.
	 * @see			FormActionBar
	 */
	result SetActionBarsVisible(unsigned long actionBars, bool visible);


	/**
	 * Creates and returns an overlay region of the specified position and size. @n
	 * Due to the hardware accelerated rendering, there are limitations for an overlay region. @n
	 * The hardware capability for an overlay region is checked by using OverlayRegion::GetWidthUnit(), OverlayRegion::GetHeightUnit() and
	 * OverlayRegion::GetMaxCount().
	 * If the specified condition is not satisfied, @c E_INVALID_ARG exception is returned.
	 *
	 * @since		2.0
	 *
	 * @return		An overlay region instance
	 * @param[in]	rect         		 	The x and y coordinates relative to the top-left corner of the form along with the width and height
	 * @param[in]	regionType				The type of the overlay region
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_MAX_EXCEEDED			The number of overlay regions has reached the maximum limit.
	 * @exception	E_UNSUPPORTED_OPTION	The specified option of the overlay region type is not supported.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 * 				- If the application runs on multi-screen resolutions, the specified bounds may not meet the hardware limitations
	 *				of the overlay region. @n
	 *				In such cases, it returns the @c E_INVALID_ARG exception. To prevent this problem,
	 *				the application should use the OverlayRegion::EvaluateBounds() method to get the validated bounds that
	 *				can be used as the input bounds of this method.
	 * 				- Do not use OverlayRegion with OverlayPanel. If used, the @c E_SYSTEM exception is thrown.
	 */
	OverlayRegion* GetOverlayRegionN(const Tizen::Graphics::Rectangle& rect, OverlayRegionType regionType);

	/**
	 * Creates and returns an overlay region of the specified position and size. @n
	 * Due to the hardware accelerated rendering, there are limitations for an overlay region. @n
	 * The hardware capability for an overlay region is checked by using OverlayRegion::GetWidthUnit(), OverlayRegion::GetHeightUnit() and
	 * OverlayRegion::GetMaxCount().
	 * If the specified condition is not satisfied, @c E_INVALID_ARG exception is returned.
	 *
	 * @since		2.1
	 *
	 * @return		An overlay region instance
	 * @param[in]	rect         		 	The x and y coordinates relative to the top-left corner of the form along with the width and height
	 * @param[in]	regionType				The type of the overlay region
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_MAX_EXCEEDED			The number of overlay regions has reached the maximum limit.
	 * @exception	E_UNSUPPORTED_OPTION	The specified option of the overlay region type is not supported.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 * 				- If the application runs on multi-screen resolutions, the specified bounds may
	 *				not meet the hardware limitations of the overlay region. @n
	 *				In such cases, it returns the @c E_INVALID_ARG exception. @n
	 *				To prevent this problem, the application should use the OverlayRegion::EvaluateBoundsF() method to
	 *				get the validated bounds that can be used as the input bounds of this method.
	 * 				- Do not use OverlayRegion with OverlayPanel. If used, the @c E_SYSTEM exception is thrown.
	 */
	OverlayRegion* GetOverlayRegionN(const Tizen::Graphics::FloatRectangle& rect, OverlayRegionType regionType);


	/**
	 * Creates and returns a graphics canvas whose bounds (position and size) are equal to the bounds of the client area of the %Form.
	 *
	 * @since         2.0
	 *
	 * @return      The graphic canvas of the %Form control, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception   E_RESOURCE_UNAVAILABLE        The required resource is currently unavailable.
	 * @remarks
	 *				- The method allocates Tizen::Graphics::Canvas whose bounds are equal to that of the client area of the %Form.
	 *				- It is the responsibility of the developers to deallocate the canvas after use.
	 * 				- The canvas is valid only if the properties of the parent control of the canvas remain unchanged. @n
	 *				Therefore, delete the previously allocated canvas and create a new canvas using this method
	 *				if the size or position of the control is changed.
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 *				- The Frame and %Form instances share a single frame-buffer. @n
	 *				Therefore, the custom drawing on the graphic canvas of the Frame and %Form controls appears on the
	 *				screen regardless of whether the control is currently visible on the screen.
	 */
	Tizen::Graphics::Canvas* GetClientAreaCanvasN(void) const;

	/**
	 * Translates the specified position to the client coordinate.
	 *
	 * @since       2.0
	 *
	 * @return      The position relative to the top-left corner of the client area, @n
	 *				else @c (-1,-1) if the instance is invalid
	 * @param[in]	position		The position relative to the top-left corner of the %Form control
	 * @see         TranslateFromClientAreaPosition()
	 */
	Tizen::Graphics::Point TranslateToClientAreaPosition(const Tizen::Graphics::Point& position) const;

	/**
	 * Translates the specified position to the client coordinate.
	 *
	 * @since       2.1
	 *
	 * @return      The position relative to the top-left corner of the client area, @n
	 *				else @c (-1,-1) if the instance is invalid
	 * @param[in]	position		The position relative to the top-left corner of the %Form control
	 * @see         TranslateFromClientAreaPosition()
	 */
	Tizen::Graphics::FloatPoint TranslateToClientAreaPosition(const Tizen::Graphics::FloatPoint& position) const;

	/**
	 * Translates the specified client position to the control coordinate.
	 *
	 * @since       2.0
	 *
	 * @return      The position relative to the top-left corner of the %Form control, @n
	 *				else @c (-1,-1) if the instance is invalid
	 * @param[in]   clientPosition     The position relative to the top-left corner of the client area
	 * @see         TranslateToClientAreaPosition()
	 */
	Tizen::Graphics::Point TranslateFromClientAreaPosition(const Tizen::Graphics::Point& clientPosition) const;

	/**
	 * Translates the specified client position to the control coordinate.
	 *
	 * @since       2.1
	 *
	 * @return      The position relative to the top-left corner of the %Form control, @n
	 *				else @c (-1,-1) if the instance is invalid
	 * @param[in]   clientPosition     The position relative to the top-left corner of the client area
	 * @see         TranslateToClientAreaPosition()
	 */
	Tizen::Graphics::FloatPoint TranslateFromClientAreaPosition(const Tizen::Graphics::FloatPoint& clientPosition) const;

	/**
     * Sets the %Form back event listener.
	 *
	 * @since       2.0
	 *
     * @param[in]	pFormBackEventListener		The %Form back event listener to set
	 * @see         Tizen::Ui::Controls::IFormBackEventListener.
	 */
	void SetFormBackEventListener(IFormBackEventListener* pFormBackEventListener);


	/**
	 * Gets the data binding context.
	 *
	 * @since 2.0
	 *
	 * @return        DataBindingContext        the data binding context
	 * @exception    E_SUCCESS        The method is successful.
	 * @exception    E_SYSTEM         A system error has occurred.
	 * @remarks      The specific error code can be accessed using the GetLastResult() method.
	 */
	DataBindingContext* GetDataBindingContextN(void) const;

	/**
	* Enables or disables the notification tray to remain open.
	*
	* @since 2.1
	*
	* @return       An error code
	* @param[in]    enable               Set to @c true to enable the notification tray to remain open, @n
	*                                      else @c false
	* @exception    E_SUCCESS            The method is successful.
	* @exception    E_INVALID_OPERATION        The current state of the instance prohibits the execution of a specified operation. @n
	*					If the style of %Form is not ::FORM_STYLE_INDICATOR or ::FORM_STYLE_INDICATOR_AUTO_HIDE,
	*					the method returns @c E_INVALID_OPERATION.
	* @remarks      If this method is not explicitly called, the notification tray is opened.
	* @see            IsNotificationTrayOpenEnabled()
	*/
	result SetNotificationTrayOpenEnabled(bool enable);


	/**
	* Checks whether the notification tray is open or not.
	*
	* @since 2.1
	*
	* @return         @c true if the notification tray is open, @n
	*                 else @c false
	* @exception      E_SUCCESS            The method is successful.
	* @exception     E_INVALID_OPERATION        The current state of the instance prohibits the execution of a specified operation. @n
	*					If the style of %Form is not ::FORM_STYLE_INDICATOR or ::FORM_STYLE_INDICATOR_AUTO_HIDE,
	*					the method returns @c E_INVALID_OPERATION.
	* @remarks        The specific error code can be accessed using the GetLastResult() method.
	* @see            SetNotificationTrayOpenEnabled()
	*/
	bool IsNotificationTrayOpenEnabled(void) const;

protected:
	friend class _FormImpl;

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void Form_Reserved1(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void Form_Reserved2(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// @since 2.0
	//
	virtual void Form_Reserved3(void) { }

// Friend Class Declaration
private:
	friend class UiBuilder;
	friend class Frame;

private:
	Form(const Form&);
	Form& operator =(const Form&);

}; // Form

} } } // Tizen::Ui::Controls

#endif // _FUI_CTRL_FORM_H_
