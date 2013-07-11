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
* @file		FSclEmail.h
* @brief	This is the header file for the %Email class.
*
* This header file contains the declarations of the %Email class.
*/
#ifndef _FSCL_EMAIL_H_
#define _FSCL_EMAIL_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
* @class	Email
* @brief	This class represents an email.
*
* @since	2.0
*
* @final	This class is not intended for extension.
*
* The %Email class represents an email.
* An email consists of the email address and email type.
*
* The following example demonstrates how to use the %Email class.
*
* @code
using namespace Tizen::Base;
using namespace Tizen::Social;

void
MyClass::SomeMethod(void)
{
	result r = E_SUCCESS;

	// Creates an instance of %Email
	Email email = Email();

	// Sets the email address
	r = email.SetEmail(L"hello@Tizen.com");
	if (IsFailed(r))
	{
		return r;
	}

	// Sets the email type
	email.SetType(EMAIL_TYPE_PERSONAL);

	return E_SUCCESS;
}
* @endcode
*/
class _OSP_EXPORT_ Email
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	Email(void);

	/**
	 * Initializes this instance of %Email with the specified @c type and @c email. @n
	 * This constructs an instance of %Email of the specified type.
	 *
	 * @since	2.0
	 *
	 * @param[in]	type		The type of email
	 * @param[in]	email		The email address
	 */
	Email(EmailType type, const Tizen::Base::String& email);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs	An instance of %Email
	 */
	Email(const Email& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Email(void);

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
         * Gets the type of the email.
         *
	 * @if OSPCOMPAT
         * @brief <i> [Compatibility] </i>
	 * @endif
         * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility            This method has compatibility issues with OSP compatible applications. @n
         *                           For more information, see @ref CompEmailGetTypePage "here".
	 * @endif
         *
         * @return	The type of the email
         */
	EmailType GetType(void) const;

	/**
	 * @if OSPCOMPAT
         * @page                CompEmailGetTypePage         Compatibility for GetType()
         * @section             CompEmailGetTypePageIssueSection             Issues
	 * Implementing this method in OSP compatible applications has the following issue: @n
         * -# EMAIL_TYPE_CUSTOM is not supported. If the type of the email is EMAIL_TYPE_CUSTOM, EMAIL_TYPE_OTHER is returned instead.
         *
         * @section             CompEmailGetTypePageSolutionSection          Resolutions
	 * The issue mentioned above has been resolved in Tizen.
	 * @endif
         */

	/**
	 * Gets the email address.
	 *
	 * @since	2.0
	 *
	 * @return	The email address
	 */
	Tizen::Base::String GetEmail(void) const;

	/**
	 * Sets the type of the email.
	 *
	 * @since	2.0
	 *
	 * @param[in]	type		The type of the email to set
	 */
	void SetType(EmailType type);

	/**
	 * Sets the email address.
	 *
	 * @if OSPCOMPAT
	 * @brief <i> [Compatibility] </i>
	 * @endif
	 * @since	2.0
	 * @if OSPCOMPAT
	 * @compatibility            This method has compatibility issues with OSP compatible applications. @n
	 *                            For more information, see @ref CompEmailSetEmailPage "here".
	 * @endif
	 *
	 * @return		An error code
	 * @param[in]	email			The email address
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified @c email address is an empty string.
	 */
	result SetEmail(const Tizen::Base::String& email);

	/**
	 * @if OSPCOMPAT
	 * @page		CompEmailSetEmailPage		Compatibility for SetEmail()
	 * @section		CompEmailSetEmailPageIssueSection		Issues
	 * Implementing this method in OSP compatible applications has the following issue: @n
	 * -# If the length of an email address to be set is greater than 100 characters, E_INVALID_ARG is returned.
	 *
	 * @section		CompEmailSetEmailPageSolutionSection		Resolutions
	 * The issue mentioned above has been resolved in Tizen.
	 * @endif
	 */

	/**
	 * Gets the label of an email.
	 *
	 * @since	2.0
	 *
	 * @return	The email label
	 * @see SetLabel()
	 */
	Tizen::Base::String GetLabel(void) const;

	/**
	 * Sets the label of an email. 
	 *
	 * @since	2.0
	 *
	 * @param[in]	label	The email label
	 * @see GetLabel()
	 */
	void SetLabel(const Tizen::Base::String& label);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs	An instance of %Email
	 */
	Email& operator =(const Email& rhs);

	/**
	 * Checks whether the value of the specified instance of %Email is equal to the value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the specified instance of %Email equals the value of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Email
	 */
	bool operator ==(const Email& rhs) const;

	/**
	 * Checks whether the value of the specified instance of %Email does not equal the value of the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the value of the specified instance of %Email does not equal the value of the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Email
	 */
	bool operator !=(const Email& rhs) const;

private:
	friend class _EmailImpl;
	class _EmailImpl* __pEmailImpl;

}; // Email

}} // Tizen::Social

#endif // _FSCL_EMAIL_H_
