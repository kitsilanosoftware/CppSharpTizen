//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file		FBaseRtLibrary.h
 * @brief		This is the header file for the dynamic linking library class.
 *
 * This header file contains the declarations of the %Library (DLL) class.
 */

#ifndef _FBASE_RT_LIBRARY_H_
#define _FBASE_RT_LIBRARY_H_

#include <FBaseResult.h>
#include <FBaseString.h>

namespace Tizen { namespace Base { namespace Runtime
{
/**
 * @class Library
 * @brief This is the class for shared library.
 *
 * @since 2.0
 *
 * @final This class is not intended for extension.
 *
 * The %Library class loads the shared library with the given file path.
 * It loads the library in current process' memory space, and application can use this library explicitly.
 */
class _OSP_EXPORT_ Library
	: public Tizen::Base::Object
{
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *  @since 2.0
	 */
	Library(void);

	/**
	 *	This is the destructor for this class.
	 *
	 *  @since 2.0
	 */
	virtual ~Library(void);

	/**
	 * Initializes this instance of %Library with the specified library path. @n
	 * Loads the library in the memory space of the current process.
	 *
	 * @since 2.0
	 *
	 * @return     An error code
	 * @param[in]  libraryPath   The path of the library file
	 * @exception   E_SUCCESS             The method is successful.
	 * @exception   E_LIBRARY_NOT_FOUND   The library cannot be found.
	 * @exception   E_INVALID_ARG         The specified @c libraryPath is an empty string.
	 * @exception   E_OUT_OF_MEMORY       The memory is insufficient.
	 * @exception   E_SYSTEM              A system error has occurred.
	 *
	 */
	result Construct(const Tizen::Base::String& libraryPath);

	/**
	 * Gets the address of the specified symbol from the specified dynamic linking library.
	 *
	 * @since 2.0
	 *
	 * @return             The address of the specified symbol
	 * @param[in] symbol    The symbol name
	 * @exception   E_SUCCESS              The method is successful.
	 * @exception   E_SYMBOL_NOT_FOUND     The symbol cannot be found.
	 * @exception   E_INVALID_ARG          The specified @c symbol is an empty string.
	 * @exception   E_OUT_OF_MEMORY        The memory is insufficient.
	 * @exception   E_SYSTEM               A system error has occurred.
	 *
	 */
	void* GetProcAddress(const Tizen::Base::String& symbol) const;

private:
	Library(const Library& rhs);
	Library& operator =(const Library& rhs);

private:
	friend class _LibraryImpl;
	class _LibraryImpl * __pLibraryImpl;
}; // Library


} } } // Tizen::Runtime


#endif // _FBASE_RT_LIBRARY_H_
