//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
/**
 * @file        FUiEffectsIEffectEventListener.h
 * @brief       This is the header file for the %IEffectEventListener interface.
 *
 * This header file contains the declarations of the %IEffectEventListener interface.
 */

#ifndef _FUI_EFFECTS_IEFFECT_LISTENER_H_
#define _FUI_EFFECTS_IEFFECT_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FUiEffectsTypes.h>

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}} // Tizen::Base::Collection

namespace Tizen { namespace Ui { namespace Effects
{

class Effect;

/**
 * @interface IEffectEventListener
 * @brief This interface provides listeners for the effects.
 *
 * @since 2.0
 *
 * This interface provides methods for notifying applications about the state change of the effects.
 */
class _OSP_EXPORT_ IEffectEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	 /**
	  * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	  *
	  * @since 2.0
	  */
	 virtual ~IEffectEventListener(void) {}

	 /**
	  * Called when the effect starts.
	  *
	  * @since 2.0
	  *
	  * @param [in]		effect	 The effect to be started.
	  */
	 virtual void OnEffectStarted(Effect& effect) = 0;

	 /**
	 * Called when the effect finishes.
	 *
	 * @since 2.0
	 *
	 * @param [in]		effect				  The effect that is finished
	 * @param [in]		effectResult		  The result of the effect
	 * @param [in]		lastShownBitmapIds	  A list of last shown bitmaps @n
	                                          The listener will be notified with the bitmaps shown at the last frame.
	 *										  The item type of @c lastShownBitmapIds is Tizen::Base::Long.
	 */
	 virtual void OnEffectFinished(Effect& effect, Tizen::Ui::Effects::EffectResult effectResult, const Tizen::Base::Collection::IList& lastShownBitmapIds) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IEffectEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IEffectEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IEffectEventListener_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IEffectEventListener_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IEffectEventListener_Reserved5(void) {}
}; // IEffectEventListener

}}} // Tizen::Ui::Effects

#endif // _FUI_EFFECTS_IEFFECT_LISTENER_H_

