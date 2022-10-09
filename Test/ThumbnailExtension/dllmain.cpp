#ifndef AAAAAAA

#include <windows.h>
#include <shlobj.h>                 // For SHChangeNotify
#include <thumbcache.h>
#include "ClassFactory.h"           // For the class factory
#include "ShellExtentionsExport.h"

#include <stdio.h>

#include <string>

// When you write your own handler, you must create a new CLSID by using the 
// "Create GUID" tool in the Tools menu, and specify the CLSID value here.
// {4D2FBA8D-621B-4447-AF6D-5794F479C4A5}

// If you change this the value must also be updated in the installer (Product.wxs)
// {EB3D82B6-0FAF-46CD-99C9-BC8081FE89CB}
const CLSID CLSID_UMANG_ThumbnailProvider =
{ 0xeb3d82b6, 0xfaf, 0x46cd, { 0x99, 0xc9, 0xbc, 0x80, 0x81, 0xfe, 0x89, 0xcb } };

#define REGISTRY_BASE			HKEY_CURRENT_USER
#define	CUSTOM_EXTENSION		L".bsdk"
#define	KEY_PREFIX				L"Software\\Classes\\"

////////////////////////////////////////////////////////////
HRESULT DllNotifyShell(void);

void LogStringInternal(const wchar_t* inMsg, const wchar_t* inFunctionName, int inLineNumber)
{
	WCHAR lineStr[64];
	wsprintf(lineStr, L"%d", inLineNumber);

	std::wstring str(L"XXX - ");

	const wchar_t* functionName = inFunctionName;

	str += functionName;
	str += L"( ";
	str += lineStr;
	str += L" )";
	str += L" - ";

	if (inMsg)
	{
		str += inMsg;
	}

	::OutputDebugStringW(str.c_str());
}

#define LogString(inMsg) LogStringInternal(inMsg, __FUNCTIONW__, __LINE__)

HRESULT SetRegistryKeyAndValue(PCWSTR pszSubKey, PCWSTR pszValueName,
	PCWSTR pszData)
{
	HRESULT hr;
	HKEY hKey = NULL;

	// Creates the specified registry key. If the key already exists, the 
	// function opens it. 
	wchar_t keyToWrite[1024];
	wsprintf(keyToWrite, L"%s%s", KEY_PREFIX, pszSubKey);
	LogString(keyToWrite);

	hr = HRESULT_FROM_WIN32(RegCreateKeyEx(REGISTRY_BASE, keyToWrite, 0,
		NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, NULL));

	if (SUCCEEDED(hr))
	{
		if (pszData != NULL)
		{
			// Set the specified value of the key.
			DWORD cbData = lstrlen(pszData) * sizeof(*pszData);
			hr = HRESULT_FROM_WIN32(RegSetValueEx(hKey, pszValueName, 0,
				REG_SZ, reinterpret_cast<const BYTE*>(pszData), cbData));
		}

		RegCloseKey(hKey);
	}
	else
	{
		LogString(L"RegCreateKeyEx Failed!");
	}

	return hr;
}


//
//   FUNCTION: GetRegistryKeyAndValue
//
//   PURPOSE: The function opens a registry key and gets the data for the 
//   specified registry value name.
//
//   PARAMETERS:
//   * pszSubKey - specifies the registry key under base key If the key does not 
//     exist, the function returns an error.
//   * pszValueName - specifies the registry value to be retrieved. If 
//     pszValueName is NULL, the function will get the default value.
//   * pszData - a pointer to a buffer that receives the value's string data.
//   * cbData - specifies the size of the buffer in bytes.
//
//   RETURN VALUE:
//   If the function succeeds, it returns S_OK. Otherwise, it returns an 
//   HRESULT error code. For example, if the specified registry key does not 
//   exist or the data for the specified value name was not set, the function 
//   returns COR_E_FILENOTFOUND (0x80070002).
// 
HRESULT GetRegistryKeyAndValue(PCWSTR pszSubKey, PCWSTR pszValueName,
	PWSTR pszData, DWORD cbData)
{
	HRESULT hr;
	HKEY hKey = NULL;

	wchar_t keyToWrite[1024];
	wsprintf(keyToWrite, L"%s%s", KEY_PREFIX, pszSubKey);
	LogString(keyToWrite);

	// Try to open the specified registry key. 
	hr = HRESULT_FROM_WIN32(RegOpenKeyEx(REGISTRY_BASE, keyToWrite, 0,
		KEY_READ, &hKey));

	if (SUCCEEDED(hr))
	{
		// Get the data for the specified value name.
		hr = HRESULT_FROM_WIN32(RegQueryValueEx(hKey, pszValueName, NULL,
			NULL, reinterpret_cast<LPBYTE>(pszData), &cbData));

		RegCloseKey(hKey);
	}

	return hr;
}

