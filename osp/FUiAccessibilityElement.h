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
 * @file        FUiAccessibilityElement.h
 * @brief       This is the header file for the AccessibilityElement class.
 *
 * This header file contains the declarations of the AccessibilityElement class.
 *
 */

#ifndef _FUI_ACCESSIBILITY_ELEMENT_H_
#define _FUI_ACCESSIBILITY_ELEMENT_H_

#include <FOspConfig.h>
#include <FBaseObject.h>
#include <FUiAccessibilityTypes.h>

namespace Tizen { namespace Base
{
	class String;
}} //Tizen::Base

namespace Tizen { namespace Graphics
{
	class Rectangle;
	class FloatRectangle;
}} //Tizen::Graphics

namespace Tizen { namespace Ui
{
class _AccessibilityElementImpl;

/**
* @class		AccessibilityElement
* @brief		This class represents an accessibility element.
* @since		2.0
*
* @final		This class is not intended for extension.
*
* This class represents an accessibility element.
*/
class _OSP_EXPORT_ AccessibilityElement
	: public Tizen::Base::Object
{
public:
	/**
	* The object is not fully constructed after this constructor is called. @n
	* For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since		2.0
	*/
	AccessibilityElement(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since		2.0
	*/
	virtual ~AccessibilityElement(void);

	/**
	* Initializes the instance of %AccessibilityElement with the specified parameters.
	*
	* @since		2.0
	*
	* @return	An error code
	* @param[in] bounds	The bounds of the accessibility element
	* @param[in] name	The name of the accessibility element
	* @exception E_SUCCESS	The method is successful.
	* @exception E_INVALID_ARG	Either the length of name parameter is @c 0, or the bounds are smaller than @c 0.
	*/
	result Construct(const Tizen::Graphics::Rectangle& bounds, const Tizen::Base::String& name);

	/**
	* Initializes this instance of %AccessibilityElement with specified parameters.
	*
	* @since		2.1
	*
	* @return	An error code
	* @param[in] bounds	The bounds  of the accessibility element
	* @param[in] name	The name of the accessibility element
	* @exception E_SUCCESS	The method is successful.
	* @exception E_INVALID_ARG	Either the length of @c name parameter is @c 0, or the @c bounds are smaller than @c 0.
	*/
	result Construct(const Tizen::Graphics::FloatRectangle& bounds, const Tizen::Base::String& name);

	/**
	* Gets the name of the element.
	*
	* @since		2.0
	* @return	The name of the element
	*/
	Tizen::Base::String GetName(void) const;

	/**
	* Sets the bounds to the element.
	*
	* @since		2.0
	* @param[in] bounds	The bounds of the accessibility element
	*/
	void SetBounds(const Tizen::Graphics::Rectangle& bounds);

	/**
	* Sets the bounds of an element.
	*
	* @since		2.1
	* @param[in] bounds	The bounds of the accessibility element
	*/
	void SetBounds(const Tizen::Graphics::FloatRectangle& bounds);

	/**
	* Gets the bounds of the element.
	*
	* @since		2.0
	* @return	The bounds of the element
	*/
	Tizen::Graphics::Rectangle GetBounds(void) const;

	/**
	* Gets the bounds of an element.
	*
	* @since		2.1
	* @return	The bounds of the element
	*/
	Tizen::Graphics::FloatRectangle GetBoundsF(void) const;

	/**
	* Sets the label to the element.
	*
	* @since		2.0
	* @param[in] label	The label of the accessibility element
	*/
	void SetLabel(const Tizen::Base::String& label);

	/**
	* Gets the label of the element.
	*
	* @since		2.0
	* @return	The label of the element
	*/
	Tizen::Base::String GetLabel(void) const;

	/**
	* Sets the hint to the element.
	*
	* @since		2.0
	* @param[in] hint	The hint of the accessibility element
	*/
	void SetHint(const Tizen::Base::String& hint);

	/**
	* Gets the hint of the element.
	*
	* @since		2.0
	* @return	The hint of the element
	*/
	Tizen::Base::String GetHint(void) const;

	/**
	* Sets the trait to the element.
	*
	* @since		2.0
	* @param[in] trait	The trait of the accessibility element
	*/
	void SetTrait(const Tizen::Base::String& trait);


	/**
	* Gets the trait of the element.
	*
	* @since		2.0
	* @return	The trait of the element
	*/
	Tizen::Base::String GetTrait(void) const;

	/**
	* Sets the value to the element.
	*
	* @since		2.0
	* @param[in] value	The value of the accessibility element
	*/
	void SetValue(const Tizen::Base::String& value);

	/**
	* Gets the value of the element.
	*
	* @since		2.0
	* @return	The value of the element
	*/
	Tizen::Base::String GetValue(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	AccessibilityElement(const AccessibilityElement& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	AccessibilityElement& operator =(const AccessibilityElement& rhs);

private:
	friend class _AccessibilityElementImpl;
	_AccessibilityElementImpl* __pAccessibilityElementImpl;
}; // AccessibilityElement

}} // Tizen::Ui
#endif //_FUI_ACCESSIBILITY_ELEMENT_H_