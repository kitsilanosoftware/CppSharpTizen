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
 * @file	FIoFile.h
 * @brief	This is the header file for the %File class.
 *
 * This header file contains the declarations of the %File class.
 */

#ifndef _FIO_FILE_H_
#define _FIO_FILE_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FBaseDateTime.h>
#include <FBaseColIList.h>
#include <FBaseResult.h>
#include <FIoFileAttributes.h>
#include <FIoFileLock.h>

namespace Tizen { namespace Io
{

/**
 * @enum FileSeekPosition
 *
 * Defines the file seek position.
 *
 * @since	2.0
 */
enum FileSeekPosition
{
	FILESEEKPOSITION_BEGIN,         /**<The beginning of the file */
	FILESEEKPOSITION_CURRENT,       /**<The current position of the file */
	FILESEEKPOSITION_END            /**<The end of the file */
};

/**
 * @class	File
 * @brief	This class provides the basic file I/O operations, such as read, write, create, and remove.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %File class provides the basic file I/O operations, such as read, write, create, and remove.
 * It only provides synchronous file read-write with raw data bytes (UTF-8) or string data.
 * It is constructed using the Construct() method to access files and control file I/O operations.
 * There is no method like Close() to close the opened file instances.
 * The only way to close an opened file is by invoking the destructor of the %File class.
 * Therefore, if the %File class is instantiated as a local variable, it is not closed until it goes out of scope.
 * To get a detailed information on a file or directory, use the FileAttributes and Directory classes.
 *
 * When an application is installed, the application has its own storage area, which is application root directory.
 * The application root directory path can be obtained by calling Tizen::App::App::GetAppRootPath().
 * The following are some of the sub-directories of the application root directory:
 * - data - Used to store and access private data of an application (read-write permission) @n
 *			To access this directory, use Tizen::App::App::GetInstance()->GetAppRootPath() + L"data"
 *			or Tizen::App::App::GetInstance()->GetAppDataPath().
 * - res - Used to read resource files that are delivered with the application package (read-only permission) @n
 *			To access this directory, use Tizen::App::App::GetInstance()->GetAppRootPath() + L"res"
 *			or Tizen::App::App::GetInstance()->GetAppResourcePath().
 * - shared - Used to share data and resource files with other applications @n
 *			There are data and res directories under the shared directory.
 *			Use Tizen::App::App::GetInstance()->GetAppRootPath() + L"shared" to access its own shared directory and
 *			use Tizen::App::AppManager::GetAppSharedPath() to access other application's shared directory.  @n
 *
 * For more information on the path,
 * see <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/io_overview.htm">I/O Overview</a>.
 *
 * For more information on class features,
 * see <a href="../org.tizen.native.appprogramming/html/guide/io/io_namespace.htm">Io Guide</a>.
 *
 * The following example demonstrates how to use the %File class.
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
	String fileName(L"test.txt");
	File file;
	char buffer[10];
	char buffer2[5];
	int i;
	int readCnt;
	result r = E_SUCCESS;

	// Creates file
	r = file.Construct(App::GetInstance()->GetAppDataPath() + fileName, "w+");
	if (IsFailed(r))
	{
		goto CATCH;
	}

	for (i = 0; i < 10; i++)
	{
		buffer[i] = (char) i;
	}

	// Writes to the file
	r = file.Write(buffer, 10);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Repositions the file pointer
	r = file.Seek(FILESEEKPOSITION_CURRENT, -5);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Reads
	readCnt = file.Read(buffer2, 5);
	r = GetLastResult();
	if (IsFailed(r))
	{
		goto CATCH;
	}
	if (readCnt != 5)
	{
		goto CATCH;
	}

	// Checks the correctness of the read data
	for (i = 0; i < readCnt; i++)
	{
		char m, n;
		m = buffer2[i];
		n = buffer[i + 5];
		if (m != n)
		{
			goto CATCH;
		}
	}
	AppLog("Succeeded!");
	return 0;

CATCH:
	AppLog("Failed...");
	return -1;
}

 * @endcode
 */

/**
 */

class _OSP_EXPORT_ File
	: public Tizen::Base::Object
{

public:
	/**
	* The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since		2.0
	*/
	File(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	virtual ~File(void);

	/**
	* @{
	* @if OSPDEPREC
	* Initializes this instance of %File with the specified parameters. @n
	* This method opens an existing file or creates a new one according to the specified file opening mode.
	*
	* @deprecated		This method is deprecated. Instead of using this method, use Directory::Create(const Tizen::Base::String &dirPath,
	*					bool createParentDirectories=false) and File::Construct(const Tizen::Base::String& filePath, const Tizen::Base::String& openMode).
	* @since			2.0
	*
	* @return		An error code
	* @param[in]	filePath				The path of the file to open or create
	* @param[in]	openMode				The file opening mode @n
	*										It can be one of the following:
	*										- r : Open for reading.
	*										- r+: Open for reading and writing.
	*										- w : Open for writing. The file is created if it does not exist,
	*											  otherwise it is truncated to zero length.
	*										- w+: Open for writing and reading. The file is created if it does not exist,
	*											  otherwise it is truncated to zero length.
	*										- a : Open for appending. The file is created if it does not exist.
	*										- a+: Open for appending and reading. The file is created if it does not exist.
	* @param[in]	createParentDirectories	Set to @c true to automatically create non-existent parent directories up to destination, @n
	*										else @c false @n
	*										This parameter is useful only if the specified @c openMode allows creation of an absent
	*										file. For example, the following modes: "w", "w+", "a" and "a+". @n
	*										If the value of @c openMode is not any one of these, E_INVALID_ARG exception is thrown.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*										- The overall length of the specified path is equal to @c 0 or
	*										  exceeds system limitations. @n
	*										- The combination of the specified @c openMode is not allowed. @n
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission. @n
	*										For example, opening a read-only file in the write mode such as "w" or "a".
	* @exception	E_FILE_NOT_FOUND		The specified @c filePath cannot be found.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception	E_STORAGE_FULL			The disk space is full.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @remarks		The following file opening mode strings are recognized by this method: "w+", "wb+", "w+b", "w", "wb", "a+",
	*				"ab+", "a+b", "a", "ab", "r+", "rb+", "r+b", "r", "rb". @n
	*				Other strings lead to E_INVALID_ARG. However, "b"(binary) open mode is ignored internally.
	* @endif
	* @}
	*/
	result Construct(const Tizen::Base::String& filePath, const Tizen::Base::String& openMode, bool createParentDirectories);

	/**
	* Initializes this instance of %File with the specified parameters. @n
	* This method opens an existing file or creates a new one according to the specified file opening mode.
	*
	* @since			2.0
	*
	* @return		An error code
	* @param[in]	filePath			The path of the file to open or create
	* @param[in]	openMode			The file opening mode @n
	*									It can be one of the following:
	*									- r : Open for reading.
	*									- r+: Open for reading and writing.
	*									- w : Open for writing. The file is created if it does not exist,
	*										  otherwise it is truncated to zero length.
	*									- w+: Open for writing and reading. The file is created if it does not exist,
	*										  otherwise it is truncated to zero length.
	*									- a : Open for appending. The file is created if it does not exist.
	*									- a+: Open for appending and reading. The file is created if it does not exist.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The overall length of the specified path is equal to @c 0 or
	*									  exceeds system limitations. @n
	*									- The combination of the specified @c openMode is not allowed. @n
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission. @n
	*									For example, opening a read-only file in the write mode such as "w" or "a".
	* @exception	E_FILE_NOT_FOUND	The specified @c filePath cannot be found.
	* @exception	E_MAX_EXCEEDED		The number of opened files has exceeded the maximum limit.
	* @exception	E_STORAGE_FULL		The disk space is full.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		The following file opening mode strings are recognized by this method: "w+", "wb+", "w+b", "w", "wb", "a+",
	*				"ab+", "a+b", "a", "ab", "r+", "rb+", "r+b", "r", "rb". @n
	*				Other strings lead to E_INVALID_ARG. However, "b"(binary) open mode is ignored internally.
	*/
	result Construct(const Tizen::Base::String& filePath, const Tizen::Base::String& openMode);

	/**
	* Initializes this instance of %File with the specified parameters. @n
	* This method opens an existing file or creates a new one according to the specified file opening mode.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	filePath			The path of the file to open or create
	* @param[in]	pOpenMode			The file opening mode @n
	*									It can be one of the following:
	*									- r : Open for reading.
	*									- r+: Open for reading and writing.
	*									- w : Open for writing. The file is created if it does not exist,
	*										  otherwise it is truncated to zero length.
	*									- w+: Open for writing and reading. The file is created if it does not exist,
	*										  otherwise it is truncated to zero length.
	*									- a : Open for appending. The file is created if it does not exist.
	*									- a+: Open for appending and reading. The file is created if it does not exist.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The overall length of the specified path is equal to @c 0 or
	*									  exceeds system limitations. @n
	*									- The combination of the specified @c pOpenMode is not allowed. @n
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission. @n
	*									For example, opening a read-only file in the write mode such as "w" or "a".
	* @exception	E_FILE_NOT_FOUND	The specified @c filePath cannot be found.
	* @exception	E_MAX_EXCEEDED		The number of opened files has exceeded the maximum limit.
	* @exception	E_STORAGE_FULL		The disk space is full.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		The following file opening mode strings are recognized by this method: "w+", "wb+", "w+b", "w", "wb", "a+",
	*				"ab+", "a+b", "a", "ab", "r+", "rb+", "r+b", "r", "rb". @n
	*				Other strings lead to E_INVALID_ARG. However, "b"(binary) open mode is ignored internally.
	*/
	result Construct(const Tizen::Base::String& filePath, const char* pOpenMode);

	/**
	* Initializes this instance of %File with the specified parameters. @n
	* This method opens an existing secure file or creates a new one according to the specified file opening mode. @n
	* The contents written to the secure file is automatically encrypted and the contents read from the secure file is automatically
	* decrypted by the platform. @n
	* Applications using this method can access the secure files that are created by other applications with the identical key value
	* in same device. However, the secure files created by this method cannot be accessed in other devices.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	filePath			The path of the file to open or create
	* @param[in]	pOpenMode			The file opening mode @n
	*									It can be one of the following:
	*									- r : Open for reading.
	*									- r+: Open for reading and writing.
	*									- w : Open for writing. The file is created if it does not exist,
	*										  otherwise it is truncated to zero length.
	*									- w+: Open for writing and reading. The file is created if it does not exist,
	*										  otherwise it is truncated to zero length.
	*									- a : Open for appending. The file is created if it does not exist.
	*									- a+: Open for appending and reading. The file is created if it does not exist.
	* @param[in]	secretKey			A key used to encrypt data of a file or decrypt a secure file @n
	*									If a secure file is created with a specific key value,
	*									other applications can access the same secure file with the identical key value.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The overall length of the specified path is equal to @c 0 or
	*									  exceeds system limitations.
	*									- The combination of the specified @c pOpenMode is not allowed. @n
	*									- The specified @c secretKey is incorrect or the secure file is corrupted.
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission. @n
	*									For example, opening a read-only file in the write mode such as "w" or "a".
	* @exception	E_FILE_NOT_FOUND	The specified @c filePath cannot be found.
	* @exception	E_MAX_EXCEEDED		The number of opened files has exceeded the maximum limit.
	* @exception	E_STORAGE_FULL		The disk space is full.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected. @n
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		The following file opening mode strings are recognized by this method: "w+", "wb+", "w+b", "w", "wb", "a+",
	*				"ab+", "a+b", "a", "ab", "r+", "rb+", "r+b", "r", "rb". @n
	*				Other strings lead to E_INVALID_ARG. However, "b"(binary) open mode is ignored internally.
	*/
	result Construct(const Tizen::Base::String& filePath, const char* pOpenMode, const Tizen::Base::ByteBuffer& secretKey);

	/**
	* Reads the byte data from the current file pointer. @n
	* The user-specified ByteBuffer is filled with the byte data from the current position in the file.
	* The read operation continues until the specified ByteBuffer is filled or end-of-file is met. @n
	* In the secure mode, the byte data read from the secure file is automatically decrypted by a platform security module.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in, out]	buffer				A reference to the buffer that is used to receive the byte data read from the file
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		The specified @c buffer has no space to store the read data.
	* @exception		E_ILLEGAL_ACCESS	Either of the following conditions has occurred: @n
	*										- The file is not opened for read operation. @n
	*										- Access is denied due to insufficient permission.
	* @exception		E_END_OF_FILE		The file pointer has reached end-of-file.
	* @exception		E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @remarks			The ByteBuffer should be constructed before being passed to the method.
	*/
	result Read(Tizen::Base::ByteBuffer& buffer);

	/**
	* Reads the byte data from the current file pointer and copies it into the specified buffer. @n
	* In the secure mode, the byte data read from the secure file is automatically decrypted by a platform security module.
	*
	* @since			2.0
	*
	* @return			The length of the data read in bytes, @n
	*					else @c 0 in case of failure
	* @param[out]		buffer				A pointer to the user-supplied buffer where the read data is copied
	* @param[in]		length				The buffer length in bytes
	* @exception	 	E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	*										- The specified @c buffer contains a @c null pointer. @n
	*										- The length of the specified @c buffer is equal to or smaller than @c 0. @n
	* @exception		E_ILLEGAL_ACCESS	Either of the following conditions has occurred: @n
	*										- The file is not opened for read operation. @n
	*										- Access is denied due to insufficient permission.
	* @exception		E_END_OF_FILE		The file pointer has reached end-of-file.
	* @exception		E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	int Read(void* buffer, int length);

	/**
	* Reads the string data from the current file pointer and copies the string to the specified buffer (it is assumed that the
	* file is in the UTF-8 format). @n
	* The read operation continues until new line character or end-of-file is met. @n
	* In the secure mode, the string data read from the secure file is automatically decrypted by a platform security module.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[out]		buffer				A reference to the buffer where the data is copied
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		The file handle is invalid (either the file is closed by another method, or the
	*										memory is corrupted).
	* @exception		E_ILLEGAL_ACCESS	Either of the following conditions has occurred: @n
	*										- The file is not opened for read operation. @n
	*										- Access is denied due to insufficient permission.
	* @exception		E_END_OF_FILE		The file pointer reached end-of-file.
	* @exception		E_IO				Either of the following conditions has occurred:
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @remarks			To get the expected string value
	* 					from a file, which is not in the UTF-8 format (Unicode or any other format),
	*					user should use other encoding or decoding methods of the Tizen::Text namespace after reading the content of
	*					a file in binary format. @n
	*					The maximum length of characters read by this method is defined as 4096. @n
	*					Therefore, if the length of a single line (considering new line character or end-of-file) from the current
	*					file position is longer than 4096, the rest of the characters remain as not read. @n
	*					'ByteBuffer' or 'void*' version of the File::Read() API can be used to overcome this limitation.
	*/
	result Read(Tizen::Base::String& buffer);

	/**
	* Writes the byte data from the specified ByteBuffer into a file beginning at the current position to the limit of the
	* %ByteBuffer. @n
	* In the secure mode, the byte data written by a user is automatically encrypted to the secure file by a platform security module. @n
	* The size of a secure file can be greater than the size of a normal (original) file
	* because of the encryption.
	* However, the file pointer for the secure file is equal to the file pointer for the original file.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		buffer				A reference to the buffer that contains byte data to write
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		The file handle is invalid (either the file is closed by another method, or the
	*										memory is corrupted).
	* @exception		E_ILLEGAL_ACCESS	Either of the following conditions has occurred: @n
	*										- The file is not opened for write operation. @n
	*										- Access is denied due to insufficient permission.
	* @exception		E_STORAGE_FULL		The disk space is full.
	* @exception		E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	*/
	result Write(const Tizen::Base::ByteBuffer& buffer);

	/**
	* Writes the byte data into a file. @n
	* In the secure mode, the byte data written by a user is automatically encrypted to the secure file by a platform security module. @n
	* The size of a secure file can be greater than the size of a normal (original) file
	* because of the encryption.
	* However, the file pointer for the secure file is equal to the file pointer for the original file.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		buffer				A pointer to the user-supplied buffer that contains @c byte data to write
	* @param[in]		length				The buffer length in bytes
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_ILLEGAL_ACCESS	Either of the following conditions has occurred: @n
	*										- The file is not opened for write operation. @n
	*										- Access is denied due to insufficient permission.
	* @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	*										- The specified @c buffer contains a @c null pointer. @n
	*										- The specified @c buffer length is equal or smaller than @c 0. @n
	* @exception		E_STORAGE_FULL		The disk space is full.
	* @exception		E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	*/
	result Write(const void* buffer, int length);

	/**
	* Writes the string data into a file. @n
	* In the secure mode, the string data written by a user is automatically encrypted to the secure file by a platform security
	* module. @n
	* The size of a secure file can be greater than the size of a normal (original) file
	* because of the encryption.
	* However, the file pointer for the secure file is equal to the file pointer for the original file.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		buffer				A reference to the buffer that contains string data to write
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_ILLEGAL_ACCESS	Either of the following conditions has occurred: @n
	*										- The file is not opened for write operation. @n
	*										- Access is denied due to insufficient permission.
	* @exception		E_INVALID_ARG		The specified @c buffer contains an empty string.
	* @exception		E_STORAGE_FULL		The disk space is full.
	* @exception		E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	*/
	result Write(const Tizen::Base::String& buffer);

	/**
	* Flushes the internally buffered data.
	*
	* @since			2.0
	*
	* @return			An error code
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception		E_INVALID_ARG		The file handle is invalid (either the file is closed by another method, or the
	*										memory is corrupted).
	* @exception        E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	*/
	result Flush(void);

	/**
	* Gets the offset of the current file pointer relative to the beginning of the file. @n
	* The size of a secure file can be greater than the size of a normal (original) file
	* because of the encryption.
	* However, the file pointer for the secure file is equal to the file pointer for the original file.
	*
	* @since			2.0
	*
	* @return			The offset of the current file pointer, @n
	*					else @c -1L if an error occurs
	* @exception	    E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		The file handle is invalid (either the file is closed by another method, or the
	*										memory is corrupted).
	* @exception        E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	* @see				Seek()
	*/
	int Tell(void) const;

	/**
	* Repositions the file pointer associated with an opened file. @n
	* Each opened file has its own file pointer, and it points to the next byte to be read or written in the file.
	* The repositioning offset can be specified with respect to the beginning of file, current position, or end of the file.
	* If the file pointer is over the end-of-file, it expands the file size to the specified position and the expanded area is
	* filled with zero. @n
	* The size of a secure file can be greater than the size of a normal (original) file
	* because of the encryption.
	* However, the file pointer for the secure file is equal to the file pointer for the original file.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		position			The origin from where to start the repositioning a file pointer
	* @param[in]		offset              The number of bytes to move a file pointer @n
	*										A negative offset moves the pointer backwards.
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		The specified @c position or @c offset is invalid.
	* @exception		E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception        E_STORAGE_FULL		The disk space is full.
	* @exception        E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	* 										- %File corruption is detected.
	* @see				FileSeekPosition
	*/
	result Seek(FileSeekPosition position, long offset);

	/**
	* Truncates the file size to the specified length. @n
	* If the specified length is less than the length of file, the bytes present between the @c length and size of a file are
	* removed.
	* If the file size is small, its size is increased. @n
	* The size of a secure file can be greater than the size of a normal (original) file
	* because of the encryption.
	* However, the file pointer for a secure file is equal to the file pointer for an original file.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		length				The required file size in bytes after this method is executed
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_ILLEGAL_ACCESS	Either of the following conditions has occurred: @n
	*										- The file is not opened for write operation. @n
	*										- Access is denied due to insufficient permission.
	* @exception		E_INVALID_ARG		The specified @c length has a negative value.
	* @exception        E_STORAGE_FULL		The disk space is full.
	* @exception        E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	* 										- %File corruption is detected.
	*/
	result Truncate(int length);

	/**
	* Gets the path associated with a constructed %File.
	*
	* @since			2.0
	*
	* @return			The file path to the currently constructed %File if successful, @n
	*					else an empty string in case of failure
	*/
	Tizen::Base::String GetName(void) const;

	/**
	* Acquires the file lock on the current opened whole file if it is not acquired.
	* If the file lock is already acquired by another process, the current process is blocked until the file lock is
	* released.
	*
	* @since			2.1
	*
	* @return           The pointer to %FileLock instance, @n
	*						else @c null pointer in case of failure
	* @param[in]		lockType				The type of file lock to be created
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_ARG			The specified @c lockType is invalid.
	* @exception		E_INVALID_OPERATION		Either of the following conditions has occurred: @n
	*												- The specified @c lockType cannot be FILE_LOCK_SHARED if the current
	*												  file is not open for reading. @n
	*												- The specified @c lockType cannot be FILE_LOCK_EXCLUSIVE if the current
	*												  file is not open for writing. @n
	* @exception		E_WOULD_DEADLOCK		The method would cause a deadlock. @n
	*												The lock is blocked by a lock from another process, and putting the
	*												calling process to sleep to wait for that lock to become free would
	*												cause a deadlock.
	* @exception		E_MAX_EXCEEDED			The number of file lock exceeds system limitations.
	* @exception		E_SYSTEM				The method cannot proceed due to a severe system error.
	* @remarks			The %FileLock instance is invalid if the associated %File instance is deleted. @n
	*						The specific error code can be accessed using the GetLastResult() method.
	* @see				Tizen::Io::File::FileLockType
	*/
	FileLock* LockN(FileLockType lockType);

	/**
	* Acquires the file lock on the specified region of the current opened file if it is not acquired.
	* If the file lock is already acquired by another process, the current process is blocked until the file lock is
	* released.
	*
	* @since			2.1
	*
	* @return			The pointer to %FileLock instance, @n
	*						else @c null pointer in case of failure
	* @param[in]		lockType				The type of file lock to be created
	* @param[in]		offset					The starting offset for the locked region
	* @param[in]		length					The length of the locked region in bytes
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The specified @c lockType is invalid.
	*											- The specified @c offset or @c length is negative or is greater than
	*											  the system limitation.
	* @exception		E_INVALID_OPERATION		Either of the following conditions has occurred: @n
	*												- The specified @c lockType cannot be FILE_LOCK_SHARED if the current
	*											  	  file is not open for reading. @n
	*												- The specified @c lockType cannot be FILE_LOCK_EXCLUSIVE if the current
	*											  	  file is not open for writing. @n
	* @exception		E_WOULD_DEADLOCK		The method would cause a deadlock. @n
	*												The lock is blocked by a lock from another process, and putting the
	*												calling process to sleep to wait for that lock to become free would
	*												cause a deadlock.
	* @exception		E_MAX_EXCEEDED			The number of file lock exceeds system limitations.
	* @exception		E_SYSTEM				The method cannot proceed due to a severe system error.
	* @remarks			The %FileLock instance is invalid if the associated %File instance is deleted. @n
	*						The specific error code can be accessed using the GetLastResult() method.
	* @see				Tizen::Io::File::FileLockType
	*/
	FileLock* LockN(FileLockType lockType, int offset, int length);

	/**
	* Tries to acquire the file lock on the current opened whole file.
	* If the file lock is already acquired by another process, E_OBJECT_LOCKED is returned.
	*
	* @since			2.1
	*
	* @return			The pointer to %FileLock instance, @n
	*						else @c null pointer in case of failure
	* @param[in]		lockType				The type of file lock to be created
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_ARG			The specified @c lockType is invalid.
	* @exception		E_INVALID_OPERATION		Either of the following conditions has occurred: @n
	*												- The specified @c lockType cannot be FILE_LOCK_SHARED if the current
	*												  file is not open for reading. @n
	*												- The specified @c lockType cannot be FILE_LOCK_EXCLUSIVE if the current
	*												  file is not open for writing. @n
	* @exception		E_OBJECT_LOCKED			Either of the following conditions has occurred: @n
	*												- The file lock is already held by another process. @n
	*												- The file to be locked has been memory-mapped by another process.
	* @exception		E_MAX_EXCEEDED			The number of file lock exceeds system limitations.
	* @exception		E_SYSTEM				The method cannot proceed due to a severe system error.
	* @remarks			The %FileLock instance is invalid if the associated %File instance is deleted. @n
	*						The specific error code can be accessed using the GetLastResult() method.
	* @see				Tizen::Io::File::FileLockType
	*/
	FileLock* TryToLockN(FileLockType lockType);

	/**
	* Tries to acquire the file lock on the specified region of the current opened file.
	* If the file lock is already acquired by another process, E_OBJECT_LOCKED is returned.
	*
	* @since			2.1
	*
	* @return			The pointer to %FileLock instance, @n
	*						else @c null pointer in case of failure
	* @param[in]		lockType				The type of file lock to be created
	* @param[in]		offset					The starting offset for the locked region
	* @param[in]		length					The length of the locked region in bytes
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*												- The specified @c lockType is invalid.
	*												- The specified @c offset or @c length is negative or is greater than
	*											  	  the system limitation.
	* @exception		E_INVALID_OPERATION		Either of the following conditions has occurred: @n
	*												- The specified @c lockType cannot be FILE_LOCK_SHARED if the current
	*												  file is not open for reading. @n
	*												- The specified @c lockType cannot be FILE_LOCK_EXCLUSIVE if the current
	*												  file is not open for writing. @n
	* @exception		E_OBJECT_LOCKED			Either of the following conditions has occurred: @n
	*												- The file lock is already held by another process. @n
	*												- The file to be locked has been memory-mapped by another process.
	* @exception		E_MAX_EXCEEDED			The number of file lock exceeds system limitations.
	* @exception		E_SYSTEM				The method cannot proceed due to a severe system error.
	* @remarks			The %FileLock instance is invalid if the associated %File instance is deleted. @n
	*						The specific error code can be accessed using the GetLastResult() method.
	* @see				Tizen::Io::File::FileLockType
	*/
	FileLock* TryToLockN(FileLockType lockType, int offset, int length);

	/**
	* Deletes the file specified. @n
	* The opened file cannot be deleted. This method is static.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		filePath			The path of the file to delete
	* @exception	    E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		Either of the following conditions has occurred: @n
	*										- The overall length of the specified path is equal to @c 0 or
	*										  exceeds system limitations. @n
	*										- The specified path is invalid.
	* @exception		E_ILLEGAL_ACCESS	Access is denied due to insufficient permission. @n
	*										For example, opening a read-only file in the write mode.
	* @exception		E_FILE_NOT_FOUND	An entry for the specified file or path cannot be found.
	* @exception        E_IO				Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @remarks          The opened file cannot be deleted.
	*/
	static result Remove(const Tizen::Base::String& filePath);

	/**
	* Moves the specified file to another location. @n
	* The opened files cannot be moved. This method is static.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		oldFilePath				The old file path
	* @param[in]		newFilePath				The new file path
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The overall length of the specified path is equal to @c 0 or
	*											  exceeds system limitations. @n
	*											- The specified path is invalid.
	* @exception		E_ILLEGAL_ACCESS		Access is denied due to insufficient permission. @n
	*											For example, opening a read-only file in the write mode.
	* @exception		E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception		E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception		E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception        E_STORAGE_FULL			The disk space is full.
	* @exception        E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected.
	* @see			Copy()
       * @see			Remove()
	*/
	static result Move(const Tizen::Base::String& oldFilePath, const Tizen::Base::String& newFilePath);

	/**
	* Copies the existing source file to the destined location. @n
	* This method is static.
	*
	* @since			2.0
	*
	* @return			An error code
	* @param[in]		srcFilePath		        The source file path
	* @param[in]		destFilePath	        The destination file path
	* @param[in]		failIfExist				Set to @c true to return an error if the destination file already exists, @n
	*											else @c false
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_INVALID_ARG			Either of the following conditions has occurred: @n
	*											- The overall length of the specified path is equal to @c 0 or
	*											  exceeds system limitations. @n
	*											- The specified path is invalid.
	* @exception		E_ILLEGAL_ACCESS		Access is denied due to insufficient permission. @n
	*											For example, opening a read-only file in the write mode.
	* @exception		E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception		E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception		E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception        E_STORAGE_FULL			The disk space is full.
	* @exception        E_IO					Either of the following conditions has occurred: @n
	*											- An unexpected device failure has occurred as the media ejected suddenly. @n
	*											- %File corruption is detected.
	* @see			Move()
    	* @see			Remove()
	*/
	static result Copy(const Tizen::Base::String& srcFilePath, const Tizen::Base::String& destFilePath, bool failIfExist);

	/**
	* Reads the file information such as size, attribute, creation date, and so on. @n
	* This method is static.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	filePath			The path of the file @n
	* @param[out]	attribute			A %File attribute instance
	* @exception    E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The overall length of the specified path is equal to @c 0 or
	*									  exceeds system limitations. @n
	*									- The specified path is invalid.
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception	E_FILE_NOT_FOUND	An entry for the specified file or path cannot be found.
	* @exception    E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	*/
	static result GetAttributes(const Tizen::Base::String& filePath, FileAttributes& attribute);

	/**
	* Gets only the file name from the specified file path. @n
	* For example, if the file path passed is 'xxx/file.txt', 'file.txt' is returned.
	*
	* @since		2.0
	*
	* @return		The file name of type String
	* @param[in]	filePath		The path of the file
	* @exception    E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The length of the specified path is @c 0 or exceeds system limitations.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			GetFileExtension()
	*/
	static Tizen::Base::String GetFileName(const Tizen::Base::String& filePath);

	/**
	* Gets the file extension of the specified file path.
	*
	* @since		2.0
	*
	* @return		The file extension, @n
	*				else an empty string if the file has no extension
	* @param[in]	filePath		The path of the file
	* @exception    E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The length of the specified path is @c 0 or exceeds system limitations.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			GetFileName()
	*/
	static Tizen::Base::String GetFileExtension(const Tizen::Base::String& filePath);

	/**
	* Checks whether the specified file or directory exists.
	*
	* @since		2.0
	*
	* @return		@c true if file or directory exists, @n
	*				else @c false
	* @param[in]	filePath			The path of the file or directory
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The overall length of the specified path is equal to @c 0 or
	*									  exceeds system limitations. @n
	*									- The specified path is invalid.
	* @exception	E_ILLEGAL_ACCESS	The specified path is not permitted, or
	*									access is denied due to insufficient permission.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	static bool IsFileExist(const Tizen::Base::String& filePath);

	/**
	* Converts a normal file to a secure file. @n
	* A secure file that is converted by this method can be shared among applications with the same key value.
	* This method is static.
	*
	* @since 2.0
	*
	* @return		An error code
	* @param[in]	plainFilePath			The normal (non-encrypted) file path
	* @param[in]	secureFilePath			The secure (encrypted) file path to create
	* @param[in]	key						A key that encrypts a secure file @n
	*										If the secure file is converted with a specific key value,
	*										applications can access the same secure file with the identical key value.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*										- The overall length of the specified path is equal to @c 0 or
	*										  exceeds system limitations. @n
	*										- The specified path is invalid. @n
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception	E_STORAGE_FULL			The disk space is full.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected. @n
	*										- The number of opened files has exceeded the maximum limit.
	*/
	static result ConvertToSecureFile(const Tizen::Base::String& plainFilePath, const Tizen::Base::String& secureFilePath, const Tizen::Base::ByteBuffer& key);

private:
	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	*/
	File(const File& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	*/
	File& operator =(const File& rhs);

	class _FileImpl* __pFileImpl;

	friend class _FileImpl;

}; // File

}} // Tizen::Io

#endif // _FIO_FILE_H_

