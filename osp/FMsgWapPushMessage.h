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
* @file			FMsgWapPushMessage.h
* @brief		This is the header file for the %WapPushMessage class.
*
* This header file contains the declarations of the %WapPushMessage class.
*/

#ifndef _FMSG_WAP_PUSH_MESSAGE_H_
#define _FMSG_WAP_PUSH_MESSAGE_H_

namespace Tizen { namespace Base
{
class String;
class ByteBuffer;
} }

#include <FBaseObject.h>

namespace Tizen { namespace Messaging
{
class _WapPushMessageImpl;

/**
* @class		WapPushMessage
* @brief		This class provides methods for handling a WAP Push message.
*
* @since		2.0
*
* @final		This class is not intended for extension.
*
* The %WapPushMessage class provides methods for handling a WAP Push message. @n
* The methods of this class fetches the header and the body of a WAP Push message.
*/
class _OSP_EXPORT_ WapPushMessage
	: public Tizen::Base::Object
{
public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*/
	virtual ~WapPushMessage(void);

public:

	/**
	* Gets the header of a message.
	*
	* @since		2.0
	*
	* @return		The header of a message
	* @remarks		The header has X-Wap-Application-Id and Content-Type fields.
	*/
	Tizen::Base::String GetHeader(void) const;

	/**
	* Gets the body of a message.
	*
	* @since		2.0
	*
	* @return		The body of a message
	* @remarks		
	*				- The message body can be any MIME content-type.
	*				- In case of error, this method returns @c null.
	*				- The specific error code can be accessed using the GetLastResult() method.
	*/
	Tizen::Base::ByteBuffer* GetBodyN(void) const;

	/**
	* Compares the calling instance with the specified instance.
	*
	* @since		2.0
	*
	* @return		@c true if the specified instance of Tizen::Base::Object is equal to the calling %WapPushMessage instance, @n
	*				else @c false
	* @param[in]	obj 	An instance of Tizen::Base::Object to compare 
	* @see 			Tizen::Base::Object::Equals()
	*/
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	* Gets the hash value of the current instance.
	*
	* @since		2.0
	*
	* @return		The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

	/**
	* Gets the copied instance of the class.
	*
	* @since		2.0
	*
	* @return		An instance of %WapPushMessage, @n
	*                else @c null in case of an error
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	WapPushMessage* CloneN(void) const;

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @since		2.0
	*/
	WapPushMessage(void);

	/**
	* This is the copy constructor for the %WapPushMessage class. @n
	* Copying of objects using this copy constructor is allowed.
	*
	* @since		2.0
	*
	* @param[in]	rhs				An instance of %WapPushMessage
	*/
	WapPushMessage(const WapPushMessage& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects. @n
	* - Use CloneN() to get an exact copy of the instance.
	* - Use Equals() to compare the contents of one instance with the other.
	* 
	* @return		A reference to this instance
	*
	* @param[in]	rhs				An instance of %WapPushMessage
	*/
	WapPushMessage& operator =(const WapPushMessage& rhs);

	/**
	* This constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @param[in]	header	The header of the received WAP Push message
	* @param[in]	body	The body of the received WAP Push message
	*/
	WapPushMessage(const Tizen::Base::String& header, const Tizen::Base::ByteBuffer& body);

private:
	_WapPushMessageImpl* __pWapPushMessageImpl;

	friend class _WapPushMessageImpl;
}; // WapPushMessage

} } // Tizen::Messaging
#endif // _FMSG_WAP_PUSH_MESSAGE_H_
