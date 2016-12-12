#pragma once

#include "../BaseCompo.hpp"

class PinCompo : public BaseCompo
{
public:
  PinCompo();
  void  getCommand(std::map<std::string,BaseAction*>& cmds) override;
  ~PinCompo();
};
