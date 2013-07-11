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
 * @file		FBaseUtilUri.h
 * @brief		This is the header file for the %Uri class.
 *
 * This header file contains the declarations of the %Uri class.
 */
#ifndef _FBASE_UTIL_URI_H_
#define _FBASE_UTIL_URI_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FBaseBuffer.h>


namespace Tizen { namespace Base { namespace Utility
{

/**
 * @class	Uri
 * @brief	This class provides useful methods for URI.
 *
 * @since 2.0
 *
 * The %Uri class represents a Uniform Resource Identifier (URI) as defined by RFC2396 and provides accessors
 * which access the URI component.
 * It also provides methods for creating, accessing, normalizing, resolving, and relativizing %Uri instances.
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/base/uri.htm">URI</a>.
 *
 * The following example demonstrates how to use the %Uri class.
 *
 * @code
 *
 * #include <FBase.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Base::Utility;
 *
 * void
 * MyClass::UriSample(void)
 * {
 *		String base(L"http://www.samsung.com");
 *		String against(L"/osp/framework/index.html");
 *		String resolveString(L"http://www.samsung.com/osp/framework/index.html");
 *
 *		Uri baseUri;
 *		baseUri.SetUri(base);
 *
 *		Uri againstUri;
 *		againstUri.SetUri(against);
 *
 *		Uri resultUri;
 *		baseUri.Resolve(againstUri, resultUri);
 *
 *		String resultString = resultUri.ToString();
 *		if (resultString.Equals(resolveString))
 *		{
 *			// ...
 *		}
 *
 * }
 * @endcode
 */
class _OSP_EXPORT_ Uri
	: public Tizen::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since 2.0
	 */
	Uri(void);

	/**
	 * Copying of objects using this copy constructor is allowed.
	 *
	 * @since 2.0
	 *
	 *  @param[in]	uri		An instance of %Uri to copy
	 */
	Uri(const Uri& uri);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since 2.0
	 */
	virtual ~Uri(void);

	/**
	 * Sets the current %Uri instance to the value of the specified instance of %Uri.
	 *
	 * @since 2.0
	 *
	 * @param[in]	uri		An instance of %Uri
	 */
	void SetUri(const Uri& uri);

	/**
	 * Sets the current %Uri instance by parsing a given string.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	str		A string to parse into a URI
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			The specified @c str is an empty string.
	 * @exception	E_INVALID_FORMAT		The specified @c str violates the URI syntax (RFC 2396).
	 */
	result SetUri(const Tizen::Base::String& str);

	/**
	 * Sets an absolute %Uri instance with given components.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	scheme			The scheme
	 * @param[in]	ssp				The scheme-specific-part
	 * @param[in]	fragment		The fragment
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_FORMAT		A component violates the URI syntax(RFC 2396).
	 */
	result SetUri(const Tizen::Base::String& scheme, const Tizen::Base::String& ssp, const Tizen::Base::String& fragment);

	/**
	 * Sets an absolute and hierarchical %Uri instance with the given components.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	scheme			The scheme
	 * @param[in]	userInfo		The user name and authorization
	 * @param[in]	host			The host name
	 * @param[in]	port			The port number
	 * @param[in]	path			The path
	 * @param[in]	query			The query
	 * @param[in]	fragment		The fragment
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_FORMAT		A component violates the URI syntax(RFC 2396).
	 */
	result SetUri(const Tizen::Base::String& scheme, const Tizen::Base::String& userInfo, const Tizen::Base::String& host, int port, const Tizen::Base::String& path, const Tizen::Base::String& query, const Tizen::Base::String& fragment);

	/**
	 * Sets an absolute and hierarchical %Uri instance with the given components.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	scheme			The scheme
	 * @param[in]	host			The host name
	 * @param[in]	path			The path
	 * @param[in]	fragment		The fragment
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_FORMAT		A component violates the URI syntax(RFC 2396).
	 * @remarks	The authority and query component are left empty, and the port is set to @c -1.
	 */
	result SetUri(const Tizen::Base::String& scheme, const Tizen::Base::String& host, const Tizen::Base::String& path, const Tizen::Base::String& fragment);

