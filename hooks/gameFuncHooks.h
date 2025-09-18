#pragma once

#include "../hookManager.h"

struct ResolutionInfo {
    int width;
    int height;
    int depth;
    int unknown;
};

void __stdcall hkSetResolution(void* res);
//typedef void(WINAPI* SetResolutionFn)(void* res);
//extern SetResolutionFn oSetResolution;
extern decltype(&hkSetResolution) oSetResolution;

void SetupGameHooks();