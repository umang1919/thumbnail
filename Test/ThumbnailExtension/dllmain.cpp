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
const CLSID CLSID_STLThumbnailProvider =
{ 0xeb3d82b6, 0xfaf, 0x46cd, { 0x99, 0xc9, 0xbc, 0x80, 0x81, 0xfe, 0x89, 0xcb } };

////////////////////////////////////////////////////////////
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

HRESULT SetHKCRRegistryKeyAndValue(PCWSTR pszSubKey, PCWSTR pszValueName,
	PCWSTR pszData)
{
	HRESULT hr;
	HKEY hKey = NULL;

	// Creates the specified registry key. If the key already exists, the 
	// function opens it. 
	hr = HRESULT_FROM_WIN32(RegCreateKeyEx(HKEY_CLASSES_ROOT, pszSubKey, 0,
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
		LogString(pszSubKey);
	}

	return hr;
}


//
//   FUNCTION: GetHKCRRegistryKeyAndValue
//
//   PURPOSE: The function opens a HKCR registry key and gets the data for the 
//   specified registry value name.
//
//   PARAMETERS:
//   * pszSubKey - specifies the registry key under HKCR. If the key does not 
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
HRESULT GetHKCRRegistryKeyAndValue(PCWSTR pszSubKey, PCWSTR pszValueName,
	PWSTR pszData, DWORD cbData)
{
	HRESULT hr;
	HKEY hKey = NULL;

	// Try to open the specified registry key. 
	hr = HRESULT_FROM_WIN32(RegOpenKeyEx(HKEY_CLASSES_ROOT, pszSubKey, 0,
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

	// Create the HKCR\CLSID\{<CLSID>} key.
	wsprintf(szSubkey, L"CLSID\\%s", szCLSID);
	hr = SetHKCRRegistryKeyAndValue(szSubkey, NULL, pszFriendlyName);

	// Create the HKCR\CLSID\{<CLSID>}\InprocServer32 key.
	if (SUCCEEDED(hr))
	{
		wsprintf(szSubkey,
			L"CLSID\\%s\\InprocServer32", szCLSID);
		// Set the default value of the InprocServer32 key to the 
		// path of the COM module.
		hr = SetHKCRRegistryKeyAndValue(szSubkey, NULL, pszModule);
		if (SUCCEEDED(hr))
		{
			// Set the threading model of the component.
			hr = SetHKCRRegistryKeyAndValue(szSubkey,
				L"ThreadingModel", pszThreadModel);
			if (FAILED(hr))
			{
				LogString(L"SetHKCRRegistryKeyAndValue failed!");
			}
		}
		else
		{
			LogString(L"SetHKCRRegistryKeyAndValue failed!");
		}
	}
	else
	{
		LogString(L"SetHKCRRegistryKeyAndValue failed!");
	}

	return hr;
}

HRESULT UnregisterInprocServer(const CLSID& clsid)
{
	HRESULT hr = S_OK;

	wchar_t szCLSID[MAX_PATH];
	StringFromGUID2(clsid, szCLSID, ARRAYSIZE(szCLSID));

	wchar_t szSubkey[MAX_PATH];

	// Delete the HKCR\CLSID\{<CLSID>} key.
	wsprintf(szSubkey, L"CLSID\\%s", szCLSID);
	hr = HRESULT_FROM_WIN32(RegDeleteTree(HKEY_CLASSES_ROOT, szSubkey));
	if (FAILED(hr))
		LogString(L"RegDeleteTree failed!");

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
	// HKCR\<File Type> key which contains the ProgID to which the file type 
	// is linked.
	if (*pszFileType == L'.')
	{
		wchar_t szDefaultVal[260];
		hr = GetHKCRRegistryKeyAndValue(pszFileType, NULL, szDefaultVal,
			sizeof(szDefaultVal));

		// If the key exists and its default value is not empty, use the 
		// ProgID as the file type.
		if (SUCCEEDED(hr) && szDefaultVal[0] != L'\0')
		{
			pszFileType = szDefaultVal;
		}
	}

	// Create the registry key 
	// HKCR\<File Type>\shellex\{e357fccd-a995-4576-b01f-234630154e96}
	wsprintf(szSubkey, 
		L"%s\\shellex\\{e357fccd-a995-4576-b01f-234630154e96}", pszFileType);
	// Set the default value of the key.
	hr = SetHKCRRegistryKeyAndValue(szSubkey, NULL, szCLSID);
	if (FAILED(hr))
		LogString(L"SetHKCRRegistryKeyAndValue failed!");

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
	// HKCR\<File Type> key which contains the ProgID to which the file type 
	// is linked.
	if (*pszFileType == L'.')
	{
		wchar_t szDefaultVal[260];
		hr = GetHKCRRegistryKeyAndValue(pszFileType, NULL, szDefaultVal,
			sizeof(szDefaultVal));

		// If the key exists and its default value is not empty, use the 
		// ProgID as the file type.
		if (SUCCEEDED(hr) && szDefaultVal[0] != L'\0')
		{
			pszFileType = szDefaultVal;
		}
	}

	// Remove the registry key: 
	// HKCR\<File Type>\shellex\{e357fccd-a995-4576-b01f-234630154e96}
	wsprintf(szSubkey, 
		L"%s\\shellex\\{e357fccd-a995-4576-b01f-234630154e96}", pszFileType);
	hr = HRESULT_FROM_WIN32(RegDeleteTree(HKEY_CLASSES_ROOT, szSubkey));
	if (FAILED(hr))
		LogString(L"RegDeleteTree failed!");

	return hr;
}
////////////////////////////////////////////////////////////



HINSTANCE   g_hInst = NULL;
long        g_cDllRef = 0;

EXTERN_C __declspec(dllexport) HRESULT DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Hold the instance of this DLL module, we will use it to get the 
		// path of the DLL to register the component.
		g_hInst = hModule;
		DisableThreadLibraryCalls(hModule);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
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
/*EXTERN_C __declspec(dllexport) HRESULT DllGetClassObject(REFCLSID rclsid, REFIID riid, void** ppv)
{
// 	HRESULT hr = CLASS_E_CLASSNOTAVAILABLE;
// 
// 	if (IsEqualCLSID(CLSID_STLThumbnailProvider, rclsid))
// 	{
// 		hr = E_OUTOFMEMORY;
// 
// 		ClassFactory* pClassFactory = new ClassFactory();
// 		if (pClassFactory)
// 		{
// 			hr = pClassFactory->QueryInterface(riid, ppv);
// 			pClassFactory->Release();
// 		}
// 	}
// 
// 	return hr;
	return S_OK;
}*/


//
//   FUNCTION: DllCanUnloadNow
//
//   PURPOSE: Check if we can unload the component from the memory.
//
//   NOTE: The component can be unloaded from the memory when its reference 
//   count is zero (i.e. nobody is still using the component).
//
/*
EXTERN_C __declspec(dllexport) HRESULT DllCanUnloadNow(void)
{
	return g_cDllRef > 0 ? S_FALSE : S_OK;
}*/


//
//   FUNCTION: DllRegisterServer
//
//   PURPOSE: Register the COM server and the thumbnail handler.
//
EXTERN_C __declspec(dllexport) HRESULT DllRegisterServer(void)
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
		CLSID_STLThumbnailProvider,
 		L"ShellExtentionsEafilesserver Class",
 		L"Apartment");
 	if (SUCCEEDED(hr))
 	{
 		// Register the thumbnail handler. The thumbnail handler is associated
 		// with the .stl file class.
 		hr = RegisterShellExtThumbnailHandler(L".stl",
 			CLSID_STLThumbnailProvider);
 		if (SUCCEEDED(hr))
 		{
 			// This tells the shell to invalidate the thumbnail cache. It is 
 			// important because any .stl files viewed before registering 
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
 
	LogString(L"End");

	return hr;
}


//
//   FUNCTION: DllUnregisterServer
//
//   PURPOSE: Unregister the COM server and the thumbnail handler.
//
EXTERN_C __declspec(dllexport) HRESULT DllUnregisterServer(void)
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
	hr = UnregisterInprocServer(CLSID_STLThumbnailProvider);
	if (SUCCEEDED(hr))
	{
	 	// Unregister the thumbnail handler.
	 	hr = UnregisterShellExtThumbnailHandler(L".stl");
		if (FAILED(hr))
			LogString(L"UnregisterShellExtThumbnailHandler failed!");
	}
	else
	{
		LogString(L"UnregisterInprocServer failed!");
	}

	LogString(L"End");

	return hr;
}

//
//   FUNCTION: DllNofifyShell
//
//   PURPOSE: Notify the Windows Shell that file associations have changed.
//   This causes it to refresh the thumbnail cache.
//
EXTERN_C __declspec(dllexport) HRESULT DllNotifyShell(void)
{
	// This tells the shell to invalidate the thumbnail cache. It is 
	// important because any .stl files viewed before registering 
	// this handler would otherwise show cached blank thumbnails.
	SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST, NULL, NULL);

	return S_OK;
}
