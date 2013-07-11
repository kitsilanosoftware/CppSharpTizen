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
 * @file	FIoDirectory.h
 * @brief	This is the header file for the %Directory class.
 *
 * This header file contains the declarations of the %Directory class.
 */

#ifndef _FIO_DIRECTORY_H_
#define _FIO_DIRECTORY_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FBaseDateTime.h>
#include <FBaseColArrayList.h>
#include <FIoDirEntry.h>
#include <FIoDirEnumerator.h>

namespace Tizen { namespace Io
{

/**
 * @class	Directory
 * @brief	This class provides methods to operate on directories.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Directory class provides methods to operate on directories.
 *
 * For more information on the class features,
 * see <a href="../org.tizen.native.appprogramming/html/guide/io/io_namespace.htm">Io Guide</a>.
 *
 * @see		Tizen::Io::DirEntry
 * @see     Tizen::Io::File
 *
 * The following example demonstrates how to use the %Directory class.
 *
 * @code
#include <FBase.h>
#include <FIo.h>
#include <FApp.h>

using namespace Tizen::Base;
using namespace Tizen::Io;
using namespace Tizen::App;

int main(void)
{
	String dirName;
	String modifyName;
	Directory* pDir;
	DirEnumerator* pDirEnum;
	result r = E_SUCCESS;

	dirName = App::GetInstance()->GetAppDataPath() + L"test";
	modifyName = App::GetInstance()->GetAppDataPath() + L"test2";

 	//------------------------------------------------
	// Directory entry traversal example
	//------------------------------------------------
	pDir = new Directory; // Allocates the %Directory instance

	// Open the directory
	r = pDir->Construct(dirName);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Reads all the directory entries
	pDirEnum = pDir->ReadN();
	if (!pDirEnum)
	{
		goto CATCH;
	}

	// Loops through all the directory entries
	while (pDirEnum->MoveNext() == E_SUCCESS)
	{
		DirEntry entry = pDirEnum->GetCurrentDirEntry();

		// Do something...
	}

	// Releases the %Directory instance.
	// The opened directory is closed automatically when the destructor of the %Directory class is invoked.
	delete pDir;
	pDir = null;

	//------------------------------------------------
	// Renames the directory example
	//------------------------------------------------
	r = Directory::Rename(dirName, modifyName);
	if (IsFailed(r))
	{
		goto CATCH;
	}
	AppLog("Succeeded!");
	return 0;

CATCH:
	if (pDir)
	{
		delete pDir;
	}
	AppLog("Failed...");
	return -1;
}
 * @endcode
 *
 */

class _OSP_EXPORT_ Directory
	: public Tizen::Base::Object
{

public:
	/**
	* The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since	2.0
	*
	* @remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	*/
	Directory(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	virtual ~Directory(void);

	/**
	* Initializes this instance of %Directory with the specified parameter. @n
	* The Construct() method safely opens an existing directory using the specified directory name.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompIoPathPage "here".
	* @endif
	*
	* @return			An error code
	* @param[in]		dirPath				The path to the directory to open
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	*										- The length of the specified path is @c 0 or exceeds system limitations. @n
	*										- The specified path contains prohibited character(s). @n
	*										- The specified path is invalid.
	* @exception		E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception		E_FILE_NOT_FOUND	An entry for the specified file or path cannot be found.
	* @exception		E_MAX_EXCEEDED		The number of opened files has exceeded the maximum limit.
	* @exception		E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	*/
	result Construct(const Tizen::Base::String& dirPath);

	/**
	* Reads all the directory entries from the current directory and then returns a DirEnumerator instance that is used to traverse each directory entry.
	*
	* @since			2.0
	*
	* @return			A pointer to the DirEnumerator object that provides a way to access the collection of a directory entry list, @n
	*					else @c null if an exception occurs
	* @exception        E_SUCCESS			The method is successful.
	* @exception        E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception        E_MAX_EXCEEDED		The number of opened files has exceeded the maximum limit.
	* @exception		E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @remarks			The returned enumeration objects should be released by the caller. @n
	*					The specific error code can be accessed using the GetLastResult() method.
	*/
	DirEnumerator* ReadN(void);

	/**
	* Creates a new directory.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompIoPathPage "here".
	* @endif
	*
	* @return			An error code
	* @param[in]		dirPath					The path at which the directory is created
	* @param[in]		createParentDirectories Set to @c true if the non-existing parent directories are created automatically
	*                                           up to the destination, @n
	*                                           else @c false if an absent parent directory causes an exception
	* @exception	 	E_SUCCESS				The method is successful.
	* @exception		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified path is @c 0 or exceeds system limitations. @n
	*											- The specified path is invalid.
	* @exception		E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception		E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception		E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception		E_STORAGE_FULL			The disk space is full.
	* @exception		E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected.
	*/
	static result Create(const Tizen::Base::String& dirPath, bool createParentDirectories = false);

	/**
	* Deletes the directory specified by the path. @n
	* When @c recursive is set to be @c true, it removes all the subdirectories and their contents. @n
	* When @c false, this method removes the directory only if it is empty.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompIoPathPage "here".
	* @endif
	*
	* @return			An error code
	* @param[in]		dirPath					The path of the directory to remove
	* @param[in]		recursive               Set to @c true to remove the sub-directories recursively, @n
	*											else @c false
	* @exception	    E_SUCCESS				The method is successful.
	* @exception        E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified path is @c 0 or exceeds
	*											  system limitations. @n
	*											- The specified @c dirPath is not directory path.
	* @exception		E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception		E_FILE_NOT_FOUND		The specified @c dirPath cannot be found.
	* @exception		E_FILE_ALREADY_EXIST	The specified directory already exists.
	* @exception		E_MAX_EXCEEDED			The number of opened directories has exceeded the maximum limit.
	* @exception		E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected.
	*/
	static result Remove(const Tizen::Base::String& dirPath, bool recursive = false);

	/**
	* Renames the specified directory to the specified name. @n
	* This method is static. @n
	* This method does not create parent directories automatically. For example, @b "/CurrentDir" cannot be moved to
	* @b "/NewDir/SubDir" if @b "/NewDir" does not already exist. An E_FILE_NOT_FOUND exception is thrown.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompIoPathPage "here".
	* @endif
	*
	* @return			An error code
	* @param[in]		orgDirPath				The original directory path
	* @param[in]		newDirPath				The new directory path
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The length of the specified path is @c 0 or exceeds system limitations. @n
	*											- The specified path is invalid.
	* @exception		E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception		E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception		E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception		E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception		E_STORAGE_FULL			The disk space is full.
	* @exception		E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected.
	*/
	static result Rename(const Tizen::Base::String& orgDirPath, const Tizen::Base::String& newDirPath);

private:
	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	*/
	Directory(const Directory& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	*/
	Directory& operator =(const Directory& rhs);

	class _DirectoryImpl* __pDirectoryImpl;

	friend class _DirectoryImpl;

}; // Directory

}} // Tizen::Io

#endif // _FIO_DIRECTORY_H_

