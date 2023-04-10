// rapl_reader.h
#pragma once
#include "msr_reader.h"

class RAPLReader {
public:
    RAPLReader();
    double read_energy() const;

private:
    static uint64_t extract_bits(uint64_t value, int start, int end);

    double energy_status_units;
    MSRReader msr_reader;
};
