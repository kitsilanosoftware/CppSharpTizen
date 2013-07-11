//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FBaseErrors.h
 * @brief		This header file defines error codes.
 *
 * This header file contains the definitions of error codes.
 */
#ifndef _FBASE_ERRORS_H_
#define _FBASE_ERRORS_H_

#include <FBaseErrorDefine.h>


//----------------------------------------------------------------------------A
/** (specialized) Thrown when network address is changed externally. */
#define E_ADDRESS_CHANGED               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1100))

/** Thrown when the target is bounded to another source. */
#define E_ALREADY_BOUND                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1101))

/** Thrown when the target is connected to another source. */
#define E_ALREADY_CONNECTED             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1102))

/** Thrown when the target is already opened. */
#define E_ALREADY_OPENED                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1103))

/** Thrown when the authentication request fails. */
#define E_AUTHENTICATION                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1104))

/** Thrown when the required application is not installed. */
#define E_APP_NOT_INSTALLED             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1105))

/** Thrown when the specified instance is already set to other values, instances or resources. */
#define E_ALREADY_SET			(ERR_SRC_FRAMEWORK + SET_E_CAUSE(1106))

/** Thrown when a specified account already exists. */
#define E_ACCOUNT_ALREADY_EXIST         (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1107))

/** Thrown when a required account does not exist. */
#define E_ACCOUNT_NOT_FOUND             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1108))


//----------------------------------------------------------------------------B

//----------------------------------------------------------------------------C
/** (specialized) ... */
#define E_CHUNKED_TRANSACTION           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1300))

/** Thrown when the connection is busy, so cannot process the new request. */
#define E_CONNECTION_BUSY               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1301))

/** Thrown when the connection to the specific destination fails. */
#define E_CONNECTION_FAILED             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1302))

/** Thrown when the connection is reset while the other thread is still
 * working on it. */
#define E_CONNECTION_RESET              (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1303))

/** Thrown when the token is expired. */
#define E_CREDENTIAL_EXPIRED            (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1304))

/** The server certificate verification has failed. */
#define E_CERTIFICATE_VERIFICATION_FAILED	(ERR_SRC_FRAMEWORK + SET_E_CAUSE(1305))

//----------------------------------------------------------------------------D
/** Thrown when the requested data does not exist. */
#define E_DATA_NOT_FOUND                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1400))

/** Thrown when underlying database system raises exception. */
#define E_DATABASE                      (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1401))

/** Thrown when decoding operation fails. */
#define E_DECODING_FAILED               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1402))

/** Thrown when the device is processing the previous task, so cannot process
 * the new one. */
#define E_DEVICE_BUSY                   (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1403))

/** Thrown when the device fails with unknown reason. */
#define E_DEVICE_FAILED                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1404))

/** Thrown when the device does not support the specific request. */
#define E_DEVICE_INCOMPATIBLE           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1405))

/** Thrown when the device is not installed, or not answering at all. */
#define E_DEVICE_UNAVAILABLE            (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1406))

/** General DHCP exception. */
#define E_DHCP                          (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1407))

/** Thrown when the dimension has changed. */
#define E_DIMENSION_CHANGED             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1408))

/** General DNS exception. */
#define E_DNS                           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1409))

/** Thrown when DNS cannot resolve the requested address. */
#define E_DNS_NOT_FOUND                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1410))

/** Thrown when the data is not enough to generate the processing result. */
#define E_DATA_NOT_ENOUGH               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1411))

//----------------------------------------------------------------------------E
/** Thrown when effects being played on the current haptic device are disabled. */
#define E_EFFECTS_DISABLED              (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1500))

/** Thrown when a body is empty. */
#define E_EMPTY_BODY                    (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1501))

/** Thrown when encoding operation fails. */
#define E_ENCODING_FAILED               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1502))

/** Thrown when an end of the file or an end of the stream is reached unexpectedly
 * during an input operation. */
