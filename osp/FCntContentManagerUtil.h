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
 * @file			FCntContentManagerUtil.h
 * @brief		This is the header file for the %ContentManagerUtil class.
 *
 * This header file contains the declarations of the %ContentManagerUtil class.
 */

#ifndef _FCNT_CONTENT_MANAGER_UTIL_H_
#define _FCNT_CONTENT_MANAGER_UTIL_H_

#include <FBaseObject.h>
#include <FCntTypes.h>

namespace Tizen { namespace Content
{

class ImageMetadata;
class AudioMetadata;
class VideoMetadata;

/**
 * @class	ContentManagerUtil
 * @brief	This class provides methods for managing the content's utility.
 *
 * @since	2.0
 *
 * The %ContentManagerUtil class provides access to different local content types, such as image, audio, and video, and manages the content metadata.
 *
 * For more information on managing the content's utility on the device, see <a href="../org.tizen.native.appprogramming/html/guide/content/device_content_mgmt.htm">Device Content Management</a>.
 *
 * The following example demonstrates how to use the %ContentManagerUtil class.
 *
 * @code
 * result
 * MyClass::TestContentManagerUtil(void)
 * {
 *		// Image
 *		Tizen::Base::String imagePath = Tizen::System::Environment::GetMediaPath() + L"Images/full_meta.jpg";
 *		ImageMetadata* pImageMeta = ContentManagerUtil::GetImageMetaN(imagePath);
 *		TryReturn(pImageMeta != null, GetLastResult(), "GetImageMetaN failed.");
 *
 *		// Audio
 *		Tizen::Base::String audioPath = Tizen::System::Environment::GetMediaPath() + L"Sounds/hot.mp3";
 *		AudioMetadata* pAudioMeta = ContentManagerUtil::GetAudioMetaN(audioPath);
 *		if(pAudioMeta == null)
 *		{
 *			delete pImageMeta;
 *			return GetLastResult();
 *		}
 *
 *		// Video
 *		Tizen::Base::String videoPath = Tizen::System::Environment::GetMediaPath() + L"Videos/video.mp4";
 *		VideoMetadata* pVideoMeta = ContentManagerUtil::GetVideoMetaN(videoPath);
 *		if(pVideoMeta == null)
 *		{
 *			delete pImageMeta;
 *			delete pAudioMeta;
 *			return GetLastResult();
 *		}
 *
 *		delete pImageMeta;
 *		delete pAudioMeta;
 *		delete pVideoMeta;
 *
 *		return E_SUCCESS;
 * }
 * @endcode
 */
class _OSP_EXPORT_ ContentManagerUtil
{
public:
	/**
	 * Gets the metadata for an image.
	 *
	 * @if OSPCOMPAT
	 * @brief	<i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *                       For more information, see @ref CompContentManagerUtilPage "here".
	 * @endif
	 *
	 * @return			A pointer to ImageMetadata, @n
	 *                     else @c null if an exception occurs
	 * @param[in]	filePath					The file path
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The supported formats are 'jpg', 'jpeg', 'gif', 'png', 'bmp', 'wbmp', or 'tiff'. @n
	 *						The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Content::ImageMetadata* GetImageMetaN(const Tizen::Base::String& filePath);

	/**
	 * Gets the metadata for an audio.
	 *
	 * @if OSPCOMPAT
	 * @brief	<i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *                       For more information, see @ref CompContentManagerUtilPage "here".
	 * @endif
	 *
	 * @return			A pointer to AudioMetadata, @n
	 *                     else @c null if an exception occurs
	 * @param[in]	filePath					The file path
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The supported formats are 'mp3', 'wav', 'aac', 'wma', 'm4a', 'xmf', '3ga', or 'mmf'. @n
	 *                     The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Content::AudioMetadata* GetAudioMetaN(const Tizen::Base::String& filePath);

	/**
	 * Gets the metadata for a video.
	 *
	 * @if OSPCOMPAT
	 * @brief	<i> [Compatibility] </i>
	 * @endif
	 * @since			2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *                       For more information, see @ref CompContentManagerUtilPage "here".
	 * @endif
	 *
	 * @return			A pointer to VideoMetadata, @n
	 *                     else @c null if an exception occurs
	 * @param[in]	filePath					The file path
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		The supported formats are 'wmv', 'asf', 'mp4', '3gp', or 'avi'. @n
	 *                     The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Content::VideoMetadata* GetVideoMetaN(const Tizen::Base::String& filePath);

	/**
	 * Checks the content type from the file path.
	 *
	 * @if OSPCOMPAT
	 * @brief	<i> [Compatibility] </i>
	 * @endif
	 * @since           2.0
	 * @if OSPCOMPAT
	 * @compatibility This method has compatibility issues with OSP compatible applications. @n
	 *                       For more information, see @ref CompContentManagerUtilPage "here".
	 * @endif
	 *
	 * @return			The content type
	 * @param[in]	filePath						The file path
	 * @exception	E_SUCCESS						The method is successful.
	 * @exception	E_INVALID_ARG					The specified input parameter is invalid, or
	 *                                                          the length of the specified path is @c 0 or exceeds system limitations.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_FILE_NOT_FOUND			The specified file cannot be found.
	 * @exception    E_UNSUPPORTED_FORMAT	The specified format is invalid or not supported.
	 * @remarks		The content type can be different for each device. @n
	 *                     The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Content::ContentType CheckContentType(const Tizen::Base::String& filePath);

	/**
	 * @if OSPDEPREC
	 * Copies an existing file to a new directory.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated   This method is deprecated because a new method has been added. @n
	 *                       Instead of using this method, use ContentManager::CreateContent(const Tizen::Base::String&, const Tizen::Base::String&, bool, const ContentInfo*).
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		srcFilePath				The source file path
	 * @param[in]		destFilePath				The destination file path
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_ARG				Either of the following conditions has occurred: @n
	 *															- The length of the specified path is equal to @c 0 or exceeds system limitations. @n
	 *															- The specified path contains prohibited character(s). @n
	 *															- The specified path is invalid.
	 * @exception		E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	 * @exception		E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception		E_FILE_ALREADY_EXIST	The specified file already exists.
	 * @exception		E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	 * @exception		E_STORAGE_FULL			The disk space is full.
	 * @exception		E_IO								Either of the following conditions has occurred: @n
	 *                                                           - An unexpected device failure has occurred as the media ejected suddenly. @n
	 *                                                           - File corruption is detected. @n
	 *                                                           - The volume or quota is no more available.
	 * @remarks		The source file in the system region cannot be copied. @n
	 *                       The destination file path must start with @c '/Media' or @c '/Storagecard/Media'.
	 * @endif
	 */
	static result CopyToMediaDirectory(const Tizen::Base::String& srcFilePath, const Tizen::Base::String& destFilePath);

