#pragma once

#include <d3d9.h>

#pragma comment(lib, "d3d9.lib")

#include "../hookManager.h"

HRESULT WINAPI hkCreateDevice(
	IDirect3D9* pD3D,
	UINT Adapter,
	D3DDEVTYPE DeviceType,
	HWND hFocusWindow,
	DWORD BehaviorFlags,
	D3DPRESENT_PARAMETERS* pPresentationParameters,
	IDirect3DDevice9** ppReturnedDeviceInterface
);

extern decltype(&hkCreateDevice) oCreateDevice;

HRESULT WINAPI hkEndScene(IDirect3DDevice9* pDevice);

extern decltype(&hkEndScene) oEndScene;

void SetupD3D9Hooks();