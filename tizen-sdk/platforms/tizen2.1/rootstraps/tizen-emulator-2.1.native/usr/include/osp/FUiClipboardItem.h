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
 * @file	FUiClipboardItem.h
 * @brief	This is the header file for the %ClipboardItem class.
 *
 * This header file contains the declarations of the %ClipboardItem class and its helper classes.
 */

#ifndef _FUI_CLIPBOARD_ITEM_H_
#define _FUI_CLIPBOARD_ITEM_H_

#include <FUiClipboardTypes.h>
#include <FBaseObject.h>

namespace Tizen { namespace Ui
{
class _ClipboardItemImpl;

/**
 * @class	ClipboardItem
 * @brief 	This class defines a common behavior for %ClipboardItem.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %ClipboardItem class represents the items in the system Clipboard. The %ClipboardItem is the unit of data handling between
 * the system clipboard and applications, and it contains both data itself and the type of the data.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/clipboard.htm">Clipboard</a>.
 *
 */
class _OSP_EXPORT_ ClipboardItem
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since   2.0
	 */
	ClipboardItem(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since   2.0
	 */
	virtual ~ClipboardItem(void);

	/**
	 * Initializes this instance of %ClipboardItem with the specified parameters.
	 *
	 * @since     2.0
	 *
	 * @return    An error code
	 * @param[in] dataType         The data type
	 * @param[in] data             The data to copy
	 * @exception E_SUCCESS        The method is successful.
	 * @exception E_INVALID_ARG   A specified input parameter is invalid.
	 * @exception E_SYSTEM         A system error has occurred.
	 * @remarks   For the image data type, the bitmap instance must be deleted
	 *            by the application after the item is copied to the clipboard.
	 */
	result Construct(ClipboardDataType dataType, const Tizen::Base::Object& data);

	/**
	 * Gets the data type of %ClipboardItem.
	 *
	 * @since   2.0
	 *
	 * @return  The data type of the clipboard item
	 */
	ClipboardDataType GetDataType(void) const;

	/**
	 * Gets the data of %ClipboardItem.
	 *
	 * @since   2.0
	 *
	 * @return  The pointer to the data
	 * @remarks The application needs to type-cast the returned data object
	 *          according to its data type.
	 */
	Tizen::Base::Object* GetData(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	ClipboardItem(const ClipboardItem& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	ClipboardItem& operator =(const ClipboardItem& rhs);

private:
	friend class _ClipboardItemImpl;

private:
	_ClipboardItemImpl* __pImpl;
}; // ClipboardItem

}} // Tizen::Ui

#endif // _FUI_CLIPBOARD_ITEM_H_
