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
* @brief		This class represents a container for accessibility element.
* @since		2.0
*
*
* @final		This class is not intended for extension.
* This class represents a container for accessibility element.
 * The following example demonstrates how to use the %AccessibilityContainer class.
.*
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

 *	@endcode
 *
 * @final		This class is not intended for extension.
 * This class represents a container for accessibility element.
 */
class _OSP_EXPORT_ AccessibilityContainer
	: public Tizen::Base::Object
{
public:
	/**
	 * Gets the owner of the accessibility container
	 *
	 * @since		2.0
	 * @return	The control which owns this %AccessibilityContainer
	 * @see		Control::GetAccessibilityContainer()
	 */
	const Control* GetOwner(void) const;

	/**
	 * Gets the owner of the accessibility container
	 *
	 * @since		2.0
	 * @return	The control which owns this %AccessibilityContainer
	 * @see		Control::GetAccessibilityContainer()
	 */
	Control* GetOwner(void);

	/**
	 * Adds the IAccessibilityListener instance to the %AccessibilityContainer. @n
	 * The added listener gets notified when the accessibility status is changed.
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
	 * The removed listener is not notified even when the accessibility status is changed.
	 *
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
	 * @see		RemoveElement(), RemoveAllElements()
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
	 * @exception E_OBJ_NOT_FOUND	The instance of AccessibilityElement is already registered.
	 * @see		AddElement(), InsertElement()
	 *
	 */
	result RemoveElement(AccessibilityElement& element);

	/**
	 * Removes all of the accessibility elements in the %AccessibilityContainer.
	 *
	 * @since		2.0
	 *
	 * @see		AddElement, InsertElement
	 *
	 */
	void RemoveAllElements(void);

	/**
	 * Gets the instance of accessibility element which is the child of the %AccessibilityContainer by the name.
	 *
	 * @since		2.0
	 *
	 * @return	The instance of child element, if there exists an element which has the given name @n
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
	 * @return	The list of child element, if there exists some elements in the container. @n
	 *			else @c null.
	 *
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
