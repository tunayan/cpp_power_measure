// msr_reader.cpp
#include "msr_reader.h"
#include <stdexcept>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <asm/msr.h>

MSRReader::MSRReader() {
    fd = open("/dev/cpu/0/msr", O_RDONLY);
    if (fd < 0) {
        throw std::runtime_error("Failed to open /dev/cpu/0/msr");
    }
}

MSRReader::~MSRReader() {
    if (fd >= 0) {
        close(fd);
    }
}

uint64_t MSRReader::read(uint32_t reg) const {
    uint64_t data;
    if (pread(fd, &data, sizeof(data), reg) != sizeof(data)) {
        throw std::runtime_error("Failed to read MSR value");
    }
    return data;
}
