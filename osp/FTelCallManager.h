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
 * @file  FTelCallManager.h
 * @brief This is the header file for the %CallManager class.
 *
 * This header file contains the declarations of the %CallManager class.
 */
#ifndef _FTEL_CALL_MANAGER_H_
#define _FTEL_CALL_MANAGER_H_


#include <FBase.h>
#include <FTelTypes.h>
#include <FTelCallInfo.h>
#include <FTelITelephonyCallEventListener.h>



namespace Tizen { namespace Telephony
{
class _CallManagerImpl;

/**
 * @class	CallManager
 * @brief	This class provides methods to obtain information about the current call.
 *
 * @since	2.0
 *
 * The %CallManager class provides methods to obtain information about the current call type and its status.
 *
 * The following example demonstrates how to use the %CallManager class to obtain information about a call.
 *
 * @code
 *
 *	result
 *	MyClass::GetCallInfo(void)
 *	{
 *		CallType callType = TYPE_UNDEFINED_CALL;
 *		CallStatus callStatus = CALL_STATUS_UNDEFINED;
 *
 *		CallManager* pCallManager = new CallManager();
 *
 *		result r = pCallManager->Construct(*this);
 *		if (IsFailed(r))
 *		{
 *			delete pCallManager;
 *			return r;
 *		}
 *
 *		callStatus = pCallManager->GetCurrentCallStatus();
 *
 *		if (callStatus == CALL_STATUS_COMMUNICATING)
 *		{
 *			callType = pCallManager->GetCurrentCallType();
 *		}
 *
 *		delete pCallManager;
 *		return E_SUCCESS;
 *	}
 *
 *	void
 *	MyClass::OnTelephonyCallStatusChangedN(CallStatus  callStatus,CallInfo *  pCallInfo)
 *	{
 *		CallType	callType;
 *		String		number;
 *
 *		if (callStatus == CALL_STATUS_RINGING)
 *		{
 *			callType  = pCallInfo->GetCallType();
 *			number = pCallInfo->GetNumber();
 *		}
 *
 *		delete pCallInfo;
 *	}
 *
 *
 * @endcode
 */
class _OSP_EXPORT_ CallManager
	: public Tizen::Base::Object
{
public:
	/**
     * 	 The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
     *
     * @since   2.0
     */
	CallManager(void);

	/**
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since   2.0
     */
	virtual ~CallManager(void);

	/**
     * Initializes a new instance of this class. @n
     * This is the two phase construction.
     *
     * @since   2.0
	 *
     * @return  An error code
     * @exception   E_SUCCESS 		The method is successful.
     * @exception   E_SYSTEM  		A system error has occurred.
     */
	result Construct(void);

	/**
     * Initializes a new instance of this class. @n
     * This is the two phase construction.
     *
     * @since   2.0
	 *
     * @return  An error code
     * @param[in]   listener  The listener for change in status of a call
     * @exception   E_SUCCESS The method is successful.
     * @exception   E_SYSTEM  A system error has occurred.
     * @see ITelephonyCallEventListener
     */
	result Construct(ITelephonyCallEventListener& listener);

	/**
     * Gets the call type of the current call.
     *
     * @since			2.0
	 *
     * @return      The current call type, @n
     *              else Telephony::TYPE_UNDEFINED_CALL if the method fails
     */
	CallType GetCurrentCallType(void) const;

	/**
     * Gets the call status of the current call.
     *
     * @since			2.0
	 *
     * @return      The current call status, @n
     *              else Telephony::CALL_STATUS_UNDEFINED if the method fails
     */
	CallStatus GetCurrentCallStatus(void) const;

private:
	/**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]	rhs	An instance of %CallManager
     */
	CallManager(const CallManager& rhs);

	/**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     *
     * @param[in]	rhs	An instance of %CallManager
     */
	CallManager& operator =(const CallManager& rhs);

private:
	_CallManagerImpl* __pCallManagerImpl;

	friend class _CallManagerImpl;
}; // CallManager

} } // Tizen::Telephony
#endif // _FTEL_CALL_MANAGER_H_
