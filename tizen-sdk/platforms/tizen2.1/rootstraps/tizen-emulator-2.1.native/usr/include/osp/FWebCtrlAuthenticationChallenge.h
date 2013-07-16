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
 * @file		FWebCtrlAuthenticationChallenge.h
 * @brief		This is the header file for the %AuthenticationChallenge class.
 *
 * This header file contains the declarations of the %AuthenticationChallenge class.
 */

#ifndef _FWEB_CTRL_AUTHENTICATION_CHALLENGE_H_
#define _FWEB_CTRL_AUTHENTICATION_CHALLENGE_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FBaseString.h>

namespace Tizen { namespace Web { namespace Controls
{

/**
 *
 * @class	AuthenticationChallenge
 * @brief		This class handles the HyperText Transfer Protocol (HTTP) authentication requests.
 *
 * @since		2.0
 *
 * The %AuthenticationChallenge class sends the user ID and password to the server requesting user authentication.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/controls_namespace.htm">Web Controls Guide</a>.
 */
class _OSP_EXPORT_ AuthenticationChallenge
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~AuthenticationChallenge(void);

	/**
	 * Sends the user ID and password to the host.
	 *
	 * @since		2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/web.service
	 *
	 * @param[in]		userId			The user ID for authentication
	 * @param[in]		password		The password for authentication
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception		E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	void Process(const UserId& userId, const Tizen::Base::String& password);

	/**
	 * Cancels the authentication request.
	 *
	 * @since		2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/web.service
	 *
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception		E_USER_NOT_CONSENTED		The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	void Cancel(void);

private :
	//
	// This is the constructor for the %AuthenticationChallenge class.
	//
	// @remarks		This constructor is hidden.
	//
	AuthenticationChallenge(void);

private:
	friend class _WebImpl;
	friend class _AuthenticationChallengeImpl;
	class _AuthenticationChallengeImpl* __pAuthenticationChallengeImpl;
}; // AuthenticationChallenge

}}} // Tizen::Web::Controls
#endif // _FWEB_CTRL_AUTHENTICATION_CHALLENGE_H_
