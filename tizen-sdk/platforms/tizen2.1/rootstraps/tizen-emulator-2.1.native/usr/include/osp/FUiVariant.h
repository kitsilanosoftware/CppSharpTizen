//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
 * @file		FUiVariant.h
 * @brief		This is the header file for the %Variant class.
 *
 * This header file contains the declarations of the %Variant class.
 */
#ifndef _FUI_VARIANT_H_
#define _FUI_VARIANT_H_

#include <FBaseDataType.h>
#include <FBaseObject.h>

namespace Tizen { namespace Base
{
	class DateTime;
} }

namespace Tizen { namespace Graphics
{
	class Rectangle;
	class Dimension;
	class Point;
	class Color;
	class FloatPoint;
	class FloatRectangle;
	class FloatDimension;
	class FloatMatrix4;
	class FloatPoint3;
	class FloatVector4;
} }

namespace Tizen { namespace Ui
{

class _VariantImpl;

/**
 * @enum		VariantType
 *
 * Defines the types which %Variant can hold.
 *
 * @since 2.0
 */
enum VariantType
{
	VARIANT_TYPE_NONE = 0, /**< The type for invalid variant */
	VARIANT_TYPE_INT, /**< The @c int type */
	VARIANT_TYPE_UINT, /**< The @c unsigned @c int type */
	VARIANT_TYPE_BOOL, /**< The @c bool type */
	VARIANT_TYPE_FLOAT, /**< The @c float type */
	VARIANT_TYPE_DOUBLE, /**< The @c double type */
	VARIANT_TYPE_LONG, /**< The @c long type */
	VARIANT_TYPE_ULONG, /**< The @c unsigned @c long type */
	VARIANT_TYPE_LONGLONG, /**< The @c long @c long type */
	VARIANT_TYPE_ULONGLONG, /**< The @c unsigned @c long @c long type */
	VARIANT_TYPE_STRING, /**< The String type */
	VARIANT_TYPE_DATETIME, /**< The DateTime type */
	VARIANT_TYPE_COLOR, /**< The Color type */
	VARIANT_TYPE_POINT, /**< The Point type */
	VARIANT_TYPE_FLOAT_POINT, /**< The FloatPoint type */
	VARIANT_TYPE_RECTANGLE, /**< The Rectangle type */
	VARIANT_TYPE_FLOAT_RECTANGLE, /**< The FloatRectangle type */
	VARIANT_TYPE_DIMENSION, /**< The Dimension type */
	VARIANT_TYPE_FLOAT_DIMENSION, /**< The FloatDimension type */
	VARIANT_TYPE_FLOAT_MATRIX4, /**< The FloatMatrix4 type */
	VARIANT_TYPE_FLOAT_POINT3, /**< The FloatPoint3 type @b Since: @b 2.1 */
	VARIANT_TYPE_FLOAT_VECTOR4 /**< The FloatPoint3 type @b Since: @b 2.1 */
};

/**
 * @class	Variant
 * @brief	This class abstracts a %Variant value.
 *
 * @since 2.0
 *
 *	The %Variant class represents a %Variant type which can hold any of the basic type values.
 *
 */
class _OSP_EXPORT_ Variant
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	Variant(void);

	/**
	 * This is the copy constructor for the %Variant class.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A reference to the %Variant instance to copy
	 */
	Variant(const Variant& value);

	/**
	 * Initializes this instance of %Variant with the specified @c int value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	An @c int value
	 */
	Variant(int value);

	/**
	 * Initializes this instance of %Variant with the specified @c unsigned @c int value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	An @c unsigned @c int value
	 */
	Variant(unsigned int value);

	/**
	 * Initializes this instance of %Variant with the specified bool value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A bool value
	 */
	Variant(bool value);

	/**
	 * Initializes this instance of %Variant with the specified @c float value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A @c float value
	 */
	Variant(float value);

	/**
	 * Initializes this instance of %Variant with the specified @c double value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A @c double value
	 */
	Variant(double value);

	/**
	 * Initializes this instance of %Variant with the specified @c long value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A @c long value
	 */
	Variant(long value);

	/**
	 * Initializes this instance of %Variant with the specified @c unsigned @c long value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	An @c unsigned @c long value
	 */
	Variant(unsigned long value);

	/**
	 * Initializes this instance of %Variant with the specified @c long @c long value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A @c long @c long value
	 */
	Variant(long long value);

