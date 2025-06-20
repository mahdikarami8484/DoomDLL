#include "inject.h"

DWORD WINAPI thread(LPVOID param) {

	Inject* inject = new Inject(param);
	while (inject) {
		inject->loop();
		Sleep(100);
	};

	FreeLibraryAndExitThread((HMODULE)param, 0);
}

Inject::Inject(LPVOID &param) {
	this->hModule = (HMODULE)param;
	this->hProcess = GetCurrentProcess();
	SetProcessAffinityMask(this->hProcess, 1);
}

Inject::~Inject() {

}

void Inject::loop() {
	// it should be corrected in the future
	delete this;
}