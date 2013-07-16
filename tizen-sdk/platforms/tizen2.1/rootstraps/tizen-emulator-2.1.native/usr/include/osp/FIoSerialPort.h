//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FIoSerialPort.h
 * @brief		This is the header file for the %SerialPort class.
 *
 * This header file contains the declarations of the %SerialPort class.
 */

#ifndef _FIO_SERIAL_PORT_H_
#define _FIO_SERIAL_PORT_H_

#include <FIo.h>

namespace Tizen { namespace Io
{

class ISerialPortEventListener;

/**
 * @class	SerialPort
 * @brief	This class provides an interface for controlling a serial port resource.
 *
 * @since 2.0
 *
 * @final	This class is not intended for extension.
 *
 * @remarks The serial communication feature is reset when the USB connection is broken or a host device sends the
 * deactivate command. Any serial port options are not supported by the current version.
 *
 * The %SerialPort class provides an interface for controlling a serial port resource. @n
 *
 *  For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/io/serial_port_comm.htm">Serial Port Communication</a>.
 *
 *
 * @see ISerialPortEventListener
 *
 * The following example demonstrates how to use the %SerialPort class.
 *
 * @code
 * #include <FIo.h>
 * #include <FBase.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Io;
 *
 * class SerialRecv
 *      : public Tizen::Io::ISerialPortEventListener
 * {
 *      void OnSerialPortDataReceivedN(Tizen::Base::ByteBuffer& byteBuffer)
 *      {
 *            //Read data.
 *      }
 *
 *      void OnSerialPortErrorOccured(result r)
 *      {
 *            //Check error status.
 *      }
 * }
 * void
 * MyClass::SerialPortSample(void)
 * {
 *      SerialPort serialPort;
 *      ByteBuffer buf;
 *      String szMessage = L"Hello";
 *      SerialRecv listener;
 *
 *      buf.Construct(1024);
 *      buf.SetArray(szMessage.GetPointer(), 0, 6);
 *      buf.Flip();
 *
 *      //Construct serial port.
 *      serialPort.Construct(listener);
 *
 *      //Write buf on output buffer.
 *      serialPort.Write(buf);
 *
 * }
 * @endcode
 *
 *
 *
 */
class _OSP_EXPORT_ SerialPort
	: public Tizen::Base::Object
{

public:
	/**
	  * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	  *
	  * @since 2.0
	  */
	SerialPort(void);

	/**
	  * This destructor overrides Tizen::Base::Object::~Object().
	  *
	  * @since 2.0
	  */
	virtual ~SerialPort(void);

	/**
	 * Constructs a new serial port connection. @n
	 * If the specified port is open, E_SYSTEM is returned.
	 *
	 * @since       2.0
	 *
	 * @return			An error code
	 * @param[in]	listener		The serial port event listener
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 */
	result Construct(ISerialPortEventListener& listener);

	/**
	 * Writes data to the output buffer synchronously.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	byteBuffer					A reference to the buffer that contains the string data to write
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_MAX_EXCEEDED   The buffer size has exceeded the maximum limit of the current device.
	 * @exception	E_SYSTEM	   			A system error has occurred.
	 * @see GetWriteBufferSize()
	 */
	result Write(const Tizen::Base::ByteBuffer& byteBuffer);

	/**
	 * Gets the size of the write buffer.
	 *
	 * @since   2.0
	 *
	 * @return  The size of the write buffer
	 * @remarks 	The size of the write buffer depends on the device.
	 */
	int GetWriteBufferSize(void) const;

private:
	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*/
	SerialPort(const SerialPort& serialPort);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*/
	SerialPort& operator =(const SerialPort& serialPort);

private:
	class _SerialPortImpl* __pSerialPortImpl;

	friend class _SerialPortImpl;

}; // SerialPort

}} // Tizen::Io

#endif // _FIO_SERIAL_PORT_H_

