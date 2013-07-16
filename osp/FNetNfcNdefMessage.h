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
 * @file    FNetNfcNdefMessage.h
 * @brief   This is the header file for the %NdefMessage class.
 *
 * This header file contains the declarations of the %NdefMessage class.
 */

#ifndef _FNET_NFC_NDEF_MESSAGE_H_
#define _FNET_NFC_NDEF_MESSAGE_H_

#include <FBaseObject.h>
#include <FBaseResult.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
class String;
} }

namespace Tizen { namespace Net { namespace Nfc
{

class _NdefMessageImpl;
class NdefRecord;

/**
 * @class   NdefMessage
 * @brief   This class represents an NDEF message.
 *
 * @since   2.0
 *
 * The %NdefMessage class represents an NDEF message. An NDEF message is composed of 1 or more NDEF records. Therefore,
 * this class has NdefRecord instances and provides the operations to manipulate the list of those instances. These
 * operations are very similar to those of the Tizen::Base::Collection::IList class.
 *
 * If a new NDEF record is inserted, the uniqueness of its payload identifier is checked. This class also provides 
 * methods which convert %NdefMessage to Tizen::Base::ByteBuffer and vice versa.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 */
class _OSP_EXPORT_ NdefMessage
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since       2.0
	 */
	NdefMessage(void);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since       2.0
	 *
	 * @param[in]   value               An instance of %NdefMessage
	 * @remarks     This performs a deep copy.
	 */
	NdefMessage(const NdefMessage& value);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~NdefMessage(void);

	/**
	 * Compares the calling instance with the specified instance.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the specified instance of Tizen::Base::Object is equal to the calling %NdefMessage
	 *              instance, @n
	 *              else @c false
	 * @param[in]   obj                    The object to compare
	 * @remark      Two %NdefMessage instances are equal only if they contain the same NdefRecord instances in the
	 *              same order.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since       2.0
	 *
	 * @return      The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the number of NDEF records in this NDEF message.
	 *
	 * @since       2.0
	 *
	 * @return      The number of NDEF records
	 */
	int GetRecordsCount(void) const;

	/**
	 * Searches for an NdefRecord object in this class. @n
	 * Gets the index of the %NdefRecord object if the record is present.
	 *
	 * @since       2.0
	 *
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OBJ_NOT_FOUND     The specified record is not found.
	 * @remarks     This method verifies the equality of its pointers, but does not check the content of the specified
	 *              record.
	 */
	result IndexOf(const NdefRecord& record, int& index) const;

	/**
	 * Gets the NdefRecord object from the specified location.
	 *
	 * @since       2.0
	 *
	 * @return      The requested NdefRecord object, @n
	 *              else @c null if the index is not valid
	 * @param[in]   index               The index of the NDEF record to get
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the record list. @n
	 *                                  The specified @c index parameter is either greater than or equal to the number
	 *                                  of elements or less than @c 0.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	NdefRecord* GetRecordAt(int index) const;

	/**
	 * Gets the NdefRecord object with the specified payload identifier.
	 *
	 * @since       2.0
	 *
	 * @return      The requested NdefRecord object, @n
	 *              else @c null if no record matches
	 * @param[in]   payloadId           The payload identifier of the NDEF record to get
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OBJ_NOT_FOUND     The specified @c id is not found in any of the NDEF records.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	NdefRecord* GetRecord(const Tizen::Base::String& payloadId) const;

	/**
	 * Appends the specified NDEF record at the end of the last record in the NDEF message.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   record              The NDEF record to append
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_ARG       The specified NDEF record is invalid. @n
	 *                                  For example, the record has the same payload identifier as the other records in
	 *                                  this NDEF message.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @remarks     This method performs a shallow copy. It adds just the pointer, not the NdefRecord instance.
	 */
	result AppendRecord(const NdefRecord& record);

