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
 * @file	FIoDirEnumerator.h
 * @brief	This is the header file for the %DirEnumerator class.
 *
 * This header file contains the declarations of the %DirEnumerator class.
 */

#ifndef _FIO_DIR_ENUMERATOR_H_
#define _FIO_DIR_ENUMERATOR_H_

#include <FBaseObject.h>
#include <FBaseColIEnumerator.h>

namespace Tizen { namespace Io
{

class DirEntry;

/**
 * @class	DirEnumerator
 * @brief	This class provides methods to access the collection of a specific directory entry list.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %DirEnumerator class provides methods to access the collection of a specific directory entry list.
 * Generally, %DirEnumerator is instantiated by the Directory::ReadN() method,
 * and used to get the %DirEntry instances that have information pertaining to the directory.
 *
 * For more information on the class features,
 * see <a href="../org.tizen.native.appprogramming/html/guide/io/io_namespace.htm">Io Guide</a>.
 *
 * @see		Tizen::Io::Directory
 * @see     Tizen::Io::DirEntry
 * @see     Tizen::Io::File
 *
 * The following example demonstrates how to use the %DirEnumerator class.
 *
 * @code
#include <FBase.h>
#include <FIo.h>

using namespace Tizen::Base;
using namespace Tizen::Io;

int main(void)
{
	String dirName(L"data/test");
	Directory dir;
	DirEnumerator *pDirEnum = null;
	result r = E_SUCCESS;

	// Open the directory
	r = dir.Construct(Tizen::App::App::GetInstance()->GetAppRootPath() + dirName);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Read all the directory entries
	pDirEnum = dir.ReadN();
	if (!pDirEnum)
	{
		goto CATCH;
	}

 	// Loop through all the directory entries
	while (pDirEnum->MoveNext() == E_SUCCESS)
	{
		DirEntry dirEntry = pDirEnum->GetCurrentDirEntry();

		// Do something...
	}

	// Delete the enumerator
	delete pDirEnum;

	AppLog("Succeeded");

	// The opened directory is closed automatically when the destructor of the Directory class is invoked.
	return 0;

CATCH:
	if (pDirEnum)
	{
		delete pDirEnum;
	}
	AppLog("Failed...");
	return -1;
}
 * @endcode
 *
 */
class _OSP_EXPORT_ DirEnumerator
	: public Tizen::Base::Object
	, public Tizen::Base::Collection::IEnumerator
{

public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	virtual ~DirEnumerator(void);

	/**
	* Gets the value of the DirEntry instance in the currently accessed directory.
	*
	* @since			2.0
	*
	* @return			A reference to the DirEntry instance
	* @exception		E_SUCCESS			The method is successful.
	* @exception        E_INVALID_STATE		The current position of the collection is not valid.
	* @remarks			Use the MoveNext() method to get information from another file or directory to the currently accessed directory. @n
	*					The specific error code can be accessed using the GetLastResult() method.
	*/
	DirEntry GetCurrentDirEntry(void) const;

	/**
	* Gets the pointer to the object at the current position of a directory entry collection.
	*
	* @since		    2.0
	*
	* @return			A pointer to the DirEntry instance, @n
	*					else @c null if the current position of the collection is invalid
	* @remarks			Use the MoveNext() method to get information of another file or directory in the currently accessed directory.
	*/
	virtual Tizen::Base::Object* GetCurrent(void) const;

	/**
	* Moves the current position of the collection to the next position in the currently accessed directory. @n
	* When %DirEnumerator is instantiated, its initial position is set to @c -1. @n
	* Therefore, calling the GetCurrentDirEntry() method without a call to MoveNext() throws an E_INVALID_STATE exception,
	* and returns a reference to an empty DirEntry instance. @n
	* Similarly, calling the GetCurrent() method without a call to MoveNext() returns a @c null pointer to indicate an error condition.
	*
	* @since			2.0
	*
	* @return			An error code
	* @exception		E_SUCCESS			The method is successful.
	* @exception        E_INVALID_ARG		Either of the following conditions has occurred: @n
	*										- The length of the specified path is @c 0 or exceeds
	*										  system limitations. @n
	*										- The specified path is invalid. @n
	*										- The file handle is invalid (either the file is closed by
	*										  another method, or the memory is corrupted).
	* @exception        E_FILE_NOT_FOUND	An entry for the specified file or path cannot be found.
	* @exception        E_MAX_EXCEEDED		The number of opened files has exceeded the maximum limit.
	* @exception        E_END_OF_FILE		There are no more directory entries to read.
	* @exception        E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception		E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	*/
	virtual result MoveNext(void);

	/**
	* Resets the current position of the collection to @c -1.
	*
	* @since			2.0
	*
	* @return			An error code
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		The file handle is invalid (either the file is closed by another method, or the memory is corrupted).
	*/
	virtual result Reset(void);

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @since	2.0
	*/
	DirEnumerator(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	*/
	DirEnumerator(const DirEnumerator& source);

	/**
	* This is the copy constructor for this class.
	*
	* @since	2.0
	*/
	DirEnumerator(const Tizen::Base::String& dirPath);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	*/
	DirEnumerator& operator =(const DirEnumerator& source);

	DirEntry* __pCurDirEntry;
	class _DirEnumeratorImpl* __pDirEnumeratorImpl;

	friend class _DirEnumeratorImpl;

}; // DirEnumerator

}} // Tizen::Io

#endif // _FIO_DIR_ENUMERATOR_H_

