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
 * @file	  	FUiTouchEventManager.h
 * @brief		This is the header file for the %TouchEventManager class.
 *
 * This header file contains the declarations of the %TouchEventManager class.
 *
 */

#ifndef _FUI_TOUCH_EVENT_MANAGER_H_
#define _FUI_TOUCH_EVENT_MANAGER_H_

#include <FBaseColIListT.h>
#include <FBaseObject.h>
#include <FUiTouchEventInfo.h>
#include <FUiControl.h>

namespace Tizen { namespace Ui
{

class _TouchEventManagerImpl;
/**
 * @class		TouchEventManager
 * @brief		This class stores the information of each touch events.
 *
 * @since 2.0
 *
 * @final      	This class is not intended for extension.
 *
 * The %TouchEventManager class provides the touch event information: touch position, status, ID, and so on.
 * @see  	  	TouchEventInfo
 *
 */
class _OSP_EXPORT_ TouchEventManager
	: public Tizen::Base::Object
{
public:
	/**
	 * Gets the instance of the %TouchEventManager.
	 *
	 * @since 2.0
	 * @return		A instance of the %TouchEventManager
	 * @exception		E_SUCCESS The method is successful.
	 * @exception		E_OUT_OF_MEMORY The memory is insufficient.
	 * @remarks		This method provides a global point of access to the TouchEventManager. And the specific error code can be accessed using the
	 * 				GetLastResult() method.
	 */
	static TouchEventManager* GetInstance(void);

	/**
	 * Gets the list of the multi-point touches, each represented by TouchEventInfo.
	 *
	 * @since 2.0
	 * @return		List of the TouchEventInfo
	 * @see			Tizen::Ui::TouchEventInfo
	 *
	 */
	Tizen::Base::Collection::IListT<TouchEventInfo*>* GetTouchInfoListN(void) const;

private:
	//
	// This default constructor is intentionally declared as private to implement the Singleton semantic.
	//
	TouchEventManager(void);

	//
	// This destructor is intentionally declared as private to implement the Singleton semantic.
	//
	virtual ~TouchEventManager(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	TouchEventManager(const TouchEventManager& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	TouchEventManager& operator =(const TouchEventManager& rhs);

private:
	_TouchEventManagerImpl* __pTouchEventManagerImpl;
}; // TouchEventManager

}} //Tizen::Ui

#endif // _FUI_TOUCH_EVENT_MANAGER_H_
