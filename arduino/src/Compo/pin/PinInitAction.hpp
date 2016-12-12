#pragma once

#include "../BaseAction.hpp"
#include <string>
class PinInitAction : public BaseAction
{
public:
  PinInitAction(BaseCompo* comp);
  virtual std::string Do(const std::string&) override;
  virtual ~PinInitAction();
};
