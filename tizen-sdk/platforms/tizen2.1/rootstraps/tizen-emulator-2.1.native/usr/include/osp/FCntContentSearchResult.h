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
 * @file		FCntContentSearchResult.h
 * @brief		This is the header file for the %ContentSearchResult class.
 *
 * This header file contains the declarations of the %ContentSearchResult class.
 */

#ifndef _FCNT_CONTENT_SEARCH_RESULT_H_
#define _FCNT_CONTENT_SEARCH_RESULT_H_

#include <FBaseObject.h>
#include <FCntTypes.h>

namespace Tizen { namespace Content
{

class _ContentSearchResultImpl;
class ContentInfo;

/**
 * @class	ContentSearchResult
 * @brief	This class represents the content search result.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %ContentSearchResult class gets a pointer to the ContentInfo class and retrieves the content type.
 *
 * The search result list comprises of this class, and each node can have a different type of %ContentInfo (ImageContentInfo, AudioContentInfo, VideoContentInfo, or OtherContentInfo).
 * You must cast the %ContentInfo class into the appropriate content type to use the %ContentSearchResult class.
 */
class _OSP_EXPORT_ ContentSearchResult
	: public Tizen::Base::Object
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	ContentSearchResult(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~ContentSearchResult(void);

	/**
	 * Gets the content type of the ContentInfo class.
	 *
	 * @since		2.0
	 *
	 * @return		The content type
	 */
	ContentType GetContentType(void) const;

	/**
	 * Gets the content information of the ContentInfo class.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the ContentInfo class
	 */
	ContentInfo* GetContentInfo(void) const;

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentSearchResult(const ContentSearchResult& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentSearchResult& operator =(const ContentSearchResult& rhs);

	void SetContentType(ContentType contentType);
	void SetContentInfo(ContentInfo* pContentInfo);

private:
	ContentType __contentType;
	ContentInfo* __pContentInfo;

	_ContentSearchResultImpl* __pImpl; // pubonly - for ABC
	friend class _ContentSearchResultImpl;
	friend class _ContentSearchImpl;
	friend class _ContentDirectoryImpl;

};  // class ContentSearchResult

}} // Tizen::Content

#endif // _FCNT_CONTENT_SEARCH_RESULT_H_
