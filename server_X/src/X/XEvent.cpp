
#include "XEvent.hpp"

#include <stdlib.h>
#include <iostream>

#include "XDisplay.hpp"
#include "XWindow.hpp"


G::XEvent::XEvent(XWindow& w):Event(),window(w) {

}

G::XEvent::~XEvent() {

  
}

// Function to create a keyboard event
Xlib::XKeyEvent G::XEvent::createKeyEvent(bool press,
                                          int keycode,
                                          int modifiers) const
{
  Xlib::XKeyEvent event;

  event.display     = this->window.get_display()->xdisplay_natif;
  event.window      = this->window.get_window_natif();
  event.root        = XDefaultRootWindow(event.display);
  event.subwindow   = None;
  event.time        = CurrentTime;
  event.x           = 1;
  event.y           = 1;
  event.x_root      = 1;
  event.y_root      = 1;
  event.same_screen = True;
  event.keycode     = XKeysymToKeycode(event.display, keycode);
  event.state       = modifiers;

  if(press)
    event.type = KeyPress;
  else
    event.type = KeyRelease;

  return event;
}


// Function to create a keyboard event
Xlib::XButtonEvent G::XEvent::createMouseEvent(bool press,
                                             int keycode,
                                             int modifiers) const
{
  Xlib::XButtonEvent event;

  event.display     = this->window.get_display()->xdisplay_natif;
  event.window      = this->window.get_window_natif();
  event.root        = XDefaultRootWindow(event.display);
  event.subwindow   = None;
  event.time        = CurrentTime;
  event.x           = 1;
  event.y           = 1;
  event.x_root      = 1;
  event.y_root      = 1;
  event.same_screen = True;

  event.state       = modifiers;

  if(press)
    event.type = KeyPress;
  else
    event.type = KeyRelease;

  return event;
}

void G::XEvent::mouse_press() const
{

}

void G::XEvent::mouse_release() const
{

}


void G::XEvent::key_release(char C) const
{
  //  std::cout << "key event send"  << "\n";

  int propagate =  true;
  long event_mask = KeyPressMask;

  auto  event_send = createKeyEvent(false,KEYCODE,0);

  Status result =  Xlib::XSendEvent(
                                    this->window.get_display()->xdisplay_natif,
                                    this->window.get_window_natif(),
                                    propagate,
                                    event_mask,
                                    (Xlib::XEvent*)&event_send);
  if (result == 0)
    {
      throw std::logic_error("error on event: "+result);
    }

}

void  G::XEvent::key_press(char C) const {
  //  std::cout << "key event send"  << "\n";

  int propagate =  true;
  long event_mask = KeyPressMask;

  auto  event_send = createKeyEvent(true,KEYCODE,0);

  Status result =  Xlib::XSendEvent(
                                    this->window.get_display()->xdisplay_natif,
                                    this->window.get_window_natif(),
                                    propagate,
                                    event_mask,
                                    (Xlib::XEvent*)&event_send);
  if (result == 0)
    {
      throw std::logic_error("error on event: "+result);
    }
}
