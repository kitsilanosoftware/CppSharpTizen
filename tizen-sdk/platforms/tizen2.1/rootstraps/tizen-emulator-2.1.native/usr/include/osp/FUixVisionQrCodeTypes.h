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
 * @file     FUixVisionQrCodeTypes.h
 * @brief    This is the header file for the QR code types.
 *
 * This header file contains the declarations of the QR code types.
 */

#ifndef _FUIX_VISION_QR_CODE_TYPES_H_
#define _FUIX_VISION_QR_CODE_TYPES_H_

namespace Tizen { namespace Uix { namespace Vision
{

/**
 * @enum     QrCodeErrorCorrectionLevel
 *
 * Defines possible error correction levels for QR code.
 *
 * @since    2.1
 */
enum QrCodeErrorCorrectionLevel
{
    QR_CODE_ERROR_CORRECTION_LEVEL_L = 1, /** < Low */
    QR_CODE_ERROR_CORRECTION_LEVEL_M = 2, /** < Medium */
    QR_CODE_ERROR_CORRECTION_LEVEL_Q = 3, /** < Quartile */
    QR_CODE_ERROR_CORRECTION_LEVEL_H = 4  /** < High */
};

/**
 * @enum     QrCodeMode
 *
 * Defines possible encoding modes for QR codes.
 *
 * @since    2.1
 */
enum QrCodeMode
{
    QR_CODE_MODE_ALPHANUMERIC = 0,  /** < Alphanumeric */
    QR_CODE_MODE_BYTE = 1,          /** < Byte */
    QR_CODE_MODE_UTF8 = 2           /** < UTF8 */
};

} } } //Tizen::Uix::Vision

#endif // _FUIX_VISION_QR_CODE_TYPES_H_
