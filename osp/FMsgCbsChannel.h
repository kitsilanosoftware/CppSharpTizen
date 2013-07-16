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
* @file			FMsgCbsChannel.h
* @brief		This is the header file for the %CbsChannel class.
*
* This header file contains the declarations of the %CbsChannel class.
*/

#ifndef _FMSG_CBS_CHANNEL_H_
#define _FMSG_CBS_CHANNEL_H_

namespace Tizen { namespace Base
{
class String;
} }

#include <FBaseObject.h>

namespace Tizen { namespace Messaging
{
class _CbsChannelImpl;

/**
* @class		CbsChannel
* @brief		This class provides methods for handling a Cell Broadcast Service (CBS) channel.
*
* @since		2.0
*
* @final		This class is not intended for extension.
*
* The %CbsChannel class provides methods for handling a CBS channel. @n
* It allows you to get and set the CBS channel information.
*/
class _OSP_EXPORT_ CbsChannel
	: public Tizen::Base::Object
{
public:

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*/
	virtual ~CbsChannel(void);

	/**
	* Gets the range of a CBS channel.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[out]	from				The starting index of the message ID of the channel
	* @param[out]	to					The last index of the message ID of the channel
	* @exception    E_SUCCESS           The method is successful.
	* @exception	E_INVALID_STATE		The range has not been set as yet.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		In case of an error, this method sets the negative values for @c from and @c to. For example, @c -1.
	*/
	result GetRange(int& from, int& to) const;

	/**
	* Gets the name of a CBS channel.
	*
	* @since		2.0
	*
	* @return		The name of the channel
	*
	* @remarks		The name can be an empty string.
	*/
	Tizen::Base::String GetName(void) const;

	/**
	* Checks whether a CBS channel is activated.
	*
	* @since		2.0
	*
	* @return		@c true if a CBS channel is activated, @n
	* 				else @c false
	*/
	bool IsActivated(void) const;

	/**
	* Activates the status of a CBS channel.
	*
	* @since		2.0
	* @privlevel	platform
	* @privilege	%http://tizen.org/privilege/cellbroadcast
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_ILLEGAL_ACCESS		The application does not have the permission to activate the CBS channel status.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	*/
	result Activate(void);

	/**
	* Deactivates the status of a CBS channel.
	*
	* @since		2.0
	* @privlevel	platform
	* @privilege	%http://tizen.org/privilege/cellbroadcast
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_ILLEGAL_ACCESS		The application does not have the permission to activate the CBS channel status.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	*/
	result Deactivate(void);

	/**
	* Updates the name of a CBS channel.
	*
	* @since		2.0
	* @privlevel	platform
	* @privilege	%http://tizen.org/privilege/cellbroadcast
	
	* @return		An error code
	* @param[in]	name					The name of the CBS channel to update
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_ILLEGAL_ACCESS		The application does not have the permission to update the CBS channel name.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	*/
	result UpdateName(const Tizen::Base::String& name);

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @since		2.0
	*/
	CbsChannel(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %CbsChannel
	 */
	CbsChannel(const CbsChannel& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs				An instance of %CbsChannel
	 */
	CbsChannel& operator =(const CbsChannel& rhs);

	/**
	* Initializes this instance of %CbsChannel with the specified parameters.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	from				The starting index of the message ID of the channel
	* @param[in]	to					The last index of the message ID of the channel
	* @param[in]	name				The name of the channel (can be an empty string)
	* @exception 	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*                                   - The specified @c to parameter is smaller than @c from. @n
	* 									- The specified @c to or @c from parameter is a negative value. @n
	* 									- The specified @c to parameter exceeds the limit (0xFFFF). @n
	* 									- The range (@c to - @c from) exceeds the limit (0xFFFF). @n
	* 									- The specified @c name string length is greater than @c 32. @n
	* @exception	E_SYSTEM			A system error has occurred.
	*/
	result Construct(int from, int to, const Tizen::Base::String& name);

private:
	_CbsChannelImpl* __pCbsChannelImpl;

	friend class _CbsChannelImpl;
}; // CbsChannel

} } // Tizen::Messaging
#endif // _FMSG_CBS_CHANNEL_H_
