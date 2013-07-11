//
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
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
 * @file		FBaseTimeSpan.h
 * @brief		This is the header file for the %TimeSpan class.
 *
 * This header file contains the declarations of the %TimeSpan class.
 */
#ifndef _FBASE_TIME_SPAN_H_
#define _FBASE_TIME_SPAN_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>


namespace Tizen { namespace Base
{
/**
 *	@class	TimeSpan
 *	@brief	This class represents a time interval.
 *
 *	@since 2.0
 *
 *	The %TimeSpan class represents a time interval. An instance of %TimeSpan represents a period of time measured in ticks. A tick is the smallest
 *	unit of time used by the platform or system. In Tizen, it is a millisecond.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/datetime_timespan.htm">DateTime and TimeSpan</a>.
 *
 *	The following example demonstrates how to use the %TimeSpan class.
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *
 *	void
 *	MyClass::TimeSpanSample(void)
 *	{
 *		TimeSpan span1(1, 1, 1);	// one hour + one minute + one second
 *		TimeSpan span2(1, 23, 70, 100); // 1 days + 23 hours + 70 minutes + 100 seconds
 *		
 *		if (span2 > span1)
 *		{
 *			TimeSpan span3 = (span2 - span1);
 *			if (TimeSpan::Compare(span1, span3) == 0)
 *			{
 *				// ...
 *			}
 *		}
 *
 *
 *		long long days, hours, minutes, seconds;
 *
 *		days = span2.GetDays();				// 2 days
 *		hours = span2.GetHours();			// 0 hours
 *		minutes = span2.GetMinutes();		// 11 minutes
 *		seconds = span2.GetSeconds();		// 40 seconds
 *
 *	}
 *	@endcode
 */
class _OSP_EXPORT_ TimeSpan
	: public Object
{
public:
	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in] value		An instance of %TimeSpan to copy
	 */
	TimeSpan(const TimeSpan& value);


	/**
	 * Initializes an instance of %TimeSpan with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @param[in]	hours	The number of hours
	 * @param[in]	minutes	The number of minutes
	 * @param[in]	seconds	The number of seconds
	 */
	TimeSpan(int hours, int minutes, int seconds);


	/**
	 * Initializes an instance of %TimeSpan with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @param[in]	days	The number of days
	 * @param[in]	hours	The number of hours
	 * @param[in]	minutes	The number of minutes
	 * @param[in]	seconds	The number of seconds
	 */
	TimeSpan(int days, int hours, int minutes, int seconds);


	/**
	 * Initializes an instance of %TimeSpan with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @param[in]	days			The number of days
	 * @param[in]	hours			The number of hours
	 * @param[in]	minutes			The number of minutes
	 * @param[in]	seconds			The number of seconds
	 * @param[in]	milliseconds	The number of milliseconds
	 */
	TimeSpan(int days, int hours, int minutes, int seconds, int milliseconds);


	/**
	 * Initializes an instance of %TimeSpan with the specified number of ticks.
	 *
	 * @since 2.0
	 *
	 * @param[in]	ticks	The number of ticks (in milliseconds)
	 */
	TimeSpan(long long ticks);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~TimeSpan(void);

	/**
	 * Adds the values of the two instances of %TimeSpan.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of %TimeSpan
	 * @param[in]	rhs	An instance of %TimeSpan to add
	 */
	TimeSpan operator +(const TimeSpan& rhs) const;

	/**
	 * Subtracts the values of the two instances of %TimeSpan.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of %TimeSpan
	 * @param[in]	rhs	An instance of %TimeSpan to subtract
	 */
	TimeSpan operator -(const TimeSpan& rhs) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the current instance of %TimeSpan
	 * @param[in]	rhs	An instance of %TimeSpan
	 */
	TimeSpan& operator =(const TimeSpan& rhs);

	/**
	 * Checks whether the value of this instance is equal to the value of the
	 * specified instance of %TimeSpan.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the two values are equal, @n
	 *				else @c false
	 * @param[in]	rhs	An instance of %TimeSpan to compare
	 */
	bool operator ==(const TimeSpan& rhs) const;

	/**
	 * Checks whether the value of this instance is not equal to
	 * the value of the specified instance of %TimeSpan.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the two values are not equal, @n
	 *				else @c false
	 * @param[in]	rhs	An instance of %TimeSpan to compare
	 */
	bool operator !=(const TimeSpan& rhs) const;

	/**
	 * Checks whether the value of the calling instance is less than that of
	 * the specified instance of %TimeSpan.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the value of the calling instance is less than that of the specified instance of %TimeSpan, @n
	 *				else @c false
	 * @param[in]	rhs	An instance of %TimeSpan to compare
	 */
	bool operator <(const TimeSpan& rhs) const;

	/**
	 * Checks whether the value of the calling instance is greater than that of
	 * the specified instance of %TimeSpan.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the value of the calling instance is greater than that of the specified instance of %TimeSpan, @n
	 *				else @c false
	 * @param[in]	rhs	An instance of %TimeSpan to compare
	 */
	bool operator >(const TimeSpan& rhs) const;

