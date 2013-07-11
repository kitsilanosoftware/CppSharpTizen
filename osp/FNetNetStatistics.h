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
 * @file		FNetNetStatistics.h
 * @brief		This is the header file for the %NetStatistics class.
 *
 * This header file contains the declarations of the %NetStatistics class.
 */
#ifndef _FNET_NET_STATISTICS_H_
#define _FNET_NET_STATISTICS_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FNetNetTypes.h>
#include <FNetNetAccountInfo.h>

namespace Tizen { namespace Net
{
class _NetStatisticsImpl;

/**
 * @class	NetStatistics
 * @brief	This class represents the statistical information on the Packet-Switched (PS) data call.
 *
 * @since	2.0
 *
 * @remarks	The %NetStatistics class cannot be tested on the emulator.
 *
 * The %NetStatistics class provides methods for getting the statistical information on the Packet-Switched (PS) data call.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/network_statistics.htm">Network Statistics</a>.
 */
class _OSP_EXPORT_ NetStatistics
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	NetStatistics(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~NetStatistics(void);

	/**
	 * Initializes this instance of %NetStatistics.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 */
	result Construct(void);

public:
	/**
	 * Gets the statistical information. @n
	 * This can consist of details such as the call duration, the sent and received size, and so on.
	 *
	 * @since			2.0
	 * @privilege		%http://tizen.org/privilege/network.statistics.read
	 *
	 * @return			The number of bytes sent or received, @n
	 *					else @c INVALID_HANDLE if an error occurs
	 * @param[in]		bearerType			The bearer type of the data call operation @n
	 *										NET_BEARER_WIFI_DIRECT and NET_BEARER_USB are not supported.
	 * @param[in]		netStatType			The type of statistical information to get
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 */
	long long GetNetStatisticsInfo(NetBearerType bearerType, NetStatisticsInfoType netStatType) const;

	/**
	 * Resets the specified statistical information on the network according to the operation mode.
	 *
	 * @since		2.0
	 * @privilege	%http://tizen.org/privilege/network.statistics.write
	 *
	 * @return		An error code
	 * @param[in]	bearerType			The bearer type (OperationMode) whose statistical information is reset @n NET_BEARER_WIFI_DIRECT and NET_BEARER_USB are not supported.
	 * @param[in]	netStatType			The type of statistical information to reset
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @remarks		This method must use warning pop-up for user notification.
	 * @see			GetNetStatisticsInfo()
	 */
	result Reset(NetBearerType bearerType, NetStatisticsInfoType netStatType);

	/**
	 * Resets all the specified statistical information on the network according to the operation mode.
	 *
	 * @since		2.0
	 * @privilege	%http://tizen.org/privilege/network.statistics.write
	 *
	 * @return		An error code
	 * @param[in]	bearerType			The bearer type (OperationMode) whose statistical information would be reset @n NET_BEARER_WIFI_DIRECT and NET_BEARER_USB are not supported.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 *
	 * @remarks		This method must use warning pop-up for user notification.
	 * @see			GetNetStatisticsInfo()
	 */
	result ResetAll(NetBearerType bearerType);

private:
	/*
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %NetStatistics
	 */
	NetStatistics(const NetStatistics& rhs);

	/*
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %NetStatistics
	 */
	NetStatistics& operator =(const NetStatistics& rhs);

private:
	_NetStatisticsImpl* __pNetStatisticsImpl;

	friend class _NetStatisticsImpl;
}; // NetStatistics

} } //Tizen::Net
#endif // _FNET_NET_STATISTICS_H_
