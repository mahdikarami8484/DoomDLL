#include "d3d9Hooks.h"
#include "../rendering/renderer.h"

decltype(&hkEndScene) oEndScene = nullptr;

HRESULT WINAPI hkEndScene(IDirect3DDevice9* pDevice) {
	Renderer::DrawStuff(pDevice);
	return oEndScene(pDevice);
}

void SetupD3D9Hooks() {
	IDirect3D9* d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (!d3d) return;

	D3DPRESENT_PARAMETERS d3dParams = {};
	d3dParams.Windowed = TRUE;
	d3dParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dParams.hDeviceWindow = GetForegroundWindow();
	
	// temporary
	IDirect3DDevice9* tempDevice = nullptr;
	
	HRESULT result = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3dParams.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParams, &tempDevice);
	if (FAILED(result) || !tempDevice) {
		d3d->Release();
		return;
	}
	void** vTable = *reinterpret_cast<void***>(tempDevice);
	oEndScene = reinterpret_cast<decltype(&hkEndScene)>(vTable[42]);

	extern HookManager gHooks;
	gHooks.AddHook(reinterpret_cast<void**>(&oEndScene), hkEndScene);

	tempDevice->Release();
	d3d->Release();
}