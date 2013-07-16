//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FGrpRectangle.h
 * @brief	This is the header file for the %Rectangle class.
 *
 * This header file contains the declarations of the %Rectangle class.
 */

#ifndef _FGRP_RECTANGLE_H_
#define _FGRP_RECTANGLE_H_

#include <FBaseObject.h>

namespace Tizen { namespace Graphics
{
class Point;
class Dimension;

/**
 * @class	Rectangle
 * @brief	This class abstracts a rectangular region.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Rectangle class represents a rectangular region in a coordinate space, which is specified by the rectangle
 * object's top-left point (x, y) in the coordinate space, along with its width and height.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/graphics/shapes.htm">Shapes</a>.
 */
class _OSP_EXPORT_ Rectangle
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * It initializes an instance of %Rectangle with all its attributes set to @c 0.
	 *
	 * @since		2.0
	 *
	 * @remarks		The attribute value is @c 0 when initialized.
	 */
	Rectangle(void);

	/**
	* This is the copy constructor for the %Rectangle class.
	*
	* @since 2.0
	*
	* @param[in]	rhs		An instance of %Rectangle
	*/
	Rectangle(const Rectangle& rhs);

	/**
	 * Initializes an instance of %Rectangle with the specified location and dimension.
	 *
	 * @since		2.0
	 *
	 * @param[in]	x		The x-coordinate of the top-left corner of the rectangle
	 * @param[in]	y		The y-coordinate of the top-left corner of the rectangle
	 * @param[in]	width	The width of the rectangle
	 * @param[in]	height	The height of the rectangle
	 *
	 */
	Rectangle(int x, int y, int width, int height);

	/**
	 * Initializes an instance of %Rectangle at the location specified by @c point and
	 * with dimension specified by @c dim.
	 *
	 * @since		2.0
	 *
	 * @param[in]	point		The location of the top-left corner of the rectangle
	 * @param[in]	dim			The width and height of the rectangle
	 */
	Rectangle(const Point& point, const Dimension& dim);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~Rectangle(void);

	/**
	* Assigns the value of the specified instance to the current instance of %Rectangle.
	*
	* @since 2.0
	*
	* @param[in]	rhs		An instance of %Rectangle
	*/
	Rectangle& operator =(const Rectangle& rhs);

	/**
	 * Checks whether the location and dimension of the current instance of %Rectangle match those of the
	 * specified instance of %Rectangle.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the location and dimension of the current instance match those of the specified instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Rectangle
	 */
	bool operator ==(const Rectangle& rhs) const;

	/**
	 * Checks whether the location and dimension of the current instance of %Rectangle do not match those of the
	 * specified instance of %Rectangle.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the location and dimension of the current instance do not match those of the specified instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Rectangle
	 */
	bool operator !=(const Rectangle& rhs) const;

	/**
	 * Checks whether the specified point lies inside the current instance of %Rectangle.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the location represented by @c point lies inside the current instance of %Rectangle, @n
	 *				else @c false
	 * @param[in]	point	An instance of %Point
	 */
	bool Contains(const Point& point) const;

	/**
	 * Checks whether the value of the current instance of %Rectangle equals the value of the specified instance of
	 * %Rectangle.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the value of the current instance of %Rectangle equals the value of the specified instance of %Rectangle, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Rectangle
	 * @remarks		The %Rectangle class has a semantic value, which means that the Equals() method checks whether the
	 *				two instances have the same location and size.
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the intersection of the current instance and the specified instance of %Rectangle. @n
	 * If the two instances of %Rectangle do not intersect, empty instance is returned.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rect	An instance of %Rectangle
	 */
	Rectangle GetIntersection(const Rectangle& rect) const;

	/**
	 * Checks whether the current instance of %Rectangle intersects with the specified instance of %Rectangle.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the current instance of %Rectangle intersects with the specified instance of %Rectangle, @n
	 *				else @c false
	 * @param[in]	rect	An instance of %Rectangle
	 *
	 */
	bool IsIntersected(const Rectangle& rect) const;

