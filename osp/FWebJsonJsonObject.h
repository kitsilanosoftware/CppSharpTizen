//
// Open Service Platform
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
 * @file		FWebJsonJsonObject.h
 * @brief		This is the header file for the %JsonObject class.
 *
 * This header file contains the declarations of the %JsonObject class.
 * The class represents the JSON value of type object.
 */
#ifndef _FWEB_JSON_JSON_OBJECT_H_
#define _FWEB_JSON_JSON_OBJECT_H_

#include <FBaseColHashMapT.h>
#include <FBaseString.h>
#include <FWebJsonIJsonValue.h>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Woverloaded-virtual"
#endif

namespace Tizen { namespace Web { namespace Json
{
class _JsonObjectImpl;
class _JsonObjectComparer;
class _JsonObjectHashCodeProvider;
}}} // Tizen::Web::Json

namespace Tizen { namespace Web { namespace Json
{

/**
 * @class	JsonObject
 * @brief	This class represents the JSON value of type object.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %JsonObject class represents the JSON value of type object.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/json_namespace.htm">JSON Guide</a>.
 *
 * The following example shows how to create and initialize a %JsonObject instance and how to use its methods.
 *
 * @code
 *	#include <FWebJson.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *	using namespace Tizen::Web::Json;
 *
 *	void
 *	MyClass::JsonObjectSample(void)
 *	{
 *		//Creates an instance of JsonObject
 *		JsonObject *pJsonObj = new JsonObject();
 *
 *		//Construct() must be called for JsonObject
 *		pJsonObj->Construct();
 *
 *		//Creates keys, the pointer to string is the key for the element of the JsonObject
 *		String  *pStrFNKey      = new String(L"firstName");
 *		String  *pStrAgeKey		= new String(L"age");
 *
 *		//Creates values, the pointer to any JsonValue is the value for the element of the JsonObject
 *		JsonString  *pStrFNVal      = new JsonString(L"John");
 *		JsonNumber	*pNumAge		= new JsonNumber(25);
 *
 *		//Adds key-value pairs to object
 *		pJsonObj->Add(pStrFNKey, pStrFNVal);
 *		pJsonObj->Add(pStrAgeKey, pNumAge);
 *
 *		// Gets the value with the specified key
 *		IJsonValue* pValue = null;
 *		pJsonObj->GetValue(pStrFNKey, pValue);
 *
 *		// Uses enumerator to access elements in the map
 *		const String* pKey = null;
 *		IMapEnumeratorT<const String*, IJsonValue*>*  pMapEnum = null;
 *		pMapEnum = pJsonObj->GetMapEnumeratorN();
 *		if( pMapEnum )
 *		{
 *			while (pMapEnum->MoveNext() == E_SUCCESS)
 *			{
 *				pMapEnum->GetKey(pKey);
 *				pMapEnum->GetValue(pValue);
 *			}
 *			delete pMapEnum;
 *		}
 *
 *		// Removes a key-value pair with memory deallocation
 *		pJsonObj->Remove(pStrAgeKey, true);
 *
 *		// Removes all remaining key-value pairs with memory deallocation
 *		pJsonObj->RemoveAll(true);
 *		delete pJsonObj;
 *	}
 * @endcode
 */
class _OSP_EXPORT_ JsonObject
	: public IJsonValue
	, public Tizen::Base::Collection::HashMapT<const Tizen::Base::String*, IJsonValue*>
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	JsonObject(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object()..
	 *
	 * @since	2.0
	 */
	virtual ~JsonObject(void);

	/**
	 * Initializes this instance of %JsonObject.
	 *
	 * @since			2.0
	 *
	 * @return      An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	The Construct() method cannot be called twice.
	 */
	result Construct(void);

	/**
	 * Gets the type of the JSON object.
	 *
	 * @since		2.0
	 *
	 * @return      The type of the JSON object
	 * @see         JsonType
	 */
	JsonType GetType(void) const;

	/**
	 * Adds the specified key-value pair to a JSON object.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	pKey				A pointer to the key-value to add
	 * @param[in]	pJsonValue			A pointer to the value to add
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 * @exception	E_OBJ_ALREADY_EXIST	The specified @c pKey already exists.
	 * @see Remove()
	 */
	virtual result Add(const Tizen::Base::String* const& pKey, Tizen::Web::Json::IJsonValue* const& pJsonValue);


	/**
	 * Gets the value associated with a specified key.
	 *
	 * @since	    2.0
	 *
	 * @return		The value associated with the key, @n
	 *				else @c null if an exception occurs
	 * @param[in]	pKey				A pointer to the key to locate
	 * @param[out]	pJsonValue			A pointer to the value associated with the key
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pKey is not found.
	 * @see			SetValue()
	 */
	virtual result GetValue(const Tizen::Base::String* const& pKey, Tizen::Web::Json::IJsonValue*& pJsonValue) const;

	/**
	 * Checks whether a JSON object contains the specified value.
	 *
	 * @since	    2.0
	 *
	 * @return		@c true if the JSON object contains the specified value, @n
	 *				else @c false
	 * @param[in]	pJsonValue A pointer to a value to locate
	 */
	virtual bool ContainsValue(IJsonValue* const& pJsonValue) const;

	/**
	 *	Checks whether the value of the specified instance equals the value of the current instance of %JsonObject.
	 *
	 *	@since		2.0
	 *
	 *	@return		@c true if the value of the current instance equals the value of the specified instance, @n
	                else @c false
	 *	@param[in]	obj	The object to compare @n
	 *                  This object is compared with the current instance of %JsonObject.
	 *	@remarks    This method returns @c false if the specified object is not of type JSON object.
	 *  @see		Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return	An integer value indicating the hash value of the current instance
	 * @remarks	The two equal instances should return the same hash value. For better performance,
	 *		the used hash function must generate a random distribution for all inputs.
	 *		@n
	 *		The default implementation of this method returns the address of the current instance.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Removes the value associated with a specified key.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	pKey                A pointer to the key to remove
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pKey is not found.
	 */
	virtual result Remove(const Tizen::Base::String* const& pKey);

	/**
	 * Removes the value associated with a specified key.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	pKey                A pointer to the key to remove
	 * @param[in]	deallocate			Set to @c true to deallocate the JSON value, @n
	 *                                  else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pKey is not found.
	 */
	virtual result Remove(const Tizen::Base::String* const& pKey, bool deallocate);

	/**
	 * Removes all the key-value pairs in %JsonObject.
	 *
	 * @since	 2.0
	 *
	 * @param[in]	deallocate			Set to @c true to deallocate the JSON value, @n
	 *                                  else @c false
	 */
	virtual void RemoveAll(bool deallocate = false);

	/**
	 * Sets a new value to a specified key.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	pKey				A pointer to the key for which the value is to be replaced
	 * @param[in]	pJsonValue			A pointer to the new value to be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pKey is not found.
	 * @remarks		Use the Add() method to add a new key-value pair.
	 */
	virtual result SetValue(const Tizen::Base::String* const& pKey, Tizen::Web::Json::IJsonValue* const& pJsonValue);

	/**
	 * Sets a new value to a specified key.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	pKey				A pointer to the key for which the value is to be replaced
	 * @param[in]	pJsonValue			A pointer to the new value to be set
	 * @param[in]	deallocate			Set to @c true to deallocate the JSON value, @n
	 *                                  else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pKey is not found.
	 * @remarks		Use the Add() method to add a new key-value pair.
	 */
	virtual result SetValue(const Tizen::Base::String* const& pKey, Tizen::Web::Json::IJsonValue* const& pJsonValue, bool deallocate);

	/**
	 * Checks whether a JSON object contains the specified key.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	pKey	The key to locate
	 * @param[out]	out     @c true if the JSON object contains the specified key, @n
	 *						else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid, or the key comparison has failed.
	 */
	virtual result ContainsKey(const Tizen::Base::String* const& pKey, bool& out) const;

	/**
	 * Return a new cloned %JsonObject instance.
	 *
	 * @since 2.0
	 *
	 * @return		a new cloned %JsonObject
	 * @exception	E_SUCCESS		The memory is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	JsonObject* CloneN(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	item		The instance of the %JsonObject class to copy from
	// @remarks		This constructor is hidden.
	//
	JsonObject(const JsonObject& item);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	item		The instance of the %JsonObject class to assign from
	// @remarks		This operator is hidden.
	//
	JsonObject& operator =(const JsonObject& item);

private:
	_JsonObjectImpl* __pJsonObjectImpl;
	_JsonObjectComparer* __pJsonObjectComparer;
	_JsonObjectHashCodeProvider* __pJsonObjectHashCodeProvider;
	friend class _JsonObjectImpl;
}; // JsonObject

}}} // Tizen::Web::Json
#endif // _FWEB_JSON_JSON_OBJECT_H_

#ifdef __clang__
#pragma clang diagnostic pop
#endif
