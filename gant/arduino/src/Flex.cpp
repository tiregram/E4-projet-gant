#include "Flex.hpp"

#include <Arduino.h>
#include <HardwareSerial.h>
#include <pins_arduino.h>

Flex::Flex(int pin) : pin(pin), value(0) {}

Flex::~Flex() {}

void Flex::update() {
  this->value = analogRead(this->pin);

  Serial.print("f\t");
  Serial.print(this->pin);
  Serial.print("\t");
  Serial.println(this->value);
}
