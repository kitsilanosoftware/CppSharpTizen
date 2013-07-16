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
 * @file		FNetHttpHttpMultipartEntity.h
 * @brief		This is the header file for the %HttpMultipartEntity class.
 *
 * This header file contains the declarations of the %HttpMultipartEntity class.
 */

#ifndef _FNET_HTTP_HTTP_MULTIPART_ENTITY_H_
#define _FNET_HTTP_HTTP_MULTIPART_ENTITY_H_

#include <FBase.h>
#include <FText.h>
#include <FNetHttpHttpTypes.h>
#include <FNetHttpIHttpEntity.h>

namespace Tizen { namespace Net { namespace Http
{
class _HttpMultipartEntityImpl;

/**
 * @if OSPDEPREC
 * The constant for the default MIME type of the string part.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated  This object is provided only for backward compatibility and will be deleted in the near future.
 *				Use HTTP_STRING_PART_DEFAULT_MIME_TYPE instead of this object.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String STRING_PART_DEFAULT_MIME_TYPE;

/**
 * @if OSPDEPREC
 * The constant for the default MIME type of the file part.
 *
 * @brief <i> [Deprecated] </i>
 * @deprecated  This object is provided only for backward compatibility and will be deleted in the near future.
  *				Use HTTP_FILE_PART_DEFAULT_MIME_TYPE instead of this object.
 * @since	2.0
 * @endif
 */
_OSP_EXPORT_ extern const Tizen::Base::String FILE_PART_DEFAULT_MIME_TYPE;

/**
 * The constant for the default MIME type of the string part ("text/plain").
 *
 * @since	2.0
 */
_OSP_EXPORT_ extern const wchar_t HTTP_STRING_PART_DEFAULT_MIME_TYPE[];

/**
 * The constant for the default MIME type of the file part ("application/octet-stream").
 *
 * @since	2.0
 */
_OSP_EXPORT_ extern const wchar_t HTTP_FILE_PART_DEFAULT_MIME_TYPE[];

/**
 * @class	HttpMultipartEntity
 * @brief	This class represents a multipart/form-data entity as defined in RFC 2388.
 *
 * @since 2.0
 *
 *  The %HttpMultipartEntity class represents a multipart/form-data entity as defined in RFC 2388.
 *  The multipart/form-data entity contains a series of parts.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/net/http_connectivity.htm">HTTP Guide</a>.
 *
 * The following example demonstrates how to use the %HttpMultipartEntity class to upload the content to the server.
 *
 * @code

    #include <FBase.h>
    #include <FNet.h>

    using namespace Tizen::Base;
    using namespace Tizen::Net::Http;

    void
    TestHttpMultipartEntity(void)
    {
        result r = E_SUCCESS;
        HttpSession* pSession = null;
        HttpTransaction* pTransaction = null;
        HttpRequest* pRequest = null;
        HttpMultipartEntity* pMultipartEntity = null;
        String hostAddr(L"http://www.tizen.org");

        // Creates an HTTP session.
        pSession = new HttpSession();
        r = pSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, null, hostAddr, null);

        pTransaction = pSession->OpenTransactionN();
        r = pTransaction->AddHttpTransactionListener(*this);
        r = pTransaction->SetHttpProgressListener(*this);

        pRequest = pTransaction->GetRequest();
        pRequest->SetMethod(NET_HTTP_METHOD_POST);
        r = pRequest->SetUri(L"http://www.tizen.org/test");

        pMultipartEntity = new HttpMultipartEntity();
        r = pMultipartEntity->Construct();

        r = pMultipartEntity->AddStringPart(L"title", L"Tizen logo");
        r = pMultipartEntity->AddStringPart(L"date", L"2010-12-25");
        r = pMultipartEntity->AddFilePart(L"upload", L"/Home/Tizen.jpg", L"Tizen.jpg", L"image/jpeg", L"ISO-8859-1");

        r = pRequest->SetEntity(*pMultipartEntity);
        r = pTransaction->Submit();
    }

 * @endcode
 */

class _OSP_EXPORT_ HttpMultipartEntity
	: public Tizen::Base::Object
	, public IHttpEntity
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. @n
	 * For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since       2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	HttpMultipartEntity(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~HttpMultipartEntity(void);

	/**
	 * Initializes this instance of %HttpMultipartEntity.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(void);

	/**
	 * Initializes this instance of %HttpMultipartEntity with the specified parameters.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	boundary			The boundary of multipart/form-data
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(const Tizen::Base::String& boundary);

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs		An instance of %HttpMultipartEntity
	 */
	HttpMultipartEntity(const HttpMultipartEntity& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %HttpMultipartEntity
	 */
	HttpMultipartEntity& operator =(const HttpMultipartEntity& rhs);

public:
	/**
	 * Gets the length of the request content.
	 *
	 * @since       2.0
	 *
	 * @return		The length of the content, @n
	 *				else @c -1 if the content length is unknown
	 */
	virtual long long GetContentLength(void) const;

	/**
	 * Gets the type of the request content.
	 *
	 * @since       2.0
	 *
	 * @return		The type of the content
	 */
	virtual Tizen::Base::String GetContentType(void) const;

	/**
	 * Adds the string part to %HttpMultipartEntity with the default MIME type and character set.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	name						The name of the part
	 * @param[in]	text						The text of the part @n
	 *											The value of @c text is encoded using the default character encoding standard ("ISO-8859-1").
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_INVALID_ENCODING_RANGE    The @c text contains code points that are outside the bounds specified by @c encoding.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		The default MIME type is "text/plain".
	 */
	result AddStringPart(const Tizen::Base::String& name, const Tizen::Base::String& text);

	/**
	 * Adds the string part to %HttpMultipartEntity.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	name						The name of the part
	 * @param[in]	text						The text of the part
	 * @param[in]	mimeType					The MIME type of @c text
	 * @param[in]	charset						The character set of @c text
	 * @param[in]	encoding					An encoding scheme for the specified @c text
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_INVALID_ENCODING_RANGE    The @c text contains code points that are outside the bounds specified by @c encoding.
	 * @exception	E_SYSTEM					A system error has occurred.
	 */
	result AddStringPart(const Tizen::Base::String& name, const Tizen::Base::String& text, const Tizen::Base::String& mimeType, const Tizen::Base::String& charset, const Tizen::Text::Encoding& encoding);

	/**
	 * Adds the file part to %HttpMultipartEntity with the default MIME type.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	name				The name of the part
	 * @param[in]	filePath			The path of the file to upload
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The default MIME type is "application/octet-stream".
	 */
	result AddFilePart(const Tizen::Base::String& name, const Tizen::Base::String& filePath);

	/**
	 * Adds the file part to %HttpMultipartEntity.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	name				The name of the part
	 * @param[in]	filePath			The path of the file to upload
	 * @param[in]	fileName			The file name of the part
	 * @param[in]	mimeType			The MIME type of the content
	 * @param[in]	charset				The character set of the content
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result AddFilePart(const Tizen::Base::String& name, const Tizen::Base::String& filePath, const Tizen::Base::String& fileName, const Tizen::Base::String& mimeType, const Tizen::Base::String& charset);

	/**
	 * Adds the binary part to %HttpMultipartEntity with the default MIME type.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	name				The name of the part
	 * @param[in]	fileName			The file name of the part
	 * @param[in]	buffer				The buffer of file to upload
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The default MIME-type is "application/octet-stream".
	 */
	result AddFilePartByBuffer(const Tizen::Base::String& name, const Tizen::Base::String& fileName, const Tizen::Base::ByteBuffer& buffer);

	/**
	 * Adds the binary part to %HttpMultipartEntity.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	name				The name of the part
	 * @param[in]	fileName			The file name of the part
	 * @param[in]	buffer				The buffer of the file to upload
	 * @param[in]	mimeType			The MIME type of the content
	 * @param[in]	charset				The character set of the content
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result AddFilePartByBuffer(const Tizen::Base::String& name, const Tizen::Base::String& fileName, const Tizen::Base::ByteBuffer& buffer, const Tizen::Base::String& mimeType, const Tizen::Base::String& charset);

protected:
	/**
	 * Checks whether the next data exists.
	 *
	 * @since       2.0
	 *
	 * @return		@c true if the next data exists, @n
	 *				else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception   E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual bool HasNextData(void);

	/**
	 * Gets the next data.
	 *
	 * @since       2.0
	 *
	 * @return		The buffer to be read
	 * @param[in]	recommendedSize			The recommended size of the data to send
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception   E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetNextDataN(int recommendedSize);

private:
	friend class _HttpMultipartEntityImpl;
	_HttpMultipartEntityImpl* __pHttpMultipartEntityImpl;

}; // HttpMultipartEntity

} } } // Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_MULTIPART_ENTITY_H_
