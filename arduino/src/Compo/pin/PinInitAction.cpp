#include <Arduino.h>
#include <pins_arduino.h>

#include "PinInitAction.hpp"

#include <sstream>
#include <iterator>


PinInitAction::PinInitAction(BaseCompo* comp):BaseAction(comp) {

}

PinInitAction::~PinInitAction() {

}


std::string PinInitAction::Do(const std::string& a)
{
  std::istringstream buf(a);
  std::istream_iterator<std::string> beg(buf), end;

  ++beg;

  std::string secondWord = *beg;

  auto TypeOfPin = INPUT;

  if("in" == secondWord)
    {
       TypeOfPin= INPUT;
    }
  else if("out"==secondWord)// out
    {
      TypeOfPin = OUTPUT;
    }

  // get char by one
  ++beg;

  for(auto& i = beg; i != end; i++){

    pinMode(atoi((*i).c_str()),TypeOfPin);

  }

  return "Done";
}
