#include "d3d9Hooks.h"
#include "../hookManager.h"

decltype(&hkEndScene) oEndScene = nullptr;

HRESULT WINAPI hkEndScene(IDirect3DDevice9* pDevice) {
	return oEndScene(pDevice);
}

void SetupD3D9Hooks() {
	IDirect3D9* d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (!d3d) return;

	D3DPRESENT_PARAMETERS d3dParam = {};
	d3dParam.Windowed = TRUE;
	d3dParam.SwapEffect = D3DSWAPEFFECT_DISCARD;

	HWND hwnd = GetForegroundWindow(); 
	
	// temporary
	IDirect3DDevice9* tempDevice = nullptr;
	
	d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParam, &tempDevice);
	
	void** vTable = *reinterpret_cast<void***>(tempDevice);
	oEndScene = reinterpret_cast<decltype(&hkEndScene)>(vTable[42]);

	extern HookManager gHooks;
	gHooks.AddHook(reinterpret_cast<void**>(&oEndScene), hkEndScene);

	tempDevice->Release();
	d3d->Release();
}