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
 * @file		FBaseUtilFileZipper.h
 * @brief		This is the header file for the %FileZipper class.
 *
 * This header file contains the declarations of the %FileZipper class.
 */

#ifndef _FBASE_UTIL_FILE_ZIPPER_H_
#define _FBASE_UTIL_FILE_ZIPPER_H_

#include <FBaseUtilTypes.h>
#include <FBaseString.h>


namespace Tizen { namespace Base { namespace Utility
{
/**
 * @class	FileZipper
 * @brief	This class provides methods that compress data to a zip-archive using zlib.
 *
 * @since 2.0
 *
 * The %FileZipper class provides a zip operation for a simple and efficient file-based access to a zip-archive.
 * It is possible to create a zip file, and add the file to an already existing zip-archive.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/utility_namespace.htm">Utility</a>.
 *
 * The following example demonstrates how to use the %FileZipper class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::App;
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Utility;
 *
 *	void
 *	MyClass::FileZipperSample(void)
 *	{
 *		FileZipper zip;
 *		String dataPath = App::GetInstance()->GetAppDataPath();
 *		zip.Construct(dataPath + L"sample.zip");
 *
 *		// Adds files to the zip file-archive
 *		zip.AddToZip(dataPath + L"data1.txt");
 *		zip.AddToZip(dataPath + L"dataDir/data2.txt");
 *	}
 * @endcode
 */
class _OSP_EXPORT_ FileZipper
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	FileZipper(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~FileZipper(void);

	/**
	 * Initializes this instance of %FileZipper with the specified filepath. @n
	 * This method opens an existing zip file in append mode. If the file does not exist, it creates and opens the file in
	 * append mode.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since 2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
	 *					For more information, see @ref CompIoPathPage "here".
	 * @endif
	 *
	 * @return			An error code
	 * @param [in] 		filePath  		The path of the zip file to open or create
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The length of the specified path is @c 0 or exceeds system limitations. @n
	 *										- The specified path contains prohibited character(s). @n
	 *										- The specified path is invalid.
	 * @exception		E_ILLEGAL_ACCESS	The specified path is not permitted, or
	 *										access is denied due to insufficient permission.
	 * @exception		E_IO			An unexpected device failure has occurred.
	 * @remarks			The paths for @b Tizen::App::AppManager::GetAppSharedPath(appId) + L"data" and @b Tizen::App::AppManager::GetAppSharedPath(appId) + L"trusted" are not supported.
	 * @see				Tizen::Io::File
	 */
	result Construct(const String& filePath);

	/**
	 * Adds a new file to an already opened zip file.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since 2.0
	 * @if OSPCOMPAT
	 * @compatibility	This method has compatibility issues with OSP compatible applications. @n
	 *					For more information, see @ref CompIoPathPage "here".
	 * @endif
	 *
	 * @return			An error code
	 * @param [in] 		filePath  	The path of the file to add to the zip file
	 * @param [in] 		excludePath	Set to @c true to exclude the path and to store only the file name, @n
	 *								 else @c false to insert the entire path name in the zip-archive
	 * @param [in] 		level		Set to @c BEST_SPEED or @c BEST_COMPRESSION @n
	 * 								By default, it is set to @c DEFAULT_COMPRESSION.
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The length of the specified path is @c 0 or exceeds system limitations. @n
	 *										- The specified path contains prohibited character(s). @n
	 *										- The specified path is invalid.
	 * @exception		E_ILLEGAL_ACCESS	The specified path is not permitted, or
	 *										access is denied due to insufficient permission.
	 * @exception		E_FILE_NOT_FOUND  	The specified file cannot be found.
	 * @exception		E_FILE_ALREADY_EXIST	The specified file already exists in the zip-archive, but the
	 *											flag for overwriting the file is not set.
	 * @exception		E_IO			An unexpected device failure has occurred.
	 * @remarks			The paths for @b Tizen::App::AppManager::GetAppSharedPath(appId) + L"data" and @b Tizen::App::AppManager::GetAppSharedPath(appId) + L"trusted" are not supported.
	 * @remarks			If the value of @c excludePath is set to @c false, full path name is inserted to the zip-
	 *					archive. Therefore, developers should handle the path name carefully. @n
	 *			 		For example, if you add @b '/Test/data.txt' file to the zip-archive, and if the
	 *					@c excludePath parameter is set to @c false, while unzipping the file in @b '/Test'
	 *					directory, then the file is extracted in @b '/Test/Test/data.txt'.
	 * @see				Tizen::Io::File
	 */
	result AddToZip(const String& filePath, bool excludePath = true, CompressionLevel level = DEFAULT_COMPRESSION);

	/**
	 * Gets the value of the overwritten flag. @n
	 * If @c true, it overwrites the existing file.
	 *
	 * @since 2.0
	 *
	 * @return			The value of the overwrite flag for the zip file
	 */
	bool GetOverwriteFlag(void) const;

	/**
	 * Sets the value of the overwritten flag. @n
	 * If @c true, the existing file gets overwritten during file addition.
	 * The default value of this flag is @c false.
	 *
	 * @since 2.0
	 *
	 * @param [in]		flag    The flag value to set
	 */
	void SetOverwriteFlag(bool flag);


private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param [in]		fileZipper		The instance of the FileZip class to copy from
	 * @remarks			This constructor is hidden.
	 */
	FileZipper(const FileZipper& fileZipper);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param [in]		fileZipper		An instance of %FileZipper
	 * @remarks			This operator is hidden.
	 */
	FileZipper& operator =(const FileZipper& fileZipper);


	friend class _FileZipperImpl;
	class _FileZipperImpl* __pFileZipperImpl;

}; // FileZipper

}}} // Tizen::Base::FileZipper

#endif // _FBASE_UTIL_FILE_ZIPPER_H_
