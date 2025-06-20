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
}

Inject::~Inject() {

}

void Inject::loop() {

	delete this;
}