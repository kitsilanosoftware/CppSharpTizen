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
 * @file	FAppAppSetting.h
 * @brief	This is the header file for the %AppSetting class.
 *
 * This header file contains the declarations of the %AppSetting class.
 */

#ifndef _FAPP_APP_SETTING_H_
#define _FAPP_APP_SETTING_H_

#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FBaseObject.h>
#include <FAppTypes.h>


namespace Tizen { namespace Base { namespace Collection
{
class IList;
}}}


namespace Tizen { namespace App
{

class IAppSettingEventListener;

/**
 * @class	AppSetting
 * @brief	This class manages an application's settings.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %AppSetting class lets an application to save or restore its settings.
 *
 *
 * The following example demonstrates how to use the %AppSetting class.
 *
 * @code
 *	void
 *	AppSettingForm::RefreshSetting(void)
 *	{
 *		AppSetting* pAppSetting = AppSetting::GetInstance();
 *		AppAssert(pAppSetting);
 *
 *		bool valueBool = false;
 *		int valueInt = 0;
 *		const String strLn(L"\n");
 *		String valueString;
 *		String settingText;
 *
 *		AppAssert(pAppSetting->GetValue(L"checkbox1", valueBool) == E_SUCCESS);
 *		settingText += L"checkbox1: ";
 *		settingText += strFalseTrue[valueBool ? 1 : 0];
 *		settingText += strLn;
 *
 *		AppAssert(pAppSetting->GetValue(L"slider1", valueInt) == E_SUCCESS);
 *		settingText += L"slider1: ";
 *		settingText += Integer(valueInt).ToString();
 *		settingText += strLn;
 *
 *		AppAssert(pAppSetting->GetValue(L"editbox1", valueString) == E_SUCCESS);
 *		settingText += L"editbox1: ";
 *		settingText += valueString;
 *		settingText += strLn;
 *		// . . .
 *	}
 *
 *	void
 *	AppSettingForm::SetSettingValueSet1(void)
 *	{
 *		AppSetting* pAppSetting = AppSetting::GetInstance();
 *		AppAssert(pAppSetting);
 *
 *		AppAssert(pAppSetting->SetValue(L"checkbox1", false) == E_SUCCESS);
 *		AppAssert(pAppSetting->SetValue(L"slider1", 100) == E_SUCCESS);
 *		AppAssert(pAppSetting->SetValue(L"editbox1", String(L"AppSetting working!")) == E_SUCCESS);
 *		AppAssert(pAppSetting->SetValue(L"expanditem1", String(L"1 minute")) == E_SUCCESS);
 *		AppAssert(pAppSetting->SetValue(L"expanditem1", false) == E_SUCCESS);
 *		AppAssert(pAppSetting->SetValue(L"slider2", 0) == E_SUCCESS);
 *		AppAssert(pAppSetting->SetValue(L"editbox2", String(L"AppSetting running!")) == E_SUCCESS);
 *		// . . .
 *	}
 * @endcode
 *
 */
class _OSP_EXPORT_ AppSetting
	: public Tizen::Base::Object
{
public:
	/**
	 * Gets the application setting instance.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the %AppSetting instance, @n
	 *				else @c null if it fails
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		It returns an instance for the latest setting. @n
	 * 				The specific error code can be accessed using the GetLastResult() method.
	 */
	static AppSetting* GetInstance(void);

	/**
	 * Gets the application setting instance of the specified version.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the %AppSetting instance, @n
	 *				else @c null if it fails
	 * @param[in]	settingVersion		The version of setting is retrieved from GetAppSettingVersionListN()
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified version is not found.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 * @see			GetAppSettingVersionListN()
	 */
	static AppSetting* GetInstance(const Tizen::Base::String& settingVersion);

	/**
	 * Gets the application setting instance of the specified AppId.
	 *
	 * @since	2.0
	 *
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/appsetting
	 *
	 * @return		A pointer to the %AppSetting instance, @n
	 *				else @c null if it fails
	 * @param[in]	appId				The AppId of the application that has a valid application setting
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The instance of specified AppId does not have setting information.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_APP_NOT_INSTALLED	The AppId is not found.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see			ReleaseInstanceByAppId()
	 */
	static AppSetting* GetInstanceByAppId(const AppId& appId);

	/**
	 * Releases the specified application setting instance.
	 *
	 * @since	2.0
	 *
	 * @privlevel	platform
	 * @privilege	%http://tizen.org/privilege/appsetting
	 *
	 * @return		An error code
	 * @param[in]	appId				The AppId of the application that has a valid application setting
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified instance of AppId is not found or already released.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		Individual instances are managed by the platform. @n
	 * 				It is recommended to release instances to reduce memory usage.
	 * @see			GetInstanceByAppId()
	 */
	static result ReleaseInstanceByAppId(const AppId& appId);

	/**
	 * Gets a list of all the versions that existed prior to the current version. @n
	 * The versions listed are based on the setting.xml file, which is generated when an application is installed.
	 *
	 * @since	2.0
	 *
	 * @return		A pointer to the list that contains the Tizen::Base::String instances of version list
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 * @remarks		The latest version string is located in the first position.
	 * 				If the old version does not exist then return empty collection. @n
	 * 				The specific error code can be accessed using the GetLastResult() method.
	 */
	static Tizen::Base::Collection::IList* GetAppSettingVersionListN(void);

	/**
	 * Gets a @c bool value associated with the specified @c id.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	id					The ID of the value to retrieve
	 * @param[out]	value				A boolean value to retrieve
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c id is not found in the application setting.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_TYPE_MISMATCH		The operation has attempted to access different types.
	 */
	result GetValue(const Tizen::Base::String& id, bool& value) const;

	/**
	 * Gets an integer value associated with the specified @c id.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	id					The ID of the value to retrieve
	 * @param[out]	value				An integer value to retrieve
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c id is not found in the application setting.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_TYPE_MISMATCH		The operation has attempted to access different types.
	 */
	result GetValue(const Tizen::Base::String& id, int& value) const;

	/**
	 * Gets a string value associated with the specified @c id.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	id					The id of the value to retrieve
	 * @param[out]	value				A string value to retrieve
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c id is not found in the application setting.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_TYPE_MISMATCH		The operation has attempted to access different types.
	 */
	result GetValue(const Tizen::Base::String& id, Tizen::Base::String& value) const;

	/**
	 * Sets a @c bool value associated with the specified @c id.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	id					The ID of the value to modify
	 * @param[in]	value				A boolean value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c id is not found in the application setting.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_TYPE_MISMATCH		The operation has attempted to access different types.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	result SetValue(const Tizen::Base::String& id, bool value);

	/**
	 * Sets an integer value associated with the specified @c id.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	id					The ID of the value to modify
	 * @param[in]	value				An integer value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c id is not found in the application setting.
	 * @exception	E_OUT_OF_RANGE		The specified @c value is out of range.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_TYPE_MISMATCH		The operation has attempted to access different types.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	result SetValue(const Tizen::Base::String& id, int value);

	/**
	 * Sets a string value associated with the specified @c id.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	id					The ID of the value to modify
	 * @param[in]	value				A string value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c id is not found in the application setting.
	 * @exception	E_OUT_OF_RANGE		The specified string length is out of range.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_TYPE_MISMATCH		The operation has attempted to access different types.
	 * @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	 */
	result SetValue(const Tizen::Base::String& id, const Tizen::Base::String& value);

	/**
	 * Sets a setting event listener.
	 *
	 * @since	2.0
	 *
	 * @return		An error code
	 * @param[in]	pListener			An instance of IAppSettingEventListener to set, @n
	 *                                  else @c null to clear a previous one
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result SetAppSettingEventListener(IAppSettingEventListener* pListener);

private:
	/**
	 * This default constructor is intentionally declared as private to implement the Singleton semantic.
	 *
	 * @since	2.0
	 */
	AppSetting(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AppSetting(const AppSetting& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AppSetting& operator =(const AppSetting& rhs);

	/**
	 * This destructor is intentionally declared as private to implement the Singleton semantic.
	 *
	 * @since	2.0
	 */
	virtual ~AppSetting(void);

	static void InitSingleton(void);
	static void DestroySingleton(void);

private:
	friend class _AppSettingImpl;
	class _AppSettingImpl* __pAppSettingImpl;
	static AppSetting* __pAppSettingInstance;

}; // AppSetting
} } // Tizen::App

#endif // _FAPP_APP_SETTING_H_
