#ifndef G_LIB_XWINDOW
#define G_LIB_XWINDOW

namespace Xlib {
  extern "C" {
#include <X11/X.h>
#include <X11/Xutil.h>
  }
}

#include "../Window.hpp"

namespace G {

  class XWindow : public Window
  {
    double xyz[3];
    Xlib::Window window_natif;
  public:

    XWindow(Xlib::Window win);
    XWindow();
    virtual ~XWindow();

  };

}

#endif
