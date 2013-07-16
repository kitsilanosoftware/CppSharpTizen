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
 * @file    FUiCtrlTabBar.h
 * @brief   This is the header file for the %TabBar class.
 *
 * This header file contains the declarations of the %TabBar class.
 */
#ifndef _FUI_CTRL_TAB_BAR_H_
#define _FUI_CTRL_TAB_BAR_H_

#include <FUiControl.h>

namespace Tizen { namespace Ui
{
class IActionEventListener;
}} // Tizen::Ui
namespace Tizen { namespace Ui { namespace Controls
{
class TabBarItem;
}}} // Tizen::Ui::Controls

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @enum	TabBarItemStatus
 *
 * Defines the possible states of TabBarItem.
 *
 * @since   2.0
 */
enum TabBarItemStatus
{
	TAB_BAR_ITEM_STATUS_NORMAL, 		/**< The normal state */
	TAB_BAR_ITEM_STATUS_SELECTED 		/**< The selected state */
};


/**
 * @class   TabBar
 * @brief   This class is an implementation of %TabBar.
 *
 * @since   2.0
 *
 * The %TabBar class displays a list of possible options for the user selection in a horizontal list.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_tab_bar.htm">TabBar</a>.
 *
 * The following example demonstrates how to use the %TabBar class.
 *
 * @code
// Sample code for TabBarSample.h
#include <FUi.h>

class TabBarSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
{
public:
	TabBarSample(void)
	: __pTabBar(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	// IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private:
	static const int ID_TABBAR_ITEM1 = 100;
	static const int ID_TABBAR_ITEM2 = 101;
	static const int ID_TABBAR_ITEM3 = 102;

	Tizen::Ui::Controls::TabBar *__pTabBar;
};
 *	@endcode
 *
 *	@code
// Sample code for TabBarSample.cpp
#include "TabBarSample.h"

using namespace Tizen::Ui::Controls;

bool
TabBarSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
TabBarSample::OnInitializing()
{
	result r = E_SUCCESS;

	// Creates an instance of TabBar
	__pTabBar = new TabBar();
	__pTabBar->Construct(0, 0, GetClientAreaBounds().width);

	// Creates instances of TabBarItem
	 TabBarItem tabBarItem1;
	 TabBarItem tabBarItem2;
	 TabBarItem tabBarItem3;

	 tabBarItem1.Construct(L"1", ID_TABBAR_ITEM1);
	 tabBarItem2.Construct(L"2", ID_TABBAR_ITEM2);
	 tabBarItem3.Construct(L"3", ID_TABBAR_ITEM3);

	 // Adds items to the tab bar
	__pTabBar->AddItem(tabBarItem1);
	__pTabBar->AddItem(tabBarItem2);
	__pTabBar->AddItem(tabBarItem3);
	__pTabBar->AddActionEventListener(*this);

	// Adds the tab bar to the form
	AddControl(__pTabBar);

	return r;
}

// IActionEventListener implementation
void
TabBarSample::OnActionPerformed(const Control& source, int actionId)
{
	switch (actionId)
	{
	case ID_TABBAR_ITEM1:
		{
			// ....
		}
		break;
	case ID_TABBAR_ITEM2:
		{
			// ....
		}
		break;
	default:
		break;
	}
}
 * @endcode
 *
 */
