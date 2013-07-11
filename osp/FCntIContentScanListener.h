//
// Open Service Platform
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
 * @file		FCntIContentScanListener.h
 * @brief		This is the header file for the %_IContentScanListener interface.
 *
 * This header file contains the declarations of the %_IContentScanListener interface.
 */

#ifndef _FCNT_ICONTENT_SCAN_LISTENER_H_
#define _FCNT_ICONTENT_SCAN_LISTENER_H_

#include <FBaseString.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Content
{

class _OSP_EXPORT_ _IContentScanListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
		virtual ~_IContentScanListener(void) {}
		virtual void OnContentScanCompleted(const Tizen::Base::String& scanPath, result r) = 0;

protected:
		virtual void _IContentScanListener_Reserved1(void) {}
		virtual void _IContentScanListener_Reserved2(void) {}

};  // class _IContentScanListener

}}

#endif // _FCNT_ICONTENT_SCAN_LISTENER_H_
