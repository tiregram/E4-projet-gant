#ifndef G_LIB_XWINDOW
#define G_LIB_XWINDOW

#include "../Window.hpp"

namespace G {
  class XWindow : public Window
  {
    double xyz[3];
  public:
    XWindow();
    virtual ~XWindow();
  };

}

#endif
