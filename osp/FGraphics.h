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
 * @file	FGraphics.h
 * @brief	This is the header file for the %Graphics namespace.
 *
 * This header file contains the declarations of the %Graphics namespace.
 *
 */

#ifndef _FGRAPHICS_H_
#define _FGRAPHICS_H_

#include "FGrpPoint.h"
#include "FGrpFloatPoint.h"

#include "FGrpDimension.h"
#include "FGrpFloatDimension.h"

#include "FGrpRectangle.h"
#include "FGrpFloatRectangle.h"

#include "FGrpFloatMatrix4.h"
#include "FGrpFloatVector4.h"
#include "FGrpFloatPoint3.h"

#include "FGrpColor.h"

#include "FGrpPixelFormat.h"

#include "FGrpBufferInfo.h"

#include "FGrpBitmapCommon.h"
#include "FGrpBitmap.h"

#include "FGrpCanvasCommon.h"
#include "FGrpCanvas.h"

#include "FGrpFontCommon.h"
#include "FGrpFont.h"

#include "FGrpTextElement.h"
#include "FGrpEnrichedText.h"

#include "FGrpCoordinateSystem.h"

/**
 * @namespace Tizen::Graphics
 * @brief	This namespace contains classes for drawing-related functionalities.
 *
 * @since	2.0
 *
 * @remarks	@b Header @b %file: @b \#include @b <FGraphics.h> @n
 *			@b Library : @b osp-uifw
 *
 * The %Graphics namespace provides enhanced two-dimensional graphics,
 * text, and imaging capabilities.
 * It supports comprehensive features for rendering geometric primitives, text, and images
 * in a flexible framework for developing rich user
 * interfaces, sophisticated drawing applications, and image editors.
 * This namespace provides additional features such as Bitmap, Font, and Color to enhance the rendered graphics.
 * The user can also use basic data types, Point, Rectangle, and Dimension to construct 2D graphic objects, such as
 * polygons.
 * @n
 * For more information on the %Graphics namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/graphics/graphics_namespace.htm">Graphics Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Graphics namespace.
 * @image html graphics_namespace_class_relationship.png
 *
 * The following example demonstrates how to use the %Graphics namespace.
 *
 *	@code
#include <FBase.h>
#include <FGraphics.h>

using namespace Tizen::Base;
using namespace Tizen::Graphics;

bool
MyClass::GraphicsSample(void)
{
    result r = E_SUCCESS;

    // Creates a canvas instance.
    Canvas* pCanvas = new Canvas();
    r = pCanvas->Construct();
    if (IsFailed(r))
    {
        goto CATCH;
    }

    // Clears
    pCanvas->SetBackgroundColor(Color(0xFF, 0xFF, 0xFF));
    r = pCanvas->Clear();
    if (IsFailed(r))
    {
        goto CATCH;
    }

    // Sets the foreground color of this canvas.
    pCanvas->SetForegroundColor(Color::GetColor(COLOR_ID_GREEN));

    // Draws an ellipse.
    r = pCanvas->DrawEllipse(Rectangle(50, 50, 50, 80));
    if (IsFailed(r))
    {
        goto CATCH;
    }

    r = pCanvas->DrawLine(Point(100, 100), Point(150, 150));
    if (IsFailed(r))
    {
        goto CATCH;
    }

    // Draws a circular arc.
    r = pCanvas->DrawArc(Rectangle(10, 200, 50, 50), 30, 60, ARC_STYLE_PIE);
    if (IsFailed(r))
    {
        goto CATCH;
    }

    {
        // Creates a font instance.
        Font font;
        r = font.Construct(FONT_STYLE_PLAIN, 32);
        if (IsFailed(r))
        {
            goto CATCH;
        }

        // Sets the font to canvas.
        r = pCanvas->SetFont(font);
        if (IsFailed(r))
        {
            goto CATCH;
        }
    }

    // Draws text at the specified location.
    r = pCanvas->DrawText(Point(50, 50), String(L"Hello World"));
    if (IsFailed(r))
    {
        goto CATCH;
    }

    // Shows the drawing result on the device screen.
    r = pCanvas->Show();
    if (IsFailed(r))
    {
        goto CATCH;
    }

    // Cleans up.
    delete pCanvas;

    return true;

CATCH:
    delete pCanvas;

    return false;
}
 *	@endcode
 *
 *
 *
 *
 */
namespace Tizen { namespace Graphics
{

} } // Tizen::Graphics

#endif // _FGRAPHICS_H_
