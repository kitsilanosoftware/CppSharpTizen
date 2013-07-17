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
 * @file    FNetNfcNfcTag.h
 * @brief   This is the header file for the %NfcTag class.
 *
 * This header file contains the declarations of the %NfcTag class.
 */

#ifndef _FNET_NFC_NFC_TAG_H_
#define _FNET_NFC_NFC_TAG_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FNetNfcNfcTypes.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
namespace Collection
{
template<class Type> class IListT;
}
} }

namespace Tizen { namespace Net { namespace Nfc
{

class _NfcTagImpl;

/**
 * @class   NfcTag
 * @brief   This class represents the NFC target tag.
 *
 * @since   2.0
 *
 * The %NfcTag class provides information about the detected NFC tag. @n
 * This class has multiple tag types for the target tag. For example, the GetTagTypeList() method returns a list of tag
 * types that include NFC_TAG_TYPE_MIFARE_UL and NFC_TAG_TYPE_FORUM_TYPE_2, because the tag is a Mifare Ultralight tag
 * and it is also an NFC Forum tag type 2.
 *
 * For more information on the class features, see
 * <a href="../org.tizen.native.appprogramming/html/guide/net/nfc.htm">NFC Guide</a>.
 */
class _OSP_EXPORT_ NfcTag
	: public Tizen::Base::Object
{
public:
	/**
	 * Gets the list of the tag types.
	 *
	 * @since       2.0
	 *
	 * @return      The list of the tag types
	 * @remarks     The return list includes single or multiple tags. For example, if the target tag is Mifare
	 *              Ultralight tag type and the NFC Forum tag 2 type, the list includes NFC_TAG_TYPE_MIFARE_UL and
	 *              NFC_TAG_TYPE_FORUM_TYPE_2.
	 */
	const Tizen::Base::Collection::IListT <NfcTagType>* GetTagTypeList(void) const;

	/**
	 * Checks whether the tag has the specified tag type.
	 *
	 * @since       2.0
	 *
	 * @return      @c true if the tag has the specified tag type, @n
	 *              else @c false
	 * @param[in]   type                The tag type to check
	 */
	bool HasTagType(NfcTagType type) const;

	/**
	 * Gets the ID of the tag.
	 *
	 * @since       2.0
	 *
	 * @return      The ID of the tag, @n
	 *              else @c null if the tag has no ID
	 * @remarks     Most tags have an unique ID (UID) or a random ID (RID) that is generated every time when they are
	 *              discovered. Some tags, however, do not have any ID.
	 */
	const Tizen::Base::ByteBuffer* GetId(void) const;

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since       2.0
	 */
	virtual ~NfcTag(void);

private:
	//
	// This default constructor is intentionally declared as private so that only the platform can create an instance.
	//
	NfcTag(void);

	//
	// The implementation of this copy constructor is intentionally blank to prohibit copying of objects.
	//
	NfcTag(const NfcTag& value);

	//
	// The implementation of this copy assignment operator is intentionally blank to prohibit copying of objects.
	//
	NfcTag& operator =(const NfcTag& value);

private:
	_NfcTagImpl* __pImpl;

	friend class _NfcTagImpl;

}; // NfcTag

} } } // Tizen::Net::Nfc

#endif // _FNET_NFC_NFC_TAG_H_
