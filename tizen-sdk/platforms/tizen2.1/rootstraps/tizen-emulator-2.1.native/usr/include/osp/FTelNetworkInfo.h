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
 * @file	FTelNetworkInfo.h
 * @brief	This is the header file for the %NetworkInfo class.
 *
 * This header file contains the declarations of the %NetworkInfo class.
 */
#ifndef _FTEL_NETWORK_INFO_H_
#define _FTEL_NETWORK_INFO_H_


#include <FBase.h>


namespace Tizen { namespace Telephony
{
class _NetworkInfoImpl;

/**
 * @class	NetworkInfo
 * @brief	This class provides information of the current network.
 *
 * @since	2.0
 *
 * The %NetworkInfo class provides methods to get information of the current network such as MNC, MCC, PLMN, cell ID, and operator name.
 *
 * The following example demonstrates how to use the %NetworkInfo class to get the network information.
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
 *  {
 *  public:
 *  	MyClass(void) {}
 *  	~MyClass(void) {}
 *
 *  	void GetNetworkInfo(void);
 *  };
 *
 *  void
 *  MyClass::GetNetworkInfo(void)
 *  {
 *  	result r = E_SUCCESS;
 *  	int mnc;
 *  	int mcc;
 *  	int cellId;
 *  	int lac;
 *  	String plmn;
 *  	String operatorName;
 *
 *  	NetworkInfo networkInfo;
 *  	NetworkManager* pNetworkManager = new (std::nothrow) NetworkManager();
 *
 *  	r = pNetworkManager->Construct(null);
 *  	if (IsFailed(r))
 *  	{
 *  		delete pNetworkManager;
 *  		return;
 *  	}
 *
 *  	r = pNetworkManager->GetNetworkInfo(networkInfo);
 *  	if (IsFailed(r))
 *  	{
 *  		delete pNetworkManager;
 *  		return;
 *  	}
 *
 *  	mnc = networkInfo.GetMnc();
 *  	mcc = networkInfo.GetMcc();
 *  	cellId = networkInfo.GetCellId();
 *  	lac = networkInfo.GetLac();
 *  	plmn = networkInfo.GetPlmn();
 *  	operatorName = networkInfo.GetOperatorName();
 *
 *  	delete pNetworkManager;
 *  }
 *
 * @endcode
 */
class _OSP_EXPORT_ NetworkInfo
	: public Tizen::Base::Object
{
public:
	/**
     * This is the default constructor for this class.
     *
     * @since   2.0
     */
	NetworkInfo(void);

	/**
     * Copying of objects using this copy constructor is allowed.
     *
     * @since 2.0
     *
     * @param[in]   rhs   An instance of %NetworkInfo
     */
	NetworkInfo(const NetworkInfo& rhs);

	/**
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since	2.0
     */
	virtual ~NetworkInfo(void);

	/**
     * Gets the Mobile Network Code (MNC) of the network.
     *
     * @since   2.0
     * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
     *
     * @return		The MNC of the network
     * @exception	E_SUCCESS	The method is successful.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
	int GetMnc(void) const;

	/**
     * Gets the Mobile Country Code (MCC) of the network.
     *
     * @since   2.0
     * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
     *
     * @return		The MCC of the network
     * @exception	E_SUCCESS	The method is successful.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
	int GetMcc(void) const;

    /**
     * Gets the Public Land Mobile Network (PLMN).
     *
     * @since   2.0
     * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
     *
     * @return		The PLMN name
     * @exception	E_SUCCESS	        The method is successful.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
	Tizen::Base::String GetPlmn(void) const;


    /**
     * @page    CompNetworkInfoGetPlmnPage Compatibility for GetPlmn()
     * @section CompNetworkInfoGetPlmnPageIssueSection Issues
     *          Implementation of this method in Tizen API versions prior to 2.1 has the following issue: @n
     *          -# The method returns an alphabetic name of PLMN.
     *
     * @section CompNetworkInfoGetPlmnPageSolutionSection Resolutions
     *          -# The method returns a numeric name of PLMN-ID(MCC+MNC).
     *           To get the alphabetic name of PLMN, it is recommended to use Tizen::Telephony::GetOperatorName().
     */

    /**
     * Gets the current cell ID.
     *
     * @since   2.0
     * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
     *
     * @return		The current cell ID
     * @exception	E_SUCCESS	The method is successful.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     * @remarks     This cell ID is provided using only NetworkManager::GetNetworkInfo() when connected to a network.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
	int GetCellId(void) const;

	/**
     * Gets the current Location Area Code (LAC).
     *
     * @since   2.0
     * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
     *
     * @return		The current LAC
     * @exception	E_SUCCESS	The method is successful.
     * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
     * @remarks     This LAC is provided using only NetworkManager::GetNetworkInfo() when connected to a network.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
	int GetLac(void) const;

    /**
     * Gets the operator name.
     *
     * @since 2.0
     * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
     *
     * @return      The operator name
     * @exception   E_SUCCESS   The method is successful.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @remarks		The specific error code can be accessed using the GetLastResult() method.
     */
    Tizen::Base::String GetOperatorName(void) const;

    /**
     * Checks whether the specified instance of %NetworkInfo equals the current instance.
     *
     * @since   2.0
	 *
     * @return  @c true if the specified instance equals the current instance, @n
     *          else @c false
     * @param[in]   rhs An instance of %NetworkInfo
     * @remarks     The method returns @c false if the specified object is not %NetworkInfo.
     */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
     * Gets the hash value of the current instance.
     *
     * @since   2.0
     *
     * @return  The hash value of the current instance
     */
	virtual int GetHashCode(void) const;

	/**
     * Gets the received signal strength indication of a modem device.
     *
     * @since   2.0
     * @privlevel	public
     * @privilege   %http://tizen.org/privilege/telephony @n
     * 				(%http://tizen.org/privilege/systeminfo is deprecated.)
	 * @feature		%http://tizen.org/feature/network.telephony
     * @return  The current RSSI @n
     *          The possible RSSI value ranges from @c 0 to @c 100.
     * @exception   E_SUCCESS   The method is successful.
     * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     * @exception   E_SYSTEM    A system error has occurred.
	 * @exception  E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature. @b Since: @b 2.1
	 * 										 For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	 * @remarks
	 *			- The specific error code can be accessed using the GetLastResult() method.
	 *			- Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
     */
	static int GetRssi(void);

	/**
      * Copying of objects using this copy assignment operator is allowed.
      *
      * @since 2.0
      *
      * @return     The reference of this instance
      * @param[in]  rhs   An instance of %NetworkInfo
      */
	NetworkInfo& operator=(const NetworkInfo& rhs);

private:
	_NetworkInfoImpl* __pNetworkInfoImpl;

	friend class _NetworkInfoImpl;
}; // NetworkInfo

}} //Tizen::Telephony
#endif // _FTEL_NETWORK_INFO_H_
