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
 * @file	FBaseFloatMatrix.h
 * @brief	This is the header file for the %FloatMatrix class.
 *
 * This header file contains the declarations of the %FloatMatrix class.
 *
 */

#ifndef _FBASE_FLOAT_MATRIX_H_
#define _FBASE_FLOAT_MATRIX_H_

#include <FBase.h>
#include <FBaseTypes.h>
#include <FBaseObject.h>

namespace Tizen { namespace Base
{
/**
 * @class	FloatMatrix
 * @brief	This class encapsulates a two-dimensional matrix.
 *
 * @since 2.0
 *
 * The %FloatMatrix class provides a @c float precision, two-dimensional matrix class.
 *
 */
class _OSP_EXPORT_ FloatMatrix
	: public Tizen::Base::Object
{
public:
	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since 2.0
	 *
	 * @param[in]	rhs	An instance of %FloatMatrix
	 */
	FloatMatrix(const FloatMatrix& rhs);

	/**
	 * Constructs a row by column null matrix in which all elements are zero.
	 *
	 * @since 2.0
	 *
	 * @param[in]	rowCount	The number of rows in the current instance
	 * @param[in]	columnCount	The number of columns in the current instance
	 */
	FloatMatrix(int rowCount, int columnCount);

	/**
	 * Constructs a row by column matrix initialized to the values in the specified array.
	 *
	 * @since 2.0
	 *
	 * @param[in]	rowCount	The number of rows in the current instance
	 * @param[in]	columnCount	The number of columns in the current instance
	 * @param[in]	pArray	A one-dimensional array @n The array must be at least row * column in length.
	 * @param[in]	rowMajor	Set to @c true to copy the array in row-major order, @n
	 * 							else @c copy in column-major order
	 */
	FloatMatrix(int rowCount, int columnCount, const float* pArray, bool rowMajor = true);

	/**
	 * Constructs a row by column matrix initialized to the values in the specified array.
	 *
	 * @since 2.0
	 *
	 * @param[in]	rowCount	The number of rows in the current instance
	 * @param[in]	columnCount	The number of columns in the current instance
	 * @param[in]	pArray[]	A two-dimensional array @n The array must be at least row * column in length.
	 */
	FloatMatrix(int rowCount, int columnCount, const float* pArray[]);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~FloatMatrix(void);

	/**
	 * Checks whether the current instance and the specified instance of %FloatMatrix are equal.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if all matrix members of the current instance are equal to the corresponding matrix members in the specified instance, @n
	 *			else @c false
	 * @param[in]	rhs	An instance of %FloatMatrix
	 */
	bool operator ==(const FloatMatrix& rhs) const;

	/**
	 * Checks whether the current instance and the specified instance of %FloatMatrix are not equal.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if all matrix members of the current instance are not equal to the corresponding matrix members in the specified instance, @n
	 *			else @c false
	 * @param[in]	rhs	An instance of %FloatMatrix
	 */
	bool operator !=(const FloatMatrix& rhs) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since 2.0
	 *
	 * @return	The reference to this instance
	 * @param[in]	rhs	An instance of %FloatMatrix
	 * @exception	E_INVALID_ARG	Either row or column count of the current instance is not same with that of the specified instance.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 * @remarks	If either row or column count of the current instance is not same with that of the specified instance,
	 *				return the reference to this instance without assigning.
	 */
	FloatMatrix& operator =(const FloatMatrix& rhs);

	/**
	 * Checks whether the current instance of %FloatMatrix equals the specified instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return	@c true if the values of the current instance are equal to the value of the specified instance, @n
	 *			else @c false
	 * @param[in]	obj	An instance of %FloatMatrix
	 * @remarks	This method overrides Tizen::Base::Object::Equals(). This method uses the values of the Matrix components to compare the two instances.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Gets the hash value of the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return	The hash value of the current instance
	 * @remarks	Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Adds the value of the specified instance to the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	matrix	An instance of %FloatMatrix
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	Either row or column count of the current instance is not same with that of the specified instance.
	 */
	result Add(const FloatMatrix& matrix);

	/**
	 * Adds the value to each matrix members of current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A @c float value to add
	 */
	void AddToEachElement(float value);

	/**
	 * Gets the number of column in the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return	The number of column in the current instance
	 */
	int GetColumnCount(void) const;

	/**
	 * Gets a new array that includes the values of the specified column in the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return	A pointer to float array
	 * @param[in]	columnIndex	The target column number in the current instance
	 * @exception	E_INVALID_ARG	The @c columnIndex is larger than the column count of the current instance.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	float* GetColumnN(int columnIndex) const;

	/**
	 * Gets the determinant of the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return	The determinant value of the current instance
	 * @exception	E_INVALID_OPERATION	The current instance is not a square matrix.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 * @remarks	If the current instance is not a square matrix, return zero.
	 */
	float GetDeterminant(void) const;

	/**
	 * Gets the value at the specified row and column of the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return	The value at the specified row and column of the current instance
	 * @param[in]	rowIndex	The target row number in the current instance
	 * @param[in]	columnIndex	The target column number in the current instance
	 * @exception	E_INVALID_ARG	The @c columnIndex or @c rowIndex is larger than that of the current instance.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	float GetElement(int rowIndex, int columnIndex) const;

	/**
	 * Gets the inverse matrix of the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return	 A pointer to the instance of %FloatMatrix containing the resulting value of the operation
	 * @exception	E_INVALID_OPERATION	The current instance is not a square matrix.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	FloatMatrix* GetInverseN(void) const;

	/**
	 * Gets the number of row in the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return	The number of row in the current instance
	 */
	int GetRowCount(void) const;

	/**
	 * Gets a new array that includes the values of the specified row in the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return	A pointer to @c float array
	 * @param[in]	rowIndex	The target row number in the current instance
	 * @exception	E_INVALID_ARG	The @c rowIndex is larger than the row count of the current instance.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	float* GetRowN(int rowIndex) const;

	/**
	 * Gets the trace of the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	value	A @c float value
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_OPERATION	The current instance is not a square matrix.
	 */
	result GetTrace(float& value) const;

	/**
	 * Gets the transpose matrix of the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return	 A pointer to the instance of %FloatMatrix containing the resulting value of the operation
	 * @exception	E_INVALID_OPERATION	The current instance is not a square matrix.
	 * @remarks    The specific error code can be accessed using the GetLastResult() method.
	 */
	FloatMatrix* GetTransposeN(void) const;

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
	 * Multiplies the value of the specified instance with the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	matrix	An instance of %FloatMatrix
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The column count of the current instance is not same with the row count of the specified instance.
	 */
	result Multiply(const FloatMatrix& matrix);

	/**
	 * Multiplies the value to each matrix members of current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A @c float value to multiply
	 */
	void Multiply(float value);

	/**
	 * Negates the matrix members of current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 */
	void Negate(void);

	/**
	 * Sets the value of the current instance of %FloatMatrix to its identity.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_OPERATION	The current instance is not a square matrix.
	 */
	result SetAsIdentity(void);

	/**
	 * Sets the value of the current instance of %FloatMatrix to its inverse.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_OPERATION	The current instance is not a square matrix.
	 */
	result Invert(void);

	/**
	 * Sets the value of the current instance of %FloatMatrix to its transpose.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_OPERATION	The current instance is not a square matrix.
	 */
	result Transpose(void);

	/**
	 * Sets the values of the specified array to the specified column of the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	columnIndex	The target column number in the current instance	
	 * @param[in]	pArray	An array which includes the values @n The array must be at least row in length.
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The @c pArray is @c null, or the @c columnIndex is larger than the column count of the current instance.
	 */
	result SetColumn(int columnIndex, const float* pArray);

	/**
	 * Sets the values of the specified array to the specified row of the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	rowIndex	The target row number in the current instance	
	 * @param[in]	pArray	An array which includes the values @n The array must be at least column in length.
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The @c pArray is @c null, or the @c rowIndex is larger than the row count of the current instance.
	 */
	result SetRow(int rowIndex, const float* pArray);

	/**
	 * Sets the value to the specified row and column of the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	rowIndex	The target row number in the current instance
	 * @param[in]	columnIndex	The target column number in the current instance
	 * @param[in]	value	A @c float value
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The pArray is @c null, or the @c rowIndex is larger than the row count of the current instance,
	 *				or the @c columnIndex is larger than the column count of the current instance.
	 */
	result SetElement(int rowIndex, int columnIndex, float value);

	/**
	 * Sets the values to the current instance of %FloatMatrix in either the row-major or column-major order.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pArray	A one-dimensional array @n The array must be at least row * column in length.
	 * @param[in]	rowMajor	Set to @c true to copy the array in row-major order, @n
	 * 							else @c false to copy in column-major order
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	The pArray is @c null.
	 */
	result SetValue(const float* pArray, bool rowMajor = true);

	/**
	 * Sets the matrix members of current instance of %FloatMatrix to zero.
	 *
	 * @since 2.0
	 */
	void SetAsNull(void);

	/**
	 * Subtracts the value of the specified instance from the current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	matrix	An instance of %FloatMatrix
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_INVALID_ARG	Either row or column count of the current instance is not same with that of the specified instance.
	 */
	result Subtract(const FloatMatrix& matrix);

	/**
	 * Subtracts the value from each matrix members of current instance of %FloatMatrix.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A @c float value to subtract
	 */
	void SubtractToEachElement(float value);

private:
	/*
	 * This default constructor is intentionally declared as private so that only the platform can create an instance.
	 *
	 * @since 2.0
	 */
	FloatMatrix(void);

	bool AllocateCapacity(int rowCount, int columnCount);
	void GetMinor(float** pSrc, float** pDest, int rowIndex, int columnIndex, int order) const;
	float CalculateDeterminant(float** pMatrix, int order) const;

	friend class _FloatMatrixImpl;
	class _FloatMatrixImpl* __pImpl;

	float** __pMatrix;
	int __row;
	int __column;

}; // FloatMatrix

}} // Tizen::Base

#endif //_FBASE_FLOAT_MATRIX_H_
