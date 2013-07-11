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
* @file        FUiEffectsEffect.h
* @brief       This is the header file for the %Effect class.
*
* This header file contains the declarations of the %Effect class.
*/

#ifndef _FUI_EFFECTS_EFFECT_H_
#define _FUI_EFFECTS_EFFECT_H_

#include <FBaseObject.h>
#include <FUiEffectsTypes.h>


namespace Tizen { namespace Base {
class String;
}} // Tizen::Base

namespace Tizen { namespace Ui {
class TouchEventInfo;
class Control;
}} // Tizen::Ui

namespace Tizen { namespace Graphics {
class Bitmap;
class Point;
}} // Tizen::Graphics

namespace Tizen { namespace Base { namespace Collection {
class IList;
}}} // Tizen::Base::Collection

namespace Tizen { namespace Ui { namespace Effects
{
class IEffectEventListener;
class IEffectResourceProvider;
class _EffectImpl;

/**
* @class      Effect
* @brief      This class contains API for managing effects.
*
* @since 2.0
*
* The %Effect class contains API for managing effects.
*/
class _OSP_EXPORT_ Effect
	: public Tizen::Base::Object
{
public:
	/**
	 * Binds the effect to Tizen::UI::Control for rendering effect.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @param [in] pControl		 Tizen::UI::Control whose content is filled by the effect
	 * @exception  E_SUCCESS 	 The specified effect is bound with @c control successfully.
	 * @exception	E_OPERATION_FAILED	The system has failed to initialize the 3D system.
	 * @exception	E_IN_PROGRESS 		The specified effect is running now, setting, changing or resetting render target is impossible
	 */
	result SetRenderTarget(Tizen::Ui::Control* pControl);

	/**
	 * Starts the effect.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @exception  E_SUCCESS 		  The specified effect is started successfully.
	 * @exception  E_INVALID_STATE	  The specified effect has already started.
	 * @exception  E_OPERATION_FAILED The specified effect has a runtime error in the script.
	 * @exception  E_ALREADY_SET 	  Other effects which use the same control as a render target are currently running.
	 */
	result Start(void);

	/**
	 * Starts the effect.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @param [in] effectStartInfo	  A list of input arguments to be passed to the OnEffectStarted() method of the scripts @n
	 *								  All arguments must be represented in @c float data type.
	 * @exception  E_SUCCESS 		  The specified effect is started successfully.
	 * @exception  E_INVALID_STATE	  The specified effect has already started.
	 * @exception  E_OPERATION_FAILED The specified effect has a runtime error in the script.
	 * @exception  E_ALREADY_SET 	  Other effects which use the same control as a render target are currently running.
	 */
	result Start(const Tizen::Base::Collection::IList& effectStartInfo);

	/**
	 * Stops the effect.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @exception  E_SUCCESS 	   The specified effect is stopped successfully.
	 * @exception  E_INVALID_STATE The specified effect has not started as yet.
	 */
	result Stop(void);

	/**
	 * Informs the effect of a TouchPress event.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @param [in] touchEventInfo	  The touch event information
	 * @param [in] offset			  The effect will regard the touch position in @c touchEventInfo translated by @c offset
	 * @exception  E_SUCCESS 		  The specified effect is successfully sent with a TouchPress event.
	 * @exception  E_INVALID_STATE	  The specified effect has not started as yet.
	 * @exception  E_OPERATION_FAILED There is a runtime error in the OnTouchPressed() script method or the effect is time-based.
	 */
	result FeedTouchPressEvent(const Tizen::Ui::TouchEventInfo& touchEventInfo, const Tizen::Graphics::Point& offset);

	/**
	 * Informs the effect of a TouchPress event.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @param [in] touchEventInfo	  The touch event information
	 * @exception  E_SUCCESS 		  The specified effect is successfully sent with a TouchPress event.
	 * @exception  E_INVALID_STATE	  The specified effect has not started as yet.
	 * @exception  E_OPERATION_FAILED There is a runtime error in the OnTouchPressed() script method or the effect is time-based.
	 */
	result FeedTouchPressEvent(const Tizen::Ui::TouchEventInfo& touchEventInfo);

	/**
	 * Informs the effect of a TouchMove event.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @param [in] touchEventInfo	  The touch event information
	 * @param [in] offset			  The effect will regard the touch position in @c touchEventInfo translated by @c offset
	 * @exception  E_SUCCESS 		  The specified effect is successfully sent with a TouchMove event.
	 * @exception  E_INVALID_STATE	  The specified effect has not started as yet.
	 * @exception  E_OPERATION_FAILED There is a runtime error in the OnTouchMoved() script method or the effect is time-based.
	 */
	result FeedTouchMoveEvent(const Tizen::Ui::TouchEventInfo& touchEventInfo, const Tizen::Graphics::Point& offset);

	/**
	 * Informs the effect of a TouchMove event.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @param [in] touchEventInfo	  The touch event information
	 * @exception  E_SUCCESS 		  The specified effect is successfully sent with a TouchMove event.
	 * @exception  E_INVALID_STATE	  The specified effect has not started as yet.
	 * @exception  E_OPERATION_FAILED There is a runtime error in the OnTouchMoved() script method or the effect is time-based.
	 */
	result FeedTouchMoveEvent(const Tizen::Ui::TouchEventInfo& touchEventInfo);

	/**
	 * Informs the effect of a TouchRelease event.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @param [in] touchEventInfo	  The touch event information
	 * @param [in] offset			  The effect will regard the touch position in @c touchEventInfo translated by @c offset
	 * @exception  E_SUCCESS 		  The specified effect is successfully sent with a TouchRelease event.
	 * @exception  E_INVALID_STATE	  The specified effect has not started as yet.
	 * @exception  E_OPERATION_FAILED There is a runtime error in the OnTouchReleased() script method or the effect is time-based.
	 */
	result FeedTouchReleaseEvent(const Tizen::Ui::TouchEventInfo& touchEventInfo, const Tizen::Graphics::Point& offset);

	/**
	 * Informs the effect of a TouchRelease event.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @param [in] touchEventInfo	  The touch event information
	 * @exception  E_SUCCESS 		  The specified effect is successfully sent with a TouchRelease event.
	 * @exception  E_INVALID_STATE	  The specified effect has not started as yet.
	 * @exception  E_OPERATION_FAILED There is a runtime error in the OnTouchReleased() script method or the effect is time-based.
	 */
	result FeedTouchReleaseEvent(const Tizen::Ui::TouchEventInfo& touchEventInfo);

	/**
	 * Informs the effect of a TouchDoublePress event.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @param [in] touchEventInfo	  The touch event information
	 * @param [in] offset			  The effect will regard the touch position in @c touchEventInfo translated by @c offset
	 * @exception  E_SUCCESS 		  The specified effect is successfully sent with a TouchDoublePress event.
	 * @exception  E_INVALID_STATE	  The specified effect has not started as yet.
	 * @exception  E_OPERATION_FAILED There is a runtime error in the OnTouchDoublePressed() script method or the effect is time-based.
	 */
	result FeedTouchDoublePressEvent(const Tizen::Ui::TouchEventInfo& touchEventInfo, const Tizen::Graphics::Point& offset);

	/**
	 * Informs the effect of a TouchDoublePress event.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @param [in] touchEventInfo	 The touch event information
	 * @exception  E_SUCCESS 		 The specified effect is successfully sent with a TouchDoublePress event.
	 * @exception  E_INVALID_STATE	 The specified effect has not started as yet.
	 * @exception  E_OPERATION_FAILED There is a runtime error in the OnTouchDoublePressed() script method or the effect is time-based.
	 */
	result FeedTouchDoublePressEvent(const Tizen::Ui::TouchEventInfo& touchEventInfo);

	/**
	 * Sets the effect's bitmap that is used as a graphical surface in scripts.
	 *
	 * @since 2.0
	 *
	 * @return	  An error code
	 * @param [in] bitmapId			  The bitmap ID to be updated
	 * @param [in] bitmap			  The bitmap content
	 * @exception  E_SUCCESS 		  The bitmap is updated successfully.
	 * @exception  E_OPERATION_FAILED Updating the bitmap contents has failed.
	 */
	result SetBitmap(long bitmapId, const Tizen::Graphics::Bitmap& bitmap);

	/**
	 * Checks whether the effect is running.
	 *
	 * @since 2.0
	 *
	 * @return	  @c true if the effect is running, @n
	 *            else @c false
	 */
	bool IsRunning(void) const;

	/**
	 * Gets the effect type.
	 *
	 * @since 2.0
	 *
	 * @return	  The type of effect
	 */
	EffectType GetType(void) const;

	/**
	 * Gets the name of the effect.
	 *
	 * @since 2.0
	 *
	 * @return	  The name of the effect.
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * Sets the IEffectsEventListener instance to get notified when the state of the effect is changed.
	 *
	 * @since 2.0
	 *
	 * @param [in] pListener 	 The event listener to be set @n
	 *							 If @c pListener is @c null, the status changes of this instance are not notified anymore.
	 * @see	GetEffectEventListener
	 */
	void SetEffectEventListener(IEffectEventListener* pListener);

	/**
	 * Gets the IEffectsEventListener instance that is registered to the instance.
	 *
	 * @since 2.0
	 *
	 * @return 	The event listener
	 *
	 * @see	SetEffectEventListener
	 */
	IEffectEventListener* GetEffectEventListener(void) const;

	/**
	 * Sets the IEffectsResourceProvider instance to get notified when resources are needed by the effect.
	 *
	 * @since 2.0
	 *
	 * @param [in] pProvider 	 The resource provider to provide the effect with bitmap resources @n
	 *							 If @c pProvider is @c null, this instance will not display effects correctly.
	 *
	 * @see	GetResourceProvider
	 */
	void SetResourceProvider(IEffectResourceProvider* pProvider);

	/**
	 * Gets the IEffectsResourceProvider instance that is registered to the instance.
	 *
	 * @since 2.0
	 *
	 * @return   The resource provider
	 *
	 * @see	SetResourceProvider
	 */
	IEffectResourceProvider* GetResourceProvider(void) const;

protected:
	/**
	 * This default constructor is intentionally declared as protected so that only the platform can create an instance.
	 *
	 * @since 2.0
	 */
	Effect(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~Effect(void);

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void Effect_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void Effect_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void Effect_Reserved3(void) {}

private:
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	Effect(const Effect& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	Effect& operator=(const Effect& rhs);

private:
	friend class _EffectManagerImpl;
	friend class _EffectImpl;
	_EffectImpl* __pEffectImpl;
}; //Effect

}}} // Tizen::Ui::Effects

#endif // _FUI_EFFECTS_EFFECT_H_

