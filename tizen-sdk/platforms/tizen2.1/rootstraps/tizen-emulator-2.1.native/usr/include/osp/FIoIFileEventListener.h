//
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
 * @file	FIoIFileEventListener.h
 * @brief	This is the header file for the %IFileEventListener interface.
 *
 * This header file contains the declarations of the %IFileEventListener interface.
 */

#ifndef _FIO_IFILE_EVENT_LISTENER_H_
#define _FIO_IFILE_EVENT_LISTENER_H_

#include <FBaseString.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Io
{

/**
* @interface    IFileEventListener
* @brief        This listener interface is used for receiving file event.
*
* @since        2.0
*
* The %IFileEventListener interface is used for receiving file event.
*/
class _OSP_EXPORT_ IFileEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	* Called when a monitored file or directory is changed.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	events		The file event type @n
	*				Multiple event type can be combined using bitwise OR (see Tizen::Io::FileEventType). @n
	*				Tizen::Io::FILE_EVENT_TYPE_ALL is provided for all file event type.
	* @param[in]	path		The path to the directory or file where the event has occurred
	* @param[in]	eventId		The event ID associating related events for single operation such as File::Move(), Directory::Rename()
	*/
	virtual void OnFileEventOccured(const unsigned long events, const Tizen::Base::String& path, const unsigned int eventId) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IFileEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IFileEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void IFileEventListener_Reserved3(void) {}

}; // IFileEventListener

}} // Tizen::Io

#endif //_FIO_IFILE_EVENT_LISTENER

