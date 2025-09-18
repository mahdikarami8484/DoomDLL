#include "inject.h"
void CreateConsole()
{
	AllocConsole();
	FILE* fp;
	FILE* fpOut;
	freopen_s(&fpOut, "CONOUT$", "w", stdout);

	FILE* fpIn;
	freopen_s(&fpIn, "CONIN$", "r", stdin);

	SetConsoleTitleA("Injected DLL Console");

	printf("Console initialized.\n");
}

DWORD WINAPI thread(LPVOID param) {

	std::unique_ptr<Inject> inject = std::make_unique<Inject>(param);
	while (inject.get()) {
		inject->loop();
		Sleep(100);
	};

	FreeLibraryAndExitThread((HMODULE)param, 0);
}

HookManager gHooks;

Inject::Inject(LPVOID &param) {
	this->hModule = (HMODULE)param;
	this->hProcess = GetCurrentProcess();
	SetProcessAffinityMask(this->hProcess, 1);

	SetupD3D9Hooks();
	SetupGameHooks();
	gHooks.EnableHooks();

	CreateConsole();
}

Inject::~Inject() {
	gHooks.DisableHooks();
}

void Inject::loop() {
	// it should be corrected in the future
	if (GetAsyncKeyState(VK_F4) & 0x8000) delete this;
}