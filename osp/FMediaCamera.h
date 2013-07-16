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
 * @file			FMediaCamera.h
 * @brief			This is the header file for the %Camera class.
 *
 * This header file contains the declarations of the %Camera class.
 */

#ifndef _FMEDIA_CAMERA_H_
#define _FMEDIA_CAMERA_H_

#include <FBase.h>
#include <FGraphics.h>
#include <FMediaCameraTypes.h>
#include <FMediaICameraEventListener.h>

namespace Tizen { namespace Media
{

class IVideoStreamFilter;
class _CameraImpl;

/**
 * @class	Camera
 * @brief	This class controls the camera device.
 *
 * @since		2.0
 *
 *
 * The %Camera class controls the camera device.
 * The supported properties are device-dependent. The list of the properties available can be retrieved using the methods of %Camera and MediaCapability classes.
 * All the other methods, except SetAutoFocus(), StartPreview(), and Capture() work synchronously.
 * The previewed or captured data are passed through ICameraEventListener. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/capturing_still_images.htm">Capturing Still Images</a>.
 *
 * The following example demonstrates how to use the %Camera class.
 *
 * @code
 * #include <FBase.h>
 * #include <FGraphics.h>
 * #include <FUi.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Graphics;
 * using namespace Tizen::Ui;
 * using namespace Tizen::Ui::Controls;
 * using namespace Tizen::Media;
 *
 * class CameraSample
 *     : public Tizen::Ui::Controls::Form
 *     , public Tizen::Media::ICameraEventListener
 * {
 * public:
 *     CameraSample(void);
 *     result Start(void);
 *     void Stop(void);
 *
 * protected:
 *     virtual void OnCameraAutoFocused(bool completeCondition) {}
 *     virtual void OnCameraPreviewed( Tizen::Base::ByteBuffer& previewedData, result r) {}
 *     virtual void OnCameraCaptured( Tizen::Base::ByteBuffer& capturedData, result r) {}
 *     virtual void OnCameraErrorOccurred(CameraErrorReason r ) {}
 *
 * private:
 *     Camera __camera;
 *     OverlayRegion * __pOverlay;
 * };
 *
 * CameraSample::CameraSample(void)
 * {
 *     __pOverlay = null;
 * }
 *
 * result
 * CameraSample::Start(void)
 * {
 *     result r = E_SUCCESS;
 *     Rectangle rect(0, 0, 320, 240);
 *     bool modified = false;
 *     bool isValid = false;
 *     BufferInfo bufferInfo;
 *
 *     r = __camera.Construct(*this, CAMERA_PRIMARY);
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     r = __camera.PowerOn();
 *     if (IsFailed(r))
 *     {
 *         return r;
 *     }
 *
 *     isValid = OverlayRegion::EvaluateBounds(OVERLAY_REGION_EVALUATION_OPTION_LESS_THAN, rect, modified);
 *     if (isValid != true)
 *     {
 *         return GetLastResult();
 *     }
 *
 *     // Gets OverlayRegion from this Form
 *     __pOverlay = GetOverlayRegionN(rect, OVERLAY_REGION_TYPE_PRIMARY_CAMERA);
 *     if (__pOverlay == null)
 *     {
 *         return GetLastResult();
 *     }
 *
 *     __pOverlay->GetBackgroundBufferInfo(bufferInfo);
 *
 *     r = __camera.StartPreview(&bufferInfo, true);
 *     if (IsFailed(r))
 *     {
 *         goto CATCH;
 *     }
 *
 *     return E_SUCCESS;
 * CATCH:
 *     if (__pOverlay)
 *     {
 *         delete __pOverlay;
 *         __pOverlay = null;
 *     }
 *     return r;
 *  }
 *
 * void
 * CameraSample::Stop(void)
 * {
 *     __camera.StopPreview();
 *     __camera.PowerOff();
 *     if (__pOverlay)
 *     {
 *         delete __pOverlay;
 *         __pOverlay = null;
 *     }
 * }
 *
 * @endcode
 *
 *
 */
class _OSP_EXPORT_ Camera
	: public Tizen::Base::Object
{
public:
	/**
	* This is the default constructor for this class. @n
	* The object is not fully constructed after this constructor is called. @n 
	* For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since		2.0
	*/
	Camera(void);

	/**
	* This is the destructor for this class. @n
	* All allocated resources are deallocated by this method. This method must be called in the same thread
	* where the Construct() method is called.@n This polymorphic destructor should be overridden if required.
	* This way, the destructors of the derived classes are called when the destructor of this interface is called.
	*
	* @since		2.0
	*
	*/
	virtual ~Camera(void);

	/**
	* Initializes this instance of %Camera with the specified parameters. @n
	* The %Construct() method creates an instance of %Camera in the subsystem. Only one instance is created at a given time.
	*
	* @since		2.0
	*
	* @feature           %http://tizen.org/feature/camera.back or %http://tizen.org/feature/camera.front
	* @return		An error code
	* @param[in]	listener				An instance of ICameraEventListener
	* @param[in]	camSel					The %Camera to power on
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_DEVICE_BUSY			The camera is under use by other application or already used in this application.
	* @exception	E_DEVICE_UNAVAILABLE	The camera is unavailable.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	* @remarks 	Before calling this method, check whether the feature is supported by MediaCapability::GetValue(const Tizen::Base::String& key, int& value) 
	*			with ::CAMERA_COUNT key.
	*/
	result Construct(ICameraEventListener& listener, CameraSelection camSel = CAMERA_PRIMARY);

	/**
	* Powers the camera on.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY			The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE	The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED			The device operation has failed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @remarks 	Reserved configurations are set in this method.
	* @see			PowerOff()
	*/
	result PowerOn(void);

	/**
	* Powers the camera off.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY			The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE	The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED			The device operation has failed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @see			PowerOn()
	*/
	result PowerOff(void);

	/**
	* Checks whether the camera is powered on.
	*
	* @since		2.0
	*
	* @return		@c true if the camera is powered on, @n
	*				else @c false
	* @see			PowerOn()
	* @see			PowerOff()
	*/
	bool IsPoweredOn(void) const;

	/**
	* Starts displaying the preview image on the camera device. @n
	* If the value of @c pBufferInfo is @c null, no preview image is displayed. In this case, the application can
	* draw the preview image with the data passed on by the ICameraEventListener::OnCameraPreviewed() method.
	*
	* If the value of @c previewedData is @c true, the previewed image data is passed to the
	* ICameraEventListener::OnCameraPreviewed() method periodically based on the frame-rate, otherwise the
	* callback is not invoked. The default value of @c previewedData is @c false.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	pBufferInfo				The buffer information for the camera preview display
	* @param[in]	previewedData			Set to @c true if the previewed data is delivered to the callback method, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_UNSUPPORTED_FORMAT	The specified format is not supported.
	* @exception	E_DEVICE_BUSY			The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE	The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED			The device operation has failed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @remarks
	*			- The overlay region retrieved by the buffer information must be the topmost window when this method is called.
	*			- The ICameraEventListener::OnCameraPreviewed() method can be delayed or dropped depending on
	*			the system's performance.
	*			- For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm
	">here</a>.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValue(const Tizen::Base::String& key, bool& value)
	*			with ::CAMERA_PRIMARY_SUPPORT_PREVIEW or ::CAMERA_SECONDARY_SUPPORT_PREVIEW keys.
	* @see		StopPreview()
    	* @see		ICameraEventListener::OnCameraPreviewed()
	*/
	result StartPreview(const Tizen::Graphics::BufferInfo* pBufferInfo, bool previewedData = false);

	/**
	* Stops displaying the preview image on the camera device.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY			The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE	The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED			The device operation has failed.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @remarks	For more information on the relationship between this method and the PowerOn() method, and the
	*               		state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm
	">here</a>.
	* @see			StartPreview()
	*/
	result StopPreview(void);

	/**
	* Captures the current image data from the camera sensor. @n
	* After capturing the image, the camera's state changes to ::CAMERA_STATE_CAPTURED. @n
	* The camera's preview must be restarted by calling the StartPreview() method. @n
	* In a zero-shutter-lag camera, after capturing the image, the state changes to ::CAMERA_STATE_PREVIEW. @n
	* The camera does not need to restart the preview in this case. @n
	* The captured image is passed through ICameraEventListener::OnCameraCaptured().
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm
	">here</a>.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValue(const Tizen::Base::String& key, bool& value)
	*			with ::CAMERA_PRIMARY_SUPPORT_CAPTURE or ::CAMERA_SECONDARY_SUPPORT_CAPTURE keys.
	*			-In a zero-shutter-lag camera, the state changes to ::CAMERA_STATE_PREVIEW after capturing.
	*			-The zero-shutter-lag capability can be checked using MediaCapability::GetValue(const Tizen::Base::String& key, bool& value) with
	*			::CAMERA_PRIMARY_SUPPORT_ZERO_SHUTTER_LAG, ::CAMERA_SECONDARY_SUPPORT_ZERO_SHUTTER_LAG keys.
	* @see			ICameraEventListener::OnCameraCaptured()
	*/
	result Capture(void);

	/**
	* Gets the state of the camera in CameraState.
	*
	* @since		2.0
	*
	* @return	    The current state of the camera
        * @see	        StopPreview()
        * @see	        SetAutoFocus()
        * @see	        Capture()
	*/
	CameraState GetState(void) const;

	/**
	* Sets the brightness level of the camera input data.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	brightness					The brightness level to set @n
	*											The range of this parameter is from @c 0 to @c 9.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_RANGE				The specified @c brightness is out of range.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- The default brightness level is @c 5.
	*			- The device's supported range for the brightness level is from @c 0 to @c 9.
	*			- This method works correctly when PowerOn() is executed. @n
	*			 For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm">here</a>.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValue(const Tizen::Base::String& key, bool& value)
	*			with ::CAMERA_PRIMARY_SUPPORT_BRIGHTNESS or ::CAMERA_SECONDARY_SUPPORT_BRIGHTNESS keys.
	* @see			GetBrightness()
	*/
	result SetBrightness(int brightness);

	/**
	* Gets the brightness level of the camera input data.
	*
	* @since		2.0
	*
	* @return		The current brightness level @n
	*			The returned value ranges from @c 0 to @c 9.
	* @remarks	The device's supported range for the brightness level is from @c 0 to @c 9.
	* @see		SetBrightness()
	*/
	int GetBrightness(void) const;

	/**
	* Sets the contrast level of the %Camera input data.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return	    An error code
	* @param[in]	contrast					The contrast level to set @n
	*											The range of this parameter is from @c 0 to @c 9.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_RANGE				The specified contrast is out of range.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- The default contrast level is @c 5.
	*			- The device's supported range for the contrast level is from @c 0 to @c 9.
	*			- This method works correctly when PowerOn() is executed. @n
	*			For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm">here</a>.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValue(const Tizen::Base::String& key, bool& value)
	*			with ::CAMERA_PRIMARY_SUPPORT_CONTRAST or ::CAMERA_SECONDARY_SUPPORT_CONTRAST keys.
	* @see			GetContrast()
	*/
	result SetContrast(int contrast);

	/**
	* Gets the contrast level of the camera input data.
	*
	* @since		2.0
	*
	* @return		The current contrast level @n
	*				The returned value ranges from @c 0 to @c 9.
	* @remarks		The device's supported range for the contrast level is from @c 0 to @c 9.
	* @see			SetContrast()
	*/
	int GetContrast(void) const;

	/**
	* Zooms in the camera.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- This method returns @c E_UNSUPPORTED_OPERATION in the Emulator.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValue(const Tizen::Base::String& key, bool& value)
	*			with ::CAMERA_PRIMARY_SUPPORT_ZOOM or ::CAMERA_SECONDARY_SUPPORT_ZOOM keys.
	*			- If Camera supports only ::CAMERA_ZOOM_TYPE_SMART, the zoom ratio can differ according
	*			to the preview, capture, and recording resolutions.
	*			- The supported zoom types can be obtained by using the
	*			MediaCapability::GetValueN(CAMERA_PRIMARY_ZOOM_TYPE) method.
	*			- For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm">here</a>.
	* @see			ZoomOut()
	* @see          GetZoomLevel()
	* @see          GetMaxZoomLevel()
	*/
	result ZoomIn(void);

	/**
	* Zooms out the camera.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- This method returns @c E_UNSUPPORTED_OPERATION in the Emulator.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValue(const Tizen::Base::String& key, bool& value)
	*			with ::CAMERA_PRIMARY_SUPPORT_ZOOM or ::CAMERA_SECONDARY_SUPPORT_ZOOM keys.
	*			- If CameraZoomType supports only ::CAMERA_ZOOM_TYPE_SMART, zoom ratio can differ according to
	*			the preview, capture, and recording resolutions.
	*			- The supported zoom types can be obtained by using the
	*			MediaCapability::GetValueN(CAMERA_PRIMARY_ZOOM_TYPE) method.
	*			- For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm">here</a>.
	* @see			ZoomIn()
	* @see          GetZoomLevel()
	* @see          GetMaxZoomLevel()
	*/
	result ZoomOut(void);

	/**
	* Gets the zoom level of the camera.
	*
	* @since		2.0
	*
	* @return		The current zoom level
	* @remarks		The zoom level is different for each camera device.
	* @see			ZoomIn()
        * @see     	    ZoomOut()
	* @see          GetMaxZoomLevel()
	*/
	int GetZoomLevel(void) const;

	/**
	* Gets the maximum zoom level supported by this %Camera.
	*
	* @since		2.0
	*
	* @return	The maximum zoom level
	* @remarks	The zoom level is different for each camera device.
	* @see		ZoomIn()
        * @see       	ZoomOut()
        * @see	        GetZoomLevel()
	*/
	int GetMaxZoomLevel(void) const;

	/**
	* Sets the current resolution of the preview.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	resolution                  The preview resolution @n
	*							                It must be one of the listed dimensions that are extracted using GetSupportedPreviewResolutionListN().
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_RANGE				The position or size is out of range.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- This method works in the ::CAMERA_STATE_INITIALIZED state. @n@n
	*			- For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm
	">here</a>.
	* @see			GetPreviewResolution()
	*/
	result SetPreviewResolution(const Tizen::Graphics::Dimension& resolution);

	/**
	* Gets the current resolution of the preview.
	*
	* @since		2.0
	*
	* @return		The current preview resolution
	* @see			SetPreviewResolution()
	*/
	Tizen::Graphics::Dimension GetPreviewResolution(void) const;

	/**
	* Gets the supported preview resolution list of the %Camera class. @n
	* Each item in the returned list contains a pointer of Tizen::Graphics::Dimension value.
	*
	* @since		2.0
	*
	* @return       A list of dimensions that represent the preview resolutions supported by the %Camera class, @n
	*				else @c null if no preview resolution is supported or an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- The return value and each item in the list must be deleted by the caller.
	* @see			SetPreviewResolution()
        * @see	        GetPreviewResolution()
	*/
	Tizen::Base::Collection::IList* GetSupportedPreviewResolutionListN(void) const;


	/**
	* Sets the capturing resolution of the camera. @n
	* Initially, the default resolution is set using the internal configuration.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	resolution					The display resolution @n
	*							                The display resolution must be one of the values extracted using GetSupportedCaptureResolutionListN().
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception	E_OUT_OF_RANGE				The specified resolution is out of range.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm
	">here</a>.
	*			- In a zero-shutter-lag camera, the default preview format applies this feature correctly. The other preview formats are not guaranteed.
	*			- The zero-shutter-lag capability can be checked using MediaCapability::GetValue(const Tizen::Base::String& key, bool& value) with
	*			::CAMERA_PRIMARY_SUPPORT_ZERO_SHUTTER_LAG, ::CAMERA_SECONDARY_SUPPORT_ZERO_SHUTTER_LAG keys.
	* @see			GetCaptureResolution()
	*/
	result SetCaptureResolution(const Tizen::Graphics::Dimension& resolution);

	/**
	* Gets the resolution for capturing the data of the camera.
	*
	* @since		2.0
	*
	* @return		The current resolution for capturing the data of the camera
	* @see			SetCaptureResolution()
	* @see          GetSupportedCaptureResolutionListN()
	*/
	Tizen::Graphics::Dimension GetCaptureResolution(void) const;

	/**
	* Gets a list of the capturing resolutions supported by the %Camera class. @n
	* Each item of the list has a pointer of the Tizen::Graphics::Dimension value.
	*
	* @since		2.0
	*
	* @return		A list of the capture resolutions supported by the %Camera class @n
	*				else @c null if no capture resolution is supported or an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- The return value and each item in the list must be deleted by the caller.
	* @see			SetCaptureResolution()
        * @see	        GetCaptureResolution()
	*/
	Tizen::Base::Collection::IList* GetSupportedCaptureResolutionListN(void) const;

	/**
	* Sets the effect for the input data of the camera.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	effect						The effect for the input data of the camera
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_INVALID_ARG				The specified input parameter is invalid.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_UNSUPPORTED_TYPE          The specified @c effect is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- The default effect is @c CAMERA_EFFECT_NONE.
	*			- This method returns @c E_UNSUPPORTED_OPERATION in the Emulator.
	*			- This method works correctly when PowerOn() is executed. @n
	*			For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm
	">here</a>.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValueN(const Tizen::Base::String& key)
	*			with @c CAMERA_PRIMARY_EFFECT or @c CAMERA_SECONDARY_EFFECT keys.
	* @see			GetEffect()
	*/
	result SetEffect(CameraEffect effect);

	/**
	* Gets the effect for the input data of the camera.
	*
	* @since		2.0
	*
	* @return		The effect for the input data of the camera
	* @see			SetEffect()
	*/
	CameraEffect GetEffect(void) const;

	/**
	* @{
	* @if OSPDEPREC
	* Sets the camera's flash.
	*
	* @brief <i> [Deprecated]  </i>
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the SetFlashMode() method.
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera.back.flash or %http://tizen.org/feature/camera.front.flash
	*
	* @return		An error code
	* @param[in]	flashOn						Set to @c true to switch on the flash light, @n
	*											else @c false
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			-The flash is switched on when the camera captures a picture. If the value of @c flashOn is
	*			set to @c true,	this method returns @c E_UNSUPPORTED_OPERATION in the Emulator. @n
	*			SetFlash(true) works same as SetFlashMode(CAMERA_FLASH_MODE_ON) and SetFlash(false) works same as SetFlashMode(CAMERA_FLASH_MODE_OFF).
	*			- For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm">here</a>.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValue(const Tizen::Base::String& key, bool& value)
	*			with ::CAMERA_PRIMARY_SUPPORT_FLASH or ::CAMERA_SECONDARY_SUPPORT_FLASH keys.
	* 			-In a zero-shutter-lag camera, only the default preview format applies this feature.
	* @see			IsFlashOn()
        * @see	        SetFlashMode()
        * @see	        CameraFlashMode
	*
	* @endif
	* @}
	*/
	result SetFlash(bool flashOn)
	{
		CameraFlashMode flashMode = CAMERA_FLASH_MODE_ON;
		if (!flashOn)
		{
			flashMode = CAMERA_FLASH_MODE_OFF;
		}
		return SetFlashMode(flashMode);
	}

	/**
	* @if OSPDEPREC
	* Checks whether the camera's flash is switched on.
	*
	* @brief <i> [Deprecated]  </i>
	* @deprecated	This method is deprecated. @n
	* Instead of using this method, use the GetFlashMode() method.
	* @since		2.0
	*
	* @return		@c true if the flash light is on, @n
	*				else @c false
	* @remarks		This method works same as return (GetFlashMode()!=CAMERA_FLASH_MODE_OFF).
	* @see			SetFlash()
        * @see	        GetFlashMode()
        * @see	        CameraFlashMode
	* @endif
	*/
	bool IsFlashOn(void) const
	{
		return (GetFlashMode() != CAMERA_FLASH_MODE_OFF);
	}

	/**
	* Sets the camera's flash mode.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera.back.flash or %http://tizen.org/feature/camera.front.flash
	*
	* @return		An error code
	* @param[in]	flashMode					flash mode to switch on the flash light.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_INVALID_ARG				The specified flash mode is invalid.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_UNSUPPORTED_TYPE          The specified @c flashMode is not supported.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- Normally the flash splashes before the camera captures a picture. @n
	*			@c CAMERA_FLASH_MODE_CONTINUOUS keeps the flash turned on after the method is called until @c CAMERA_FLASH_MODE_OFF is set.
	*			- This method returns @c E_UNSUPPORTED_OPERATION in the Emulator.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValueN(const Tizen::Base::String& key)
	*			with @c CAMERA_PRIMARY_FLASH_MODE or @c CAMERA_SECONDARY_FLASH_MODE keys.
	*			- In a zero-shutter-lag camera, the default preview format applies this feature correctly. The other preview formats are not guaranteed.
	*			- The zero-shutter-lag capability can be checked using MediaCapability::GetValue(const Tizen::Base::String& key, bool& value) with
	*			::CAMERA_PRIMARY_SUPPORT_ZERO_SHUTTER_LAG, ::CAMERA_SECONDARY_SUPPORT_ZERO_SHUTTER_LAG keys.
	* @see			GetFlashMode()
	*/
	result SetFlashMode(CameraFlashMode flashMode);

	/**
	* Gets the flash mode of the camera.
	*
	* @since		2.0
	*
	* @return		The flash mode of the camera
	* @remarks		If the %Camera doesn't support the flash mode, this method always returns @c CAMERA_FLASH_MODE_OFF.
	* @see			SetFlashMode()
	*/
	CameraFlashMode GetFlashMode(void) const;

	/**
	* Sets the exposure level of the camera.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	exposure					The camera exposure level @n
	*											The range of this parameter is from @c 0 to @c 9.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_RANGE				The specified exposure level is out of range.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- The default exposure level is @c 5.
	*			- The supported range for exposure level is from @c 0 to @c 9.
	*			- This method returns @c E_UNSUPPORTED_OPERATION in the Emulator.
	*			- This method works correctly when PowerOn() is executed. @n
	*			For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm">here</a>.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValue(const Tizen::Base::String& key, bool& value)
	*			with ::CAMERA_PRIMARY_SUPPORT_EXPOSURE or ::CAMERA_SECONDARY_SUPPORT_EXPOSURE keys.
	* @see			GetExposure()
	*/
	result SetExposure(int exposure);

	/**
	* Gets the exposure level of the camera.
	*
	* @since		2.0
	*
	* @return		An integer value representing the exposure level of the camera @n
	*				The returned value ranges from @c 0 to @c 9.
	* @remarks		The supported range for exposure level is from @c 0 to @c 9.
	* @see			SetExposure()
	*/
	int GetExposure(void) const;

	/**
	* Sets the white balance level of the camera.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	whiteBalance				The camera white balance level
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_INVALID_ARG				The specified input parameter is invalid.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_UNSUPPORTED_TYPE          The specified @c whiteBalance is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- The default white balance is @c CAMERA_WHITE_BALANCE_AUTO.
	*			- This method returns @c E_UNSUPPORTED_OPERATION in the Emulator.
	*			- This method works correctly when PowerOn() is executed. @n
	*			For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm">here</a>.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValueN(const Tizen::Base::String& key)
	*			with @c CAMERA_PRIMARY_WHITE_BALANCE or @c CAMERA_SECONDARY_WHITE_BALANCE keys.
	* @see			GetWhiteBalance()
	*/
	result SetWhiteBalance(CameraWhiteBalance whiteBalance);

	/**
	* Gets the white balance level of the camera.
	*
	* @since		2.0
	*
	* @return		The white balance level of the camera
	* @see			SetWhiteBalance()
	*/
	CameraWhiteBalance GetWhiteBalance(void) const;

	/**
	* Sets the capturing quality of the camera.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	quality						The camera's quality level
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_INVALID_ARG				The specified @c quality is not supported.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- The default quality is @c CAMERA_QUALITY_NORMAL.
	*			- This method works correctly when PowerOn() is executed. @n
	*			For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm">here</a>.
	* @see			GetQuality()
	*/
	result SetQuality(CameraQuality quality);

	/**
	* Gets the capturing quality of the camera.
	*
	* @since		2.0
	*
	* @return		The %Camera quality level
	* @see			SetQuality()
	*/
	CameraQuality GetQuality(void) const;

	/**
	* Sets the focus mode of the camera.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	focusMode				focus mode
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_INVALID_ARG				The specified focus mode is invalid.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_UNSUPPORTED_TYPE		  The specified @c focusMode is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- @c CAMERA_FOCUS_MODE_NONE always throws @c E_INVALID_ARG.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValueN(const Tizen::Base::String& key)
	*			with @c CAMERA_PRIMARY_FOCUS_MODE or @c CAMERA_SECONDARY_FOCUS_MODE keys.
	*
	* @see		GetFocusMode()
	*/
	result SetFocusMode(CameraFocusMode focusMode);

	/**
	* Gets the focus mode of the camera.
	*
	* @since		2.0
	*
	* @return		The %Camera focus mode
	* @remarks	If the %Camera does not support the focus mode, this method always returns @c CAMERA_FOCUS_MODE_NONE.
	* @see		SetFocusMode()
	*/
	CameraFocusMode GetFocusMode(void) const;

	/**
	* Sets the auto focus point list.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	pointList				The auto focus point list which consists of Tizen::Graphics::Point pointers
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_INVALID_ARG				The specified input parameter is invalid.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_UNSUPPORTED_TYPE			This method is not supported for the current focus mode.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- This method works fine when the current focus mode is ::CAMERA_FOCUS_MODE_NORMAL or ::CAMERA_FOCUS_MODE_MACRO.
	* 			- If the input parameter has a empty list, the focus area is changed to the center.
	* @see		GetAutoFocusPointN()
	*/
	result SetAutoFocusPoint(const Tizen::Base::Collection::IList& pointList);

	/**
	* Gets the auto focus point list. @n
	* Each item of the list has a pointer of the Tizen::Graphics::Point value.
	*
	* @since		2.0
	*
	* @return		The %Camera auto focus point list @n
	*               A list of points that represent the auto focus point, @n
	*				else @c null if no auto focus point is set or if an exception occurs.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @remarks
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- The return value and each item in the list must be deleted by the caller.
	* @see		SetAutoFocusPoint()
	*/
	Tizen::Base::Collection::IList* GetAutoFocusPointN(void) const;

	/**
	* Sets the auto focus mode of the camera.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	callback					Set to @c true to enable auto focus callback, @n
	*											else @c false
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- If @c callback is set to @c false, the ICameraEventListener::OnCameraAutoFocused() method is not called.
	*			- This method throws @c E_UNSUPPORTED_OPERATION in the emulator.
	*			- For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm">here</a>.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValue(const Tizen::Base::String& key, bool& value)
	*			with ::CAMERA_PRIMARY_SUPPORT_FOCUS or ::CAMERA_SECONDARY_SUPPORT_FOCUS keys.
	*/
	result SetAutoFocus(bool callback);

	/**
	* Sets the capturing format of the camera. @n
	* Initially, the default format is set using the internal configuration.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege	%http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	format						The camera's capture format @n
	*											It must be one of the pixel formats extracted using GetSupportedCaptureFormatListN().
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception	E_UNSUPPORTED_FORMAT		The specified format is not supported.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks		This method works correctly when PowerOn() is executed.
	* @see			GetCaptureFormat()
	*/
	result SetCaptureFormat(const Tizen::Graphics::PixelFormat format);

	/**
	* Gets the capturing format of the camera.
	*
	* @since		2.0
	*
	* @return		The capturing format of the camera
	* @see			SetCaptureFormat()
        * @see	        GetSupportedCaptureFormatListN()
	*/
	Tizen::Graphics::PixelFormat GetCaptureFormat(void) const;

	/**
	* Gets the supported capturing format list for the %Camera class. @n
	* Each list item has a Tizen::Graphics::PixelFormat value.
	*
	* @since		2.0
	*
	* @return		A list of the formats supported by the %Camera class, @n
	*				else @c null if no capture format is supported or an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- The return value must be deleted.
	* @see			SetCaptureFormat()
        * @see	        GetCaptureFormat()
	*/
	Tizen::Base::Collection::IListT <Tizen::Graphics::PixelFormat>* GetSupportedCaptureFormatListN(void) const;

	/**
	* Sets the preview format of the camera. @n
	* Initially, the default format is set using the internal configuration.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	format						The camera's preview format @n
	*											It must be one of the pixel formats extracted using GetSupportedPreviewFormatListN().
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_SYSTEM					A system error has occurred.
	* @exception	E_UNSUPPORTED_FORMAT		The specified format is not supported.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- This method works in ::CAMERA_STATE_INITIALIZED state.
	*			- For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm">here</a>.
	* @see			GetPreviewFormat()
        * @see	        GetSupportedPreviewFormatListN()
	*/
	result SetPreviewFormat(const Tizen::Graphics::PixelFormat format);

	/**
	* Gets the preview format of the camera.
	*
	* @since		2.0
	*
	* @return		The preview format of the camera
	* @see			SetPreviewFormat()
        * @see	        GetSupportedPreviewFormatListN()
	*/
	Tizen::Graphics::PixelFormat GetPreviewFormat(void) const;

	/**
	* Gets the supported preview format list for the %Camera class. @n
	* Each list item has a Tizen::Graphics::PixelFormat value.
	*
	* @since		2.0
	*
	* @return		A list of the preview format supported by the %Camera class, @n
	*				else @c null if no preview format is supported or an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- The return value must be deleted.
	* @see			SetPreviewFormat()
        * @see	        GetPreviewFormat()
	*/
	Tizen::Base::Collection::IListT <Tizen::Graphics::PixelFormat>* GetSupportedPreviewFormatListN(void) const;


	/**
	* Sets the ISO level of the camera.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	isoLevel					The camera's ISO level @n
	*											The default ISO level is set from the internal configuration.
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_RANGE				The specified ISO level is out of range.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_UNSUPPORTED_TYPE          The specified @c isoLevel is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- In some devices this method works in the ::CAMERA_STATE_PREVIEW state.
	*			- This method throws @c E_UNSUPPORTED_OPERATION in the Emulator.
	*			- For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm">here</a>.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValueN(const Tizen::Base::String& key)
	*			with @c CAMERA_PRIMARY_ISO_LEVEL or @c CAMERA_SECONDARY_ISO_LEVEL keys.
	* @see			GetIsoLevel()
	*/
	result SetIsoLevel(CameraIsoLevel isoLevel);

	/**
	* Gets the ISO level of the camera.
	*
	* @since		2.0
	*
	* @return		The ISO level of the camera
	* @see			SetIsoLevel()
	*/
	CameraIsoLevel GetIsoLevel(void) const;

	/**
	* Sets the preview frame rate of the camera. @n
	* Initially, the default frame rate is set using the internal configuration.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege	%http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	fps							The frame rate per second @n
	*											It must be one of the fps extracted using GetSupportedPreviewFrameRateListN().
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_RANGE				The specified @c fps is out of range on this device.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- This method works in ::CAMERA_STATE_INITIALIZED state.
	*			- For more information on the relationship between this method and the PowerOn() method, and the
	*			state transition caused by this method, see <a href="../org.tizen.native.appprogramming/html/guide/media/launching_camera.htm">here</a>.
	* @see			GetPreviewFrameRate()
	*/
	result SetPreviewFrameRate(int fps);

	/**
	* Gets the frame rate of the camera.
	*
	* @since		2.0
	*
	* @return		The frame rate of the camera @n
	*               		If the frame rate is not set using SetPreviewFrameRate(), the system-dependent default frame rate is returned.
	* @see			GetSupportedPreviewFrameRateListN()
	*/
	int GetPreviewFrameRate(void) const;

	/**
	* Gets the supported preview frame rate list for the %Camera class. @n
	* Each list item has an integer value.
	*
	* @since		2.0
	*
	* @return		A list of the preview frame rate supported by the %Camera class, @n
	*				else @c null if no frame rate is supported or an exception occurs
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- The return value must be deleted by the caller.
	*			- This method returns fps list that can be supported by all resolutions.
	* @see			SetPreviewFrameRate()
        * @see	        GetPreviewFrameRate()
        * @see	        FRAME_RATE_AUTO
	* @see			GetSupportedPreviewFrameRateListN(const Tizen::Graphics::Dimension& dim) const
	*/
	Tizen::Base::Collection::IListT <int>* GetSupportedPreviewFrameRateListN(void) const;

	/**
	* Gets the supported preview frame rate list of the input resolution of the %Camera class. @n
	* Each item of the list has an integer value.
	*
	* @since		2.0
	*
	* @return		A list of the preview frame rate of the input preview resolution, @n
	*				else @c null if no frame rate is supported or if an exception occurs
	* @param[in]	dim						The preview resolution of the camera
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified input resolution is invalid.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- The return value must be deleted by the caller.
	* @see			SetPreviewFrameRate()
        * @see	        GetPreviewFrameRate()
	* @see			GetSupportedPreviewFrameRateListN(void) const
	*/
	Tizen::Base::Collection::IListT <int>* GetSupportedPreviewFrameRateListN(const Tizen::Graphics::Dimension& dim) const;

	/**
	* Sets the orientation value in the Exchangeable Image File Format (EXIF) field of the captured data.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]    orientation					The orientation value to set in EXIF
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_RANGE				The input value is out of range.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks
	*			- The default value of orientation is @c CAMERA_EXIF_ORIENTATION_TOP_LEFT.
	*			- This method works correctly when PowerOn() is executed. The orientation value set by this method can be obtained using the
	*			Tizen::Content::ImageData::GetOrientation() method after writing the captured data to a file.
	*/
	result SetExifOrientation(CameraExifOrientation orientation);

	/**
	* Sets the GPS coordinates in the Exchangeable %Image File Format (EXIF) field for the captured data.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	latitude					The latitude value to set in EXIF @n
	*											The valid range is [-90.0, 90.0].
	* @param[in]	longitude					The longitude value to set in EXIF @n
	*											The valid range is [-180.0, 180.0]
	* @param[in]	altitude					The altitude value to set in EXIF
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_RANGE				The input value is out of range.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks
	*			- This method sets the GPS coordinates and enables entering the coordinates into the Exchangeable Image File Format (EXIF).
	*			-By default, the GPS coordinates are not entered in JPEG's EXIF.
	*			- The GPS coordinates that are set using this method are entered in every call to the
	*			Capture() method, until DisableExifGpsCoordinates() is called or this instance is destroyed.
	*			- This method works correctly when PowerOn() is executed.
	*			- The values set by this method can result in an error as compared to the values stored in the Exchangeable Image File Format (EXIF) field.
	*/
	result SetExifGpsCoordinates(double latitude, double longitude, float altitude);

	/**
	* Disables the insertion of the GPS coordinates in the Exchangeable %Image File Format (EXIF) field for the captured data.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_OUT_OF_RANGE				The input value is out of range.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_SYSTEM					A system error has occurred.
	* @see          SetExifGpsCoordinates()
	*/
	result DisableExifGpsCoordinates(void);

	/**
	* Sets the flip type for the previewed and captured data.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	flip						The camera flip type
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_INVALID_ARG				The input value is out of range.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_UNSUPPORTED_TYPE          The specified @c flip is not supported.
	* @exception	E_SYSTEM					A system error has occurred.
	* @remarks
	*			- This method works in the ::CAMERA_STATE_INITIALIZED state.
	*			- Finally the last specified type is applied even with the several types applicable.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValueN(const Tizen::Base::String& key)
	*			with @c CAMERA_PRIMARY_FLIP or @c CAMERA_SECONDARY_FLIP keys.
	*			- In a zero-shutter-lag camera, the default preview format is not guaranteed to apply this feature correctly.
	*			- The zero-shutter-lag capability can be checked using MediaCapability::GetValue(const Tizen::Base::String& key, bool& value) with
	*			::CAMERA_PRIMARY_SUPPORT_ZERO_SHUTTER_LAG, ::CAMERA_SECONDARY_SUPPORT_ZERO_SHUTTER_LAG keys.
	* @see          GetFlip()
	*/
	result SetFlip(CameraFlipType flip);

	/**
	* Gets the flip type for the previewed and captured data.
	*
	* @since		2.0
	*
	* @return		The camera flip type
	* @see      SetFlip()
	*/
	CameraFlipType GetFlip(void) const;

	/**
	* Sets the rotation for the previewed data.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return           An error code
	* @param[in] rotation                                      The camera rotation
	* @exception E_SUCCESS                               The method is successful.
	* @exception E_PRIVILEGE_DENIED         The application does not have the privilege to call this method.
	* @exception E_INVALID_STATE                         This instance is in an invalid state for this method.
	* @exception E_INVALID_ARG                    The input value is out of range.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception E_UNSUPPORTED_TYPE               The specified @c rotation is not supported.
	* @exception E_SYSTEM                                A system error has occurred.
	* @remarks
	*			- This method works in the ::CAMERA_STATE_INITIALIZED state.
	*			- The last specified type is applied even with the several types applicable.
	*			- This method rotates the preview and recording data but not the captured image. @n
	*			The captured image's orientation is always following the physical rotation.
	*			- When the preview is rotated, the preview callback data's width and height can be changed. @n
	*			Thus the application must recognize these changes when it uses the preview data in ICameraEventListener::OnCameraPreviewed() callback.
	*			- For the intended view of preview, Tizen::Ui::Controls::OverlayRegion::OVERLAY_REGION_TYPE_NORMAL must be selected when 
	*			Tizen::Ui::Controls::OverlayRegion is created.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValueN(const Tizen::Base::String& key)
	*			with @c CAMERA_PRIMARY_PREVIEW_ROTATION or @c CAMERA_SECONDARY_PREVIEW_ROTATION keys.
	*			- In a zero-shutter-lag camera, the default preview format is not guaranteed to apply this feature correctly.
	*			- The zero-shutter-lag capability can be checked using MediaCapability::GetValue(const Tizen::Base::String& key, bool& value) with
	*			::CAMERA_PRIMARY_SUPPORT_ZERO_SHUTTER_LAG, ::CAMERA_SECONDARY_SUPPORT_ZERO_SHUTTER_LAG keys.
	* @see                     GetPreviewRotation()
	*
	*/
	result SetPreviewRotation(CameraRotation rotation);

	/**
	*
	* Gets the rotation for the previewed data.
	*
	* @since		2.0
	*
	* @return           The camera rotation
	* @see              SetPreviewRotation()
	*
	*/
	CameraRotation GetPreviewRotation(void) const;

	/**
	* Sets the metering mode of the camera.
	*
	* @since		2.0
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	meteringMode				The metering mode
	* @exception	E_SUCCESS					The method is successful.
	* @exception	E_INVALID_STATE				This instance is in an invalid state for this method.
	* @exception	E_DEVICE_BUSY				The camera is under use by other application.
	* @exception	E_DEVICE_UNAVAILABLE		The camera becomes unavailable.
	* @exception	E_DEVICE_FAILED				The device operation has failed.
	* @exception	E_INVALID_ARG				The specified metering mode is invalid.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception	E_UNSUPPORTED_TYPE		  The specified @c meteringMode is not supported.
	* @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks
	*			- @c CAMERA_METERING_MODE_NONE always throws @c E_INVALID_ARG.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValueN(const Tizen::Base::String& key)
	*			with @c CAMERA_PRIMARY_METERING_MODE or @c CAMERA_SECONDARY_METERING_MODE keys.
	* @see		GetMeteringMode()
	*/
	result SetMeteringMode(CameraMeteringMode meteringMode);

	/**
	* Gets the metering mode of the camera.
	*
	* @since		2.0
	*
	* @return		The %Camera metering mode
	* @remarks	If the %Camera does not support the metering mode, this method always returns @c CAMERA_METERING_MODE_NONE.
	* @see		SetMeteringMode()
	*/
	CameraMeteringMode GetMeteringMode(void) const;

	/**
	* Sets the scene mode of the camera.
	*
	* @since		2.1
	* @privlevel        public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return             An error code
	* @param[in]       sceneMode                                                  The scene mode
	* @exception       E_SUCCESS                                                               The method is successful.
	* @exception       E_INVALID_STATE                                         This instance is in an invalid state for this method.
	* @exception       E_DEVICE_BUSY                                            The camera is under use by another application.
	* @exception       E_DEVICE_UNAVAILABLE                  The camera becomes unavailable.
	* @exception       E_DEVICE_FAILED                                         The device operation has failed.
	* @exception       E_INVALID_ARG                                            The specified @c sceneMode is invalid.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @exception       E_UNSUPPORTED_TYPE                      The specified @c sceneMode is not supported.
	* @exception       E_PRIVILEGE_DENIED                                    The application does not have the privilege to call this method.
	* @remarks
	*			- In a specific scene mode, camera's attributes such as brightness, metering mode, iso level, white balance, flash, and focus are changed 
	*			to the ones that are pre-defined by each scene mode.
	*			- In a specific scene mode, if an application sets any attribute that is related to the scene, the mode can be changed to @c CAMERA_SCENE_OFF. @n
	*			Thus, it is recommended that the application check the current scene mode after setting the attributes. @n
	*			In case that the scene mode is changed to @c CAMERA_SCENE_OFF, all the attributes set by the application are reloaded.
	*			- Before calling this method, check whether the feature is supported by MediaCapability::GetValueN(const Tizen::Base::String& key)
	*			with @c CAMERA_PRIMARY_SCENE_MODE or @c CAMERA_SECONDARY_SCENE_MODE keys.
	*/
	 result SetSceneMode(CameraSceneMode sceneMode);


	 /**
	 * Gets the scene mode of the camera.
	 *
	 * @since		2.1
	 *
	 * @return                         The %Camera scene mode
	 */
	 CameraSceneMode GetSceneMode(void) const;

	/**
	* Adds the stream filter to process the video stream data while previewing or recording.
	*
	* @since		2.1
	* @privlevel	public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	filter			An instance of IVideoStreamFilter
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OBJ_ALREADY_EXIST     The filter already exists.
	* @exception	E_OUT_OF_MEMORY	    The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @remarks 	IVideoStreamFilter::ProcessVideoStream() will be called when the video frame is ready.
	*/
	result AddVideoStreamFilter(Tizen::Media::IVideoStreamFilter& filter);

	/**
	* Removes the stream filter to stop receiving the video stream data.
	*
	* @since		2.1
	* @privlevel	public
	* @privilege    %http://tizen.org/privilege/camera
	* @feature           %http://tizen.org/feature/camera
	*
	* @return		An error code
	* @param[in]	filter			An instance of IVideoStreamFilter
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OBJ_NOT_FOUND        The filter is not found.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. @n
	* For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	*/
	result RemoveVideoStreamFilter(Tizen::Media::IVideoStreamFilter& filter);

	/**
	 * This value can be used to set the preview frame rate by using the SetPreviewFrameRate() method. @n
	 * If the preview frame rate is set using this value, the frame rate during the preview is automatically adjusted as per the light condition.
	 *
	 * @since		2.0
	 */
	static const int FRAME_RATE_AUTO = 0xFFFFFFFF;

private:
	/**
	* This is the copy constructor for this class.
	*
	* @since		2.0
	*
	* @remarks		The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	* @see			Construct()
	*/
	Camera(const Camera& rhs);

	/**
	* This is the copy assignment operator for this class.
	*
	* @since		2.0
	*
	* @remarks		The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*
	*/
	Camera& operator =(const Camera& rhs);

	friend class _CameraImpl;
	_CameraImpl* __pImpl;

};

}}// Tizen::Media

#endif