	/**
	 * Initializes this instance of %Variant with the specified @c unsigned @c long @c long value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	An @c unsigned @c long @c long value
	 */
	Variant(unsigned long long value);

	/**
	 * Initializes this instance of %Variant with the specified array of characters.
	 *
	 * @since 2.0
	 *
	 * @param[in]	pValue	An array of characters value
	 */
	Variant(const char* pValue);

	/**
	 * Initializes this instance of %Variant with the specified array of Unicode characters.
	 *
	 * @since 2.0
	 *
	 * @param[in]	pValue	An array of Unicode characters value
	 */
	Variant(const wchar_t* pValue);

	/**
	 * Initializes this instance of %Variant with the specified Tizen::Base::String value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A Tizen::Base::String value
	 */
	Variant(const Tizen::Base::String& value);

	/**
	 * Initializes this instance of %Variant with the specified Tizen::Base::DateTime value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A Tizen::Base::DateTime value
	 */
	Variant(const Tizen::Base::DateTime& value);

	/**
	 * Initializes this instance of %Variant with the specified Tizen::Graphics::Color value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A Tizen::Graphics::Color value
	 */
	Variant(const Tizen::Graphics::Color& value);

	/**
	 * Initializes this instance of %Variant with the specified Tizen::Graphics::Point value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A Tizen::Graphics::Point value
	 */
	Variant(const Tizen::Graphics::Point& value);

	/**
	 * Initializes this instance of %Variant with the specified Tizen::Graphics::FloatPoint value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A Tizen::Graphics::FloatPoint value
	 */
	Variant(const Tizen::Graphics::FloatPoint& value);

	/**
	 * Initializes this instance of %Variant with the specified Tizen::Graphics::Rectangle value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A Tizen::Graphics::Rectangle value
	 */
	Variant(const Tizen::Graphics::Rectangle& value);

	/**
	 * Initializes this instance of %Variant with the specified Tizen::Graphics::FloatRectangle value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A Tizen::Graphics::FloatRectangle value
	 */
	Variant(const Tizen::Graphics::FloatRectangle& value);

	/**
	 * Initializes this instance of %Variant with the specified Tizen::Graphics::Dimension value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A Tizen::Graphics::Dimension value
	 */
	Variant(const Tizen::Graphics::Dimension& value);

	/**
	 * Initializes this instance of %Variant with the specified Tizen::Graphics::FloatDimension value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A Tizen::Graphics::FloatDimension value
	 */
	Variant(const Tizen::Graphics::FloatDimension& value);

	/**
	 * Initializes this instance of %Variant with the specified Tizen::Graphics::FloatMatrix4 value.
	 *
	 * @since 2.0
	 *
	 * @param[in]	value	A Tizen::Graphics::FloatMatrix4 value
	 */
	Variant(const Tizen::Graphics::FloatMatrix4& value);

	/**
	 * Initializes this instance of %Variant with a specified Tizen::Graphics::FloatPoint3 value.
	 *
	 * @since 2.1
	 *
	 * @param[in]	 value	  A Tizen::Graphics::FloatPoint3 value
	 */
	Variant(const Tizen::Graphics::FloatPoint3& value);

	/**
	 * Initializes this instance of %Variant with a specified Tizen::Graphics::FloatVector4 value.
	 *
	 * @since 2.1
	 *
	 * @param[in]	 value	  A Tizen::Graphics::FloatVector4 value
	 */
	Variant(const Tizen::Graphics::FloatVector4& value);

	/**
	 * This is the destructor for this class.
	 *
	 * @since 2.0
	 */
	virtual ~Variant(void);

	/**
	 * Assigns the value of the specified instance to the current instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An instance of %Variant to copy
	 */
	Variant& operator =(const Variant& rhs);

	/**
	 * Assigns the value to the current instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An @c int value
	 */
	Variant& operator =(int rhs);

	/**
	 * Assigns the value to the current instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An @c unsigned @c int value
	 *
	 */
	Variant& operator =(unsigned int rhs);

	/**
	 * Assigns the value to the current instance of %Variant.
	 *
	 * @since 2.0
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		A @c bool value
	 *
	 */
	Variant& operator =(bool rhs);

	/**
	 * Assigns the value to the current instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		A @c float value
	 *
	 */
	Variant& operator =(float rhs);

	/**
	 * Assigns the value to the current instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		A @c double value
	 *
	 */
	Variant& operator =(double rhs);

	/**
	 * Assigns the value to the current instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		A @c long value
	 *
	 */
	Variant& operator =(long rhs);

