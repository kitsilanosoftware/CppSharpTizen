//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 3.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-3.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file    FUixSpeechSpeechToText.h
 * @brief   This is the header file for the %SpeechToText class.
 *
 * This header file contains the declarations of the %SpeechToText class.
 */

#ifndef _FUIX_SPEECH_SPEECH_TO_TEXT_H_
#define _FUIX_SPEECH_SPEECH_TO_TEXT_H_

#include <FBaseObject.h>
#include <FBaseDataType.h>
#include <FUixSpeechSpeechToTextTypes.h>
#include <FUixSpeechISpeechToTextEventListener.h>

namespace Tizen { namespace Base
{
    class String;
    class ByteBuffer;
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

class _SpeechToTextImpl;

/**
* @class    SpeechToText
* @brief    This class is used to convert spoken words into text.
*
* @since 2.0
*
* @remarks  @b Header @b %file: @b \#include @b <FUix.h> @n
*           @b Library : @b osp-speech-stt
*
* The %SpeechToText class converts spoken words into text.
* @n
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/speech_to_text.htm">Speech-To-Text</a>.
*
* The following example demonstrates how to use the %SpeechToText class. @n
* In the example, the Start() method is called after invoking the ISpeechToTextEventListener::OnSpeechToTextInitialized() method.
*
* @code
*   //Sample code for SpeechToTextSample.h
*   #include <FUix.h>
*
*   using namespace Tizen::Uix::Speech;
*
*     class SpeechToTextSample : public ISpeechToTextEventListener
*     {
*         public:
*             SpeechToTextSample(void);
*             virtual ~SpeechToTextSample(void);
*
*             bool Initialize(void);
*             bool Start(void);
*
*             virtual void OnSpeechToTextInitialized(void);
*             virtual void OnSpeechToTextStatusChanged(Tizen::Uix::Speech::SpeechToTextStatus status);
*             virtual void OnSpeechToTextErrorOccurred(Tizen::Uix::Speech::SpeechToTextError error);
*             virtual void OnSpeechToTextCompleted(Tizen::Base::String& result);
*
*         private:
*             Tizen::Uix::Speech::SpeechToText* __pStt;
*     };
*
*     //Sample code for SpeechToTextSample.cpp
*     #include "SpeechToTextSample.h"
*
*     SpeechToTextSample::SpeechToTextSample(void)
*         : __pStt(null)
*     {
*     }
*
*     SpeechToTextSample::~SpeechToTextSample(void)
*     {
*     }
*
*     void SpeechToTextSample::OnSpeechToTextInitialized(void)
*     {
*         // ....
*         __pStt->SetLocale(Locale(LANGUAGE_ENG, COUNTRY_US));
*
*         __pStt->SetSilenceDetectionEnabled(true);
*     }
*
*     void SpeechToTextSample::OnSpeechToTextStatusChanged(Tizen::Uix::Speech::SpeechToTextStatus status)
*     {
*         // ....
*     }
*
*     void SpeechToTextSample::OnSpeechToTextErrorOccurred(Tizen::Uix::Speech::SpeechToTextError error)
*     {
*         // ....
*     }
*
*     void SpeechToTextSample::OnSpeechToTextCompleted(Tizen::Base::String& result)
*     {
*         // ....
*     }
*
*     bool SpeechToTextSample::Initialize(void)
*     {
*         result r = E_SUCCESS;
*
*         __pStt = new SpeechToText();
*
*         r = __pStt->Construct(*this);
*         if (IsFailed(r))
*         {
*             AppLog("Error code: %s", GetErrorMessage(r)):
*             return false;
*         }
*
*         r = __pStt->Initialize();
*         if (IsFailed(r))
*         {
*             AppLog("Error code: %s", GetErrorMessage(r)):
*             return false;
*         }
*         return true;
*     }
*
*     void SpeechToTextSample::Start(void)
*     {
*         if (__pStt->GetCurrentStatus() == SPEECH_TO_TEXT_STATUS_READY)
*         {
*             __pStt->Start();
*         }
*     }
* @endcode
*/

class _OSP_EXPORT_ SpeechToText
    : public Tizen::Base::Object
{
public:
    /**
     * The object is not fully constructed after this constructor is called. @n
     * For full construction, the Construct() method must be called right after calling this constructor.
     *
     * @since 2.0
     */
    SpeechToText(void);

    /**
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since 2.0
     */
    virtual ~SpeechToText(void);

    /**
     * Initializes this instance of %SpeechToText with the specified @c listener.
     *
     * @since 2.0
     *
     * @return      An error code
     * @param[in]   listener        An instance of ISpeechToTextEventListener
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_SYSTEM        A system error has occurred.
     * @exception   E_OUT_OF_MEMORY The memory is insufficient.
     */
    result Construct(ISpeechToTextEventListener& listener);

    /**
     * Initializes the Speech-To-Text service. @n
     * The %Initialize() method is asynchronous. @n
     * The ISpeechToTextEventListener::OnSpeechToTextInitialized() is invoked when the service has been initialized.
     * @since 2.0
     *
     * @feature           %http://tizen.org/feature/speech.recognition
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception  E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature. @b Since: @b 2.1
     * For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
     * @remarks     
     *			- Before calling this method, check whether the feature is supported by 
     *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
     * 			- This method must be called after Construct().
     */
    result Initialize(void);

    /**
     * Starts recording the speech of a user and converts it to text.
     *
     * @since 2.0
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @exception   E_SERVICE_BUSY      The recorder is busy.
     * @exception   E_INVALID_STATE     This instance is not initialized as yet.
     * @exception   E_INVALID_OPERATION The current status should be @c SPEECH_TO_TEXT_STATUS_READY.
     */
    result Start(void);

    /**
     * Stops the recording and current Speech-To-Text service.
     *
     * @since 2.0
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
     * @exception   E_INVALID_STATE     This instance is not initialized as yet.
     * @exception   E_INVALID_OPERATION The current status should be @c SPEECH_TO_TEXT_STATUS_RECORDING.
     */
    result Stop(void);

    /**
     * Cancels the in-progress recognition of the Speech-To-Text service.
     *
     * @since 2.0
     *
     * @return      An error code
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_SYSTEM            A system error has occurred.
     * @exception   E_INVALID_STATE     This instance is not initialized as yet.
     * @exception   E_INVALID_OPERATION The current status should be @c SPEECH_TO_TEXT_STATUS_RECORDING or @c SPEECH_TO_TEXT_STATUS_PROCESSING.
     */
    result Cancel(void);

    /**
    * Sets the locale for the Speech-To-Text service.
    *
    * @since 2.0
    *
    * @return       An error code
    * @param[in]    locale                  The locale
    * @exception    E_SUCCESS               The method is successful.
    * @exception    E_UNSUPPORTED_LOCALE    This locale is not supported.
    * @exception    E_INVALID_STATE         This instance is not initialized as yet.
    * @see          GetSupportedLocales()
    */
    result SetLocale(const Tizen::Locales::Locale& locale);

    /**
     * Gets the current locale.
     *
     * @since 2.0
     *
     * @return      A current locale
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is not initialized as yet.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    Tizen::Locales::Locale GetLocale(void) const;

    /**
     * Checks whether a locale is supported or not.
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
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is not initialized as yet.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    const Tizen::Base::Collection::IList* GetSupportedLocales(void) const;

    /**
     * Sets the grammar for %SpeechToText.
     *
     * @since 2.0
     *
     * @return      An error code
     * @param[in]   grammar         A grammar
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is not initialized as yet.
     */
    result SetGrammar(SpeechToTextGrammar grammar);

    /**
     * Gets the current grammar.
     *
     * @since 2.0
     *
     * @return      The current grammar used by recognition
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is not initialized as yet.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    SpeechToTextGrammar GetGrammar(void) const;

    /**
     * Sets the silence detection enabled or disabled.
     *
     * @since 2.0
     *
     * @return      An error code
     * @param[in]   enable  Set to @c true to enable the silence detection, @n
     *                      else @c false
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is not initialized as yet.
     */
    result SetSilenceDetectionEnabled(bool enable);

    /**
     * Checks whether the silence detection feature is enabled.
     *
     * @since 2.0
     *
     * @return      @c true if the silence detection is enabled, @n
     *              else @c false
     * @exception   E_SUCCESS       The method is successful.
     * @exception   E_INVALID_STATE This instance is not initialized as yet.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    bool IsSilenceDetectionEnabled(void) const;

    /**
     * Gets the current status.
     *
     * @since 2.0
     *
     * @return      current status
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_INVALID_STATE     This instance is not initialized as yet.
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
     */
    SpeechToTextStatus GetCurrentStatus(void) const;


private:
    /**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @since 2.0
     */
    SpeechToText(const SpeechToText& rhs);

    /**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @since 2.0
     */
    SpeechToText& operator =(const SpeechToText& rhs);

private:
    _SpeechToTextImpl* __pSpeechToTextImpl;
    friend class _SpeechToTextImpl;

}; // SpeechToText

} } } // Tizen::Uix::Speech

#endif
