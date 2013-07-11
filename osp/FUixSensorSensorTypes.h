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
 * @file     FUixSensorSensorTypes.h
 * @brief    This is the header file for the common data types used by the SensorData and SensorManager classes.
 *
 * This header file contains the declarations of the common data types and constants used by the SensorData and SensorManager classes.
 */

#ifndef _FUIX_SENSOR_SENSOR_TYPES_H_
#define _FUIX_SENSOR_SENSOR_TYPES_H_

namespace Tizen { namespace Uix { namespace Sensor
{

/**
* @enum     SensorType
*
* Defines the sensor type.
*
* @since    2.0
*/
enum SensorType
{
	SENSOR_TYPE_ACCELERATION = 0,    /**< The acceleration sensor type */
	SENSOR_TYPE_MAGNETIC,            /**< The magnetic sensor type */
	SENSOR_TYPE_PROXIMITY,           /**< The proximity sensor type */
	SENSOR_TYPE_TILT,                /**< The tilt sensor type */
	SENSOR_TYPE_GYRO,                /**< The gyro sensor type */
	SENSOR_TYPE_LIGHT,               /**< The light sensor type */
	SENSOR_TYPE_MAX,                 // This enum value is for internal use only.
	                                 // Using this enum value can cause behavioral,
	                                 // security-related, and consistency-related
	                                 // issues in the application.
	SENSOR_TYPE_NONE = -1,           // This enum value is for internal use only.
	                                 // Using this enum value can cause behavioral,
	                                 // security-related, and consistency-related
	                                 // issues in the application.
};

/**
* @enum       SensorDataKey
*
* Defines the default key types for the SensorData class.
*
* @since      2.0
*
* @remarks    Use actual key type, such as Tizen::Uix::Sensor::AccelerationDataKey, Tizen::Uix::Sensor::MagneticDataKey, Tizen::Uix::Sensor::ProximityDataKey or Tizen::Uix::Sensor::TiltDataKey with type casting. For example, use Tizen::Uix::Sensor::SensorData::GetValue(static_cast<SensorDataKey>(ACCELERATION_DATA_KEY_X), value) to get the acceleration value in x-axis.
*/
enum SensorDataKey
{
	SENSOR_DATA_KEY_0 = 0,
	SENSOR_DATA_KEY_1,
	SENSOR_DATA_KEY_2,
	SENSOR_DATA_KEY_3,
	SENSOR_DATA_KEY_4
};

/**
* @enum     AccelerationDataKey
*
* Defines the keys to access the acceleration sensor data.
*
* @since    2.0
*/
enum AccelerationDataKey
{
	ACCELERATION_DATA_KEY_TIMESTAMP = 256,    /**< The key to the timestamp of the acceleration sensor data */
	ACCELERATION_DATA_KEY_X,                  /**< The key to the x-axis of the acceleration sensor data */
	ACCELERATION_DATA_KEY_Y,                  /**< The key to the y-axis of the acceleration sensor data */
	ACCELERATION_DATA_KEY_Z,                  /**< The key to the z-axis of the acceleration sensor data */
	ACCELERATION_DATA_KEY_COUNT = 4           /**< The number of indices for the acceleration sensor data */
};

/**
* @enum     MagneticDataKey
*
* Defines the keys to access the magnetic sensor data.
*
* @since    2.0
*/
enum MagneticDataKey
{
	MAGNETIC_DATA_KEY_TIMESTAMP = 266,    /**< The key to the timestamp of the magnetic sensor data */
	MAGNETIC_DATA_KEY_X,                  /**< The key to the x-axis of the magnetic sensor data */
	MAGNETIC_DATA_KEY_Y,                  /**< The key to the y-axis of the magnetic sensor data  */
	MAGNETIC_DATA_KEY_Z,                  /**< The key to the z-axis of the magnetic sensor data  */
	MAGNETIC_DATA_KEY_COUNT = 4           /**< The number of indices to access magnetic sensor data */
};

/**
* @enum     ProximityDataKey
*
* Defines the keys to access the proximity sensor data.
*
* @since    2.0
*/
enum ProximityDataKey
{
	PROXIMITY_DATA_KEY_TIMESTAMP = 276,    /**< The key to the timestamp of the proximity sensor data */
	PROXIMITY_DATA_KEY_ONOFF,              /**< The key to on/off the proximity sensor data */
	PROXIMITY_DATA_KEY_COUNT = 2           /**< The number of indices to access the proximity sensor data */
};

/**
* @enum     TiltDataKey
*
* Defines the keys to access the tilt sensor data.
*
* @since    2.0
*/
enum TiltDataKey
{
	TILT_DATA_KEY_TIMESTAMP = 286,    /**< The key to the timestamp of the tilt sensor data */
	TILT_DATA_KEY_AZIMUTH,            /**< The key to the azimuth of the tilt sensor data  */
	TILT_DATA_KEY_PITCH,              /**< The key to the pitch of the tilt sensor data */
	TILT_DATA_KEY_ROLL,               /**< The key to the roll of the tilt sensor data */
	TILT_DATA_KEY_COUNT = 4           /**< The number of indices to access the tilt sensor data */
};

} } }// Tizen::Uix::Sensor

#endif // _FUIX_SENSOR_SENSOR_TYPES_H_
