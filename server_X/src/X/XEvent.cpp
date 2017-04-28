#include "XEvent.hpp"
#include "XWindow.hpp"
#include "XDisplay.hpp"
#include <iostream>

namespace Xlib {
  extern "C" {
#include <X11/X.h>
#include <X11/Xutil.h>
  }
}

G::XEvent::XEvent(XWindow& w):Event(),window(w) {

}

G::XEvent::~XEvent() {

}

void  G::XEvent::key_press(char C) const {
  std::cout << "key event send"  << "\n";

  int propagate =  true;
  long event_mask = KeyPressMask;

  Xlib::XEvent event_send;
  Xlib::XKeyPressedEvent *a;
  a = &event_send.xkey;


  Status result =  Xlib::XSendEvent(
                                    this->window.get_display()->xdisplay_natif,
                                    this->window.get_window_natif(),
                                    propagate,
                                    event_mask,
                                    &event_send);

  
}
