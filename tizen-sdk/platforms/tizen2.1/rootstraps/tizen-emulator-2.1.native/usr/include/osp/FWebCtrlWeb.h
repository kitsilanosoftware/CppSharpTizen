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
 * @file		FWebCtrlWeb.h
 * @brief	This is the header file for the %Web class.
 *
 * This header file contains the declarations of the %Web class.
 */
#ifndef _FWEB_CTRL_WEB_H_
#define _FWEB_CTRL_WEB_H_

#include <FBaseBuffer.h>
#include <FBaseResult.h>
#include <FBaseString.h>
#include <FUiContainer.h>

namespace Tizen { namespace Graphics
{
class Dimension;
class Point;
class Rectangle;
}} // Tizen::Graphics

namespace Tizen { namespace Net { namespace Http
{
class HttpHeader;
}}} // Tizen::Net::Http

namespace Tizen { namespace Web { namespace Controls
{
class IJavaScriptBridge;
class ILoadingListener;
class ITextSearchListener;
class IWebDownloadListener;
class IWebKeypadEventListener;
class IWebUiEventListener;
class IWebUiEventListenerF;
class IWebUiListener;
class HitElementResult;
class PageNavigationList;
class WebSetting;
class _WebImpl;
}}} // Tizen::Web::Controls

