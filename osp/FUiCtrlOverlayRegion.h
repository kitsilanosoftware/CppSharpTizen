//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FUiCtrlOverlayRegion.h
 * @brief   This is the header file for the %OverlayRegion class.
 *
 * This header file contains the declarations of the %OverlayRegion class.
 */

#ifndef _FUI_CTRL_OVERLAY_REGION_H_
#define _FUI_CTRL_OVERLAY_REGION_H_

#include <FBaseObject.h>
#include <FBaseColArrayListT.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
}} // Tizen::Base

namespace Tizen { namespace Graphics
{
class Point;
class Dimension;
class Rectangle;
class BufferInfo;
}} // Tizen::Graphics

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum OverlayRegionBufferPixelFormat
 *
 * Defines the pixel formats.
 *
 * @since	2.0
 */
enum OverlayRegionBufferPixelFormat
{
	OVERLAY_REGION_BUFFER_PIXEL_FORMAT_ARGB8888 = 1,        /**< The ARGB8888 pixel format */
	OVERLAY_REGION_BUFFER_PIXEL_FORMAT_RGB565,          /**< The RGB565 pixel format */
	OVERLAY_REGION_BUFFER_PIXEL_FORMAT_YCbCr420_PLANAR, /**< The 8-bit Y plane followed by the 8-bit 2x2 subsampled U and V planes */
	OVERLAY_REGION_BUFFER_PIXEL_FORMAT_NV12, 		/**< The NV12 pixel format */
	OVERLAY_REGION_BUFFER_PIXEL_FORMAT_UYVY, 		/**< The UYVY pixel format */
	OVERLAY_REGION_BUFFER_PIXEL_FORMAT_MAX,              // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	OVERLAY_REGION_BUFFER_PIXEL_FORMAT_MIN = 0         // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum OverlayRegionType
 *
 * Defines the type of an overlay region.
 *
 * @since	2.0
 */
enum OverlayRegionType
{
	OVERLAY_REGION_TYPE_PRIMARY_CAMERA = 1,                 /**< The primary camera type @n
				                                            An overlay region displays the auto-rotated primary camera input that comes from Camera. */
	OVERLAY_REGION_TYPE_SECONDARY_CAMERA,               /**< The secondary camera type @n
				                                            An overlay region displays the auto-rotated and mirrored secondary camera input that comes from Camera. */
	OVERLAY_REGION_TYPE_NORMAL,                         /**< The normal type @n
				                                            An overlay region displays the user input as it is. */
	OVERLAY_REGION_TYPE_MAX,                             // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
	OVERLAY_REGION_TYPE_MIN = 0                          // This enum value is for internal use only. Using this enum value can cause behavioral, security-related, and consistency-related issues in the application.
};

/**
 * @enum OverlayRegionEvaluationOption
 *
 * Defines the option for evaluating the bounds of an overlay region.
 *
 * @since	2.0
 */
enum OverlayRegionEvaluationOption
{
	OVERLAY_REGION_EVALUATION_OPTION_GREATER_THAN,  /**< The option evaluating the overlay region bounds and finding the minimum bounds greater than the input bounds */
	OVERLAY_REGION_EVALUATION_OPTION_LESS_THAN,     /**< The option evaluating the overlay region bounds and finding the maximum bounds smaller than input bounds */
};


/**
 * @class	OverlayRegion
 * @brief	This class is an implementation of an %OverlayRegion.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %OverlayRegion class displays a region of an overlay surface, which is used to play back a video or show the camera preview.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_overlay_region.htm">OverlayRegion</a>.
 *
 * @code
//Sample code for OverlayRegionSample.h
#include <FGraphics.h>
#include <FMedia.h>
#include <FUi.h>

class OverlayRegionSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Media::IPlayerEventListener
{
public:
	OverlayRegionSample(void)
	: __pPlayer(null)
	, __pOverlayRegion(null)
	, __pOverlayPanel(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// IPlayerEventListener
	virtual void OnPlayerOpened(result r);
	virtual void OnPlayerEndOfClip(void);
	virtual void OnPlayerSeekCompleted(result r);
	virtual void OnPlayerBuffering(int percent);
	virtual void OnPlayerErrorOccurred(const Tizen::Media::PlayerErrorReason r);
	virtual void OnPlayerInterrupted(void);
	virtual void OnPlayerReleased(void);

private:
	Tizen::Media::Player* __pPlayer;
	Tizen::Ui::Controls::OverlayRegion*__pOverlayRegion;
	Tizen::Ui::Controls::Panel* __pOverlayPanel;
};
 *	@endcode
 *
 *	@code
//Sample code for OverlayRegionSample.cpp
#include <FApp.h>

#include "OverlayRegionSample.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Ui::Controls;

bool
OverlayRegionSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
OverlayRegionSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Sets an overlay region area
	int widthVideo = 480;
	int HeightVideo = 320;
	int positionX = (GetClientAreaBounds().width - 480) / 2;
	int positionY = (GetClientAreaBounds().width - 480) / 2;
	Rectangle overlayRectangle(positionX, positionY, widthVideo, HeightVideo);

	// Gets an overlay region
	__pOverlayRegion = GetOverlayRegionN(overlayRectangle,  OVERLAY_REGION_TYPE_NORMAL);

	// Gets buffer information
	BufferInfo bufferInfo;
	__pOverlayRegion->GetBackgroundBufferInfo(bufferInfo);

	// Gets a video file path
	String videoFilePath = App::GetInstance()->GetAppResourcePath() + L"tizen.mp4";

	// Creates an instance of Player
	__pPlayer = new Player();
	__pPlayer->Construct(*this, &bufferInfo);
	__pPlayer->SetLooping(true);
	__pPlayer->OpenFile(videoFilePath);
	__pPlayer->Play();

	// Creates an instance of Panel which is overlaid with overlay region
	__pOverlayPanel = new Panel();
	__pOverlayPanel->Construct(overlayRectangle);
	AddControl(*__pOverlayPanel);

	// Creates instaces of Button and Label and adds controls to the panel
	Label* pLabel = new Label();
	pLabel->Construct(Rectangle(0, 0, 400, 80),L"OverlayRegion Sample");
	pLabel->SetTextColor(Color::GetColor(COLOR_ID_RED));
	__pOverlayPanel->AddControl(*pLabel);

	Button* pButton = new Button();
	pButton->Construct(Rectangle(widthVideo - 200, HeightVideo - 100, 180, 80),L"BUTTON");
	__pOverlayPanel->AddControl(*pButton);

	Invalidate(true);

	return r;
}

result
OverlayRegionSample::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates controls
	delete __pPlayer;
	delete __pOverlayRegion;

	return r;
}

// IPlayerEventListener implementation
void
OverlayRegionSample::OnPlayerOpened(result r)
{
	// ....
}

void
OverlayRegionSample::OnPlayerEndOfClip(void)
{
	// ....
}

void
OverlayRegionSample::OnPlayerSeekCompleted(result r)
{
	// ....
}

void
OverlayRegionSample::OnPlayerBuffering(int percent)
{
	// ....
}

void
OverlayRegionSample::OnPlayerErrorOccurred(const PlayerErrorReason r)
{
	// ....
}

void
OverlayRegionSample::OnPlayerInterrupted(void)
{
	// ....
}

void
OverlayRegionSample::OnPlayerReleased(void)
{
	// ....
}
 * @endcode
 */
class _OSP_EXPORT_ OverlayRegion
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the destructor for this class.
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~OverlayRegion(void);

