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
 * @file	FUiCtrlICustomElement.h
 * @brief	This is the header file for the %ICustomElement interface.
 *
 * This header file contains the declarations of %ICustomElement and its helper classes.
 */

#ifndef _FUI_CTRL_ICUSTOM_ELEMENT_H_
#define _FUI_CTRL_ICUSTOM_ELEMENT_H_

#include <FBaseObject.h>
#include <FGrpCanvas.h>
#include <FUiCtrlListViewTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @interface	ICustomElement
 * @brief       This interface represents the common behaviors of a custom element.
 *
 * @since		2.0
 *
 * The %ICustomElement interface is the listener interface for custom drawing in a list item.
 * The class that processes a custom drawing event implements this interface. The list items are added by calling the
 * AddElement(int elementId, const %ICustomElement &element) method. When the custom drawing event occurs and the list item must be
 * redrawn, the OnDraw() method is invoked.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_listviews.htm">ListViews</a>.
 *
 */
class _OSP_EXPORT_ ICustomElement
{
public:
	/**
	 * This polymorphic destructor should be overridden if required.@n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~ICustomElement(void) {}

// Operation
public:
	/**
	 * Called when a custom element of the item is drawn.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the drawing is successful, @n
	 *           else @c false
	 * @param[in] canvas      The graphic canvas of the list control
	 * @param[in] rect        The position and size of the element
	 * @param[in] status      The status of the element
	 * @remarks  This method must return @c true if the drawing is successful, else @c false.
	 */
	virtual bool OnDraw(Tizen::Graphics::Canvas& canvas, const Tizen::Graphics::Rectangle& rect, Tizen::Ui::Controls::ListItemDrawingStatus status) = 0;

protected:
	//
	// The following methods are reserved and may change its name at any time without prior notice.
	//
	virtual void ICustomElement_Reserved1(void) {}
	virtual void ICustomElement_Reserved2(void) {}
	virtual void ICustomElement_Reserved3(void) {}
}; // ICustomElement

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_ICUSTOM_ELEMENT_H_

