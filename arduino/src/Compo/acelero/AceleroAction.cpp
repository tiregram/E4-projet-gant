

#include "../BaseAction.hpp"
#include "AceleroAction.hpp"
#include "AceleroCompo.hpp"

#include <sstream>

Ace_getAction::Ace_getAction(BaseCompo* comp)
  :BaseAction(comp)
{

}

bool
Ace_getAction::Do(const std::string& in)
{

  AceleroCompo& ac = (AceleroCompo&) this->comp;

  ac.rx  = ac.rx + float(ac.gx) * 0.01/131;
  ac.ry  = ac.ry + float(ac.gy) * 0.01/131;
  ac.rz  = ac.rz + float(ac.gz) * 0.01/131;

  ac.vx  = ac.vx + float(ac.ax) * 0.01/131;
  ac.vy  = ac.vy + float(ac.ay) * 0.01/131;
  ac.vz  = ac.vz + float(ac.az) * 0.01/131;

  ac.px  = ac.px + ac.vx;
  ac.py  = ac.py + ac.vy;
  ac.pz  = ac.pz + ac.vz;

  if (ac.rx < 0)   ac.rx += 360;
  if (ac.rx > 360) ac.rx -= 360;
  if (ac.ry < 0)   ac.ry += 360;
  if (ac.ry > 360) ac.ry -= 360;
  if (ac.rz < 0)   ac.rz += 360;
  if (ac.rz > 360) ac.rz -= 360;

  char buff[200];
  sprintf(buff,"{rx:%d,ry:%d,rz:%d}", (int) ac.rx,(int) ac.ry,(int) ac.rz);
  Serial.printf(buff);

  return true;
}

Ace_getAction::~Ace_getAction() {

}
