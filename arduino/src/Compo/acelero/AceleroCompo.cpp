

#include "AceleroCompo.hpp"
#include "Ace_getAction.hpp"

#include "I2Cdev.h"
#include "MPU6050.h"

#include <map>

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif



AceleroCompo::AceleroCompo():BaseCompo("acelero") {

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif

  accelgyro.initialize();

}

AceleroCompo::~AceleroCompo() {

}

void  AceleroCompo::getCommand(std::map<std::string,BaseAction*>& cmds)
{
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  cmds["ace_get"]   = new Ace_getAction(this);

}
