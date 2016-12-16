#pragma once

#include "../nice.inc"

#include "BaseCompo.hpp"

class BaseCompo;

class BaseAction
{

public:
  BaseCompo* comp;
  BaseAction(BaseCompo* comp);
  virtual bool Do(const std::string&in) =0;
  virtual ~BaseAction();
};

