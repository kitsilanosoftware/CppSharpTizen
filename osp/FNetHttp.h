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
 * @file		FNetHttp.h
 * @brief		This is the header file for the %Http namespace.
 *
 * This header file contains the declarations and descriptions of the %Http namespace.
 */

#ifndef _FNET_HTTP_H_
#define _FNET_HTTP_H_

#include "FNetHttpHttpTypes.h"
#include "FNetHttpHttpHeader.h"
#include "FNetHttpHttpMessage.h"
#include "FNetHttpHttpRequest.h"
#include "FNetHttpHttpResponse.h"
#include "FNetHttpHttpSession.h"
#include "FNetHttpHttpCookieStorageManager.h"
#include "FNetHttpHttpTransaction.h"
#include "FNetHttpIHttpTransactionEventListener.h"
#include "FNetHttpHttpAuthentication.h"
#include "FNetHttpHttpCookie.h"
#include "FNetHttpHttpCredentials.h"
#include "FNetHttpIHttpEntity.h"
#include "FNetHttpHttpMultipartEntity.h"
#include "FNetHttpHttpStringEntity.h"
#include "FNetHttpHttpUrlEncodedEntity.h"
#include "FNetHttpHttpXmlDomEntity.h"
#include "FNetHttpIHttpProgressEventListener.h"


namespace Tizen { namespace Net
{
/**
 * @namespace	Tizen::Net::Http
 * @brief		This namespace contains the classes and interfaces for the HTTP 1.1 client programming.
 * @since       2.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FNet.h> @n
 *			    @b Library : @b osp-net
 *
 * The %Http namespace contains the fundamental classes and interfaces for the HTTP 1.1 client programming.
 *
 * It provides the implementation of the HTTP data communication protocol. This namespace provides:
 * - A client interface for the internet applications using the HTTP protocol for communication with the HTTP servers on the Internet.
 * - A HTTP management module that encapsulates a standard HTTP request-and-response transaction and provides access to the common HTTP headers.
 * - Support for most HTTP 1.1 features, including pipelining and chunking.
 *
 * Using this namespace correctly, makes the application a conditional HTTP 1.1-compliant client, as defined in RFC 2616.
 *
 * For more information on the HTTP namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_connectivity.htm">HTTP Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Net namespace.
 * @image	html	net_http_using_the_apis_classdiagram.png
 *
 *
 */
namespace Http
{
} } } //	Tizen::Net::Http
#endif // _FNET_HTTP_H_
