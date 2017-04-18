#ifndef G_LIB_XWINDOW
#define G_LIB_XWINDOW

#include "../Window.hpp"
namespace Xlib {
  extern "C" {
#include <X11/X.h>
#include <X11/Xutil.h>
  }
}


namespace G {

  class XWindow : public G::Window
  {
    Xlib::Window window_natif;

  public:
    XWindow(Xlib::Window win);
    XWindow();
    virtual ~XWindow();
    std::string  getName();
    virtual unsigned int getWidth();
    virtual unsigned int getHeight();
    virtual unsigned int getX();
    virtual unsigned int getY();
  };

}

#endif
