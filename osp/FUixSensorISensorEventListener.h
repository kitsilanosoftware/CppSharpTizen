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
 * @file     FUixSensorISensorEventListener.h
 * @brief    This is the header file for the %ISensorEventListener interface.
 *
 * This header file contains the declarations of the %ISensorEventListener interface.
 */

#ifndef _FUIX_SENSOR_ISENSOR_EVENT_LISTENER_H_
#define _FUIX_SENSOR_ISENSOR_EVENT_LISTENER_H_

#include <FUixSensorSensorData.h>
#include <FBaseDataType.h>
#include <FBaseRtIEventListener.h>

namespace Tizen { namespace Uix { namespace Sensor
{

/**
 * @interface    ISensorEventListener
 * @brief        This interface is an event listener used to receive sensor data asynchronously.
 *
 * @since        2.0
 *
 * @remarks      @b Header @b %file: @b \#include @b <FUix.h> @n
 *               @b Library : @b osp-uix
 *
 * The %ISensorEventListener interface is an event listener used to receive sensor data asynchronously.
 * It provides methods that are invoked when the sensor data is received from the device.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/sensor_manager.htm">Sensor Manager</a>.
 */
class _OSP_EXPORT_ ISensorEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
// Lifecycle
public:
	/**
	* This is the destructor for this class.
	*
	* @since    2.0
	*/
	virtual ~ISensorEventListener(void){}

// Operation
public:
	/**
	* Called when the sensor data is sensed after every sensor interval or when the sensor data is changed from the previous interval.
	*
	* @since        2.0
	*
	* @param[in]    sensorType        The sensor type
	* @param[in]    sensorData        The array of sensor data
	* @param[in]    r                 The error code
	* @exception    E_SUCCESS         The method is successful.
	* @exception    E_INVALID_DATA    The sensor data is invalid.
	* @remarks     Calling of the application methods (including UI) must be handled in the main application thread, that is outside the sensor event handler %OnDataReceived().
	* @see          Tizen::Uix::Sensor::AccelerationDataKey
	* @see			Tizen::Uix::Sensor::MagneticDataKey
	* @see			Tizen::Uix::Sensor::ProximityDataKey
	* @see			Tizen::Uix::Sensor::TiltDataKey
	*
	* The following example demonstrates how to use the %OnDataReceived() method.
	*
	* @code
	* // Sample code for SensorSample.h
	* #include <FUix.h>
	* #include <FUi.h>
	*
	* class SensorSample :
	*     public Tizen::Ui::Controls::Form,
	*     public Tizen::Uix::Sensor::ISensorEventListener
	* {
	* public:
	*         virtual result OnDraw();
	*         void OnDataReceived(SensorType sensorType, SensorData& sensorData , result r);
	*         //...
	* }
	*
	* // Sample code for SensorSample.cpp
	* #include "SensorSample.h"
	*
	* using namespace Tizen::Uix::Sensor;
	*
	* void
	* SensorSample::OnDataReceived(SensorType sensorType, SensorData& sensorData , result r)
	* {
	*     // ...
	* }
	*
	* result
	* SensorSample::OnDraw()
	* {
	*     // ...
	* }
	* @endcode
	*/
	virtual void OnDataReceived(SensorType sensorType, SensorData& sensorData, result r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	virtual void ISensorEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	virtual void ISensorEventListener_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	virtual void ISensorEventListener_Reserved3(void) {}

}; // ISensorEventListener

} } }// Tizen::Uix::Sensor

#endif // _FUIX_SENSOR_ISENSOR_EVENT_LISTENER_H_