HRESULT DeleteRegistryKey(PCWSTR pszSubKey)
{
	HRESULT hr;
	HKEY hKey = NULL;

	wchar_t keyToDelete[1024];
	wsprintf(keyToDelete, L"%s%s", KEY_PREFIX, pszSubKey);
	LogString(keyToDelete);

	// Try to open the specified registry key. 
	hr = HRESULT_FROM_WIN32(RegDeleteTree(REGISTRY_BASE, keyToDelete));

	return hr;
}

HRESULT RegisterInprocServer(PCWSTR pszModule, const CLSID& clsid,
	PCWSTR pszFriendlyName, PCWSTR pszThreadModel)
{
	if (pszModule == NULL || pszThreadModel == NULL)
	{
		return E_INVALIDARG;
	}

	HRESULT hr;

	wchar_t szCLSID[MAX_PATH];
	StringFromGUID2(clsid, szCLSID, ARRAYSIZE(szCLSID));

	wchar_t szSubkey[MAX_PATH];

	// Create the <BASE KEY>\CLSID\{<CLSID>} key.
	wsprintf(szSubkey, L"CLSID\\%s", szCLSID);
	hr = SetRegistryKeyAndValue(szSubkey, NULL, pszFriendlyName);

	// Create the <BASE KEY>\CLSID\{<CLSID>}\InprocServer32 key.
	if (SUCCEEDED(hr))
	{
		wsprintf(szSubkey,
			L"CLSID\\%s\\InprocServer32", szCLSID);
		// Set the default value of the InprocServer32 key to the 
		// path of the COM module.
		hr = SetRegistryKeyAndValue(szSubkey, NULL, pszModule);
		if (SUCCEEDED(hr))
		{
			// Set the threading model of the component.
			hr = SetRegistryKeyAndValue(szSubkey,
				L"ThreadingModel", pszThreadModel);
			if (FAILED(hr))
			{
				LogString(L"SetRegistryKeyAndValue failed!");
			}
		}
		else
		{
			LogString(L"SetRegistryKeyAndValue failed!");
		}
	}
	else
	{
		LogString(L"SetRegistryKeyAndValue failed!");
	}

	return hr;
}

HRESULT UnregisterInprocServer(const CLSID& clsid)
{
	HRESULT hr = S_OK;

	wchar_t szCLSID[MAX_PATH];
	StringFromGUID2(clsid, szCLSID, ARRAYSIZE(szCLSID));

	wchar_t szSubkey[MAX_PATH];

	// Delete the <BASE KEY>\CLSID\{<CLSID>} key.
	wsprintf(szSubkey, L"CLSID\\%s", szCLSID);
	hr = DeleteRegistryKey(szSubkey);
	if (FAILED(hr))
	{
		LogString(L"DeleteRegistryKey failed!");
		LogString(szSubkey);
	}

	return hr;
}

HRESULT RegisterShellExtThumbnailHandler(PCWSTR pszFileType, const CLSID& clsid)
{
	if (pszFileType == NULL)
	{
		return E_INVALIDARG;
	}

	HRESULT hr;

	wchar_t szCLSID[MAX_PATH];
	StringFromGUID2(clsid, szCLSID, ARRAYSIZE(szCLSID));

	wchar_t szSubkey[MAX_PATH];

	// If pszFileType starts with '.', try to read the default value of the 
	// <BASE KEY>\<File Type> key which contains the ProgID to which the file type 
	// is linked.
	wchar_t szDefaultVal[260] = {};
	if (*pszFileType == L'.')
	{
		hr = GetRegistryKeyAndValue(pszFileType, NULL, szDefaultVal,
			sizeof(szDefaultVal));

		// If the key exists and its default value is not empty, use the 
		// ProgID as the file type.
		if (SUCCEEDED(hr) && szDefaultVal[0] != L'\0')
		{
			pszFileType = szDefaultVal;
		}
	}

	// Create the registry key 
	// <BASE KEY>\<File Type>\ShellEx\{e357fccd-a995-4576-b01f-234630154e96}
	wsprintf(szSubkey, 
		L"%s\\ShellEx\\{e357fccd-a995-4576-b01f-234630154e96}", pszFileType);
	// Set the default value of the key.
	hr = SetRegistryKeyAndValue(szSubkey, NULL, szCLSID);
	if (FAILED(hr))
		LogString(L"SetRegistryKeyAndValue failed!");

	return hr;
}

