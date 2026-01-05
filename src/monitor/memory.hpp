#pragma once
#include <cstdint>

struct MemoryInfo {
    uint64_t total_bytes;
    uint64_t used_bytes;
    uint64_t available_bytes;
    double usage_percent;
};

MemoryInfo getMemoryInfo();
