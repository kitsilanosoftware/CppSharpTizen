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
 * @file     FUixSensorAccelerationSensorData.h
 * @brief    This is the header file for the %AccelerationSensorData class.
 *
 * This header file contains the declarations of the %AccelerationSensorData class.
 */

#ifndef _FUIX_SENSOR_ACCELERATION_SENSOR_DATA_H_
#define _FUIX_SENSOR_ACCELERATION_SENSOR_DATA_H_

#include <FOspConfig.h>
#include <FUixSensorSensorData.h>

namespace Tizen { namespace Uix { namespace Sensor
{
/**
 * @class    AccelerationSensorData
 * @brief    This class stores acceleration sensor data, including a time stamp.
 *
 * @since 2.0
 *
 * @remarks      @b Header @b %file: @b \#include @b <FUix.h> @n
 *               @b Library : @b osp-uix
 *
 * The %AccelerationSensorData class stores acceleration sensor data, including a time stamp.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/sensor_manager.htm">Sensor Manager</a>.
 */
class _OSP_EXPORT_ AccelerationSensorData
	: public Tizen::Uix::Sensor::SensorData
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	AccelerationSensorData(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~AccelerationSensorData(void);

private:
	virtual result GetValue(SensorDataKey dataKey, long& value) const;
	virtual result GetValue(SensorDataKey dataKey, float& value) const;
	virtual result GetValue(SensorDataKey dataKey, bool& value) const;

public:
	/**
	 * The x-axis value of the acceleration sensor data
	 *
	 * @since 2.0
	 */
	float x;

	/**
	 * The y-axis value of the acceleration sensor data
	 *
	 * @since 2.0
	 */
	float y;

	/**
	 * The z-axis value of the acceleration sensor data
	 *
	 * @since 2.0
	 */
	float z;
}; // AccelerationSensorData
} } } // Tizen::Uix::Sensor

#endif // _FUIX_SENSOR_ACCELERATION_SENSOR_DATA_H_
