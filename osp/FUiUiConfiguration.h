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
 * @file	FUiUiConfiguration.h
 * @brief	This is the header file for the %UiConfiguration class.
 *
 * This header file contains the declarations of the %UiConfiguration class.
 */

#ifndef _FUI_UI_CONFIGURATION_H_
#define _FUI_UI_CONFIGURATION_H_

namespace Tizen { namespace Base {
class String;
}} // Tizen::Base

namespace Tizen { namespace Ui {

class _OSP_EXPORT_ UiConfiguration
{
public:
	/**
	 * Sets the default font to all the Controls.
	 *
	 * @since 2.0
	 *
	 * @return	An error code
	 * @param[in]	fontName	The app font name or system font name @n
	 *							The app font name is retrieved using Tizen::Graphics::GetFaceName(Tizen::Base::String& filepath).
	 *							The system font name is retrieved using Tizen::Graphics::Font::GetSystemFontListN().
	 *							Sets an empty string if you want to reset
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_FILE_NOT_FOUND	The specified font cannot be found or accessed.
	 * @remarks		At First, the value of fontName is considered app font name if it matches one of the face names of the font files which is located in '/res/font'.
	 *				If not, the value of fontName is considered system font name if it matches one of the retrieved values using GetSystemFontListN().
	 * @remarks		The control first attempt to find the control font. If it fails, then it searches for the application default font and the system font, in sequence.
	 * @see			GetDefaultFont()
	 */
	static result SetDefaultFont(const Tizen::Base::String& fontName);

	/**
	 * Gets the default font for all the Controls.
	 *
	 * @since 2.0
	 *
	 * @return                   The app font name or system font name @n
	 *                                         else an empty string if the default font is not set
	 * @see         SetDefaultFont()
	 */
	static Tizen::Base::String GetDefaultFont(void);


private:
	//
	// This default constructor is intentionally declared as private because this class cannot be constructed.
	//
	UiConfiguration(void);

	//
	// This destructor is intentionally declared as private because this class cannot be constructed.
	//
	 ~UiConfiguration(void);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	UiConfiguration(const UiConfiguration& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	UiConfiguration& operator =(const UiConfiguration& rhs);

}; // UiConfiguration

}} // Tizen::Ui

#endif // _FUI_UI_CONFIGURATION_H_
