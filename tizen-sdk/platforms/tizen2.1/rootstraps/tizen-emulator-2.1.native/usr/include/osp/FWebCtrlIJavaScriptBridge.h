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
 * @file		FWebCtrlIJavaScriptBridge.h
 * @brief		This is the header file for the %IJavaScriptBridge interface.
 *
 * This header file contains the declarations of the %IJavaScriptBridge interface.
 */
#ifndef _FWEB_CTRL_IJAVA_SCRIPT_BRIDGE_H_
#define _FWEB_CTRL_IJAVA_SCRIPT_BRIDGE_H_

#include <FBaseString.h>

namespace Tizen { namespace Web { namespace Json
{
class IJsonValue;
}}} // Tizen::Web::Json

namespace Tizen { namespace Web { namespace Controls
{

/**
 * @interface	IJavaScriptBridge
 * @brief	 	This interface provides a communication channel between JavaScript and native object.
 *
 * @since		2.0
 *
 * The %IJavaScriptBridge interface provides a communication channel between JavaScript and native object.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/controls_namespace.htm">Web Controls Guide</a>.
 *
 */
class _OSP_EXPORT_ IJavaScriptBridge
{
public:
	/**
	* This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since			2.0
	*/
	virtual ~IJavaScriptBridge(void) {}

	/**
	 * Called asynchronously on invocation request from JavaScript side through the requestToNative() method.
	 *
	 * @since			2.0
	 *
	 * @param[in] pArg	The parameters delivered by JavaScript
	 */
	virtual void HandleJavaScriptRequestN(Tizen::Web::Json::IJsonValue* pArg) = 0;

	/**
	 * Gets the name of %IJavaScriptBridge to identify each %IJavaScriptBridge.
	 *
	 * @since		2.0
	 *
	 * @return	The name of %IJavaScriptBridge
	 */
	virtual Tizen::Base::String GetName(void) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IJavaScriptBridge_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IJavaScriptBridge_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IJavaScriptBridge_Reserved3(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IJavaScriptBridge_Reserved4(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// Gets the Impl instance.
	//
	// @since		2.0
	//
	virtual void IJavaScriptBridge_Reserved5(void) {}

}; // IJavaScriptBridge

}}} // Tizen::Web::Controls
#endif // _FWEB_CTRL_IJAVA_SCRIPT_BRIDGE_H_
