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
 * @file	FIoFileAttributes.h
 * @brief	This is the header file for the %FileAttributes class.
 *
 * This header file contains the declarations of the %FileAttributes class.
 */

#ifndef _FIO_FILE_ATTRIBUTES_H_
#define _FIO_FILE_ATTRIBUTES_H_

#include <FBaseObject.h>

namespace Tizen { namespace Base
{
class DateTime;
}}

namespace Tizen { namespace Io
{

/**
 * @class	FileAttributes
 * @brief	This class provides a collection of basic file attributes.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %FileAttributes class provides the attributes of a file or directory.
 * It can be used to determine the various file properties such as file attributes
 * (read-only, hidden, system, or directory), creation time, last modified time, and file size.
 *
 * For more information on the class features,
 * see <a href="../org.tizen.native.appprogramming/html/guide/io/io_namespace.htm">Io Guide</a>.
 *
 * The following example demonstrates how to use the %FileAttributes class.
 *
 * @code
#include <FBase.h>
#include <FIo.h>

using namespace Tizen::Base;
using namespace Tizen::Io;

int main(void)
{
	String fileName(L"test.txt");
	File file;
	FileAttributes attr;
	long long size;
	DateTime dtCreate ;
	DateTime dtModified ;
	result r = E_SUCCESS;

	r = File::GetAttributes(App::GetInstance()->GetAppDataPath() + fileName, attr);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	size = attr.GetFileSize();
	AppLog("* size=%d", size);

	dtCreate = attr.GetDateTime();
	AppLog("* creation time: %d year, %d month, %d day, %d hour, %d min, %d sec.\n",
		dtCreate.GetYear(),
		dtCreate.GetMonth(),
		dtCreate.GetDay(),
		dtCreate.GetHour(),
		dtCreate.GetMinute(),
		dtCreate.GetSecond()
	);

	dtModified = attr.GetLastModifiedTime();
	AppLog("* last modified time: %d year, %d month, %d day, %d hour, %d min, %d sec.\n",
		dtModified.GetYear(),
		dtModified.GetMonth(),
		dtModified.GetDay(),
		dtModified.GetHour(),
		dtModified.GetMinute(),
		dtModified.GetSecond()
	);

	if (attr.IsDirectory())
	{
		AppLog("* This is a directory.");
	}
	if (attr.IsHidden())
	{
		AppLog("* This is a hidden file.");
	}
	if (attr.IsReadOnly())
	{
		AppLog("* This is a read-only file.");
	}

	AppLog("Succeeded!");
	return 0;

CATCH:
	AppLog("Failed...");
	return -1;
}
 * @endcode
 */
class _OSP_EXPORT_ FileAttributes
	: public Tizen::Base::Object
{

public:
	/**
	* This is the default constructor for this class.
	*
	* @since		2.0
	*/
	FileAttributes(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*/
	virtual ~FileAttributes(void);

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since		2.0
	*
	* @param[in]	rhs		An instance of %FileAttributes
	*/
	FileAttributes(const FileAttributes& rhs);

	/**
	* Assigns the value of the specified instance to the current instance of %FileAttributes.
	*
	* @since		2.0
	*
	* @return		The reference of this instance
	* @param[in]	rhs		An instance of %FileAttributes
	*/
	FileAttributes& operator =(const FileAttributes& rhs);

	/**
	* Compares the specified instance of Object to the calling instance of %FileAttributes.
	*
	* @since		2.0
	*
	* @return		@c true if the values of the specified instance equals the values of the current instance, @n
	*				else @c false
	* @param[in]	object		The object to compare with the current instance
	*/
	virtual bool Equals(const Tizen::Base::Object& object) const;

	/**
	* Gets the hash value of the current instance.
	*
	* @since		2.0
	*
	* @return		An integer value indicating the hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

	/**
	* Gets the file size.
	*
	* @since		2.0
	*
	* @return		The file size in bytes
	*/
	long long GetFileSize(void) const;

	/**
	* Checks whether the current file is a directory.
	*
	* @since		2.0
	*
	* @return		@c true if the file is a directory, @n
	*				else @c false
	*/
	bool IsDirectory(void) const;

	/**
	* Checks whether the file has a hidden attribute.
	*
	* @since		2.0
	*
	* @return		@c true if the file has a hidden attribute, @n
	*				else @c false
	*/
	bool IsHidden(void) const;

	/**
	* Checks whether the file has a read-only attribute.
	*
	* @since		2.0
	*
	* @return		@c true if the file has a read-only attribute, @n
	*				else @c false
	*/
	bool IsReadOnly(void) const;

	/**
	* Gets the date and time of the last modification to the file.
	*
	* @since		2.0
	*
	* @return		The date and time of the last modification to the file
	*/
	Tizen::Base::DateTime GetDateTime(void) const;

	/**
	* Gets the date and time of the last modification to the file.
	*
	* @since		2.0
	*
	* @return		The date and time of the last modification to the file
	*/
	Tizen::Base::DateTime GetLastModifiedTime(void) const;

private:
	class _FileAttributesImpl* __pFileAttributesImpl;

	friend class _FileAttributesImpl;

}; // FileAttributes

}} // Tizen::Io

#endif //_FIO_FILE_ATTRIBUTES_H_

