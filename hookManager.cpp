#include "hookManager.h"

void HookManager::AddHook(void** target, void* detour) {
	this->hooks.push_back({ target, detour });
}

void HookManager::EnableHooks() {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    
    for (auto& hook : hooks) {
        DetourAttach(hook.target, hook.detour);
    }
    
    DetourTransactionCommit();
}

void HookManager::DisableHooks() {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    for (auto& hook : hooks) {
        DetourDetach(hook.target, hook.detour);
    }

    DetourTransactionCommit();
}