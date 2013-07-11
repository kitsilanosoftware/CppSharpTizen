//
// Open Service Platform
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
 * @file		FBaseResult.h
 * @brief		This is the header file for the %Result class.
 *
 * This header file contains the declaration of the %Result class.
 */
#ifndef _FBASE_RESULT_H_
#define _FBASE_RESULT_H_

#include <FBaseTypes.h>
#include <FBaseErrors.h>
#include <stdarg.h>


#ifdef __cplusplus
extern "C" {
#endif


#define SetLastResultReturn(r) \
	SetLastResult(r); \
	return r;


_OSP_EXPORT_ result GetLastResult(void);

_OSP_EXPORT_ void SetLastResult(result r);

_OSP_EXPORT_ void ClearLastResult(void);

struct ErrorTable
{
	result error;
	char errorString[50];
};

_OSP_EXPORT_ void RegisterErrorTable(unsigned long package, struct ErrorTable* pErrorTable);

_OSP_EXPORT_ const char* GetErrorMessage(result value);

_OSP_EXPORT_ result TransExceptionsExclusiveInternal(result r, result e, int num,...);

_OSP_EXPORT_ result TransExceptionsInclusiveInternal(result r, result e, int num,...);

#define NUMARGS(...)  (sizeof((result[]){0, ##__VA_ARGS__})/sizeof(result)-1)

/**
* This macro returns translated exception when the checked exception doesn't correspond with the conditional exceptions.
* In contrast, this macro returns the checked exception if it corresponds with the conditional exceptions. 
*
* @since 2.0
*
* @return         The translated exception 
* @param[in]   r              The result that will be checked
* @param[in]   e              The translated exception
* @param[in]   ...            The list of exceptions that will be excluded in translation process @n
*                             All other exceptions than this list will be translated into @c e. 
*
*
*/

#define TransExceptionsExclusive(r, e, ...)     TransExceptionsExclusiveInternal(r, e, NUMARGS(__VA_ARGS__), __VA_ARGS__)

 
/**
* This macro returns translated exception when the checked exception corresponds with the conditional exceptions.
* In contrast, this macro returns the checked exception if it doesn't correspond with the conditional exceptions.
*
* @since 2.0
*
* @return         The translated exception
* @param[in]   r              The result that will be checked
* @param[in]   e              The translated exception
* @param[in]   ...            The list of exceptions that will be included in translation process @n
*                             All exceptions in this list will be translated into @c e.
*
*/

#define TransExceptionsInclusive(r, e, ...)     TransExceptionsInclusiveInternal(r, e, NUMARGS(__VA_ARGS__), __VA_ARGS__)


#ifdef __cplusplus
}
#endif

#endif //_FBASE_RESULT_H_
