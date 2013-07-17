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
 * @file	FMediaVideoDecoder.h
 * @brief	This is the header file for the %VideoDecoder class.
 *
 * This header file contains the declarations of the %VideoDecoder class.
 */

#ifndef _FMEDIA_VIDEO_DECODER_H_
#define _FMEDIA_VIDEO_DECODER_H_

#include <FBase.h>
#include <FMediaTypes.h>

namespace Tizen { namespace Media
{

/**
 * @class VideoDecoder
 * @brief This class decodes a compressed video stream into a raw video data.
 *
 * @since		2.0
 *
 * The %VideoDecoder class decodes a compressed video stream into a raw video data.
 * The video decoding formats, such as CODEC_H263, CODEC_MPEG4, and CODEC_H264 are supported.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_video.htm">Encoding and Decoding Video</a>.
 *
 * The following example demonstrates how to use the %VideoDecoder class in H.264 decoding.
 * @code
 *
 * #include <FBase.h>
 * #include <FIo.h>
 * #include <FApp.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Base::Collection;
 * using namespace Tizen::Io;
 * using namespace Tizen::Media;
 *
 * result
 * VideoDecoderSample(void)
 * {
 *	 VideoDecoder dec;
 *	 result r;
 *	 ByteBuffer srcBuf, dstBuf;
 *	 File srcFile;
 *	 bool gotFrame;
 *	 int width, height;
 *	 MediaPixelFormat pixelFormat;
 *	 String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.h264";
 *	 FileAttributes attr;
 *
 *	 // Loads data from src file
 *	 File::GetAttributes(filePath, attr);
 *	 srcBuf.Construct(attr.GetFileSize());
 *	 srcFile.Construct(filePath, "rb");
 *	 srcFile.Read(srcBuf);
 *	 srcBuf.Flip();  // Sets the position of source buffer to zero
 *
 *	 dec.Construct(CODEC_H264);
 *	 r = dec.Probe(srcBuf, width, height, pixelFormat);
 *	 if (IsFailed(r) || (pixelFormat != MEDIA_PIXEL_FORMAT_YUV420P))
 *	 {
 *		 return E_INVALID_DATA;
 *	 }
 *
 *	 dstBuf.Construct(width * height * 3 / 2);
 *
 *	 while (srcBuf.GetRemaining() > 0)
 *	 {
 *		 gotFrame = false;
 *		 r = dec.Decode(srcBuf, dstBuf, gotFrame);
 *		 if (IsFailed(r))
 *		 {
 *			 return r;
 *		 }
 *
 *		 if (gotFrame)
 *		 {
 *			 // Adds code handling decoded frame
 *		 }
 *		 dstBuf.Clear();
 *	 }
 *
 *	 return E_SUCCESS;
 * }
 *
 * @endcode
 *
 *
 */
class _OSP_EXPORT_ VideoDecoder
	: public Tizen::Base::Object
{
public:
	/**
	 *	The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 *	@since		2.0
	 *
	 */
	VideoDecoder(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since		2.0
	 */
	virtual ~VideoDecoder(void);

	/**
	 *	Initializes this instance of %VideoDecoder with the specified parameters.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	type				The codec type
	 *	@param[in]	pOption				The <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_video.htm#decoding_video">optional parameters</a>
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_UNSUPPORTED_CODEC The specified decoder is not supported.
	 *	@exception	E_OUT_OF_RANGE		A specified input parameter has a value that is out of range.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient. 
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *	@remarks	The key type of the specified option is Tizen::Base::Integer and the value type varies depending on the key type.
	 */
	result Construct(CodecType type, const Tizen::Base::Collection::HashMap* pOption = null);

public:
	/**
	 *	Probes whether the video data can be decoded and sets the width, height, and pixel format of the video data.
	 *
	 *	@since		2.0
	 *
	 *	@return	 An error code
	 *	@param[in]	srcBuf					The source buffer that stores the compressed video data
	 *	@param[out]	width					The width of the decoded video frame
	 *	@param[out]	height					The height of the decoded video frame
	 *	@param[out]	pixelFormat				The pixel format of the decoded video frame
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c srcBuf is invalid.
	 *	@exception	E_UNSUPPORTED_FORMAT	The input data is not in a supported format.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception  E_SYSTEM				A system error has occurred.
	 *	@remarks	This method resets the internal state of the video decoder.
	 */
	result Probe(const Tizen::Base::ByteBuffer& srcBuf, int& width, int& height, MediaPixelFormat& pixelFormat);


	/**
	 *	Decodes the video data from the source buffer and stores the decoded data into the destination buffer.
	 *
	 *	@since		2.0
	 *
	 *	@return	 An error code
	 *	@param[in]	srcBuf					The source buffer that stores the compressed video data
	 *	@param[out]	dstBuf					The destination buffer that stores the decoded video data
	 *	@param[out]	gotFrame			    @c true when a frame is decoded, @n
	 *									    else @c false
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c srcBuf or @c dstBuf is invalid.
	 *	@exception	E_UNSUPPORTED_FORMAT	The input data is not in a supported format.
	 *	@exception	E_OUT_OF_MEMORY			The destination buffer has insufficient memory.
	 *  @exception	E_DIMENSION_CHANGED		The dimension of video stream has changed.
	 *	@exception  E_SYSTEM				A system error has occurred.
	 *	@remarks
	 *			  - The destination buffer must have sufficient free space to store the decoded frame data.
	 *			  - The decoder starts the decoding of the frame from the current position of the source buffer,
	 *				and moves the position of the source buffer to the end of the consumed data.
	 *				The decoder also fills the destination buffer with the decoded frame from the current position of the destination buffer,
	 *				and moves the position of the destination buffer to the end of the decoded frame.
	 *			  - When the first decoding begins, the @c E_DIMENSION_CHANGED exception can occur.
	 *				An exception can also occur when the dimension of the video frame in the bitstream has changed.
	 *				An application should increase the size of @c dstBuf if the @c dstBuf cannot hold the video frame with new dimensions.
	 *				The video frame can be received even if the result is @c E_DIMENSION_CHANGED.
	 *				The application should check the @c position of the destination buffer and the value of @c gotFrame
	 *				when the result is @c E_DIMENSION_CHANGED.
	 *			  - The H.264 video decoder returns data with the width and height in multiples of 16.
	 *				The application should detect the width and height of the frame and crop the decoder's output data if the original dimension is not a multiple of @c 16.
	 *	@see Probe()
	 */
	result Decode(Tizen::Base::ByteBuffer& srcBuf, Tizen::Base::ByteBuffer& dstBuf, bool& gotFrame);

	/**
	 *	Resets the internal state of the video decoder to process a new video stream.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 */
	result Reset(void);


	/**
	 *	Gets the specified property value of this instance.
	 *
	 *	@since		2.0
	 *
	 *	@return		 An error code
	 *	@param[in]		key					The <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_video.htm#decoding_video">key</a> whose value is required
	 *	@param[out]		value				The obtained property value
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE		    This instance is in an invalid state for this method.
	 *	@exception	E_OBJ_NOT_FOUND		    The specified @c key is not found.
	 *	@exception	E_INVALID_ARG			The specified @c key is not supported.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@remarks	The property whose value is of type enum can be obtained by using this method.
	 */
	result GetValue(MediaPropertyType key, int& value) const;


	/**
	 *	Gets the specified property value of this instance.
	 *
	 *	@since		2.0
	 *
	 *	@return		 An error code
	 *	@param[in]		key					The <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_video.htm#decoding_video">key</a> whose value is required
	 *	@param[out]		value				The obtained property value
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_STATE			 This instance is in an invalid state for this method.
	 *	@exception	E_OBJ_NOT_FOUND		The specified @c key is not found.
	 *	@exception	E_INVALID_ARG			The specified @c key is not supported.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@remarks	The property whose value is of type enum can be obtained using this method.
	 */
	result GetValue(MediaPropertyType key, float& value) const;

	/**
	 *	Gets the supported properties of this instance.
	 *
	 *	@since		2.0
	 *
	 *	@return	 A list of supported properties, @n
	 *				else @c null if no property is supported or if an exception occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY		 The memory is insufficient.
	 *	@exception	E_OBJ_NOT_FOUND			This instance does not support any property.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@remarks
	 *			  - The specific error code can be accessed using the GetLastResult() method.
	 *			  - The return value must be deleted.
	 */
	Tizen::Base::Collection::IListT<MediaPropertyType>* GetSupportedPropertyListN(void) const;

	/**
	 *	Checks whether the specified property is supported.
	 *
	 *	@since		2.0
	 *
	 *	@return	 @c true if the property is supported, @n
	 *				else @c false
	 *	@param[in]	key					The <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_video.htm#decoding_video">key</a> whose value is required
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
	 * @return     A list of the codecs supported by the %VideoDecoder class, @n
	 *             else @c null if an exception occurs
	 * @exception  E_SUCCESS             The method is successful.
	 * @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	 * @remarks
	 *			 - The specific error code can be accessed using the GetLastResult() method.
	 *			 - The return value must be deleted by the caller.
	 */
	static Tizen::Base::Collection::IListT<CodecType>* GetSupportedCodecListN(void);


private:
	/**
	*	The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	*	@since		2.0
	*
	*/
	VideoDecoder(const VideoDecoder& dec);
	/**
	*	The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	*	@since		2.0
	*
	*/
	VideoDecoder& operator =(const VideoDecoder& dec);

	friend class _VideoDecoderImpl;
	class _VideoDecoderImpl* __pImpl;
};

}} // Tizen::Media


#endif
