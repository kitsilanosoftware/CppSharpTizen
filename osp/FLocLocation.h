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
 * @file	FLocLocation.h
 * @brief	This is the header file for the %Location class.
 *
 * This header file contains the declarations of the %Location class.
 */

#ifndef _FLOC_LOCATION_H_
#define _FLOC_LOCATION_H_

#include <FBaseObject.h>

namespace Tizen { namespace Base
{
class String;
class DateTime;
}}

namespace Tizen { namespace Locations
{
class Coordinates;

/**
* @class	Location
* @brief	This class contains and provides information about a location including its geographical coordinates, altitude, and so on.
*
* @since 2.0
*
* @final	This class is not intended for extension.
*
* The %Location class contains all information about a location that the location provider fixed at a certain moment.
* It basically provides geographical coordinates and horizontal accuracy that gives the estimated error about the coordinates,
* while the altitude, vertical accuracy, speed, and course at the location are optionally provided.
* It also contains detailed and specific positioning information, such as satellites used to fix the location.
*
* An application obtains the %Location instances from LocationProvider.
*/
class _OSP_EXPORT_ Location
	: public Tizen::Base::Object
{
public:
	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since 2.0
	*
	* @param[in]	rhs	An instance of %Location to copy
	*/
	Location(const Location& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~Location(void);

	/**
	* Compares the calling instance with the specified instance for equality.
	*
	* @since 2.0
	*
	* @return	@c true if all the fields in the objects are equal, @n
	*			else @c false
	* @param[in]	rhs	The object to compare
	*/
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	* Gets the hash value of the calling instance.
	*
	* @since 2.0
	*
	* @return	The hash value of the calling instance
	*/
	virtual int GetHashCode(void) const;

	/**
	* Gets the horizontal accuracy.
	*
	* @since 2.0
	*
	* @return	The horizontal accuracy in meters, @n
	*			else @c NaN if it is not available
	*/
	double GetHorizontalAccuracy(void) const;

	/**
	* Gets the vertical accuracy.
	*
	* @since 2.0
	*
	* @return	The vertical accuracy in meters, @n
	*			else @c NaN if it is not available
	*/
	double GetVerticalAccuracy(void) const;

	/**
	* Gets the course.
	*
	* The course is the angle of moving direction measured clockwise from true north.
	*
	* @since 2.0
	*
	* @return	The course in degrees within the range [0.0, +360.0], @n
	*			else @c NaN if it is not available
	*/
	double GetCourse(void) const;

	/**
	* Gets the coordinates.
	*
	* @since 2.0
	*
	* @return	The geographical coordinates
	*/
	Coordinates GetCoordinates(void) const;

	/**
	* Gets the ground speed.
	*
	* @since 2.0
	*
	* @return	The speed in km/h, @n
	*			else @c NaN if it is not available
	*/
	double GetSpeed(void) const;

	/**
	* Gets the timestamp when this location is fixed.
	*
	* @since 2.0
	*
	* @return	The fix time in UTC
	*/
	Tizen::Base::DateTime GetTimestamp(void) const;

	/**
	* Gets the detailed positioning information.
	*
	* The detailed positioning information is queried using a key, and the %GetExtraInfo() method returns the information corresponding to the key.
	* <table>
	    <tr><th>Key</th><th>Information</th></tr>
	    <tr><td>location_method</td><td>Positioning technology used to fix this location. Possible values are "gps" and "network".</td></tr>
	    <tr><td>satellite</td>
	            <td>GPS satellite information in the semicolon-separated satellite sentences.
	            Each sentence forms "PRN, Elevation, Azimuth, SNR, Active" where PRN is a satellite ID, Elevation is in degree, Azimuth is in degree,
	            SNR is a signal to nose ratio in dBHZ, and Active is @c 1, if the satellite is in use for positioning, or @c 0.
	            For example, it can be "02, 40.0, 83.0, 35.0, 1; 15, 30.0, 65.0, 35.0, 0; 22, 80.0, 120.0, 40.0, 1;".</td>
	    </tr></table>
	*
	* @since 2.0
	*
	* @return         The information corresponding to the key, @n
	*                 else an empty string if the @c key is invalid or the requested information is not available for this location
	* @param[in]     key       The key to the positioning information
	*/
	Tizen::Base::String GetExtraInfo(const Tizen::Base::String& key) const;

	/**
	* Checks the validity for this location.
	*
	* @since 2.0
	*
	* @return	@c true if the location is valid, @n
	*			else @c false
	*/
	bool IsValid(void) const;

	/**
	* Copying of objects using this copy assignment operator is allowed.
	*
	* @since 2.0
	*
	* @return	A reference to the current instance
	* @param[in]	rhs	An instance of %Location to assign
	*/
	Location& operator =(const Location& rhs);

private:
	//
	// This default constructor is intentionally declared as private so that only the platform can create an instance.
	//
	// @since 2.0
	//
	Location(void);

private:
	class _LocationImpl* __pImpl;
	friend class _LocationImpl;
}; // Location
}} // Tizen::Locations
#endif // _FLOC_LOCATION_H_
