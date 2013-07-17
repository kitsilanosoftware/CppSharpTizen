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



#ifndef _FOSP_COMPAT_H_
#define _FOSP_COMPAT_H_

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>
#include <FOspConfig.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*funread)(void* _cookie, char* _buf, int _n);
typedef int (*funwrite)(void* _cookie, const char* _buf, int _n);
#ifdef __LARGE64_FILES
typedef _fpos64_t (*funseek)(void* _cookie, _fpos64_t _off, int _whence);
#else
typedef fpos_t (*funseek)(void* _cookie, fpos_t _off, int _whence);
#endif
typedef int (*funclose)(void* _cookie);

// String functions NewlibCompatString.cpp
_OSP_EXPORT_ char* strlwr(char* pcStr);
_OSP_EXPORT_ char* strupr(char* pcStr);
_OSP_EXPORT_ size_t wcslcat(wchar_t * wcDst, const wchar_t * wcSrc, size_t siz);
_OSP_EXPORT_ size_t wcslcpy( wchar_t* wcDst,	const wchar_t* wcSrc, size_t siz);

// String functions NewlibCompatStdlib.cpp
_OSP_EXPORT_ float atoff(const char* pstr);
_OSP_EXPORT_ char* ecvtf(float fval, int ndigit, int* decpt, int* sign);
_OSP_EXPORT_ char* ecvtbuf(double invalue, int ndigit, int* decpt, int* sign, char* ecvt_buf);
_OSP_EXPORT_ char* fcvtf( float fval, int ndigit, int* decpt, int* sign);
_OSP_EXPORT_ char* fcvtbuf(double invalue, int ndigit, int* decpt, int* sign, char* fcvt_buf);
_OSP_EXPORT_ char* gcvtf( float fval, int ndigit, char* buf);
_OSP_EXPORT_ void* reallocf (void* pstr, unsigned int size);

// String functions NewlibCompatStdio.cpp
_OSP_EXPORT_ char* asnprintf(char* buf, size_t* lenp, const char* format, ...);
_OSP_EXPORT_ char* vasnprintf(char *buf, size_t *lenp, const char *format, va_list ap);
_OSP_EXPORT_ int asiprintf(char **strp,const char *fmt0, ...);
_OSP_EXPORT_ char * asniprintf(char *buf, size_t *lenp, const char *fmt0, ... );
_OSP_EXPORT_ int iprintf(const char *fmt0, ...);
_OSP_EXPORT_ int fiprintf(FILE * fp, const char *fmt0, ...);
_OSP_EXPORT_ int siprintf(char *str, const char *fmt0, ...);
_OSP_EXPORT_ int sniprintf(char *str, size_t size, const char *fmt0, ...);
_OSP_EXPORT_ int vasiprintf(char **strp, const char *fmt0, va_list ap);
_OSP_EXPORT_ char* vasniprintf(char *buf, size_t *lenp, const char *fmt0, va_list ap);
_OSP_EXPORT_ int vfiprintf(FILE * fp, const char *fmt0, va_list ap);
_OSP_EXPORT_ int viprintf(const char *fmt0, va_list ap);
_OSP_EXPORT_ int vsiprintf(char *str, const char *fmt0, va_list ap);
_OSP_EXPORT_ int vsniprintf(char *str, size_t size, const char *fmt0, va_list ap);
_OSP_EXPORT_ int diprintf(int fd, const char *fmt0, ...);
_OSP_EXPORT_ int siscanf( const char* str, const char* fmt0, ...);
_OSP_EXPORT_ int vdiprintf(int fd, const char *fmt0, va_list ap);
_OSP_EXPORT_ int vfiscanf(FILE *fp, const char *fmt0, va_list ap);
_OSP_EXPORT_ int vsiscanf(const char *str, const char *fmt0, va_list ap);
_OSP_EXPORT_ int fiscanf(FILE *fp, const char *fmt0, ...);
_OSP_EXPORT_ FILE* funopen(const void* cookie, funread readfn, funwrite writefn, funseek seekfn, funclose closefn);
_OSP_EXPORT_ FILE*  fropen(const void* cookie , funread readfn);
_OSP_EXPORT_ FILE*  fwopen(const void* cookie,funwrite writefn);

// Miscellaneous functions NewlibCompatMisc.cpp
#define unctrllen(ch)		__unctrllen[(ch) & 0xff]
_OSP_EXPORT_ extern const char __unctrllen[256];

#ifdef __cplusplus
}; //extern "C"
#endif

typedef wchar_t mchar;

namespace Tizen {
// Add constant which has compatible issue on Tizen

namespace Ads {
// Add constant which has compatible issue on Tizen::Ads

}; // Tizen::Ads

namespace App
{
// Add constant which has compatible issue on Tizen::App

}; // Tizen::App

namespace Base
{
// Add constant which has compatible issue on Tizen::Base

template<class Type> class Buffer;

typedef Buffer <mchar> McharBuffer;

}; // Tizen::Base

namespace Commerce
{
// Add constant which has compatible issue on Tizen::Commerce

}; // Tizen::Commerce

namespace Content
{
// Add constant which has compatible issue on Tizen::Content

}; // Tizen::Content

namespace Graphics
{
// Add constant which has compatible issue on Tizen::Graphics

}; // Tizen::Graphics

namespace Io
{
// Add constant which has compatible issue on Tizen::Io

}; // Tizen::Io

namespace Locales
{
// Add constant which has compatible issue on Tizen::Locales

}; // Tizen::Locales

namespace Locations
{
// Add constant which has compatible issue on Tizen::Locations

}; // Tizen::Locations

namespace Media
{
// Add constant which has compatible issue on Tizen::Media

}; // Tizen::Media

namespace Messaging
{
// Add constant which has compatible issue on Tizen::Messaging

}; // Tizen::Messaging

namespace Net
{
// Add constant which has compatible issue on Tizen::Net

namespace Sockets
{

static const int NET_SOCKET_INADDR_ANY = 0;

}; // Tizen::Net::Sockets

namespace Wifi
{

static const int WIFI_DIRECT_MAX_CONNECTED_CLIENTS = 8;
static const int WIFI_DIRECT_MAX_GROUP_OWNER_INTENT = 15;

}; // Tizen::Net::Wifi

}; // Tizen::Net

namespace Security
{
// Add constant which has compatible issue on Tizen::Security

}; // Tizen::Security

namespace Social
{
// Add constant which has compatible issue on Tizen::Social

}; // Tizen::Social

namespace System
{
// Add constant which has compatible issue on Tizen::System

}; // Tizen::System

namespace Telephony
{
// Add constant which has compatible issue on Tizen::Telephony

}; // Tizen::Telephony

namespace Test
{
// Add constant which has compatible issue on Tizen::Test

}; // Tizen::Test

namespace Text
{
// Add constant which has compatible issue on Tizen::Text

}; // Tizen::Text

namespace Ui
{
// Add constant which has compatible issue on Tizen::Ui

namespace Animations
{
// Add constant which has compatible issue on Tizen::Ui::Animations
}

namespace Controls
{
#define MIN_FLASH_VOLUME		0
#define MAX_FLASH_VOLUME		100
#define DEFAULT_FLASH_VOLUME	50
}

}; // Tizen::Ui

namespace Uix
{
// Add constant which has compatible issue on Tizen::Uix

}; // Tizen::Uix

namespace Web
{
// Add constant which has compatible issue on Tizen::Web

}; // Tizen::Web
}; // Tizen

#endif // _FOSP_COMPAT_H_
