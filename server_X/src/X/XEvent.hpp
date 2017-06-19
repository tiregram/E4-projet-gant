#pragma once

#include "../Event.hpp"
#include <cstdlib>

namespace Xlib {
  extern "C" {
#include <X11/Xlib.h>
#include <X11/keysym.h>
#define KEYCODE XK_Down
  }
}

namespace G{
  class XWindow;

  class XEvent : public ::G::Event
  {
  private:

    XWindow& window;

  public:
    XEvent(XWindow&);
    virtual ~XEvent();


    Xlib::XKeyEvent create_key_event(int keycode,
                                   bool press_or_release) const ;

    Xlib::XButtonEvent create_mouse_event(
                                          int keycode,
                                          bool press_or_release,
                                          int x,
                                          int y);


    void  send_event(Xlib::XEvent* event_to_send) const;

    void key_mouvement(unsigned int keycode,
                       bool press_or_release) const override;

    void mouse_click(unsigned int  ButtonNumber,
                     bool press_or_release ,
                     int x,
                     int y) override;
  };
}
