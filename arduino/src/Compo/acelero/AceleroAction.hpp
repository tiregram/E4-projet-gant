#pragma once

#include "../BaseAction.hpp"

class Ace_getAction: public BaseAction
{
public:
  Ace_getAction(BaseCompo* comp);
  bool Do(const std::string&) override;
  virtual ~Ace_getAction();
};

