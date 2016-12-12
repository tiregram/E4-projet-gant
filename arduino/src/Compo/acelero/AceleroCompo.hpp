#pragma once

#include "../BaseCompo.hpp"
#include "MPU6050.h"

class AceleroCompo:public BaseCompo
{
public:
  // r pour rotation v pour vitesse ,p pour possition , a pour acelero ,g pour aceleroderot
  int16_t ax, ay, az;
  int16_t vx, vy, vz;
  int16_t px, py, pz;
  int16_t gx, gy, gz;
  float rx,ry,rz;
  char incomingByte;

  MPU6050 accelgyro;

public:
  AceleroCompo();
  void  getCommand(std::map<std::string,BaseAction*>& cmds) override;
  virtual ~AceleroCompo();
};


