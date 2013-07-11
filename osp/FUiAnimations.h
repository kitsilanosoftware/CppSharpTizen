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
 * @file	FUiAnimations.h
 * @brief	This is the header file for the %Animations namespace.
 *
 * This header file contains the declarations and descriptions of the %Animations namespace.
 */

#ifndef _FUI_ANIMATIONS_H_
#define _FUI_ANIMATIONS_H_

#include <FUiAnimTypes.h>
#include <FUiAnimAnimationBase.h>
#include <FUiAnimAnimationGroup.h>
#include <FUiAnimParallelAnimationGroup.h>
#include <FUiAnimSequentialAnimationGroup.h>
#include <FUiAnimDimensionAnimation.h>
#include <FUiAnimFloatAnimation.h>
#include <FUiAnimIntegerAnimation.h>
#include <FUiAnimPointAnimation.h>
#include <FUiAnimRectangleAnimation.h>
#include <FUiAnimRotateAnimation.h>
#include <FUiAnimControlAnimator.h>
#include <FUiAnimFrameAnimator.h>

#include <FUiAnimAnimationTransaction.h>
#include <FUiAnimIAnimationTransactionEventListener.h>

#include <FUiAnimIControlAnimatorDetailedEventListener.h>
#include <FUiAnimIControlAnimatorEventListener.h>
#include <FUiAnimIFrameAnimatorEventListener.h>

#include <FUiAnimIVisualElementAnimationStatusEventListener.h>
#include <FUiAnimIVisualElementAnimationTickEventListener.h>
#include <FUiAnimIVisualElementAnimationTimingFunction.h>
#include <FUiAnimIVisualElementAnimationValueInterpolator.h>

#include <FUiAnimVisualElementAnimation.h>
#include <FUiAnimVisualElementAnimationGroup.h>
#include <FUiAnimVisualElementPropertyAnimation.h>
#include <FUiAnimVisualElementValueAnimation.h>

#include <FUiAnimBezierTimingFunction.h>
#include <FUiAnimDiscreteTimingFunction.h>
#include <FUiAnimEaseElasticInTimingFunction.h>
#include <FUiAnimEaseElasticOutTimingFunction.h>
#include <FUiAnimEaseInOutTimingFunction.h>
#include <FUiAnimEaseInTimingFunction.h>
#include <FUiAnimEaseOutInTimingFunction.h>
#include <FUiAnimEaseOutTimingFunction.h>
#include <FUiAnimExpInTimingFunction.h>
#include <FUiAnimExpOutTimingFunction.h>
#include <FUiAnimLinearTimingFunction.h>

#include <FUiAnimDisplayContext.h>
#include <FUiAnimVisualElement.h>
#include <FUiAnimVisualElementSurface.h>
#include <FUiAnimVisualElementAnimationProvider.h>
#include <FUiAnimVisualElementContentProvider.h>
#include <FUiAnimIVisualElementAnimationProvider.h>
#include <FUiAnimIVisualElementContentProvider.h>
#include <FUiAnimIVisualElementEventListener.h>