	/**
	 * Assigns the value to the current instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An @c unsigned @c long value
	 *
	 */
	Variant& operator =(unsigned long rhs);

	/**
	 * Assigns the value to the current instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		A @c long @c long value
	 *
	 */
	Variant& operator =(long long rhs);

	/**
	 * Assigns the value to the current instance of %Variant.
	 *
	 * @since 2.0
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An @c unsigned @c long @c long value
	 *
	 */
	Variant& operator =(unsigned long long rhs);

	/**
	 * Assigns the value of the pointer to the current instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the %Variant instance
	 * @param[in]	pRhs	A pointer to an array of characters
	 *
	 */
	Variant& operator =(const char* pRhs);

	/**
	 * Assigns the value of the pointer to the current instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the %Variant instance
	 * @param[in]	pRhs	A pointer to an array of Unicode characters
	 *
	 */
	Variant& operator =(const wchar_t* pRhs);

	/**
	 * Assigns the value of the specified instance of Tizen::Base::String to the current instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An instance of Tizen::Base::String
	 */
	Variant& operator =(const Tizen::Base::String& rhs);

	/**
	 * Assigns the value of the specified instance of Tizen::Base::DateTime to the current instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An instance of Tizen::Base::DateTime
	 */
	Variant& operator =(const Tizen::Base::DateTime& rhs);

	/**
	 * Assigns the value of the specified instance of Tizen::Graphics::Color to the current instance of %Variant.
	 *
	 * @since 2.0
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An instance of Tizen::Graphics::Color
	 */
	Variant& operator =(const Tizen::Graphics::Color& rhs);

	/**
	 * Assigns the value of the specified instance of Tizen::Graphics::Point to the current instance of %Variant.
	 *
	 * @since 2.0
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An instance of Tizen::Graphics::Point
	 */
	Variant& operator =(const Tizen::Graphics::Point& rhs);

	/**
	 * Assigns the value of the specified instance of Tizen::Graphics::FloatPoint to the current instance of %Variant.
	 *
	 * @since 2.0
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An instance of Tizen::Graphics::FloatPoint
	 */
	Variant& operator =(const Tizen::Graphics::FloatPoint& rhs);

	/**
	 * Assigns the value of the specified instance of Tizen::Graphics::Rectangle to the current instance of %Variant.
	 *
	 * @since 2.0
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An instance of Tizen::Graphics::Rectangle
	 */
	Variant& operator =(const Tizen::Graphics::Rectangle& rhs);

	/**
	 * Assigns the value of the specified instance of Tizen::Graphics::FloatRectangle to the current instance of %Variant.
	 *
	 * @since 2.0
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An instance of Tizen::Graphics::FloatRectangle
	 */
	Variant& operator =(const Tizen::Graphics::FloatRectangle& rhs);

	/**
	 * Assigns the value of the specified instance of Tizen::Graphics::Dimension to the current instance of %Variant.
	 *
	 * @since 2.0
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An instance of Tizen::Graphics::Dimension
	 */
	Variant& operator =(const Tizen::Graphics::Dimension& rhs);

	/**
	 * Assigns the value of the specified instance of Tizen::Graphics::FloatDimension to the current instance of %Variant.
	 *
	 * @since 2.0
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An instance of Tizen::Graphics::FloatDimension
	 */
	Variant& operator =(const Tizen::Graphics::FloatDimension& rhs);

	/**
	 * Assigns the value of the specified instance of Tizen::Graphics::FloatMatrix4 to the current instance of %Variant.
	 *
	 * @since 2.0
	 * @return		A reference to the %Variant instance
	 * @param[in]	rhs		An instance of Tizen::Graphics::FloatMatrix4
	 */
	Variant& operator =(const Tizen::Graphics::FloatMatrix4& rhs);

	/**
	 * Assigns the value of a specified instance of Tizen::Graphics::FloatPoint3 to the current instance of %Variant.
	 *
	 * @since 2.1
	 * @return					A reference to the %Variant instance
	 * @param[in]	 rhs				 An instance of Tizen::Graphics::FloatPoint3
	 */
	Variant& operator =(const Tizen::Graphics::FloatPoint3& rhs);

	/**
	 * Assigns the value of a specified instance of Tizen::Graphics::FloatVecto4 to the current instance of %Variant.
	 *
	 * @since 2.1
	 * @return					A reference to the %Variant instance
	 * @param[in]	 rhs				 An instance of Tizen::Graphics::FloatVector4
	 */
	Variant& operator =(const Tizen::Graphics::FloatVector4& rhs);

