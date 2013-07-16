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
 * @file			FAppAppResource.h
 * @brief			This is the header file for the %AppResource class.
 *
 * This header file contains the declarations of the %AppResource class.
 */

#ifndef _FAPP_APP_RESOURCE_H_
#define _FAPP_APP_RESOURCE_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FAppTypes.h>
#include <FGrpBitmapCommon.h>

namespace Tizen { namespace Graphics { class Bitmap; } }

namespace Tizen { namespace App
{

/**
* @class		AppResource
* @brief		This class provides convenient methods to load application resources at run time.
*
* @since	2.0
*
* @final	This class is not intended for extension.
*
* The %AppResource class provides convenient methods to load application resources at run time: @n
* - Use AppResource::GetString() to get handle and display localized strings.
* - Use AppResource::GetBitmapN() to obtain a bitmap image that matches the screen density.
* - If the matching image does not exist, the image of the baseline density folder, ScreenDensity-High is used.
*
* The instance of this class can be obtained through App::GetAppResource().
* The following example demonstrates how to use the %AppResource class to get strings.
*
* @code
#include <FApp.h>

using namespace Tizen::App;

void
MyClass::StringResourceSample(void)
{
	String hello;
	AppResource *pAppResource = App::GetInstance()->GetAppResource();
	if (pAppResource)
	{
		pAppResource->GetString(L"IDS_HELLO", hello);
	}
}
* @endcode
*
*
*
* The following example demonstrates how to use the %AppResource class to retrieve bitmaps.
* @code
#include <FApp.h>

using namespace Tizen::App;
using namespace Tizen::Graphics;

void
MyClass::BitmapResourceSample(void)
{
	AppResource *pAppResource = App::GetInstance()->GetAppResource();
	Bitmap* pBitmap = null;

	if (pAppResource)
	{
		pBitmap = pAppResource->GetBitmapN(L"Tizen.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	}
}
* @endcode
*/

class _OSP_EXPORT_ AppResource
	: public Tizen::Base::Object
{
public:
	/**
	* Gets the string at the specified resource ID.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	resourceId		The resource ID of type Tizen::Base::String that describes the resource
	* @param[out]	loadedString	The string obtained from the loaded application resource
	* @exception	E_SUCCESS				  The method is successful.
	* @exception	E_FAILURE			The argument passed is not found.
	* @exception	E_INVALID_ARG			The argument passed to a method contains an invalid resource ID.
	*/
	result GetString(const Tizen::Base::String& resourceId, Tizen::Base::String& loadedString) const;

	/**
	* Gets the bitmap at the specified path. @n
	* The %GetBitmapN() method interprets the given resource path and reads the best matching image file for the current device resolution. @n
	* To load the bitmap image from a file, give the name of the file as the input parameter and not the file path (For example: "img.png").
	* Then, the system will first look for the image file in the folder specific to the current device resolution, such as
	* '720x1280' and if the file does not exist, it will then search the folder that corresponds to the current screen density,
	* such as 'screen-density-xhigh'. After searching the density folder, all the other density folders are searched in the order high to low.
	* If the requested image file is found in a density-specific folder that is different from the current screen density, the bitmap returned from this method is pre-scaled.
	* But in case of requested image file is saved as ".#.png" (For example : "img.#.png"), then a bitmap instance which is value of returned pointer is not pre-scaled.
	* So, it is recommended to use ".#.png" as extension (For example : "ninePatchImg.#.png") for nine-patch image file.
	* Currently supported image formats are: JPEG, GIF, PNG, BMP, TIFF, and WBMP.
	* For more information on the features, see <a href="../org.tizen.native.appprogramming/html/multiple_screen/autoscale_resource_fallback.htm">Resource Fallback and Prescaling.</a>
	*
	* @since	2.0
	*
	* @return	A pointer to the Bitmap instance generated from the specified file
	* @param[in]	imagePath				The relative path starting from the directory @b "res/screen-density-XXX/" or @b "res/AxB", @n
	*									where A and B represent the screen width and height of the supported device models, respectively.
	* @param[in]	pixelFormat				The pixel format of the resulting bitmap
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid.
	* @exception	E_UNSUPPORTED_FORMAT	The image file format or specified pixel format is not supported.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found.
	* @exception	E_SYSTEM				A system error has occurred.
	* @remarks	The specific error code can be accessed using the GetLastResult() method.
	* @remarks	There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	*/
	Tizen::Graphics::Bitmap* GetBitmapN(const Tizen::Base::String& imagePath, Tizen::Graphics::BitmapPixelFormat pixelFormat) const;

	/**
	* Gets the bitmap at the specified path. @n
	* The %GetBitmapN() method interprets the given resource path and reads the best matching image file for the current device resolution. @n
	* To load the bitmap image from a file, give the name of the file as the input parameter and not the file path (For example: "img.png").
	* Then, the system will first look for the image file in the folder specific to the current device resolution, such as
	* '720x1280' and if the file does not exist, it will then search the folder that corresponds to the current screen density,
	* such as 'screen-density-xhigh'. After searching the density folder, all the other density folders are searched in the order high to low.
	* If the requested image file is found in a density-specific folder that is different from the current screen density, the bitmap returned from this method is pre-scaled.
	* But in case of requested image file is saved as ".#.png" (For example : "img.#.png"), then a bitmap instance which is value of returned pointer is not pre-scaled.
	* So, it is recommended to use ".#.png" as extension (For example : "ninePatchImg.#.png") for nine-patch image file.
	* Currently supported image formats are: JPEG, GIF, PNG, BMP, TIFF, and WBMP.
	* For more information on the features, see <a href="../org.tizen.native.appprogramming/html/multiple_screen/autoscale_resource_fallback.htm">Resource Fallback and Prescaling.</a>
	*
	* @since	2.0
	*
	* @return	A pointer to the Tizen::Graphics::Bitmap instance generated from the specified file
	* @param[in]	imagePath				The relative path starting from the density directory @b "res/screen-density-XXX/" or @b "res/AxB", @n
	*									where A and B represent the width and height of the screen of the supported device models, respectively
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified input parameter is invalid.
	* @exception	E_UNSUPPORTED_FORMAT	The image file format is not supported.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found.
	* @exception	E_SYSTEM				A system error has occurred.
	* @remarks	The specific error code can be accessed using the GetLastResult() method.
	* @remarks	There is a high probability for an occurrence of an out-of-memory exception. If possible, check whether the exception is E_OUT_OF_MEMORY or not. For more information on how to handle the out-of-memory exception, refer <a href="../org.tizen.native.appprogramming/html/basics_tizen_programming/exception_check.htm">here</a>.
	*/
	Tizen::Graphics::Bitmap* GetBitmapN(const Tizen::Base::String& imagePath) const;

	/**
	* Gets the %AppResource instance pointer.
	*
	* @since  2.0
	*
	* @return A pointer to the %AppResource instance, @n
	*		  else @c null if it fails
	*/
	static AppResource* GetInstance(void);

	/**
	 * Gets the resource instance of the specified resource path.
	 * @since	2.0
	 * @return		A pointer to the %AppResource instance, @n
	 *				else @c null if it fails
	 * @param[in]	resourcePath		The relative path starting from the resource directory path of the current application
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_FILE_NOT_FOUND	The specified resource path does not exist.
	 * @exception	E_INVALID_ARG		The length of the specified path is @c 0 or exceeds system limitations.
	 * @exception	E_SYSTEM			Initializing string and bitmap resource is failed due to system error.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
    static AppResource* LoadAppResource(const Tizen::Base::String& resourcePath);

	/**
	* Gets the application resource instance of the specified @c appId.
	*
	* @since	2.0
	*
	* @privlevel	platform
	* @privilege   %http://tizen.org/privilege/appsetting
	*
	* @return       A pointer to the %AppResource instance, @n
	*               else @c null if it fails
	* @param[in]    appId                The AppId of the installed application
	* @exception    E_SUCCESS            The method is successful.
	* @exception    E_DATA_NOT_FOUND      The instance of specified @c appId does not provide the string resource.
	* @exception    E_OUT_OF_MEMORY      The memory is insufficient.
	* @exception    E_APP_NOT_INSTALLED  The specified @c appId is not found in the list of installed applications.
	* @exception    E_SYSTEM        Initializing string and bitmap resource has failed due to a system error.
	* @exception    E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @remarks The specific error code can be accessed using the GetLastResult() method.
	*/
	static AppResource* GetInstanceByAppId(const AppId& appId);

	/**
	* Releases the application resource instance of the specified @c appId.
	*
	* @since	2.0
	*
	* @privlevel	platform
	* @privilege   %http://tizen.org/privilege/appsetting
	*
	* @return       An error code
	* @param[in]    appId                The AppId of the installed application
	* @exception    E_SUCCESS            The method is successful.
	* @exception    E_OBJ_NOT_FOUND      The application resource instance of the specified @c appId is not found.
	* @exception    E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @remarks     Individual instances are managed by the platform. @n
	*              It is recommended to release instances to reduce memory usage.
	*/
	static result ReleaseInstanceByAppId(const AppId& appId);

private:
	/**
	 * This default constructor is intentionally declared as private to implement the %Singleton semantic.
	 *
	 * @since	2.0
	 */
	AppResource(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AppResource(const AppResource& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AppResource& operator =(const AppResource& rhs);

	/**
	 * This destructor is intentionally declared as private to implement the %Singleton semantic.
	 *
	 * @since	2.0
	 */
	virtual ~AppResource(void);

private:
	friend class _AppResourceImpl;
	class _AppResourceImpl* __pAppResourceImpl;
}; // AppResource

} } // Tizen::App

#endif
