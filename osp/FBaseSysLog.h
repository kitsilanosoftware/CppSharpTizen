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
 * @file		FBaseSysLog.h
 * @brief		This is the header file for the %Log macros.
 *
 * This header file defines the %Log macros.
 */

#ifndef _FBASE_SYS_LOG_H_
#define _FBASE_SYS_LOG_H_

#include <stdarg.h>
#include <FOspConfig.h>
#include <FBaseDataType.h>
#include <FIoRegistry.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifndef likely
#define likely(x)    __builtin_expect(!!(x), 1)
#endif
#ifndef unlikely
#define unlikely(x)  __builtin_expect(!!(x), 0)
#endif

/** 
 * @mainpage Tizen Platform API Reference
 *
 * The Tizen platform API Reference provides descriptions of APIs for the platform developers.
 */

/**
 * @defgroup GroupMacros Debugging Macros
 *
 * This page describes Tizen debugging macros used by the Tizen modules.
 * These debugging macros should use specific NID ( Namespace ID ) to distinguish each Tizen modules.
 *
 * @since 2.0
 */


/**
 * @addtogroup  GroupMacros
 *
 * @{
 */

/**
 * This macro allows display of informative log messages.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	...         		The message to display
 *
 * The following example demonstrates how to use the SysLog macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   SysLog(NID, "Initialization successful.");
 *
 *	   return true; 
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysLog(NID, ...)               SysLogInternal(NID, __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__)

/**
 * This macro allows display of exception log messages with a tag and sets the last result.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	r			The last result to set
 * @param[in]	...			The message to display
 *
 * The following example demonstrates how to use the SysLogException macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *	   if (something_wrong)   // The Try family macros can be used instead.
 *	   {
 *	      SysLogException(NID,  E_INVALID_ARG, "An unexpected error has occurred.");
 *
 *	      return false;
 *	   }
 *   //...
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysLogException(NID, r, ...)               SysLogExceptionInternal(NID, r, __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__)

/**
 * This macro allows display of informative log messages with a tag.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	tag			The user defined tag
 * @param[in]	...         		The message to display
 *
 * The following example demonstrates how to use the SysLogTag macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   SysLogTag(NID, "MyTag", "Initialization successful.");
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysLogTag(NID, tag, ...)       SysLogTagInternal(NID, tag, __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__)

/**
 * This macro allows display of exception log messages with a tag and sets the last result.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	tag			The user defined tag
 * @param[in]	r			The last result to set
 * @param[in]	...         		The message to display
 *
 * The following example demonstrates how to use the SysLogTagException macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   SysLogExceptionTag(NID, "MyTag", E_INVALID_ARG, "Initialization successful.");
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysLogExceptionTag(NID, tag, r, ...)       SysLogExceptionTagInternal(NID, tag, r, __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__)



/**
 * This macro allows display of informative log message with a tag, when the condition is @c false.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]  	...			The message to display
 *
 * The following example demonstrates how to use the SysTryLog macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *
 *	   SysTryLog(NID, condition, "An unexpected error has occurred.");
 *
 *	   //...
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysTryLog(NID, condition, ...) \
	do \
	{ \
		if (unlikely(!(condition))) {	\
			SysLog(NID, __VA_ARGS__); \
		} \
	} while (0);

/**
 * This macro allows display of informative log message, when the condition is @c false.
 * Executes statements and goes to label.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	expr			Expressions that are evaluated before going to CATCH label
 * @param[in]   ...			The message to display
 *
 * The following example demonstrates how to use the SysTryLogCatch macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *
 *	   SysTryLogCatch(NID, condition, r=E_INVALID_ARG, "An unexpected error has occurred.");
 *
 *	   //...
 *	   CATCH:
 *	   		return false;
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysTryLogCatch(NID, condition, expr, ...)	\
	do \
	{ \
		if (unlikely(!(condition))) { \
			SysLog(NID, __VA_ARGS__); \
			expr; \
			goto CATCH;	\
		} \
	} while (0);

/**
 * This macro allows display of informative log message and returns returnValue, when the condition is @c false.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	returnValue        	The value to return when the condition is @c false
 * @param[in]   ...			The message to display
 *
 * The following example demonstrates how to use the SysTryLogReturn macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *
 *	   SysTryLogReturn(NID, condition, false, "An unexpected error has occurred.");
 *
 *	   //...
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysTryLogReturn(NID, condition, returnValue, ...) \
	do \
	{ \
		if (unlikely(!(condition))) { \
			SysLog(NID, __VA_ARGS__); \
			return returnValue;	\
		} \
	} while (0);


/**
 * This macro allows display of exception log message with a tag and sets the last result, when the condition is @c false.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	returnValue       	The value to return when the condition is @c false
 * @param[in]	r			The last result to set
 * @param[in]   ...			The message to display
 *
 * The following example demonstrates how to use the SysTryReturn macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *
 *	   SysTryReturn(NID, condition, false,  E_INVALID_ARG, "An unexpected error has occurred.");
 *
 *	   //...
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysTryReturn(NID, condition, returnValue, r, ...) \
	do \
	{ \
		if (unlikely(!(condition))) {	\
			SysLogException(NID, r, __VA_ARGS__); \
			return returnValue;	\
		} \
	} while (0);

/**
 * This macro allows display of exception log message with a tag and sets the last result, when the condition is @c false.
 * This is a shorthand macro for SysTryReturn(NID, condition, r, r, "[" # r "] " ...).
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	r			The last result to set
 * @param[in]   ...			The message to display
 *
 * The following example demonstrates how to use the SysTryReturnResult macro.
 *
 * @code
 * #define E_UNKNOWN_ERROR 1
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *
 *	   SysTryReturnResult(NID, condition, E_UNKNOWN_ERROR, "An unexpected error has occurred.");
 *
 *	   //...
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysTryReturnResult(NID, condition, r, ...) \
	do \
	{ \
		if (unlikely(!(condition))) {	\
			SysTryReturnResultInternal(NID, r, __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__); \
			return r;	\
		} \
	} while (0);

/**
 * This macro allows display of exception log message with a tag and sets the last result, when the condition is @c false.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	r			The last result to set
 * @param[in]   ...			The message to display
 *
 * The following example demonstrates how to use the SysTryReturnVoidResult macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *
 *	   SysTryReturnVoidResult(NID, condition,  E_INVALID_ARG, "An unexpected error has occurred.");
 *
 *	   //...
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysTryReturnVoidResult(NID, condition, r, ...)	\
	do \
	{ \
		if (unlikely(!(condition))) {	\
			SysLogException(NID, r, __VA_ARGS__); \
			return;	\
		} \
	} while (0);

/**
 * This macro allows display of exception log message with a tag, when the condition is @c false.
 * Executes statements, sets the last result and goes to label.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	expr			Expressions that are evaluated before going to CATCH label
 * @param[in]	r			The last result to set
 * @param[in]   ...			The message to display
 *
 * The following example demonstrates how to use the SysTryCatch macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *
 *	   SysTryCatch(NID, condition, r=E_INVALID_ARG, E_INVALID_ARG, "An unexpected error has occurred.");
 *
 *	   //...
 *	   CATCH:
 *	   		return false;
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysTryCatch(NID, condition, expr, r, ...) \
	do \
	{ \
		if (unlikely(!(condition))) {	\
			SysLogException(NID, r, __VA_ARGS__); \
			expr; \
			goto CATCH;	\
		} \
	} while (0);

/**
 * This macro allows display of exception log message with a tag, when the condition is @c false.
 * Executes statements, sets the last result and goes to label.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	expr			Expressions that are evaluated before going to catchLabel label
 * @param[in]	catchLabel		The label for goto operation
 * @param[in]	r			The last result to set
 * @param[in]   ...			The message to display
 *
 * The following example demonstrates how to use the SysTryCatchLabel macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *
 *	   SysTryCatchLabel(NID, condition, r=E_INVALID_ARG, LABEL, E_INVALID_ARG, "An unexpected error has occurred.");
 *
 *	   //...
 *	   LABEL:
 *	   		return false;
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysTryCatchLabel(NID, condition, expr, catchLabel, r, ...) \
	do \
	{ \
		if (unlikely(!(condition))) {	\
			SysLogException(NID, r, __VA_ARGS__); \
			expr; \
			goto catchLabel; \
		} \
	} while (0);


/**
 * This macro allows display of exception log message and the program will expire, when the condition is @c false.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	condition		The condition that is expected to be true
 *
 * The following example demonstrates how to use the SysAssert macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *
 *	   SysAssert(condition);
 *
 *	   //...
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysAssert(condition) \
	do \
	{ \
		if (unlikely(!(condition))) { \
			SysAssertInternal(__FILE__, __LINE__, __PRETTY_FUNCTION__);	\
		} \
	} while (0);

/**
 * This macro allows display of exception log message with a tag and the program will expire, when the condition is @c false.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]  	...			The message to display
 *
 * The following example demonstrates how to use the SysAssertf macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *
 *	   SysAssertf(condition, "");
 *
 *	   //...
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysAssertf(condition, ...) \
	do \
	{ \
		if (unlikely(!(condition))) { \
			SysAssertfInternal(# condition, __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__); \
		} \
	} while (0);


/**
 * This macro generates an error message during compile time, when the condition is @c false.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	condition		The condition that is expected to be true
 *
 * The following example demonstrates how to use the SysStaticAssert macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *
 *	   SysStaticAssert(condition);
 *
 *	   //...
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysStaticAssert(condition) switch (0) { \
case 0: \
case condition: \
  ; \
}


/**
 * This macro allows display of exception log messages.
 * This system log macro is for the platform modules.
 *
 * @since 2.0
 *
 * @param[in]	NID			The Tizen namespace
 * @param[in]	r			The last result to set
 *
 * The following example demonstrates how to use the SysPropagate macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   //...
 *
 *	   SysPropagate(NID, E_INVALID_ARG);
 *
 *	   //...
 *	}
 * @endcode
 * @hideinitializer
 */
