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
* @file			FMediaTypes.h
* @brief		This is the header file for the media types.
*
* This header file contains the declarations of the media types.
*/
#ifndef _FMEDIA_MEDIA_TYPES_H_
#define _FMEDIA_MEDIA_TYPES_H_

#include <FMediaImageTypes.h>

namespace Tizen { namespace Media
{

/**
 * Defines a macro that is added to declare the four-character code.
 *
 * @since    2.0
 *
 * @param[in]     ch1					The first character
 * @param[in]     ch2					The second character
 * @param[in]     ch3					The third character
 * @param[in]     ch4					The fourth character
*/
#define FourCharCode(ch1, ch2, ch3, ch4)   ((unsigned int) (unsigned char) (ch1)) | \
	((unsigned int) (unsigned char) (ch2) << 8) | \
	((unsigned int) (unsigned char) (ch3) << 16) | \
	((unsigned int) (unsigned char) (ch4) << 24)

/**
 * @enum    CodecType
 *
 * Defines the types of codec.
 *
 * @since   2.0
 *
 * @see         FourCharCode(ch1, ch2, ch3, ch4)
 */
enum CodecType
{
	CODEC_NONE = 0x00000000,                    /**< No codec */
	// Audio codecs
	CODEC_LPCM = FourCharCode('L', 'P', 'C', 'M'),      /**< The Linear PCM codec */
	CODEC_ALAW = FourCharCode('A', 'L', 'A', 'W'),  /**< The G.711 A-Law codec */
	CODEC_ULAW = FourCharCode('u', 'L', 'A', 'W'),      /**< The G.711 u-Law codec */
	CODEC_IMA_ADPCM = FourCharCode('I', 'M', 'A', 'D'), /**< The IMA ADPCM codec */
	CODEC_MS_ADPCM = FourCharCode('M', 'S', 'A', 'D'), /**< The MS ADPCM codec */
	CODEC_AMR_NB = FourCharCode('A', 'M', 'R', ' '), /**< The AMR-NB codec */
	CODEC_FLAC = FourCharCode('F', 'L', 'A', 'C'),      /**< The FLAC codec */
	CODEC_MP3 = FourCharCode('M', 'P', '3', ' '),       /**< The MP3 codec */
	CODEC_AAC = FourCharCode('A', 'A', 'C', ' '),       /**< The AAC codec */
	CODEC_HEAAC = FourCharCode('A', 'A', 'C', 'H'), /**< The Enhanced AAC codec */
	CODEC_HEAAC_V2 = FourCharCode('A', 'A', 'C', 'P'), /**< The Enhanced AAC V2 codec */
	CODEC_AC3 = FourCharCode('A', 'C', '-', '3'),       /**< The AC-3 codec */
	CODEC_VORBIS = FourCharCode('V', 'O', 'R', 'B'), /**< The VORBIS codec */
	CODEC_WMA = FourCharCode('W', 'M', 'A', ' '),       /**< The WMA codec */
	CODEC_MIDI = FourCharCode('M', 'I', 'D', 'I'),      /**< The MIDI codec */
	// Video codecs
	CODEC_H263 = FourCharCode('H', '2', '6', '3'),      /**< The H.263 codec */
	CODEC_MPEG4 = FourCharCode('M', 'P', 'G', '4'), /**< The MPEG4 codec */
	CODEC_H264 = FourCharCode('H', '2', '6', '4'),      /**< The H.264 codec */
	CODEC_THEORA = FourCharCode('T', 'H', 'R', 'A'), /**< The THEORA codec */
	CODEC_WMV = FourCharCode('W', 'M', 'V', ' '),       /**< The WMV codec */
	// Image codecs
	CODEC_JPEG = FourCharCode('J', 'P', 'E', 'G'),      /**< The JPEG codec */
	CODEC_PNG = FourCharCode('P', 'N', 'G', ' '),       /**< The PNG codec */
	CODEC_GIF = FourCharCode('G', 'I', 'F', ' '),           /**< The GIF codec */

	CODEC_UNKNOWN = 0xFFFFFFFE,             /**< The unknown codec */
	CODEC_MAX = 0xFFFFFFFF                        // Max
};

/**
 * @enum    MediaContainerType
 *
 * Defines the various container types of the media.
 *
 * @since   2.0
 *
 * @see         FourCharCode(ch1, ch2, ch3, ch4)
 */
enum MediaContainerType
{
	MEDIA_CONTAINER_NONE = 0x00000000,                  /**< No container */
	MEDIA_CONTAINER_WAV = FourCharCode('W', 'A', 'V', ' '), /**< The WAVE container */
	MEDIA_CONTAINER_AMR = FourCharCode('A', 'M', 'R', ' '), /**< The AMR container */
	MEDIA_CONTAINER_AAC = FourCharCode('A', 'A', 'C', ' '),     /**< The AAC container */
	MEDIA_CONTAINER_MP3 = FourCharCode('M', 'P', '3', ' '),     /**< The MP3 container */
	MEDIA_CONTAINER_FLAC = FourCharCode('F', 'L', 'A', 'C'), /**< The FLAC container */
	MEDIA_CONTAINER_3GP = FourCharCode('3', 'G', 'P', ' '),     /**< The 3GP container */
	MEDIA_CONTAINER_MP4 = FourCharCode('M', 'P', '4', ' '),     /**< The MP4 container */
	MEDIA_CONTAINER_AVI = FourCharCode('A', 'V', 'I', ' '),     /**< The AVI container */
	MEDIA_CONTAINER_ASF = FourCharCode('A', 'S', 'F', ' '),     /**< The ASF container */
	MEDIA_CONTAINER_MKV = FourCharCode('M', 'K', 'V', ' '), /**< The MKV container */
	MEDIA_CONTAINER_MOV = FourCharCode('M', 'O', 'V', ' '), /**< The MOV container */
	MEDIA_CONTAINER_OGG = FourCharCode('O', 'G', 'G', ' '), /**< The OGG container */
	MEDIA_CONTAINER_UNKNOWN = 0xFFFFFFFE,           /**< The unknown container */
	MEDIA_CONTAINER_MAX = 0xFFFFFFFF                  // Max
};

/**
 *	@enum	MediaPropertyType
 *
 *	Defines the various property types of the media.
 *
 *	@since	2.0
 */
enum MediaPropertyType
{
	MEDIA_PROPERTY_VIDEO_WIDTH = 0x0001,            /**< The video width (int) */
	MEDIA_PROPERTY_VIDEO_HEIGHT,                    /**< The video height (int) */
	MEDIA_PROPERTY_VIDEO_FRAME_RATE,                /**< The video frame rate (float or int) */
	MEDIA_PROPERTY_VIDEO_PIXEL_FORMAT,              /**< The video pixel format (::MediaPixelFormat) */
	MEDIA_PROPERTY_VIDEO_BIT_RATE,                  /**< The video bit rate (int) */

