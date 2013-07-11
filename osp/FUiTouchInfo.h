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
 * @file	FUiTouchInfo.h
 * @brief	This is the header file for the %TouchInfo class.
 *
 * This header file contains the declarations of the %TouchInfo class.
 *
 */

#ifndef _FUI_TOUCH_INFO_H_
#define _FUI_TOUCH_INFO_H_

#include <FBaseObject.h>
#include <FUiTouchEventInfo.h>

namespace Tizen { namespace Ui
{

class Control;

/**
 * @if OSPDEPREC
 * @class	TouchInfo
 * @brief	<i> [Deprecated] </i> This class stores the information of a touch event.
 *
 * @deprecated  This class is deprecated because the use of the %TouchInfo is no longer recommended. Instead of using this class, use Tizen::Ui::TouchEventInfo class.
 * @since	2.0
 *
 * @final        This class is not intended for extension.
 *
 * The %TouchInfo class provides touch-related information to support multi-point touch.
 * @endif
 */
class _OSP_EXPORT_ TouchInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * @if OSPDEPREC
	 * This is the default constructor for this class.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated because the %TouchInfo class is not supported any more. Instead, use the Tizen::Ui::TouchEventInfo class.
	 * @since		2.0
	 * @endif
	 */
	TouchInfo(void)
		: id(0)
		, position(0, 0)
		, status(TOUCH_PRESSED)
	{
	}

	/**
	 * @if OSPDEPREC
	 * The ID of the Touch instance.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated because the %TouchInfo class is not supported any more. Instead, get the Tizen::Ui::TouchEventManager::GetTouchInfoListN()
	 *				and use the Tizen::Ui::TouchEventInfo::GetPointId() method.
	 * @since	2.0
	 * @endif
	 */
	unsigned long id;

	/**
	 * @if OSPDEPREC
	 * The position of the Touch instance.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated because the %TouchInfo class is not supported any more. Instead, get the Tizen::Ui::TouchEventManager::GetTouchInfoListN()
	 *				and use the Tizen::Ui::TouchEventInfo::GetCurrentPosition() method.
	 * @since	2.0
	 * @endif
	 */
	Tizen::Graphics::Point position;

	/**
	 * @if OSPDEPREC
	 * The status of the Touch instance, using only the @c TOUCH_PRESSED and @c TOUCH_RELEASED states.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated because the %TouchInfo class is not supported any more. Instead, get the Tizen::Ui::TouchEventManager::GetTouchInfoListN()
	 *				and use the Tizen::Ui::TouchEventInfo::GetTouchStatus() method.
	 * @since	2.0
	 * @endif
	 */
	TouchStatus status;
}; // TouchInfo

}} // Tizen::Ui

#endif // _FUI_TOUCH_INFO_H_
