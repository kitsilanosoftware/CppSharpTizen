//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FBaseRtMemoryManager.h
 * @brief	This is the header file for the %MemoryManager class.
 *
 * This header file contains the declarations of the %MemoryManager class.
 */

#ifndef _FBASE_RT_MEMORY_MANAGER_H_
#define _FBASE_RT_MEMORY_MANAGER_H_

#include <FBase.h>
#include <FBaseObject.h>

namespace Tizen { namespace Base { namespace Runtime {

/**
 * @enum         MemoryProtectionMode
 *
 * Defines the memory protection modes.
 *
 * @since 2.0
 */
enum MemoryProtectionMode
{
	MEMORY_PROTECTION_MODE_NONE   = 0x0,   /**< The memory cannot be accessed */
	MEMORY_PROTECTION_MODE_READ   = 0x1,  /**< The memory can be read */
	MEMORY_PROTECTION_MODE_WRITE  = 0x2,  /**< The memory can be modified */
	MEMORY_PROTECTION_MODE_EXEC  = 0x4,  /**< The memory can be executed */
};

/**
 *  @class		MemoryManager
 *	@brief	This class represents a memory manager for runtime.
 *
 *	@since 2.0
 *
 *  The %MemoryManager class represents a memory manager for runtime.
 *
 *  The following example demonstrates how to use the %MemoryManager class.
 *
 *  @code
 *  #include <FBase.h>
 *
 *  using namespace Tizen::Base::Runtime;
 *
 *  result
 *  MyApp::Execute(void)
 *  {
 *		result r = E_SUCCESS;
 *		int size = 1024;
 *		void* pMemory = (void*)malloc(4096);
 *
 *		// Sets to an aligned page
 *		pMemory = (void*)(((int)pMemory + size) & ~(size - 1));
 *
 *		// Prepares for execution
 *		r = MemoryManager::ProtectMemory(pMemory, size, MEMORY_PROTECTION_MODE_EXEC);
 *		if (IsFailed(r))
 *		{
 *				// Failed to change memory protection
 *		}
 *
 *		// Executes code in the memory
 *
 *  }
 *
 *  @endcode
 */
class _OSP_EXPORT_ MemoryManager
{
public:
	/**
	 * Changes protection on a memory region.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   pAddress        The start address of the memory region aligned on a page boundary.
	 * @param[in]   length          The length of the memory region in bytes
	 * @param[in]   protection      The memory protection @n
	 *                              It is either Tizen::Base::Runtime::MEMORY_PROTECTION_MODE_NONE or a bitwise OR of the
	 *                              other values in Tizen::Base::Runtime::MemoryProtectionMode.
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_SYSTEM        A system error has occurred due to an invalid address.
	 * @exception   E_INVALID_ARG   The memory address is not valid, or the length is not a multiple of system page size.
	 */
	static result ProtectMemory(const void* pAddress, long long length, unsigned long protection);

private:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	MemoryManager(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	~MemoryManager(void);

}; // MemoryManager

} } } // Tizen::Base::Runtime

#endif // _FBASE_RT_MEMORY_MANAGER_H_
