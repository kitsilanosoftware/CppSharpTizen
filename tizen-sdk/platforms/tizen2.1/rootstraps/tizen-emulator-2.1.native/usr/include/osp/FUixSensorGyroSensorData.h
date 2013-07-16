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
 * @file     FUixSensorGyroSensorData.h
 * @brief    This is the header file for the %GyroSensorData class.
 *
 * This header file contains the declarations of the %GyroSensorData class.
 */

#ifndef _FUIX_SENSOR_GYRO_SENSOR_DATA_H_
#define _FUIX_SENSOR_GYRO_SENSOR_DATA_H_

#include <FOspConfig.h>
#include <FUixSensorSensorData.h>

namespace Tizen { namespace Uix  { namespace Sensor
{
/**
 * @class    GyroSensorData
 * @brief    This class stores gyro sensor data, including a time stamp.
 *
 * @since 2.0
 *
 * @remarks      @b Header @b %file: @b \#include @b <FUix.h> @n
 *               @b Library : @b osp-uix
 *
 * The %GyroSensorData class stores gyro sensor data, including a time stamp.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/uix/sensor_manager.htm">Sensor Manager</a>.
 */
class _OSP_EXPORT_ GyroSensorData
	: public Tizen::Uix::Sensor::SensorData
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	GyroSensorData(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~GyroSensorData(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since		2.1
	 *
	 * @param[in]	rhs	An instance of %GyroSensorData
	 */
	GyroSensorData(const GyroSensorData& rhs);

	/**
	 * Compares the equality of values between two %GyroSensorData objects by overriding the Tizen::Base::Object::Equals() method.
	 *
	 * @since          2.1
	 *
	 * @return         @c true if all the fields in the objects are equal, @n
	 *                     else @c false
	 * @param[in]    rhs     The Tizen::Base::Object with which the comparison is done
 	 * @remarks		An instance of Tizen::Graphics::Bitmap is not taken into account in the comparisons.
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance by overriding the Tizen::Base::Object::GetHashCode() method.
	 *
	 * @since         2.1
	 *
	 * @return        The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since          2.1
	 *
	 * @return         A reference to this instance
	 * @param[in]    rhs An instance of %GyroSensorData
	 */
	GyroSensorData& operator =(const GyroSensorData& rhs);



private:
	virtual result GetValue(SensorDataKey dataKey, long& value) const;
	virtual result GetValue(SensorDataKey dataKey, float& value) const;
	virtual result GetValue(SensorDataKey dataKey, bool& value) const;

public:
	/**
	 * The x-axis value of the gyro sensor data
	 *
	 * @since 2.0
	 */
	float x;

	/**
	 * The y-axis value of the gyro sensor data
	 *
	 * @since 2.0
	 */
	float y;

	/**
	 * The z-axis value of the gyro sensor data
	 *
	 * @since 2.0
	 */
	float z;
}; // GyroSensorData
} } }// Tizen::Uix::Sensor

#endif // _FUIX_SENSOR_GYRO_SENSOR_DATA_H_