#define E_END_OF_FILE                   (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1503))


//----------------------------------------------------------------------------F
// Thrown when the requested operation fails by undefined reason.
//#define E_FAILURE						(ERR_SRC_FRAMEWORK + SET_E_CAUSE(1600))

/** (specialized) Thrown when application tries to call with a number which is
 * not allowed in FDN mode, while the FDN mode is enabled. */
#define E_FDN_MODE                      (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1600))

/** Thrown when an attempt to create the file denoted by a specified pathname
 *  fails. */
#define E_FILE_ALREADY_EXIST            (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1601))

/** Thrown when an attempt to open the file denoted by a specified pathname
 *  fails. */
#define E_FILE_NOT_FOUND                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1602))


//----------------------------------------------------------------------------G
/** Thrown when a required group does not exist. */
#define E_GROUP_NOT_FOUND               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1700))


//----------------------------------------------------------------------------H
/** Thrown the destination host is not found. */
#define E_HOST_NOT_FOUND                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1800))

/** Thrown when the destination host is unreachable. */
#define E_HOST_UNREACHABLE              (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1801))

/** Thrown the Http transaction is canceled by user. */
#define E_HTTP_USER                     (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1802))


//----------------------------------------------------------------------------I
/** Thrown when the user does not have proper permissions. */
#define E_ILLEGAL_ACCESS                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1900))

/** Thrown when the application requests an operation which is in progress. */
#define E_IN_PROGRESS                   (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1901))

/** Thrown when the return type is supposed to be a file path, but the path is not accessible by the application. */
#define E_INACCESSIBLE_PATH             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1902))

/** Thrown when initialization fails. */
#define E_INIT_FAILED                   (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1903))

/** Thrown when an instantiation fails by certain reason. */
#define E_INSTANTIATION_FAILED          (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1904))

/** Thrown when the haptic device priority is lower than that of the current
 *  effects being played, belonging to another device instance. */
#define E_INSUFFICIENT_PRIORITY         (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1905))

/** Thrown when a requested operation cannot perform any further due to an
 * interruption from other thread. */
#define E_INTERRUPTED                   (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1906))

/** Thrown when an account configuration is invalid. */
#define E_INVALID_ACCOUNT               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1907))

/** Thrown when a given address is invalid or not suitable for a requested
 * operation. */
#define E_INVALID_ADDRESS               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1908))

/** Thrown when a combination of passed information is not proper for performing
 * the requested operation. */
#define E_INVALID_ARG                   (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1909))

/** Thrown when a combination of passed information is not proper for performing
 * the requested operation. */
#define E_INVALID_CONDITION             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1910))

/** Thrown when an operation requests for invalid connection. */
#define E_INVALID_CONNECTION            (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1911))

/** Thrown when content is invalid. */
#define E_INVALID_CONTENT               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1912))

/** Thrown when context is invalid. */
#define E_INVALID_CONTEXT               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1913))

/** Thrown when the requested (given or referenced) data is invalid. */
#define E_INVALID_DATA                  (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1914))

/** (specialized) Thrown when the requested (given or referenced) domain is
 * invalid. */
#define E_INVALID_DOMAIN                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1915))

/** Thrown when an indicated string contains code pointing outside of bounds by the
 * specified character encoding scheme. */
#define E_INVALID_ENCODING_RANGE        (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1916))

/** Thrown when the specified input has invalid format. */
#define E_INVALID_FORMAT                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1917))

/** (specialized) Thrown when  */
#define E_INVALID_HEADER                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1918))

/** Thrown when the specified input has invalid format. */
#define E_INVALID_KEY                   (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1919))

/** Thrown when current state of the instance prohibits the execution of the
 * specified operation. */
#define E_INVALID_OPERATION             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1920))

/** (specialized) Thrown when the proxy address is invalid. */
#define E_INVALID_PROXY                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1921))

