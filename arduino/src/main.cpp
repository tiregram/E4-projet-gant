#include "nice.inc"

#include <Arduino.h>
#include <pins_arduino.h>
#include <HardwareSerial.h>

#include "Compo/BaseCompo.hpp"
#include "Compo/HelpCompo.hpp"
#include "Compo/Action.hpp"
#include "Compo/acelero/AceleroCompo.hpp"

//#define DEBUG

std::map<std::string,BaseAction*> t;

void setup() {

  Serial.begin(9600);

#ifdef DEBUG
  Serial.println("!!!INIT!!!");
#endif

  HelpCompo* hc = new HelpCompo();
  hc->getCommand(t);


  AceleroCompo* ac = new AceleroCompo();
  ac->getCommand(t);

}

std::string command;

void loop() {
  char charSend;
  command = "";
#ifdef DEBUG
  Serial.print("\n>>>");
#endif
  charSend = ' ';
  do{
    if(Serial.available()){
      charSend = Serial.read();

#ifdef DEBUG
      Serial.write(charSend);
#endif

      command += charSend;
    }

  }
  while(charSend != 13);

  // first word of the command
  std::string firstword = command.substr(0,command.find(" "));

#ifdef DEBUG
  Serial.print("cmd:");
  Serial.println(command.c_str());
  Serial.print("fw:");
  Serial.println(firstword.c_str());
#endif

  auto is_in = t.find(firstword);

  if(is_in == t.end()){
    Serial.println("{sucess:False}");
    return;
  }

  std::string result= is_in->second->Do(firstword);

  Serial.printf("{sucess:True,result:%s}",result.c_str());


}

