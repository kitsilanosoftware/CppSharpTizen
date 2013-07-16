//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
 * @file		FNetHttpHttpTypes.h
 * @brief		This is the header file for defining the primitive types for the HTTP operations.
 *
 * This header file contains the definition of the primitive types for the HTTP operations.
 */

#ifndef _FNET_HTTP_HTTP_TYPES_H_
#define _FNET_HTTP_HTTP_TYPES_H_

#include "FBaseObject.h"
#include "FBaseColIComparer.h"
#include "FBaseString.h"
#include "FBaseErrorDefine.h"
#include "FBaseColIHashCodeProvider.h"

namespace Tizen { namespace Net { namespace Http
{

/**
 * @enum    NetHttpMethod
 *
 * Defines the HTTP method types. For the detailed description of each method, refer to HttpRequest::SetMethod().
 *
 * @since 2.0
 */
enum NetHttpMethod
{
	NET_HTTP_METHOD_GET = 0x40,         /**< The HTTP GET Method */
	NET_HTTP_METHOD_OPTIONS = 0x41,     /**< The HTTP OPTIONS Method */
	NET_HTTP_METHOD_HEAD = 0x42,        /**< The HTTP HEAD Method */
	NET_HTTP_METHOD_DELETE = 0x43,      /**< The HTTP DELETE Method */
	NET_HTTP_METHOD_TRACE = 0x44,       /**< The HTTP TRACE Method */
	NET_HTTP_METHOD_POST = 0x60,        /**< The HTTP POST Method */
	NET_HTTP_METHOD_PUT = 0x61,         /**< The HTTP PUT Method */
	NET_HTTP_METHOD_CONNECT = 0x70,     /**< The HTTP CONNECT Method */
};

/**
 * @enum	NetHttpSessionMode
 *
 * Defines the HTTP session mode.
 *
 * @since 2.0
 */
enum NetHttpSessionMode
{
	NET_HTTP_SESSION_MODE_NORMAL,           /**< The Normal Mode */
	NET_HTTP_SESSION_MODE_PIPELINING,       /**< The Pipelining mode */
	NET_HTTP_SESSION_MODE_MULTIPLE_HOST     /**< The Multiple host mode */
};

/**
 * @enum	HttpVersion
 *
 * Defines the HTTP version.
 *
 * @since 2.0
 */
enum HttpVersion
{
	HTTP_VERSION_1_0,   /**< %Http version 1.0 */
	HTTP_VERSION_1_1    /**< %Http version 1.1 */
};

/**
 * @if OSPDEPREC
 * @enum    NetHttpStatusCode
 *
 * Defines the HTTP status code.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated This enum is deprecated. Instead of using this enum, it is recommended to use the HTTP_STATUS_XXX constants.
 * @since 2.0
 * @endif
 */
enum NetHttpStatusCode
{
	NET_HTTP_STATUS_UNDEFINED = 0,                                          /**< @if OSPDEPREC The undefined status @endif */
	NET_HTTP_STATUS_CONTINUE = 100,                                         /**< @if OSPDEPREC The status code: 100 Continue @endif */
	NET_HTTP_STATUS_SWITCHING_PROTOCOLS = 101,                              /**< @if OSPDEPREC The status code: 101 Switching Protocols @endif */
	NET_HTTP_STATUS_OK = 200,                                               /**< @if OSPDEPREC The status code: 200 OK @endif */
	NET_HTTP_STATUS_CREATED = 201,                                          /**< @if OSPDEPREC The status code: 201 Created @endif */
	NET_HTTP_STATUS_ACCEPTED = 202,                                         /**< @if OSPDEPREC The status code: 202 Accepted @endif */
	NET_HTTP_STATUS_NON_AUTHORITATIVE_INFORMATION = 203,                    /**< @if OSPDEPREC The status code: 203 Non-Authoritative Information @endif */
	NET_HTTP_STATUS_NO_CONTENT = 204,                                       /**< @if OSPDEPREC The status code: 204 No %Content @endif */
	NET_HTTP_STATUS_RESET_CONTENT = 205,                                    /**< @if OSPDEPREC The status code: 205 Reset %Content @endif */
	NET_HTTP_STATUS_PARTIAL_CONTENT = 206,                                  /**< @if OSPDEPREC The status code: 206 Partial %Content @endif */

