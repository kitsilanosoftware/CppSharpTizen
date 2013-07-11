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
 * @file	FIoISerialPortEventListener.h
 * @brief	This is the header file for the %ISerialPortEventListener interface.
 *
 * This header file contains the declarations of the %ISerialPortEventListener interface.
 */

#ifndef _FIO_SERIAL_PORT_EVENT_LISTENER_H_
#define _FIO_SERIAL_PORT_EVENT_LISTENER_H_

#include <FBaseResult.h>
#include <FBaseRtIEventListener.h>
#include <FIoSerialPort.h>

namespace Tizen { namespace Io
{

/**
 * @interface ISerialPortEventListener
 * @brief This interface provides event handlers to receive serial port events synchronously.
 *
 * @since	2.0
 *
 * The %ISerialPortEventListener interface provides event handlers to receive serial port events synchronously. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/io/serial_port_comm.htm">Serial Port Communication</a>.
 *
 */

class _OSP_EXPORT_ ISerialPortEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	* Called when the data is received on the serial port.
	*
	* @since		2.0
	*
	* @param[in]	byteBuffer		A byte buffer that contains the received data
	* @remarks			The ByteBuffer instance needs to be deleted by the application.
	*/
	virtual void OnSerialPortDataReceivedN(Tizen::Base::ByteBuffer& byteBuffer) = 0;

	/**
	* Called when an error occurs on the serial port.
	*
	* @since		2.0
	*
	* @param[in]	r	The error code
	* @exception 	E_INVALID_DATA	The data is invalid.
	* @exception	E_SYSTEM				A system error has occurred.
	*/
	virtual void OnSerialPortErrorOccured(result r) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ISerialPortEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ISerialPortEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since	2.0
	//
	virtual void ISerialPortEventListener_Reserved3(void) {}

}; // ISerialPortEventListener

}} // Tizen::Io

#endif // _FIO_SERIAL_PORT_EVENT_LISTENER_H_

