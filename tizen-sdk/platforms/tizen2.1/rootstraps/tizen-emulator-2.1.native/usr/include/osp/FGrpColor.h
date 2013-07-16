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
 * @file	FGrpColor.h
 * @brief	This is the header file for the %Color class.
 *
 * This header file contains the declarations of the %Color class.
 *
 */

#ifndef _FGRP_COLOR_H_
#define _FGRP_COLOR_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>

namespace Tizen { namespace Graphics
{

/**
 * @class    Color32
 * @brief    This template code makes a 32-bit combination from each color component
 * @since 2.0
 *
 * The following example demonstrates how to use this template code
 *
 * @code
 *
 *     #include <FGraphics.h>
 *
 *     using namespace Tizen::Graphics;
 *
 *     // 0xFFFF00FF: Opaque magenta
 *     const unsigned int MY_COLOR1 = Color32<255, 0, 255>::Value;
 *
 *     // 0x80FF0000: Red with 50% opacity
 *     const unsigned int MY_COLOR2 = Color32<255, 0, 0, 128>::Value;
 *
 * @endcode
 */
template <unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 0xFF>
struct Color32
{
	enum
	{
		Value = static_cast<unsigned int>(alpha) << 24 |
				static_cast<unsigned int>(red) << 16 |
				static_cast<unsigned int>(green) << 8 |
				static_cast<unsigned int>(blue)
	};
};

/**
 * @enum         ColorId
 *
 * Defines the color ID.
 *
 * @since 2.0
 */
enum ColorId
{
	COLOR_ID_BLACK, /**< This attribute is pre-defined. Its value is black. */
	COLOR_ID_BLUE, /**< This attribute is pre-defined. Its value is blue. */
	COLOR_ID_CYAN, /**< This attribute is pre-defined. Its value is cyan. */
	COLOR_ID_GREEN, /**< This attribute is pre-defined. Its value is green. */
	COLOR_ID_GREY, /**< This attribute is pre-defined. Its value is grey. */
	COLOR_ID_MAGENTA, /**< This attribute is pre-defined. Its value is magenta. */
	COLOR_ID_RED, /**< This attribute is pre-defined. Its value is red. */
	COLOR_ID_VIOLET, /**< This attribute is pre-defined. Its value is violet. */
	COLOR_ID_YELLOW, /**< This attribute is pre-defined. Its value is yellow. */
	COLOR_ID_WHITE /**< This attribute is pre-defined. Its value is white. */
};

/**
 * @class	Color
 * @brief	This class encapsulates a color.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Color class provides an ARGB (Alpha, Red, Green, Blue) color model.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/graphics/color.htm">Color</a>.
 */
class _OSP_EXPORT_ Color
	: public Tizen::Base::Object
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	Color(void);

	/**
	 * This is the copy constructor for the %Color class. @n
	 * This constructor initializes the instance of %Color with the attributes of the specified instance of %Color.
	 *
	 * @since			2.0
	 *
	 * @param[in]	rhs	An instance of %Color
	 */
	Color(const Color& rhs);

	/**
	 * Initializes the instance of %Color with the specified ARGB values.
	 *
	 * @since			2.0
	 *
	 * @param[in]	r	The red component
	 * @param[in]	g	The green component
	 * @param[in]	b	The blue component
	 * @param[in]	a	The alpha component
	 */
	Color(byte r, byte g, byte b, byte a = 0xFF);

	/**
	 * Initializes the instance of %Color with the specified RGB value.
	 *
	 * @since			2.0
	 *
	 * @param[in]	rgb			The RGB color value
	 * @param[in]	hasAlpha	Set to @c true if @c rgb contains an alpha value, @n
	 *						else @c false
	 */
	Color(unsigned int rgb, bool hasAlpha = true);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~Color(void);


public:
	/**
	 * Checks whether the two instances of %Color are equal.
	 *
	 * @since			2.0
	 *
	 * @return		@c true if the values of the two instances of %Color are equal, @n
	 *               else @c false
	 * @param[in]	rhs		An instance of %Color
	 */
	bool operator ==(const Color& rhs) const;