	/**
	 * Gets the union of the current instance and the specified instance of %Rectangle.
	 *
	 * @since		2.0
	 *
	 * @return		An instance of %Rectangle containing the union of the two rectangles
	 * @param[in]	rect	An instance of %Rectangle
	 */
	Rectangle GetUnion(const Rectangle& rect) const;

	/**
	 * Gets the coordinates of the point at the bottom-right corner of the rectangle.
	 *
	 * @since		2.0
	 *
	 * @return		The coordinates of the point at the bottom-right corner of the rectangle
	 */
	Point GetBottomRight(void) const;

	/**
	 * Gets the coordinates of the point at the top-left corner of the rectangle.
	 *
	 * @since		2.0
	 *
	 * @return		The coordinates of the point at the top-left corner of the rectangle
	 */
	Point GetTopLeft(void) const;

	/**
	 * Checks whether this %Rectangle is empty. @n
	 * A %Rectangle is empty if its width or its height is less than or equal to @c 0.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if this rectangle is empty,	@n
	 *				else @c false
	 */
	bool IsEmpty(void) const;

	/**
	 * Sets the size of this %Rectangle to match the specified Dimension.
	 *
	 * @since		2.0
	 *
	 * @param[in]	dim		The new size for the Dimension
	 */
	void SetSize(const Dimension& dim);

	/**
	 * Sets the size of this %Rectangle to match the specified dimension.
	 *
	 * @since		2.0
	 *
	 * @param[in]	width	The new width
	 * @param[in]	height	The new height
	 */
	void SetSize(int width, int height);

	/**
	 * Sets the position of this %Rectangle to the specified point.
	 *
	 * @since		2.0
	 *
	 * @param[in]	point	The new position
	 */
	void SetPosition(const Point& point);

	/**
	 * Sets the location of the current instance of %Rectangle with the specified values of the
	 * x and y coordinates of the top-left corner point.
	 *
	 * @since		2.0
	 *
	 * @param[in]	x		The new x-coordinate
	 * @param[in]	y		The new y-coordinate
	 */
	void SetPosition(int x, int y);

	/**
	 * Sets the location and the dimensions of the current instance of %Rectangle with the specified x and y
	 * coordinates of the top-left corner point and the specified dimensions.
	 *
	 * @since		2.0
	 *
	 * @param[in]	x		The new x coordinate
	 * @param[in]	y		The new y coordinate
	 * @param[in]	width	The new width
	 * @param[in]	height	The new height
	 */
	void SetBounds(int x, int y, int width, int height);

	/**
	 * Sets the location and the dimensions of the current instance of %Rectangle with the specified location and
	 * dimension.
	 *
	 * @since		2.0
	 *
	 * @param[in]	point	An instance of Point
	 * @param[in]	dim		An instance of Dimension
	 */
	void SetBounds(const Point& point, const Dimension& dim);

	/**
	 * Translates this %Rectangle to the new point by the specified distance along the x-axis and y-axis.
	 *
	 * @since		2.0
	 *
	 * @param[in]	deltaX	The distance to move this %Rectangle along the x-axis
	 * @param[in]	deltaY	The distance to move this %Rectangle along the y-axis
	 */
	void Translate(int deltaX, int deltaY);

public:
	/**
	 * The x-coordinate of the top-left corner of the rectangle.
	 *
	 * @since	2.0
	 */
	int x;

	/**
	 * The y-coordinate of the top-left corner of the rectangle.
	 *
	 * @since	2.0
	 */
	int y;

	/**
	 * The width of this rectangle.
	 *
	 * @since	2.0
	 */
	int width;

	/**
	 * The height of this rectangle.
	 *
	 * @since	2.0
	 */
	int height;

private:
	friend class _RectangleImpl;

	//
	// This variable is for internal use only.
	// Using this variable can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	//
	class _RectangleImpl * __pImpl;

}; // Rectangle

}} // Tizen::Graphics

#endif // _FGRP_RECTANGLE_H_
