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
 * @file	FUiCtrlGalleryItem.h
 * @brief	This is the header file for the %GalleryItem class.
 *
 * This header file contains the declarations of the %GalleryItem class and its helper classes.
 */

#ifndef _FUI_CTRL_GALLERY_ITEM_H_
#define _FUI_CTRL_GALLERY_ITEM_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FGrpBitmap.h>
#include <FUiCtrlGalleryTypes.h>

namespace Tizen { namespace Ui { namespace Controls
{

class _GalleryItemImpl;

/**
 * @class	GalleryItem
 * @brief This class defines the common behavior for a %GalleryItem control.
 *
 * @since		2.0
 *
 * The %GalleryItem class represents an item of the Gallery control. An instance of the %GalleryItem class
 * comprises of a bitmap image and its image rotation. @n @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/ui/implementing_gallery.htm">Gallery</a>.
 */
class _OSP_EXPORT_ GalleryItem
	: public Tizen::Base::Object
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the %Construct() method must be called right after calling this constructor.
	 *
	 * @since 2.0
	 */
	GalleryItem(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~GalleryItem(void);

public:
	/**
	 * Initializes this instance of %GalleryItem with the specified parameters.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	bitmap			The default bitmap image
	 * @param[in]	rotation		The rotation of the bitmap image
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result Construct(const Tizen::Graphics::Bitmap& bitmap, GalleryImageRotation rotation = GALLERY_IMAGE_ROTATION_0);

	/**
	 * Initializes this instance of %GalleryItem with the specified parameters.
	 * @since 2.0
	 * @return            	 			 An error code
	 * @param[in]  bitmap                 The default bitmap image
	 * @param[in]  filePath               The bitmap file path
	 * @param[in]  rotation               The rotation of the bitmap image
	 * @exception  	E_SUCCESS				The method is successful.
	 * @exception  	E_OVERFLOW				The image specified by @c filePath has caused an overflow.
	 * @exception  	E_UNSUPPORTED_FORMAT   	The image specified by @c filePath is not supported.
	 * @exception  E_FILE_NOT_FOUND       The specified file cannot be found or accessed.
	 * @exception  E_INTERRUPTED   		 The requested operation cannot be performed due to an interruption from another thread. @n
	 * @exception  E_ILLEGAL_ACCESS       The image specified by @c filePath parameter, is protected with DRM.
	 * @exception  E_SYSTEM           	 A system error has occurred.
	 * @remarks  The specified file path is used to decode the original bitmap to show a more higher quality image when the corresponding item is zoomed.
	 */
	result Construct(const Tizen::Graphics::Bitmap& bitmap, const Tizen::Base::String& filePath, GalleryImageRotation rotation = GALLERY_IMAGE_ROTATION_0);

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	GalleryItem(const GalleryItem& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	GalleryItem& operator =(const GalleryItem& rhs);

private:
	_GalleryItemImpl* __pImpl;

	friend class _GalleryItemImpl;
}; // GalleryItem

}}} // Tizen::Ui::Controls

#endif // _FUI_CTRL_GALLERY_ITEM_H_
