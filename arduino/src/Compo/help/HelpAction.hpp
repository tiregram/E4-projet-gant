#pragma once

#include "../Action.hpp"

class HelpAction : public BaseAction
{
public:
  HelpAction(BaseCompo* comp);
  virtual std::string Do(const std::string&) override;
  virtual ~HelpAction();
};



