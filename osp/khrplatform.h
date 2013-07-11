/* $Change: 1028567 $ */
#ifndef __khrplatform_h_
#define __khrplatform_h_

/*
** Copyright (c) 2008-2009 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

/* Khronos platform-specific types and definitions.
 *
 * $Revision: #1 $ on $Date: 2011/08/12 $
 *
 * Adopters may modify this file to suit their platform. Adopters are
 * encouraged to submit platform specific modifications to the Khronos
 * group so that they can be included in future versions of this file.
 * Please submit changes by sending them to the public Khronos Bugzilla
 * (http://khronos.org/bugzilla) by filing a bug against product
 * "Khronos (general)" component "Registry".
 *
 * A predefined template which fills in some of the bug fields can be
 * reached using http://tinyurl.com/khrplatform-h-bugreport, but you
 * must create a Bugzilla login first.
 *
 *
 * See the Implementer's Guidelines for information about where this file
 * must be located on your system and for more details of its use:
 *    http://www.khronos.org/registry/implementers_guide.pdf
 *
 * This file must be included as
 *        #include <KHR/khrplatform.h>
 * by Khronos client API header files that use its types and defines.
 *
 * The types in khrplatform.h must only be used to define API-specific types.
 *
 * Types defined in khrplatform.h:
 *    khronos_int8_t              signed   8  bit
 *    khronos_uint8_t             unsigned 8  bit
 *    khronos_int16_t             signed   16 bit
 *    khronos_uint16_t            unsigned 16 bit
 *    khronos_int32_t             signed   32 bit
 *    khronos_uint32_t            unsigned 32 bit
 *    khronos_int64_t             signed   64 bit
 *    khronos_uint64_t            unsigned 64 bit
 *    khronos_intptr_t            signed   same number of bits as a pointer
 *    khronos_uintptr_t           unsigned same number of bits as a pointer
 *    khronos_ssize_t             signed   size
 *    khronos_usize_t             unsigned size
 *    khronos_float_t             signed   32 bit floating point
 *    khronos_time_ns_t           unsigned 64 bit time in nanoseconds
 *    khronos_utime_nanoseconds_t unsigned time interval or absolute time in
 *                                         nanoseconds
 *    khronos_stime_nanoseconds_t signed time interval in nanoseconds
 *    khronos_boolean_enum_t      enumerated boolean type. This must
 *      only be used as a base type when a client API's boolean type is
 *      an enum. Client APIs which use an integer or other type for
 *      booleans cannot use this as the base type for their boolean.
 *
 * Tokens defined in khrplatform.h:
 *
 *    KHRONOS_FALSE, KHRONOS_TRUE Enumerated boolean false/true values.
 *
 *    KHRONOS_SUPPORT_INT64 is 1 if 64 bit integers are supported; otherwise 0.
 *    KHRONOS_SUPPORT_FLOAT is 1 if floats are supported; otherwise 0.
 *
 * Calling convention macros defined in this file:
 *    KHRONOS_APICALL
 *    KHRONOS_APIENTRY
 *    KHRONOS_APIATTRIBUTES
 *
 * These may be used in function prototypes as:
 *
 *      KHRONOS_APICALL void KHRONOS_APIENTRY funcname(
 *                                  int arg1,
 *                                  int arg2) KHRONOS_APIATTRIBUTES;
 */

/**
 * @addtogroup opengles
 *
 * @{
 */

/*-------------------------------------------------------------------------
 * Definition of KHRONOS_APICALL
 *-------------------------------------------------------------------------
 * This precedes the return type of the function in the function prototype.
 */
#if defined(_WIN32)
#ifdef __KHRONOS_EXPORTS
#define KHRONOS_APICALL __declspec(dllexport)
#else
#define KHRONOS_APICALL __declspec(dllimport)
#endif
//#define KHRONOS_APICALL extern
#elif defined(__SYMBIAN32__)
#define KHRONOS_APICALL IMPORT_C
#else
#define KHRONOS_APICALL extern
#endif