namespace Tizen
{
namespace Ui
{
/**
 * @namespace Tizen::Ui::Animations
 * @brief	This namespace contains the classes for the animation-related functionalities.
 * @since	2.0
 *
 * @remarks	@b Header @b %file: @b \#include @b <FUiAnimations.h> @n
 *			@b Library : @b osp-uifw
 *
 *
 *
 * The %Animations namespace provides animation capabilities for the UI controls.
 *
 * For more information on the %Animations namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/animation.htm">Animations Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Animations namespace.
 * @image html ui_animations_classdiagram.png
 *
 * The following examples demonstrate how to use the %Animations namespace.
 *
 *	@code
// Sample code for Control Animation using ControlAnimator
#include <FUi.h>
#include <FUiAnimations.h>

using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Graphics;

class AnimationSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
{
public:
	virtual result OnInitializing(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

protected:
	static const int ID_BUTTON = 101;
	Tizen::Ui::Controls::Button *__pButton;
};

result
AnimationSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Button
	__pButton = new Button();
	__pButton->Construct(Rectangle(10, 200, 460, 100));
	__pButton->SetText(L"Start animation");
	__pButton->SetActionId(ID_BUTTON);
	__pButton->AddActionEventListener(*this);
	AddControl(*__pButton);

	return r;
}

void
AnimationSample::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_BUTTON:
		{
			// Starts an animation
			result r = E_SUCCESS;

			ControlAnimator* pButtonAnimator = __pButton->GetControlAnimator();
			Point startPos = __pButton->GetPosition();
			Point endPos(startPos.x, startPos.y + 200);
			PointAnimation pointAnimation(startPos,
										  endPos,
										  2000,
										  ANIMATION_INTERPOLATOR_LINEAR);

			pointAnimation.SetAutoReverseEnabled(true);

			r = pButtonAnimator->StartUserAnimation(ANIMATION_TARGET_POSITION, pointAnimation);
			if (IsFailed(r))
			{
				AppLog("Start Animation on Button Failed.\n");
				return;
			}
		}
		break;
	}
}
 *	@endcode
 *
 *	@code
// Sample code for Form Transition Animation using FrameAnimator
#include <FUi.h>
#include <FUiAnimations.h>

using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Animations;

bool
FrameAnimatorSample::OnAppInitializing(AppRegistry& appRegistry)
{
	// Creates instances of Form
	Form1 *pForm1 = new Form1();
	pForm1->Initialize();

	Form2* pForm2 = new Form2();
	pForm2->Initialize();

	// Adds forms to the frame
	Frame *pFrame = GetAppFrame()->GetFrame();
	pFrame->AddControl(*pForm1);
	pFrame->AddControl(*pForm2);

	// Sets the current form
	pFrame->SetCurrentForm(*pForm1);

	// Display the form
	pForm1->Invalidate();

	return true;
}

// Transition from Form1 to Form2
void
Form1::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_TRANSIT:
		{
			result r = E_SUCCESS;

			Frame *pFrame = UiApp::GetInstance()->GetAppFrame()->GetFrame();
			FrameAnimator *pFrameAnimator = pFrame->GetFrameAnimator();

			Form *nextForm = static_cast<Form*>(pFrame->GetControl(L"Form2"));

			if(pFrameAnimator->GetStatus() == ANIMATOR_STATUS_STOPPED)
			{
				pFrameAnimator->SetFormTransitionAnimation (FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_TRANSLATE_LEFT,
															1000,
															ANIMATION_INTERPOLATOR_LINEAR );
				r = pFrameAnimator->SetCurrentForm (*nextForm);
				if (IsFailed(r))
				{
					AppLog("SetCurrentForm on the Form2 Failed.\n");
					return;
				}
			}
		}
		break;
	default:
		break;
	}
}

// Transition from Form2 to Form1
void
Form2::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_TRANSIT:
		{
			result r = E_SUCCESS;

			Frame *pFrame = UiApp::GetInstance()->GetAppFrame()->GetFrame();
			FrameAnimator *pFrameAnimator = pFrame->GetFrameAnimator();

			Form *nextForm = static_cast<Form*>(pFrame->GetControl(L"Form1"));
			if(pFrameAnimator->GetStatus() == ANIMATOR_STATUS_STOPPED)
			{
				pFrameAnimator->SetFormTransitionAnimation(FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_TRANSLATE_RIGHT,
														   1000,
														   ANIMATION_INTERPOLATOR_LINEAR );
				r = pFrameAnimator->SetCurrentForm (*nextForm);
				if (IsFailed(r))
				{
					AppLog("SetCurrentForm on the Form1 Failed.\n");
					return;
				}
			}
		}
		break;
	default:
		break;
	}
}
 *	@endcode
 *
 *	@code
 // Sample code for VisualElement and VisualElementAnimation
#include <FApp.h>
#include <FUi.h>
#include <FUiAnimations.h>

using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;

class VisualElementSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Animations::VisualElementContentProvider
{
public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

	virtual void DrawContent(Tizen::Ui::Animations::VisualElement& target, Tizen::Graphics::Canvas& canvas);

private:
	static const int ID_FOOTER_START_ANIMATION = 101;

	Tizen::Ui::Animations::VisualElement* __pRect;
};

result
VisualElementSample::OnInitializing(void)
{
	__pRect = new VisualElement();
	__pRect->Construct();
	__pRect->SetName(L"Rect");
	__pRect->SetBounds(FloatRectangle(50.0f, 50.0f, 200.0f, 200.0f));
	__pRect->SetShowState(true);
	__pRect->SetContentProvider(this);

	GetVisualElement()->AttachChild(*__pRect);
	__pRect->InvalidateRectangle(null);

	return E_SUCCESS;
}

result
VisualElementSample::OnTerminating(void)
{
	__pRect->Destroy();

	return E_SUCCESS;
}

void
VisualElementSample::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_START_ANIMATION:
		{
			VisualElementPropertyAnimation* pAnimation = new VisualElementPropertyAnimation();
			pAnimation->SetPropertyName(L"opacity");
			pAnimation->SetStartValue(1.0f);
			pAnimation->SetEndValue(0.0f);
			pAnimation->SetDuration(500);
			pAnimation->SetAutoReverseEnabled(true);

			__pRect->AddAnimation(*pAnimation);
			delete pAnimation;
		}
		break;

	default:
		break;
	}
}

void
VisualElementSample::DrawContent(Tizen::Ui::Animations::VisualElement& target, Tizen::Graphics::Canvas& canvas)
{
	if (target.GetName() == L"Rect")
	{
		canvas.FillRectangle(Color::GetColor(COLOR_ID_WHITE), Rectangle(0, 0, 200, 200));
	}
}
 *	@endcode
 *
 *
 *
 */

namespace Animations
{
};

} } // Tizen::Ui

#endif // _FUI_ANIMATIONS_H_