HRESULT UnregisterShellExtThumbnailHandler(PCWSTR pszFileType)
{
	if (pszFileType == NULL)
	{
		return E_INVALIDARG;
	}

	HRESULT hr;

	wchar_t szSubkey[MAX_PATH];

	// If pszFileType starts with '.', try to read the default value of the 
	// <BASE KEY>\<File Type> key which contains the ProgID to which the file type 
	// is linked.
	if (*pszFileType == L'.')
	{
		wchar_t szDefaultVal[260];
		hr = GetRegistryKeyAndValue(pszFileType, NULL, szDefaultVal,
			sizeof(szDefaultVal));

		// If the key exists and its default value is not empty, use the 
		// ProgID as the file type.
		if (SUCCEEDED(hr) && szDefaultVal[0] != L'\0')
		{
			pszFileType = szDefaultVal;
		}
	}

	// Remove the registry key: 
	// <BASE KEY>\<File Type>\shellex\{e357fccd-a995-4576-b01f-234630154e96}
	wsprintf(szSubkey, 
		L"%s\\shellex\\{e357fccd-a995-4576-b01f-234630154e96}", pszFileType);
	hr = DeleteRegistryKey(szSubkey);
	if (FAILED(hr))
	{
		LogString(L"DeleteRegistryKey failed!");
		LogString(szSubkey);
	}

	return hr;
}
////////////////////////////////////////////////////////////



HINSTANCE   g_hInst = NULL;
long        g_cDllRef = 0;

extern "C" bool __stdcall DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Hold the instance of this DLL module, we will use it to get the 
		// path of the DLL to register the component.
		g_hInst = hModule;
		DisableThreadLibraryCalls(hModule);
		LogString(L"DLL_PROCESS_ATTACH");
		break;

	case DLL_THREAD_ATTACH:
		LogString(L"DLL_THREAD_ATTACH");
		break;

	case DLL_THREAD_DETACH:
		LogString(L"DLL_THREAD_DETACH");
		break;

	case DLL_PROCESS_DETACH:
		LogString(L"DLL_PROCESS_DETACH");
		break;
	}
	return TRUE;
}


//
//   FUNCTION: DllGetClassObject
//
//   PURPOSE: Create the class factory and query to the specific interface.
//
//   PARAMETERS:
//   * rclsid - The CLSID that will associate the correct data and code.
//   * riid - A reference to the identifier of the interface that the caller 
//     is to use to communicate with the class object.
//   * ppv - The address of a pointer variable that receives the interface 
//     pointer requested in riid. Upon successful return, *ppv contains the 
//     requested interface pointer. If an error occurs, the interface pointer 
//     is NULL. 
//
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
 	HRESULT hr = CLASS_E_CLASSNOTAVAILABLE;

	LogString(L"Thumbnail provider!");
 
 	if (IsEqualCLSID(CLSID_UMANG_ThumbnailProvider, rclsid))
 	{
		LogString(L"Thumbnail provider!");
 	}
 
 	return hr;
}


//
//   FUNCTION: DllCanUnloadNow
//
//   PURPOSE: Check if we can unload the component from the memory.
//
//   NOTE: The component can be unloaded from the memory when its reference 
//   count is zero (i.e. nobody is still using the component).
//
STDAPI DllCanUnloadNow(void)
{
	LogString(L"Check!");

	return g_cDllRef > 0 ? S_FALSE : S_OK;
}


