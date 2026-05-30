#include <iostream>
#include "../include/Monitor.h"

void PrintBanner() {
    std::cout << "=================================================\n";
    std::cout << "     Monitor - Advanced NTAPI Diagnostic Utility\n";
    std::cout << "     Build: Production Ready (x64)\n";
    std::cout << "=================================================\n\n";
}

int main() {
  
    setlocale(LC_ALL, "C");
    
    PrintBanner();

    KernelMonitor monitor;

    if (!monitor.IsInitialized()) {
        std::cerr << "[-] FATAL ERROR: Failed to initialize NTDLL pointers. Program will terminate.\n";
        return 1;
    }

    std::cout << "[~] Successfully hooked into NTDLL.\n";
    std::cout << "[~] Fetching processes directly via kernel structures...\n";
    monitor.EnumerateProcesses();

    std::cout << "\n[~] Fetching raw system handles...\n";
    monitor.EnumerateHandles(0); 

    std::cout << "\n[!] Execution finished. Press ENTER to exit...";
    std::cin.get();
    
    return 0;
}
