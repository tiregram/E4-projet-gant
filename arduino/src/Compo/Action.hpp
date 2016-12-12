#pragma once

#include "../nice.inc"

#include "BaseCompo.hpp"

class BaseCompo;

class BaseAction
{

private:
  BaseCompo* comp;

public:
  BaseAction(BaseCompo* comp);
  virtual std::string Do(const std::string&) =0;
  virtual ~BaseAction();
};

