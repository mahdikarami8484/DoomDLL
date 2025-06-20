#include "renderer.h"

void Renderer::DrawStuff(IDirect3DDevice9* pDevice) {
	D3DRECT rect = { 100, 100, 300, 200 };
	pDevice->Clear(1, &rect, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255, 0, 0, 255), 1.0f, 0);
}