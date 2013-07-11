//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FWebCtrlHitElementResult.h
 * @brief		This is the header file for the %HitElementResult class.
 *
 * This header file contains the declarations of the %HitElementResult class.
 */
#ifndef _FWEB_CTRL_HIT_ELEMENT_RESULT_H_
#define _FWEB_CTRL_HIT_ELEMENT_RESULT_H_

#include <FBaseColIMap.h>
#include <FBaseObject.h>
#include <FBaseString.h>

namespace Tizen { namespace Graphics
{
class Bitmap;
}} // Tizen::Graphics

namespace Tizen { namespace Web { namespace Controls
{
class _HitElementResultImpl;
}}} // Tizen::Web::Controls

namespace Tizen { namespace Web { namespace Controls
{

/**
 * @class	HitElementResult
 * @brief		This class provides methods to retrieve information from the HyperText Markup Language (HTML) element, pointed by the x and y coordinates.
 *
 * @since	2.0
 *
 * The %HitElementResult class provides methods to retrieve information from the HTML element, such as tag name, attributes and content.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/controls_namespace.htm">Web Controls Guide</a>.
 *
 */
class _OSP_EXPORT_ HitElementResult
	: public Tizen::Base::Object
{

public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~HitElementResult(void);

	/**
	 * Gets the tag name of an element.
	 *
	 * @since		2.0
	 *
	 * @return		The tag name of the element
	 */
	Tizen::Base::String GetTagName(void) const;

	/**
	 * Gets the value of the specified attribute.
	 *
	 * @since		2.0
	 *
	 * @return      The value of the specified attribute
	 * @param[in]	attributeName			The name of attribute
	 */
	Tizen::Base::String GetAttributeValue(const Tizen::Base::String& attributeName) const;

	/**
	 * Gets the content of an element.
	 *
	 * @since		2.0
	 *
	 * @return		The content of the element
	 */
	Tizen::Base::String GetContent(void) const;

	/**
	*  Gets the Uniform Resource Locator (URL) linked to the element.
	*
	* @since		2.0
	*
	* @return       The URL linked to the element
	*/
	Tizen::Base::String GetUrl(void) const;

	/**
	 * Gets the image if the element is an image element.
	 *
	 * @since		2.0
	 *
	 * @return		The image
	 */
	const Tizen::Graphics::Bitmap* GetImage(void) const;

	/**
	 * Checks whether the element is an image element.
	 *
	 * @since		2.0
	 *
	 * @return      @c true if the element is an image element, @n
	 *				else @c false
	 */
	bool HasImage(void) const;

	/**
	 * Checks whether the element has a URL linked to it.
	 *
	 * @since		2.0
	 *
	 * @return      @c true if there is a URL linked to the element, @n
	 *				else @c false
	 */
	bool HasUrl(void) const;

private:
	//
	// This constructor is intentionally declared as private so that only the platform can create an instance.
	//
	// @remarks		This constructor is hidden.
	//
	HitElementResult(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	element	The instance of the %HitElementResult class to copy from
	// @remarks		This constructor is hidden.
	//
	HitElementResult(const HitElementResult& element);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	source	The instance of the %HitElementResult class to assign from
	// @remarks		This operator is hidden.
	//
	HitElementResult& operator =(const HitElementResult& source);

private:
	_HitElementResultImpl* __pHitElementResultImpl;

	friend class _HitElementResultImpl;

	friend class _WebImpl;
}; // HitElementResult

}}} // Tizen::Web::Controls
#endif // _FWEB_CTRL_HIT_ELEMENT_RESULT_H_
