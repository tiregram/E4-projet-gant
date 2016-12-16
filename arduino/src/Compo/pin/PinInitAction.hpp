#pragma once

#include "../BaseAction.hpp"
#include <string>

class PinInitAction : public BaseAction
{
public:
  PinInitAction(BaseCompo* comp);
  virtual bool  Do(const std::string&) override;
  virtual ~PinInitAction();
};
