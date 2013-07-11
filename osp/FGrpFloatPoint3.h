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
 * @file	FGrpFloatPoint3.h
 * @brief	This is the header file for the %FloatPoint3 class.
 *
 * This header file contains the declarations of the %FloatPoint3 class.
 *
 */

#ifndef _FGRP_FLOAT_POINT3_H_
#define _FGRP_FLOAT_POINT3_H_

#include <FBaseObject.h>

namespace Tizen { namespace Graphics
{
class FloatVector4;
}}

namespace Tizen { namespace Graphics
{
/**
 * @class	FloatPoint3
 * @brief	This class encapsulates a 3-dimensional point.
 *
 * @since 2.0
 *
 * The %FloatPoint3 class provides a float precision, three-dimensional point class.
 *
 */
class _OSP_EXPORT_ FloatPoint3
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * This constructor initializes the instance to a 3-dimensional zero point.
	 *
	 * @since 2.0
	 */
	FloatPoint3(void);

	/**
	 * This is the copy constructor for the %FloatPoint3 class. @n
	 * This constructor initializes the instance of %FloatPoint3 with the attributes of the specified instance of %FloatPoint3.
	 *
	 * @since 2.0
	 *
	 * @param[in]	rhs	An instance of %FloatPoint3
	 */
	FloatPoint3(const FloatPoint3& rhs);

	/**
	 * This constructor initializes the instance of %FloatPoint3 with the attributes of the specified instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @param[in]	vector	An instance of %FloatVector4
	 * @remarks	The normalized vector can only be converted to point. Therefore, when the input vector is not normalized then the point is converted from the normal vector of the input instance.
	 */
	explicit FloatPoint3(const FloatVector4& vector);

	/**
	 * This constructor initializes the instance of %FloatPoint3 with the attributes of the specified instance of the array.
	 *
	 * @since 2.0
	 *
	 * @param[in]	point	The point with 3 float values
	 */
	explicit FloatPoint3(const float point[3]);

	/**
	 * This constructor initializes the instance of %FloatPoint3 with floating point numbers for each coordinate.
	 *
	 * @since 2.0
	 *
	 * @param[in]	x	x component of point instance
	 * @param[in]	y	y component of point instance
	 * @param[in]	z	z component of point instance
	 */
	FloatPoint3(float x, float y, float z);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~FloatPoint3(void);

	/**
	 * Checks whether the current instance and the specified instance of %FloatPoint3 are equal.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if all members of the current point instance are equal to the corresponding point members in the specified instance, @n
	 *			else @c false
	 * @param[in]	rhs	An instance of %FloatPoint3
	 */
	bool operator ==(const FloatPoint3& rhs) const;

	/**
	 * Checks whether the current instance and the specified instance of %FloatPoint3 are not equal.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if all point members of the current instance are not equal to the corresponding point members in the specified instance, @n
	 *			else @c false
	 * @param[in]	rhs	An instance of %FloatPoint3
	 */
	inline bool operator !=(const FloatPoint3& rhs) const
	{
		return !(*this == rhs);
	}

	/**
	 * Assigns the values of the specified instance to the current instance of %FloatPoint3.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to this instance
	 * @param[in]	rhs	An instance of %FloatPoint3
	 */
	FloatPoint3& operator =(const FloatPoint3& rhs);

	/**
	 * Multiplies the value to each point members of current instance of %FloatPoint3.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatPoint3 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to multiply
	 */
	FloatPoint3 operator *(float value) const;

	/**
	 * Divides each point members of current instance of %FloatPoint3 with the specified value.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatPoint3 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to divide
	 */
	FloatPoint3 operator /(float value) const;

	/**
	 * Adds the value of the specified instance and the current instance of %FloatPoint3.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatPoint3 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatPoint3
	 */
	FloatPoint3 operator +(const FloatPoint3& rhs) const;

	/**
	 * Subtracts the value of the specified instance from the current instance of %FloatPoint3.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatPoint3 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatPoint3
	 */
	FloatPoint3 operator -(const FloatPoint3& rhs) const;

	/**
	 * Adds the value of the specified instance to the current instance of %FloatPoint3.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to %FloatPoint3 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatPoint3
	 */
	FloatPoint3& operator +=(const FloatPoint3& rhs);

	/**
	 * Subtracts the value of the specified instance from the current instance of %FloatPoint3.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to %FloatPoint3 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatPoint3
	 */
	FloatPoint3& operator -=(const FloatPoint3& rhs);

	/**
	 * Checks whether the current instance of %FloatPoint3 equals the specified instance of %FloatPoint3.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if the values of the current instance is equal to the value of the specified instance, @n
	 *			else @c false
	 * @param[in]	obj	An instance of %FloatPoint3
	 * @remarks	This method overrides Tizen::Base::Object::Equals(). This method uses the values of the Point components to compare the two instances.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Gets the hash value of the current instance of %FloatPoint3.
	 *
	 * @since 2.0
	 *
	 * @return	The hash value of the current instance
	 * @remarks	Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * x component of the current instance of %FloatPoint3.
	 *
	 * @since 2.0
	 */
	float x;

	/**
	 * y component of the current instance of %FloatPoint3.
	 *
	 * @since 2.0
	 */
	float y;

	/**
	 * z component of the current instance of %FloatPoint3.
	 *
	 * @since 2.0
	 */
	float z;

private:
	friend class _FloatPoint3Impl;
	class _FloatPoint3Impl* __pImpl;

}; // FloatPoint3

/**
 * Gets the instance of %FloatPoint3 resulting from the product of the value and the specified instance of %FloatPoint3.
 *
 * @since 2.0
 *
 * @return	A new instance of %FloatPoint3 containing the resulting value of the operation
 * @param[in]	value	A @c float value to multiply
 * @param[in]	rhs	An instance of %FloatPoint3
 */
_OSP_EXPORT_ FloatPoint3 operator *(const float& value, const FloatPoint3& rhs);

/**
 * Gets the instance of %FloatPoint3 resulting from the divide of the value and the specified instance of %FloatPoint3.
 *
 * @since 2.0
 *
 * @return	A new instance of %FloatPoint3 containing the resulting value of the operation
 * @param[in]	value	A @c float value to divide
 * @param[in]	rhs	An instance of %FloatPoint3
 */
_OSP_EXPORT_ FloatPoint3 operator /(const float& value, const FloatPoint3& rhs);

}} // Tizen::Graphics

#endif //_FGRP_FLOAT_POINT3_H_