	/**
	 * Sets an absolute and hierarchical %Uri instance with the given components.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	scheme			The scheme
	 * @param[in]	authority		The authority
	 * @param[in]	path			The path
	 * @param[in]	query			The query
	 * @param[in]	fragment		The fragment
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_FORMAT		A component violates the URI syntax(RFC 2396).
	 */
	result SetUri(const Tizen::Base::String& scheme, const Tizen::Base::String& authority, const Tizen::Base::String& path, const Tizen::Base::String& query, const Tizen::Base::String& fragment);

	/**
	 * Copying of objects using this copy assignment operator is allowed.
	 *
	 * @since 2.0
	 *
	 * @return		A reference to the calling instance
	 * @param[in]	rhs		An instance of %Uri
	 */
	Uri& operator =(const Uri& rhs);

	/**
	 * Gets the value of the authority component.
	 *
	 * @since 2.0
	 *
	 * @return		The value of the authority component, @n
	 *				else an empty string if the authority component is undefined
	 * @remarks		The string returned by this method is equal to the string returned by GetEncodedAuthority(),
	 *				except that all sequences of the escaped octets are decoded.
	 */
	Tizen::Base::String GetAuthority(void) const;

	/**
	 * Gets the value of the fragment component.
	 *
	 * @since 2.0
	 *
	 * @return		The value of the fragment component, @n
	 *				else an empty string if the fragment component is undefined
	 * @remarks		The string returned by this method is equal to the string returned by GetEncodedFragment(),
	 *				except that all sequences of the escaped octets are decoded.
	 */
	Tizen::Base::String GetFragment(void) const;

	/**
	 * Gets the value of the host component.
	 *
	 * @since 2.0
	 *
	 * @return		The value of the host component, @n
	 *				else an empty string if the host component is undefined
	 */
	Tizen::Base::String GetHost(void) const;

	/**
	 * Gets the value of the path component.
	 *
	 * @since 2.0
	 *
	 * @return		The value of the path component, @n
	 *				else an empty string if the path component is undefined
	 * @remarks		The string returned by this method is equal to the string returned by GetEncodedPath(),
	 *				except that all sequences of the escaped octets are decoded.
	 */
	Tizen::Base::String GetPath(void) const;


	/**
	 * Gets the value of the port component.
	 *
	 * @since 2.0
	 *
	 * @return		The value of the port component, @n
	 *				else @c -1 if the port component is undefined
	 */
	int GetPort(void) const;


	/**
	 * Gets the value of the query component.
	 *
	 * @since 2.0
	 *
	 * @return		The value of the query component, @n
	 *				else an empty string if the query component is undefined
	 * @remarks		The string returned by this method is equal to the string returned by GetEncodedQuery(),
	 *				except that all sequences of the escaped octets are decoded.
	 */
	Tizen::Base::String GetQuery(void) const;


	/**
	 * Gets the value of the scheme component.
	 *
	 * @since 2.0
	 *
	 * @return		The value of the query scheme, @n
	 *				else an empty string if the query scheme is undefined
	 */
	Tizen::Base::String GetScheme(void) const;


	/**
	 * Gets the value of the scheme-specific-part component.
	 *
	 * @since 2.0
	 *
	 * @return		The value of the scheme-specific-part component, @n
	 *				else an empty string if the scheme-specific-part component is undefined
	 * @remarks		The string returned by this method is equal to the string returned by GetEncodedSchemeSpecificPart(),
	 *				except that all sequences of the escaped octets are decoded.
	 */
	Tizen::Base::String GetSchemeSpecificPart(void) const;