/** (specialized) Thrown when the SIM is not in proper state for processing the
 * requested operation. */
#define E_INVALID_SIM_STATE             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1922))

/** (specialized) Thrown when the DNS request goes to an invalid DNS server. */
#define E_INVALID_SERVER                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1923))

/** Thrown when the relevant session is invalid. */
#define E_INVALID_SESSION               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1924))

/** Thrown when the socket which is responsible for the application's request
 * is invalid. */
#define E_INVALID_SOCKET                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1925))

/** Thrown when an instance is not in valid state. */
#define E_INVALID_STATE                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1926))

/** Thrown when the relevant transaction is invalid. */
#define E_INVALID_TRANSACTION           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1927))

/** Thrown when an exception occurs during I/O operations. This is a general
 * exception produced by failed or interrupted I/O operations. */
#define E_IO                            (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1928))

/** Thrown when the client has not joined the domain controller. */
#define E_NOT_JOINED                    (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1929))

/** The server certificate verification has failed on client. */
#define E_INVALID_CERTIFICATE           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1930))

/** Thrown when a given url is invalid or not suitable for a requested
* operation. */
#define E_INVALID_URL                   (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1931))

/** Thrown when the specified user id has invalid format. */
#define E_INVALID_USER_ID               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1932))

/** Thrown when the specified password has invalid format. */
#define E_INVALID_PASSWORD              (ERR_SRC_FRAMEWORK + SET_E_CAUSE(1933))


//----------------------------------------------------------------------------J

//----------------------------------------------------------------------------K
/** Thrown when a specified key already exists. */
#define E_KEY_ALREADY_EXIST             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2100))

/** Thrown when a required key does not exist. */
#define E_KEY_NOT_FOUND                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2101))

//----------------------------------------------------------------------------L
/** Thrown when an error related to handling landmark occurs. */
#define E_LANDMARK                      (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2200))

/** Thrown when a specified library does not exists. */
#define E_LIBRARY_NOT_FOUND             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2201))

/** Thrown when a specified library is not loaded. */
#define E_LIBRARY_NOT_LOADED            (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2202))

/** (specialized) Thrown when a link error occurs. */
#define E_LINK                          (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2203))

/** Thrown when a Location API specific error has occurred. */
#define E_LOCATION                      (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2204))

/** Thrown when an error related to handling service provider requests has
 * occurred. */
#define E_LOCATION_SERVICE              (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2205))

/** Thrown when locking (or unlocking) fails inside the logic. So cannot
 * guarantee synchronous operation. */
#define E_LOCK_FAILED                   (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2206))

/** Thrown when the language is not set yet. */
#define E_LANGUAGE_NOT_SET              (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2207))

/** Thrown when a location is not available */
#define E_LOCATION_UNAVAILABLE          (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2208))

//----------------------------------------------------------------------------M
/** Thrown when the defined limit exceeds. */
#define E_MAX_EXCEEDED                  (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2300))

/** Thrown when one or more of the required input is not provided. */
#define E_MISSING_INPUT                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2301))

/** (specialized) ... */
#define E_MOBILE_FAILED                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2302))

/** (specialized) ... */
#define E_MODEL_NOT_FOUND               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2303))

/** Thrown when a specified member already exists. */
#define E_MEMBER_ALREADY_EXIST          (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2304))


//----------------------------------------------------------------------------N
/** General network exception. */
#define E_NETWORK_FAILED                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2400))

/** Thrown when the network is not enabled. */
#define E_NETWORK_UNAVAILABLE           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2401))

/** Thrown the client certificate is required to connect to the server. */
#define E_NO_CERTIFICATE                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2402))

/** Thrown when the operation is permitted only for members, but the current
 * user is not. */
#define E_NOT_A_MEMBER                  (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2403))

/** (specialized) Thrown when Bluetooth pairing is not established. */
#define E_NOT_PAIRED                    (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2404))

