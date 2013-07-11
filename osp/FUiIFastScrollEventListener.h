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
 * @file		FUiIFastScrollEventListener.h
 * @brief		This is the header file for the %IFastScrollEventListener interface.
 *
 * This header file contains declarations of the %IFastScrollEventListener interface.
 * If item event is generated, a method of this interface will be called.
 * Applications that do some jobs related to item event, call methods of this interface.
 *
 */
#ifndef _FUI_IFAST_SCROLL_EVENT_LISTENER_H_
#define _FUI_IFAST_SCROLL_EVENT_LISTENER_H_

#include <FBaseCharacter.h>
#include <FBaseRtIEventListener.h>
#include <FUiIItemEventListener.h>

namespace Tizen { namespace Ui
{
class Control;
} }

namespace Tizen {namespace Ui
{

/**
 * @if OSPDEPREC
 * @interface	IFastScrollEventListener
 * @brief		<i> [Deprecated] </i> This interface implements the listener for fast scroll event.
 *
 * @deprecated  This class is deprecated. Instead of using this class, use the IFastScrollListener class.
 * @since		2.0
 *
 *
 * The %IFastScrollEventListener interface for receiving item events. The class that processes a fast scroll
 * implements this interface, and the object created with that class is registered with a UI control, using the control's
 * AddFastScrollEventListener method. When an item event occurs, the object's OnItemStateChanged() method is invoked.
 * @endif
 */
class _OSP_EXPORT_ IFastScrollEventListener
	: public Tizen::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * @if OSPDEPREC
	 * This is the destructor for this class.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the IFastScrollListener class.
	 * @since		2.0
	 * @endif
	 */
	virtual ~IFastScrollEventListener(void) {}

	/**
	 * @if OSPDEPREC
	 * Called when a main index is selected.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the IFastScrollListener class.
	 * @since				2.0
	 *
	 * @param[in]   source				The source of the event
	 * @param[in]   mainIndex			The main index
	 * @endif
	 */
	virtual void OnMainIndexChanged(const Tizen::Ui::Control& source, Tizen::Base::Character& mainIndex) = 0;

	/**
	 * @if OSPDEPREC
	 * Called when a sub index is selected.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the IFastScrollListener class.
	 * @since				2.0
	 *
	 * @param[in]   source				The source of the event
	 * @param[in]   mainIndex			The main index
	 * @param[in]   subIndex			The sub index
	 * @endif
	 */
	virtual void OnSubIndexChanged(const Tizen::Ui::Control& source, Tizen::Base::Character& mainIndex, Tizen::Base::Character& subIndex) = 0;

	/**
	 * @if OSPDEPREC
	 * Called when a main index is expanded.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the IFastScrollListener class.
	 * @since				2.0
	 *
	 * @param[in]   source				The source of the event
	 * @param[in]   mainIndex			The main index
	 * @endif
	 */
	virtual void OnMainIndexSelected(const Tizen::Ui::Control& source, Tizen::Base::Character& mainIndex) = 0;

	/**
	 * @if OSPDEPREC
	 * Called when a sub index is expanded.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated  This class is deprecated. Instead of using this class, use the IFastScrollListener class.
	 * @since				2.0
	 *
	 * @param[in]   source				The source of the event
	 * @param[in]   mainIndex			The main index
	 * @param[in]   subIndex			The sub index
	 * @endif
	 */
	virtual void OnSubIndexSelected(const Tizen::Ui::Control& source, Tizen::Base::Character& mainIndex, Tizen::Base::Character& subIndex) = 0;

protected:

	virtual void IFastScrollEventListener_Reserved1(void) {}
	virtual void IFastScrollEventListener_Reserved2(void) {}
	virtual void IFastScrollEventListener_Reserved3(void) {}
}; // IFastScrollEventListener

}}

#endif // _FUI_IFAST_SCROLL_EVENT_LISTENER_H_
