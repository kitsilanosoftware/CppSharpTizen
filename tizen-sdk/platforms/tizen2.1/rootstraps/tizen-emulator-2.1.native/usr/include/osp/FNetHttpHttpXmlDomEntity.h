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
 * @file		FNetHttpHttpXmlDomEntity.h
 * @brief		This is the header file for the %HttpXmlDomEntity class.
 *
 * This header file contains the declarations of the %HttpXmlDomEntity class.
 */

#ifndef _FNET_HTTP_HTTP_XML_DOM_ENTITY_H_
#define _FNET_HTTP_HTTP_XML_DOM_ENTITY_H_

#include <libxml/tree.h>
#include <FNetHttpHttpTypes.h>
#include <FNetHttpIHttpEntity.h>

#include <FBaseString.h>
#include <FBaseByteBuffer.h>

namespace Tizen { namespace Net { namespace Http
{
class _HttpXmlDomEntityImpl;

/**
 * @class	HttpXmlDomEntity
 * @brief	This class represents a http body for the xml content.
 *
 * @since 2.0
 *
 * The %HttpXmlDomEntity class represents a http body for the xml content. @n
 *
 * The following example demonstrates how to use the %HttpXmlDomEntity class to send the xml content to the server.
 *
 * @code

    #include <FBase.h>
    #include <FNet.h>
    #include <FXml.h>

    using namespace Tizen::Base;
    using namespace Tizen::Net::Http;


    void
    TestHttpXmlDomEntity(void)
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

        xmlDoc* pDocument = MakeDomTree();
        HttpXmlDomEntity* pHttpXmlDomEntity = new HttpXmlDomEntity();
        pHttpXmlDomEntity->Construct(*pDocument, L"UTF-8");

        r = pRequest->SetEntity(*pHttpXmlDomEntity);

        // Sends the HttpTransaction.
        r = pTransaction->Submit();
    }

 * @endcode
 */

class _OSP_EXPORT_ HttpXmlDomEntity
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
	HttpXmlDomEntity(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~HttpXmlDomEntity(void);

	/**
	 * Initializes this instance of %HttpXmlDomEntity with the specified parameters.
	 *
	 * @since       2.0
	 *
	 * @return		An error code
	 * @param[in]	xmlDocument					The DOM instance of the xml content
	 * @param[in]	encodingScheme				The encoding scheme for the document
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ENCODING_RANGE    The document contains code points that are outside the bounds specified by @c encodingScheme.
	 * @exception	E_SYSTEM					A system error has occurred.
	 * @remarks		The default content type is "text/xml".
	 */
	result Construct(const xmlDoc& xmlDocument, const Tizen::Base::String& encodingScheme = L"UTF-8");

private:
	/**
	 * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs			An instance of %HttpXmlDomEntity
	 */
	HttpXmlDomEntity(const HttpXmlDomEntity& rhs);

	/**
	 * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	 *
	 * @param[in]	rhs				An instance of %HttpXmlDomEntity
	 */
	HttpXmlDomEntity& operator =(const HttpXmlDomEntity& rhs);

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
	friend class _HttpXmlDomEntityImpl;
	_HttpXmlDomEntityImpl* __pHttpXmlDomEntityImpl;

}; // HttpXmlDomEntity

} } } // Tizen::Net::Http
#endif // _FNET_HTTP_HTTP_XML_DOM_ENTITY_H_
