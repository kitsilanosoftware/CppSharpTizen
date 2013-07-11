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
 * @file			FMediaICameraEventListener.h
 * @brief			This is the header file for the %ICameraEventListener interface.
 *
 * This header file contains the declarations of the %ICameraEventListener interface.
 */

#ifndef _FMEDIA_ICAMERA_EVENT_LISTENER_H_
#define _FMEDIA_ICAMERA_EVENT_LISTENER_H_

#include <FBase.h>
#include <FMediaCameraTypes.h>

namespace Tizen { namespace Media
{

/**
 * @interface	ICameraEventListener
 * @brief		This interface provides a listener that receives events associated with the Camera class.
 *
 * @since		2.0
 *
 * The %ICameraEventListener interface specifies the methods used to notify the status of the camera and camera events.
 * The camera engine works asynchronously. Therefore, it is important to implement this listener
 * to ensure smooth performance of the camera.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/media/capturing_still_images.htm">Capturing Still Images</a>.
 */
class _OSP_EXPORT_ ICameraEventListener
	: virtual public Tizen::Base::Runtime::IEventListener
{

public:
	/**
	* This is the destructor for this class.
	*
	* @since		2.0
	*/
	virtual ~ICameraEventListener(void) {}

	/**
	* Called when the Camera::SetAutoFocus() method is completed.
	*
	* @since		2.0
	*
	* @param[in]	 completeCondition   The condition of auto focus completion @n
	*										  Set to @c true if it succeeds, @n
	*										  else @c false.
	*/
	virtual void OnCameraAutoFocused(bool completeCondition) = 0;

	/**
	* Called when the Camera::StartPreview() method is completed. @n
	* Notifies to the application periodically, at the speed of the camera's frame rate,
	* once the %Camera::StartPreview() method is called, so as to receive the preview data.
	*
	* @since		2.0
	*
	*	@param[in]	previewedData			The displayed image data in the viewfinder @n
	*										The previewed data format is same as the format
	*									   set by Camera::SetPreviewFormat().
	* @param[in]	r	The cause of the error
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_INVALID_DATA	 The ByteBuffer contains invalid data.
	*	@remarks	This method is called only if the @c previewedData flag of
	*				Camera::StartPreview() is @c true.
	*	@remarks	This method can be delayed or dropped depending on system performance.
        *   @see	    Camera::GetPreviewFormat()
	*
	* The camera rotation can be different according to the physical design.
	* For keeping the compatibility between targets, the application must check the H/W camera rotation.
	* Based on this information, the application can rotate the preview data.
	*
	* The following example demonstrates how to use the %OnCameraPreviewed() method to rotate the preview data in the portrait mode.
	*
	* @code
	// Rotates the preview data to use it
	int rotation = (int)CAMERA_ROTATION_NONE;
	MediaCapability::GetValue(CAMERA_SECONDARY_ROTATION, rotation);

	ByteBuffer rotatedData;
	rotatedData.Construct(previewedData.GetLimit());

	switch ((CameraRotation) rotation)
	{
			case CAMERA_ROTATION_90:
					ImageUtil::Rotate(previewedData, rotatedData,
								Dimension(__previewWidth, __previewHeight), IMAGE_ROTATION_90, MEDIA_PIXEL_FORMAT_YUV420P);
					break;

			case CAMERA_ROTATION_180:
					ImageUtil::Rotate(previewedData, rotatedData,
								Dimension(__previewWidth, __previewHeight), IMAGE_ROTATION_180, MEDIA_PIXEL_FORMAT_YUV420P);
					break;

			case CAMERA_ROTATION_270:
					ImageUtil::Rotate(previewedData, rotatedData,
								Dimension(__previewWidth, __previewHeight), IMAGE_ROTATION_270, MEDIA_PIXEL_FORMAT_YUV420P);
					break;

			default:
					break;
	}
	// Normally Camera::SetFlip(CAMERA_FLIP_VERTICAL) is used when using the front camera.
	// Remember that the OverlayRegion method rotates the visible region internally corresponding to the form's orientation.
	// An application does not need to rotate the visible region explicitly.
	// However, the preview data itself is not rotated. If an application wants to rotate the preview data, the data must be rotated like above.
	// The width and height changes according to the degree of rotation.
	* @endcode
	*/
	virtual void OnCameraPreviewed(Tizen::Base::ByteBuffer& previewedData, result r) = 0;

	/**
	*	Called when the Camera::Capture() method is completed.
	*
	* @since		2.0
	*
	*	@param[in]	 capturedData			The image data captured by the camera @n
	*										The captured data format is the same as the format
	*									   set by Camera::SetCaptureFormat().
	* @param[in]	 r	The cause of the error
	*	@exception	 E_SUCCESS	The method is successful.
	*	@exception	 E_INVALID_DATA	 The ByteBuffer contains invalid data.
	*	@see		Camera::Capture()
        *   @see	    Camera::GetCaptureFormat()
	*/
	virtual void OnCameraCaptured(Tizen::Base::ByteBuffer& capturedData, result r) = 0;

	/**
	*	Called when an error occurs in Camera.
	*
	* @since		2.0
	*
	*	@param[in]	r		A camera error @n
	*						This is one of the ::CameraErrorReason values.
	*	@remarks			The ::CAMERA_ERROR_DEVICE_FAILED error occurs when the camera device
	*					   has a problem, such as damaged shape or hardware malfunction.
	*						The ::CAMERA_ERROR_DEVICE_INTERRUPTED error occurs when the camera
	*					   device has been interrupted by other request, such as an incoming
	*					   video telephony call.
	*						In this method, the application calls the Camera::PowerOff()
	*					 method to reset the camera device.
	*/
	virtual void OnCameraErrorOccurred(CameraErrorReason r) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void ICameraEventListener_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related, and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since		2.0
	//
	virtual void ICameraEventListener_Reserved2(void) {}

};

}}// Tizen::Media

#endif
