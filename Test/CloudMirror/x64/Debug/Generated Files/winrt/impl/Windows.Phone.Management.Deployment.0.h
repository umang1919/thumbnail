// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.220110.5

#pragma once
#ifndef WINRT_Windows_Phone_Management_Deployment_0_H
#define WINRT_Windows_Phone_Management_Deployment_0_H
WINRT_EXPORT namespace winrt::Windows::ApplicationModel
{
    struct Package;
}
WINRT_EXPORT namespace winrt::Windows::Foundation
{
    struct IAsyncAction;
    template <typename TResult, typename TProgress> struct __declspec(empty_bases) IAsyncOperationWithProgress;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct Uri;
}
WINRT_EXPORT namespace winrt::Windows::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
WINRT_EXPORT namespace winrt::Windows::Management::Deployment
{
    enum class DeploymentOptions : uint32_t;
    enum class PackageInstallState : int32_t;
    enum class RemovalOptions : uint32_t;
}
WINRT_EXPORT namespace winrt::Windows::Phone::Management::Deployment
{
    enum class EnterpriseEnrollmentStatus : int32_t
    {
        Success = 0,
        CancelledByUser = 1,
        UnknownFailure = 2,
    };
    enum class EnterpriseStatus : int32_t
    {
        Enrolled = 0,
        Disabled = 1,
        Revoked = 2,
        Expired = 3,
    };
    struct IEnterprise;
    struct IEnterpriseEnrollmentManager;
    struct IEnterpriseEnrollmentResult;
    struct IInstallationManagerStatics;
    struct IInstallationManagerStatics2;
    struct IPackageInstallResult;
    struct IPackageInstallResult2;
    struct Enterprise;
    struct EnterpriseEnrollmentManager;
    struct EnterpriseEnrollmentResult;
    struct InstallationManager;
    struct PackageInstallResult;
}
namespace winrt::impl
{
    template <> struct category<winrt::Windows::Phone::Management::Deployment::IEnterprise>{ using type = interface_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentManager>{ using type = interface_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult>{ using type = interface_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::IInstallationManagerStatics>{ using type = interface_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::IInstallationManagerStatics2>{ using type = interface_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::IPackageInstallResult>{ using type = interface_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::IPackageInstallResult2>{ using type = interface_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::Enterprise>{ using type = class_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::EnterpriseEnrollmentManager>{ using type = class_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult>{ using type = class_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::InstallationManager>{ using type = class_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::PackageInstallResult>{ using type = class_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::EnterpriseEnrollmentStatus>{ using type = enum_category; };
    template <> struct category<winrt::Windows::Phone::Management::Deployment::EnterpriseStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::Enterprise> = L"Windows.Phone.Management.Deployment.Enterprise";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::EnterpriseEnrollmentManager> = L"Windows.Phone.Management.Deployment.EnterpriseEnrollmentManager";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult> = L"Windows.Phone.Management.Deployment.EnterpriseEnrollmentResult";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::InstallationManager> = L"Windows.Phone.Management.Deployment.InstallationManager";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::PackageInstallResult> = L"Windows.Phone.Management.Deployment.PackageInstallResult";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::EnterpriseEnrollmentStatus> = L"Windows.Phone.Management.Deployment.EnterpriseEnrollmentStatus";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::EnterpriseStatus> = L"Windows.Phone.Management.Deployment.EnterpriseStatus";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::IEnterprise> = L"Windows.Phone.Management.Deployment.IEnterprise";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentManager> = L"Windows.Phone.Management.Deployment.IEnterpriseEnrollmentManager";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult> = L"Windows.Phone.Management.Deployment.IEnterpriseEnrollmentResult";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::IInstallationManagerStatics> = L"Windows.Phone.Management.Deployment.IInstallationManagerStatics";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::IInstallationManagerStatics2> = L"Windows.Phone.Management.Deployment.IInstallationManagerStatics2";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::IPackageInstallResult> = L"Windows.Phone.Management.Deployment.IPackageInstallResult";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Management::Deployment::IPackageInstallResult2> = L"Windows.Phone.Management.Deployment.IPackageInstallResult2";
    template <> inline constexpr guid guid_v<winrt::Windows::Phone::Management::Deployment::IEnterprise>{ 0x96592F8D,0x856C,0x4426,{ 0xA9,0x47,0xB0,0x63,0x07,0x71,0x80,0x78 } }; // 96592F8D-856C-4426-A947-B06307718078
    template <> inline constexpr guid guid_v<winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentManager>{ 0x20F9F390,0x2C69,0x41D8,{ 0x88,0xE6,0xE4,0xB3,0x88,0x40,0x26,0xCB } }; // 20F9F390-2C69-41D8-88E6-E4B3884026CB
    template <> inline constexpr guid guid_v<winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult>{ 0x9FF71CE6,0x90DB,0x4342,{ 0xB3,0x26,0x17,0x29,0xAA,0x91,0x30,0x1C } }; // 9FF71CE6-90DB-4342-B326-1729AA91301C
    template <> inline constexpr guid guid_v<winrt::Windows::Phone::Management::Deployment::IInstallationManagerStatics>{ 0x929AA738,0x8D49,0x42AC,{ 0x80,0xC9,0xB4,0xAD,0x79,0x3C,0x43,0xF2 } }; // 929AA738-8D49-42AC-80C9-B4AD793C43F2
    template <> inline constexpr guid guid_v<winrt::Windows::Phone::Management::Deployment::IInstallationManagerStatics2>{ 0x7C6C2CBD,0xFA4A,0x4C8E,{ 0xAB,0x97,0xD9,0x59,0x45,0x2F,0x19,0xE5 } }; // 7C6C2CBD-FA4A-4C8E-AB97-D959452F19E5
    template <> inline constexpr guid guid_v<winrt::Windows::Phone::Management::Deployment::IPackageInstallResult>{ 0x33E8EED5,0x0F7E,0x4473,{ 0x96,0x7C,0x7D,0x6E,0x1C,0x0E,0x7D,0xE1 } }; // 33E8EED5-0F7E-4473-967C-7D6E1C0E7DE1
    template <> inline constexpr guid guid_v<winrt::Windows::Phone::Management::Deployment::IPackageInstallResult2>{ 0x7149D909,0x3FF9,0x41ED,{ 0xA7,0x17,0x2B,0xC6,0x5F,0xFC,0x61,0xD2 } }; // 7149D909-3FF9-41ED-A717-2BC65FFC61D2
    template <> struct default_interface<winrt::Windows::Phone::Management::Deployment::Enterprise>{ using type = winrt::Windows::Phone::Management::Deployment::IEnterprise; };
    template <> struct default_interface<winrt::Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult>{ using type = winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult; };
    template <> struct default_interface<winrt::Windows::Phone::Management::Deployment::PackageInstallResult>{ using type = winrt::Windows::Phone::Management::Deployment::IPackageInstallResult; };
    template <> struct abi<winrt::Windows::Phone::Management::Deployment::IEnterprise>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(winrt::guid*) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_WorkplaceId(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_EnrollmentValidFrom(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_EnrollmentValidTo(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EnrolledEnterprises(void**) noexcept = 0;
            virtual int32_t __stdcall get_CurrentEnterprise(void**) noexcept = 0;
            virtual int32_t __stdcall ValidateEnterprisesAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RequestEnrollmentAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestUnenrollmentAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EnrolledEnterprise(void**) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::Phone::Management::Deployment::IInstallationManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AddPackageAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall AddPackagePreloadedAsync(void*, void*, void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetPendingPackageInstalls(void**) noexcept = 0;
            virtual int32_t __stdcall FindPackagesForCurrentPublisher(void**) noexcept = 0;
            virtual int32_t __stdcall FindPackages(void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::Phone::Management::Deployment::IInstallationManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RemovePackageAsync(void*, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RegisterPackageAsync(void*, void*, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall FindPackagesByNamePublisher(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::Phone::Management::Deployment::IPackageInstallResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ProductId(void**) noexcept = 0;
            virtual int32_t __stdcall get_InstallState(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::Phone::Management::Deployment::IPackageInstallResult2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ErrorText(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Phone_Management_Deployment_IEnterprise
    {
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::guid) Id() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] WINRT_IMPL_AUTO(int32_t) WorkplaceId() const;
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::Foundation::DateTime) EnrollmentValidFrom() const;
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::Foundation::DateTime) EnrollmentValidTo() const;
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::Phone::Management::Deployment::EnterpriseStatus) Status() const;
    };
    template <> struct consume<winrt::Windows::Phone::Management::Deployment::IEnterprise>
    {
        template <typename D> using type = consume_Windows_Phone_Management_Deployment_IEnterprise<D>;
    };
    template <typename D>
    struct consume_Windows_Phone_Management_Deployment_IEnterpriseEnrollmentManager
    {
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Phone::Management::Deployment::Enterprise>) EnrolledEnterprises() const;
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::Phone::Management::Deployment::Enterprise) CurrentEnterprise() const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncAction) ValidateEnterprisesAsync() const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult>) RequestEnrollmentAsync(param::hstring const& enrollmentToken) const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperation<bool>) RequestUnenrollmentAsync(winrt::Windows::Phone::Management::Deployment::Enterprise const& enterprise) const;
    };
    template <> struct consume<winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentManager>
    {
        template <typename D> using type = consume_Windows_Phone_Management_Deployment_IEnterpriseEnrollmentManager<D>;
    };
    template <typename D>
    struct consume_Windows_Phone_Management_Deployment_IEnterpriseEnrollmentResult
    {
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::Phone::Management::Deployment::Enterprise) EnrolledEnterprise() const;
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::Phone::Management::Deployment::EnterpriseEnrollmentStatus) Status() const;
    };
    template <> struct consume<winrt::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult>
    {
        template <typename D> using type = consume_Windows_Phone_Management_Deployment_IEnterpriseEnrollmentResult<D>;
    };
    template <typename D>
    struct consume_Windows_Phone_Management_Deployment_IInstallationManagerStatics
    {
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>) AddPackageAsync(param::hstring const& title, winrt::Windows::Foundation::Uri const& sourceLocation) const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>) AddPackageAsync(param::hstring const& title, winrt::Windows::Foundation::Uri const& sourceLocation, param::hstring const& instanceId, param::hstring const& offerId, winrt::Windows::Foundation::Uri const& license) const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>>) GetPendingPackageInstalls() const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::ApplicationModel::Package>) FindPackagesForCurrentPublisher() const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::ApplicationModel::Package>) FindPackages() const;
    };
    template <> struct consume<winrt::Windows::Phone::Management::Deployment::IInstallationManagerStatics>
    {
        template <typename D> using type = consume_Windows_Phone_Management_Deployment_IInstallationManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Phone_Management_Deployment_IInstallationManagerStatics2
    {
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>) RemovePackageAsync(param::hstring const& packageFullName, winrt::Windows::Management::Deployment::RemovalOptions const& removalOptions) const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperationWithProgress<winrt::Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>) RegisterPackageAsync(winrt::Windows::Foundation::Uri const& manifestUri, param::async_iterable<winrt::Windows::Foundation::Uri> const& dependencyPackageUris, winrt::Windows::Management::Deployment::DeploymentOptions const& deploymentOptions) const;
        WINRT_IMPL_AUTO(winrt::Windows::Foundation::Collections::IIterable<winrt::Windows::ApplicationModel::Package>) FindPackages(param::hstring const& packageName, param::hstring const& packagePublisher) const;
    };
    template <> struct consume<winrt::Windows::Phone::Management::Deployment::IInstallationManagerStatics2>
    {
        template <typename D> using type = consume_Windows_Phone_Management_Deployment_IInstallationManagerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Phone_Management_Deployment_IPackageInstallResult
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) ProductId() const;
        [[nodiscard]] WINRT_IMPL_AUTO(winrt::Windows::Management::Deployment::PackageInstallState) InstallState() const;
    };
    template <> struct consume<winrt::Windows::Phone::Management::Deployment::IPackageInstallResult>
    {
        template <typename D> using type = consume_Windows_Phone_Management_Deployment_IPackageInstallResult<D>;
    };
    template <typename D>
    struct consume_Windows_Phone_Management_Deployment_IPackageInstallResult2
    {
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) ErrorText() const;
    };
    template <> struct consume<winrt::Windows::Phone::Management::Deployment::IPackageInstallResult2>
    {
        template <typename D> using type = consume_Windows_Phone_Management_Deployment_IPackageInstallResult2<D>;
    };
}
#endif
