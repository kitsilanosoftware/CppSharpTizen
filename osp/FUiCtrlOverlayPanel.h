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
 * @file		FUiCtrlOverlayPanel.h
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
 * @if OSPDEPREC
 * @class	OverlayPanel
 * @brief	 <i> [Deprecated] </i> This class is an implementation of %OverlayPanel.
 *
 * @deprecated  This class is deprecated. Instead of using this class, use the OverlayRegion class, that supports video playback and camera preview.
 * @since		2.0
 *
 * @remarks	The %OverlayPanel control can only be attached to a %Form control by using Tizen::Ui::Container::AddControl method, because of its native
 *			characteristics. Since %OverlayPanel inherits a Panel control, it can be used as a container if needed.
 *
 * The %OverlayPanel class is an implementation of the %OverlayPanel control.
 * The %OverlayPanel is a special type of panel which is used to specify a region where the developer
 * can playback video or camera preview. It is called an overlay because it is possible to overlay
 * other graphics and controls on top of the panel.
 * The %OverlayPanel consists of two layers, the foreground panel and background buffer which supports
 * H/W accelerated rendering. Due to the hardware accelerated nature, there is a limitation with an
 * %OverlayPanel. The Form that houses an %OverlayPanel can only have a black, opaque background.
 * The overlay panel can manipulate the rotation, the aspect ratio and the size of input buffer.
 *
 * Example: Please refer to the camera preview example of Tizen::Media::Camera
 *
 * @endif
 */
