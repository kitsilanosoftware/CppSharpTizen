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
 * @file		FCntContentSearch.h
 * @brief		This is the header file for the %ContentSearch class.
 *
 * This header file contains the declarations of the %ContentSearch class.
 */

#ifndef _FCNT_CONTENT_SEARCH_H_
#define _FCNT_CONTENT_SEARCH_H_

#include <FBaseString.h>
#include <FCntTypes.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}

namespace Tizen { namespace Content
{

class _ContentSearchImpl;

/**
 * @class	ContentSearch
 * @brief	This class provides methods for the content search.
 *
 * @since	2.0
 *
 * The %ContentSearch class provides methods to search content based on conditions and to retrieve the results for a specific
 * column. It enables searching for content stored on the %Tizen device. The local content is stored in the form of database columns.
 *
 * For more information on the database columns and their corresponding content types, see <a href="../org.tizen.native.appprogramming/html/guide/content/content_search_device.htm">Content Search on the Device</a>.
 *
 * The following example demonstrates how to use the %ContentSearch class.
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
 *	// Call Construct() of ContentSearch
 *	ContentSearch search;
 *	result r = search.Construct(CONTENT_TYPE_AUDIO);
 *	if (IsFailed(r))
 *	{
 *		// Do something for an error
 *	}
 *
 *	// Call SearchN() of ContentSearch as the first page
 *	int pageNo = 1;
 *	int countPerPage = 5;
 *	int totalPage = 0;
 *	int totalCount = 0;
 *	IList* pContentInfoList = search.SearchN(pageNo, countPerPage, totalPage, totalCount,
 *				L"Artist='rain'", L"Title", SORT_ORDER_ASCENDING);
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
class _OSP_EXPORT_ ContentSearch
	: virtual public Tizen::Base::Object
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	ContentSearch(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~ContentSearch(void);

	/**
	 * Initializes this instance of %ContentSearch with the specified parameter.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	type			The content type
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 * @remarks     To search a specific type, use the content type as @c CONTENT_TYPE_OTHER, @c CONTENT_TYPE_IMAGE, @c CONTENT_TYPE_AUDIO, or @c CONTENT_TYPE_VIDEO.
	 *
	 * The following example demonstrates how to use the %Construct() method.
	 *
	 * @code
	 *
	 *	// Call Construct() of ContentSearch
	 *	ContentSearch search;
	 *	result r = search.Construct(CONTENT_TYPE_IMAGE);
	 *	if (IsFailed(r))
	 *	{
	 *		// Do something for an error
	 *	}
	 *
	 * @endcode
	 */
	result Construct(ContentType type);

