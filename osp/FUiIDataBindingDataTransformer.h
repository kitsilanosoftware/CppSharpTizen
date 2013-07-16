//
// Open Service Platform
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * @file	FUiIDataBindingDataTransformer.h
 * @brief	This is the header file for the %IDataBindingDataTransformer interface.
 *
 * This header file contains the declarations of the %IDataBindingDataTransformer interface.
 */

#ifndef _FUI_IDATA_BINDING_DATA_TRANSFORMER_H_
#define _FUI_IDATA_BINDING_DATA_TRANSFORMER_H_

#include <FUiDataBindingTypes.h>

namespace Tizen { namespace Base
{
class String;
class Object;
}}

namespace Tizen { namespace Ui
{

/**
* @interface    IDataBindingDataTransformer
* @brief 		This interface defines methods for transforming the value of the data that will be updated to the binding target or source.
*
* @since 2.0
*
* The %IDataBindingDataTransformer interface defines methods for transforming the value of source type to the value of destination type.
*/
class _OSP_EXPORT_ IDataBindingDataTransformer
{
public:
	/**
	 * This polymorphic destructor should be overridden if required. This way, the destructors of the derived classes are called when the destructor of this interface is called.
	 *
	 * @since 2.0
	 */
	virtual ~IDataBindingDataTransformer(void) {};

	/**
	* Transforms the value of the data of source type to value of target type.
	* @since 2.0
	* @return        @c true if it is successful to convert source to target @n
	*                 else @c false
	* @param[in]    bindingId    The specified binding ID
	* @param[in]    sourceType        The source data type
	* @param[in]    sourceData       The data source
	* @param[in]    targetType    The target data type
	* @param[out]   targetData    The data target
	*/
	virtual bool TransformSourceToTarget(const Tizen::Base::String& bindingId, DataBindingDataType sourceType, const Tizen::Base::Object& sourceData, DataBindingDataType targetType, Tizen::Base::Object& targetData) = 0;

	/**
	* Transforms the value of the data of target type to value of source type.
	* @since 2.0
	* @return        @c true if it is successful to convert target to source @n
	*                 else @c false
	* @param[in]    bindingId    The specified binding ID
	* @param[in]    targetType    The target data type
	* @param[in]    targetData    The data target
	* @param[in]    sourceType        The source data type
	* @param[out]   sourceData       The data source
	*/
	virtual bool TransformTargetToSource(const Tizen::Base::String& bindingId, DataBindingDataType targetType, const Tizen::Base::Object& targetData, DataBindingDataType sourceType, Tizen::Base::Object& sourceData) = 0;

	/**
	* Checks whether the this transformer can convert the source type to target type.
	*
	* @since 2.0
	* @return        @c true if it is possible to transform source type to target type, @n
	*                 else @c false
	* @param[in]    bindingId    The specified binding ID
	* @param[in]    sourceType        The source data type
	* @param[in]    targetType    The target data type
	*/
	virtual bool IsSourceToTargetTransformable(const Tizen::Base::String& bindingId, DataBindingDataType sourceType, DataBindingDataType targetType) = 0;

	/**
	* Checks whether the this transformer can convert the target type to source type.
	*
	* @since 2.0
	* @return        @c true if it is possible to transform target type to source type, @n
	*                 else @c false
	* @param[in]    bindingId    The specified binding ID
	* @param[in]    targetType    The target data type
	* @param[in]    sourceType        The source data type
	*/
	virtual bool IsTargetToSourceTransformable(const Tizen::Base::String& bindingId, DataBindingDataType targetType, DataBindingDataType sourceType) = 0;

protected:
	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IDataBingingDataTransformer_Reserved1(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IDataBingingDataTransformer_Reserved2(void) {}

	//
	// This method is for internal use only. Using this method can cause behavioral, security-related,
	// and consistency-related issues in the application.
	//
	// This method is reserved and may change its name at any time without
	// prior notice.
	//
	virtual void IDataBingingDataTransformer_Reserved3(void) {}

}; // IDataBindingDataTransformer

}} // Tizen::Ui
#endif // _FUI_IDATA_BINDING_DATA_TRANSFORMER_H_
