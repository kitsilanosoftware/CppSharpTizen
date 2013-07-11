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
 * @file	FGrpCoordinateSystem.h
 * @brief	This is the header file for the %CoordinateSystem class.
 *
 * This header file contains the declarations of the %CoordinateSystem class.
 */

#ifndef _FGRP_COORDINATE_SYSTEM_H_
#define _FGRP_COORDINATE_SYSTEM_H_


#include <FGrpDimension.h>


namespace Tizen { namespace Graphics
{

/**
 * @class	CoordinateSystem
 * @brief	This class provides various utility methods for coordinate handling.
 *
 * @since 2.0
 *
 * The %CoordinateSystem class provides various utility methods for coordinate handling.
 *
 */
class _OSP_EXPORT_ CoordinateSystem
{
public:
	/**
	 * Returns the screen resolution in logical coordinates.
	 *
	 * @since 2.0
	 *
	 * @return			The screen resolution in logical coordinates
	 */
	static Dimension GetLogicalResolution(void);

	/**
	 * Returns the screen resolution in physical coordinates.
	 *
	 * @since 2.0
	 *
	 * @return			The screen resolution in physical coordinates
	 */
	static Dimension GetPhysicalResolution(void);

	/**
	 * Converts the physical value along x-axis to the logical one.
	 *
	 * @since 2.0
	 *
	 * @return			The converted logical value for the physical one
	 * @param[in]			physicalX	An input physical value to be converted
	 */
	static int ConvertToLogicalX(int physicalX);

	/**
	 * Converts the physical value along y-axis to the logical one.
	 *
	 * @since 2.0
	 *
	 * @return			The converted logical value for the physical one
	 * @param[in]			physicalY	An input physical value to be converted
	 */
	static int ConvertToLogicalY(int physicalY);

	/**
	 * Converts the logical value along x-axis to the physical one.
	 *
	 * @since 2.0
	 *
	 * @return			The converted physical X value
	 * @param[in]			logicalX 	An input logical value to be converted
	 */
	static int ConvertToPhysicalX(int logicalX);

	/**
	 * Converts the logical value along y-axis to the physical one.
	 *
	 * @since 2.0
	 *
	 * @return			The converted physical Y value
	 * @param[in]			logicalY 	An input logical value to be converted
	 */
	static int ConvertToPhysicalY(int logicalY);

private:
	//
	// This default constructor is intentionally declared as private because this class cannot be constructed.
	//
	CoordinateSystem(void);

	//
	// This destructor is intentionally declared as private because this class cannot be constructed.
	//
	~CoordinateSystem(void);

}; // CoordinateSystem

}} // Tizen::Graphics

#endif // _FGRP_COORDINATE_SYSTEM_H_
