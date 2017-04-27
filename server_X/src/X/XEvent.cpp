#include "XEvent.hpp"
#include <iostream>

G::XEvent::XEvent():Event() {

}

G::XEvent::~XEvent() {

}

void  G::XEvent::key_press(char C) const {
  std::cout << "key event send"  << "\n";
}
