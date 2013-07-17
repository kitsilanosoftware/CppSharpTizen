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
 * @file	FLocLocationProvider.h
 * @brief	This is the header file for the %LocationProvider class.
 *
 * This header file contains the declarations of the %LocationProvider class.
 */

#ifndef _FLOC_LOCATION_PROVIDER_H_
#define _FLOC_LOCATION_PROVIDER_H_

#include <FBaseObject.h>
#include <FLocTypes.h>

namespace Tizen { namespace Locations
{
class LocationCriteria;
class Location;
class ILocationProviderListener;

/**
* @class	LocationProvider
* @brief	This class provides methods to get locations and enable region monitoring.
*
* @since 2.0
*
* @final	This class is not intended for extension.
*
* The %LocationProvider class is a fundamental module that provides location-based services: location providing and region monitoring.
* The location provider is constructed with a location criteria and offers the services trying to satisfy it in a best-effort manner.
* An application gets locations by simply calling the GetLocation() method, or requesting asynchronous location updates with the
* StartLocationUpdatesByInterval() and StartLocationUpdatesByDistance() methods. An application can also register regions by calling the
* AddMonitoringRegion() method to be notified when moving into or out of regions. It gets asynchronous location updates and notifications
* from the region monitoring by assigning a listener, which implements the ILocationProviderListener interface, to the location provider.
*
* @see		LocationCriteria
*/
class _OSP_EXPORT_ LocationProvider
	: public Tizen::Base::Object
{
public:
	/**
	* The object is not fully constructed after this constructor is called. @n
	* For full construction, the Construct() method must be called right after
	* calling this constructor.
	*
	* @since 2.0
	*/
	LocationProvider(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since 2.0
	*/
	virtual ~LocationProvider(void);

	/**
	* Initializes this instance of %LocationProvider with the specified @c criteria and @c listener. @n
	* An application chooses the desired service quality based on its scenario and constructs the location provider with the specified
	* @c criteria. The desired accuracy for locations is a configurable property of LocationCriteria. @n
	* The location provider tries to provides locations and services based on the specified @c criteria. @n
	* The @c listener is notified on asynchronous location updates or region monitoring events.
	*
	* @since 2.0
	*
	* @feature	%http://tizen.org/feature/location
	* @return	An error code
	* @param[in]	criteria	The desired location criteria
	* @param[in]	listener	The listener to register
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_SYSTEM	A system error has occurred.
	* @exception	E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature. @b Since: @b 2.1
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @remarks	Before calling this method, check whether the feature is supported by Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	*/
	result Construct(const LocationCriteria& criteria, ILocationProviderListener& listener);

	/**
	* Requests the location updates service with the specific @c interval. @n
	* Once the location updates have started and the location provider has fixed the current location, the location is delivered
	* to the listener by calling the ILocationProviderListener::OnLocationUpdated() method. @n
	* The location provider is trying to provide accurate locations as requested in the criteria, but locations updated by the location provider
	* do not always fall into the requested accuracy level. It provides locations in low-grade accuracy if that is all it can offer
	* or can not even provide locations when it hardly fixes the current location.  @n The location provider notifies the listener whenever the accuracy
	* level of ongoing updates are changed by calling the ILocationProviderListener::OnAccuracyChanged() method. @n
	* The location updates can be paused by the location provider when the application is unable to point locations out to the user
	* for the moment. @n This is possible for the following situations:
	*  - The application is not running in foreground.
	*  - The screen is off.
	*
	* In this case, the location provider notifies the status @c LOC_SVC_STATUS_PAUSED to the listener. @n
	* It resumes the paused location updates when the application gets out of the situations. @n
	* To get the location updates all the time, the application should use the KeepLocationUpdateAwake() method. @n
	* The change in the service status that the location provider is providing are notified to the listener
	* by calling the ILocationProviderListener::OnLocationUpdateStatusChanged() method. @n
	* If the location updates are already started by calling the StartLocationUpdatesByInterval() or StartLocationUpdatesByDistance() methods,
	* the location provider cancels the prior request and restarts the updates with the specified parameter.
	*
	* @since 2.0
	* @privlevel	public
	* @privilege %http://tizen.org/privilege/location
	*
	* @return	An error code
	* @param[in]	interval	The update interval in seconds
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_INVALID_ARG	The specified @c interval is less than @c 1.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED	The user blocks an application from using the location information.
	* @see		StopLocationUpdates()
	*/
	result StartLocationUpdatesByInterval(int interval);

	/**
	* Requests the location updates service with the specific @c distance filter. @n
	* Once the location updates have started, the initial location is delivered soon after it becomes available to the listener
	* by calling the ILocationProviderListener::OnLocationUpdated() method. @n Then the location provider updates subsequent locations
	* when it changes over the specified @c distance. @n
	* The location updates can be paused by the location provider when the application is unable to point locations out to the user
	* for the moment. @n This is possible for the following situations:
	*  - The application is not running in foreground.
	*  - The screen is off.
	*
	* In this case, the location provider notifies the status @c LOC_SVC_STATUS_PAUSED to the listener. @n
	* It resumes the paused location updates when the application gets out of the situations. @n
	* To get the location updates all the time, the application should use the KeepLocationUpdateAwake() method. @n
	* Along with the service status, the accuracy level that the location provider is currently providing
	* is notified to the listener on changes by calling the ILocationProviderListener::OnLocationUpdateStatusChanged()
	* and ILocationProviderListener::OnAccuracyChanged() methods respectively. @n
	* If the location updates are already started by calling the StartLocationUpdatesByInterval() or StartLocationUpdatesByDistance() methods,
	* the location provider cancels the prior request and restarts the updates with the specified parameter.
	*
	* @since 2.0
	* @privlevel	public
	* @privilege %http://tizen.org/privilege/location
	*
	* @return	An error code
	* @param[in]	distance	The distance in meters
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_INVALID_ARG	The specified @c distance is less than or equal to @c 0.0 or @c NaN.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED	The user blocks an application from using the location information.
	* @see		StopLocationUpdates()
	*/
	result StartLocationUpdatesByDistance(double distance);

	/**
	* Stops the location updates.
	*
	* @since 2.0
	*
	* @return	An error code
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_INVALID_OPERATION	The location updates has not been requested.
	* @see		StartLocationUpdatesByInterval()
	* @see		StartLocationUpdatesByDistance()
	*/
	result StopLocationUpdates(void);

	/**
	* Keeps the location updates awake or not. @n
	* The location provider can pause the ongoing location updates when the application is unable to point locations out to the user
	* for the moment. @n This is possible for the following situations:
	*  - The application is not running in foreground.
	*  - The screen is off.
	*
	* To get the location updates all the time, the application should use the StartLocationUpdatesByInterval() or
	* StartLocationUpdatesByDistance() methods together with the %KeepLocationUpdateAwake() method turning the flag @c enable on. @n
	* The application should be cautious about doing so since it can make the system awake
	* during the location updates.
	*
	* @since 2.0
	* @privlevel	public
	* @privilege %http://tizen.org/privilege/location and %http://tizen.org/privilege/power @n
	*				Both privileges are required.
	*
	* @return	An error code
	* @param[in]	enable	Set to @c true to keep the location updates awake, @n
	*							else @c false
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED	The user blocks an application from using the location information. @b Since: @b 2.1
	* @see		StartLocationUpdatesByInterval()
	* @see		StartLocationUpdatesByDistance()
	* @see		StopLocationUpdates()
	*/
	result KeepLocationUpdateAwake(bool enable);

	/**
	* Adds a region for monitoring. @n
	* A region is defined by a center point and a radius. @n
	* The location provider starts the region monitoring service until all regions are removed. When it detects a movement that crosses the
	* boundary of a registered region, it notifies the application by calling ILocationProviderListener::OnRegionEntered() or
	* ILocationProviderListener::OnRegionLeft() with the region identifier that is returned by the %AddMonitoringRegion() method. @n
	* The altitude of @c regionCenter is not considered in monitoring. @n
	* Along with the service status, the accuracy level that the location provider is currently providing
	* is notified to the listener on changes by calling the ILocationProviderListener::OnRegionMonitoringStatusChanged()
	* and ILocationProviderListener::OnAccuracyChanged() methods respectively. @n
	* Note that, the monitoring service can sometimes makes the system awake by running costly positioning devices.
	*
	* @since 2.0
	* @privlevel	public
	* @privilege %http://tizen.org/privilege/location and %http://tizen.org/privilege/power @n
	*				Both privileges are required.
	*
	* @return	An error code
	* @param[in]	regionCenter	The center coordinate of the region
	* @param[in]	radius	The monitoring radius in meters
	* @param[out]	regionId	The ID for the registered region
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_INVALID_ARG	The @c radius is not in the supported monitoring radius range, which currently is [50, 100000] meters, @n
	*								else the @c radius or the latitude or the longitude of @c regionCenter is @c NaN
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_USER_NOT_CONSENTED	The user blocks an application from using the location information.
	* @see		RemoveMonitoringRegion()
	* @see		RemoveAllMonitoringRegions()
	*/
	result AddMonitoringRegion(const Coordinates& regionCenter, double radius, RegionId& regionId);

	/**
	* Removes the monitoring region.
	*
	* @since 2.0
	*
	* @return	An error code
	* @param[in]	regionId	The region ID to remove
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_INVALID_ARG	The specified @c regionId is invalid.
	* @see		AddMonitoringRegion()
	*/
	result RemoveMonitoringRegion(RegionId regionId);

	/**
	* Removes all regions that the location provider monitors.
	*
	* @since 2.0
	*
	* @see		AddMonitoringRegion()
	*/
	void RemoveAllMonitoringRegions(void);

	/**
	* Gets the current service status of the location updates. @n
	* The location updates service is started by calling the StartLocationUpdatesByInterval() or StartLocationUpdatesByDistance()
	* method. If an application has not made valid requests for the service, the %GetLocationUpdateStatus() method returns @c LOC_SVC_STATUS_IDLE. @n
	* Otherwise, it returns the service status notified last by the ILocationProviderListener::OnLocationUpdateStatusChanged() listener method.
	*
	* @since 2.0
	* @return	The current service status of the location updates
	*/
	LocationServiceStatus GetLocationUpdateStatus(void) const;

	/**
	* Gets the current service status of the region monitoring. @n
	* The region monitoring service is started by calling the AddMonitoringRegion() method. @n
	* If an application has not made valid requests for the service, the %GetRegionMonitoringStatus() method returns @c LOC_SVC_STATUS_IDLE. @n
	* Otherwise, it returns the service status notified last by the ILocationProviderListener::OnRegionMonitoringStatusChanged() listener method.
	*
	* @since 2.0
	* @return	The current status of the region monitoring service
	*/
	LocationServiceStatus GetRegionMonitoringStatus(void) const;

	/**
	* Gets the accuracy level that the location provider is currently providing. @n
	* If an application has not made valid requests for location updates and region monitoring, the %GetCurrentAccuracy() method
	* returns @c LOC_ACCURACY_INVALID. @n
	* Otherwise, it returns the accuracy level last notified by the ILocationProviderListener::OnAccuracyChanged() listener method.
	*
	* @since 2.0
	* @return	The current location accuracy
	*/
	LocationAccuracy GetCurrentAccuracy(void) const;

	/**
	* Gets a current location. @n
	* An application can simply get the current location with the %GetLocation() method. @n
	* The location provider runs and waits for positioning systems to fix the current location as requested in the criteria. @n
	* If it is not fixed in some time, this method call is aborted and returns a location in low-grade accuracy or even
	* an invalid location with an @c E_LOCATION_UNAVAILABLE error.
	*
	* @since 2.0
	* @privlevel	public
	* @privilege %http://tizen.org/privilege/location
	*
	* @feature	%http://tizen.org/feature/location
	* @return	The current location
	* @param[in]	criteria	The desired location criteria
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_LOCATION_UNAVAILABLE	The location provider fails to fix the current location.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature.  @b Since: @b 2.1
	* 										For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_USER_NOT_CONSENTED	The user blocks an application from using the location information.
	* @exception	E_SYSTEM	A system error has occurred.
	* @remarks	
	*			- This method call takes time as the location provider runs and waits for positioning system.
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- Before calling this method, check whether the feature is supported by 
	*			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	*/
	static Location GetLocation(const LocationCriteria& criteria);

	/**
	* Gets the last known location. @n
	* The %GetLastKnownLocation() method returns the last location the system keeps. @n
	* It is always a good idea to prefer using this method than requesting current locations
	* since using the last location preserves the location provider from running costly positioning systems.
	*
	* @since 2.0
	* @privlevel	public
	* @privilege %http://tizen.org/privilege/location
	*
	* @feature	%http://tizen.org/feature/location
	* @return	The last location
	* @exception	E_SUCCESS	The method is successful.
	* @exception    E_LOCATION_UNAVAILABLE  The last location is unavailable.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature.  @b Since: @b 2.1
	* 										For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_USER_NOT_CONSENTED	The user blocks an application from using the location information.
	* @remarks     
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- Before calling this method, check whether the feature is supported by 
	*			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	*/
	static Location GetLastKnownLocation(void);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	LocationProvider(const LocationProvider& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	LocationProvider& operator =(const LocationProvider& rhs);

private:
	class _LocationProviderImpl* __pImpl;
	friend class _LocationProviderImpl;
}; //LocationProvider
}} // Tizen::Locations
#endif // _FLOC_LOCATION_PROVIDER_H_
