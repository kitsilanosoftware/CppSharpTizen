//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
 * @file FUiImeIInputMethodProviderF.h
 * @brief This is the header file for the %IInputMethodProviderF interface.
 *
 * This header file contains the declarations of the %IInputMethodProviderF interface.
 */

#ifndef _FUI_IME_IINPUT_METHOD_PROVIDER_F_H_
#define _FUI_IME_IINPUT_METHOD_PROVIDER_F_H_

#include <FGrpFloatRectangle.h>
#include <FLclLocale.h>
#include <FOspConfig.h>
#include <FUiInputConnectionTypes.h>

namespace Tizen { namespace Ui { namespace Ime {

/**
 * @interface	IInputMethodProviderF
 * @brief	This interface is for the InputMethod class that interacts with the associated text input UI control.
 * @since	2.1
 *
 * @remarks The IME application developers can implement a class derived from %IInputMethodProviderF and set it as the provider of the InputMethod class.
 * The IME application can then provide attributes for the soft input panel and operate according to the commands of the associated text input UI control. For
 * example, when ShowInputPanel() or HideInputPanel() are called, the IME application's frame should either be hidden or made visible.
 *
 * The %IInputMethodProviderF interface is for the InputMethod class that interacts with the associated text input UI control.
 *
 * The following example demonstrates how to use the %IInputMethodProviderF interface.
 * @code
 * #include <FUi.h>
 *
 * class MyProvider
 * 	: public IInputMethodProviderF
 * {
 * 	//...
 *	virtual Tizen::Graphics::FloatRectangle GetInputPanelBounds(void); 
 *	virtual void HideInputPanel(void); 
 *	virtual void ShowInputPanel(void); 
 * 	//...
 * };
 * @endcode
 *
 */
class _OSP_EXPORT_ IInputMethodProviderF
{
public:
	/**
	* This polymorphic destructor should be overridden if required. @n This way, the destructors of the derived classes are called when the destructor of this
	* interface is called.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*/
	virtual ~IInputMethodProviderF(void) {}

	/**
	* Called when an associated text input UI control requests for the enter key action of the input panel.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return The enter key action of the input panel
	*/
	virtual Tizen::Ui::InputPanelAction GetEnterKeyAction(void)
	{
		return Tizen::Ui::INPUT_PANEL_ACTION_ENTER;
	}

	/**
	* Called when an associated text input UI control requests for the position and size of the input panel.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return The position and size of the input panel
	* @remarks The associated text input UI control can change its position on the screen to avoid becoming positioned behind the input panel.
	*/
	virtual Tizen::Graphics::FloatRectangle GetInputPanelBounds(void) = 0;

	/**
	* Called when an associated text input UI control requests for the style of the input panel.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return A style of the input panel
	*/
	virtual Tizen::Ui::InputPanelStyle GetInputPanelStyle(void)
	{
		return Tizen::Ui::INPUT_PANEL_STYLE_NORMAL;
	}

	/**
	* Called when the associated text input UI control requests for the language of the input method.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return A language of the input method
	*/
	virtual Tizen::Locales::Locale GetLanguage(void)
	{
		return Tizen::Locales::Locale(Tizen::Locales::LANGUAGE_ENG, Tizen::Locales::COUNTRY_US);
	}

	/**
	* Called when an associated text input UI control requests the input panel to enable or disable the caps mode.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @param[in] enable The state of the caps mode
	*/
	virtual void SetCapsModeEnabled(bool enable) {}

	/**
	* Called when an associated text input UI control requests the input panel to set the enter key action. @n
	* The input panel can show text on the enter button according to the enter key action.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @param[in] action The enter key action
	*/
	virtual void SetEnterKeyAction(Tizen::Ui::InputPanelAction action) {}

	/**
	* Called when an associated text input UI control requests the input panel to enable or disable the enter key action.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @param[in] enable The state of the enter key action
	*/
	virtual void SetEnterKeyActionEnabled(bool enable) {}

	/**
	* Called when an associated text input UI control requests the input panel to set its style.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @param[in] style The style of the input panel
	*/
	virtual void SetInputPanelStyle(Tizen::Ui::InputPanelStyle style) {}

	/**
	* Called when an associated text input UI control requests the input panel to hide itself.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*/
	virtual void HideInputPanel(void) = 0;

	/**
	* Called when an associated text input UI control checks whether the enter key action is enabled or not.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*
	* @return The state of the enter key action
	*/
	virtual bool IsEnterKeyActionEnabled(void)
	{
		return false;
	}

	/**
	* Called when an associated text input UI control requests the input panel to show itself.
	*
	* @since 2.1
	* @privlevel partner
	* @privilege %http://tizen.org/privilege/ime
	*/
	virtual void ShowInputPanel(void) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void IInputMethodProviderF_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void IInputMethodProviderF_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void IInputMethodProviderF_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void IInputMethodProviderF_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.1
	//
	virtual void IInputMethodProviderF_Reserved5(void) {}
};

}}} // Tizen::Ui::Ime

#endif // _FUI_IME_IINPUT_METHOD_PROVIDER_F_H_