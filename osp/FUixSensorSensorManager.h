// 
// Open Service Platform
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
// 
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.tizenopensource.org/license
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file     FUixSensorSensorManager.h
 * @brief    This is the header file for the %SensorManager class.
 *
 * This header file contains the declarations of the %SensorManager class.
 */

#ifndef _FUIX_SENSOR_SENSOR_MANAGER_H_
#define _FUIX_SENSOR_SENSOR_MANAGER_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FUixSensorSensorTypes.h>
#include <FUixSensorISensorEventListener.h>

namespace Tizen { namespace Base
{
class String;
} } // Tizen::Base

namespace Tizen { namespace Uix { namespace Sensor
{

/**
 * @class SensorManager
 * @brief This class is used to receive sensor data from the device.
 *
 * @since 2.0
 *
 * @remarks      @b Header @b %file: @b \#include @b <FUix.h> @n
 *               @b Library : @b osp-uix
 *
 * The %SensorManager class is used to receive and manage sensor data from the device, including adding or removing the sensor
 * listeners, checking sensor availability, setting intervals, and getting the maximum or minimum intervals.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/sensor_manager.htm">Sensor Manager</a>.
 *
 * The following examples demonstrate how to use the %SensorManager class with the acceleration sensor.
 *
 * @code
 * //Sample code for SensorSample.h
 * #include <FUixSensor.h>
 *
 * using namespace Tizen::Uix::Sensor;
 *
 * class SensorSample : public ISensorEventListener
 * {
 *     public:
 *         SensorSample(void);
 *         virtual ~SensorSample(void);
 *         bool CreateSensor(void);
 *
 *         virtual void OnDataReceived(SensorType sensorType, SensorData& sensorData, result r);
 *
 *     private:
 *         SensorManager __sensorManager;
 * };
 *
 * //Sample code for SensorSample.cpp
 * #include "SensorSample.h"
 *
 * SensorSample::SensorSample(void)
 * {
 *     // Initializes the sensor manager
 *     __sensorManager.Construct();
 * }
 *
 * SensorSample::~SensorSample(void)
 * {
 *     // Finalizes the sensor manager
 * }
 *
 * void SensorSample::OnDataReceived(SensorType sensorType, SensorData& sensorData, result r)
 * {
 *     // Adds your code.
 *     // Refers to API Reference to ISensorEventListener::OnDataReceived().
 *     // Application APIs should not be called inside this event handler.
 *     // Overrides OnDataReceived() for just receiving the sensor data and copying it to the main application context.
 *
 * }
 *
 * bool SensorSample::CreateSensor(void)
 * {
 *     result r = E_SUCCESS;
 *
 *     if (__sensorManager.IsAvailable(SENSOR_TYPE_ACCELERATION))
 *     {
 *         r = __sensorManager.AddSensorListener(*this, SENSOR_TYPE_ACCELERATION, 50, true);
 *         if (IsFailed(r))
 *         {
 *             return false;
 *	   }
 *     }
 *     else
 *     {
 *         AppLogException("Acceleration sensor is not available.");
 *         return false;
 *     }
 *
 *     return true;
 * }
 * @endcode
 */
class _OSP_EXPORT_ SensorManager
	: public Tizen::Base::Object
{

// Lifecycle
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since      2.0
	 *
	 * @remarks    After creating an instance of this class, the Construct() method
	 *             must be called explicitly to initialize this instance.
	 */
	SensorManager(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since      2.0
	 *
	 * @remarks    All listeners are removed
	 *             and the internally allocated memory block is deleted when the instance is destroyed.
	 */
	virtual ~SensorManager(void);


// Operation
public:
	/**
	 * Initializes this instance of %SensorManager. @n
	 * It includes initializing the sub-component of the sensor manager.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @exception    E_SUCCESS          The method is successful.
	 * @exception    E_OUT_OF_MEMORY    The memory is insufficient.
	 */
	result Construct(void);

	/**
	* Adds a sensor listener when the sensor powers up for the first time.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since        2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerAddSensorListenerPage "here".
	* @endif
	* @return       An error code
	* @param[in]    listener                     The listener to add
	* @param[in]    sensorType                   The sensor type
	* @param[in]    interval                     The interval (in milliseconds) at which the sensor data is received
	* @param[in]    dataChanged                  Set to @c true if the sensor data is received only when the sensor data is changed, @n
	*                                            else @c false if the sensor data is received at every interval
	* @exception    E_SUCCESS                    The method is successful.
	* @exception    E_OUT_OF_MEMORY              The memory is insufficient.
	* @exception    E_INVALID_ARG                An interval must be greater than the maximum interval or less than the minimum interval or the sensor type is invalid.
	* @exception    E_OPERATION_FAILED         The operation has failed to add a sensor listener.
	* @exception    E_USER_ALREADY_REGISTERED    The specified listener is already registered for the specified sensor type.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	*/

	result AddSensorListener(ISensorEventListener& listener, SensorType sensorType, long interval, bool dataChanged);

	/**
	* @if OSPCOMPAT
	* @page	        CompSensorManagerAddSensorListenerPage Compatibility for AddSensorListener()
	* @section      CompSensorManagerAddSensorListenerIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section      CompSensorManagerAddSensorListenerSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* Removes a sensor listener from all sensor types. @n
	* Sensor powers down when every listener added to the type of sensor is removed.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since        2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerRemoveSensorListenerPage "here".
	* @endif
	* @return       An error code
	* @param[in]    listener                The listener to remove
	* @exception    E_SUCCESS               The method is successful.
	* @exception   E_OBJ_NOT_FOUND           The specified @c listener is not found in the listener list.
	* @exception    E_OPERATION_FAILED           The operation has failed to remove sensor listeners.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	*/

	result RemoveSensorListener(ISensorEventListener& listener);

	/**
	* @if OSPCOMPAT
	* @page                    CompSensorManagerRemoveSensorListenerPage Compatibility for RemoveSensorListener()
	* @section                 CompSensorManagerRemoveSensorListenerIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerRemoveSensorListenerSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/


	/**
	* Removes a sensor listener from the sensor type. @n
	* Sensor powers down when every listener added to the type of sensor is removed.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since        2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerRemoveSensorListenerPage "here".
	* @endif
	* @return       An error code
	* @param[in]    listener                   The listener to remove
	* @param[in]    sensorType                 The sensor type
	* @exception    E_SUCCESS                  The method is successful.
	* @exception    E_OBJ_NOT_FOUND           The specified @c listener is not found in the listener list,
	*                                            or the specified type of sensor is not valid.
	* @exception    E_OPERATION_FAILED           The operation has failed to remove the sensor listener.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	*/
	result RemoveSensorListener(ISensorEventListener& listener, SensorType sensorType);

	/**
	 * @if OSPCOMPAT
	* @page                    CompSensorManagerRemoveSensorListenerPage Compatibility for RemoveSensorListener ()
	* @section                   CompSensorManagerRemoveSensorListenerIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerRemoveSensorListenerSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* @if OSPDEPREC
	* @{
	* Sets an interval of a sensor.
	* @if OSPCOMPAT
	* @brief <i> [Deprecated] [Compatibility] </i>
	* @endif
	* @deprecated   This method is deprecated because it changes only the first listener's interval; the other listeners do not have an option to change their intervals.
	* To resolve this, a new method has been added. Instead of using this method, use the SetInterval(ISensorEventListener& listener, SensorType sensorType, long interval) method.
	* @since        2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerSetIntervalPage "here".
	* @endif
	* @return       An error code
	* @param[in]    sensorType                 The sensor type
	* @param[in]    interval                   The interval (in milliseconds) at which the sensor data is received
	* @exception    E_SUCCESS                  The method is successful.
	* @exception    E_INVALID_ARG              An interval must be greater than the maximum interval or less than the minimum interval,
	*                                            or the sensor type is invalid.
	* @exception    E_OPERATION_FAILED         The operation has failed to set interval of sensor.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	* @see SensorManager::GetMaxInterval() for getting the maximum intervals
	* @see SensorManager::GetMinInterval() for getting the minimum intervals
	* @}
	* @endif
	*/

	result SetInterval(SensorType sensorType, long interval);

	/**
	* @if OSPCOMPAT
	* @page                    CompSensorManagerSetIntervalPage Compatibility for SetInterval ()
	* @section                   CompSensorManagerSetIntervalIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerSetIntervalSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* Sets an interval of a sensor using the specified @c listener.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since        2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerSetIntervalPage "here".
	* @endif
	* @return       An error code
	* @param[in]    listener                   The added listener
	* @param[in]    sensorType                 The sensor type
	* @param[in]    interval                   The interval (in milliseconds) at which the sensor data is received
	* @exception    E_SUCCESS                  The method is successful.
	* @exception    E_INVALID_ARG              An interval must be greater than the maximum interval or less than the minimum interval,
    *                                           or the listener is not registered for this type of sensor, or the sensor type is invalid.
	* @exception    E_OPERATION_FAILED         The operation has failed to set the interval of sensor.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	* @see SensorManager::GetMaxInterval() for getting the maximum intervals
	* @see SensorManager::GetMinInterval() for getting the minimum intervals
	*/
	result SetInterval(ISensorEventListener& listener, SensorType sensorType, long interval);

	/**
	* @if OSPCOMPAT
	* @page                    CompSensorManagerSetIntervalPage Compatibility for SetInterval ()
	* @section                   CompSensorManagerSetIntervalIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerSetIntervalSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* Checks whether a sensor type is available on the device.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since        2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerIsAvailablePage "here".
	* @endif
	* @return       @c true if the sensor type is available, @n
	*               else @c false
	* @param[in]    sensorType       The sensor type
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_INVALID_ARG     The sensor type is invalid.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	*/
	bool IsAvailable(SensorType sensorType) const;

	/**
	* @if OSPCOMPAT
	* @page                    CompSensorManagerIsAvailablePage Compatibility for IsAvailable ()
	* @section                   CompSensorManagerIsAvailableIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerIsAvailableSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* Gets the minimum interval of the sensor type.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since         2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerGetMinIntervalPage "here".
	* @endif
	* @return        An error code
	* @param[in]     sensorType                 The sensor type
	* @param[out]    interval                   The minimum interval in milliseconds
	* @exception     E_SUCCESS                  The method is successful.
	* @exception    E_INVALID_ARG               The sensor type is invalid.
	* @exception    E_OPERATION_FAILED         The operation has failed to get interval of sensor.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	*/
	result GetMinInterval(SensorType sensorType, long& interval) const;

	/**
    * @if OSPCOMPAT
	* @page                    CompSensorManagerGetMinIntervalPage Compatibility for GetMinInterval()
	* @section                   CompSensorManagerGetMinIntervalIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerGetMinIntervalSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* Gets the maximum interval of the sensor type.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since         2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerGetMaxIntervalPage "here".
	* @endif
	* @return        An error code
	* @param[in]     sensorType                 The sensor type
	* @param[out]    interval                   The maximum interval in milliseconds
	* @exception     E_SUCCESS                  The method is successful.
	* @exception    E_INVALID_ARG               The sensor type is invalid.
	* @exception    E_OPERATION_FAILED         The operation has failed to get interval of sensor.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	*/
	result GetMaxInterval(SensorType sensorType, long& interval) const;

	/**
	* @if OSPCOMPAT
	* @page                    CompSensorManagerGetMaxIntervalPage Compatibility for GetMaxInterval()
	* @section                   CompSensorManagerGetMaxIntervalIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerGetMaxIntervalSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* Gets a brief description on this sensor.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since         2.0
	*
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerGetDescriptionPage "here".
	* @endif
	* @return        An error code
	* @param[in]     sensorType                 The sensor type
	* @param[out]    description                The sensor description
	* @exception     E_SUCCESS                  The method is successful.
	* @exception    E_INVALID_ARG               The sensor type is invalid.
	* @exception    E_OPERATION_FAILED         The operation has failed to get description of sensor.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	*/
	result GetDescription(SensorType sensorType, Tizen::Base::String& description) const;

	/**
	* @if OSPCOMPAT
	* @page                    CompSensorManagerGetDescriptionPage Compatibility for GetDescription()
	* @section                   CompSensorManagerGetDescriptionIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerGetDescriptionSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* Gets the sensor's vendor information.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since         2.0
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerGetVendorPage "here".
	* @endif
	* @return        An error code
	* @param[in]     sensorType                 The sensor type
	* @param[out]    vendor                     The vendor information
	* @exception     E_SUCCESS                  The method is successful.
	* @exception    E_INVALID_ARG               The sensor type is invalid.
	* @exception    E_OPERATION_FAILED         The operation has failed to get vender information of sensor.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	*/
	result GetVendor(SensorType sensorType, Tizen::Base::String& vendor) const;

	/**
	* @if OSPCOMPAT
	* @page                    CompSensorManagerGetVendorPage Compatibility for GetVendor()
	* @section                   CompSensorManagerGetVendorIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerGetVendorSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* Gets the sensor's model ID.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since         2.0
	*
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerGetModelIdPage "here".
	* @endif
	* @return        An error code
	* @param[in]     sensorType                 The sensor type
	* @param[out]    modelId                    The model ID of the sensor hardware
	* @exception     E_SUCCESS                  The method is successful.
	* @exception    E_INVALID_ARG               The sensor type is invalid.
	* @exception    E_OPERATION_FAILED         The operation has failed to get the model ID of the sensor.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	*/
	result GetModelId(SensorType sensorType, Tizen::Base::String& modelId) const;

	/**
	* @if OSPCOMPAT
	* @page                    CompSensorManagerGetModelIdPage Compatibility for GetModelId()
	* @section                   CompSensorManagerGetModelIdIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerGetModelIdSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* Gets the measurement range of the sensor.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since         2.0
	*
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerGetMeasurementRangePage "here".
	* @endif
	* @return        An error code
	* @param[in]     sensorType                 The sensor type
	* @param[out]    min                        The minimum value of the measurement range
	* @param[out]    max                        The maximum value of the measurement range
	* @param[out]    resolution                 The resolution of the sensor measurement, that is, Measurement/bit @n
	*                                           This is a device specific characteristic.
	* @exception     E_SUCCESS                  The method is successful.
	* @exception    E_INVALID_ARG               The sensor type is invalid.
	* @exception    E_OPERATION_FAILED         The operation has failed.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	*/
	result GetMeasurementRange(SensorType sensorType, float& min, float& max, float& resolution) const;

	/**
	* @if OSPCOMPAT
	* @page                    CompSensorManagerGetMeasurementRangePage Compatibility for GetMeasurementRange()
	* @section                   CompSensorManagerGetMeasurementRangeIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerGetMeasurementRangeSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* Checks whether the wake up feature is supported for the specified sensor type. @n
	* The return value can vary depending on a specific device model.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since        2.0
	*
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerIsWakeupSupportedPage "here".
	* @endif
	* @return       @c true if the sensor type supports the wake up feature while the device is in the sleep mode, @n
	*               else @c false if the wake up feature is not supported by the sensor or if the instance is not initialized properly
	* @param[in]    sensorType                 The sensor type
	* @exception    E_SUCCESS                  The method is successful.
	* @exception    E_INVALID_ARG              The sensor type is invalid.
	* @exception    E_OPERATION_FAILED         The operation has failed.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	* @remarks		This method cannot be tested on the Emulator. It always returns true on the Emulator.
	*/
	bool IsWakeupSupported(SensorType sensorType) const;

	/**
	* @if OSPCOMPAT
	* @page                    CompSensorManagerIsWakeupSupportedPage Compatibility for IsWakeupSupported()
	* @section                   CompSensorManagerIsWakeupSupportedIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerIsWakeupSupportedSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* Sets the application-wise wake up feature as enabled or disabled for the specified sensor type.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since        2.0
	*
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerSetWakeupEnabledPage "here".
	* @endif
	* @return       An error code
	* @param[in]    sensorType                 The sensor type
	* @param[in]    enable                     Set to @c true to enable the wake up feature, @n
	*                                          else @c false to disable the wake up feature
	* @exception    E_SUCCESS                  The method is successful.
	* @exception    E_OPERATION_FAILED         The method has failed to set the wake up option.
	* @exception    E_INVALID_STATE            There is no sensor listener registered for this type.
	* @exception    E_INVALID_ARG              The sensor type is invalid.
	* @exception    E_OPERATION_FAILED         The operation has failed.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	* @remarks      The wake up feature is automatically disabled by the system as soon as the calling application is terminated.
	* @remarks		This method cannot be tested on the Emulator. It always returns E_SUCCESS on the Emulator.
	*/
	result SetWakeupEnabled(SensorType sensorType, bool enable);

	/**
	* @if OSPCOMPAT
	* @page                    CompSensorManagerSetWakeupEnabledPage Compatibility for SetWakeupEnabled()
	* @section                   CompSensorManagerSetWakeupEnabledIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerSetWakeupEnabledSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

	/**
	* Checks whether the wake up feature is enabled for the specified sensor type.
	* @if OSPCOMPAT
	* @brief                   <i> [Compatibility] </i>
	* @endif
	* @since        2.0
	*
	* @if OSPCOMPAT
	* @compatibility     This method has compatibility issues with OSP compatible applications. @n
	*                              For more information, see @ref CompSensorManagerIsWakeupEnabledPage "here".
	* @endif
	* @return       @c true if the wakeup feature is enabled for the specified sensor type for the calling application, @n
	*               else @c false
	* @param[in]    sensorType                 The sensor type
	* @exception    E_SUCCESS                  The method is successful.
	* @exception    E_INVALID_ARG              The sensor type is invalid.
	* @exception    E_OPERATION_FAILED         The operation has failed.
	* @exception    E_UNSUPPORTED_OPERATION      The target device does not support the specific sensor.
	* @remarks      The specific error code can be accessed using the GetLastResult() method.
	* @remarks		This method cannot be tested on the Emulator. It always returns true on the Emulator.
	*/
	bool IsWakeupEnabled(SensorType sensorType) const;

	/**
	* @if OSPCOMPAT
	* @page                    CompSensorManagerIsWakeupEnabledPage Compatibility for IsWakeupEnabled()
	* @section                   CompSensorManagerIsWakeupEnabledIssueSection Issues
	* Implementing this method in OSP compatible applications has the following issues:   @n
	* -# The method returns E_DEVICE_UNAVAILABLE if the target device does not support the specific sensor.
	*
	* @section                 CompSensorManagerIsWakeupEnabledSolutionSection Resolutions
	* This issue has been resolved in Tizen. @n
	* -# The method returns @c E_UNSUPPORTED_OPERATION if the target device does not support the specific sensor.
	* -# E_DEVICE_UNAVAILABLE exception is removed.
	* @endif
	*/

private:
	/**
	 * This is the copy constructor for %SensorManager class.
	 *
	 * @since 2.0
	 */
	SensorManager(const SensorManager& sensorManager);

	/**
	 * Assigns the value of the specified %SensorManager object to the current instance.
	 *
	 * @since 2.0
	 */
	SensorManager& operator =(const SensorManager& sensorManager);

private:
	class _SensorManagerImpl* __pSensorManagerImpl;
	friend class _SensorManagerImpl;

}; // SensorManager

} } }// Tizen::Uix::Sensor

#endif // _FUIX_SENSOR_SENSOR_MANAGER_H_
