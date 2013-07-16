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
 * @file FUiImeInputMethodInfo.h
 * @brief	This is the header file for the %InputMethodInfo class.
 *
 * This header file contains the declarations of the %InputMethodInfo class.
 */

#ifndef _FUI_IME_INPUT_METHOD_INFO_H_
#define _FUI_IME_INPUT_METHOD_INFO_H_

#include <FAppTypes.h>
#include <FBaseColIList.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FOspConfig.h>
#include <FUiImeTypes.h>

namespace Tizen { namespace Ui { namespace Ime {

class _InputMethodInfoImpl;

/**
 * @class InputMethodInfo
 * @brief This class provides a standard implementation of the %InputMethodInfo class.
 * @since 2.1
 *
 * @final This class is not intended for extension.
 * @remarks A user can get the general information of the input method.
 *
 * The %InputMethodInfo class provides a standard implementation of the %InputMethodInfo class.
 *
 */
class _OSP_EXPORT_ InputMethodInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.1
	 * @privlevel platform
	 * @privilege %http://tizen.org/privilege/imemanager
	 */
	virtual ~InputMethodInfo(void);

	/**
	 * Gets the application ID of an input method.
	 *
	 * @since 2.1
	 * @privlevel platform
	 * @privilege %http://tizen.org/privilege/imemanager
	 *
	 * @return The application ID
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 */
	Tizen::App::AppId GetAppId(void) const;

	/**
	 * Gets the language list that an input method supports.
	 *
	 * @since 2.1
	 * @privlevel platform
	 * @privilege %http://tizen.org/privilege/imemanager
	 *
	 * @return An instance of the language list that consists of the Tizen::Locales::Locale instances
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @remarks The %InputMethodInfo instance automatically deallocates the memory assigned to the language list when it is destroyed. Therefore, a user must not
	 * manually deallocate the memory assigned to the language list.
	 */
	const Tizen::Base::Collection::IList* GetLanguageList(void) const;

	/**
	 * Gets the name of an input method.
	 *
	 * @since 2.1
	 * @privlevel platform
	 * @privilege %http://tizen.org/privilege/imemanager
	 *
	 * @return The name of an input method
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * Gets the type of an input method.
	 *
	 * @since 2.1
	 * @privlevel platform
	 * @privilege %http://tizen.org/privilege/imemanager
	 *
	 * @return The type of an input method
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 */
	InputMethodType GetType(void) const;

private:
	//
	// This Equals() is intentionally declared as private so that only the platform can compare the object received as an input parameter with this object.
	//
	// @since 2.1
	//
	// @return @c true if the object received as an input parameter equals this object, @n
	// else @c false
	// @param[in]	object A reference to the %InputMethodInfo
	//
	virtual bool Equals(const Object& object) const;

	//
	// This default constructor is intentionally declared as private so that only the platform can create an instance.
	//
	// @since 2.1
	//
	InputMethodInfo(void);

	//
	// This copy constructor is intentionally declared as private so that only the platform can copy objects.
	//
	// @since 2.1
	//
	// @param[in]	info A reference to the %InputMethodInfo
	//
	InputMethodInfo(const InputMethodInfo& info);

	//
	// This copy assignment operator is intentionally declared as private so that only the platform can copy objects.
	//
	// @since 2.1
	//
	// @param[in]	info A reference to the %InputMethodInfo
	//
	InputMethodInfo& operator=(const InputMethodInfo& info);

private:
	friend class _InputMethodInfoImpl;
	friend class _InputMethodManagerImpl;

	_InputMethodInfoImpl* __pInputMethodInfoImpl;
};

}}} // Tizen::Ui::Ime

#endif // _FUI_IME_INPUT_METHOD_INFO_H_
