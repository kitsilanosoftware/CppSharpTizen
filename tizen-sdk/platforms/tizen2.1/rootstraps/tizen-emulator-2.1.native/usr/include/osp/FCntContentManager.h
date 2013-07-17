//
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
 * @file			FCntContentManager.h
 * @brief		This is the header file for the %ContentManager class.
 *
 * This header file contains the declarations of the %ContentManager class.
 */

#ifndef _FCNT_CONTENT_MANAGER_H_
#define _FCNT_CONTENT_MANAGER_H_

#include <FBaseObject.h>
#include <FCntTypes.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
}}

namespace Tizen { namespace Content
{

class ContentInfo;
class _ContentManagerImpl;
class IContentScanListener;
class IContentUpdateEventListener;

/**
 * @class	ContentManager
 * @brief	This class provides methods for local content management.
 *
 * @since	2.0
 *
 * The %ContentManager class manages the information stored locally on the device's content database. @n
 * It also allows you to create, read, update, and delete specific content information in the database.
 *
 * For more information on managing content on the device, see <a href="../org.tizen.native.appprogramming/html/guide/content/device_content_mgmt.htm">Device Content Management</a>.
 *
 * The following example demonstrates how to use the %ContentManager class.
 *
 * @code
 * result
 * MyClass::TestContentManager(void)
 * {
 *		result r = E_SUCCESS;
 *		ContentId contentId;
 *		ContentManager contentManager;
 *		r = contentManager.Construct();
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		// Creates
 *		ImageContentInfo imageContentInfo;
 *		r = imageContentInfo.Construct(null);
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		r = imageContentInfo.SetKeyword(L"platform, tizen");
 *		if (IsFailed(r))
 *		{
 *			return r;
 *		}
 *
 *		r = imageContentInfo.SetLocationTag(L"seoul");
 *		if (IsFailed(r))
 *		{
 *			return r;
 *		}
 *
 *		Tizen::Base::String sourcePath = Tizen::App::App::GetInstance()->GetAppRootPath() + L"data/flower.jpg";
 *		Tizen::Base::String destPath = Tizen::System::Environment::GetMediaPath() + L"Images/flower.jpg";
 *
 *		contentId = contentManager.CreateContent(sourcePath, destPath, false, &imageContentInfo);
 *		TryReturn(Tizen::Base::UuId::GetInvalidUuId() != contentId, GetLastResult(), "CreateContent failed.");
 *
 *		// Gets
 *		ImageContentInfo* pImageContentInfo = null;
 *		pImageContentInfo = dynamic_cast<ImageContentInfo*>(contentManager.GetContentInfoN(contentId));
 *		TryReturn(pImageContentInfo != null, GetLastResult(), "GetContentInfoN failed.");
 *
 *		pImageContentInfo->GetContentPath();
 *
 *		// Updates
 *		r = pImageContentInfo->SetKeyword(L"apple, fruit");
 *		if (IsFailed(r))
 *		{
 *			delete pImageContentInfo;
 *			return r;
 *		}
 *		r = pImageContentInfo->SetProvider(L"kw1128");
 *		if (IsFailed(r))
 *		{
 *			delete pImageContentInfo;
 *			return r;
 *		}
 *		r = contentManager.UpdateContent(*pImageContentInfo);
 *		if (IsFailed(r))
 *		{
 *			delete pImageContentInfo;
 *			return r;
 *		}
 *
 *		// Deletes
 *		r = contentManager.DeleteContent(contentId);
 *		if (IsFailed(r))
 *		{
 *			delete pImageContentInfo;
 *			return r;
 *		}
 *
 *		delete pImageContentInfo;
 *	 	return r;
 * }
 * @endcode
 */
class _OSP_EXPORT_ ContentManager
	: virtual public Tizen::Base::Object
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	ContentManager(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~ContentManager(void);

	/**
	 * Initializes this instance of %ContentManager.
	 *
	 * @since			2.0
	 *
	 * @return			An error code
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM					A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Creates the content information.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/content.write
	 *
	 * @return			The content ID
	 * @param[in]	contentInfo						An instance of ContentInfo
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid, or
	 *                                                      the specified format is invalid or not supported on the device.
	 * @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception	E_IO								An I/O error has occurred.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM						A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SERVICE_BUSY			The database is busy.
	 * @remarks
	 * 				- If the @c E_UNSUPPORTED_FORMAT exception is received from ContentManagerUtil::CheckContentType(),
	 *					the file can be created as a content only using the OtherContentInfo class.
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 */
	ContentId CreateContent(const ContentInfo& contentInfo);

	/**
	 * Writes the content in the byte buffer to the destination path and creates the content information.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/content.write
	 *
	 * @return			The content ID
	 * @param[in]	byteBuffer						The @c byteBuffer of the content to create
	 * @param[in]	destinationPath				The destination file path formed by the @c byteBuffer
	 * @param[in]	pContentInfo					A pointer to the ContentInfo instance @n
	 *                                                         If the content path exists in %ContentInfo, it gets ignored.
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				Either of the following conditions has occurred: @n
	 *                                                         - A specified input parameter is invalid. @n
	 *                                                         - There is a mismatch between the type specified in ContentInfo and the type specified in the actual content.
	 * @exception	E_STORAGE_FULL			The storage is full.
	 * @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	 * @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	 * @exception	E_IO								An I/O error has occurred.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM						A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SERVICE_BUSY			The database is busy.
	 * @remarks
	 * 				- The destination path should start with the directory path returned by either Tizen::System::Environment::GetMediaPath() or Tizen::System::Environment::GetExternalStoragePath().
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 */
	ContentId CreateContent(const Tizen::Base::ByteBuffer& byteBuffer, const Tizen::Base::String& destinationPath, const ContentInfo* pContentInfo = null);

	/**
	 * Copies or moves the actual content to the destination path and creates the content information.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/content.write
	 *
	 * @return			The content ID
	 * @param[in]	sourcePath						The source file path
	 * @param[in]	destinationPath				The destination file path
	 * @param[in]	deleteSource					Set to @c true in order to delete the source file, @n
	 *															else @c false
	 * @param[in]	pContentInfo					A pointer to the ContentInfo instance @n
	 *                                                         If the content path exists in %ContentInfo, it gets ignored.
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				Either of the following conditions has occurred: @n
	 *                                                         - A specified input parameter is invalid. @n
	 *                                                         - There is a mismatch between the type of the source path and destination path. @n
	 *                                                         - There is a mismatch between the type specified in ContentInfo and the type specified in the actual content.
	 * @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception	E_STORAGE_FULL			The storage is full.
	 * @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	 * @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	 * @exception	E_IO								An I/O error has occurred.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM						A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SERVICE_BUSY			The database is busy.
	 * @remarks
	 * 				- The source path should start with the directory path returned by either Tizen::App::App::GetAppRootPath() or Tizen::System::Environment::GetExternalStoragePath().
	 *				- The destination path should start with the directory path returned by either Tizen::System::Environment::GetMediaPath() or Tizen::System::Environment::GetExternalStoragePath().
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 */
	ContentId CreateContent(const Tizen::Base::String& sourcePath, const Tizen::Base::String& destinationPath, bool deleteSource, const ContentInfo* pContentInfo = null);

	/**
	 */

	/**
	 * Gets the content information.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/content.read
	 *
	 * @return			A pointer to ContentInfo
	 * @param[in]	contentId						The content ID
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid, or
	 *                                          the content information corresponding to @c contentId cannot be found.
	 * @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM						A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SERVICE_BUSY			The database is busy.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	ContentInfo* GetContentInfoN(const ContentId& contentId) const;

	/**
	 * Updates the content information with the specified instance of ContentInfo.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/content.write
	 *
	 * @return			An error code
	 * @param[in]	contentInfo						An instance of ContentInfo
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid.
	 * @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM						A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SERVICE_BUSY			The database is busy.
	 */
	result UpdateContent(const ContentInfo& contentInfo);

	/**
	 * Deletes the content information with the specified content ID.
	 *
	 * @since			2.0
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/content.write
	 *
	 * @return			An error code
	 * @param[in]	contentId						The content ID
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				The specified input parameter is invalid, or
	 *                                          the content information corresponding to @c contentId cannot be found.
	 * @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	 * @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM						A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_SERVICE_BUSY			The database is busy.
	 * @remarks		The physical file corresponding to @c contentId is deleted.
	 */
	result DeleteContent(const ContentId& contentId);

	/**
	 * Adds a listener to receive the database change notification.
	 *
	 * @since			2.1
	 *
	 * @return			An error code
	 * @param[in]		listener				The event listener to add
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_OBJ_ALREADY_EXIST	The listener has already been added.
	 * @exception		E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks		Only a listener of an instance can be added.
	 * 					If you add more than two listeners, the listener added first will receive notification for the DB change.
	 */
	result AddContentUpdateEventListener(IContentUpdateEventListener& listener);

	/**
	 * Removes a listener.
	 *
	 * @since           2.1
	 *
	 * @return			An error code
	 * @param[in]		listener			The event listener to remove
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_OBJ_NOT_FOUND	The listener is not found.
	 * @exception		E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	result RemoveContentUpdateEventListener(IContentUpdateEventListener& listener);


	/**
	 * Requests to scan a file.
	 *
	 * @since			2.1
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/content.write
	 *
	 * @return		An error code
	 * @param[in]	contentPath			The content path
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SERVICE_BUSY		The database is busy.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	static result ScanFile(const Tizen::Base::String& contentPath);

	/**
	 * Requests to scan a directory.
	 *
	 * @since			2.1
	 * @privlevel		public
	 * @privilege		%http://tizen.org/privilege/content.write
	 *
	 * @return			An error code
	 * @param[in]		directoryPath			The directory path
	 * @param[in]		recursive				Set to @c true in order to recursively scan sub directories, @n
	 *                                          else @c false
	 * @param[in]		pListener				The scan event listener
	 * @param[out]		reqId					The request ID
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception		E_SERVICE_BUSY			The database is busy.
	 * @exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception		E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @remarks			Platform does not have the ownership of the listener.
	 */
	static result ScanDirectory(const Tizen::Base::String& directoryPath, bool recursive, IContentScanListener* pListener, RequestId& reqId);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentManager(const ContentManager& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	ContentManager& operator =(const ContentManager& rhs);

private:
	friend class _ContentManagerImpl;
	_ContentManagerImpl* __pImpl;

};  // Class ContentManager

}}  // Tizen::Content

#endif  // _FCNT_CONTENT_MANAGER_H_
