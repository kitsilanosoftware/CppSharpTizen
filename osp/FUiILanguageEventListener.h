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
 * @file	FUiILanguageEventListener.h
 * @brief	This is the header file for the %ILanguageEventListener interface.
 *
 * This header file contains the declarations of the %ILanguageEventListener interface.
 */

#ifndef _FUI_ILANGUAGE_EVENT_LISTENER_H_
#define _FUI_ILANGUAGE_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FLclLocale.h>

namespace Tizen {namespace Ui
{

class Control;

/**
 * @interface  ILanguageEventListener
 * @brief      This interface implements the listener for the language event.
 *
 * @since		2.0
 *
 * The %ILanguageEventListener interface receives language events. The class that processes a language event
 * implements this interface, and the instance created with that class is registered with a UI control, using the control's
 * AddLanguageEventListener() method.
 *
 * When the current input language is changed (for example, when the user toggles the input language from the virtual
 * keypad), the listener's OnLanguageChanged() method is invoked.
 */

class _OSP_EXPORT_ ILanguageEventListener
	: public Tizen::Base::Runtime::IEventListener
{

// Operation

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since				2.0
	 */
	ILanguageEventListener(void) {};

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since				2.0
	 */
	virtual ~ILanguageEventListener(void) {}

	/**
	 * Called when the input language is changed.
	 *
	 * @since		2.0
	 *
	 * @param[in]   source              The source of the event
	 * @param[in]   oldLanguage    The previous input language
	 * @param[in]   newLanguage     The current input language
	 */
	virtual void OnLanguageChanged(const Tizen::Ui::Control& source, Tizen::Locales::LanguageCode oldLanguage, Tizen::Locales::LanguageCode newLanguage) = 0;

// Reserves
protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ILanguageEventListener_Reserved1(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ILanguageEventListener_Reserved2(void) { }

	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void ILanguageEventListener_Reserved3(void) { }
}; // ILanguageEventListener

}} // Tizen::Ui

#endif
