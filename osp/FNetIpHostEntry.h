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
 * @file		FNetIpHostEntry.h
 * @brief		This is the header file for the %IpHostEntry class.
 *
 * This header file contains the declarations of the %IpHostEntry class.
 */
#ifndef _FNET_IP_HOST_ENTRY_H_
#define _FNET_IP_HOST_ENTRY_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FBaseString.h>
#include <FBaseColIList.h>
#include <FNetSockSocketTypes.h>

namespace Tizen { namespace Net
{
class _IpHostEntryImpl;

/**
 * @class	IpHostEntry
 * @brief	This class encapsulates the Internet host address information.
 *
 * @since	2.0
 *
 *  The %IpHostEntry class associates a Domain Name %System (DNS) host name with a list of aliases and matching IP addresses. If the specified host has
 *  multiple entries in the DNS database, %IpHostEntry contains multiple IP addresses and aliases. The %IpHostEntry class is used as a helper class
 *	with the Dns class.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/domain_name_system_access.htm">Domain Name System Access</a>.
 *
 * The following example demonstrates how to use the %IpHostEntry class.
 *
 * @code
class MyDnsListener
    : public IDnsEventListener
{
public:
    void OnDnsResolutionCompletedN(IpHostEntry* ipHostEntry, result r);
};


void
MyDnsListener::OnDnsResolutionCompletedN(IpHostEntry* ipHostEntry, result r)
{
	if (ipHostEntry == null)
	{
		AppLog("error case no.%d \n", r);
	}
	else
	{
		Tizen::Base::Collection::IList* addressList = ipHostEntry->GetAddressList();

		if (addressList != null)
		{
			int count = addressList->GetCount();

			for (int i = 0; i < count; i++)
			{
				IpAddress* pIpAddress = (IpAddress*)(addressList->GetAt(i));
				Tizen::Base::ByteBuffer*_pbb = Tizen::Base::Utility::StringUtil::StringToUtf8N(pIpAddress->ToString());

				AppLog("IpAddress no.%d : %s\n", i, (char*)(_pbb->GetPointer()));
				delete _pbb;
			}
		}

		Tizen::Base::Collection::IList* aliasList = ipHostEntry->GetAliasList();

		if (aliasList != null)
		{
			int count = aliasList->GetCount();

			for (int i = 0; i < count; i++)
			{
				String* alias = (String*)(aliasList->GetAt(i));
				Tizen::Base::ByteBuffer*_pbb = Tizen::Base::Utility::StringUtil::StringToUtf8N(*alias);

				AppLog("alias no.%d : %s\n", i, (char*)(_pbb->GetPointer()));
				delete _pbb;
			}
		}
		delete ipHostEntry;
	}
}
 * @endcode
 */
class _OSP_EXPORT_ IpHostEntry
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since			2.0
	 */
	virtual ~IpHostEntry(void);

public:
	/**
	 * Gets the IP address list of a domain name.
	 *
	 * @since		2.0
	 *
	 * @return		An IEnumerator whose element is of the type IpAddress*, @n
	 *				else @c null if the object is not constructed or addressList is not set
	 */
	Tizen::Base::Collection::IList* GetAddressList(void) const;

	/**
	 * Gets the alias list of a domain name.
	 *
	 * @since			2.0
	 *
	 * @return			An IEnumerator whose element is of the type String*, @n
	 *					else @c null if the object is not constructed or aliasList is not set
	 */
	Tizen::Base::Collection::IList* GetAliasList(void) const;

private:
	/*
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 */
	IpHostEntry(void);

	/*
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	value		An instance of %IpHostEntry
	 */
	IpHostEntry(const IpHostEntry& value);

	/*
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %IpHostEntry
	 */
	IpHostEntry& operator =(const IpHostEntry& rhs);

private:
	_IpHostEntryImpl* __pIpHostEntryImpl;

	friend class _IpHostEntryImpl;
}; // IpHostEntry

} } //Tizen::Net

#endif // _FNET_IP_HOST_ENTRY_H_
