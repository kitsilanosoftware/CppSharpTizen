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
 * @file		FUi.h
 * @brief		This is the header file for the %Ui namespace.
 *
 * This header file contains the declarations and descriptions of the %Ui namespace.
 */

#ifndef _FUI_H_
#define _FUI_H_

// Includes
#include <FUiAccessibilityContainer.h>
#include <FUiAccessibilityElement.h>
#include <FUiAnimations.h>
#include <FUiClipboard.h>
#include <FUiClipboardTypes.h>
#include <FUiClipboardItem.h>
#include <FUiCompositeMode.h>
#include <FUiContainer.h>
#include <FUiControl.h>
#include <FUiControls.h>
#include <FUiCustomControlBase.h>
#include <FUiDataBindingContext.h>
#include <FUiDataBindingTypes.h>
#include <FUiEffects.h>
#include <FUiFocusManager.h>
#include <FUiGridLayout.h>
#include <FUiHorizontalBoxLayout.h>
#include <FUiIAccessibilityListener.h>
#include <FUiIActionEventListener.h>
#include <FUiIAdjustmentEventListener.h>
#include <FUiIAnimationEventListener.h>
#include <FUiIClipboard.h>
#include <FUiIClipboardPopupEventListener.h>
#include <FUiIColorChangeEventListener.h>
#include <FUiICustomItemEventListener.h>
#include <FUiIDataBindingDataTransformer.h>
#include <FUiIDataBindingDataValidator.h>
#include <FUiIDataBindingListener.h>
#include <FUiIDateChangeEventListener.h>
#include <FUiIDateTimeChangeEventListener.h>
#include <FUiIDragDropEventListener.h>
#include <FUiIDragDropEventListenerF.h>
#include <FUiIExpandableItemEventListener.h>
#include <FUiIFastScrollEventListener.h>
#include <FUiIFocusEventListener.h>
#include <FUiIGroupedItemEventListener.h>
#include <FUiIInputConnectionEventListener.h>
#include <FUiIInputConnectionProvider.h>
#include <FUiIItemEventListener.h>
#include <FUiIKeyEventListener.h>
#include <FUiIKeypadEventListener.h>
#include <FUiILanguageEventListener.h>
#include <FUiInputConnection.h>
#include <FUiInputConnectionTypes.h>
#include <FUiIOrientationEventListener.h>
#include <FUiIPropagatedKeyEventListener.h>
#include <FUiIPropagatedTouchEventListener.h>
#include <FUiIScrollPanelEventListener.h>
#include <FUiISlidableGroupedListEventListener.h>
#include <FUiISlidableListEventListener.h>
#include <FUiITextBlockEventListener.h>
#include <FUiITextEventListener.h>
#include <FUiITimeChangeEventListener.h>
#include <FUiITouchCustomGestureEventListener.h>
#include <FUiITouchEventListener.h>
#include <FUiITouchFlickGestureEventListener.h>
#include <FUiITouchGestureEventListener.h>
#include <FUiITouchLongPressGestureEventListener.h>
#include <FUiITouchModeChangedEventListener.h>
#include <FUiITouchPanningGestureEventListener.h>
#include <FUiITouchPinchGestureEventListener.h>
#include <FUiITouchRotationGestureEventListener.h>
#include <FUiITouchTapGestureEventListener.h>
#include <FUiIUiLinkEventListener.h>
#include <FUiIWindowEventListener.h>
#include <FUiKeyboardMap.h>
#include <FUiKeyEventInfo.h>
#include <FUiKeyEventManager.h>
#include <FUiKeyTypes.h>
#include <FUiLayout.h>
#include <FUiLayoutTypes.h>
#include <FUiRelativeLayout.h>
#include <FUiScenes.h>
#include <FUiSystemUtil.h>
#include <FUiTouch.h>
#include <FUiTouchEventInfo.h>
#include <FUiTouchEventManager.h>
#include <FUiTouchFlickGestureDetector.h>
#include <FUiTouchGestureDetector.h>
#include <FUiTouchInfo.h>
#include <FUiTouchLongPressGestureDetector.h>
#include <FUiTouchPanningGestureDetector.h>
#include <FUiTouchPinchGestureDetector.h>
#include <FUiTouchRotationGestureDetector.h>
#include <FUiTouchTapGestureDetector.h>
#include <FUiVariant.h>
#include <FUiVerticalBoxLayout.h>
#include <FUiWindow.h>

namespace Tizen
{
/**
 * @namespace   Tizen::Ui
 * @brief		This namespace contains the classes and interfaces that act as the %UI foundation for the applications.
 * @since		2.0
 *
 * @remarks	    @b Header @b %file: @b \#include @b <FUi.h> @n
 *				@b Library : @b osp-uifw
 *
 * The %Ui namespace is used to construct graphical user interfaces (UI). It contains classes and interfaces for handling
 * UI-related events. In addition, it has 4 sub-namespaces: Tizen::Ui::Controls, whose classes handle the display and interaction with UI elements, Tizen::Ui::Scenes, whose classes handle scene transition using the scene management functionalities,
 * Tizen::Ui::Animations, whose classes handle animation-related functionalities, and Tizen::Ui::Effects, whose classes
 * handle the effect-related functionalities.
 *
 * For more information on the %Ui namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/ui_namespace.htm">UI Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Ui namespace.
 *
 * @image html ui_namespace_classdiagram.png
 *
 */
namespace Ui
{

}; // Tizen::Ui
}; // Tizen
#endif // _FUI_H_