	NET_HTTP_STATUS_MULTIPLE_CHOICE = 300,                                  /**< @if OSPDEPREC The status code: 300 Multiple Choices @endif */
	NET_HTTP_STATUS_MOVED_PERMANENTLY = 301,                                /**< @if OSPDEPREC The status code: 301 Moved Permanently @endif */
	NET_HTTP_STATUS_MOVED_TEMPORARILY = 302,                                /**< @if OSPDEPREC The status code: 302 Found @endif */
	NET_HTTP_STATUS_SEE_OTHER = 303,                                        /**< @if OSPDEPREC The status code: 303 See Other @endif */
	NET_HTTP_STATUS_NOT_MODIFIED = 304,                                     /**< @if OSPDEPREC The status code: 304 Not Modified @endif */
	NET_HTTP_STATUS_USE_PROXY = 305,                                        /**< @if OSPDEPREC The status code: 305 Use Proxy @endif */

	NET_HTTP_STATUS_BAD_REQUEST = 400,                                      /**< @if OSPDEPREC The status code: 400 Bad Request @endif */
	NET_HTTP_STATUS_UNAUTHORIZED = 401,                                     /**< @if OSPDEPREC The status code: 401 Unauthorized @endif */
	NET_HTTP_STATUS_PAYMENT_REQUIRED = 402,                                 /**< @if OSPDEPREC The status code: 402 Payment Required @endif */
	NET_HTTP_STATUS_FORBIDDEN = 403,                                        /**< @if OSPDEPREC The status code: 403 Forbidden @endif */
	NET_HTTP_STATUS_NOT_FOUND = 404,                                        /**<@if OSPDEPREC  The status code: 404 Not Found @endif */
	NET_HTTP_STATUS_METHOD_NOT_ALLOWED = 405,                               /**< @if OSPDEPREC The status code: 405 Method Not Allowed @endif */
	NET_HTTP_STATUS_NOT_ACCEPTABLE = 406,                                   /**< @if OSPDEPREC The status code: 406 Not Acceptable @endif */
	NET_HTTP_STATUS_PROXY_AUTHENTICATION_REQUIRED = 407,                    /**< @if OSPDEPREC The status code: 407 Proxy Authentication Required @endif */
	NET_HTTP_STATUS_REQUEST_TIME_OUT = 408,                                 /**< @if OSPDEPREC The status code: 408 Request Timeout (not used) @endif */
	NET_HTTP_STATUS_CONFLICT = 409,                                         /**<@if OSPDEPREC  The status code: 409 Conflict @endif */
	NET_HTTP_STATUS_GONE = 410,                                             /**< @if OSPDEPREC The status code: 410 Gone @endif */
	NET_HTTP_STATUS_LENGTH_REQUIRED = 411,                                  /**< @if OSPDEPREC The status code: 411 Length Required @endif */
	NET_HTTP_STATUS_PRECONDITION_FAILED = 412,                              /**<@if OSPDEPREC  The status code: 412 Precondition Failed @endif */
	NET_HTTP_STATUS_REQUEST_ENTITY_TOO_LARGE = 413,                         /**< @if OSPDEPREC The status code: 413 Request Entity Too Large (not used) @endif */
	NET_HTTP_STATUS_REQUEST_URI_TOO_LARGE = 414,                            /**< @if OSPDEPREC The status code: 414 Request-URI Too Long (not used) @endif */
	NET_HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE = 415,                           /**< @if OSPDEPREC The status code: 415 Unsupported %Media Type @endif */

