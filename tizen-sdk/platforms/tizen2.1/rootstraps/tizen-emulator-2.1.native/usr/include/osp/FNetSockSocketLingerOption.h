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
* @file		FNetSockSocketLingerOption.h
* @brief	This is the header file for the %LingerOption class.
*
* This header file contains the declarations of the %LingerOption class.
*/

#ifndef _FNET_SOCK_SOCKET_LINGER_OPTION_H_
#define _FNET_SOCK_SOCKET_LINGER_OPTION_H_

#include <FBaseObject.h>

namespace Tizen { namespace Net { namespace Sockets
{

class _LingerOptionImpl;

/**
* @class	LingerOption
* @brief	This class specifies whether a socket remains connected after the Socket::Close() method is called.
*			It also specifies the amount of time for which it remains connected, if the data is not sent.
*
* @since	2.0
*
* The %LingerOption class specifies whether a socket remains connected after the Socket::Close() method is called.
*			It also specifies the amount of time for which it remains connected, if the data is not sent.
*
*For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/sockets.htm">Sockets Guide</a>.
*
* @see		Tizen::Net::Sockets::Socket::SetSockOpt(NetSocketOptLevel, NetSocketOptName, const LingerOption&)
*
* The following example demonstrates how to use the %LingerOption class.
*
*	@code
*	using namespace Tizen::Base;
*	using namespace Tizen::Net::Sockets;
*
*	void
*	MyClass::SomeMethod(void)
*	{
*		// Constructs a LingerOption object.
*		LingerOption socketLinger(true, 10);
*
*		// Gets information on a LingerOption object.
*		if (socketLinger.IsEnabled())
*		{
*			ushort time = socketLinger.GetLingerTime();
*		}
*	}
*	@endcode
*/
class _OSP_EXPORT_ LingerOption
	: public Tizen::Base::Object
{

public:
	/**
	* Initializes this instance of %LingerOption class with the specified parameters.
	*
	* @since		2.0
	*
	* @param[in]	enable		Set to @c true to remain connected after the Socket::Close() method is called, @n
	*							else @c false
	* @param[in]	seconds		The number of seconds to remain connected after the Socket::Close() method is called
	* @remarks      Data may still be available in the outgoing network buffer after the socket is closed.
	*				If you want to specify the amount of time the socket attempts to transmit unsent data after being closed,
	*				create a %LingerOption with the @c enable parameter set to @c true, and the @c seconds parameter set to the desired
	*				amount of time. The @c seconds parameter is used to indicate how long the socket remains connected
	*				before getting timed out. If the socket is not required to stay connected for any amount of time after being closed,
	*				create a %LingerOption with the enabled parameter set to @c false. In this case, the socket closes immediately
	*				and any unsent data is lost. Once created, pass the %LingerOption to the Socket::SetSoLinger() method.
	*
	*/
	LingerOption(bool enable, int seconds);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*/
	virtual ~LingerOption(void);

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since		2.0
	*
	* @param[in]	rhs		An instance of %LingerOption
	*/
	LingerOption(const LingerOption& rhs);

	/**
	* Copying of objects using this copy assignment operator is allowed.
	*
	* @since		2.0
	*
	* @return		A reference to this instance
	* @param[in]	rhs			An instance of %LingerOption
	*/
	LingerOption& operator =(const LingerOption& rhs);

	/**
	 * Compares the specified instance of %LingerOption with the calling instance.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the values match, @n
	 *			else @c false
	 * @param[in]	obj 	The other Tizen::Base::Object to compare
	 * @see 		Tizen::Base::Object::Equals()
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since		2.0
	 * @return  	The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

public:
	/**
	* Sets a value indicating whether the socket should linger after being closed.
	*
	* @since		2.0
	*
	* @param[in]	on			Set to @c true if the socket should linger after Socket::Close() is called, @n
	*							else @c false
	*/
	void SetEnabled(bool on);

	/**
	* Sets the linger time. @n
	* This is the amount of time to remain connected after calling the Socket::Close() method if data remains to be sent.
	*
	* @since		2.0
	*
	* @param[in]	seconds		The amount of time, in seconds, to remain connected after calling Socket::Close()
	* @remarks		Use this method to determine how long a closed socket attempts transferring unsent data before getting timed out. The value can
	*				also be set to the desired time-out period in seconds. If the Enabled property is set to @c true, and LingerTime is set to @c 0, the
	*				socket attempts to send the data until there is no data left in the outgoing network buffer.
	* @see			Socket::SetSockOpt()
	*/
	void SetLingerTime(int seconds);

	/**
	* Gets the linger time. @n
	* This is the amount of time to remain connected after calling the Socket::Close() method if data still remains to be sent.
	*
	* @since		2.0
	*
	* @return		The amount of time in seconds to remain connected after calling Socket::Close()
	*/
	int GetLingerTime(void) const;

	/**
	 * Checks whether the linger option is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the socket lingers after Socket::Close() is called, @n
	 *				else @c false
	 */
	bool IsEnabled(void) const;

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*/
	LingerOption(void);

private:
	_LingerOptionImpl* __pLingerOptionImpl;

	friend class _LingerOptionImpl;
};

} } }   // Tizen::Net::Sockets


#endif // _FNET_SOCK_SOCKET_LINGER_OPTION_H_
