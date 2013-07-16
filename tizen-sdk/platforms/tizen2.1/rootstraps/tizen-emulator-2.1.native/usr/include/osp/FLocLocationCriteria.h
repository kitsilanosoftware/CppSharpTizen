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
 * @file	FLocLocationCriteria.h
 * @brief	This is the header file for the %LocationCriteria class.
 *
 * This header file contains the declarations of the %LocationCriteria class.
 */

#ifndef _FLOC_LOCATION_CRITERIA_H_
#define _FLOC_LOCATION_CRITERIA_H_

#include <FBaseObject.h>
#include <FLocTypes.h>

namespace Tizen { namespace Locations
{

/**
* @class	LocationCriteria
* @brief	This class provides methods to specify the service quality that an application wants for the location provider.
*
* @since 2.0
*
* @final	This class is not intended for extension.
*
* The %LocationCriteria class provides methods to specify the service quality that an application wants for the location provider.
* The application specifies the location criteria based on its scenario and gives it to the location provider.
*
* The accuracy in the location criteria is for specifying the accuracy levels for the location provider.
* The accuracy @c LOC_ACCURACY_ANY is for getting locations of any accuracy that the location provider provides.
* The application can get more accurate locations as it takes higher accuracy levels from @c LOC_ACCURACY_ONE_KILOMETER,
* @c LOC_ACCURACY_HUNDRED_METERS, @c LOC_ACCURACY_TEN_METERS, and @c LOC_ACCURACY_FINEST.
* The application should be aware that higher accuracy levels makes the location provider run costly positioning systems more. Considering proper
* accuracy levels helps the system to provide efficient services to the user.
*
* @see		LocationProvider
*/
class _OSP_EXPORT_ LocationCriteria
	: public Tizen::Base::Object
{
public:
	/**
	* Initializes an instance of %LocationCriteria with the accuracy set to @c LOC_ACCURACY_ANY.
	*
	* @since 2.0
	* @see		SetAccuracy()
	*/
	LocationCriteria(void);

	/**
	* This is the copy constructor for the %LocationCriteria class. @n
	* Copying of objects using this copy constructor is allowed.
	*
	* @since 2.0
	*
	* @param[in]	rhs	An instance of %LocationCriteria to copy
	*/
	LocationCriteria(const LocationCriteria& rhs);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since 2.0
	*/
	virtual ~LocationCriteria(void);

	/**
	* Compares the calling instance with the specified instance for equality.
	*
	* @since 2.0
	*
	* @return	@c true if all the fields in the objects are equal, @n
	*			else @c false
	* @param[in]	rhs	The object to compare
	*/
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	* Gets the hash value of the calling instance.
	*
	* @since 2.0
	*
	* @return	The hash value of the calling instance
	*/
	virtual int GetHashCode(void) const;

	/**
	* Sets the desired accuracy.
	*
	* @since 2.0
	*
	* @return	An error code
	* @param[in]	accuracy	The desired accuracy
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_INVALID_ARG	The specified @c accuracy is invalid.
	* @see		GetAccuracy()
	*/
	result SetAccuracy(LocationAccuracy accuracy);

	/**
	* Gets the desired accuracy of this location criteria.
	*
	* @since 2.0
	*
	* @return	The accuracy of this location criteria
	* @see		SetAccuracy()
	*/
	LocationAccuracy GetAccuracy(void) const;

	/**
	* Copying of objects using this copy assignment operator is allowed.
	*
	* @since 2.0
	*
	* @return	A reference to the current instance
	* @param[in]	rhs	An instance of %LocationCriteria to assign
	*/
	LocationCriteria& operator =(const LocationCriteria& rhs);

private:
	LocationAccuracy __accuracy;

	class _LocationCriteriaImpl* __pImpl;
	friend class _LocationCriteriaImpl;
}; // LocationCriteria
}} // Tizen::Locations
#endif // _FLOC_LOCATION_CRITERIA_H_
