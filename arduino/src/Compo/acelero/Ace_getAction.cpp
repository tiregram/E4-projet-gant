
#include "../Action.hpp"
#include "Ace_getAction.hpp"

Ace_getAction::Ace_getAction(BaseCompo* comp)
  :BaseAction(comp)
{
  
}

std::string
Ace_getAction::Do(const std::string&)
{

  this->rx  = rx + float(gx) * 0.01/131;
  this->ry  = ry + float(gy) * 0.01/131;
  this->rz  = rz + float(gz) * 0.01/131;

  this->vx  = vx + float(ax) * 0.01/131;
  this->vy  = vy + float(ay) * 0.01/131;
  this->vz  = vz + float(az) * 0.01/131;

  this->px  = px + vx;
  this->py  = py + vy;
  this->pz  = pz + vz;

  if (this->rx < 0)  this->rx += 360;
  if (this->rx > 360)this->rx -= 360;
  if (this->ry < 0)  this->ry += 360;
  if (this->ry > 360)this->ry -= 360;
  if (this->rz < 0)  this->rz += 360;
  if (this->rz > 360)this->rz -= 360;

  std::string retu = "{aceX:,aceY:20,aceZ:30}";

  return retu;
}

Ace_getAction::~Ace_getAction() {

}