	/**
	 * Gets the value of the user-info component.
	 *
	 * @since 2.0
	 *
	 * @return		The value of the user-info component, @n
	 *				else an empty string if the user-info component is undefined
	 * @remarks		The string returned by this method is equal to the string returned by GetEncodedUserInfo(),
	 *				except that all sequences of the escaped octets are decoded.
	 */
	Tizen::Base::String GetUserInfo(void) const;


	/**
	 * Gets the encoded value of the authority component. @n
	 * The non-US-ASCII characters in the authority component are encoded to escaped octets.
	 *
	 * @since 2.0
	 *
	 * @return		The encoded value of the authority component, @n
	 *				else an empty string if the authority component is undefined
	 */
	Tizen::Base::String GetEncodedAuthority(void) const;


	/**
	 * Gets the encoded value of the fragment component. @n
	 * The non-US-ASCII characters in the fragment component are encoded to escaped octets.
	 *
	 * @since 2.0
	 *
	 * @return		The encoded value of the fragment component, @n
	 *				else an empty string if the fragment component is undefined
	 */
	Tizen::Base::String GetEncodedFragment(void) const;


	/**
	 * Gets the encoded value of the path component. @n
	 * The non-US-ASCII characters in the path component are encoded to escaped octets.
	 *
	 * @since 2.0
	 *
	 * @return		The encoded value of the path component, @n
	 *				else an empty string if the path component is undefined
	 */
	Tizen::Base::String GetEncodedPath(void) const;


	/**
	 * Gets the encoded value of the query component. @n
	 * The non-US-ASCII characters in the query component are encoded to escaped octets.
	 *
	 * @since 2.0
	 *
	 * @return		The encoded value of the query component, @n
	 *				else an empty string if the query component is undefined
	 */
	Tizen::Base::String GetEncodedQuery(void) const;


	/**
	 * Gets the encoded value of the scheme-specific-part component. @n
	 * The non-US-ASCII characters in the scheme-specific-part component are encoded to escaped octets.
	 *
	 * @since 2.0
	 *
	 * @return		The encoded value of the scheme-specific-part component, @n
	 *				else an empty string if the scheme-specific-part component is undefined
	 */
	Tizen::Base::String GetEncodedSchemeSpecificPart(void) const;

	/**
	* Gets the encoded value of a user-info component,
	* or returns an empty string if the user-info component is undefined. @n
	* The non-US-ASCII characters in the user-info component are encoded to escaped octets.
	*
	* @since 2.0
	*
	* @return		The encoded value of user-info, @n
	*				else an empty string if the user-info component is undefined
	*/
	Tizen::Base::String GetEncodedUserInfo(void) const;


	/**
	 * Checks whether the current %Uri instance is an absolute URI.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the current %Uri instance is an absolute URI, @n
	 *				else @c false
	 */
	bool IsAbsolute(void) const;


	/**
	 * Checks whether the calling %Uri instance is an opaque URI.
	 *
	 * @since 2.0
	 *
	 * @return		@c true if the current %Uri instance is an opaque URI, @n
	 *				else @c false
	 */
	bool IsOpaque(void) const;


	/**
	 * Gets the encoded US-ASCII string.
	 *
	 * @since 2.0
	 *
	 * @return		The encoded US-ASCII string
	 * @remarks		If this URI does not contain any non US_ASCII characters,
	 *				then the string returned by this method is equal to the string returned by ToString().
	 *
	 * The following example demonstrates how to use the %GetEncodedString() method.
	 *
	 * @code
	 * String str(L"http://www.sec.com/osp?currency==\u20ac");
	 *
	 *	 Uri uri;
	 *	 uri.SetUri(str);
	 *
	 *	 String encode = uri.GetEncodedString();	// encode == L"http://www.sec.com/osp?currency==%E2%82%AC"
	 *
	 * @endcode
	 */
	Tizen::Base::String GetEncodedString(void) const;

