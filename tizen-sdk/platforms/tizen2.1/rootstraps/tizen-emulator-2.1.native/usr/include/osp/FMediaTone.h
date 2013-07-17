//
// Open Service Platform
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
 * @file			FMediaTone.h
 * @brief			This is the header file for the %Tone class.
 *
 * This header file contains the declarations of the %Tone class.
 */

#ifndef _FMEDIA_TONE_H_
#define _FMEDIA_TONE_H_

#include <FBaseObject.h>
#include <FMediaToneTypes.h>

namespace Tizen { namespace Media
{

/**
 * @class		Tone
 * @brief		This class generates a tone.
 *
 * @since		2.0
 *
 * @remarks
 * The instance of the %Tone class can be played using TonePlayer.
 *
 * The %Tone class generates a tone and provides methods for:
 * - Generating a single tone.
 * - Generating dual tones with two different values of frequencies.
 * - Generating a silent tone for a specified period of interval.
 *
 */
class _OSP_EXPORT_ Tone
	: public Tizen::Base::Object
{
public:
	/**
	* The object is not fully constructed after this constructor is called. @n
	* For full construction, the Construct() method must be called right after calling this constructor.
	*
	*   @since		2.0
	*
	*/
	Tone(void);

	/**
	*	This destructor overrides Tizen::Base::Object::~Object(). @n
	*	The resources are deallocated by this method.
	*	This method must be called in the same thread as the Construct() method.
	*
	*   @since		2.0
	*
	*	@see		Construct()
	*/
	virtual ~Tone(void);

public:
	/**
	* @if OSPDEPREC
	 *	Initializes this instance of %Tone with the values of the specified tone.
	*
	*     @brief	<i> [Deprecated] </i>
	*     @deprecated     This method is deprecated because this method is not used as 2-phase constructor.
	*     @since		2.0
	*
	*	@return		An error code
	*	@param[in]	firstFrequency					The first frequency of the dual tone in Hertz (Hz) @n
	*                                               The range of this parameter is @c 0 Hz to @c 15000 Hz.
	*	@param[in]	secondFrequency					The second frequency of the dual tone in Hertz (Hz) @n
	*                                               The range of this parameter is @c 0 Hz to @c 15000 Hz.
	*	@param[in]	duration						The duration of the tone in milliseconds @n
	*                                               The value of this parameter must be greater than @c 0.
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_OUT_OF_RANGE					A specified input parameter is out of range.
	*	@remarks If both the input frequencies are @c 0 Hz, the tone is set as a silent tone.
	* @endif
	*/
	result Construct(int firstFrequency, int secondFrequency, long duration);


	/**
	* @if OSPDEPREC
	*	Initializes this instance of %Tone with the values of the specified DTMF preset tone.
	*
	*     @brief	<i> [Deprecated] </i>
	*	@deprecated     This method is deprecated because this method is not used as 2-phase constructor.
	*     @since		2.0
	*
	*	@return		An error code
	*	@param[in]	preset							The preset of the DTMF tone
	*	@param[in]	duration						The duration of the tone in milliseconds @n
	*                                               The value of this parameter must be greater than @c 0.
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_OUT_OF_RANGE					A specified input parameter is out of range.
	* @endif
	*/
	result Construct(DtmfPreset preset, long duration);


	/**
	*	Gets the current frequency.
	*
	*   @since		2.0
	*
	*	@return		An error code
	*	@param[out]	firstFrequency					The first frequency of the dual tone in Hertz (Hz)
	*	@param[out]	secondFrequency					The second frequency of the dual tone in Hertz (Hz)
	*	@exception	E_SUCCESS						The method is successful.
	*	@remarks The specified input parameters of this method are @c -1 when an exception occurs.
	*/
	result GetFrequency(int& firstFrequency, int& secondFrequency) const;

	/**
	*	Gets the current duration.
	*
	*   @since		2.0
	*
	*	@return		The duration of the tone
	*	@remarks This method returns @c 0 before the Construct() method is called.
	*/
	long GetDuration(void) const;

	/**
	*   Initializes this instance of %Tone with the values of the specified tone.
	*
	*   @since		2.0
	*
	*   @param[in]       firstFrequency    The first frequency of the dual tone in Hertz (Hz) @n
	*	                                   The range of this parameter is @c 0 Hz to @c 15000 Hz.
	*   @param[in]       secondFrequency   The second frequency of the dual tone in Hertz (Hz) @n
	*                                      The range of this parameter is @c 0 Hz to @c 15000 Hz.
	*   @param[in]       duration          The duration of the tone in milliseconds @n
	*	                                   The value of this parameter must be greater than @c 0.
	*   @remarks If both the input frequencies are @c 0 Hz, the tone is set as a silent tone.
	*/
	Tone(int firstFrequency, int secondFrequency, long duration);

	/**
	* Initializes this instance of %Tone with the values of the specified DTMF preset tone.
	*
	* @since		2.0
	*
	* @param[in]       preset              The preset of the DTMF tone
	* @param[in]       duration            The duration of the tone in milliseconds @n
	*	                                   The value of this parameter must be greater than @c 0.
	*/
	Tone(DtmfPreset preset, long duration);

	/**
	* Compares the specified instance of %Tone with the calling instance.
	*
	* @since		2.0
	*
	* @return             @c true if the values match, @n
	*                     else @c false
	* @param[in]    rhs   The other Tizen::Base::Object to compare
	* @see                Tizen::Base::Object::Equals()
	*/
	virtual bool Equals(const Object& rhs) const;

	/**
	* Gets the hash value of the current instance.
	*
	* @since		2.0
	*
	* @return            The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

	/**
	* Copying of objects using this copy constructor is allowed.
	*
	* @since		2.0
	*
	* @return		The copy of this instance
	* @param[in]	rhs	An instance of %Tone
	*/
	Tone(const Tone& rhs);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since		2.0
	 *
	 * @return		The reference of this instance
	 * @param[in]	rhs 	An instance of %Tone
	 */
	Tone& operator =(const Tone& rhs);

private:
	int __firstFrequency;
	int __secondFrequency;
	long __duration;
	bool __isConstructed;
};

}} // Tizen::Media

#endif
