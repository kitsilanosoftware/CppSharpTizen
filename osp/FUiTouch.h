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
 * @file	FUiTouch.h
 * @brief	This is the header file for the %Touch class.
 *
 * This header file contains the declarations of the %Touch class.get
 *
 */

#ifndef _FUI_TOUCH_H_
#define _FUI_TOUCH_H_

#include <FBaseColIList.h>
#include <FUiTouchInfo.h>
#include <FUiTouchEventInfo.h>

namespace Tizen { namespace Ui
{

class Control;
/**
 * @if OSPDEPREC
 * @class	Touch
 * @brief	<i> [Deprecated] </i> This class supports multi-point touch for %Touch devices.
 *
 * @deprecated  This class is deprecated because the use of the %Touch is no longer recommended. Instead of using this class, use Tizen::Ui::TouchEventManager class.
 * @since	2.0
 *
 * @final        This class is not intended for extension.
 *
 * The %Touch class supports multi-point touch, and provides information about touch events.
 *
 * The following example demonstrates how to use the %Touch class.
 * @code
// Sample code for TouchSample.h
#include <FUi.h>

class TouchSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::ITouchEventListener
{
public:
	bool Initialize(void);
	virtual result OnInitializing(void);
	void DisplayMultipointTouchInfo(const Tizen::Ui::Control &source);

	// ITouchEventListener
	virtual void OnTouchDoublePressed(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusIn(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusOut(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchLongPressed(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchMoved(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchPressed(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchReleased(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
};
 *	@endcode
 *
 *	@code
// Sample code for TouchSample.cpp
#include <FBase.h>
#include <FGraphics.h>

#include "TouchSample.h"

using namespace Tizen::Base::Collection;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
TouchSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
TouchSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Touch
	Touch touch;
	touch.SetMultipointEnabled(*this, true);
	AddTouchEventListener(*this);

	return r;
}

void
TouchSample::DisplayMultipointTouchInfo(const Control &source)
{
	Touch touch;
	IList *pList = touch.GetTouchInfoListN(source);
	if (pList)
	{
		for(int i = 0; i < pList->GetCount(); i++ )
		{
			TouchInfo *pTouchInfo = static_cast<TouchInfo *>(pList->GetAt(i));
			AppLog("OnTouchMoved : [%d]%d,%d - %d", pTouchInfo->id, pTouchInfo->position.x, pTouchInfo->position.y, pTouchInfo->status);
		}
		pList->RemoveAll(true);
		delete pList;
	}
}

// ITouchEventListeners implementation
void
TouchSample::OnTouchDoublePressed(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
	AppLog("OnTouchDoublePressed is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
	DisplayMultipointTouchInfo(source);
}

void
TouchSample::OnTouchFocusIn(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
	AppLog("OnTouchFocusIn is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
	DisplayMultipointTouchInfo(source);
}

void
TouchSample::OnTouchFocusOut(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
	AppLog("OnTouchFocusOut is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
	DisplayMultipointTouchInfo(source);
}

void
TouchSample::OnTouchLongPressed(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
	AppLog("OnTouchLongPressed is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
	DisplayMultipointTouchInfo(source);
}

void
TouchSample::OnTouchMoved(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
	AppLog("OnTouchMoved is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
	DisplayMultipointTouchInfo(source);
}

void
TouchSample::OnTouchPressed(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
	AppLog("OnTouchPressed is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
	DisplayMultipointTouchInfo(source);
}

void
TouchSample::OnTouchReleased(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
	AppLog("OnTouchReleased is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
	DisplayMultipointTouchInfo(source);
}
 * @endcode
 * @endif
 */
class _OSP_EXPORT_ Touch
	: public Tizen::Base::Object
{
public:
	/**
	 * @if OSPDEPREC
	 * This is the default constructor for this class.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the %Touch class is not supported any more. Instead, use the Tizen::Ui::TouchEventManager class.
	 * @since		2.0
	 * @endif
	 */
	Touch(void);

	/**
	 * @if OSPDEPREC
	 * This destructor overrides Osp::Base::Object::~Object().
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the %Touch class is not supported any more. Instead, use the Tizen::Ui::TouchEventManager class.
	 * @since		2.0
	 * @endif
	 */
	virtual ~Touch(void);

public:
	/**
	 * @if OSPDEPREC
	 * Enables or disables the multi-point touch of the Control.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated because the %Touch class is not supported any more. Instead, use the Tizen::Ui::Control::SetMultipointTouchEnabled() method.
	 * @since			2.0
	 *
	 * @return		An error code
	 * @param[in]		control				The control
	 * @param[in]		enable				A Boolean flag indicating whether to enable to the multi-point touch
	 * @exception	E_SUCCESS      		The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
 	 * @see			IsMultipointEnabled()
	 * @endif
	 */
	result SetMultipointEnabled(const Tizen::Ui::Control& control, bool enable);

	/**
	 * @if OSPDEPREC
	 * Checks whether the multi-point touch is enabled.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated 	This method is deprecated because the %Touch class is not supported any more. Instead, use the Tizen::Ui::Control::IsMultipointTouchEnabled() method.
	 * @since			2.0
	 *
	 * @return		@c true if the multi-point touch is enabled, @n
	 *				else @c false
	 * @see			IsMultipointEnabled()
	 * @endif
	 */
	bool IsMultipointEnabled(const Tizen::Ui::Control& control) const;


	/**
	 * @if OSPDEPREC
	 * Gets the touch position.
	 * If there is only a single touch, that is returned. If there are multi-point touches, then the position of the last touch is returned.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated 	This method is deprecated because the %Touch class is not supported any more.
	 *				Instead, get the Tizen::Ui::TouchEventManager::GetTouchInfoListN() and use the Tizen::Ui::TouchEventInfo::GetCurrentPosition() method.
	 * @since			2.0
 	 *
	 * @return		The coordinates of the touch
 	 * @remarks		If an error occurs, this method returns Point(-1, -1).
 	 * @endif
	 */
	Tizen::Graphics::Point GetPosition(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the touch position by ID.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated 	This method is deprecated because the %Touch class is not supported any more.
	 *				Instead, get the Tizen::Ui::TouchEventManager::GetTouchInfoListN() and use the Tizen::Ui::TouchEventInfo::GetCurrentPosition() method.
	 * @since			2.0
	 *
	 * @return		The coordinates of the touch
	 * @param[in]		id		The ID of the touch
	 * @remarks		If an error occurs, this method returns Point(-1, -1).
	 * @endif
	 */
	Tizen::Graphics::Point GetPosition(unsigned long id) const;

	/**
	 * @if OSPDEPREC
	 * Gets the touch position relative to the specified control.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated 	This method is deprecated because the %Touch class is not supported any more.
	 *				Instead, get the Tizen::Ui::TouchEventManager::GetTouchInfoListN() and use the Tizen::Ui::TouchEventInfo::GetCurrentPosition() method.
	 * @since			2.0
	 *
	 * @return		The coordinates of the touch
	 * @param[in]		control		The source control
	 * @remarks		If an error occurs, this method returns Point(-1, -1).
	 * @endif
	 */
	Tizen::Graphics::Point GetPosition(const Tizen::Ui::Control& control) const;

	/**
	 * @if OSPDEPREC
	 * Gets the touch position relative to the specified control by ID.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated 	This method is deprecated because the %Touch class is not supported any more.
	 *				Instead, get the Tizen::Ui::TouchEventManager::GetTouchInfoListN() and use the Tizen::Ui::TouchEventInfo::GetCurrentPosition() method.
	 * @since			2.0
	 *
	 * @return		The coordinates of the touch
	 * @param[in]		control		The source control
	 * @param[in]		id			The ID of the touch
	 * @remarks		If an error occurs, this method returns Point(-1, -1).
	 * @endif
	 */
	Tizen::Graphics::Point GetPosition(const Tizen::Ui::Control& control, unsigned long id) const;

	/**
	 * @if OSPDEPREC
	 * Gets the status of the touch by ID.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated 	This method is deprecated because the %Touch class is not supported any more.
	 *				Instead, get the Tizen::Ui::TouchEventManager::GetTouchInfoListN() and use the Tizen::Ui::TouchEventInfo::GetTouchStatus() method.
	 * @since			2.0
	 *
	 * @param[in]		id		The ID of the touch
	 * @return		The touch status
	 * @endif
	 */
	TouchStatus GetTouchStatus(unsigned long id) const;

	/**
	 * @if OSPDEPREC
	 * Gets the list of the multi-point touches, each represented by TouchInfo.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated because the %Touch class is not supported any more. Instead, use the Tizen::Ui::TouchEventManager::GetTouchInfoListN() method.
	 * @since			2.0
	 *
	 * @return		List of the TouchInfo
	 * @see			Tizen::Ui::TouchInfo
	 * @endif
	 */
	Tizen::Base::Collection::IList* GetTouchInfoListN(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the list of the multi-point touch positions relative to the specified control, each represented by TouchInfo.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated 	This method is deprecated because the %Touch class is not supported any more. Instead, use the Tizen::Ui::TouchEventManager::GetTouchInfoListN() method.
	 * @since			2.0
	 *
	 * @return		A list of the TouchInfo instances
	 * @param[in]		control 	The source object for calculating the coordinates
	 * @see			Tizen::Ui::TouchInfo
	 * @endif
	 */
	Tizen::Base::Collection::IList* GetTouchInfoListN(const Tizen::Ui::Control& control) const;

	/**
	 * @if OSPDEPREC
	 * Gets the count of the multi-point touches.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated 	This method is deprecated because the %Touch class is not supported any more. Instead, get the count of Tizen::Ui::TouchEventManager::GetTouchInfoListN() method.
	 * @since			2.0
	 *
	 * @return		The number of the multi-point touches
	 * @endif
	 */
	int GetPointCount(void) const;

	/**
	 * @if OSPDEPREC
	 * Gets the point ID at the given index.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  	This method is deprecated because the %Touch class is not supported any more.
	 *				Instead, get the Tizen::Ui::TouchEventManager::GetTouchInfoListN() and use the Tizen::Ui::TouchEventInfo::GetPointId() method.
	 * @since			2.0
	 *
	 * @return		The touch point ID
	 * @param[in]		index	The index of the touch
	 * @endif
	 */
	unsigned long GetPointId(int index) const;

private:
	//
	//  The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Touch(const Touch&);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Touch& operator =(const Touch&);
};  // Touch

}} // Tizen::Ui

#endif // _FUI_TOUCH_H_
