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
 * @file FUiImeInputMethodManager.h
 * @brief This is the header file for the %InputMethodManager class.
 *
 * This header file contains the declarations of the %InputMethodManager class.
 */

#ifndef _FUI_IME_INPUT_METHOD_MANAGER_H_
#define _FUI_IME_INPUT_METHOD_MANAGER_H_

#include <FAppTypes.h>
#include <FBaseColIList.h>
#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FOspConfig.h>
#include <FUiImeInputMethodInfo.h>

namespace Tizen { namespace Ui { namespace Ime {

class _InputMethodManagerImpl;

/**
 * @class	InputMethodManager
 * @brief	This class provides a standard implementation of the %InputMethodManager class.
 * @since 2.1
 *
 * @final This class is not intended for extension.
 * @remarks A user can manage input methods installed in the system.
 *
 * The %InputMethodManager class provides a standard implementation of the %InputMethodManager class.
 *
 */
class _OSP_EXPORT_ InputMethodManager
	: public Tizen::Base::Object
{
public:
	/**
	 * Gets an instance of %InputMethodManager.
	 *
	 * @since 2.1
	 * @privlevel platform
	 * @privilege %http://tizen.org/privilege/imemanager
	 *
	 * @return An instance of %InputMethodManager 
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @remarks 
	 * - The specific error code can be accessed using the GetLastResult() method.
	 * - There is a high probability for an occurrence of an out-of-memory exception. @n If possible, check whether the exception is @c E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	 */
	static InputMethodManager* GetInstance(void);

	/**
	 * Gets the %InputMethodInfo of the active input method.
	 *
	 * @since 2.1
	 * @privlevel platform
	 * @privilege %http://tizen.org/privilege/imemanager
	 *
	 * @return An instance of the InputMethodInfo @n
	 *			This method returns @c null if it fails.
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	InputMethodInfo* GetActiveInputMethodInfoN(void) const;

	/**
	 * Gets the list of InputMethodInfo for all the input methods installed in a system.
	 *
	 * @since 2.1
	 * @privlevel platform
	 * @privilege %http://tizen.org/privilege/imemanager
	 *
	 * @return An instance of the list that consists of the InputMethodInfo instances
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetInputMethodInfoListN(void) const;

	/**
	 * Sets an input method.
	 *
	 * @since 2.1
	 * @privlevel platform
	 * @privilege %http://tizen.org/privilege/imemanager
	 *
	 * @return An error code
	 * @param[in]	id An application ID
	 * @exception	E_SUCCESS The method is successful.
	 * @exception E_APP_NOT_INSTALLED The specified ID does not match with any of the application IDs for the input methods installed in the system.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 */
	result SetInputMethod(const Tizen::App::AppId& id);

	/**
	 * Checks whether an input method is active or not.
	 *
	 * @since 2.1
	 * @privlevel platform
	 * @privilege %http://tizen.org/privilege/imemanager
	 *
	 * @return @c true if the input method is active, @n
	 *             else @c false
	 * @param[in]	id An application ID
	 * @exception E_SUCCESS The method is successful.
	 * @exception E_PRIVILEGE_DENIED The application does not have the privilege to call this method.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsActiveInputMethod(const Tizen::App::AppId& id) const;

private:
	//
	// This default constructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @since 2.1
	//
	InputMethodManager(void);

	//
	// This destructor is intentionally declared as private to implement the Singleton semantic.
	//
	// @since 2.1
	//
	virtual ~InputMethodManager(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.1
	//
	InputMethodManager(const InputMethodManager& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.1
	//
	InputMethodManager& operator=(const InputMethodManager& rhs);

private:
	friend class _InputMethodManagerImpl;

	_InputMethodManagerImpl* __pInputMethodManagerImpl;
};

}}} // Tizen::Ui::Ime

#endif // _FUI_IME_INPUT_METHOD_MANAGER_H_
