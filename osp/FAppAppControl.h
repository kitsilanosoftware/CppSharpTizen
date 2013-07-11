//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FAppAppControl.h
 * @brief		This is the header file for the %AppControl class.
 *
 * This header file contains the declarations of the %AppControl class.
 */

#ifndef _FAPP_APPCONTROL_H_
#define _FAPP_APPCONTROL_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FAppTypes.h>

namespace Tizen { namespace Base { namespace Collection {
class IList;
class IMap;
}}}

namespace Tizen { namespace App
{

class IAppControlEventListener;
class IAppControlResponseListener;

/**
* @if OSPDEPREC
* The Contact %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_contact.htm">Contact Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.contacts".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CONTACT;

/**
* @if OSPDEPREC
* The Calendar %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_calendar.htm">Calendar Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.calendar" or L"tizen.events".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CALENDAR;

/**
* @if OSPDEPREC
* The Todo %AppControl ID.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This application control provider name is deprecated.
* @b OPERATION_PICK:
* @since	2.0
*
* @remarks	This constant is currently not available.
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_TODO;

/**
* @if OSPDEPREC
* The Dial %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_call.htm">Call Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.phone" with operation L"http://tizen.org/appcontrol/operation/dial".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_DIAL;

/**
* @if OSPDEPREC
* The Call %AppControl ID. @n
* Makes a phone call. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_call.htm">Call Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.phone" with operation L"http://tizen.org/appcontrol/operation/call".
* @since	2.0
* @privilege    %http://tizen.org/privilege/systeminfo
*
* @remarks Privilege is required to use this application control.
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CALL;


/**
* @if OSPDEPREC
* The Message %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_message.htm">Message Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.messages".
* @since	2.0
*
* @remarks An MMS attachment may contain either an image, audio, video, vCard, vCalendar or a combination of an image, audio, vCard, and vCalendar files. @n
* MMS attachments cannot contain a video in combination with an image or an audio file.
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_MESSAGE;

/**
* @if OSPDEPREC
* The Email %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_email.htm">Email Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.email".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_EMAIL;

/**
* @if OSPDEPREC
* The Media %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_media.htm">Media Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.filemanager" or L"tizen.gallery".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_MEDIA;

/**
* @if OSPDEPREC
* The Image %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_image.htm">Image Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.imageviewer".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_IMAGE;

/**
* @if OSPDEPREC
* The Video %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_video.htm">Video Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.videoplayer".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_VIDEO;

/**
* @if OSPDEPREC
* The Audio %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_audio.htm">Audio Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.musicplayer".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_AUDIO;

/**
* @if OSPDEPREC
* The Browser %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_browser.htm">Browser Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.internet".
* @since	2.0
* @privilege    %http://tizen.org/privilege/web.service
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_BROWSER;

/**
* @if OSPDEPREC
* The Camera %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_camera.htm">Camera Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.camera".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CAMERA;

/**
* @if OSPDEPREC
* The Bluetooth %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_bluetooth.htm">Bluetooth Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.bluetooth".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_BT;

/**
* @if OSPDEPREC
* The Setting %AppControl ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_settings.htm">Settings Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.settings".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_SETTINGS;

/**
* @if OSPDEPREC
* The Contact %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_contact.htm">Contact Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.contacts".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_CONTACT;

/**
* @if OSPDEPREC
* The Certificate Manager %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_certmgr.htm">Certificate Manager Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.certificatemanager".
* @since		2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_CERTIFICATE_MANAGER;

/**
* @if OSPDEPREC
* The Calendar %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_calendar.htm">Calendar Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.calendar" or L"tizen.events".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_CALENDAR;

/**
* @if OSPDEPREC
* The Call %AppControl provider ID. @n
* Makes a phone call. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_call.htm">Call Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.phone".
* @since			2.0
* @privilege    %http://tizen.org/privilege/systeminfo
*
* @remarks Privilege is required to use this application control.
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_CALL;

/**
* @if OSPDEPREC
* The Message %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_message.htm">Message Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.messages".
* @since	2.0
*
* @remarks	An MMS attachment may contain either an image, audio, video, vCard, vCalendar or a combination of an image, audio, vCard, and vCalendar files. @n
*           MMS attachments cannot contain a video in combination with an image or an audio file. @n
*			From Tizen 2.0, the CC and BCC recipients are merged with the TO recipients when launching the MMS app control.
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_MESSAGE;

/**
* @if OSPDEPREC
* The Email %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_email.htm">Email Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.email".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_EMAIL;

/**
* @if OSPDEPREC
* The Media %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_media.htm">Media Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.filemanager" or L"tizen.gallery".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_MEDIA;

/**
* @if OSPDEPREC
* The Image %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_image.htm">Image Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.imageviewer".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_IMAGE;

/*
* @if OSPDEPREC
* The ImageCrop application control provider ID @n
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in a future release.
* 				use the literal, L"tizen.imageeditor", instead of this variable.
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_IMAGE_EDITOR;

/**
* @if OSPDEPREC
* The Video %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_video.htm">Video Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.videoplayer".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_VIDEO;

/**
* @if OSPDEPREC
* The Audio %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_audio.htm">Audio Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.musicplayer".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_AUDIO;

/**
* @if OSPDEPREC
* The Browser %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_browser.htm">Browser Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.internet".
* @since			2.0
* @privilege	%http://tizen.org/privilege/web.service
*
* @remarks Privilege is required to use this application control.
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_BROWSER;

/**
* @if OSPDEPREC
* The Camera %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_camera.htm">Camera Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.camera".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_CAMERA;

/**
* @if OSPDEPREC
* The Bluetooth %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_bluetooth.htm">Bluetooth Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.bluetooth".
* @since	2.0
*
* @remarks Bluetooth functionality cannot be tested on the Emulator.
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_BLUETOOTH;

/**
* @if OSPDEPREC
* The Setting %AppControl provider ID. @n
*
* For more information, see <a href="../org.tizen.native.appprogramming/html/guide/app/appcontrol_settings.htm">Settings Application Control</a>.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"tizen.settings".
* @since    2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_SETTINGS;

//
// The AllShare application control provider ID. @n
//
// @since		2.0
// @visibility	internal
// @privlevel	user
// @privilege    ALLSHARE
//
// @remarks Privilege is required to use this application control. @n
//	'path' is the main key of the all keys. Other keys' value are the extra information for the main key's value. @n
//	'path' and 'type' values must be filled mandatorily and the others are optional. @n
//	More than one content can be added if the 'path' key and value item is added in the input list.
//
// @li	Input dataList : @n
// <table border=1 cellpadding="1" cellspacing="1">
// <tr>
//   <th>Key</th>
//   <th>value</th>
//   <th>description</th>
// </tr>
// <tr>
//   <td>path</td>
//   <td>Path, such as /Media/Images/sampleImage.jpg or http://localhost:8080/sampleVideo.mp4 or http://mycompany.com/sampleImage.jpg"</td>
//   <td>This is the main key. @n Path to the media file to be shared.</td>
// </tr>
// <tr>
//   <td>type</td>
//   <td>image|audio|video</td>
//	<td>Type of the media file.</td>
// </tr>
// <tr>
//   <td>title</td>
//   <td>Title, such as MyTitle</td>
//   <td>Title of the media file.</td>
// </tr>
// <tr>
//   <td>duration</td>
//   <td>Duration in milliseconds, such as 60000 (60secs)</td>
//	<td>Duration of the media file.</td>
// </tr>
// <tr>
//   <td>bitrate</td>
//   <td>Bit rate in kilo-bits per second, such as 192</td>
//	<td>Bit rate of the media file.</td>
// </tr>
// <tr>
//   <td>width</td>
//   <td>Width in pixel, such as 640</td>
//	<td>Width of the media file</td>
// </tr>
// <tr>
//   <td>height</td>
//   <td>Height in pixel, such as 480</td>
//	<td>Height of the media file</td>
// </tr>
//<tr>
//	<td>size</td>
//	<td>Size in bytes, such as 512000 (500KB)</td>
//	<td>Size of the media file.</td>
//</td>
//<tr>
//	<td>mimeType</td>
//	<td>Mime type, such as audio/mp3</td>
//	<td>Mime type of the media file.</td>
//</tr>
//<tr>
//	<td>artist</td>
//	<td>Artist, such as TizenSinger</td>
//	<td>Artist of media file.</td>
//</tr>
//<tr>
//	<td>albumTitle</td>
//	<td>Album title, such as TizenAlbum</td>
//	<td>Album title of media file.</td>
//</tr>
// </table>
//
// @n
// @li	Example code for AllShare: @n
// @code
//     void
//     MyAppClass::AllShareAppControlSample(void)
//     {
//         ArrayList* pDataList = new ArrayList();
//
//         pDataList->Construct();
//         pDataList->Add(*new String(L"path:/mycompany.com/sampleImage.jpg"));
//         pDataList->Add(*new String(L"type:image"));
//         pDataList->Add(*new String(L"title:MyImage"));
//         pDataList->Add(*new String(L"width:640"));
//         pDataList->Add(*new String(L"height:480"));
//         pDataList->Add(*new String(L"size:51200"));
//         pDataList->Add(*new String(L"mimeType:image/jpg"));
//         pDataList->Add(*new String(L"path:http://mycompany.com/sampleVideo.mp4"));
//         pDataList->Add(*new String(L"type:video"));
//         pDataList->Add(*new String(L"title:MyVideo"));
//         pDataList->Add(*new String(L"duration:600000"));
//         pDataList->Add(*new String(L"width:320"));
//         pDataList->Add(*new String(L"height:240"));
//         pDataList->Add(*new String(L"size:2097152"));
//         pDataList->Add(*new String(L"mimeType:video/mp4"));
//         pDataList->Add(*new String(L"path:http://mycompany.com/sampleAudio.mp3"));
//         pDataList->Add(*new String(L"type:audio"));
//         pDataList->Add(*new String(L"title:MyAudio"));
//         pDataList->Add(*new String(L"duration:200000"));
//         pDataList->Add(*new String(L"size:3565158"));
//         pDataList->Add(*new String(L"mimeType:audio/mp3"));
//         pDataList->Add(*new String(L"artist:TizenSinger"));
//         pDataList->Add(*new String(L"albumTitle:TizenAlbum"));
//
//         AppControl* pAc = AppManager::FindAppControlN(APPCONTROL_PROVIDER_ALLSHARE, APPCONTROL_OPERATION_SHARE);
//         if (pAc)
//         {
//             pAc->Start(pDataList, null);
//             delete pAc;
//         }
//
//         pDataList->RemoveAll(true);
//         delete pDataList;
//     }
//
// @endcode
//
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_PROVIDER_ALLSHARE;

/**
* @if OSPDEPREC
* Operation Add. @n
* Adds an application item.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/add".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String OPERATION_ADD;

/**
* @if OSPDEPREC
* Operation Pick. @n
* Picks some application item(s).
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/pick".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String OPERATION_PICK;

/**
* @if OSPDEPREC
* Operation Edit. @n
* Edits an application item.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/edit".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String OPERATION_EDIT;

/**
* @if OSPDEPREC
* Operation View. @n
* Shows the application content.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/view".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String OPERATION_VIEW;

/**
* @if OSPDEPREC
* Operation Play. @n
* Plays the application content.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/view".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String OPERATION_PLAY;

/**
* @if OSPDEPREC
* Operation Default. @n
*
* Uses the default operation specific to the application control.
* An application control can export its functionality using an operation. If the application control exports only one operation, OPERATION_DEFAULT can act as an alias for the operation.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/main".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String OPERATION_DEFAULT;

/**
* @if OSPDEPREC
* Operation Capture.
*
* @brief	<i> [Deprecated] </i>
* @deprecated This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/createcontent".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String OPERATION_CAPTURE;


/**
* @if OSPDEPREC
* Operation Add. @n
* Adds an application item.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/add".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_ADD;

/**
* @if OSPDEPREC
* Operation Call. @n
* Makes a call to the specified phone number.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/call".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_CALL;

/**
* @if OSPDEPREC
* Operation Capture.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/createcontent".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_CAPTURE;

/**
* @if OSPDEPREC
* Operation Compose.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/compose".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_COMPOSE;

/**
* @if OSPDEPREC
* Operation Configure Settings.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/configure".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_CONFIGURE;

/**
* @if OSPDEPREC
* Operation Default. @n
*
* Uses the default operation specific to the application control.
* An application control can export its functionality using an operation. If the application control exports only one operation, OPERATION_DEFAULT can act as an alias for the operation.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/main".
* @since 2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_DEFAULT;

/**
* @if OSPDEPREC
* Operation Dial. @n
* Launches the dial screen for making a call.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/dial".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_DIAL;

/**
* @if OSPDEPREC
* Operation Edit. @n
* Edits an application item.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/edit".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_EDIT;

/**
* @if OSPDEPREC
* Operation Main. @n
*
* All the application exports the implicit %AppControl with %APPCONTROL_OPERATION_MAIN operation.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/main".
*	@since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_MAIN;

/**
* @if OSPDEPREC
* Operation Pick. @n
* Picks some application item(s).
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is providyed only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/pick".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_PICK;

/**
* @if OSPDEPREC
* Operation Play. @n
* Plays the application content.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/view".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_PLAY;

/**
* @if OSPDEPREC
* Operation Record. @n
* Records the content.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/createcontent".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_RECORD;

/**
* @if OSPDEPREC
* Operation Share. @n
* Shares the contents.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/share".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_SHARE;

/**
* @if OSPDEPREC
* Operation View. @n
* Shows the application content.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/view".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_VIEW;

/**
* @if OSPDEPREC
* Operation Crop. @n
* Shows image with the crop rectangle.
*
* @brief	<i> [Deprecated] </i>
* @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
* 				Instead of this variable, use the literal, L"http://tizen.org/appcontrol/operation/crop".
* @since	2.0
* @endif
*/
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_OPERATION_CROP;

/**
 * @if OSPDEPREC
 * Not specified category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_NONE;

/**
 * @if OSPDEPREC
 * The audio category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_AUDIO;

/**
 * @if OSPDEPREC
 * The browser category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_BROWSER;

/**
 * @if OSPDEPREC
 * The Bluetooth device category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_BLUETOOTH;

/**
 * @if OSPDEPREC
 * The calendar category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_CALENDAR;

/**
 * @if OSPDEPREC
 * The certificate category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_CERTIFICATE;

/**
 * @if OSPDEPREC
 * The contact category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_CONTACT;

/**
 * @if OSPDEPREC
 * The document category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_DOCUMENT;

/**
 * @if OSPDEPREC
 * The email category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_EMAIL;

/**
 * @if OSPDEPREC
 * The media category. @n
 * Specifying App::APPCONTROL_CATEGORY_MEDIA is equivalent to specifying all the App::APPCONTROL_CATEGORY_AUDIO,
 * App::APPCONTROL_CATEGORY_IMAGE, and App::APPCONTROL_CATEGORY_VIDEO categories.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_MEDIA;

/**
 * @if OSPDEPREC
 * The MMS category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_MMS;

/**
 * @if OSPDEPREC
 * The image category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_IMAGE;

/**
 * @if OSPDEPREC
 * The security category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_SECURITY;

/**
 * @if OSPDEPREC
 * The SMS category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_SMS;

/**
 * @if OSPDEPREC
 * The settings category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_SETTINGS;

/**
 * @if OSPDEPREC
 * The video call category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_VIDEO_CALL;

/**
 * @if OSPDEPREC
 * The voice call category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_VOICE_CALL;

/**
 * @if OSPDEPREC
 * The video category.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_VIDEO;

/**
 * @if OSPDEPREC
 * The complete URI handling category corresponding to AppManager::StartAppControl().
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_CATEGORY_URI;

/**
 * @if OSPDEPREC
 * The %AppControl operation is successful.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_RESULT_SUCCEEDED;

/**
 * @if OSPDEPREC
 * The %AppControl operation has failed.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_RESULT_FAILED;

/**
 * @if OSPDEPREC
 * The %AppControl operation is canceled.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_RESULT_CANCELED;

/**
 * @if OSPDEPREC
 * The %AppControl is terminated without sending the result.
 *
 * @brief	<i> [Deprecated] </i>
 * @deprecated	This variable is provided only for backward compatibility and will be deleted in the near future.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String APPCONTROL_RESULT_TERMINATED;

/**
* @class	AppControl
* @brief	This class represents the application control behavior.
* @since	2.0
*
*	@final	This class is not intended for extension.
*
*	The %AppControl class represents the application control behavior that provides a standard mechanism for using specific operations exported by other applications.
*
* For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/app/app_controls.htm">Application Controls</a>.
*
* @see	Tizen::App::AppManager
*
*  The following example demonstrates how to use the %AppControl class.
*
*
* @code
*
*	using namespace Tizen::Base::Collection;
*	using namespace Tizen::App;
*
*	void
*	MyAppClass::AppControlCallSample(void)
*	{
*		HashMap extraData;
*		String telKey = L"tel";
*		String telVal = L"1234567890";
*		String typeKey = L"type";
*		String typeVal = L"voice";
*
*		extraData.Construct();
*		extraData.Add(&telKey, &telVal);
*		extraData.Add(&typeKey, &typeVal);
*
*		AppControl* pAc = AppManager::FindAppControlN(L"tizen.phone", L"http://tizen.org/appcontrol/operation/call");
*		if(pAc)
*		{
*			pAc->Start(null, null, &extraData, null);
*			delete pAc;
*		}
*	}
*
* @endcode
*/
class _OSP_EXPORT_ AppControl
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~AppControl(void);

