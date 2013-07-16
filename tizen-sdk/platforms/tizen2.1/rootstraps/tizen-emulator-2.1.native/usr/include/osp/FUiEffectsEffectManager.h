//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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
* @file        FUiEffectsEffectManager.h
* @brief       This is the header file for the %EffectManager class.
*
* This header file contains the declarations of the %EffectManager class.
*/

#ifndef _FUI_EFFECTS_EFFECT_MANAGER_H_
#define _FUI_EFFECTS_EFFECT_MANAGER_H_

#include <FBaseObject.h>
#include <FUiEffectsTypes.h>


namespace Tizen { namespace Base {
class String;
}} // Tizen::Base


namespace Tizen { namespace Ui { namespace Effects
{

class _EffectManagerImpl;
class Effect;

/**
 * @class			EffectManager
 * @brief This class contains API for managing effects.
 *
 * @since 2.0
 *
 * The %EffectManager class contains API for managing effects.
 */
class _OSP_EXPORT_ EffectManager
	: public Tizen::Base::Object
{
public:
	/**
	 * Gets the effect manager instance.
	 *
	 * @since 2.0
	 *
	 * @return			A pointer to the %EffectManager instance
	 * @exception		E_SUCCESS			   The %EffectManager instance is constructed successfully.
	 * @exception		E_OPERATION_FAILED	   The system has failed to initialize the 3D system.
	 */
	 static EffectManager* GetInstance(void);

	/**
	 * Destroys all previously created effects and their resources. @n
	 * Application can use OpenGL APIs only after invoking this method.
	 *
	 * @since 2.0
	 */
	 static void DestroyInstance(void);

	/**
	 * Creates a new effect from the specified effect file.
	 *
	 * @since 2.0
	 *
	 * @return A pointer to the Effect instance, @n
	 *			else @c null if an error occurs
	 * @param [in]		filePath			   The file path of the effect
	 * @exception		E_SUCCESS			   The effect is created successfully.
	 * @exception		E_FILE_NOT_FOUND	   The specified effect file does not exist.
	 * @exception		E_PARSING_FAILED	   A syntax error exists in the effect file.
	 * @remarks 		The DestroyEffect() method must be used to destroy the Effect instance returned.
	 * @see DestroyEffect()
	 */
	 Effect* CreateEffect(const Tizen::Base::String& filePath);

	/**
	 * Destroys the Effect instance.
	 *
	 * @since 2.0
	 *
	 * @param [in]		effect				 The Effect instance to destroy
	 * @see CreateEffect()
	 */
	 void DestroyEffect(Effect& effect);

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void EffectManager_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void EffectManager_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since 2.0
	//
	virtual void EffectManager_Reserved3(void) {}

private:
	// This default constructor is intentionally declared as private to implement the Singleton semantic.
	EffectManager(void);

	// This destructor is intentionally declared as private to implement the Singleton semantic.
	virtual ~EffectManager(void);

	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	EffectManager(const EffectManager& rhs);

	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	EffectManager& operator=(const EffectManager& rhs);

private:
	friend class _EffectManagerImpl;
	_EffectManagerImpl* __pEffectManagerImpl;
}; //EffectManager

}}} // Tizen::Ui::Effects

#endif // _FUI_EFFECTS_EFFECT_MANAGER_H_

