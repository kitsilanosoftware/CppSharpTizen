//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 	http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FGrpFloatRectangle.h
 * @brief	This is the header file for the %FloatRectangle class.
 *
 * This header file contains the declarations of the %FloatRectangle class.
 */

#ifndef _FGRP_FLOAT_RECTANGLE_H_
#define _FGRP_FLOAT_RECTANGLE_H_

#include <FBaseObject.h>

namespace Tizen { namespace Graphics
{
class FloatPoint;
class FloatDimension;

/**
 * @class	FloatRectangle
 * @brief	This class abstracts a rectangular region.
 *
 * @since 2.0
 *
 * The %FloatRectangle class represents a rectangular region in a coordinate space, which is specified by the rectangle
 * object's top-left point (x, y) in the coordinate space, along with its width and height.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/graphics/shapes.htm">Shapes</a>.
 */
class _OSP_EXPORT_ FloatRectangle
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * It initializes an instance of %FloatRectangle with all its attributes set to @c 0.f.
	 *
	 * @since 2.0
	 *
	 * @remarks		The attribute value is @c 0 when initialized.
	 */
	FloatRectangle(void);

	/**
	 * This is the copy constructor for the %FloatRectangle class.
	 *
	 * @since 2.0
	 *
	 * @param[in]     rhs                     An instance of %FloatRectangle
	 */
	FloatRectangle(const FloatRectangle& rhs);

	/**
	 * Initializes an instance of %FloatRectangle with the specified location and dimension.
	 *
	 * @since 2.0
	 *
	 * @param[in]	x		The x-coordinate of the top-left corner of the rectangle
	 * @param[in]	y		The y-coordinate of the top-left corner of the rectangle
	 * @param[in]	width	The width of the rectangle
	 * @param[in]	height	The height of the rectangle
	 *
	 */
	FloatRectangle(float x, float y, float width, float height);

	/**
	 * Initializes an instance of %FloatRectangle at the location specified by @c point and
	 * with dimension specified by @c dim.
	 *
	 * @since 2.0
	 *
	 * @param[in]	point		The location of the top-left corner of the rectangle
	 * @param[in]	dim			The width and height of the rectangle
	 */
	FloatRectangle(const FloatPoint& point, const FloatDimension& dim);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~FloatRectangle(void);

	/**
	 * This is the default assignment operator for this class.
	 *
	 * @since 2.0
	 *
	 * @param[in]     rhs                     An instance of %FloatRectangle
	 */
	FloatRectangle& operator=(const FloatRectangle& rhs);

	/**
	 * Checks whether the location and dimension of the current instance of %FloatRectangle match those of the
	 * specified instance of %FloatRectangle.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the location and dimension of the current instance match those of the specified instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %FloatRectangle
	 */
	bool operator==(const FloatRectangle& rhs) const;

	/**
	 * Checks whether the location and dimension of the current instance of %FloatRectangle do not match those of the
	 * specified instance of %FloatRectangle.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the location and dimension of the current instance do not match those of the specified instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %FloatRectangle
	 */
	bool operator!=(const FloatRectangle& rhs) const;

	/**
	 * Checks whether the specified point lies inside the current instance of %FloatRectangle.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the location represented by @c point lies inside the current instance of %FloatRectangle, @n
	 *				else @c false
	 * @param[in]	point	An instance of FloatPoint
	 */
	bool Contains(const FloatPoint& point) const;

	/**
	 * Checks whether the value of the current instance of %FloatRectangle equals the value of the specified instance of
	 * %FloatRectangle.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the value of the current instance of %FloatRectangle equals the value of the specified instance of %FloatRectangle, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %FloatRectangle
	 * @remarks		The %FloatRectangle class has a semantic value, which means that the Equals() method checks whether the
	 *				two instances have the same location and size.
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		The hash value of the current instance
	 * @remarks		Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the intersection of the current instance and the specified instance of %FloatRectangle. @n
	 * If the two instances of %FloatRectangle do not intersect, empty instance is returned.
	 *
	 * @since 2.0
	 *
	 * @param[in]	rect	An instance of %FloatRectangle
	 */
	FloatRectangle GetIntersection(const FloatRectangle& rect) const;

