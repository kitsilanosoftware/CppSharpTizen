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
 * @file		FBaseUtilFileUnzipper.h
 * @brief		This is the header file for %FileUnzipper class.
 *
 * This header file contains the declarations of the %FileUnzipper class.
 */

#ifndef _FBASE_UTIL_FILE_UNZIPPER_H_
#define _FBASE_UTIL_FILE_UNZIPPER_H_


#include <FBaseString.h>
#include <FBaseUtilZipEntry.h>


namespace Tizen { namespace Base { namespace Utility
{

/**
 * @class	FileUnzipper
 * @brief	This class provides methods that decompress data from a zip-archive using zlib.
 *
 * @since 2.0
 *
 * The %FileUnzipper class provides an unzip operation for a simple and efficient file-based access to a zip-archive.
 * It is possible to extract a zipped file completely or partially and access the entry of a zip-archive.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/utility_namespace.htm">Utility</a>.
 *
 * The following example demonstrates how to use the %FileUnzipper class.
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::App;
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Utility;
 *
 *	void
 *	MyClass::FileUnzipperSample(void)
 *	{
 *		int count = 0;
 *
 *		FileUnzipper unzip;
 *		String dataPath = App::GetInstance()->GetAppDataPath();
 *		unzip.Construct(dataPath + L"sample.zip");
 *
 *		// Unzips the zip-archive fully
 *		unzip.UnzipTo(dataPath);
 *
 *		// Unzips the file from the zip-archive
 *		unzip.UnzipTo(dataPath + L"Sample/", L"data1.txt");
 *
 *		// Gets the number of entries
 *		count = unzip.GetEntryCount();
 *
 *	}
 * @endcode
 */

class _OSP_EXPORT_ FileUnzipper
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	FileUnzipper(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~FileUnzipper(void);

	/**
	 * Initializes this instance of %FileUnzipper with the specified filepath. @n
	 * This method opens a zip file in the read mode.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param [in] 		filePath  		The path of the file to open or create
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The length of the specified path is @c 0 or exceeds system limitations. @n
	 *										- The specified path contains prohibited character(s). @n
	 *										- The specified path is invalid.
	 * @exception 		E_ILLEGAL_ACCESS 	The specified file path is inaccessible as per the %Tizen platform policy.
	 * @exception		E_FILE_NOT_FOUND  	The specified file cannot be found or accessed.
	 * @exception		E_IO 			An unexpected device failure has occurred.
	 * @remarks			The paths for @b Tizen::App::AppManager::GetAppSharedPath(appId) + L"data" and @b Tizen::App::AppManager::GetAppSharedPath(appId) + L"trusted" are not supported.
	 * @see				Tizen::Io::File
	 */
	result Construct(const String& filePath);

	/**
	 * Unzips a zip file at the specified path or destination.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param [in] 		dirPath   			A directory path to unzip
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The length of the specified path is @c 0 or exceeds system limitations. @n
	 *										- The specified path contains prohibited character(s). @n
	 *										- The specified path is invalid.
	 * @exception		E_ILLEGAL_ACCESS	The specified path is not permitted, or
	 *										access is denied due to insufficient permission.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			The paths for @b Tizen::App::AppManager::GetAppSharedPath(appId) + L"data" and @b Tizen::App::AppManager::GetAppSharedPath(appId) + L"trusted" are not supported.
	 * @remarks			This operation consumes a lot of time if the zip-archive contains large number of files or
	 *					directories.
	 *           		In such cases, it is recommended to call this method in a separate thread.
	 * @see				Tizen::Io::File
	 */
	result UnzipTo(const String& dirPath) const;

	/**
	 * Unzips a zip entry from a zip-archive to the specified path.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param [in] 		dirPath  			A directory path to unzip
	 * @param [in] 		zipEntryName		A zip entry name that could be a file or directory name
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The length of the specified path is @c 0 or exceeds system limitations. @n
	 *										- The specified path contains prohibited character(s). @n
	 *										- The specified path is invalid.
	 * @exception		E_ILLEGAL_ACCESS	The specified path is not permitted, or
	 *										access is denied due to insufficient permission.
 	 * @exception		E_FILE_NOT_FOUND	The entry of the specified file or path cannot be found in the archive.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			The paths for @b Tizen::App::AppManager::GetAppSharedPath(appId) + L"data" and @b Tizen::App::AppManager::GetAppSharedPath(appId) + L"trusted" are not supported.
	 * @remarks			If the value of @c zipEntryName is a directory name present in the archive, this method
	 *					creates an empty directory. @n
	 *					For example, UnzipTo(Tizen::App::App::GetInstance()->GetAppDataPath() + L"Test/", L"/someDir/") will create @b '[AppDataPath]/Test/someDir'
	 *					directory only, and the files or subdirectories under @b 'someDir' will not be extracted.
	 * @see				Tizen::Io::File
	 */
	result UnzipTo(const String& dirPath, const String& zipEntryName) const;

	/**
	 * Gets the number of entries present in a zip-archive.
	 *
	 * @since 2.0
	 *
	 * @return			The number of entries present in a zip-archive, @n
	 *					else @c -1 in case of an error
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetEntryCount(void) const;

	/**
	 * Gets the number of files present in a zip-archive.
	 *
	 * @since 2.0
	 *
	 * @return			The number of files present in a zip-archive, @n
	 *					else @c -1 in case of an error
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetFileCount(void) const;

	/**
	 * Gets the number of directories present in a zip-archive.
	 *
	 * @since 2.0
	 *
	 * @return			The number of directories present in a zip-archive, @n
	 *					else @c -1 in case of an error
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetDirectoryCount(void) const;

	/**
	 * Gets a zip entry associated with the file or directory name passed as parameter.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param [in] 		zipEntryName		A zip entry name that could be a file or directory name
	 * @param [out]		entry				A reference to the ZipEntry
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The length of the specified path is @c 0 or exceeds system limitations. @n
	 *										- The specified path contains prohibited character(s). @n
	 *										- The specified path is invalid.
	 * @exception		E_FILE_NOT_FOUND	The entry of the specified file or path cannot be found in the archive.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 * @remarks			If the value of @c zipEntryName is a directory name, it must have a suffix '/'.
	 *					For example, @b Tizen::App::App::GetInstance()->GetAppDataPath() + L"Test/" or @b Tizen::App::App::GetInstance()->GetAppDataPath() + L"Test/DATA/".
	 */
	result GetEntry(const String& zipEntryName, ZipEntry& entry) const;

	/**
	 * Gets a zip entry associated with the index from the root directory.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param [in]      index				An index of the zip entry to access @n
	 *										The index starts from @c 0.
	 * @param [out] 	entry				A reference to the ZipEntry
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		The specified index is out of range, or an invalid index is passed.
	 * @exception		E_IO 				An unexpected device failure has occurred.
	 */
	result GetEntry(int index, ZipEntry& entry) const;


private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param [in]	fileUnzipper	The instance of the %FileUnzipper class to copy from
	 * @remarks		This constructor is hidden.
	 */
	FileUnzipper(const FileUnzipper& fileUnzipper);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param [in]	fileUnzipper	An instance of %FileUnzipper
	 * @remarks		This operator is hidden.
	 */
	FileUnzipper& operator =(const FileUnzipper& fileUnzipper);


	friend class _FileUnzipperImpl;
	class _FileUnzipperImpl* __pFileUnzipperImpl;

}; // FileUnzipper

}}} // Tizen::Base::Utility

#endif // _FBASE_UTIL_FILE_UNZIPPER_H_
