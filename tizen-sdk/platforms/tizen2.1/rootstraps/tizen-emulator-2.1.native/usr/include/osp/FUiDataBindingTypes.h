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
 * @file	FUiDataBindingTypes.h
 * @brief	This is the header file for the data binding enumerations.
 *
 * This header file contains the declarations of the data binding enumerations.
 */

#ifndef _FUI_DATA_BINDING_TYPES_H_
#define _FUI_DATA_BINDING_TYPES_H_

namespace Tizen { namespace Ui
{
/**
* @enum        DataBindingFlow
*
* Defines the possible data flow types.
*
* @since 2.0
*/
enum DataBindingFlow
{
	DATA_BINDING_FLOW_ONE_WAY = 0,                                    /**< The data flow is one way from source to target */
	DATA_BINDING_FLOW_ONE_WAY_TO_SOURCE = 1,                   /**< The data flow is one way from target to source */
	DATA_BINDING_FLOW_TWO_WAY = 2                                    /**< The data flow is two way */
};

/**
* @enum        DataBindingTrigger
*
* Defines the possible data binding trigger types.
*
* @since 2.0
*/
enum DataBindingTrigger
{
	DATA_BINDING_TRIGGER_IMMEDIATE = 0,                   /**< Immediate trigger */
	DATA_BINDING_TRIGGER_EXPLICIT = 1,                       /**< Explicit trigger */
};

/**
* @enum        DataBindingDataType
*
* Defines the possible data types for data binding source.
*
* @since 2.0
*/
enum DataBindingDataType
{
	DATA_BINDING_DATA_TYPE_BOOLEAN = 0,                             /**< Boolean type */
	DATA_BINDING_DATA_TYPE_COLOR = 1,                                 /**< Color type */
	DATA_BINDING_DATA_TYPE_DIMENSION = 2,                          /**< Dimension type */
	DATA_BINDING_DATA_TYPE_DOUBLE = 3,                                /**< Double type */
	DATA_BINDING_DATA_TYPE_FLOAT = 4,                                  /**< Float type */
	DATA_BINDING_DATA_TYPE_INTEGER = 5,                              /**<  Integer type */
	DATA_BINDING_DATA_TYPE_LONG = 6,                                  /**< Long type */
	DATA_BINDING_DATA_TYPE_POINT = 7,                                  /**< Point type */
	DATA_BINDING_DATA_TYPE_RECTANGLE = 8,                           /**< Rectangle type */
	DATA_BINDING_DATA_TYPE_STRING = 9,                                 /**< String type */
	DATA_BINDING_DATA_TYPE_FLOAT_DIMENSION = 10,          /**<  Dimension type in floating-point number @b Since: @b 2.1 */
	DATA_BINDING_DATA_TYPE_FLOAT_POINT = 11,                  /**<Point type in floating-point number @b Since: @b 2.1 */
	DATA_BINDING_DATA_TYPE_FLOAT_RECTANGLE = 12           /**<Rectangle type in floating-point number @b Since: @b 2.1 */
};

/**
* @enum        DataBindingDestinationType
*
* Defines the possible destination types for explicit data bindings.
*
* @since 2.0
*/
enum DataBindingDestinationType
{
	DATA_BINDING_DESTINATION_TYPE_SOURCE = 0,                            /**< Update source with latest data of associated target */
	DATA_BINDING_DESTINATION_TYPE_TARGET = 1                              /**< Update target with latest data of associated source */
};

}}// Tizen::Ui
#endif // _FUI_DATA_BINDING_TYPES_H_
