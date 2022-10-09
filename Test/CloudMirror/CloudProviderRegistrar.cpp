// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

//#include "stdafx.h"

//===============================================================
// CloudProviderRegistrar
//
//   This class registers the provider with the Shell so that 
//   the syncroot shows up.
//
// Fakery Factor:
//
//   You should be able to replace the strings with your real values
//   and then use this class as-is.
//
//===============================================================

#define STORAGE_PROVIDER_ID L"TestStorageProvider"
#define STORAGE_PROVIDER_ACCOUNT L"TestAccount1"

#include "CloudProviderRegistrar.h"
#include "ProviderFolderLocations.h"
#include "Utilities.h"

#include <winrt\Windows.Foundation.h>
#include <winrt\windows.foundation.collections.h>
#include <winrt\windows.storage.provider.h>
#include <winrt\Windows.Security.Cryptography.h>


namespace winrt {
	using namespace Windows::Foundation;
	using namespace Windows::Storage;
	using namespace Windows::Storage::Streams;
	using namespace Windows::Storage::Provider;
	using namespace Windows::Foundation::Collections;
	using namespace Windows::Security::Cryptography;
}


void CloudProviderRegistrar::RegisterWithShell()
{
    try
    {
        auto syncRootID = GetSyncRootId();

        winrt::StorageProviderSyncRootInfo info;
        info.Id(syncRootID);

        auto folder = winrt::StorageFolder::GetFolderFromPathAsync(ProviderFolderLocations::GetClientFolder()).get();
        info.Path(folder);

        // The string can be in any form acceptable to SHLoadIndirectString.
        info.DisplayNameResource(L"UmangCloudMirror");

        // This icon is just for the sample. You should provide your own branded icon here
        info.IconResource(L"%SystemRoot%\\system32\\charmap.exe,0");
        info.HydrationPolicy(winrt::StorageProviderHydrationPolicy::Partial);
        //info.HydrationPolicyModifier(winrt::StorageProviderHydrationPolicyModifier::None);
        info.HydrationPolicyModifier(winrt::StorageProviderHydrationPolicyModifier::AutoDehydrationAllowed);
        info.PopulationPolicy(winrt::StorageProviderPopulationPolicy::AlwaysFull);
        //info.InSyncPolicy(winrt::StorageProviderInSyncPolicy::FileCreationTime | winrt::StorageProviderInSyncPolicy::DirectoryCreationTime);
        info.InSyncPolicy(winrt::StorageProviderInSyncPolicy::Default);
        info.Version(L"1.0.0");
        info.ShowSiblingsAsGroup(false);
        info.HardlinkPolicy(winrt::StorageProviderHardlinkPolicy::None);

        winrt::Uri uri(L"http://cloudmirror.example.com/recyclebin");
        info.RecycleBinUri(uri);

        // Context
        std::wstring syncRootIdentity(ProviderFolderLocations::GetServerFolder());
        syncRootIdentity.append(L"->");
        syncRootIdentity.append(ProviderFolderLocations::GetClientFolder());

        wchar_t const contextString[] = L"TestProviderContextString";
        winrt::IBuffer contextBuffer = winrt::CryptographicBuffer::ConvertStringToBinary(syncRootIdentity.data(), winrt::BinaryStringEncoding::Utf8);
        info.Context(contextBuffer);

//         winrt::IVector<winrt::StorageProviderItemPropertyDefinition> customStates = info.StorageProviderItemPropertyDefinitions();
//         AddCustomState(customStates, L"CustomStateName1", 1);
//         AddCustomState(customStates, L"CustomStateName2", 2);
//         AddCustomState(customStates, L"CustomStateName3", 3);

        winrt::StorageProviderSyncRootManager::Register(info);

        // Give the cache some time to invalidate
        Sleep(1000);
    }
    catch (...)
    {
        // winrt::to_hresult() will eat the exception if it is a result of winrt::check_hresult,
        // otherwise the exception will get rethrown and this method will crash out as it should
        wprintf(L"Could not register the sync root, hr %08x\n", static_cast<HRESULT>(winrt::to_hresult()));
    }

	/*GUID kProviderID =
	{ 0x4f1c90c8, 0xa314, 0x41a3, { 0xa4, 0xab, 0x98, 0x80, 0x69, 0xf5, 0xa4, 0x6e } };

    // sync registration details
    // [TODO] fix the empty values
    CF_SYNC_REGISTRATION registrationDetails{
        sizeof(CF_SYNC_REGISTRATION),	// size of the structure
        L"eafilesserver",				// ProviderName
        L"1.0.0",						// ProviderVersion
        nullptr,						// SyncRootIdentity
        0,								// SyncRootIdentityLength
        nullptr,						// FileIdentity
        0,								// FileIdentityLength
        kProviderID						// ProviderId;			
    };

//     // create sync policies
//     CF_HYDRATION_POLICY hydrationPolicy = {
//         CF_HYDRATION_POLICY_FULL, /* user IO request is completed as soon as sufficient data is received from the sync provider */
//         CF_HYDRATION_POLICY_MODIFIER_AUTO_DEHYDRATION_ALLOWED /* This policy modifier grants the platform the permission
//                                                                 to dehydrate in-sync cloud file placeholders without the help of sync providers.*/
//     };
// 
//     CF_POPULATION_POLICY populationPolicy = {
//         CF_POPULATION_POLICY_ALWAYS_FULL, /* When CF_POPULATION_POLICY_ALWAYS_FULL is selected, the platform assumes that the full name space is always available locally.
//                                           It will never forward any directory enumeration request to the sync provider.*/
//         CF_POPULATION_POLICY_MODIFIER_NONE
//     };
// 
//     CF_SYNC_POLICIES syncPolicies{
//         sizeof(CF_SYNC_POLICIES),
//         hydrationPolicy,
//         populationPolicy,
//         CF_INSYNC_POLICY_NONE,
//         CF_HARDLINK_POLICY_NONE
//     };
// 
//     // Perform one time sync root registration.
//     HRESULT hr = CfRegisterSyncRoot(
//         ProviderFolderLocations::GetClientFolder(),
//         &registrationDetails,
//         &syncPolicies,
//         CF_REGISTER_FLAG_NONE);


}

