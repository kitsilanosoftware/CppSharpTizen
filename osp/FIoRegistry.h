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
 * @file	FIoRegistry.h
 * @brief	This is the header file for the %Registry class.
 *
 * This header file contains the declarations of the %Registry class.
 */

#ifndef _FIO_REGISTRY_H_
#define _FIO_REGISTRY_H_

#include <FBaseObject.h>
#include <FBaseUuId.h>
#include <FBaseByteBuffer.h>
#include <FBaseColArrayList.h>
#include <FBaseResult.h>
#include <FBaseColIMap.h>

namespace Tizen {namespace Base
{
class String;
class ByteBuffer;
}}

namespace Tizen { namespace Io
{

static const long REG_OPEN_READ_ONLY  = 0x00000001L;
static const long REG_OPEN_READ_WRITE = 0x00000002L;
static const long REG_OPEN_CREATE     = 0x00000004L;

/**
 * @class	Registry
 * @brief	This class provides a mechanism to access and manipulate registry files.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Registry class provides a mechanism to access and manipulate registry files.
 *
 * For more information on the class features,
 * see <a href="../org.tizen.native.appprogramming/html/guide/io/io_namespace.htm">Io Guide</a>.
 *
 * The following example demonstrates how to use the %Registry class.
 *
 * @code
#include <FBase.h>
#include <FIo.h>
#include <FApp.h>

using namespace Tizen::Base;
using namespace Tizen::Io;
using namespace Tizen::App;

void
RegistryTest()
{
	Registry reg;
	String regPathName(L"regTest.ini");

	// Section name
	String sect1(L"section1");
	String sect2(L"section2");
	String sect3(L"section3");

	// Entry name
	String entry1(L"entry1");
	String entry2(L"entry2");

	int iVal;
	result r;

	r = reg.Construct(App::GetInstance()->GetAppDataPath() + regPathName, "a+");
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Create sections
	r = reg.AddSection(sect1);
	r = reg.AddSection(sect2);
	r = reg.AddSection(sect3);

	// Add value: section1 { entry1 = 999 }
	r = reg.AddValue(sect1, entry1, 999);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Change value: section1 { entry1 = 3 }
	r = reg.SetValue(sect1, entry1, 3);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Add value: section2 { entry2 = 1.1234599 }
	r = reg.AddValue(sect2, entry2, 1.1234599);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Get value: section1 { entry1 = ? }
	r = reg.GetValue(sect1, entry1, iVal);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	// Write to the file
	r = reg.Flush();
	if (IsFailed(r))
	{
		goto CATCH;
	}

	return;

CATCH:
	// Do some error handling
	return;
}
 * @endcode
 */

class _OSP_EXPORT_ Registry
	: public Tizen::Base::Object
{

public:
	/**
	* The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since	2.0
	*/
	Registry(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	virtual ~Registry(void);

	/**
	* @if OSPDEPREC
	* @{
	* Initializes this instance of %Registry with the specified parameters. @n
	* This method loads a registry file in the read-write mode.
	*
	* @if OSPCOMPAT
	* @brief			<i> [Deprecated] [Compatibility] </i>
	* @endif
	* @deprecated		This method is deprecated. Instead of using this method, use Directory::Create(const Tizen::Base::String &dirPath,
	*					bool createParentDirectories=false) and Registry::Construct(const Tizen::Base::String& regPath, const Tizen::Base::String& openMode).
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompIoPathPage "here".
	* @endif
	*
	* @return		An error code
	* @param[in]	regPath					The path of the registry file to open or create
	* @param[in]	createIfNotExist		Set to @c true to create a registry file, @n
	*                                       else @c false to open an existing registry file
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*										- The length of the specified string of a file path is less
	*										  than or equal to @c 0. @n
	*										- The translated overall length of the specified path exceeds the
	*										  system limitation. @n
	*										- The specified path is invalid. @n
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_END_OF_FILE			The file pointer has reached end-of-file.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception    E_STORAGE_FULL			The disk space is full.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @exception	E_INVALID_FORMAT		The input registry file contains '0x00' in the middle of the file.
	* @exception	E_PARSING_FAILED		The method has failed to parse the registry file.
	* @remarks		To load the registry in read-only mode, use the Registry::Construct(const Tizen::Base::String& regPath,
	*               long openMode, long option) method with REG_OPEN_READ_ONLY as a value for the open mode flag.
	* @}
	* @endif
	*/
	result Construct(const Tizen::Base::String& regPath, bool createIfNotExist);

	/**
	* @if OSPDEPREC
	* @{
	* Initializes this instance of %Registry with the specified parameters. @n
	* This method loads a registry file in the read-only or the read-write mode.
	*
	* @if OSPCOMPAT
	* @brief			<i> [Deprecated] [Compatibility] </i>
	* @endif
	* @deprecated		This method is deprecated. Instead of using this method, use Directory::Create(const Tizen::Base::String &dirPath,
	*					bool createParentDirectories=false) and Registry::Construct(const Tizen::Base::String& regPath, const Tizen::Base::String& openMode).
	* @since			2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompIoPathPage "here".
	* @endif
	*
	* @return		An error code
	* @param[in]	regPath					The path of the registry file to open or create
	* @param[in]	openMode				An open mode flag @n
	*                                       Currently, the following flags can be used in combination with
	*                                       the logical OR operator: @n
	*										 (1) REG_OPEN_READ_ONLY @n
	*										 (2) REG_OPEN_READ_WRITE @n
	*										 (3) REG_OPEN_READ_WRITE | REG_OPEN_CREATE
	* @param[in]	option					This argument is reserved for further use @n It is recommended to use @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*										- The length of the specified string of a file path is less
	*										  than or equal to @c 0. @n
	*										- The translated overall length of the specified path exceeds the
	*										  system limitation. @n
	*										- The specified path is invalid. @n
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_END_OF_FILE			The file pointer has reached end-of-file.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception    E_STORAGE_FULL			The disk space is full.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @exception	E_INVALID_FORMAT		The input registry file contains '0x00' in the middle of the file.
	* @exception	E_PARSING_FAILED		The method has failed to parse the registry file.
	* @}
	* @endif
	*/
	result Construct(const Tizen::Base::String& regPath, long openMode, long option);

	/**
	* Initializes this instance of %Registry with the specified parameters. @n
	* This method opens an existing registry file or creates a new one according to the specified file opening mode.
	* And this method loads data of the registry file to system memory and flushes the data to the storage when this instance
	* is released or Registry::Flush() is called.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	regPath				The path of the registry file to open or create
	* @param[in]	pOpenMode			The file opening mode @n
	*									It can be one of the following:
	*									- r : Open for reading.
	*									- r+: Open for reading and writing.
	*									- w : Open for writing. The registry file is created if it does not exist,
	*										  otherwise it is truncated to zero length.
	*									- w+: Open for writing and reading. The registry file is created if it does not exist,
	*										  otherwise it is truncated to zero length.
	*									- a : Open for appending. The registry file is created if it does not exist.
	*									- a+: Open for appending and reading. The registry file is created if it does not exist.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The overall length of the specified @c regPath is equal to @c 0 or
	*									  exceeds system limitations. @n
	*									- The combination of the specified @c pOpenMode is not allowed. @n
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception	E_FILE_NOT_FOUND	The specified @c regPath cannot be found.
	* @exception	E_INVALID_FORMAT	Either of the following conditions has occurred: @n
	*									- The section or entry name of the registry file includes one of the following characters:
	*									'\0', '\n', '#' and '='.
	*									- The entry value of the registry file includes one of the following characters:
	*									'\0' and '\n'.
	* @exception	E_MAX_EXCEEDED		The number of opened files has exceeded the maximum limit.
	* @exception    E_STORAGE_FULL		The disk space is full.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	*/
	result Construct(const Tizen::Base::String& regPath, const char* pOpenMode);

	/**
	* Initializes this instance of %Registry with the specified parameters. @n
	* This method opens an existing secure registry file or creates a new one according to the specified file opening mode.
	* And this method loads data of the secure registry file to system memory and flushes the data to the storage when this instance
	* is released or Registry::Flush() is called.
	* The contents written to the secure registry file is automatically encrypted and the contents read from the secure registry
	* file is automatically decrypted by the platform. @n
	* Applications using this method can access the same secure registry files that are created by other applications with the
	* identical key value in same device. However, the secure registry files created by this method cannot be accessed in other devices.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	regPath				The path of the registry file to open or create
	* @param[in]	pOpenMode			The file opening mode @n
	*									It can be one of the following:
	*									- r : Open for reading.
	*									- r+: Open for reading and writing.
	*									- w : Open for writing. The registry file is created if it does not exist,
	*										  otherwise it is truncated to zero length.
	*									- w+: Open for writing and reading. The registry file is created if it does not exist,
	*										  otherwise it is truncated to zero length.
	*									- a : Open for appending. The registry file is created if it does not exist.
	*									- a+: Open for appending and reading. The registry file is created if it does not exist.
	* @param[in]	secretKey			A key used to encrypt data of a registry file or decrypt a secure registry file @n
	*									If a secure registry file is created with a specific key value,
	*									other applications can access the same secure registry file with the identical key value.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The overall length of the specified path is equal to @c 0 or
	*									  exceeds system limitations.
	*									- The combination of the specified @c pOpenMode is not allowed. @n
	*									- The specified @c secretKey is incorrect or the secure registry file is corrupted.
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception	E_FILE_NOT_FOUND	The specified @c regPath cannot be found.
	* @exception	E_INVALID_FORMAT	Either of the following conditions has occurred: @n
	*									- The section or entry name of the registry file includes one of the following characters:
	*									'\0', '\n', '#' and '='.
	*									- The entry value of the registry file includes one of the following characters:
	*									'\0' and '\n'.
	* @exception	E_MAX_EXCEEDED		The number of opened files has exceeded the maximum limit.
	* @exception    E_STORAGE_FULL		The disk space is full.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected. @n
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	*/
	result Construct(const Tizen::Base::String& regPath, const char* pOpenMode, const Tizen::Base::ByteBuffer& secretKey);

	/**
	* Writes the current contents of a registry in memory to the non-volatile storage. @n
	* If the secure mode is set to be @c true, the contents of the registry are automatically encrypted
	* and saved by the platform.
	*
	* @since		2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception    E_STORAGE_FULL			The disk space is full.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected. @n
	*										- The memory is insufficient.
	*/
	result Flush(void);

	/**
	* Creates the specified section then adds it into the registry.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The length of the specified string for a section name is less than
	*                                       or equal to @c 0.
	* @exception	E_SECTION_ALREADY_EXIST	A section with the specified name already exists.
	*/
	result AddSection(const Tizen::Base::String& sectionName);

	/**
	* Removes the section from %Registry.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name to remove
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The length of the specified string for a section is less than
	*                                       or equal to @c 0.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	*/
	result RemoveSection(const Tizen::Base::String& sectionName);

	/**
	* Gets all section names in the registry.
	*
	* @since		2.0
	*
	* @return		A list of section names @n
	*				If this method fails, @c null value is returned. @n
	*				The specific error code can be accessed using the GetLastResult() method. @n
	*				When there are no sections at all, the method returns an empty list instance. @n
	*				Use the Tizen::Base::Collection::ICollection::GetCount() method to check the number of elements in the list.
	* @exception	E_SUCCESS				The method is successful.
	* @remarks		Do not forget to delete not only the returned IList instance, but also its
	*               contents by invoking IList::RemoveAll(). @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Base::Collection::IList* GetAllSectionNamesN(void) const;

	/**
	* Gets all entry names in the specified section of the registry.
	*
	* @since		2.0
	*
	* @return		A list of entry names @n
	*				If this method fails, @c null value is returned. @n
	*				When there are no entries at all, the method returns an empty list instance. @n
	*				Use the Tizen::Base::Collection::ICollection::GetCount() method to check the number of element in the list.
	* @param[in]	sectionName				The section name
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_IO					A system error has occurred.
	* @remarks		Do not forget to delete not only the returned IList instance, but also its
	*				contents by invoking IList::RemoveAll(). @n
	*				The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Base::Collection::IList* GetAllEntryNamesN(const Tizen::Base::String& sectionName) const;

	/**
	* Adds the name-value pair of type integer as an entry of the specific section.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name
	* @param[in]	value					The @c int value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_ALREADY_EXIST		The specified @c entryName already exists in this section.
	*/
	result AddValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, int value);

	/**
	* Adds the name-value pair of type double as an entry of the specific section.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name
	* @param[in]	value					The @c double value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_ALREADY_EXIST		The specified @c entryName already exists in this section.
	*/
	result AddValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, double value);

