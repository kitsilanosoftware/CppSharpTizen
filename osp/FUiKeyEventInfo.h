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
 * @file FUiKeyEventInfo.h
 * @brief          This is the header file for the %KeyEventInfo class.
 *
 * This header file contains the declarations of the %KeyEventInfo class.
 *
 */

#ifndef _FUI_KEY_EVENT_INFO_H_
#define _FUI_KEY_EVENT_INFO_H_

#include <FBaseObject.h>
#include <FUiKeyTypes.h>

namespace Tizen { namespace Ui
{

class Control;
class _KeyEventInfoImpl;

/**
 * @class          KeyEventInfo
 * @brief                     This class stores the information of each key events.
 *
 * @since         2.1
 *
 * The %KeyEventInfo class provides the key event information: key code and key modifiers.
 * @see     IPropagatedKeyEventListener::OnKeyPressed()
 * @see	  IPropagatedKeyEventListener::OnKeyReleased()
 * @see	  IPropagatedKeyEventListener::TranslateKeyEventInfo()
 *
 */
class _OSP_EXPORT_ KeyEventInfo
           : public Tizen::Base::Object
{
public:
	/**
	 * Initializes this instance of %KeyEventInfo.
	 *
	 * @since       2.1
	 *
	 * @param[in]   keyCode                                The key code that represents the key of interest
	 * @param[in]   keyModifiers                                The key modifier that modifies the normal action of the key
	 * @see Tizen::Ui::KeyCode
	 * @see Tizen::Ui::KeyModifier
	 */
	KeyEventInfo(KeyCode keyCode, int keyModifiers);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since              2.1
	 */
	virtual ~KeyEventInfo(void);

	/**
	 * Sets the key code.
	 *
	 * @since                               2.1
	 *
	 * @param[in]    keyCode         The key code
	 * @see         GetKeyCode()
	 *
	 */
	void SetKeyCode(KeyCode keyCode);

	/**
	 * Gets the key code.
	 *
	 * @since         2.1
	 *
	 * @return  The key code
	 * @see         SetKeyCode()
	 */
	KeyCode GetKeyCode(void) const;

	/**
	 * Sets the bitwise ORed key modifiers of the keyboard such as Control, Shift, Numeric lock, and so on.
	 *
	 * @since                               2.1
	 *
	 * @param[in]    keyModifiers         The key modifiers that can be combined using the bitwise OR operator
	 * @see         GetKeyModifier()
	 * @see Tizen::Ui::KeyModifier
	 *
	 */
	void SetKeyModifier(int keyModifiers);

	/**
	 * Gets the key modifiers of the keyboard such as Control, Shift, Numeric lock, and so on.
	 *
	 * @since         2.1
	 *
	 * @return  The bitwise ORing key modifiers
	 * @see         SetKeyModifier()
	 * @see Tizen::Ui::KeyModifier
	 */
	int GetKeyModifier(void) const;

private:
	/*
	 * This is the default constructor for this class.
	 *
	 * @since              2.1
	 */
	KeyEventInfo(void);

	/*
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since              2.1
	 */
	KeyEventInfo(const KeyEventInfo& rhs);

	/*
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since              2.1
	 */
	KeyEventInfo& operator =(const KeyEventInfo& rhs);

private:
	_KeyEventInfoImpl* __pKeyEventInfoImpl;

}; // KeyEventInfo

} } // Tizen::Ui

#endif // _FUI_KEY_EVENT_INFO_H_
