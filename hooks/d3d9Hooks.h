#pragma once

#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")

#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")

#include <doomgeneric.h>
#pragma comment(lib, "doomgeneric.lib")

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

HRESULT WINAPI hkSetTexture(LPDIRECT3DDEVICE9 pDevice, DWORD Stage, LPDIRECT3DBASETEXTURE9 pTexture);

extern decltype(&hkSetTexture) oSetTexture;

HRESULT WINAPI hkEndScene(IDirect3DDevice9* pDevice);

extern decltype(&hkEndScene) oEndScene;

void SetupD3D9Hooks();