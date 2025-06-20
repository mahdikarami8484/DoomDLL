#pragma once

#include <windows.h>

class Inject {
public:
	Inject(LPVOID &param);
	
	void loop();

	~Inject();
private:
	HMODULE hModule;
};

DWORD WINAPI thread(LPVOID param);