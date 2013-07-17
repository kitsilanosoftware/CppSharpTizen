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
 * @file			FMediaPlayerTypes.h
 * @brief			This is the header file for the enumerations of the Player class.
 *
 * This header file contains the declarations of the enumerations of the Player class.
 */

#ifndef _FMEDIA_PLAYER_TYPES_H_
#define _FMEDIA_PLAYER_TYPES_H_

namespace Tizen { namespace Media
{

#define MIN_PLAYER_VOLUME 0
#define MAX_PLAYER_VOLUME 100
#define DEFAULT_PLAYER_VOLUME 50

/**
 * @enum PlayerState
 *
 * Defines the state of the player.
 *
 * @since		2.0
 *
 * @see		Tizen::Media::Player::GetState()
 */
enum PlayerState
{
	PLAYER_STATE_INITIALIZED,       /**< The player is initialized */
	PLAYER_STATE_OPENING,           /**< The player opening behavior is processed */
	PLAYER_STATE_OPENED,            /**< The source is opened */
	PLAYER_STATE_ENDOFCLIP,         /**< The player has reached the end of the clip */
	PLAYER_STATE_STOPPED,           /**< The player has stopped and has no current play-time, but the media content is still opened and initialized */
	PLAYER_STATE_PAUSED,            /**< The player playback is paused */
	PLAYER_STATE_PLAYING,           /**< The player is playing the media content */
	PLAYER_STATE_CLOSED,            /**< The source is closed */
	PLAYER_STATE_ERROR,             /**< An error has occurred */

};

/**
 * @enum PlayerErrorReason
 *
 * Defines the player error reason.
 *
 * @since		2.0
 */
enum PlayerErrorReason
{
	PLAYER_ERROR_NONE,                      // Not defined
	PLAYER_ERROR_INVALID_DATA,              /**< The data is invalid */
	PLAYER_ERROR_CONNECTION_LOST,           /**< The connection is lost */
	PLAYER_ERROR_STREAMING_TIMEOUT,         /**< The streaming has timed out */
	PLAYER_ERROR_TRANSPORT,                 /**< The transport has failed */
	PLAYER_ERROR_SERVER,                    /**< The server has failed */
	PLAYER_ERROR_OUT_OF_MEMORY,             /**< The memory is insufficient*/
	PLAYER_ERROR_DEVICE_FAILED,             /**< The player device has failed */
	PLAYER_ERROR_RIGHT_EXPIRED,          	   /**< The content right has expired */
	PLAYER_ERROR_RIGHT_NO_LICENSE,          	/**< The content has no license */
	PLAYER_ERROR_RIGHT_FUTURE_USE,          	/**< The content right is for future use */
	PLAYER_ERROR_DISPLAY_RIGHT_VIOLATED,			/**< The display right is not valid for the specific output device @b Since: @b 2.1*/

};

}} // Tizen::Media

#endif
