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
 * @file	FGrpCanvas.h
 * @brief	This is the header file for the %Canvas class.
 *
 * This header file contains the declarations of the %Canvas class.
 *
 */

#ifndef _FGRP_CANVAS_H_
#define _FGRP_CANVAS_H_

#include <FBase.h>
#include <FBaseObject.h>
#include <FBaseColArrayListT.h>
#include <FGrpRectangle.h>
#include <FGrpFloatRectangle.h>
#include <FGrpColor.h>
#include <FGrpPixelFormat.h>
#include <FGrpBufferInfo.h>
#include <FGrpBitmap.h>
#include <FGrpCanvasCommon.h>

namespace Tizen { namespace Graphics
{
class Font;
class EnrichedText;

/**
 * @class	Canvas
 * @brief	This class provides methods for drawing objects.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Canvas class provides a rectangular region to draw objects on the display device. The %Canvas instance is
 * associated with a specific context.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/graphics/canvas.htm">Canvas</a>.
 *
 */
class _OSP_EXPORT_ Canvas
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be
	 *				called explicitly to initialize this instance.
	 */
	Canvas(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~Canvas(void);

	/**
	 * Initializes this instance of %Canvas to create a canvas control of the same size as that of the
	 * device screen.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Construct(void);

	/**
	 * Initializes this instance of %Canvas with the specified parameter.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the canvas control on the device screen @n
	 *								The width and height of the rectangle must be greater than @c 0.
	 *								If this condition is not satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result Construct(const Rectangle& rect);

	/**
	 * Initializes this instance of %Canvas with a specified parameter.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the canvas control on the device screen @n
	 *								The width and height of the rectangle must be greater than @c 0.0f.
	 *								If this condition is not satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result Construct(const FloatRectangle& rect);

	/**
	 * Initializes this instance of %Canvas with the buffer information.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	bufferInfo           The information of the buffer to use by the canvas
	 * @exception	E_SUCCESS            The method is successful.
	 * @exception	E_INVALID_ARG        The buffer information is invalid.
	 * @exception	E_UNSUPPORTED_FORMAT The given buffer information is a format unsupported by the canvas.
	 * @exception	E_SYSTEM             An unknown operating system error has occurred
	 * @remarks Only ::PIXEL_FORMAT_ARGB8888 is supported.
	 */
	result Construct(const BufferInfo& bufferInfo);

public:
	/**
	 * Clears the current instance of %Canvas with the background color.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result Clear(void);

	/**
	 * Clears a rectangular region of the current instance of %Canvas with the background color.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the rectangular region @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangular region must not fall outside the edges of the
	 *								current instance of %Canvas entirely.If these conditions are not
	 *								satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result Clear(const Rectangle& rect);

	/**
	 * Clears a rectangular region of the current instance of %Canvas with the background color.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the rectangular region @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.0f.
	 *								The rectangular region must not fall outside the edges of the
	 *								current instance of %Canvas entirely.If these conditions are not
	 *								satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result Clear(const FloatRectangle& rect);

	/**
	 * Copies the specified rectangular region from the specified instance of %Canvas to the current instance of
	 * %Canvas at the specified location.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	destPoint			The location to copy the rectangular region
	 * @param[in]	srcCanvas			The source %Canvas
	 * @param[in]	srcRect				The location and size of the rectangular region on the source %Canvas @n
	 *									The rectangular region must not fall outside the edges of
	 *									the current instance of %Canvas entirely. If this condition is
	 *									not satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 */
	result Copy(const Point& destPoint, const Canvas& srcCanvas, const Rectangle& srcRect);

	/**
	 * Copies a specified rectangular region from a specified instance of %Canvas to the current instance of
	 * %Canvas at a specified location.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	destPoint			The location to copy the rectangular region
	 * @param[in]	srcCanvas			The source %Canvas
	 * @param[in]	srcRect				The location and size of the rectangular region on the source %Canvas @n
	 *									The rectangular region must not fall outside the edges of
	 *									the current instance of %Canvas entirely. If this condition is
	 *									not satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 */
	result Copy(const FloatPoint& destPoint, const Canvas& srcCanvas, const FloatRectangle& srcRect);

	/**
	 * Copies the scaled image of the specified rectangular region from the specified instance of
	 * %Canvas to the current instance of %Canvas.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	destRect			The location and size of the destination image @n
	 *									The value of @c destRect must not fall outside the edges of
	 *									the current instance of %Canvas entirely. If this condition is
	 *									not satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	srcCanvas			The source %Canvas
	 * @param[in]	srcRect				The location and size of the source image @n
	 *									The value of @c srcRect must not fall outside the edges of
	 *									the current instance of %Canvas entirely. If this condition is
	 *									not satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of this operation.
	 */
	result Copy(const Rectangle& destRect, const Canvas& srcCanvas, const Rectangle& srcRect);

	/**
	 * Copies the scaled image of a specified rectangular region from a specified instance of
	 * %Canvas to the current instance of %Canvas.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	destRect			The location and size of the destination image @n
	 *									The value of @c destRect must not fall outside the edges of
	 *									the current instance of %Canvas entirely. If this condition is
	 *									not satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	srcCanvas			The source %Canvas
	 * @param[in]	srcRect				The location and size of the source image @n
	 *									The value of @c srcRect must not fall outside the edges of
	 *									the current instance of %Canvas entirely. If this condition is
	 *									not satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of this operation.
	 */
	result Copy(const FloatRectangle& destRect, const Canvas& srcCanvas, const FloatRectangle& srcRect);

	/**
	 * Gets the line style set for the current instance of %Canvas.
	 *
	 * @since		2.0
	 *
	 * @return		An instance of LineStyle
	 * @remarks The default value is @c LINE_STYLE_SOLID.
	 */
	LineStyle GetLineStyle(void) const;

	/**
	 * Gets the line width of the current instance of %Canvas.
	 *
	 * @since		2.0
	 *
	 * @return		The line width, @n
	 *				else @c -1 if the method fails
	 * @remarks The default value is @c 1.
	 */
	int GetLineWidth(void) const;

	/**
	 * Gets the line width of the current instance of %Canvas.
	 *
	 * @since		2.1
	 *
	 * @return		The line width, @n
	 *				else @c -1.0f if the method fails
	 * @remarks The default value is @c 1.0f.
	 */
	float GetLineWidthF(void) const;

	/**
	 * Sets the line style for the current instance of %Canvas.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	style				The new line style for the %Canvas control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result SetLineStyle(LineStyle style);

	/**
	 * Sets the line width for the current instance of %Canvas.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	width				The new width for the %Canvas control @n
	 *									The width for the %Canvas control must be greater than @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 */
	result SetLineWidth(int width);

	/**
	 * Sets the line width for the current instance of %Canvas.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	width				The new width for the %Canvas control @n
	 *									The width for the %Canvas control must be greater than @c 0.0f.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 */
	result SetLineWidth(float width);

	/**
	 * Gets the dash pattern of the current instance of %Canvas.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	pattern			The list containing the information of dash pattern.
	 * @param[out]	offset			The offset into the dash pattern at which the stroke must start
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specific input parameter is invalid.
	 */
	result GetDashPattern(Tizen::Base::Collection::IListT<int>& pattern, int& offset) const;

	/**
	 * Gets the dash pattern of the current instance of %Canvas.
	 *
	 * @since 2.1
	 *
	 * @return		An error code
	 * @param[out]	pattern			The list containing the information of dash pattern
	 * @param[out]	offset			The offset into the dash pattern at which the stroke must start
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specific input parameter is invalid.
	 */
	result GetDashPattern(Tizen::Base::Collection::IListT<float>& pattern, float& offset) const;

	/**
	 * Sets the dash pattern for the current instance of %Canvas.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	pattern			The list containing the information of dash pattern.
	 * @param[in]	offset			The offset into the dash pattern at which the stroke must start
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specific input parameter is invalid.
	 */
	result SetDashPattern(const Tizen::Base::Collection::IListT<int>& pattern, int offset);

	/**
	 * Sets the dash pattern for the current instance of %Canvas.
	 *
	 * @since 2.1
	 *
	 * @return		An error code
	 * @param[in]	pattern			The list containing the information of dash pattern
	 * @param[in]	offset			The offset into the dash pattern at which the stroke must start
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specific input parameter is invalid.
	 */
	result SetDashPattern(const Tizen::Base::Collection::IListT<float>& pattern, float offset);

	/**
	 * Sets the line cap style.
	 *
	 * @since 2.1
	 *
	 * @return		An error code
	 * @param[in]	lineCapStyle	The new line cap style
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 */
	result SetLineCapStyle(LineCapStyle lineCapStyle);

	/**
	 * Gets the line cap style for the current instance.
	 *
	 * @since 2.1
	 *
	 * @return		The current line cap style
	 * @remarks		The default style is @c LINE_CAP_STYLE_ROUND.
	 */
	LineCapStyle GetLineCapStyle(void) const;

	/**
	 * Sets the line join style.
	 *
	 * @since 2.1
	 *
	 * @return		An error code
	 * @param[in]	lineJoinStyle	The new line join style
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 */
	result SetLineJoinStyle(LineJoinStyle lineJoinStyle);

	/**
	 * Gets the line join style for the current instance.
	 *
	 * @since 2.1
	 *
	 * @return		The current line join style
	 * @remarks		The default style is @c LINE_JOIN_STYLE_ROUND.
	 */
	LineJoinStyle GetLineJoinStyle(void) const;

	/**
	 * Gets the color information at the specified point.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point			The location of the point relative to the upper-left corner of the current instance of %Canvas @n
	 *								The point must not fall outside the edges of %Canvas. If this
	 *								condition is not satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @param[out]	color			An instance of Color
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result GetPixel(const Point& point, Color& color) const;

	/**
	 * Gets the color information at a specified point.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	point			The location of the point relative to the upper-left corner of the current instance of %Canvas @n
	 *								The point must not fall outside the edges of %Canvas. If this
	 *								condition is not satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @param[out]	color			An instance of Color
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result GetPixel(const FloatPoint& point, Color& color) const;

	/**
	 * Sets a point at the specified coordinate.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point			The location of the point relative to the upper-left corner of the current instance of %Canvas @n
	 *								The point must not entirely fall outside the edges of %Canvas.
	 *								If this condition is not satisfied, the @c E_OUT_OF_RANGE exception
	 *								is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result SetPixel(const Point& point);

	/**
	 * Sets a point at a specified coordinate.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point			The location of the point relative to the upper-left corner of the current instance of %Canvas @n
	 *								The point must not entirely fall outside the edges of %Canvas.
	 *								If this condition is not satisfied, the @c E_OUT_OF_RANGE exception
	 *								is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result SetPixel(const FloatPoint& point);

	/**
	 * Draws a line between the two specified points.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point1				The starting point
	 * @param[in]	point2				The end point
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result DrawLine(const Point& point1, const Point& point2);

	/**
	 * Draws a line between the two specified points.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	point1				The starting point
	 * @param[in]	point2				The end point
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result DrawLine(const FloatPoint& point1, const FloatPoint& point2);

	/**
	 * Draws a rectangle.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect				The rectangle to draw on the %Canvas control @n
	 *									The width and height of the rectangle must be greater than or equal to @c 0.
	 *									The rectangle must not entirely fall outside the edges of
	 *									the %Canvas control. If these conditions are not satisfied,
	 *									the @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 */
	result DrawRectangle(const Rectangle& rect);

	/**
	 * Draws a rectangle.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect				The rectangle that is drawn on the %Canvas control @n
	 *									The width and height of the rectangle must be greater than or equal to @c 0.0f.
	 *									The rectangle must not entirely fall outside the edges of
	 *									the %Canvas control. If these conditions are not satisfied,
	 *									the @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 */
	result DrawRectangle(const FloatRectangle& rect);

	/**
	 * Fills a rectangular region of the current instance of %Canvas with the specified color.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	color			The fill color
	 * @param[in]	rect			The rectangular region on the %Canvas control @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result FillRectangle(const Color& color, const Rectangle& rect);

	/**
	 * Fills a rectangular region of the current instance of %Canvas with a specified color.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	color			The fill color
	 * @param[in]	rect			The rectangular region on the %Canvas control @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.0f.
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result FillRectangle(const Color& color, const FloatRectangle& rect);

	/**
	 * Draws a round-edged rectangle.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	arcDim			The width and height of the round edge @n
	 *							The width and height in the @c arcDim parameter must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result DrawRoundRectangle(const Rectangle& rect, const Dimension& arcDim);

	/**
	 * Draws a round-edged rectangle.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.0f.
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	arcDim			The width and height of the round edge @n
	 *							The width and height in the @c arcDim parameter must be greater than or equal to @c 0.0f.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result DrawRoundRectangle(const FloatRectangle& rect, const FloatDimension& arcDim);

	/**
	 * Draws a filled rectangle.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	color			The fill color
	 * @param[in]	rect			The location and size of the rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	arcDim			The width and height of the round edge @n
	 *							The width and height mentioned in the @c arcDim parameter must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result FillRoundRectangle(const Color& color, const Rectangle& rect, const Dimension& arcDim);

	/**
	 * Draws a filled rectangle.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	color			The fill color
	 * @param[in]	rect			The location and size of the rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.0f.
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	arcDim			The width and height of the round edge @n
	 *							The width and height mentioned in the @c arcDim parameter must be greater than or equal to @c 0.0f.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result FillRoundRectangle(const Color& color, const FloatRectangle& rect, const FloatDimension& arcDim);

	/**
	 * Draws an ellipse.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the bounding rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result DrawEllipse(const Rectangle& rect);

	/**
	 * Draws an ellipse.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the bounding rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.0f.
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result DrawEllipse(const FloatRectangle& rect);

	/**
	 * Draws a filled ellipse with the specified color.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	color			The fill color
	 * @param[in]	rect			The location and size of the bounding rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0. @n
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result FillEllipse(const Color& color, const Rectangle& rect);

	/**
	 * Draws a filled ellipse with a specified color.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	color			The fill color
	 * @param[in]	rect			The location and size of the bounding rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.0f. @n
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result FillEllipse(const Color& color, const FloatRectangle& rect);

	/**
	 * Draws a circular arc.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the bounding rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	startAngle		The starting angle
	 * @param[in]	endAngle		The ending angle
	 * @param[in]	arcStyle		The arc style
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 */
	result DrawArc(const Rectangle& rect, int startAngle, int endAngle, ArcStyle arcStyle);

	/**
	 * Draws a circular arc.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the bounding rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.0f.
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	startAngle		The starting angle
	 * @param[in]	endAngle		The ending angle
	 * @param[in]	arcStyle		The arc style
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 */
	result DrawArc(const FloatRectangle& rect, float startAngle, float endAngle, ArcStyle arcStyle);

	/**
	 * Draws a triangle.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point1				The location of the first vertex
	 * @param[in]	point2				The location of the second vertex
	 * @param[in]	point3				The location of the third vertex
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result DrawTriangle(const Point& point1, const Point& point2, const Point& point3);

	/**
	 * Draws a triangle.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	point1				The location of the first vertex
	 * @param[in]	point2				The location of the second vertex
	 * @param[in]	point3				The location of the third vertex
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result DrawTriangle(const FloatPoint& point1, const FloatPoint& point2, const FloatPoint& point3);

	/**
	 * Draw a filled triangle with the specified color.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	color				The fill color
	 * @param[in]	point1				The location of the first vertex
	 * @param[in]	point2				The location of the second vertex
	 * @param[in]	point3				The location of the third vertex
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result FillTriangle(const Color& color, const Point& point1, const Point& point2, const Point& point3);

	/**
	 * Draw a filled triangle with a specified color.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	color				The fill color
	 * @param[in]	point1				The location of the first vertex
	 * @param[in]	point2				The location of the second vertex
	 * @param[in]	point3				The location of the third vertex
	 * @exception	E_SUCCESS			The method is successful.
	 */
	result FillTriangle(const Color& color, const FloatPoint& point1, const FloatPoint& point2, const FloatPoint& point3);

	/**
	 * Draws a poly-line.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	points				A list containing the location of points @n
	 *									The number of points must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result DrawPolyline(const Tizen::Base::Collection::IList& points);

	/**
	 * Draws a polygon.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	points				A list containing the locations of the vertices of the polygon @n
	 *									The number of points must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result DrawPolygon(const Tizen::Base::Collection::IList& points);

	/**
	 * Draws a filled polygon with the specified color.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	color				The fill color
	 * @param[in]	points				A list containing the locations of the vertices of the polygon @n
	 *									The number of points must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result FillPolygon(const Color& color, const Tizen::Base::Collection::IList& points);

	/**
	 * Sets a font to the %Canvas control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	font				The font @n
	 *									It must be constructed before being passed to this method.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 */
	result SetFont(const Font& font);

	/**
	 * Gets a font of the %Canvas control.
	 *
	 * @since		2.0
	 *
	 * @return		The font of the %Canvas control, @n
	 *				else @c null if the method fails
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception   	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remarks
	 *			- The specific error code can be accessed using the GetLastResult() method.
	 *			- If a font is not set with the SetFont() method, this method returns the system default font.
	 */
	Font* GetFontN(void) const;

	/**
	 * Draws a text at the specified location.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point				The location to draw the text
	 * @param[in]	text				The text to draw
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OPERATION_FAILED  The operation has failed.
	 * @remarks
	 *			- The foreground color (RGB value only) of the %Canvas control is used as the text color.
	 *			- The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.
	 */
	result DrawText(const Point& point, const Tizen::Base::String& text);

	/**
	 * Draws a text at a specified location.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	point				The location to draw the text
	 * @param[in]	text				The text to draw
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OPERATION_FAILED  The operation has failed.
	 * @remarks
	 *			- The foreground color (RGB value only) of the %Canvas control is used as the text color.
	 *			- The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.
	 */
	result DrawText(const FloatPoint& point, const Tizen::Base::String& text);

	/**
	 * Draws a text at the specified location and length.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point				The location to draw the text
	 * @param[in]	text				The text to draw
	 * @param[in]	length				The number of characters in the string @n
	 *									It must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_OPERATION_FAILED  The operation has failed.
	 * @remarks
	 *			- The foreground color (RGB value only) of the %Canvas control is used as the text color.
	 *			- The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.
	 */
	result DrawText(const Point& point, const Tizen::Base::String& text, int length);

	/**
	 * Draws a text at a specified location and length.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	point				The location to draw the text
	 * @param[in]	text				The text to draw
	 * @param[in]	length				The number of characters in the string @n
	 *									It must be greater than or equal to @c 0.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_OPERATION_FAILED  The operation has failed.
	 * @remarks
	 *			- The foreground color (RGB value only) of the %Canvas control is used as the text color.
	 *			- The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.
	 */
	result DrawText(const FloatPoint& point, const Tizen::Base::String& text, int length);

	/**
	 * Draws a text with an outline rendering at the specified location.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    point               The location to draw the text
	 * @param[in]    text                The text to draw @n
	 * @param[in]    outlineColor        The color that is set as outline color
	 * @exception    E_SUCCESS           The method is successful.
	 * @exception    E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception    E_OUT_OF_RANGE      The value of the argument is outside the valid range defined by the method.
	 * @exception    E_OPERATION_FAILED  The operation has failed.
	 * @remarks
	 *			- The foreground color (RGB value only) of the %Canvas control is used as the text color.
	 *			- The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.
	 */
	result DrawText(const Point& point, const Tizen::Base::String& text, const Color& outlineColor);

	/**
	 * Draws a text with an outline rendering at a specified location.
	 *
	 * @since        2.1
	 *
	 * @return       An error code
	 * @param[in]    point               The location to draw the text
	 * @param[in]    text                The text to draw
	 * @param[in]    outlineColor        The color that is set as outline color
	 * @exception    E_SUCCESS           The method is successful.
	 * @exception    E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception    E_OUT_OF_RANGE      The value of the argument is outside the valid range defined by the method.
	 * @exception    E_OPERATION_FAILED  The operation has failed.
	 * @remarks
	 *			- The foreground color (RGB value only) of the %Canvas control is used as the text color.
	 *			- The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.
	 */
	result DrawText(const FloatPoint& point, const Tizen::Base::String& text, const Color& outlineColor);

	/**
	 * Draws a text with an outline rendering at the specified location and length.
	 *
	 * @since        2.0
	 *
	 * @return       An error code
	 * @param[in]    point               The location to draw the text
	 * @param[in]    text                The text to draw
	 * @param[in]    length              The number of characters in the string @n
	 *                                   It must be greater than or equal to @c 0.
	 * @param[in]    outlineColor        The color that is set as outline color
	 * @exception    E_SUCCESS           The method is successful.
	 * @exception    E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception    E_OUT_OF_RANGE      The value of the argument is outside the valid range defined by the method.
	 * @exception    E_OPERATION_FAILED  The operation has failed.
	 * @remarks
	 *			- The foreground color (RGB value only) of the %Canvas control is used as the text color.
	 *			- The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.
	 */
	result DrawText(const Point& point, const Tizen::Base::String& text, int length, const Color& outlineColor);

	/**
	 * Draws a text with an outline rendering at a specified location and length.
	 *
	 * @since        2.1
	 *
	 * @return       An error code
	 * @param[in]    point               The location to draw the text
	 * @param[in]    text                The text to draw
	 * @param[in]    length              The number of characters in the string @n
	 *                                   It must be greater than or equal to @c 0.
	 * @param[in]    outlineColor        The color that is set as outline color
	 * @exception    E_SUCCESS           The method is successful.
	 * @exception    E_INVALID_ARG       A specified input parameter is invalid.
	 * @exception    E_OUT_OF_RANGE      The value of the argument is outside the valid range defined by the method.
	 * @exception    E_OPERATION_FAILED  The operation has failed.
	 * @remarks
	 *			- The foreground color (RGB value only) of the %Canvas control is used as the text color.
	 *			- The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.
	 */
	result DrawText(const FloatPoint& point, const Tizen::Base::String& text, int length, const Color& outlineColor);

	/**
	 * Draws an enriched text at the specified area.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point					The location to draw the text
	 * @param[in]	enrichedText			The TextElement to draw
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	A specified device is invalid.
	 * @remarks
	 *			- The foreground color (RGB value only) of the %Canvas control is used as the text color.
	 *			- The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.
	 */
	result DrawText(const Point& point, const EnrichedText& enrichedText);

	/**
	 * Draws an enriched text at a specified area.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	point					The location to draw the text
	 * @param[in]	enrichedText			The TextElement to draw
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	A specified device is invalid.
	 * @remarks
	 *			- The foreground color (RGB value only) of the %Canvas control is used as the text color.
	 *			- The em square has a defined font size. As a result, if the font's glyph exceeds its em square, it will be scaled down when it is drawn.
	 */
	result DrawText(const FloatPoint& point, const EnrichedText& enrichedText);

	/**
	 * Draws a bitmap image at the specified location.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point				The location of the upper-left corner of the bitmap
	 * @param[in]	bitmap				The bitmap to draw @n
	 *									It must be constructed before being passed into this
	 *									method. ::BITMAP_PIXEL_FORMAT_R8G8B8A8 is
	 *									not applicable for this method. The bitmap must not
	 *									entirely fall outside the edges of the %Canvas control. If
	 *									this condition is not satisfied, the @c E_OUT_OF_RANGE exception
	 *									is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result DrawBitmap(const Point& point, const Bitmap& bitmap);

	/**
	 * Draws a bitmap image at a specified location.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	point				The location of the upper-left corner of the bitmap
	 * @param[in]	bitmap				The bitmap to draw @n
	 *									It must be constructed before being passed into this
	 *									method. ::BITMAP_PIXEL_FORMAT_R8G8B8A8 is
	 *									not applicable for this method. The bitmap must not
	 *									entirely fall outside the edges of the %Canvas control. If
	 *									this condition is not satisfied, the @c E_OUT_OF_RANGE exception
	 *									is returned.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 */
	result DrawBitmap(const FloatPoint& point, const Bitmap& bitmap);

	/**
	 * Draws a bitmap image at the specified location.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the scaled bitmap @n
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If this condition is not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	bitmap			The bitmap to draw @n
	 *								It must be constructed well before being passed into this
	 *								method.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @remarks BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 */
	result DrawBitmap(const Rectangle& rect, const Bitmap& bitmap);

	/**
	 * Draws a bitmap image at a specified location.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect			The location and size of the scaled bitmap @n
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If this condition is not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	bitmap			The bitmap to draw @n
	 *								It must be constructed well before being passed into this
	 *								method.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @remarks BitmapPixelFormat::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 */
	result DrawBitmap(const FloatRectangle& rect, const Bitmap& bitmap);

	/**
	 * Draws a color data corresponding to a rectangle of pixels from the specified bitmap onto %Canvas.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	destRect			The destination rectangle of %Canvas @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle defined by @c destRect will be clipped at the edges
	 *								of the %Canvas control to prevent the rectangle from falling
	 *								outside the edges of the %Canvas control. The destination
	 *								rectangle of a %Canvas control must not fall outside the edges
	 *								of the %Canvas control entirely. If these conditions are not
	 *								satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	srcBitmap		The bitmap to draw
	 * @param[in]	srcRect			The source rectangle of a bitmap @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle defined by @c srcRect will be clipped at the edges
	 *								of the bitmap to prevent the rectangle from falling outside the
	 *								edges of the bitmap. The source rectangle of a bitmap must not
	 *								fall outside the edges of the bitmap entirely. If these
	 *								conditions are not satisfied, the @c E_OUT_OF_RANGE exception is
	 *								thrown.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @remarks		If the source and destination rectangles are not of the same size,
	 *				the source bitmap is stretched to match the destination rectangle. @n
	 *				::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 */
	result DrawBitmap(const Rectangle& destRect, const Bitmap& srcBitmap, const Rectangle& srcRect);

	/**
	 * Draws a color data corresponding to a rectangle of pixels from a specified bitmap onto %Canvas.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	destRect			The destination rectangle of %Canvas @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.0f.
	 *								The rectangle defined by @c destRect will be clipped at the edges
	 *								of the %Canvas control to prevent the rectangle from falling
	 *								outside the edges of the %Canvas control. The destination
	 *								rectangle of a %Canvas control must not fall outside the edges
	 *								of the %Canvas control entirely. If these conditions are not
	 *								satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	srcBitmap		The bitmap to draw
	 * @param[in]	srcRect			The source rectangle of a bitmap @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.0f.
	 *								The rectangle defined by @c srcRect will be clipped at the edges
	 *								of the bitmap to prevent the rectangle from falling outside the
	 *								edges of the bitmap. The source rectangle of a bitmap must not
	 *								fall outside the edges of the bitmap entirely. If these
	 *								conditions are not satisfied, the @c E_OUT_OF_RANGE exception is
	 *								thrown.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @remarks		If the source and destination rectangles are not of the same size,
	 *				the source bitmap is stretched to match the destination rectangle. @n
	 *				::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 */
	result DrawBitmap(const FloatRectangle& destRect, const Bitmap& srcBitmap, const FloatRectangle& srcRect);

	/**
	 * Draws a flipped bitmap image at the specified location.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @param[in]   point			The location to draw the bitmap
	 * @param[in]   bitmap          The bitmap to draw @n
	 *                              It must be constructed before being passed to this method.
	 * @param[in]   dir             The flip direction
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   A specified input parameter is invalid.
	 * @remarks		::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 */
	result DrawBitmap(const Point& point, const Bitmap& bitmap, FlipDirection dir);

	/**
	 * Draws a flipped bitmap image at a specified location.
	 *
	 * @since		2.1
	 *
	 * @return      An error code
	 * @param[in]   point			The location to draw the bitmap
	 * @param[in]   bitmap          The bitmap to draw @n
	 *                              It must be constructed before being passed to this method.
	 * @param[in]   dir             The flip direction
	 * @exception   E_SUCCESS       The method is successful.
	 * @exception   E_INVALID_ARG   A specified input parameter is invalid.
	 * @remarks		::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 */
	result DrawBitmap(const FloatPoint& point, const Bitmap& bitmap, FlipDirection dir);

	/**
	 * Draws a rotated bitmap image at the specified location.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point			A location to draw a bitmap image @n
	 *                              This location is relatively defined from the origin (upper-left
	 *								corner) of the %Canvas control.
	 * @param[in]   bitmap           The bitmap to draw @n
	 *                               It must be constructed before being passed to this method.
	 * @param[in]   pivot            The center of rotation of a bitmap image @n
	 *                               This center is relatively defined from the origin (upper-left
	 *								corner) of the bitmap.
	 * @param[in]   degree           The amount of rotation in degrees
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_INVALID_ARG    A specified input parameter is invalid.
	 * @remarks     ::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 * 				 This method faces a problem while working in an unbounded region and it affects the whole Canvas pixels in the case of ::COMPOSITE_MODE_SRC or ::COMPOSITE_MODE_CLEAR.
	 * @image		html	graphics_rotatebitmap.PNG
	 */
	result DrawBitmap(const Point& point, const Bitmap& bitmap, const Point& pivot, int degree);

	/**
	 * Draws a rotated bitmap image at a specified location.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	point			A location to draw a bitmap image @n
	 *                              This location is relatively defined from the origin (upper-left
	 *								corner) of the %Canvas control.
	 * @param[in]   bitmap           The bitmap to draw @n
	 *                               It must be constructed before being passed to this method.
	 * @param[in]   pivot            The center of rotation of a bitmap image @n
	 *                               This center is relatively defined from the origin (upper-left
	 *								corner) of the bitmap.
	 * @param[in]   degree           The amount of rotation in degrees
	 * @exception   E_SUCCESS        The method is successful.
	 * @exception   E_INVALID_ARG    A specified input parameter is invalid.
	 * @remarks     ::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method.
	 * 				 This method faces a problem while working in an unbounded region and it affects the whole Canvas pixels in the case of ::COMPOSITE_MODE_SRC or ::COMPOSITE_MODE_CLEAR.
	 * @image		html	graphics_rotatebitmap.PNG
	 */
	result DrawBitmap(const FloatPoint& point, const Bitmap& bitmap, const FloatPoint& pivot, float degree);

	/**
	 * Draws a nine-patched bitmap at the specified location.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]   rect			The location and size of the nine-patched bitmap @n
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If this condition is not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	bitmap			The bitmap to draw @n
	 *								It must be constructed before being passed to this method.
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @remarks    ::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method. @n
	 *             The nine-patched bitmap must have a stretchable section by drawing one (or more) 1-pixel-wide black line(s) in the
	 *             left and top part of the border.
	 * @image			html	graphics_ninepatchedbitmap.PNG
	 *
	 */
	result DrawNinePatchedBitmap(const Rectangle& rect, const Bitmap& bitmap);

	/**
	 * Draws a nine-patched bitmap at a specified location.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]   rect			The location and size of the nine-patched bitmap @n
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If this condition is not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @param[in]	bitmap			The bitmap to draw @n
	 *								It must be constructed before being passed to this method.
	 * @exception	E_SUCCESS       The method is successful.
	 * @exception	E_INVALID_ARG   A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 * @remarks    ::BITMAP_PIXEL_FORMAT_R8G8B8A8 is not applicable for this method. @n
	 *             The nine-patched bitmap must have a stretchable section by drawing one (or more) 1-pixel-wide black line(s) in the
	 *             left and top part of the border.
	 * @image			html	graphics_ninepatchedbitmap.PNG
	 *
	 */
	result DrawNinePatchedBitmap(const FloatRectangle& rect, const Bitmap& bitmap);

	/**
	 * Shows the current instance of %Canvas on the device screen.
	 *
	 * @since			2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION		This operation is not supported.
	 *
	 */
	result Show(void);

	/**
	 */


	/**
	 * @if OSPDEPREC
	 * Shows the specified rectangle of the current instance of %Canvas on the device screen.
	 *
	 * @brief	<i> [Deprecated] </i>
	 * @deprecated	This method is deprecated. Instead of this method, use the Show().
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			The bounds of the %Canvas control to display @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The rectangle must not entirely fall outside the edges of the
	 *								%Canvas control. If these conditions are not satisfied, the
	 *								@c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 *
	 * @remark	If you use Show(Rectangle&) in Tizen, this method works differently. @n
	 *		This method shows the screen entirely not partially in Tizen.
	 * @endif
	 */
	result Show(const Rectangle& rect);

	/**
	 * Gets the location and size of the current %Canvas instance on the device screen.
	 *
	 * @since	2.0
	 *
	 * @return	The Rectangle instance containing the location and size of the current %Canvas instance
	 * @remarks If this %Canvas instance is a Window %Canvas, it returns Rectangle(0, 0, w, h).
	 */
	Rectangle GetBounds(void) const;

	/**
	 * Gets the location and size of the current %Canvas instance on the device screen.
	 *
	 * @since	2.1
	 *
	 * @return	The FloatRectangle instance containing the location and size of the current %Canvas instance
	 * @remarks If this %Canvas instance is a Window %Canvas, it returns FloatRectangle(0.0f, 0.0f, w, h).
	 */
	FloatRectangle GetBoundsF(void) const;

	/**
	 * Gets the actual location and size of the current %Canvas instance on the device screen.
	 *
	 * @since	2.1
	 *
	 * @return	The FloatRectangle instance containing the actual location and size of the current %Canvas instance
	 * @remarks If this %Canvas instance is a Window %Canvas, it returns FloatRectangle(0.0f, 0.0f, w, h).
	 */
	FloatRectangle GetActualBounds(void) const;

	/**
	 * Sets the clip rectangle for a %Canvas control. @n
	 * When a clip rectangle is set, any drawing is restricted within the specified rectangular area. The
	 * rectangular area defined is clipped at the edges of the %Canvas control so as to prevent the clipped rectangle
	 * from falling outside the %Canvas control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect			The bounds of the clip rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.
	 *								The clip rectangle for a %Canvas control must not entirely fall
	 *								outside the edges of the %Canvas control. If these conditions are
	 *								not satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result SetClipBounds(const Rectangle& rect);

	/**
	 * Sets the clip rectangle for a %Canvas control. @n
	 * When a clip rectangle is set, any drawing is restricted within a specified rectangular area. The
	 * rectangular area defined is clipped at the edges of the %Canvas control so as to prevent the clipped rectangle
	 * from falling outside the %Canvas control.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	rect			The bounds of the clip rectangle @n
	 *								The width and height of the rectangle must be greater than or equal to @c 0.0f.
	 *								The clip rectangle for a %Canvas control must not entirely fall
	 *								outside the edges of the %Canvas control. If these conditions are
	 *								not satisfied, the @c E_OUT_OF_RANGE exception is returned.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The value of the argument is outside the valid range defined by the method.
	 */
	result SetClipBounds(const FloatRectangle& rect);

	/**
	 * Gets the bounds of the clip rectangle of a %Canvas control.
	 *
	 * @since		2.0
	 *
	 * @return		An instance of Rectangle indicating the bounds of the clip rectangle
	 */
	Rectangle GetClipBounds(void) const;

	/**
	 * Gets the bounds of the clip rectangle of a %Canvas control.
	 *
	 * @since		2.1
	 *
	 * @return		An instance of FloatRectangle indicating the bounds of the clip rectangle
	 */
	FloatRectangle GetClipBoundsF(void) const;

	/**
	 * Locks the %Canvas control for direct pixel access. @n
	 * This sets up a %Canvas control for accessing the pixels directly. Between the calls to the
	 * Canvas::Lock() and Canvas::UnLock() methods, the data can be written to and read from the
	 * Canvas control's pixels. Once the operations on the %Canvas control's pixels are finished, the
	 * %Canvas::Unlock() method must be called to release the lock.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	info			The information of the %Canvas control
	 * @param[in]	timeout			The time, in milliseconds, that the caller waits to obtain the lock @n
	 *								If the lock attempt fails, @c E_TIMEOUT is returned. The default value
	 *								is @c INFINITE, which means that the method does not return until the lock
	 *								is acquired.
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_TIMEOUT		The operation cannot be completed within the specified time period.
	 * @exception	E_SYSTEM		An unknown operating system error has occurred.
	 * @remarks	BufferInfo contains a valid physical memory information, regardless of the
	 *				logical position and size of the %Canvas control.
	 */
	result Lock(BufferInfo& info, long timeout = INFINITE);

	/**
	 * Unlocks the %Canvas control.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			An unknown operating system error has occurred.
	 * @remarks		The %Canvas control must be unlocked as soon as possible.
	 */
	result Unlock(void);

	/**
	 * Sets the foreground color.
	 *
	 * @since		2.0
	 *
	 * @param[in]	color	The color that is set as foreground color
	 */
	void SetForegroundColor(const Color& color);

	/**
	 * Gets the foreground color.
	 *
	 * @since		2.0
	 *
	 * @return		The foreground color
	 */
	Color GetForegroundColor(void) const;

	/**
	 * Sets the background color.
	 *
	 * @since		2.0
	 *
	 * @param[in]	color	The color that is set as background color
	 */
	void SetBackgroundColor(const Color& color);

	/**
	 * Gets the background color.
	 *
	 * @since		2.0
	 *
	 * @return		The background color
	 */
	Color GetBackgroundColor(void) const;

	/**
	 * Sets the current instance of %Canvas to the specified point.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated   This method is deprecated.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	point					The new position
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	Window %Canvas does not support moving the position.
	 * @remarks		This method has been influenced on only Memory canvas. However, Show() for Memory canvas is not supported anymore.
	 */
	result SetPosition(const Point& point);

	/**
	 * Sets the current instance of %Canvas to the specified point.
	 *
	 * @brief <i> [Deprecated] </i>
	 * @deprecated   This method is deprecated.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	x						The new x-coordinate
	 * @param[in]	y						The new y-coordinate
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_UNSUPPORTED_OPERATION	Window %Canvas does not support moving the position.
	 * @remarks		This method has been influenced on only Memory canvas. However, Show() for Memory canvas is not supported anymore.
	 */
	result SetPosition(int x, int y);

	/**
	 * Sets the composite mode.
	 *
	 * @since	2.1
	 *
	 * @return		An error code
	 * @param[in]	compositeMode			The new composite mode
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified input parameter is invalid.
	 */
	result SetCompositeMode(CompositeMode compositeMode);

	/**
	 * Gets the composite mode for the current instance.
	 *
	 * @since	2.1
	 *
	 * @return	The current composite mode
	 * @remarks	The default value is @c COMPOSITE_MODE_SRC_OVER.
	 */
	 CompositeMode GetCompositeMode(void) const;

	/**
	* Enables or disables anti-aliasing to the current instance of %Canvas.
	*
	* @since		2.1
	*
	* @param[in]	enable		Set to @c true to enable anti-aliasing for the current instance of %Canvas, @n
	*							else @c false
	* @remarks		By default, the anti-aliasing is enabled.
	*/
	void SetAntiAliasingEnabled(bool enable);

	/**
	* Checks whether anti-aliasing is enabled to the current instance.
	*
	* @since	2.1
	*
	* @return	@c true if the anti-aliasing is enabled to the current instance.
	*			else @c false
	*/
	bool IsAntiAliasingEnabled(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Canvas(const Canvas& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Canvas& operator =(const Canvas& rhs);

	friend class Bitmap;
	friend class TextElement;

private:
	friend class _CanvasImpl;

	//
	// This variable is for internal use only.
	// Using this variable can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// @since 2.0
	//
	class _CanvasImpl* __pImpl;

}; // Canvas

}} // Tizen::Graphics

#endif //_FGRP_CANVAS_H_
