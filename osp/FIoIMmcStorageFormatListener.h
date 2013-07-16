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
* @file		FIoIMmcStorageFormatListener.h
* @brief	This is the header file for the %IMmcStorageFormatListener interface.
*
* This header file contains the declarations of the %IMmcStorageFormatListener interface.
*/

#ifndef _FIO_IMMC_STORAGE_FORMAT_LISTENER_H_
#define _FIO_IMMC_STORAGE_FORMAT_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Io
{

/**
* @interface     IMmcStorageFormatListener
* @brief          This interface is the listener to receive the result of external MMC format operations.
* @since         2.0
*
* The %IMmcStorageFormatListener interface must be registered and implemented by an application to receive the result of
* external MMC format operations.
*
* @see MmcStorageManager
*/
class _OSP_EXPORT_ IMmcStorageFormatListener
           : public virtual Tizen::Base::Runtime::IEventListener
{
public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface called.
	*
	* @since	2.0
	*/
	virtual ~IMmcStorageFormatListener(void) {}

	/**
	* Called when external MMC format operation is done.
	*
	* @since		2.0
	*
	* @param[in]	r				The result of external MMC format operation
	* @exception	E_SUCCESS		The format operation is successful.
	* @exception	E_IO			An unexpected device failure has occurred as the media ejected suddenly.
	* @exception	E_SYSTEM		The method cannot proceed due to a severe system error.
	*/
	virtual void OnMmcStorageFormatted(result r) = 0;

protected:
	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void IMmcStorageFormatListener_Reserved1(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void IMmcStorageFormatListener_Reserved2(void) {}

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	virtual void IMmcStorageFormatListener_Reserved3(void) {}

}; // IMmcStorageFormatListener

} } // Tizen::Io

#endif // _FIO_IMMC_STORAGE_FORMAT_LISTENER_H
