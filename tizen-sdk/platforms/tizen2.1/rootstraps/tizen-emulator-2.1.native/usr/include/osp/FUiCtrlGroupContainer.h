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
* @file                 FUiCtrlGroupContainer.h
* @brief               This is the header file for the %GroupContainer class.
*
* This header file contains the declarations of the %GroupContainer class.
*/
#ifndef _FUI_CTRL_GROUP_CONTAINER_H_
#define _FUI_CTRL_GROUP_CONTAINER_H_

#include <FBaseTypes.h>
#include <FUiContainer.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
* @class GroupContainer
* @brief   This class defines common behavior for a %GroupContainer container.
*
* @since 2.1
*
* The %GroupContainer class displays child controls in grouping look. It is a concrete implementation of the Container class.
*/

class _OSP_EXPORT_ GroupContainer
     : public Tizen::Ui::Container
{
public:
	/**
	* The object is not fully constructed after this constructor is called. @n
	* For full construction, the %Construct() method must be called right after calling this constructor.
	*
	* @since 2.1
	*/
	GroupContainer(void);

	/**
	* This polymorphic destructor should be overridden if required. @n
	* This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since	2.1
	*/
	virtual ~GroupContainer(void);

	/**
	* Initializes this instance of %GroupContainer with the specified parameters.
	*
	* @since 2.1
	*
	* @return      An error code
	* @param[in]   rect                The location and size of the %GroupContainer control as an instance of Rectangle
	* @param[in]   rowCount            The number of rows
	* @param[in]   columnCount         The number of columns
	* @param[in]   lineWidth           Width of the grid lines to draw
	* @exception   E_SUCCESS           The method is successful.
	* @exception   E_INVALID_ARG   	A specified input parameter is invalid. @n
	*                              	The width or height of @c rect or @c rowCount or @c columnnCount is negative or the value of @c lineWidth is @c 0 or negative.
	* @exception E_OPERATION_FAILED    The operation has failed.
	* @remarks The available space for controls is less than the width or height of the container by the total width or height of the grid lines.
	*/
	result Construct(const Tizen::Graphics::Rectangle& rect, int rowCount, int columnCount, int lineWidth = 1);

	/**
	* Initializes this instance of %GroupContainer with the specified parameters.
	*
	* @since 2.1
	*
	* @return      An error code
	* @param[in]   rect                The location and size of the %GroupContainer control as an instance of FloatRectangle
	* @param[in]   rowCount            The number of rows
	* @param[in]   columnCount         The number of columns
	* @param[in]   lineWidth           Width of the grid lines to draw
	* @exception   E_SUCCESS           The method is successful.
	* @exception   E_INVALID_ARG   	A specified input parameter is invalid. @n
	*                              	The width or height of @c rect or @c rowCount or @c columnnCount is negative or the value of @c lineWidth is @c 0 or negative.
	* @exception E_OPERATION_FAILED    The operation has failed.
	* @remarks The available space for controls is less than the width or height of the container by the total width or height of the grid lines.
	*/
	result Construct(const Tizen::Graphics::FloatRectangle& rect, int rowCount, int columnCount, float lineWidth = 1.0f);

	/**
	* Adds a control at a specified row and column index.
	*
	* @since 2.1
	*
	* @return      An error code
	* @param[in]   control				The control to add to the container
	* @param[in]   rowIndex			The row index of the cell
	* @param[in]   columnIndex			The column index of the cell
	* @exception   E_SUCCESS			The method is successful.
	* @exception   E_OUT_OF_RANGE      The specified @c rowIndex or @c columnIndex is greater than the number of elements or less than @c 0.
	* @exception   E_INVALID_ARG       A specified input parameter @c control is invalid.
	* @exception   E_INVALID_OPERATION The cell specified by @c rowIndex and @c columnIndex is already bound to another control.
	* @see    Merge()
	* @remarks
	*				- If a control is being added to the merged cells, the row index and column index of a representative cell should be given.
	*				- The control to add should be allocated in heap memory, and the ownership of the control is transferred to the platform.
	*/
	result AddControlAt(Control& control, int rowIndex, int columnIndex);

	/**
	* Gets the control at a specified cell index in the GroupContainer.
	*
	* @since 2.1
	*
	* @return		The control at a specified index of the list, @n
	*              else @c null if the cell index is not valid or no control is added
	* @param[in]	rowIndex			The row index of the cell
	* @param[in]   columnIndex			The column index of the cell
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex or @c columnIndex is greater than the number of elements or less than @c 0.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @exception	E_INVALID_OPERATION	No control has been bound to the specified cell.
	* @remarks  When you get the control from the merged cell, the row index and column index of a representative cell should be given.
	*/
	const Tizen::Ui::Control* GetControlAt(int rowIndex, int columnIndex) const;

	/**
	* Gets the control at a specified cell index in the GroupContainer.
	*
	* @since 2.1
	*
	* @return		The control at a specified index of the list, @n
	*              else @c null if the cell index is not valid or no control is added
	* @param[in]	rowIndex			The row index of the cell
	* @param[in]	columnIndex			The column index of the cell
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex or @c columnIndex is greater than the number of elements or less than @c 0.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @exception	E_INVALID_OPERATION	No control has been bound to the specified cell.
	* @remarks  When you get the control from the merged cells, the row index and column index of a representative cell should be given.
	*/
	Tizen::Ui::Control* GetControlAt(int rowIndex, int columnIndex);

	/**
	* Removes a specified control from a specified row and column index
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]	rowIndex			The row index of the control to remove
	* @param[in]	columnIndex			The column index of the control to remove
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex or @c columnIndex is greater than the number of elements or less than @c 0.
	* @exception   E_OPERATION_FAILED	The operation has failed.
	* @exception   E_INVALID_OPERATION No control has been bound to the specified cell.
	* @remarks
	*			- When you remove the control from the merged cell, the row index and column index of a representative cell should be given.
	*			- The removed child control is deleted from the memory. Before it is removed from the container, OnTerminating()
	*			of the child control is called.
	* @see                      Tizen::Ui::Control::OnTerminating()
	*/
	result RemoveControlAt (int rowIndex, int columnIndex);

	/**
	* Sets the width of a column.
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]	columnIndex			The column index
	* @param[in]	width				The new width of the column
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c columnIndex is greater than the number of elements or less than @c 0.
	* @exception   E_INVALID_ARG		The specified @c width must be greater than or equal to @c 0.
	*
	*/
	result SetColumnWidth(int columnIndex, int width);

	/**
	* Sets the width of a column.
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]	columnIndex			The column index
	* @param[in]	width				The new width of the column
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c columnIndex is greater than the number of elements or less than @c 0.
	* @exception   E_INVALID_ARG		The specified @c width must be greater than or equal to @c 0.0f.
	*
	*/
     result SetColumnWidth(int columnIndex, float width);

     /**
	* Gets the width of a column.
	*
	* @since 2.1
	*
	* @return		The width of the column
	* @param[in]	columnIndex			The column index
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE      The specified @c columnIndex is greater than the number of elements or less than @c 0.
	*/
	int GetColumnWidth(int columnIndex) const;

	/**
	* Gets the width of a column.
	*
	* @since 2.1
	*
	* @return		The width of the column
	* @param[in]	columnIndex			The column index
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE      The specified @c columnIndex is greater than the number of elements or less than @c 0.
	*/
	float GetColumnWidthF(int columnIndex) const;

	/**
	* Sets the height of a row.
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]	rowIndex			The row index
	* @param[in]	height				The new height of the row
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex is greater than the number of elements or less than @c 0.
	* @exception	E_INVALID_ARG		The specified @c height must be greater than or equal to @c 0.
	*
	*/
	result SetRowHeight(int rowIndex, int height);

	/**
	* Sets the height of a row.
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]	rowIndex			The row index
	* @param[in]	height				The new height of the row
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex is greater than the number of elements or less than @c 0.
	* @exception	E_INVALID_ARG		The specified @c height must be greater than or equal to @c 0.
	*
	*/
	result SetRowHeight(int rowIndex, float height);

	/**
	* Gets the height of a row.
	*
	* @since 2.1
	*
	* @return		The height of the row
	* @param[in]	rowIndex			The row index
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex is greater than the number of elements or less than @c 0.
	*
	*/
	int GetRowHeight(int rowIndex) const;

	/**
	* Gets the height of a row.
	*
	* @since 2.1
	*
	* @return		The height of the row
	* @param[in]	rowIndex			The row index
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex is greater than the number of elements or less than @c 0.
	*
	*/
	float GetRowHeightF(int rowIndex) const;

	/**
	* Merges the cells for a given row and column index.
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]	rowStartIndex		The start index of the row from which the merge happens
	* @param[in]	columnStartIndex	The start index of the column from which the merge happens
	* @param[in]	rowCount			The number of cells to merge along the row
	* @param[in]	columnCount			The number of cells to merge along the column
	* @exception	E_SUCCESS			The method is successful.
	* @exception   E_INVALID_ARG		One or more cells in the specified range is(are) already merged.
	* @exception	E_OUT_OF_RANGE 		The specified @c rowStartIndex or @c columnStartIndex is greater than the number of elements or less than @c 0
	* @remarks
	*			- When the cells are merged, the top-left cell will play the role of representative cell on behalf of merged cells.
	*			- To manipulate the merge cell, the row index and column index of the representative cell has to be given. Merging cells
	*			with the merged cell is allowed, but the newly merged cell should completely contain the all cells to merge.
	*/
	result Merge(int rowStartIndex, int columnStartIndex, int rowCount, int columnCount);

	/**
	* Enables/disables resizing of the control in a cell
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]	rowIndex			The row index of the row in which the control is resized
	* @param[in]	columnIndex			The column index of the column in which the control is resized
	* @param[in]	enable				boolean value to enable or disable the resizing of control
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex or @ccolumnIndex is greater than the number of elements or less than @c 0.
	*
	*/
	result SetChildResizingEnabled(int rowIndex, int columnIndex, bool enable);

	/**
	* Sets the margin of a cell
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]	rowIndex			The row index of the cell
	* @param[in]	columnIndex			The column index of the cell
	* @param[in]	leftMargin			The left margin
	* @param[in]	rightMargin			The right margin
	* @param[in]	topMargin			The top margin
	* @param[in]	bottomMargin		The bottom margin
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex or @c columnIndex is greater than the number of elements or less than @c 0.
	* @exception   E_INVALID_ARG		The specified @c leftMargin or @c topMargin or @c rightMargin or @c bottomMargin must be greater than or equal to @c 0.
	* @remarks     The default margin value is @c 2.0f logical pixel.
	*/
	result SetMargin(int rowIndex, int columnIndex, int leftMargin, int rightMargin, int topMargin, int bottomMargin);

	/**
	* Sets the margin of a cell
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]	rowIndex			The row index of the cell
	* @param[in]	columnIndex			The column index of the cell
	* @param[in]	leftMargin			The left margin
	* @param[in]	rightMargin			The right margin
	* @param[in]	topMargin			The top margin
	* @param[in]	bottomMargin		The bottom margin
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex or @c columnIndex is greater than the number of elements or less than @c 0.
	* @exception   E_INVALID_ARG		The specified @c leftMargin or @c topMargin or @c rightMargin or @c bottomMargin must be greater than or equal to @c 0.0f.
	* @remarks     The default margin value is 2.0f logical pixel.
	*/
	result SetMargin(int rowIndex, int columnIndex, float leftMargin, float rightMargin, float topMargin, float bottomMargin);

	/**
	* Splits the merged cells
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]	rowIndex			The row index of the representative cell of the merged cells
	* @param[in]	columnIndex			The column index of the representative cell of the merged cells
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex or @c columnIndex is greater than the number of elements or less than @c 0.
	* @exception	E_INVALID_ARG		The specified row and column index are not those of the representative cell of the merged cells.
	*/
	result Split(int rowIndex, int columnIndex);

	/**
	* Gets the bounds of a specified cell.
	*
	* @since 2.1
	*
	* @return		An instance of the Tizen::Graphics::Rectangle that represents the position of top-left corner,
	*              the width, and the height of the cell, @n else Rectangle(0, 0, -1, -1)  if an error occurs
	* @param[in]	rowIndex			The row index of the cell
	* @param[in]	columnIndex			The column index of the cell
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex or @c columnIndex is greater than the number of elements or less than @c 0.
	*/
	Tizen::Graphics::Rectangle GetBoundsAt(int rowIndex, int columnIndex) const;

	/**
	* Gets the bounds of a specified cell.
	*
	* @since 2.1
	*
	* @return		An instance of the Tizen::Graphics::FloatRectangle that represents the position of top-left corner,
	*              the width, and the height of the cell, @n else Rectangle(0.0f, 0.0f, -1.0f, -1.0f)  if an error occurs
	* @param[in]	rowIndex			The row index of the cell
	* @param[in]	columnIndex			The column index of the cell
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex or @c columnIndex is greater than the number of elements or less than @c 0.
	*/
	Tizen::Graphics::FloatRectangle GetBoundsAtF(int rowIndex, int columnIndex) const;

	/**
	* Enables/disables stretchable or shrinkable property of a column
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]	columnIndex			The column index of the cell
	* @param[in]	stretchable			boolean value to set stretchable or shrinkable property
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c columnIndex is greater than the number of elements or less than @c 0.
	*/
	result SetColumnStretchable(int columnIndex, bool stretchable);

	/**
	* Checks whether the column is stretchable or shrinkable
	*
	* @since 2.1
	*
	* @return		@c true if the column is stretchable or shrinkable
	*                   else @c false
	* @param[in]	columnIndex			The column index of the cell
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c columnIndex is greater than the number of elements or less than @c 0.
	*/
	bool IsColumnStretchable(int columnIndex) const;

	/**
	* Enables/disables stretchable or shrinkable property of a row
	*
	* @since 2.1
	*
	* @return		An error code
	* @param[in]	rowIndex			The row index of the cell
	* @param[in]	stretchable			boolean value to set stretchable or shrinkable property
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex is greater than the number of elements or less than @c 0.
	*/
	result SetRowStretchable(int rowIndex, bool stretchable);

	/**
	* Checks whether the row is stretchable or shrinkable
	*
	* @since 2.1
	*
	* @return		@c true if the row is stretchable or shrinkable
	*                   else @c false
	* @param[in]	rowIndex			The row index of the cell
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c rowIndex is greater than the number of elements or less than @c 0.
	*/
	bool IsRowStretchable(int rowIndex) const;

	/**
	* Gets the background color of the %GroupContainer control.
	*
	* @since		2.1
	*
	* @return		The background color, @n
	*              	else RGBA(0, 0, 0, 0) if an error occurs
	*/
	Tizen::Graphics::Color GetBackgroundColor(void) const;

	/**
	* Sets the background color of the %GroupContainer control.
	*
	* @since 2.1
	*
	* @param[in]	color			The background color
	*/
	void SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	* Gets the row and column divider line color of the %GroupContainer control.
	*
	* @since		2.1
	*
	* @return		The row and column divider line color, @n
	*                              else RGBA(0, 0, 0, 255) if line color is not set.
	*/
	Tizen::Graphics::Color GetLineColor(void) const;

	/**
	* Sets the row and column divider line color of the %GroupContainer control.
	*
	* @since 		2.1
	*
	* @param[in]    color   		The line color
	*/
	void SetLineColor(const Tizen::Graphics::Color& color);

protected:
     //
     // This method is for internal use only. Using this method can cause behavioral, security-related,
     // and consistency-related issues in the application.
     //
     // Following method is reserved and may change its name at any time without
     // prior notice.
     //
     // @since 2.1
     //
     virtual void GroupContainer_Reserved1(void) {}

     //
     // This method is for internal use only. Using this method can cause behavioral, security-related,
     // and consistency-related issues in the application.
     //
     // Following method is reserved and may change its name at any time without
     // prior notice.
     //
     // @since 2.1
     //
     virtual void GroupContainer_Reserved2(void) {}

     //
     // This method is for internal use only. Using this method can cause behavioral, security-related,
     // and consistency-related issues in the application.
     //
     // Following method is reserved and may change its name at any time without
     // prior notice.
     //
     // @since 2.1
     //
     virtual void GroupContainer_Reserved3(void) {}

private:
     friend class _GroupContainerImpl;

     //
     // The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     //
     // @since 2.1
     //
     GroupContainer(const GroupContainer& rhs);

     //
     // The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     //
     GroupContainer& operator =(const GroupContainer& rhs);

}; // GroupContainer

}}} //Tizen::Ui::Controls

#endif // _FUI_CTRL_GROUP_CONTAINER_H_
