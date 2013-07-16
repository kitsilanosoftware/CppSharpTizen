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
 * @file		FUiControls.h
 * @brief		This is the header file for the %Tizen::Ui::Controls namespace.
 *
 * This header file contains the declarations and descriptions of the %Tizen::Ui::Controls namespace.
 */

#ifndef _FUI_CONTROLS_H_
#define _FUI_CONTROLS_H_

#include <FUiCtrlAnimation.h>
#include <FUiCtrlAnimationFrame.h>
#include <FUiCtrlButton.h>
#include <FUiCtrlButtonItem.h>
#include <FUiCtrlCheckButton.h>
#include <FUiCtrlColorPicker.h>
#include <FUiCtrlContextMenu.h>
#include <FUiCtrlControlsTypes.h>
#include <FUiCtrlCustomItem.h>
#include <FUiCtrlCustomList.h>
#include <FUiCtrlCustomListItem.h>
#include <FUiCtrlCustomListItemFormat.h>
#include <FUiCtrlCustomListTypes.h>
#include <FUiCtrlDatePicker.h>
#include <FUiCtrlDateTimePicker.h>
#include <FUiCtrlEditArea.h>
#include <FUiCtrlEditDate.h>
#include <FUiCtrlEditField.h>
#include <FUiCtrlEditTime.h>
#include <FUiCtrlEditTypes.h>
#include <FUiCtrlExpandableEditArea.h>
#include <FUiCtrlExpandableList.h>
#include <FUiCtrlFooter.h>
#include <FUiCtrlFooterItem.h>
#include <FUiCtrlForm.h>
#include <FUiCtrlFrame.h>
#include <FUiCtrlFrameTypes.h>
#include <FUiCtrlGallery.h>
#include <FUiCtrlGalleryItem.h>
#include <FUiCtrlGalleryTypes.h>
#include <FUiCtrlGroupContainer.h>
#include <FUiCtrlGroupedList.h>
#include <FUiCtrlGroupedListView.h>
#include <FUiCtrlGroupedListViewTypes.h>
#include <FUiCtrlGroupedTableView.h>
#include <FUiCtrlGroupItem.h>
#include <FUiCtrlHeader.h>
#include <FUiCtrlHeaderItem.h>
#include <FUiCtrlIconList.h>
#include <FUiCtrlIconListTypes.h>
#include <FUiCtrlIconListView.h>
#include <FUiCtrlIconListViewItem.h>
#include <FUiCtrlIconListViewTypes.h>
#include <FUiCtrlICustomElement.h>
#include <FUiCtrlICustomElementF.h>
#include <FUiCtrlICustomListElement.h>
#include <FUiCtrlIEditTextFilter.h>
#include <FUiCtrlIExpandableEditAreaEventListener.h>
#include <FUiCtrlIFastScrollListener.h>
#include <FUiCtrlIFormBackEventListener.h>
#include <FUiCtrlIFrameEventListener.h>
#include <FUiCtrlIGalleryEventListener.h>
#include <FUiCtrlIGalleryItemProvider.h>
#include <FUiCtrlIGroupedListViewItemEventListener.h>
#include <FUiCtrlIGroupedListViewItemProvider.h>
#include <FUiCtrlIGroupedListViewItemProviderF.h>
#include <FUiCtrlIGroupedTableViewItemEventListener.h>
#include <FUiCtrlIGroupedTableViewItemProvider.h>
#include <FUiCtrlIGroupedTableViewItemProviderF.h>
#include <FUiCtrlIIconListViewItemEventListener.h>
#include <FUiCtrlIIconListViewItemProvider.h>
#include <FUiCtrlIListViewItemEventListener.h>
#include <FUiCtrlIListViewItemProvider.h>
#include <FUiCtrlIListViewItemProviderF.h>
#include <FUiCtrlInputTypes.h>
#include <FUiCtrlIProgressPopupEventListener.h>
#include <FUiCtrlIScrollEventListener.h>
#include <FUiCtrlIScrollEventListenerF.h>
#include <FUiCtrlISearchBarEventListener.h>
#include <FUiCtrlISectionTableViewItemEventListener.h>
#include <FUiCtrlISectionTableViewItemProvider.h>
#include <FUiCtrlISectionTableViewItemProviderF.h>
#include <FUiCtrlISliderEventListener.h>
#include <FUiCtrlISplitPanelEventListener.h>
#include <FUiCtrlISplitPanelEventListenerF.h>
#include <FUiCtrlITableViewItemEventListener.h>
#include <FUiCtrlITableViewItemProvider.h>
#include <FUiCtrlITableViewItemProviderF.h>
#include <FUiCtrlITokenFilter.h>
#include <FUiCtrlKeypad.h>
#include <FUiCtrlLabel.h>
#include <FUiCtrlLabelTypes.h>
#include <FUiCtrlList.h>
#include <FUiCtrlListContextItem.h>
#include <FUiCtrlListItemBase.h>
#include <FUiCtrlListTypes.h>
#include <FUiCtrlListView.h>
#include <FUiCtrlListViewTypes.h>
#include <FUiCtrlMessageBox.h>
#include <FUiCtrlOptionMenu.h>
#include <FUiCtrlOverlayPanel.h>
#include <FUiCtrlOverlayRegion.h>
#include <FUiCtrlPanel.h>
#include <FUiCtrlPopup.h>
#include <FUiCtrlProgress.h>
#include <FUiCtrlProgressPopup.h>
#include <FUiCtrlRadioGroup.h>
#include <FUiCtrlScrollEventTypes.h>
#include <FUiCtrlScrollPanel.h>
#include <FUiCtrlScrollPanelTypes.h>
#include <FUiCtrlSearchBar.h>
#include <FUiCtrlSectionTableView.h>
#include <FUiCtrlSimpleItem.h>
#include <FUiCtrlSlidableGroupedList.h>
#include <FUiCtrlSlidableList.h>
#include <FUiCtrlSlider.h>
#include <FUiCtrlSliderTypes.h>
#include <FUiCtrlSplitPanel.h>
#include <FUiCtrlSplitPanelTypes.h>
#include <FUiCtrlTab.h>
#include <FUiCtrlTabBar.h>
#include <FUiCtrlTabBarItem.h>
#include <FUiCtrlTableView.h>
#include <FUiCtrlTableViewContextItem.h>
#include <FUiCtrlTableViewGroupItem.h>
#include <FUiCtrlTableViewItem.h>
#include <FUiCtrlTableViewItemBase.h>
#include <FUiCtrlTableViewSimpleGroupItem.h>
#include <FUiCtrlTableViewSimpleItem.h>
#include <FUiCtrlTableViewTypes.h>
#include <FUiCtrlTextBox.h>
#include <FUiCtrlTimePicker.h>

