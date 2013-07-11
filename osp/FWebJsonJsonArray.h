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
 * @file		FWebJsonJsonArray.h
 * @brief		This is the header file for the %JsonArray class.
 *
 * This header file contains the declarations of the %JsonArray class.
 */
#ifndef _FWEB_JSON_JSON_ARRAY_H_
#define _FWEB_JSON_JSON_ARRAY_H_

#include <FBaseColArrayListT.h>
#include <FBaseColICollectionT.h>
#include <FWebJsonIJsonValue.h>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Woverloaded-virtual"
#endif

namespace Tizen { namespace Web { namespace Json
{
class _JsonArrayImpl;
}}} // Tizen::Web::Json

namespace Tizen { namespace Web { namespace Json
{

/**
 * @class	JsonArray
 * @brief	This class represents the JSON value of type array.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %JsonArray class represents the JSON value of type array.
 * @n
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/web/json_namespace.htm">JSON Guide</a>.
 *
 * The following example shows how to create and initialize a %JsonArray instance and how to use its methods.
 *
 * @code
 *	#include <FWebJson.h>
 *
 *	using namespace Tizen::Base;
 *	using namespace Tizen::Base::Collection;
 *	using namespace Tizen::Web::Json;
 *
 *	void
 *	MyClass::JsonArraySample(void)
 *	{
 *		// Creates an instance of JsonArray
 *		JsonArray *pJsonArray = new JsonArray();
 *
 *		// Must call Construct() for JasonArray
 *		pJsonArray->Construct();
 *
 *		// Creates value instances
 *		JsonString  *pJsonstr   = new JsonString(L"myname");
 *		JsonNumber  *pJsonNum   = new JsonNumber(99);
 *		JsonBool    *pJsonBool  = new JsonBool(true);
 *
 *		// Adds the string to the JsonArray
 *		pJsonArray->Add(pJsonstr); 
 *		// Adds the number to the JsonArray
 *		pJsonArray->Add(pJsonNum);
 *		// Adds the boolean to the JsonArray
 *		pJsonArray->Add(pJsonBool);
 *
 *		// Gets the value at the given position(index) in the JsonArray
 *		IJsonValue* pValue = null;
 *		pJsonArray->GetAt(0, pValue);
 *
 *		// Finds the index of the given value in the JsonArray
 *		JsonString *pJsonstrcheck = new JsonString(L"myname");
 *		int index;
 *		pJsonArray->IndexOf(pJsonstrcheck, index);
 *
 *		// Uses enumerator to access elements in the JsonArray
 *		IEnumeratorT<IJsonValue*>* pEnum = pJsonArray->GetEnumeratorN();
 *		if(pEnum)
 *		{
 *			while( pEnum->MoveNext() == E_SUCCESS )
 *			{
 *				IJsonValue* pJsonValue = null;
 *
 *				//Uses the pJsonValue
 *				pEnum->GetCurrent( pJsonValue );
 *			}
 *			delete pEnum;
 *		}
 *
 *		// Removes the value in the JsonArray
 *		pJsonArray->RemoveAt(index, true);
 *
 *		// Removes all the remaining values
 *		pJsonArray->RemoveAll(true);
 *		delete pJsonArray;
 *	}
 * @endcode
 */
class _OSP_EXPORT_ JsonArray
	: public IJsonValue
	, public Tizen::Base::Collection::ArrayListT<IJsonValue*>
{
public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	 *
	 * @since	2.0
	 */
	JsonArray(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since	2.0
	 */
	virtual ~JsonArray(void);

	/**
	 * Initializes the instance of %JsonArray.
	 *
	 * @since		2.0
	 *
	 * @return      An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_INVALID_OPERATION	This instance has already been constructed.
	 */
	result Construct(void);

	/**
	 * Returns the type of this class. @n
	 * In this case, it is always @c JSON_ARRAY.
	 *
	 * @since	2.0
	 *
	 * @return      The JSON type
	 * @see     JsonType
	 */
	JsonType GetType(void) const;

	/**
	 * Adds the specified element to end of the list.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	pJsonValue		A pointer to JsonValue to be added to the list
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @see			Remove()
	 */
	virtual result Add(IJsonValue* const& pJsonValue);

	/**
	 * Searches for an element in this list. @n
	 * Gets the index of the element if it is found.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the JsonValue class to be located
	 * @param[out]	index				The index of the element
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The @c pJsonValue is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(IJsonValue* const& pJsonValue, int& index) const;

	/**
	 * Searches for an element starting from the specified index. @n
	 * Gets the index of the element if it is found.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the JsonValue class to be located
	 * @param[in]	startIndex			The starting index for the search @n
	 *									It must be less than the number of elements in the array.
	 * @param[out]	index				The index of the element
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c index is outside the bounds of the data structure, or the specified @c startIndex is either equal to or greater than the number of elements or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pJsonValue is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(IJsonValue* const& pJsonValue, int startIndex, int& index) const;

	/**
	 * Searches for an element within the specified range. @n
	 * Gets the index of the element if it is found.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the JsonValue class to be located
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count				The number of elements to be read
	 * @param[out]	index				The index of the element
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		Either of the following conditions has occurred: @n
	 *									- The specified index is outside the bounds of the data structure. @n
	 *									- The specified @c startIndex is either greater than or equal to the number of elements or less than @c 0. @n
	 *									- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @exception	E_OBJ_NOT_FOUND		The @c pJsonValue is not found.
	 * @see			LastIndexOf()
	 */
	virtual result IndexOf(IJsonValue* const& pJsonValue, int startIndex, int count, int& index) const;

	/**
	 * Searches for the last occurrence of an element in this list. @n
	 * Gets the index of the element if it is found.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the JsonValue class to be located
	 * @param[out]	index				The index of the last occurrence of the specified element
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The specified @c pJsonValue is not found.
	 * @see			IndexOf()
	 */
	virtual result LastIndexOf(IJsonValue* const& pJsonValue, int& index) const;

	/**
	 * Checks whether the list contains the specified @c JsonValue.
	 *
	 * @since	    2.0
	 *
	 * @return		@c true if the specified @c JsonValue is present in the list, @n
	 *				else @c false
	 * @param[in]	pJsonValue      A pointer to the JsonValue class to be located
	 */
	virtual bool Contains(IJsonValue* const& pJsonValue) const;

	/**
	 * Checks whether value of the specified instance equals to value of the current instance of @c %JsonArray.
	 *
	 *	@since		2.0
	 *
	 * @return		@c true if value of the current instance equals to value of the specified instance, @n
	 *				else @c false
	 * @param[in]	obj			The element to be compared with the current instance of @c %JsonArray
	 * @remarks     The method returns @c false if the specified element is not @c %JsonArray.
	 *  @see		Object::Equals()
	 */
	virtual bool Equals(const Object& obj) const;

	/**
	 * Gets the hash value of the current instance.
	 *
	 * @since 2.0
	 *
	 * @return	An integer value indicating the hash value of the current instance
	 * @remarks	The two equal instances must return the same hash value. For better performance,
	 *		the used hash function must generate a random distribution for all inputs.
	 *		The default implementation of this method returns the address of the current instance.
	 */
	virtual int GetHashCode(void) const;

	/**
	 * Removes the first occurrence of the specified element.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the %JsonValue class to be removed
	 * @param[in]	deallocate			Set to @c true to deallocate the @c JsonValue, @n
	 *                                  else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OBJ_NOT_FOUND		The @c pJsonValue is not found.
	 * @see			Add(), RemoveAt(), RemoveAll()
	 */
	virtual result Remove(IJsonValue* const& pJsonValue, bool deallocate = false);

	/**
	 * Removes all the elements of the specified collection from the list.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	collection      The collection to be removed from this list
	 * @param[in]	deallocate				Set to @c true to deallocate the @c JsonValues, @n
	 *                                      else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The @c collection is modified during the operation of this method.
	 */
	virtual result RemoveItems(const Tizen::Base::Collection::ICollectionT<IJsonValue*>& collection, bool deallocate = false);

	/**
	 * Removes an element from the specified location.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	index                   The index of the element to be removed
	 * @param[in]	deallocate				Set to @c true to deallocate the @c JsonValue, @n
	 *                                      else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			The specified index is outside the bounds of the data structure, or the specified @c index is greater than or equal to the number of elements or less than @c 0.
	 * @remarks		The elements that follow the deleted element move up the list to occupy the empty location.
	 */
	virtual result RemoveAt(int index, bool deallocate = false);

	/**
	 * Removes all the elements within a specified range.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	startIndex	The starting index of the range
	 * @param[in]	count		The number of elements to remove
	 * @param[in]	deallocate				Set to @c true to deallocate the JsonValue, @n
	 *                                      else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE			Either of the following conditions has occurred: @n
	 *										- The specified index is outside the bounds. @n
	 *										- The specified @c startIndex is either greater than or equal to the number of elements or less than @c 0. @n
	 *										- The specified @c count is either greater than the number of elements starting from @c startIndex or less than @c 0.
	 * @remarks		The elements that follow the deleted elements move up the list to occupy the empty locations.
	 */
	virtual result RemoveItems(int startIndex, int count, bool deallocate = false);

	/**
	 * Removes all the elements in the %JsonArray class.
	 *
	 * @since		 2.0
	 *
	 * @param[in]	deallocate		Set to @c true to deallocate all the elements, @n
	 *                              else @c false
	 */
	virtual void RemoveAll(bool deallocate = false);

	/**
	 * Replaces the element at the specified index with the specified element.
	 *
	 * @since	    2.0
	 *
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the JsonValue class to be set
	 * @param[in]	index				The index at which the element must be set
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(IJsonValue* const& pJsonValue, int index);

	/**
	 * Replaces the element at the specified index with the specified element.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	pJsonValue			A pointer to the JsonValue class to be set
	 * @param[in]	index				The index at which the element must be set
	 * @param[in]	deallocate			Set to @c true to deallocate the @c JsonValue, @n
	 *                                  else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_RANGE		The specified index is outside the bounds of the data structure, or the specified @c index is either equal to or greater than the number of elements or less than @c 0.
	 * @see			GetAt()
	 */
	virtual result SetAt(IJsonValue* const& pJsonValue, int index, bool deallocate);

	/**
	 * Returns a new cloned %JsonArray instance.
	 *
	 * @since 2.0
	 *
	 * @return		A new cloned %JsonArray
	 * @exception	E_SUCCESS		The memory is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	JsonArray* CloneN(void) const;

private:
	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	item		The instance of the %JsonArray class to copy from
	// @remarks			This constructor is hidden.
	//
	JsonArray(const JsonArray& item);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @param[in]	item		The instance of the %JsonArray class to assign from
	// @remarks			This operator is hidden.
	//
	JsonArray& operator =(const JsonArray& item);

private:
	_JsonArrayImpl* __pJsonArrayImpl;

	friend class _JsonArrayImpl;
}; // JsonArray

}}} // Tizen::Web::Json
#endif // _FWEB_JSON_JSON_ARRAY_H_

#ifdef __clang__
#pragma clang diagnostic pop
#endif
