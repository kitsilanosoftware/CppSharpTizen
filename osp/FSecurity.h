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
 * @file		FSecurity.h
 * @brief		This is the header file for the %Security namespace.
 *
 * This header file contains the declarations of the %Security namespace.
 *
 */
#ifndef _FSECURITY_H_
#define _FSECURITY_H_

#include "FSecAesSecureRandom.h"
#include "FSecDesEdeSecureRandom.h"
#include "FSecDesSecureRandom.h"
#include "FSecIKey.h"
#include "FSecIKeyPairGenerator.h"
#include "FSecIPrivateKey.h"
#include "FSecIPublicKey.h"
#include "FSecISecretKey.h"
#include "FSecISecretKeyGenerator.h"
#include "FSecISecureRandom.h"
#include "FSecKeyPair.h"
#include "FSecKeyPairGenerator.h"
#include "FSecPrivateKey.h"
#include "FSecPublicKey.h"
#include "FSecSecretKey.h"
#include "FSecSecretKeyGenerator.h"
#include "FSecIKeyParameters.h"
#include "FSecCryptoIKeyExchange.h"
#include "FSecCryptoKeaKeyExchange.h"
#include "FSecCryptoDhKeyExchange.h"
#include "FSecKeaKeyParameters.h"
#include "FSecDhKeyParameters.h"
#include "FSecCrypto.h"
#include "FSecCert.h"


/**
 * @namespace	Tizen::Security
 * @brief		This namespace contains classes and interfaces for security services.
 *
 * @since   2.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FSecurity.h> @n
 *				@b Library : @b osp-appfw
 *
 *
 * The %Security namespace contains classes for
 * managing certificates, cryptographic keys, signatures, and for generating pseudo-random numbers. @n
 *
 * For more information on the %Security namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/security/security_namespace.htm">Security Guide</a>. @n
 *
 * The following diagram illustrates the relationships between the classes and sub-namespaces belonging to the %Security namespace.
 * @image html security_classdiagram.png
 *
 */
namespace Tizen { namespace Security
{

} } //Tizen::Security

#endif // _FSECURITY_H_
