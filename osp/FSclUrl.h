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
* @file		FSclUrl.h
* @brief	This is the header file for the %Url class.
*
* This header file contains the declarations of the %Url class.
*/
#ifndef _FSCL_URL_H_
#define _FSCL_URL_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
 * @if OSPDEPREC
 * The maximum length of the URL property.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 * @endif
 */
static const int MAX_URL_LENGTH = 100;

/**
* @class	Url
* @brief	This class stores the information of a URL.
*
* @since	2.0
*
* @final	This class is not intended for extension.
*
* @remarks	The %Url class consists of a URL string and a URL type.
*
* The %Url class stores the information of a URL. @n
* The following example demonstrates how to use the %Url class.
*
* @code
using namespace Tizen::Base;
using namespace Tizen::Social;

void
MyClass::SomeMethod(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Url
	Url url = Url();

	// Sets the URL
	r = url.SetUrl(L"http://www.tizen.org");
	if (IsFailed(r))
	{
		return r;
	}

	// Sets the type
	url.SetType(URL_TYPE_WORK);

	return E_SUCCESS;
}
* @endcode
*/
class _OSP_EXPORT_ Url
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	Url(void);

	/**
	 * Initializes this instance with the specified URL string and type.
	 *
	 * @since	2.0
	 *
	 * @param[in]	type	The type of the URL
	 * @param[in]	url		The URL
	 */
	Url(UrlType type, const Tizen::Base::String& url);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Url
	 */
	Url(const Url& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Url(void);

	/**
	 * Checks whether the value of the specified instance is equal to the value of the current instance of Tizen::Base::Object.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the value of the specified instance of Tizen::Base::Object is equal to the value of the current instance of %Tizen::Base::Object, @n
	 *			else @c false
	 * @param[in]	rhs		An instance of Tizen::Base::Object to compare
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance of Tizen::Base::Object.
	 *
	 * @since	2.0
	 *
	 * @return	An integer value indicating the hash value of the current instance of Tizen::Base::Object
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the type of this %Url instance.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility            This method has compatibility issues with OSP compatible applications. @n
	 *                           For more information, see @ref CompUrlGetTypePage "here".
	 * @endif
	 *
	 * @return		The type of %Url
	 */
	UrlType GetType(void) const;

	/**
	 * @if OSPCOMPAT
	 * @page                CompUrlGetTypePage         Compatibility for GetType()
	 * @section             CompUrlGetTypePageIssueSection             Issues
	 * Implementing this method in OSP compatible applications has the following issue: @n
	 * -# URL_TYPE_CUSTOM is not supported. If the type of the url is URL_TYPE_CUSTOM, URL_TYPE_OTHER is returned instead.
	 *
	 * @section             CompUrlGetTypePageSolutionSection          Resolutions
	 * The issue mentioned above has been resolved in Tizen.
	 *
	 * @endif
	 */

	/**
	 * Gets the label of an URL.
	 *
	 * @since	2.0
	 *
	 * @return	The URL label
	 * @see SetLabel()
	 */
	Tizen::Base::String GetLabel(void) const;

	/**
	 * Sets the label of an URL. 
	 *
	 * @since	2.0
	 *
	 * @param[in]	label	The URL label
	 * @see GetLabel()
	 */
	void SetLabel(const Tizen::Base::String& label);

	/**
	 * Gets the URL of this %Url instance.
	 *
	 * @since	2.0
	 *
	 * @return		The URL as a string
	 */
	Tizen::Base::String GetUrl(void) const;

	/**
	 * Sets the type of this %Url instance.
	 *
	 * @since	2.0
	 *
	 * @param[in]	type	The type of %Url
	 */
	void SetType(UrlType type);

	/**
	 * Sets the URL of this %Url instance.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility            This method has compatibility issues with OSP compatible applications. @n
	 *                           For more information, see @ref CompUrlSetUrlPage "here".
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	url				The URL
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c url is an empty string.
	 */
	result SetUrl(const Tizen::Base::String& url);

	/**
	 * @if OSPCOMPAT
	 * @page		CompUrlSetUrlPage		Compatibility for SetUrl()
	 * @section		CompUrlSetUrlPageIssueSection		Issues
	 * Implementing this method in OSP compatible applications has the following issue: @n
	 * -# If the length of an URL to be set is greater than 100 characters, E_INVALID_ARG is returned.
	 *
	 * @section		CompUrlSetUrlPageSolutionSection		Resolutions
	 * The issue mentioned above has been resolved in Tizen.
	 * @endif
	 */
	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs	An instance of %Url
	 */
	Url& operator =(const Url& rhs);

	/**
	 * Checks whether the specified instance is equal to the calling instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data of the specified instance is equal to the data of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		 The source instance of %Url
	 */
	bool operator ==(const Url& rhs) const;

	/**
	 * Compares the specified instance with the calling instance for inequality.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data of the specified instance is not equal to the data of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		The source instance of %Url
	 */
	bool operator !=(const Url& rhs) const;

private:
	friend class _UrlImpl;
	class _UrlImpl* __pUrlImpl;
}; // Url

}} // Tizen::Social

#endif // _FSCL_URL_H_
