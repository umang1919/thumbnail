// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.220110.5

#pragma once
#ifndef WINRT_Windows_Phone_Devices_Power_1_H
#define WINRT_Windows_Phone_Devices_Power_1_H
#include "winrt/impl/Windows.Phone.Devices.Power.0.h"
WINRT_EXPORT namespace winrt::Windows::Phone::Devices::Power
{
    struct __declspec(empty_bases) IBattery :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IBattery>
    {
        IBattery(std::nullptr_t = nullptr) noexcept {}
        IBattery(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBatteryStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IBatteryStatics>
    {
        IBatteryStatics(std::nullptr_t = nullptr) noexcept {}
        IBatteryStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