	/**
	 * Gets the position and size of the overlay region.
	 *
	 * @since		2.0
	 *
	 * @return		An instance of Rectangle that represents the position of the top-left corner, the width, and the height of the overlay region
	 * @remarks	The shape of an overlay region is rectangular, which is defined by the top-left point, and the width or height. The position of the top-left
	 *			point is relative to the top-left corner of the parent form.
	 *
	 */
	Tizen::Graphics::Rectangle GetBounds(void) const;

	/**
	 * Gets the position and size of the overlay region.
	 *
	 * @since		2.0
	 *
	 * @param[out]	x		The x position of the top-left corner of the overlay region
	 * @param[out]	y		The y position of the top-left corner of the overlay region
	 * @param[out]	width	The width of the rectangular region
	 * @param[out]	height	The height of the rectangular region
	 * @remarks	The shape of an overlay region is rectangular, which is defined by the top-left point, and the width or height. The position of the top-left
	 *			point is relative to the top-left corner of the parent form.
	 *
	 */
	void GetBounds(int& x, int& y, int& width, int& height) const;

	/**
	 * Sets the input buffer. @n
	 * Due to the hardware accelerated rendering, there are limitations for an input buffer. The input buffer has the same restriction regarding its size as
	 * the overlay region and it can be checked by using the GetWidthUnit(), GetHeightUnit() and GetMaxCount(). If the specified condition is not satisfied,
	 * the E_INVALID_ARG exception is returned. If an input buffer does not fit to the bounds of the overlay region, it will be scaled up or down to the overlay
	 * region bounds without keeping the ratio of input.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	srcBuffer				The source buffer
	 * @param[in]	srcDim					The source dimension
	 * @param[in]	srcFormat				The pixel format of buffer data
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_FORMAT    The specified pixel format is not supported.
	 * @exception	E_INVALID_OPERATION     The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result SetInputBuffer(const Tizen::Base::ByteBuffer& srcBuffer, const Tizen::Graphics::Dimension& srcDim, OverlayRegionBufferPixelFormat srcFormat);

	/**
	 * Gets the information related to the background buffer.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	info					The information of the input buffer
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks This method provides the buffer information, except the pointer of a color buffer. Therefore, info.pPixels is always assigned as @c null.
	 */class Dimension;

