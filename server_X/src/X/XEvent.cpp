
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
Xlib::XKeyEvent G::XEvent::create_key_event(int keycode,
                                            bool press_or_release) const
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
  event.state       = true;

  if(press_or_release)
    event.type = KeyPress;
  else
    event.type = KeyRelease;

  return event;
}

Xlib::XButtonEvent G::XEvent::create_mouse_event(int ButtonNumber,
                                                 bool press_or_release,
                                                 int x,
                                                 int y)
{

  auto& geo =  this->window.get_geo_manager();

  
  Xlib::XButtonEvent event;

  event.display     = this->window.get_display()->xdisplay_natif;
  event.window      = this->window.get_window_natif();
  event.root        = XDefaultRootWindow(event.display);
  event.subwindow   = None;
  event.time        = CurrentTime;
  event.x           = x;
  event.y           = y;
  event.x_root      = geo.get_x()+x;
  event.y_root      = geo.get_y()+y;
  event.same_screen = True;
  event.state       = true;

  if(press_or_release)
    event.type = KeyPress;
  else
    event.type = KeyRelease;

  return event;
}

void G::XEvent::send_event(Xlib::XEvent* event_to_send) const
{

  Status result =  Xlib::XSendEvent(
                                    this->window.get_display()->xdisplay_natif,
                                    this->window.get_window_natif(),
                                    1,
                                    0XFF,
                                    event_to_send);
  if (result == 0)
    {
      throw std::logic_error("error on event: "+result);
    }


}


void G::XEvent::mouse_click(unsigned int  buttonNumber ,bool press_or_release,int x,int y)
{
  Xlib::XButtonEvent event =  this->create_mouse_event(buttonNumber,press_or_release,x,y);
  Xlib::XEvent* ev= (Xlib::XEvent*)  &event;
  this->send_event(ev);

}


void G::XEvent::key_mouvement(unsigned int keycode ,bool press_or_release) const
{
  Xlib::XKeyEvent event =  this->create_key_event(keycode,press_or_release);
  Xlib::XEvent* ev= (Xlib::XEvent*)  &event;
  this->send_event(ev);
}

