#pragma once
#include <windows.h>
#include <string>

class KernelMonitor {
private:
    HMODULE hNtDll;
    FARPROC pNtQuerySystemInformation;

    bool InitializeNtDll();
    bool EnableDebugPrivilege();

public:
    KernelMonitor();
    ~KernelMonitor();

    bool IsInitialized() const;
    void EnumerateProcesses();
    void EnumerateHandles(ULONG_PTR targetProcessId = 0);
};
