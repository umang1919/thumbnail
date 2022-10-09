// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.220110.5

#pragma once
#ifndef WINRT_Windows_ApplicationModel_Store_Preview_0_H
#define WINRT_Windows_ApplicationModel_Store_Preview_0_H
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
}
WINRT_EXPORT namespace winrt::Windows::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
WINRT_EXPORT namespace winrt::Windows::Security::Authentication::Web::Core
{
    struct WebTokenRequest;
    struct WebTokenRequestResult;
}
WINRT_EXPORT namespace winrt::Windows::Security::Credentials
{
    struct WebAccount;
}
WINRT_EXPORT namespace winrt::Windows::Storage::Streams
{
    struct IRandomAccessStreamReference;
}
WINRT_EXPORT namespace winrt::Windows::System
{
    struct User;
}
WINRT_EXPORT namespace winrt::Windows::UI::Xaml
{
    struct UIElement;
}
WINRT_EXPORT namespace winrt::Windows::ApplicationModel::Store::Preview
{
    enum class DeliveryOptimizationDownloadMode : int32_t
    {
        Simple = 0,
        HttpOnly = 1,
        Lan = 2,
        Group = 3,
        Internet = 4,
        Bypass = 5,
    };
    enum class DeliveryOptimizationDownloadModeSource : int32_t
    {
        Default = 0,
        Policy = 1,
    };
    enum class StoreLogOptions : uint32_t
    {
        None = 0,
        TryElevate = 0x1,
    };
    enum class StorePreviewProductPurchaseStatus : int32_t
    {
        Succeeded = 0,
        AlreadyPurchased = 1,
        NotFulfilled = 2,
        NotPurchased = 3,
    };
    enum class StoreSystemFeature : int32_t
    {
        ArchitectureX86 = 0,
        ArchitectureX64 = 1,
        ArchitectureArm = 2,
        DirectX9 = 3,
        DirectX10 = 4,
        DirectX11 = 5,
        D3D12HardwareFL11 = 6,
        D3D12HardwareFL12 = 7,
        Memory300MB = 8,
        Memory750MB = 9,
        Memory1GB = 10,
        Memory2GB = 11,
        CameraFront = 12,
        CameraRear = 13,
        Gyroscope = 14,
        Hover = 15,
        Magnetometer = 16,
        Nfc = 17,
        Resolution720P = 18,
        ResolutionWvga = 19,
        ResolutionWvgaOr720P = 20,
        ResolutionWxga = 21,
        ResolutionWvgaOrWxga = 22,
        ResolutionWxgaOr720P = 23,
        Memory4GB = 24,
        Memory6GB = 25,
        Memory8GB = 26,
        Memory12GB = 27,
        Memory16GB = 28,
        Memory20GB = 29,
        VideoMemory2GB = 30,
        VideoMemory4GB = 31,
        VideoMemory6GB = 32,
        VideoMemory1GB = 33,
        ArchitectureArm64 = 34,
    };
    struct IDeliveryOptimizationSettings;
    struct IDeliveryOptimizationSettingsStatics;
    struct IStoreConfigurationStatics;
    struct IStoreConfigurationStatics2;
    struct IStoreConfigurationStatics3;
    struct IStoreConfigurationStatics4;
    struct IStoreConfigurationStatics5;
    struct IStoreHardwareManufacturerInfo;
    struct IStorePreview;
    struct IStorePreviewProductInfo;
    struct IStorePreviewPurchaseResults;
    struct IStorePreviewSkuInfo;
    struct IWebAuthenticationCoreManagerHelper;
    struct DeliveryOptimizationSettings;
    struct StoreConfiguration;
    struct StoreHardwareManufacturerInfo;
    struct StorePreview;
    struct StorePreviewProductInfo;
    struct StorePreviewPurchaseResults;
    struct StorePreviewSkuInfo;
    struct WebAuthenticationCoreManagerHelper;
}
namespace winrt::impl
{
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IDeliveryOptimizationSettings>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IDeliveryOptimizationSettingsStatics>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics2>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics3>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics4>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics5>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IStorePreview>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::IWebAuthenticationCoreManagerHelper>{ using type = interface_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::DeliveryOptimizationSettings>{ using type = class_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::StoreConfiguration>{ using type = class_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::StoreHardwareManufacturerInfo>{ using type = class_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::StorePreview>{ using type = class_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo>{ using type = class_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewPurchaseResults>{ using type = class_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewSkuInfo>{ using type = class_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::WebAuthenticationCoreManagerHelper>{ using type = class_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::DeliveryOptimizationDownloadMode>{ using type = enum_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::DeliveryOptimizationDownloadModeSource>{ using type = enum_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::StoreLogOptions>{ using type = enum_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewProductPurchaseStatus>{ using type = enum_category; };
    template <> struct category<winrt::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::DeliveryOptimizationSettings> = L"Windows.ApplicationModel.Store.Preview.DeliveryOptimizationSettings";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::StoreConfiguration> = L"Windows.ApplicationModel.Store.Preview.StoreConfiguration";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::StoreHardwareManufacturerInfo> = L"Windows.ApplicationModel.Store.Preview.StoreHardwareManufacturerInfo";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::StorePreview> = L"Windows.ApplicationModel.Store.Preview.StorePreview";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo> = L"Windows.ApplicationModel.Store.Preview.StorePreviewProductInfo";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewPurchaseResults> = L"Windows.ApplicationModel.Store.Preview.StorePreviewPurchaseResults";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewSkuInfo> = L"Windows.ApplicationModel.Store.Preview.StorePreviewSkuInfo";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::WebAuthenticationCoreManagerHelper> = L"Windows.ApplicationModel.Store.Preview.WebAuthenticationCoreManagerHelper";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::DeliveryOptimizationDownloadMode> = L"Windows.ApplicationModel.Store.Preview.DeliveryOptimizationDownloadMode";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::DeliveryOptimizationDownloadModeSource> = L"Windows.ApplicationModel.Store.Preview.DeliveryOptimizationDownloadModeSource";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::StoreLogOptions> = L"Windows.ApplicationModel.Store.Preview.StoreLogOptions";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewProductPurchaseStatus> = L"Windows.ApplicationModel.Store.Preview.StorePreviewProductPurchaseStatus";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::StoreSystemFeature> = L"Windows.ApplicationModel.Store.Preview.StoreSystemFeature";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IDeliveryOptimizationSettings> = L"Windows.ApplicationModel.Store.Preview.IDeliveryOptimizationSettings";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IDeliveryOptimizationSettingsStatics> = L"Windows.ApplicationModel.Store.Preview.IDeliveryOptimizationSettingsStatics";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics> = L"Windows.ApplicationModel.Store.Preview.IStoreConfigurationStatics";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics2> = L"Windows.ApplicationModel.Store.Preview.IStoreConfigurationStatics2";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics3> = L"Windows.ApplicationModel.Store.Preview.IStoreConfigurationStatics3";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics4> = L"Windows.ApplicationModel.Store.Preview.IStoreConfigurationStatics4";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics5> = L"Windows.ApplicationModel.Store.Preview.IStoreConfigurationStatics5";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo> = L"Windows.ApplicationModel.Store.Preview.IStoreHardwareManufacturerInfo";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IStorePreview> = L"Windows.ApplicationModel.Store.Preview.IStorePreview";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo> = L"Windows.ApplicationModel.Store.Preview.IStorePreviewProductInfo";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults> = L"Windows.ApplicationModel.Store.Preview.IStorePreviewPurchaseResults";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo> = L"Windows.ApplicationModel.Store.Preview.IStorePreviewSkuInfo";
    template <> inline constexpr auto& name_v<winrt::Windows::ApplicationModel::Store::Preview::IWebAuthenticationCoreManagerHelper> = L"Windows.ApplicationModel.Store.Preview.IWebAuthenticationCoreManagerHelper";
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IDeliveryOptimizationSettings>{ 0x1810FDA0,0xE853,0x565E,{ 0xB8,0x74,0x7A,0x8A,0x7B,0x9A,0x0E,0x0F } }; // 1810FDA0-E853-565E-B874-7A8A7B9A0E0F
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IDeliveryOptimizationSettingsStatics>{ 0x5C817CAF,0xAED5,0x5999,{ 0xB4,0xC9,0x8C,0x60,0x89,0x8B,0xC4,0xF3 } }; // 5C817CAF-AED5-5999-B4C9-8C60898BC4F3
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics>{ 0x728F7FC0,0x8628,0x42EC,{ 0x84,0xA2,0x07,0x78,0x0E,0xB4,0x4D,0x8B } }; // 728F7FC0-8628-42EC-84A2-07780EB44D8B
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics2>{ 0x657C4595,0xC8B7,0x4FE9,{ 0x9F,0x4C,0x4D,0x71,0x02,0x7D,0x34,0x7E } }; // 657C4595-C8B7-4FE9-9F4C-4D71027D347E
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics3>{ 0x6D45F57C,0xF144,0x4CB5,{ 0x9D,0x3F,0x4E,0xB0,0x5E,0x30,0xB6,0xD3 } }; // 6D45F57C-F144-4CB5-9D3F-4EB05E30B6D3
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics4>{ 0x20FF56D2,0x4EE3,0x4CF0,{ 0x9B,0x12,0x55,0x2C,0x03,0x31,0x0F,0x75 } }; // 20FF56D2-4EE3-4CF0-9B12-552C03310F75
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics5>{ 0xF7613191,0x8FA9,0x49DB,{ 0x82,0x2B,0x01,0x60,0xE7,0xE4,0xE5,0xC5 } }; // F7613191-8FA9-49DB-822B-0160E7E4E5C5
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo>{ 0xF292DC08,0xC654,0x43AC,{ 0xA2,0x1F,0x34,0x80,0x1C,0x9D,0x33,0x88 } }; // F292DC08-C654-43AC-A21F-34801C9D3388
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IStorePreview>{ 0x8A157241,0x840E,0x49A9,{ 0xBC,0x01,0x5D,0x5B,0x01,0xFB,0xC8,0xE9 } }; // 8A157241-840E-49A9-BC01-5D5B01FBC8E9
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo>{ 0x1937DBB3,0x6C01,0x4C9D,{ 0x85,0xCD,0x5B,0xAB,0xAA,0xC2,0xB3,0x51 } }; // 1937DBB3-6C01-4C9D-85CD-5BABAAC2B351
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults>{ 0xB0DAAED1,0xD6C5,0x4E53,{ 0xA0,0x43,0xFB,0xA0,0xD8,0xE6,0x12,0x31 } }; // B0DAAED1-D6C5-4E53-A043-FBA0D8E61231
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>{ 0x81FD76E2,0x0B26,0x48D9,{ 0x98,0xCE,0x27,0x46,0x1C,0x66,0x9D,0x6C } }; // 81FD76E2-0B26-48D9-98CE-27461C669D6C
    template <> inline constexpr guid guid_v<winrt::Windows::ApplicationModel::Store::Preview::IWebAuthenticationCoreManagerHelper>{ 0x06A50525,0xE715,0x4123,{ 0x92,0x76,0x9D,0x6F,0x86,0x5B,0xA5,0x5F } }; // 06A50525-E715-4123-9276-9D6F865BA55F
    template <> struct default_interface<winrt::Windows::ApplicationModel::Store::Preview::DeliveryOptimizationSettings>{ using type = winrt::Windows::ApplicationModel::Store::Preview::IDeliveryOptimizationSettings; };
    template <> struct default_interface<winrt::Windows::ApplicationModel::Store::Preview::StoreHardwareManufacturerInfo>{ using type = winrt::Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo; };
    template <> struct default_interface<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo>{ using type = winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo; };
    template <> struct default_interface<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewPurchaseResults>{ using type = winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults; };
    template <> struct default_interface<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewSkuInfo>{ using type = winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo; };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IDeliveryOptimizationSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DownloadMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DownloadModeSource(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IDeliveryOptimizationSettingsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetCurrentSettings(void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetSystemConfiguration(void*, void*, int64_t, void*) noexcept = 0;
            virtual int32_t __stdcall SetMobileOperatorConfiguration(void*, uint32_t, uint32_t) noexcept = 0;
            virtual int32_t __stdcall SetStoreWebAccountId(void*) noexcept = 0;
            virtual int32_t __stdcall IsStoreWebAccountId(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall get_HardwareManufacturerInfo(void**) noexcept = 0;
            virtual int32_t __stdcall FilterUnsupportedSystemFeaturesAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PurchasePromptingPolicy(void**) noexcept = 0;
            virtual int32_t __stdcall put_PurchasePromptingPolicy(void*) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall HasStoreWebAccount(bool*) noexcept = 0;
            virtual int32_t __stdcall HasStoreWebAccountForUser(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall GetStoreLogDataAsync(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall SetStoreWebAccountIdForUser(void*, void*) noexcept = 0;
            virtual int32_t __stdcall IsStoreWebAccountIdForUser(void*, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall GetPurchasePromptingPolicyForUser(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetPurchasePromptingPolicyForUser(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetStoreWebAccountId(void**) noexcept = 0;
            virtual int32_t __stdcall GetStoreWebAccountIdForUser(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetEnterpriseStoreWebAccountId(void*) noexcept = 0;
            virtual int32_t __stdcall SetEnterpriseStoreWebAccountIdForUser(void*, void*) noexcept = 0;
            virtual int32_t __stdcall GetEnterpriseStoreWebAccountId(void**) noexcept = 0;
            virtual int32_t __stdcall GetEnterpriseStoreWebAccountIdForUser(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ShouldRestrictToEnterpriseStoreOnly(bool*) noexcept = 0;
            virtual int32_t __stdcall ShouldRestrictToEnterpriseStoreOnlyForUser(void*, bool*) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics5>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsPinToDesktopSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall IsPinToTaskbarSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall IsPinToStartSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall PinToDesktop(void*) noexcept = 0;
            virtual int32_t __stdcall PinToDesktopForUser(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_HardwareManufacturerId(void**) noexcept = 0;
            virtual int32_t __stdcall get_StoreContentModifierId(void**) noexcept = 0;
            virtual int32_t __stdcall get_ModelName(void**) noexcept = 0;
            virtual int32_t __stdcall get_ManufacturerName(void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IStorePreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestProductPurchaseByProductIdAndSkuIdAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall LoadAddOnProductInfosAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ProductId(void**) noexcept = 0;
            virtual int32_t __stdcall get_ProductType(void**) noexcept = 0;
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall get_SkuInfoList(void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ProductPurchaseStatus(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ProductId(void**) noexcept = 0;
            virtual int32_t __stdcall get_SkuId(void**) noexcept = 0;
            virtual int32_t __stdcall get_SkuType(void**) noexcept = 0;
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall get_CustomDeveloperData(void**) noexcept = 0;
            virtual int32_t __stdcall get_CurrencyCode(void**) noexcept = 0;
            virtual int32_t __stdcall get_FormattedListPrice(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedData(void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::ApplicationModel::Store::Preview::IWebAuthenticationCoreManagerHelper>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestTokenWithUIElementHostingAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestTokenWithUIElementHostingAndWebAccountAsync(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IDeliveryOptimizationSettings
    {
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::ApplicationModel::Store::Preview::DeliveryOptimizationDownloadMode) DownloadMode() const;
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::ApplicationModel::Store::Preview::DeliveryOptimizationDownloadModeSource) DownloadModeSource() const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IDeliveryOptimizationSettings>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IDeliveryOptimizationSettings<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IDeliveryOptimizationSettingsStatics
    {
        WINRT_IMPL_AUTO(winrt::Windows::ApplicationModel::Store::Preview::DeliveryOptimizationSettings) GetCurrentSettings() const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IDeliveryOptimizationSettingsStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IDeliveryOptimizationSettingsStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IStoreConfigurationStatics
    {
        WINRT_IMPL_AUTO(void) SetSystemConfiguration(param::hstring const& catalogHardwareManufacturerId, param::hstring const& catalogStoreContentModifierId, winrt::Windows::Foundation::DateTime const& systemConfigurationExpiration, param::hstring const& catalogHardwareDescriptor) const;
        WINRT_IMPL_AUTO(void) SetMobileOperatorConfiguration(param::hstring const& mobileOperatorId, uint32_t appDownloadLimitInMegabytes, uint32_t updateDownloadLimitInMegabytes) const;
        WINRT_IMPL_AUTO(void) SetStoreWebAccountId(param::hstring const& webAccountId) const;
        WINRT_IMPL_AUTO(bool) IsStoreWebAccountId(param::hstring const& webAccountId) const;
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::ApplicationModel::Store::Preview::StoreHardwareManufacturerInfo) HardwareManufacturerInfo() const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>>) FilterUnsupportedSystemFeaturesAsync(param::async_iterable<winrt::Windows::ApplicationModel::Store::Preview::StoreSystemFeature> const& systemFeatures) const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IStoreConfigurationStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IStoreConfigurationStatics2
    {
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::Foundation::IReference<uint32_t>) PurchasePromptingPolicy() const;
        WINRT_IMPL_AUTO(void) PurchasePromptingPolicy(winrt::Windows::Foundation::IReference<uint32_t> const& value) const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IStoreConfigurationStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IStoreConfigurationStatics3
    {
        WINRT_IMPL_AUTO(bool) HasStoreWebAccount() const;
        WINRT_IMPL_AUTO(bool) HasStoreWebAccountForUser(winrt::Windows::System::User const& user) const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::Streams::IRandomAccessStreamReference>) GetStoreLogDataAsync(winrt::Windows::ApplicationModel::Store::Preview::StoreLogOptions const& options) const;
        WINRT_IMPL_AUTO(void) SetStoreWebAccountIdForUser(winrt::Windows::System::User const& user, param::hstring const& webAccountId) const;
        WINRT_IMPL_AUTO(bool) IsStoreWebAccountIdForUser(winrt::Windows::System::User const& user, param::hstring const& webAccountId) const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IReference<uint32_t>) GetPurchasePromptingPolicyForUser(winrt::Windows::System::User const& user) const;
        WINRT_IMPL_AUTO(void) SetPurchasePromptingPolicyForUser(winrt::Windows::System::User const& user, winrt::Windows::Foundation::IReference<uint32_t> const& value) const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IStoreConfigurationStatics3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IStoreConfigurationStatics4
    {
        WINRT_IMPL_AUTO(hstring) GetStoreWebAccountId() const;
        WINRT_IMPL_AUTO(hstring) GetStoreWebAccountIdForUser(winrt::Windows::System::User const& user) const;
        WINRT_IMPL_AUTO(void) SetEnterpriseStoreWebAccountId(param::hstring const& webAccountId) const;
        WINRT_IMPL_AUTO(void) SetEnterpriseStoreWebAccountIdForUser(winrt::Windows::System::User const& user, param::hstring const& webAccountId) const;
        WINRT_IMPL_AUTO(hstring) GetEnterpriseStoreWebAccountId() const;
        WINRT_IMPL_AUTO(hstring) GetEnterpriseStoreWebAccountIdForUser(winrt::Windows::System::User const& user) const;
        WINRT_IMPL_AUTO(bool) ShouldRestrictToEnterpriseStoreOnly() const;
        WINRT_IMPL_AUTO(bool) ShouldRestrictToEnterpriseStoreOnlyForUser(winrt::Windows::System::User const& user) const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics4>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IStoreConfigurationStatics4<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IStoreConfigurationStatics5
    {
        WINRT_IMPL_AUTO(bool) IsPinToDesktopSupported() const;
        WINRT_IMPL_AUTO(bool) IsPinToTaskbarSupported() const;
        WINRT_IMPL_AUTO(bool) IsPinToStartSupported() const;
        WINRT_IMPL_AUTO(void) PinToDesktop(param::hstring const& appPackageFamilyName) const;
        WINRT_IMPL_AUTO(void) PinToDesktopForUser(winrt::Windows::System::User const& user, param::hstring const& appPackageFamilyName) const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics5>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IStoreConfigurationStatics5<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IStoreHardwareManufacturerInfo
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) HardwareManufacturerId() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) StoreContentModifierId() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) ModelName() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) ManufacturerName() const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IStoreHardwareManufacturerInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IStorePreview
    {
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewPurchaseResults>) RequestProductPurchaseByProductIdAndSkuIdAsync(param::hstring const& productId, param::hstring const& skuId) const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo>>) LoadAddOnProductInfosAsync() const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IStorePreview>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IStorePreview<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IStorePreviewProductInfo
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) ProductId() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) ProductType() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Title() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Description() const;
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Store::Preview::StorePreviewSkuInfo>) SkuInfoList() const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IStorePreviewProductInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IStorePreviewPurchaseResults
    {
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::ApplicationModel::Store::Preview::StorePreviewProductPurchaseStatus) ProductPurchaseStatus() const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IStorePreviewPurchaseResults<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IStorePreviewSkuInfo
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) ProductId() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) SkuId() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) SkuType() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Title() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Description() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) CustomDeveloperData() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) CurrencyCode() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) FormattedListPrice() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) ExtendedData() const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IStorePreviewSkuInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Store_Preview_IWebAuthenticationCoreManagerHelper
    {
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Web::Core::WebTokenRequestResult>) RequestTokenWithUIElementHostingAsync(winrt::Windows::Security::Authentication::Web::Core::WebTokenRequest const& request, winrt::Windows::UI::Xaml::UIElement const& uiElement) const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Web::Core::WebTokenRequestResult>) RequestTokenWithUIElementHostingAsync(winrt::Windows::Security::Authentication::Web::Core::WebTokenRequest const& request, winrt::Windows::Security::Credentials::WebAccount const& webAccount, winrt::Windows::UI::Xaml::UIElement const& uiElement) const;
    };
    template <> struct consume<winrt::Windows::ApplicationModel::Store::Preview::IWebAuthenticationCoreManagerHelper>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Store_Preview_IWebAuthenticationCoreManagerHelper<D>;
    };
}
#endif
