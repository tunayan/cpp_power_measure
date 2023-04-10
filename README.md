# CPP Power Measurement 
The Power Library is a C++ project that measures the power consumption of different functions using the Intel Running Average Power Limit (RAPL) interface for Intel processors. This module can be easily included in other projects to compare power consumption of various functions or operations.

## Building the Environment
Install the required packages (for Ubuntu):

```bash
sudo apt-get update
sudo apt-get install build-essential cmake

```

## Building the Project

Clone the project or copy the project files to your local machine.

Navigate to the project's root directory and create a build directory:

```bash
mkdir build
cd build
cmake ..
make

```
## Running the Project
Grant the necessary permissions to read the MSR files:

```bash
sudo modprobe msr
sudo chown root:root power_test
sudo chmod u+s power_test
./power_test
```

## Including the Power Measurement Library in Other Projects
To include the Power Measurement Library in another C++ project, follow these steps:

- Copy the power_library folder to your project directory.
- Add the following lines to your project's CMakeLists.txt file:

```
add_subdirectory(power_library)
target_link_libraries(<your_target_name> power_lib)
```
- Include the power_measurement.h file in your source code:

```cpp
#include "power_library/power_measurement.h"
```
- Use the power_library::measure_power_consumption function to measure the power consumption of your functions:
```cpp
power_measurement_module::measure_power_consumption(<your_function_name>);
```