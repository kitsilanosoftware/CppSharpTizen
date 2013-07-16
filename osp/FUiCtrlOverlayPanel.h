//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FUiCtrlOverlayPanel.h
 * @brief	This is the header file for the %OverlayPanel class.
 *
 * This header file contains the declarations of the %OverlayPanel class.
 */

#ifndef _FUI_CTRL_OVERLAY_PANEL_H_
#define _FUI_CTRL_OVERLAY_PANEL_H_

#include <FBaseTypes.h>
#include <FGrpCanvas.h>
#include <FUiCtrlPanel.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @enum OverlayPanelEvaluationOption
 *
 * Defines the option for evaluating the bounds of an overlay panel.
 *
 * @since		2.1
 */
enum OverlayPanelEvaluationOption
{
	OVERLAY_PANEL_EVAL_OPT_GREATER_THAN,	/**< The option evaluating the overlay panel bounds and finding the minimum
												bounds greater than the input bounds */
	OVERLAY_PANEL_EVAL_OPT_LESS_THAN	/**< The option evaluating the overlay panel bounds and finding the maximum
											bounds smaller than input bounds */
};

/**
 * @class	OverlayPanel
 * @brief	This class is an implementation of %OverlayPanel.
 *
 * @since		2.1
 *
 * @remarks	The %OverlayPanel control can only be attached to a %Form control by using Tizen::Ui::Container::AddControl method, because of its native
 *			characteristics. Since %OverlayPanel inherits a Panel control, it can be used as a container if needed.
 *
 * The %OverlayPanel class is an implementation of the %OverlayPanel control.
 * The %OverlayPanel is a special type of panel which is used to specify area where the developer
 * can playback video or camera preview. It is called an overlay because it is possible to overlay
 * other graphics and controls on top of the panel.
 * The %OverlayPanel consists of two layers, the foreground panel and background buffer which supports
 * H/W accelerated rendering. Due to the hardware accelerated nature, there is a limitation with an
 * %OverlayPanel. The Form that houses an %OverlayPanel can only have a black, opaque background.
 * The overlay panel can manipulate the rotation and the size of input buffer.
 *
 * The following example demonstrates how to use the %OverlayPanel class.
 *
 * @code
//Sample code for OverlayPanelSampleForm.h
#include <FBase.h>
#include <FMedia.h>
#include <FUi.h>

class OverlayPanelSampleForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Media::IPlayerEventListener
{
public:
	OverlayPanelSampleForm(void);
	virtual ~OverlayPanelSampleForm(void);

	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

	// IPlayerEventListener
	virtual void OnPlayerOpened(result r);
	virtual void OnPlayerEndOfClip(void);
	virtual void OnPlayerSeekCompleted(result r);
	virtual void OnPlayerBuffering(int percent);
	virtual void OnPlayerErrorOccurred(const Tizen::Media::PlayerErrorReason r);
	virtual void OnPlayerInterrupted(void);
	virtual void OnPlayerReleased(void);

private:
	static const int ID_BUTTON_OK = 101;

	Tizen::Media::Player* __pPlayer;
	Tizen::Ui::Controls::OverlayPanel* __pOverlayPanel;
};
 *	@endcode
 *
 *	@code
//Sample code for OverlayPanelSampleForm.cpp
#include <FApp.h>
#include "OverlayPanelSampleForm.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Ui::Controls;

OverlayPanelSampleForm::OverlayPanelSampleForm(void)
{
}

OverlayPanelSampleForm::~OverlayPanelSampleForm(void)
{
}

bool
OverlayPanelSampleForm::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
OverlayPanelSampleForm::OnInitializing(void)
{
	// Set bounds of overlay panel
	Rectangle overlayPanelBounds(10, 10, GetClientAreaBounds().width - 20, 500);

	// Evaluate bounds
	bool isModifiedBounds = false;
	result r = OverlayPanel::EvaluateBounds(OVERLAY_PANEL_EVAL_OPT_GREATER_THAN, overlayPanelBounds, isModifiedBounds);

	// Creates an instance of overlay panel
	__pOverlayPanel = new OverlayPanel();
	__pOverlayPanel->Construct(overlayPanelBounds);
	AddControl(__pOverlayPanel);

	// Gets a background buffer info
	BufferInfo bufferinfo;
	__pOverlayPanel->GetBackgroundBufferInfo(bufferinfo);

	// Gets a video file path (/res/video.mp4)
	String videoFilePath = App::GetInstance()->GetAppResourcePath() + L"video.mp4";

	// Creates an instance of Player
	__pPlayer = new Player();
	__pPlayer->Construct(*this, &bufferinfo);
	__pPlayer->OpenFile(videoFilePath);
	__pPlayer->Play();

	// Creates an instance of Button
	Button *pButton = new Button();
	pButton->Construct(Rectangle(10, 10, 300, 100));
	pButton->SetText(L"Resize & Rotate");
	pButton->SetActionId(ID_BUTTON_OK);
	pButton->AddActionEventListener(*this);
	__pOverlayPanel->AddControl(pButton);

	return r;
}

result
OverlayPanelSampleForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// Deallocates controls
	if (__pPlayer)
	{
		__pPlayer->Close();
		delete __pPlayer;
	}

	return r;
}

void
OverlayPanelSampleForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_BUTTON_OK:
		{
			//Modify renderer size & Rotate renderer
			__pOverlayPanel->SetRenderSize(Dimension(400, 400));
			__pOverlayPanel->SetRendererRotation(OverlayPanel::ROTATION_270);
		}
		break;
	default:
		break;
	}
}

// IPlayerEventListener implementation
void
OverlayPanelSampleForm::OnPlayerOpened(result r)
{
	// ....
}

void
OverlayPanelSampleForm::OnPlayerEndOfClip(void)
{
	// ....
}

void
OverlayPanelSampleForm::OnPlayerSeekCompleted(result r)
{
	// ....
}

void
OverlayPanelSampleForm::OnPlayerBuffering(int percent)
{
	// ....
}

void
OverlayPanelSampleForm::OnPlayerErrorOccurred(const PlayerErrorReason r)
{
	// ....
}

void
OverlayPanelSampleForm::OnPlayerInterrupted(void)
{
	// ....
}

void
OverlayPanelSampleForm::OnPlayerReleased(void)
{
	// ....
}
 * @endcode
 */

