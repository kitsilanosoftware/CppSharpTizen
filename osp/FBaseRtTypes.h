//
// Open Service Platform
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
 * @file		FBaseRtTypes.h
 * @brief		This is the header file for types in the Runtime package.
 *
 * This header file defines the types in the Runtime package.
 */
#ifndef _FBASE_RT_TYPES_H_
#define _FBASE_RT_TYPES_H_

#include <FBaseTypes.h>

namespace Tizen { namespace Base { namespace Runtime
{

/**
* This method is for internal use only. Using this method can cause behavioral, security-related,
* and consistency-related issues in the application.
*
* @since 2.0
*/
enum TimerStatus
{
	TIMER_STATUS_NOT_ACTIVATED, // This enum value is for internal use only. Using this enum can cause behavioral, security-related, and consistency-related issues in the application.
	TIMER_STATUS_ACTIVATED,     // This enum value is for internal use only. Using this enum can cause behavioral, security-related, and consistency-related issues in the application.
	TIMER_STATUS_CANCELED,      // This enum value is for internal use only. Using this enum can cause behavioral, security-related, and consistency-related issues in the application.
	TIMER_STATUS_EXPIRED,       // This enum value is for internal use only. Using this enum can cause behavioral, security-related, and consistency-related issues in the application.
	TIMER_STATUS_ACTIVATED_REPEATABLE,       // This enum value is for internal use only. Using this enum can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
* @struct	TryTag
* @brief	This struct is used only for supporting non-blocking acquisition of a resource
*
* This struct is used for just discriminating between blocking and non-blocking acquisition
* of a resource. So, the definition is empty.
*
* @since 2.0
*
* @see		MutexGuard, SemaphoreGuard, Try
*/
struct TryTag
{
};

/**
* @brief	Used only for for just discriminating between blocking and non-blocking acquisition
*
* @code
* Mutex m;
* m.Create();
* {
*     MutexGuard guard(m, Try);
*     // Access to shared resources
* }
*
* Semaphore s;
* s.Create();
* {
*     SemaphoreGuard guard(s, Try);
*     // Access to multiple shared resources
* }
* @endcode
*/
static const TryTag Try = {};

} } } // Tizen::Runtime

#endif // _FBASE_RT_TYPES_H_
