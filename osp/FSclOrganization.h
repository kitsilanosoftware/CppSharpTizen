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
 * @file	FSclOrganization.h
 * @brief	This is the header file for the %Organization class.
 *
 * This header file contains the declarations of the %Organization class.
 */
#ifndef _FSCL_ORGANIZATION_H_
#define _FSCL_ORGANIZATION_H_

#include <FBaseResult.h>
#include <FBaseObject.h>
#include <FSclTypes.h>

namespace Tizen { namespace Base
{
class String;
}}

namespace Tizen { namespace Social
{

/**
 * @class	Organization
 * @brief	This class represents the organization information.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Organization class represents the organization information of a person. @n
 * The organization information consists of name, job title, role, agent, and department.
 */
class _OSP_EXPORT_ Organization
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since	2.0
	 */
	Organization(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Organization
	 */
	Organization(const Organization& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~Organization(void);

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
	 * Gets the organization name.
	 *
	 * @since	2.0
	 *
	 * @return	The organization name
	 */
	Tizen::Base::String GetName(void) const;

	/**
	 * Gets the job title.
	 *
	 * @since	2.0
	 *
	 * @return	The job title
	 */
	Tizen::Base::String GetJobTitle(void) const;

	/**
	 * Gets the department. 
	 *
	 * @since	2.0
	 *
	 * @return	The department
	 */
	Tizen::Base::String GetDepartment(void) const;

	/**
	 * Gets the role.
	 *
	 * @since	2.0
	 *
	 * @return	The role
	 */
	Tizen::Base::String GetRole(void) const;

	/**
	 * Gets the agent.
	 *
	 * @since	2.0
	 *
	 * @return	The agent
	 */
	Tizen::Base::String GetAgent(void) const;

	/**
	* Sets the name of the organization.
	*
	* @since	2.0
	*
	* @param[in]	name	The organization name
	*/
	void SetName(const Tizen::Base::String& name);

	/**
	 * Sets the job title.
	 *
	 * @since	2.0
	 *
	 * @param[in]	jobTitle	The job title
	 */
	void SetJobTitle(const Tizen::Base::String& jobTitle);

	/**
	 * Sets the department.
	 *
	 * @since	2.0
	 *
	 * @param[in]	department	The department
	 */
	void SetDepartment(const Tizen::Base::String& department);

	/**
	 * Sets the role.
	 *
	 * @since	2.0
	 *
	 * @param[in]	role	The role
	 */
	void SetRole(const Tizen::Base::String& role);

	/**
	 * Sets the agent.
	 *
	 * @since	2.0
	 *
	 * @param[in]	agent		The agent
	 */
	void SetAgent(const Tizen::Base::String& agent);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since	2.0
	 *
	 * @param[in]	rhs		An instance of %Organization
	 */
	Organization& operator =(const Organization& rhs);

	/**
	 * Checks whether the data in the specified instance of %Organization is equal to the data in the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data in the specified instance equals the data in the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Organization
	 */
	bool operator ==(const Organization& rhs) const;

	/**
	 * Checks whether the data in the specified instance of %Organization is not equal to the data in the current instance.
	 *
	 * @since	2.0
	 *
	 * @return		@c true if the data in the specified instance is not equal to the data in the current instance, @n
	 *				else @c false
	 * @param[in]	rhs		An instance of %Organization
	 */
	bool operator !=(const Organization& rhs) const;

private:
	friend class _OrganizationImpl;
	class _OrganizationImpl* __pOrganizationImpl;
}; // Organization

}} // Tizen::Social

#endif //_FSCL_ORGANIZATION_H_