class _OSP_EXPORT_ OverlayPanel
	: public Tizen::Ui::Controls::Panel
{
public:
	/**
	 * @enum   Rotation
	 *
	 * Defines the various rotation options.
	 *
	 * @since		2.1
	 */
	enum Rotation
	{
		ROTATION_NONE,		/**<  No rotation*/
		ROTATION_90,		/**<  The 90 degree rotation */
		ROTATION_180,		/**< The 180 degree rotation */
		ROTATION_270,		/**< The 270 degree rotation */
		ROTATION_NONE_LR,	/**< The horizontal mirroring */
		ROTATION_NONE_UD,	/**< The vertical mirroring */
		ROTATION_90_LR,		/**< The 90 degree rotation with horizontal mirroring */
		ROTATION_90_UD,		/**< The 90 degree rotation with vertical mirroring */
		ROTATION_180_LR,	/**< The 180 degree rotation with horizontal mirroring */
		ROTATION_180_UD,	/**< The 180 degree rotation with vertical mirroring */
		ROTATION_270_LR,	/**< The 270 degree rotation with horizontal mirroring */
		ROTATION_270_UD,	/**< The 270 degree rotation with vertical mirroring */
		ROTATION_MAX
	};

	/**
	 * @enum  BufferPixelFormat
	 *
	 * Defines the pixel formats.
	 *
	 * @since		2.1
	 */
	enum BufferPixelFormat
	{
		BUFFER_PIXEL_FORMAT_ARGB8888,			/**< The ARGB8888 pixel format */
		BUFFER_PIXEL_FORMAT_RGB565,			/**< The RGB565 pixel format */
		BUFFER_PIXEL_FORMAT_YCbCr420_PLANAR,	/**< The 8 bit Y plane followed by 8 bit 2 X 2 subsampled U and V planes */
		BUFFER_PIXEL_FORMAT_NV12,				/**< The NV12 pixel format */
		BUFFER_PIXEL_FORMAT_UYVY				/**< The UYVY pixel format */
	};

	/**
	 * This is the default constructor for this class. @n
	 * The object is not fully constructed after this constructor is called.  @n
	 * For full construction, the %Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.1
	 */
	OverlayPanel(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.1
	 */
	virtual ~OverlayPanel(void);

	/**
	 * Initializes this instance of %OverlayPanel at the specified rectangle.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]		rect				The location and size of the %OverlayPanel control @n
	 *								The maximum size is equal to screen size. for example 720 x 1280 on a HD screen, or 480 x 800 on a
	 *								WVGA screen.
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception  	E_INVALID_ARG	A specified input parameter @c is invalid.
	 * @exception		E_SYSTEM		A system error has occurred.
	 * @remarks
	 *				- The size of the control must be within the range defined by the minimum size and the maximum size.
	 *				- To guarantee the size of the render buffer equal to the size of the %OverlayPanel after constructed, checks bounds of
	 *				@c rect using EvaluateBounds() method before calling this method.
	 *				- Do not use %OverlayPanel in combination with %OverlayRegion. If used, %OverlayPanel may not work as expected.
	 * @see			%Tizen::Ui::Container
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect);

	/**
	 * Initializes this instance of %OverlayPanel at the specified rectangle.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]		rect				The location and size of the %OverlayPanel control @n
	 *								The maximum size is equal to screen size. for example 720 x 1280 on a HD screen, or 480 x 800 on a
	 *								WVGA screen.
	 * @exception		E_SUCCESS		The method is successful.
	 * @exception  	E_INVALID_ARG	A specified input parameter @c is invalid.
	 * @exception		E_SYSTEM		A system error has occurred.
	 * @remarks
	 *				- The size of the control must be within the range defined by the minimum size and the maximum size.
	 *				- To guarantee the size of the render buffer equal to the size of the %OverlayPanel after constructed, checks bounds of
	 *				@c rect using EvaluateBounds() method before calling this method.
	 *				- Do not use %OverlayPanel in combination with %OverlayRegion. If used, %OverlayPanel may not work as expected.
	 * @see			%Tizen::Ui::Container
	 */
	result Construct(const Tizen::Graphics::FloatRectangle& rect);

	/**
	 * Sets the rotation of the input buffer. @n
	 *
	 * @since		2.1
	 *
	 * @param[in]	rotation	The rotation
	 */
	void SetRendererRotation(OverlayPanel::Rotation rotation);

	/**
	 * @if OSPDEPREC
	 * Changes the size of the displayed renderer.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and
	 *				camera preview.
	 * @since			2.0
	 *
	 * @param[in]	dim	The dimension of the window to draw
	 *
	 * @endif
	 */
	void SetRendererSize(Tizen::Graphics::Dimension& dim);

	/**
	 * Changes the size of the displayed renderer.
	 *
	 * @since		2.1
	 *
	 * @return	An error code
	 * @param[in]	dim	The dimension of the window to draw
	 * @exception E_SUCCESS			The method is successful.
	 * @exception E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @remarks
	 *			- A %OverlayPanel becomes displayable only after it has been added to a form.
	 *			- If you want to resize window to draw render buffer, calls this function after the %OverlayPanel is added to a %Form control
	 * @code
	 *	OverlayPanel* pOverlayPanel = new OverlayPanel();
	 *	pOverlayPanel->Construct(Rectangle(100, 250, 300, 300));
	 *	AddControl(pOverlayPanel);
	 *
	 *	//...
	 *	result r = pOverlayPanel->SetRenderSize(Dimension(300, 200));
	 *	//...
           * @endcode
	 */
	result SetRenderSize(const Tizen::Graphics::Dimension& dim);

	/**
	 * Changes the size of the displayed renderer.
	 *
	 * @since		2.1
	 *
	 * @return	An error code
	 * @param[in]	dim	The dimension of the window to draw
	 * @exception E_SUCCESS			The method is successful.
	 * @exception E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation.
	 * @remarks
	 *			- A %OverlayPanel becomes displayable only after it has been added to a form.
	 *			- If you want to resize window to draw render buffer, calls this function after the %OverlayPanel is added to a %Form control
	 * @code
	 *	OverlayPanel* pOverlayPanel = new OverlayPanel();
	 *	pOverlayPanel->Construct(FloatRectangle(100.0, 250.0, 300.0, 300.0));
	 *	AddControl(pOverlayPanel);
	 *
	 *	//...
	 *	result r = pOverlayPanel->SetRenderSize(FloatDimension(300.0, 200.0));
	 *	//...
           * @endcode
	 */
	result SetRenderSize(const Tizen::Graphics::FloatDimension& dim);

	/**
	 * Sets the input buffer.
	 *
	 * @since		2.1
	 *
	 * @param[in]		destDim					The dimension of the window to draw
	 * @param[in]		srcBuffer					The source buffer
	 * @param[in]		srcDim					The source dimension
	 * @param[in]		srcFormat				The pixel format of buffer data
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception		E_SYSTEM				A system error has occurred.
	 * @exception		E_UNSUPPORTED_FORMAT	The specified pixel format is not supported.
	 * @remarks		Control::Invalidate() methods must be called to properly display the input buffer.
	 */
	result SetInputBuffer(const Tizen::Graphics::Dimension& destDim, const Tizen::Base::ByteBuffer& srcBuffer, const Tizen::Graphics::Dimension& srcDim, BufferPixelFormat srcFormat);

	/**
	 * Sets the input buffer.
	 *
	 * @since		2.1
	 *
	 * @param[in]		destDim					The dimension of the window to draw
	 * @param[in]		srcBuffer					The source buffer
	 * @param[in]		srcDim					The source dimension
	 * @param[in]		srcFormat				The pixel format of buffer data
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception		E_SYSTEM				A system error has occurred.
	 * @exception		E_UNSUPPORTED_FORMAT	The specified pixel format is not supported.
	 * @remarks		Control::Invalidate() methods must be called to properly display the input buffer.
	 */
	result SetInputBuffer(const Tizen::Graphics::FloatDimension& destDim, const Tizen::Base::ByteBuffer& srcBuffer, const Tizen::Graphics::Dimension& srcDim, BufferPixelFormat srcFormat);

	/**
	 * Gets the information of the background buffer.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[out] 	info					The information of the background buffer
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_OPERATION_FAILED	The operation has failed.
	 * @remarks		Currently, this method provides buffer information except the pointer of the RGB color buffer. @n
	 *				Therefore, info.pPixels is always assigned @c null.
	 */
	result GetBackgroundBufferInfo(Tizen::Graphics::BufferInfo& info) const;

	/**
	 * @if OSPDEPREC
	 * Sets the aspect ratio of the renderer.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated because the renderer aspect ratio is not guaranteed any more.
	 * @since			2.0
	 *
	 * @param[in]	fix	Set to @c true if the renderer will display the aspect ratio of the input buffer even if the renderer and input data have
	 *				different aspect ratios, @n
	 *				else @c false
	 * @remarks		This method has no effects for hardware accelerated GL backend.
	 * @endif
	 */
	void SetRendererAspectRatio(bool fix);

	/**
	 * @if OSPDEPREC
	 * Gets the masking color of this control.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated because masking color does not exist on %OverlayPanel any more.
 	 * @remarks		Do not call this method. It is not supported.
	 * @since			2.0
	 *
	 * @return		Always returns Tizen::Graphics::Color(0x00000000)
	 * @endif
	 */
	Tizen::Graphics::Color GetMaskingColor(void) const;

	/**
	 * Evaluates and returns the valid position and size that are closest to the specified bounds.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]		option				The option for evaluating the bounds of the overlay panel
	 * @param[in, out]	rect					An instance of %Tizen::Graphics::Rectangle that represents the validated bounds of %OverlayPanel @n
	 *									The width and height of the input rectangle must be greater than @c 0.
	 * @param[out]	modified				A boolean flag that indicates whether the specified @c rectangle is modified
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG			The specified input parameter @c is invalid.
	 * @exception		E_UNSUPPORTED_OPTION	The specified input parameter @c is not supported.
	 * @exception		E_OPERATION_FAILED		The operation has failed.
	 * @remarks
	 *				- Due to the hardware accelerated rendering, there are limitations for an overlay panel.
	 *				- The hardware capability for an overlay region is checked by using the GetWidthUnit(), GetHeightUnit() and GetMaxCount().
	 *				- If the application runs on multi-screen resolutions, the specified bounds may not meet the hardware limitations of the overlay
	 *				panel. In such cases, Construct() will return @c E_INVALID_ARG. @n
	 *				To prevent this kind of problem, the application must the this method to get a validated bounds
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 */
	static result EvaluateBounds(OverlayPanelEvaluationOption option, Tizen::Graphics::Rectangle& rect, bool& modified);

	/**
	 * Evaluates and returns the valid position and size that are closest to the specified bounds.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]		option				The option for evaluating the bounds of the overlay panel
	 * @param[in, out]	rect					An instance of %Tizen::Graphics::FloatRectangle that represents the validated bounds of %OverlayPanel @n
	 *									The width and height of the input float rectangle must be greater than @c 0.
	 * @param[out]	modified				A boolean flag that indicates whether the specified @c rectangle is modified
	 * @exception		E_SUCCESS			The method is successful.
	 * @exception		E_INVALID_ARG			The specified input parameter @c is invalid.
	 * @exception		E_UNSUPPORTED_OPTION	The specified input parameter @c is not supported.
	 * @exception		E_OPERATION_FAILED		The operation has failed.
	 * @remarks
	 *				- Due to the hardware accelerated rendering, there are limitations for an overlay panel.
	 *				- The hardware capability for an overlay region is checked by using the GetWidthUnit(), GetHeightUnit() and GetMaxCount().
	 *				- If the application runs on multi-screen resolutions, the specified bounds may not meet the hardware limitations of the overlay
	 *				panel. In such cases, Construct() will return E_INVALID_ARG. @n
	 *				To prevent this kind of problem, the application must use this method to get a validated bounds
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 */
	static result EvaluateBounds(OverlayPanelEvaluationOption option, Tizen::Graphics::FloatRectangle& rect, bool& modified);

	/**
	 * Gets the BufferPixelFormat list for the %OverlayPanel class. @n
	 * Each list item has a Tizen::UI::Controls::OverlayPanel::BufferPixelFormat value.
	 *
	 * @since		2.1
	 *
	 * @return
	 *				- A list of the pixel formats supported by the %OverlayPanel class, @n
	 *				else @c null if no pixel format is supported or an exception occurs
	 *				- The specific error code can be accessed using the GetLastResult() method.
	 *				- The return value and each item in the list must be deleted by the caller.
	 *				- The format list can vary depending on the device. After checking the supported formats using this method,
	 *				it's better to use a proper pixel format.
	 */
	static Tizen::Base::Collection::IListT<BufferPixelFormat>* GetSupportedBufferPixelFormatListN(void);

	/**
	 * Gets the width unit. @n
	 * Only a multiple of this value can be allowed as the width of an overlay panel.
	 *
	 * @since		2.1
	 *
	 * @return	The value of width
	 */
	static int GetWidthUnit(void);

	/**
	 * Gets the height unit. @n
	 * Only a multiple of this value can be allowed as the height of an overlay panel.
	 *
	 * @since		2.1
	 *
	 * @return	The value of the height
	 */
	static int GetHeightUnit(void);

	/**
	 * Gets the maximum count of overlay panel that can be used simultaneously per application.
	 *
	 * @since		2.1
	 *
	 * @return	The maximum count of overlay panel that can be used simultaneously per application
	 */
	static int GetMaxCount(void);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	OverlayPanel(const OverlayPanel& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	OverlayPanel& operator =(const OverlayPanel& rhs);
}; // OverlayPanel

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_OVERLAY_PANEL_H_

