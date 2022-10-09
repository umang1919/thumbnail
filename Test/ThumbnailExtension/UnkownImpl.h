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

#include <unknwn.h>

#pragma once

template<typename T>
class UnknownImpl : public T
{
public:
	UnknownImpl()
	: mRefCount(0)
	{
	}

	HRESULT __stdcall QueryInterface(
		REFIID riid,
		void** ppObj)
	{
		if (!ppObj)
		{
			return E_INVALIDARG;
		}

		*ppObj = NULL;
		if (riid == IID_IUnknown)
		{
			// Increment the reference count and return the pointer.
			*ppObj = (LPVOID)this;
			AddRef();
			return NOERROR;
		}

		return E_NOINTERFACE;
	}

	ULONG   __stdcall AddRef()
	{
		InterlockedIncrement(&mRefCount);
		return mRefCount;
	}

	ULONG   __stdcall Release()
	{
		ULONG refCount = InterlockedDecrement(&mRefCount);
		if (!refCount)
		{
			delete this;
		}
		return refCount;
	}

private:
	ULONG mRefCount;
};
