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
 * @file     FUixSensorSensorData.h
 * @brief    This is the header file for the %SensorData class.
 *
 * This header file contains the declarations of the %SensorData class.
 */

#ifndef _FUIX_SENSOR_SENSOR_DATA_H_
#define _FUIX_SENSOR_SENSOR_DATA_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>
#include <FUixSensorSensorTypes.h>

namespace Tizen { namespace Uix { namespace Sensor
{

/**
 * @class    SensorData
 * @brief    This class stores sensor data, including a time stamp.
 *
 * @since    2.0
 *
 * @remarks      @b Header @b %file: @b \#include @b <FUix.h> @n
 *               @b Library : @b osp-uix
 *
 * The %SensorData class stores sensor data, including a time stamp.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/sensor_manager.htm">Sensor Manager</a>.
 */
class _OSP_EXPORT_ SensorData
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since    2.0
	 */
	SensorData(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since    2.0
	 */
	virtual ~SensorData(void);

	/**
	 * Gets sensor data with @c long value as the key input.
	 *
	 * @since         2.0
	 *
	 * @return        An error code
	 * @param[in]     dataKey          The key to access the sensor data
	 * @param[out]    value            The @c long value representing the sensor data requested by the user
	 * @exception     E_SUCCESS        The method is successful.
	 * @exception     E_INVALID_ARG    The data matching the specified key and data type cannot be found.
	 */
	virtual result GetValue(SensorDataKey dataKey, long& value) const;

	/**
	 * Gets the sensor data with @c float value as the key input.
	 *
	 * @since         2.0
	 *
	 * @return        An error code
	 * @param[in]     dataKey          The key to access the sensor data
	 * @param[out]    value            The @c float value representing the sensor data requested by the user
	 * @exception     E_SUCCESS        The method is successful.
	 * @exception     E_INVALID_ARG    The data matching the specified key and data type cannot be found.
	 */
	virtual result GetValue(SensorDataKey dataKey, float& value) const;

	/**
	 * Gets the sensor data with @c bool value as the key input.
	 *
	 * @since         2.0
	 *
	 * @return        An error code
	 * @param[in]     dataKey          The key to access the sensor data
	 * @param[out]    value            The @c bool value representing the sensor data requested by the user
	 * @exception     E_SUCCESS        The method is successful.
	 * @exception     E_INVALID_ARG    The data matching the specified key and data type cannot be found.
	 */
	virtual result GetValue(SensorDataKey dataKey, bool& value) const;

public:
	/**
	 * The time stamp of the sensor data.
	 *
	 * @since 2.0
	 */
	long long timestamp;

}; // SensorData

} } }// Tizen::Uix::Sensor

#endif // _FUIX_SENSOR_SENSOR_DATA_H_
