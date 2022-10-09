// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.220110.5

#pragma once
#ifndef WINRT_Windows_Phone_Notification_Management_1_H
#define WINRT_Windows_Phone_Notification_Management_1_H
#include "winrt/impl/Windows.Phone.Notification.Management.0.h"
WINRT_EXPORT namespace winrt::Windows::Phone::Notification::Management
{
    struct __declspec(empty_bases) IAccessoryManager :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAccessoryManager>
    {
        IAccessoryManager(std::nullptr_t = nullptr) noexcept {}
        IAccessoryManager(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAccessoryManager2 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAccessoryManager2>
    {
        IAccessoryManager2(std::nullptr_t = nullptr) noexcept {}
        IAccessoryManager2(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAccessoryManager3 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAccessoryManager3>
    {
        IAccessoryManager3(std::nullptr_t = nullptr) noexcept {}
        IAccessoryManager3(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAccessoryNotificationTriggerDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAccessoryNotificationTriggerDetails>
    {
        IAccessoryNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IAccessoryNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAlarmNotificationTriggerDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAlarmNotificationTriggerDetails>,
        impl::require<winrt::Windows::Phone::Notification::Management::IAlarmNotificationTriggerDetails, winrt::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>
    {
        IAlarmNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IAlarmNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAlarmNotificationTriggerDetails2 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAlarmNotificationTriggerDetails2>
    {
        IAlarmNotificationTriggerDetails2(std::nullptr_t = nullptr) noexcept {}
        IAlarmNotificationTriggerDetails2(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppNotificationInfo :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAppNotificationInfo>
    {
        IAppNotificationInfo(std::nullptr_t = nullptr) noexcept {}
        IAppNotificationInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBinaryId :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IBinaryId>
    {
        IBinaryId(std::nullptr_t = nullptr) noexcept {}
        IBinaryId(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICalendarChangedNotificationTriggerDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ICalendarChangedNotificationTriggerDetails>,
        impl::require<winrt::Windows::Phone::Notification::Management::ICalendarChangedNotificationTriggerDetails, winrt::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>
    {
        ICalendarChangedNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        ICalendarChangedNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICortanaTileNotificationTriggerDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ICortanaTileNotificationTriggerDetails>,
        impl::require<winrt::Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails, winrt::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>
    {
        ICortanaTileNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        ICortanaTileNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailAccountInfo :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IEmailAccountInfo>
    {
        IEmailAccountInfo(std::nullptr_t = nullptr) noexcept {}
        IEmailAccountInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailFolderInfo :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IEmailFolderInfo>
    {
        IEmailFolderInfo(std::nullptr_t = nullptr) noexcept {}
        IEmailFolderInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailNotificationTriggerDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IEmailNotificationTriggerDetails>,
        impl::require<winrt::Windows::Phone::Notification::Management::IEmailNotificationTriggerDetails, winrt::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>
    {
        IEmailNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IEmailNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailNotificationTriggerDetails2 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IEmailNotificationTriggerDetails2>,
        impl::require<winrt::Windows::Phone::Notification::Management::IEmailNotificationTriggerDetails2, winrt::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>
    {
        IEmailNotificationTriggerDetails2(std::nullptr_t = nullptr) noexcept {}
        IEmailNotificationTriggerDetails2(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailReadNotificationTriggerDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IEmailReadNotificationTriggerDetails>,
        impl::require<winrt::Windows::Phone::Notification::Management::IEmailReadNotificationTriggerDetails, winrt::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>
    {
        IEmailReadNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IEmailReadNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaControlsTriggerDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMediaControlsTriggerDetails>,
        impl::require<winrt::Windows::Phone::Notification::Management::IMediaControlsTriggerDetails, winrt::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>
    {
        IMediaControlsTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IMediaControlsTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaMetadata :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IMediaMetadata>
    {
        IMediaMetadata(std::nullptr_t = nullptr) noexcept {}
        IMediaMetadata(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPhoneCallDetails>
    {
        IPhoneCallDetails(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLineDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPhoneLineDetails>
    {
        IPhoneLineDetails(std::nullptr_t = nullptr) noexcept {}
        IPhoneLineDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLineDetails2 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPhoneLineDetails2>
    {
        IPhoneLineDetails2(std::nullptr_t = nullptr) noexcept {}
        IPhoneLineDetails2(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneNotificationTriggerDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPhoneNotificationTriggerDetails>,
        impl::require<winrt::Windows::Phone::Notification::Management::IPhoneNotificationTriggerDetails, winrt::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>
    {
        IPhoneNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IPhoneNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IReminderNotificationTriggerDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IReminderNotificationTriggerDetails>,
        impl::require<winrt::Windows::Phone::Notification::Management::IReminderNotificationTriggerDetails, winrt::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>
    {
        IReminderNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IReminderNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IReminderNotificationTriggerDetails2 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IReminderNotificationTriggerDetails2>
    {
        IReminderNotificationTriggerDetails2(std::nullptr_t = nullptr) noexcept {}
        IReminderNotificationTriggerDetails2(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeedDialEntry :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ISpeedDialEntry>
    {
        ISpeedDialEntry(std::nullptr_t = nullptr) noexcept {}
        ISpeedDialEntry(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextResponse :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<ITextResponse>
    {
        ITextResponse(std::nullptr_t = nullptr) noexcept {}
        ITextResponse(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationTriggerDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IToastNotificationTriggerDetails>,
        impl::require<winrt::Windows::Phone::Notification::Management::IToastNotificationTriggerDetails, winrt::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>
    {
        IToastNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationTriggerDetails2 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IToastNotificationTriggerDetails2>
    {
        IToastNotificationTriggerDetails2(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationTriggerDetails2(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVolumeInfo :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IVolumeInfo>
    {
        IVolumeInfo(std::nullptr_t = nullptr) noexcept {}
        IVolumeInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
