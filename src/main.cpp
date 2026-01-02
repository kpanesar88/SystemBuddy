#include <iostream>
#include <windows.h>
#include <monitor/cpu.hpp>

int main() {

    // CPU usage sampling
    CpuTimes prev = getCpuTimes();
    Sleep(500);  // 0.5s gives more stable results
    CpuTimes curr = getCpuTimes();

    double usage = getCpuUsage(prev, curr);
    double freq  = getCpuFrequencyGHz();
    std::string cpuName = getCpuName();

    int cores = 0;
    int threads = 0;
    getCpuCoresAndThreads(cores, threads);

    std::cout << "CPU NAME: " << cpuName << "\n";
    std::cout << "CPU USAGE: " << usage << "%\n";
    std::cout << "CPU FREQ (GHz): " << freq << "\n";
    std::cout << "CPU CORES: " << cores << "\n";
    std::cout << "CPU THREADS: " << threads << "\n";

    return 0;
}
