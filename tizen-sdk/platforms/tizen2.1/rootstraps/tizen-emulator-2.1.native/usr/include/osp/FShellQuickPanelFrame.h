//
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
* @file               FShellQuickPanelFrame.h
* @brief      This is the header file for the %QuickPanelFrame class.
*
* This header file contains the declarations of the %QuickPanelFrame class.
*/

#ifndef _FSHELL_QUICK_PANEL_FRAME_H_
#define _FSHELL_QUICK_PANEL_FRAME_H_

#include <FUiWindow.h>

namespace Tizen { namespace Ui
{
class IOrientationEventListener;
class Layout;
}} // Tizen::Ui

namespace Tizen { namespace Shell
{

/**
* @class      QuickPanelFrame
* @brief      This class is an implementation of a %QuickPanelFrame.
* @since	2.0
*
* The %QuickPanelFrame class provides the main container for a QuickPanel panel.
* It is an ultimate parent of all %QuickPanel controls.
*
* The following example demonstrates how to use the %QuickPanelFrame class.
* @code
// Sample code for QuickPanelFrameSample.h
#include <FUi.h>
#include <FShell.h>

class QuickPanelFrameSample
	: public Tizen::Ui::Controls::Form
{
public:
	QuickPanelFrameSample(void)
		: __pQuickPanelFrame(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

private:
	static const int QUICK_PANEL_FRAME_HEIGHT = 102;
	Tizen::Shell::QuickPanelFrame *__pQuickPanelFrame;
};

// Sample code for QuickPanelFrameSample.cpp
#include <FGraphics.h>
#include "QuickPanelFrameSample.h"

using namespace Tizen::App;
using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Shell;

bool
QuickPanelFrameSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL|FORM_STYLE_INDICATOR);
	return true;
}

result
QuickPanelFrameSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of QuickPanelFrame
	__pQuickPanelFrame = new QuickPanelFrame;
	__pQuickPanelFrame->Construct(QUICK_PANEL_FRAME_HEIGHT);

	// Creates an instance of Button
	Button* pButton = new Button();
	pButton->Construct(Rectangle(10,10,200,80), L"Button");

	// Adds the button to the QuickPanelFrame
	__pQuickPanelFrame->AddControl(pButton);
	__pQuickPanelFrame->Show();

	return r;
}

result
QuickPanelFrameSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	delete __pQuickPanelFrame;
	return r;
}
* @endcode
*
*/

class _OSP_EXPORT_ QuickPanelFrame
        : public Tizen::Ui::Window
{
public:
        /**
        * The object is not fully constructed after this constructor is called. @n
        * For full construction, the Construct() method must be called right after calling this constructor.
        *
        * @since	2.0
        */
        QuickPanelFrame(void);

        /**
        * This destructor overrides Tizen::Base::Object::~Object().
        *
        * @since	2.0
        */
        virtual ~QuickPanelFrame(void);

        /**
        * Initializes this instance of %QuickPanelFrame with a specified parameter.
        *
        * @since	2.0
        * @privlevel        public
        * @privilege   %http://tizen.org/privilege/notification
        *
        * @return      An error code
        * @param[in]  height                        The height of %QuickPanelFrame
        * @exception  E_SUCCESS           The method is successful.
        * @exception  E_PRIVILEGE_DENIED     The application does not have the privilege to call this method.
        * @exception  E_INVALID_ARG          The @c height is less than or equal to @c 0.
        */
        result Construct(int height);

        /**
        * Initializes this instance of %QuickPanelFrame and child controls with a specified resource ID. @n
        *
        * The %Construct() method first attempts to find the resource file in the folder that corresponds to the current screen resolution. @n
        * If it fails to find the resource file, it searches in other folders in the following order when CoordinateSystem is Logical in the application manifest file @n
        * the density folder that corresponds to the current screen size category @b "res/screen-size-normal/" folder.
        *
        * @since	2.0
        * @privlevel        public
        * @privilege   %http://tizen.org/privilege/notification
        *
        * @return             An error code
        * @param[in]  resourceId                    The resource ID describing the %QuickPanelFrame control
        * @exception  E_SUCCESS                     The method is successful.
        * @exception  E_PRIVILEGE_DENIED     The application does not have the privilege to call this method.
        * @exception  E_FILE_NOT_FOUND       The file corresponding to the specified @c resourceId cannot be found.
        * @exception  E_INVALID_FORMAT       The file format corresponding to the specified @c resourceId is invalid.
        * @exception  E_OPERATION_FAILED     The operation has failed.
        */
        result Construct(const Tizen::Base::String& resourceId);

        /**
        * Initializes this instance of %QuickPanelFrame with the specified parameters.
        *
        * @since	2.0
        * @privlevel        public
        * @privilege   %http://tizen.org/privilege/notification
        *
        * @return      An error code
        * @param[in]  layout                        The layout for both the portrait and landscape mode
        * @param[in]  height                        The height of %QuickPanelFrame
        * @exception  E_SUCCESS           The method is successful.
        * @exception  E_PRIVILEGE_DENIED     The application does not have the privilege to call this method.
        * @exception  E_INVALID_ARG          The @c height is less than or equal to @c 0.
        */
        result Construct(const Tizen::Ui::Layout& layout, int height);

        /**
        * Constructs and initializes an instance of %QuickPanelFrame with the specified parameters.
        *
        * @since	2.0
        * @privlevel        public
        * @privilege   %http://tizen.org/privilege/notification
        *
        * @return      An error code
        * @param[in]  portraitLayout         The layout for the portrait mode
        * @param[in]  landscapeLayout               The layout for the landscape mode
        * @param[in]  height                        The height of %QuickPanelFrame
        * @exception  E_SUCCESS           The method is successful.
        * @exception  E_PRIVILEGE_DENIED     The application does not have the privilege to call this method.
        * @exception  E_INVALID_ARG          The @c height is less than or equal to @c 0.
        */
        result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, int height);

