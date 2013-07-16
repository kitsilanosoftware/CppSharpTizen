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
 * @file    FTelCallInfo.h
 * @brief   This is the header file for the %CallInfo class.
 *
 * This header file contains the declarations of the %CallInfo class.
 */
#ifndef _FTEL_CALL_INFO_H_
#define _FTEL_CALL_INFO_H_

#include <FBase.h>
#include <FTelTypes.h>

namespace Tizen { namespace Telephony
{
class _CallInfoImpl;

/**
 * @class   CallInfo
 * @brief   This class provides methods to obtain detailed information about a call.
 *
 * @since   2.0
 *
 * The %CallInfo class provides methods to obtain detailed call information, such as the call type and number.
 */
class _OSP_EXPORT_ CallInfo
	: public Tizen::Base::Object
{
public:
	/**
     * This is the default constructor for this class.
     *
     * @since   2.0
     */
	CallInfo(void);

	/**
     * Copying of objects using this copy constructor is allowed.
     *
     * @since   2.0
     *
     * @param[in] rhs The call information
     */
	CallInfo(const CallInfo& rhs);

	/**
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since   2.0
     */
	virtual ~CallInfo(void);

	/**
     * Gets the call type.
     *
     * @since   2.0
     *
     * @return  The current call type
     */
	CallType GetCallType(void) const;

	/**
     * Gets the correspondent's phone number.
     *
     * @since   2.0
	 *
     * @return  The phone number
     * @remarks This information is valid only for an incoming event.
     */
	Tizen::Base::String GetNumber(void) const;

	/**
    * Checks whether the specified instance of %CallInfo equals the current instance.
    *
    * @since    2.0
	*
    * @return   @c true if the specified instance equals the current instance, @n
    *           else @c false
    * @param[in]    obj An instance of %CallInfo
    * @remarks This method returns @c false if the specified object is not %CallInfo.
    */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
     * Gets the hash value of the current instance.
     *
     * @since   2.0
     *
     * @return  The hash value of the current instance
     */
	virtual int GetHashCode(void) const;

	/**
     * Copying of objects using this copy assignment operator is allowed.
     *
     * @since 2.0
     *
     * @return  The reference of this instance
     * @param[in]   rhs   An instance of %CallInfo to copy
     */
	CallInfo& operator=(const CallInfo& rhs);

private:
	/**
     * This constructor is intentionally declared as private so that only the platform can create an instance.
     *
     * @param[in]   type   The call type
     * @param[in]   number The phone number @n
     */
	CallInfo(CallType type, const Tizen::Base::String& number);

private:
	_CallInfoImpl* __pCallInfoImpl;

	friend class _CallInfoImpl;
}; // CallInfo

} } // Tizen::Telephony
#endif // _FTEL_CALL_INFO_H_
