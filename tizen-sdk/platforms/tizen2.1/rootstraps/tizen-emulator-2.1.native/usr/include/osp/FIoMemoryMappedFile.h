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
 * @file	FIoMemoryMappedFile.h
 * @brief	This is the header file for the %MemoryMappedFile class.
 *
 * This header file contains the declarations of the %MemoryMappedFile class.
 */

#ifndef _FIO_MEMORY_MAPPED_FILE_H_
#define _FIO_MEMORY_MAPPED_FILE_H_

#include <FOspConfig.h>
#include <FBaseObject.h>

namespace Tizen { namespace Io
{

/**
 * @enum	MemoryMappedFileFlag
 *
 * Defines flags providing information about the handling of a memory mapped file.
 *
 * @since	2.0
 */
enum MemoryMappedFileFlag
{
	MEMORY_MAPPED_FILE_FLAG_SHARED = 0x01,	/**< Changes are shared with other processes mapping the same file */
	MEMORY_MAPPED_FILE_FLAG_PRIVATE = 0x02,	/**< Changes are not visible to other processes mapping the same file */
	MEMORY_MAPPED_FILE_FLAG_FIXED = 0x10	/**< This forces the system to use the specified mapping address exactly,
											  which should be a multiple of the page size */
};

/**
 * @enum	MemoryMappedFileSyncFlag
 *
 * Defines synchronization flags of a memory mapped file.
 *
 * @since	2.0
 */
enum MemoryMappedFileSyncFlag
{
	MEMORY_MAPPED_FILE_SYNC_FLAG_ASYNC = 0x01,		/**< Asynchronous update */
	MEMORY_MAPPED_FILE_SYNC_FLAG_SYNC = 0x02		/**< Synchronous update */
};

/**
 * @class	MemoryMappedFile
 * @brief	This class provides features mapping a file to virtual address space.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %MemoryMappedFile class provides features for using a memory mapped file,
 * which maps the data of a file to an application's virtual address space.
 *
 * @code
 *
 * #include <FBase.h>
 * #include <FIo.h>
 * #include <FApp.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Base::Runtime;
 * using namespace Tizen::Base::Collection;
 * using namespace Tizen::Io;
 * using namespace Tizen::App;
 *
 * result
 * MyApp::Execute(void)
 * {
 *	File file;
 *	String filePath(App::GetInstance()->GetAppDataPath() + L”myFile.txt”);
 *	file.Construct(filePath, “w+);
 *
 *	String testMsg(L”MemoryMappedFileTest”);
 *	file.Write(testMsg);
 *	file.Flush();
 *
 *	long long mapLength = 4096;
 *	MemoryMappedFile mapFile;
 *	mapFile.Construct(file);
 *	void* pMappedAddr = mapFile.Map(null, mapLength, MEMORY_PROTECTION_MODE_READ | MEMORY_PROTECTION_MODE_WRITE, MEMORY_MAPPED_FILE_FLAG_SHARED, 0);
 *
 *	char* pBuffer = new char[testMsg.GetLength() + 1];
 *	memcpy(pBuffer, pMappedAddr, testMsg.GetLength());
 *
 * }
 *
 * @endcode
 */
class _OSP_EXPORT_ MemoryMappedFile
	: public Tizen::Base::Object
{

public:
	/**
	* The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since	2.0
	*/
	MemoryMappedFile(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	~MemoryMappedFile(void);

	/**
	* Initializes this instance of %MemoryMappedFile with a specified file.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	file				The File instance for memory mapping
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c file is not opened for reading. @n
	*									The opening mode should not be "w" or "a".
	* @remarks		The specified @c file should be initialized by the Io::File::Construct() method.
	* @see			Tizen::Io::File
	*/
	result Construct(const File& file);

	/**
	* Creates a new mapping for the specified file in the virtual address space of the calling process.
	*
	* @since		2.0
	*
	* @return		The mapped address space, @n
	*				else @c null pointer if this method fails
	* @param[in]	address					A starting address of the mapping @n
	*										If the specified @c address is @c null, the system chooses the address.
	*										It should be a multiple of the page size.
	* @param[in]	length					The length of the mapping space
	* @param[in]	protection				The memory protection of the mapping @n
	*										It is either Base::Runtime::MEMORY_PROTECTION_MODE_NONE or the bitwise-inclusive OR of one
	*										or more of the other modes in Base::Runtime::MemoryProtectionMode.
	* @param[in]	flag					The flag providing information about the handling of a memory mapped file @n
	*										It is the bitwise-inclusive OR of the flags in Tizen::Io::MemoryMappedFileFlag.
	* @param[in]	offset					The start offset of the specified file @n
	*										It should be a multiple of the page size.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_ILLEGAL_ACCESS		The specified @c flag is MEMORY_MAPPED_FILE_FLAG_SHARED and the specified @c
	*										protection is MEMORY_PROTECTION_MODE_WRITE, but the specified file of
	*										MemoryMappedFile::Construct() is not opened with read-write mode.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*										- The specified @c address or @c offset is not aligned on a page boundary. @n
	*										- The specified @c length is not positive. @n
	*										- The specified @c protection, @c flag, or @c offset @ is invalid. @n
	*										- The specified @c flag cannot contain both MEMORY_MAPPED_FILE_FLAG_PRIVATE and
	*										  MEMORY_MAPPED_FILE_FLAG_SHARED.
	* @exception	E_MAX_EXCEEDED			The number of mapped regions has exceeded the maximum limit.
	* @exception	E_OBJECT_LOCKED			The mapped file has been locked.
	* @exception	E_OUT_OF_MEMORY			Either of the following conditions has occurred: @n
	*										- The memory is insufficient. @n
	*										- The specified @c flag is MEMORY_MAPPED_FILE_FLAG_FIXED, and the specified address
	*										  range exceeds that allowed for the address space of a current process.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*										- The underlying file system does not support memory mapping. @n
	*										- The specified @c protection is MEMORY_PROTECTION_MODE_EXEC, but the mapped file
	*										  exists on a file system that has been mounted no-exec.
	* @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	*				When this instance is destructed, all mappings are deleted automatically.
	* @see			Tizen::Base::Runtime::MemoryManager
	*/
	void* Map(void* address, long long length, unsigned long protection, unsigned long flag, long long offset);

	/**
	* Deletes the mapping of the specified address space. @n
	* Further references to the addresses within the range result in generation of an invalid memory access. @n
	* This method flushes all changes of a shared mapping to the correlated file on the permanent storage.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	address				The memory mapping address to unmap
	* @param[in]	length				The length of the mapping space
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The specified @c address is not aligned on a page boundary. @n
	*									- The specified @c length is not positive. @n
	*									- The specified address range is out of the valid address space of a current process.
	* @remarks		When this instance is destructed, all mappings of the instance are not unmapped automatically.
	*/
	result Unmap(void* address, long long length);

	/**
	* Flushes all changes of an address range to the correlated file on the permanent storage.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	address				The memory mapping address to synchronize
	* @param[in]	length				The length of the mapping space
	* @param[in]	syncFlag			The synchronization option
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The specified @c address is not aligned on a page boundary. @n
	*									- The specified @c length is not positive. @n
	*									- The specified @c syncFlag is invalid. @n
	*									- The specified @c address space is not mapped.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @remarks		The specific page size of a current file system is provided by Tizen::System::SystemInfo class with
	*				"StorageInfo" key.
	* @see			Tizen::Io::MemoryMappedFileSyncFlag
    * @see 	        Tizen::System::SystemInfo
	*/
	result Sync(void* address, long long length, MemoryMappedFileSyncFlag syncFlag);

private:
	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	*/
	MemoryMappedFile(const MemoryMappedFile& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	*/
	MemoryMappedFile& operator =(const MemoryMappedFile& rhs);

	class _MemoryMappedFileImpl* __pMemoryMappedFileImpl;

	friend class _MemoryMappedFileImpl;

}; // MemoryMappedFile

}} // Tizen::Io

#endif // _FIO_MEMORY_MAPPED_FILE_H_