class _OSP_EXPORT_ OverlayPanel
	: public Tizen::Ui::Controls::Panel
{
public:
	/**
	 * @if OSPDEPREC
	 * @enum   Rotation
	 *
	 * Defines the various rotation options.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This enumerator is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera
	 *				preview.
	 * @since	2.0
	 * @endif
	 */
	enum Rotation
	{
		ROTATION_NONE,      /**< @if OSPDEPREC No rotation @endif */
		ROTATION_90,        /**< @if OSPDEPREC The 90 degree rotation @endif */
		ROTATION_180,       /**< @if OSPDEPREC The 180 degree rotation @endif */
		ROTATION_270,       /**< @if OSPDEPREC The 270 degree rotation @endif */
		ROTATION_NONE_LR,   /**< @if OSPDEPREC The horizontal mirroring @endif */
		ROTATION_NONE_UD,   /**< @if OSPDEPREC The vertical mirroring @endif */
		ROTATION_90_LR,     /**< @if OSPDEPREC The 90 degree rotation with horizontal mirroring @endif */
		ROTATION_90_UD,     /**< @if OSPDEPREC The 90 degree rotation with vertical mirroring @endif */
		ROTATION_180_LR,    /**< @if OSPDEPREC The 180 degree rotation with horizontal mirroring @endif */
		ROTATION_180_UD,    /**< @if OSPDEPREC The 180 degree rotation with vertical mirroring @endif */
		ROTATION_270_LR,    /**< @if OSPDEPREC The 270 degree rotation with horizontal mirroring @endif */
		ROTATION_270_UD,    /**< @if OSPDEPREC The 270 degree rotation with vertical mirroring @endif */
		ROTATION_MAX
	};

	/**
	 * @if OSPDEPREC
	 * @enum  BufferPixelFormat
	 *
	 * Defines the pixel formats.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This enumerator is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 * @since	2.0
	 * @endif
	 */
	enum BufferPixelFormat
	{
		/**
		 * @if OSPDEPREC 
		 * The ARGB8888 pixel format
		 *
		 * @since	2.0
		 * @endif
		 */
		BUFFER_PIXEL_FORMAT_ARGB8888,

		/**
		 * @if OSPDEPREC 
		 * The RGB565 pixel format
		 *
		 * @since	2.0
		 * @endif 
		 */
		BUFFER_PIXEL_FORMAT_RGB565,

		/**
		 * @if OSPDEPREC 
		 * The 8 bit Y plane followed by 8 bit 2 X 2 subsampled U and V planes
		 *
		 * @since	2.0
		 * @endif 
		 */
		BUFFER_PIXEL_FORMAT_YCbCr420_PLANAR
	};

	/**
	 * @if OSPDEPREC
	 * This is the default constructor for this class.
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 * @since	2.0
	 * @endif
	 */
	OverlayPanel(void);

	/**
	 * @if OSPDEPREC
	 * This is the destructor for this class.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 * @since	2.0
	 * @endif
	 */
	virtual ~OverlayPanel(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %OverlayPanel at the specified rectangle.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 * @since			2.0
	 *
	 * @return							An error code
	 * @param[in]	rect				The location and size of the %OverlayPanel control @n
	 *									The maximum size is 480 x 800 on a WVGA screen, or 240 x 400 on a WQVGA screen. @n
	 *									The minimum size of this control is 32 x 32 on a WVGA screen.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks	The size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks	Do not use %OverlayPanel in combination with %OverlayRegion. If used, %OverlayPanel may not work as expected.
	 * @see		Tizen::Ui::Container
	 * @endif
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect);

	/**
	 * @if OSPDEPREC
	 * Sets the rotation of the input buffer. @n
	 * All the rotations are clock-wise.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 * @since			2.0
	 *
	 * @param[in]	rotation	The rotation
	 *
	 * @endif
	 */
	void SetRendererRotation(OverlayPanel::Rotation rotation);

	/**
	 * @if OSPDEPREC
	 * Changes the size of the displayed renderer.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated  This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 * @since			2.0
	 *
	 * @param[in]	dim		The dimension of the window to draw
	 *
	 * @endif
	 */
	void SetRendererSize(Tizen::Graphics::Dimension& dim);

	/**
	 * @if OSPDEPREC
	 * Sets the aspect ratio of the renderer.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 * @since			2.0
	 *
	 * @param[in]	fix		Set to @c true if the renderer will display the aspect ratio of the input buffer even if the renderer and input data have
	 *						different aspect ratios, @n
	 *						else @c false
	 * @endif
	 */
	void SetRendererAspectRatio(bool fix);

	/**
	 * @if OSPDEPREC
	 * Sets the input buffer.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 * @since		2.0
	 *
	 * @param[in]   destDim				  The dimension of the window to be drawn
	 * @param[in]  	srcBuffer             The source buffer
	 * @param[in]  	srcDim                The source dimension
	 * @param[in]  	srcFormat             The pixel format of buffer data
	 * @exception   E_SUCCESS			  The method is successful.
	 * @exception  	E_INVALID_ARG		  A specified input parameter is invalid.
	 * @exception   E_SYSTEM			  A system error has occurred.
	 * @exception  	E_UNSUPPORTED_FORMAT  The specified pixel format is not supported.
	 * @remarks	BUFFER_PIXEL_FORMAT_ARGB8888, and BUFFER_PIXEL_FORMAT_RGB565 are not supported. @n
	 *			Control::Invalidate() methods must be called to properly display the input buffer.
	 *
	 * @endif
	 */
	result SetInputBuffer(const Tizen::Graphics::Dimension& destDim, const Tizen::Base::ByteBuffer& srcBuffer, const Tizen::Graphics::Dimension& srcDim, BufferPixelFormat srcFormat);

	/**
	 * @if OSPDEPREC
	 * Gets the information of the background buffer.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 * @since			 2.0
	 *
	 * @return		An error code
	 * @param[out] 	info				The information of the background buffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @remarks		Currently, this function provides buffer information except the pointer of the RGB color buffer. @n
	 *				Therefore, info.pPixels is always assigned @c null.
	 * @endif
	 */
	result GetBackgroundBufferInfo(Tizen::Graphics::BufferInfo& info) const;

	/**
	 * @if OSPDEPREC
	 * Gets the masking color of this control.
	 *
	 * @brief <i> [Deprecated]  </i>
	 * @deprecated	This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 * @since			 2.0
	 *
	 * @return     The pixel color format
	 * @endif
	 */
	Tizen::Graphics::Color GetMaskingColor(void) const;

private:
	friend class _OverlayPanelImpl;

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