	MEDIA_PROPERTY_VIDEO_QUANTIZATION_PARAMETER = 0x0100, /**< The video quantization level (int) */
	MEDIA_PROPERTY_VIDEO_QUANTIZATION_MIN,          /**< The minimum quantization level (int) */
	MEDIA_PROPERTY_VIDEO_QUANTIZATION_MAX,          /**< The maximum quantization level (int) */
	MEDIA_PROPERTY_VIDEO_GOP_SIZE,                  /**< The video Group of Picture (GOP) size (int) */
	MEDIA_PROPERTY_VIDEO_PROFILE,                   /**< The video profile (int) */
	MEDIA_PROPERTY_VIDEO_GOB_SIZE,                  /**< The video Group of Block (GOB) size (int) */
	MEDIA_PROPERTY_VIDEO_PACKET_SIZE,               /**< The video packet size in byte (int) */
	MEDIA_PROPERTY_VIDEO_SLICE_SIZE_MODE,           /**< The slice mode (::VideoSliceMode) */
	MEDIA_PROPERTY_VIDEO_SLICE_SIZE_IN_BYTE,        /**< The size of a video slice in bytes (int) */
	MEDIA_PROPERTY_VIDEO_SLICE_SIZE_IN_MACROBLOCK,  /**< The number of macroblocks in a slice (int) */
	MEDIA_PROPERTY_VIDEO_REFERENCE_PICTURE_COUNT,   /**< The count of reference picture (int) */

	MEDIA_PROPERTY_VIDEO_USE_FRAME_SKIP = 0x0200,   /**< The media property type that uses the frame skip algorithm (int) */
	MEDIA_PROPERTY_VIDEO_USE_DEBLOCKING_FILTER,     /**< The media property type that uses the deblocking filter (int) @n
			                                             It enables or disables the deblocking filter. */
	MEDIA_PROPERTY_VIDEO_USE_AC_PREDICTION,         /**< The media property type that uses the AC prediction mode (int) */
	MEDIA_PROPERTY_VIDEO_USE_HEADER_EXTENSION_CODE, /**< The media property type that uses the header extension code mode (int) */

	MEDIA_PROPERTY_VIDEO_FORCE_SKIP_FRAME = 0x0300, /**< The media property type that skips the encoding or decoding of the current frame (int) by force */
	MEDIA_PROPERTY_VIDEO_FORCE_INTRA_CODING,        /**< The media property type that uses the intra coding for the current frame (int) by force */

	MEDIA_PROPERTY_VIDEO_H264_USE_ANNEX_B = 0x0400, /**< The media property type that uses H.264 Annex B for output bitstream format (int) */


	MEDIA_PROPERTY_AUDIO_SAMPLE_RATE = 0x1000,      /**< The audio sample rate (int) */
	MEDIA_PROPERTY_AUDIO_BIT_RATE,                  /**< The audio bit rate (int) */
	MEDIA_PROPERTY_AUDIO_CHANNEL_TYPE,              /**< The audio channel type (::AudioChannelType) */
	MEDIA_PROPERTY_AUDIO_SAMPLE_TYPE,               /**< The audio sample type (::AudioSampleType) */

};

/**
 *  @enum VideoSliceMode
 *
 *  Defines the slice mode of the video data.
 *
 *  @since	2.0
 */
enum VideoSliceMode
{
	VIDEO_SLICE_MODE_NONE = 0x00,           /**< The no slicing mode */
	VIDEO_SLICE_MODE_FIXED_MACROBLOCK,      /**< The slicing of a video by a fixed number of macroblocks */
	VIDEO_SLICE_MODE_FIXED_BYTE,            /**< The slicing of a video by a fixed number of bytes */
};

/**
 *  @enum H263ProfileType
 *
 *  Defines the profile types of the H.263 video codec.
 *
 *  @since	2.0
 */
enum H263ProfileType
{
	H263_PROFILE_BASELINE = 0x00,           /**< The baseline profile */
	H263_PROFILE_VERSION_2 = 0x03,          /**< The version 2 interactive and streaming wireless profile */
};


};
};   // Tizen::Media


#endif
