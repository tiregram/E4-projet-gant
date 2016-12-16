#include <Arduino.h>
#include <pins_arduino.h>

#include "PinWriteAction.hpp"

#include <sstream>

PinWriteAction::PinWriteAction(BaseCompo* comp):BaseAction(comp) {

}

PinWriteAction::~PinWriteAction() {

}

bool PinWriteAction::Do(const std::string&in)
{
  std::istringstream buf(in);
  std::istream_iterator<std::string> beg(buf), end;
  beg++;
  uint8_t up_or_dow=LOW;

  std::string secondWord = *(beg);

  if (secondWord == "U" ||secondWord == "UP" || secondWord == "1" ||secondWord == "H"||secondWord == "HIGH" )
    {
      up_or_dow = HIGH;
    }
  else   if (secondWord == "D" ||secondWord == "DOWN" || secondWord == "0"|| secondWord == "LOW" || secondWord == "L")
    {
      up_or_dow = LOW;
    }
  else
    {
      Serial.print("Erreur Type");
      return false;
    }

  beg++;

  for(auto i = beg; i != end; i++)
    {
      digitalWrite(atoi((*i).c_str()),up_or_dow);
    }

  Serial.print("DONE");

  return true;

}
