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
 * @file	FUiUiConfiguration.h
 * @brief	This is the header file for the %UiConfiguration class.
 *
 * This header file contains the declarations of the %UiConfiguration class.
 */

#ifndef _FUI_UI_CONFIGURATION_H_
#define _FUI_UI_CONFIGURATION_H_

#include <FGrpColor.h>
#include <FUiUiConfigurationTypes.h>

namespace Tizen { namespace Base {
class String;
}} // Tizen::Base

namespace Tizen { namespace Ui {

/**
 * @class	UiConfiguration
 * @brief	This class provides various utility methods for UI configuration.
 *
 * @since 2.0
 *
 * The %UiConfiguration class provides various utility methods for UI configuration.
 *
 */
class _OSP_EXPORT_ UiConfiguration
{
public:
	/**
	 * Sets the default font to all the Controls.
	 *
	 * @since 2.0
	 *
	 * @return	An error code
	 * @param[in]	fontName			The app font name or system font name @n
	 *									The app font name is retrieved using Tizen::Graphics::GetFaceName(Tizen::Base::String& filepath).
	 *									The system font name is retrieved using Tizen::Graphics::Font::GetSystemFontListN().
	 *									Sets an empty string if you want to reset
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_FILE_NOT_FOUND	The specified font cannot be found or accessed.
	 * @remarks						At First, the value of fontName is considered app font name if it matches one of the face names of the font files which is located in '/res/font'.
	 *									If not, the value of fontName is considered system font name if it matches one of the retrieved values using GetSystemFontListN().
	 * @remarks						The control first attempt to find the control font. If it fails, then it searches for the application default font and the system font, in sequence.
	 * @see							GetDefaultFont()
	*/
	static result SetDefaultFont(const Tizen::Base::String& fontName);

	/**
	* Gets the default font for all the Controls.
	*
	* @since 2.0
	*
	* @return							The app font name or system font name @n
	*									else an empty string if the default font is not set
	* @see								SetDefaultFont()
	*/
	static Tizen::Base::String GetDefaultFont(void);

	/**
	 * Sets the font of the control with the specified file name.
	 *
	 * @since 2.1
	 *
	 * @return             An error code
	 * @param[in]  fileName								The file name of a font-resource located in @b '/res/font', @n
	 *														else sets an empty string to reset
	 * @exception  E_SUCCESS								The method is successful.
	 * @exception  E_FILE_NOT_FOUND						The specified font cannot be found or accessed.
	 * @exception  E_UNSUPPORTED_FORMAT				The specified font format is not supported.
	 * @see        GetDefaultFontFile()
	*/
	static result SetDefaultFontFromFile(const Tizen::Base::String& fileName);

	/**
	 * Gets a font file name of the control.
	 *
	 * @since 2.1
	 *
	 * @return					The font name set in the control  @n
	 *							else an empty string if the font is not set
	 * @see					SetDefaultFontFromFile()
	*/
	static Tizen::Base::String GetDefaultFontFile(void);

	/**
	* Gets the actual font size.
	*
	* @since 2.1
	*
	* @return					An actual font size of given font size string
	* @param[in]  sizeString		The predefined string value, such as "giant", "huge", "large", "medium", or "small" @n
	*						It is case-insensitive and can be retrieved using Tizen::System::SettingInfo::GetValue().
	* @remarks				If the specified @c sizeString is not defined, @c -1 is returned.
	*/
	static float GetFontSize(const Tizen::Base::String& sizeString);

	/**
	* Gets the color of controls.
	*
	* @since 2.1
	*
	* @return     The color of the given color key
	* @param[in]  colorKey			The color key
	* @exception  E_SUCCESS		The method is successful.
	* @exception  E_KEY_NOT_FOUND	The specified color cannot be found or accessed.
	* @remarks
	*			- Color keys are defined in FUiUiConfigurationTypes.h.
	*			- The specific error code can be accessed using the GetLastResult() method.
	*			- Using the return value without checking the return value of GetLastResult() is prohibited.
	*/
	static Tizen::Graphics::Color GetColor(int colorKey);

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