#define SysPropagate(NID, r)        SysPropagateInternal(__PRETTY_FUNCTION__, __LINE__, NID, r)


/**
 * Defines the log ID.
 */
enum LogID
{
//Tizen Namespace ID ===============================================================
	NID_APP = 0,

	NID_BASE = 10,
	NID_BASE_COL = 11,
	NID_BASE_RT = 12,
	NID_BASE_UTIL = 13,

	NID_CNT = 20,

	NID_CTXT = 30,

	NID_GRP = 40,

	NID_IO = 50,

	NID_LCL = 60,

	NID_LOC = 70,
	NID_LOC_CTRL = 71,
	NID_LOC_SVC = 72,

	NID_MEDIA = 80,

	NID_MSG = 90,

	NID_NET = 100,
	NID_NET_BT = 101,
	NID_NET_HTTP = 102,
	NID_NET_NFC = 103,
	NID_NET_SOCK = 104,
	NID_NET_WIFI = 105,

	NID_SEC = 110,
	NID_SEC_CERT = 111,
	NID_SEC_CRYPTO = 112,

	NID_SCL = 120,

	NID_SYS = 130,

	NID_TEL = 140,

	NID_TEXT = 150,

	NID_UI = 160,
	NID_UI_ANIM = 161,
	NID_UI_CTRL = 162,
	NID_UI_EFFECT = 163,
	NID_UI_IME = 164,
	NID_UI_SCENES = 165,

