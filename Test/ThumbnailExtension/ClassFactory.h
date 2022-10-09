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

//#include "windows.h"
#include <unknwn.h>
//#include "unknwn.h"

#include "ThumbnailProvider.h"
#include "UnkownImpl.h"

#pragma once

namespace ShellExtentions
{
	class ClassFactory : public IClassFactory
	{
	private:
		ULONG mRefCount;

	public:
		ClassFactory()
		{
		}

		STDMETHODIMP    QueryInterface(REFIID riid, void** ppv)
		{
			if (!ppv)
				return E_POINTER;

			if (riid == IID_IClassFactory)
			{
				*ppv = dynamic_cast<IClassFactory*>(this);
				this->AddRef();

				return S_OK;
			}
			else if (riid == IID_IUnknown)
			{
				*ppv = dynamic_cast<IUnknown*>(this);
				this->AddRef();

				return S_OK;
			}

			return E_NOINTERFACE;
		}

		STDMETHODIMP_(ULONG) AddRef(void)
		{
			return ++mRefCount;
		}

		STDMETHODIMP_(ULONG) Release(void)
		{
			ULONG ref = --mRefCount;
			if (!ref)
				delete this;

			return ref;
		}

		// IClassFactory
		IFACEMETHODIMP CreateInstance(_In_opt_ IUnknown* unkOuter, REFIID riid, _COM_Outptr_ void** object)
		{
			if (!object)
				return E_POINTER;

			if (riid == IID_IThumbnailCache)
			{
				IThumbnailProvider* thumbnailProvider = new ThumbnailProvider();
				thumbnailProvider->QueryInterface(riid, object);

				return S_OK;
			}

			return E_NOINTERFACE;
		}

		IFACEMETHODIMP LockServer(BOOL lock)
		{
			return S_OK;
		}
	};
}
