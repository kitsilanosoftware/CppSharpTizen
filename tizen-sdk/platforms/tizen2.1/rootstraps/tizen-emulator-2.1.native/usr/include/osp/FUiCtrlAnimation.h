//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FUiCtrlAnimation.h
 * @brief	This header file contains the declarations of the %Animation class.
 *
 * This header file contains the declarations of the %Animation class and its helper classes.
 */

#ifndef _FUI_CTRL_ANIMATION_H_
#define _FUI_CTRL_ANIMATION_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseColArrayList.h>
#include <FGrpBitmap.h>
#include <FGrpColor.h>
#include <FGrpPoint.h>
#include <FGrpRectangle.h>
#include <FUiContainer.h>
#include <FUiCtrlAnimationFrame.h>
#include <FUiIAnimationEventListener.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum	AnimationStatus
 *
 * Defines the animation status.
 *
 * @since	2.0
 */
enum AnimationStatus
{
	ANIMATION_STOPPED,              /**< The %Animation is in 'stopped' state */
	ANIMATION_PAUSED,               /**< The %Animation is in 'paused' state */
	ANIMATION_PLAYING               /**< The %Animation is in 'playing' state */
};


/**
 * @class	Animation
 * @brief This class defines the common behavior of an %Animation control.
 *
 * @since	2.0
 *
 * The %Animation class displays a series of frames one by one that are represented by the AnimationFrame instances.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_animation.htm">Animation</a>.
 *
 *
 * The following example demonstrates how to use the %Animation class.
 *
 *
 * @code
// Sample code for AnimationSample.h
#include <FBase.h>
#include <FUi.h>

class AnimationSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IAnimationEventListener
{
public:
	AnimationSample(void)
	: __animationFrameList(){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IAnimationEventListener
	virtual void OnAnimationStopped(const Tizen::Ui::Control& source);

private :
	Tizen::Base::Collection::ArrayList __animationFrameList;
};

 *	@endcode
 *
 *	@code

// Sample code for AnimationSample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "AnimationSample.h"

using namespace Tizen::App;
using namespace Tizen::Base::Collection;
using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

bool
AnimationSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
AnimationSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Gets instances of Bitmap
	AppResource *pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap* pBitmap1 = pAppResource->GetBitmapN(L"progressing00_big.png");
	Bitmap* pBitmap2 = pAppResource->GetBitmapN(L"progressing02_big.png");
	Bitmap* pBitmap3 = pAppResource->GetBitmapN(L"progressing04_big.png");
	Bitmap* pBitmap4 = pAppResource->GetBitmapN(L"progressing06_big.png");

	// Creates instances of AnimationFrame
	AnimationFrame* pAniFrame1 = new AnimationFrame(*pBitmap1, 1000) ;
	AnimationFrame* pAniFrame2 = new AnimationFrame(*pBitmap2, 1000) ;
	AnimationFrame* pAniFrame3 = new AnimationFrame(*pBitmap3, 1000) ;
	AnimationFrame* pAniFrame4 = new AnimationFrame(*pBitmap4, 1000) ;

	__animationFrameList.Construct();
	__animationFrameList.Add(*pAniFrame1);
	__animationFrameList.Add(*pAniFrame2);
	__animationFrameList.Add(*pAniFrame3);
	__animationFrameList.Add(*pAniFrame4);

	// Creates an instance of Animation
	Animation* pAnimation = new Animation();
	pAnimation->Construct(Rectangle((GetClientAreaBounds().width - pBitmap1->GetWidth()) / 2, 100,
						  pBitmap1->GetWidth(), pBitmap1->GetHeight()), __animationFrameList);
	pAnimation->SetRepeatCount(100);
	pAnimation->AddAnimationEventListener(*this);

	// Adds the animation to the form
	AddControl(pAnimation);

	// Plays the animation
	pAnimation->Play();

	delete pBitmap1;
	delete pBitmap2;
	delete pBitmap3;
	delete pBitmap4;

	return r;
}

result
AnimationSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates added animation frames from the list
	__animationFrameList.RemoveAll(true);

	return r;
}

void
AnimationSample::OnAnimationStopped(const Control& source)
{
	// ....
}
 * @endcode
 *
 */
