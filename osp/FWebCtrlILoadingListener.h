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
 * @file		FWebCtrlILoadingListener.h
 * @brief		This is the header file for the %ILoadingListener interface.
 *
 * This header file contains the declarations of the %ILoadingListener interface.
 */
#ifndef _FWEB_CTRL_ILOADING_LISTENER_H_
#define _FWEB_CTRL_ILOADING_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FBaseString.h>

namespace Tizen { namespace Net { namespace Http
{
class HttpHeader;
}}} // Tizen::Neb::Http

namespace Tizen { namespace Web { namespace Controls
{
class AuthenticationChallenge;
}}} // Tizen::Web::Controls

namespace Tizen { namespace Web { namespace Controls
{

/**
 * @enum WebNavigationType
 *
 * Defines the type of %Web navigation.
 *
 * @since	2.0
 */
enum WebNavigationType
{
	WEB_NAVIGATION_LINK_CLICKED,            /**< The clicking of a link on the page */
	WEB_NAVIGATION_FORM_SUBMITTED,          /**< The submission of a form */
	WEB_NAVIGATION_BACKFORWARD,             /**< The back and forward navigation*/
	WEB_NAVIGATION_RELOAD,                  /**< The reloading of the page */
	WEB_NAVIGATION_FORM_RESUBMITTED,        /**< The resubmission of the form  */
	WEB_NAVIGATION_OTHER                    /**< A navigation other than any of the above */
};

/**
 * @enum LoadingErrorType
 *
 * Defines the types of loading errors.
 *
 * @since	2.0
 */
enum LoadingErrorType
{
	WEB_ERROR_UNKNOWN,                          /**< An unknown error*/
	WEB_REQUEST_TIMEOUT,                    /**< The request timeout */
	WEB_NO_CONNECTION,                          /**< The network is not in service */
	WEB_MIME_NOT_SUPPORTED,                     /**< The content type is not supported */
	WEB_BAD_URL,                                /**< The URL is invalid */
	WEB_HTTP_RESPONSE,                      /**< The hypertext transfer protocol (HTTP) response */
	WEB_OUT_OF_MEMORY,                      /**< The memory is not enough to load the page */
	WEB_FILE_ACCESS_FAILED,                 /**< The file access failed  */
	WEB_REQUEST_MAX_EXCEEDED,               /**< The request has failed because the total number of requests have exceeded the maximum limit */
	WEB_INVALID_CERTIFICATE                 /**< The hypertext transfer protocol secure (HTTPS) request has failed due to an invalid certificate or CA */
};

/**
 * @enum DecisionPolicy
 *
 * Defines the decision policy.
 *
 * @since	2.0
 */
enum DecisionPolicy
{
	WEB_DECISION_DOWNLOAD,                          /**< The download policy*/
	WEB_DECISION_CONTINUE,                          /**< The usage policy*/
	WEB_DECISION_IGNORE,                                /**< The ignore policy*/
};

/**
 * @interface	ILoadingListener
 * @brief		This interface is for receiving the events that occur during the loading of data.
 *
 * @since	2.0
 *
 * The %ILoadingListener interface receives the events that occur during the loading of data.
 * To listen to the events occurred during a data loading operation, implement this listener. If there is no
 * registered load event listener, the browser engine handles these events according to its own settings.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/controls_namespace.htm">Web Controls Guide</a>.
 */
class _OSP_EXPORT_ ILoadingListener
	: public virtual Tizen::Base::Runtime::IEventListener
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since	2.0
	 */
	virtual ~ILoadingListener(void) {}

	/**
	 * Called when an authentication is requested.
	 *
	 * @since			2.0
	 *
	 * @return		@c true if the ownership is taken by the application, @n
	 *				else @c false, and a default dialog for the ID and password is displayed @n
	 *				If this method returns @c true, the application must delete the AuthenticationChallenge instance.
	 * @param[in]	host			The host requiring the authentication
	 * @param[in]	realm			The description to help save the user credentials for future visits
	 * @param[in]		authentication	The handler to send a user response to the server that requested the authentication
	 */
	virtual bool OnHttpAuthenticationRequestedN(const Tizen::Base::String& host, const Tizen::Base::String& realm, const Tizen::Web::Controls::AuthenticationChallenge& authentication) = 0;

