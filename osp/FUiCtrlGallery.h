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
 * @file	FUiCtrlGallery.h
 * @brief	This is the header file for the %Gallery class.
 *
 * This header file contains the declarations of the %Gallery class and its helper classes.
 */

#ifndef _FUI_CTRL_GALLERY_H_
#define _FUI_CTRL_GALLERY_H_

#include <FBaseObject.h>
#include <FBaseTypes.h>
#include <FBaseString.h>
#include <FGrpRectangle.h>
#include <FGrpDimension.h>
#include <FGrpBitmap.h>
#include <FUiControl.h>
#include <FUiContainer.h>
#include <FUiCtrlGalleryItem.h>
#include <FUiCtrlGalleryTypes.h>
#include <FUiCtrlIGalleryItemProvider.h>
#include <FUiCtrlIGalleryEventListener.h>

namespace Tizen { namespace Ui { namespace Controls
{
/**
 * @class	Gallery
 * @brief	This class defines the common behavior of a %Gallery control.
 *
 * @since	2.0
 *
 * The %Gallery class displays an image viewer that contains a collection of images (1
 * image at a time) in a horizontally scrolling list. It also supports a slide
 * show that automatically displays all the images consecutively.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_gallery.htm">Gallery</a>.
 *
 * The following example demonstrates how to use the %Gallery class.
 *
 * @code
// Sample code for GallerySample.h
#include <FUi.h>

class GallerySample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IGalleryItemProvider
	, public Tizen::Ui::Controls::IGalleryEventListener
{
public:
	GallerySample(void)
	: __pGallery(null){}

	bool Initialize(void);
	virtual result OnInitializing(void);

	//IGalleryItemProvider
	virtual Tizen::Ui::Controls::GalleryItem* CreateItem (int index);
	virtual bool DeleteItem (int index, Tizen::Ui::Controls::GalleryItem *pItem);
	virtual int GetItemCount(void);

	// IGalleryEventListener
	virtual void OnGalleryCurrentItemChanged(Tizen::Ui::Controls::Gallery &gallery, int index);
	virtual void OnGalleryItemClicked(Tizen::Ui::Controls::Gallery &gallery, int index);
	virtual void OnGallerySlideShowStarted(Tizen::Ui::Controls::Gallery& gallery);
	virtual void OnGallerySlideShowStopped(Tizen::Ui::Controls::Gallery& gallery);

private:
	Tizen::Ui::Controls::Gallery* __pGallery;
};
 *	@endcode
 *
 *	@code
// Sample code for GallerySample.cpp
#include <FApp.h>
#include <FGraphics.h>

#include "GallerySample.h"

using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;

bool
GallerySample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL);
	return true;
}

result
GallerySample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates an instance of Gallery
	__pGallery = new Gallery();
	__pGallery->Construct(GetBounds());
	__pGallery->SetItemProvider(*this);
	__pGallery->AddGalleryEventListener(*this);

	AddControl(*__pGallery);

	return r;
}

// IGalleryItemProvider implementation
GalleryItem*
GallerySample::CreateItem(int index)
{
	// Gets an instance of Bitmap
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap* pImageTemp = pAppResource->GetBitmapN(L"Image.jpg");

	// Creates an instance of GalleryItem and registers the bitmap to the gallery item
	GalleryItem* pGallery = new GalleryItem();
	pGallery->Construct(*pImageTemp);

	// Deallocates the bitmap
	delete pImageTemp;

	return pGallery;
}

bool
GallerySample::DeleteItem(int index, GalleryItem *pItem)
{
	delete pItem;
	return true;
}

int
GallerySample::GetItemCount(void)
{
	return 1;
}

// IGalleryEventListener implementation
void
 GallerySample::OnGalleryCurrentItemChanged(Gallery &gallery, int index)
{
	// ....
}

void
GallerySample::OnGalleryItemClicked(Gallery &gallery, int index)
{
	// ....
}

void
GallerySample::OnGallerySlideShowStarted(Gallery& gallery)
{
	// ....
}

void
GallerySample::OnGallerySlideShowStopped(Gallery& gallery)
{
	// ....
}
 * @endcode
 */

class _OSP_EXPORT_ Gallery
	: public Tizen::Ui::Control
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	Gallery(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~Gallery(void);

public:
	/**
	 * Initializes this instance of %Gallery with the specified parameter.
	 *
	 * @since 		2.0
	 *
	 * @return		An error code
	 * @param[in]	rect	        An instance of the Graphics::Rectangle class @n
	 *						        	This instance represents the x and y coordinates of the top-left corner of the created %Gallery control along with the
	 *									width and height.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::Rectangle& rect);

	/**
	 * Sets the item provider that creates and deletes the items from the %Gallery control.
	 *
	 * @since 		2.0
	 *
	 * @return		An error code
	 * @param[in]	provider		The item provider to create and delete items
	 * @exception	E_SUCCESS			The method is successful.
	 * @remark		If an item provider is not set for the %Gallery control, the method does not work. @n
	 *              The item provider should be allocated on a heap memory.
	 */
	result SetItemProvider(IGalleryItemProvider& provider);

	/**
	 * Adds an IGalleryEventListener instance. @n
	 * The added listener can listen to the item events when they are fired.
	 *
	 * @since 		2.0
	 *
	 * @param[in]	listener 		The listener to be added
	 */
	void AddGalleryEventListener(IGalleryEventListener& listener);

	/**
	 * Removes an IGalleryEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 		2.0
	 *
	 * @param[in]	listener 		The listener to be removed
	 */
	void RemoveGalleryEventListener(IGalleryEventListener& listener);

	/**
	 * Gets the index of the current item.
	 *
	 * @since 		2.0
	 *
	 * @return		The current item index of the %Gallery control
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetCurrentItemIndex(void) const;

	/**
	 * Sets the index of the current item.
	 *
	 * @since 		2.0
	 *
	 * @return		An error code
	 * @param[in]	index			The index of the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is out of range.
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 */
	result SetCurrentItemIndex(int index);

	/**
	 * Gets the total number of items.
	 *
	 * @since	2.0
	 *
	 * @return	The total number of items, @n
	 *			else @c -1 if an error occurs
	 */
	int GetItemCount(void) const;

	/**
	 * Refreshes the item at the specified index.
	 *
	 * @since 		2.0
	 *
	 * @return		An error code
	 * @param[in]	itemIndex    			The index of the item to be refreshed
	 * @param[in]	type			The type of change for an item
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is out of range.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result RefreshGallery(int itemIndex, GalleryRefreshType type);

	/**
	 * Updates all the items of a list.
	 *
	 * @since 	  2.0
	 *
	 * @return    An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	 * @exception E_SYSTEM             A system error has occurred.
	 * @remarks   This method clears items in the list and reinvokes methods of the item provider to fill the list.
	 */
	result UpdateGallery(void);

	/**
	 * Sets the text of the empty %Gallery control.
	 *
	 * @since 		2.0
	 *
	 * @return		An error code
	 * @param[in]   text    			The text of the empty %Gallery control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetTextOfEmptyGallery(const Tizen::Base::String& text);

	/**
	 * Gets the text of the empty %Gallery control.
	 *
	 * @since 		2.0
	 *
	 * @return		The text of the empty %Gallery control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Base::String GetTextOfEmptyGallery(void) const;

	/**
	 * Sets the background bitmap of the %Gallery control.
	 *
	 * @since 		2.0
	 *
	 * @param[in] 	pBitmap				The bitmap of the empty %Gallery control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		When @c pBitmap is @c null, the %Gallery control does not have a background bitmap. The default value for the background bitmap is @c null.
	 * @remarks		The background bitmap has a priority over the background color. When both the background bitmap and the background color are specified,
	 *				only the bitmap is displayed.
	 */
	result SetBitmapOfEmptyGallery(const Tizen::Graphics::Bitmap* pBitmap);

	/**
	 * Sets the slide show transition animation type.
	 *
	 * @since 		2.0
	 *
	 * @param[in] animation                The animation type of the %Gallery control
	 * @exception E_SUCCESS                The method is successful.
	 * @exception E_UNSUPPORTED_OPERATION  This operation is not supported.
	 * @exception E_SYSTEM                 A system error has occurred.
	 * @remarks   The method is not supported in 16-bit devices.
	 */
	result SetSlideShowAnimation(GalleryAnimation animation);

	/**
	 * Gets the transition animation type of the slide show.
	 *
	 * @since 		2.0
	 *
	 * @return    The animation type of a %Gallery control
	 * @exception E_SUCCESS                The method is successful.
	 * @exception E_UNSUPPORTED_OPERATION  This operation is not supported.
	 * @exception E_SYSTEM                 A system error has occurred.
	 * @remarks   The specific error code can be accessed using the GetLastResult() method.
	 * @remarks   The method is not supported in 16-bit devices.
	 */
	GalleryAnimation GetSlideShowAnimation(void) const;

	/**
	 * Sets the duration of the slide show transition animation.
	 *
	 * @since 		2.0
	 *
	 * @param[in] 	duration	The animation duration
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c duration is out of the possible duration range. @n
	 * 				The specified duration should be greater than or equal to 300 or less than or equals to 20000.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The unit of the duration is in milliseconds.@n
	 * 				The default animation duration is different for each slide show animation type.
	 */
	result SetSlideShowAnimationDuration(int duration);

	/**
	 * Gets the transition animation duration of the %Gallery control.
	 *
	 * @since 		2.0
	 *
	 * @return     	The animation duration, @n
	 *     	        else @c -1 if an error occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetSlideShowAnimationDuration(void) const;

	/**
	 * Sets the duration of the slide-show item view.
	 *
	 * @since		2.0
	 *
	 * @param[in]	duration		The item view duration
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified @c duration is out of possible duration range. @n
	 *								- The specified @c duration should be greater than 10.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The unit of the duration is in milliseconds.@n
	 * 				The default animation duration is different for each slide show animation type.
	 */
	result SetSlideShowViewDuration(int duration);

	/**
	 * Gets the duration of the slide-show item view.
	 *
	 * @since		2.0
	 *
	 * @return		The item view duration, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using @c GetLastResult() method.
	 */
	int GetSlideShowViewDuration(void) const;

	/**
	 * Starts the slide show.
	 *
	 * @since 		2.0
	 *
	 * @return		An error code
	 * @param[in]   repeat			     The repeat status
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM		     A system error has occurred.
	 */
	result StartSlideShow(bool repeat = false);

	/**
	 * Stops the slide show.
	 *
	 * @since 		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM		     A system error has occurred.
	 */
	result StopSlideShow(void) const;

	/**
	 * Checks whether the slide show has started.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the slide show is running, @n
	 * 				else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsSlideShowStarted(void) const;

	/**
	 * Enables or disables the image zooming.
	 *
	 * @since 		2.0
	 *
	 * @return		An error code
	 * @param[in]   enable	   			Set to @c true to enable zooming, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		When enabled, the user can enter the zoom mode by double-clicking or pinching the current image.
	 */
	result SetZoomingEnabled(bool enable);

	/**
	 * Checks whether zooming is enabled.
	 *
	 * @since 		2.0
	 *
	 * @return		@c true if zooming is enabled, @n
	 * 				else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsZoomingEnabled(void) const;

	/**
	 * Sets the background color of the %Gallery control.
	 *
	 * @since       2.0
	 *
	 * @return      An error code
	 * @param[in]   color   The background color
	 * @exception   E_SUCCESS              	The method is successful.
	 * @exception   E_SYSTEM              	A system error has occurred.
	 * @remarks     The method ignores the alpha value of the @c color parameter and sets the alpha value to 255.
	 */
	result SetBackgroundColor(const Tizen::Graphics::Color& color);

	/**
	 * Gets the background color of the %Gallery control.
	 *
	 * @since       2.0
	 *
	 * @return      The background color, @n
	 *              else RGBA(0, 0, 0, 0) if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Color GetBackgroundColor(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	Gallery(const Gallery& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	Gallery& operator =(const Gallery& rhs);

protected:
	friend class _GalleryImpl;
}; // Gallery

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_GALLERY_H_