/*-------------------------------------------------------------------------
 * Definition of KHRONOS_APIENTRY
 *-------------------------------------------------------------------------
 * This follows the return type of the function  and precedes the function
 * name in the function prototype.
 */
#if defined(_WIN32) && !defined(_WIN32_WCE) && !defined(__SCITECH_SNAP__)
/* Win32 but not WinCE */
#define KHRONOS_APIENTRY __stdcall
#else
#define KHRONOS_APIENTRY
#endif

/*-------------------------------------------------------------------------
 * Definition of KHRONOS_APIATTRIBUTES
 *-------------------------------------------------------------------------
 * This follows the closing parenthesis of the function prototype arguments.
 */
#if defined(__ARMCC_2__)
#define KHRONOS_APIATTRIBUTES __softfp
#else
#define KHRONOS_APIATTRIBUTES
#endif

/*-------------------------------------------------------------------------
 * basic type definitions
 *-----------------------------------------------------------------------*/
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__GNUC__) || defined(__SCO__) || defined(__USLC__)


//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// Using <stdint.h>
// @since 2.0
//
#include <stdint.h>
typedef int32_t khronos_int32_t;
typedef uint32_t khronos_uint32_t;
typedef int64_t khronos_int64_t;
typedef uint64_t khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(__VMS) || defined(__sgi)

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// Using <inttypes.h>
// @since 2.0
//
#include <inttypes.h>
typedef int32_t khronos_int32_t;
typedef uint32_t khronos_uint32_t;
typedef int64_t khronos_int64_t;
typedef uint64_t khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(_WIN32) && !defined(__SCITECH_SNAP__)

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// Win32
// @since 2.0
//
typedef __int32 khronos_int32_t;
typedef unsigned __int32 khronos_uint32_t;
typedef __int64 khronos_int64_t;
typedef unsigned __int64 khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(__sun__) || defined(__digital__)

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// Sun or Digital
// @since 2.0
//
typedef int khronos_int32_t;
typedef unsigned int khronos_uint32_t;
#if defined(__arch64__) || defined(_LP64)
typedef long int khronos_int64_t;
typedef unsigned long int khronos_uint64_t;
#else
typedef long long int khronos_int64_t;
typedef unsigned long long int khronos_uint64_t;
#endif /* __arch64__ */
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif 0

/*
 * Hypothetical platform with no float or int64 support
 */
typedef int khronos_int32_t;
typedef unsigned int khronos_uint32_t;
#define KHRONOS_SUPPORT_INT64   0
#define KHRONOS_SUPPORT_FLOAT   0

#else

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// Generic fallback
// @since 2.0
//
#include <stdint.h>
typedef int32_t khronos_int32_t;
typedef uint32_t khronos_uint32_t;
typedef int64_t khronos_int64_t;
typedef uint64_t khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#endif


/*
 * Types that are (so far) the same on all platforms
 */
//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef signed char khronos_int8_t
// \brief A type definition for khronos_int8_t.
// @since 2.0
//
typedef signed char khronos_int8_t;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef unsigned char khronos_uint8_t
// \brief A type definition for khronos_uint8_t.
// @since 2.0
//
typedef unsigned char khronos_uint8_t;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef signed   short int     khronos_int16_t
// \brief A type definition for khronos_int16_t.
// @since 2.0
//
typedef signed short int khronos_int16_t;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef unsigned short int     khronos_uint16_t
// \brief A type definition for khronos_uint16_t.
// @since 2.0
//
typedef unsigned short int khronos_uint16_t;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef signed   long  int     khronos_intptr_t
// \brief A type definition for khronos_intptr_t.
// @since 2.0
//
typedef signed long int khronos_intptr_t;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef unsigned long  int     khronos_uintptr_t
// \brief A type definition for khronos_uintptr_t.
// @since 2.0
//
typedef unsigned long int khronos_uintptr_t;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef signed   long  int     khronos_ssize_t
// \brief A type definition for khronos_ssize_t.
// @since 2.0
//
typedef signed long int khronos_ssize_t;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef unsigned long  int     khronos_usize_t
// \brief A type definition for khronos_usize_t.
// @since 2.0
//
typedef unsigned long int khronos_usize_t;

