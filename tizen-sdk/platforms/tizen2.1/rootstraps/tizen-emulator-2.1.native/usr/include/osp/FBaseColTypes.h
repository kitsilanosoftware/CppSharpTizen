//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FBaseColTypes.h
 * @brief		This is the header file for the element deleter.
 *
 * This header file contains the declarations of the element deleter.
 * Depending on the element deleter, collection decides whether to remove the object or not.
 */
#ifndef _FBASE_COL_TYPES_H_
#define _FBASE_COL_TYPES_H_

#include <FBaseObject.h>

namespace Tizen { namespace Base { namespace Collection
{

typedef void (*DeleterFunctionType)(Object* pObj);

/**
 * This function does not remove the object.
 *
 * @since 2.0
 *
 * @param[in]	pObj		The pointer to the object to remove
 */
_OSP_EXPORT_ void NoOpDeleter(Object* pObj);

/**
 * This function removes the single object.
 *
 * @since 2.0
 *
 * @param[in]	pObj		The pointer to the object to remove
 */
_OSP_EXPORT_ void SingleObjectDeleter(Object* pObj);

/**
 * This function removes the array object.
 *
 * @since 2.0
 *
 * @param[in]	pObj		The pointer to the object to remove
 */
_OSP_EXPORT_ void ArrayDeleter(Object* pObj);

}}} // Tizen::Base::Collection

#endif  // _FBASE_COL_TYPES_H_
