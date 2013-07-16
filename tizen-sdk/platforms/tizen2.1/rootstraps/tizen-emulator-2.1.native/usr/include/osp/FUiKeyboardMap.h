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
 * @file		FUiKeyboardMap.h
 * @brief		This is the header file for the %KeyboardMap class.
 *
 * This header file contains the declarations of the %KeyboardMap class.
 */

#ifndef _FUI_KEYBOARD_MAP_H_
#define _FUI_KEYBOARD_MAP_H_

#include <FBaseObject.h>
#include <FBaseErrors.h>
#include <FBaseString.h>
#include <FUiIKeyEventListener.h>

namespace Tizen {namespace Ui
{
/**
 * @if OSPDEPREC
 * @enum	KeyboardKeyLabelType
 *
 * Defines the key label types. @n
 * It defines the types of labels that are printed on the corresponding key of the QWERTY keyboard. Only the printing
 * keys have one or more text labels.
 *
 *  @brief <i> [Deprecated]  </i>
 *  @deprecated     This enum is deprecated because it is not supported by the platform.
 *  @since  2.0
 * @endif
 */
enum KeyboardKeyLabelType
{
	/**
	 * @if OSPDEPREC
	 *	The first label to be displayed
	 * @endif
	 */
	KEYBOARD_KEY_LABEL_1 = 0x0000,

	/**
	 * @if OSPDEPREC
	 *	The second label to be displayed after KEY_CAPSLOCK or KEY_FN is pressed
	 * @endif
	 */
	KEYBOARD_KEY_LABEL_2,

	/**
	 * @if OSPDEPREC
	 *	The third label to be displayed when the key is toggled twice (without pressing KEY_CAPSLOCK or KEY_FN)
	 * @endif
	 */
	KEYBOARD_KEY_LABEL_3,

	/**
	 * @if OSPDEPREC
	 *	The fourth label to be displayed when the key is toggled the third time (without pressing KEY_CAPSLOCK or KEY_FN)
	 * @endif
	 */
	KEYBOARD_KEY_LABEL_4,

