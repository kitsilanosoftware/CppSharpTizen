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
 * @file		FUiLayout.h
 * @brief		This is the header file for the %Layout class.
 *
 * This header file contains the declarations of the %Layout class.
 */

#ifndef _FUI_LAYOUT_H_
#define _FUI_LAYOUT_H_

#include <FBaseObject.h>
#include <FUiLayoutTypes.h>

namespace Tizen { namespace Ui
{

/**
 * @class	Layout
 * @brief	This class is the abstract base class of all the %Layout classes.
 *
 * @since	2.0
 *
 * The %Layout class is the abstract base class of all the %Layout classes.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/layout.htm">Layout</a>.
 */
class _OSP_EXPORT_ Layout
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Layout(void);

	/**
	 * Gets the type of the layout.
	 *
	 * @since	2.0
	 *
	 * @return	The layout type
	 */
	virtual LayoutType GetLayoutType(void) const = 0;

	/**
	 * Updates the layout.
	 *
	 * @since 2.0
	 *
	 * @return        An error code
	 *
	 * @exception     E_SUCCESS                           The method is successful.
	 */
	result Update(void);

protected:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	Layout(void);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Layout(const Layout& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Layout& operator =(const Layout& rhs);

protected:
	void* _pImpl;
	friend class _LayoutImpl;
}; // Layout

}} // Tizen::Ui

#endif // _FUI_LAYOUT_H_