	result GetBackgroundBufferInfo(Tizen::Graphics::BufferInfo& info) const;

	/**
	 * Shows the overlay region on the screen.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, that is, this control cannot be displayed.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result Show(void);

	/**
	 * Evaluates and returns the valid position and size that are closest to the specified bounds.
	 *
	 * @since									2.0
	 *
	 * @return		@c true if the evaluation process does not meet an error, @n
	 *				else @c false
	 * @param[in]		option					The option for evaluating the bounds of the overlay region
	 * @param[in, out]	rect					An instance of %Rectangle that represents the validated bounds of %OverlayRegion @n
	 *											The width and height of the input rectangle must be greater than @c 0.
	 * @param[out]		modified				A boolean flag that indicates whether the specified @c rectangle is modified
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception		E_UNSUPPORTED_OPTION	A specified input parameter is not supported.
	 * @exception		E_SYSTEM				A system error has occurred.
	 * @remarks Due to the hardware accelerated rendering, there are limitations for an overlay region. @n
	 * The hardware capability for an overlay region is checked by using the GetWidthUnit(), GetHeightUnit() and GetMaxCount(). @n
	 *			If the application runs on multi-screen resolutions, the specified bounds may not meet the hardware limitations of the overlay region. In
	 *			such cases, GetOverlayRegionN() will return E_INVALID_ARG. @n
	 *          To prevent this kind of problem, the application must use the OverlayRegion::EvaluateBounds() method to get a validated bounds that can be
	 *			used as the input bounds of the GetOverlayRegionN() method.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	static bool EvaluateBounds(OverlayRegionEvaluationOption option, Tizen::Graphics::Rectangle& rect, bool& modified);

	/**
	 * Gets the value of the width. @n
	 * Only a multiple of this value can be allowed as the width of an overlay region.
	 *
	 * @since		2.0
	 *
	 * @return		The value of width
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	static int GetWidthUnit(void);

	/**
	 * Gets the value of the height. @n
	 * Only a multiple of this value can be allowed as the height of an overlay region.
	 *
	 * @since		2.0
	 *
	 * @return		The value of the height
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	static int GetHeightUnit(void);

	/**
	 * Gets the maximum count of overlay regions that can be used simultaneously per application.
	 *
	 * @since		2.0
	 *
	 * @return		The maximum count of overlay regions that can be used simultaneously per application
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	static int GetMaxCount(void);

	/**
	 * Gets the BufferPixelFormat list for the %OverlayRegion class. @n
	 * Each list item has a Tizen::UI::Controls::OverlayRegionBufferPixelFormat value.
	 *
	 * @since 2.0
	 *
	 * @return		A list of the pixel formats supported by the %OverlayRegion class, @n
	 *				else @c null if no pixel format is supported or an exception occurs
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @remark		The specific error code can be accessed using the GetLastResult() method. @n
	 *				The return value and each item in the list must be deleted by the caller. @n
	 *				The format list can vary depending on the device. After checking the supported formats using this API, it's better to use a proper pixel format. @n
	 */
	static Tizen::Base::Collection::IListT< Tizen::Ui::Controls::OverlayRegionBufferPixelFormat >* GetSupportedBufferPixelFormatListN(void);

private:
	//
	// This default constructor is intentionally declared as private so that only the platform can create an instance.
	//
	// @since		2.0
	//
	OverlayRegion(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	OverlayRegion(const OverlayRegion& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	OverlayRegion& operator =(const OverlayRegion& rhs);

private:
	class _OverlayRegionImpl * __pOverlayRegionImpl;

	friend class _OverlayRegionImpl;

}; // OverlayRegion

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_OVERLAY_CONTROL_H_
