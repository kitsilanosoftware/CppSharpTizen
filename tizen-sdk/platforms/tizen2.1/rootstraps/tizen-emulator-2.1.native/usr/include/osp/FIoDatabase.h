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
 * @file	FIoDatabase.h
 * @brief	This is the header file for the %Database class.
 *
 * This header file contains the declarations of the %Database class.
 */

#ifndef _FIO_DATABASE_H_
#define _FIO_DATABASE_H_

#include <FBaseObject.h>
#include <FBaseString.h>
#include <FBaseColArrayList.h>
#include <FBaseRtMutex.h>

namespace Tizen { namespace Base
{
class ByteBuffer;
}}

namespace Tizen { namespace Io
{

class DbStatement;
class DbEnumerator;

/**
 * @class	Database
 * @brief	This class provides the basic database and database entry management methods.
 *
 * @since	2.0
 *
 * @final	This class is not intended for extension.
 *
 * The %Database class provides the basic database and database entry management methods.
 * All members of this class are guaranteed to be thread-safe.
 *
 * For more information on the class features,
 * see <a href="../org.tizen.native.appprogramming/html/guide/io/database_operations.htm">Database Operations</a>.
 *
 * @see Tizen::Io::DbStatement
 * @see Tizen::Io::DbEnumerator
 *
 * The following example demonstrates how to use the %Database class.
 *
 * @code
#include <FIo.h>
#include <FApp.h>

using namespace Tizen::Io;
using namespace Tizen::App;

result
MyTest::UsingDatabase(void)
{
	Database* pDatabase;
	DbStatement* pStmt;
	DbEnumerator* pEnum;
	String dbName;
	String sql, sql2, sql3;
	String statement;
	String stringItem;
	result r = E_SUCCESS;

	dbName = App::GetInstance()->GetAppDataPath() + L"sample.db");

	pDatabase = new Database();
	if (!pDatabase)
	{
		goto CATCH;
	}

	r = pDatabase->Construct(dbName, "a+");
	if (IsFailed(r))
	{
		goto CATCH;
	}

	AppLog("Create database table:");
	sql.Append(L"CREATE TABLE IF NOT EXISTS myTable1 ( column0 INTEGER PRIMARY KEY, column1 DOUBLE, column2 TEXT )");

	r = pDatabase->ExecuteSql(sql, true);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	AppLog("Insert rows:");
	pDatabase->BeginTransaction();

	statement.Append(L"INSERT INTO myTable1 (column0, column1, column2) VALUES (?, ?, ?)");
	pStmt = pDatabase->CreateStatementN(statement);

	stringItem.Append(L"Initial Data");
	for (int i = 0; i < 10; i++)
	{
		pStmt->BindInt(0, i);
		pStmt->BindDouble(1, i * 0.1);
		pStmt->BindString(2, stringItem);

		pEnum = pDatabase->ExecuteStatementN(*pStmt);
		AppAssert(!pEnum);
	}

	pDatabase->CommitTransaction();

	delete pStmt;

	AppLog("Select query using Database::QueryN() wrapper API:");
	pEnum = pDatabase->QueryN(L"SELECT * FROM myTable1 WHERE column0 < 5");
	if (pEnum)
	{
		int nRows = 0;
		int iVal;
		double fVal;
		String strVal;
		while (pEnum->MoveNext() == E_SUCCESS)
		{
			r = pEnum->GetIntAt(0, iVal);
			if (IsFailed(r))
			{
				goto CATCH;
			}

			r = pEnum->GetDoubleAt(1, fVal);
			if (IsFailed(r))
			{
				goto CATCH;
			}

			r = pEnum->GetStringAt(2, strVal);
			if (IsFailed(r))
			{
				goto CATCH;
			}

			AppLog("[%d] column0=%d, column1=%f, column2=%ls", nRows++, iVal, fVal, strVal.GetPointer());
		}
        delete pEnum;
	}

	AppLog("Select query using statement:");
	pStmt = pDatabase->CreateStatementN(L"SELECT * FROM myTable1 WHERE column0 > ? AND column0 < ?");
	r = GetLastResult();
	if (IsFailed(r))
	{
		goto CATCH;
	}
	AppAssert(pStmt);

	r = pStmt->BindInt(0, 3);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	r = pStmt->BindInt(1, 8);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	pEnum = pDatabase->ExecuteStatementN(*pStmt);
	r = GetLastResult();
	if (IsFailed(r))
	{
		goto CATCH;
	}

	if (pEnum)
	{
		int nRows = 0;
		int iVal;
		double fVal;
		String strVal;
		while (pEnum->MoveNext() == E_SUCCESS)
		{
			r = pEnum->GetIntAt(0, iVal);
			if (IsFailed(r))
			{
				goto CATCH;
			}

			r = pEnum->GetDoubleAt(1, fVal);
			if (IsFailed(r))
			{
				goto CATCH;
			}

			r = pEnum->GetStringAt(2, strVal);
			if (IsFailed(r))
			{
				goto CATCH;
			}

			AppLog("[%d] column0=%d, column1=%f, column2=%ls", nRows++, iVal, fVal, strVal.GetPointer());
		}
		delete pEnum;
	}

	AppLog("Delete rows:");
	pDatabase->BeginTransaction();

	sql2.Append(L"DELETE FROM myTable1 WHERE column0 = 1");
	r = pDatabase->ExecuteSql(sql2, true);

	if (r != E_SUCCESS)
	{
		goto CATCH;
	}

	pDatabase->CommitTransaction();

	AppLog("Update rows:");
	pDatabase->BeginTransaction();

	sql3.Append(L"UPDATE myTable1 SET column2 = 'Converted Data' WHERE column2 = 'Initial Data'");
	r = pDatabase->ExecuteSql(sql3, true);

	if (r != E_SUCCESS)
	{
		goto CATCH;
	}

	pDatabase->CommitTransaction();

	// Resource cleanup
	delete pDatabase;
	pDatabase = null;

	r = Database::Delete(dbName);
	if (IsFailed(r))
	{
		goto CATCH;
	}

	AppLog("Finished successfully...");
	return E_SUCCESS;

CATCH:
	if (pDatabase)
	{
		delete pDatabase;
		pDatabase = null;
	}

	if (Database::Exists(dbName))
	{
		Database::Delete(dbName);
	}

	return r;
}
 * @endcode
 */

class _OSP_EXPORT_ Database
	: public Tizen::Base::Object
{

public:
	/**
	* The object is not fully constructed after this constructor is called. For full construction, the Construct() method must be called right after calling this constructor.
	*
	* @since	2.0
	*/
	Database(void);

	/**
	* This destructor overrides Tizen::Base::Object::~Object().
	*
	* @since	2.0
	*/
	virtual ~Database(void);

	/**
	* @{
	* @if OSPDEPREC
	* Initializes this instance of %Database with the specified parameters. @n
	* This method creates a new database file or opens an existing database file in the read-write mode.
	*
	* @deprecated		This method is deprecated. Instead of using this method, use Directory::Create(const Tizen::Base::String &dirPath,
	*					bool createParentDirectories=false) and Database::Construct(const Tizen::Base::String& dbPath, const Tizen::Base::String& openMode).
	* @since			2.0
	*
	* @return		An error code
	* @param[in]	dbPath					The path of the database file to open
	* @param[in]	createIfNotExist		Set to @c true to create a database file, @n
	*										else @c false to open an existing database file
	* @exception   	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*										- The length of the specified @c dbPath is invalid. @n
	*										- The specified @c dbPath is invalid or the path ends with '/'. @n
	*										- The directory name path is missing. @n
	*										- The parent directory does not exist. @n
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified database file already exists. @n
	*										Creation of database file has failed because the destination file already exists. @n
	*										Creation of the database file is attempted if the file does not exist and
	*										the specified @c createIfNotExist is @c true.
	*										However, at this moment another thread has been already created the database file
	*										with the same file path.
	*										This is a rare case, however, it is possible if a race condition is present between several threads.
	* @exception	E_FILE_NOT_FOUND		The specified database file cannot be found or accessed.
	* @exception	E_DATABASE				Either of the following conditions has occurred: @n
	*										- The method has failed to open or create a file. @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @remarks	To open the database file in the read-only mode,
	*			use the Database::Construct(const Tizen::Base::String& dbPath, const char* pOpenMode) method
	*			with "r" as the value for the open mode flag.
	* @endif
	* @}
	*/
	result Construct(const Tizen::Base::String& dbPath, bool createIfNotExist);

	/**
	* @{
	* @if OSPDEPREC
	* Initializes this instance of %Database with the specified parameters. @n
	* This method creates a new database file or opens an existing database file in the read-only or the read-write mode.
	*
	* @deprecated		This method is deprecated. Instead of using this method, use Directory::Create(const Tizen::Base::String &dirPath,
	*					bool createParentDirectories=false) and Database::Construct(const Tizen::Base::String& dbPath, const Tizen::Base::String& openMode).
	* @since			2.0
	*
	* @return		An error code
	* @param[in]	dbPath					The path of the database file to open
	* @param[in]	openMode				An open mode flag @n
	*										Currently, the following flags can be used in combination with the logical OR operator: @n
	*										 (1) DB_OPEN_READ_ONLY @n
	*										 (2) DB_OPEN_READ_WRITE @n
	*										 (3) DB_OPEN_READ_WRITE | DB_OPEN_CREATE
	* @param[in]	option					This argument is reserved for further use
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*										- The length of the specified @c dbPath is invalid. @n
	*										- The specified @c openMode is invalid. @n
	*										- The specified @c dbPath is invalid or the path ends with '/'. @n
	*										- The directory name path is missing. @n
	*										- The parent directory does not exist. @n
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified database file already exists.
	* @exception	E_FILE_NOT_FOUND		The specified database file cannot be found or accessed.
	* @exception	E_DATABASE				Either of the following conditions has occurred: @n
	*										- The method has failed to open or create a file. @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @endif
	* @}
	*/
	result Construct(const Tizen::Base::String& dbPath, long openMode, long option);

	/**
	* Initializes this instance of %Database with the specified parameters. @n
	* This method opens an existing database file or creates a new database file according to the specified file opening mode.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	dbPath				The path of the database file to open or create
	* @param[in]	pOpenMode			The file opening mode @n
	*									It can be one of the following:
	*									- r : Open for reading.
	*									- r+: Open for reading and writing.
	*									- a+: Open for writing and reading. The database file is created if it does not exist.
	* @exception    E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The overall length of the specified @c dbPath is equal to @c 0 or
	*									  exceeds system limitations. @n
	*									- The specified @c dbPath ends with '/'. @n
	*									- The combination of the specified @c pOpenMode is not allowed. @n
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception	E_FILE_NOT_FOUND	The specified @c dbPath cannot be found.
	* @exception	E_INVALID_FORMAT	The specified @c dbPath is not a database.
	* @exception    E_STORAGE_FULL		The disk space is full.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected. @n
	*/
	result Construct(const Tizen::Base::String& dbPath, const char* pOpenMode);

	/**
	* Initializes this instance of %Database with the specified parameters. @n
	* This method opens an existing secure database file or creates a new one according to the specified file opening mode.
	* The contents written to the secure database file is automatically encrypted and the contents read from the secure database
	* file is automatically decrypted by the platform. @n
	* Applications using this method can access the same secure database files that are created by other applications with the
	* identical key value in same device. However, the secure files created by this method cannot be accessed in other devices.
	*
	* @since		2.0
	* @feature		%http://tizen.org/feature/database.encryption
	*
	* @return		An error code
	* @param[in]	dbPath					The path of the database file to open or create
	* @param[in]	pOpenMode				The file opening mode @n
	*										It can be one of the following: @n
	*										- r : Open for reading @n
	*										- r+: Open for reading and writing @n
	*										- a+: Open for writing and reading. The database file is created if it does not exist. @n
	* @param[in]	secretKey				A key used to encrypt data of a database file or decrypt a secure database file @n
	*										If a secure database file is created with a specific key value,
	*										other applications can access the same secure database file with the identical key value.
	* @exception    E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*										- The overall length of the specified @c dbPath is equal to @c 0 or
	*										  exceeds system limitations. @n
	*										- The specified @c dbPath ends with '/'. @n
	*										- The combination of the specified @c pOpenMode is not allowed. @n
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_NOT_FOUND		The specified @c dbPath cannot be found.
	* @exception	E_INVALID_FORMAT		The specified @c dbPath is not a database.
	* @exception    E_STORAGE_FULL			The disk space is full.
	* @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected. @n
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. For more information, see
	*										<a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @remarks		Before calling this method, check whether the feature is supported by Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	*/
	result Construct(const Tizen::Base::String& dbPath, const char* pOpenMode, const Tizen::Base::ByteBuffer& secretKey);

	/**
	* Creates a SQL statement for the current database.
	*
	* @since			2.0
	*
	* @return		A pointer to the DbStatement instance, @n
	*               else @c null if an exception occurs
	* @param[in]	sqlStatement		The SQL statement to compile
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c sqlStatement is invalid SQL.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @see			ExecuteStatementN()
	*/
	DbStatement* CreateStatementN(const Tizen::Base::String& sqlStatement);

	/**
	* Executes a statement in the calling %Database instance. @n
	* If an application opens a database file using Database::Construct(const Tizen::Base::String& dbPath,
	* const char* pOpenMode, const Tizen::Base::ByteBuffer& secretKey),
	* the data set written by INSERT/UPDATE is automatically encrypted by the Tizen platform and
	* the data set read by SELECT is also decrypted by itself.
	*
	* @since			2.0
	*
	* @return		A pointer to the DbEnumerator instance, @n
	*				else @c null if an exception occurs, if no result set is generated after the successful execution of the
	*				SELECT query, or if one of INSERT, UPDATE, and DELETE queries is executed.
	* @param[in]	dbStatement			The DbStatement instance to execute
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c dbStatement includes invalid SQL.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_STORAGE_FULL		The disk space or database image is full.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		If @c dbStatement contains the SELECT query, the Reset() method of the DbEnumerator instance returned
	* 				from this method should be called. The Reset() method should be called before re-binding the dbStatement
	* 				with the bind methods of the DbStatement class.
	* 				This method returns an enumerator if the result set is generated by the SELECT query.
	* 				@c null is returned if no result set is available after the successful execution of the SELECT query.
	* 				Note that, a return value of @c null does not mean that the statement execution has failed.
	* 				The enumerator returned by the SELECT query does not indicate any row before it calls DbEnumerator::MoveNext().
	* 				The specific error code can be accessed using the GetLastResult() method.
	*/
	DbEnumerator* ExecuteStatementN(const DbStatement& dbStatement);

	/**
	* Executes SQL statement in this %Database instance. @n
	* Any SQL statement that does not give a result set can be run using this method; for example, CREATE, INSERT, UPDATE, DELETE.
	* The SELECT query cannot be executed using this method. @n
	* If an application opens a database file using Database::Construct(const Tizen::Base::String& dbPath,
	* const char* pOpenMode, const Tizen::Base::ByteBuffer& key),
	* the data set written by INSERT/UPDATE is automatically encrypted by the Tizen platform.
	*
	* @since			2.0
	*
	* @return		An error code
	* @param[in]	sqlStatement		The SQL statement to execute
	* @param[in]	option		    	This argument is reserved for further use.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c sqlStatement is invalid SQL.
	* @exception	E_INVALID_OPERATION	The specified @c sqlStatement is a SELECT query.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_STORAGE_FULL		The disk space or database image is full.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		Use QueryN() to execute SELECT query.
	* @see			QueryN()
	*/
	result ExecuteSql(const Tizen::Base::String& sqlStatement, bool option);

	/**
	* Executes a SELECT query in the calling %Database instance. @n
	* If an application opens a database file using Database::Construct(const Tizen::Base::String& dbPath,
	* const char* pOpenMode, const Tizen::Base::ByteBuffer& key),
	* the data set read by SELECT is automatically decrypted by the Tizen platform.
	*
	* @since			2.0
	*
	* @return		A pointer to the %DbEnumerator instance, @n
	*				else @c null if an exception occurs or if no result set is generated after the successful execution of the SELECT query
	* @param[in]	sqlStatement		The SQL statement to execute
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified @c sqlStatement is invalid SQL.
	* @exception	E_INVALID_OPERATION	The specified @c sqlStatement is not a SELECT query.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		This method returns an enumerator if the result set is generated by the SELECT query.
	* 				@c null is returned if no result set is available after the successful execution of the SELECT query.
	* 				Note that, a return value of @c null does not mean that the statement execution has failed.
	* 				The enumerator returned by the SELECT query does not indicate any row before it calls
	* 				DbEnumerator::MoveNext().
	* 				The specific error code can be accessed using the GetLastResult() method.
	* @see          ExecuteSql()
	*/
	DbEnumerator* QueryN(const Tizen::Base::String& sqlStatement);

	/**
	* Begins a transaction within this %Database instance.
	*
	* @since			2.0
	*
	* @return		An error code
	* @exception    E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE 	The transaction has already begun.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @see			CommitTransaction()
    * @see	        RollbackTransaction()
	*/
	result BeginTransaction(void);

	/**
	* Commits a transaction within this %Database instance.
	*
	* @since			2.0
	*
	* @return		An error code
	* @exception    E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The transaction mode is not activated.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_STORAGE_FULL		The disk space or database image is full.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @remarks		Database::CommitTransaction() automatically resets not only all the DbStatement instances
	*				but also all the DbEnumerator instances obtained from the current %Database instance.
	*				As a result, the prepared statement of the %DbStatement instances are reset to its initial state, ready to be re-executed,
	*				and enumerator of the %DbEnumerator instances are reset to the first position.
	*				Therefore, the user should be careful when the same instance of the %Database class is shared across multiple threads.
	*				Further, access to the %DbStatement or %DbEnumerator instances resets due to commit operation. This will eventually lead to crash.
	*				To avoid a crash, the user can use multiple database instances for each thread.
	*				Sharing of the same database instance across multiple threads is not recommended.
	* @see			BeginTransaction()
	* @see			RollbackTransaction()
	*/
	result CommitTransaction(void);

	/**
	* Aborts a running transaction within this %Database instance.
	*
	* @since			2.0
	*
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		The transaction mode is not activated.
	* @exception	E_OBJECT_LOCKED		The database instance is locked.
	* @exception	E_INVALID_FORMAT 	The database file is malformed.
	* @exception	E_STORAGE_FULL		The disk space or database image is full.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected.
	* @exception	E_SYSTEM			The method cannot proceed due to a severe system error.
	* @see			BeginTransaction()
    * @see	        CommitTransaction()
	*/
	result RollbackTransaction(void);

	/**
	* Gets the database's filename.
	*
	* @since		2.0
	*
	* @return		The filename of this %Database instance
	*/
	Tizen::Base::String GetName(void) const;

	/**
	* Deletes the database file with the specified file name.
	*
	* @since		2.0
	*
	* @return		An error code
	* @param[in]	databasePath		The path of the database file to delete
	* @exception    E_SUCCESS			The method is successful.
	* @exception    E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The length of the specified @c databasePath is invalid. @n
	*									- The specified @c databasePath parameter contains an invalid path or
	*									  the path ends with '/'. @n
	*									- The directory name path is missing. @n
	*									- The parent directory does not exist. @n
	*									- An I/O security issue.
	* @exception    E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception 	E_FILE_NOT_FOUND	The specified database file cannot be found.
	* @exception	E_IO				Either of the following conditions has occurred: @n
	*									- An unexpected device failure has occurred as the media ejected suddenly. @n
	*									- %File corruption is detected. @n
	*									- A system error has occurred.
	*/
	static result Delete(const Tizen::Base::String& databasePath);

	/**
	* Checks whether the database file exists.
	*
	* @since		2.0
	*
	* @return		@c true if the database file exists, @n
	*				else @c false
	* @param[in]	databasePath		The path of the database file to check
	* @exception    E_SUCCESS			The method is successful.
	* @exception    E_INVALID_ARG		Either of the following conditions has occurred: @n
	*									- The length of the specified @c databasePath is invalid. @n
	*									- The specified @c databasePath parameter contains an invalid path or
	*									  the path ends with '/'. @n
	*									- The directory name path is missing. @n
	*									- The parent directory does not exist. @n
	*									- An I/O security issue.
	* @exception    E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	static bool Exists(const Tizen::Base::String& databasePath);

	/**
	* Converts a normal database file to a secure database file. @n
	* A secure database file, that is converted by this method, can be shared among applications with the same key value.
	*
	* @since			2.0
	* @feature			%http://tizen.org/feature/database.encryption
	*
	* @return		An error code
	* @param[in]	normalDbPath			The normal (non-encrypted) database file path
	* @param[in]	secureDbPath			The secure (encrypted) database file path to create
	* @param[in]	secretKey				A key to encrypt normal database file @n
	*										If the normal database file is converted with a specific key value,
	*										applications can access the same secure database file with the identical key value.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*										- The length of the specified path is @c 0 or exceeds system limitations. @n
	*										- The specified path is invalid. @n
	* @exception 	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_NOT_FOUND		The specified @c normalDbPath does not exist.
	* @exception	E_FILE_ALREADY_EXIST	The specified @c secureDbPath already exists.
	* @exception	E_OBJECT_LOCKED			The database instance is locked.
	* @exception	E_INVALID_FORMAlT	 	The database file is malformed.
	* @exception	E_STORAGE_FULL			The disk space or database image is full.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- %File corruption is detected.
	* @exception	E_SYSTEM				The method cannot proceed due to a severe system error.
	* @exception	E_UNSUPPORTED_OPERATION	The Emulator or target device does not support the required feature. For more information, see
	*										<a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
	* @remarks		Before calling this method, check whether the feature is supported by Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
	*/
	static result ConvertToSecureDatabase(const Tizen::Base::String& normalDbPath, const Tizen::Base::String& secureDbPath,
			const Tizen::Base::ByteBuffer& secretKey);

	/**
	* Gets the last inserted row ID.
	*
	* @since		2.0
	*
	* @return		Row ID of the most recent successful insert, @n
	*				else @c -1 if no successful INSERT operations have ever occurred on
	*				the current opened database.
	* @remarks		The row ID is always available as an undeclared column named ROWID, OID, or _ROWID_
	*				as long as those names are not also used by explicitly declared columns.
	*				If the table has a column of type INTEGER PRIMARY KEY then that column is another alias
	*				for the row ID. @n
	*				This method returns the row ID of the most recent successful INSERT operation
	*				for current %Database.
	*/
	long long GetLastInsertRowId(void) const;

	/**
	*/

private:
	/**
 	* The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
	*
	* @since	2.0
	*/
	Database(const Database& rhs);

	/**
	* The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
	* @since	2.0
	*/
	Database& operator =(const Database& rhs);

	/**
	* The implementation of this method is intentionally blank and declared as private to prohibit implicit conversion.
	*
	* @since	2.0
	*/
	result Construct(const Tizen::Base::String& dbPath, const wchar_t* pOpenMode);

	class _DatabaseImpl* __pDatabaseImpl;

	friend class _DatabaseImpl;

}; // Database

}} // Tizen::Io

#endif //_FIO_DATABASE_H_

