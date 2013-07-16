//
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FShellAppWidgetProviderInfo.h
 * @brief	This is the header file for the %AppWidgetSizeInfo class.
 *
 * This header file contains the declarations of the %AppWidgetSizeInfo class.
 */

#ifndef _FSHELL_APPWIDGET_SIZE_INFO_H_
#define _FSHELL_APPWIDGET_SIZE_INFO_H_

#include <FBaseString.h>
#include <FAppTypes.h>
#include <FGrpFloatDimension.h>

namespace Tizen { namespace Shell
{

class _AppWidgetSizeInfoImpl;

/**
 * @class	AppWidgetSizeInfo
 * @brief	This class provides methods to retrieve size and image path for preview.
 *
 * @since	2.1
 *
 * The %AppWidgetSizeInfo class provides methods to retrieve size and image path for preview.
 */
class _OSP_EXPORT_ AppWidgetSizeInfo
	: public Tizen::Base::Object
{
public:
	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.1
	 */
	virtual ~AppWidgetSizeInfo(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since	2.1
	 *
	 * @param[in]	rhs		An instance of %AppWidgetSizeInfo
	 */
	AppWidgetSizeInfo(const AppWidgetSizeInfo& rhs);

	/**
	 * Gets the size.
	 *
	 * @since	2.1
	 *
	 * @return	The size
	 */
    Tizen::Graphics::FloatDimension GetSize(void) const;

	/**
	 * Gets the image path for preview.
	 *
	 * @since	2.1
	 *
	 * @return	The image path for preview
	 */
    Tizen::Base::String GetPreviewImagePath(void) const;

private:
	//
	// This is the constructor that initializes an instance of %AppWidgetSizeInfo with the specified values.
    // This constructor is intentionally declared as private so that only the platform can create an instance.
	//
	// @since	2.1
	//
	// @param[in]	size		One of the size that the AppWidget provider supports.
	// @param[in]	previewImagePath		The preview image path for the size.
	//
    AppWidgetSizeInfo(Tizen::Graphics::FloatDimension size, const Tizen::Base::String& previewImagePath);

    //
	// This default constructor is intentionally declared as private so that only the platform can create an instance.
	//
	// @since	2.1
	//
	AppWidgetSizeInfo(void);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since	2.1
	//
	AppWidgetSizeInfo& operator =(const AppWidgetSizeInfo& rhs);

private:
    _AppWidgetSizeInfoImpl* __pAppWidgetSizeInfoImpl;

friend class _AppWidgetSizeInfoImpl;
};


}} // Tizen::Shell
#endif /* _FSHELL_APPWIDGET_SIZE_INFO_H_ */
