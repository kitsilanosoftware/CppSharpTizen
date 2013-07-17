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
 * @file	FTelSimInfo.h
 * @brief	This is the header file for the %SimInfo class.
 *
 * This header file contains the declarations of the %SimInfo class.
 */
#ifndef _FTEL_SIM_INFO_H_
#define _FTEL_SIM_INFO_H_


#include <FBase.h>
#include <FTelTypes.h>


namespace Tizen { namespace Telephony
{
class _SimInfoImpl;


/**
 * @class	SimInfo
 * @brief	This class provides information of the currently inserted SIM card.
 * @since	2.0
 *
 * The %SimInfo class provides methods to get information from the SIM card such as MCC, MNC, SPN, ICC ID, the name of operator,
 * and whether the SIM card is available or not.
 *
 * The following example demonstrates how to use the %SimInfo class to get the SIM information.
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
 *   {
 *   public:
 *  	 void GetSimInfo(void);
 *   };
 *
 *   void
 *   MyClass::GetSimInfo(void)
 *   {
 *  	 int mnc;
 *  	 int mcc;
 *  	 bool isAvailable;
 *  	 String spn;
 *  	 String iccId;
 *  	 String operatorName;
 *  	 SimType simType;
 *
 *  	 SimStateManager* pSimStateManager = new (std::nothrow) SimStateManager();
 *  	 SimInfo simInfo;
 *
 *  	 result r = pSimStateManager->Construct();
 *  	 if (IsFailed(r))
 *  	 {
 *  		 delete pSimStateManager;
 *  		 return;
 *  	 }
 *
 *  	 r = pSimStateManager->GetSimInfo(simInfo);
 *  	 if (IsFailed(r))
 *  	 {
 *  		 delete pSimStateManager;
 *  		 return;
 *  	 }
 *
 *  	 mnc = simInfo.GetMnc();
 *  	 mcc = simInfo.GetMcc();
 *  	 spn = simInfo.GetSpn();
 *  	 iccId = simInfo.GetIccId();
 *  	 operatorName = simInfo.GetOperatorName();
 *  	 isAvailable = simInfo.IsAvailable();
 *  	 simType = simInfo.GetSimType();
 *
 *  	 delete pSimStateManager;
 *   }
 *
 *
 * @endcode
 */
class _OSP_EXPORT_ SimInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	SimInfo(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since   	2.1
	 *
	 * @param[in]   rhs   An instance of %SimInfo
	 */
	SimInfo(const SimInfo& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~SimInfo(void);

	/**
	 * Initializes this instance of %SimInfo.
	 *
	 * @brief   <i> [Deprecated] </i>
	 * @deprecated	This method is deprecated. Instead of using this method, it is recommended to use the SimStateManager::GetSimInfo() method to get the initialized %SimInfo instance.
	 *
	 * @since		2.0
	 * @feature %http://tizen.org/feature/network.telephony
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception   E_UNSUPPORTED_OPERATION	 The Emulator or target device does not support the required feature. @b Since: @b 2.1
	 * 										 For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks     Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	 */
	result Construct(void);

	/**
	 * Gets the Mobile Network Code (MNC) of the SIM International Mobile Subscriber Identity (IMSI) information.
	 *
	 * @since	2.0
	 *
	 * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
	 *
	 * @return      The MNC of the SIM card, @n
	 *              else @c -1 if the method fails
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetMnc(void) const;

	/**
	 * Gets the Mobile Country Code (MCC) of the SIM IMSI information.
	 *
	 * @since	2.0
	 *
	 * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
	 *
	 * @return      The MCC of the SIM card, @n
	 *              else @c -1 if the method fails
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetMcc(void) const;

	/**
	 * Gets the Service Provider Name (SPN) string of the SIM card.
	 *
	 * @since	2.0
	 *
	 * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
	 *
	 * @return      The SPN of the SIM card, @n
	 *              else an empty string if there is no SIM card in the device, or if an SPN is not assigned to the SIM card
	 * @exception   E_SUCCESS	The method is successful.
	 * @exception   E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception   E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetSpn(void) const;

	/**
 	 * Gets the Integrated Circuit Card Identifier (ICCID) of the SIM card. @n
	 * One useful case to detect the change of SIM cards is to store this value and compare it with the most recent value.
	 * The %GetIccId() method provides a unique identification number for the SIM card.
	 *
	 * @since	2.0
	 *
	 * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
	 *
	 * @return  The ICCID of the SIM card, @n
	 *          else an empty string if the method fails
	 * @exception   E_SUCCESS	The method is successful.
	 * @exception   E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception   E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetIccId(void) const;

    /**
	 * Gets the operator name of Common PCN Handset Specification (CPHS) of the SIM card.
	 *
	 * @since	2.0
	 *
	 * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
	 *
	 * @return      The operator name of the SIM card, @n
	 *              else an empty string if there is no SIM card in the device, or if an operator name is not assigned to the SIM card
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks If this method has failed, then this method returns an empty string.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetOperatorName(void) const;

	/**
	 * Gets the phone number of the SIM card.
	 *
	 * @since	2.0
	 *
	 * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
	 *
	 * @return      The phone number of the SIM card, @n
	 *              else an empty string if there is no SIM card in the device, or if a Mobile Station International Subscriber Directory Number
	 *              (MSISDN) is not assigned to the SIM card
	 * @exception	E_SUCCESS    The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetPhoneNumber(void) const;

	/**
	 * Gets the International Mobile Subscriber Identity (IMSI) of the SIM card.
	 *
	 * @since	2.0
	 *
	 * @privlevel  partner
     * @privilege   %http://tizen.org/privilege/systemmanager @n
     * 				(%http://tizen.org/privilege/useridentity is deprecated.)
	 *
	 * @return      The IMSI of the SIM card, @n
	 *              else an empty string if the method fails
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception 	E_SYSTEM	The method cannot proceed due to a severe system error.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetImsi(void) const;

	/**
	 * Gets the type of SIM card.
	 *
	 * @since	2.1
	 *
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/telephony
	 *
	 * @return		The type of SIM card
	 *
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM	The method cannot proceed due to a severe system error.
	 * @remarks		The specified error code can be accessed using the GetLastResult() method.
	 */
	SimType GetSimType(void) const;

	/**
	 * Checks whether a SIM card is present in the device or not.
	 *
	 * @since	2.0
	 *
	 * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
	 *
	 * @return  @c true if the SIM card is present in the device, @n
	 *          else @c false
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsAvailable(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since		2.1
	 *
	 * @param[in]   rhs An instance of %SimInfo
	 */
	SimInfo& operator =(const SimInfo& rhs);

	/**
	 * Compares the specified instance of %SimInfo with the calling instance.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the values match, @n
	 *				else @c false
	 * @param[in]	rhs 	The other Tizen::Base::Object to compare
	 * @see 		Tizen::Base::Object::Equals()
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since		2.0
	 *
	 * @return  	The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

private:
	_SimInfoImpl* __pSimInfoImpl;

	friend class _SimInfoImpl;
}; // SimInfo

}} // Tizen::Telephony

#endif // _FTEL_SIM_INFO_H_
