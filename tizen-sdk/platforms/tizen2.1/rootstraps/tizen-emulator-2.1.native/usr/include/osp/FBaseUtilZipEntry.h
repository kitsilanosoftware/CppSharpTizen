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
 * @file		FBaseUtilZipEntry.h
 * @brief		This is the header file for the %ZipEntry class.
 *
 * This header file contains the declarations of the %ZipEntry class.
 */

#ifndef _FBASE_UTIL_ZIP_ENTRY_H_
#define _FBASE_UTIL_ZIP_ENTRY_H_

#include <FBaseString.h>
#include <FBaseDateTime.h>
#include <FBaseUtilTypes.h>



namespace Tizen { namespace Base { namespace Utility
{
/**
 * @class	ZipEntry
 * @brief		This class provides access to the entries of a zip-archive.
 *
 * @since 2.0
 *
 * The %ZipEntry class is used for accessing the elements of a zip-archive. Each instance of
 * %ZipEntry represents a single entry in the zip-archive.
 * It also stores the information related to that entry, such as name, compressed size,
 * uncompressed size, compression level, and archive name.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/utility_namespace.htm">Utility</a>.
 *
 * The following example demonstrates how to use the %ZipEntry class.
 *
 * @code
 *	#include <FBase.h>
 *
 *	using namespace Tizen::App;
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Utility;
 *
 *	void
 *	MyClass::FileZipSample(void)
 *	{
 *		String str;
 *		int i = 0, count = 0;
 *		unsigned long size = 0;
 *		ZipEntry entry;
 *
 *		FileUnzip unzip;
 *		String dataPath = App::GetInstance()->GetAppDataPath();
 *		unzip.Construct(dataPath + L"sample.zip");
 *
 *		count = unzip.GetEntryCount();
 *
 *		for (i = 0; i < count; i++)
 *		{
 *			// Gets a ZipEntry from the zip-archive
 *			unzip.GetEntry(i, entry);
 *
 *			// Gets an entry name associated with the ZipEntry
 *			str = entry.GetName();
 *
 *			// Gets the name of the zip file which ZipEntry belongs to
 *			str = entry.GetArchiveName();
 *
 *			// Gets the compressed size of ZipEntry
 *			size = entry.GetCompressedSize();
 *		}
 *
 *	}
 * @endcode
 */
class _OSP_EXPORT_ ZipEntry
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	ZipEntry(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~ZipEntry(void);

	/**
	 * Gets an entry name associated with a zip entry. @n
	 * It can be a file or directory name.
	 *
	 * @since 2.0
	 *
	 * @return		An entry name
	 *
	 */
	String GetName(void) const;

	/**
	 * Gets the compression level associated with a zip entry.
	 *
	 * @since 2.0
	 *
	 * @return		The compression level associated with a zip entry
	 *
	 */
	CompressionLevel GetCompressionLevel(void) const;

	/**
	 * Checks whether a zip entry is a file or directory.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the entry is a directory, @n
	 *				else @c false
	 */
	bool IsDirectory(void) const;

	/**
	 * Gets the compressed size of a zip entry.
	 *
	 * @since 2.0
	 *
	 * @return		The compressed size of a zip entry
	 */
	unsigned long GetCompressedSize(void) const;

	/**
	 * Gets the uncompressed size of a zip entry.
	 *
	 * @since 2.0
	 *
	 * @return		The uncompressed size of a zip entry
	 */
	unsigned long GetUncompressedSize(void) const;

	/**
	 * Gets the name of a zip file to which %ZipEntry belongs.
	 *
	 * @since 2.0
	 *
	 * @return		The name of a zip file
	 * @remarks 	This method returns the name of a zip file that is opened
	 * in the FileUnzipper::Construct() method.
	 */
	String GetArchiveName(void) const;

	/**
	 * Compares the specified instance to the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the specified instance equals the current instance, @n
	 *				else @c false
	 * @param[in]	obj	The object to compare with the current instance
	 * @remarks 	This method returns @c true if all the attributes in the instance are same.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;


private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since 2.0
	 *
	 * @param[in]	entry  The instance of the %ZipEntry class to copy from
	 * @remarks		This constructor is hidden.
	 */
	ZipEntry(const ZipEntry& entry);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since 2.0
	 *
	 * @param[in]	entry   An instance of %ZipEntry
	 * @remarks		This operator is hidden.
	 */
	ZipEntry& operator =(const ZipEntry& entry);

	void Set(void* unzFile);


	String __name;
	void* __unzFile;
	CompressionLevel __compressionLevel;

	friend class _FileUnzipperImpl;

	friend class _ZipEntryImpl;
	class _ZipEntryImpl* __pZipEntryImpl;

}; // ZipEntry

}}} // Tizen::Base::Utility

#endif // _FBASE_UTIL_ZIP_ENTRY_H_
