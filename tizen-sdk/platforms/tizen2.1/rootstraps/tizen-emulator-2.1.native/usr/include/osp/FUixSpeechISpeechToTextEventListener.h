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
 * @file    FUixSpeechISpeechToTextEventListener.h
 * @brief   This is the header file for the %ISpeechToTextEventListener interface.
 *
 * This header file contains the declarations of the %ISpeechToTextEventListener interface.
 */

#ifndef _FUIX_SPEECH_ISPEECH_TO_TEXT_EVENT_LISTENER_H_
#define _FUIX_SPEECH_ISPEECH_TO_TEXT_EVENT_LISTENER_H_

#include <FUixSpeechSpeechToTextTypes.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Uix { namespace Speech
{

/**
 * @interface   ISpeechToTextEventListener
 * @brief		This interface is a listener for speech recognition events.
 *
 * @since 2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FUix.h> @n
 *              @b Library : @b osp-speech-stt
 *
 * The %ISpeechToTextEventListener interface is a listener interface for speech recognition events.
 * It provides methods that are invoked by the voice engine when the status is changed, an
 * error or warning occurs or the result is received in the Speech-To-Text service. @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/speech_to_text.htm">Speech-To-Text</a>.
 *
 */

class _OSP_EXPORT_ ISpeechToTextEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
    /**
     * This polymorphic destructor should be overridden if required. @n
     * This way, the destructors of the derived classes are called when the destructor of this interface is called.
     *
     * @since 2.0
     */
    virtual ~ISpeechToTextEventListener(void) {}

    /**
     * Called when the Speech-To-Text service is initialized.
     *
     * @since 2.0
     *
     * @see SpeechToText::Initialize()
     */
    virtual void OnSpeechToTextInitialized(void) = 0;

    /**
     * Called when the Speech-To-Text recording status is changed.
     *
     * @since 2.0
     *
     * @param[in]   status  The recording status of the Speech-To-Text service
     */
    virtual void OnSpeechToTextStatusChanged(Tizen::Uix::Speech::SpeechToTextStatus status) = 0;

    /**
     * Called when an error occurs in the Speech-To-Text service.
     *
     * @since 2.0
     *
     * @param[in]   error   The reason for an error in the Speech-To-Text service
     */
    virtual void OnSpeechToTextErrorOccurred(Tizen::Uix::Speech::SpeechToTextError error) = 0;

    /**
     * Called when the Speech-To-Text service is completed.
     *
     * @since 2.0
     *
     * @param[in]   result  The result of the Speech-To-Text service
     */
    virtual void OnSpeechToTextCompleted(const Tizen::Base::String& result) = 0;

protected:
    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
	//
    virtual void ISpeechToTextEventListener_Reserved1(void) {}

    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
    //
    virtual void ISpeechToTextEventListener_Reserved2(void) {}

    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
    //
    virtual void ISpeechToTextEventListener_Reserved3(void) {}

}; // ISpeechToTextEventListener

}}} // Tizen::Uix::Speech

#endif
