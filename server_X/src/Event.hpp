#pragma once

namespace G {
  class Event
  {
  public:
    Event();
    virtual ~Event();

    virtual void key_press(char C) const=0;
  };
}
