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
 * @file		FBaseUtilInflator.h
 * @brief		This is the header file for the %Inflator class.
 *
 * This header file contains the declarations of the %Inflator class.
 */
#ifndef _FBASE_UTIL_INFLATOR_H_
#define _FBASE_UTIL_INFLATOR_H_

#include <FBaseByteBuffer.h>
#include <FBaseUtilTypes.h>


namespace Tizen { namespace Base { namespace Utility
{
/**
 * @class	Inflator
 * @brief	This class provides the inflate functionality using zlib.
 *
 * @since 2.0
 *
 * The %Inflator class provides the inflate functionality using zlib.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/utility_namespace.htm">Utility</a>.
 *
 * The following example demonstrates how to use the %Inflator class.
 *
 * @code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Utility;
 *
 *	void
 *	MyClass::InflatorSample(ByteBuffer &buf)
 *	{
 *		ByteBuffer* pBuf1 = null;
 *		ByteBuffer* pBuf2 = null;
 *
 *		// Inflates the buf from the current position to limit of the buf
 *		pBuf1 = Inflator::InflateN(buf);
 *		if (null == pBuf1)
 *		{
 *			// Error case handling...
 *		}
 *		// pBuf1 : Inflated Data of buf
 *
 *
 *		// Inflates the buf from the current position to (limit-2) of the buf
 *		pBuf2 = Inflator::InflateN(buf, (buf.GetLimit()-2));
 *		if (null == pBuf2)
 *		{
 *			// Error case handling...
 *		}
 *
 *
 *		delete pBuf1;
 *		delete pBuf2;
 *	}
 *
 * @endcode
 */
class _OSP_EXPORT_ Inflator
{
public:
	/**
	 * Inflates the number of bytes from the source byte buffer to the output byte buffer.
	 *
	 * @since 2.0
	 *
	 * @return			A pointer to the ByteBuffer instance with the inflated equivalent of the source buffer @n
	 *					The buffer's limit is the length of the inflated data, @n
	 * 					else @c null if an exception occurs.
	 * @param[in]		src	The buffer to inflate
	 * @param[in]		byteCount	The number of bytes to inflate from the source buffer
	 * @exception		E_SUCCESS	The method is successful.
	 * @exception		E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception		E_SYSTEM	A system error has occurred.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				Tizen::Base::Utility::Deflator
	 */
	static ByteBuffer* InflateN(const ByteBuffer& src, int byteCount);

	/**
	 * Inflates data from the source byte buffer to the output byte buffer.
	 *
	 * @since 2.0
	 *
	 * @return			A pointer to the ByteBuffer instance with the inflated equivalent of the source buffer @n
	 *					The buffer's limit is the length of the inflated data, @n
	 * 					else @c null if an exception occurs.
	 * @param[in]		src	The buffer to inflate
	 * @exception		E_SUCCESS	The method is successful.
	 * @exception		E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception		E_SYSTEM	A system error has occurred.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				Tizen::Base::Utility::Deflator
	 */
	static ByteBuffer* InflateN(const ByteBuffer& src);

private:
	static ByteBuffer* __InflateN(const ByteBuffer& src, int byteCount);

	/**
	 * This default constructor is intentionally declared as private because this class cannot be constructed.
	 */
	Inflator(void);

	/**
	 * This destructor is intentionally declared as private because this class cannot be constructed.
	 */
	~Inflator(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs	An instance of %Inflator
	 */
	Inflator(const Inflator& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs	An instance of %Inflator
	 */
	Inflator& operator =(const Inflator& rhs);

}; // Inflator

}}} // Tizen::Base::Utility

#endif // _FBASE_UTIL_INFLATOR_H_