	/**
	 * Inserts the specified NDEF record in the NDEF message at the specified location.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   record              The NDEF record to insert
	 * @param[in]   index               The index at which the NDEF record must be inserted
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the record list. @n
	 *                                  The specified @c index is greater than the number of elements or less than
	 *                                  @c 0.
	 * @exception   E_INVALID_ARG       The specified NDEF record is invalid. @n
	 *                                  For example, the record has the same payload identifier as the other records in
	 *                                  this NDEF message.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @remarks
	 *              - The NDEF records that appear after the insertion point move downwards to accommodate the inserted
	 *                NDEF record.
	 *              - This method performs a shallow copy. It adds just the pointer, not the NdefRecord instance.
	 */
	result InsertRecordAt(const NdefRecord& record, int index);

	/**
	 * Replaces the NDEF record from the specified location with the specified NDEF record.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   record              The NDEF record to set
	 * @param[in]   index               The index at which the NDEF record is set
	 * @param[in]   deallocate          Set to @c true to deallocate the replaced record, @n
	 *                                  else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the record list. @n
	 *                                  The specified @c index is either equal to or greater than the number of
	 *                                  elements or less than @c 0.
	 * @exception   E_INVALID_ARG       The specified NDEF record is invalid. @n
	 *                                  For example, the record has the same payload identifier as the other records in
	 *                                  this NDEF message.
	 * @remarks     This method performs a shallow copy. It adds just the pointer, not the NdefRecord instance.
	 */
	result SetRecordAt(const NdefRecord& record, int index, bool deallocate = false);

	/**
	 * Removes the NDEF record from a specified location.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   index               The index from where the NDEF record is removed
	 * @param[in]   deallocate          Set to @c true to deallocate the record, @n
	 *                                  else @c false
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_OUT_OF_RANGE      The specified index is outside the bounds of the record list. @n
	 *                                  The specified @c index is either equal to or greater than the number of 
	 *                                  elements or less than @c 0.
	 * @remarks     The NDEF records that appear after the deletion point move upwards to occupy the vacated spot.
	 */
	result RemoveRecordAt(int index, bool deallocate = false);

	/**
	 * Removes all the records in the NDEF message. @n
	 * If the specified @c deallocate parameter is set to @c true, it deallocates all the NdefRecord instances in the 
	 * message.
	 *
	 * @since       2.0
	 *
	 * @param[in]   deallocate          Set to @c true to deallocate the record, @n
	 *                                  else @c false
	 */
	void RemoveAllRecords(bool deallocate = false);

	/**
	 * Converts the entire NDEF message with all the NDEF records into a byte sequence as per the NDEF specification.
	 *
	 * @since       2.0
	 *
	 * @return      The NDEF message as a Tizen::Base::ByteBuffer, @n
	 *              else @c null if the conversion fails
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_DATA      The specified NDEF message does not contain any NDEF records.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::ByteBuffer* ToByteBufferN(void) const;

	/**
	 * Gets a new instance of the NDEF message from the specified Tizen::Base::ByteBuffer.
	 *
	 * @since       2.0
	 *
	 * @return      The instance of the created NDEF message, @n
	 *              else @c null if the conversion fails
	 * @param[in]   buffer              An NDEF message as a byte sequence
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_INVALID_FORMAT    The specified @c buffer cannot be formulated to the NDEF message.
	 * @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	 * @exception   E_SYSTEM            A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	static NdefMessage* GetInstanceN(const Tizen::Base::ByteBuffer& buffer);

	/**
	 * Assigns the value of a specified instance to the current instance of %NdefMessage.
	 *
	 * @since       2.0
	 *
	 * @return      A reference to the %NdefMessage instance
	 * @param[in]   rhs                     A reference to the %NdefMessage instance to copy
	 */
	NdefMessage& operator =(const NdefMessage& rhs);

private:
	_NdefMessageImpl* __pImpl;

	friend class _NdefMessageImpl;

}; // NdefMessage

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_NDEF_MESSAGE_H_
