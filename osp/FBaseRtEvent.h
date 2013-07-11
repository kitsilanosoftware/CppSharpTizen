//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FBaseRtEvent.h
 * @brief	This is the header file for the %Event class.
 *
 * This file contains the declarations of the %Event class.
 */

#ifndef _FBASE_RT_EVENT_H_
#define _FBASE_RT_EVENT_H_

#include <FBaseObject.h>

namespace Tizen { namespace Base { namespace Runtime
{

class IEventArg;
class IEventListener;
/**
* @class Event
* @brief This class provides methods for delivering an event with an argument synchronously and asynchronously.
* @since 2.0
*
* @code
*
* #include <FBase.h>
*
* using namespace Tizen::Base::Runtime;
*
* class MyEventArg : public IEventArg
* {
* public:
* 	MyEventArg(int t);
* 	int type;
* };
*
* MyEventArg::MyEventArg(int t)
* {
* 	type = t;
* }
*
* class MyEventListener : public IEventListener
* {
* public:
* 	void OnEventReceived(const IEventArg& arg);
* };
*
* void
* MyEventListener::OnEventReceived(const IEventArg& arg)
* {
* 	const MyEventArg* myarg = dynamic_cast<const MyEventArg*> (&arg);
* }
*
* class MyEvent : public Event
* {
* protected:
*     virtual void FireImpl(IEventListener& listener, const IEventArg& arg);
* };
*
* void
* MyEvent::FireImpl(IEventListener& listener, const IEventArg& arg)
* {
* 	MyEventListener* plistener = dynamic_cast<MyEventListener*> (&listener);
* 	plistener->OnEventReceived(arg);
* }
*
* void
* MyApplication::Test Code(void)
* {
* 	MyEventListener* mylistener = new MyEventListener();
* 	MyEvent* my = new MyEvent();
* 	MyEventArg* myarg = new MyEventArg(3);
* 	my->AddListener(*mylistener);
* 	my->Fire(*myarg);
* }
*
* @endcode
*/
class _OSP_EXPORT_ Event
	: virtual public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	Event(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~Event(void);

	/**
	 * Adds the listener object.
	 * The added listener can listen to events when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return      An error code
	 * @param[in]   listener  Listener to add
	 * @param[in]   calledByCallerThread        true, to call the listener on the caller thread of this method
	 *                                          false, to call the listener on the thread in which the event is fired.
	 * @exception   E_SUCCESS        This method is successful.
	 * @exception   E_OBJ_ALREADY_EXIST     The listener already exists.
	 * @exception   E_INVALID_OPERATION calledByCallerThread is set to true but the caller thread is a worker thread.
	 */
	result AddListener(IEventListener& listener, bool calledByCallerThread = true);

	/**
	 * Removes the listener object.
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 2.0
	 *
	 * @return       An error code
	 * @param[in]    listener  Listener to remove
	 * @exception    E_SUCCESS        This method is successful.
	 * @exception    E_OBJ_NOT_FOUND        The listener is not found.
	 */
	result RemoveListener(IEventListener& listener);

	/**
	 * Fires the event with an argument.
	 *
	 * @since 2.0
	 *
	 * @return       An error code
	 * @param[in]    arg       The event argument.
	 * @exception    E_SUCCESS                   This method is successful.
	 * @exception    E_INVALID_STATE                     This event has not been initialized.
	 *
	 * @remark This takes the ownership of @c arg. So arg should be created on a heap and should not be deleted by caller.
	 */
	result Fire(IEventArg& arg);

protected:
	/**
	 * Implement to call the corresponding event listener's method.
	 *
	 * @since 2.0
	 *
	 * @param[in]    listener  The listener instance which is currently processing
	 * @param[in]    arg                 The event argument that is fired
	 *
	 * @remark A derived class must override this method.
	 */
	virtual void FireImpl(IEventListener& listener, const IEventArg& arg) = 0;

private:
	friend class _EventImpl;
	class _EventImpl* __pEventImpl;

}; // Event

} } } // Tizen::Base::Runtime

#endif // _FBASE_RT_EVENT_H_
