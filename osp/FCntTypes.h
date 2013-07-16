//
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
 * @file			FCntTypes.h
 * @brief		This is the header file for the definitions of constants and enumerators in the Content namespace.
 *
 * This header file contains definitions for the constants and enumerators in the Content namespace.
 */

#ifndef _FCNT_TYPES_H_
#define _FCNT_TYPES_H_

namespace Tizen { namespace Base
{
class UuId;
}}

namespace Tizen { namespace Base
{
class String;
}}

namespace Tizen { namespace Content
{

/**
 * The content ID.
 *
 * @since	2.0
 */
typedef Tizen::Base::UuId ContentId;

/**
 * @enum ContentType
 *
 * Defines the content type.
 *
 * @since	2.0
 */
enum ContentType
{
	CONTENT_TYPE_OTHER = 0,	/**< Other types */
	CONTENT_TYPE_IMAGE,		/**< An Image */
	CONTENT_TYPE_AUDIO,		/**< An Audio */
	CONTENT_TYPE_VIDEO,		/**< A Video */
	CONTENT_TYPE_ALL,			/**< @if OSPDEPREC The content type: all types @endif */ /**< @if OSPDEPREC @deprecated This enum field is deprecated as unified search will not be supported. @endif */
	CONTENT_TYPE_UNKNOWN		/**< An Unknown type */
};

/**
 * @enum ImageOrientationType
 *
 * Defines the orientation type of an image.
 *
 * @since 2.0
 */
enum ImageOrientationType
{
	IMAGE_ORIENTATION_TYPE_UNKNOWN = 0,		/**< An Unknown type */
	IMAGE_ORIENTATION_TYPE_NORMAL,				/**< Normal */
	IMAGE_ORIENTATION_TYPE_FLIP_HORIZONTAL,	/**< Flip horizontal */
	IMAGE_ORIENTATION_TYPE_ROTATE_180,			/**< Rotate 180 degree */
	IMAGE_ORIENTATION_TYPE_FLIP_VERTICAL,		/**< Flip vertical */
	IMAGE_ORIENTATION_TYPE_TRANSPOSE,			/**< Transpose */
	IMAGE_ORIENTATION_TYPE_ROTATE_90,			/**< Rotate 90 degree */
	IMAGE_ORIENTATION_TYPE_TRANSVERSE,			/**< Transverse */
	IMAGE_ORIENTATION_TYPE_ROTATE_270			/**< Rotate 270 degree */
};

/**
 * @enum DownloadNetworkType
 * Defines the download network type.
 * @since 2.1
 */
enum DownloadNetworkType
{
	DOWNLOAD_NETWORK_DATA_NETWORK = 1,	/**< The data network is allowed */
	DOWNLOAD_NETWORK_WIFI,			/*< The wifi network is allowed */
	DOWNLOAD_NETWORK_ALL = 100		/*< The all network types are allowed */
};

/**
 * @enum DownloadState
 *
 * Defines the download state.
 *
 * @since 2.0
 */
enum DownloadState
{
	DOWNLOAD_STATE_NONE = 0, 		/**< The download request does not exist */
	DOWNLOAD_STATE_QUEUED, 			/**< The download request is listed in a download queue */
	DOWNLOAD_STATE_DOWNLOADING, 	/**< The download request is in progress */
	DOWNLOAD_STATE_PAUSED, 			/**< The download request is in a paused state by user request */
	DOWNLOAD_STATE_CANCELLED, 		/**< The download request is cancelled by user request */
	DOWNLOAD_STATE_COMPLETED, 		/**< The download request is in a completed state */
	DOWNLOAD_STATE_FAILED 			/**< The download request has failed */
};

_OSP_EXPORT_ extern const wchar_t OSP_HOME[];
_OSP_EXPORT_ extern const wchar_t OSP_HOME_EXT[];
_OSP_EXPORT_ extern const wchar_t OSP_MEDIA_PHONE[];
_OSP_EXPORT_ extern const wchar_t OSP_MEDIA_MMC[];

} } // Tizen::Content

#endif  // _FCNT_TYPES_H_
