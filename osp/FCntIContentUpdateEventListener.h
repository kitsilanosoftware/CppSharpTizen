//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
 * @file		FCntIContentUpdateEventListener.h
 * @brief		This is the header file for the %IContentUpdateEventListener interface.
 *
 * This header file contains the declarations of the %IContentUpdateEventListener interface.
 */

#ifndef _FCNT_ICONTENT_UPDATE_EVENT_LISTENER_H_
#define _FCNT_ICONTENT_UPDATE_EVENT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Content
{
/**
 * @interface	IContentUpdateEventListener
 * @brief		This interface is used for receiving the database change notification.
 *
 * @since 2.1
 *
 * The %IContentUpdateEventListener interface is used for receiving the database change notification.
 */
class _OSP_EXPORT_ IContentUpdateEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.1
	 */
	virtual ~IContentUpdateEventListener(void) {}

	/**
	 * Called when the content is created.
	 *
	 * @since				2.1
	 *
	 * @param[in]			contentId			The content ID
	 * @param[in]			contentType		The content type
	 * @param[in]			r					An error code @n
	 *											The following exceptions are given through this parameter.
	 * @exception			E_SUCCESS			The method is successful.
	 * @exception			E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	virtual void OnContentFileCreated(ContentId contentId, ContentType contentType, result r) = 0;

    /**
    * Called when the content is updated.
    *
    * @since				2.1
    *
    * @param[in]			contentId			The content ID
    * @param[in]			contentType		The content type
    * @param[in]			r					An error code @n
    *											The following exceptions are given through this parameter.
    * @exception			E_SUCCESS			The method is successful.
    * @exception			E_SYSTEM			The method cannot proceed due to a severe system error.
    */
    virtual void OnContentFileUpdated(ContentId contentId, ContentType contentType, result r) = 0;

	/**
	 * Called when the content is deleted.
	 *
	 * @since				2.1
	 *
	 * @param[in]			contentId			The content ID
	 * @param[in]			contentType		The content type
	 * @param[in]			r					An error code @n
	 *											The following exceptions are given through this parameter.
	 * @exception			E_SUCCESS			The method is successful.
	 * @exception			E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	virtual void OnContentFileDeleted(ContentId contentId, ContentType contentType, result r) = 0;

	/**
	 * Called when the scan for a directory is completed.
	 *
	 * @since				2.1
	 *
	 * @param[in]			directoryPath		The directory path
	 * @param[in]			r					An error code @n
	 *											The following exceptions are given through this parameter.
	 * @exception			E_SUCCESS			The method is successful.
	 * @exception			E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	virtual void OnContentDirectoryScanCompleted(const Tizen::Base::String& directoryPath, result r) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since          2.1
	//
	virtual void IContentUpdateEventListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since          2.1
	//
	virtual void IContentUpdateEventListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since          2.1
	//
	virtual void IContentUpdateEventListener_Reserved3(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since          2.1
	//
	virtual void IContentUpdateEventListener_Reserved4(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since          2.1
	//
	virtual void IContentUpdateEventListener_Reserved5(void) {}

};  // class IContentUpdateEventListener

}} // Tizen::Content

#endif // _FCNT_ICONTENT_UPDATE_EVENT_LISTENER_H_
