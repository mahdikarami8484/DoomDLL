#pragma once

#include <d3d9.h>

#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "../hookManager.h"

HRESULT WINAPI hkEndScene(IDirect3DDevice9* pDevice);

extern decltype(&hkEndScene) oEndScene;

void SetupD3D9Hooks();