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
* @file			FMsgCbsMessage.h
* @brief		This is the header file for the %CbsMessage class.
*
* This header file contains the declarations of the %CbsMessage class.
*/

#ifndef _FMSG_CBS_MESSAGE_H_
#define _FMSG_CBS_MESSAGE_H_

namespace Tizen { namespace Base
{
class ByteBuffer;
class String;
class DateTime;
} }

#include <FBaseObject.h>
#include <FMsgTypes.h>

namespace Tizen { namespace Messaging
{

class _CbsMessageImpl;

/**
* @class	CbsMessage
*
* @brief	This class provides methods for handling a CBS message.
*
* @since		2.0
*
* @final		This class is not intended for extension.
*
* The %CbsMessage class provides methods for handling a CBS message (including the ETWS secondary notification). It allows you to get the serial number,
* message ID, body text, and received time of a CBS message.
*/
class _OSP_EXPORT_ CbsMessage
	: public Tizen::Base::Object
{
public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*/
	virtual ~CbsMessage(void);

	/**
	* Compares the calling instance with the specified instance.
	*
	* @since		2.0
	*
	* @return		@c true if the specified instance of Tizen::Base::Object is equal to the calling %CbsMessage instance, @n
	*				else @c false
	* @param[in]	obj 	An instance of Tizen::Base::Object to compare
	* @see 			Tizen::Base::Object::Equals()
	*/
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	* Copies the instance of a class.
	*
	* @since		2.0
	*
	* @return		An instance of %CbsMessage
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	*
	* @remarks		
	*				- In case of error, this method returns @c null.
	*				- The specific error code can be accessed using the GetLastResult() method.
	*/
	CbsMessage* CloneN(void) const;

	/**
	* Gets the hash value of the current instance.
	*
	* @since		2.0
	*
	* @return		The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

	/**
	* Checks whether this message is an ETWS notification.
	*
	* @since		2.0
	*
	* @return		@c true if this message is an ETWS notification, @n
	*				else @c false
	* @remarks		If the return value is @c true, the message is ETWS secondary notification.
	*/
	bool IsEtwsNotification(void) const;

	/**
	* Gets the serial number of the CBS message.
	*
	* @since		2.0
	*
	* @return		The serial number of the CBS message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		
	*				- The specific error code can be accessed using the GetLastResult() method.
	*				- In case of an error, this method returns @c null.
	*/
	Tizen::Base::ByteBuffer* GetSerialNumberN(void) const;

	/**
	* Gets the message ID of the CBS message.
	*
	* @since		2.0
	*
	* @return		The message ID of the CBS message
	*/
	int GetMessageId(void) const;

	/**
	* Gets the body of a message.
	*
	* @since		2.0
	*
	* @return		The body of a message
	*/
	Tizen::Base::String GetText(void) const;

	/**
	* Gets the date and time (UTC time) of the message when it is received.
	*
	* @since		2.0
	*
	* @return		The date and time (UTC time) when the message is received
	*/
	Tizen::Base::DateTime GetReceivedTime(void) const;

	/**
	* Gets the Data Coding Scheme of the CBS message.
	*
	* @since		2.0
	*
	* @return        	The Data Coding Scheme of the CBS message
	* @exception     	E_SUCCESS                        The method is successful.
	* @exception     	E_OUT_OF_MEMORY                  The memory is insufficient.
	* @remarks      	
	*				- In case of an error, this method returns @c null.
	*				- The specific error code can be accessed using the GetLastResult() method.
	*				- The alphabet/coding and the language applied to CBS messages are defined in 3GPP TS 23.038.
	*/
	byte GetDataCodingScheme(void) const;

	/**
	* Gets the language type of a message.
	*
	* @since		2.1
	*
	* @return        	The language type of a message
	*/
	Tizen::Base::String GetLanguageType(void) const;

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @since		2.0
	*/
	CbsMessage(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since		2.0
	*
	* @param[in]	rhs				An instance of %CbsMessage
	*/
	CbsMessage(const CbsMessage& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects. @n
	* -	Use CloneN() to get an exact copy of the instance.
	* -	Use Equals() to compare the contents of one instance with the other.
	*
	* @since		2.0
	*
	* @return		A reference to this instance
	* @param[in]	rhs				An instance of %CbsMessage
	*/
	CbsMessage& operator =(const CbsMessage& rhs);

private:
	_CbsMessageImpl* __pCbsMessageImpl;

	friend class _CbsMessageImpl;
}; // CbsMessage

} } // Tizen::Messaging
#endif // _FMSG_CBS_MESSAGE_H_