	/**
	 * Searches the content and returns the search result list according to the query.
	 *
	 * @since		2.0
	 * @privlevel		public
	 * @privilege   %http://tizen.org/privilege/content.read
	 *
	 * @return		A pointer to a list containing the ContentSearchResult instances @n
	 *				An empty list is returned if there is no result and there is no error, @n
	 *				else @c null if an exception occurs.
	 * @param[in]	pageNo			The page number @n
	 *								It must be equal to or greater than @c 1.
	 * @param[in]	countPerPage	The count of the search results per page  @n
	 *								It must be equal to or greater than @c 1.
	 * @param[out]	totalPageCount	The total page count of the search result
	 * @param[out]	totalCount		The total count of the search result
	 * @param[in]	whereExpr		The search condition like an sql "where" expression style @n
	 *								If it uses the default value, L"", it searches for all the content of the content type set in the constructor. @n
	 *								In case of the "DateTime" condition, the range starts from '01/01/1970 00:00:00'. @n
	 *								Every type of value has to be covered with single quotation marks, even if it is a decimal type.
	 * @param[in]	sortColumn		The sort <a href="../org.tizen.native.appprogramming/html/guide/content/content_search_device.htm">column</a> @n
	 *								The default value is @c L"".
	 * @param[in]	sortOrder		The sort order
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_ARG	Either of the following conditions has occurred: @n
	 *	                                - The specified @c column is either invalid or empty. @n
	 *	                                - The content is searched with @c type set as ::CONTENT_TYPE_UNKNOWN. @n
	 *	                                - The length of the specified @c whereExpr parameter exceeds 512 characters.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 * 				- The specific error code can be accessed using the GetLastResult() method.
	 * 				- The return value must be deleted.
	 *				- ContentType supports ::CONTENT_TYPE_OTHER, ::CONTENT_TYPE_IMAGE, ::CONTENT_TYPE_AUDIO, and ::CONTENT_TYPE_VIDEO. @n
	 *					If %ContentType in Construct() uses ::CONTENT_TYPE_UNKNOWN or an invalid value, @c E_INVALID_ARG occurs.
	 *
	 * The following example demonstrates how to use the %SearchN() method.
	 *
	 * @code
	 *
	 *	// Call Construct() of ContentSearch
	 *	ContentSearch search;
	 *	result r = search.Construct(CONTENT_TYPE_AUDIO);
	 *	if (IsFailed(r))
	 *	{
	 *		// Do something for an error
	 *	}
	 *
	 *	// Call SearchN() of ContentSearch as the first page
	 *	int pageNo = 1;
	 *	int countPerPage = 5;
	 *	int totalPage = 0;
	 *	int totalCount = 0;
	 *	IList* pContentInfoList = search.SearchN(pageNo, countPerPage, totalPage, totalCount,
	 *				L"Artist='rain'", L"Title", SORT_ORDER_ASCENDING);
	 *	if (IsFailed(GetLastResult()))
	 *	{
	 *		// Do something for an error
	 *	}
	 *
	 *	// Do something
	 *
	 *	// Delete resource
	 *	pContentInfoList->RemoveAll(true);
	 *	delete pContentInfoList;
	 *
	 * @endcode
	 */
	Tizen::Base::Collection::IList* SearchN(int pageNo, int countPerPage, int& totalPageCount, int& totalCount, const Tizen::Base::String& whereExpr = L"", const Tizen::Base::String& sortColumn = L"", Tizen::Base::SortOrder sortOrder = Tizen::Base::SORT_ORDER_NONE) const;

	/**
	 * Gets the value list of the specified column within a specified range.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/content.read
	 *
	 * @return		A pointer to a list containing the values of a column @n
	 *				The type of value can be Tizen::Base::Float, Tizen::Base::Double, Tizen::Base::LongLong, Tizen::Base::DateTime, or Tizen::Base::String. @n
	 *				An empty list is returned if the specified column has no value and there is no error, @n
	 *              else @c null if an exception occurs.
	 * @param[in]	pageNo			The page number @n
	 *								It must be equal to or greater than @c 1.
	 * @param[in]	countPerPage	The count of the value list per page  @n
	 *								It must be equal to or greater than @c 1.
	 * @param[out]	totalPageCount	The total page count of the value list
	 * @param[out]	totalCount		The total count of the value list
	 * @param[in]	column			The <a href="../org.tizen.native.appprogramming/html/guide/content/content_search_device.htm">column</a> name
	 * @param[in]	sortOrder		The sort order
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_ARG	The specified @c column is either invalid or empty, or
	 *								the content is searched with @c type set as ::CONTENT_TYPE_UNKNOWN.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks
	 * 				- The specific error code can be accessed using the GetLastResult() method.
	 * 				- The return value must be deleted. @n
	 *					The result of GetValueListN() returns a distinct value.
	 *				- ContentType supports ::CONTENT_TYPE_OTHER, ::CONTENT_TYPE_IMAGE, ::CONTENT_TYPE_AUDIO, and ::CONTENT_TYPE_VIDEO. @n
	 *					If %ContentType in Construct() uses ::CONTENT_TYPE_UNKNOWN or an invalid value, @c E_INVALID_ARG occurs.
	 *
	 * The following example demonstrates how to use the %GetValueListN() method.
	 *
	 * @code
	 *
	 *	// Call Construct() of ContentSearch
	 *	ContentSearch search;
	 *	result r = search.Construct(CONTENT_TYPE_AUDIO);
	 *	if (IsFailed(r))
	 *	{
	 *		// Do something for an error
	 *	}
	 *
	 *	// Call GetValueListN() of ContentSearch
	 *	int pageNo = 1;
	 *	int countPerPage = 10;
	 *	int totalPage = 0;
	 *	int totalCount = 0;
	 *	IList* pValueList = search.GetValueListN(pageNo, countPerPage, totalPage, totalCount, L"Genre", SORT_ORDER_NONE);
	 *
	 *	if (IsFailed(GetLastResult()))
	 *	{
	 *		// Do something for an error
	 *	}
	 *
	 *	// Do something
	 *
	 *	// Delete resource
	 *	pValueList->RemoveAll(true);
	 *	delete pValueList;
	 *
	 * @endcode
	 */
	Tizen::Base::Collection::IList* GetValueListN(int pageNo, int countPerPage, int& totalPageCount, int& totalCount, const Tizen::Base::String& column, Tizen::Base::SortOrder sortOrder = Tizen::Base::SORT_ORDER_NONE) const;