	/**
	* Adds the name-value pair of type float as an entry of the specific section.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name
	* @param[in]	value					The @c float value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_ALREADY_EXIST		The specified @c entryName already exists in this section.
	*/
	result AddValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, float value);

	/**
	* Adds the name-value pair of type String as an entry of the specific section.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name
	* @param[in]	value					The String value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0.
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_ALREADY_EXIST		The specified @c entryName already exists in this section.
	*/
	result AddValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, const Tizen::Base::String& value);

	/**
	* Adds the name-value pair of type UuId as an entry for the specified section.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name
	* @param[in]	value					The UuId value
	* @exception	E_SUCCESS				The method is successful.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_ALREADY_EXIST		The specified @c entryName already exists in this section.
	*/
	result AddValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, const Tizen::Base::UuId& value);

	/**
	* Adds the name-value pair of type ByteBuffer as an entry for the specified section.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name
	* @param[in]	value					The @c ByteBuffer value @n
	*                                       Note that, it should be constructed before being passed to the method.
	* @exception	E_SUCCESS				The method is successful.
    * @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_ALREADY_EXIST		The specified @c entryName already exists in this section.
	* @remarks		Note that all the contents of @c ByteBuffer are saved as an entry value.
	*               That is, byte data from @c 0 up to the buffer limit is saved.
	* @see			Tizen::Base::ByteBuffer
	*/
	result AddValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, const Tizen::Base::ByteBuffer& value);

	/**
	* Gets the @c int value of the specified entry.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of entry where its value will be fetched
	* @param[out]	retVal					The return value obtained from the registry
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @exception	E_PARSING_FAILED		The method has failed to parse the encoded entry value string, or the value is retrieved by using an incorrect data type.
	* @exception	E_DATA_NOT_FOUND		The name-value pair has no value assigned (if the value is retrieved using the REGTYPE_STRING type, an empty string is returned even if no value is assigned).
	*/
	result GetValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, int& retVal) const;

	/**
	* Gets the @c double value of the specified entry.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of entry where its value will be fetched
	* @param[out]	retVal					The return value obtained from the registry
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @exception	E_PARSING_FAILED		The method has failed to parse the encoded entry value string, or the value is retrieved by using an incorrect data type.
	* @exception	E_DATA_NOT_FOUND		The name-value pair has no value assigned (if the value is retrieved using the REGTYPE_STRING type, an empty string is returned even if no value is assigned).
	*/
	result GetValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, double& retVal) const;

	/**
	* Gets the @c float value of the specified entry.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of entry where its value will be fetched
	* @param[out]	retVal					The return value obtained from the registry
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @exception	E_PARSING_FAILED		The method has failed to parse the encoded entry value string, or the value is retrieved by using an incorrect data type.
	* @exception	E_DATA_NOT_FOUND		The name-value pair has no value assigned (if the value is retrieved using the REGTYPE_STRING type, an empty string is returned even if no value is assigned).
	*/
	result GetValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, float& retVal) const;

	/**
	* Gets the String value of a specific entry.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of entry where its value will be fetched
	* @param[out]	retVal					The return value obtained from the registry
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @exception	E_PARSING_FAILED		The method has failed to parse the encoded entry value string, or the value is retrieved by using an incorrect data type.
	* @exception	E_DATA_NOT_FOUND		The name-value pair has no value assigned (if the value is retrieved using the REGTYPE_STRING type, an empty string is returned even if no value is assigned).
	*/
	result GetValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, Tizen::Base::String& retVal) const;

	/**
	* Gets the UuId value of the specified entry.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of entry where its value will be fetched
	* @param[out]	retVal					The return value obtained from the registry
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND	    The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @exception	E_PARSING_FAILED		The method has failed to parse the encoded entry value string, or the value is retrieved by using an incorrect data type.
	* @exception	E_DATA_NOT_FOUND		The name-value pair has no value assigned (if the value is retrieved using the REGTYPE_STRING type, an empty string is returned even if no value is assigned).
	*/
	result GetValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, Tizen::Base::UuId& retVal) const;

	/**
	* Gets the ByteBuffer value of the specified entry.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The name of entry where its value will be fetched
	* @param[out]	retVal					The return value obtained from the registry
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @exception	E_PARSING_FAILED		The method has failed to parse the encoded entry value string, or the value is retrieved by using an incorrect data type.
	* @exception	E_DATA_NOT_FOUND		The name-value pair has no value assigned (if the value is retrieved using the REGTYPE_STRING type, an empty string is returned even if no value is assigned).
	* @remarks		The ByteBuffer should be constructed before passing it to the method.
	*				That is, the size of the binary data to be fetched should be decided beforehand.
	*				When the %ByteBuffer capacity is less than the actual binary data stored in the registry,
	*				this method reads the data as much as the %ByteBuffer capacity. The position of the %ByteBuffer and
	*				limit are not changed. When the %ByteBuffer capacity is greater than the actual data size,
	*				the method reads the whole data and adjusts the limit of the buffer accordingly.
	* @see			Tizen::Base::ByteBuffer
	*/
	result GetValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, Tizen::Base::ByteBuffer& retVal) const;

	/**
	* Modifies the value of the specified entry using the specified @c int value.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to modify
	* @param[in]	newValue				The @c int value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @remarks		This method will not add a name-value pair as an entry of a specific section
	*               if no entry with the specified name exists.
	*				In such a case, it returns E_KEY_NOT_FOUND. Use AddValue() to insert a new entry.
	* @see			AddValue()
	*/
	result SetValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, int newValue);

	/**
	* Modifies the value of the specified entry using the specified @c double value.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to modify
	* @param[in]	newValue				The @c double value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @remarks		This method will not add a name-value pair as an entry of a specific section
	*               if no entry with the specified name exists.
	*				In such a case, it returns E_KEY_NOT_FOUND. Use AddValue() to insert a new entry.
	* @see			AddValue()
	*/
	result SetValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, double newValue);

	/**
	* Modifies the value of the specified entry using the specified @c float value.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to modify
	* @param[in]	newValue				The @c float value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @remarks		This method will not add a name-value pair as an entry of a specific section
	*               if no entry with the specified name exists.
	*				In such a case, it returns E_KEY_NOT_FOUND. Use AddValue() to insert a new entry.
	* @see			AddValue()
	*/
	result SetValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, float newValue);

	/**
	* Modifies the value of the specified entry using the specified String value.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to modify
	* @param[in]	newValue				The String value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0.
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @remarks		This method will not add a name-value pair as an entry of a specific section
	*               if no entry with the specified name exists.
	*				In such a case, it returns E_KEY_NOT_FOUND. Use AddValue() to insert a new entry.
	* @see			AddValue()
	*/
	result SetValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, const Tizen::Base::String& newValue);

	/**
	* Modifies the value of the specified entry using the specified UuID value.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to modify
	* @param[in]	newValue				The UuId value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @remarks		This method will not add a name-value pair as an entry of a specific section if no
	*               entry with the specified name exists.
	*				In such a case, it returns E_KEY_NOT_FOUND. Use AddValue() to insert a new entry.
	* @see			AddValue()
	*/
	result SetValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, const Tizen::Base::UuId& newValue);

	/**
	* Modifies the value of the specified entry using the specified ByteBuffer value.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to modify
	* @param[in]	newValue				The @c ByteBuffer value
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either the length of the specified string for a section
	*                                       or an entry is less than or equal to @c 0,
	*                                       or a @c null value is passed. @n
	*										Note that, it is also possible that the data inside a registry instance is
	*										corrupted due to its usage in a multi-threaded environment without
	*										synchronization.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	* @remarks		This method will not add a name-value pair as an entry of a specific section
	*               if no entry with the specified name exists.
	*				In such a case, it returns E_KEY_NOT_FOUND. Use AddValue() to insert a new entry.
	* @see			AddValue()
	*/
	result SetValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName, const Tizen::Base::ByteBuffer& newValue);

	/**
	* Removes the name-value pair entry from specific section.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	sectionName				The section name
	* @param[in]	entryName				The entry name to remove
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The length of the specified string for a section or entry is less
	*                                       than or equal to @c 0.
	* @exception	E_SECTION_NOT_FOUND		The specified @c sectionName is not found within the registry.
	* @exception	E_KEY_NOT_FOUND			The specified @c entryName is not found within the registry.
	*/
	result RemoveValue(const Tizen::Base::String& sectionName, const Tizen::Base::String& entryName);

	/**
	* Removes the specified registry file.
	*
	* @if OSPCOMPAT
	* @brief <i> [Compatibility] </i>
	* @endif
	* @since		2.0
	* @if OSPCOMPAT
	* @compatibility	This method has compatibility issues with OSP compatible applications. @n
	*					For more information, see @ref CompIoPathPage "here".
	* @endif
	*
	* @return		An error code
	* @param[in]	regPath					The path of the registry file to remove
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*										- The length of the specified string of a file path is less
	* 										  than or equal to @c 0. @n
	*										- The translated overall length of the specified path exceeds the
	*										  system limitation. @n
	*										- The specified path is invalid. @n
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	*/
	static result Remove(const Tizen::Base::String& regPath);

	/**
	* Converts a normal registry file to a secure registry file. @n
	* A secure registry file that is converted by this method can be shared among applications with the same key value.
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
	* @return		An error code
	* @param[in]	plainRegPath			The normal (non-encrypted) registry file path
	* @param[in]	secureRegPath			The secure (encrypted) registry file path to create
	* @param[in]	key						A key that encrypts a secure registry file @n
	*										If the secure registry file is converted with a specific key value,
	*										applications can access the same secure registry file with the identical key value.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*										- The length of the specified string of a file path is less
	*										  than or equal to @c 0. @n
	*										- The translated overall length of the specified path exceeds the
	*										  system limitation. @n
	*										- The specified path is invalid. @n
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_FILE_NOT_FOUND		An entry for the specified file or path cannot be found.
	* @exception	E_INVALID_FORMAT		The input registry file contains '0x00' in the middle of the file.
	* @exception	E_PARSING_FAILED		The method has failed to parse the registry file.
	* @exception	E_STORAGE_FULL			The disk space is full.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected. @n
	*										- The number of opened files has exceeded the maximum limit.
	*/
	static result ConvertToSecureRegistry(const Tizen::Base::String& plainRegPath, const Tizen::Base::String& secureRegPath, const Tizen::Base::ByteBuffer& key);

private:
	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since 2.0
	*/
	Registry(const Registry& source);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since 2.0
	*/
	Registry& operator =(const Registry& source);

	class _RegistryImpl* __pRegistryImpl;

	friend class _RegistryImpl;

}; // Registry

}} // Tizen::Io

#endif //_FIO_REGISTRY_H_