	/**
	 * Compares the calling URI instance to the specified %Uri instance. @n
	 * When comparing corresponding components of two URIs, if one component in the current instance is undefined
	 * but the other is defined, then the current instance is considered to be less than the given object.
	 *
	 * @since 2.0
	 *
	 * @return		The result of the comparison
	 * @code
	 * < 0	if the current instance is less than the given object
	 * = 0	if the current instance is equal to the given object
	 * > 0	if the current instance is greater than the given object
	 * @endcode
	 * @param[in]	uri			An instance of %Uri
	 * @remarks
	 *
	 * Ordering of URIs
	 * 1. Scheme
	 *    Two URIs are ordered according to the ordering of schemes, without regard to case.
	 * 2. Hierarchical URI vs. Opaque URI
	 *    A hierarchical URI is less than an opaque URI if they have an identical scheme.
	 * 3. Scheme-specific-part
	 *    If two opaque URIs have an identical scheme, they are ordered according to
	 *    the scheme-specific-part, without regard to %case.
	 * 4. Fragment
	 *    If two opaque URIs have identical schemes and scheme-specific-parts, they are ordered according
	 *    to the ordering of fragments, without regard to case.
	 * 5. Authority
	 *    If two hierarchical URIs have identical schemes, they are ordered according to the authority,
	 *    without regard to the case.
	 *       5-1. Server-based authority
	 *             If two URIs are server-based, they are ordered according to their user-information,
	 *             without regard to case.
	 *             If the hosts are identical, then the URIs are ordered according to the ordering of ports.
	 * 6. Path
	 *    If two hierarchical URIs have identical schemas and authority components, they are ordered according to the
	 *    ordering of paths, without regard to the case.
	 *    If their paths are identical, their queries are compared. And if the queries are the same, then their fragments
	 *    are compared.
	 *
	 */
	int CompareTo(const Uri& uri) const;


	/**
	 *	Compares the specified instance to the current instance.
	 *
	 *  @since 2.0
	 *
	 *	@return		@c true if the two instances are equal, @n
	 *				else @c false
	 *	@param[in]	obj	The object to compare with the current instance
	 *	@remarks 	Two equal instances must return the same hash value. The default
	 *				implementation of this method returns @c true if two instances
	 *				have the same address. @n
	 *				The method can be overridden to support value equality. Furthermore, the Equals()
	 *				method must return the same results as the equality operator.
	 */
	virtual bool Equals(const Tizen::Base::Object& obj) const;


	/**
	 *	Gets the hash value of the current instance.
	 *
	 *  @since 2.0
	 *
	 *	@return		The hash value of the current instance
	 *	@remarks 	Two equal instances must return the same hash value. For better performance,
	 *				the used hash function must generate a random distribution for all inputs.
	 */
	virtual int GetHashCode(void) const;


	/**
	 * Normalizes the current URI.
	 *
	 * @since 2.0
	 *
	 * @return		The normalized URI, @n
	 *				else the current URI in case any error occurs
	 * @remarks	Normalization is the process of removing unnecessary "." and ".." segments from the path component of the
	 *			hierarchical URI. All "." segments are removed and If a ".." segment is preceded by a non-".." segment,
	 *			both of these segments are removed. If a URI is opaque, the normalization has no effect.
	 *
	 * The following example demonstrates how to use the %Normalize() method.
	 *
	 * @code
	 *	 Uri uri1;
	 *	 uri1.SetUri(L"http://www.example.com/a/b/../c/./d.html");
	 *
	 *	 Uri uriNormalized = uri1.Normalize();
	 *	 String uriStr = uriNormalized.ToString();		// uriStr == L"http://www.example.com/a/c/d.html"
	 *
	 * @endcode
	 */
	Uri Normalize(void);


	/**
	 * Parses the server-based authority component, if defined.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[out]	uri					The parsed URI
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The authority component is defined but cannot be parsed as a server-based authority.
	 * @remarks		This method is provided because the generic URI syntax cannot always distinguish a malformed server-based authority from a legitimate registry-based authority.
	 *				For example, the authority component in the URI string "//foo:bar/" is not a legal
	 *				server-based authority but it is legal as a registry-based authority.
	 */
	result ParseAuthority(Uri& uri);


