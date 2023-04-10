// rapl_reader.cpp
#include "rapl_reader.h"
#include <iostream>
#include <math.h>


constexpr uint32_t MSR_RAPL_POWER_UNIT = 0x606;
constexpr uint32_t MSR_PKG_ENERGY_STATUS = 0x611;

RAPLReader::RAPLReader() {
    energy_status_units = extract_bits(msr_reader.read(MSR_RAPL_POWER_UNIT), 8, 12);
}

double RAPLReader::read_energy() const {
    uint64_t energy_status = msr_reader.read(MSR_PKG_ENERGY_STATUS);

    double energy_units = pow(2.0, energy_status_units);
    double energy = static_cast<double>(energy_status) / energy_units;
    
    return energy;
}

uint64_t RAPLReader::extract_bits(uint64_t value, int start, int end) {
    uint64_t mask = (1ULL << (end - start + 1)) - 1;
    return (value >> start) & mask;
}
