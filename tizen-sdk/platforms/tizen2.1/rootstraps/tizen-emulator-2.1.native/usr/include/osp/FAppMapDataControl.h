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
 * @file    FAppMapDataControl.h
 * @brief   This is the header file for the %MapDataControl class.
 *
 * This header file contains the declarations of the %MapDataControl class.
 */

#ifndef _FAPP_MAP_DATA_CONTROL_H_
#define _FAPP_MAP_DATA_CONTROL_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>

namespace Tizen { namespace Base
{
class String;
}}

namespace Tizen { namespace App
{

class IMapDataControlResponseListener;

/**
 * @class   MapDataControl
 * @brief   This class represents the MAP-type data control behavior.
 *
 * @since	2.0
 *
 * @final   This class is not intended for extension.
 *
 * The %MapDataControl class represents the MAP-type data control behavior, that provides a standard mechanism
 * for accessing specific data exported by other applications.
 * Data control provider can share its own data to data control consumers.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/app/data_controls.htm">Data Controls</a>.
 *
 * @see	Tizen::App::AppManager
 *
 * @code
 *
 * #include <FBase.h>
 * #include <FApp.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::App;
 *
 * class MyMapDataControlResponseListener:
 *	: public Tizen::App::IMapDataControlResponseListener
 * {
 * public:
 * 	void OnMapDataControlGetValueResponseReceived(RequestId reqId, const String& providerId, const String& dataId, IList& resultValueList, bool providerResult, const String* pErrorMsg)
 *	{
 *		int count = resultValueList.GetCount();
 *		for (int i = 0; i < count; i++)
 *		{
 *			String pPerson = static_cast< String* >(resultValueList.GetAt(i));
 *			AppLog("%dth person: %ls", i, pPerson->GetPointer());
 *		}
 *	}
 * };
 *
 * void
 * MyClass::Execute(void)
 * {
 *		String providerId(L"http://tizen.org/datacontrol/provider/example");
 *		MapDataControl* pDc = AppManager::GetMapDataControlN(providerId);
 *
 *		MyMapDataControlResponseListener* pResponseListener = new MyMapDataControlResponseListener();
 *
 *		pDc->SetMapDataControlResponseListener(pResponseListener);
 *
 *		String dataId(L"test");
 *		String person(L"person");
 *		RequestId reqId;
 *
 *		pDc->GetValue(dataId, person, reqId);
 * }
 *
 * @endcode
 */

class _OSP_EXPORT_ MapDataControl
	: public Tizen::Base::Object
{

public:
	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	virtual ~MapDataControl(void);

	/**
	* Gets the value list associated with the specified @c key, from a key-values map owned by MAP-type data control provider. @n
	* The %GetValue() method is asynchronous.
	* For receiving the response from data control provider, set the listener
	* with MapDataControl::SetMapDataControlResponseListener(). @n
	* When the requested value list has been received from data control provider,
	* the IMapDataControlResponseListener::OnMapDataControlGetValueResponseReceived() method is called.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	dataId			A string for identifying specific data, usually a registry section to get from @n
	*                               The string consists of one or more components, separated by a slash('/').
	* @param[in]	key             A key of the value list to obtain
	* @param[out]   reqId			The ID of the request
	* @param[in]	pageNo			The page number of the value set @n
	*								It starts from @c 1.
	* @param[in]	countPerPage	The desired maximum count of the data item on the page
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been properly constructed as yet.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The specified @c pageNo parameter is less than @c 1.
	*									- The specified @c countPerPage parameter is less than @c 1.
	* @exception	E_ILLEGAL_ACCESS	Either of the following conditions has occurred: @n
	*									- Access is denied due to insufficient permission.
	*									- The application using this method is not signed with the same certificate of provider application. @b Since: @b 2.1
	* @exception	E_MAX_EXCEEDED		Either of the following conditions has occurred: @n
	* 									- The size of sending buffer has exceeded the maximum limit.
	* 									- The number of sending requests has exceeded the maximum limit.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The recommended data size is under 16KB because severe system performance degradation may occur for large messages. @c E_MAX_EXCEEDED may be returned for messages over 16KB size.
	*/
	result GetValue(const Tizen::Base::String& dataId, const Tizen::Base::String& key, RequestId& reqId, int pageNo = 1, int countPerPage = 20);

	/**
	* Adds the value associated with the specified @c key, to a key-values map owned by MAP-type data control provider. @n
	* The %AddValue() method is asynchronous.
	* For receiving the response from data control provider, set the listener
	* with MapDataControl::SetMapDataControlResponseListener(). @n
	* When the response has been received from the data control provider,
	* the IMapDataControlResponseListener::OnMapDataControlAddValueResponseReceived() method is called.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	dataId		A string for identifying specific data, usually a registry section to add to @n
	*							The string consists of one or more components, separated by a slash('/').
	* @param[in]	key			A key of the value list to add
	* @param[in]	value       A value to add
	* @param[out]   reqId		The ID of the request
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been properly constructed as yet.
	* @exception	E_ILLEGAL_ACCESS	Either of the following conditions has occurred: @n
	*									- Access is denied due to insufficient permission.
	*									- The application using this method is not signed with the same certificate of provider application. @b Since: @b 2.1
	* @exception	E_MAX_EXCEEDED		Either of the following conditions has occurred: @n
	* 									- The size of sending buffer has exceeded the maximum limit.
	* 									- The number of sending requests has exceeded the maximum limit.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The recommended data size is under 16KB because severe system performance degradation may occur for large messages. @c E_MAX_EXCEEDED may be returned for messages over 16KB size.
	*/
	result AddValue(const Tizen::Base::String& dataId, const Tizen::Base::String& key, const Tizen::Base::String& value, RequestId& reqId);

	/**
	* Sets the value associated with the specified @c key with a new value. @n
	* The key-values map is owned by MAP-type data control provider. @n
	* The %SetValue() method is asynchronous.
	* For receiving the response from data control provider, set the listener
	* with MapDataControl::SetMapDataControlResponseListener(). @n
	* When the response has been received from the data control provider,
	* the IMapDataControlResponseListener::OnMapDataControlSetValueResponseReceived() method is called.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	dataId		A string for identifying specific data, usually a registry section to update @n
	*							The string consists of one or more components, separated by a slash('/').
	* @param[in]	key			A key of the value to replace
	* @param[in]	oldValue	A value to replace
	* @param[in]	newValue	A new value to replace the existing value
	* @param[out]   reqId		The ID of the request
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been properly constructed as yet.
	* @exception	E_ILLEGAL_ACCESS	Either of the following conditions has occurred: @n
	*									- Access is denied due to insufficient permission.
	*									- The application using this method is not signed with the same certificate of provider application. @b Since: @b 2.1
	* @exception	E_MAX_EXCEEDED		Either of the following conditions has occurred: @n
	* 									- The size of sending buffer has exceeded the maximum limit.
	* 									- The number of sending requests has exceeded the maximum limit.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The recommended data size is under 16KB because severe system performance degradation may occur for large messages. @c E_MAX_EXCEEDED may be returned for messages over 16KB size.
	*/
	result SetValue(const Tizen::Base::String& dataId, const Tizen::Base::String& key, const Tizen::Base::String& oldValue, const Tizen::Base::String& newValue, RequestId& reqId);

	/**
	* Removes the value associated with the specified @c key, from a key-values map owned by MAP-type data control provider. @n
	* The %RemoveValue() method is asynchronous.
	* For receiving the response from data control provider, set the listener
	* with MapDataControl::SetMapDataControlResponseListener(). @n
	* When the response has been received from the data control provider,
	* the IMapDataControlResponseListener::OnMapDataControlRemoveValueResponseReceived() method is called.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	dataId		A string for identifying specific data, usually a registry section to remove from @n
	*							The string consists of one or more components, separated by a slash('/').
	* @param[in]	key			A key of the value to remove
	* @param[in]	value       A value to remove
	* @param[out]   reqId		The ID of the request
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been properly constructed as yet.
	* @exception	E_ILLEGAL_ACCESS	Either of the following conditions has occurred: @n
	*									- Access is denied due to insufficient permission.
	*									- The application using this method is not signed with the same certificate of provider application. @b Since: @b 2.1
	* @exception	E_MAX_EXCEEDED		Either of the following conditions has occurred: @n
	* 									- The size of sending buffer has exceeded the maximum limit.
	* 									- The number of sending requests has exceeded the maximum limit.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The recommended data size is under 16KB because severe system performance degradation may occur for large messages. @c E_MAX_EXCEEDED may be returned for messages over 16KB size.
	*/
	result RemoveValue(const Tizen::Base::String& dataId, const Tizen::Base::String& key, const Tizen::Base::String& value, RequestId& reqId);

	/**
	* Sets the MAP-based data control listener to this instance.
	*
	* @since	2.0
	*
	* @return		An error code
	* @param[in]	pListener			The data control callback listener @n
	*									Some data controls need to get the callback result by implementing
	*									the IMapDataControlResponseListener interface.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been properly constructed.
	* @exception	E_SYSTEM			A system error has occurred.
	*/
	result SetMapDataControlResponseListener(IMapDataControlResponseListener* pListener);

private:
	/**
	* This default constructor is intentionally declared as private so that only the platform can create an instance.
	*
	* @since	2.0
	*/
	MapDataControl(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	* @remarks	This constructor is hidden.
	*/
	MapDataControl(const MapDataControl& mapDataControl);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	* @remarks	This operator is hidden.
	*/
	MapDataControl& operator =(const MapDataControl& mapDataControl);

private:
	class _MapDataControlImpl * __pMapDataControlImpl;

	friend class _MapDataControlImpl;
}; // MapDataControl

}} // Tizen::App

#endif // _FAPP_MAP_DATA_CONTROL_H_