	/**
 	 * @if OSPDEPREC
	 * Starts the resolved application control. @n
	 * Once the application starts, it goes to the background and the target
	 * application control is displayed.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because IAppControlEventListener method is deprecated and replaced by
	 * 				IAppControlResponseListener due to lack of argument capability. @n
	 * 				Instead of using this method, use Start().
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/application.launch
	 *
	 * @return		An error code
	 * @param[in]	pDataList	The data list to deliver to the resolved application control @n
	 *							The maximum size of the list is 4096 bytes.
	 * @param[in]	pListener	The application control callback listener @n
	 *							Some application controls need to get the callback result by implementing the IAppControlEventListener interface.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_MAX_EXCEEDED			The size of @c pDataList has exceeded the maximum limit.
	 * @exception	E_OBJ_NOT_FOUND			The target application control resource is not found.
	 * @exception	E_IN_PROGRESS			The application control is in progress: @n
	 *                                       - The application has already started an %AppControl. @n
	 *                                       - The target application has already started.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		If the IAppControlEventListener instance (@c pListener) needs to get the
	 *               callback result for an application control, it must be valid till
	 *               IAppControlEventListener::OnAppControlCompleted() is invoked.
	 *               For example, a form object listener must not be deleted before the
	 *               system invokes %IAppControlEventListener::OnAppControlCompleted().
	 * @see	AppManager::FindAppControlN()
	 * @see	AppManager::FindAppControlsN()
	 * @endif
	 */
	result Start(const Tizen::Base::Collection::IList* pDataList, IAppControlEventListener* pListener);

