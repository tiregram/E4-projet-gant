#include "Ace.hpp"
#include "Flex.hpp"
#include "Comp.hpp"
#include "nice.inc"
#include <Arduino.h>
#include <HardwareSerial.h>
#include <pins_arduino.h>
#define DEBUG

std::vector<Comp *> comps;

void waitForResponse() {
  delay(1000);
  while (Serial.available()) {
    Serial.write(Serial.read());
  }
  Serial.write("\n");
}

void setup() {

  Serial.begin(9600);

  Serial.print("AT\r\n");
  waitForResponse();

  //  //Serial.println("AT+NAME:GLOVE");
  Serial.println("AT+UART=115200,1,0");
  waitForResponse();

  //  Serial.begin(115200);
  //Serial.println("INIT");

  comps.push_back(new Ace());
  comps.push_back(new Flex(1));
  comps.push_back(new Flex(2));
  comps.push_back(new Flex(3));

}

void loop() {

  for (auto comp : comps) {
    comp->update();
  }

  delay(1000/60);

}

#include "nice.inc"
void *operator new(size_t size_, void *ptr_) { return ptr_; }
