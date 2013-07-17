//
// Open Service Platform
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
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
 * @file FUiImeTypes.h
 * @brief This is the header file for the data types.
 *
 * This header file contains the declarations of the data types.
 */

#ifndef _FUI_IME_TYPES_H_
#define _FUI_IME_TYPES_H_

namespace Tizen { namespace Ui { namespace Ime {

/**
 * @enum InputMethodType
 *
 * Defines the types of the input method.
 *
 * @since	2.1
 * 
 */
enum InputMethodType
{
	INPUT_METHOD_TYPE_SOFTWARE, /**< On-screen soft input panel */
	INPUT_METHOD_TYPE_HARDWARE /**< Hardware input engine */
};

}}} // Tizen::Ui::Ime

#endif // _FUI_IME_TYPES_H_
