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
 * @file		FWebCtrlITextSearchListener.h
 * @brief		This is the header file for the %ITextSearchListener interface.
 *
 * This header file contains the declarations of the %ITextSearchListener interface.
 */
#ifndef _FWEB_CTRL_ITEXT_SEARCH_LISTENER_H_
#define _FWEB_CTRL_ITEXT_SEARCH_LISTENER_H_

#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Web { namespace Controls
{

/**
 * @interface	ITextSearchListener
 * @brief		This interface is for receiving the result of the search operation made by asynchronous methods.
 *
 * @since		2.0
 *
 * The %ITextSearchListener interface receives the result of the search operation made by asynchronous methods.
 */
class _OSP_EXPORT_ ITextSearchListener
             : public virtual Tizen::Base::Runtime::IEventListener

{

public:

	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since		2.0
	 */
	virtual ~ITextSearchListener(void) {}

	/**
	 * Called when the text is found.
	 *
	 * @since		2.0
	 *
	 * @param[in]	totalCount		The total count of matches
	 * @param[in]	currentOrdinal	The ordinal of currently selected match @n
	 *								If there is no match, it will be set to zero.
	 */
	virtual void OnTextFound(int totalCount, int currentOrdinal) = 0;

protected:

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void ITextSearchListener_Reserved1(void) {};

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void ITextSearchListener_Reserved2(void) {};
};

}}} // Tizen::Web::Controls
#endif // _FWEB_CTRL_ITEXT_SEARCH_LISTENER_H_
