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
* @file		FSclImAddress.h
* @brief	This is the header file for the %ImAddress class.
*
* This header file contains the declarations of the %ImAddress class.
*/
#ifndef _FSCL_IM_ADDRESS_H_
#define _FSCL_IM_ADDRESS_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseString.h>

namespace Tizen { namespace Social
{
/**
 * @if OSPDEPREC
 * The maximum length of the IM address property.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated	This constant is deprecated because there is no limitation any more.
 * @since	2.0
 @ endif
 */
static const int MAX_IM_ADDRESS_LENGTH = 100;

/**
 * @if OSPDEPREC
 * The IM service provider name for MSN.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated 	This object is provided only for backward compatibility and will be deleted in the near future.
 *				Use IM_ADDRESS_MSN instead of this object.
 * @since	2.0
 @ endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String IM_MSN;

/**
 * @if OSPDEPREC
 * The IM service provider name for ICQ.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated 	This object is provided only for backward compatibility and will be deleted in the near future.
 *				Use IM_ADDRESS_ICQ instead of this object.
 * @since	2.0
 @ endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String IM_ICQ;

/**
 * @if OSPDEPREC
 * The IM service provider name for AIM.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated 	This object is provided only for backward compatibility and will be deleted in the near future.
 *				Use IM_ADDRESS_AIM instead of this object.
 * @since	2.0
 @ endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String IM_AIM;

/**
 * @if OSPDEPREC
 * The IM service provider name for Yahoo.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated 	This object is provided only for backward compatibility and will be deleted in the near future.
 *				Use IM_ADDRESS_YAHOO instead of this object.
 * @since	2.0
 @ endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String IM_YAHOO;

/**
 * @if OSPDEPREC
 * The IM service provider name for Jabber.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated 	This object is provided only for backward compatibility and will be deleted in the near future.
 *				Use IM_ADDRESS_JABBER instead of this object.
 * @since	2.0
 @ endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String IM_JABBER;

/**
 * @if OSPDEPREC
 * The IM service provider name for Google talk.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated 	This object is provided only for backward compatibility and will be deleted in the near future.
 *				Use IM_ADDRESS_GTALK instead of this object.
 * @since	2.0
 @ endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String IM_GTALK;

/**
 * @if OSPDEPREC
 * The IM service provider name for Skype.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated 	This object is provided only for backward compatibility and will be deleted in the near future.
 *				Use IM_ADDRESS_SKYPE instead of this object.
 * @since	2.0
 @ endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String IM_SKYPE;

/**
 * @if OSPDEPREC
 * The IM service provider name for QQ.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated 	This object is provided only for backward compatibility and will be deleted in the near future.
 *				Use IM_ADDRESS_QQ instead of this object.
 * @since	2.0
 @ endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String IM_QQ;

/**
 * The IM service provider name for AIM.
 *
 * @since	2.0
 */
_OSP_EXPORT_ extern const wchar_t IM_ADDRESS_AIM[];

/**
 * The IM service provider name for Google talk.
 *
 * @since	2.0
 */
_OSP_EXPORT_ extern const wchar_t IM_ADDRESS_GOOGLE_TALK[];

/**
 * The IM service provider name for ICQ.
 *
 * @since	2.0
 */
_OSP_EXPORT_ extern const wchar_t IM_ADDRESS_ICQ[];

/**
 * The IM service provider name for Jabber.
 *
 * @since	2.0
 */
_OSP_EXPORT_ extern const wchar_t IM_ADDRESS_JABBER[];

/**
 * The IM service provider name for MSN.
 *
 * @since	2.0
*/
_OSP_EXPORT_ extern const wchar_t IM_ADDRESS_MSN[];

/**
 * The IM service provider name for QQ.
 *
 * @since	2.0
 */
_OSP_EXPORT_ extern const wchar_t IM_ADDRESS_QQ[];

/**
 * The IM service provider name for Skype.
 *
 * @since	2.0
 */
_OSP_EXPORT_ extern const wchar_t IM_ADDRESS_SKYPE[];

/**
 * The IM service provider name for Yahoo.
 *
 * @since	2.0
 */
_OSP_EXPORT_ extern const wchar_t IM_ADDRESS_YAHOO[];

/**
 * @class	ImAddress
 * @brief	This class represents the Instant Messenger (IM) addresses.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %ImAddress class represents the Instant Messenger (IM) addresses. It consists of an IM service provider name and an account.
 */
class _OSP_EXPORT_ ImAddress
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	ImAddress(void);

