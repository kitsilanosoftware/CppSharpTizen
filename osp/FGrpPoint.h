//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FGrpPoint.h
 * @brief	This is the header file for the %Point class.
 *
 * This header file contains the declarations of the %Point class.
 */

#ifndef _FGRP_POINT_H_
#define _FGRP_POINT_H_

#include <FBaseObject.h>

namespace Tizen { namespace Graphics
{
/**
 * @class	Point
 * @brief	This class encapsulates a point in a two-dimensional coordinate system.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Point class represents a location in a two-dimensional coordinate space specified with an integer precision.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/graphics/shapes.htm">Shapes</a>.
 */
class _OSP_EXPORT_ Point
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * This initializes an instance of %Point with the values (0, 0).
	 *
	 * @since	2.0
	 */
	Point(void);

	/**
	* This is the copy constructor for the %Point class.
	*
	* @since 2.0
	*
	* @param[in]	rhs		An instance of %Point
	*/
	Point(const Point& rhs);

	/**
	 * Initializes an instance of %Point with the specified location.
	 *
	 * @since			2.0
	 *
	 * @param[in]	x  The x-coordinate
	 * @param[in]	y  The y-coordinate
	 */
	Point(int x, int y);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~Point(void);

	/**
	* Assigns the value of the specified instance to the current instance of %Point.
	*
	* @since 2.0
	*
	* @param[in]	rhs		An instance of %Point
	*/
	Point& operator =(const Point& rhs);

	/**
	 * Checks whether the current instance and the specified instance of %Point are equal.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the two instances of %Point are at the same location, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Point
	 */
	bool operator ==(const Point& rhs) const;

	/**
	 * Checks whether the current instance and the specified instance of %Point are not equal.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the two instances of %Point are at different locations, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Point
	 */
	bool operator !=(const Point& rhs) const;

	/**
	 * Adds the value of the specified instance of %Point and the current instance.
	 *
	 * @since		2.0
	 *
	 * @return		A new instance of %Point containing the resulting value of the operation
	 * @param[in]	rhs		An instance of %Point
	 */
	Point operator +(const Point& rhs) const;

	/**
	 * Subtracts the value of the specified instance of %Point and the current instance.
	 *
	 * @since		2.0
	 *
	 * @return		A new instance of %Point containing the resulting value of the operation
	 * @param[in]	rhs		An instance of %Point
	 */
	Point operator -(const Point& rhs) const;

	/**
	 * Adds the value of the specified instance of %Point to the current instance.
	 *
	 * @since		2.0
	 *
	 * @param[in]	point		An instance of %Point
	 */
	Point& operator +=(const Point& point);

	/**
	 * Subtracts the value of the specified instance of %Point from the current instance.
	 *
	 * @since		2.0
	 *
	 * @param[in]	point		An instance of %Point
	 */
	Point& operator -=(const Point& point);

	/**
	 * Checks whether the value of the specified instance of %Point equals the value of the current instance.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the value of the specified instance equals the value of the current instance, @n
	 *              else @c false
	 * @param[in]	rhs		An instance of %Point
	 * @remarks		The %Point class has a semantic value, which means that the
	 *				Equals() method checks whether the two instances have the same
	 *				location.
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since		2.0
	 *
	 * @return		The hash value of the current instance
	 * @remarks		Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Sets the x and y coordinates for the current instance of %Point.
	 *
	 * @since		2.0
	 *
	 * @param[in]	x	The new x-coordinate
	 * @param[in]	y	The new y-coordinate
	 */
	void SetPosition(int x, int y);

	/**
	 * Sets the current instance of %Point.
	 *
	 * @since		2.0
	 *
	 * @param[in]	point	An instance of %Point
	 */
	void SetPosition(const Point& point);

	/**
	 * Translates this %Point to the indicated distance.
	 *
	 * @since		2.0
	 *
	 * @param[in]	deltaX	The distance to move this point along the x-axis
	 * @param[in]	deltaY	The distance to move this point along the y-axis
	 */
	void Translate(int deltaX, int deltaY);

public:
	/**
	 *	The x-coordinate of the point.
	 *
	 *  @since	2.0
	 */
	int x;

	/**
	 *	The y-coordinate of the point.
	 *
	 *  @since	2.0
	 */
	int y;

private:
	friend class _PointImpl;

	//
	// This variable is for internal use only.
	// Using this variable can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	//
	class _PointImpl * __pImpl;

}; // Point

}} // Tizen::Graphics

#endif // _FGRP_POINT_H_
