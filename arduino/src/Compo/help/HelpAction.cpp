
#include "../BaseAction.hpp"
#include "HelpAction.hpp"
#include <Arduino.h>
HelpAction::HelpAction(BaseCompo* comp):BaseAction(comp)
{

}

HelpAction::~HelpAction()
{

}

bool HelpAction::Do(const std::string& in )
{
  Serial.print("NO HELP TODO");

  return true;
}