namespace Tizen { namespace Web { namespace Controls
{

/**
 * @class		Web
 * @brief		This class provides methods for embedding a browser in an application.
 *
 * @since		2.0
 *
 * The %Web class provides methods for embedding a browser in an application to load and render various types of %Web content. Similar to adding UI controls, the %Web content can be added to the application by adding a %Web control.
 * @n
 * For more information on the class features and %Web browser feature limitations, see <a href="../org.tizen.native.appprogramming/html/guide/web/controls_namespace.htm">Web Controls Guide</a> and <a href="../org.tizen.native.appprogramming/html/guide/web/supported_web_features.htm">Supported Features in the Web Control</a>.
 *
 * The following example demonstrates how to use the %Web class.
 *	@code
// Sample code for WebSample.h
#include <FUi.h>
#include <FWeb.h>

class WebSample :
    public Tizen::Ui::Controls::Form
{
public:
    WebSample(void) {};
    virtual ~WebSample(void) {};

protected:
    void LoadUrl(void);

private:
    Tizen::Web::Controls::Web *__pWeb;

public:
    virtual result OnInitializing(void);
};

// Sample code for WebSample.cpp
#include "WebSample.h"

using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Web::Controls;

result
WebSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    __pWeb = new Web();
    __pWeb->Construct(GetClientAreaBounds());
    AddControl(__pWeb);
    LoadUrl();

    return r;
}

// Calls LoadUrl() with the URL of the Web content to display it on the Web control
void
WebSample::LoadUrl(void)
{
    Tizen::Base::String url(L"http://www.tizen.org");

    __pWeb->LoadUrl(url);
}
 *	@endcode
 *
 */
class _OSP_EXPORT_ Web
	: public Tizen::Ui::Container
{
public:
	/**
	 * The object is not fully constructed after this constructor is called.  @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	Web(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~Web(void);

	/**
	 * Initializes this instance of the %Web control with the specified parameters.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		An error code
	 * @param[in]	rect			The rectangle size of the control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method has failed.
	 * @exception	E_INVALID_ARG		The specified @c rect is invalid.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect);

	/**
	 * Initializes this instance of the %Web control with the specified parameters.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		An error code
	 * @param[in]	rect			The rectangle size of the control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method has failed.
	 * @exception	E_INVALID_ARG		The specified @c rect is invalid.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 */
	result Construct(const Tizen::Graphics::FloatRectangle& rect);

	/**
	 * Loads the resource specified by the URL.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @param[in]	url				The resource to load
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	void LoadUrl(const Tizen::Base::String& url);

	/**
	 * Loads the resource specified by the URL with a given header of HTTP request.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		An error code
	 * @param[in]	url				The resource to load
	 * @param[in]	header			The header of the HTTP request
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_HEADER	The header object does not contain any header fields.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 */
	result LoadUrl(const Tizen::Base::String& url, const Tizen::Net::Http::HttpHeader& header);

	/**
	 * Loads the resource specified by the URL with a given header and body of HTTP request. @n
	 * The header must include content-type entity-header field that is needed to check mime-type of the message body.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		An error code
	 * @param[in]	url				The resource to load
	 * @param[in]	header			The header of the HTTP request
	 * @param[in]	body			The message body of the HTTP request
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_HEADER	The header object does not contain any header fields.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 */
	result LoadUrlWithPostRequest(const Tizen::Base::String& url, const Tizen::Net::Http::HttpHeader& header, const Tizen::Base::ByteBuffer& body);

	/**
	 * Loads the content of the specified buffer.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @param[in]	baseUrl			The uniform resource locator (URL) of the content
	 * @param[in]	content			The content
	 * @param[in]	mime			The MIME type of the content
	 * @param[in]	encoding		The <a href= "../org.tizen.native.appprogramming/html/guide/web/supported_web_features.htm">text encoding</a> of the content
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The content buffer is empty. @b Since: @b 2.1
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	void LoadData(const Tizen::Base::String& baseUrl, const Tizen::Base::ByteBuffer& content, const Tizen::Base::String& mime, const Tizen::Base::String& encoding = "UTF-8");

	/**
	 * Stops the current loading operation.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	void StopLoading(void);

	/**
	 * Reloads the current page.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	void Reload(void);

	/**
	 * Checks whether the page is loading.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if a page is loading, @n
	 *					else @c false
	 */
	bool IsLoading(void) const;

	/**
	 * Checks whether the current %Web control has a back history item.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if a back history item exists, @n
	 *					else @c false
	 */
	bool CanGoBack(void) const;

	/**
	 * Checks whether the current %Web control has a forward history item.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if a forward history item exists, @n
	 *					else @c false
	 */
	bool CanGoForward(void) const;

	/**
	 * Goes to the back history of the current %Web control.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	void GoBack(void);

	/**
	 * Goes to the forward history of the current %Web control.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	void GoForward(void);

	/**
	 * Gets the backward and forward navigation list of the %Web control.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to PageNavigationList containing the history items of the %Web control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Web::Controls::PageNavigationList* GetBackForwardListN(void) const;

	/**
	 * Searches for a word on the current page. @n
	 * When called again, it searches for the next instance of the word on the page. Set @c searchForward to @c false to search for the word in the backward
	 * direction.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the specified @c word is found, @n
	 *					else @c false
	 * @param[in]	word			The string to search for
	 * @param[in]	searchForward	Set to @c true to search for the word in the forward direction from the current position, @n
	 *									else @c false to search for the word in the backward direction from the current position
	 */
	bool SearchText(const Tizen::Base::String& word, bool searchForward = true);

	/**
	 * Sets the new values for the default setting. @n
	 * It fails to change the setting during data load.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		An error code
	 * @param[in]	setting			The setting to update
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 */
	result SetSetting(const Tizen::Web::Controls::WebSetting& setting);

	/**
	 * Gets the setting of the %Web control.
	 *
	 * @since		2.0
	 *
	 * @return		An instance of WebSetting
	 */
	Tizen::Web::Controls::WebSetting GetSetting(void) const;


	/**
	 * Gets the information of the element pointed by the specified coordinates.
	 *
	 * @since		2.0
	 *
	 * @return		A HitElementResult of the pointed element
	 * @param[in]	point			The x and y coordinates
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c point is invalid.
	 * @exception	E_UNSUPPORTED_FORMAT	The image format is not supported.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Web::Controls::HitElementResult* GetElementByPointN(const Tizen::Graphics::Point& point) const;

	/**
	 * Gets the information of the element pointed by the specified coordinates.
	 *
	 * @since		2.1
	 *
	 * @return		A HitElementResult of the pointed element
	 * @param[in]	point			The x and y coordinates
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c point is invalid.
	 * @exception	E_UNSUPPORTED_FORMAT	The image format is not supported.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Web::Controls::HitElementResult* GetElementByPointN(const Tizen::Graphics::FloatPoint& point) const;

	/**
	 * Evaluates the JavaScript string and returns the result.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		The result of the evaluated JavaScript, @n
	 *					else null if an error occurs
	 * @param[in]	scriptCode		The JavaScript code as string
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String* EvaluateJavascriptN(const Tizen::Base::String& scriptCode);

	/**
	 * Sets the zoom-out level as a ratio.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	level			The zoom-out level @n
	 *								The value ranges between @c 0.3 and @c 2.0. When the page view is at its original size, the level is @c 1.0. @n If the
	 *								specified level is less than @c 1.0, the page view is reduced. @n If the specified level is greater than @c 1.0, the page view is
	 *								magnified.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c level is less than @c 0.3 or greater than @c 2.0.
	 */
	result SetZoomLevel(float level);

	/**
	 * Gets the zoom level of a page as a percentage.
	 *
	 * @since		2.0
	 *
	 * @return		The value ranges between @c 0.3 and @c 2.0
	 */
	float GetZoomLevel(void) const;

	/**
	 * Gets the title of the current page.
	 *
	 * @since		2.0
	 *
	 * @return		The title of the current page
	 */
	Tizen::Base::String GetTitle(void) const;

	/**
	 * Gets the URL of the current page.
	 *
	 * @since		2.0
	 *
	 * @return		The URL of the current page
	 */
	Tizen::Base::String GetUrl(void) const;

	/**
	 * Checks whether the specified multipurpose internet mail extensions (MIME) type is supported by %Tizen.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the specified MIME type is supported, @n
	 *					else @c false
	 * @param[in]	mime			The MIME type
	 */
	bool IsMimeSupported(const Tizen::Base::String& mime) const;

	/**
	 * Sets a load event listener.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @param[in]	pLoadingListener	The listener receives the events that occurs while loading the data
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	void SetLoadingListener(Tizen::Web::Controls::ILoadingListener* pLoadingListener);

	/**
	 * Sets a download event listener.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @param[in]	pDownLoadListener	The listener to receive the data from a network incrementally
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	void SetDownloadListener(Tizen::Web::Controls::IWebDownloadListener* pDownLoadListener);

	/**
	 * Sets the starting point for the text selection block. @n
	 * It sets the selection block around the nearest word bound.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	startPoint		The starting point for the text selection block
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		There is nothing to select from the specified starting point.
	 */
	result SetBlockSelectionPosition(const Tizen::Graphics::Point& startPoint);

	/**
	 * Sets the starting point for the text selection block. @n
	 * It sets the selection block around the nearest word bound.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	startPoint		The starting point for the text selection block
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		There is nothing to select from the specified starting point.
	 */
	result SetBlockSelectionPosition(const Tizen::Graphics::FloatPoint& startPoint);

	/**
	 * Releases the currently selected block.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 *
	 */
	result ReleaseBlock(void);

	/**
	 * Gets the starting point and the ending point of the selected text block. @n
	 * When the %GetBlockRange() method is called without the selection block, the @c startPoint and @c endPoint have (0,0) values for the x and y coordinates.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	startPoint		The starting point of the selected text block
	 * @param[out]	endPoint		The ending point of the selected text block
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result GetBlockRange(Tizen::Graphics::Point& startPoint, Tizen::Graphics::Point& endPoint) const;

	/**
	 * Gets the starting point and the ending point of the selected text block. @n
	 * When this method is called without the selection block, the startPoint and endPoint have (0.0,0.0) values for the x and y coordinates.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[out]	startPoint		The starting point of the selected text block
	 * @param[out]	endPoint		The ending point of the selected text block
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result GetBlockRange(Tizen::Graphics::FloatPoint& startPoint, Tizen::Graphics::FloatPoint& endPoint) const;


	/**
	 * Gets the text of the selected text block.
	 *
	 * @since		2.0
	 *
	 * @return		The selected text, @n
	 *					else an empty string if there is no selection block
	 */
	Tizen::Base::String GetTextFromBlock(void) const;

	/**
	 * Enables or disables the vertical and horizontal scrolls.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable			Set to @c true to enable the scrolling of the web page, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks		This method does not affect javascript touch event.
	 */
	result SetScrollEnabled(bool enable);


	/**
	 * Checks whether the web page scroll is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the web page scroll is enabled, @n
	 *					else @c false
	 */
	bool IsScrollEnabled(void) const;

	/**
	 * Registers a user interface (UI) event listener.
	 *
	 * @since		2.0
	 *
	 * @param[in]	pUiEventListener	The listener to receive the user interface (UI) related events
	 */
	void SetWebUiEventListener(Tizen::Web::Controls::IWebUiEventListener* pUiEventListener);

	/**
	 * Registers a user interface (UI) event listener.
	 *
	 * @since		2.1
	 *
	 * @param[in]	pUiEventListener	The listener to receive the user interface (UI) related events
	 */
	void SetWebUiEventListenerF(Tizen::Web::Controls::IWebUiEventListenerF* pUiEventListener);

	/**
	 * Checks whether the %Web control uses private browsing.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if private browsing is enabled, @n
	 *               	else @c false
	 */
	bool IsPrivateBrowsingEnabled(void) const;

	/**
	 * Sets the private browsing and returns the result.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		The result of setting the private browsing
	 * @param[in]	enable			Set to @c true to enable private browsing, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 */
	result SetPrivateBrowsingEnabled(bool enable);

	/**
	 * Clears the back and forward navigation list.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 * @see	CanGoBack()
	 * @see	CanGoForward()
	 * @see	GoBack()
	 * @see	GoForward()
	 */
	result ClearHistory(void);

	/**
	 * Clears the application's cache.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 */
	result ClearCache(void);

	/**
	 * Clears the application's cookie.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 */
	result ClearCookie(void);

	/**
	 * Clears the application's all stored form datas.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	 */
	result ClearFormData(void);

	/**
	 * Clears the application's all stored ID/password datas.
	 *
	 * @since		2.1
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method.
	*/
	result ClearLoginFormData(void);

	/**
	 * Checks whether the %Web control allows cookie. @n
	 * Returns @c true if cookie is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if cookie is allowed, @n
	 *					else @c false
	 */
	bool IsCookieEnabled(void) const;

	/**
	 * Enables or disables a cookie.
	 *
	 * @since		2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/web.service
	 *
	 * @return		The result of enabling or disabling cookie
	 * @param[in]	enable			Set to @c true if the web control allows a cookie, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 */
	result SetCookieEnabled(bool enable);

	/**
	 * Saves the current web page as a pdf file. @n The size parameter is used to set size of the pdf file using millimeter.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	filePath		The path of the pdf file that is created
	 * @param[in]	pSize			The width and height of the pdf file in millimeter. The width and height must be greater than @c 0. @n
	 *								If the parameter contains @c null, the method uses the default size of the web page that is shown on the screen.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	 *										- The specified path is invalid.
	 *										- The specified size is invalid.
	 * @exception	E_INACCESSIBLE_PATH	The file path is not allowed for the application to write.
	 */
	result SavePageAsPdf(const Tizen::Base::String& filePath, const Tizen::Graphics::Dimension* pSize = null);

	/**
	 * Adds a JavaScript bridge instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	jsBridge		The JavaScript bridge to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_ALREADY_EXIST	A JavaScript bridge with the same name already exists.
	 */
	result AddJavaScriptBridge(const IJavaScriptBridge& jsBridge);

	/**
	 * Removes a JavaScript bridge instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	jsBridge		The JavaScript bridge to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified element is not found.
	 */
	result RemoveJavaScriptBridge(const IJavaScriptBridge& jsBridge);

	/**
	 * Registers a keypad event listener. @n
	 * The registered listener is notified when the keypad associated with <input> tag or with <textarea> tag is opened or closed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	pKeypadEventListener	The event listener to set
	 * @remarks		The interfaces of IWebKeypadEventListener are called only when the input style of the keypad is @c INPUT_STYLE_OVERLAY.
	 * @see	WebSetting::SetInputStyle()
	 */
	void SetWebKeypadEventListener(IWebKeypadEventListener* pKeypadEventListener);

	/**
	 * Searches for all instances of the text on the current page and then highlights them. @n
	 * The current matched block will indicate the first match.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	text			The string to search for
	 * @param[in]	caseSensitive	Set to @c true to search for the text with case-sensitive mode, @n
	 *								else @c false to search for the text in the backward direction from the current position
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c text is invalid.
	 * @remarks		This method operates asynchronously.
	 * @see	Tizen::Web::Controls::ITextSearchListener::OnTextFound()
	 */
	result SearchTextAllAsync(const Tizen::Base::String& text, bool caseSensitive);

	/**
	 * Scrolls the current matched block to the next text matched by SearchTextAllAsync().
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	searchForward	Set to @c true to search for the text in the forward direction from the current position, @n
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The next instance is not found.
	 * @exception	E_INVALID_OPERATION		The SearchTextAllAsync() method is not called.
	 * @remarks		This method operates asynchronously.
	 * @see	Tizen::Web::Controls::ITextSearchListener::OnTextFound()
	 */
	result SearchNextAsync(bool searchForward = true);

	/**
	 * Sets a text search listener.
	 *
	 * @since		2.0
	 *
	 * @param[in]	pTextSearchListener		The result of the search operation made by asynchronous methods
	 */
	void SetTextSearchListener(ITextSearchListener* pTextSearchListener);

	/**
	 * Gets the favicon image from current page.
	 *	 
	 * @since		2.0
	 *
	 * @return		The image
	 * @see	Tizen::Web::Controls::ILoadingListener::OnFaviconReceived()
	 */
	Tizen::Graphics::Bitmap* GetFaviconN(void) const;

	/**
	 * Informs the browser engine to stop the screen operations such as updating a screen until %Web calls the Resume() method. @n
	 * It is useful when a %Web control is not visible and does not need to update its screen.
	 *
 	 * @since		2.0
	 */
	void	Pause(void);

	/**
	 * Informs the browser engine to resume the handling of screen operations. 
	 *
 	 * @since		2.0
	 */
	void	Resume(void);

	/**
	 * Scrolls the web page with the given coordinates.
	 *
	 * @since		2.1
	 *
	 * @param[in]	diff			The x and y coordinates
	 */
	void ScrollBy(const Tizen::Graphics::Point& diff);

	/**
	 * Sets the scrolled position of the web page.
	 *
	 * @since		2.1
	 *
	 * @param[in]	dest			The x and y coordinates
	 */
	void ScrollTo(const Tizen::Graphics::Point& dest);

	/**
	 * Gets the current scroll position of the web page.
	 *
	 * @since		2.1
	 *
	 * @return		The x and y coordinates
	 */
	Tizen::Graphics::Point GetScrollPosition(void) const;

	/**
	 * Gets the size of the current web page.
	 *
	 * @since		2.1
	 *
	 * @return	The size of the current web page
	 * @remarks		If an application want to get the displayed size, the return value should be multiplied by the zoom factor.
	 * @see	GetZoomLevel()
	 */
	Tizen::Graphics::Dimension GetPageSize(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	item			The instance of the %Web class to copy from
	// @remarks		This constructor is hidden.
	//
	Web(const Web& item);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	item			The instance of the %Web class to assign from
	// @remarks		This operator is hidden.
	//
	Web& operator =(const Web& item);
}; // Web

}}} // Tizen::Web::Controls
#endif // _FWEB_CTRL_WEB_H_
