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
 * @file		FBaseUtilLinkInfo.h
 * @brief		This is the header file for the %LinkInfo class.
 *
 * This header file contains the declarations of the %LinkInfo class.
 */
#ifndef _FBASE_UTIL_LINK_INFO_H_
#define _FBASE_UTIL_LINK_INFO_H_

#include <FBaseColIList.h>
#include <FBaseString.h>
#include <FBaseUtilTypes.h>


namespace Tizen { namespace Base { namespace Utility
{

/**
* @class   LinkInfo
* @brief   This class provides methods for accessing the link, its type, and a string that represents the link.
*
* @since 2.0
*
* The %LinkInfo class provides information regarding a link. It contains methods
* for accessing the link, its type, and a string that represents the link.
*/
class _OSP_EXPORT_ LinkInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 *
	 * @remarks     The link and text are set to empty strings and the link type is set to @c LINK_TYPE_NONE.
	 */
	LinkInfo(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~LinkInfo(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in]   value  An instance of %LinkInfo
	 */
	LinkInfo(const LinkInfo& value);

	/**
	 * Initializes an instance of %LinkInfo with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @param[in]   linkType    The link type
	 * @param[in]   link        The link
	 * @remarks     The link's @c text is set to the same string as @c link.
	 * @see         Tizen::Base::Utility::LinkType
	 */
	LinkInfo(LinkType linkType, const Tizen::Base::String& link);

	/**
	 * Initializes an instance of %LinkInfo with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @param[in]   linkType    The link type
	 * @param[in]   link        The link
	 * @param[in]   text        A string that represents the link
	 * @see         Tizen::Base::Utility::LinkType
	 */
	LinkInfo(LinkType linkType, const Tizen::Base::String& link, const Tizen::Base::String& text);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since 2.0
	 *
	 * @return      A reference to the calling instance
	 * @param[in]   rhs     An instance of %LinkInfo
	 */
	LinkInfo& operator =(const LinkInfo& rhs);

	/**
	 * Gets the link.
	 *
	 * @since 2.0
	 *
	 * @return      The string that contains the link
	 * @see         SetLink()
	 */
	Tizen::Base::String GetLink(void) const;

	/**
	 * Sets the link.
	 *
	 * @since 2.0
	 *
	 * @param[in]   link    The string that contains the link
	 * @see         GetLink()
	 */
	void SetLink(const Tizen::Base::String& link);

	/**
	 * Gets the type of the link.
	 *
	 * @since 2.0
	 *
	 * @return      The link type
	 * @see         SetLinkType()
	 * @see         Tizen::Base::Utility::LinkType
	 */
	LinkType GetLinkType(void) const;

	/**
	 * Sets the type of the link.
	 *
	 * @since 2.0
	 *
	 * @param[in]   linkType    The link type
	 * @see         GetLinkType()
	 * @see         Tizen::Base::Utility::LinkType
	 */
	void SetLinkType(LinkType linkType);

	/**
	 * Gets the string that represents the link.
	 *
	 * @since 2.0
	 *
	 * @return      The string that represents the link
	 * @see         SetText()
	 */
	Tizen::Base::String GetText(void) const;

	/**
	 * Sets the string that represents the link.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   text            The string that represents the link
	 * @see         GetText()
	 */
	void SetText(const Tizen::Base::String& text);


private:
	LinkType __linkType;
	Tizen::Base::String __link;
	Tizen::Base::String __text;

	friend class _LinkInfoImpl;
	class _LinkInfoImpl* __pLinkInfoImpl;

}; // LinkInfo

}}} // Tizen::Base::Utility

#endif // _FBASE_UTIL_LINK_INFO_H_