	/**
	 * Starts the found application control. @n
	 * Once the found application starts, the calling application goes to the background and the found
	 * application is displayed.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/application.launch
	 *
	 * @return		An error code
	 * @param[in]	pUriData	A pointer to the URI data
	 * @param[in]	pDataType	A pointer to the MIME type (RFC 2046) data
	 * @param[in]	pExtraData	A pointer to an argument map of key and value pair where the key is of type String and the value is of type String to deliver to the resolved application @n
	 *							The maximum size is 16 kilo bytes.
	 * @param[in]	pListener	The application control callback listener @n
	 *							Some application need to get the result by implementing the IAppControlResponseListener interface.
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_MAX_EXCEEDED			The size of @c pExtraData has exceeded the maximum limit.
	 * @exception	E_OBJ_NOT_FOUND			The target application control is not found.
	 * @exception	E_IN_PROGRESS			The application control is in progress: @n
	 *                                      - The application has already started an %AppControl.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		If the calling application needs to get some result for application control,
	 * 				it must be valid till IAppControlResponseListener::OnAppControlCompleteResponseReceived() is invoked.
	 * 				For example, a form object listener must not be deleted before the
	 * 				system invokes %IAppControlResponseListener::OnAppControlCompleteResponseReceived().
	 * @see	AppManager::FindAppControlN()
	 * @see	AppManager::FindAppControlsN()
	 */
	result Start(const Tizen::Base::String* pUriData, const Tizen::Base::String* pDataType, const Tizen::Base::Collection::IMap* pExtraData, IAppControlResponseListener* pListener);

