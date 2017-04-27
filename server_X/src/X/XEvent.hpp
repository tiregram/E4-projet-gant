#pragma once

#include "../Event.hpp"

namespace G{
  class XEvent : public G::Event
  {

  public:
    XEvent();
    virtual ~XEvent();

    void key_press(char C) const override;
  };
}
