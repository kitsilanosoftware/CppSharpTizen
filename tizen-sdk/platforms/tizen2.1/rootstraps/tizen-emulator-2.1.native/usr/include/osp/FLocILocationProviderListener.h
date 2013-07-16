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
* @file		FLocILocationProviderListener.h
* @brief	This is the header file for the %ILocationProviderListener interface.
*
* This header file contains the declarations of the %ILocationProviderListener interface.
*/

#ifndef _FLOC_ILOCATION_PROVIDER_LISTENER_H_
#define _FLOC_ILOCATION_PROVIDER_LISTENER_H_

#include <FBaseRtIEventListener.h>
#include <FLocTypes.h>

namespace Tizen { namespace Locations
{

class Location;

/**
* @interface    ILocationProviderListener
* @brief	This interface defines listener interfaces to get asynchronous notifications from the location provider.
*
* @since 2.0
*
* The %ILocationProviderListener interface defines listener interfaces to get asynchronous notifications from the location provider.
* An application should implement this listener interface and construct the location provider with the listener
* to get the asynchronous notifications for the location updates and region monitoring requests.
*
* @see		LocationProvider
*/
class _OSP_EXPORT_ ILocationProviderListener
	: virtual public Tizen::Base::Runtime::IEventListener
{
public:
	/**
	* This polymorphic destructor should be overridden if required. @n This way, the destructors of the derived classes are called
	* when the destructor of this interface is called.
	*
	* @since 2.0
	*/
	virtual ~ILocationProviderListener(void)  {}

	/**
	* Called when the location update is running. @n
	* The location update is started when an application calls the LocationProvider::StartLocationUpdatesByInterval() or LocationProvider::StartLocationUpdatesByDistance() methods. @n
	* Note that, the updated locations may not always fall into the requested accuracy level that the application has specified in the criteria. @n
	* The application is able to filter out less accurate locations by checking the location accuracy with the Location::GetHorizontalAccuracy() method
	* if it matters to the application. @n
	* During updating locations, along with changes in the location's accuracy, changes in the service status are also notified.
	*
	* @since 2.0
	*
	* @param[in]	location	The location to update
	* @remarks	An application should implement this method when it requests for the location updates and wants to handle the updated locations.
	* @see		OnAccuracyChanged()
	* @see		OnLocationUpdateStatusChanged()
	*/
	virtual void OnLocationUpdated(const Tizen::Locations::Location& location) { }

	/**
	* Called when the location provider detects a movement entering into the registered region. @n
	* A region is registered for monitoring by calling LocationProvider::AddMonitoringRegion() and is identified by the region ID. @n
	* While monitoring regions, the changes in the location's accuracy and the changes in the service status are notified.
	*
	* @since 2.0
	*
	* @param[in]	regionId	The ID for the registered region
	* @remarks	An application should implement this method when it requests for the region monitoring and wants to handle the movement into the region.
	* @see		OnAccuracyChanged()
	* @see		OnRegionMonitoringStatusChanged()
	*/
	virtual void OnRegionEntered(Tizen::Locations::RegionId regionId) { }

	/**
	* Called when the location provider detects a movement leaving from the registered region. @n
	* A region is registered for monitoring by calling LocationProvider::AddMonitoringRegion() and identified by the region ID. @n
	* While monitoring regions, the changes in the location's accuracy and the changes in the service status are notified.
	*
	* @since 2.0
	*
	* @param[in]	regionId	The ID for the registered region
	* @remarks	An application should implement this method when it requests the region monitoring and wants to handle the movement out of the region.
	* @see		OnAccuracyChanged()
	* @see		OnRegionMonitoringStatusChanged()
	*/
	virtual void OnRegionLeft(Tizen::Locations::RegionId regionId) { }

	/**
	* Called when the service status of the location updates change. @n
	* The status changes to @c LOC_SVC_STATUS_RUNNING, when the location provider successfully runs the requested service. @n
	* The status changes to @c LOC_SVC_STATUS_NOT_FIXED, when the location provider is not able to run the requested service because it
	* cannot fix the current location due to poor circumstances such as weak radio for positioning. @n
	* When this status continues for a fairly long time, it is recommended to cancel the request. The request should be run after some time in order to avoid excessive battery consumption. @n
	* When the user withdraws the permission for an application to use the location information, the status changes to
	* @c LOC_SVC_STATUS_DENIED and the location provider stops all ongoing services to the application.  @n
	* In that case, the application might ask the user to grant permission to continue the aborted service
	* or to finalize all resources for the location provider. @n
	* The status @c LOC_SVC_STATUS_PAUSED is displayed when the location provider pauses the ongoing service. This happens when the application requests for the location updates without keeping the location updates awake. The status will be changed to others
	* once the location provider resumes the paused service. @n
	* Note that, the application can get notifications about the location updates and accuracy changes
	* only when the service status is @c LOC_SVC_STATUS_RUNNING.
	*
	* @since 2.0
	*
	* @param[in]	status	The service status of the location updates
	* @remarks	An application should implement this method when it requests for the location updates and wants to handle status changes of the service.
	*/
	virtual void OnLocationUpdateStatusChanged(Tizen::Locations::LocationServiceStatus status) { }


	/**
	* Called when the service status of the region monitoring changes. @n
	* The status changes to @c LOC_SVC_STATUS_RUNNING, when the location provider successfully runs the requested service. @n
	* The status changes to @c LOC_SVC_STATUS_NOT_FIXED, when the location provider is not able to run the requested service because it
	* cannot fix the location that is suitable for monitoring the regions. @n
	* When the user withdraws the permission for an application to use the location information, the status changes to
	* @c LOC_SVC_STATUS_DENIED and the location provider stops all ongoing services to the application. @n
	* In that case, the application might ask the user to grant permission to continue the aborted service
	* or to finalize all resources for the location provider. @n
	* Note that, the application can get notifications about the movement around regions and accuracy changes
	* only when the service status is @c LOC_SVC_STATUS_RUNNING.
	*
	* @since 2.0
	*
	* @param[in]	status	The service status of the region monitoring
	* @remarks	An application should implement this method when it requests for the region monitoring and wants to handle status changes of the service.
	*/
	virtual void OnRegionMonitoringStatusChanged(Tizen::Locations::LocationServiceStatus status) { }


	/**
	* Called when the accuracy level of the location changes. @n
	* The location provider tries to provide accurate location services as specified in the criteria,
	* but the location provided by location provider may not always fall into the requested accuracy level. @n
	* The %OnAccuracyChanged() listener method is called whenever the current accuracy of the location provided by location provider is changed. @n
	* The accuracy changes to @c LOC_ACCURACY_INVALID when the location provider is not running any services in @c LOC_SVC_STATUS_RUNNING
	* status.
	*
	* @since 2.0
	*
	* @param[in]	accuracy	The accuracy of the location
	*/
	virtual void OnAccuracyChanged(Tizen::Locations::LocationAccuracy accuracy) = 0;

protected:
	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	virtual void ILocationProviderListener_Reserved1(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	virtual void ILocationProviderListener_Reserved2(void) { }

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	virtual void ILocationProviderListener_Reserved3(void) { }
}; // ILocationProviderListener
}} // Tizen::Locations
#endif // _FLOC_ILOCATION_PROVIDER_LISTENER_H_