	/**
	 * Finds the matching application control with given operation ID, URI pattern, data type, and category and
	 * starts the found one. @n
	 * If there are more than one application controls found, then the selection is shown for user and the one that the user selects is started.
	 * When the found application control is started, the URI pattern, MIME type, and extra data is delivered using IAppControlProviderEventListener.
	 *
	 * @since	2.0
	 * @privilege	%http://tizen.org/privilege/application.launch
	 *
	 * @return  An error code
	 * @param[in]   operationId	The operation ID
	 * @param[in]   pUriPattern		A URI pattern which is used for application control resolution and is delivered as the argument
	 * @param[in]   pDataType   The MIME type (RFC 2046) or file extension @n
	 *                          The '.' prefix must be used when specifying the file extension.
	 * @param[in]   pCategory	The application control category
	 * @param[in]	pExtraData	A pointer to an argument map of key and value pair where the key is of type String and the value is of type String to deliver to the resolved application @n
	 * 							The maximum size is 16 kilo bytes.
	 * @param[in]   pListener   A listener that gets notified
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_MAX_EXCEEDED      The size of @c pDataList has exceeded the maximum limit.
	 * @exception   E_OBJ_NOT_FOUND     The application control is not found.
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @see IAppControlResponseListener
	 */
	static result FindAndStart(const Tizen::Base::String& operationId, const Tizen::Base::String* pUriPattern, const Tizen::Base::String* pDataType, const Tizen::Base::String* pCategory, const Tizen::Base::Collection::IMap* pExtraData, IAppControlResponseListener* pListener);

