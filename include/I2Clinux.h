#pragma once

#include <I2C.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>

class I2Clinux : public I2C {
  private:
    int i2c;
    std::string device;
    unsigned char address;

  public:
    I2Clinux(std::string device, unsigned char address);
    ~I2Clinux();
    // Returns true if initialization is successful
    bool init();
    bool send(const Config& config, const char* buffer, int size);
    bool receive(const Config& config, char* buffer, int size);
};