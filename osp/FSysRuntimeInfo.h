//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
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
 * @file	FSysRuntimeInfo.h
 * @brief	This is the header file for the %RuntimeInfo class.
 *
 * This header file contains the declarations of the %RuntimeInfo class.
 */

#ifndef _FSYS_RUNTIME_INFO_H_
#define _FSYS_RUNTIME_INFO_H_

#include <FBaseString.h>
#include <FBaseUuId.h>
#include <FBaseColIList.h>

namespace Tizen { namespace System
{

class IRuntimeInfoGetIntAsyncResultListener;
class IRuntimeInfoGetLonglongAsyncResultListener;

/**
 * @class	RuntimeInfo
 * @brief	This class provides methods for getting runtime information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %RuntimeInfo class provides runtime information, such as the allocated memory used by the application storage, memory, and CPU utilization. To get the information, you must provide the <a href="../org.tizen.native.appprogramming/html/guide/system/runtime_info.htm">RuntimeInfo key</a>.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/system/runtime_info.htm">Runtime Information</a>.
 *
 * The following example demonstrates how to use the %RuntimeInfo class.
 * @code
 * #include <FBase.h>
 * #include <FSystem.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::System;
 *
 * result
 * MyClass::GetAllocatedMemory(void)
 * {
 *	 result r = E_SUCCESS;
 *
 *	 String key(L"http://tizen.org/runtime/memory.allocated");
 *	 int allocatedMemory = 0;
 *
 *	 r = RuntimeInfo::GetValue(key, allocatedMemory);
 *	 TryCatch(r == E_SUCCESS, , "MyRuntimeInfo: Failed to get value");
 *
 *	 return E_SUCCESS;
 *
 *	CATCH:
 *	 return r;
 * }
 * @endcode
 *
 */

class _OSP_EXPORT_ RuntimeInfo
	: public Tizen::Base::Object
{

public:
	/**
	 * Gets the specific Tizen::Base::String type runtime information based on the specified
	 * designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/runtime_info.htm">key name</a> of the runtime information
	 * @param[out]	value			The runtime information of type Tizen::Base::String
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception   E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, Tizen::Base::String& value);

	/**
	 * Gets the specific integer type runtime information based on the specified
	 * designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/runtime_info.htm">key name</a> of the runtime information @n
	 * @if OSPCOMPAT
	 *			The following key values are updated: @n
	 *			- @b Since: @b 2.0 Refer <a href="../org.tizen.native.appprogramming/html/guide/system/runtime_info.htm">here</a>.
	 *			  @xmlonly <pcheck kind="value" since="2.0"> memory.allocated, memory.available </pcheck> @endxmlonly
	 *			- @b Deprecated All the key values provided prior to %Tizen 2.0 are deprecated. For more detailed information, refer 
	 *			 <a href="../org.tizen.native.appprogramming/html/guide/system/runtime_info_deprecated.htm">here</a>.
	 * @endif
	 * @param[out]	value			The integer type runtime information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception   E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, int& value);

	/**
	 * Gets the specific @c long @c long type runtime information based on the specified
	 * designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/runtime_info.htm">key name</a> of the runtime information @n
	 * @if OSPCOMPAT
	 *			The following key values are updated: @n
	 *			- @b Since: @b 2.0 Refer <a href="../org.tizen.native.appprogramming/html/guide/system/runtime_info.htm">here</a>.
	 *			  @xmlonly <pcheck kind="value" since="2.0"> storage.external.available, storage.internal.available, storage.media.available </pcheck> @endxmlonly
	 *			- @b Deprecated All the key values provided prior to %Tizen 2.0 are deprecated. For more detailed information, refer 
	 *			 <a href="../org.tizen.native.appprogramming/html/guide/system/runtime_info_deprecated.htm">here</a>.
	 *			 @xmlonly <pcheck kind="value" since="1.0" deprecated="yes"> @endxmlonly MaxAllocatableMemory, AvailableVideoMemory @xmlonly </pcheck> @endxmlonly
	 * @endif
	 * @param[out]	value			The @c long @c long type runtime information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception   E_SYSTEM		The method cannot proceed due to a severe system error.
	*/
	static result GetValue(const Tizen::Base::String& key, long long& value);

	/**
	 * Gets the specific double type runtime information based on the specified
	 * designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/runtime_info.htm">key name</a> of the runtime information
	 * @param[out]	value			The @c double type runtime information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception   E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, double& value);

	/**
	 * Gets the specific @c bool type runtime information based on the specified
	 * designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key			The key name of the runtime information
	 * @param[out]	value			The @c bool type runtime information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception   E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, bool& value);

	/**
	 * Gets the specific UuId type runtime information based on the specified
	 * designators (key).
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	The <a href="../org.tizen.native.appprogramming/html/guide/system/runtime_info.htm">key name</a> of the runtime information
	 * @param[out]	value			The UuId type runtime information
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 * @exception   E_SYSTEM		The method cannot proceed due to a severe system error.
	 */
	static result GetValue(const Tizen::Base::String& key, Tizen::Base::UuId& value);

	/**
	 * Gets the specific @c long @c long type runtime information based on specified designators (key) asynchronously.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key 		The key of the runtime information
	 * @param[in]	listener	The result listener
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception   E_SYSTEM	The method cannot proceed due to a severe system error.
	 * @remarks	The listener instance ownership is transferred to platform. After notifying result, listener instance is removed automatically. A reuse of the listener instance is not allowed.
	 */
	static result GetValueAsync(const Tizen::Base::String& key, IRuntimeInfoGetLonglongAsyncResultListener* listener);

	/**
	 * Gets the specific @c int type runtime information based on specified designators (key) asynchronously.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key 		The key of the runtime information
	 * @param[in]	listener	The result listener
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception   E_SYSTEM	The method cannot proceed due to a severe system error.
	 * @remarks	The listener instance ownership is transferred to platform. After notifying result, listener instance is removed automatically. A reuse of the listener instance is not allowed.
	 */
	static result GetValueAsync(const Tizen::Base::String& key, IRuntimeInfoGetIntAsyncResultListener* listener);

private:
	/**
	 * This is the default constructor for this class. This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	RuntimeInfo(void);

	/**
	 * This is the destructor for this class. This destructor overrides Tizen::Base::Object::~Object().
	 */
	virtual ~RuntimeInfo(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	RuntimeInfo(const RuntimeInfo& value);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	RuntimeInfo& operator =(const RuntimeInfo& value);

private:
	friend class _RuntimeInfoImpl;
	class _RuntimeInfoImpl* __pRuntimeInfoImpl;
}; // RuntimeInfo

} } // Tizen::System

#endif // _FSYS_RUNTIME_INFO_H_
