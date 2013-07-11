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
 * @file			FMediaCapability.h
 * @brief			This is the header file for the %MediaCapability class.
 *
 * This header file contains the declarations of the %MediaCapability class.
 */

#ifndef _FMEDIA_CAPABILITY_H_
#define _FMEDIA_CAPABILITY_H_

#include <FBase.h>
#include <FMediaCapabilityTypes.h>

namespace Tizen { namespace Media
{

class _CapabilityImpl;

/**
 * @class	MediaCapability
 * @brief	This class provides capability information of the various classes in the Media namespace.
 *
 * @since		2.0
 *
 *
 * The %MediaCapability class provides capability information of the various classes in the %Media namespace.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/media_capabilities.htm">Media Capabilities</a>.
 *
 * The following example demonstrates how to use the %MediaCapability class.
 * @code
 *
 * #include <FBase.h>
 * #include <FGraphics.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Media;
 *
 * result
 * MediaCapabilitySample(void)
 * {
 *	 Tizen::Base::Collection::IList *pList = null;
 *
 *	 pList = MediaCapability::GetValueN(CAMERA_PRIMARY_CAPTURE_FORMAT);
 *	 if (pList == null)
 *	 {
 *		 return GetLastResult();
 *	 }
 *
 *	 for (int i = 0; i < pList->GetCount(); i++)
 *	 {
 *		 Tizen::Graphics::PixelFormat captureFormat;
 *		 Tizen::Base::Integer *pValue = dynamic_cast<Tizen::Base::Integer*>(pList->GetAt(i));
 *		 if (pValue)
 *		 {
 *			 captureFormat = (Tizen::Graphics::PixelFormat)pValue->ToInt();
 *			 AppLog("CaptureFormat[%d] = %d", i, captureFormat);
 *		 }
 *	 }
 *	 pList->RemoveAll(true);
 *	 delete pList;
 *
 *	 pList = MediaCapability::GetValueN(CAMERA_PRIMARY_PREVIEW_RESOLUTION);
 *	 if (pList == null)
 *	 {
 *		 return GetLastResult();
 *	 }
 *
 *	 for (int i = 0; i < pList->GetCount(); i++)
 *	 {
 *		 Tizen::Graphics::Dimension *pValue = dynamic_cast<Tizen::Graphics::Dimension*>(pList->GetAt(i));
 *		 if (pValue)
 *		 {
 *			 AppLog("PreviewResolution[%d] = %d x %d", i, pValue->width, pValue->height);
 *		 }
 *	 }
 *	 pList->RemoveAll(true);
 *	 delete pList;
 *
 *	 return E_SUCCESS;
 * }
 *
 * @endcode
 *
 *
 *
 */

class _OSP_EXPORT_ MediaCapability
{

// Operations
public:
	/**
	*	Gets the capability value.
	*
	* @since		2.0
	*
	*	@return		An error code on failure, @n
	*				else E_SUCCESS
	*	@param[in]	key								The <a href="../org.tizen.native.appprogramming/html/guide/media/media_capabilities.htm#media_capabilities">key name</a> of the media capability
	*	@param[out]	value							The retrieved capability information
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_OBJ_NOT_FOUND				 The specified @c key is not found.
	*	@exception	E_INVALID_ARG					A specified input parameter is invalid.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	static result GetValue(const Tizen::Base::String& key, bool& value);


	/**
	*	Gets the capability value.
	*
	* @since		2.0
	*
	*	@return		An error code on failure, @n
	*				else E_SUCCESS
	*	@param[in]	key								The <a href="../org.tizen.native.appprogramming/html/guide/media/media_capabilities.htm#media_capabilities">key name</a> of the media capability
	*	@param[out]	value							The retrieved capability information
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_OBJ_NOT_FOUND				 The specified @c key is not found.
	*	@exception	E_INVALID_ARG					A specified input parameter is invalid.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	static result GetValue(const Tizen::Base::String& key, int& value);

	/**
	*	Gets the capability value.
	*
	* @since		2.0
	*
	*	@return		An error code on failure, @n
	*				else E_SUCCESS
	*	@param[in]	key								The <a href="../org.tizen.native.appprogramming/html/guide/media/media_capabilities.htm#media_capabilities">key name</a> of the media capability
	*	@param[out]	value							The retrieved capability information
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_OBJ_NOT_FOUND				 The specified @c key is not found.
	*	@exception	E_INVALID_ARG					A specified input parameter is invalid.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	static result GetValue(const Tizen::Base::String& key, long long& value);

	/**
	*	Gets the capability value.
	*
	* @since		2.0
	*
	*	@return			An error code on failure, @n
	*					else E_SUCCESS
	*	@param[in]	key								The <a href="../org.tizen.native.appprogramming/html/guide/media/media_capabilities.htm#media_capabilities">key name</a> of the media capability
	*	@param[out]	value							The retrieved capability information
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_OBJ_NOT_FOUND				 The specified @c key is not found.
	*	@exception	E_INVALID_ARG					A specified input parameter is invalid.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	static result GetValue(const Tizen::Base::String& key, double& value);

	/**
	*	Gets the capability value.
	*
	* @since		2.0
	*
	*	@return			An error code on failure, @n
	*					else E_SUCCESS
	*	@param[in]	key								The <a href="../org.tizen.native.appprogramming/html/guide/media/media_capabilities.htm#media_capabilities">key name</a> of the media capability
	*	@param[out]	value							The retrieved capability information
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_OBJ_NOT_FOUND				 The specified @c key is not found.
	*	@exception	E_INVALID_ARG					A specified input parameter is invalid.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	static result GetValue(const Tizen::Base::String& key, Tizen::Base::String& value);

	/**
	*	Gets the capability value.
	*
	* @since		2.0
	*
	*	@return		A pointer to Tizen::Base::Collection::IList on success, @n
	*				else @c null
	*	@param[in]	key								The <a href="../org.tizen.native.appprogramming/html/guide/media/media_capabilities.htm#media_capabilities">key name</a> of the media capability
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_OBJ_NOT_FOUND				 The specified @c key is not found.
	*	@exception	E_INVALID_ARG					The specified input parameter is invalid.
	*	@exception	E_SYSTEM						A system error has occurred.
	*	@remarks	The specific error code can be accessed using the GetLastResult() method.
	*			If the type of a key is 'List, type', use GetValueN(). @n
	*			For example, 'List, String', 'List, Integer'.
	*/
	static Tizen::Base::Collection::IList* GetValueN(const Tizen::Base::String& key);

private:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks	    This default constructor is intentionally declared as private to implement the Singleton semantic.
	 */
	MediaCapability(void);
	/**
	 * This is the default destructor for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks	    This destructor is intentionally declared as private to implement the Singleton semantic.
	 */
	~MediaCapability(void);
	/**
	 * This is the copy constructor for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks	    The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	MediaCapability(const MediaCapability& src);
	/**
	 * This is the copy assignment operator for this class.
	 *
	 * @since		2.0
	 *
	 * @remarks	    The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	MediaCapability& operator =(const MediaCapability& src);

	friend class _CapabilityImpl;
	_CapabilityImpl* __pImpl;
};


}}// Tizen::Media

#endif
