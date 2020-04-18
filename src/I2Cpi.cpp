#include "I2Cpi.h"

I2Cpi::I2Cpi(std::string device, unsigned char address) {
    this->device = device;
    this->address = address;
}

I2Cpi::~I2Cpi() { close(i2c); }

bool I2Cpi::init() {
    i2c = open(device.c_str(), O_RDWR);
    if (i2c < 0) {
        return false;
    }

    if (ioctl(i2c, I2C_SLAVE, address) >= 0) {
        return true;
    }

    return false;
}

bool I2Cpi::send(const Config& config, const char* buffer, int size) {
    if (write(i2c, buffer, size) == size) {
        return true;
    }

    return false;
}

bool I2Cpi::receive(const Config& config, char* buffer, int size) {
    if (read(i2c, buffer, size) == size) {
        return true;
    }

    return false;
}