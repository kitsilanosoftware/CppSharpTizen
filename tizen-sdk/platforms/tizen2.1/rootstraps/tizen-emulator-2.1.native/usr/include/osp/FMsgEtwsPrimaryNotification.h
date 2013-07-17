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
* @file			FMsgEtwsPrimaryNotification.h
* @brief		This is the header file for the %EtwsPrimaryNotification class.
*
* This header file contains the declarations of the %EtwsPrimaryNotification class.
*/

#ifndef _FMSG_ETWS_PRIMARY_NOTIFICATION_H_
#define _FMSG_ETWS_PRIMARY_NOTIFICATION_H_

namespace Tizen { namespace Base
{
class DateTime;
class ByteBuffer;
} }

#include <FBaseObject.h>
#include <FMsgTypes.h>

namespace Tizen { namespace Messaging
{

class _EtwsPrimaryNotificationImpl;

/**
* @class	EtwsPrimaryNotification
*
* @brief	This class provides methods for handling an ETWS primary notification.
*
* @since		2.0
*
* @final		This class is not intended for extension.
*
* The %EtwsPrimaryNotification class provides methods for handling an ETWS primary notification. It allows you to get the serial number,
* message ID, warning type, warning security info, and received time of an ETWS primary notification.
*/
class _OSP_EXPORT_ EtwsPrimaryNotification
	: public Tizen::Base::Object
{
public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*/
	virtual ~EtwsPrimaryNotification(void);

	/**
	* Compares the specified instance of %EtwsPrimaryNotification with the calling instance.
	*
	* @since		2.0
	*
	* @return		@c true if the values match, @n
	*				else @c false
	* @param[in]	obj 	The other Tizen::Base::Object to compare
	* @see 			Tizen::Base::Object::Equals()
	*/
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	* Gets the copied instance of the class.
	*
	* @since		2.0
	*
	* @return		An instance of %EtwsPrimaryNotification
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	*
	* @remarks		
	*				- In case of error, this method returns @c null.
	*				- The specific error code can be accessed using the GetLastResult() method.
	*/
	EtwsPrimaryNotification* CloneN(void) const;

	/**
	* Gets the hash value of the current instance.
	*
	* @since		2.0
	*
	* @return		The current instance's hash value
	*/
	virtual int GetHashCode(void) const;

	/**
	* Gets the date and time (UTC time) of the message when it is received.
	*
	* @since		2.0
	*
	* @return		The date and time (UTC time) when the message is received
	*/
	Tizen::Base::DateTime GetReceivedTime(void) const;

	/**
	* Gets the serial number of the ETWS primary notification.
	*
	* @since		2.0
	*
	* @return		The serial number of the ETWS primary notification
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		
	*				- The specific error code can be accessed using the GetLastResult() method.
	*				- In case of an error, this method returns @c null.
	*/
	Tizen::Base::ByteBuffer* GetSerialNumberN(void) const;

	/**
	* Gets the message ID of the ETWS primary notification.
	*
	* @since		2.0
	*
	* @return		The message ID of the ETWS primary notification
	*/
	int GetMessageId(void) const;

	/**
	* Gets the warning type.
	*
	* @since		2.0
	*
	* @return		The ETWS warning type of the message
	*/
	Tizen::Base::ByteBuffer* GetWarningTypeN(void) const;

	/**
	* Gets the warning security information of the ETWS primary notification.
	*
	* @since		2.0
	*
	* @return		The warning security information of the ETWS primary notification
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		
	*				- The specific error code can be accessed using the GetLastResult() method.
	*				- In case of an error, this method returns @c null.
	*/
	Tizen::Base::ByteBuffer* GetWarningSecurityInfoN(void) const;

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @since		2.0
	*/
	EtwsPrimaryNotification(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since		2.0
	*
	* @param[in]	rhs				An instance of EtwsPrimaryNotification
	*/
	EtwsPrimaryNotification(const EtwsPrimaryNotification& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects. @n
	* -	Use CloneN() to get an exact copy of the instance.
	* -	Use Equals() to compare the contents of one instance with the other.
	*
	* @since		2.0
	*
	* @return		A reference to this instance
	* @param[in]	rhs				An instance of EtwsPrimaryNotification
	*/
	EtwsPrimaryNotification& operator =(const EtwsPrimaryNotification& rhs);

private:
	_EtwsPrimaryNotificationImpl* __pEtwsPrimaryNotificationImpl;

	friend class _EtwsPrimaryNotificationImpl;
}; // EtwsPrimaryNotification

} } // Tizen::Messaging
#endif // _FMSG_ETWS_PRIMARY_NOTIFICATION_H_
