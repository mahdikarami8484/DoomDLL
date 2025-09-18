#include "gameFuncHooks.h"
#include <iostream>
#include <intrin.h>

decltype(&hkSetResolution) oSetResolution = nullptr;

void WINAPI hkSetResolution(void* res) {
	int* data = (int*)res;

	int originalWidth = data[0];
	int originalHeight = data[1];

	data[0] = 1920;
	data[1] = 1080;

	oSetResolution(res);
}

void SetupGameHooks() {
	uintptr_t gtaBase = (uintptr_t)GetModuleHandleA(NULL);
	uintptr_t addrSetResolution = gtaBase + 0x3F6CB0;

	oSetResolution = reinterpret_cast<decltype(&hkSetResolution)>(addrSetResolution);

	extern HookManager gHooks;
	gHooks.AddHook(reinterpret_cast<void**>(&oSetResolution), hkSetResolution);
}