	NID_UIX = 170,
	NID_UIX_SPEECH = 171,

	NID_WEB = 180,
	NID_WEB_CTRL = 181,
	NID_WEB_JSON = 182
};

/**
*
@} */

_OSP_EXPORT_ void SysLogInternal(unsigned long id, const char* pFunction, int lineNumber, const char* pFormat, ...);
_OSP_EXPORT_ void SysLogExceptionInternal(unsigned long id, result r, const char* pFunction, int lineNumber, const char* pFormat, ...);

_OSP_EXPORT_ void SysLogTagInternal(unsigned long id, const char* pTag, const char* pFunction, int lineNumber, const char* pFormat, ...);
_OSP_EXPORT_ void SysLogExceptionTagInternal(unsigned long id, const char* pTag, result r, const char* pFunction, int lineNumber, const char* pFormat, ...);

_OSP_EXPORT_ void SysAssertInternal(const char* pFileName, int lineNumber, const char* pFunction);
_OSP_EXPORT_ void SysAssertfInternal(const char* expr, const char* pFunction, int lineNumber, const char* pFormat, ...);

_OSP_EXPORT_ void SysPropagateInternal(const char* pFunction, int lineNumber, unsigned long nid, result r);

_OSP_EXPORT_ void SysTryReturnResultInternal(unsigned long id, result r, const char* pFunction, int lineNumber, const char* pFormat, ...);

#ifdef __cplusplus
}
#endif // __cplusplus


#endif // _FBASE_SYS_LOG_H_
