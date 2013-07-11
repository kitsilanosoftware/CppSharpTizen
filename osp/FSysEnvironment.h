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
 * @file	FSysEnvironment.h
 * @brief	This is the header file for the %Environment class.
 *
 * This header file contains the declarations of the %Environment class.
 */

#ifndef _FSYS_ENVIRONMENT_H_
#define _FSYS_ENVIRONMENT_H_

#include <FBaseString.h>

namespace Tizen { namespace System
{

/**
 * @enum	PredefinedDirectoryType
 *
 * Defines the type of the pre-defined directory used to classify files to be stored.
 *
 * @since 2.0
 */
enum PredefinedDirectoryType
{
	PREDEFINED_DIRECTORY_IMAGES = 0, /** The directory for image files to be stored in internal storage (read-write permission) */
	PREDEFINED_DIRECTORY_SOUNDS,	 /** the directory for sound files to be stored in internal storage (read-write permission) */
	PREDEFINED_DIRECTORY_VIDEOS,	 /** The directory for video files to be stored in internal storage (read-write permission) */
	PREDEFINED_DIRECTORY_CAMERA,	 /** The directory for files to be stored in internal storage by camera application (read-write permission) */
	PREDEFINED_DIRECTORY_DOWNLOADS,	 /** The directory for files to be stored in internal storage by download manager (read-write permission) */
	PREDEFINED_DIRECTORY_OTHERS,	 /** The directory for other files to be stored in internal storage (read-write permission) */

	PREDEFINED_DIRECTORY_EXTERNAL_IMAGES = 100,	/** The directory for image files to be stored in external MMC (read-write permission) */
	PREDEFINED_DIRECTORY_EXTERNAL_SOUNDS,		/** the directory for sound files to be stored in external MMC (read-write permission) */
	PREDEFINED_DIRECTORY_EXTERNAL_VIDEOS,		/** The directory for video files to be stored in external MMC (read-write permission) */
	PREDEFINED_DIRECTORY_EXTERNAL_CAMERA,		/** The directory for files to be stored in external MMC by camera application (read-write permission) */
	PREDEFINED_DIRECTORY_EXTERNAL_DOWNLOADS,	/** The directory for files to be stored in external MMC by download manager (read-write permission) */
	PREDEFINED_DIRECTORY_EXTERNAL_OTHERS,		/** The directory for other files to be stored in external MMC (read-write permission) */

	PREDEFINED_DIRECTORY_APPLICATIONS = 200,	/** The directory for applications to be installed in internal storage (read-only permission) */
	PREDEFINED_DIRECTORY_EXTERNAL_APPLICATIONS,	/** The directory for applications to be installed in external MMC (read-only permission) */
};

/**
 * @class	Environment
 * @brief	This class provides methods for getting the system environment variables.
 *
 * @since 2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Environment class provides methods for getting the system environment variables.
 */
class _OSP_EXPORT_ Environment
{

public:
	/**
	* Gets the path for the media directory that is usually used to store media contents.
	*
	* @since 2.0
	*
	* @return	The media directory path
	*/
	static Tizen::Base::String GetMediaPath(void);

	/**
	* Gets the path for the default download directory that is usually used to store downloaded contents by the Tizen::Content::DownloadManager class.
	*
	* @since 2.0
	*
	* @return	The default download directory path
	*/
	static Tizen::Base::String GetDefaultDownloadPath(void);

	/**
	* Gets the path for the external storage.
	*
	* @since 2.0
	*
	* @return	The external storage directory path
	*/
	static Tizen::Base::String GetExternalStoragePath(void);

	/**
	* Gets the directory path according to the pre-defined directory type.
	*
	* @since	2.0
	*
	* @return	The pre-defined directory path according to the specified @c dirType, @n
	*               else an empty string if the specified @c dirType is invalid
	* @param[in]	dirType	The pre-defined directory type
	* @remarks	The directory path for some directory types such as IMAGES, SOUNDS, VIDEOS, CAMERA, DOWNLOADS, and OTHERS may not yet exist,
	*		so you must make sure that it exists before using it.
	* @see		PredefinedDirectoryType
	* @see		Tizen::Io::Directory::Create()
	*/
	static Tizen::Base::String GetPredefinedPath(PredefinedDirectoryType dirType);

private:
	/**
	* The implementation of this constructor is intentionally blank to prohibit creation of an instance.
	*
	* @since 2.0
	*/
	Environment(void);

	/**
	* The implementation of this destructor is intentionally blank because an instance cannot be created.
	*
	* @since 2.0
	*/
	~Environment(void);

	/**
	* This copy constructor is intentionally declared as private to prohibit copying.
	*
	* @since 2.0
	*/
	Environment(const Environment& rhs);

	/**
	* This copy assignment operator is intentionally declared as private to prohibit copying.
	*
	* @since 2.0
	*/
	Environment& operator =(const Environment& rhs);

}; // Environment

}} // Tizen::System

#endif // _FSYS_ENVIRONMENT_H_