//
//   FUNCTION: DllRegisterServer
//
//   PURPOSE: Register the COM server and the thumbnail handler.
//
HRESULT DllRegisterServer(void)
{
	HRESULT hr = S_OK;
	LogString(L"Start");

 	wchar_t szModule[MAX_PATH];
 	if (GetModuleFileName(g_hInst, szModule, ARRAYSIZE(szModule)) == 0)
 	{
 		hr = HRESULT_FROM_WIN32(GetLastError());
 		return hr;
 	}
 
 	// Register the component.
 	hr = RegisterInprocServer(
		szModule, 
		CLSID_UMANG_ThumbnailProvider,
 		L"ShellExtentions Custom BSDK Class",
 		L"Apartment");
 	if (SUCCEEDED(hr))
 	{
 		// Register the thumbnail handler. The thumbnail handler is associated
 		// with the CUSTOM_EXTENSION file class.
 		hr = RegisterShellExtThumbnailHandler(CUSTOM_EXTENSION,
 			CLSID_UMANG_ThumbnailProvider);
 		if (SUCCEEDED(hr))
 		{
 			// This tells the shell to invalidate the thumbnail cache. It is 
 			// important because any custom files viewed before registering 
 			// this handler would otherwise show cached blank thumbnails.
 			SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST, NULL, NULL);
 		}
		else
		{
			LogString(L"RegisterShellExtThumbnailHandler failed!");
		}
 	}
	else
	{
		LogString(L"RegisterInprocServer failed!");
	}

	DllNotifyShell();
 
	LogString(L"End");

	return hr;
}


//
//   FUNCTION: DllUnregisterServer
//
//   PURPOSE: Unregister the COM server and the thumbnail handler.
//
HRESULT DllUnregisterServer(void)
{
	HRESULT hr = S_OK;

	LogString(L"Start");

	wchar_t szModule[MAX_PATH];
	if (GetModuleFileName(g_hInst, szModule, ARRAYSIZE(szModule)) == 0)
	{
		LogString(L"GetModuleFileName failed!");
	 	hr = HRESULT_FROM_WIN32(GetLastError());
	 	return hr;
	}
	 
	// Unregister the component.
	hr = UnregisterInprocServer(CLSID_UMANG_ThumbnailProvider);
	if (SUCCEEDED(hr))
	{
	 	// Unregister the thumbnail handler.
	 	hr = UnregisterShellExtThumbnailHandler(CUSTOM_EXTENSION);
		if (FAILED(hr))
			LogString(L"UnregisterShellExtThumbnailHandler failed!");
	}
	else
	{
		LogString(L"UnregisterInprocServer failed!");
	}

	DllNotifyShell();

	LogString(L"End");

	return hr;
}

//
//   FUNCTION: DllNofifyShell
//
//   PURPOSE: Notify the Windows Shell that file associations have changed.
//   This causes it to refresh the thumbnail cache.
//
HRESULT DllNotifyShell(void)
{
	// This tells the shell to invalidate the thumbnail cache. It is 
	// important because any custom files viewed before registering 
	// this handler would otherwise show cached blank thumbnails.
	LogString(L"Start");

	SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST, NULL, NULL);

	LogString(L"End");

	return S_OK;
}

#else
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#include <objbase.h>
#include <shlwapi.h>
#include <thumbcache.h> // For IThumbnailProvider.
#include <shlobj.h>     // For SHChangeNotify
#include <new>
#include <string>

#define SZ_CLSID_RECIPETHUMBHANDLER     L"{eb3d82b6-2a80-4f08-93b9-2eb526477d1b}"
#define SZ_RECIPETHUMBHANDLER           L"Recipe Thumbnail Handler"

const CLSID CLSID_RecipeThumbHandler    = {0xeb3d82b6, 0x2a80, 0x4f08, {0x93, 0xb9, 0x2e, 0xb5, 0x26, 0x47, 0x7d, 0x1b}};

void LogStringInternal(const wchar_t* inMsg, const wchar_t* inFunctionName, int inLineNumber)
{
	WCHAR lineStr[64];
	wsprintf(lineStr, L"%d", inLineNumber);

	std::wstring str(L"XXX - ");

	const wchar_t* functionName = inFunctionName;

	str += functionName;
	str += L"( ";
	str += lineStr;
	str += L" )";
	str += L" - ";

	if (inMsg)
	{
		str += inMsg;
	}

	::OutputDebugStringW(str.c_str());
}

#define LogString(inMsg) LogStringInternal(inMsg, __FUNCTIONW__, __LINE__)

typedef HRESULT (*PFNCREATEINSTANCE)(REFIID riid, void **ppvObject);
struct CLASS_OBJECT_INIT
{
	const CLSID *pClsid;
	PFNCREATEINSTANCE pfnCreate;
};

long g_cRefModule = 0;

// Handle the the DLL's module
HINSTANCE g_hInst = NULL;

// Standard DLL functions
STDAPI_(BOOL) DllMain(HINSTANCE hInstance, DWORD dwReason, void *)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		g_hInst = hInstance;
		DisableThreadLibraryCalls(hInstance);
	}
	return TRUE;
}

