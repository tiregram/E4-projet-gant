#pragma once

#include "../BaseCompo.hpp"

class AceleroCompo:public BaseCompo
{
protected:
  // r pour rotation v pour vitesse ,p pour possition , a pour acelero ,g pour aceleroderot
  int16_t ax, ay, az;
  int16_t vx, vy, vz;
  int16_t px, py, pz;
  int16_t gx, gy, gz;
  char incomingByte;
  float rx,ry,rz;

public:
  AceleroCompo();
  void  getCommand(std::map<std::string,BaseAction*>& cmds) override;
  virtual ~AceleroCompo();
};


