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
 * @file	FIo.h
 * @brief	This is the header file for the Tizen::Io namespace.
 *
 * This header file contains the declarations of the Tizen::Io namespace.
 */

#ifndef _FIO_H_
#define _FIO_H_

#include <FIoFile.h>
#include <FIoDirectory.h>
#include <FIoDirEntry.h>
#include <FIoDirEnumerator.h>
#include <FIoRegistry.h>
#include <FIoDbTypes.h>
#include <FIoDatabase.h>
#include <FIoDbStatement.h>
#include <FIoDbEnumerator.h>
#include <FIoSqlStatementBuilder.h>
#include <FIoFileEventManager.h>
#include <FIoChannel.h>
#include <FIoMessagePortManager.h>
#include <FIoIMessagePortListener.h>
#include <FIoSerialPort.h>
#include <FIoIDbEnumerator.h>
#include <FIoIFileEventListener.h>
#include <FIoISerialPortEventListener.h>

/**
 * @namespace	Tizen::Io
 * @brief		This namespace contains classes and interfaces for performing basic I/O operations.
 * @since		2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FIo.h> @n
 *				@b Library : @b osp-appfw
 *
 * The %Io namespace allows applications to input/output data to/from file systems and other programs and process it.
 * Thus, the %Io namespace is an interface between the system and the application.
 * The %Io namespace provides classes and methods for managing files, directories, registries, databases, channels, and serial port communication.
 * @n
 * For more information on the %Io namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/io/io_namespace.htm">Io Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Io namespace.
 *  @image html io_namespace_classdiagram.png
 */

namespace Tizen
{
namespace Io
{

}
}

#endif // _FIO_H_

