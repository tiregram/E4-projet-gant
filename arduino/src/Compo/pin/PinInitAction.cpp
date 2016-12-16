#include <Arduino.h>
#include <pins_arduino.h>

#include "PinInitAction.hpp"

#include <sstream>
#include <iterator>


PinInitAction::PinInitAction(BaseCompo* comp):BaseAction(comp) {

}

PinInitAction::~PinInitAction() {

}


bool PinInitAction::Do(const std::string& in)
{
  std::istringstream buf(in);
  std::istream_iterator<std::string> beg(buf), end;

  ++beg;

  std::string secondWord = *beg;

  auto TypeOfPin = INPUT;

  if("in" == secondWord || "IN" == secondWord)
    {
       TypeOfPin= INPUT;
    }
  else if("out"==secondWord || "OUT"==secondWord)// out
    {
      TypeOfPin = OUTPUT;
    }
  else
    {
      Serial.print("Output Type Are not properly write");
      return false;
    }

  // get char by one
  ++beg;

  for(auto& i = beg; i != end; i++)
    {
      unsigned int pin = atoi((*i).c_str());
      pinMode(pin ,TypeOfPin);
      //Serial.printf("%i open as %s",pin,secondWord.c_str());
  }

  Serial.print( "DONE");
  return true;
}
