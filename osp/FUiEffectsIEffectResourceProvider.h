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
 * @file        FUiEffectsIEffectResourceProvider.h
 * @brief       This is the header file for the %IEffectResourceProvider interface.
 *
 * This header file contains the declarations of the %IEffectResourceProvider interface.
 */

#ifndef _FUI_EFFECTS_IEFFECT_RESOURCE_PROVIDER_H_
#define _FUI_EFFECTS_IEFFECT_RESOURCE_PROVIDER_H_

namespace Tizen { namespace Ui { namespace Effects
{

class Effect;

/**
 * @interface  IEffectResourceProvider
 * @brief This interface implements the listener for events on Effect to provide the effects with resources.
 *
 * @since 2.0
 *
 * The %IEffectResourceProvider interface provides methods for notifying applications about the resources needed by the effects.
 * Applications have to provide the effects with appropriate resources.
 */
class _OSP_EXPORT_ IEffectResourceProvider
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IEffectResourceProvider(void) { }

	/**
	 * Called when the effect requires an image that is specified by its ID.
	 *
	 * @since 2.0
	 *
	 * @return			An error code
	 * @param [in,out]	effect			 The effect that needs a bitmap.
	 * @param [in]		bitmapId		 The bitmap ID needed.
	 * @remarks In general, EffectManager::SetBitmap should be used to provide this instance with a bitmap in this callback.
	 * @see  Effect::SetBitmap()
	 */
	virtual result SetBitmap(Effect& effect, long bitmapId) = 0;

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
	virtual void IEffectResourceProvider_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IEffectResourceProvider_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IEffectResourceProvider_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IEffectResourceProvider_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IEffectResourceProvider_Reserved5(void) {}
}; // IEffectResourceProvider

}}} // Tizen::Ui::Effects

#endif // _FUI_EFFECTS_IEFFECT_RESOURCE_PROVIDER_H_

