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
 * @file		FSecDhKeyParameters.h
 * @brief		This is the header file for the %DhKeyParameters class.
 *
 * This header file contains the declarations of the %DhKeyParameters class.
 */
#ifndef _FSEC_DH_KEY_PARAMETERS_H_
#define _FSEC_DH_KEY_PARAMETERS_H_

#include <FSecIKeyParameters.h>


namespace Tizen { namespace Security
{

/**
 * @class		DhKeyParameters
 * @brief		This class provides methods for retrieving the parameters for the Diffie-Hellman (DH) algorithm.
 *
 * @since		2.0
 *
 * The %DhKeyParameters class provides a subset of the domain parameters for the DH algorithm.
 * For example, a prime number and a generator value are used to exchange keys between two parties. @n
 *
 * For more information on the class features, see <a href="../org.tizen.native.appprogramming/html/guide/security/key_exchange_algorithm.htm">Key exchanging</a>.
 *
 * @see	IKeyParameters
 *
 * The following example demonstrates how to use the %DhKeyParameters class.
 *
 *  @code
 *	void GetParameterExample(void)
 *	{
 *		result r = E_SUCCESS;
 *		KeyPairGenerator *pKeyPairGen = null;
 *		IKeyParameters *pKeyParams = null;
 *
 *		int size = 1024;
 *		int nResult = 0;
 *		ByteBuffer* pResult = null;
 *
 *		// Generates the key.
 *		pKeyPairGen = new KeyPairGenerator();
 *		if (null == pKeyPairGen)
 *		{
 *			goto CATCH;
 *		}
 *
 *		r = pKeyPairGen->Construct(size, L"DH");
 *		if (IsFailed(r))
 *		{
 *			goto CATCH;
 *		}
 *
 *		pKeyParams = pKeyPairGen->GenerateKeyParametersN();
 *		if (null == pKeyParams)
 *		{
 *			goto CATCH;
 *		}
 *
 *		pResult  = pKeyParams->GetParameterValueN(KEY_PARAMETER_DH_P);
 *		if (null == pResult)
 *		{
 *			goto CATCH;
 *		}
 *
 *		nResult  = pKeyParams->GetParameterSize(KEY_PARAMETER_DH_PRIVATE_KEY_SIZE);
 *
 *	CATCH:
 *		delete pKeyPairGen;
 *		delete pResult;
 *		delete pKeyParams;
 *
 *	}
 * @endcode
 */

class _OSP_EXPORT_ DhKeyParameters
	: public IKeyParameters
	, public Tizen::Base::Object
{

public:
	/**
	 * The object is not fully constructed after this constructor is called. For full construction, @n
	 * the Construct() method must be called right after calling this constructor.
	 *
	 * @since		2.0
	 */
	DhKeyParameters(void);

	/**
	 * This destructor overrides Tizen::Base::Object::~Object().
	 *
	 * @since		2.0
	 */
	virtual ~DhKeyParameters(void);

	/**
	 * Constructs and initializes this instance of IKeyParameters with the specified key parameters.
	 *
	 * @since		2.0
	 *
	 * @return		An error code
	 * @param[in]	primeNumber					The prime number 'p' to instantiate
	 * @param[in]	generatorNumber				The generator value 'g' to instantiate
	 * @param[in]	privateKeySize				The size of the private key to instantiate
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_INVALID_ARG				A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 */
	result Construct(const Tizen::Base::ByteBuffer& primeNumber, const Tizen::Base::ByteBuffer& generatorNumber, int privateKeySize);

	/**
	 * Gets the value of domain parameters (in Tizen::Base::ByteBuffer format) for the specified key parameter type.
	 *
	 * @since		2.0
	 *
	 * @return		A pointer to the Tizen::Base::ByteBuffer class that contains the parameter values, @n
	 *				else @c null if an error occurs
	 * @param[in]	paramType					The type of the parameter
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_UNSUPPORTED_TYPE			The specified @c paramType is not supported.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Tizen::Base::ByteBuffer* GetParameterValueN(KeyParameterType paramType) const;

	/**
	 * Gets the size of the private key component.
	 *
	 * @since			2.0
	 *
	 * @return		The size of the private key component
	 * @param[in]	paramType					The type of the parameter
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_UNSUPPORTED_TYPE			The specified @c paramType is not supported.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual int GetParameterSize(KeyParameterType paramType) const;

private:

	//
	// The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	DhKeyParameters(const DhKeyParameters& rhs);

	//
	// The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	//
	// @since 2.0
	//
	DhKeyParameters& operator =(const DhKeyParameters& rhs);

private:
	Tizen::Base::ByteBuffer __prime;
	Tizen::Base::ByteBuffer __generator;
	int __privateKeySize;

	class _DhKeyParametersImpl* __pDhKeyParametersImpl;
	friend class _DhKeyParametersImpl;

}; //DhKeyParameters

} } //Tizen::Security

#endif //_FSEC_DH_KEY_PARAMETERS_H_