#if KHRONOS_SUPPORT_FLOAT
//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// Float type
// @since 2.0
//
typedef          float khronos_float_t;
#endif

#if KHRONOS_SUPPORT_INT64
//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// Time types
//
// These types can be used to represent a time interval in nanoseconds or
// an absolute Unadjusted System Time.  The Unadjusted System Time is the number
// of nanoseconds since some arbitrary system event (for example, since the last
// time the system booted). It is an unsigned 64-bit value that wraps back to 0 after every 584 years.
// The time intervals can be either signed or unsigned.
// @since 2.0
//
typedef khronos_uint64_t khronos_utime_nanoseconds_t;
typedef khronos_int64_t khronos_stime_nanoseconds_t;
#endif

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// Dummy value used to pad enum types to 32 bits.
// @since 2.0
//
#ifndef KHRONOS_MAX_ENUM
#define KHRONOS_MAX_ENUM 0x7FFFFFFF
#endif

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// Enumerated boolean type
//
// Values other than zero must be considered to be true. Therefore
// comparisons must not be made against KHRONOS_TRUE.
// @since 2.0
//
typedef enum
{
	KHRONOS_FALSE = 0,
	KHRONOS_TRUE = 1,
	KHRONOS_BOOLEAN_ENUM_FORCE_SIZE = KHRONOS_MAX_ENUM
} khronos_boolean_enum_t;



/*-------------------------------------------------------------------------
 * Data type definitions for GL APIs
 *-----------------------------------------------------------------------*/

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef void GLvoid
// \brief A type definition for GLvoid.
// @since 2.0
//
typedef void GLvoid;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef unsigned int GLenum
// \brief A type definition for GLenum.
// @since 2.0
//
typedef unsigned int GLenum;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef unsigned char GLboolean
// \brief A type definition for GLboolean.
// @since 2.0
//
typedef unsigned char GLboolean;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef unsigned int GLbitfield
// \brief A type definition for GLbitfield.
// @since 2.0
//
typedef unsigned int GLbitfield;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef signed char GLbyte
// \brief A type definition for GLbyte.
// @since 2.0
//
typedef khronos_int8_t GLbyte;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef short GLshort
// \brief A type definition for GLshort.
// @since 2.0
//
typedef short GLshort;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef int GLint
// \brief A type definition for GLint.
// @since 2.0
//
typedef int GLint;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef int GLsizei
// \brief A type definition for GLsizei.
// @since 2.0
//
typedef int GLsizei;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef khronos_uint8_t GLubyte
// \brief A type definition for GLubyte.
// @since 2.0
//
typedef khronos_uint8_t GLubyte;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef unsigned short GLushort
// \brief A type definition for GLushort.
// @since 2.0
//
typedef unsigned short GLushort;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var unsigned int       GLuint
// \brief A type definition for GLuint.
// @since 2.0
//
typedef unsigned int GLuint;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef khronos_float_t GLfloat
// \brief A type definition for GLfloat.
// @since 2.0
//
typedef khronos_float_t GLfloat;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef khronos_float_t GLclampf
// \brief A type definition for GLclampf.
// @since 2.0
//
typedef khronos_float_t GLclampf;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef khronos_int32_t GLfixed
// \brief A type definition for GLfixed.
// @since 2.0
//
typedef khronos_int32_t GLfixed;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef khronos_int32_t GLclampx
// \brief A type definition for GLclampx.
// @since 2.0
//
typedef khronos_int32_t GLclampx;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef khronos_intptr_t GLintptr
// \brief A type definition for GLintptr.
// @since 2.0
//
typedef khronos_intptr_t GLintptr;

//
// This method is for internal use only.
// Using this method can cause behavioral, security-related, and consistency-related issues in the application.
//
// \var typedef khronos_ssize_t GLsizeiptr
// \brief A type definition for GLsizeiptr.
// @since 2.0
//
typedef khronos_ssize_t GLsizeiptr;

/**
 * @}
 */

#endif /* __khrplatform_h_ */
