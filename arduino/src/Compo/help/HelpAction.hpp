#pragma once

#include "../BaseAction.hpp"

class HelpAction : public BaseAction
{
public:
  HelpAction(BaseCompo* comp);
  virtual bool Do(const std::string&) override;
  virtual ~HelpAction();
};



