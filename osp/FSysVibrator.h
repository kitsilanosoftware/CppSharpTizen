//
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
 * @file	FSysVibrator.h
 * @brief	This is the header file for the %Vibrator class.
 *
 * This header file contains the declarations of the %Vibrator class.
 */

#ifndef _FSYS_VIBRATOR_H_
#define _FSYS_VIBRATOR_H_

#include <FBaseObject.h>

namespace Tizen { namespace System
{

/**
 * @class   Vibrator
 * @brief   This class handles the vibration functionality of the device.
 *
 * @since   2.0
 *
 * The %Vibrator class handles the vibration functionality of a device. It allows you to manage the device's vibrator parameters, such as vibration count and level.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/system/vibrator_mgmt.htm">Vibrator Management</a>.
 *
 * The following example demonstrates how to use the %Vibrator class.
 *
 * @code
 *
 * #include <FBase.h>
 * #include <FSystem.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::System;
 *
 * class MyVibratorClass
 * {
 * public:
 *  result VibratorExample(void);
 * private:
 *  Vibrator vibrator;
 * };
 *
 * result
 * MyVibratorClass::VibratorExample(void)
 * {
 * 	result r = vibrator.Construct();
 * 	if (IsFailed(r))
 * 	{
 * 		goto CATCH;
 * 	}
 *
 *	// Initializes the vibration pattern
 *	IntensityDurationVibrationPattern patterns[4] = {{2000, 50}, {1000, 0}, {500, -1}, {1000, 80}};
 *	int length = sizeof(patterns);

 * 	// Vibrates with a given pattern and repeats count
 *	vibrator.Start(patterns, length, 3);
 *
 * 	return E_SUCCESS;
 *
 * CATCH:
 * 	// Do some exception handling
 * 	return r;
 * }
 * @endcode
 */

/**
 * @struct      IntensityDurationVibrationPattern
 * @brief       This struct has the specified duration and a vibration intensity level.
 *
 * The %IntensityDurationVibrationPattern struct has the specified duration and a vibration intensity level. This can be used with Vibrator::Start(IntensityDurationVibrationPattern[] patterns, int length, int repeatCount) as a custom pattern.
 *
 * @since 2.1
 */
struct _OSP_EXPORT_ IntensityDurationVibrationPattern
{
	int duration; /**< The duration in milliseconds when the vibrator is on @n
			*	The @c duration is not allowed a negative value.
			*/
	int intensity; /**< The vibration intensity [@c -1~ @c 100]: @n
			*	@li The system default vibration intensity (-1)
			*	@li The silent vibration intensity (0)
			*	@li The minimum vibration intensity (1)
			*	@li The maximum vibration intensity (100)
			*/
};


class _OSP_EXPORT_ Vibrator
	: public Tizen::Base::Object
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since   2.0
	 *
	 * @remarks The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 */
	Vibrator(void);

	/**
	 * This is the destructor for this class. @n
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since   2.0
	 *
	 * @remarks If the instance is destroyed before the vibration stops, the vibration is stopped forcefully.
	 */
	virtual ~Vibrator(void);

	/**
	 * Initializes this instance of %Vibrator.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception   E_SYSTEM            An unknown operating system error has occurred.
	 *
	 */
	result Construct(void);


        /**
         * Vibrates the device with a specified array pattern that has vibration intensity and duration. @n
         * The %Start() method returns the result immediately so that the vibration occurs simultaneously as the device runs. @n
         * If this method is called again before the previous vibration stops, the previous vibration is canceled and the new vibration starts immediately. @n
         * If a new vibrator instance triggers the vibration, the vibrator merges the previous vibration pattern with the new one in the overlapped time. @n
         * If the system alert occurs such as ring vibration and a system event notification, the vibration can be interrupted. @n
         * If the application is terminated, the vibration is canceled.
         *
         * @since 2.1
         * @privilege     %http://tizen.org/privilege/vibrator
         *
         * @return      An error code
         *
         * @param[in]   patterns                        An array of @c IntensityDurationVibrationPattern
	 * @param[in]   length				The length of @c patterns
         * @param[in]   repeatCount                           The number of times the pattern repeats @n This value must be between @c 1 to @c 100.
         * @exception   E_SUCCESS           The method is successful.
         * @exception    E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
         * @exception   E_INVALID_ARG       A specified input parameter is invalid.
         * @exception E_OPERATION_FAILED The device operation has failed.
         * @remarks The vibration intensity does not apply the change, even if the system default vibration intensity is changed after starting vibration.
         * @see  IntensityDurationVibrationPattern
         */
        result Start(IntensityDurationVibrationPattern* patterns, int length, int repeatCount = 1);

