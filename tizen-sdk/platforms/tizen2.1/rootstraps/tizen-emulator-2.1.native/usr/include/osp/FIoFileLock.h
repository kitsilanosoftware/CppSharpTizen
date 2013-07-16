//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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

/**
 * @file	FIoFileLock.h
 * @brief	This is the header file for the %FileLock class.
 *
 * This header file contains the declarations of the %FileLock class.
 */

#ifndef _FIO_FILE_LOCK_H_
#define _FIO_FILE_LOCK_H_

namespace Tizen { namespace Io
{

/**
 * @enum FileLockType
 *
 * Defines the file lock types.
 *
 * @since	2.1
 */
enum FileLockType
{
	FILE_LOCK_SHARED,		/**< More than one process can hold a shared file lock on a file region @n
							A shared lock prevents any other process from setting an exclusive lock on the file
							region. */
	FILE_LOCK_EXCLUSIVE		/**< Only one process can hold an exclusive lock on a file region @n
							An exclusive lock prevents any other process from setting both shared and exclusive
							lock on the file region. */
};

/**
 * @class	FileLock
 * @brief	This class provides methods to check %FileLock type and release it.
 *
 * @since	2.1
 *
 * @final	This class is not intended for extension.
 *
 * The %FileLock class provides methods to check %FileLock type and release it.
 *
 * @see Tizen::Io::File
 * @see Tizen::Io::Registry
 */
class _OSP_EXPORT_ FileLock
	: public Tizen::Base::Object
{

public:
	/**
	* This destructor releases the file lock on the current opened file if acquired.
	*
	* @since          2.1
	*/
	virtual ~FileLock(void);

	/**
	* Checks whether the file lock is shared.
	*
	* @since          2.1
	*
	* @return         @c true if the file lock is shared, @n
	*                    else @c false
	*/
	bool IsShared(void) const;

	/**
	* Checks whether the file lock is exclusive.
	*
	* @since          2.1
	*
	* @return         @c true if the file lock is exclusive, @n
	*                    else @c false
	*/
	bool IsExclusive(void) const;

	/**
	* Checks whether the file lock is valid. @n
	* The lock is valid unless the associated file has been closed.
	*
	* @since          2.1
	*
	* @return         @c true if the file lock is valid, @n
	*                    else @c false
	*/
	bool IsValid(void) const;

private:
	//
	// This default constructor is intentionally declared as private so that only the platform can create an instance.
	//
	// @since	2.1
	//
	FileLock(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	FileLock(const FileLock& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	FileLock& operator =(const FileLock& rhs);

	class _FileLockImpl* __pFileLockImpl;

	friend class _FileLockImpl;

}; // FileLock

}} // Tizen::Io

#endif // _FIO_FILE_LOCK_H_
