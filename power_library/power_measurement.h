// power_measurement.h
#pragma once
#include "rapl_reader.h"
#include <iostream>
#include <chrono>

namespace power_measurement_module {

template <typename Func>
void measure_power_consumption(Func&& func) {
    RAPLReader rapl_reader;
    double start_energy = rapl_reader.read_energy();
    auto start_time = std::chrono::steady_clock::now();
    func();
    auto end_time = std::chrono::steady_clock::now();
    double end_energy = rapl_reader.read_energy();
    double energy_consumed = end_energy - start_energy;

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    std::cout << "Time spent: " << duration << " ms" << std::endl;
    std::cout << "Energy consumed: " << energy_consumed << " mJ" << std::endl;
}

} // namespace power_measurement_module