	/**
	 * Checks whether the value of the calling instance is less than or equal to
	 * the value of the specified instance of %TimeSpan.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the value of the calling instance is less than or equal to the value of the specified instance of %TimeSpan, @n
	 *				else @c false
	 * @param[in]	rhs	An instance of %TimeSpan to compare
	 */
	bool operator <=(const TimeSpan& rhs) const;

	/**
	 * Checks whether the value of the calling instance is greater than or equal to
	 * the value of the specified instance of %TimeSpan.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the value of the calling instance is greater than or equal to the value of the specified instance of %TimeSpan, @n
	 *				else @c false
	 * @param[in]	rhs	An instance of %TimeSpan to compare
	 */
	bool operator >=(const TimeSpan& rhs) const;

	/**
	 * Compares the two specified instances of %TimeSpan.
	 *
	 * @since 2.0
	 *
	 * @return		A 32-bit @c signed integer value
	 * @param[in]	t1	An instance of %TimeSpan to compare
	 * @param[in]	t2	An instance of %TimeSpan to compare
	 *
	 * @code	
	 * <  0  if the value of @c t1 is less than the value of @c t2
	 * == 0  if the value of @c t1 is equal to the value of @c t2
	 * >  0  if the value of @c t1 is greater than the value of @c t2
	 * @endcode
	 */
	static int Compare(const TimeSpan& t1, const TimeSpan& t2);

	/**
	 * Compares the value of the calling instance to the value of the specified instance.
	 *
	 * @since 2.0
	 *
	 * @return		A 32-bit @c signed integer value
	 * @param[in]	value	An instance of %TimeSpan to compare
	 *
	 * @code	
	 * <  0  if the value of the current instance is less than the value of @c obj
	 * == 0  if the value of the current instance is equal to the value of @c obj
	 * >  0  if the value of the current instance is greater than the value of @c obj
	 * @endcode
	 */
	int CompareTo(const TimeSpan& value) const;

	/**
	 * Checks whether the specified instance of Object is equal to the current instance of %TimeSpan.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the specified instance of Object is equal to the current instance of %TimeSpan, @n
	 *				else @c false
	 * @param[in]	obj An instance of Object to compare
	 * @see			Tizen::Base::Object::GetHashCode()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Gets the absolute value of the calling instance.
	 *
	 *  @since 2.0
	 *
	 *	@return			An instance of %TimeSpan containing the absolute value
	 *	@remarks		This method is used to get absolute difference between two %TimeSpan instances.
	 *
	 *	@code
	 *	TimeSpan t1(1000); // 1000 milliseconds
	 *	TimeSpan t2(2000); // 2000 milliseconds
	 *	TimeSpan t3 = t1 - t2; // t3 == -1000
	 *	TimeSpan t4 = t3.Duration(); // t4 == 1000
	 *	@endcode
	 */
	TimeSpan Duration(void) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return	The hash value of the current instance
	 * @see			Tizen::Base::Object::Equals()
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the negative value of the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of %Timespan containing the negative value of the calling instance
	 */
	TimeSpan Negate(void) const;

	/**
	 * Gets the number of whole days represented by the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		The number of whole days represented by the calling instance
	 */
	long long GetDays(void) const;

	/**
	 * Gets the number of hours represented by the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		The number of hours represented by the calling instance
	 */
	long long GetHours(void) const;

	/**
	 * Gets the number of minutes represented by the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		The number of minutes represented by the calling instance
	 */
	long long GetMinutes(void) const;

	/**
	 * Gets the number of seconds represented by the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		The number of seconds represented by the calling instance
	 */
	long long GetSeconds(void) const;

	/**
	 * Gets the number of milliseconds represented by the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		The number of milliseconds represented by the calling instance
	 */
	long long GetMilliseconds(void) const;

	/**
	 * Gets the number of ticks represented by the calling instance.
	 *
	 * @since 2.0
	 *
	 * @return		The number of ticks represented by the calling instance
	 */
	long long GetTicks(void) const;

	/**
	 * A constant holding the number of ticks in a day.
	 *
	 * @since 2.0
	 */
	static const long long NUM_OF_TICKS_IN_DAY = 86400000;

	/**
	 * A constant holding the number of ticks in an hour.
	 *
	 * @since 2.0
	 */
	static const long long NUM_OF_TICKS_IN_HOUR = 3600000;

	/**
	 * A constant holding the number of ticks in a minute.
	 *
	 * @since 2.0
	 */
	static const long long NUM_OF_TICKS_IN_MINUTE = 60000;

	/**
	 * A constant holding the number of ticks in a second.
	 *
	 * @since 2.0
	 */
	static const long long NUM_OF_TICKS_IN_SECOND = 1000;

private:
	//
	// Gets the numbers of ticks.
	// @return		The numbers of ticks
	// @param[in]	days			The number of whole days
	// @param[in]	hours			The number of hours
	// @param[in]	minutes			The number of minutes
	// @param[in]	seconds			The number of seconds
	// @param[in]	milliseconds	The number of milliseconds
	//
	static long long CalcTicks(int days, int hours, int minutes, int seconds, int milliseconds);

	long long __ticks;

	friend class _TimeSpanImpl;
	class _TimeSpanImpl * __pTimeSpanImpl;

}; // TimeSpan

}} // Tizen::Base

#endif //_FBASE_TIME_SPAN_H_
