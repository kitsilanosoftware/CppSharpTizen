//
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
 * @file			FCntImageMetadata.h
 * @brief		This is the header file for the %ImageMetadata class.
 *
 * This header file contains the declarations of the %ImageMetadata class.
 */

#ifndef _FCNT_IMAGE_METADATA_H_
#define _FCNT_IMAGE_METADATA_H_

#include <FBaseObject.h>
#include <FCntTypes.h>

namespace Tizen { namespace Graphics
{
class Bitmap;
}}

namespace Tizen { namespace Content
{

class _ImageMetadataImpl;

/**
 * @class	ImageMetadata
 * @brief	This class provides methods to access the image metadata.
 *
 * @since	2.0
 *
 * The %ImageMetadata class provides methods to access the image metadata that contains the image content-specific attributes.
 *
 * The following example demonstrates how to use the %ImageMetadata class.
 *
 * @code
 * result
 * MyClass::TestImageMetadata(void)
 * {
 *		result r = E_SUCCESS;
 *
 *		Tizen::Base::String contentPath = Tizen::System::Environment::GetMediaPath() + L"Images/full_meta.jpg";
 *		ImageMetadata* pImgMeta = ContentManagerUtil::GetImageMetaN(contentPath);
 *		TryReturn(pImgMeta != null, GetLastResult(), "ContentManagerUtil::GetImageMetaN failed.");
 *
 *		// Width
 *		pImgMeta->GetWidth();
 *
 *		// Height
 *		pImgMeta->GetHeight();
 *
 *		// Camera
 *		pImgMeta->GetCameraManufacturer();
 *
 *		// Model
 *		pImgMeta->GetCameraModel();
 *
 *		// Software
 *		pImgMeta->GetSoftware();
 *
 *		// Date time
 *		pImgMeta->GetDateTime();
 *
 *		// Thumbnail
 *		Tizen::Media::Image image;
 *		r = image.Construct();
 *		if (IsFailed(r))
 *		{
 *			delete pImgMeta;
 *			return r;
 *		}
 *
 *		Tizen::Graphics::Bitmap* pBitmap = pImgMeta->GetThumbnailN();
 *		if (pBitmap == null)
 *		{
 *			delete pImgMeta;
 *			return GetLastResult();
 *		}
 *
 *		Tizen::Base::String thumbnailPath = Tizen::System::Environment::GetMediaPath() + L"Images/image.bmp";
 *		r = image.EncodeToFile(*pBitmap, Tizen::Media::IMG_FORMAT_BMP, thumbnailPath, false);
 *		if (IsFailed(r))
 *		{
 *			delete pImgMeta;
 *			delete pBitmap;
 *			return r;
 *		}
 *
 *		delete pImgMeta;
 *		delete pBitmap;
 *
 *		return r;
 * }
 * @endcode
 */
class _OSP_EXPORT_ ImageMetadata
	: virtual public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	ImageMetadata(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs	An instance of %ImageMetadata
	 */
	ImageMetadata(const ImageMetadata& rhs);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~ImageMetadata(void);

	/**
	 * Gets the width of the image.
	 *
	 * @since		2.0
	 *
	 * @return		The width of the image
	 */
	int GetWidth(void) const;

	/**
	 * Gets the height of the image.
	 *
	 * @since		2.0
	 *
	 * @return		The height of the image
	 */
	int GetHeight(void) const;

	/**
	 * Gets the name of the camera's manufacturer.
	 *
	 * @since		2.0
	 *
	 * @return		The name of the camera's manufacturer
	 */
	Tizen::Base::String GetCameraManufacturer(void) const;

	/**
	 * Gets the model of the camera.
	 *
	 * @since		2.0
	 *
	 * @return		The model of the camera
	 */
	Tizen::Base::String GetCameraModel(void) const;

	/**
	 * Gets the version of either the software or the firmware of the camera or the image input device
	 * used to generate the image.
	 *
	 * @since		2.0
	 *
	 * @return		The version of either the software or the firmware of the camera or the image input device
	 *					used to generate the image
	 */
	Tizen::Base::String GetSoftware(void) const;

	/**
	 * Gets the date and time of the created content.
	 *
	 * @since		2.0
	 *
	 * @return		The date and time of the created content
	 */
	Tizen::Base::String GetDateTime(void) const;

	/**
	 * Gets the latitude of the image.
	 *
	 * @since		2.0
	 *
	 * @return		The latitude of the image
	 * @remarks	If there is no latitude in the image, @c -200.0 is returned.
	 */
	double GetLatitude(void) const;

	/**
	 * Gets the longitude of the image.
	 *
	 * @since		2.0
	 *
	 * @return		The longitude of the image
	 * @remarks	If there is no longitude in the image, @c -200.0 is returned.
	 */
	double GetLongitude(void) const;

	/**
	 * Gets the orientation of the image.
	 *
	 * @since		2.0
	 *
	 * @return		The orientation of the image
	 */
	ImageOrientationType GetOrientation(void) const;

	/**
	 * Gets the white balance of the image.
	 *
	 * @since		2.0
	 *
	 * @return		The white balance of the image
	 */
	Tizen::Base::String GetWhiteBalance(void) const;

	/**
	 * Gets the thumbnail image.
	 *
	 * @since			2.0
	 *
	 * @return			A pointer to the thumbnail image
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_DATA_NOT_FOUND	The thumbnail image does not exist.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	Tizen::Graphics::Bitmap* GetThumbnailN(void) const;

	/**
	 * Compares the equality of values between two %ImageMetadata objects by overriding the Tizen::Base::Object::Equals() method.
	 *
	 * @since          2.0
	 *
	 * @return         @c true if all the fields in the objects are equal, @n
	 *                     else @c false
	 * @param[in]    rhs     The Tizen::Base::Object with which the comparison is done
 	 * @remarks		An instance of Tizen::Graphics::Bitmap is not taken into account in the comparisons.
	 */
	virtual bool Equals(const Tizen::Base::Object& rhs) const;

	/**
	 * Gets the hash value of the current instance by overriding the Tizen::Base::Object::GetHashCode() method.
	 *
	 * @since         2.0
	 *
	 * @return        The hash value of the current instance
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since          2.0
	 *
	 * @return         A reference to this instance
	 * @param[in]    rhs An instance of %ImageMetadata
	 */
	ImageMetadata& operator =(const ImageMetadata& rhs);

private:
	friend class _ImageMetadataImpl;
	_ImageMetadataImpl* __pImpl;

};  // class ImageMetadata

}}  // Tizen::Content

#endif  // _FCNT_IMAGE_METADATA_H_
