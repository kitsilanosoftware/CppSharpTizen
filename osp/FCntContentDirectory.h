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
 * @file		FCntContentDirectory.h
 * @brief		This is the header file for the %ContentDirectory class.
 *
 * This header file contains the declarations of the %ContentDirectory class.
 */

#ifndef _FCNT_CONTENT_DIRECTORY_H_
#define _FCNT_CONTENT_DIRECTORY_H_

#include <FBaseString.h>
#include <FBaseColIListT.h>
#include <FCntTypes.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}

namespace Tizen { namespace Content
{
	static const int MAX_CONTENTTYPE_LIST_COUNT = 5;
	static const int MIN_CONTENTTYPE_LIST_COUNT = 0;
	static const int CONTENTTYPE_LIST_COUNT_ONE = 1;

class _ContentDirectoryImpl;
/**
 * @class	ContentDirectory
 * @brief	This class provides methods for the content directory.
 * @since	2.0
 *
 * @final       This class is not intended for extension.
 *
 * The %ContentDirectory class provides methods to access a list of content directories 
 * and information of the content (specified content type) in the content directories.
 *
 * For more information on the database columns and their corresponding content types, 
 * see <a href="../org.tizen.native.appprogramming/html/guide/content/content_search_device.htm">Content Search on the Device</a>.
 *
 * The following example demonstrates how to use the %ContentDirectory class.
 *
 * @code
 * #include <FContent.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Base::Collection;
 * using namespace Tizen::Content;
 *
 * void
 * MyClass::Test(void)
 * {
 *	// Call Construct() of ContentDirectory
 *	ContentDirectory directory;
 *	const Tizen::Base::String contentDirectoryPath = L"";
 *	result r = directory.Construct(CONTENT_TYPE_AUDIO);
 *	if (IsFailed(r))
 *	{
 *		// Do something for an error
 *	}
 *
 *	// Call GetContentDirectoryItemListN() of ContentDirectory as the first page
 *	int pageNo = 1;
 *	int countPerPage = 5;
 *	int totalPage = 0;
 *	int totalCount = 0;
 *	IList* pContentInfoList = directory.GetContentDirectoryItemListN(contentDirectoryPath, pageNo, countPerPage, L"Title", SORT_ORDER_ASCENDING);
 *				 
 *	if (IsFailed(GetLastResult()))
 *	{
 *		// Do something for an error
 *	}
 *
 *	// Delete resource
 *	pContentInfoList->RemoveAll(true);
 *	delete pContentInfoList;
 * }
 *
 * @endcode
 *
 */

class _OSP_EXPORT_ ContentDirectory
	: public Tizen::Base::Object
{

public:

	/**
 	 * The object is not fully constructed after this constructor is called. @n
 	 * For full construction, the Construct() method must be called right after calling this constructor.
 	 *
 	 * @since 2.0
 	 */
	ContentDirectory(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~ContentDirectory(void);

	/**
	 * Initializes this instance of %ContentDirectory with the specified parameter.
	 *
	 * @since 2.0
	 *
	 * @return    An error code
	 * @param     contentType		The content type
	 * @exception E_SUCCESS                 The method is successful.
	 * @exception E_INVALID_ARG             The specified input parameter is invalid.
	 * @exception E_OUT_OF_MEMORY           The memory is insufficient.
	 * @exception E_SYSTEM                  The method cannot connect to the database.
	 * @remarks   This method is used to access only one type of content. @n
	 *            If you want to access more than one type of content, use Construct(const Tizen::Base::Collection::IListT<ContentType>&).
	 *				The allowed types are CONTENT_TYPE_OTHER, CONTENT_TYPE_IMAGE, CONTENT_TYPE_AUDIO, and CONTENT_TYPE_VIDEO.
	 */
	result Construct(ContentType contentType);

	/**
	 * Initializes this instance of %ContentDirectory with the specified parameter.
	 *
	 * @since 2.0
	 *
	 * @return    An error code
	 * @param     contentTypeList		The list of content types
	 * @exception E_SUCCESS                 The method is successful.
	 * @exception E_INVALID_ARG             The specified input parameter is invalid.
	 * @exception E_OUT_OF_MEMORY           The memory is insufficient.
	 * @exception E_SYSTEM                  The method cannot connect to the database.
	 * @remarks   This method is used to access more than one type of content. @n
	 *            If you want to access only one type of content, use Construct(ContentType). @n
	 *            Total count of @c contentTypeList should not be greater than @c 4. @n
	 *	      		Any combination with CONTENT_TYPE_ALL is a invalid argument. @n
	 *				The allowed types are CONTENT_TYPE_OTHER, CONTENT_TYPE_IMAGE, CONTENT_TYPE_AUDIO, and CONTENT_TYPE_VIDEO.
	 */
	result Construct(const Tizen::Base::Collection::IListT<ContentType>& contentTypeList);

	/**
	 * Gets the count of content directories that contains the content type that is passed as a parameter in Construct().
	 *
	 * @since 2.0
	 *
	 * @return    The count of content directories
	 * @exception E_SUCCESS			The method is successful.
	 * @exception E_OUT_OF_MEMORY           The memory is insufficient.
	 * @exception E_SERVICE_BUSY            The database is busy.
	 * @exception E_SYSTEM                  The method cannot access the database.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetContentDirectoryCount(void) const;

	/**
	 * Gets the list of content directory path that contains the content type that is passed as a parameter in Construct().
	 *
	 * @since 2.0
	 *
	 * @return    A list of Tizen::Base::String values that contains content directory path
	 * @param     sortOrder			The sort order
	 * @exception E_SUCCESS                 The method is successful.
	 * @exception E_INVALID_ARG             The specified input parameter is invalid.
	 * @exception E_OUT_OF_MEMORY           The memory is insufficient.
	 * @exception E_SERVICE_BUSY            The database is busy.
	 * @exception E_SYSTEM                  The method cannot access the database.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetContentDirectoryPathListN(Tizen::Base::SortOrder sortOrder) const;

	
	/**
	 * Gets the count of files in a directory.
	 *
	 * @since 2.0
	 *
	 * @return    The count of files
	 * @param     contentDirectoryPath		The content directory path @n
	 * 											The allowed directory path can be obtained by using
	 * 											Tizen::System::Environment::GetMediaPath() and Tizen::System::Environment::GetExternalStoragePath().
	 * @exception E_SUCCESS                 The method is successful.
	 * @exception E_INVALID_ARG             The specified input parameter is invalid.
	 * @exception E_OUT_OF_MEMORY           The memory is insufficient.
	 * @exception E_SERVICE_BUSY            The database is busy.
	 * @exception E_SYSTEM                  The method cannot access the database.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 * @see GetContentDirectoryPathListN()
	 */
	int GetContentDirectoryItemCount(const Tizen::Base::String& contentDirectoryPath) const;

	/**
	 * Gets the list of content information in a directory.
	 *
	 * @since 2.0
	 *
	 * @return     A list of ContentInfo classes that contains content information 
	 * @param     contentDirectoryPath			The content directory path @n
	 *								 				The allowed directory path can be obtained by using
	 *								 				Tizen::System::Environment::GetMediaPath() and Tizen::System::Environment::GetExternalStoragePath().
	 * @param     pageNo							The page number @n
	 *												It must be equal to or greater than @c 1.
	 * @param     countPerPage					The count of the search results per page @n
	 *												It must be equal to or greater than @c 1.
	 * @param     column							The sort column name
	 * @param     sortOrder						The sort order
	 * @exception E_SUCCESS						The method is successful.
	 * @exception E_INVALID_ARG					A specified input parameter is invalid.
	 * @exception E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception E_SERVICE_BUSY				The database is busy.
	 * @exception E_SYSTEM						The method cannot access the database.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 * @see GetContentDirectoryPathListN()
	 */
	Tizen::Base::Collection::IList* GetContentDirectoryItemListN(const Tizen::Base::String& contentDirectoryPath, int pageNo, int countPerPage,
		                                    				const Tizen::Base::String& column, Tizen::Base::SortOrder sortOrder) const;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentDirectory(const ContentDirectory& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentDirectory& operator =(const ContentDirectory& rhs);

	_ContentDirectoryImpl* __pImpl;

	friend class _ContentDirectoryImpl;

};  // class ContentDirectory

}}  // Tizen::Content

#endif  // _FCNT_CONTENT_DIRECTORY_H_
