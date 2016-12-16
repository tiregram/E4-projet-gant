#include "nice.inc"

#include <Arduino.h>
#include <pins_arduino.h>
#include <HardwareSerial.h>

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

#include "Compo/BaseCompo.hpp"
#include "Compo/BaseAction.hpp"

#include "Compo/acelero/AceleroCompo.hpp"
#include "Compo/pin/PinCompo.hpp"
#include "Compo/help/HelpCompo.hpp"
#include "Compo/pin/PinInitAction.hpp"
#include <algorithm>

#define DEBUG

AceleroCompo* ac;

std::map<std::string,BaseAction*> t;


std::vector<std::string> getWordList(std::string str )
{
  std::istringstream buf(str);
  std::istream_iterator<std::string> beg(buf), end;

  std::vector<std::string> tokens(beg, end);

  return tokens;
}


void setup() {

  Serial.begin(9600);
  
  
#ifdef DEBUG
  Serial.println("!!!INIT!!!");
#endif

  HelpCompo* hc = new HelpCompo();
  hc->getCommand(t);

  PinCompo* pc = new PinCompo();
  pc->getCommand(t);

  ac = new AceleroCompo();
  ac->getCommand(t);

}

std::string command;

void loop() {
  Serial.println("lapin");
  ac->update();
  return;

  char charSend;
  command = "";
#ifdef DEBUG
  Serial.println();
  Serial.print(">>>");
#endif

  charSend = ' ';

  do{
    if(Serial.available()){
      charSend = Serial.read();
      
#ifdef DEBUG
      if(charSend != 13)
        Serial.write((int)charSend);

#endif
      command += charSend;
    }

  }
  while(charSend != 13);

  // first word of the comma
  size_t min1 = command.find(" ");
  size_t min2 = command.find("\r");
  Serial.print(min2);
  if (min1 == std::string::npos && min2 ==0)
    {
      Serial.printf("{result:\"No input\",sucess:False}");

      return;
    }

  size_t realmin = min( min1 , min2 );

  std::string firstword = command.substr(0,realmin);

#ifdef DEBUG
  Serial.print("cmd:");
  Serial.println(command.c_str());
  Serial.print("fw:");
  Serial.println(firstword.c_str());
  Serial.print("sizefw:");
  Serial.println(firstword.length());
#endif

  auto is_in = t.find(firstword);

  if(is_in == t.end()){
    Serial.println("{result\"Not a Valid Command\",sucess:False}");
    return;
  }


  bool sucess ;
  Serial.print("{result:");
  sucess = is_in->second->Do(command);
  Serial.printf(",sucess:%s}", (sucess)?"True":"False");


}

