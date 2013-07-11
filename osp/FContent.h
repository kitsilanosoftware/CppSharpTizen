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
 * @file		FContent.h
 * @brief		This is the header file for the %Tizen::Content namespace.
 *
 * This header file contains the declarations and descriptions of the %Tizen::Content namespace.
 */

#ifndef _FCNT_H_
#define _FCNT_H_

#include <FCntContentInfo.h>
#include <FCntImageContentInfo.h>
#include <FCntAudioContentInfo.h>
#include <FCntVideoContentInfo.h>
#include <FCntOtherContentInfo.h>
#include <FCntContentManager.h>
#include <FCntContentManagerUtil.h>
#include <FCntImageMetadata.h>
#include <FCntAudioMetadata.h>
#include <FCntVideoMetadata.h>
#include <FCntContentSearch.h>
#include <FCntContentDirectory.h>
#include <FCntPlayList.h>
#include <FCntPlayListManager.h>
#include <FCntContentSearchResult.h>
#include <FCntContentTransfer.h>
#include <FCntContentTransferInfo.h>
#include <FCntIContentTransferListener.h>
#include <FCntIContentScanListener.h>
#include <FCntDownloadRequest.h>
#include <FCntDownloadManager.h>
#include <FCntIDownloadListener.h>

namespace Tizen
{

/**
 * @namespace	Tizen::Content
 * @brief		This namespace contains classes and interfaces for content management and search services.
 * @since		2.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FContent.h> @n
 *						@b Library : @b osp-content
 *
 * The %Content namespace contains classes for managing the most common media data types, such as image, audio, and video on the device. This namespace also provides operations to search content and content information stored on the device, and to download content from servers through HTTP access.
 *
 * For more information on the %Content namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/content/content_namespace.htm">Content Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Content namespace.
 * @image html content_using_the_apis_classdiagram.png
 */

namespace Content
{
}}  // Tizen::Content

#endif  // _FCNT_H_
