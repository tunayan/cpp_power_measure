#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "power_measurement.h"

std::vector<int> generate_random_vector(size_t size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    std::vector<int> v(size);
    for (auto& elem : v) {
        elem = dis(gen);
    }
    return v;
}

// Inefficient sorting algorithm: Bubble Sort
void bubble_sort(std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j < v.size() - 1 - i; ++j) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

// Efficient sorting algorithm: Quick Sort
void quick_sort(std::vector<int>& v, int low, int high) {
    if (low < high) {
        int pivot = v[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (v[j] < pivot) {
                ++i;
                std::swap(v[i], v[j]);
            }
        }
        std::swap(v[i + 1], v[high]);

        quick_sort(v, low, i);
        quick_sort(v, i + 2, high);
    }
}

int main() {
    constexpr size_t data_size = 50000;
    auto data1 = generate_random_vector(data_size);
    auto data2 = generate_random_vector(data_size);

    std::cout << "Bubble Sort:" << std::endl;
    power_measurement_module::measure_power_consumption([&data1]() { bubble_sort(data1); });

    std::cout << "Quick Sort:" << std::endl;
    power_measurement_module::measure_power_consumption([&data2]() { quick_sort(data2, 0, data_size - 1); });

    return 0;
}
