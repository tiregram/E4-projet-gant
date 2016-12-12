#pragma once

#include "../nice.inc"

#include "BaseCompo.hpp"

class BaseCompo;

class BaseAction
{



public:
  BaseCompo* comp;
  BaseAction(BaseCompo* comp);
  virtual std::string Do(const std::string&) =0;
  virtual ~BaseAction();
};