namespace Tizen
{
/**
 * @namespace   Tizen::Ui::Controls
 * @brief		This namespace contains the classes and interfaces for creating rich user interface components for the applications.
 * @since		2.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FUi.h> @n
 *				@b Library : @b osp-uifw
 *
 * The %Ui::Controls namespace contains classes that have graphical representations that can be displayed on the screen as UI elements and with
 * which the user can interact.
 *
 * For more information on the %Ui::Controls namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/controls.htm">UI Controls Guide</a>.
 *
 */

namespace Ui
{

namespace Controls
{

/**
 * @if OSPDEPREC
 * The system color for the text that appears in the indicator and the command area (for example, Header and Footer).
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release.
 * @since        2.0
 *
 * @remarks      Different color values can be defined for different device models.
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Graphics::Color SYSTEM_COLOR_TITLE_TEXT;

/**
 * @if OSPDEPREC
 * The system color for the text that appears in controls, has a different background color than that of its parent (for example, Button).
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release.
 * @since        2.0
 *
 * @remarks      Different color values can be defined for different device models.
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Graphics::Color SYSTEM_COLOR_BODY_TEXT;

/**
 * @if OSPDEPREC
 * The system default foreground color (for example, Label and CheckButton).
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release.
 * @since        2.0
 *
 * @remarks      Different color values can be defined for different device models.
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Graphics::Color SYSTEM_COLOR_FOREGROUND;

/**
 * @if OSPDEPREC
 * The system default background color (for example, Label, Panel, and ScrollPanel).
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release.
 * @since        2.0
 *
 * @remarks      Different color values can be defined for different device models.
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Graphics::Color SYSTEM_COLOR_BACKGROUND;

/**
 * @if OSPDEPREC
 * The system default color for the List background.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release.
 * @since        2.0
 *
 * @remarks      Different color values can be defined for different device models.
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Graphics::Color SYSTEM_COLOR_LIST_BACKGROUND;

/**
 * @if OSPDEPREC
 * The system default color for the Form background.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release.
 * @since        2.0
 *
 * @remarks      Different color values can be defined for different device models.
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Graphics::Color SYSTEM_COLOR_FORM_BACKGROUND;

/**
 * @if OSPDEPREC
 * The system default color for the background of the Form with grouped style child controls.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release.
 * @since        2.0
 *
 * @remarks      Different color values can be defined for different device models.
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Graphics::Color SYSTEM_COLOR_FORM_GROUP_BACKGROUND;

/**
 * @if OSPDEPREC
 * The system default color for the Popup background.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release.
 * @since        2.0
 *
 * @remarks      Different color values can be defined for different device models.
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Graphics::Color SYSTEM_COLOR_POPUP_BACKGROUND;

/**
 * @if OSPDEPREC
 * The system default color of the group item text.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release.
 * @since        2.0
 *
 * @remarks      Different color values can be defined for different device models.
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Graphics::Color SYSTEM_COLOR_GROUP_ITEM_TEXT;

/**
 * @if OSPDEPREC
 * The system default color of the list text.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release.
 * @since        2.0
 *
 * @remarks      Different color values can be defined for different device models.
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Graphics::Color SYSTEM_COLOR_LIST_ITEM_TEXT;

/**
 * @if OSPDEPREC
 * The system default color of the list item text, when an item is selected.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release.
 * @since        2.0
 *
 * @remarks      Different color values can be defined for different device models.
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Graphics::Color SYSTEM_COLOR_LIST_ITEM_PRESSED_TEXT;

/**
 * @if OSPDEPREC
 * The system default color of the list element text when the item is highlighted.
 *
 * @brief <i> [Deprecated]  </i>
 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release.
 * @since        2.0
 *
 * @remarks      Different color values can be defined for different device models.
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Graphics::Color SYSTEM_COLOR_LIST_ITEM_HIGHLIGHTED_TEXT;

}; // Tizen::Ui::Controls
}; // Tizen::Ui
}; // Tizen
#endif // _FUI_CONTROLS_H_
