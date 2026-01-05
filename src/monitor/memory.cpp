#include "memory.hpp"
#include <windows.h>

MemoryInfo getMemoryInfo() {
    MEMORYSTATUSEX mem{};
    mem.dwLength = sizeof(mem);

    MemoryInfo info{};

    if (!GlobalMemoryStatusEx(&mem)) {
        return info;
    }

    info.total_bytes     = mem.ullTotalPhys;
    info.available_bytes = mem.ullAvailPhys;
    info.used_bytes      = info.total_bytes - info.available_bytes;
    info.usage_percent =
        (static_cast<double>(info.used_bytes) /
         static_cast<double>(info.total_bytes)) * 100.0;

    return info;
}