	/**
	 * Relativizes the specified %Uri instance against the calling %Uri instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	uri					The %Uri to relativize against the calling %Uri
	 * @param[out]	resultUri			The relativized URI
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		Relativization is the opposite of Resolution. It is used
	 *				to divide a URI into the base URI and the relative URI.
	 */
	result Relativize(const Uri& uri, Uri& resultUri);


	/**
	 * Resolves the specified %Uri instance against the calling %Uri instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	uri					The URI to resolve against this URI
	 * @param[out]	resultUri			The resolved URI
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @remarks		Resolution is the process of resolving a URI against another, base URI. For hierarchical URI,
	 *				the path of the original is resolved against the path of the base URI and then normalized. @n
	 *
	 *				For example, to resolve the URI "/osp/framework/index.html" against the base URI "http://www.samsung.com" ,
	 *				the resultant URI is "http://www.samsung.com/osp/framework/index.html".
	 *
	 */
	result Resolve(const Uri& uri, Uri& resultUri);


	/**
	 * Sets the authority component to the specified String instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	authority			The authority
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetAuthority(const Tizen::Base::String& authority);


	/**
	 * Sets the fragment component to the specified String instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	fragment			The new fragment
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetFragment(const Tizen::Base::String& fragment);


	/**
	 * Sets the host component to the specified String instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	host				The new host
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetHost(const Tizen::Base::String& host);


	/**
	 * Sets the path component to the specified String instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	path				The new path component
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetPath(const Tizen::Base::String& path);


	/**
	 * Sets the port component to a given integer.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	port				The new port component
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c port is negative.
	 */
	result SetPort(int port);


	/**
	 * Sets the query component to the specified String instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	query				The new query string
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetQuery(const Tizen::Base::String& query);


	/**
	 * Sets the scheme component to the specified String instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	scheme				The new scheme
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetScheme(const Tizen::Base::String& scheme);


	/**
	 * Sets the scheme-specific-part component to the specified String instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	ssp					The new scheme-specific-part component
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetSchemeSpecificPart(const Tizen::Base::String& ssp);


	/**
	 * Sets the user-info component to the specified String instance.
	 *
	 * @since 2.0
	 *
	 * @return		An error code
	 * @param[in]	userInfo			The new user-info string
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_FORMAT	The specified string is invalid.
	 */
	result SetUserInfo(const Tizen::Base::String& userInfo);


	/**
	 * Gets the content of the calling %Uri instance as a string containing escaped octets.
	 *
	 * @since 2.0
	 *
	 * @return		The content of this URI as a string containing escaped octets
	 */
	Tizen::Base::String ToString(void) const;

private:
	//
	// Constructs an Uri instance with the given components.
	// scheme, ssp(opaquePart), authority, user-info, host, port, path, query, fragment
	//
	result SetUri(const Tizen::Base::String& scheme, const Tizen::Base::String& opaque,
		const Tizen::Base::String& authority, const Tizen::Base::String& userInfo,
		const Tizen::Base::String& host, int port, const Tizen::Base::String& path,
		const Tizen::Base::String& query, const Tizen::Base::String& fragment);

	//
	// Appends a given scheme-specific-part to a String.
	//
	result AppendSchemeSpecificPart(Tizen::Base::String& strbuf, const Tizen::Base::String& opaque,
		const Tizen::Base::String& authority, const Tizen::Base::String& userInfo,
		const Tizen::Base::String& host, int port, const Tizen::Base::String& path,
		const Tizen::Base::String& query) const;

	//
	// Appends a given fragment to a String.
	//
	result AppendFragment(Tizen::Base::String& strbuf, const Tizen::Base::String& fragment) const;

	//
	// Appends a given authority component to a String.
	//
	result AppendAuthority(Tizen::Base::String& strbuf, const Tizen::Base::String& authority,
		const Tizen::Base::String& userInfo, const Tizen::Base::String& host, int port) const;

