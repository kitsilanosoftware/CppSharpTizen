//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FGrpFloatVector4.h
 * @brief	This is the header file for the %FloatVector4 class.
 *
 * This header file contains the declarations of the %FloatVector4 class.
 *
 */

#ifndef _FGRP_FLOAT_VECTOR4_H_
#define _FGRP_FLOAT_VECTOR4_H_

#include <FBaseObject.h>

namespace Tizen { namespace Graphics
{
class FloatPoint3;
class FloatMatrix4;
}}

namespace Tizen { namespace Graphics
{
/**
 * @class	FloatVector4
 * @brief	This class encapsulates a 4-dimensional vector.
 *
 * @since 2.0
 *
 * The %FloatVector4 class provides a float precision, four-dimensional vector class.
 *
 */
class _OSP_EXPORT_ FloatVector4
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * This constructor initializes the instance to a 4-dimensional zero vector.
	 *
	 * @since 2.0
	 */
	FloatVector4(void);

	/**
	 * This is the copy constructor for the %FloatVector4 class. @n
	 * This constructor initializes the instance of %FloatVector4 with the attributes of the specified instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @param[in]	rhs	An instance of %FloatVector4
	 */
	FloatVector4(const FloatVector4& rhs);

	/**
	 * This constructor initializes the instance of %FloatVector4 with the attributes of the specified instance of %FloatPoint3.
	 *
	 * @since 2.0
	 *
	 * @param[in]	point	An instance of %FloatPoint3
	 * @remarks	The point is converted to normal vector.
	 */
	explicit FloatVector4(const FloatPoint3& point);

	/**
	 * This constructor initializes the instance of %FloatVector4 with the attributes of the specified instance of the array.
	 *
	 * @since 2.0
	 *
	 * @param[in]	vector	The vector with 4 float values
	 */
	explicit FloatVector4(const float vector[4]);

	/**
	 * This constructor initializes the instance of %FloatVector4 with floating point numbers for each coordinate.
	 *
	 * @since 2.0
	 *
	 * @param[in]	x	x component of vector instance
	 * @param[in]	y	y component of vector instance
	 * @param[in]	z	z component of vector instance
	 * @param[in]	w	w component of vector instance
	 */
	FloatVector4(float x, float y, float z, float w);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~FloatVector4(void);

	/**
	 * Checks whether the current instance and the specified instance of %FloatVector4 are equal.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if all members of the current vector instance are equal to the corresponding vector members in the specified instance, @n
	 *			else @c false
	 * @param[in]	rhs	An instance of %FloatVector4
	 */
	bool operator ==(const FloatVector4& rhs) const;

	/**
	 * Checks whether the current instance and the specified instance of %FloatVector4 are not equal.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if all vector members of the current instance are not equal to the corresponding vector members in the specified instance, @n
	 *			else @c false
	 * @param[in]	rhs	An instance of %FloatVector4
	 */
	inline bool operator !=(const FloatVector4& rhs) const
	{
		return !(*this == rhs);
	}

	/**
	 * Assigns the values of the specified instance to the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to this instance
	 * @param[in]	rhs	An instance of %FloatVector4
	 */
	FloatVector4& operator =(const FloatVector4& rhs);

	/**
	 * Multiplies the value to each vector members of current instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatVector4 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to multiply
	 */
	FloatVector4 operator *(float value) const;

	/**
	 * Divides each vector members of current instance of %FloatVector4 with the specified value.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatVector4 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to divide
	 */
	FloatVector4 operator /(float value) const;

	/**
	 * Adds the value of the specified instance and the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatVector4 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatVector4
	 */
	FloatVector4 operator +(const FloatVector4& rhs) const;

	/**
	 * Subtracts the value of the specified instance from the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatVector4 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatVector4
	 */
	FloatVector4 operator -(const FloatVector4& rhs) const;

	/**
	 * Adds the value of the specified instance to the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to %FloatVector4 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatVector4
	 */
	FloatVector4& operator +=(const FloatVector4& rhs);

	/**
	 * Subtracts the value of the specified instance from the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to %FloatVector4 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatVector4
	 */
	FloatVector4& operator -=(const FloatVector4& rhs);

	/**
	 * Calculates the dot product with the specified instance and the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @return	The value of the operation.
	 * @param[in]	rhs	An instance of %FloatVector4
	 */
	float DotProduct(const FloatVector4& rhs) const;

	/**
	 * Calculates the dot product with the specified instance and the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @return	The value of the operation.
	 * @param[in]	rhs	An instance of %FloatVector4
	 */
	float operator *(const FloatVector4& rhs) const;

	/**
	 * Checks whether the current instance of %FloatVector4 equals the specified instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if the values of the current instance is equal to the value of the specified instance, @n
	 *			else @c false
	 * @param[in]	obj	An instance of %FloatVector4
	 * @remarks	This method overrides Tizen::Base::Object::Equals(). This method uses the values of the Vector components to compare the two instances.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Gets the hash value of the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @return	The hash value of the current instance
	 * @remarks	Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the length of the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @return	The length of the current instance
	 */
	float GetLength(void) const;

	/**
	 * Gets the normal vector of the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatVector4 containing the resulting value of the operation
	 */
	FloatVector4 GetNormal(void) const;

	/**
	 * Normalize the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 */
	void Normalize(void);

	/**
	 * x component of the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 */
	float x;

	/**
	 * y component of the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 */
	float y;

	/**
	 * z component of the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 */
	float z;

	/**
	 * w component of the current instance of %FloatVector4.
	 *
	 * @since 2.0
	 */
	float w;

private:
	friend class _FloatVector4Impl;
	class _FloatVector4Impl* __pImpl;

}; // FloatVector4

/**
 * Gets the instance of %FloatVector4 resulting from the product of the value and the specified instance of %FloatVector4.
 *
 * @since 2.0
 *
 * @return	A new instance of %FloatVector4 containing the resulting value of the operation
 * @param[in]	value	A @c float value to multiply
 * @param[in]	rhs	An instance of %FloatVector4
 */
_OSP_EXPORT_ FloatVector4 operator *(const float& value, const FloatVector4& rhs);

/**
 * Gets the instance of %FloatVector4 resulting from the divide of the value and the specified instance of %FloatVector4.
 *
 * @since 2.0
 *
 * @return	A new instance of %FloatVector4 containing the resulting value of the operation
 * @param[in]	value	A @c float value to divide
 * @param[in]	rhs	An instance of %FloatVector4
 */
_OSP_EXPORT_ FloatVector4 operator /(const float& value, const FloatVector4& rhs);

}} // Tizen::Graphics

#endif //_FGRP_FLOAT_VECTOR4_H_
