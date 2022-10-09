// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.220110.5

#pragma once
#ifndef WINRT_Windows_Phone_Devices_Notification_0_H
#define WINRT_Windows_Phone_Devices_Notification_0_H
WINRT_EXPORT namespace winrt::Windows::Foundation
{
}
WINRT_EXPORT namespace winrt::Windows::Phone::Devices::Notification
{
    struct IVibrationDevice;
    struct IVibrationDeviceStatics;
    struct VibrationDevice;
}
namespace winrt::impl
{
    template <> struct category<winrt::Windows::Phone::Devices::Notification::IVibrationDevice>{ using type = interface_category; };
    template <> struct category<winrt::Windows::Phone::Devices::Notification::IVibrationDeviceStatics>{ using type = interface_category; };
    template <> struct category<winrt::Windows::Phone::Devices::Notification::VibrationDevice>{ using type = class_category; };
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Devices::Notification::VibrationDevice> = L"Windows.Phone.Devices.Notification.VibrationDevice";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Devices::Notification::IVibrationDevice> = L"Windows.Phone.Devices.Notification.IVibrationDevice";
    template <> inline constexpr auto& name_v<winrt::Windows::Phone::Devices::Notification::IVibrationDeviceStatics> = L"Windows.Phone.Devices.Notification.IVibrationDeviceStatics";
    template <> inline constexpr guid guid_v<winrt::Windows::Phone::Devices::Notification::IVibrationDevice>{ 0x1B4A6595,0xCFCD,0x4E08,{ 0x92,0xFB,0xC1,0x90,0x6D,0x04,0x49,0x8C } }; // 1B4A6595-CFCD-4E08-92FB-C1906D04498C
    template <> inline constexpr guid guid_v<winrt::Windows::Phone::Devices::Notification::IVibrationDeviceStatics>{ 0x332FD2F1,0x1C69,0x4C91,{ 0x94,0x9E,0x4B,0xB6,0x7A,0x85,0xBD,0xC7 } }; // 332FD2F1-1C69-4C91-949E-4BB67A85BDC7
    template <> struct default_interface<winrt::Windows::Phone::Devices::Notification::VibrationDevice>{ using type = winrt::Windows::Phone::Devices::Notification::IVibrationDevice; };
    template <> struct abi<winrt::Windows::Phone::Devices::Notification::IVibrationDevice>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Vibrate(int64_t) noexcept = 0;
            virtual int32_t __stdcall Cancel() noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::Phone::Devices::Notification::IVibrationDeviceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Phone_Devices_Notification_IVibrationDevice
    {
        WINRT_IMPL_AUTO(void) Vibrate(winrt::Windows::Foundation::TimeSpan const& duration) const;
        WINRT_IMPL_AUTO(void) Cancel() const;
    };
    template <> struct consume<winrt::Windows::Phone::Devices::Notification::IVibrationDevice>
    {
        template <typename D> using type = consume_Windows_Phone_Devices_Notification_IVibrationDevice<D>;
    };
    template <typename D>
    struct consume_Windows_Phone_Devices_Notification_IVibrationDeviceStatics
    {
        WINRT_IMPL_AUTO(winrt::Windows::Phone::Devices::Notification::VibrationDevice) GetDefault() const;
    };
    template <> struct consume<winrt::Windows::Phone::Devices::Notification::IVibrationDeviceStatics>
    {
        template <typename D> using type = consume_Windows_Phone_Devices_Notification_IVibrationDeviceStatics<D>;
    };
}
#endif
