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
 * @file		FWebCtrlIWebDownloadListener.h
 * @brief		This is the header file for the %IWebDownloadListener interface.
 *
 * This header file contains the declarations of the %IWebDownloadListener interface.
 */
#ifndef _FWEB_CTRL_IWEB_DOWNLOAD_LISTENER_H_
#define _FWEB_CTRL_IWEB_DOWNLOAD_LISTENER_H_

#include <FBaseByteBuffer.h>
#include <FBaseRtIEventListener.h>
#include <FWebCtrlILoadingListener.h>

namespace Tizen { namespace Web { namespace Controls
{

/**
 * @interface	IWebDownloadListener
 * @brief		This interface downloads data from the internet.
 *
 * @since	2.0
 *
 * The %IWebDownloadListener interface downloads data from the internet.
 * An application receives content from a network incrementally
 * when it decides to download the content after checking the Multipurpose Internet Mail Extensions (MIME).
 * This is useful when the content is not supported by the framework itself and the application wants to handle it.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/controls_namespace.htm">Web Controls Guide</a>.
 *
 * The following examples demonstrate how to use the %IWebDownloadListener interface.
 *	@code
 *	#include <FWeb.h>
 *	#include <FUiControls.h>
 *
 *	using namespace Tizen::Web;
 *	using namespace Tizen::Ui::Controls;
 *
 *	// Adds a Web control to the parent container
 *	result
 *	WebSample::CreateControl(Form* pParentForm)
 *	{
 *		result r = E_SUCCESS;
 *
 *		pWeb = new Web();
 *		r = pWeb->Construct( pParentForm->GetClientAreaBounds());
 *		r = pParentForm->AddControl(*pWeb);
 *
 *		// Sets a loading listener and a Web downloading listener
 *		pWeb->SetDownloadListener(pMyDownloadListener);
 *		pWeb->SetLoadingListener(pMyLoadingListener);
 *
 *		return r;
 *	}
 *	@endcode
 *
 *	As soon as the first chunk of data is received, OnWebDataReceived() is fired with the MIME type.
 *	If you want to download the data, return WEB_DECISION_DOWNLOAD.
 *
 *	@code
 *	DecisionPolicy
 *	MyLoadingListener::OnWebDataReceived(const Tizen::Base::String& mime, const Tizen::Net::Http::HttpHeader& header)
 *	{
 *		return WEB_DECISION_DOWNLOAD;
 *	}
 *	@endcode
 *
 * Then, the data is routed to OnWebChunkedDataReceived().
 *
 *	@code
 *	void
 *	MyDownloadListener::OnWebChunkedDataReceived(Tizen::Base::ByteBuffer& chunk)
 *	{
 *		// ....
 *	}
 *	@endcode
 */
class _OSP_EXPORT_ IWebDownloadListener
	: public virtual Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~IWebDownloadListener(void) {}

	/**
	* Called when the HyperText Transfer Protocol (HTTP) protocol receives the next chunked data.
	 *
	 * @since				2.0
	 *
	 * @param[in]		chunk		The chunked data
	 * @remarks     The received data size is less than the capacity of the specified Tizen::Base::ByteBuffer by @c 1.
	 */
	virtual void OnWebChunkedDataReceived(const Tizen::Base::ByteBuffer& chunk) = 0;

	/**
	  * Called when the downloading of the content is completed.
	  *
	  * @since	2.0
	  */
	virtual void OnWebDataDownloadCompleted(void) = 0;

	/**
	* Called when an error has occurred while downloading content.
	*
	* @since                  2.0
	*
	* @param[in]          error                           The type of error that occurred while downloading data
	*/
	virtual void OnWebDownloadFailed(LoadingErrorType error) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since 2.0
	//
	virtual void IWebDownloadListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since 2.0
	//
	virtual void IWebDownloadListener_Reserved2(void) {}

}; // IWebDownloadListener

}}} // Tizen::Web::Controls
#endif // _FWEB_CTRL_IWEB_DOWNLOAD_LISTENER_H_
