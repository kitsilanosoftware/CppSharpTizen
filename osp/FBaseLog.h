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
 * @file		FBaseLog.h
 * @brief		This is the header file for the diagnostic types.
 *
 * This header file defines the diagnostic types.
 *
 */
#ifndef _FBASE_LOG_H_
#define _FBASE_LOG_H_

#include <new>
#include <FOspConfig.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup GroupMacros Debugging Macros
 *
 * This page describes Tizen debugging macros.
 *
 * @since 2.0
 */

#if defined(_APP_LOG) || defined(_OSP_DEBUG_) || defined(_DEBUG)

// AppLog Macro

#define AppLog(...)                     AppLogInternal(__PRETTY_FUNCTION__, __LINE__, __VA_ARGS__)
#define AppLogDebug(...)                AppLogDebugInternal(__PRETTY_FUNCTION__, __LINE__, __VA_ARGS__)
#define AppLogException(...)            AppLogExceptionInternal(__PRETTY_FUNCTION__, __LINE__, __VA_ARGS__)

#define AppLogTag(tag, ...)                     AppLogTagInternal(tag, __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__)
#define AppLogDebugTag(tag, ...)                AppLogDebugTagInternal(tag, __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__)
#define AppLogExceptionTag(tag, ...)            AppLogExceptionTagInternal(tag, __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__)

#define AppLogIf(expression, ...) \
	if (expression) { \
		AppLogInternal(__PRETTY_FUNCTION__, __LINE__, __VA_ARGS__);	\
	} \
	else {;}

#define AppLogDebugIf(expression, ...) \
	if (expression) { \
		AppLogDebugInternal(__PRETTY_FUNCTION__, __LINE__, __VA_ARGS__); \
	} \
	else {;}

#define AppLogExceptionIf(expression, ...) \
	if (expression) { \
		AppLogExceptionInternal(__PRETTY_FUNCTION__, __LINE__, __VA_ARGS__); \
	} \
	else {;}

#define AppAssert(condition) \
	if (!(condition)) { \
		AppassertInternal(__PRETTY_FUNCTION__, __LINE__); \
	} \
	else {;}