	/**
	 * Checks whether the two instances of %Color are not equal.
	 *
	 * @since			2.0
	 *
	 * @return		@c true if the values of the two instances of %Color are not equal, @n
	 *               else @c false
	 * @param[in]	rhs		An instance of %Color
	 *
	 */
	bool operator !=(const Color& rhs) const;

	/**
	 * Assigns the values of the RGB components of the specified instance to the current instance of %Color.
	 *
	 * @since			2.0
	 *
	 * @return		The reference to the instance of %Color
	 * @param[in]	rhs		An instance of %Color
	 */
	Color& operator =(const Color& rhs);


public:
	/**
	 * Checks whether the current instance of %Color equals the specified instance of %Color.
	 *
	 * @since			2.0
	 *
	 * @return		@c true if the values of the current instance is equal to the value of the specified instance, @n
	 *               else @c false
	 * @param[in]	rhs		An instance of %Color
	 * @remarks	This method overrides Tizen::Base::Object::Equals(). This method uses the values of the RGB components to compare the two instances.
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance of %Color.
	 *
	 * @since		2.0
	 *
	 * @return		The hash value of the current instance
	 * @remarks	Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;


public:
	/**
	 * Gets the value of the alpha component of the current instance of %Color.
	 *
	 * @since		2.0
	 *
	 * @return	A @c byte representation of the alpha component of the current instance of %Color
	 */
	byte GetAlpha(void) const;

	/**
	 * Gets the value of the red component of the current instance of %Color.
	 *
	 * @since		2.0
	 *
	 * @return	A @c byte representation of the red component of the current instance of %Color
	 */
	byte GetRed(void) const;

	/**
	 * Gets the value of the blue component of the current instance of %Color.
	 *
	 * @since		2.0
	 *
	 * @return	A @c byte representation of the blue component of the current instance of %Color
	 */
	byte GetBlue(void) const;

	/**
	 * Gets the value of the green component of the current instance of %Color.
	 *
	 * @since		2.0
	 *
	 * @return	A @c byte representation of the green component of the current instance of %Color
	 */
	byte GetGreen(void) const;

	/**
	 * Gets the ARGB components of the current instance of %Color.
	 *
	 * @since				2.0
	 *
	 * @param[out]	r	The red component
	 * @param[out]	g	The green component
	 * @param[out]	b	The blue component
	 * @param[out]	a	The alpha component
	 */
	void GetColorComponents(byte& r, byte& g, byte& b, byte& a) const;

	/**
	 * Gets the 32-bit integer value of the current instance of %Color.
	 *
	 * @since		2.0
	 *
	 * @return	An @c unsigned integer value representing the current instance of %Color
	 */
	unsigned int GetRGB32(void) const;

	/**
	 * Sets the value of the alpha component of the current instance of %Color.
	 *
	 * @since			2.0
	 *
	 * @param[in]	a	The new value of the alpha component
	 */
	void SetAlpha(byte a);

	/**
	 * Sets the value of the red component of the current instance of %Color.
	 *
	 * @since			2.0
	 *
	 * @param[in]	r	The new value of the red component
	 */
	void SetRed(byte r);

	/**
	 * Sets the value of the green component of the current instance of %Color.
	 *
	 * @since			2.0
	 *
	 * @param[in]	g	The new value of the green component
	 */
	void SetGreen(byte g);

	/**
	 * Sets the value of the blue component of the current instance of %Color.
	 *
	 * @since			2.0
	 *
	 * @param[in]	b	The new value of the blue component
	 */
	void SetBlue(byte b);

	/**
	 * Sets the values of the ARGB components of the current instance of %Color.
	 *
	 * @since			2.0
	 *
	 * @param[in]	r	The red component
	 * @param[in]	g	The green component
	 * @param[in]	b	The blue component
	 * @param[in]	a	The alpha component
	 */
	void SetColorComponents(byte r, byte g, byte b, byte a = 0xFF);

