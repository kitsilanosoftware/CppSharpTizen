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
 * @file    FNetNfcTagConnection.h
 * @brief   This is the header file for the %TagConnection class.
 *
 * This header file contains the declarations of the %TagConnection class.
 */

#ifndef _FNET_NFC_TAG_CONNECTION_H_
#define _FNET_NFC_TAG_CONNECTION_H_

#include <FBaseObject.h>
#include <FBaseResult.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
} }

namespace Tizen { namespace Net { namespace Nfc
{

// Forward declaration
class NfcTag;
class _TagConnectionImpl;
class ITagConnectionListener;

/**
 * @class   TagConnection
 * @brief   This class represents the connection with an NFC tag. It provides the mechanism to communicate with the NFC
 *          tag through ISO14443 or a general Radio Frequency Identification (RFID) manner.
 *
 * @since   2.0
 *
 * The %TagConnection class represents the connection with an NFC tag. It provides the mechanism to communicate with the NFC tag
 * through ISO14443 or a general Radio Frequency Identification (RFID) manner. @n
 * The class has an NfcTag instance that represents the target tag. This class can be inherited by the
 * NdefTagConnection class if the target tag supports the NFC Data Exchange Format (NDEF) operations.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 *
 * The following example demonstrates how to use the %TagConnection class.
 *
 * @code
 * // MyClass.h
 * #include <FNet.h>
 *
 * class MyClass
 * 	: public Tizen::Net::Nfc::INfcManagerEventListener
 * 	, public Tizen::Net::Nfc::INfcTagDiscoveryEventListener
 * 	, public Tizen::Net::Nfc::ITagConnectionListener
 * {
 * public:
 * 	// Method declarations are hidden for the sake of simplicity.
 *
 * private:
 * 	Tizen::Net::Nfc::NfcManager*      __pNfcManager;
 * 	Tizen::Net::Nfc::TagConnection*   __pConnection;
 * };
 *
 * // MyClass.cpp
 * #include "MyClass.h"
 *
 * using namespace Tizen::Net::Nfc;
 *
 * MyClass::MyClass(void)
 * 	: __pNfcManager(null)
 * 	, __pConnection(null)
 * {
 * 	__pNfcManager = new NfcManager();
 * }
 *
 * MyClass::~MyClass(void)
 * {
 * 	// Removes the tag discovery event listener for the ISO14443-4 tag type.
 * 	__pNfcManager->RemoveTagDiscoveryEventListener(*this, NFC_TAG_TYPE_ISO14443_4);
 *
 * 	delete __pNfcManager;
 * }
 *
 * void
 * MyClass::SendApduCommandSample(void)
 * {
 * 	// Creates an instance of NfcManager and registers the manager event listener
 * 	__pNfcManager->Construct(*this);
 *
 * 	// Adds the tag discovery event listener for the ISO14443-4 tag type
 * 	__pNfcManager->AddTagDiscoveryEventListener(*this, NFC_TAG_TYPE_ISO14443_4);
 * }
 *
 * // This method is invoked when a new ISO14443-4 tag like a Mifare DESFire is detected
 * void
 * MyClass::OnNfcTagDetectedN(TagConnection* pConnection)
 * {
 * 	// Checks whether the connection supports ISO14443-4,
 * 	// but the evaluation result of the below code is always true in this example
 * 	if (pConnection->GetTargetTag()->HasTagType(NFC_TAG_TYPE_ISO14443_4))
 * 	{
 * 		__pConnection = pConnection;
 *
 * 		// Registers the tag connection listener
 * 		__pConnection->SetTagConnectionListener(this);
 *
 * 		Tizen::Base::ByteBuffer command;
 * 		// Makes an APDU(ISO7816-4) command here
 *
 * 		__pConnection->SendCommand(command);
 * 	}
 * }
 *
 * // This method is invoked when the target tag is lost
 * void
 * MyClass::OnNfcTagLost(void)
 * {
 * 	// The acquired TagConnection should be deallocated
 * 	delete __pConnection;
 * }
 *
 * // This method is invoked when the response of the command is received
 * void
 * MyClass::OnNfcResponseReceivedN(Tizen::Base::ByteBuffer* pResponse, result r)
 * {
 * 	if (r == E_SUCCESS)
 * 	{
 * 		// Uses the response data here
 *
 * 		// Deallocates the response data
 * 		delete pResponse;
 * 	}
 * }
 * @endcode
 */
class _OSP_EXPORT_ TagConnection
	: public Tizen::Base::Object
{
public:
	/**
	 * Checks whether the connection supports the NDEF message operations.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the connection supports the NDEF message operations, @n
	 *              else @c false
	 */
	virtual bool IsNdefConnection(void) const;

	/**
	 * Gets the target tag object with which this connection is established.
	 *
	 * @since       2.0
	 *
	 * @return      The tag object
	 */
	const NfcTag* GetTargetTag(void) const;

	/**
	 * Sets a listener for receiving the response of the command sent on this tag connection.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   pListener           The listener to be added
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     Only one event listener can be registered. If the input parameter is @c null, the listener that is
	 *              already registered gets unregistered.
	 */
	result SetTagConnectionListener(ITagConnectionListener* pListener);

	/**
	 * Sends the specified command to the target tag.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   command             The command to be sent
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       The input @c command is invalid.
	 * @exception   E_IN_PROGRESS       The previous send request is in progress.
	 * @exception   E_CONNECTION_BUSY   The connection is busy. Therefore, the method cannot process the send request.
	 * @exception   E_CONNECTION_FAILED The connection to the tag is closed or it has failed.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @see         ITagConnectionListener::OnNfcResponseReceivedN()
	 */
	result SendCommand(const Tizen::Base::ByteBuffer& command);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~TagConnection(void);

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This is the default constructor for this class.
	//
	// @since       2.0
	//
	TagConnection(void);

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void TagConnection_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void TagConnection_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since       2.0
	//
	virtual void TagConnection_Reserved3(void) {}

private:
	/*
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]   value					An instance of %TagConnection
	 */
	TagConnection(const TagConnection& value);

	/*
	 * The implementation of this copy assignment operator is intentionally blank
	 * and declared as private to prohibit copying of objects.
	 *
	 * @param[in]   value					An instance of %TagConnection
	 */
	TagConnection& operator =(const TagConnection& value);

protected:
	//
	// This variable is for internal use only. Using this variable can cause behavioral,
	// security-related, and consistency-related issues in the application.
	//
	// The point for indicating the implementation object.
	//
	// @since       2.0
	//
	_TagConnectionImpl* _pImpl;

	friend class _TagConnectionImpl;

}; // TagConnection

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_TAG_CONNECTION_H_