#define AppAssertf(condition, ...)	\
	if (!(condition)) { \
		AppassertfInternal(# condition, __PRETTY_FUNCTION__, __LINE__, __VA_ARGS__); \
	} \
	else {;}
#else // defined(_APP_LOG)

/**
 * @addtogroup  GroupMacros
 *
 * @{
 */
/**
 * This macro allows display of arbitrary messages for future examination.
 *
 * @since 2.0
 *
 * @param[in]	...			The message to display
 *
 * The following example demonstrates how to use the AppLog macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   AppLog("Initialization successful.");
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLog(...)

/**
 * This macro must be added in your program if you want the debug messages to be displayed in the output.
 *
 * @since 2.0
 *
 * @param[in]	...			The message to display
 *
 *  @image html debugging_applog_output.png
 *
 * The following example demonstrates how to use the AppLogDebug macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   AppLogDebug("Invoked with value: %d", value);
 *
 *	   //...
 *
 *	   AppLogDebug("Exit.");
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogDebug(...)

/**
 * This macro must be added in your program if you want the exception messages to be displayed in the output.
 *
 * @since 2.0
 *
 * @param[in]	...			The message to display
 *
 * The following example demonstrates how to use the AppLogException macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   AppLogDebug("Invoked with value: %d", value);
 *	   //...
 *	   if (something_wrong)   // The Try family macros can be used instead.
 *	   {
 *	      AppLogException("An unexpected error occurred.");
 *
 *	      return false;
 *	   }
 *
 *	   AppLog("Initialization successful.");
 *	   AppLogDebug("Exit.");
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogException(...)

/**
 * This macro is used to check logical errors in a program.
 * If the assertion fails, the current process is killed.
 *
 * @since 2.0
 *
 * @param[in]	condition  The condition that is expected to be true
 * @hideinitializer
 */
#define AppAssert(condition)

/**
 * This macro is used to check logical errors in a program.
 * If the assertion fails, a message is printed on the console and the current process is killed.
 *
 * @since 2.0
 *
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	...			The message to print, if the assertion fails
 *
 * @image html debugging_appassert.png
 *
 * The following example demonstrates how to use the Assert macro.
 *
 * @code
 *	result
 *	MyClass::DoSomething(void)
 *	{
 *	   result r = E_SUCCESS;
 *	   r = mutex.Acquire();
 *	   // Do something
 *	   r = mutex.Release();
 *
 *	   // If false, console prints "Mutex Release Failed."
 *	   // and the process is killed.
 *	   AppAssertf(r == E_SUCCESS, "Mutex Release Failed.");
 *
 *	   return r;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppAssertf(condition, ...)

/**
 * This macro is added in a program to display a message when an expression is @c true.
 *
 * @since 2.0
 *
 * @param[in]	expression		The expression to evaluate
 * @param[in]	...			The message to display
 *
 * The following example demonstrates how to use the AppLogIf macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   AppLogIf(value !=0, "Invoked with value: %d", value);
 *	   //...
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogIf(expression, ...)

/**
 * This macro is added in a program to display a debug message when an expression is @c true.
 *
 * @since 2.0
 *
 * @param[in]	expression		The expression to evaluate
 * @param[in]	...			The message to display
 *
 * The following example demonstrates how to use the AppLogDebugIf macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   AppLogDebugIf(value !=0, "Invoked with value: %d", value);
 *	   //...
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogDebugIf(expression, ...)

/**
 * This macro is added in a program to display an exception message when an expression is @c true.
 *
 * @since 2.0
 *
 * @param[in]	expression		The expression to evaluate
 * @param[in]	...			The message to display
 *
 * The following example demonstrates how to use the AppLogExceptionIf macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   int status;
 *
 *	   AppLogExceptionIf(status != 0, "status : %d.", status);
 *	   //...
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogExceptionIf(expression, ...)

/**
 * This macro is added in a program to display an info message with a tag.
 *
 * @since 2.0
 *
 * @param[in]	tag			Used to identify the source of a log message
 * @param[in]	...			The message to display
 *
 * The following example demonstrates how to use the AppLogTag macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   int status;
 *
 *	   AppLogTag("MyTag", "Initialization successful.");
 *	   //...
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogTag(tag, ...)

/**
 * This macro is added in a program to display a debug message with a tag.
 *
 * @since 2.0
 *
 * @param[in]	tag			Used to identify the source of a log message
 * @param[in]	...			The message to display
 *
 * The following example demonstrates how to use the AppLogDebugTag macro.
 *
  * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   AppLogDebugTag("MyTag", "Invoked with value: %d", value);
 *
 *	   //...
 *
 *	   AppLogDebugTag("MyTag", "Exit.");
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogDebugTag(tag, ...)

/**
 * This macro is added in a program to display an exception message with a tag.
 *
 * @since 2.0
 *
 * @param[in]	tag			Used to identify the source of a log message
 * @param[in]	...			The message to display
 *
 * The following example demonstrates how to use the AppLogExceptionTag macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   AppLogDebug("Invoked with value: %d", value);
 *	   //...
 *	   if (something_wrong)   // The Try family macros can be used instead.
 *	   {
 *	      AppLogExceptionTag("MyTag", "An unexpected error occurred.");
 *
 *	      return false;
 *	   }
 *
 *	   AppLog("Initialization successful.");
 *	   AppLogDebug("Exit.");
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogExceptionTag(tag, ...)
/** @} */
#endif // defined(_APP_LOG)

// Try Macros
/**
 * @addtogroup  GroupMacros
 *
 * @{
 */
/**
 * If the condition is @c false, it prints a message, evaluates a cleanup expression,
 * and goes to <tt>CATCH</tt>.
 *
 * @since 2.0
 *
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	expr			Expressions that are evaluated before going to CATCH label
 * @param[in]	...			The message to display
 *
 * The following example demonstrates how to use the Try macro.
 *
 * @code
 *	const  A*
 *	MyClass::DoSomething(const wchar_t* pValue)
 *	{
 *	   result r = E_SUCCESS;
 *
 *	   // Do something...
 *
 *	   // If pValue is null, print "pValue == null" to the
 *	   // console and return E_INVALID_ARG.
 *	   TryCatch(pValue != null, r = E_INVALID_ARG, "pValue == null");
 *
 *	   SetLastResult(E_SUCCESS);
 *
 *	   return _pValue;
 *
 *	   CATCH:
 *	      SetLastResult(r);
 *
 *	      return null;
 *	}
 * @endcode
 * @hideinitializer
 */
#define TryCatch(condition, expr, ...) \
	if (!(condition)) { \
		AppLogException(__VA_ARGS__); \
		expr; \
		goto CATCH;	\
	} \
	else {;}

/**
 * If the condition is @c false, it prints a message, sets the last result, evaluates a cleanup expression
 * and goes to <tt>CATCH</tt>.
 *
 * @since 2.0
 *
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	expr			Expressions that are evaluated before going to CATCH label
 * @param[in]	r			The last result to set
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryCatchResult(condition, expr, r, ...) \
	if (!(condition)) { \
		SetLastResult(r); \
		AppLogException(__VA_ARGS__); \
		expr; \
		goto CATCH;	\
	} \
	else {;}

/**
 * If the condition is @c false, the message is printed and a value is returned.
 *
 * @since 2.0
 *
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	returnValue		The value to return when the condition is @c false
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryReturn(condition, returnValue, ...)	\
	if (!(condition)) { \
		AppLogException(__VA_ARGS__); \
		return returnValue;	\
	} \
	else {;}

/**
 * If the condition is @c false, the message is printed, sets the last result and a value is returned.
 *
 * @since 2.0
 *
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	returnValue		The value to return when the condition is @c false
 * @param[in]	r			The last result to set
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryReturnResult(condition, returnValue, r, ...)	\
	if (!(condition)) { \
		SetLastResult(r); \
		AppLogException(__VA_ARGS__); \
		return returnValue;	\
	} \
	else {;}

/**
 * If the condition is @c false, the message is printed, sets the last result and no value is returned.
 *
 * @since 2.0
 *
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	r			The last result to set
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryReturnVoidResult(condition, r, ...)	\
	if (!(condition)) { \
		SetLastResult(r); \
		AppLogException(__VA_ARGS__); \
		return;	\
	} \
	else {;}

/**
 * If the condition is @c false, the message is printed and no value is returned.
 *
 * @since 2.0
 *
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryReturnVoid(condition, ...) \
	if (!(condition)) { \
		AppLogException(__VA_ARGS__); \
		return;	\
	} \
	else {;}

/**
 * If the condition is @c false, the message is printed.
 *
 * @since 2.0
 *
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryLog(condition, ...)	\
	if (!(condition)) { \
		AppLog(__VA_ARGS__); \
	} \
	else {;}


// TryTag Macros

/**
 * If the condition is @c false, it prints a message with a tag, evaluates a cleanup expression
 * and goes to <tt>CATCH</tt>.
 *
 * @since 2.0
 *
 * @param[in]	tag			Used to identify the source of a log message
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	expr			Expressions that are evaluated before going to CATCH label
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryCatchTag(tag, condition, expr, ...) \
	if (!(condition)) { \
		AppLogExceptionTag(tag, __VA_ARGS__); \
		expr; \
		goto CATCH;	\
	} \
	else {;}

/**
 * If the condition is @c false, it prints a message with a tag, sets the last result, evaluates a cleanup expression,
 * and goes to <tt>CATCH</tt>.
 *
 * @since 2.0
 *
 * @param[in]	tag			Used to identify the source of a log message
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	expr			Expressions that are evaluated before going to CATCH label
 * @param[in]	r			The last result to set
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryCatchResultTag(tag, condition, expr, r, ...) \
	if (!(condition)) { \
		SetLastResult(r); \
		AppLogExceptionTag(tag, __VA_ARGS__); \
		expr; \
		goto CATCH;	\
	} \
	else {;}

/**
 * If the condition is @c false, the message is printed with a tag and a value is returned.
 *
 * @since 2.0
 *
 * @param[in]	tag			Used to identify the source of a log message
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	returnValue		The value to return when the condition is @c false
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryReturnTag(tag, condition, returnValue, ...)	\
	if (!(condition)) { \
		AppLogExceptionTag(tag, __VA_ARGS__); \
		return returnValue;	\
	} \
	else {;}

/**
 * If the condition is @c false, the message is printed with a tag, sets the last result and a value is returned.
 *
 * @since 2.0
 *
 * @param[in]	tag			Used to identify the source of a log message
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	returnValue		The value to return when the condition is @c false
 * @param[in]	r			The last result to set
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryReturnResultTag(tag, condition, returnValue, r, ...)	\
	if (!(condition)) { \
		SetLastResult(r); \
		AppLogExceptionTag(tag, __VA_ARGS__); \
		return returnValue;	\
	} \
	else {;}

/**
 * If the condition is @c false, the message is printed with a tag, sets the last result and no value is returned.
 *
 * @since 2.0
 *
 * @param[in]	tag			Used to identify the source of a log message
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	r			The last result to set
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryReturnVoidResultTag(tag, condition, r, ...)	\
	if (!(condition)) { \
		SetLastResult(r); \
		AppLogExceptionTag(tag, __VA_ARGS__); \
		return;	\
	} \
	else {;}

/**
 * If the condition is @c false, the message is printed with a tag and no value is returned.
 *
 * @since 2.0
 *
 * @param[in]	tag			Used to identify the source of a log message
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryReturnVoidTag(tag, condition, ...) \
	if (!(condition)) { \
		AppLogExceptionTag(tag, __VA_ARGS__); \
		return;	\
	} \
	else {;}

/**
 * If the condition is @c false, the message is printed with a tag.
 *
 * @since 2.0
 *
 * @param[in]	tag			Used to identify the source of a log message
 * @param[in]	condition		The condition that is expected to be true
 * @param[in]	...			The message to display
 * @hideinitializer
 */
#define TryLogTag(tag, condition, ...)	\
	if (!(condition)) { \
		AppLogTag(tag, __VA_ARGS__); \
	} \
	else {;}

/** @} */

_OSP_EXPORT_ void AppLogInternal(const char* pFunction, int lineNumber, const char* pFormat, ...);
_OSP_EXPORT_ void AppLogDebugInternal(const char* pFunction, int lineNumber, const char* pFormat, ...);
_OSP_EXPORT_ void AppLogExceptionInternal(const char* pFunction, int lineNumber, const char* pFormat, ...);
_OSP_EXPORT_ void AppassertInternal(const char* pFunction, int lineNumber);
_OSP_EXPORT_ void AppassertfInternal(const char* expr, const char* pFunction, int lineNumber, const char* pFormat, ...);

_OSP_EXPORT_ void AppLogTagInternal(const char* pTag, const char* pFunction, int lineNumber, const char* pFormat, ...);
_OSP_EXPORT_ void AppLogDebugTagInternal(const char* pTag, const char* pFunction, int lineNumber, const char* pFormat, ...);
_OSP_EXPORT_ void AppLogExceptionTagInternal(const char* pTag, const char* pFunction, int lineNumber, const char* pFormat, ...);


#ifdef __cplusplus
}
#endif

#endif // _FBASE_LOG_H_
