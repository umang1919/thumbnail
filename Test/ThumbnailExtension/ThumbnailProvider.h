// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#pragma once
#include <thumbcache.h>
#include "UnkownImpl.h"

namespace ShellExtentions
{
	class __declspec(uuid("62924C2B-6B51-4168-BFAE-069318861C95")) ThumbnailProvider : public virtual UnknownImpl<IThumbnailProvider>, virtual UnknownImpl<IInitializeWithItem>
	{
	public:
		ThumbnailProvider();
		~ThumbnailProvider();

		// IInitializeWithItem
		IFACEMETHODIMP Initialize(_In_ IShellItem* item, _In_ DWORD mode);

		// IThumbnailProvider
		IFACEMETHODIMP GetThumbnail(_In_ UINT width, _Out_ HBITMAP* bitmap, _Out_ WTS_ALPHATYPE* alphaType);

	private:
		IShellItem2* _itemDest;
		IShellItem2* _itemSrc;
	};
}
