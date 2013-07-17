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
 * @file	FUiClipboard.h
 * @brief	This is the header file for the %Clipboard class.
 *
 * This header file contains the declarations of the %Clipboard class and its helper classes.
 */

#ifndef _FUI_CLIPBOARD_H_
#define _FUI_CLIPBOARD_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FBaseColIList.h>
#include <FUiClipboardItem.h>
#include <FUiIClipboard.h>
#include <FUiIClipboardPopupEventListener.h>

namespace Tizen { namespace Ui
{
class _ClipboardImpl;

/**
 * @class	Clipboard
 * @brief 	This class defines a common behavior for %Clipboard.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Clipboard class manages the copy and paste operation between and within applications.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/clipboard.htm">Clipboard</a>.
 *
 * The following example demonstrates how to use the %Clipboard class.
 *
 * @code
// Sample code for ClipboardSample.h
#include <FUi.h>

class ClipboardSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
{
public:
	ClipboardSample(void)
	: __pLabel(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	// IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private:
	static const int ID_BUTTON_OK = 101;

	Tizen::Ui::Controls::Label* __pLabel;
};
 * @endcode
 *
 * @code
// Sample code for ClipboardSample.cpp
#include <FApp.h>
#include <FBase.h>
#include <FGraphics.h>

#include "ClipboardSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
ClipboardSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
ClipboardSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Sets data to a clip board item
	ClipboardItem item;
	String resourcePath = App::GetInstance()->GetAppResourcePath();
	item.Construct(CLIPBOARD_DATA_TYPE_HTML, String(resourcePath + L"screen-size-normal/IDF_FORM.xml"));

	// Gets an instance of Clipboard and copies an item to it
	Clipboard* pClipboard = Clipboard::GetInstance();
	pClipboard->CopyItem(item);

	// Creates controls to test clipboard
	Button* pButton = new Button();
	pButton->Construct(Rectangle(50, 50, 200, 80), "COPY");
	pButton->SetActionId(ID_BUTTON_OK);
	pButton->AddActionEventListener(*this);
	AddControl(pButton);

	__pLabel = new Label();
	__pLabel->Construct(Rectangle(0, 200, GetClientAreaBounds().width, 80), L"..");
	AddControl(__pLabel);

	return r;
}

void
ClipboardSample::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_BUTTON_OK:
		{
			// Gets an instance of Clipboard
			Clipboard* pClipboard = Clipboard::GetInstance();

			// Retrieves a latest item
			ClipboardItem* pItem = pClipboard->RetrieveLatestItemN(CLIPBOARD_DATA_TYPE_TEXT
					| CLIPBOARD_DATA_TYPE_HTML
					| CLIPBOARD_DATA_TYPE_AUDIO
					| CLIPBOARD_DATA_TYPE_VIDEO );

			//Gets data from the clipboard item
			String* pString = dynamic_cast<String*>(pItem->GetData());

			__pLabel->SetText(*pString + L" is Copied");
			__pLabel->Invalidate(false);

			delete pItem;
		}
		break;
	default:
		break;
	}
}
 * @endcode
 */
class _OSP_EXPORT_ Clipboard
	: public Tizen::Base::Object
	, public Tizen::Ui::IClipboard
{
public:
	/**
	 * Gets the system clipboard.
	 *
	 * @since   2.0
	 *
	 * @return  The pointer to the system clipboard
	 * @remarks The copy and paste operation is performed through the system
	 *          clipboard that can be obtained through this method. @n
	 *          The method returns @c null if a system error occurs.
	 */
	static Clipboard* GetInstance(void);

	/**
	 * Copies the specified @c item to the system clipboard.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   item            The item to save in the system clipboard
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   The specified input parameter is invalid.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     This method returns @c E_INVALID_ARG if the specified item is
	 *              not constructed. @n
	 *              For the text and image data type, the data itself is copied
	 *              by the method and kept by the system clipboard.
	 */
	result CopyItem(const ClipboardItem& item);

	/**
	 * Retrieves a collection of items that matches the specified data types from the
	 * system clipboard.
	 *
	 * @since       2.0
	 *
	 * @return      The pointer to a Tizen::Base::Collection::IList that contains a collection of ClipboardItem, @n
	 *              else @c null if an error occurs
	 * @param[in]   dataTypes       The types of items @n Multiple data types can be
	 *                              combined using bitwise OR.
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_OBJ_NOT_FOUND The item of the specified data types is not found.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
	 *              This method returns a pointer to an Tizen::Base::Collection::IList that contains
	 *              a collection of ClipboardItem. The returned pointer to %Tizen::Base::Collection::IList
	 *              and all the elements in %Tizen::Base::Collection::IList must be deleted by applications. @n
	 *              The items in %Tizen::Base::Collection::IList are sorted in the reverse order in which
	 *              they are copied to the system clipboard. So, the first
	 *              item in %Tizen::Base::Collection::IList is the latest one among them. @n
	 *              @c dataType can be a combination of ClipboardDataType.
	 * @see Tizen::Ui::ClipboardDataType
	 */
	Tizen::Base::Collection::IList* RetrieveItemsN(unsigned long dataTypes);

	/**
	 * Retrieves the latest item for the specified data types from the system clipboard.
	 *
	 * @since       2.0
	 *
	 * @return      The pointer to a ClipboardItem instance, @n
	 *              else @c null if an error occurs
	 * @param[in]   dataTypes       The types of items @n Multiple data types can be
	 *                              combined using bitwise OR.
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_OBJ_NOT_FOUND The item of the specified data types is not found.
	 * @exception   E_SYSTEM        A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method. @n
	 *              This method returns the pointer to a ClipboardItem instance. The
	 *              returned %ClipboardItem must be deleted by applications. @n
	 *              If there is no matched item in the system clipboard, this method
	 *              returns @c null. @n
	 *              @c dataType can be a combination of ClipboardDataType.
	 * @see Tizen::Ui::ClipboardDataType
	 */
	Tizen::Ui::ClipboardItem* RetrieveLatestItemN(unsigned long dataTypes);

	/**
	 * Shows the clipboard popup with the specified parameters.
	 *
	 * @since     2.0
	 *
	 * @return	  An error code
	 * @param[in] dataTypes           The types of items @n Multiple data types can be
	 *                                combined using bitwise OR.
	 * @param[in] listener            The clipboard popup event listener
	 * @exception E_SUCCESS           The method is successful.
	 * @exception E_INVALID_OPERATION The current state of the instance
	 *                                prohibits the execution of the specified
	 *                                operation.
	 * @exception E_SYSTEM            A system error has occurred.
	 * @remarks    @c dataTypes can decide whether the clipboard popup shows image items or not.
	 *            If @c dataTypes contains #CLIPBOARD_DATA_TYPE_IMAGE, all types of items are shown.
	 *            If not, text items, html items, video items, and audio items are shown except image items. @n
	 *            This method returns @c E_INVALID_OPERATION if the clipboard popup is currently
	 *            being shown. Furthermore, attempting to show the clipboard popup when the application is
	 *            in the background will return @c E_INVALID_OPERATION. @n
	 *            The clipboard popup shows the current content of the system clipboard. The user
	 *            can clear the system clipboard or choose a clipboard item for the paste operation.
	 * @see Tizen::Ui::ClipboardDataType
	 */
	static result ShowPopup(unsigned long dataTypes, const IClipboardPopupEventListener& listener);

	/**
	 * Hides the clipboard popup.
	 *
	 * @since          2.0
	 *
	 * @return         An error code
	 * @exception      E_SUCCESS             The method is successful.
	 * @exception      E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	 * @exception      E_SYSTEM              A system error has occurred.
	 * @remarks        This method returns @c E_INVALID_OPERATION if no clipboard popup is currently being shown.
	 */
	static result HidePopup(void);

	/**
	 * Checks whether the clipboard popup is currently being shown.
	 *
	 * @since          2.0
	 *
	 * @return         @c true if the clipboard popup is being shown, @n
	 *                 else @c false
	 */
	static bool IsPopupVisible(void);

private:
	//
	// This default constructor is intentionally declared as private to implement the Singleton semantic.
	//
	Clipboard(void);

	//
	// This destructor is intentionally declared as private to implement the Singleton semantic.
	//
	virtual ~Clipboard(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Clipboard(const Clipboard& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Clipboard& operator =(const Clipboard& rhs);

private:
	friend class _ClipboardImpl;

private:
	_ClipboardImpl* __pClipboardImpl;
}; // Clipboard

}} //Tizen::Ui

#endif //_FUI_CLIPBOARD_H_
