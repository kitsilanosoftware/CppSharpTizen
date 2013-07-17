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
* @file		FLocTypes.h
* @brief	This is the header file for the types and constants in the Locations namespace.
*
* This header file contains the declarations for the types and constants in the Locations namespace.
*/

#ifndef _FLOC_TYPES_H_
#define _FLOC_TYPES_H_

namespace Tizen { namespace Locations
{
/**
* A region ID that identifies a monitoring region registered to LocationProvider.
*
* @since 2.0
*/
typedef int RegionId;

/**
* @enum CoordinateFormat
*
* Defines the format for angle representation in degrees, minutes, and seconds.
*
* @since 2.0
*/
enum CoordinateFormat
{
	COORDINATE_FORMAT_DEGREE_MINUTE = 0, /**< The "DD:MM.mm" format, where DD is degrees, MM is minutes, and mm is decimal fraction of a minute */
	COORDINATE_FORMAT_DEGREE_MINUTE_SECOND, /**< The "DD:MM:SS.ss" format, where DD is degrees, MM is minutes, SS is seconds, and ss is decimal fraction of a second */
};

/**
* @enum	LocationAccuracy
*
* Defines the accuracy of the location.
*
* @since 2.0
*/
enum LocationAccuracy
{
	LOC_ACCURACY_INVALID = 0, /**< Invalid accuracy @n The location provider uses this value when the location is not available. */
	LOC_ACCURACY_FINEST, /**< The accuracy of the location is the finest that the location provider provides */
	LOC_ACCURACY_TEN_METERS, /**< The accuracy of the location is under 10 meters */
	LOC_ACCURACY_HUNDRED_METERS, /**< The accuracy of the location is under 100 meters */
	LOC_ACCURACY_ONE_KILOMETER, /**< The accuracy of the location is under 1 kilometer */
	LOC_ACCURACY_ANY, /**< The accuracy of the location can be anything that the location provider provides */
};

/**
* @enum	LocationServiceStatus
*
* Defines the location service status that the location provider provides.
*
* @since 2.0
*/
enum LocationServiceStatus
{
	LOC_SVC_STATUS_IDLE = 0, /**< The status of the location service is idle */
	LOC_SVC_STATUS_RUNNING, /**< The location provider is successfully running the requested service */
	LOC_SVC_STATUS_PAUSED, /**< The location provider has paused the location service */
	LOC_SVC_STATUS_DENIED, /**< The location provider is unable to provide services because the user restricted the use of location service */
	LOC_SVC_STATUS_NOT_FIXED, /**< The location provider is trying to run the service by fixing the current location */
};
}} // Tizen::Locations
#endif // _FLOC_TYPES_H_
