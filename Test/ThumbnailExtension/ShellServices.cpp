/*************************************************************************
* ADOBE CONFIDENTIAL
* ___________________
*
* Copyright 2022 Adobe
* All Rights Reserved.
*
* NOTICE: All information contained herein is, and remains
* the property of Adobe and its suppliers, if any. The intellectual
* and technical concepts contained herein are proprietary to Adobe
* and its suppliers and are protected by all applicable intellectual
* property laws, including trade secret and copyright laws.
* Dissemination of this information or reproduction of this material
* is strictly forbidden unless prior written permission is obtained
* from Adobe.
**************************************************************************/

//#include "stdafx.h"
#include <thread>
#include <combaseapi.h>

#include "ClassFactory.h"
#include "ShellServices.h"
#include "ThumbnailProvider.h"
// #include "ContextMenus.h"
// #include "CustomStateProvider.h"
// #include "UriSource.h"
// #include "MyStatusUISourceFactory.h"
// #include "MyStorageProviderUICommand.h"

//===============================================================
// ShellServices
//
//    Registers a bunchof COM objects that implement the various
//    whizbangs and gizmos that Shell needs for things like
//    thumbnails, context menus, and custom states.
//
// Fakery Factor:
//
//    Not a lot here. The classes referenced are all fakes,
//    but you could prolly modify them with ease.
//
//===============================================================

namespace ShellExtentions
{
	ClassFactory gClassFactory;

	template <typename T>
	HRESULT RegisterClass()
	{
		DWORD cookie = 0;
		HRESULT result = CoRegisterClassObject(__uuidof(T), &gClassFactory, CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE, &cookie);
		return result;
	}

	void Initialize()
	{
		RegisterClass<ThumbnailProvider>();
	}

	SHELLEXTENTIONS_EXPORT
	void ShellServices::InitAndStartServiceTask()
	{
		auto task = std::thread([]()
			{
				CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

				RegisterClass<ThumbnailProvider>();

				DWORD index;
				HANDLE dummyEvent(CreateEvent(nullptr, FALSE, FALSE, nullptr));
				auto res = CoWaitForMultipleHandles(COWAIT_DISPATCH_CALLS, INFINITE, 1, &dummyEvent, &index);

				if (!res)
				{

				}

				int a = 5;
				a++;
				CoUninitialize();
			});
		task.detach();
	}
}
