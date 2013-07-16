//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FBaseColAllElementsDeleter.h
 * @brief		This is the header file for the %AllElementsDeleter struct.
 *
 * This header file contains the declarations of the %AllElementsDeleter struct.
 */

#ifndef _FBASE_COL_ALL_ELEMENTS_DELETER_H_
#define _FBASE_COL_ALL_ELEMENTS_DELETER_H_

namespace Tizen { namespace Base { namespace Collection
{
/**
 * @struct	AllElementsDeleter
 * @brief	This function object provides a resource clean-up function for collection.
 *
 * The %AllElementsDeleter struct provides a resource clean-up function for collection. This can be used with unique_ptr as a custom deleter.
 *
 * @since 2.0
 */
struct AllElementsDeleter
{
	/**
	 * Deletes every element of the collection and the collection itself.
	 *
	 * @since 2.0
	 *
	 * @param[in] c		The collection to clean up
	 * @remarks		The collection should be destructible and support the RemoveAll(bool) method.
	 *			IList, IMap, and IMultiMap support this concept.
	 */
	template< typename Collection >
	void operator ()(Collection* c)
	{
		c->RemoveAll(true);
		delete c;
	}
};
}}}

#endif // _FBASE_COL_ALL_ELEMENTS_DELETER_H_
