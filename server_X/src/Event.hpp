#pragma once

namespace G {

  class Event
  {
  public:
    Event();
    virtual ~Event();



    virtual void mouse_click(unsigned int  ButtonNumber,
                             bool press_or_release ,
                             int x,
                             int y);

    virtual void key_mouvement(unsigned int keycode,
                               bool press_or_release) const;

  };
}
