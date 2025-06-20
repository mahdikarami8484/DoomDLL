#pragma once

#include <d3d9.h>

HRESULT WINAPI hkEndScene(IDirect3DDevice9* pDevice);
extern decltype(&hkEndScene) oEndScene;

void SetupD3D9Hooks();