


#include "XWindow.hpp"
#include "XDisplay.hpp"
#include "XGeometry.hpp"
#include "XEvent.hpp"

#include <ostream>
#include <string>
#include <memory>
#include <iostream>

namespace Xlib {
  extern "C" {

#include <X11/Xlib.h>
#include <X11/Xatom.h>
  }
}

using namespace Xlib;
G::XWindow::XWindow(XDisplay* display, Xlib::Window win):window_natif(win),display(display),geo(*this),event(*this)
{
  this->geo.update();
}

G::Geometry& G::XWindow::get_geo_manager() {
  return this->geo;
}

G::XWindow::~XWindow() {

}

std::string G::XWindow::getName() const {
  return this->getProperties("WM_NAME");
}

unsigned int G::XWindow::getPID() const{
  return 10;
}

unsigned int G::XWindow::getWidth() const{

  return 0;
}

unsigned int G::XWindow::getHeight() const {
  return 0;
}

unsigned int G::XWindow::getX() const{
  return 0;
}

unsigned int G::XWindow::getY() const{
  return 0;
}


unsigned int G::XWindow::getId() const {
  return (unsigned int) this->window_natif;
}

void  G::XWindow::print(std::ostream& os)
{
  os << "{\"XWindows\":"
     << "{\"name\":\"" << this->getName()<<"\""
     << ",\"geometry\":" << this->get_geo_manager()
     << ",\"id:" <<this->getId()
     << " }}";
}

std::ostream& operator<<(std::ostream& os, G::Window* c)
{
  c->print(os);
  return os;
}

std::ostream& operator<<(std::ostream& os, G::Window& c)
{
  c.print(os);
  return os;
}



std::string G::XWindow::getProperties(const std::string& str_NAME) const 
{
  Atom  prop_type, prop, da;
  char *an;
  int di;
  int status;
  unsigned char *prop_ret = NULL;
  unsigned long dl,dl2;

  prop_type = Xlib::XInternAtom(this->display->xdisplay_natif, str_NAME.c_str(), True);

  status = Xlib::XGetWindowProperty(this->display->xdisplay_natif, this->window_natif, prop_type, 0L, sizeof (Xlib::Atom), False,
                                    XA_STRING, &da, &di, &dl, &dl2, &prop_ret);

  if (status == Success && prop_ret )
    {
      // std::cout << "status:" << status
      //           << ", " << da
      //           << ", " << di
      //           << ", " << dl
      //           << ", " << dl2
      //           << ", " << *((long*)prop_ret)
      //           << "\n";
      return std::string((char*)prop_ret);
    }

  return "undef";

}


void G::XWindow::get_screen(uint8_t* data)
{

  auto& gm = this->get_geo_manager();

  Xlib::XColor a ;
  unsigned long plane_mask = 0X00ffffff;

  XImage * img = Xlib::XGetImage(this->get_display()->xdisplay_natif,
                                 this->window_natif,
                                 gm.get_x(),
                                 gm.get_y(),
                                 gm.get_width(),
                                 gm.get_height(),
                                 plane_mask,
                                 ZPixmap);

  for(unsigned int x = 0; x < gm.get_width() ; x++){
    for(unsigned int y = 0; y <gm.get_height() ; y++  ){

      unsigned int pi =  XGetPixel(img, x, y);

      if( this->get_display()->col[pi].i == 0)
        {
          a.pixel = pi;
          Xlib::XQueryColor(this->get_display()->xdisplay_natif,
                            this->get_display()->cmap,
                            &a);



          this->get_display()->col[pi].i = 1;
          this->get_display()->col[pi].r = a.red;
          this->get_display()->col[pi].g = a.green;
          this->get_display()->col[pi].b = a.blue;

          std::cout << "nb:" <<pi  << "\n";
        }

      Mycolor mc  = this->get_display()->col[pi]  ;

      *(data++) =  mc.b;// r
      *(data++) = mc.g;// g
      *(data++) = mc.r;// mc.b;//mc.b; // b
      *(data++) =  0; // a

    }
  }

  Xlib::XFree(img);
}


G::Event& G::XWindow::get_event_manager()
{

  return this->event;;
}
