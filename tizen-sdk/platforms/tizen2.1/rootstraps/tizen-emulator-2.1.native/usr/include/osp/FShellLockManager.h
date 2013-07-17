//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
 * @file		FShellLockManager.h
 * @brief		This is the header file for the %LockManager class.
 *
 * This header file contains the declarations of the %LockManager class.
 */

#ifndef _FSHELL_LOCK_MANAGER_H_
#define _FSHELL_LOCK_MANAGER_H_

#include <unique_ptr.h>
#include <FBaseObject.h>

namespace Tizen { namespace Shell {

/**
 * @class		LockManager
 * @brief		This class manages state of lock screen.
 *
 * @since	2.1
 *
 * @final		This class is not intended for extension.
 *
 * The %LockManager class manages state of lock screen.
 */
class _OSP_EXPORT_ LockManager
	: public Tizen::Base::Object
{
public:
	/**
	 * Gets the %LockManager instance.
	 *
	 * @since	2.1
	 *
	 * @return	A pointer to the %LockManager instance, @n
	 *			else @c null if it fails
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	static LockManager* GetInstance(void);

	/**
	 * Checks whether the screen is locked.
	 *
	 * @since	2.1
	 *
	 * @return	@c true if the screen is locked,
	 *           else @c false
	 */
	bool IsLocked(void) const;

	/**
	 * Checks whether password lock screen is enabled by Settings.
	 *
	 * @since	2.1
	 *
	 * @return	@c true if password lock screen is enabled,
	 *           else @c false
	 */
	bool IsSecureMode(void) const;

	/**
	 * Unlocks current lock screen.
	 *
	 * @since	2.1
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/lockmanager
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_INVALID_OPERATION	The application cannot unlock because the secure mode is enabled.
	 * @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	 * @remarks		This method call has no effect while secure mode is enabled. 
	 */
	result Unlock(void);

private:
	//
	// This default constructor is intentionally declared as private to implement the %Singleton semantic.
	//
	// @since	2.1
	//
	LockManager(void);

	//
	// This destructor is intentionally declared as private to implement the %Singleton semantic.
	//
	// @since	2.1
	//
	virtual ~LockManager(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	LockManager(const LockManager& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	LockManager& operator =(const LockManager& rhs);

	//
	// Constructs the instance of this class.
	//
	// @since	2.1
	//
	// @return	    An error code
	// @exception	E_SUCCESS	The method is successful.
	// @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	//
	result Construct(void);

	static void InitSingleton(void);
	static void DestroySingleton(void);

private:
	
	static LockManager* __pTheInstance;
	friend struct std::default_delete< LockManager >;
	class _LockManagerImpl* __pLockManagerImpl;
};

}} // Tizen::Shell
#endif /* _FSHELL_LOCK_MANAGER_H_ */
