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
 * @file	FUiAnimDisplayContext.h
 * @brief	This is the header file for the %DisplayContext class.
 *
 * This header file contains the declarations of the %DisplayContext class.
 */

#ifndef _FUI_ANIM_DISPLAY_CONTEXT_H_
#define _FUI_ANIM_DISPLAY_CONTEXT_H_

#include <FBaseObject.h>

namespace Tizen { namespace Ui { namespace Animations
{
class _DisplayContextImpl;

/**
 * @class	DisplayContext
 * @brief	This class represents the display resources for the displayable objects.
 *
 * @since	2.0
 *
 * The %DisplayContext class represents the display context of the window.
 * The display context is a set of display resources that includes VisualElements, VisualElementSurfaces, and frame buffer,
 * and it is managed by Tizen::Ui::Window.
 */
class _OSP_EXPORT_ DisplayContext
	: public Tizen::Base::Object
{
protected:
	/**
	 * This default constructor is intentionally declared as private to prohibit creation of an instance by a user.
	 *
	 * @since		2.0
	 *
	 * @remarks The %DisplayContext instance cannot be created,
	 * 			it is offered by the Tizen::Ui::Window::GetDisplayContext() method.
	 * @see Window::GetDisplayContext()
	 */
	DisplayContext(void);


	/**
	 * This destructor is intentionally declared as private to implement the Singleton semantic.
	 *
	 * @since		2.0
	 *
	 * @remarks		The display context is released when the Tizen::Ui::Window instance is destroyed.
	 *
	 */
	virtual ~DisplayContext(void);


private:

	/**
	 * The implementation of this copy constructor is intentionally blank to prohibit copying of objects.
	 *
	 * @since		2.0
	 */
	DisplayContext(const DisplayContext& rhs);


	/**
	 * The implementation of this assignment constructor is intentionally blank to prohibit assignment of objects.
	 *
	 * @since		2.0
	 */
	DisplayContext& operator =(const DisplayContext& rhs);


protected:
	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void DisplayContext_Reserved1(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void DisplayContext_Reserved2(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void DisplayContext_Reserved3(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void DisplayContext_Reserved4(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	virtual void DisplayContext_Reserved5(void) {}

protected:
	friend class _DisplayContextImpl;
	_DisplayContextImpl* _pDisplayContextImpl;
}; // class DisplayContext

}}} //namespace Tizen { namespace Ui { namespace Animations

#endif //_FUI_ANIM_DISPLAY_CONTEXT_H_
