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
 * @file			FAppAppRegistry.h
 * @brief			This is the header file for the %AppRegistry class.
 *
 * This header file contains the declarations of the %AppRegistry class.
 */

#ifndef _FAPP_APP_REGISTRY_H_
#define _FAPP_APP_REGISTRY_H_

#include <FBaseObject.h>
#include <FAppTypes.h>

namespace Tizen { namespace App
{

/**
 * @class		AppRegistry
 * @brief		This class manages an application's preferences.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %AppRegistry class lets an application to save or restore its preferences.
 * An instance of this class can be obtained through the Application class.
 * Also, since an application's state is generally restored in the App::OnAppInitializing() method and saved in the App::OnAppTerminating() method, an instance of this class is passed as an argument when these methods are invoked.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/app/app_namespace.htm">App Guide</a>.
 *
 * The following example demonstrates how to use the %AppRegistry class.
 *
 * @code
 *
 * void
 * MyAppClass::AppRegistryCallSample(void)
 * {
 * 	AppRegistry* pAppRegistry = GetAppRegistry();
 * 	String countKey("BasicAppRunCount");
 * 	String nameKey("BasicAppUserName");
 * 	String temperatureKey("BasicAppTemperature");
 * 	String name("BasicApp");
 * 	double temperature = 32.5;
 * 	result r = E_SUCCESS;
 * 	int	count = 0;
 *
 * 	r = pAppRegistry->Get(nameKey, name);
 * 	if (r == E_KEY_NOT_FOUND)
 * 	{
 * 		pAppRegistry->Add(nameKey, name);
 * 	}
 *
 * 	r = pAppRegistry->Get(countKey, count);
 * 	if (r == E_KEY_NOT_FOUND)
 * 	{
 * 		pAppRegistry->Add(countKey, count);
 * 	}
 *
 * 	r = pAppRegistry->Get(temperatureKey, temperature);
 * 	if (r == E_KEY_NOT_FOUND)
 * 	{
 * 		pAppRegistry->Add(temperatureKey, temperature);
 * 	}
 *
 * 	r = pAppRegistry->Save();
 * 	if (IsFailed(r))
 * 	{
 * 		// Failed to save data to registry
 * 	}
 *
 * 	// Displays the retrieved data
 * 	AppLog("AppRegistry Name value [%ls]", name.GetPointer());
 * 	AppLog("AppRegistry count [%d]", count);
 * 	AppLog("AppRegistry temperature value [%f]", temperature);
 *
 * 	// Updates the state of the application variables
 * 	count++;
 * 	name.Append(count);
 * 	temperature++;
 *
 * 	// Saves the app registry
 * 	r = pAppRegistry->Set(nameKey, name);
 * 	if (IsFailed(r))
 * 	{
 * 		// Error condition
 * 	}
 *
 * 	r = pAppRegistry->Set(countKey, count);
 * 	if (IsFailed(r))
 * 	{
 * 		// Error condition
 * 	}
 *
 * 	r = pAppRegistry->Set(temperatureKey, temperature);
 * 	if (IsFailed(r))
 * 	{
 * 		// Error condition
 * 	}
 *
 * 	r = pAppRegistry->Save();
 * 	if (IsFailed(r))
 * 	{
 * 		// Failed to save data to registry
 * 	}
 *
 * 	// Retrieves the saved content
 * 	pAppRegistry->Get(nameKey, name);
 * 	pAppRegistry->Get(countKey, count);
 * 	pAppRegistry->Get(temperatureKey, temperature);
 *
 * 	AppLog("AppRegistry Name value [%ls]", name.GetPointer());
 * 	AppLog("AppRegistry count [%d]", count);
 * 	AppLog("AppRegistry temperature value [%f]", temperature);
 *
 * 	return;
 * }
 * @endcode
 *
 **/
class _OSP_EXPORT_ AppRegistry
	: public Tizen::Base::Object
{
public:
	/**
	 * Adds a string value along with the specified @c key.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key		A key corresponding to the value
	 * @param[in]	value	A string value
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c key is empty or is string with '\0' and @htmlonly '\n' @endhtmlonly.
	 * @exception	E_KEY_ALREADY_EXIST		The key has already been used in the application preferences.
	 * @remarks	In order to save the value in the persistent storage, the Save() method must be called.
	 */
	result Add(const Tizen::Base::String& key, const Tizen::Base::String& value);

	/**
	 * Adds an integer value along with the specified @c key.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key		A key corresponding to the value
	 * @param[in]	value	An integer value
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c key is empty or is string with '\0' and @htmlonly '\n' @endhtmlonly.
	 * @exception	E_KEY_ALREADY_EXIST		The key has already been used in the application preferences.
	 * @remarks	In order to save the value in the persistent storage, the Save() method must be called.
	 */
	result Add(const Tizen::Base::String& key, int value);

	/**
	 * Adds a floating point value along with the specified @c key.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key		A key corresponding to the value
	 * @param[in]	value	A floating point value
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c key is empty or is string with '\0' and @htmlonly '\n' @endhtmlonly.
	 * @exception	E_KEY_ALREADY_EXIST		The key has already been used in the application preferences.
	 * @remarks	In order to save the value in the persistent storage, the Save() method must be called.
	 */
	result Add(const Tizen::Base::String& key, double value);

	/**
	 * Sets a string value associated with the specified @c key.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key		A key corresponding to the value
	 * @param[in]	value	A string value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c key is empty or is string with '\0' and @htmlonly '\n' @endhtmlonly.
	 * @exception	E_KEY_NOT_FOUND		The specified @c key is not used in the application preferences.
	 * @remarks	In order to save the value in the persistent storage, the Save() method must be called.
	 */
	result Set(const Tizen::Base::String& key, const Tizen::Base::String& value);

	/**
	 * Sets an integer value associated with the specified @c key.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	A key corresponding to the value
	 * @param[in]	value	An integer value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c key is empty or is string with '\0' and @htmlonly '\n' @endhtmlonly.
	 * @exception	E_KEY_NOT_FOUND		The specified @c key is not used in the application preferences.
	 * @remarks	In order to save the value in the persistent storage, the Save() method must be called.
	 */
	result Set(const Tizen::Base::String& key, int value);

	/**
	 * Sets a floating point value associated with the specified @c key.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key	A key corresponding to the value
	 * @param[in]	value	A floating point value
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c key is empty or is string with '\0' and @htmlonly '\n' @endhtmlonly. 
	 * @exception	E_KEY_NOT_FOUND		The specified @c key is not used in the application preferences.
	 * @remarks	In order to save the value in the persistent storage, the Save() method must be called.
	 */
	result Set(const Tizen::Base::String& key, double value);

	/**
	 * Saves the values temporarily in the persistent storage. @n
	 * The %Save() method is invoked internally when the instance of this class is deleted.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result Save(void);

	/**
	 * Removes a preference associated with the specified @c key.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key		The key of the value to remove
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_KEY_NOT_FOUND		The specified @c key is not used in the application preferences.
	 */
	result Remove(const Tizen::Base::String& key);

	/**
	 * Gets a string value associated with the specified @c key.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key		The key of the value to retrieve
	 * @param[out]	value	A string value to retrieve
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c key is empty or is string with '\0' and @htmlonly '\n' @endhtmlonly.
	 * @exception	E_KEY_NOT_FOUND		The specified @c key is not used in the application preferences.
	 */
	result Get(const Tizen::Base::String& key, Tizen::Base::String& value) const;

	/**
	 * Gets an integer value associated with the specified @c key.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key		The key of the value to retrieve
	 * @param[out]	value	An integer value to retrieve
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c key is empty or is string with '\0' and @htmlonly '\n' @endhtmlonly.
	 * @exception	E_KEY_NOT_FOUND		The specified @c key is not used in the application preferences.
	 */
	result Get(const Tizen::Base::String& key, int& value) const;

	/**
	 * Gets a floating point value associated with the specified @c key.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @param[in]	key		The key of the value to retrieve
	 * @param[out]	value	A floating point value to retrieve
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c key is empty or is string with '\0' and @htmlonly '\n' @endhtmlonly.
	 * @exception	E_KEY_NOT_FOUND		The specified @c key is not used in the application preferences.
	 */
	result Get(const Tizen::Base::String& key, double& value) const;

	/**
	 * Gets the %AppRegistry instance pointer.
	 *
	 * @since		2.0
	 *
	 * @return A pointer to the %AppRegistry instance, @n
	 *		  else @c null if it fails
	 */
	static AppRegistry* GetInstance(void);

private:
	/**
	 * This default constructor is intentionally declared as private to implement the %Singleton semantic.
	 *
	 * @since	2.0
	 */
	AppRegistry(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AppRegistry(const AppRegistry& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @since	2.0
	 */
	AppRegistry& operator =(const AppRegistry& rhs);

	/**
	 * This destructor is intentionally declared as private to implement the %Singleton semantic.
	 *
	 * @since	2.0
	 */
	virtual ~AppRegistry(void);

	/**
	 * Initializes this instance.
	 *
	 * @since	2.0
	 *
	 * @return	An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 */
	result Construct(void);

private:
	class _AppRegistryImpl* __pAppRegistryImpl;

	friend class _AppRegistryImpl;
}; // AppRegistry

} } // Tizen::App

#endif // _FAPP_APP_REGISTRY_H_
