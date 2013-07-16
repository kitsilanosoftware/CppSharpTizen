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
 * @file	FUiAnimIVisualElementContentProvider.h
 * @brief	This is the header file for the %IVisualElementContentProvider interface.
 *
 * This header file contains the declarations of the %IVisualElementContentProvider interface.
 */

#ifndef _FUI_ANIM_IVISUAL_ELEMENT_CONTENT_PROVIDER_H_
#define _FUI_ANIM_IVISUAL_ELEMENT_CONTENT_PROVIDER_H_

#include <FOspConfig.h>
#include <FUiAnimTypes.h>

namespace Tizen { namespace Graphics {
class Canvas;
class FloatPoint;
}} // Tizen::Graphics

namespace Tizen { namespace Ui { namespace Animations
{
class VisualElement;


/**
 * @interface           IVisualElementContentProvider
 * @brief This interface customizes content of VisualElement.
 *
 * @since          2.0
 *
 * The %IVisualElementContentProvider interface is the listener interface for providing content and information on it. The class that needs to customize content must implement this interface, and
 * use the VisualElement::SetContentProvider() method to register to the VisualElement.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/visualelement_content.htm">Content Provider</a>.
 *
 */
class _OSP_EXPORT_ IVisualElementContentProvider
{
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~IVisualElementContentProvider(void) {}

public:
	/**
	 * %PrepareDraw() is invoked by UI framework before DrawContent() is called.
	 * If this method returns @c true, VisualElement can call the %DrawContent() method.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if DrawContent() can be called, @n
     *              else @c false
	 * @param[in]	target			An instance of VisualElement to check
	 */
	virtual bool PrepareDraw(Tizen::Ui::Animations::VisualElement& target) = 0;


	/**
	 * Fills content in the given canvas.
	 *
	 * @since		2.0
	 *
	 * @param[in]	target			An instance of VisualElement to draw
	 * @param[in]	canvas			A graphic canvas for drawing
	 * @see VisualElement::OnDraw()
	 * @see	VisualElement::InvalidateRectangle()
	 */
	virtual void DrawContent(Tizen::Ui::Animations::VisualElement& target, Tizen::Graphics::Canvas& canvas) = 0;


	/**
	 * The %HitTest() method is called by VisualElement::GetChildAt(). @n
	 * The %GetChildAt() method traverses through a list of all children, and performs a hit test search at the @c point using this method.
	 * You can modify hit test search result by overriding this method.
	 *
	 * @since		2.0
	 *
	 * @return		The hit test result
	 * @param[in]	target			An instance of VisualElement to test
	 * @param[in]	point			The position of the source to check
	 * @remarks		Hit test results must be one of the following: @n
	 * 			 - Tizen::Ui::Animations::HitTestResult::HIT_TEST_NOWHERE
	 *			 - Tizen::Ui::Animations::HitTestResult::HIT_TEST_MATCH
	 * @see VisualElement::GetChildAt()
	 */
	virtual HitTestResult HitTest(Tizen::Ui::Animations::VisualElement& target, const Tizen::Graphics::FloatPoint& point) = 0;


protected:
	// Reserved virtual methods for later extension.
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementContentProvider_Reserved1(void) {}


	// Reserved virtual methods for later extension.
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementContentProvider_Reserved2(void) {}


	// Reserved virtual methods for later extension.
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementContentProvider_Reserved3(void) {}


	// Reserved virtual methods for later extension.
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementContentProvider_Reserved4(void) {}


	// Reserved virtual methods for later extension.
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void IVisualElementContentProvider_Reserved5(void) {}
};		// IVisualElementContentProvider


}}}		// Tizen::Ui::Animations

#endif //_FUI_ANIM_IVISUAL_ELEMENT_CONTENT_PROVIDER_H_
