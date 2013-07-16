//
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
 * @file		FBaseStringHashCodeProvider.h
 * @brief		This is the header file for the %StringHashCodeProvider class.
 *
 * This header file contains the declarations of the %StringHashCodeProvider class.
 */
#ifndef _FBASE_STRING_HASH_CODE_PROVIDER_H_
#define _FBASE_STRING_HASH_CODE_PROVIDER_H_

#include <FBaseObject.h>
#include <FBaseColIHashCodeProvider.h>
#include <FBaseColIHashCodeProviderT.h>

namespace Tizen { namespace Base
{
/**
 * @class	StringHashCodeProvider
 * @brief	This class provides the hash code of an instance of type String.
 *
 * @since	2.1
 *
 * The %StringHashCodeProvider class provides the hash code of an instance of type String.
 *
 * The following example demonstrates how to use the %StringHashCodeProvider class.
 *
 * @code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *
 *	void
 *	MyClass::StringHashCodeProviderSample(void)
 *	{
 *		HashMapT<String, int> map;
 *
 *		ComparerT<String> comparer;
 *		StringHashCodeProvider strHashCodeProvider;
 *
 *		map.Construct(0, 0, strHashCodeProvider, comparer);
 *
 *		map.Add(String(L"Zero"), 0);
 *		map.Add(String(L"One"), 1);
 *		map.Add(String(L"Two"), 2);
 *
 *		...
 *	}
 * @endcode
 */
class _OSP_EXPORT_ StringHashCodeProvider
	: public virtual Tizen::Base::Collection::IHashCodeProvider
	, public virtual Tizen::Base::Collection::IHashCodeProviderT <Tizen::Base::String>
	, public Tizen::Base::Object
{
public:
	using Object::GetHashCode;

	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.1
	 */
	StringHashCodeProvider(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~StringHashCodeProvider(void);

	/**
	 * Gets the hash code of an instance of type String.
	 *
	 * @since	2.1
	 *
	 * @return		The hash code of an instance of type String
	 * @param[in]	str		The String instance whose hash code is requested
	 * @remarks		The hash algorithm is usually specific to a type.
	 *				Two equal instances must return the same hash value.
	 *				For better performance, the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(const Tizen::Base::String& str) const;

	/**
	 * Gets the hash code of the specified object.
	 *
	 * @since	2.1
	 *
	 * @return		The hash code of the specified object
	 * @param[in]	obj		The Object whose hash code is requested
	 * @remarks		The hash algorithm is usually specific to a type.
	 *				Two equal instances must return the same hash value.
	 *				For better performance, the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(const Tizen::Base::Object& obj) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	StringHashCodeProvider(const StringHashCodeProvider& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	StringHashCodeProvider& operator =(const StringHashCodeProvider& rhs);

}; // StringHashCodeProvider

}} // Tizen::Base

#endif // _FBASE_STRING_HASH_CODE_PROVIDER_H_