	/**
	 * Stops the event listener from receiving the application control result.
	 *
	 * @since	2.0
	 *
	 * @param[in]	pListener	The listener to stop receiving the application control result
	 */
	static void StopAppControlResponseListener(IAppControlResponseListener* pListener);

	/**
	 * Gets the name of the application that provides the features represented by this %AppControl instance.
	 *
	 * @since			2.0
	 *
	 * @return		The name of the application providing this %AppControl instance
	 */
	Tizen::Base::String GetAppName(void) const;

	/**
	 * Gets the associated application ID.
	 *
	 * @since	2.0
	 *
	 * @return	The application ID
	 */
	AppId GetAppId(void) const;

	/**
         * @if OSPDEPREC
	 * Gets the associated application control provider ID.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated because application ID replaced the role of provider ID. @n
	 * 				Instead of using this method, use GetAppId().
	 * @since			2.0
	 *
	 * @return		The application control provider ID
         * @endif
	 */
	Tizen::Base::String GetAppControlProviderId(void) const;

	/**
	 * Gets the associated operation ID.
	 *
	 * @since			2.0
	 *
	 * @return		The operation ID
	 */
	Tizen::Base::String GetOperationId(void) const;

	/**
	 * Gets the associated application control categories.
	 *
	 * @since	2.0
	 *
	 * @return	A pointer to the list of application control categories, @n
	 *               else @c null if an error occurs
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::Collection::IList* GetCategoryListN(void) const;


	/**
	 * Stops the activated application control. @n
	 * The %Stop() method works only with the following %AppControls provided by the platform:
	 * App::APPCONTROL_PROVIDER_AUDIO, App::APPCONTROL_PROVIDER_BLUETOOTH, @n
	 * App::APPCONTROL_PROVIDER_CALENDAR, App::APPCONTROL_PROVIDER_CAMERA, @n
	 * App::APPCONTROL_PROVIDER_CERTIFICATE_MANAGER, App::APPCONTROL_PROVIDER_CONTACT, @n
	 * App::APPCONTROL_PROVIDER_EMAIL, App::APPCONTROL_PROVIDER_IMAGE, @n
	 * App::APPCONTROL_PROVIDER_MEDIA, App::APPCONTROL_PROVIDER_MESSAGE, @n
	 * and App::APPCONTROL_PROVIDER_VIDEO.
	 *
	 * @since		2.0
	 *
	 * @return          An error code
	 * @exception E_SUCCESS                        The method is successful.
	 * @exception E_SYSTEM                         A system error has occurred.
	 * @exception E_INVALID_OPERATION        The application control is not permitted to call this method.
	 * @remarks	This method is asynchronous.
	 */
	result Stop(void);

private:
	/**
	 * This constructor is intentionally declared as private so that only the platform can create an instance.
	 *
	 * @since	2.0
	 */
	AppControl(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AppControl(const AppControl& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AppControl& operator =(const AppControl& rhs);


private:
	class _AppControlImpl * __pAppControlImpl;

	friend class _AppControlImpl;
}; // AppControl

} } // Tizen::App

#endif // _FAPP_APPCONTROL_H_