	/**
	 * Called when the authentication request is cancelled.
	 *
	 * @since	2.0
	 */
	virtual void OnHttpAuthenticationCanceled(void) = 0;

	/**
	 * Called when the loading operation starts.
	 *
	 * @since	2.0
	 */
	virtual void OnLoadingStarted(void) = 0;

	/**
	 * Called when the loading operation is cancelled.
	 *
	 * @since	2.0
	 */
	virtual void OnLoadingCanceled(void) = 0;

	/**
	* Called when the loading operation fails.
	*
	* @since                  2.0
	*
	* @param[in]          error                                            The error that occurred during loading
	* @param[in]          reason                                        The reason for the loading failure, @n
	*                               - WEB_HTTP_RESPONSE: The HTTP state code such as "404" @n
	*                               - WEB_MIME_NOT_SUPPORTED: The Multipurpose Internet Mail Extensions (MIME) type such as "application/rdf+xml" is not supported @n
	*                               - WEB_BAD_URL: The URL is incorrect
	*/
	virtual void OnLoadingErrorOccurred(LoadingErrorType error, const Tizen::Base::String& reason) = 0;

	/**
	 * Called when the loading operation is completed.
	 *
	 * @since	2.0
	 */
	virtual void OnLoadingCompleted(void) = 0;

	/**
	 * Called when the loading progress for the current page is requested. @n
	 * The progress rate is displayed as a percentage.
	 *
	 * @since				2.0
	 *
	 * @param[in]		progress			The progress rate ranging from [0~100]
	 */
	virtual void OnEstimatedProgress(int progress) = 0;

	/**
	 * Called when the title of the new page has been received.
	 *
	 * @since	2.0
	 */
	virtual void OnPageTitleReceived(const Tizen::Base::String& title) = 0;

	/**
	 * Called to notify an application of the URL to be requested. @n
	 * If an application wants to handle the URL, it must return @c true. If an application returns @c false, the request of the URL continues with the
	 * browser engine.
	 *
	 * @since					2.0
	 *
	 * @return			@c true if the application handles the URL after the request is canceled in the browser engine, @n
	 *                  else @c false if the browser engine proceeds with the requested URL
	 * @param[in]		url			The URL that is requested
	 * @param[in]		type		The type indicating how the URL is triggered
	 */
	virtual bool OnLoadingRequested(const Tizen::Base::String& url, WebNavigationType type) = 0;

	/**
	 * Called to notify an application of the content type of the data to be downloaded. @n
	 * - To handle data by itself, the application must return WEB_DECISION_DOWNLOAD. The data is routed to IWebDownloadListener to be downloaded incrementally. @n
	 * - If an application returns WEB_DECISION_CONTINUE, the browser engine continues the downloading and tries to parse the data. @n
	 * - If an application returns WEB_DECISION_IGNORE, the browser engine cancels the downloading of the data.
	 *
	 * @since				2.0
	 *
	 * @return			DecisionPolicy			A value of the enumerator DecisionPolicy
	 * @param[in]		mime				The content type of the data that is downloaded
	 * @param[in]		httpHeader			The HTTP header string
	 */
	virtual DecisionPolicy OnWebDataReceived(const Tizen::Base::String& mime, const Tizen::Net::Http::HttpHeader& httpHeader) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since 2.0
	//
	virtual void ILoadingListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since 2.0
	//
	virtual void ILoadingListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since 2.0
	//
	virtual void ILoadingListener_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since 2.0
	//
	virtual void ILoadingListener_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since 2.0
	//
	virtual void ILoadingListener_Reserved5(void) {}

}; // ILoadingListener

}}} // Tizen::Web::Controls
#endif // _FWEB_CTRL_ILOADING_LISTENER_H_
