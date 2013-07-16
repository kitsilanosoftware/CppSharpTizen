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
 * @file	FUiCtrlICustomElementF.h
 * @brief	This is the header file for the %ICustomElementF class.
 *
 * This header file contains the declarations of the %ICustomElementF class and its helper classes.
 */

#ifndef _FUI_CTRL_ICUSTOM_ELEMENT_F_H_
#define _FUI_CTRL_ICUSTOM_ELEMENT_F_H_

#include <FBaseObject.h>
#include <FGrpCanvas.h>
#include <FUiCtrlListViewTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @interface	ICustomElementF
 * @brief       This interface represents the common behaviors of a custom element.
 *
 * @since		2.1
 *
 * The %ICustomElementF interface is the listener interface for custom drawing in a list item.
 * The class that processes a custom drawing event implements this interface. The list items are added by calling the
 * AddElement(int elementId, const %ICustomElementF &element) method. When the custom drawing event occurs and the list item must be
 * redrawn, the OnDraw() method is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 *
 */
class _OSP_EXPORT_ ICustomElementF
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~ICustomElementF(void) {}

// Operation
public:
	/**
	 * Called when a custom element of the item is drawn.
	 *
	 * @since	2.1
	 *
	 * @return	@c true if the drawing is successful, @n
	 *           else @c false
	 * @param[in] canvas      The graphic canvas of the list control
	 * @param[in] rect        The position and size of the element
	 * @param[in] status      The status of the element
	 * @remarks  This method must return @c true if the drawing is successful, else @c false.
	 */
	virtual bool OnDraw(Tizen::Graphics::Canvas& canvas, const Tizen::Graphics::FloatRectangle& rect, Tizen::Ui::Controls::ListItemDrawingStatus status) = 0;

protected:
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void ICustomElementF_Reserved1(void) {}
	virtual void ICustomElementF_Reserved2(void) {}
	virtual void ICustomElementF_Reserved3(void) {}
}; // ICustomElementF

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ICUSTOM_ELEMENT_F_H_

