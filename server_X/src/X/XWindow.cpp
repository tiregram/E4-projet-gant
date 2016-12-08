
namespace Xlib {
  extern "C" {
#include <X11/X.h>
#include <X11/Xutil.h>
  }
}

#include "XWindow.hpp"

G::XWindow::XWindow(Xlib::Window win)
{
  this->window_natif = win;
  
}

G::XWindow::XWindow()
{

}

G::XWindow::~XWindow() {

}