	/**
	 * Sets the current instance of %Color to the specified 32-bit integer value.
	 *
	 * @since			2.0
	 *
	 * @param[in]	rgb			The new RGB color value
	 * @param[in]	hasAlpha	@c true if @c rgb contains alpha value, @n
	                            else @c false
	 */
	void SetRGB32(unsigned int rgb, bool hasAlpha = true);

	/**
	 * Return the Color object for the specified color
	 *
	 * @since 2.0
	 * @return	The Color object
	 * @param[in]	colorId	The enum value for the specified color
	 */
	static Color GetColor(ColorId colorId);


public:
	/**
	 * @if OSPDEPREC
	 * This attribute is pre-defined. Its value is black.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @since			2.0
	 *
	 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release
	 * Instead of using this static constant, it is recommended to use GetColor(COLOR_ID_BLACK)
	 * @endif
	 */
	const static Color COLOR_BLACK;

	/**
	 * @if OSPDEPREC
	 * This attribute is pre-defined. Its value is blue.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @since			2.0
	 *
 	 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release
	 * Instead of using this static constant, it is recommended to use GetColor(COLOR_ID_BLUE)
	 * @endif
	 */
	const static Color COLOR_BLUE;

	/**
	 * @if OSPDEPREC
	 * This attribute is pre-defined. Its value is cyan.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @since			2.0
	 *
	 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release
	 * Instead of using this static constant, it is recommended to use GetColor(COLOR_ID_CYAN)
	 * @endif
	 */
	const static Color COLOR_CYAN;

	/**
	 * @if OSPDEPREC
	 * This attribute is pre-defined. Its value is green.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @since			2.0
	 *
	 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release
	 * Instead of using this static constant, it is recommended to use GetColor(COLOR_ID_GREEN)
	 * @endif
	 */
	const static Color COLOR_GREEN;

	/**
	 * @if OSPDEPREC
	 * This attribute is pre-defined. Its value is grey.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @since			2.0
	 *
	 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release
	 * Instead of using this static constant, it is recommended to use GetColor(COLOR_ID_GREY)
	 * @endif
	 */
	const static Color COLOR_GREY;

	/**
	 * @if OSPDEPREC
	 * This attribute is pre-defined. Its value is magenta.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @since			2.0
	 *
	 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release
	 * Instead of using this static constant, it is recommended to use GetColor(COLOR_ID_MAGENTA)
	 * @endif
	 */
	const static Color COLOR_MAGENTA;

	/**
	 * @if OSPDEPREC
	 * This attribute is pre-defined. Its value is red.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @since			2.0
	 *
	 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release
	 * Instead of us	ing this static constant, it is recommended to use GetColor(COLOR_ID_RED)
	 * @endif
	 */
	const static Color COLOR_RED;

	/**
	 * @if OSPDEPREC
	 * This attribute is pre-defined. Its value is violet.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @since			2.0
	 *
	 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release
	 * Instead of using this static constant, it is recommended to use GetColor(COLOR_ID_VIOLET)
	 * @endif
	 */
	const static Color COLOR_VIOLET;

	/**
	 * @if OSPDEPREC
	 * This attribute is pre-defined. Its value is yellow.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @since			2.0
	 *
	 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release
	 * Instead of using this static constant, it is recommended to use GetColor(COLOR_ID_YELLOW)
	 * @endif
	 */
	const static Color COLOR_YELLOW;

	/**
	 * @if OSPDEPREC
	 * This attribute is pre-defined. Its value is cwhite.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @since			2.0
	 *
	 * @deprecated This object is provided only for backward compatibility and will be deleted in a future release
	 * Instead of using this static constant, it is recommended to use GetColor(COLOR_ID_WHITE)
	 * @endif
	 */
	const static Color COLOR_WHITE;


private:
	unsigned int __color;

	friend class _ColorImpl;

	//
	// This variable is for internal use only.
	// Using this variable can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	//
	class _ColorImpl * __pImpl;

}; // Color

}} // Tizen::Graphics

#endif //_FGRP_COLOR_H_
