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
 * @file		FNetHttpHttpStringEntity.h
 * @brief		This is the header file for the %HttpStringEntity class.
 *
 * This header file contains the declarations of the %HttpStringEntity class.
 */

#ifndef _FNET_HTTP_HTTP_STRING_ENTITY_H_
#define _FNET_HTTP_HTTP_STRING_ENTITY_H_

#include <FNetHttpHttpTypes.h>
#include <FNetHttpIHttpEntity.h>

namespace Tizen { namespace Base
{
class String;
class ByteBuffer;
} }

namespace Tizen { namespace Text
{
class Encoding;
} }

namespace Tizen { namespace Net { namespace Http
{
class _HttpStringEntityImpl;

/**
 * @class	HttpStringEntity
 * @brief	This class represents a http body for the text content.
 *
 * @since 2.0
 *
 * The %HttpStringEntity class represents a http body for the text content.
 *
 * The following example demonstrates how to use the %HttpStringEntity class to send the content for text to the server using this class.
 *
 * @code

    #include <FBase.h>
    #include <FNet.h>

    using namespace Tizen::Base;
    using namespace Tizen::Net::Http;

    void
    TestHttpStringEntity(void)
    {
        result r = E_SUCCESS;

        HttpSession* pSession = null;
        HttpTransaction* pTransaction = null;
        HttpRequest* pRequest = null;
        String hostAddr(L"http://www.tizen.org");

        pSession = new HttpSession();
        r = pSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, null, hostAddr, null);

        pTransaction = pSession->OpenTransactionN();
        r = pTransaction->AddHttpTransactionListener(*this);

        pRequest = const_cast<HttpRequest*>(pTransaction->GetRequest());
        r = pRequest->SetUri(L"http://www.tizen.org/test");
        r = pRequest->SetMethod(NET_HTTP_METHOD_POST);

        HttpStringEntity* pHttpStringEntity = new HttpStringEntity();
        pHttpStringEntity->Construct(L"test content body");

        r = pRequest->SetEntity(*pHttpStringEntity);

        // Sends the HttpTransaction.
        r = pTransaction->Submit();
    }

 * @endcode
 */

class _OSP_EXPORT_ HttpStringEntity
	: public Tizen::Base::Object
	, public IHttpEntity
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since       2.0
	 *
	 * @remarks		After creating an instance of this class, the Construct() method
	 *              must be called explicitly to initialize this instance.
	 */
	HttpStringEntity(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~HttpStringEntity(void);

	/**
	 * Initializes this instance of %HttpStringEntity with the default content type and character set.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	text						The text of the body
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ENCODING_RANGE    The specified @c text contains code points that are outside the bounds of the default encoding standard ("ISO-8859-1").
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		The default content type is "text/plain" and default charset is "ISO-8859-1".
	 */
	result Construct(const Tizen::Base::String& text);

	/**
	 * Initializes this instance of %HttpStringEntity with the specified parameters.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	text						The text of the body
	 * @param[in]	contentType					The content type of @c text
	 * @param[in]	charset						The character set of @c text
	 * @param[in]	encoding					An encoding scheme for the specified @c text
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_INVALID_ENCODING_RANGE    The specified @c text contains code points that are outside the bounds of @c encoding.
	 * @exception	E_SYSTEM					A system error has occurred.
	 */
	result Construct(const Tizen::Base::String& text, const Tizen::Base::String& contentType, const Tizen::Base::String& charset, const Tizen::Text::Encoding& encoding);


private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %HttpStringEntity
	 */
	HttpStringEntity(const HttpStringEntity& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs				An instance of %HttpStringEntity
	 */
	HttpStringEntity& operator =(const HttpStringEntity& rhs);

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

protected:
	/**
	 * Checks whether the next data exists.
	 *
	 * @since       2.0
	 *
	 * @return		@c true if the next data exists, @n
	 *				else @c false
	 * @exception	E_SUCCESS				The method is successful.
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
	 * @exception   E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetNextDataN(int recommendedSize);

private:
	friend class _HttpStringEntityImpl;
	_HttpStringEntityImpl* __pHttpStringEntityImpl;

}; // HttpStringEntity

} } } // Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_STRING_ENTITY_H_
