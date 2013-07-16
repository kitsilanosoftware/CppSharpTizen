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
 * @file    FUixSpeechITextToSpeechEventListener.h
 * @brief   This is the header file for the %ITextToSpeechEventListener interface.
 *
 * This header file contains the declarations of the %ITextToSpeechEventListener interface.
 */

#ifndef _FUIX_SPEECH_ITEXT_TO_SPEECH_EVENT_LISTENER_H_
#define _FUIX_SPEECH_ITEXT_TO_SPEECH_EVENT_LISTENER_H_

#include <FUixSpeechTextToSpeechTypes.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Uix { namespace Speech
{

/**
 * @interface   ITextToSpeechEventListener
 * @brief       This interface is a listener for the speech synthesis events.
 *
 * @since 2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FUix.h> @n
 *              @b Library : @b osp-speech-tts
 *
 * The %ITextToSpeechEventListener interface is a listener interface for the speech synthesis events.
 * It provides methods that are used to notify when the status is changed and an error occurs from the voice engine. @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/text_to_speech.htm">Text-To-Speech</a>.
 */

class _OSP_EXPORT_ ITextToSpeechEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
    /**
     * This polymorphic destructor should be overridden if required. @n
     * This way, the destructors of the derived classes are called when the destructor of this interface is called.
     *
     * @since 2.0
     */
    virtual ~ITextToSpeechEventListener(void) {}

    /**
     * Called when the Text-To-Speech service is initialized.
     *
     * @since 2.0
     *
     * @see     TextToSpeech::Initialize()
     */
     virtual void OnTextToSpeechInitialized(void) = 0;

    /**
     * Called when the status of the Text-To-Speech service is changed.
     *
     * @since 2.0
     *
     * @param[in]   status  The status of the Text-To-Speech service
     */
    virtual void OnTextToSpeechStatusChanged(Tizen::Uix::Speech::TextToSpeechStatus status) = 0;

    /**
     * Called when an error occurs in the Text-To-Speech service.
     *
     * @since 2.0
     *
     * @param[in]   error   The reason for an error in the Text-To-Speech service
     */
     virtual void OnTextToSpeechErrorOccurred(Tizen::Uix::Speech::TextToSpeechError error) = 0;

    /**
     * Called when the Text-To-Speech service is completed.
     *
     * @since 2.0
     */
    virtual void OnTextToSpeechCompleted(void) = 0;

protected:
    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
    //
	virtual void ITextToSpeechEventListener_Reserved1(void) {}

    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
    //
	virtual void ITextToSpeechEventListener_Reserved2(void) {}

    //
    // This method is for internal use only. Using this method can cause behavioral, security-related,
    // and consistency-related issues in the application.
    //
	virtual void ITextToSpeechEventListener_Reserved3(void) {}

};

} } } // Tizen::Uix::Speech

#endif // _FUIX_ITEXT_TO_SPEECH_EVENT_LISTENER_H_