//  A real sync engine should NOT unregister the sync root upon exit.
//  This is just to demonstrate the use of StorageProviderSyncRootManager::Unregister.
void CloudProviderRegistrar::Unregister()
{
    try
    {
        winrt::StorageProviderSyncRootManager::Unregister(GetSyncRootId());
    }
    catch (...)
    {
        // winrt::to_hresult() will eat the exception if it is a result of winrt::check_hresult,
        // otherwise the exception will get rethrown and this method will crash out as it should
        wprintf(L"Could not unregister the sync root, hr %08x\n", static_cast<HRESULT>(winrt::to_hresult()));
    }
}

std::unique_ptr<TOKEN_USER> CloudProviderRegistrar::GetTokenInformation()
{
    std::unique_ptr<TOKEN_USER> tokenInfo;

    // get the tokenHandle from current thread/process if it's null
    auto tokenHandle{ GetCurrentThreadEffectiveToken() }; // Pseudo token, don't free.

    DWORD tokenInfoSize{ 0 };
    if (!::GetTokenInformation(tokenHandle, TokenUser, nullptr, 0, &tokenInfoSize))
    {
        if (::GetLastError() == ERROR_INSUFFICIENT_BUFFER)
        {
            tokenInfo.reset(reinterpret_cast<TOKEN_USER*>(new char[tokenInfoSize]));
            if (!::GetTokenInformation(tokenHandle, TokenUser, tokenInfo.get(), tokenInfoSize, &tokenInfoSize))
            {
                throw std::exception("GetTokenInformation failed");
            }
        }
        else
        {
            throw std::exception("GetTokenInformation failed");
        }
    }
    return tokenInfo;
}

std::wstring CloudProviderRegistrar::GetSyncRootId()
{
    std::unique_ptr<TOKEN_USER> tokenInfo(GetTokenInformation());
    auto sidString = Utilities::ConvertSidToStringSid(tokenInfo->User.Sid);
    std::wstring syncRootID(STORAGE_PROVIDER_ID);
    syncRootID.append(L"!");
    syncRootID.append(sidString.data());
    syncRootID.append(L"!");
    syncRootID.append(STORAGE_PROVIDER_ACCOUNT);

    return syncRootID;
}

