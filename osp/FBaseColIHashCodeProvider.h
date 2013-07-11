//
// Open Service Platform
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
 * @file		FBaseColIHashCodeProvider.h
 * @brief		This is the header file for the %IHashCodeProvider interface.
 *
 * This header file contains the declarations of the %IHashCodeProvider interface.
 */
#ifndef _FBASE_COL_IHASH_CODE_PROVIDER_H_
#define _FBASE_COL_IHASH_CODE_PROVIDER_H_

namespace Tizen {namespace Base
{
class Object;
}}

namespace Tizen { namespace Base { namespace Collection
{

/**
 * @interface	IHashCodeProvider
 * @brief	This interface represents classes that can provide the hash code of a specific type of object.
 *
 * @since 2.0
 *
 * The %IHashCodeProvider interface represents classes that can provide the hash code of a specific type of object.
 */
class _OSP_EXPORT_ IHashCodeProvider
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. @n
	 * This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IHashCodeProvider(void) {}

	/**
	 * Gets the hash code of the specified object.
	 *
	 * @since 2.0
	 *
	 * @return		The hash code of the specified object
	 * @param[in]	obj A pointer to the object whose hash code is required
	 * @remarks 	The hash algorithm is usually specific to a type.
	 *				Two equal instances must return the same hash value.
	 *				For better performance, the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(const Tizen::Base::Object& obj) const = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IHashCodeProvider_Reserved1(void) { }


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void IHashCodeProvider_Reserved2(void) { }

}; // IHashCodeProvider

}}} // Tizen::Base::Collection

#endif // _FBASE_COL_IHASH_CODE_PROVIDER_H_