/** Thrown when the target is not responding. */
#define E_NOT_RESPONDING                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2405))

/** Thrown when the specified string does not represent valid number. */
#define E_NUM_FORMAT                    (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2406))

//----------------------------------------------------------------------------O
/** Thrown when the specified instance already exists. */
#define E_OBJ_ALREADY_EXIST             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2500))

/** Thrown when the required instance does not exist. */
#define E_OBJ_NOT_FOUND                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2501))

/** Thrown when the specified instance is already locked. */
#define E_OBJECT_LOCKED                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2502))

/** Thrown when any request occurs while the target is still
 * initializing. */
#define E_ON_INITIALIZING               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2503))

/** Thrown when the operation is canceled explicitly. */
#define E_OPERATION_CANCELED            (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2504))

/** Thrown when the operation fails due to certain reason. */
#define E_OPERATION_FAILED              (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2505))

/** Thrown when the memory is not sufficient to perform the requested
 * operation. */
#define E_OUT_OF_MEMORY                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2506))

/** Thrown when the internal state of the current instance reaches the
 * valid range. */
#define E_OUT_OF_RANGE                  (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2507))

/** Thrown when the operation has caused an overflow. */
#define E_OVERFLOW                      (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2508))

/** Thrown when OpenGL operation failed. */
#define E_OPENGL_ERROR                  (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2509))


//----------------------------------------------------------------------------P
/** (specialized) Thrown when the requested Bluetooth pairing fails. */
#define E_PAIRING_FAILED                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2600))

/** Thrown when the parsing fails due to any reason. */
#define E_PARSING_FAILED                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2601))

/** Thrown when an application invokes an API without a proper privilege. */
#define E_PRIVILEGE_DENIED              (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2602))

/** Thrown when the package is not installed. */
#define E_PKG_NOT_INSTALLED             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2603))

//----------------------------------------------------------------------------Q

//----------------------------------------------------------------------------R
/** Thrown when a write operation is requested for an instance in read only
 * mode. */
#define E_READ_ONLY                     (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2800))

/** Thrown when the operation is rejected by remote site. */
#define E_REJECTED                      (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2801))

/** (not used) */
#define E_REMOTE_DEVICE_NOT_FOUND       (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2802))

/** (not used) */
#define E_REMOVE_SERVICE_NOT_FOUND      (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2803))

/** Thrown when the required resource is currently unavailable. */
#define E_RESOURCE_UNAVAILABLE          (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2804))

/** Thrown when the right to get served has expired. */
#define E_RIGHT_EXPIRED                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2805))

/** Thrown when there is no right. */ 
#define E_RIGHT_NO_LICENSE		(ERR_SRC_FRAMEWORK + SET_E_CAUSE(2806))

/** Thrown when the right is for future use. */
#define E_RIGHT_FUTURE_USE			(ERR_SRC_FRAMEWORK + SET_E_CAUSE(2807))


//----------------------------------------------------------------------------S
/** Thrown when the specified section already exists. */
#define E_SECTION_ALREADY_EXIST         (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2900))

/** Thrown when the required section does not exist. */
#define E_SECTION_NOT_FOUND             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2901))

/** Thrown when a server tells the device that operation failed due to some
 * reason. Detailed message will be followed by - error code and an error message. */
#define E_SERVER                        (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2902))

/** Thrown when the dedicated service module is too busy to handle another
 * request. */
#define E_SERVICE_BUSY                  (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2903))

/** Thrown when the specific service is restricted by policy. */
#define E_SERVICE_LIMITED               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2904))

/** Thrown when a service is locked. */
#define E_SERVICE_LOCKED                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2905))

/** Thrown when the dedicated service is not available. */
#define E_SERVICE_UNAVAILABLE           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2906))

/** Thrown when the base session is deactivated while it's still being used. */
#define E_SESSION_DEACTIVATED           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2907))

/** (not used) */
#define E_SESSION_UNAVAILABLE           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2908))

