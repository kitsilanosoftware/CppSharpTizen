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

/**
 * @file		FBaseObject.h
 * @brief		This is the header file for the %Object class.
 *
 * This header file contains the declarations of the %Object class. @n
 * This class defines a set of behaviors shared by all Tizen classes.
 */
#ifndef _FBASE_OBJECT_H_
#define _FBASE_OBJECT_H_

#include <FBaseTypes.h>
#include <FOspConfig.h>
#include <FOspCompat.h>


namespace Tizen { namespace Base
{
/**
 * @class	Object
 * @brief	This class is the @b root class of Tizen.
 *
 * @since 2.0
 *
 * The %Object class defines a set of behaviors and characteristics shared by all the other classes.
 *
 * The derived classes can override some of these methods, such as the Equals() method, which tests for object equivalence.
 */
class _OSP_EXPORT_ Object
{
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *  @since 2.0
	 */
	Object(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *  @since 2.0
	 */
	virtual ~Object(void);

	/**
	 *	Checks whether the value of the specified instance is equal to the value of the current instance of %Object.
	 *
	 *  @since 2.0
	 *
	 *	@return			@c true if the value of the specified instance of %Object is equal to the value of the current instance of %Object, @n
	 *				else @c false
	 *	@param[in]	obj	An instance of %Object to compare
	 *	@remarks 	The default implementation of this method returns @c true
	 *				if the two instances have the same address. @n
	 *				The method can be overridden to support value equality. Furthermore, this method must return the same result as the equality operator.
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 *	Gets the hash value of the current instance of %Object.
	 *
	 *  @since 2.0
	 *
	 *	@return		An integer value indicating the hash value of the current instance of %Object
	 *	@remarks 	Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs. @n
	 *				The default implementation of this method returns the address of the current instance.
	 */
	virtual int GetHashCode(void) const;

protected:
	/**
	 * This is the copy constructor for the %Object class.
	 *
	 * @param[in]	obj	An instance of %Object
	 */
	Object(const Object& obj);

	/**
	 * Assigns the value of the specified instance to the current instance of %Object.
	 *
	 * @param[in]	rhs	An instance of %Object
	 */
	Object& operator =(const Object& rhs);

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void Object_Reserved1(void) { }

}; // Object

}} // Tizen::Base

#endif //_FBASE_OBJECT_H_