        /*
        * Initializes this instance of %QuickPanelFrame with the specified parameter.
        *
        * @since	2.1
        *
        * @privlevel        public
        * @privilege   %http://tizen.org/privilege/notification
        *
        * @return      An error code
        * @param[in]  height                        The height of %QuickPanelFrame
        * @exception  E_SUCCESS           The method is successful.
        * @exception  E_PRIVILEGE_DENIED     The application does not have the privilege to call this method.
        * @exception  E_INVALID_ARG          The @c height is less than or equal to @c 0.0f.
        */
        result Construct(float height);

        /*
        * Initializes this instance of %QuickPanelFrame with the specified parameters.
        *
        * @since	2.1
        *
        * @privlevel        public
        * @privilege   %http://tizen.org/privilege/notification
        *
        * @return      An error code
        * @param[in]  layout                        The layout for both the portrait and landscape mode
        * @param[in]  height                        The height of %QuickPanelFrame
        * @exception  E_SUCCESS           The method is successful.
        * @exception  E_PRIVILEGE_DENIED     The application does not have the privilege to call this method.
        * @exception  E_INVALID_ARG          The @c height is less than or equal to @c 0.0f.
        */
        result Construct(const Tizen::Ui::Layout& layout, float height);

        /*
        * Constructs and initializes an instance of %QuickPanelFrame with the specified parameters.
        *
        * @since	2.1
        *
        * @privlevel        public
        * @privilege   %http://tizen.org/privilege/notification
        *
        * @return      An error code
        * @param[in]  portraitLayout         The layout for the portrait mode
        * @param[in]  landscapeLayout               The layout for the landscape mode
        * @param[in]  height                        The height of %QuickPanelFrame
        * @exception  E_SUCCESS           The method is successful.
        * @exception  E_PRIVILEGE_DENIED     The application does not have the privilege to call this method.
        * @exception  E_INVALID_ARG          The @c height is less than or equal to @c 0.0f.
        */
        result Construct(const Tizen::Ui::Layout& portraitLayout, const Tizen::Ui::Layout& landscapeLayout, float height);

