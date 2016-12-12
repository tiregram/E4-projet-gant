#pragma once

#include "../BaseCompo.hpp"

class HelpCompo : public BaseCompo
{
public:
  HelpCompo();
  void  getCommand(std::map<std::string,BaseAction*>& cmds) override;
  ~HelpCompo();
};



