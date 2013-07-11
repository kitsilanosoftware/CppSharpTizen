//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
 * @file		FNetHttpIHttpEntity.h
 * @brief		This is the header file for the %IHttpEntity interface.
 *
 * This header file contains the declarations of the %IHttpEntity interface.
 */

#ifndef _FNET_HTTP_IHTTP_ENTITY_H_
#define _FNET_HTTP_IHTTP_ENTITY_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FBaseByteBuffer.h>
#include <FNetHttpHttpTypes.h>

namespace Tizen { namespace Net { namespace Http
{
class _HttpRequestImpl;
/**
 * @interface	IHttpEntity
 * @brief		This interface provides common functions for the HTTP entity.
 *
 * @since       2.0
 *
 *	The %IHttpEntity interface represents the HTTP entity for the data exchanged between the client and the server.
 */


class _OSP_EXPORT_ IHttpEntity
{

public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since       2.0
	 */
	virtual ~IHttpEntity(void) {}

public:
	/**
	 * Gets the length of the request content.
	 *
	 * @since       2.0
	 *
	 * @return		The length of the content, @n
	 *				else @c -1 if the content length is unknown
	 */
	virtual long long GetContentLength(void) const = 0;

	/**
	 * Gets the type of the request content.
	 *
	 * @since       2.0
	 *
	 * @return		The type of the content
	 */
	virtual Tizen::Base::String GetContentType(void) const = 0;

protected:
	/**
	 * Checks whether the next data exists.
	 *
	 * @since       2.0
	 *
	 * @return		@c true if the next data exists, @n
	 *				else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception   E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual bool HasNextData(void) = 0;

	/**
	 * Gets the next data.
	 *
	 * @since       2.0
	 *
	 * @return		The buffer to be read
	 * @param[in]	recommendedSize			The recommended size of the data to send
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception   E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetNextDataN(int recommendedSize) = 0;

protected:
	// Reserved virtual methods for later extension.

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IHttpEntity_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IHttpEntity_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void IHttpEntity_Reserved3(void) {}

	friend class _HttpRequestImpl;
};

} } } // Tizen::Net::Http
#endif // _FNET_HTTP_IHTTP_ENTITY_H_
