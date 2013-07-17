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
 * @file	FUiAnimVisualElementSurface.h
 * @brief	This is the header file for the %VisualElementSurface class.
 *
 * This header file contains the declarations of the %VisualElementSurface class.
 */

#ifndef _FUI_ANIM_VISUAL_ELEMENT_SURFACE_H_
#define _FUI_ANIM_VISUAL_ELEMENT_SURFACE_H_

#include <FOspConfig.h>
#include <FBaseObject.h>
#include <FGrpDimension.h>
#include <FGrpFloatDimension.h>

namespace Tizen { namespace Graphics
{
	class BufferInfo;
}} // Tizen::Graphics

namespace Tizen { namespace Ui { namespace Animations
{

class DisplayContext;
class _VisualElementSurfaceImpl;

/**
* @class	VisualElementSurface
* @brief	This class provides methods to control %VisualElementSurface.
*
* @since	2.0
*
* The %VisualElementSurface class provides methods to control %VisualElementSurface.
*/
class _OSP_EXPORT_ VisualElementSurface
	: public Tizen::Base::Object
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 */
	VisualElementSurface(void);

	/**
	 * This is the copy constructor for the %VisualElementSurface class.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs					An instance of %VisualElementSurface
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks     It does not perform a deep copy (shared with the source).
	 */
	VisualElementSurface(const VisualElementSurface& rhs);

	/**
	 * Assigns the value of the specified instance to the current instance of %VisualElementSurface.
	 *
	 * @since		2.0
	 *
	 * @param[in]	rhs					An instance of %VisualElementSurface
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks     It does not perform a deep copy (shared with the source).
	 */
	VisualElementSurface& operator =(const VisualElementSurface& rhs);

	/**
	 * This is the default destructor for this class.
	 *
	 * @since		2.0
	 */
	virtual ~VisualElementSurface(void);

public:

	/**
	 * Initializes this instance of %VisualElementSurface with the specified parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	displayContext		The display context of the window
	 * @param[in]	size				The size of the %VisualElementSurface instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		The display context is invalid.
	 * @remarks		The width and height of the @c size parameter is the logical size and must be greater than @c 0.
	 * @remarks		If this condition is not satisfied, the E_OUT_OF_RANGE exception is returned.
	 * @see			Tizen::Ui::Window::GetDisplayContext()
	 */
	result Construct(const DisplayContext& displayContext, const Tizen::Graphics::Dimension& size);

	/**
	 * Initializes this instance of %VisualElementSurface with the specified parameters.
	 *
	 * @since		2.1
	 *
	 * @return		An error code
	 * @param[in]	displayContext		The display context of the window
	 * @param[in]	size				The size of the %VisualElementSurface instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The value of the argument is outside the valid range defined by the method.
	 * @exception	E_INVALID_ARG		The display context is invalid.
	 * @remarks		The width and height of the @c size parameter is the logical size and must be greater than @c 0.
	 * @remarks		If this condition is not satisfied, the E_OUT_OF_RANGE exception is returned.
	 * @see			Tizen::Ui::Window::GetDisplayContext()
	 */
	result Construct(const DisplayContext& displayContext, const Tizen::Graphics::FloatDimension& size);

	/**
	 * Gets the buffer-related information of the %VisualElementSurface instance.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[out]	bufferInfo			The buffer-related information of the surface
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 */
	result GetBufferInfo(Tizen::Graphics::BufferInfo& bufferInfo) const;

	/**
	 * Gets the size of the %VisualElementSurface instance.
	 *
	 * @since		2.0
	 *
	 * @return		The size of the %VisualElementSurface instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an error occurs, this method returns Tizen::Graphics::Dimension(0, 0).
	 */
	Tizen::Graphics::Dimension GetSize(void) const;

	/**
	 * Gets the size of the %VisualElementSurface instance.
	 *
	 * @since		2.1
	 *
	 * @return		The size of the %VisualElementSurface instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @remarks 	The specific error code can be accessed using the GetLastResult() method.
	 * @remarks		If an error occurs, this method returns Tizen::Graphics::Dimension(0, 0).
	 */

	Tizen::Graphics::FloatDimension GetSizeF(void) const;

	/**
	 * Compares the Tizen::Base::Object instance with the calling %VisualElementSurface instance for equivalence.
	 *
	 * @since		2.0
	 *
	 * @return		@c true if the specified instance share the content with the current instance, @n
	 *				else @c false
	 * @param[in]	obj					The object to compare with the current instance
	 * @see			GetHashCode()
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since		2.0
	 *
	 * @return		The hash value of the current instance
	 * @remarks    	The hash code of a buffer depends only upon its remaining elements.
	 */
	virtual int GetHashCode(void) const;


protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void VisualElementSurface_Reserved1(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void VisualElementSurface_Reserved2(void) {}


	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	//
	// This method is reserved and may change its name at any time without prior notice.
	//
	// @since        2.0
	//
	virtual void VisualElementSurface_Reserved3(void) {}


private:

	//
	// This variable is for internal use only. Using this variable can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	/**
	 * @since  2.0
	 */
	_VisualElementSurfaceImpl* __pVisualElementSurfaceImpl;

	friend class _VisualElementSurfaceImpl;

};		// VisualElementSurface


}}}		// Tizen::Ui::Animations

#endif // _FUI_ANIM_VISUAL_ELEMENT_SURFACE_H_

