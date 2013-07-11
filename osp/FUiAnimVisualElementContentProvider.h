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
 * @file		FUiAnimVisualElementContentProvider.h
 * @brief		This is the header file for the %VisualElementContentProvider class.
 *
 * This header file contains the declarations of the %VisualElementContentProvider class.
 */

#ifndef _FUIANIM_VISUAL_ELEMENT_CONTENT_PROVIDER_H_
#define _FUIANIM_VISUAL_ELEMENT_CONTENT_PROVIDER_H_

#include <FUiAnimIVisualElementContentProvider.h>

namespace Tizen { namespace Graphics {
class Canvas;
class FloatPoint;
}} // Tizen::Graphics

namespace Tizen { namespace Ui { namespace Animations
{

class VisualElement;

/**
* @class           VisualElementContentProvider
* @brief           This class customizes content of VisualElement.
*
* @since          2.0
*
* The %VisualElementContentProvider class provides the content and information on it. The class that needs to customize content must implement this interface, and
* using the VisualElement::SetContentProvider() method register to the VisualElement.
* This class implements IVisualElementContentProvider for the default operation of the contents.
*/
class _OSP_EXPORT_ VisualElementContentProvider
	: public IVisualElementContentProvider
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	VisualElementContentProvider(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~VisualElementContentProvider(void);

public:
	/**
	 * Checks whether the %PrepareDraw() method is invoked by UI framework before DrawContent() is called. @n
	 * If this method returns @c true, VisualElement can call the %DrawContent() method.
	 *
	 * @since		2.0
	 *
	 * @return  @c true if DrawContent() can be called, @n
	 *              else @c false
	 * @param[in]	target			The VisualElement instance to check
	 */
	virtual bool PrepareDraw(VisualElement& target);


	/**
	 * Fills the contents in the given canvas.
	 *
	 * @since		2.0
	 *
	 * @param[in]	target			The VisualElement instance to draw
	 * @param[in]	canvas			The graphic canvas for drawing
	 * @see VisualElement::OnDraw()
	 * @see	VisualElement::InvalidateRectangle()
	 */
	virtual void DrawContent(VisualElement& target, Tizen::Graphics::Canvas& canvas);


	/**
	 * The %HitTest() method is called by VisualElement::GetChildAt(). @n
	 * The %VisualElement::GetChildAt() method traverses through a list of all the children, and performs a hit test search at the @c point using this method. @n
	 * You can modify hit test search result by overriding this method.
	 *
	 * @since		2.0
	 *
	 * @return		The hit test result
	 * @param[in]	target			The VisualElement target to test
	 * @param[in]	point			The position of source to check
	 * @remarks		Hit test results must be one of the following: @n
	 * 			 - Tizen::Ui::Animations::HitTestResult::HIT_TEST_NOWHERE
	 *			 - Tizen::Ui::Animations::HitTestResult::HIT_TEST_MATCH
	 * @see VisualElement::GetChildAt()
	 */
	virtual HitTestResult HitTest(VisualElement& target, const Tizen::Graphics::FloatPoint& point);

private:
	VisualElementContentProvider(const VisualElementContentProvider& value);
	VisualElementContentProvider& operator =(const VisualElementContentProvider& value);

};		// VisualElementContentProvider


}}}		// Tizen::Ui::Animations

#endif //_FUIANIM_VISUAL_ELEMENT_CONTENT_PROVIDER_H_
