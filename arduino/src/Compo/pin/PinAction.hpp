#pragma once

#include "../BaseAction.hpp"

class PinAction : public BaseAction
{
public:
  PinAction(BaseCompo* comp);
  std::string Do(const std::string&) override;
  virtual ~PinAction();
};

