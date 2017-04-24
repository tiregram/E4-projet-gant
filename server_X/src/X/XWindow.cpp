


#include "XWindow.hpp"
#include "XDisplay.hpp"
#include "XGeometry.hpp"

#include <ostream>
#include <string>
#include <memory>
#include <iostream>

namespace Xlib {
  extern "C" {
#include <X11/X.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
  }
}
using namespace Xlib;
G::XWindow::XWindow(XDisplay* display, Xlib::Window win):window_natif(win),display(display),geo(*this)
{
  this->geo.update();
}

G::Geometry& G::XWindow::get_geo() {
  return this->geo;
}

G::XWindow::~XWindow() {

}

std::string G::XWindow::getName() const {
  std::string b("TODO");

  return b;
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
     << "{\"name\":" << this->getName()<<"\""
     << ",\"geometry\":" << this->get_geo()
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


std::shared_ptr<std::string> G::XWindow::getProperties(const std::string& str_NAME)
{
  Atom  prop_type, prop, da;
  char *an;
  int di;
  int status;
  unsigned char *prop_ret = NULL;
  unsigned long dl,dl2;

  prop_type = Xlib::XInternAtom(this->display->xdisplay_natif, str_NAME.c_str(), True);

  status = Xlib::XGetWindowProperty(this->display->xdisplay_natif, this->window_natif, prop_type, 0L, sizeof (Xlib::Atom), False,
                                    XA_CARDINAL, &da, &di, &dl, &dl2, &prop_ret);

  if (status == Success && prop_ret )
    {
      std::cout << "status:" << status
                << ", " << da
                << ", " << di
                << ", " << dl
                << ", " << dl2
                << ", " << *((long*)prop_ret)
                << "\n";
    }

}

