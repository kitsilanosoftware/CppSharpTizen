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
 * @file		FIoChannelTypes.h
 * @brief		This is the header file for the %ChannelType class.
 *
 * This header file contains the enumerator declarations of the %ChannelType class.
 */
#ifndef _FIO_CHANNEL_TYPES_H_
#define _FIO_CHANNEL_TYPES_H_

namespace Tizen { namespace Io
{

/**
 * @enum ChannelType
 *
 * Defines the type of the channel.
 *
 * @since    2.0
 *
 */
enum ChannelType
{
	CHANNEL_TYPE_CLIENT = 0, /**< The client channel */
	CHANNEL_TYPE_SERVER      /**< The server channel */
};

} } // Tizen::Io

#endif //_FIO_CHANNEL_TYPES_H_
