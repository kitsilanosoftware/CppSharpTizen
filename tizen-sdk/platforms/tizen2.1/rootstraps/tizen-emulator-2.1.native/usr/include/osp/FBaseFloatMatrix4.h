//
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
 * @file	FBaseFloatMatrix4.h
 * @brief	This is the header file for the %FloatMatrix4 class.
 *
 * This header file contains the declarations of the %FloatMatrix4 class.
 *
 */

#ifndef _FBASE_FLOAT_MATRIX4_H_
#define _FBASE_FLOAT_MATRIX4_H_

#include <FBase.h>
#include <FBaseTypes.h>
#include <FBaseObject.h>

namespace Tizen { namespace Base
{
/**
 * @class	FloatMatrix4
 * @brief	This class encapsulates a 4 X 4 matrix.
 *
 * @since 2.0
 *
 * The %FloatMatrix4 class provides a @c float precision, two-dimensional matrix class.
 *
 */
class _OSP_EXPORT_ FloatMatrix4
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class. @n
	 * Constructs a 4 X 4 null matrix in which all elements are zero.
	 *
	 * @since 2.0
	 */
	FloatMatrix4(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	FloatMatrix4(const FloatMatrix4& rhs);

	/**
	 * Constructs a 4 by 4 matrix initialized to the value in the specified array.
	 *
	 * @since 2.0
	 *
	 * @param[in]	matrix	The matrix with 16 @c float values
	 */
	FloatMatrix4(const float matrix[4][4]);

	/**
	 * TThis destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~FloatMatrix4(void);

	/**
	 * Checks whether the current instance and the specified instance of %FloatMatrix4 are equal.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if all matrix members of the current instance are equal to the corresponding matrix members in the specified instance, @n
	 *			else @c false
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	bool operator ==(const FloatMatrix4& rhs) const;

	/**
	 * Checks whether the current instance and the specified instance of %FloatMatrix4 are not equal.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if all matrix members of the current instance are not equal to the corresponding matrix members in the specified instance, @n
	 *			else @c false
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	bool operator !=(const FloatMatrix4& rhs) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to this instance
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	FloatMatrix4& operator =(const FloatMatrix4& rhs);

	/**
	 * Assigns the value of the specified instance to the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to this instance
	 * @param[in]	value	A @c float value to assign
	 */
	FloatMatrix4& operator =(float value);

	/**
	 * Multiplies the value of the specified instance with the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	FloatMatrix4 operator *(const FloatMatrix4& rhs) const;

	/**
	 * Multiplies the value to each matrix members of current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to multiply
	 */
	FloatMatrix4 operator *(float value) const;

	/**
	 * Adds the value of the specified instance and the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	FloatMatrix4 operator +(const FloatMatrix4& rhs) const;

	/**
	 * Adds the value to each matrix members of current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to add
	 */
	FloatMatrix4 operator +(float value) const;

	/**
	 * Subtracts the value of the specified instance and the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	FloatMatrix4 operator -(const FloatMatrix4& rhs) const;

	/**
	 * Subtracts the value from each matrix members of current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to subtract
	 */
	FloatMatrix4 operator -(float value) const;

	/**
	 * Multiplies the value of the specified instance and the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	FloatMatrix4& operator *=(const FloatMatrix4& rhs);

	/**
	 * Multiplies the value to each matrix members of current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to multiply
	 */
	FloatMatrix4& operator *=(float value);

	/**
	 * Adds the value of the specified instance to the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	FloatMatrix4& operator +=(const FloatMatrix4& rhs);

	/**
	 * Adds the value to each matrix members of current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to add
	 */
	FloatMatrix4& operator +=(float value);

	/**
	 * Subtracts the value of the specified instance from the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	FloatMatrix4& operator -=(const FloatMatrix4& rhs);

	/**
	 * Subtracts the value from each matrix members of current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to subtract
	 */
	FloatMatrix4& operator -=(float value);

	/**
	 * Gets the instance of %FloatMatrix4 resulting from the sum of the value and the specified instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to add
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	_OSP_EXPORT_ friend FloatMatrix4 operator +(const float& value, const FloatMatrix4& rhs);

	/**
	 * Gets the instance of %FloatMatrix4 resulting from the product of the value and the specified instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to multiply
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	_OSP_EXPORT_ friend FloatMatrix4 operator *(const float& value, const FloatMatrix4& rhs);

	/**
	 * Gets the instance of %FloatMatrix4 resulting from the difference between the value and the specified instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatMatrix4 containing the resulting value of the operation
	 * @param[in]	value	A @c float value to subtract
	 * @param[in]	rhs	An instance of %FloatMatrix4
	 */
	_OSP_EXPORT_ friend FloatMatrix4 operator -(const float& value, const FloatMatrix4& rhs);

	/**
	 * Checks whether the current instance of %FloatMatrix4 equals the specified instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if the values of the current instance is equal to the value of the specified instance, @n
	 *			else @c false
	 * @param[in]	obj	An instance of %FloatMatrix4
	 * @remarks	This method overrides Tizen::Base::Object::Equals(). This method uses the values of the Matrix components to compare the two instances.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Gets the hash value of the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	The hash value of the current instance
	 * @remarks	Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the determinant of the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	The determinant value of the current instance
	 */
	float GetDeterminant(void) const;

	/**
	 * Gets the inverse matrix of the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatMatrix4 containing the resulting value of the operation
	 * @remarks	This function must be called after checking whether the matrix is invertible or not.
	 */
	FloatMatrix4 GetInverse(void) const;

	/**
	 * Gets the trace of the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	The trace of the current instance
	 */
	float GetTrace(void) const;

	/**
	 * Gets the transpose matrix of the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return	A new instance of %FloatMatrix4 containing the resulting value of the operation
	 */
	FloatMatrix4 GetTranspose(void) const;

	/**
	 * Checks whether the current instance is an identity matrix.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if the matrix is an identity matrix, @n
	 *			else @c false
	 */
	bool IsIdentity(void) const;

	/**
	 * Checks whether the current matrix is invertible.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if the matrix is invertible, @n
	 *			else @c false
	 */
	bool IsInvertible(void) const;

	/**
	 * Negates the matrix members of current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 */
	void Negate(void);

	/**
	 * Sets the identity matrix to the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 */
	void SetAsIdentity(void);

	/**
	 * Sets the inverse matrix to the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_OPERATION	The current instance is not invertible.
	 */
	result Invert(void);

	/**
	 * Sets the transposed matrix to the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 */
	void Transpose(void);

	/**
	 * Sets the matrix members of current instance of %FloatMatrix4 to zero.
	 *
	 * @since 2.0
	 */
	void SetAsNull(void);

	/**
	 * The matrix of the current instance of %FloatMatrix4.
	 *
	 * @since 2.0
	 *
	 * @remarks	The column-major order matrix.
	 */
	float matrix[4][4];

private:
	friend class _FloatMatrix4Impl;
	class _FloatMatrix4Impl* __pImpl;

}; // FloatMatrix4

}} // Tizen::Base

#endif //_FBASE_FLOAT_MATRIX4_H_
