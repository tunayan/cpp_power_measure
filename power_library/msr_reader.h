// msr_reader.h
#pragma once
#include <cstdint>

class MSRReader {
public:
    MSRReader();
    ~MSRReader();

    uint64_t read(uint32_t reg) const;

private:
    int fd;
};