	/**
	 * @if OSPDEPREC
	* Gets the list consisting of values of a specified column in the specified order.
	*
	* @brief	<i> [Deprecated] </i>
	* @deprecated	This method is deprecated. Instead of using this method, it is recommended to use the GetValueListN(int, int, int&, int&, const Tizen::Base::String&, @n
	*				Tizen::Base::SortOrder) method, that gets the value list of the specified column.
	* @since		2.0
	* @privlevel	public
	* @privilege	%http://tizen.org/privilege/content.read
	*
	* @return		A pointer to a list containing the values of a column @n
	*				The type of value can be Tizen::Base::Integer, Tizen::Base::Double, Tizen::Base::LongLong, Tizen::Base::DateTime, or Tizen::Base::String. @n
	*				An empty list is returned if the specified column has no value and there is no error, @n
	*               else @c null if an exception occurs.
	* @param[in]	column			The <a href="../org.tizen.native.appprogramming/html/guide/content/content_search_device.htm">column</a> name
	* @param[in]	sortOrder		The sort order
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	* @exception	E_INVALID_ARG	The specified @c column is either invalid or empty, or the content is searched with @c type set as CONTENT_TYPE_UNKNOWN.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_SYSTEM		A system error has occurred.
	* @remarks
	* 				- The specific error code can be accessed using the GetLastResult() method.
	* 				- The return value must be deleted. @n
	*					The result of GetValueListN() returns a distinct value.
	*				- ContentType supports ::CONTENT_TYPE_OTHER, ::CONTENT_TYPE_IMAGE, ::CONTENT_TYPE_AUDIO, and ::CONTENT_TYPE_VIDEO. @n
	*					If %ContentType in Construct() uses ::CONTENT_TYPE_UNKNOWN or an invalid value, @c E_INVALID_ARG occurs.
	*
	* The following example demonstrates how to use the %GetValueListN() method.
	*
	* @code
	*
	*	// Call Construct() of ContentSearch
	*	ContentSearch search;
	*	result r = search.Construct(CONTENT_TYPE_AUDIO);
	*	if (IsFailed(r))
	*	{
	*		// Do something for an error
	*	}
	*
	*	// Call GetValueListN() of ContentSearch
	*	IList* pValueList = search.GetValueListN(L"Artist", SORT_ORDER_NONE);
	*
	*	if (IsFailed(GetLastResult()))
	*	{
	*		// Do something for an error
	*	}
	*
	*	// Do something
	*
	*	// Delete resource
	*	pValueList->RemoveAll(true);
	*	delete pValueList;
	*
	* @endcode
	* @endif
	*/
	Tizen::Base::Collection::IList* GetValueListN(const Tizen::Base::String& column, Tizen::Base::SortOrder sortOrder = Tizen::Base::SORT_ORDER_NONE);
private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentSearch(const ContentSearch& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentSearch& operator =(const ContentSearch& rhs);

	_ContentSearchImpl* __pImpl;

	friend class _ContentSearchImpl;
};  // class ContentSearch

}}  // Tizen::Content

#endif  // _FCNT_CONTENT_SEARCH_H_
