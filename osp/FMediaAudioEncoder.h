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
 * @file	FMediaAudioEncoder.h
 * @brief	This is the header file for the %AudioEncoder class.
 *
 * This header file contains the declarations of the %Tizen::Media::AudioEncoder class.
 */

#ifndef _FMEDIA_AUDIO_ENCODER_H_
#define _FMEDIA_AUDIO_ENCODER_H_

#include <FBase.h>
#include <FMediaAudioTypes.h>
#include <FMediaTypes.h>

namespace Tizen { namespace Media
{

/**
 * @class AudioEncoder
 * @brief This class encodes raw audio data into compressed audio stream.
 *
 * @since		2.0
 *
 * The %AudioEncoder class encodes raw audio data into compressed audio stream.
 * It supports the audio encoding formats such as CODE_AAC and CODEC_AMR_NB. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_audio.htm">Encoding and Decoding Audio</a>. @n
 *
 * The following example demonstrates how to use the %AudioEncoder class in Advanced Audio Coding (AAC) encoding.
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
 * #define DST_BUF_SIZE   (1024*8)
 *
 * result
 * AudioEncoderSample(void)
 * {
 *	 AudioEncoder enc;
 *	 result r;
 *	 ByteBuffer srcBuf, dstBuf;
 *	 File srcFile;
 *	 FileAttributes attr;
 *	 int sampleRate = 44100;
 *	 AudioChannelType channelType = AUDIO_CHANNEL_TYPE_STEREO;
 *	 int bitRate = 128000; // 128Kbps
 *	 HashMap option;
 *	 String filePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/test.wav";
 *
 *	 option.Construct();
 *	 option.Add(*(new Integer(MEDIA_PROPERTY_AUDIO_CHANNEL_TYPE)), *(new Integer(channelType)));
 *	 option.Add(*(new Integer(MEDIA_PROPERTY_AUDIO_SAMPLE_RATE)), *(new Integer(sampleRate)));
 *	 option.Add(*(new Integer(MEDIA_PROPERTY_AUDIO_BIT_RATE)), *(new Integer(bitRate)));
 *
 *	 // Loads src file into buffer
 *	 File::GetAttributes(filePath, attr);
 *	 srcBuf.Construct(attr.GetFileSize());
 *	 srcFile.Construct(filePath, L"rb");
 *	 srcFile.Read(srcBuf);
 *	 srcBuf.Flip();  // Sets the position of source buffer to zero
 *
 *	 // Adds code that skips WAV header in srcBuf
 *
 *	 dstBuf.Construct(DST_BUF_SIZE);
 *
 *	 enc.Construct(CODEC_AAC, &option);
 *
 *	 while (srcBuf.GetRemaining() > 0)
 *	 {
 *		 r = enc.Encode(srcBuf, dstBuf);
 *		 if (IsFailed(r))
 *		 {
 *			 break;
 *		 }
 *		 // Adds code handling encoded data
 *
 *		 dstBuf.Clear();
 *	 }
 *
 *	 return r;
 * }
 * @endcode
 *
 */
class _OSP_EXPORT_ AudioEncoder
	: public Tizen::Base::Object
{
public:
	/**
	 *	The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 *	@since		2.0
	 *
	 *	@remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 *	@see		Construct()
	 */
	AudioEncoder(void);

	/**
	 *	This destructor overrides Tizen::Base::Object::~Object().
	 *
	 *	@since		2.0
	 */
	virtual ~AudioEncoder(void);

	/**
	 *	Initializes this instance of %AudioEncoder with the specified parameters.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@param[in]	type				The codec type
	 *	@param[in]	pOption				The <a href="../org.tizen.native.appprogramming/html/guide/media/encoding_decoding_audio.htm#encoding_audio">optional parameters</a>
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_UNSUPPORTED_CODEC The specified encoder is not supported.
	 *	@exception	E_OUT_OF_RANGE		A specified input parameter has a value that is out of range.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient. 
	 *	@exception	E_SYSTEM			A system error has occurred.
	 *	@remarks	The key type of the specified option is Tizen::Base::Integer, and the value type varies depending on the key type.
	 */
	result Construct(CodecType type, const Tizen::Base::Collection::HashMap* pOption = null);


public:
	/**
	 *	Encodes the audio data from the source buffer and stores the encoded data into the destination buffer. @n
	 *	The %AudioEncoder class reads the audio data from the source buffer
	 *  and it writes the encoded audio data into the destination buffer.
	 *  The position of the source buffer is moved to the end of the consumed data and the position of the destination buffer is moved to the end of the written data.
	 *	If there is no space in the destination buffer, the encoder returns @c E_INVALID_ARG.
	 *
	 *	@since		2.0
	 *
	 *	@return	 An error code
	 *	@param[in]	srcBuf					The source buffer that stores the uncompressed audio data
	 *	@param[out]	dstBuf					The destination buffer that stores the encoded audio data
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified source or destination buffer is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The specified destination buffer is not sufficient to store the decoded data.
	 *	@exception  E_SYSTEM				A system error has occurred.
	 */
	result Encode(Tizen::Base::ByteBuffer& srcBuf, Tizen::Base::ByteBuffer& dstBuf);

	/**
	 *	Resets the internal state of the audio encoder to process a new audio stream.
	 *
	 *	@since		2.0
	 *
	 *	@return		An error code
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 */
	result Reset(void);

	/**
	* Gets a list of the supported codecs.
	*
	* @since		2.0
	*
	* @return     A list of the codecs supported by the %AudioEncoder class, @n
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
	AudioEncoder(const AudioEncoder& enc);

	/**
	 *	The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 *	@since		2.0
	 *
	 */
	AudioEncoder& operator =(const AudioEncoder& enc);

	friend class _AudioEncoderImpl;
	class _AudioEncoderImpl* __pImpl;
};

}} // Tizen::Media


#endif