/** (not used)  */
#define E_SIZE_MISMATCH                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2909))

/** The socket connection closed by user. */
#define E_SOCKET_USER                   (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2910))

/** Thrown when the storage is full. */
#define E_STORAGE_FULL                  (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2911))

/** Thrown when the specified symbol is not found. */
#define E_SYMBOL_NOT_FOUND              (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2912))

/** Thrown when the input statement does not confirm to the specific syntax. */
#define E_SYNTAX                        (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2913))

/** Thrown when a failure occurs from the underlying system. */
#define E_SYSTEM                        (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2914))

/** Thrown when a service is deactivated. */
#define E_SERVICE_DEACTIVATED           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(2915))


//----------------------------------------------------------------------------T
/** (specialized) Thrown then the specified table does not exist. */
#define E_TABLE_NOT_FOUND               (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3000))

/** Thrown when the operation can not be completed within the specified time
 * period. */
#define E_TIMEOUT                       (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3001))

/** Thrown when the specified type does not match. */
#define E_TYPE_MISMATCH                 (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3002))


//----------------------------------------------------------------------------U
/** Thrown when the operation causes an underflow. */
#define E_UNDERFLOW                     (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3100))

/** Thrown when a unknown error occurs. */
#define E_UNKNOWN                       (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3101))

/** Thrown when the specified algorithm is not supported. */
#define E_UNSUPPORTED_ALGORITHM         (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3102))

/** Thrown when the required CODEC is not found. */
#define E_UNSUPPORTED_CODEC             (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3103))

/** (specialized) Thrown when the requested address family is not supported. */
#define E_UNSUPPORTED_FAMILY            (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3104))

/** Thrown when the current implementation does not support the format of the
 * input. */
#define E_UNSUPPORTED_FORMAT            (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3105))

/** Thrown when the specified protocol is not supported. */
#define E_UNSUPPORTED_PROTOCOL          (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3106))

/** Thrown when the current implementation does not support the requested
 * operation. */
#define E_UNSUPPORTED_OPERATION         (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3107))

/** Thrown when the specified option is not supported. */
#define E_UNSUPPORTED_OPTION            (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3108))

/** Thrown when the specified service is not supported. */
#define E_UNSUPPORTED_SERVICE           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3109))

/** Thrown when the specified type is not supported. */
#define E_UNSUPPORTED_TYPE              (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3110))

/** Thrown when the URL is changed. */
#define E_URL_CHANGED                   (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3111))

/** (specialized) used by HTTP transaction. */
#define E_USER_AGENT_NOT_ALLOWED        (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3112))

/** Thrown when a user is already registered to the device. */
#define E_USER_ALREADY_REGISTERED       (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3113))

/** Thrown when the required user does not exist. */
#define E_USER_NOT_FOUND                (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3114))

/** Thrown when no user is registered to the device yet. */
#define E_USER_NOT_REGISTERED           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3115))

/** Thrown when the specified language is not supported. */
#define E_UNSUPPORTED_LANGUAGE          (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3116))

/** Thrown when the specified version of the input content is not supported. */
#define E_UNSUPPORTED_VERSION           (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3117))

/** Thrown when the specified locale is not supported. */
#define E_UNSUPPORTED_LOCALE            (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3118))

/** Thrown when the user blocks an application from using the user information. */
#define E_USER_NOT_CONSENTED            (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3119))

//----------------------------------------------------------------------------V

//----------------------------------------------------------------------------W
/** (specialized) Thrown when non-blocking socket operation could not be
 * completed immediately. */
#define E_WOULD_BLOCK                   (ERR_SRC_FRAMEWORK + SET_E_CAUSE(3300))

//----------------------------------------------------------------------------X

//----------------------------------------------------------------------------Y

//----------------------------------------------------------------------------Z


//-----------------------------------------------------------------------------

#endif // _FBASE_ERRORS_H_
