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
* @file		FSclRelationship.h
* @brief	This is the header file for the %Relationship class.
*
* This header file contains the declarations of the %Relationship class.
*/
#ifndef _FSCL_RELATIONSHIP_H_
#define _FSCL_RELATIONSHIP_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FBaseString.h>
#include <FSclTypes.h>

namespace Tizen { namespace Social
{

/**
* @class	Relationship
* @brief	This class represents a relation.
*
* @since	2.0
*
* @final	This class is not intended for extension.
*
* The %Relationship class represents a relation. A relation consists of the type, label, and name. 
*
*/
class _OSP_EXPORT_ Relationship
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	Relationship(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs	An instance of %Relationship
	 */
	Relationship(const Relationship& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Relationship(void);

	/**
	 * Checks whether the value of the specified instance is equal to the value of the current instance of Tizen::Base::Object.
	 *
	 * @since	2.0
	 *
	 * @return	@c true if the value of the specified instance of Tizen::Base::Object is equal to the value of the current instance of %Tizen::Base::Object, @n
	 *			else @c false
	 * @param[in]	rhs		An instance of Tizen::Base::Object to compare
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance of Tizen::Base::Object.
	 *
	 * @since	2.0
	 *
	 * @return	An integer value indicating the hash value of the current instance of Tizen::Base::Object
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Gets the relation type.
	 *
	 * @since	2.0
	 *
	 * @return	The type of the relation
	 */
	RelationshipType GetType(void) const;

	/**
	 * Gets the name of the relative.
	 *
	 * @since	2.0
	 *
	 * @return	The name of the relative
	 */
	Tizen::Base::String GetRelativeName(void) const;

	/**
	 * Gets the label of the relation.
	 *
	 * @since	2.0
	 *
	 * @return	The relation label
	 * @see SetLabel()
	 */
	Tizen::Base::String GetLabel(void) const;

	/**
	 * Sets the relation type.
	 *
	 * @since	2.0
	 *
	 * @param[in]	type		The type of the relation
	 */
	void SetType(RelationshipType type);

	/**
	 * Sets the label of a relation.
	 *
	 * @since	2.0
	 *
	 * @param[in]	label		The relation label
	 * @see GetLabel()
	 */
	void SetLabel(const Tizen::Base::String& label);

	/**
	 * Sets the name of the relative.
	 *
	 * @since	2.0
	 *
	 * @param[in]	name		The name of the relative
	 */
	void SetRelativeName(const Tizen::Base::String& relativeName);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs	An instance of %Relationship
	 */
	Relationship& operator =(const Relationship& rhs);

	/**
	 * Checks whether the data in the specified instance of %Relationship is equal to the data in the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data in the specified instance equals the data in the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Relationship
	 */
	bool operator ==(const Relationship& rhs) const;

	/**
	 * Checks whether the data in the specified instance of %Relationship is not equal to the data in the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data in the specified instance is not equal to the data in the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Relationship
	 */
	bool operator !=(const Relationship& rhs) const;

private:
	RelationshipType __type;
	Tizen::Base::String __label;
	Tizen::Base::String __name;

	friend class _RelationshipImpl;
	class _RelationshipImpl* __pRelationshipImpl;
}; // Relationship

}} // Tizen::Social

#endif // _FSCL_RELATIONSHIP_H_
