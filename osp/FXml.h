//
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
 * @file			FXml.h
 * @brief			This is the header file for the Tizen::Xml namespace.
 *
 * This header file contains the introduction of the Tizen::Xml namespace.
 */
#ifndef _FXML_H_
#define _FXML_H_

#include <FBase.h>
#include <stdarg.h>
#include <stdio.h>

namespace Tizen
{
/**
 * @if OSPDEPREC
 * @namespace	Tizen::Xml
 * @brief		<i> [Deprecated] </i> This namespace contains interfaces to manipulate %XML documents.
 *
 * @deprecated	This namespace is deprecated because Libxml2 open source library is supported by Tizen directly. Instead of using this namespace, use Libxml2 open source library directly.
 *
 * @since		2.0
 *
 * @remarks     Include Libxml2 open source library header and use APIs directly without any additional setting.
 *
 *
 *
 *
 *
 * For more information about using Libxml2 open source library, visit <a href="http://www.xmlsoft.org" target="_blank">http://www.xmlsoft.org</a>
 *
 *
 *	@code
// Sample data - map.xml
<?xml version="1.0" encoding="ISO-8859-1" ?>

<map>
	<item>
		<country>United Arab Emirates</country>
		<capital>Abu Dhabi</capital>
	</item>
	
	<item>
		<country>Nigeria</country>
		<capital>Abuja</capital>
	</item>

	<item>
		<country>Ghana</country>
		<capital>Accra</capital>
	</item>
	
	<item>
		<country>Pitcairn Islands</country>
		<capital>Adamstown</capital>
	</item>			
</map>

// Sample code for XmlSample.h
#include <FBase.h>
#include <FUi.h>

class XmlSample :
	public Tizen::Ui::Controls::Form
{
// Construction
public:
	XmlSample(void);
	~XmlSample(void);

public:
	virtual result OnInitializing(void);
};

// Sample code for XmlSample.cpp
#include <libxml/parser.h>
#include "XmlSample.h"

using namespace Tizen::Base;

result
XmlSample::OnInitializing(void)
{
	xmlDocPtr pDocument = null;
	xmlNodePtr pRoot = null;
	xmlNodePtr pCurrentElement = null;

	// Creates a XML document
	pDocument = xmlParseFile("/Home/map.xml");
	pRoot = xmlDocGetRootElement(pDocument);

	for(pCurrentElement = pRoot->children; pCurrentElement; pCurrentElement = pCurrentElement->next)
	{
		String countryName;
		xmlNodePtr pChildElement = null;

		if(pCurrentElement->type == XML_ELEMENT_NODE)
		{
			// Gets the <country> element from the <item> element
			pChildElement = pCurrentElement->children->next;

			if(pChildElement)
			{
				// Gets the content from XML_TEXT_NODE
				Tizen::Base::Utility::StringUtil::Utf8ToString ((char*)pChildElement->children->content, countryName);
				AppLog("country : %S\n", countryName.GetPointer());
			}
		}
	}

	xmlFreeDoc(pDocument);
	return E_SUCCESS;
}
 *	@endcode
 * @endif
 */

namespace Xml
{
#include <libxml/parser.h>
#include <libxml/HTMLparser.h>
#include <libxml/parserInternals.h>
#include <libxml/SAX.h>
#include <libxml/SAX2.h>
#include <libxml/xpath.h>
#include <libxml/xmlmemory.h>

#include <libxml/xmlerror.h>
#include <libxml/tree.h>

#include <libxml/uri.h>
#include <libxml/xmlsave.h>
#include <libxml/xmlunicode.h>
#include <libxml/encoding.h>
#include <libxml/xmlIO.h>
#include <libxml/xmlwriter.h>
#include <libxml/xmlreader.h>
#include <libxml/xpathInternals.h>


}; // Tizen::Xml
}; // Tizen

using namespace Tizen::Xml;

#endif // _FXML_H_
