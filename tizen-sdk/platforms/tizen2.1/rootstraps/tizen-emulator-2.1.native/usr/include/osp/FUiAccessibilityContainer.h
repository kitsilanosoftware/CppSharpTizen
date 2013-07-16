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
 * @file         FUiAccessibilityContainer.h
 * @brief         This is the header file for the AccessibilityContainer class.
 *
 * This header file contains the declarations of the AccessibilityContainer class.
 */

#ifndef _FUI_ACCESSIBILITY_CONTAINER_H_
#define _FUI_ACCESSIBILITY_CONTAINER_H_

#include <FOspConfig.h>
#include <FBaseObject.h>
#include <FUiAccessibilityTypes.h>

namespace Tizen { namespace Base
{
class String;
}} // Tizen::Base

namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}} //Tizen::Base::Collection


namespace Tizen { namespace Ui
{

class Control;
class AccessibilityElement;
class IAccessibilityListener;
class _AccessibilityContainerImpl;

/**
* @class		AccessibilityContainer
* @brief		This class represents a container for an accessibility element.
* @since		2.0
*
*
* @final		This class is not intended for extension.
*
* This class represents a container for an accessibility element. @n
* The following example demonstrates how to use the %AccessibilityContainer class.
*
* @code
// Sample code for AccessibilitySample.h
#include <FGraphics.h>
#include <FUi.h>

class AccessibilitySample
	: public Tizen::Ui::Controls::Form
{
public:
	AccessibilitySample(void);
	virtual ~AccessibilitySample(void);

	result Initialize(void);

	virtual result OnInitializing(void);


private:
	static const int ID_FOOTER_ITEM1 = 101;
	static const int ID_FOOTER_ITEM2 = 102;

	Tizen::Graphics::Bitmap *__pTizenBitmap;
};

// Sample code for AccessibilitySample.cpp
#include "FApp.h"
#include "FMedia.h"
#include "AccessibilitySample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

AccessibilitySample::AccessibilitySample(void)
	: __pTizenBitmap(null)
{
}

AccessibilitySample::~AccessibilitySample(void)
{
	delete __pTizenBitmap;
	__pTizenBitmap = null;
}

result
AccessibilitySample::Initialize(void)
{
	Image image;
	result r = Form::Construct(FORM_STYLE_NORMAL| FORM_STYLE_INDICATOR| FORM_STYLE_HEADER| FORM_STYLE_FOOTER);
	r = image.Construct();
	String filepath = App::GetInstance()->GetAppResourcePath() + L"screen-density-xhigh/tizen.png";

	__pTizenBitmap = image.DecodeN(filepath, BITMAP_PIXEL_FORMAT_ARGB8888);
	return r;
}

result
AccessibilitySample::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header * pHeader = GetHeader();
	if (pHeader != null)
	{
		pHeader->SetStyle(HEADER_STYLE_TITLE);
		pHeader->SetTitleText(L"Accessibility Sample");
	}

	//Draws an image
	Canvas* pCanvas = GetCanvasN();
	Rectangle rt = pCanvas->GetBounds();
	int width = rt.width;
	int height = rt.width * __pTizenBitmap->GetHeight() / __pTizenBitmap->GetWidth();
	r = pCanvas->DrawBitmap(Rectangle(rt.x, (rt.y + ( (rt.height - height) / 2)), width, height), *__pTizenBitmap);

	//Makes an accessibility element for the drawn image
	AccessibilityElement* pAccessibilityElement = new AccessibilityElement();
	r = pAccessibilityElement->Construct(GetBounds(), L"Tizen Image");
	pAccessibilityElement->SetLabel(L"Tizen Image");
	pAccessibilityElement->SetTrait(L"Image");
	pAccessibilityElement->SetHint(L"This image rotates automatically.");
	GetAccessibilityContainer()->AddElement(*pAccessibilityElement);
	pAccessibilityElement->SetBounds(Rectangle(rt.x, (rt.y + ( (rt.height - height) / 2)), width, height));

	Footer* pFooter = GetFooter();
	if (pFooter != null)
	{
		pFooter->SetStyle(FOOTER_STYLE_TAB);

		FooterItem footerItem1;
		footerItem1.Construct(ID_FOOTER_ITEM1);
		footerItem1.SetText(L"Item1");
		pFooter->AddItem(footerItem1);

		FooterItem footerItem2;
		footerItem2.Construct(ID_FOOTER_ITEM2);
		footerItem2.SetText(L"Item2");
		pFooter->AddItem(footerItem2);

		//Sets an information to the system accessibility element
		AccessibilityContainer* pContainer = pFooter->GetAccessibilityContainer();
		AccessibilityElement* pElement = pContainer->GetElement(L"Tab2Text");
		pElement->SetHint(L"Test accessibility");
	}
	delete pCanvas;
	Invalidate(true);
	return r;
}
 * @endcode
 *
 */

class _OSP_EXPORT_ AccessibilityContainer
	: public Tizen::Base::Object
{
public:
	/**
	* Gets the owner of the accessibility container
	*
	* @since		2.0
	* @return	A pointer to the control which owns this %AccessibilityContainer @n
	*			It cannot be @c null.
	* @see		Control::GetAccessibilityContainer()
	*/
	const Control* GetOwner(void) const;

	/**
	* Gets the owner of the accessibility container
	*
	* @since		2.0
	* @return	A pointer to the control which owns this %AccessibilityContainer @n
	*			It cannot be @c null.
	* @see		Control::GetAccessibilityContainer()
	*/
	Control* GetOwner(void);

	/**
	* Adds the IAccessibilityListener instance to the %AccessibilityContainer. @n
	* The added listener gets notified when the accessibility status has been changed.
	*
	* @since		2.0
	* @return An error code
	* @param[in] listener	The event listener to add
	* @exception E_SUCCESS	The method is successful.
	* @exception E_OBJ_ALREADY_EXIST	The instance of IAccessibilityListener is already registered.
	* @see		RemoveAccessibilityListener()
	*/
	result AddAccessibilityListener(IAccessibilityListener& listener);

	/**
	* Removes the IAccessibilityListener listener instance. @n
	* The removed listener is not notified even when the accessibility status has been changed.
	*
	* @since		2.0
	* @return An error code
	* @param[in] listener	The listener to remove
	* @exception E_SUCCESS	The method is successful.
	* @exception E_OBJ_NOT_FOUND	The instance of listener is not found.
	* @see		AddAccessibilityListener()
	*/
	result RemoveAccessibilityListener(IAccessibilityListener& listener);

	/**
	* Adds the accessibility element to the %AccessibilityContainer.
	*
	* @since		2.0
	* @return An error code
	* @param[in] element	The instance of AccessibilityElement
	* @exception E_SUCCESS	The method is successful.
	* @exception E_OBJ_ALREADY_EXIST	The instance of AccessibilityElement is already registered.
	* @see		RemoveElement()
	* @see		RemoveAllElements()
	*
	*/
	result AddElement(AccessibilityElement& element);

	/**
	* Removes the accessibility element in the %AccessibilityContainer.
	*
	* @since		2.0
	*
	* @return An error code
	*
	* @param[in] element	The instance of AccessibilityElement
	*
	* @exception E_SUCCESS	The method is successful.
	* @exception E_OBJ_NOT_FOUND	The instance of AccessibilityElement is not found.
	* @see		AddElement()
	*
	*/
	result RemoveElement(AccessibilityElement& element);

	/**
	* Removes all of the accessibility elements in the %AccessibilityContainer.
	*
	* @since		2.0
	*
	* @see		AddElement()
	*
	*/
	void RemoveAllElements(void);

	/**
	* Gets the instance of the accessibility element which is the child of the %AccessibilityContainer by the name.
	*
	* @since		2.0
	*
	* @return	The instance to the child element, if there exists an element which has the given name, @n
	*			else @c null
	*
	* @param[in] name The name of AccessibilityElement
	*
	*/
	AccessibilityElement* GetElement(const Tizen::Base::String& name) const;

	/**
	* Gets the list of accessibility elements that are the child of the %AccessibilityContainer.
	*
	* @since		2.0
	*
	* @return	A pointer to the list of the child element, if there exists some elements in the container, @n
	*			else @c null
	*/
	Tizen::Base::Collection::IList* GetElementsN(void) const;

private:
	//
	// This default constructor is intentionally declared as private so that only the platform can create an instance
	//
	AccessibilityContainer(void);

	//
	// This destructor is intentionally declared as private so that only the platform can delete an instance.
	//
	virtual ~AccessibilityContainer(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	AccessibilityContainer(const AccessibilityContainer& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	AccessibilityContainer& operator =(const AccessibilityContainer& rhs);

private:
	_AccessibilityContainerImpl* __pAccessibilityContainerImpl;
	friend class _AccessibilityContainerImpl;
}; // AccessibilityContainer

}} // Tizen::Ui
#endif //_FUI_ACCESSIBILITY_CONTAINER_H_