        /**
        * Adds an IOrientationEventListener instance. @n
        * The added listener can listen to the orientation changed events that are fired when the orientation mode of the screen is changed.
        *
        * @since	2.0
        *
        * @param[in]  listener                      The listener to add @n
        *                                           The listener must be allocated at heap, not stack.
        * @exception  E_SUCCESS                     The method is successful.
        * @exception  E_OBJ_ALREADY_EXIST    The listener is already added.
        * @see                RemoveOrientationEventListener()
        */
        result AddOrientationEventListener(Tizen::Ui::IOrientationEventListener& listener);

        /**
        * Removes an IOrientationEventListener instance. @n
        * The removed listener cannot listen to the events when they are fired.
        *
        * @since	2.0
        *
        * @param[in]  listener                      The listener to remove @n
        *                                           The listener should be referring to previously allocated instance that is passed as an argument to AddOrientationEventListener().
        * @exception  E_SUCCESS                     The method is successful.
        * @exception  E_OBJ_NOT_FOUND               The specified @c listener is not found.
        * @see                AddOrientationEventListener()
        */
        result RemoveOrientationEventListener(Tizen::Ui::IOrientationEventListener& listener);

        /**
        * Sets the height of %QuickPanelFrame.
        *
        * @since	2.0
		*
        * @return             An error code
        * @param[in]  height                        The height of %QuickPanelFrame
        * @exception  E_SUCCESS                     The method was successful.
        * @exception  E_INVALID_ARG          The @c height is less than or equal to @c 0.
        */
        result SetHeight(int height);

        /*
        * Sets the height of the %QuickPanelFrame.
        *
        * @since	2.1
        * @return             An error code
        * @param[in]  height                        The height of %QuickPanelFrame
        * @exception  E_SUCCESS                     The method was successful.
        * @exception  E_INVALID_ARG          The @c height is less than or equal to @c 0.0f.
        */
        result SetHeight(float height);

protected:
        //
        // This method is for internal use only. Using this method can cause behavioral, security-related,
        // and consistency-related issues in the application.
        //
        // This method is reserved and may change its name at any time without prior notice.
        //
        // @since	2.0
        //
        virtual void QuickPanelFrame_Reserved1(void) {}

        //
        // This method is for internal use only. Using this method can cause behavioral, security-related,
        // and consistency-related issues in the application.
        //
        // This method is reserved and may change its name at any time without prior notice.
        //
        // @since	2.0
        //
        virtual void QuickPanelFrame_Reserved2(void) {}

        //
        // This method is for internal use only. Using this method can cause behavioral, security-related,
        // and consistency-related issues in the application.
        //
        // This method is reserved and may change its name at any time without prior notice.
        //
        // @since	2.0
        //
        virtual void QuickPanelFrame_Reserved3(void) {}

        //
        // This method is for internal use only. Using this method can cause behavioral, security-related,
        // and consistency-related issues in the application.
        //
        // This method is reserved and may change its name at any time without prior notice.
        //
        // @since	2.0
        //
        virtual void QuickPanelFrame_Reserved4(void) {}

        //
        // This method is for internal use only. Using this method can cause behavioral, security-related,
        // and consistency-related issues in the application.
        //
        // This method is reserved and may change its name at any time without prior notice.
        //
        // @since	2.0
        //
        virtual void QuickPanelFrame_Reserved5(void) {}

private:
       /**
        * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
        *
        * @since	2.0
        */
        QuickPanelFrame(const QuickPanelFrame& rhs);

        /**
        * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
        *
        * @since	2.0
        */
        QuickPanelFrame& operator =(const QuickPanelFrame& rhs);
}; // QuickPanelFrame

}} // Tizen::Shell

#endif // _FSHELL_QUICK_PANEL_FRAME_H_

