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
 *	@file	FMediaVideoEncoder.h
 *	@brief	This is the header file for the %VideoEncoder class.
 *
 *	This header file contains the declarations of the %VideoEncoder class.
 */

#ifndef _FMEDIA_VIDEO_ENCODER_H_
#define _FMEDIA_VIDEO_ENCODER_H_

#include <FBase.h>
#include <FMediaTypes.h>

namespace Tizen { namespace Media
{

/**
 * @class VideoEncoder
 * @brief This class encodes a raw video stream into a compressed video data.
 *
 * @since		2.0
 *
 * The %VideoEncoder class encodes a raw video stream into a compressed video data. The video encoders such as H.263, MPEG4 Part 2 are supported.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_video.htm">Encoding and Decoding Video</a>.
 *
 * The following example demonstrates how to use the %VideoEncoder class in H.263 encoding.
 * @code
 *
 * #include <FBase.h>
 * #include <FIo.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Base::Collection;
 * using namespace Tizen::Io;
 * using namespace Tizen::Media;
 *
 * result
 * VideoEncoderSample(void)
 * {
 *	 VideoEncoder enc;
 *	 result r;
 *	 ByteBuffer srcBuf, dstBuf;
 *	 int width = 352;
 *	 int height = 288;
 *	 int bitRate = 512000; // 512 Kbps
 *	 int frameRate = 15;
 *	 MediaPixelFormat pixelFormat = MEDIA_PIXEL_FORMAT_YUV420P;
 *	 HashMap option;
 *	 byte* pBuf = null;
 *	 int srcBufSize = width * height * 3 / 2;
 *
 *	 option.Construct();
 *	 option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_WIDTH)), *(new Integer(width)));
 *	 option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_HEIGHT)), *(new Integer(height)));
 *	 option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_PIXEL_FORMAT)), *(new Integer(pixelFormat)));
 *	 option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_FRAME_RATE)), *(new Integer(frameRate)));
 *	 option.Add(*(new Integer(MEDIA_PROPERTY_VIDEO_BIT_RATE)), *(new Integer(bitRate)));
 *
 *	 pBuf = new byte[srcBufSize];
 *	 srcBuf.Construct(pBuf, 0, srcBufSize, srcBufSize);
 *	 dstBuf.Construct(width * height * 3 / 2);
 *
 *	 enc.Construct(CODEC_H263, &option);
 *
 *	 for (int i = 0; i < 255; i += 25)
 *	 {
 *		 // Fills source buffer with a gray color
 *		 memset(pBuf, i, width * height);					   // Y
 *		 memset(pBuf + width * height, 128, width * height / 4);	  // Cb
 *		 memset(pBuf + width * height * 5 / 4, 128, width * height / 4);  // Cr
 *
 *		 srcBuf.SetPosition(0);
 *		 srcBuf.SetLimit(srcBufSize);
 *
 *		 r = enc.Encode(srcBuf, dstBuf);
 *		 if (IsFailed(r))
 *		 {
 *			 break;
 *		 }
 *
 *		 // Adds code handling encoded data
 *
 *		 dstBuf.Clear();
 *	 }
 *
 *	 delete pBuf;
 *	 return r;
 * }
 *
 * @endcode
 *
 */
class _OSP_EXPORT_ VideoEncoder
	: public Tizen::Base::Object
{
public:
	/**
	 *	The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 *	@since		2.0
	 *
	 *	@remarks		 After creating an instance of this class, the Construct() method must be
	 *					 called explicitly to initialize this instance.
	 *	@see		Construct()
	 */
	VideoEncoder(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since		2.0
	 */
	virtual ~VideoEncoder(void);

	/**
	 *	Initializes an instance of %VideoEncoder with the specified parameters.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	type				The codec type
	 *	@param[in]	pOption				The <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_video.htm#encoding_video">optional parameters</a>
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_UNSUPPORTED_CODEC The specified encoder is not supported.
	 *	@exception	E_INVALID_ARG		A specified input parameter has invalid data.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient. 
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *	@remarks	The key type of the specified option is Tizen::Base::Integer and the value type varies depending
	 *			  on the key type.
	 *				The unsupported keys in @c pOption are ignored.
	 *				If specified @c pOption has an invalid value, @c E_INVALID_ARG is returned.
	 *  @remarks The supported codec types can vary depending on the device model or platform version.
	 */
	result Construct(CodecType type, const Tizen::Base::Collection::HashMap* pOption = null);

public:
	/**
	 *	Encodes the video data from the source buffer and stores the encoded data in the destination buffer.
	 *
	 *	@since		2.0
	 *
	 *	@return	 An error code
	 *	@param[in]	srcBuf					The source buffer that stores the raw video data
	 *	@param[out]	dstBuf					The destination buffer that stores the encoded video data
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified source or destination buffer is invalid or has insufficient memory.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@remarks	The destination buffer must have sufficient free space to store the encoded frame data.
	 *	@remarks	The position of the source buffer is moved to the end of the consumed data and the position of the destination buffer is moved to the end of the written data.
	 */
	result Encode(Tizen::Base::ByteBuffer& srcBuf, Tizen::Base::ByteBuffer& dstBuf);

	/**
	 *	Resets the internal state of the video encoder to process a new video stream.

	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *	@remarks	This method resets the properties that were set after the execution of the Construct() method.
	 */
	result Reset(void);

	/**
	 *	Sets the specified property value of this instance.
	 *
	 *	@since		2.0
	 *
	 *	@return		 An error code
	 *	@param[in]		key					The <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_video.htm#encoding_video">key</a> value to set
	 *	@param[in]		value				The property value to set
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE		 This instance is in an invalid state for this method.
	 *	@exception	E_OBJ_NOT_FOUND			The specified @c key is not found.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@remarks	The media property that has the value of type enum can be set using this method.
	 */
	result SetValue(MediaPropertyType key, int value);

	/**
	 *	Sets the specified property value of this instance.
	 *
	 *	@since		2.0
	 *
	 *	@return		 An error code
	 *	@param[in]		key					The <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_video.htm#encoding_video">key</a> value to set
	 *	@param[in]		value				The property value to set
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE		 This instance is in an invalid state for this method.
	 *	@exception	E_OBJ_NOT_FOUND			The specified @c key is not found.
	 *	@exception	E_INVALID_ARG			A specified input parameter is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@remarks	The media property that has the value of type enum can be set using this method.
	 */
	result SetValue(MediaPropertyType key, bool value);

	/**
	 *	Gets the properties supported by this instance.
	 *
	 *	@since		2.0
	 *
	 *	@return	 A list of the supported properties, @n
	 *				else @c null if no property is supported or if an exception occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY		 The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@exception	E_OBJ_NOT_FOUND			This instance does not support any property.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 *				The returned value must be deleted.
	 */
	Tizen::Base::Collection::IListT<MediaPropertyType>* GetSupportedPropertyListN(void) const;

	/**
	 *	Checks whether the specified property is supported.
	 *
	 *	@since		2.0
	 *
	 *	@return	 @c true if the property is supported, @n
	 *				else @c false
	 *	@param[in]	key					The <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_video.htm#encoding_video">key</a> value
	 *	@exception	E_SUCCESS		   The method is successful.
	 *	@exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *	@remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsPropertySupported(MediaPropertyType key) const;

	/**
	 * Gets a list of the supported codecs.
	 *
	 * @since		2.0
	 *
	 * @return     A list of the codecs supported by the %VideoEncoder class, @n
	 *             else @c null if an exception occurs
	 * @exception  E_SUCCESS             The method is successful.
	 * @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 * @remarks    The return value must be deleted by the caller.
	 */
	static Tizen::Base::Collection::IListT<CodecType>* GetSupportedCodecListN(void);

private:
	/**
	 *	The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 *	@since		2.0
	 *
	 */
	VideoEncoder(const VideoEncoder& enc);

	/**
	 *	The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 *	@since		2.0
	 *
	 */
	VideoEncoder& operator =(const VideoEncoder& enc);

	friend class _VideoEncoderImpl;
	class _VideoEncoderImpl* __pImpl;
};

}} // Tizen::Media

#endif
