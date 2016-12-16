#include <Arduino.h>
#include <pins_arduino.h>

#include "PinReadAction.hpp"

#include <sstream>

PinReadAction::PinReadAction(BaseCompo* comp):BaseAction(comp) {

}

PinReadAction::~PinReadAction() {

}

bool PinReadAction::Do(const std::string&in)
{
  std::istringstream buf(in);
  std::istream_iterator<std::string> beg(buf),end;
  beg++; //escape first word

  Serial.print("{");

  for(auto i = beg; i != end; i++)
    {
      Serial.printf("\"%s\":%i",(*i).c_str(),digitalRead(atoi((*i).c_str())));
    }

  Serial.print("}");

  return true;

}
