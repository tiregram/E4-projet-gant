#pragma once

#include "../BaseAction.hpp"
#include <sstream>
#include <iterator>


class PinReadAction : public BaseAction
{
public:
  PinReadAction(BaseCompo* comp);
  bool Do(const std::string& in) override;
  virtual ~PinReadAction();
};

