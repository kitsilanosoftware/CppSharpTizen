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
 * @file  FTelCallManager.h
 * @brief This is the header file for the %CallManager class.
 *
 * This header file contains the declarations of the %CallManager class.
 */
#ifndef _FTEL_CALL_MANAGER_H_
#define _FTEL_CALL_MANAGER_H_


#include <FBase.h>
#include <FTelTypes.h>
#include <FTelCallInfo.h>
#include <FTelITelephonyCallEventListener.h>
#include <FTelITelephonyCallForwardListener.h>


namespace Tizen { namespace Telephony
{
class _CallManagerImpl;

/**
 * @class	CallManager
 * @brief	This class provides methods to obtain information about the current call.
 *
 * @since	2.0
 *
 * The %CallManager class provides methods to obtain information about the current call type and its status.
 *
 * The following example demonstrates how to use the %CallManager class to obtain information about a call.
 *
 * @code
 *
 *  #include <FBase.h>
 *  #include <FTelephony.h>
 *
 *   using namespace Tizen::Base;
 *   using namespace Tizen::Telephony;
 *
 *   class MyClass
 *  	 : public Object
 *  	 , public ITelephonyCallEventListener
 *   {
 *   public:
 *  	 MyClass(void) {}
 *  	 ~MyClass(void) {}
 *
 *  	 // ITelephonyCallEventListener
 *  	 void OnTelephonyCallStatusChangedN(CallStatus callStatus, CallInfo* pCallInfo);
 *
 *  	 void GetCallInfo(void);
 *   };
 *
 *   void
 *   MyClass::OnTelephonyCallStatusChangedN(CallStatus callStatus, CallInfo* pCallInfo)
 *   {
 *  	 CallType callType;
 *  	 String number;
 *
 *  	 if (callStatus == CALL_STATUS_RINGING)
 *  	 {
 *  		 callType  = pCallInfo->GetCallType();
 *  		 number = pCallInfo->GetNumber();
 *  	 }
 *
 *  	 delete pCallInfo;
 *   }
 *
 *   void
 *   MyClass::GetCallInfo(void)
 *   {
 *  	 CallType callType = TYPE_UNDEFINED_CALL;
 *  	 CallStatus callStatus = CALL_STATUS_UNDEFINED;
 *
 *  	 CallManager* pCallManager = new (std::nothrow) CallManager();
 *
 *  	 result r = pCallManager->Construct(*this);
 *  	 if (IsFailed(r))
 *  	 {
 *  	   delete pCallManager;
 *  	   return;
 *  	 }
 *
 *  	 callStatus = pCallManager->GetCurrentCallStatus();
 *  	 if (callStatus == CALL_STATUS_COMMUNICATING)
 *  	 {
 *  		 callType = pCallManager->GetCurrentCallType();
 *  	 }
 *
 *  	 delete pCallManager;
 *   }
 *
 *
 *
 * @endcode
 */
class _OSP_EXPORT_ CallManager
	: public Tizen::Base::Object
{
public:
	/**
     * 	 The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
     *
     * @since   2.0
     */
	CallManager(void);

	/**
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since   2.0
     */
	virtual ~CallManager(void);

	/**
     * Initializes a new instance of this class. @n
     * This is the two phase construction.
     *
     * @since   2.0
	 * @feature %http://tizen.org/feature/network.telephony
     * @return  An error code
     * @exception   E_SUCCESS 		The method is successful.
     * @exception   E_SYSTEM  		A system error has occurred.
	 * @exception  E_UNSUPPORTED_OPERATION	 The Emulator or target device does not support the required feature. @b Since: @b 2.1
	 * 										 For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks     Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
     */
	result Construct(void);

	/**
     * Initializes a new instance of this class. @n
     * This is the two phase construction.
     *
     * @since   2.0
	 * @feature %http://tizen.org/feature/network.telephony
     * @return  An error code
     * @param[in]   listener  The listener for change in status of a call
     * @exception   E_SUCCESS The method is successful.
     * @exception   E_SYSTEM  A system error has occurred.
	 * @exception   E_UNSUPPORTED_OPERATION	 The Emulator or target device does not support the required feature. @b Since: @b 2.1
	 * 										 For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks     Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
     */
	result Construct(ITelephonyCallEventListener& listener);

	/**
     * Sets the listener that listens to the call forwarding request.
     *
     * @since   2.0
	 *
     * @privlevel	platform
     * @privilege   %http://tizen.org/privilege/callforward
     *
     * @return  An error code
     * @param[in]   pListener           An ITelephonyCallForwardListener instance @n
     *                                  The parameter can be set to @c null to remove listener.
     * @exception   E_SUCCESS           The method is successful.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @exception   E_SYSTEM            A system error has occurred.
     */
	result SetCallForwardListener(ITelephonyCallForwardListener* pListener);

	/**
     * Requests call forwarding with the specified number. @n
     * The %RequestCallForward() method sends the request to the network, and receives the response asynchronously.
     *
     * @since   2.0
	 *
     * @privlevel	platform
     * @privilege   %http://tizen.org/privilege/callforward
     *
     * @return  An error code
     * @param[in]   phoneNumber The phone number for call forwarding
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_INVALID_STATE         This instance is in an invalid state.
     * @exception   E_INVALID_FORMAT        The specified phone number is in an invalid format.
     * @exception   E_IN_PROGRESS           The previous request is in progress.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_NETWORK_UNAVAILABLE   The operation has failed because the device is in the offline mode.
     * @exception   E_SERVICE_UNAVAILABLE   The operation has failed because the device is out of the coverage area or in the emergency mode.
     * @exception   E_SYSTEM                A system error has occurred.
     * @remarks The call will be forwarded unconditionally. Voice call only. @n
     *          The phone number can start with plus(+) and the remaining part must be number.
     * @see ITelephonyCallForwardListener::OnTelephonyCallForwardResponseReceived()
     */
	result RequestCallForward(const Tizen::Base::String& phoneNumber);

    /**
     * Stops call forwarding.
     *
     * @since   2.0
	 *
     * @privlevel	platform
     * @privilege   %http://tizen.org/privilege/callforward
     *
     * @return  An error code
     * @exception	E_SUCCESS               The method is successful.
     * @exception	E_INVALID_STATE         This instance is in an invalid state.
     * @exception	E_IN_PROGRESS           The previous request is in progress.
     * @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception	E_NETWORK_UNAVAILABLE   The operation has failed because the device is in the offline mode.
     * @exception	E_SERVICE_UNAVAILABLE   The operation has failed because the device is out of the coverage area or in the emergency mode.
     * @exception	E_SYSTEM                A system error has occurred.
     * @see ITelephonyCallForwardListener::OnTelephonyCallForwardStopped()
     */
	result StopCallForward(void);

	/**
     * Gets the phone number to which the call must be forwarded.
     *
     * @since   2.0
	 *
     * @privlevel	platform
     * @privilege   %http://tizen.org/privilege/callforward
     *
     * @return  An error code
     * @exception   E_SUCCESS               The method is successful.
     * @exception   E_IN_PROGRESS           The previous request is in progress.
     * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
     * @exception   E_NETWORK_UNAVAILABLE   The operation has failed because the device is in the offline mode.
     * @exception   E_SERVICE_UNAVAILABLE   The operation has failed because the device is out of the coverage area or in the emergency mode.
     * @exception   E_SYSTEM                A system error has occurred.
     * @see ITelephonyCallForwardListener::OnTelephonyCallForwardNumberReceived
     */
	result GetCallForwardNumber(void) const;

	/**
     * Gets the call type of the current call.
     *
     * @since			2.0
	 *
     * @return      The current call type, @n
     *              else @c TYPE_UNDEFINED_CALL if the method fails
     */
	CallType GetCurrentCallType(void) const;

	/**
     * Gets the call status of the current call.
     *
     * @since			2.0
	 *
     * @return      The current call status, @n
     *              else @c CALL_STATUS_UNDEFINED if the method fails
     */
	CallStatus GetCurrentCallStatus(void) const;

private:
	/**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]	rhs	An instance of %CallManager
     */
	CallManager(const CallManager& rhs);

	/**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]	rhs	An instance of %CallManager
     */
	CallManager& operator =(const CallManager& rhs);

private:
	_CallManagerImpl* __pCallManagerImpl;

	friend class _CallManagerImpl;
}; // CallManager

} } // Tizen::Telephony
#endif // _FTEL_CALL_MANAGER_H_