	//
	// Parses a given URI string.
	//
	result ParseUri(const Tizen::Base::String& str);

	//
	// Copies a given URI.
	//
	result CopyUri(const Uri& uri);

	//
	// Encodes all components - authority, fragment, path, query, and ssp.
	//
	void EncodeAllComponent(void);

	//
	// Parses a hierarchical URI string.
	// @return		The start index of the fragment. If the operation fails, @c -1 is returned.
	// @param[in]	startSsp			The start index of scheme-specific-part
	// @param[in] lengthOfUri		The length of the URI string
	// @param[out] authority	A parsed authority component
	// @param[out] path			A parsed path component
	// @param[out] query			A parsed query component
	//
	result ParseHierarchicalUri(const Tizen::Base::String& str, int startSsp, Tizen::Base::String& authority,
		Tizen::Base::String& path, Tizen::Base::String& query, int& index);


	//
	// Parses a server_based authority component.
	// server_based authority: [user-info@]<host>[:port]
	//
	result ParseAuthority(const Tizen::Base::String& str, int curIndex, Tizen::Base::String& newAuth,
		Tizen::Base::String& userInfo, Tizen::Base::String& host, int& port);

	void SetAndEncodeAuthority(const Tizen::Base::String& authority,
		const Tizen::Base::String& path, const Tizen::Base::String& query);

	//
	// Parses a server_based authority component.
	// Assigns user-info, host and port to their member variable.
	//
	result ParseServerAuthority(const Tizen::Base::String& str, Tizen::Base::String& user, Tizen::Base::String& host, int& port);

	//
	// Parses an IPv4 address.
	//
	result ParseIpv4(const Tizen::Base::String& str, int index, int& count);

	//
	// Parses an IPv6 address.
	// It will be implemented.
	//
	result ParseIpv6(const Tizen::Base::String& ip6, Tizen::Base::String& outIpv6);

	//
	// Parses a host name and returns a host name as an out-param.
	//
	result ParseHostName(const Tizen::Base::String& str, int index, Tizen::Base::String& host);

	//
	// These methods verify components.
	// If a given component is valid, return @c true, else, @c false.
	// @param[in]	str		A component
	//
	bool VerifyScheme(const Tizen::Base::String& str) const;
	bool VerifyAuthority(const Tizen::Base::String& str) const;
	bool VerifyHost(const Tizen::Base::String& str) const;
	bool VerifyPath(const Tizen::Base::String& str) const;
	bool VerifyUserInfo(const Tizen::Base::String& str) const;
	bool VerifyUriChar(const Tizen::Base::String& str) const;

	//
	// Checks that a given string only consists of server_based characters.
	// @return		@c true if a string consists of only server_based characters, @n
	//			else @c false
	//
	bool VerifyServerAuthority(const Tizen::Base::String& str) const;

	//
	//  Checks that a given string only consists of registry_based characters.
	// @return		@c true if a string consists of only registry_based characters, @n
	//				else @c false
	//
	bool VerifyRegistryAuthority(const Tizen::Base::String& str) const;

	//
	// Checks whether a given char is a user-info character or not.
	// user-info char: alphabet, digit, -_.!~*'(), ;:&=+$,
	//
	bool IsUserInfo(wchar_t mch) const;

	//
	// Returns true if a given wchar_t is a mark character.
	// mark char : -_.!~*'()
	//
	bool IsMark(wchar_t mch) const;

	//
	// Returns true if two given wchar_ts are hexadecimals.
	//
	bool IsEscapedChar(wchar_t ch1, wchar_t ch2) const;

	//
	// Returns true if a given string is already encoded.
	//
	bool IsEncoded(const Tizen::Base::String& str) const;

	//
	// Returns true if a given wchar_t is an ISO control character.
	//
	bool IsControlChar(wchar_t ch) const;