	/**
	 * Initializes this instance of %ImAddress with the specified parameters. @n
	 * This constructs an instance of %ImAddress with the specified service provider name.
	 *
	 * @since	2.0
	 *
	 * @param[in]	serviceProviderName		The service provider name of the %ImAddress
	 * @param[in]	imAddress				The IM address
	 * @see			#IM_ADDRESS_AIM
	 * @see			#IM_ADDRESS_GOOGLE_TALK
	 * @see			#IM_ADDRESS_ICQ
	 * @see			#IM_ADDRESS_JABBER
	 * @see			#IM_ADDRESS_MSN
	 * @see			#IM_ADDRESS_QQ
	 * @see			#IM_ADDRESS_SKYPE
	 * @see			#IM_ADDRESS_YAHOO
	 */
	ImAddress(const Tizen::Base::String& serviceProviderName, const Tizen::Base::String& imAddress);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs	An instance of %ImAddress
	 */
	ImAddress(const ImAddress& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~ImAddress(void);

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
	 * Gets the service provider name of the IM address.
	 *
	 * @since	2.0
	 *
	 * @return		The service provider name of the IM address
	 */
	Tizen::Base::String GetServiceProviderName(void) const;

	/**
	 * Gets the IM address of the current instance of %ImAddress.
	 *
	 * @since	2.0
	 *
	 * @return		The IM address
	 */
	Tizen::Base::String GetImAddress(void) const;

	/**
	 * Sets the service provider name of the IM address.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	serviceProviderName		The service provider name of the IM address
	 * @see			#IM_ADDRESS_AIM
	 * @see			#IM_ADDRESS_GOOGLE_TALK
	 * @see			#IM_ADDRESS_ICQ
	 * @see			#IM_ADDRESS_JABBER
	 * @see			#IM_ADDRESS_MSN
	 * @see			#IM_ADDRESS_QQ
	 * @see			#IM_ADDRESS_SKYPE
	 * @see			#IM_ADDRESS_YAHOO
	 */
	void SetServiceProviderName(const Tizen::Base::String& serviceProviderName);

	/**
	 * Sets the IM address of the current instance of %ImAddress.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility            This method has compatibility issues with OSP compatible applications. @n
	 *				For more information, see @ref CompImAddressSetImAddressPage "here".
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	imAddress			The IM address
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c imAddress is an empty string.
	 */
	result SetImAddress(const Tizen::Base::String& imAddress);

	/**
	 * @if OSPCOMPAT
	 * @page		CompImAddressSetImAddressPage		Compatibility for SetImAddress()
	 * @section		CompImAddressSetImAddressPageIssueSection		Issues
	 * Implementing this method in OSP compatible applications has the following issue: @n
	 * -# If the length of an IM address to be set is greater than 100 characters, E_INVALID_ARG is returned.
	 *
	 * @section		CompImAddressSetImAddressPageSolutionSection		Resolutions
	 * The issue mentioned above has been resolved in Tizen.
	 * @endif
	 */

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs	An instance of %ImAddress
	 */
	ImAddress& operator =(const ImAddress& rhs);

	/**
	 * Checks whether the value of the specified instance of %ImAddress is equal to the value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the specified instance of %ImAddress is equal to the value of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %ImAddress
	 */
	bool operator ==(const ImAddress& rhs) const;

	/**
	 * Checks whether the value of the specified instance of %ImAddress does not match the value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the specified instance of %ImAddress is not equal to the value of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %ImAddress
	 */
	bool operator !=(const ImAddress& rhs) const;

private:
	friend class _ImAddressImpl;
	class _ImAddressImpl* __pImAddressImpl;

}; // ImAddress

}} // Tizen::Social

#endif // _FSCL_IM_ADDRESS_H_