	/**
	 * Checks whether the specified instance and current instance of %Variant have equal values.
	 *
	 * @since 2.0
	 * @return		@c true if the two instances of %Variant are equal, @n
	 *				else @c false
	 * @param[in]	lhs		An instance of %Variant
	 * @param[in]	rhs		An instance of %Variant
	 */
	_OSP_EXPORT_	friend bool operator ==(const Variant& lhs, const Variant& rhs);

	/**
	 * Checks whether the specified instance and current instance of %Variant have different values.
	 * @since 2.0
	 *
	 * @return		@c true if the values of the two instances of %Variant are not equal, @n
	 *				else @c false
	 * @param[in]	lhs		An instance of %Variant
	 * @param[in]	rhs		An instance of %Variant
	 *
	 */
	_OSP_EXPORT_	friend bool operator !=(const Variant& lhs, const Variant& rhs);

	/**
	 * Gets the @c signed @c int equivalent of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		The @c signed @c int equivalent of the current instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_OPERATION	The current variant type is not @c VARIANT_TYPE_INT.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns @c 0 and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_INT.
	 *
	 */
	int ToInt(void) const;

	/**
	 * Gets the @c unsigned @c int equivalent of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		The @c unsigned @c int equivalent of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_UINT.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns @c 0 and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_UINT.
	 *
	 */
	unsigned int ToUInt(void) const;

	/**
	 * Gets the @c bool equivalent of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		The @c bool equivalent of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_BOOL.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns @c false and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_BOOL.
	 *
	 */
	bool ToBool(void) const;

	/**
	 * Gets the @c float equivalent of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		The @c float equivalent of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_FLOAT.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns @c 0 and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_FLOAT.
	 *
	 */
	float ToFloat(void) const;

	/**
	 * Gets the @c double equivalent of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		The @c double equivalent of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_DOUBLE.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns @c 0 and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_DOUBLE.
	 *
	 */
	double ToDouble(void) const;

	/**
	 * Gets the @c signed @c long equivalent of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		The @c signed @c long equivalent of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_LONG.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns @c 0 and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_LONG.
	 *
	 */
	long ToLong(void) const;

	/**
	 * Gets the @c unsigned @c int equivalent of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		The @c unsigned @c long equivalent of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_ULONG.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns @c 0 and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_ULONG.
	 *
	 */
	unsigned long ToULong(void) const;

	/**
	 * Gets the @c signed @c long @c long equivalent of the current instance.
	 *
	 * @since 2.0
	 *
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_LONGLONG.
	 *
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns @c 0 and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_LONGLONG.
	 *
	 */
	long long ToLongLong(void) const;

	/**
	 * Gets the @c unsigned @c long @c long equivalent of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		The @c unsigned @c long @c long equivalent of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_ULONGLONG.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns @c 0 and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_ULONGLONG.
	 *
	 */
	unsigned long long ToULongLong(void) const;

	/**
	 * Gets the Tizen::Base::String representation of the value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		A Tizen::Base::String representing the value of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_STRING.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns String("") and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_STRING.
	 *
	 */
	Tizen::Base::String ToString(void) const;

	/**
	 * Gets the Tizen::Base::DateTime representation of the value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		A Tizen::Base::DateTime representing the value of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_DATETIME.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns DateTime and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_DATETIME.
	 *
	 */
	Tizen::Base::DateTime ToDateTime(void) const;

	/**
	 * Gets the Tizen::Graphics::Color representation of the value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		A Tizen::Graphics::Color representing the value of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_COLOR.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns Color and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_COLOR.
	 *
	 */
	Tizen::Graphics::Color ToColor(void) const;

	/**
	 * Gets the Tizen::Graphics::Point representation of the value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		A Tizen::Graphics::Point representing the value of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_POINT.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns Point and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_POINT.
	 *
	 */
	Tizen::Graphics::Point ToPoint(void) const;

	/**
	 * Gets the Tizen::Graphics::FloatPoint representation of the value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		A Tizen::Graphics::FloatPoint representing the value of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_FLOAT_POINT.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns FloatPoint and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_FLOAT_POINT.
	 *
	 */
	Tizen::Graphics::FloatPoint ToFloatPoint(void) const;