class _OSP_EXPORT_ Animation
	: public Tizen::Ui::Control
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the %Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	Animation(void);


	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~Animation(void);


	/**
	 * Initializes this instance of %Animation with the specified parameters. @n
	 * The @c aniFrames list of the AnimationFrame instances should be deleted explicitly after use.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			An instance of the Tizen::Graphics::Rectangle class @n
	 *								This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *								its width and height.@n
	 *								The optimal size of the control is defined in
	 *								<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]	aniFrames		An IList of %AnimationFrames used in the animation
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception   E_INVALID_ARG           A specified input parameter is invalid.
	 * @remarks
	 *			- A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier.
	 *			- The size of the control must be within the range defined by the minimum size and the maximum size.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect, const Tizen::Base::Collection::IList& aniFrames);

	/**
	 * Initializes this instance of %Animation with the specified parameters. @n
	 * The @c aniFrames list of the AnimationFrame instances should be deleted explicitly after use.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect			An instance of the Tizen::Graphics::FloatRectangle class @n
	 *								This instance represents the x and y coordinates of the top-left corner of the created window along with
	 *								its width and height.@n
	 *								The optimal size of the control is defined in
	 *								<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @param[in]	aniFrames		An IList of %AnimationFrames used in the animation
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @exception   E_INVALID_ARG           A specified input parameter is invalid.
	 * @remarks
	 *			- A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier.
	 *			- The size of the control must be within the range defined by the minimum size and the maximum size.
	 */
	result Construct(const Tizen::Graphics::FloatRectangle& rect, const Tizen::Base::Collection::IList& aniFrames);

public:
	/**
	 * Adds a listener instance to the current instance of %Animation. @n
	 * The added listener can listen to the events on the given event dispatcher's context when they are fired. @n
	 * When an animation stops, a state change event with the state name "ANIMATION_NOTIFY_CLOSE" is fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to add
	 */
	void AddAnimationEventListener(Tizen::Ui::IAnimationEventListener& listener);


	/**
	 * Removes a listener instance from the current instance of %Animation. @n
	 * The removed listener cannot listen to the events when they are fired.
	 *
	 * @since		2.0
	 *
	 * @param[in]	listener	The listener to remove
	 */
	void RemoveAnimationEventListener(Tizen::Ui::IAnimationEventListener& listener);


	/**
	 * Sets the repeat count of the animation. @n
	 * If this value is not set, the default value is @c 1.
	 *
	 * @since		2.0
	 *
	 * @param[in]   count		The repeat count
	 */
	void SetRepeatCount(int count);


	/**
	 * Gets the total repeat count of the animation.
	 *
	 * @since		2.0
	 *
	 * @return		The total repeat count
	 *
	 * @remarks		The default repeat count is @c 1.
	 */
	int GetRepeatCount(void) const;


	/**
	 * Gets the current repeated count of the animation.
	 *
	 * @since		2.0
	 *
	 * @return		The current repeated count
	 *
	 * @remarks		The default current repeated count is @c 0.
	 */
	int GetCurrentRepeatedCount(void) const;


	/**
	 * Gets the total image count of the animation.
	 *
	 * @since		2.0
	 *
	 * @return		The total image count
	 *
	 * @remarks		The default image count is @c 0.
	 */
	int GetImageCount(void) const;


	/**
	 * Plays the animation.
	 *
	 * @since		2.0
	 */
	void Play(void);


	/**
	 * Stops the animation.
	 *
	 * @since		2.0
	 */
	void Stop(void);


	/**
	 * Pauses the animation.
	 *
	 * @since		2.0
	 */
	void Pause(void);


	/**
	 * Gets the status of the animation.
	 *
	 * @since		2.0
	 *
	 * @return		The status of animation
	 *
	 * @remarks		The default animation status is @c ANIMATION_STOPPED.
	 */
	AnimationStatus GetStatus(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Animation(const Animation& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Animation& operator =(const Animation& rhs);

	friend class _AnimationImpl;

};  // Animation

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ANIMATION_H_
