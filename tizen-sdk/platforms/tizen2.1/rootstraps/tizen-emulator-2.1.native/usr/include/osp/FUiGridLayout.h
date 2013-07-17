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
 * @file		FUiGridLayout.h
 * @brief		This is the header file for the %GridLayout class.
 *
 * This header file contains the declarations of the %GridLayout class.
 */

#ifndef _FUI_GRID_LAYOUT_H_
#define _FUI_GRID_LAYOUT_H_

#include <FUiLayout.h>

namespace Tizen { namespace Ui
{
class Control;

/**
 * @class	GridLayout
 * @brief	The grid layout positions the children of a container in a rectangular grid.
 *
 * @since	2.0
 *
 * The %GridLayout class defines the grid layout for a Container. The layout positions the children of the %Container in a rectangular grid.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/grid_layout.htm">Grid Layout</a>.
 *
 * @code
// Sample code for GridLayoutSample.h
#include <FUi.h>

class GridLayoutSample
	: public Tizen::Ui::Controls::Form
{
public:
	bool Initialize(void);
	virtual result OnInitializing(void);
};
 *	@endcode
 *
 *	@code
// Sample code for GridLayoutSample.cpp
#include <FGraphics.h>

#include "GridLayoutSample.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
GridLayoutSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
GridLayoutSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of GridLayout
	GridLayout gridPanelLayout;
	gridPanelLayout.Construct(2, 3);

	// Creates an instance of Panel and applies it to grid layout
	Panel* pPanel = new Panel();
	pPanel->Construct(gridPanelLayout, Rectangle((GetClientAreaBounds().width - 440)/2, (GetClientAreaBounds().height - 700)/2, 440, 700));
	{
		// Creates instances of Label and an instance of Button
		Label* pLabel1 = new Label();
		pLabel1->Construct(Rectangle(0, 0, 100, 200), L"Label1\n(0, 0)");
		pLabel1->SetBackgroundColor(Color(0x00, 0x10, 0x80, 0xFF));
		pPanel->AddControl(pLabel1);

		Label* pLabel2 = new Label();
		pLabel2->Construct(Rectangle(0, 0, 100, 200), L"Label2\n(0, 1)");
		pLabel2->SetBackgroundColor(Color(0x00, 0x20, 0xA0, 0xFF));
		pPanel->AddControl(pLabel2);

		Label* pLabel3 = new Label();
		pLabel3->Construct(Rectangle(0, 0, 100, 200), L"Label3\n(0, 2)");
		pLabel3->SetBackgroundColor(Color(0x00, 0x30, 0xC0, 0xFF));
		pPanel->AddControl(pLabel3);

		Label* pLabel4 = new Label();
		pLabel4->Construct(Rectangle(0, 0, 100, 200), L"Label4\n(1, 0)");
		pLabel4->SetBackgroundColor(Color(0x00, 0x40, 0xE0, 0xFF));
		pPanel->AddControl(pLabel4);

		Button* pButton = new Button();
		pButton->Construct(Rectangle(0, 0, 100, 200), L"Button\n(1, 1)");
		pPanel->AddControl(pButton);

		// Sets position to each label and button in grid layout
		gridPanelLayout.SetPosition(*pLabel1, 0, 0, 1, 1);
		gridPanelLayout.SetPosition(*pLabel2, 0, 1, 1, 1);
		gridPanelLayout.SetPosition(*pLabel3, 0, 2, 1, 1);
		gridPanelLayout.SetPosition(*pLabel4, 1, 0, 1, 1);
		gridPanelLayout.SetPosition(*pButton, 1, 1, 1, 2);

		// Sets stretchability each label and button in grid layout
		gridPanelLayout.SetColumnStretchable(0, true);
		gridPanelLayout.SetColumnStretchable(1, true);
		gridPanelLayout.SetColumnStretchable(2, true);
		gridPanelLayout.SetRowStretchable(1, true);

		// Sets spacing
		gridPanelLayout.SetColumnSpacing(1, 10);
		gridPanelLayout.SetRowSpacing(1, 10);
	}

	// Adds the top panel to the form
	AddControl(pPanel);

	return r;
}
 * @endcode
 *
 */

class _OSP_EXPORT_ GridLayout
	: public Layout
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	GridLayout(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~GridLayout(void);

	/**
	 * Initializes this instance of %GridLayout with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rowCount		The number of rows
	 * @param[in]	columnCount		The number of columns
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified index is out of range. @n
	 *								Either @c rowCount or @c columnCount is @c 0 or negative.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result Construct(int rowCount, int columnCount);

	/**
	 * Gets the type of the layout.
	 *
	 * @since	2.0
	 *
	 * @return	The layout type
	 */
	virtual LayoutType GetLayoutType(void) const;

	/**
	 * Gets the number of rows in a grid layout.
	 *
	 * @since		2.0
	 *
	 * @return		The number of rows
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetRowCount(void) const;

	/**
	 * Gets the number of columns in a grid layout.
	 *
	 * @since		2.0
	 *
	 * @return		The number of columns
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetColumnCount(void) const;

	/**
	 * Sets the stretching ability of the specified column.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	columnIndex		The column index
	 * @param[in]	stretchable		Set to @c true to make the column stretchable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetColumnStretchable(int columnIndex, bool stretchable);

	/**
	 * Sets the shrinking ability of the specified column.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	columnIndex		The column index
	 * @param[in]	shrinkable		Set to @c true to make the column shrinkable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetColumnShrinkable(int columnIndex, bool shrinkable);

	/**
	 * Sets the collapsibility of a column.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	columnIndex		The column index
	 * @param[in]	collapsed		Set to @c true to make the column collapsible, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetColumnCollapsed(int columnIndex, bool collapsed);

	/**
	 * Sets the stretching ability of all the columns.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	stretchable		Set to @c true to set all columns as stretchable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetAllColumnsStretchable(bool stretchable);

	/**
	 * Sets the shrinking ability of all the columns.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	shrinkable		Set to @c true to set all columns as shrinkable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetAllColumnsShrinkable(bool shrinkable);

	/**
	 * Sets the space before the specified column index.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	columnIndex		The column index
	 * @param[in]	space			An @c int representing the space
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method does not perform any operation if the value of @c columnIndex is 0.
	 * @remarks		The column spacing cannot be applied to the first column.
	 */
	result SetColumnSpacing(int columnIndex, int space);

	/**
	 * Sets the space before the specified column index.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	columnIndex		The column index
	 * @param[in]	space			An @c int representing the space
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method does not perform any operation if the value of @c columnIndex is 0.
	 * @remarks		The column spacing cannot be applied to the first column.
	 */
	result SetColumnSpacing(int columnIndex, float space);

	/**
	 * Sets the stretching ability of the specified row.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rowIndex		The row index
	 * @param[in]	stretchable		Set to @c true to make the row stretchable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetRowStretchable(int rowIndex, bool stretchable);

	/**
	 * Sets the shrinking ability of the specified row.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rowIndex		The row index
	 * @param[in]	shrinkable		Set to @c true to make the row shrinkable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetRowShrinkable(int rowIndex, bool shrinkable);

	/**
	 * Sets the collapsibility of the specified row.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rowIndex		The row index
	 * @param[in]	collapsed		Set to @c true to make the row as collapsible, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetRowCollapsed(int rowIndex, bool collapsed);

	/**
	 * Sets the stretching ability of all the rows.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	stretchable		Set to @c true to set all the rows as stretchable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetAllRowsStretchable(bool stretchable);

	/**
	 * Sets the shrinking ability of all the rows.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	shrinkable		Set to @c true to set all the rows as shrinkable, @n
	 *								else @c false
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	result SetAllRowsShrinkable(bool shrinkable);

	/**
	 * Sets the space before the specified column index.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rowIndex		The row index
	 * @param[in]	space			An @c int representing the space
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method does not perform any operation if the value of @c rowIndex is @c 0.
	 * @remarks		The row spacing cannot be applied to the first column.
	 */
	result SetRowSpacing(int rowIndex, int space);

	/**
	 * Sets the space before the specified column index.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rowIndex		The row index
	 * @param[in]	space			An @c int representing the space
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The specified index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		This method does not perform any operation if the value of @c rowIndex is @c 0.
	 * @remarks		The row spacing cannot be applied to the first column.
	 */
	result SetRowSpacing(int rowIndex, float space);

	/**
	 * Sets the position and span of the control. @n
	 * Adds the control at the specified position.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl		The control for which the position is set
	 * @param[in]	rowStartIndex		The row index
	 * @param[in]	columnStartIndex	The column index
	 * @param[in]	rowSpan				The row span specifies the total number of cells in a row that are merged into a cell
	 * @param[in]	columnSpan			The column span specifies the total number of cells in a column that are merged into a cell
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG   	Either of the following conditions has occurred: @n
	 *									- A specified input parameter is invalid. @n
	 *									- Either @c rowSpan or @c columnSpan is @c 0 or negative. @n
	 *									- The specified @c childControl parameter is not a child of the container that owns the layout. @n
	 *									- The specified span has tried to include a cell, which is already included in another span.
	 * @exception	E_OUT_OF_RANGE		The specified index is out of range, or @n
	 *									the calculated range of the cell is out of the grid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetPosition(Control& childControl, int rowStartIndex, int columnStartIndex, int rowSpan, int columnSpan);

	/**
	 * Sets the horizontal alignment and the vertical alignment.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl		The control for which the alignment is set
	 * @param[in]	horizontalAlignment	The horizontal alignment
	 * @param[in]	verticalAlignment	The vertical alignment
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG   	A specified input parameter is invalid. @n
	 *									The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		          			By default, the value of @c horizontalAlignment is HORIZONTAL_ALIGN_LEFT and the value of @c verticalAlignment is
	 *									VERTICAL_ALIGN_TOP.
	 *				          			The column width is set to the largest width amongst controls in the column, and the row height is set to the largest
	 *									height amongst controls in the row.
	 *				          			Therefore, the smaller controls have vertical or horizontal margins around them, and they are repositioned in cells
	 *									according to the alignment options.
	 */
	result SetAlignment(Control& childControl, LayoutHorizontalAlignment horizontalAlignment, LayoutVerticalAlignment verticalAlignment);

	/**
	 * Sets the margins of the specified control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the margins are set
	 * @param[in]	left			The left margin
	 * @param[in]	right			The right margin
	 * @param[in]	top				The top margin
	 * @param[in]	bottom			The bottom margin
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   A specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the margins are set to @c 0.
	 */
	result SetMargin(Control& childControl, int left, int right, int top, int bottom);

	/**
	 * Sets the margins of the specified control.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	childControl	The control for which the margins are set
	 * @param[in]	left			The left margin
	 * @param[in]	right			The right margin
	 * @param[in]	top				The top margin
	 * @param[in]	bottom			The bottom margin
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG   A specified input parameter is invalid. @n
	 *								The specified @c childControl parameter is not a child of the container that owns the layout.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		By default, the margins are set to @c 0.
	 */
	result SetMargin(Control& childControl, float left, float right, float top, float bottom);
private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	GridLayout(const GridLayout& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	GridLayout& operator =(const GridLayout& rhs);
}; // GridLayout

}} // Tizen::Ui

#endif // _FUI_GRID_LAYOUT_H_