	/**
	 * Gets the Tizen::Graphics::Rectangle representation of the value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		A Tizen::Graphics::Rectangle representing the value of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_RECTANGLE.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns Rectangle and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_RECTANGLE.
	 *
	 */
	Tizen::Graphics::Rectangle ToRectangle(void) const;

	/**
	 * Gets the Tizen::Graphics::FloatRectangle representation of the value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		A Tizen::Graphics::FloatRectangle representing the value of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_FLOAT_RECTANGLE.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns FloatRectangle and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_FLOAT_RECTANGLE.
	 *
	 */
	Tizen::Graphics::FloatRectangle ToFloatRectangle(void) const;

	/**
	 * Gets the Tizen::Graphics::Dimension representation of the value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		A Tizen::Graphics::Dimension representing the value of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_DIMENSION.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns Dimension and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_DIMENSION.
	 *
	 */
	Tizen::Graphics::Dimension ToDimension(void) const;

	/**
	 * Gets the Tizen::Graphics::FloatDimension representation of the value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		A Tizen::Graphics::FloatDimension representing the value of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_FLOAT_DIMENSION.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns FloatDimension and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_FLOAT_DIMENSION.
	 *
	 */
	Tizen::Graphics::FloatDimension ToFloatDimension(void) const;

	/**
	 * Gets the Tizen::Graphics::FloatMatrix4 representation of the value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		A Tizen::Graphics::FloatMatrix4 representing the value of the current instance
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current variant type is not @c VARIANT_TYPE_FLOAT_MATRIX4.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns FloatMatrix4() and generates E_INVALID_OPERATION exception if the current variant type is not VARIANT_TYPE_FLOAT_MATRIX4.
	 *
	 */
	Tizen::Graphics::FloatMatrix4 ToFloatMatrix4(void) const;

	/**
	 * Gets the Tizen::Graphics::FloatPoint3 representation of the value of the current instance.
	 *
	 * @since 2.1
	 *
	 * @return		A Tizen::Graphics::FloatPoint3 representing the value of the current instance
	 * @exception	 E_SUCCESS				The method is successful.
	 * @exception	 E_INVALID_OPERATION	The current variant type is not @c VARIANT_TYPE_FLOAT_POINT3.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns FloatPoint3 and generates @c E_INVALID_OPERATION exception if the current variant type is not @c VARIANT_TYPE_FLOAT_POINT3.
	 *
	 */
	Tizen::Graphics::FloatPoint3 ToFloatPoint3(void) const;

	/**
	 * Gets the Tizen::Graphics::FloatVector4 representation of the value of the current instance.
	 *
	 * @since 2.1
	 *
	 * @return		A Tizen::Graphics::FloatVector4 representing the value of the current instance
	 * @exception	 E_SUCCESS				The method is successful.
	 * @exception	 E_INVALID_OPERATION	The current variant type is not @c VARIANT_TYPE_FLOAT_VECTOR4.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 *				The method returns FloatVector4() and generates E_INVALID_OPERATION exception if the current variant type is not VARIANT_TYPE_FLOAT_VECTOR4.
	 *
	 */
	Tizen::Graphics::FloatVector4 ToFloatVector4(void) const;

	/**
	 * Checks whether the variant is empty.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the current instance is NULL_VARIANT, @n
	 *				else @c false
	 */
	bool IsEmpty(void) const;

	/**
	 * Gets the type of the variant.
	 *
	 * @since 2.0
	 *
	 * @return		The variant type
	 */
	VariantType GetType(void) const;

	/**
	 * Checks whether the current instance of %Variant equals the specified instance of %Variant.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the values of the current instance is equal to the value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj		An instance of %Variant
	 * @remarks		This method overrides Tizen::Base::Object::Equals(). This method uses the values of the %Variant to compare the two instances.
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return		The hash value of the current instance
	 * @remarks		Two equal instances must return the same hash value. For better performance, the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;

public:
	/**
	 * A constant represents a @c null value.
	 *
	 * @since 2.0
	 */
	static const Variant NULL_VARIANT;

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is prohibited. If this method is used in an application, the application can get rejected during
	// the certification process.
	//
	// @since 2.0
	//
	const _VariantImpl* GetVariantImpl(void) const;

	//
	// This method is for internal use only.
	// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is prohibited. If this method is used in an application, the application can get rejected during
	// the certification process.
	//
	// @since 2.0
	//
	_VariantImpl* GetVariantImpl(void);

private:
	_VariantImpl* __pVariantImpl;
}; // Variant

} } // Tizen::Ui

#endif // _FUI_VARIANT_H_
