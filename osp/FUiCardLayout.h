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
 * @file		FUiCardLayout.h
 * @brief		This is the header file for the %CardLayout class.
 *
 * This header file contains the declarations of the %CardLayout class.
 */

#ifndef _FUI_CARD_LAYOUT_H_
#define _FUI_CARD_LAYOUT_H_

#include <FUiLayout.h>

namespace Tizen { namespace Ui
{
class Control;

/**
 * @class	CardLayout
 * @brief	The card layout fits a child control to the container by changing the position and the size of the child control.
 *
 * @since	2.0
 *
 * The %CardLayout class defines the card layout for a container.@n
 *
 * @code
// Sample code for CardLayoutSample.h
#include <FUi.h>

class CardLayoutSample
	: public Tizen::Ui::Controls::Form
{
public:
	bool Initialize(void);
	virtual result OnInitializing(void);
};
 *	@endcode
 *
 *	@code
// Sample code for CardLayoutSample.cpp
#include <FGraphics.h>

#include "CardLayoutSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
CardLayoutSample::Initialize(void)
{
	// Creates an instance of CardLayout
	CardLayout formLayout;
	formLayout.Construct();

	// Applies the card layout to the form
	Construct(formLayout, FORM_STYLE_NORMAL);
	return true;
}

result
CardLayoutSample::OnInitializing(void)
{
	result = E_SUCCESS;

	// Creates an instance of 1st panel
	Panel* pFirstPanel = new Panel();
	pFirstPanel->Construct(Rectangle(0, 0, 50, 50));
	pFirstPanel->SetBackgroundColor(Color(0xFF, 0x40, 0x40, 0xFF));

	// Adds the 1st panel to the form
	AddControl(*pFirstPanel);

	// Creates an instance of 2nd panel
	Panel* pSecondPanel = new Panel();
	pSecondPanel->Construct(Rectangle(0, 0, 50, 50));
	pSecondPanel->SetBackgroundColor(Color(0x40, 0x40, 0xFF, 0xFF));

	// Adds the 2nd panel to the form
	AddControl(*pSecondPanel);

	return r;
}
 * @endcode
 *
 */
class _OSP_EXPORT_ CardLayout
	: public Layout
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	CardLayout(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~CardLayout(void);

	/**
	 * Initializes this instance of %CardLayout.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result Construct(void);

	/**
	 * Gets the type of the layout.
	 *
	 * @since 2.0
	 *
	 * @return	The layout type
	 */
	virtual LayoutType GetLayoutType(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	CardLayout(const CardLayout& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	CardLayout& operator =(const CardLayout& rhs);

}; // CardLayout

}} // Tizen::Ui

#endif // _FUI_CARD_LAYOUT_H_
