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
 * @file		FBase.h
 * @brief		This is the header file for the %Base namespace.
 *
 * This header file contains the declarations and descriptions of the %Base namespace.
 */
#ifndef _FBASE_H_
#define _FBASE_H_


// Base
#include <FBaseTypes.h>
#include <FBaseErrors.h>
#include <FBaseErrorDefine.h>
#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseCharacter.h>
#include <FBaseNumber.h>
#include <FBaseBoolean.h>
#include <FBaseInt8.h>
#include <FBaseInteger.h>
#include <FBaseShort.h>
#include <FBaseLong.h>
#include <FBaseLongLong.h>
#include <FBaseFloat.h>
#include <FBaseDouble.h>
#include <FBaseString.h>
#include <FBaseInt8Comparer.h>
#include <FBaseIntegerComparer.h>
#include <FBaseShortComparer.h>
#include <FBaseLongComparer.h>
#include <FBaseLongLongComparer.h>
#include <FBaseFloatComparer.h>
#include <FBaseDoubleComparer.h>
#include <FBaseStringComparer.h>
#include <FBaseComparerT.h>
#include <FBaseDateTime.h>
#include <FBaseTimeSpan.h>
#include <FBaseBuffer.h>
#include <FBaseByteBuffer.h>
#include <FBaseUuId.h>

// Collection
#include <FBaseCol.h>

// Runtime
#include <FBaseRt.h>

// Utility
#include <FBaseUtil.h>


/**
 *	@namespace	Tizen::Base
 *	@brief		This namespace contains classes and interfaces for basic features.
 *	@since 2.0
 *
 *  @remarks  @b Header @b %file: @b \#include @b <FBase.h> @n
 *				@b Library : @b osp-appfw
 *
 * The %Base namespace contains classes and interfaces around which the entire Tizen platform is built.
 * The main features of the namespace include basic data types, collections, runtime libraries, and various utilities.
 *
 * For more information on the %Base namespace features, see <a href="../org.tizen.native.appprogramming/html/guide/base/base_namespace.htm">Base Guide</a>.
 *
 *  The following diagram illustrates the relationships between the classes belonging to the %Base namespace.
 *  @image html base_namespace_classdiagram.png
 *
 *
 *
 */

namespace Tizen { namespace Base
{

}} // Tizen::Base
#endif // _FBASE_H_
