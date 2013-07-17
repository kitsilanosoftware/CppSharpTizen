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
 * @file	FUiDataBindingContext.h
 * @brief	This is the header file for the %DataBindingContext class.
 *
 * This header file contains the declarations of the %DataBindingContext class.
 */

#ifndef _FUI_DATA_BINDING_CONTEXT_H_
#define _FUI_DATA_BINDING_CONTEXT_H_

#include <FBaseTypes.h>
#include <FBaseObject.h>
#include <FUiDataBindingTypes.h>
#include <FUiIDataBindingListener.h>
#include <FUiIDataBindingDataValidator.h>
#include <FUiIDataBindingDataTransformer.h>

namespace Tizen { namespace Base
{
class String;
}}

namespace Tizen { namespace Ui
{

class Control;
class _DataBindingContextImpl;

/**
 * @class          DataBindingContext
 * @brief          This class represents a data binding context and the application's data source.
 *
 * @since 2.0
 *
 * The %DataBindingContext class represents the data binding context.
 *
 * The following example demonstrates how to use the %DataBindingContext class.
.*
 * @code
// Sample code for DataBindingSample.h
#include <FBase.h>
#include <FUi.h>

class DataBindingSample
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
{
public:
	virtual bool Initialize(void);
	virtual result OnInitializing(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private :
	static const int ID_BUTTON_UNBIND = 402;
	static const int ID_BUTTON_UPDATE_BINDING = 403;
	static const int ID_BUTTON_BIND = 404;

	Tizen::Base::Integer __bindIntegerToButtonText;
	Tizen::Ui::Controls::Button* __pUnbindButton;
	Tizen::Ui::Controls::Button* __pUpdateBindingButton;
	Tizen::Ui::Controls::Button* __pTargetButton;
	Tizen::Ui::Controls::Button* __pBindButton;
};

 *	@endcode
 *
 *	@code

// Sample code for DataBindingSample.cpp
#include "DataBindingSample.h"

using namespace Tizen::App;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

bool
DataBindingSample::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL| FORM_STYLE_INDICATOR| FORM_STYLE_HEADER| FORM_STYLE_FOOTER);
	return true;
}

result
DataBindingSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = GetHeader();
	pHeader->SetTitleText(L"DataBinding");

	Rectangle rect;
	rect = GetClientAreaBounds();

	__pUpdateBindingButton = new (std::nothrow) Button();
	__pUpdateBindingButton->Construct(Rectangle(10, rect.height / 6, rect.width - 20, rect.height / 6), L"BindingTarget");
	__pUpdateBindingButton->SetName("Target");
	AddControl(__pUpdateBindingButton);

	__pTargetButton = new (std::nothrow) Button();
	__pTargetButton->Construct(Rectangle(10, (rect.height / 3) + 10 , (rect.width - 20), rect.height / 6), L"Update Binding");
	__pTargetButton->SetActionId(ID_BUTTON_UPDATE_BINDING);
	__pTargetButton->AddActionEventListener(*this);
	AddControl(__pTargetButton);

	__pUnbindButton = new (std::nothrow) Button();
	__pUnbindButton->Construct(Rectangle(10, (rect.height * 2 / 3), (rect.width / 2) - 10, rect.height / 6), L"Unbind");
	__pUnbindButton->SetActionId(ID_BUTTON_UNBIND);
	__pUnbindButton->AddActionEventListener(*this);
	AddControl(__pUnbindButton);

	__pBindButton = new (std::nothrow) Button();
	__pBindButton->Construct(Rectangle((rect.width / 2) + 10 , (rect.height * 2 / 3), (rect.width / 2) - 20 , rect.height / 6), L"Bind");
	__pBindButton->SetActionId(ID_BUTTON_BIND);
	__pBindButton->AddActionEventListener(*this);
	AddControl(__pBindButton);

	DataBindingContext* pContext = GetDataBindingContextN();
	r = pContext->Bind(L"bindingcount", L"Target", L"text", __bindIntegerToButtonText, DATA_BINDING_DATA_TYPE_INTEGER, DATA_BINDING_FLOW_ONE_WAY, DATA_BINDING_TRIGGER_EXPLICIT, null, null, null);
	delete pContext;

	return r;
}

void
DataBindingSample::OnActionPerformed(const Control& source, int actionId)
{
	DataBindingContext* pContext = GetDataBindingContextN();
	result r = E_SUCCESS;
	switch (actionId)
	{
	case ID_BUTTON_UNBIND:
		{
			pContext->Unbind(L"bindingcount");
			break;
		}
	case ID_BUTTON_BIND:
		{
			pContext->Bind(L"bindingcount", L"Target", L"text", __bindIntegerToButtonText, DATA_BINDING_DATA_TYPE_INTEGER, DATA_BINDING_FLOW_ONE_WAY, DATA_BINDING_TRIGGER_EXPLICIT, null, null, null);
			break;
			}
	case ID_BUTTON_UPDATE_BINDING:
		{
			r = pContext->UpdateBinding(L"bindingcount", DATA_BINDING_DESTINATION_TYPE_TARGET);
			if (r  == E_SUCCESS)
			{
				__bindIntegerToButtonText = __bindIntegerToButtonText.ToInt() + 1;
			}
			break;
		}
	default:
		break;
	}
	delete pContext;
	Invalidate(true);
}
 * @endcode
 *
 */
class _OSP_EXPORT_ DataBindingContext
	: public Tizen::Base::Object
{
public:
	/**
	* This is the destructor for this class.
	*
	* @since 2.0
	*/
	virtual ~DataBindingContext(void);

public:
	/**
	* Gets the owner of this data binding context.
	*
	* @since 2.0
	*
	* @return        The context owner
	*/
	Control* GetContextOwner(void) const;

	/**
	* Binds the specified control's property and data source.
	*
	* @since 2.0
	*
	* @return        An error code
	* @param[in]    bindingId          	The binding ID
	* @param[in]    controlName      	The name of target property owner
	* @param[in]    propertyName    	The target property name
	* @param[in]    dataSource        	The data binding source
	* @param[in]    sourceType        	The data type of the @c dataSource
	* @param[in]    flow      			The data flow type
	* @param[in]    trigger  			The data binding trigger type
	* @param[in]    pListener          	The data binding listener
	* @param[in]    pValidator         	The data validator
	* @param[in]    pTransformer     	The data transformer
	* @exception    E_SUCCESS        		The method is successful.
	* @exception    E_SYSTEM         		A system error has occurred.
	* @exception    E_INVALID_ARG  1. sourceType is not of a supported type.
	                                 2. flow is not of a supported type.
	                                 3. trigger is not of a supported type.
	* @exception    E_OBJ_NOT_FOUND        1. The control named controlName does not exist.
	                                          2. The parameter "propertyName" is not found in control properties.
	* @exception    E_UNSUPPORTED_FORMAT          The given transformer does not supported changing source type to target type.
	* @exception    E_UNSUPPORTED_OPERATION      In this system, binding with the given trigger and flow is not supported.
	* @remarks      The propertyName parameter is defined in "UI Builder Guide". @n
	*                     There is no duplication check for each binding ID. @n
	*                     Please use a unique binding ID for each binding setting.
	*/
	result Bind(const Tizen::Base::String& bindingId, const Tizen::Base::String& controlName, const Tizen::Base::String& propertyName, Tizen::Base::Object& dataSource, DataBindingDataType sourceType, DataBindingFlow flow, DataBindingTrigger trigger, const IDataBindingListener* pListener, const IDataBindingDataValidator* pValidator, const IDataBindingDataTransformer* pTransformer = null);

	/**
	* Sets the binding listener for the specified data binding.
	*
	* @since 2.0
	*
	* @return        An error code
	* @param[in]    bindingId         	The binding ID
	* @param[in]    pListener         	The data binding listener
	* @exception    E_SUCCESS        	The method is successful.
	* @exception    E_SYSTEM         	A system error has occurred.
	* @exception    E_OBJ_NOT_FOUND     The given binding ID is not registered.
	* @exception    E_INVALID_ARG  The given listener is not valid.
	* @remarks       If you give pListener parameter as 'null', the existing dataBindingEventListener will be removed.
	*/
	result SetDataBindingEventListener(const Tizen::Base::String& bindingId, IDataBindingListener* pListener);

	/**
	* Unbinds all bindings that exist in this context.
	*
	* @since 2.0
	*
	* @return        An error code
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_SYSTEM         A system error has occurred.
	*/
	result UnbindAll(void);

	/**
	* Unbinds a binding that exists in this context.
	*
	* @since 2.0
	*
	* @return        An error code
	* @param[in]    bindingId        The binding ID
	* @exception    E_SUCCESS        The method is successful.
	* @exception    E_SYSTEM         A system error has occurred.
	* @exception    E_OBJ_NOT_FOUND        The given binding ID is not registered.
	*/
	result Unbind(const Tizen::Base::String& bindingId);

	/**
	* Updates all 'explicit' data bindings.
	*
	* @since 2.0
	*
	* @return        An error code
	* @param[in]    destType          	The destination type
	* @exception    E_SUCCESS       	The method is successful.
	* @exception    E_SYSTEM        	A system error has occurred.
	* @exception    E_INVALID_ARG 	 	The specified @c destType is not of a supported type.
	* @remarks
	* 					- If you have set a data binding listener, @n
					this method is returned after that listener is called.
	*					- The behavior of this method is dependent on the system default locale setting.
	* @see    IDataBindingListener
	*/
	result UpdateAllBindings(DataBindingDestinationType destType);

	/**
	* Updates the specified data binding.

	* @since 2.0
	*
	* @param[in]    bindingId          	The binding ID
	* @param[in]    destType          	The destination type
	* @exception    E_SUCCESS        	The method is successful.
	* @exception    E_SYSTEM         	A system error has occurred.
	* @exception    E_OBJ_NOT_FOUND    	The given binding ID is not registered.
	* @exception    E_INVALID_OPERATION    The given binding's trigger is not 'explicit' type.
	* @exception    E_INVALID_ARG  The specified @c destType is not supported in binding ID.
	* @remarks
	* 					- If you have set a data binding listener, @n
					this method is returned after that listener is called.
	*					- The behavior of this method is dependent on the system default locale setting.
	* @see    IDataBindingListener
	*/
	result UpdateBinding(const Tizen::Base::String& bindingId, DataBindingDestinationType destType);

private:
	//
	// This default constructor is intentionally declared as private so that only the platform can create an instance.
	//
	DataBindingContext(void);

	//
	// This destructor is intentionally declared as private so that only the platform can delete an instance.
	//
	DataBindingContext(const Control& contextOwner);

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	DataBindingContext(const DataBindingContext& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	DataBindingContext& operator =(const DataBindingContext& rhs);

private:
	_DataBindingContextImpl* __pDataBindingContextImpl;

	friend class _DataBindingContextImpl;

}; // DataBindingContext

} } // Tizen::Ui
#endif // _FUI_DATA_BINDING_CONTEXT_H_
