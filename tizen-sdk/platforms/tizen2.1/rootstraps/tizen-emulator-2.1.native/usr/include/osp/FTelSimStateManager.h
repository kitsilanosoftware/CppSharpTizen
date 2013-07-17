//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
 * @file	FTelSimStateManager.h
 * @brief	This is the header file for the %SimStateManager class.
 *
 * This header file contains the declarations of the %SimStateManager class.
 */
#ifndef _FTEL_SIM_STATE_MANAGER_H_
#define _FTEL_SIM_STATE_MANAGER_H_


#include <FBase.h>
#include <FTelTypes.h>
#include <FTelSimInfo.h>
#include <FTelITelephonySimEventListener.h>
#include <FTelISimStateManagerGetPinLockSettingResultListener.h>


namespace Tizen { namespace Telephony
{
class _SimStateManagerImpl;

/**
 * @class	SimStateManager
 * @brief	This class provides methods to obtain information and events about the SIM card.
 * @since	2.1
 *
 * The %SimStateManager class provides methods to obtain information and events about the SIM card.
 *
 * @code
 *
 *  #include <FBase.h>
 *  #include <FTelephony.h>
 *
 *  using namespace Tizen::Base;
 *  using namespace Tizen::Telephony;
 *
 *  class MyClass
 *  	: public Object
 *  	, public ITelephonySimEventListener
 *  {
 *    public:
 *  	MyClass(void) {}
 *  	~MyClass(void) {}
 *
 *   // ITelephonySimEventListener
 * 	 void OnTelephonySimStateChanged(SimState state);
 *
 *   void GetSimState (void);
 * };
 *
 *  void
 *  MyClass::OnTelephonySimStateChanged(SimState state)
 *  {
 * 		//Do Something.
 *  }
 *
 *  void
 *  MyClass::GetSimState(void)
 *  {
 *  	SimStateManager* pSimStateManager = new (std::nothrow) SimStateManager();
 *  	SimInfo simInfo;
 *  	SimState simState = SIM_STATE_UNKNOWN;
 *
 *  	result r = pSimStateManager->Construct();
 *  	if (IsFailed(r))
 *  	{
 *  		delete pSimStateManager;
 *  		return;
 *  	}
 *
 *  	r = pSimStateManager->SetSimEventListener(this);
 *  	if (IsFailed(r))
 *  	{
 *  		delete pSimStateManager;
 *  		return;
 *  	}
 *
 *  	r = pSimStateManager->GetSimInfo(simInfo);
 *  	if (IsFailed(r))
 *  	{
 *  		delete pSimStateManager;
 *  		return;
 *  	}
 *
 *  	simState = pSimStateManager->GetSimState();
 *		delete pSimStateManager;
 *  }
 *
 *
 * @endcode
 */
class _OSP_EXPORT_ SimStateManager
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.1
	 */
	SimStateManager(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~SimStateManager(void);

	/**
	 * Initializes this instance of %SimStateManager.
	 *
	 * @since	2.1
	 * @feature %http://tizen.org/feature/network.telephony
	 * @return	An error code
	 *
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	 * @exception   E_UNSUPPORTED_OPERATION	 The Emulator or target device does not support the required feature.
	 * 										 For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks     Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	result Construct(void);

	/**
	 * Sets the listener for receiving SIM-related events.
	 *
	 * @since   2.1
	 *
	 * @privlevel	public
	 * @privilege   %http://tizen.org/privilege/telephony
	 *
	 * @return  An error code
	 *
	 * @param[in]   pListener				An ITelephonySimEventListener instance @n
	 *										The parameter can be set to @c null to remove listener.
	 *
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, @n
	 * 										because the caller thread is a worker thread.
	 */
	result SetSimEventListener(ITelephonySimEventListener* pListener);

	/**
	 * Requests for the PIN lock setting information. @n
	 * The %GetPinLockSetting() method is asynchronous.
	 *
	 * @since   2.1
	 *
	 * @privlevel	public
	 * @privilege   %http://tizen.org/privilege/telephony
	 *
	 * @return  An error code
	 *
	 * @param[in]   pListener				An ISimStateManagerGetPinLockSettingResultListener instance
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c pListener must not be @c null.
	 * @exception	E_IN_PROGRESS			The previous request is in progress.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception   E_SYSTEM            	The method cannot proceed due to a severe system error.
	 * @see ISimStateManagerGetPinLockSettingResultListener::OnSimStateManagerGetPinLockSettingResultReceived()
	 */
	result GetPinLockSetting(ISimStateManagerGetPinLockSettingResultListener* pListener);

	/**
	 * Gets the current state of SIM card.
	 *
	 * @since   2.1
	 *
	 * @privlevel	public
	 * @privilege   %http://tizen.org/privilege/telephony
	 *
	 * @return  	The state of SIM card, @n
	 * 				else @c SIM_STATE_UNKNOWN if the method fails
	 *
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 */
	SimState GetSimState(void) const;

	/**
	 * Gets the SIM card information.
	 *
	 * @since   2.1
	 *
	 * @privlevel	public
	 * @privilege   %http://tizen.org/privilege/telephony
	 *
	 * @return  An error code
	 *
	 * @param[out]	simInfo					The SIM card information
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 */
	result GetSimInfo(SimInfo& simInfo) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]   rhs   An instance of %SimStateManager
	//
	SimStateManager(const SimStateManager& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]   rhs An instance of %SimStateManager
	//
	SimStateManager& operator =(const SimStateManager& rhs);

private:
	_SimStateManagerImpl* __pSimStateManagerImpl;

	friend class _SimStateManagerImpl;
}; // SimStateManager

}} // Tizen::Telephony

#endif // _FTEL_SIM_STATE_MANAGER_H_