	/*
	 * @if OSPDEPREC
	 *	The max value
	 * @endif
	 */
	KEYBOARD_KEY_LABEL_MAX = 255
};


/**
 * @if OSPDEPREC
 * @class	KeyboardMap
 * @brief	<i> [Deprecated] </i> This class manages the hardware keyboard key mapping.
 * @deprecated     This class is deprecated because it is not supported by the platform.
 * @since	2.0
 *
 * The %KeyboardMap class maintains a map of hardware keys. You can query the current
 * hardware keyboard type of the device and check the availability of a
 * specific key. Furthermore, you can query the labels that are printed on the
 * hardware keyboard of a specific key.
 *
 * The following example demonstrates how to use the %KeyboardMap class to get the type of the keyboard and the property of each key.
 *
 * @code
 * KeyboardMap* pKeyboardMap = KeyboardMap::GetInstance();
 * if (pKeyboardMap != null)
 * {
 *     // Gets the keyboard type
 *     String type = pKeyboardMap->GetKeyboardType();
 *     AppLog("The current hardware keyboard type = %ls", type.GetPointer());
 *
 *     // Checks properties of the hardware key
 *     bool available = pKeyboardMap->IsKeyAvailable(KEY_A);
 *     bool printing  = pKeyboardMap->IsPrintingKey(KEY_A);
 *     String l1 = pKeyboardMap->GetDisplayableLabel(KEY_A);
 *     String l2 = pKeyboardMap->GetDisplayableLabel(KEY_A, KEYBOARD_KEY_LABEL_2);
 *     String l3 = pKeyboardMap->GetDisplayableLabel(KEY_A, KEYBOARD_KEY_LABEL_3);
 *     String l4 = pKeyboardMap->GetDisplayableLabel(KEY_A, KEYBOARD_KEY_LABEL_4);
 * }
 * @endcode
 * @endif
 */
class _OSP_EXPORT_ KeyboardMap
	: public Tizen::Base::Object
{
public:
	/**
         * @if OSPDEPREC
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated because it is not supported by the platform.
	 * @since		2.0
         * @endif
	 */
	virtual ~KeyboardMap(void);

	/**
         * @if OSPDEPREC
	 * Gets the pointer to the %KeyboardMap instance.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated because it is not supported by the platform.
	 * @since		2.0
	 *
	 * @return  	The current %KeyboardMap instance
         * @endif
	 */
	static KeyboardMap* GetInstance(void);

public:
	/**
         * @if OSPDEPREC
	 * Checks whether the specified key is a printing key (the key has one or more labels printed on the corresponding key).
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated because it is not supported by the platform.
	 * @since		2.0
	 *
	 * @return      @c true if the specified key is a printing key, @n
	 *				else @c false
	 * @param[in]	keyCode     The key
         * @endif
	 */
	bool IsPrintingKey(KeyCode keyCode) const;

	/**
         * @if OSPDEPREC
	 * Checks whether the specified key is available on the current keyboard.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated because it is not supported by the platform.
	 * @since		2.0
	 *
	 * @return      @c true if the specified key is available on the current keyboard, @n
	 *				else @c false
	 * @param[in]	keyCode     The key
         * @endif
	 */
	bool IsKeyAvailable(KeyCode keyCode) const;

	/**
         * @if OSPDEPREC
	 * Gets the name of the keyboard type.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated because it is not supported by the platform.
	 * @since		2.0
	 *
	 * @return		The name of the keyboard type
	 * @remarks		The name of the keyboard type follows the following naming convention: @n
	 *              GENERAL-TYPE_KEY-LAYOUT_LANGUAGE/COUNTRY/REGION (for example, QWERTY_11x4_EUROPE,
	 *              NUMERIC_3x4_EUROPE). @n If the device does not have a keyboard, the method returns "NONE". @n
	 * @remarks
	 * Supported keyboard types
	 * <table>
	 * <tr> <td> Keyboard Type              </td> <td> Languages                        </td> </tr>
	 * <tr> <td> QWERTY_11x4_GLOBAL         </td> <td> English                          </td> </tr>
	 * <tr> <td> QWERTY_11x4_EUROPE         </td> <td> English                          </td> </tr>
	 * <tr> <td> QWERTY_11x4_UK             </td> <td> English                          </td> </tr>
	 * <tr> <td> QWERTY_11x4_FRANCE	        </td> <td> French, English                  </td> </tr>
	 * <tr> <td> QWERTY_11x4_GERMAN         </td> <td> German, English                  </td> </tr>
	 * <tr> <td> QWERTY_11x4_GREECE         </td> <td> Greek, English                   </td> </tr>
	 * <tr> <td> QWERTY_11x4_ITALY          </td> <td> Italian, English                 </td> </tr>
	 * <tr> <td> QWERTY_11x4_NORDIC	        </td> <td> North Germanic                   </td> </tr>
	 * <tr> <td> QWERTY_11x4_RUSSIA         </td> <td> Russian, English                 </td> </tr>
	 * <tr> <td> QWERTY_11x4_SPAIN          </td> <td> Spanish, English                 </td> </tr>
	 * <tr> <td> QWERTY_11x4_TURKEY         </td> <td> English                          </td> </tr>
	 * <tr> <td> QWERTY_11x4_NORTH-AFRICA   </td> <td> English, English                 </td> </tr>
	 * <tr> <td> QWERTY_11x4_ARAB	        </td> <td> Arabic, English                  </td> </tr>
	 * <tr> <td> QWERTY_11x4_IRAN	        </td> <td> Farsi, English                   </td> </tr>
	 * <tr> <td> QWERTY_11x4_PARKISTAN	    </td> <td> Urdu, English                    </td> </tr>
	 * <tr> <td> QWERTY_11x4_ISRAEL	        </td> <td> Hebrew, English                  </td> </tr>
	 * <tr> <td> QWERTY_11x4_CHINA	        </td> <td> English                          </td> </tr>
	 * <tr> <td> QWERTY_11x4_HONGKONG	    </td> <td> Chinese Traditional, English     </td> </tr>
	 * <tr> <td> QWERTY_11x4_SINGAPORE	    </td> <td> English                          </td> </tr>
	 * <tr> <td> QWERTY_11x4_THAILAND	    </td> <td> Thai, English                    </td> </tr>
	 * <tr> <td> QWERTY_11x4_TAIWAN	        </td> <td> Chinese Traditional, English     </td> </tr>
	 * <tr> <td> QWERTY_11x4_VIETNAM	    </td> <td> Vietnamese, English              </td> </tr>
	 * <tr> <td> QWERTY_11x4_JAPAN	        </td> <td> Japanese, English                </td> </tr>
	 * <tr> <td> QWERTY_11x4_KOREA	        </td> <td> Korean, English                  </td> </tr>
	 * <tr> <td> QWERTY_11x4_NORTH-AMERICA	</td> <td> English                          </td> </tr>
	 * </table>
         * @endif
	*/
	Tizen::Base::String GetKeyboardType(void) const;

	/**
         * @if OSPDEPREC
	 * Gets the label of the specified key.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated because it is not supported by the platform.
	 * @since		2.0
	 *
	 * @return      The text of the label, @n
	 *				else an empty string if the specified key is not a printing key or the secondary/tertiary character label is not defined
	 * @param[in]	keyCode     The key
	 * @param[in]	type        The keyboard key label type
         * @endif
	 */
	Tizen::Base::String GetDisplayableLabel(KeyCode keyCode, KeyboardKeyLabelType type = KEYBOARD_KEY_LABEL_1) const;

protected:
	/**
	 * @if OSPDEPREC
	 * This is the default constructor for this class.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated because it is not supported by the platform.
	 * @since		2.0
	 * @endif
	 */
	KeyboardMap(void);

	/**
	 * @if OSPDEPREC
	 * Initializes this instance of %KeyboardMap.
	 *
	 * @brief		<i> [Deprecated] </i>
	 * @deprecated	This class is deprecated because it is not supported by the platform.
	 * @since		2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_IO            An IO error has occurred.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @endif
	 */
	result Construct(void);

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// Gets KeyCode of the specified system key.
	//
	// @since		2.0
	// @return		The key code
	// @param[in]   systemKeyCode   The system key
	//
	KeyCode GetKeyCode(int systemKeyCode) const;

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	// Loads keyboard map table from file.
	//
	// @since		2.0
	// @return		An error code
	// @exception	E_SUCCESS		The method is successful.
	// @exception	E_IO            An unexpected IO error has occurred.
	// @exception	E_SYSTEM		A system error has occurred.
	//
	result LoadKeyboarMapFromFile(void);
private:
	static void InitializeInstance(void);

}; // KeyboardMap

}} // Tizen::Ui

#endif // _FUI_KEYBOARD_MAP_H_
