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
 * @file    FUiCtrlTabBarItem.h
 * @brief   This is the header file for the %TabBarItem class.
 *
 * This header file contains the declarations of the %TabBarItem class.
 */
#ifndef _FUI_CTRL_TAB_BAR_ITEM_H_
#define _FUI_CTRL_TAB_BAR_ITEM_H_

#include <FBaseObject.h>

namespace Tizen { namespace Ui { namespace Controls
{
class _TabBarItemImpl;
};
};
};


namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @class	TabBarItem
 * @brief	This class is an implementation of %TabBarItem.
 *
 * @since	2.0
 *
 * The %TabBarItem class is a helper class that specifies the contents of a tab bar item.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_tab_bar.htm">TabBar</a>.
 */
class _OSP_EXPORT_ TabBarItem
	: public Tizen::Base::Object
{
// Lifecycle
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the TabBarItem::Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	TabBarItem(void);


	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~TabBarItem(void);


	/**
	 * Initializes this instance of %TabBarItem with the specified parameters.
	 *
	 * @since 		2.0
	 *
	 * @return      An error code
	 * @param[in]   text                The item text
	 * @param[in]	actionId	        The action ID of this item
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid. @n
	 *									The @c actionId of the specified item must be greater than or equal to @c 0.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 */
	result Construct(const Tizen::Base::String& text, int actionId);


// Operation
public:
	/**
	 * Sets the action ID of the item.
	 *
	 * @since 		2.0
	 *
	 * @return      An error code
	 * @param[in]	actionId		    The action ID for this item
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       The specified input parameter is invalid. @n
	 *									The @c actionId of the specified item must be a positive integer.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 */
	result SetActionId(int actionId);


	/**
	 * Gets the action ID of the item.
	 *
	 * @since		2.0
	 *
	 * @return      The action ID, @n
	 *				else @c -1 if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_STATE		This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetActionId(void) const;


	/**
	 * Gets the text of the item.
	 *
	 * @since 		2.0
	 *
	 * @return		The item text, @n
	 *				else an empty string if an error occurs
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetText(void) const;


	/**
	 * Sets the text of the item.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]   text		        The text to set
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_STATE     This instance is in an invalid state.
	 * @remarks		If the size of the text exceeds the displayable area, the font size of the text is decreased automatically.
	 */
	result SetText(const Tizen::Base::String& text);


private:
	friend class TabBar;

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	_TabBarItemImpl* __pTabBarItemImpl;

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	TabBarItem(const TabBarItem& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	TabBarItem& operator =(const TabBarItem& rhs);

}; // TabBarItem

}}} // Tizen::Ui: Control

#endif //_FUI_CTRL_TAB_BAR_ITEM_H_
