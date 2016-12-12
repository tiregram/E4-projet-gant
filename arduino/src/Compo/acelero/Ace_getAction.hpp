#pragma once

#include "../Action.hpp"

class Ace_getAction: public BaseAction
{
public:
  Ace_getAction(BaseCompo* comp);
  std::string Do(const std::string&) override;
  virtual ~Ace_getAction();
};


class Ace_helpAction: public BaseAction
{
public:
  Ace_helpAction();
  std::string Do(const std::string&) override;
  virtual ~Ace_helpAction();
};

