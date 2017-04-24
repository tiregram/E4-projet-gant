#include "XGeometry.hpp"
#include "XDisplay.hpp"
#include "XWindow.hpp"
#include <iostream>
namespace G {

  XGeometry::XGeometry( XWindow& w):Geometry(),window(w) {
    //    this->update();
  }

  XGeometry::~XGeometry() {

  }


  void XGeometry::update() {
    Status st;
    Xlib::Window root_return;
    st = XGetGeometry(this->window.display->xdisplay_natif,
                      this->window.get_window_natif(),
                      &root_return,
                      &this->x,
                      &this->y,
                      &this->width,
                      &this->height,
                      &this->border_width,
                      &this->depth
                      );

    if (st==BadDrawable)
      {
        throw std::logic_error( "Error geometry update"+st );
      }


  }


  void XGeometry::apply()
  {
    Xlib::XWindowChanges wm;
    wm.x = this->x;
    wm.y = this->y;
    wm.width=this->width;
    wm.height=this->height;
    wm.border_width = this->border_width;

    Status st = XConfigureWindow(this->window.display->xdisplay_natif,
                                 this->window.get_window_natif(),
                                 CWX|CWY|CWWidth|CWHeight|CWBorderWidth,
                                 &wm);

     switch (st) {
     case BadMatch:
       throw std::logic_error( "BadMatch:"+st );
       break;
     case BadValue:
       throw std::logic_error( "BadValue:"+st );
       break;
     case BadWindow:
       throw std::logic_error( "BadWindow:"+st );
       break;

     default:
       this->update();
       break;
     }

     this->print(std::cout);
  }

  void XGeometry::print(std::ostream& os) const
  {

    os << "{"
       << "x:" << this->get_x()
       << ",y:" << this->get_y()
       << ",width:" << this->get_width()
       << ",height:" << this->get_height()
       << ",border_width:" << this->get_border_width()
       <<"}";
  }

}
