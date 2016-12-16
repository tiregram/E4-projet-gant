#pragma once

#include "../BaseAction.hpp"
#include <sstream>
#include <iterator>


class PinWriteAction : public BaseAction
{
public:
  PinWriteAction(BaseCompo* comp);
  bool Do(const std::string& in) override;
  virtual ~PinWriteAction();
};

