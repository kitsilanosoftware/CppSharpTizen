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
 *	result
 *	MyClass::GetSimInfo(void)
 *	{
 *		int mnc;
 *		int mcc;
 *		bool isAvailable;
 *		String spn;
 *		String iccId;
 *		String operatorName;
 *
 *		SimInfo* pSimInfo = new SimInfo();
 *
 *		result r = pSimInfo->Construct();
 *		if (IsFailed(r))
 *		{
 *			delete pSimInfo;
 *			return r;
 *		}
 *
 *		mnc = pSimInfo->GetMnc();
 *		mcc = pSimInfo->GetMcc();
 *		spn = pSimInfo->GetSpn();
 *		iccId = pSimInfo->GetIccId();
 *		operatorName = pSimInfo->GetOperatorName();
 *		isAvailable = pSimInfo->IsAvailable();
 *
 *		delete pSimInfo;
 *		return E_SUCCESS;
 *	}
 *
 * @endcode
 */
class _OSP_EXPORT_ SimInfo
	: public Tizen::Base::Object
{
public:
	/**
     * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
     *
     * @since	2.0
     */
	SimInfo(void);

	/**
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since	2.0
     */
	virtual ~SimInfo(void);

	/**
     * Initializes this instance of %SimInfo.
     *
     * @since	2.0
	 *
     * @return	An error code
     * @exception	E_SUCCESS	The method is successful.
     * @exception	E_SYSTEM	A system error has occurred.
     * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
     */
	result Construct(void);

	/**
     * Gets the Mobile Network Code (MNC) of the SIM International Mobile Subscriber Identity (IMSI) information.
     *
     * @since	2.0
	 *
     * @privilege   %http://tizen.org/privilege/systeminfo
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
     * @privilege   %http://tizen.org/privilege/systeminfo
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
     * @privilege   %http://tizen.org/privilege/systeminfo
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
     * This method provides a unique identification number for the SIM card.
     *
     * @since	2.0
	 *
     * @privilege   %http://tizen.org/privilege/systeminfo
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
     * @privilege   %http://tizen.org/privilege/systeminfo
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
     * @privilege   %http://tizen.org/privilege/systeminfo
     *
     * @return      The phone number of the SIM card, @n
     *              else an empty string if there is no SIM card in the device, or if a Mobile Station International Subscriber Directory Number
     *              (MSISDN) is not assigned to the SIM card
     * @exception	E_SUCCESS    The method is successful.
     * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     * @exception	E_SYSTEM	A system error has occurred.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
	Tizen::Base::String GetPhoneNumber(void) const;

	/**
     * Checks whether a SIM card is present in the device or not.
     *
     * @since	2.0
	 *
     * @privilege   %http://tizen.org/privilege/systeminfo
     *
     * @return  @c true if the SIM card is present in the device, @n
     *          else @c false
     * @exception	E_SUCCESS	The method is successful.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
	bool IsAvailable(void) const;

private:
	/**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]   rhs   An instance of %SimInfo
     */
	SimInfo(const SimInfo& rhs);

	/**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]   rhs An instance of %SimInfo
     */
	SimInfo& operator =(const SimInfo& rhs);

private:
	_SimInfoImpl* __pSimInfoImpl;

	friend class _SimInfoImpl;
}; // SimInfo

}} // Tizen::Telephony
#endif // _FTEL_SIM_INFO_H_
