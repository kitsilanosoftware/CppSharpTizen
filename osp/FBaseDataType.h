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
 * @file		FBaseDataType.h
 * @brief		This is the header file for the data types.
 *
 * This header file defines the data types.
 */
#ifndef _FBASE_DATA_TYPE_H_
#define _FBASE_DATA_TYPE_H_


/**
 * @c byte is an @c unsigned @c char datatype.
 * @since 2.0
 */
typedef unsigned char byte;

/**
 * @c result is a @c unsigned @c long type and indicates the result of the method execution.
 * @since 2.0
 */
typedef unsigned long result;


namespace Tizen { namespace Base
{
class String;
}}

typedef Tizen::Base::String UserId;
typedef Tizen::Base::String LoginId;


/**
* The invocation ID is returned when a request is sent.
* @since 2.0
*/
typedef long RequestId;
#define INVALID_REQUEST_ID  -1


// Macro to get the value in byte
#define GET_MASK(val, pos, msk) (((val) & ((msk) << (pos))) >> (pos))
// Macro to put the value in byte
#define PUT_MASK(var, val, pos) ((var) | ((val) << (pos)))


#ifndef Handle
typedef int Handle;
#define INVALID_HANDLE  -1
#endif // Handle

#ifndef null
#define null    0
#endif // null

#ifndef INFINITE
#define INFINITE    0xFFFFFFFF
#endif // INFINITE


#ifndef UUID
#ifndef UUID__DEFINED
typedef struct UUID_
{
	unsigned long x;
	unsigned short s1;
	unsigned short s2;
	unsigned char c[8];
} UUID_;

#define UUID__DEFINED
#define UUID_DEFINED
#endif

#define UUID UUID_
#endif // UUID

#endif // _FBASE_DATA_TYPE_H_
