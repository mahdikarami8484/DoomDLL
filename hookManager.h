#pragma once

#include <windows.h>
#include <vector>
#include <detours.h>

struct HookEntry {
	void** target;
	void* detour;
};

class HookManager {
public:
	void AddHook(void** target, void* detour);
	void EnableHooks();
	void DisableHooks();

private:
	std::vector<HookEntry> hooks;
};