	/**
	 * @if OSPDEPREC
	 * Moves the file to a new directory.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated   This method is deprecated because a new method has been added. @n
	 *                       Instead of using this method, use ContentManager::CreateContent(const Tizen::Base::String&, const Tizen::Base::String&, bool, const ContentInfo*).
	 * @since			2.0
	 *
	 * @return			An error code
	 * @param[in]		srcFilePath				The source file path
	 * @param[in]		destFilePath				The destination file path
	 * @exception		E_SUCCESS					The method is successful.
	 * @exception		E_INVALID_ARG				Either of the following conditions has occurred: @n
	 *                                                           - The length of the specified path is equal to @c 0 or exceeds system limitations. @n
	 *                                                           - The specified path contains prohibited character(s). @n
	 *                                                           - The specified path is invalid.
	 * @exception		E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	 * @exception		E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception		E_FILE_ALREADY_EXIST	The specified file already exists.
	 * @exception		E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	 * @exception		E_STORAGE_FULL			The disk space is full.
	 * @exception		E_IO								Either of the following conditions has occurred: @n
	 *															- An unexpected device failure has occurred as the media ejected suddenly. @n
	 *															- File corruption is detected. @n
	 *															- The volume or quota is no more available.
	 * @remarks		The source file in the system region cannot be copied. @n
	 *                       The destination file path must start with @c '/Media' or @c '/Storagecard/Media'.
	 * @endif
	 */
	static result MoveToMediaDirectory(const Tizen::Base::String& srcFilePath, const Tizen::Base::String& destFilePath);

	/**
	 * @if OSPCOMPAT
	 * @page	CompContentManagerUtilPage Compatibility for the file path.
	 * @section	CompContentManagerUtilPageIssueSection Issues
	 *                 The file path argument of this method in OSP compatible applications has the following issues: @n
	 *                 -# The file path should be a path that begins with an allowed path prefix. @n
	 *                     For example, L"/Media/Images/flower.jpg", "/Storagecard/Media/Images/flower.jpg".
	 *
	 * @section	CompContentManagerUtilPageSolutionSection Resolutions
	 *                 This issue has been resolved in Tizen. @n
	 *                 -# The file path can be a path without a specific allowed path prefix. @n
	 *                 Application do not need to know the specific allowed path prefixes. @n
	 *                 To get the directory path, use the following methods: @n
	 *                 - For accessing the home directory, use Tizen::App::App::GetInstance()->GetAppRootPath().
	 *                 - For accessing the media directory, use Tizen::System::Environment::GetMediaPath().
	 *                 - For accessing the external storage, use Tizen::System::Environment::GetExternalStoragePath().
	 *
	 * @endif
	 */

private:
	/**
	 * This default constructor is intentionally declared as private because this class cannot be constructed.
	 */
	ContentManagerUtil(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentManagerUtil(const ContentManagerUtil& rhs);

	/**
	 * This destructor is intentionally declared as private because this class cannot be constructed.
	 */
	virtual ~ContentManagerUtil(void);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentManagerUtil& operator =(const ContentManagerUtil& rhs);

};  // class ContentManagerUtil

}}  // Tizen::Content

#endif  // _FCNT_CONTENT_MANAGER_UTIL_H_