	NET_HTTP_STATUS_INTERNAL_SERVER_ERROR = 500,                            /**< @if OSPDEPREC The status code: 500 Internal Server Error @endif */
	NET_HTTP_STATUS_NOT_IMPLEMENTED = 501,                                  /**< @if OSPDEPREC The status code: 501 Not Implemented @endif */
	NET_HTTP_STATUS_BAD_GATEWAY = 502,                                      /**< @if OSPDEPREC The status code: 502 Bad Gateway @endif */
	NET_HTTP_STATUS_SERVICE_UNAVAILABLE = 503,                              /**< @if OSPDEPREC The status code: 503 Service Unavailable @endif */
	NET_HTTP_STATUS_GATEWAY_TIME_OUT = 504,                                 /**< @if OSPDEPREC The status code: 504 Gateway Timeout @endif */
	NET_HTTP_STATUS_HTTP_VERSION_NOT_SUPPORTED = 505                        /**< @if OSPDEPREC The status code: 505 HTTP Version Not Supported @endif */
};

/**
 * Status Code: 100 Continue
 *
 * @since 2.0
 */
static const int HTTP_STATUS_CONTINUE = 100;
/**
 * Status Code: 101 Switching Protocols
 *
 * @since 2.0
 */
static const int HTTP_STATUS_SWITCHING_PROTOCOLS = 101;

/**
 * Status Code: 200 OK
 *
 * @since 2.0
 */
static const int HTTP_STATUS_OK = 200;
/**
 * Status Code: 201 Created
 *
 * @since 2.0
 */
static const int HTTP_STATUS_CREATED = 201;
/**
 * Status Code: 202 Accepted
 *
 * @since 2.0
 */
static const int HTTP_STATUS_ACCEPTED = 202;
/**
 * Status Code: 203 Non-Authoritative Information
 *
 * @since 2.0
 */
static const int HTTP_STATUS_NON_AUTHORITATIVE_INFORMATION = 203;
/**
 * Status Code: 204 No %Content
 *
 * @since 2.0
 */
static const int HTTP_STATUS_NO_CONTENT = 204;
/**
 * Status Code: 205 Reset %Content
 *
 * @since 2.0
 */
static const int HTTP_STATUS_RESET_CONTENT = 205;
/**
 * Status Code: 206 Partial %Content
 *
 * @since 2.0
 */
static const int HTTP_STATUS_PARTIAL_CONTENT = 206;
/**
 * Status Code: 300 Multiple Choices
 *
 * @since 2.0
 */
static const int HTTP_STATUS_MULTIPLE_CHOICE = 300;
/**
 * Status Code: 301 Moved Permanently
 *
 * @since 2.0
 */
static const int HTTP_STATUS_MOVED_PERMANENTLY = 301;
/**
 * Status Code: 302 Found
 *
 * @since 2.0
 */
static const int HTTP_STATUS_FOUND = 302;
/**
 * Status Code: 303 See Other
 *
 * @since 2.0
 */
static const int HTTP_STATUS_SEE_OTHER = 303;
/**
 * Status Code: 304 Not Modified
 *
 * @since 2.0
 */
static const int HTTP_STATUS_NOT_MODIFIED = 304;
/**
 * Status Code: 305 Use Proxy
 *
 * @since 2.0
 */
static const int HTTP_STATUS_USE_PROXY = 305;
/**
 * Status Code: 306 Switch Proxy
 *
 * @since 2.0
 */
static const int HTTP_STATUS_SWITCH_PROXY = 306;
/**
 * Status Code: 307 Temporary Redirect
 *
 * @since 2.0
 */
static const int HTTP_STATUS_TEMPORARY_REDIRECT = 307;

/**
 * Status Code: 400 Bad Request
 *
 * @since 2.0
 */
static const int HTTP_STATUS_BAD_REQUEST = 400;
/**
 * Status Code: 401 Unauthorized
 *
 * @since 2.0
 */
static const int HTTP_STATUS_UNAUTHORIZED = 401;
/**
 * Status Code: 402 Payment Required
 *
 * @since 2.0
 */
static const int HTTP_STATUS_PAYMENT_REQUIRED = 402;
/**
 * Status Code: 403 Forbidden
 *
 * @since 2.0
 */
static const int HTTP_STATUS_FORBIDDEN = 403;
/**
 * Status Code: 404 Not Found
 *
 * @since 2.0
 */
static const int HTTP_STATUS_NOT_FOUND = 404;
/**
 * Status Code: 405 Method Not Allowed
 *
 * @since 2.0
 */
static const int HTTP_STATUS_METHOD_NOT_ALLOWED = 405;
/**
 * Status Code: 406 Not Acceptable
 *
 * @since 2.0
 */
static const int HTTP_STATUS_NOT_ACCEPTABLE = 406;
/**
 * Status Code: 407 Proxy Authentication Required
 *
 * @since 2.0
 */
static const int HTTP_STATUS_PROXY_AUTHENTICATION_REQUIRED = 407;
/**
 * Status Code: 408 Request Timeout
 *
 * @since 2.0
 */
static const int HTTP_STATUS_REQUEST_TIMEOUT = 408;
/**
 * Status Code: 409 Conflict
 *
 * @since 2.0
 */
static const int HTTP_STATUS_CONFLICT = 409;
/**
 * Status Code: 410 Gone
 *
 * @since 2.0
 */
static const int HTTP_STATUS_GONE = 410;
/**
 * Status Code: 411 Length Required
 *
 * @since 2.0
 */
static const int HTTP_STATUS_LENGTH_REQUIRED = 411;
/**
 * Status Code: 412 Precondition Failed
 *
 * @since 2.0
 */
static const int HTTP_STATUS_PRECONDITION_FAILED = 412;
/**
 * Status Code: 413 Request Entity Too Large
 *
 * @since 2.0
 */
static const int HTTP_STATUS_REQUEST_ENTITY_TOO_LARGE = 413;
/**
 * Status Code: 414 Request-URI Too Long
 *
 * @since 2.0
 */
static const int HTTP_STATUS_REQUEST_URI_TOO_LONG = 414;
/**
 * Status Code: 415 Unsupported %Media Type
 *
 * @since 2.0
 */
static const int HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE = 415;
/**
 * Status Code: 416 Requested Range Not Satisfiable
 *
 * @since 2.0
 */
static const int HTTP_STATUS_REQUESTED_RANGE_NOT_SATISFIABLE = 416;
/**
 * Status Code: 417 Expectation Failed
 *
 * @since 2.0
 */
static const int HTTP_STATUS_EXPECTATION_FAILED = 417;


/**
 * Status Code: 500 Internal Server Error
 *
 * @since 2.0
 */
static const int HTTP_STATUS_INTERNAL_SERVER_ERROR = 500;
/**
 * Status Code: 501 Not Implemented
 *
 * @since 2.0
 */
static const int HTTP_STATUS_NOT_IMPLEMENTED = 501;
/**
 * Status Code: 502 Bad Gateway
 *
 * @since 2.0
 */
static const int HTTP_STATUS_BAD_GATEWAY = 502;
/**
 * Status Code: 503 Service Unavailable
 *
 * @since 2.0
 */
static const int HTTP_STATUS_SERVICE_UNAVAILABLE = 503;
/**
 * Status Code: 504 Gateway Timeout
 *
 * @since 2.0
 */
static const int HTTP_STATUS_GATEWAY_TIMEOUT = 504;
/**
 * Status Code: 505 HTTP Version Not Supported
 *
 * @since 2.0
 */
static const int HTTP_STATUS_HTTP_VERSION_NOT_SUPPORTED = 505;

/**
 * @enum    NetHttpAuthScheme
 *
 * Defines the supported authentication schemes.
 *
 * @since 2.0
 */
enum NetHttpAuthScheme
{
	NET_HTTP_AUTH_NONE = 0,             /**< The no authentication type */
	NET_HTTP_AUTH_PROXY_BASIC = 1,      /**< The authentication type is Proxy Basic Authentication */
	NET_HTTP_AUTH_PROXY_MD5 = 2,        /**< The authentication type is Proxy Digest Authentication */
	NET_HTTP_AUTH_WWW_BASIC = 3,        /**< The authentication Type is HTTP Basic Authentication */
	NET_HTTP_AUTH_WWW_MD5 = 4,          /**< The authentication type is HTTP Digest Authentication */
	NET_HTTP_AUTH_PROXY_NTLM = 5,       /**< The authentication type is Proxy NTLM Authentication */
	NET_HTTP_AUTH_WWW_NTLM = 7,         /**< The authentication type is NTLM Authentication */
	NET_HTTP_AUTH_WWW_NEGOTIATE = 8     /**< The authentication type is Negotiate Authentication */
};

/**
 * @enum    NetHttpCookieFlag
 *
 * Defines the HTTP cookie mode.
 *
 * @since 2.0
 */
enum  NetHttpCookieFlag
{
	NET_HTTP_COOKIE_FLAG_NONE,              /**< The mode is not defined */
	NET_HTTP_COOKIE_FLAG_ALWAYS_AUTOMATIC,  /**< The cookie will be parsed and saved, and also attached to request automatically */
	NET_HTTP_COOKIE_FLAG_ALWAYS_MANUAL      /**< The cookie will be handled by the user action with Tizen::Net::Http::HttpRequest::SetCookie() and Tizen::Net::Http::HttpCookieStorageManager::GetCookies() */
};

/**
 * @enum    NetHttpCertificateVerificationFlag
 *
 * Defines the certificate verification mode.
 *
 * @since 2.1
 */
enum  NetHttpCertificateVerificationFlag
{
	HTTP_CV_FLAG_AUTOMATIC,  	/**< The certificate is verified by the system @n If server certificate is invalid, the IHttpTransactionEventListener::OnTransactionCertVerificationRequiredN() listener is received.  */
	HTTP_CV_FLAG_MANUAL,      /**< The certificate verification is handled by user action when the IHttpTransactionEventListener::OnTransactionCertVerificationRequestedN() listener is received */
	HTTP_CV_FLAG_IGNORED, 	/**< The certificate verification is ignored */
};

} } } //Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_TYPES_H_
