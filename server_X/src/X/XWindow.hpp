#ifndef G_LIB_XWINDOW
#define G_LIB_XWINDOW
#include <memory>
#include "../Window.hpp"

#include "XGeometry.hpp"
#include "XEvent.hpp"

namespace Xlib {
  extern "C" {
#include <X11/X.h>
#include <X11/Xutil.h>
  }
}


namespace G {

  class XDisplay;
  class Geometry;
  class XGeometry;
  class Event;
  class XEvent;


  class XWindow : public G::Window
  {
    Xlib::Window window_natif;

  public:
    G::XGeometry geo;
    G::XEvent event;

    const Xlib::Window get_window_natif() const {
      return window_natif;
    }

    void set_window_natif(const Xlib::Window window_natif) {
      this->window_natif = window_natif;
    }

    G::Geometry& get_geo_manager() override;
    G::Event& get_event_manager() override;

    XDisplay* display;
    XWindow(XDisplay* display,Xlib::Window win);

    virtual ~XWindow();

    std::string  getName() const;

    virtual unsigned int getWidth() const;
    virtual unsigned int getHeight() const;
    virtual unsigned int getX() const;
    virtual unsigned int getY() const;

    void print(std::ostream&)   override;

    unsigned int getId() const;
    unsigned int getPID() const;

    std::string getProperties(const std::string& str_NAME) const;
  };

}

#endif