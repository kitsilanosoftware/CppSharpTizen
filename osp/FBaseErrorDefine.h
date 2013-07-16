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
 * @file		FBaseErrorDefine.h
 * @brief		This header file defines common error codes.
 *
 * This header file contains the definitions of error codes.
 */

#ifndef _FBASE_ERROR_DEFINE_H_
#define _FBASE_ERROR_DEFINE_H_

#include <FBaseTypes.h>


#define E_SEVERITY_POS                  31
#define E_TYPE_POS                      29

#define SET_E_SEVERITY(X)               (static_cast<unsigned long>(PUT_MASK(0, (X), E_SEVERITY_POS)))
#define SET_E_TYPE(X)                   (static_cast<unsigned long>(PUT_MASK(0, (X), E_TYPE_POS)))
#define SET_E_CAUSE(X)                  (static_cast<unsigned long>(X))


// Error severities
#define E_SUCCESS                       (SET_E_SEVERITY(0))
#define E_FAILURE                       (SET_E_SEVERITY(1))


// Error types
#define ERR_SRC_FRAMEWORK               (E_FAILURE + SET_E_TYPE(1))
#define ERR_SRC_USER                    (E_FAILURE + SET_E_TYPE(2))


// Macros for error codes
#define IsFailed(X)                     (static_cast<long>(X) != E_SUCCESS)


#endif //_FBASE_ERROR_DEFINE_H_
