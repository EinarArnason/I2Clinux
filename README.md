# I2Clinux library

I2C implementation for Linux

## The What

This library is a Linux implementation for I<sup>2</sup>C controllers.

## The Why

Because this library inherits the I2C interface, it can be applied in a modular manner.

## The How

### Building

#### Using cmake

```cmake
add_subdirectory(${I2ClinuxDir})
target_link_libraries(${PROJECT_NAME} I2Clinux)
```

### Usage

Typical operation:

```c++
#include "I2Clinux.h"

I2C::Config i2cConfig(0x00, 100000);
I2Clinux i2c("/dev/i2c-1", i2cConfig.address);
i2c.init();

char data[1] = 0xAA;
i2c.send(i2cConfig, data, sizeof(data));
i2c.receive(i2cConfig, data, sizeof(data));
```

## The Who

Einar Arnason  
<https://github.com/EinarArnason>  
<https://www.linkedin.com/in/einararnason/>
