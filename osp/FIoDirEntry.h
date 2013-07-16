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
 * @file	FIoDirEntry.h
 * @brief	This is the header file for the %DirEntry class.
 *
 * This header file contains the declarations of the %DirEntry class.
 */

#ifndef _FIO_DIR_ENTRY_H_
#define _FIO_DIR_ENTRY_H_

#include <FBaseObject.h>

namespace Tizen { namespace Base
{
class String;
class DateTime;
}}

namespace Tizen { namespace Io
{

/**
 * @class	DirEntry
 * @brief	This class stores the information about each directory entry.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %DirEntry class stores the information about each directory entry.
 *
 * For more information on the class features,
 * see <a href="../org.tizen.native.appprogramming/html/guide/io/io_namespace.htm">Io Guide</a>.
 *
 * @see		Tizen::Io::Directory
 * @see     Tizen::Io::File
 *
 * The following example demonstrates how to use the %DirEntry class.
 *
 * @code

#include <FBase.h>
#include <FIo.h>

using namespace Tizen::Base;
using namespace Tizen::Io;

int main(void)
{
	String dirName(L"test");
	Directory dir;
	DirEnumerator *pDirEnum = null;
	String name;
	Tizen::Base::DateTime dt;
	result r = E_SUCCESS;

	// Open the directory
	r = dir.Construct(App::GetInstance()->GetAppDataPath() + dirName);
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

 		// Get several properties of each directory entry.
		name = dirEntry.GetName();

		name += L": size=";
		name += Long((long) dirEntry.GetFileSize()).ToString();

		if (dirEntry.IsDirectory())
		{
			name += L", [directory]";
		}
		if (dirEntry.IsReadOnly())
		{
			name += L", [read-only]";
		}
		if (dirEntry.IsHidden())
		{
			name += L", [hidden]";
		}

		dt = dirEntry.GetDateTime();

		name += L", year=";
		name += dt.GetYear();

		name += L", month=";
		name += dt.GetMonth();

		name += L", day=";
		name += dt.GetDay();

		name += L", hour=";
		name += dt.GetHour();

		name += L", min=";
		name += dt.GetMinute();

		name += L", second=";
		name += dt.GetSecond();

		// Print out message...
	}

	// Delete the enumerator
	delete pDirEnum;

	AppLog("Succeeded");

	// The opened directory is closed automatically when the destructor of Directory class is invoked
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
 */
class _OSP_EXPORT_ DirEntry
	: public Tizen::Base::Object
{

public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	virtual ~DirEntry(void);

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since		2.0
	*
	* @param[in]	rhs		An instance of %DirEntry
	*/
	DirEntry(const DirEntry& rhs);

	/**
	* Assigns the value of the specified instance to the current instance of %DirEntry.
	*
	* @since		2.0
	*
	* @return		A reference to the calling instance
	* @param[in]	rhs		An instance of %DirEntry
	*/
	DirEntry& operator =(const DirEntry& rhs);

	/**
	* Compares the specified instance of Object to the calling instance of %DirEntry.
	*
	* @since		2.0
	*
	* @return		@c true if the values of the specified instance equals the values of the current instance, @n
	*				else @c false
	* @param[in]	object		The object to compare with the current instance
	*/
	virtual bool Equals(const Object& object) const;

	/**
	* Gets the hash value of the current instance.
	*
	* @since		2.0
	*
	* @return		An integer value indicating the hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

	/**
	* Gets the name of this directory entry.
	*
	* @since		2.0
	*
	* @return		The name of this directory entry
	*/
	const Tizen::Base::String GetName(void) const;

	/**
	* Gets the file size of this directory entry.
	*
	* @since		2.0
	*
	* @return		The file size of this directory entry
	*/
	unsigned long GetFileSize(void) const;

	/**
	* Checks whether the current %DirEntry instance is a directory.
	*
	* @since		2.0
	*
	* @return		@c true if it is a directory, @n
	*				else @c false
	*/
	bool IsDirectory(void) const;

	/**
	* Checks whether a file has a hidden attribute.
	*
	* @since		2.0
	*
	* @return		@c true if the file has a hidden attribute, @n
	*				else @c false
	*/
	bool IsHidden(void) const;

	/**
	* Checks whether a file has a read-only attribute.
	*
	* @since		2.0
	*
	* @return		@c true if the file has a read-only attribute, @n
	*				else @c false
	*/
	bool IsReadOnly(void) const;

	/**
	* Gets the date and time of the last modification of the directory entry.
	*
	* @since		2.0
	*
	* @return		The date and time of the last modification
	*/
	Tizen::Base::DateTime GetDateTime(void) const;

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @since    2.0
	*/
	DirEntry(void);

	class _DirEntryImpl* __pDirEntryImpl;

	friend class _DirEntryImpl;

}; // DirEntry

}} // Tizen::Io

#endif // _FIO_DIR_ENTRY_H_

