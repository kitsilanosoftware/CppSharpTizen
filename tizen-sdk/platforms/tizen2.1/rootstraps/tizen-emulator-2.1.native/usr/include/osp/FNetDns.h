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
 * @file		FNetDns.h
 * @brief		This is the header file for the %Dns class.
 *
 * This header file contains the declarations of the %Dns class.
 */
#ifndef _FNET_DNS_H_
#define _FNET_DNS_H_

#include <FBaseResult.h>
#include <FNetIpAddress.h>
#include <FNetIpHostEntry.h>
#include <FNetNetConnection.h>
#include <FNetIDnsEventListener.h>

namespace Tizen { namespace Net
{
class _DnsImpl;

/**
 * @class	Dns
 * @brief	This class provides a way to access the resolver of the Domain Name %System.
 *
 * @since	2.0
 *
 * The %Dns class represents a request for information from a DNS server. A DNS request can be one of two types, represented by the GetHostByAddress()
 *			and GetHostByName() methods. The %GetHostByAddress() method represents a request for the DNS information about a host, while the %GetHostByName()
 *			method represents a request for the DNS host information for an IP address. Both requests can be made in an asynchronous mode.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/domain_name_system_access.htm">Domain Name System Access</a>.
 *
 * The following example demonstrates how to use the %Dns class.
 *
 * @code
 *
 *	#include <FBase.h>
 *	#include <FNet.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *	using namespace Tizen::Net;
 *
 *	class MyClass
 *	  : public Object
 *	  , public IDnsEventListener
 *	{
 *	   public:
 *		  MyClass(void) {}
 *		  ~MyClass(void) {}
 *
 *		  // IDnsEventListener
 *		  void OnDnsResolutionCompletedN(IpHostEntry* pIpHostEntry, result r);
 *
 *		  void GetHostByName(void);
 *	};
 *
 *	void
 *	MyClass::OnDnsResolutionCompletedN(IpHostEntry* pIpHostEntry, result r)
 *	{
 *		if (pIpHostEntry == null)
 *		{
 *			return;
 *		}
 *
 *		IList* pAddressList = pIpHostEntry->GetAddressList();
 *		if (pAddressList != null)
 *		{
 *			int count = pAddressList->GetCount();
 *
 *			for (int i = 0; i<count; i++)
 *			{
 *				IpAddress* pIpAddress = (IpAddress*)(pAddressList->GetAt(i));
 *				AppLog("IpAddress no.%d = [%ls]\n", i, pIpAddress->ToString().GetPointer());
 *			}
 *		}
 *
 *		IList* pAliasList = pIpHostEntry->GetAliasList();
 *		if (pAliasList != null)
 *		{
 *			int count = pAliasList->GetCount();
 *
 *			for (int i = 0; i<count; i++)
 *			{
 *				String* pAlias = (String*)(pAliasList->GetAt(i));
 *				AppLog("Alias no.%d = [%ls]\n", i, pAlias->GetPointer());
 *			}
 *		}
 *
 *		delete pIpHostEntry;
 *	}
 *
 *	void
 *	MyClass::GetHostByName(void)
 *	{
 *		Dns* pDns = new Dns();
 *		result r = pDns->Construct(*this);
 *		if (IsFailed(r))
 *		{
 *			delete pDns;
 *			return;
 *		}
 *
 *		r = pDns->GetHostByName(L"www.tizen.org");
 *
 *		// Wait OnDnsResolutionCompletedN() event
 *
 *		delete pDns;
 *	}
 *
 * @endcode
 */
class _OSP_EXPORT_ Dns
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	Dns(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since			2.0
	 */
	virtual ~Dns(void);

	/**
	 * Initializes this instance of %Dns with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	netConnection			A NetConnection on which the DNS request executes
	 * @param[in]	listener				A reference to IDnsEventListener
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c netConnection contains an invalid value.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, @n
	 * 										because the caller thread is a worker thread.
	 */
	result Construct(const NetConnection& netConnection, IDnsEventListener& listener);

	/**
	 * Initializes this instance of %Dns with the specified @c listener.
	 *
     * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	listener				A reference to IDnsEventListener
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, @n
	 * 										because the caller thread is a worker thread.
	 */
	result Construct(IDnsEventListener& listener);

public:
	/**
	 * Requests a DNS lookup by host name. @n
	 * The %GetHostByName() method is asynchronous.
	 *
	 * @since		2.0
	 *
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/dns
	 *
	 * @return		An error code
	 * @param[in]	hostName				The DNS name of the host
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
	 * @exception	E_CONNECTION_FAILED		The network connection has failed.
	 * @exception	E_OPERATION_FAILED		Requested but an error is received while waiting for the response.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		Only one query is processed at a time in this instance.
	 *              Multiple queries may be discarded.
	 */
	result GetHostByName(const Tizen::Base::String& hostName);

	/**
	 * Requests a DNS lookup by IP address. @n
	 * The %GetHostByAddress() method is asynchronous.
	 *
	 * @since		2.0
	 *
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/dns
	 *
	 * @return		An error code
	 * @param[in]	ipAddress				An IP address
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 * @exception	E_INVALID_CONNECTION	The network connection is invalid.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception	E_NETWORK_UNAVAILABLE	The network is unavailable.
	 * @exception	E_CONNECTION_FAILED		The network connection has failed.
	 * @exception	E_OPERATION_FAILED		Requested but an error is received while waiting for the response.
	 * @exception	E_SYSTEM				An internal error has occurred.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_USER_NOT_CONSENTED	The user blocks an application from calling this method. @b Since: @b 2.1
	 * @remarks		Only one query is processed at a time in this instance.
	 *              Multiple queries may be discarded.
	 */
	result GetHostByAddress(const IpAddress& ipAddress);

private:
	/*
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %Dns
	 */
	Dns(const Dns& rhs);

	/*
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %Dns
	 */
	Dns& operator =(const Dns& rhs);

private:
	_DnsImpl* __pDnsImpl;

	friend class _DnsImpl;
}; // Dns

} } //Tizen::Net

#endif // _FNET_DNS_H_