	/**
	 * Checks whether the current instance of %FloatRectangle intersects with the specified instance of %FloatRectangle.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the current instance of %FloatRectangle intersects with the specified instance of %FloatRectangle, @n
	 *				else @c false
	 * @param[in]	rect	An instance of %FloatRectangle
	 *
	 */
	bool IsIntersected(const FloatRectangle& rect) const;

	/**
	 * Gets the union of the current instance and the specified instance of %FloatRectangle.
	 *
	 * @since 2.0
	 *
	 * @return		An instance of %FloatRectangle containing the union of the two rectangles
	 * @param[in]	rect	An instance of %FloatRectangle
	 */
	FloatRectangle GetUnion(const FloatRectangle& rect) const;

	/**
	 * Gets the coordinates of the point at the bottom-right corner of the rectangle.
	 *
	 * @since 2.0
	 *
	 * @return		The coordinates of the point at the bottom-right corner of the rectangle
	 */
	FloatPoint GetBottomRight(void) const;

	/**
	 * Gets the coordinates of the point at the top-left corner of the rectangle.
	 *
	 * @since 2.0
	 *
	 * @return		The coordinates of the point at the top-left corner of the rectangle
	 */
	FloatPoint GetTopLeft(void) const;

	/**
	 * Checks whether this %FloatRectangle is empty. @n
	 * A %FloatRectangle is empty if its width or its height is less than or equal to @c 0.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if this rectangle is empty,	@n
	 *				else @c false
	 */
	bool IsEmpty(void) const;

	/**
	 * Sets the size of this %FloatRectangle to match the specified FloatDimension.
	 *
	 * @since 2.0
	 *
	 * @param[in]	dim		The new size for FloatDimension
	 */
	void SetSize(const FloatDimension& dim);

	/**
	 * Sets the size of this %FloatRectangle to match the specified dimension.
	 *
	 * @since 2.0
	 *
	 * @param[in]	width	The new width
	 * @param[in]	height	The new height
	 */
	void SetSize(float width, float height);

	/**
	 * Sets the position of this %FloatRectangle to the specified point.
	 *
	 * @since 2.0
	 *
	 * @param[in]	point	The new position
	 */
	void SetPosition(const FloatPoint& point);

	/**
	 * Sets the location of the current instance of %FloatRectangle with the specified values of the
	 * x and y coordinates of the top-left corner point.
	 *
	 * @since 2.0
	 *
	 * @param[in]	x		The new x-coordinate
	 * @param[in]	y		The new y-coordinate
	 */
	void SetPosition(float x, float y);

	/**
	 * Sets the location and the dimensions of the current instance of %FloatRectangle with the specified x and y
	 * coordinates of the top-left corner point and the specified dimensions.
	 *
	 * @since 2.0
	 *
	 * @param[in]	x		The new x-coordinate
	 * @param[in]	y		The new y-coordinate
	 * @param[in]	width	The new width
	 * @param[in]	height	The new height
	 */
	void SetBounds(float x, float y, float width, float height);

	/**
	 * Sets the location and the dimensions of the current instance of %FloatRectangle with the specified location and
	 * dimension.
	 *
	 * @since 2.0
	 *
	 * @param[in]	point	An instance of FloatPoint
	 * @param[in]	dim		An instance of FloatDimension
	 */
	void SetBounds(const FloatPoint& point, const FloatDimension& dim);

	/**
	 * Translates this %FloatRectangle to the new point by the specified distance along the x-axis and y-axis.
	 *
	 * @since 2.0
	 *
	 * @param[in]	deltaX	The distance to move this %FloatRectangle along the x-axis
	 * @param[in]	deltaY	The distance to move this %FloatRectangle along the y-axis
	 */
	void Translate(float deltaX, float deltaY);

public:
	/**
	 * The x-coordinate of the top-left corner of the rectangle.
	 *
	 * @since 2.0
	 */
	float x;

	/**
	 * The y-coordinate of the top-left corner of the rectangle.
	 *
	 * @since 2.0
	 */
	float y;

	/**
	 * The width of this rectangle.
	 *
	 * @since 2.0
	 */
	float width;

	/**
	 * The height of this rectangle.
	 *
	 * @since 2.0
	 */
	float height;

private:
	friend class _FloatRectangleImpl;

	//
	// This variable is for internal use only.
	// Using this variable can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	//
	class _FloatRectangleImpl* __pImpl;

}; // FloatRectangle

}} // Tizen::Graphics

#endif // _FGRP_FLOAT_RECTANGLE_H_

