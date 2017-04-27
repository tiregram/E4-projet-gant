#ifndef G_LIB_WINDOW
#define G_LIB_WINDOW

#include <string>

namespace G {

  class Geometry;
  class Event;
  
  class Window
  {
    double xyz[3];

  public:
    Window();
    virtual ~Window();
    virtual std::string  getName() const= 0;
    virtual G::Geometry& get_geo_manager() = 0;
    virtual G::Event& get_event_manager() = 0;
    virtual void print(std::ostream&) =0;
  };
}


std::ostream& operator<<(std::ostream& os, G::Window& c);
std::ostream& operator<<(std::ostream& os,  G::Window* c);

#endif
