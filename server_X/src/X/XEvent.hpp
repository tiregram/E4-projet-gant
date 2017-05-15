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



    // xlib create event //////////////////////////////////////////////////////
    Xlib::XKeyEvent createKeyEvent(bool press,
                                   int keycode,
                                   int modifiers) const ;

    Xlib::XButtonEvent createMouseEvent(bool press,
                                        int keycode,
                                        int modifiers) const;


    // event method ///////////////////////////////////////////////////////////
    virtual void key_press(char C) const;
    virtual void key_release(char C) const;

    virtual void mouse_press() const;
    virtual void mouse_release() const;
  };
}