class _OSP_EXPORT_ TabBar
	: public Tizen::Ui::Control
{
// Lifecycle
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the %Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 *
	 */
	TabBar(void);


	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 	2.0
	 *
	 */
	virtual ~TabBar(void);

	/**
	 * Initializes this instance of %TabBar with the specified parameters.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   x               	The X position of the top left corner
	 * @param[in]   y               	The Y position of the top left corner
	 * @param[in]   width           	The width @n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @exception   E_SUCCESS       	The method is successful.
	 * @exception   E_INVALID_ARG   	A specified input parameter is invalid.
	 * @exception   E_INVALID_STATE 	This instance is in an invalid state.
	 * @exception   E_SYSTEM        	A system error has occurred.
	 */
	result Construct(int x, int y, int width);

	/**
	 * Initializes this instance of %TabBar with the specified parameters.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   x               	The X position of the top left corner
	 * @param[in]   y               	The Y position of the top left corner
	 * @param[in]   width           	The width @n
	 *									The optimal size of the control is defined in
	 *									<a href="../org.tizen.native.appprogramming/html/guide/ui/control_optimalsize.htm">Optimal Size of UI Controls</a>.
	 * @exception   E_SUCCESS       	The method is successful.
	 * @exception   E_INVALID_ARG   	A specified input parameter is invalid.
	 * @exception   E_INVALID_STATE 	This instance is in an invalid state.
	 * @exception   E_SYSTEM        	A system error has occurred.
	 */
	result Construct(float x, float y, float width);


// Operation
public:
	/**
	 * Adds the specified item.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   item            	The item to add
	 * @exception   E_SUCCESS       	The method is successful.
	 * @exception   E_INVALID_ARG   	The specified input parameter is invalid. @n
	 *									The specified @c item is not constructed.
	 * @exception   E_MAX_EXCEEDED  	The number of items has exceeded the maximum limit.
	 * @exception   E_INVALID_STATE 	This instance is in an invalid state.
	 * @exception   E_SYSTEM        	A system error has occurred.
	 * @remarks
	 *				- The maximum number of items for a %TabBar control is @c 100.
	 *				- The content of the specified item is copied to the %TabBar control.
	 *				- The item can be deallocated explicitly after this method call if it is created dynamically.
	 *				- The %TabBar control does not throw any exception even though the same action ID is assigned to multiple items.
	 */
	result AddItem(const TabBarItem& item);


	/**
	 * Inserts the %TabBar item at the specified index.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   index             	The index of the item to insert
	 * @param[in]   item              	The item to insert
	 * @exception   E_SUCCESS         	The method is successful.
	 * @exception   E_INVALID_ARG     	A specified input parameter is invalid. @n
	 *								  	The specified @c item is not constructed.
	 * @exception   E_MAX_EXCEEDED    	The number of items has exceeded the maximum limit.
	 * @exception   E_OUT_OF_RANGE    	The specified @c index is out of the range of the data structure. @n
	 *									The specified @c index is either greater than or equal to the number of items or is less than @c 0.
	 * @exception   E_INVALID_STATE   	This instance is in an invalid state.
	 * @exception   E_SYSTEM          	A system error has occurred.
	 * @remarks
	 *				- The maximum number of items for a %TabBar control is @c 100.
	 *				- The content of the specified item is copied to the @c %TabBar control. @n
	 *				- The item can be deallocated explicitly after this method call if it is created dynamically. @n
	 *				- The %TabBar control does not throw any exception even though the same action ID is assigned to multiple items.
	 */
	result InsertItemAt(int index, const TabBarItem& item);


	/**
	 * Gets the color of the %TabBar control.
	 *
	 * @since       2.0
	 *
	 * @return      The color, @n
	 *				else RGBA(0,0,0,0) if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetColor(void) const;


	/**
	 * Gets the item count.
	 *
	 * @since       2.0
	 *
	 * @return      The item count, @n
	 *              else @c -1 if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetItemCount(void) const;


	/**
	 * Gets the item color that is displayed when an item is selected.
	 *
	 * @since       2.0
	 *
	 * @return      The selected item color, @n
	 *				else RGBA(0,0,0,0) if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetSelectedItemColor(void) const;


	/**
	 * Gets the item text color for the specified state.
	 *
	 * @since       2.0
	 *
	 * @return      The item text color, @n
	 *				else RGBA (0,0,0,0) if an error occurs
	 * @param[in]   status              The item state
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetItemTextColor(TabBarItemStatus status) const;


	/**
	 * Gets the index of the selected item.
	 *
	 * @since       2.0
	 *
	 * @return      The selected item index, @n
	 *              else @c -1 if an error occurs
	 * @exception   E_SUCCESS           	The method is successful.
	 * @exception   E_INVALID_STATE     	This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetSelectedItemIndex(void) const;


	/**
	 * Removes the %TabBar item at the specified index.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   index             	The index of the item
	 * @exception   E_SUCCESS         	The method is successful.
	 * @exception   E_OUT_OF_RANGE    	The specified @c index is out of the range of the data structure. @n
	 *									The specified @c index is either greater than or equal to the number of items or is less than @c 0.
	 * @exception   E_INVALID_STATE   	This instance is in an invalid state.
	 * @exception   E_SYSTEM          	A system error has occurred.
	 * @remarks     If the currently selected item is removed, the next item is selected automatically.
	 */
	result RemoveItemAt(int index);


	/**
	 * Removes all the items from the %TabBar control.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS         The method is successful.
	 * @exception   E_INVALID_STATE   This instance is in an invalid state.
	 * @exception   E_SYSTEM          A system error has occurred.
	 */
	result RemoveAllItems(void);


	/**
	 * Sets the color of the %TabBar control.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   color             The color
	 * @exception   E_SUCCESS         The method is successful.
	 * @exception   E_INVALID_STATE   This instance is in an invalid state.
	 */
	result SetColor(const Tizen::Graphics::Color& color);


	/**
	 * Sets the content of the %TabBar item at the specified index.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   index             	The index at which to set the specified item
	 * @param[in]   item              	The item to set
	 * @exception   E_SUCCESS         	The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid. @n
	 *								  	The specified @c item is not constructed.
	 * @exception   E_OUT_OF_RANGE    	The specified @c index is out of the range of the data structure. @n
	 *									The specified @c index is either greater than or equal to the number of items or is less than @c 0.
	 * @exception   E_INVALID_STATE		This instance is in an invalid state.
	 * @exception   E_SYSTEM			A system error has occurred.
	 * @remarks
	 *				- The contents of the specified item are copied.
	 *				- The item can be deallocated explicitly after this method call if it is created dynamically.
	 */
	result SetItemAt(int index, const TabBarItem& item);


	/**
	 * Selects the item at the specified index.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   index             	The index of the item to select
	 * @exception   E_SUCCESS         	The method is successful.
	 * @exception   E_OUT_OF_RANGE    	The specified @c index is not within the range of the data structure. @n
	 *									The specified @c index is either greater than or equal to the number of items or is less than @c 0.
	 * @exception   E_INVALID_STATE   	This instance is in an invalid state.
	 * @exception   E_SYSTEM          	A system error has occurred.
	 */
	result SetItemSelected(int index);


	/**
	 * Sets the item text color for the specified state.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   status            The item state
	 * @param[in]   color             The item text color
	 * @exception   E_SUCCESS         The method is successful.
	 * @exception   E_INVALID_STATE   This instance is in an invalid state.
	 * @exception   E_SYSTEM          A system error has occurred.
	 */
	result SetItemTextColor(TabBarItemStatus status, const Tizen::Graphics::Color& color);


	/**
	 * Sets the selected item color.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   color             The item color
	 * @exception   E_SUCCESS         The method is successful.
	 * @exception   E_INVALID_STATE   This instance is in an invalid state.
	 * @exception   E_SYSTEM          A system error has occurred.
	 */
	result SetSelectedItemColor(const Tizen::Graphics::Color& color);


	/**
	 * Sets the width of the tab bar.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   width             The width
	 * @exception   E_SUCCESS         The method is successful.
	 * @exception   E_INVALID_ARG     The specified input parameter is invalid.
	 * @exception   E_INVALID_STATE   This instance is in an invalid state.
	 * @exception   E_SYSTEM          A system error has occurred.
	 */
	result SetWidth(int width);

	/**
	 * Sets the width of the tab bar.
	 *
	 * @since       2.1
	 *
	 * @return      An error code
	 * @param[in]   width             The width
	 * @exception   E_SUCCESS         The method is successful.
	 * @exception   E_INVALID_ARG     The specified input parameter is invalid.
	 * @exception   E_INVALID_STATE   This instance is in an invalid state.
	 * @exception   E_SYSTEM          A system error has occurred.
	 */
	result SetWidth(float width);


//Listeners
public:
	/**
	 * Adds an action event listener instance. @n
	 * The added listener can listen to events on the specified event dispatcher's context when they are fired.
	 *
	 * @since 		2.0
	 *
	 * @param[in]   listener		The event listener to add
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	void AddActionEventListener(Tizen::Ui::IActionEventListener& listener);


	/**
	 * Removes an action event listener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 		2.0
	 *
	 * @param[in]   listener		The event listener to remove
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	void RemoveActionEventListener(Tizen::Ui::IActionEventListener& listener);

protected:
	friend class _TabBarImpl;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.0
	//
	//
	TabBar(const TabBar& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.0
	//
	//
	TabBar& operator =(const TabBar& rhs);

}; // TabBar

}}} // Tizen::Ui: Control
#endif //_FUI_CTRL_TAB_BAR_H_
