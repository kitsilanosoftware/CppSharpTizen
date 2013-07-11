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
 * @file		FWebCtrlWebSetting.h
 * @brief		This is the header file for the %WebSetting class.
 *
 * This header file contains the declarations of the %WebSetting class for a %Web control.
 */
#ifndef _FWEB_CTRL_WEB_SETTING_H_
#define _FWEB_CTRL_WEB_SETTING_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FUiCtrlInputTypes.h>

namespace Tizen { namespace Web { namespace Controls
{
class _WebSettingImpl;
}}} // Tizen::Web::Control

namespace Tizen { namespace Web { namespace Controls
{

/**
 * @enum CacheMode
 *
 * Defines the types of cache mode.
 *
 * @since         2.0
 */
enum CacheMode
{
	WEB_CACHE_VALIDATED,        /**< The use of cache data only when the cache data is valid */
	WEB_CACHE_IGNORE            /**< The retrieval of data from a network resource without using cache data */
};

/**
 * @enum CertificateErrorHandlingMode
 *
 * Defines the types of certification error handling mode.
 *
 * @since         2.0
 */
enum CertificateErrorHandlingMode
{
	WEB_CERTIFICATE_ERROR_HANDLING_MODE_USER_CONFIRM,            /**< The web certificate error handling mode: The confirm popup is displayed to get the user confirmation */
	WEB_CERTIFICATE_ERROR_HANDLING_MODE_CANCEL,                 /**< The web certificate error handling mode: The confirm popup is not displayed and the request is canceled */
	WEB_CERTIFICATE_ERROR_HANDLING_MODE_CONTINUE                    /**< The web certificate error handling mode: The confirm popup is not displayed and the request proceeds */
};

/**
 * @class		WebSetting
 * @brief		This class holds the setting values for a %Web control.
 *
 * @since		2.0
 *
 * The %WebSetting class holds the setting values, which configure the behavior of a %Web control. An application can, for example, enable or disable JavaScript and image auto loading.
 */
class _OSP_EXPORT_ WebSetting
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	WebSetting(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 * This is the copy constructor for the %WebSetting class. @n
	 * It creates an instance of %WebSetting with the values of the specified instance.
	 *
	 * @since		2.0
	 *
	 * @param[in] setting An instance of %WebSetting
	 */
	WebSetting(const WebSetting& setting);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~WebSetting(void);

	/**
	* Sets a cache control strategy for a %Web control.
	*
	* @since				2.0
	*
	* @param[in]		mode		A cache mode
	*/
	void SetCacheControl(CacheMode mode);

	/**
	 * Sets the font size of the content.
	 *
	 * @since		2.0
	 *
	 * @param[in]	fontSize            The font size
	 */
	void SetFontSize(int fontSize);

	/**
	 * Sets the text encoding for the content of a %Web control.
	 *
	 * @since		2.0
	 *
	 * @param[in]	encoding		The text encoding
	 */
	void SetDefaultTextEncoding(const Tizen::Base::String& encoding);

	/**
	 * Enables or disables the use of JavaScript.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable      Set to @c true if the %Web control uses JavaScript, @n
	 *							else @c false
	 */
	void SetJavascriptEnabled(bool enable);

	/**
	 * Decides if a %Web control loads images included in the content.
	 *
	 * @since		2.0
	 *
	 * @param[in]	enable      Set to @c true if the %Web control must load images included in the content, @n
	 *							else @c false
	 */
	void SetAutoImageLoadEnabled(bool enable);

	/**
	 * Sets the input style of the keypad, which is displayed for the <input> or <textarea> tag.
	 *
	 * @since		2.0
	 *
	 * @param[in]   inputStyle	The input style of keypad
	 * @remarks		If an application sets the input style to INPUT_STYLE_OVERLAY, the application must implement IWebKeypadEventListener to rearrange the layout of the current Form.
	 *
	 */
	void SetInputStyle(Tizen::Ui::Controls::InputStyle inputStyle);

	/**
	 * Gets the value of the cache control strategy for a %Web control.
	 *
	 * @since		2.0
	 *
	 * @return		A cache mode
	 */
	CacheMode GetCacheControl(void) const;

	/**
	 * Gets the font size of the content.
	 *
	 * @since		2.0
	 *
	 * @return		The size of the font
	 */
	int GetFontSize(void) const;

	/**
	 * Gets the text encoding of the content of a %Web control.
	 *
	 * @since		2.0
	 *
	 * @return		The text encoding
	 */
	Tizen::Base::String GetDefaultTextEncoding(void) const;

	/**
	 * Checks whether a %Web control uses JavaScript. @n
	 * Returns @c true if JavaScript is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if JavaScript is enabled and used by a %Web control, @n
	 *              else @c false
	 */
	bool IsJavascriptEnabled(void) const;

	/**
	 * Checks whether a %Web control loads images included in the content automatically. @n
	 * Returns @c true if auto image loading is enabled.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if auto image loading is enabled, @n
	 *               else @c false
	 */
	bool IsAutoImageLoadEnabled(void) const;

	/**
	 * Gets the input style of the keypad, which is displayed for the <input> or <textarea> tag.
	 *
	 * @since		2.0
	 *
	 * @return		The input style of keypad @n
	 *				The default value of the input style is INPUT_STYLE_FULLSCREEN.
	 */
	Tizen::Ui::Controls::InputStyle GetInputStyle(void) const;

	/**
	* Sets a certificate error handling mode for a %Web control.
	*
	* @since		2.0
	*
	* @param[in]	mode	A certificate error handling mode
	*/
	void SetCertificateErrorHandlingMode(CertificateErrorHandlingMode mode);

	/**
	* Gets the value of the certificate error handling mode for a %Web control.
	*
	* @since		2.0
	*
	* @return		A certificate error handling mode
	*/
	CertificateErrorHandlingMode GetCertificateErrorHandlingMode(void) const;

	/**
	 * Sets a user agent for a %Web control.
	 *
	 * @since 2.0
	 *
	 * @param[in]	agent	The user agent
	 */
	void SetUserAgent(const Tizen::Base::String& agent);

	/**
	 * Gets a value of user agent for a %Web control.
	 *
	 * @since 2.0
	 *
	 * @return		The value of user agent
	 */
	Tizen::Base::String GetUserAgent(void) const;

	/**
	 * Decides if a %Web control loads the resized contents to fit width automatically.
	 *
	 * @since 2.0
	 *
	 * @param[in]	enable	Set to @c true if the %Web control should load contents to fit width, @n
	 *					else @c false
	 */
	void SetAutoFittingEnabled(bool enable);

	/**
	 * Checks whether a %Web control loads the resize contents to fit width. Returns true if auto fitting is enabled.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if auto fitting is enabled, @n
	 *			else @c false
	 */
	bool IsAutoFittingEnabled(void) const;

	/**
	 * Decides if a %Web control allows JavaScript to open new window.
	 *
	 * @since 2.0
	 *
	 * @param[in]	enable	Set to @c true if the %Web control should allow JavaScript to open new window, @n
	 *					else @c false
	 */
	void SetJavaScriptPopupEnabled(bool enable);

	/**
	 * Checks whether a %Web control allows JavaScript to open new window. Returns true if opening new window by JavaScript is enabled.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if opening new window by JavaScript is enabled, @n
	 *			else @c false
	 */
	bool IsJavaScriptPopupEnabled(void) const;

	/**
	 * Decides if a %Web control supports html5 geolocation feature.
	 *
	 * @since 2.0
	 *
	 * @param[in]	enable	Set to @c true if the %Web control should support html5 geolocation feature, @n
	 *					else @c false
	 */
	void SetGeolocationEnabled(bool enable);

	/**
	 * Checks whether a %Web control supports html5 geolocation feature. Returns true if html5 geolocation feature is enabled.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if html5 geolocation feature is enabled, @n
	 *			else @c false
	 */
	bool IsGeolocationEnabled(void) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since		2.0
	 *
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Compares two instances of the %WebSetting class.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the two instances match, @n
	 *				else @c false
	 * @param[in]	obj		The object to compare with the current instance
	 * @remarks		This method returns @c true if and only if the two instances contain the same elements.
 	 * @see			Tizen::Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed. 
	 *
	 * @since 2.0
	 *
	 * @param[in]	setting			The instance of the %WebSetting class to assign from
	 */
	WebSetting& operator =(const WebSetting& setting);

private:
	_WebSettingImpl* __pWebSettingImpl;

	friend class _WebSettingImpl;
}; // WebSetting

}}} // Tizen::Web::Control
#endif // _FWEB_CTRL_WEB_SETTING_H_
