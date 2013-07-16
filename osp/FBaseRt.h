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
 * @file			FBaseRt.h
 * @brief			This is the header file for the %Runtime namespace.
 *
 * This header file contains the declarations of the %Runtime namespace.
 *
 */

#ifndef _FBASE_RT_H_
#define _FBASE_RT_H_

#include <FBaseRtEvent.h>
#include <FBaseRtEventDrivenThread.h>
#include <FBaseRtIEventArg.h>
#include <FBaseRtIEventListener.h>
#include <FBaseRtITimerEventListener.h>
#include <FBaseRtLibrary.h>
#include <FBaseRtMemoryManager.h>
#include <FBaseRtMonitor.h>
#include <FBaseRtMonitorGuard.h>
#include <FBaseRtMutex.h>
#include <FBaseRtMutexGuard.h>
#include <FBaseRtSemaphore.h>
#include <FBaseRtSemaphoreGuard.h>
#include <FBaseRtThread.h>
#include <FBaseRtTimer.h>
#include <FBaseRtTypes.h>

/**
 * @namespace	Tizen::Base::Runtime
 * @brief		This namespace contains classes for running applications.
 * @since 2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FBase.h> @n
 *				@b Library : @b osp-appfw
 *
 *
 * The %Runtime namespace contains classes for running applications.
 * The runtime environment includes threading, synchronization objects,
 * and timer.
 *
 * For more information on the %Base::Runtime namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/base/runtime_namespace.htm">Runtime</a>.
 *
 *	The following diagram illustrates the relationships between the classes belonging to the %Runtime namespace.
 *	@image html base_runtime_namespace_classdiagram.png
 *
 *
 *
 */

namespace Tizen { namespace Base { namespace Runtime
{

}}} // Tizen::Base::Runtime

#endif // _FBASE_RT_H_
