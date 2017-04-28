#pragma once

#include "../Event.hpp"

namespace G{
  class XWindow;

  class XEvent : public G::Event
  {
  private:

    XWindow& window;

  public:
    XEvent(XWindow&);
    virtual ~XEvent();

    void key_press(char C) const override;
  };
}
