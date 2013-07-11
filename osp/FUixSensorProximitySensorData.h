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
 * @file     FUixSensorProximitySensorData.h
 * @brief    This is the header file for the %ProximitySensorData class.
 *
 * This header file contains the declarations of the %ProximitySensorData class.
 */

#ifndef _FUIX_SENSOR_PROXIMITY_SENSOR_DATA_H_
#define _FUIX_SENSOR_PROXIMITY_SENSOR_DATA_H_

#include <FOspConfig.h>
#include <FUixSensorSensorData.h>

namespace Tizen { namespace Uix { namespace Sensor
{
/**
 * @class    ProximitySensorData
 * @brief    This class stores proximity sensor data, including a time stamp.
 *
 * @since 2.0
 *
 * @remarks      @b Header @b %file: @b \#include @b <FUix.h> @n
 *               @b Library : @b osp-uix
 *
 * The %ProximitySensorData class stores proximity sensor data, including a time stamp.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/sensor_manager.htm">Sensor Manager</a>.
 */
class _OSP_EXPORT_ ProximitySensorData
	: public Tizen::Uix::Sensor::SensorData
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	ProximitySensorData(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~ProximitySensorData(void);

	/**
	 * Checks whether the object is detected.
	 *
	 * @since 2.0
	 *
	 * @return       @c true if the object is detected, @n
	 *               else @c false
	 */
	bool IsObjectDetected(void) const;

private:
	virtual result GetValue(SensorDataKey dataKey, long& value) const;
	virtual result GetValue(SensorDataKey dataKey, float& value) const;
	virtual result GetValue(SensorDataKey dataKey, bool& value) const;

public:
	/**
	 * The distance value of the proximity sensor data
	 *
	 * @since 2.0
	 */
	float distance;
}; // ProximitySensorData
} } }// Tizen::Uix:Sensor

#endif // _FUIX_SENSOR_PROXIMITY_SENSOR_DATA_H_