	/**
	 * Vibrates the device with the specified pattern and level. @n
	 * The %Start() method returns the result immediately so that the vibration occurs simultaneously as the device runs.
	 * If this method is called again before the previous vibration stops, the previous vibration is canceled and the new vibration starts immediately.
	 *
	 * @deprecated This method is deprecated. Instead of using this method, use Start(IntensityDurationVibrationPattern[] patterns, int length, int repeatCount).
	 * @since 2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/vibrator
	 *
	 * @return      An error code
	 * @param[in]   onPeriod    The period in milliseconds when the vibrator is on @n
	 *                          It should be greater than @c 0.
	 * @param[in]   offPeriod   The period in milliseconds when the vibrator is off @n
	 *                          It should be equal to or greater than @c 0.
	 * @param[in]   count       The number of times to execute the given pattern @n
	 *                          It should be greater than @c 0.
	 * @param[in]   level       The vibration level @n
	 *                          Ranges from [@c 0~ @c 100], where '@c 0' is a special case indicating the system default level.
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception   E_DEVICE_BUSY       The device cannot be approached because of other operations.
	 * @exception   E_DEVICE_FAILED     The device operation has failed.
	 * @remarks     Various devices may have different vibration capabilities.
	 *              If the device supports only one level of vibration, then a level value between [@c 0~ @c 100] results in the default vibration.
	 *              If the device supports many levels of vibration, then a level value @c 0 results in the system default vibration, value @c 1 results in the lowest frequency vibration, value @c 100 results in the highest frequency vibration, and intermediate values result in intermediate vibration levels. @n
	 *              Devices have implementation-specific limits for the total duration of the vibration, and vibration cuts off at that limit even if the duration parameter is greater than the limit.
	 *
	 */
	result Start(long onPeriod, long offPeriod, int count, int level = 0);

	/**
	 * Vibrates the device for the specified duration at the specified @c level. @n
	 * The %Start() method returns the result immediately so that the vibration occurs simultaneously as the device runs.
	 * If this method is called again before the previous vibration stops, the previous vibration is canceled and the new vibration starts immediately.
	 *
	 * @deprecated This method is deprecated. Instead of using this method, use Start(IntensityDurationVibrationPattern[] patterns, int length, int repeatCount).
	 * @since       2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/vibrator
	 *
	 * @return      An error code
	 * @param[in]   milliseconds    The duration for the vibration in milliseconds @n
	 *                              It should be greater than @c 0.
	 * @param[in]   level           The vibration level @n
	 *                              Ranges from [@c 0~ @c 100], where ' @c 0' is a special case indicating the system default level.
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception   E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception   E_DEVICE_BUSY       The device cannot be approached because of other operations.
	 * @exception   E_DEVICE_FAILED     The device operation has failed.
	 * @remarks     Various devices have different vibration capabilities. @n
	 *              If the device supports only one level of vibration, then a level value between [@c 0~ @c 100] results in the default vibration.
	 *              If the device supports many levels of vibration, then a level value @c 0 results in the system default vibration, value @c 1 results in the lowest frequency vibration, value @c 100 results in the highest frequency vibration, and intermediate values result in intermediate vibration levels. @n
	 *              Devices have implementation-specific limits for the total duration of the vibration, and vibration cuts off at that limit even if the duration parameter is greater than the limit.
	 *
	 */
	result Start(long milliseconds, int level = 0);

	/**
	 * Turns the vibrator off.
	 *
	 * @since   2.0
	 * @privlevel	public
	 * @privilege	%http://tizen.org/privilege/vibrator
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS           The method is successful.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception   E_DEVICE_FAILED     The device operation has failed.
	 *
	 */
	result Stop(void);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 */
	Vibrator(const Vibrator& value);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 */
	Vibrator& operator =(const Vibrator& value);

private:
	friend class _VibratorImpl;
	class _VibratorImpl* __pVibratorImpl;

}; // Vibrator

} } // Tizen::System

#endif
