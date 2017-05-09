#pragma once

namespace G {

  class Event
  {
  public:
    Event();
    virtual ~Event();

    virtual void key_press(char C) const=0;
    virtual void key_release(char C) const=0;

    virtual void mouse_press() const=0;
    virtual void mouse_release() const=0;
  };
}
