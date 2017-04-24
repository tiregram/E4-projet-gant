#ifndef G_LIB_XDISPLAY
#define G_LIB_XDISPLAY

#include "../Display.hpp"

#include <string>

extern "C" {
#include <SDL/SDL.h>
}

namespace Xlib {
  extern "C" {
#include <X11/Xlib.h>
  }
}



typedef struct {
  Uint8 i;
  Uint8 r;
  Uint8 g;
  Uint8 b;
} Mycolor;


namespace G {

  class XDisplay : public G::Display
  {
  private:
    Xlib::Window * children_return;
    unsigned int  nb;
    Mycolor* col;
    Xlib::Colormap cmap;



  public:
    Xlib::Display* xdisplay_natif;
    XDisplay(std::string& pname, std::string& paddr);
    virtual ~XDisplay();


    std::vector<std::shared_ptr<G::Window>> get_windows_list()    override;

  };

}


#endif
