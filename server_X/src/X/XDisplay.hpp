#ifndef G_LIB_XDISPLAY
#define G_LIB_XDISPLAY

#include "../Display.hpp"

namespace G {

  class XDisplay : public Display
  {
  public:
    XDisplay();
    virtual ~XDisplay();
  };

}


#endif
