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
* @file		FUixSensor.h
* @brief    This is the header file for the %Sensor namespace.
*
* This header file contains the declarations and descriptions of the %Sensor namespace.
*/

#ifndef _FUIX_SENSOR_H_
#define _FUIX_SENSOR_H_

#include <FUixSensorSensorData.h>
#include <FUixSensorAccelerationSensorData.h>
#include <FUixSensorMagneticSensorData.h>
#include <FUixSensorProximitySensorData.h>
#include <FUixSensorTiltSensorData.h>
#include <FUixSensorGyroSensorData.h>
#include <FUixSensorLightSensorData.h>
#include <FUixSensorGravitySensorData.h>
#include <FUixSensorUserAccelerationSensorData.h>
#include <FUixSensorDeviceOrientationSensorData.h>
#include <FUixSensorISensorEventListener.h>
#include <FUixSensorMotion.h>
#include <FUixSensorSensorManager.h>


/**
 * @namespace    Tizen::Uix::Sensor
 * @brief        This namespace contains %Sensor classes and %Tizen interfaces.
 * @since        2.0
 *
 * @remarks    @b Header @b %file: @b \#include @b <FUix.h> @n
 *             @b Library :  @b osp-uix
 *
 * The %Sensor namespace contains classes and interfaces for the %Sensor services, user control sensor and access data of each sensor.
 *
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Sensor namespace.
 * @image html uix_sensor_namespace_classdiagram.png

 */
namespace Tizen { namespace Uix { namespace Sensor
{

} } } // Tizen::Uix::Sensor

#endif // _FUIX_SENSOR_H_