	//
	// Compares @c pStr1 with @c pStr2. @n
	// If @c pStr1 is greater than @c pStr2, returns @c 1.
	// If two strings are the same, return @c 0.
	// If @c pStr1 is less than @c pStr2, returns @c -1.
	//
	int Compare(const Tizen::Base::String& pStr1, const Tizen::Base::String& pStr2) const;

	//
	// Adds leading dots.
	// If the normalized path is relative, and if the first segment could be parsed as a scheme name,
	// then prepend a '.' segment
	//
	void AddLeadingDot(Tizen::Base::WcharBuffer& path, int* segments, int numSegments);

	//
	// Finds the first character in stopString.
	// If there is not a character in stopString, the last index is returned.
	//
	int Scan(const Tizen::Base::String& str, int start, const Tizen::Base::String& stopString);

	//
	// Normalizes a given string and removes unnecessary dots.
	//
	Tizen::Base::String InternalNormalize(const Tizen::Base::String& path);

	//
	// Returns the number of segments from a given path.
	//
	int GetNumberOfSegments(const Tizen::Base::String& path) const;

	// Join the segments in the given path according to the given segment-index array,
	// ignoring those segments whose index entries have been set to @c -1, and inserting slashes as needed.
	// Return the length of the resulting path.
	//
	// Preconditions:
	//   segs[i] == @c -1 implies segment i is to be ignored
	//   path computed by split, as above, with '\0' having replaced '/'
	//
	// Postconditions:
	//  path[0] .. path[return value] == Resulting path
	//
	int Join(Tizen::Base::WcharBuffer& path, int* segments, int segCount);

	//
	// Removes unnecessary dots and segment pairs consisting of a non-".." segment
	// followed by a ".." segment
	//
	void RemoveDots(const Tizen::Base::WcharBuffer& mb, int* segments, int segCount, int length);

	//
	// Splits a path component into segments.
	//
	void SplitIntoSegments(Tizen::Base::WcharBuffer& mb, int* segments, int segCount);

	//
	// Implements Uri resolution in RFC2396 5.2
	//
	result Resolve(const Uri& baseUri, const Uri& childUri, Uri& resultUri);

	//
	// Resolves the path of the base and child URI.
	//
	Tizen::Base::String ResolvePath(const Tizen::Base::String& path, const Tizen::Base::String& resolve, bool isAbsolute);

	bool EqualsComponent(const Tizen::Base::String& comp1, const Tizen::Base::String& comp2);
	result Relativize(const Uri& baseUri, const Uri& childUri, Uri& resultUri);

	//
	// Converts a component represented by UTF8 to a component represented by Unicode.
	//
	Tizen::Base::String Decode(const Tizen::Base::String& str);

	//
	// Converts a component represented by Unicode to a component represented by UTF8.
	//
	Tizen::Base::String Encode(const Tizen::Base::String& str) const;

	static result AppendEscape(Tizen::Base::String& strbuf, byte b);

	//
	// Clears the current instance.
	//
	void Clear(void);

	// Component
	Tizen::Base::String __scheme;
	Tizen::Base::String __ssp;
	Tizen::Base::String __authority;
	Tizen::Base::String __host;
	Tizen::Base::String __fragment;
	Tizen::Base::String __path;
	Tizen::Base::String __userInfo;
	Tizen::Base::String __query;
	Tizen::Base::String __ipv4;
	Tizen::Base::String __ipv6;

	// Encoded Component
	Tizen::Base::String __encodedAuth;
	Tizen::Base::String __encodedFragment;
	Tizen::Base::String __encodedPath;
	Tizen::Base::String __encodedQuery;
	Tizen::Base::String __encodedSsp;
	Tizen::Base::String __encodedUserInfo;

	int __port;
	bool __hasScheme;
	int __ipv6ByteCount;

	friend class _UriImpl;
	class _UriImpl* __pUriImpl;

}; // Uri

}}} // Tizen::Base::Utility

#endif //_FBASE_UTIL_URI_H_
