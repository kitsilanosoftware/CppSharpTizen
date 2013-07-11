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
* @file		FLocCoordinates.h
* @brief	This is the header file for the %Coordinates class.
*
* This header file contains the declarations of the %Coordinates class.
*/

#ifndef _FLOC_COORDINATES_H_
#define _FLOC_COORDINATES_H_

#include <FBaseObject.h>
#include <FLocTypes.h>

namespace Tizen { namespace Base
{
class String;
}}

namespace Tizen { namespace Locations
{

/**
* @class	Coordinates
* @brief	This class represents a geographical point.
*
* @since 2.0
*
* @final	This class is not intended for extension.
*
* The %Coordinates class represents a geographical point specified by latitude, longitude, and altitude values and provides
* geographic calculations between two points.
*
* The latitude and longitude in decimal degrees are sometimes represented in degrees, minutes, and seconds format. For example, 40.1874 degrees
* can also be represented in "40:11.25"(40 degrees and 11.25 minutes) or "40:11:15.0" (40 degrees, 11 minutes and 15.0 seconds).
* This class provides methods for converting a coordinate value to degrees and minutes or degrees, minutes, and seconds representation.
*/
class _OSP_EXPORT_ Coordinates
	: public Tizen::Base::Object
{
public:
	/**
	* Initializes an instance of %Coordinates with the values of latitude, longitude, and altitude to Not-a-Number.
	*
	* An application should set values of the coordinates using Set() method to specify it.
	*
	* @since 2.0
	*/
	Coordinates(void);

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since 2.0
	*
	* @param[in]	rhs	An instance of %Coordinates to copy
	*/
	Coordinates(const Coordinates& rhs);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since 2.0
	*/
	virtual ~Coordinates(void);

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
	* Sets the latitude, longitude, and altitude values of the coordinates.
	*
	* An application should specify latitude and longitude values in the valid ranges of [-90.0, +90.0] and [-180.0, +180.0], respectively.
	* Otherwise, the %Set() method returns an @c E_INVALID_ARG exception.
	*
	* @since 2.0
	*
	* @return	An error code
	* @param[in]	latitude	The latitude of the coordinates in decimal degrees within the range [-90.0, +90.0]
	* @param[in]	longitude	The longitude of the coordinates in decimal degrees within the range [-180.0, +180.0]
	* @param[in]	altitude	The altitude of the coordinates in meters
	* @exception	E_SUCCESS	This method is successful.
	* @exception	E_INVALID_ARG	The specified @c latitude or @c longitude is invalid.
	* @see		GetLatitude()
	* @see		GetLongitude()
	* @see		GetAltitude()
	*/
	result Set(double latitude, double longitude, double altitude);

	/**
	* Sets the latitude value of the coordinates.
	*
	* An application should specify latitude value in the valid range of [-90.0, +90.0].
	* Otherwise, the %SetLatitude() method returns an @c E_INVALID_ARG exception.
	*
	* @since 2.0
	*
	* @return	An error code
	* @param[in]	latitude	The latitude of the coordinates in decimal degrees within the range [-90.0, +90.0]
	* @exception	E_SUCCESS	This method is successful.
	* @exception	E_INVALID_ARG	The specified @c latitude is invalid.
	* @see		GetLatitude()
	*/
	result SetLatitude(double latitude);

	/**
	* Sets the longitude value of the coordinates.
	*
	* An application should specify longitude value in the valid range of [-180.0, +180.0].
	* Otherwise, the %SetLongitude() method returns an @c E_INVALID_ARG exception.
	*
	* @since 2.0
	*
	* @return	An error code
	* @param[in]	longitude	The longitude of the coordinates in decimal degrees within the range [-180.0, +180.0]
	* @exception	E_SUCCESS	This method is successful.
	* @exception	E_INVALID_ARG	The specified @c longitude is invalid.
	* @see		GetLongitude()
	*/
	result SetLongitude(double longitude);

	/**
	* Sets the altitude value of the coordinates.
	*
	* @since 2.0
	*
	* @param[in]	altitude	The altitude of the coordinates in meters
	* @see		GetAltitude()
	*/
	void SetAltitude(double altitude);

	/**
	* Gets the latitude value of the coordinates.
	*
	* @since 2.0
	*
	* @return	The latitude in decimal degrees within the range [-90.0, +90.0], @n
	*			else @c NaN if it is not available
	* @see		SetLatitude()
	*/
	double GetLatitude(void) const;

	/**
	* Gets the longitude value of the coordinates.
	*
	* @since 2.0
	*
	* @return	The longitude in decimal degrees within the range [-180.0, +180.0], @n
	*			else @c NaN if it is not available
	* @see		SetLongitude()
	*/
	double GetLongitude(void) const;

	/**
	* Gets the altitude value of the coordinates.
	*
	* @since 2.0
	*
	* @return	The altitude in meters, @n
	*			else @c NaN if it is not available
	* @see		SetAltitude()
	*/
	double GetAltitude(void) const;

	/**
	* Calculates the azimuth value.
	*
	* The coordinates are the starting point and @c dest is the destination for the azimuth calculation.
	* The azimuth is measured clockwise from true north based on the WGS84 ellipsoid model.
	*
	* The altitude value is not considered in calculation.
	*
	* @since 2.0
	*
	* @return	The azimuth value in decimal degrees within the range [0.0, +360.0], @n
	*			else @c NaN if the latitude or the longitude of two points has an @c NaN value
	* @param[in]	dest The destination coordinates
	*/
	double GetAzimuth(const Coordinates& dest) const;

	/**
	* Calculates the geodetic distance to the given coordinates.
	*
	* The distance calculation is based on the WGS84 ellipsoid model.
	*
	* The altitude value is not considered in calculation.
	*
	* @since 2.0
	*
	* @return	The distance to the given coordinates in meters, @n
	*			else @c NaN if the latitude or the longitude of two points has an @c NaN value
	* @param[in]	to The destination coordinates
	*/
	double GetDistanceTo(const Coordinates& to) const;

	/**
	* Converts the coordinate value into string.
	*
	* An application specifies formats like @c COORDINATE_FORMAT_DEGREE_MINUTE or @c COORDINATE_FORMAT_DEGREE_MINUTE_SECOND for the result string.
	*
	* @since 2.0
	*
	* @return	An error code
	* @param[in]	degree	The coordinate in degrees within the range [-180.0, +180.0]
	* @param[in]	format	The desired format
	* @param[out]	string	The converted result in string
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_INVALID_ARG	The specified @c degree or @c format is invalid.
	* @see		Parse()
	*/
	static result ToString(double degree, CoordinateFormat format, Tizen::Base::String& string);

	/**
	* Converts a string into coordinate degree.
	*
	* The @c string should be in @c COORDINATE_FORMAT_DEGREE_MINUTE or @c COORDINATE_FORMAT_DEGREE_MINUTE_SECOND format.
	*
	* @since 2.0
	*
	* @return	An error code
	* @param[in]	string	The string in degree-minute or degree-minute-second representation
	* @param[out]	degree	The converted result in decimal degrees
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_INVALID_ARG	The specified @c string is not in CoordinateFormat.
	* @see		ToString()
	*/
	static result Parse(const Tizen::Base::String& string, double& degree);

	/**
	* Copying of objects using this copy assignment operator is allowed.
	*
	* @since 2.0
	*
	* @return	A reference to the current instance
	* @param[in]	rhs	An instance of %Coordinates to assign
	*/
	Coordinates& operator =(const Coordinates& rhs);

private:
	double __latitude;
	double __longitude;
	double __altitude;

	class _CoordinatesImpl* __pImpl;
	friend class _CoordinatesImpl;
}; // Coordinates
}} // Tizen::Locations
#endif // _FLOC_COORDINATES_H_
