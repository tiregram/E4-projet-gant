#ifndef G_LIB_XDISPLAY
#define G_LIB_XDISPLAY

#include "../Display.hpp"

#include <string>
#include <cstdint>


namespace Xlib {
  extern "C" {
#include <X11/Xlib.h>
  }
}



typedef struct {
  uint8_t i;
  uint8_t r;
  uint8_t g;
  uint8_t b;
} Mycolor;


namespace G {

  class XDisplay : public G::Display
  {
  private:

    unsigned int  nb;

  public:
    //    Mycolor* col;
    Mycolor* col;

    Xlib::Colormap cmap;

    Xlib::Display* xdisplay_natif;
    XDisplay(std::string& pname, std::string& paddr);
    virtual ~XDisplay();


    std::vector<std::shared_ptr<G::Window>> get_windows_list()    override;

  };

}


#endif
