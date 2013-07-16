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
* @file		FIoMmcStorageManager.h
* @brief	This is the header file for the %MmcStorageManager class.
*
* This header file contains the declarations of the %MmcStorageManager class.
*/

#ifndef _FIO_MMC_STORAGE_MANAGER_H_
#define _FIO_MMC_STORAGE_MANAGER_H_

#include <FBaseObject.h>
#include <FBaseResult.h>
#include <FIoIMmcStorageMountListener.h>
#include <FIoIMmcStorageFormatListener.h>

namespace Tizen { namespace Io
{

/**
 * @class	MmcStorageManager
 * @brief	This class provides methods to mount, unmount, and format external MMC.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %MmcStorageManager class provides methods to mount, unmount, and format external MMC.
 *
 * @see IMmcStorageMountListener
 * @see IMmcStorageFormatListener
 *
 * @code
 *
 * #include <FBase.h>
 * #include <FIo.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Io;
 *
 * class MyMmcStorageMountListener
 * : public Tizen::Io::IMmcStorageMountListener
 * {
 * public:
 *	void OnMmcStorageMounted (result r)
 *	{
 *		if (!IsFailed(r))
 *		{
 *			AppLog(“External MMC is mounted”);
 *		}
 *	}
 *
 *	void OnMmcStorageUnmounted (result r)
 *	{
 *		if (!IsFailed(r))
 *		{
 *		    AppLog(“External MMC is unmounted”);
 *		}
 *	}
 * };
 *
 * void
 * MyClass::Execute(void)
 * {
 *		MyMmcStorageMountListener* pMyMmcStorageMountListener = new MyMmcStorageMountListener();
 *
 *		MmcStorageManager* pMmcStorageMgr = new MmcStorageManager();
 *
 *		pMmcStorageMgr->AddMmcStorageMountListener(*pMyMmcStorageMountListener);
 *
 *		pMmcStorageMgr->Mount();
 *
 *		pMmcStorageMgr->Unmount();
 * }
 *
 * @endcode
 */
class _OSP_EXPORT_ MmcStorageManager
           : public Tizen::Base::Object
{

public:
	/**
	* Gets the MMC storage manager instance.
	*
	* @since		2.0
	*
	* @return		A pointer to %MmcStorageManager instance if this method is successful, @n
	*				else @c null
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	static MmcStorageManager* GetInstance(void);

	/**
	* Mounts file system of external MMC.
	*
	* @since		2.0
	* @privlevel	platform
	* @privilege	%http://tizen.org/privilege/settingmanager.write @n
	*				(%http://tizen.org/privilege/systemsetting.read is deprecated.)
	*
	* @return		An error code
	* @exception	E_SUCCESS			Mount operation is successfully started.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_INVALID_OPERATION	The external MMC has already been mounted.
	* @exception	E_SERVICE_BUSY		One of mount, unmount and format operations is ongoing.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		The directory path of the mounted external MMC can be obtained by calling
	*				Environment::GetExternalStoragePath().
	*/
	result Mount(void);

	/**
	* Unmounts file system of external MMC.
	*
	* @since		2.0
	* @privlevel	platform
	* @privilege	%http://tizen.org/privilege/settingmanager.write @n
	*				(%http://tizen.org/privilege/systemsetting.read is deprecated.)
	*
	* @return		An error code
	* @exception	E_SUCCESS			Unmount operation is successfully started.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_INVALID_OPERATION	The external MMC has already been unmounted.
	* @exception	E_SERVICE_BUSY		One of mount, unmount and format operations is ongoing.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	*/
	result Unmount(void);

	/**
	* Formats file system of external MMC.
	*
	* @since		2.0
	* @privlevel	platform
	* @privilege	%http://tizen.org/privilege/settingmanager.write @n
	*				(%http://tizen.org/privilege/systemsetting.read is deprecated.)
	*
	* @return		An error code
	* @exception	E_SUCCESS			Format operation is successfully started.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_INVALID_OPERATION	The external MMC should be unmounted for format operation.
	* @exception	E_SERVICE_BUSY		One of mount, unmount and format operations is ongoing.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	*/
	result Format(void);

	/**
	* Adds the listener for receiving the result of external MMC mount or unmount operations.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	listener			The listener to add
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	*/
	result AddMmcStorageMountListener(IMmcStorageMountListener& listener);

	/**
	* Removes the listener for receiving the result of external MMC mount or unmount operations.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	listener			The listener to add
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	*/
	result RemoveMmcStorageMountListener(IMmcStorageMountListener& listener);

	/**
	* Adds the listener for receiving the result of external MMC format operation.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	listener			The listener to add
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	*/
	result AddMmcStorageFormatListener(IMmcStorageFormatListener& listener);

	/**
	* Removes the listener for receiving the result of external MMC format operation.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	listener			The listener to add
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	*/
	result RemoveMmcStorageFormatListener(IMmcStorageFormatListener& listener);

private:
	/**
	* This default constructor is intentionally declared as private to implement the Singleton semantic.
	*/
	MmcStorageManager(void);

	/**
	* This destructor is intentionally declared as private to implement the Singleton semantic.
	*/
	virtual ~MmcStorageManager(void);

	/**
	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*/
	MmcStorageManager(const MmcStorageManager& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	*/
	MmcStorageManager& operator =(const MmcStorageManager& rhs);

	static void InitSingleton(void);

	static void DestroySingleton(void);

private:
	static MmcStorageManager* __pMmcStorageManagerInstance;
	friend class _MmcStorageManagerImpl;
	class _MmcStorageManagerImpl* __pMmcStorageManagerImpl;

}; // MmcStorageManager

}} // Tizen::Io

#endif // _FIO_MMC_STORAGE_MANAGER_H_