STDAPI DllCanUnloadNow()
{
	// Only allow the DLL to be unloaded after all outstanding references have been released
	return (g_cRefModule == 0) ? S_OK : S_FALSE;
}

void DllAddRef()
{
	InterlockedIncrement(&g_cRefModule);
}

void DllRelease()
{
	InterlockedDecrement(&g_cRefModule);
}

extern "C" HRESULT __stdcall DllGetClassObject(REFCLSID clsid, REFIID riid, void** ppv)
{
	LogString(L"Got it!!!");

	return CLASS_E_CLASSNOTAVAILABLE;
}

// A struct to hold the information required for a registry entry

struct REGISTRY_ENTRY
{
	HKEY   hkeyRoot;
	PCWSTR pszKeyName;
	PCWSTR pszValueName;
	PCWSTR pszData;
};

// Creates a registry key (if needed) and sets the default value of the key

HRESULT CreateRegKeyAndSetValue(const REGISTRY_ENTRY *pRegistryEntry)
{
	HKEY hKey;
	HRESULT hr = HRESULT_FROM_WIN32(RegCreateKeyExW(pRegistryEntry->hkeyRoot, pRegistryEntry->pszKeyName,
		0, NULL, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, NULL, &hKey, NULL));
	if (SUCCEEDED(hr))
	{
		hr = HRESULT_FROM_WIN32(RegSetValueExW(hKey, pRegistryEntry->pszValueName, 0, REG_SZ,
			(LPBYTE) pRegistryEntry->pszData,
			((DWORD) wcslen(pRegistryEntry->pszData) + 1) * sizeof(WCHAR)));
		RegCloseKey(hKey);
	}
	return hr;
}

//
// Registers this COM server
//
EXTERN_C HRESULT DllRegisterServer()
{
	HRESULT hr;

	WCHAR szModuleName[MAX_PATH];

	if (!GetModuleFileNameW(g_hInst, szModuleName, ARRAYSIZE(szModuleName)))
	{
		hr = HRESULT_FROM_WIN32(GetLastError());
	}
	else
	{
		// List of registry entries we want to create
		const REGISTRY_ENTRY rgRegistryEntries[] =
		{
			// RootKey            KeyName                                                                ValueName                     Data
			{HKEY_CURRENT_USER,   L"Software\\Classes\\CLSID\\" SZ_CLSID_RECIPETHUMBHANDLER,                                 NULL,                           SZ_RECIPETHUMBHANDLER},
			{HKEY_CURRENT_USER,   L"Software\\Classes\\CLSID\\" SZ_CLSID_RECIPETHUMBHANDLER L"\\InProcServer32",             NULL,                           szModuleName},
			{HKEY_CURRENT_USER,   L"Software\\Classes\\CLSID\\" SZ_CLSID_RECIPETHUMBHANDLER L"\\InProcServer32",             L"ThreadingModel",              L"Apartment"},
			{HKEY_CURRENT_USER,   L"Software\\Classes\\.recipe\\ShellEx\\{e357fccd-a995-4576-b01f-234630154e96}",            NULL,                           SZ_CLSID_RECIPETHUMBHANDLER},
		};

		hr = S_OK;
		for (int i = 0; i < ARRAYSIZE(rgRegistryEntries) && SUCCEEDED(hr); i++)
		{
			hr = CreateRegKeyAndSetValue(&rgRegistryEntries[i]);
		}
	}
	if (SUCCEEDED(hr))
	{
		// This tells the shell to invalidate the thumbnail cache.  This is important because any .recipe files
		// viewed before registering this handler would otherwise show cached blank thumbnails.
		SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST, NULL, NULL);
	}
	return hr;
}

//
// Unregisters this COM server
//
EXTERN_C HRESULT DllUnregisterServer()
{
	HRESULT hr = S_OK;

	const PCWSTR rgpszKeys[] =
	{
		L"Software\\Classes\\CLSID\\" SZ_CLSID_RECIPETHUMBHANDLER,
		L"Software\\Classes\\.recipe\\ShellEx\\{e357fccd-a995-4576-b01f-234630154e96}"
	};

	// Delete the registry entries
	for (int i = 0; i < ARRAYSIZE(rgpszKeys) && SUCCEEDED(hr); i++)
	{
		hr = HRESULT_FROM_WIN32(RegDeleteTreeW(HKEY_CURRENT_USER, rgpszKeys[i]));
		if (hr == HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND))
		{
			// If the registry entry has already been deleted, say S_OK.
			hr = S_OK;
		}
	}
	return hr;
}
#endif