#pragma once

#include <windows.h>
#include <memory>
#include "hookManager.h"
#include "hooks/d3d9Hooks.h"

class Inject {
public:
	Inject(LPVOID &param);
	
	void loop();

	~Inject();
private:
	HMODULE hModule;
	HANDLE hProcess;
};

extern HookManager gHooks;

DWORD WINAPI thread(LPVOID param);