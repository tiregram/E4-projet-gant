#pragma once

#include "Comp.hpp"

class Flex : public Comp {
private:
  int pin;
  int value;

public:
  Flex(int pin);
  virtual void update() override;
  virtual ~Flex();
};
