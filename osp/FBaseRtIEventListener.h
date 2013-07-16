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
 * @file			FBaseRtIEventListener.h
 * @brief			This is the header file for the %IEventListener interface.
 *
 * This header contains the declarations of the %IEventListener interface.
 */
#ifndef _FBASE_RT_I_EVENT_LISTENER_H_
#define _FBASE_RT_I_EVENT_LISTENER_H_


#include <FBaseResult.h>


namespace Tizen { namespace Base { namespace Runtime
{

/**
 * @interface IEventListener
 * @brief  This is a tagging interface that all event listeners must implement.
 *
 * @since 2.0
 *
 * The %IEventListener interface is a tagging interface that all event listeners must implement.
 * The event listener can listen when the specific event occurs. The event listener
 * has several methods, and each method is called when a specific event occurs.
 *
 */
class _OSP_EXPORT_ IEventListener
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~IEventListener(void);
}; // IEventListener

} } } // Tizen::Runtime

#endif // _FBASE_RT_I_EVENT_LISTENER_H_
