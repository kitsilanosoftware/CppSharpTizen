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
 * @file		FUiCtrlIGalleryItemProvider.h
 * @brief		This is the header file for the %IGalleryItemProvider interface.
 *
 * This header file contains the declarations of the %IGalleryItemProvider interface. @n
 * If an event is generated, a method of this interface is called. @n
 * Therefore, if applications perform jobs related to the list events, use the methods of this interface.
 *
 */
#ifndef _FUI_CTRL_IGALLERY_ITEM_PROVIDER_H_
#define _FUI_CTRL_IGALLERY_ITEM_PROVIDER_H_

#include <FUiCtrlGalleryItem.h>

namespace Tizen { namespace Ui { namespace Controls
{

/**
 * @interface	IGalleryItemProvider
 * @brief		This interface implements the provider for events on Gallery.
 *
 * @since		2.0
 *
 * The %IGalleryItemProvider interface is the interface for handling Gallery items. The class that handles gallery items implements this
 * interface, and the instance created using the Gallery's SetItemProvider() method.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_gallery.htm">Gallery</a>.
 */
class _OSP_EXPORT_ IGalleryItemProvider
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 	2.0
	 */
	virtual ~IGalleryItemProvider(void) {}

	/**
	 * Gets the total number of items.
	 *
	 * @since 	2.0
	 *
	 * @return		The total number of the Gallery control items
	 * @remarks		An application that uses the Gallery control must implement this method.
	 */
	virtual int GetItemCount(void) = 0;

	/**
	 * Gets the item at the specified index from the item provider.
	 *
	 * @since	2.0
	 *
	 * @return		An item of the Gallery control
 	 * @param[in]	index			The index of the item
 	 * @see			DeleteItem()
	 * @remarks		An application that uses the Gallery control must implement this method. This method is expected to return an item that is allocated on a
	 *				heap memory. The returned item can be of type GalleryItem. Note that when the item is not required, the Gallery control calls the
	 *				IGalleryItemProvider::DeleteItem() method.
	 */
	virtual Tizen::Ui::Controls::GalleryItem* CreateItem(int index) = 0;

	/**
	 * Deletes the specified item.
	 *
	 * @since 	2.0
	 *
	 * @return		@c true if the item is deallocated by this method, @n
	 * 				else @c false
	 * @param[in]	index		The index of the item
	 * @param[in]	pItem		The pointer to GalleryItem that is to be deleted
	 * @see			CreateItem()
	 * @remarks		An application that uses the Gallery control must implement this method. Using this method, an application can deallocate the item. If an
	 *				application deallocates the item, this method returns @c true. This notifies the Gallery control to not release the item.
	 *				Otherwise, the item is deallocated by the Gallery control.
	 */
	virtual bool DeleteItem(int index, Tizen::Ui::Controls::GalleryItem* pItem) = 0;

protected:
	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	virtual void GalleryItemProvider_Reserved1(void) {}

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	virtual void GalleryItemProvider_Reserved2(void) {}

	//
	//This method is for internal use only. Using this method can cause behavioral, security-related,
	//and consistency-related issues in the application.
	//
	virtual void GalleryItemProvider_Reserved3(void) {}
}; // IGalleryItemProvider

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_IGALLERY_ITEM_PROVIDER_H_
