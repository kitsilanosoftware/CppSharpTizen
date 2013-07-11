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
 * @file		FBaseUtilTypes.h
 * @brief		This is the header file for various utilities.
 *
 * This header file contains the descriptions of various utilities.
 */

#ifndef _FBASE_UTIL_TYPES_H_
#define _FBASE_UTIL_TYPES_H_

namespace Tizen { namespace Base { namespace Utility
{


/**
 *	@enum	CompressionLevel
 *
 *	Defines the compression level.
 *
 *	@since 2.0
 */
enum CompressionLevel
{
	BEST_SPEED = 0,                 /**< For best speed */
	BEST_COMPRESSION,               /**< For best compression */
	DEFAULT_COMPRESSION             /**< For average speed and average compression */
};


/**
 *	@enum LinkType
 *
 * 	Defines the possible link types.
 *
 *	@since 2.0
 */
enum LinkType
{
	LINK_TYPE_NONE = 0x0000,        /**< The no link type */
	LINK_TYPE_URL = 0x0001,         /**< The URL link type */
	LINK_TYPE_EMAIL = 0x0002,       /**< The email link type */
	LINK_TYPE_TEL_NUM = 0x0004,     /**< The telephone number link type */
	LINK_TYPE_APPCONTROL = 0x0008,  /**< The AppControl link type */
	LINK_TYPE_MIME = 0x0010,        /**< The MIME link type */
	LINK_TYPE_MAX = 0x7FFF          /*<  Not Used. The placeholder */
};

}}} // Tizen::Base::Utility

#endif /* _FBASE_UTIL_TYPES_H_ */
