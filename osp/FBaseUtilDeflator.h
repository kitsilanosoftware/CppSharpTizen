//
// Open Service Platform
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
 * @file		FBaseUtilDeflator.h
 * @brief		This is the header file for the %Deflator class.
 *
 * This header file contains the declarations of the %Deflator class.
 */
#ifndef _FBASE_UTIL_DEFLATOR_H_
#define _FBASE_UTIL_DEFLATOR_H_

#include <FBaseByteBuffer.h>
#include <FBaseUtilTypes.h>


namespace Tizen { namespace Base { namespace Utility
{
/**
 * @class	Deflator
 * @brief	This class provides the deflate functionality using zlib.
 *
 * @since 2.0
 *
 * The %Deflator class provides the deflate functionality using zlib.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/utility_namespace.htm">Utility</a>.
 *
 * The following example demonstrates how to use the %Deflator class.
 *
 *	@code
 *
 *	#include <FBase.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Utility;
 *
 *	void
 *	MyClass::DeflatorSample(ByteBuffer &buf)
 *	{
 *		ByteBuffer* pBuf1 = null;
 *		ByteBuffer* pBuf2 = null;
 *		ByteBuffer* pBuf3 = null;
 *
 *		// Deflates the buf from the current position to limit of the buf
 *		pBuf1 = Deflator::DeflateN(buf);
 *		if (null == pBuf1)
 *		{
 *			// Error case handling...
 *		}
 *		// pBuf1: Deflated data of buf
 *
 *		// Deflates the buf from the current position to (limit-2) of the buf
 *		pBuf2 = Deflator::DeflateN(buf, (buf.GetLimit()-2));
 *		if (null == pBuf2)
 *		{
 *			// Error case handling...
 *		}
 *
 *		// Deflates the buf from the current position to limit of the buf for BEST_COMPRESSION
 *		pBuf3 = Deflator::DeflateN(buf, BEST_COMPRESSION);
 *		if (null == pBuf3)
 *		{
 *			// Error case handling...
 *		}
 *
 *
 *		delete pBuf1;
 *		delete pBuf2;
 *		delete pBuf3;
 *	}
 *
 *	@endcode
 */
class _OSP_EXPORT_ Deflator
{
public:
	/**
	 * Deflates the number of bytes from the source byte buffer to the output byte buffer.
	 *
	 * @since 2.0
	 *
	 * @return			A pointer to the ByteBuffer instance with the deflated equivalent of the source buffer @n
	 *					The buffer's limit is the length of the deflated data, @n
	 * 					else @c null if an exception occurs.
	 * @param[in]		src	The buffer to deflate
	 * @param[in]		byteCount	The number of bytes to deflate from the source buffer
	 * @param[in]		level		Set to @c BEST_SPEED or @c BEST_COMPRESSION @n
	 * 								By default, it is set to @c DEFAULT_COMPRESSION.
	 * @exception		E_SUCCESS	The method is successful.
	 * @exception		E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception		E_SYSTEM	A system error has occurred.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				Tizen::Base::Utility::Inflator
	 */
	static ByteBuffer* DeflateN(const ByteBuffer& src, int byteCount, CompressionLevel level = DEFAULT_COMPRESSION);

	/**
	 * Deflates data from the source byte buffer to the output byte buffer.
	 *
	 * @since 2.0
	 *
	 * @return			A pointer to the ByteBuffer instance with the deflated equivalent of the source buffer @n
	 *					The buffer's limit is the length of the deflated data, @n
	 * 					else @c null if an exception occurs.
	 * @param[in]		src		The buffer to deflate
	 * @param[in]		level	Set to @c BEST_SPEED or @c BEST_COMPRESSION @n
	 * 							By default, it is set to @c DEFAULT_COMPRESSION.
	 * @exception		E_SUCCESS	The method is successful.
	 * @exception		E_INVALID_ARG	A specified input parameter is invalid.
	 * @exception		E_SYSTEM	A system error has occurred.
	 * @remarks			The specific error code can be accessed using the GetLastResult() method.
	 * @see				Tizen::Base::Utility::Inflator
	 */
	static ByteBuffer* DeflateN(const ByteBuffer& src, CompressionLevel level = DEFAULT_COMPRESSION);

private:
	static ByteBuffer* __DeflateN(const ByteBuffer& src, int byteCount, CompressionLevel level);

	/**
	 * This default constructor is intentionally declared as private because this class cannot be constructed.
	 */
	Deflator(void);

	/**
	 * This destructor is intentionally declared as private because this class cannot be constructed.
	 */
	~Deflator(void);

	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs	An instance of %Deflator
	 */
	Deflator(const Deflator& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs	An instance of %Deflator
	 */
	Deflator& operator =(const Deflator& rhs);

}; // Deflator

}}} // Tizen::Base::Utility

#endif // _FBASE_UTIL_DEFLATOR_H_
