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
 * @file    FUixSpeechTextToSpeech.h
 * @brief   This is the header file for the %TextToSpeech class.
 *
 * This header file contains the declarations of the %TextToSpeech class.
 */

#ifndef _FUIX_SPEECH_TEXT_TO_SPEECH_H_
#define _FUIX_SPEECH_TEXT_TO_SPEECH_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FUixSpeechITextToSpeechEventListener.h>
#include <FUixSpeechTextToSpeechTypes.h>

namespace Tizen { namespace Base
{
	class String;
}}
namespace Tizen { namespace Base { namespace Collection
{
	class IList;
}}}
namespace Tizen { namespace Locales
{
	class Locale;
}}

namespace Tizen { namespace Uix { namespace Speech
{

class _TextToSpeechImpl;

/**
* @class    TextToSpeech
* @brief    This class is used to convert normal language text into speech.
*
* @since 2.0
*
* @remarks  @b Header @b %file: @b \#include @b <FUix.h> @n
*           @b Library : @b osp-speech-tts
*
* The %TextToSpeech class is used to convert normal language text into speech. @n
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/text_to_speech.htm">Text-To-Speech</a>.
*
* The following example demonstrates how to use the %TextToSpeech class. @n
* In the example, the Speak() method is called after invoking the ITextToSpeechEventListener::OnTextToSpeechInitialized() method.
*
* @code
*   //Sample code for TextToSpeechSample.h
*   #include <FUix.h>
*
*   using namespace Tizen::Uix::Speech;
*
*     class TextToSpeechSample : public ITextToSpeechEventListener
*     {
*         public:
*             TextToSpeechSample(void);
*             virtual ~TextToSpeechSample(void);
*
*             bool Initialize(void);
*             bool Speak(void);
*
*             virtual void OnTextToSpeechInitialized(void);
*             virtual void OnTextToSpeechStatusChanged(Tizen::Uix::Speech::TextToSpeechStatus status);
*             virtual void OnTextToSpeechErrorOccurred(Tizen::Uix::Speech::TextToSpeechError error);
*             virtual void OnTextToSpeechCompleted();
*
*         private:
*             Tizen::Uix::Speech::TextToSpeech* __pTts;
*     };
*
*     //Sample code for TextToSpeechSample.cpp
*     #include "TextToSpeechSample.h"
*
*     TextToSpeechSample::TextToSpeechSample(void)
*         : __pTts(null)
*     {
*     }
*
*     TextToSpeechSample::~TextToSpeechSample(void)
*     {
*     }
*
*     void TextToSpeechSample::OnTextToSpeechInitialized(void)
*     {
*         // ....
*         __pTts->SetLocale(Locale(LANGUAGE_ENG, COUNTRY_US));
*
*         __pTts->SetSpeechRate(TEXT_TO_SPEECH_SPEECH_RATE_NORMAL);
*     }
*
*     void TextToSpeechSample::OnTextToSpeechStatusChanged(Tizen::Uix::Speech::TextToSpeechStatus status)
*     {
*         // ....
*     }
*
*     void TextToSpeechSample::OnTextToSpeechErrorOccurred(Tizen::Uix::Speech::TextToSpeechError error)
*     {
*         // ....
*     }
*
*     void TextToSpeechSample::OnTextToSpeechCompleted()
*     {
*         // ....
*     }
*
*     bool TextToSpeechSample::Initialize(void)
*     {
*         result r = E_SUCCESS;
*
*         __pTts = new TextToSpeech();
*
*         r = __pTts->Construct(*this);
*         if (IsFailed(r))
*         {
*             AppLog("Error code: %s", GetErrorMessage(r)):
*             return false;
*         }
*
*         r = __pTts->Initialize();
*         if (IsFailed(r))
*         {
*             AppLog("Error code: %s", GetErrorMessage(r)):
*             return false;
*         }
*         return true;
*     }
*
*     void TextToSpeechSample::Speak(void)
*     {
*         if (__pTts->GetCurrentStatus() == TEXT_TO_SPEECH_STATUS_READY)
*         {
*             __pTts->Speak(L"Hi! Tizen.", TEXT_TO_SPEECH_REQUEST_MODE_APPEND);
*         }
*     }
* @endcode
*/

class _OSP_EXPORT_ TextToSpeech
	: public Tizen::Base::Object
{
public:
    /**
     * The object is not fully constructed after this constructor is called. @n
     * For full construction, the Construct() method must be called right after calling this constructor.
     *
     * @since 2.0
     */
    TextToSpeech(void);

    /**
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since 2.0
     */
    virtual ~TextToSpeech(void);

    /**
     * Initializes this instance of %TextToSpeech with the specified @c listener.
     *
     * @since 2.0
     *
     * @return      An error code
     * @param[in]   listener        An instance of ITextToSpeechEventListener
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @exception   E_OUT_OF_MEMORY The memory is insufficient.
     */
    result Construct(ITextToSpeechEventListener& listener);

    /**
     * Initializes the Text-To-Speech service. @n
     * This method is asynchronous. @n
     * The ITextToSpeechEventListener::OnTextToSpeechInitialized() is invoked when the service has been initialized.
     *
     * @since 2.0
	 *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @remarks     This method must be called after Construct().
     */
	result Initialize(void);

    /**
     * Starts the conversion of given text and starts playing the synthesized sound.
     *
     * @since 2.0
     *
     * @return      An error code
     * @param[in]   text            A text string for synthesizing a speech
     * @param[in]   requestMode     The request mode
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @exception   E_OUT_OF_MEMORY The memory is insufficient.
     * @exception   E_INVALID_STATE This instance is not initialized as yet.
     */
    result Speak(const Tizen::Base::String& text, TextToSpeechRequestMode requestMode = TEXT_TO_SPEECH_REQUEST_MODE_APPEND);

    /**
     * Stops the synthesis or the sound on playing.
     *
     * @since 2.0
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_INVALID_STATE     This instance is not initialized as yet.
     * @exception   E_INVALID_OPERATION The current status should be @c TEXT_TO_SPEECH_STATUS_PLAYING or @c TEXT_TO_SPEECH_STATUS_PAUSED.
     */
    result Stop(void);

    /**
     * Pauses the speech.
     *
     * @since 2.0
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_INVALID_STATE     This instance is not initialized as yet.
     * @exception   E_INVALID_OPERATION The current status should be @c TEXT_TO_SPEECH_STATUS_PLAYING.
     */
    result Pause(void);

    /**
     * Resumes the speech.
     *
     * @since 2.0
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_INVALID_STATE     This instance is not initialized as yet.
     * @exception   E_INVALID_OPERATION The current status should be @c TEXT_TO_SPEECH_STATUS_PAUSED.
     */
    result Resume(void);

    /**
     * Sets the locale for the Text-To-Speech service.
     *
     * @since 2.0
     *
     * @return      An error code
     * @param[in]   locale                  The current locale
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_UNSUPPORTED_LOCALE    This locale is not supported.
     * @exception   E_INVALID_STATE         This instance is not initialized as yet.
     * @see         GetSupportedLocales()
     */
    result SetLocale(const Tizen::Locales::Locale& locale);

    /**
     * Gets the current locale.
     *
     * @since 2.0
     *
     * @return      A current locale
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is not initialized as yet.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    Tizen::Locales::Locale GetLocale(void) const;

    /**
     * Checks whether a locale is supported.
     *
     * @since 2.0
     *
     * @return      @c true if the locale is available, @n
     *              else @c false
     * @param[in]   locale          The locale
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is not initialized as yet.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    bool IsLocaleSupported(const Tizen::Locales::Locale& locale) const;

    /**
     * Gets the list of supported locales. @n
     * Each list's item has a pointer of Tizen::Locales::Locale value.
     *
     * @since 2.0
     *
     * @return      A list of locales
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is not initialized as yet.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    const Tizen::Base::Collection::IList* GetSupportedLocales(void) const;

    /**
     * Sets the speech rate.
     *
     * @since 2.0
     *
     * @return      An error code
     * @param[in]   rate    A speech rate
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is not initialized as yet.
     * @see         TextToSpeechSpeechRate
     */
    result SetSpeechRate(TextToSpeechSpeechRate rate);

    /**
     * Gets the current status.
     *
     * @since 2.0
     *
     * @return      current status
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     TThis instance is not initialized as yet.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    TextToSpeechStatus GetCurrentStatus(void) const;

private:
    /**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @since 2.0
     */
	TextToSpeech(const TextToSpeech& rhs);

	/**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @since 2.0
     */
	TextToSpeech& operator =(const TextToSpeech& rhs);

private:
	_TextToSpeechImpl* __pTextToSpeechImpl;
	friend class _TextToSpeechImpl;

}; // TextToSpeech

} } } // Tizen::Uix::Speech

#endif
