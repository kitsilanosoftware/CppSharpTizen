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
 * @file   FMediaAudioDecoder.h
 * @brief  This is the header file for the %AudioDecoder class.
 *
 * This header file contains the declarations of the %AudioDecoder class.
 */

#ifndef _FMEDIA_AUDIO_DECODER_H_
#define _FMEDIA_AUDIO_DECODER_H_

#include <FBase.h>
#include <FMediaAudioTypes.h>
#include <FMediaTypes.h>

namespace Tizen { namespace Media
{

/**
 * @class AudioDecoder
 * @brief This class decodes a compressed audio stream to a raw audio data.
 *
 * @since		2.0
 *
 * @remarks
 * Source data of AAC and AMR decoder must be raw compressed data without header.
 *
 *  The %AudioDecoder class decodes a compressed audio stream to a raw audio data.
 *  The audio decoding formats, such as CODEC_MP3, CODEC_AAC, and CODEC_AMR_NB, are supported.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_audio.htm">Encoding and Decoding Audio</a>.
 *
 * The following example demonstrates how to use the %AudioDecoder class in MP3 decoding.
 *
 *
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
 * #define DST_BUF_SIZE   (1024*16)
 *
 * result
 * AudioDecoderSample(void)
 * {
 *	 AudioDecoder dec;
 *	 result r;
 *	 ByteBuffer srcBuf, dstBuf;
 *	 File srcFile;
 *	 FileAttributes attr;
 *	 int sampleRate;
 *	 AudioChannelType channelType;
 *	 AudioSampleType sampleType;
 *	 String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.mp3";
 *
 *	 // Loads src file into buffer
 *	 File::GetAttributes(filePath, attr);
 *	 srcBuf.Construct(attr.GetFileSize());
 *	 srcFile.Construct(filePath, "rb");
 *	 srcFile.Read(srcBuf);
 *	 srcBuf.Flip();  // Sets the position of source buffer to zero
 *
 *	 // Adds code that skips ID3 tag in srcBuf
 *
 *	 dstBuf.Construct(DST_BUF_SIZE);
 *
 *	 dec.Construct(CODEC_MP3);
 *	 r = dec.Probe(srcBuf, sampleType, channelType, sampleRate);
 *	 if (IsFailed(r))
 *	 {
 *		 return r;
 *	 }
 *
 *	 while (srcBuf.GetRemaining() > 0)
 *	 {
 *		 r = dec.Decode(srcBuf, dstBuf);
 *		 if (IsFailed(r))
 *		 {
 *			 break;
 *		 }
 *
 *		 // Adds code handling decoded data
 *
 *		 dstBuf.Clear();
 *	 }
 *
 *	 return r;
 * }
 * @endcode
 */

class _OSP_EXPORT_ AudioDecoder
	: public Tizen::Base::Object
{
public:
	/**
	 *	The object is not fully constructed after this constructor is called. @n
	 * 	For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 *	@since		2.0
	 *
	 */
	AudioDecoder(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since		2.0
	 */
	virtual ~AudioDecoder(void);

	/**
	 *	Initializes this instance of %AudioDecoder with the specified parameters. @n
	 *  The following example demonstrates how to use the %Construct() method as a simple decoder construction with optional parameters.
	 *  @code
	 *
	 * result OpenAacDecoder(void)
	 * {
	 *	 AudioDecoder dec;
	 *	 result r;
	 *	 HashMap option;
	 *
	 *	 option.Construct();
	 *	 option.Add(*(new Integer(MEDIA_PROPERTY_AUDIO_CHANNEL_TYPE)), *(new Integer(AUDIO_CHANNEL_TYPE_STEREO)));
	 *	 option.Add(*(new Integer(MEDIA_PROPERTY_AUDIO_SAMPLE_RATE)), *(new Integer(44100)));
	 *
	 *	 r = dec.Construct(CODEC_AAC, &option);
	 *	 if (IsFailed(r))
	 *	 {
	 *		goto CATCH;
	 *	 }
	 *
	 *	return E_SUCCESS;
	 * CATCH:
	 *	 return r;
	 * }
	 * @endcode
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	type				The codec type
	 *	@param[in]	pOption				The <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_audio.htm#decoding_audio">optional parameters</a>
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_UNSUPPORTED_CODEC The specified decoder is not supported.
	 *	@exception	E_OUT_OF_RANGE		A specified input parameter has a value that is out of range.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient. 
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *	@remarks	The key type of the specified option is Tizen::Base::Integer, and the value type varies depending on the key type.
	 */
	result Construct(CodecType type, const Tizen::Base::Collection::HashMap* pOption = null);

	/**
	 *
	 *	Probes whether the audio data can be decoded.
	 *
	 *	@since		2.0
	 *
	 *	@return	 An error code
	 *	@param[in]	srcBuf					The source buffer that stores the compressed audio data
	 *	@param[out]	sampleType				The sample type of the decoded audio sample
	 *	@param[out]	channelType				The channel type of the decoded audio sample
	 *	@param[out]	sampleRate				The sample rate of the decoded audio sample
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			A specified source buffer is invalid.
	 *	@exception	E_UNSUPPORTED_FORMAT	The input data is not in a supported format.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient to decode the sample.
	 *	@exception  E_SYSTEM				A system error has occurred.
	 *	@remarks	This method resets the internal state of an audio decoder.
	 */
	result Probe(const Tizen::Base::ByteBuffer& srcBuf, AudioSampleType& sampleType, AudioChannelType& channelType, int& sampleRate);

	/**
	 *
	 *	Decodes the audio data from the source buffer and stores the decoded data into a destination buffer. @n
	 *	The %AudioDecoder class reads and decodes the audio data from the source buffer
	 *	and it also writes the decoded audio data into the destination buffer. @n
	 *  The position of the source buffer is moved to the end of the consumed data and the position of the destination buffer is moved to the end of the written data.
	 *
	 *	@since		2.0
	 *
	 *	@return	 An error code
	 *	@param[in]	srcBuf			The source buffer that stores the compressed audio data
	 *	@param[out]	dstBuf			The destination buffer that stores the decoded audio data
	 *	@exception	E_SUCCESS		The method is successful.
	 *	@exception	E_INVALID_ARG			A specified source or destination buffer is invalid.
	 *	@exception	E_UNSUPPORTED_FORMAT	The input data is not in a supported format.
	 *	@exception	E_OUT_OF_MEMORY			The specified destination buffer is insufficient to store the decoded data.
	 *	@exception  E_SYSTEM				A system error has occurred.
	 */
	result Decode(Tizen::Base::ByteBuffer& srcBuf, Tizen::Base::ByteBuffer& dstBuf);

	/**
	 *	Resets the internal state of the audio decoder to process a new audio stream.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 */
	result Reset(void);

	/**
	 *	Gets the specified property type value of this instance.
	 *
	 *	@since		2.0
	 *
	 *	@return		 An error code
	 *	@param[in]		key					The <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_audio.htm#decoding_audio">key</a> for which the value is obtained
	 *	@param[out]		value			The obtained property value
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OBJ_NOT_FOUND			The specified @c key is not found.
	 *	@exception	E_INVALID_ARG			The specified @c key is not supported.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@remarks	The property whose value type is enum can be obtained using this method.
	 */
	result GetValue(MediaPropertyType key, int& value) const;

	/**
	 *	Gets the supported properties of this instance.
	 *
	 *	@since		2.0
	 *
	 *	@return	 A list of supported properties, @n
	 *				else @c null if no property is supported or if an exception occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY		 	The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 *	@exception	E_OBJ_NOT_FOUND			This instance does not support any property.
	 *	@remarks	
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 *				- The return value must be deleted.
	 */
	Tizen::Base::Collection::IListT<MediaPropertyType>* GetSupportedPropertyListN(void) const;

	/**
	 *	Checks whether the specified property type is supported.
	 *
	 *	@since		2.0
	 *
	 *	@return	 @c true if the property is supported, @n
	 *				else @c false
	 *	@param[in]		key				The <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_audio.htm#decoding_audio">key</a> for which the value is obtained
	 *	@exception	E_SUCCESS		    The method is successful.
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
	* @return     A list of the codecs supported by the %AudioDecoder class, @n
	*             else @c null if an exception occurs
	* @exception  E_SUCCESS             The method is successful.
	* @exception  E_OUT_OF_MEMORY       The memory is insufficient.
	* @remarks
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- The return value must be deleted by the caller.
	*/
	static Tizen::Base::Collection::IListT<CodecType>* GetSupportedCodecListN(void);

private:
	/**
	*	The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	*	@since		2.0
	*
	*/
	AudioDecoder(const AudioDecoder& rhs);
	/**
	*	The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	*	@since		2.0
	*
	*/
	AudioDecoder& operator =(const AudioDecoder& rhs);

	friend class _AudioDecoderImpl;
	class _AudioDecoderImpl* __pImpl;
};

}} // Tizen::Media

#endif // _FMEDIA_AUDIODECODER_H_
