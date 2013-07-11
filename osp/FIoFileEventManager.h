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
 * @file	FIoFileEventManager.h
 * @brief	This is the header file for the %FileEventManager class.
 *
 * This header file contains the declarations of the %FileEventManager class.
 */

#ifndef _FIO_FILE_EVENT_MANAGER_H_
#define _FIO_FILE_EVENT_MANAGER_H_

#include <FBaseObject.h>

namespace Tizen { namespace Base
{
class String;
}}

namespace Tizen { namespace Io
{

class IFileEventListener;
class _FileEventManagerImpl;

/**
 * @enum FileEventType
 *
 * Defines the file event type.
 *
 * @since	2.0
 */
enum FileEventType
{
	FILE_EVENT_TYPE_ACCESS = 0x01, /**<%File was accessed (read)*/
	FILE_EVENT_TYPE_ATTRIBUTE = 0x04, /**<Metadata changed*/
	FILE_EVENT_TYPE_CLOSE_WRITE = 0x08, /**<%File opened for writing was closed*/
	FILE_EVENT_TYPE_CLOSE_NOWRITE = 0x10, /**<%File not opened for writing was closed*/
	FILE_EVENT_TYPE_CREATE = 0x100, /**<%File/directory created in monitored directory*/
	FILE_EVENT_TYPE_DELETE = 0x200, /**<%File/directory deleted from monitored directory*/
	FILE_EVENT_TYPE_DELETE_SELF = 0x400, /**<Monitored file/directory was itself deleted.*/
	FILE_EVENT_TYPE_MODIFY = 0x02, /**<%File was modified*/
	FILE_EVENT_TYPE_MOVE_SELF = 0x800, /**<Monitored file/directory was itself moved.*/
	FILE_EVENT_TYPE_MOVED_FROM = 0x40, /**<%File moved out of monitored directory. */
	FILE_EVENT_TYPE_MOVED_TO = 0x80, /**<%File moved into monitored directory. */
	FILE_EVENT_TYPE_OPEN = 0x20 /**<%File was opened. */
};

/**
 * All file event types.
 *
 * @since 2.0
 */
static const unsigned long FILE_EVENT_TYPE_ALL = FILE_EVENT_TYPE_ACCESS | FILE_EVENT_TYPE_ATTRIBUTE | FILE_EVENT_TYPE_CLOSE_WRITE |
		FILE_EVENT_TYPE_CLOSE_NOWRITE | FILE_EVENT_TYPE_CREATE | FILE_EVENT_TYPE_DELETE | FILE_EVENT_TYPE_DELETE_SELF |
		FILE_EVENT_TYPE_MODIFY | FILE_EVENT_TYPE_MOVE_SELF | FILE_EVENT_TYPE_MOVED_FROM | FILE_EVENT_TYPE_MOVED_TO | FILE_EVENT_TYPE_OPEN;

/**
 * @class	FileEventManager
 * @brief	This class provides a mechanism for monitoring file system events.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %FileEventManager class can be used to monitor individual files or directories. When a directory is monitored, this class will send an event for the directory or file itself, and for sub-files or sub-directories inside the observed directory.
 */
class _OSP_EXPORT_ FileEventManager
	: public Tizen::Base::Object
{

public:
	/**
	* The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since		2.0
	*/
	FileEventManager(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*/
	virtual ~FileEventManager(void);

	/**
	* Initializes this instance of %FileEventManager. @n
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	listener			A listener invoked when monitored files are changed.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_MAX_EXCEEDED		The number of opened files has exceeded the maximum limit.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- Fail to attach on platform.
	*									- Detected corruption of a file.
	*/
	result Construct(IFileEventListener& listener);


	/**
	* Adds a new monitor file, or modifies an existing monitor file, for the file whose location is specified in path; the application has to have read permission for this %path. %File event type can be set in %eventsToMonitor.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	path				The path to the directory or file to monitor
	* @param[in]	eventsToMonitor		The kind of event to monitor @n
	*									Multiple event type can be combined using bitwise OR (see Tizen::Io::FileEventType). @n
	*									The Tizen::Io::FILE_EVENT_TYPE_ALL is provided for all file event type @n
	*									If a specific eventsToMonitor is set, the events that have the specified file event are returned.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified eventsToMonitor contains no valid events.
	* @exception	E_FILE_NOT_FOUND	An entry for the specified path could not be found.
	* @exception	E_ILLEGAL_ACCESS	The specified path is not permitted.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- The specified path outside of the process's accessible address space. @n
	*									- The number of file monitor has been exceeded the maximum limit or
	*									  the failed to allocate a needed resource. @n
	*									- Detected corruption of a file.
	* @see			FileEventType
	*/
	result AddPath(const Tizen::Base::String& path, unsigned long eventsToMonitor);

	/**
	* Removes the monitored file associated with the current instance.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]		path			The path to the directory or file that is monitored
	* @exception		E_SUCCESS		The method is successful.
	* @exception		E_IO			The specified path is not monitored.
	*/
	result RemovePath(const Tizen::Base::String& path);

private:
	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since 2.0
	*/
	FileEventManager(const FileEventManager& fileEventManager);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since 2.0
	*/
	FileEventManager& operator =(const FileEventManager& fileEventManager);

	class _FileEventManagerImpl* __pFileEventManagerImpl;

	friend class _FileEventManagerImpl;

}; // FileEventManager

}} // Tizen::Io

#endif //_FIO_FILE_EVENT_MANAGER_H_

