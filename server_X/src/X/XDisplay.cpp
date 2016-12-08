
extern "C" {
#include <SDL/SDL.h>
}

namespace Xlib {
  extern "C" {
#include <X11/X.h>
#include <X11/Xutil.h>
  }
}

extern void paint(SDL_Surface *surface, int x, int y, Uint8 red, Uint8 green, Uint8 blue);


using namespace Xlib;
#include <bitset>
#include <iostream>
#include <cstdlib>

#include "../Display.hpp"
#include "XApp.hpp"
#include "XDisplay.hpp"
#include "XWindow.hpp"

namespace G {

  XDisplay::XDisplay(std::string& pname, std::string& paddr)
    :Display(pname)
  {
    this->col = (Mycolor*) malloc(sizeof(Mycolor)*1000);


    this->xdisplay_natif = Xlib::XOpenDisplay(paddr.c_str());
    if (this->xdisplay_natif == NULL)
      {
        std::cerr <<"Impossible d'ouvrir le Display"  << "\n";
        throw std::logic_error( "exception de test" );
      }

    Xlib::Window rr;
    Xlib::Window ra;

    Xlib::Window *  root_return   = &rr;
    Xlib::Window *  parent_return = &ra;



    Xlib::Window root = RootWindow(this->xdisplay_natif, DefaultScreen(this->xdisplay_natif));

    Status status = Xlib::XQueryTree(this->xdisplay_natif,
                                     root,
                                     &rr,
                                     &ra,
                                     &children_return,
                                     &nb);

    cmap = DefaultColormap(this->xdisplay_natif,
                           DefaultScreen(this->xdisplay_natif));

    // TODO: test status
    Xlib::XTextProperty text_prop_return;
    char ** a;

    int b;
    for(unsigned int i = 0; i < nb; i++)
      {

        // Status stat =  XGetWMName(this->xdisplay_natif, children_return[i], &text_prop_return);
        // std::cout << "WMname"<< text_prop_return.value  << "\n";
        // stat =  Xlib::XGetCommand(this->xdisplay_natif, children_return[i],&a ,&b );
        // std::cout << "cmd" << a[0]  << "\n";
        // Xlib::XClassHint obj;
        // stat = Xlib::XGetClassHint(this->xdisplay_natif, children_return[i], &obj);

        /*        std::cout
          << obj.res_name
          << "|"
          << obj.res_class
          << "\n" ;*/

        //        auto name_app = std::string(obj.res_class);

        //auto have_appli = this->listApp.find(std::string(obj.res_class));

        /*        if (have_appli == this->listApp.end())
          {
            this->listApp[name_app] = new XApp(name_app);

          }

        this->listApp[name_app] = new XApp(name_app);

        Xlib::Window root;
        int x, y;
        unsigned int d,sb;

        unsigned int width,height;
        stat =  Xlib::XGetGeometry(this->xdisplay_natif,
                                   children_return[i],
                                   &root,
                                   &x,&y, &width, &height, &sb, &d);

        unsigned long plane_mask = 0XFFFFFFFF;
        unsigned format = ZPixmap;

        XWindow* w = new XWindow(children_return[i]);

        std::cout <<"x"<< x <<" y"<<y<<" w"<<width<<" h"<<height<< "\n";

                                                                   XImage * img = Xlib::XGetImage(this->xdisplay_natif ,
                                 children_return[i],
                                 x,
                                 y,
                                 width,
                                 height,
                                 plane_mask,
                                 format);
        */

        //                                                         delete w;
      }

  }

  XDisplay::~XDisplay()
  {
    Xlib::XCloseDisplay(this->xdisplay_natif);
  }





void   XDisplay::draw(SDL_Surface *surface,int id)
  {

    Xlib::XColor a ;

    int i=id;
    Status stat;
    Xlib::Window root;
    int x, y;
    unsigned int d,sb;

    unsigned int width,height;
    stat =  Xlib::XGetGeometry(this->xdisplay_natif,
                               children_return[i],
                               &root,
                               &x,&y, &width, &height, &sb, &d);
    std::cout << "d" << d <<" sb" << sb << "\n";

    unsigned long plane_mask = 0Xffffffff;
    unsigned format = XYPixmap;

    XWindow* w = new XWindow(children_return[i]);
    clock_t start, finish;
    double duration;

    while(1){
      start = clock();
      XImage * img = Xlib::XGetImage(this->xdisplay_natif ,
                                   children_return[i],
                                   x,
                                   y,
                                   width,
                                   height,
                                   plane_mask,
                                   ZPixmap);

    for(unsigned int x = 0; x < width ; x++)
      for(unsigned int y = 0; y < height ; y++  )
        {

          unsigned int pi =  XGetPixel(img, x, y);

          if( this->col[pi].i == 0)
            {
              a.pixel = pi;
              Xlib::XQueryColor(this->xdisplay_natif,
                                cmap,
                                &a);
              this->col[pi].i = 1;
              this->col[pi].r = a.red;
              this->col[pi].g = a.green;
              this->col[pi].b = a.blue;
              std::cout << "nb:" <<pi  << "\n";
            }

          Mycolor mc  = this->col[pi]  ;


          /*
          std::cout
            <<"r" << std::bitset<8>(a.red)
            <<" g"<< std::bitset<8>(a.green)
            <<" b"<< std::bitset<8>(a.blue) <<"\n";
          */

          paint(surface,
                x, y,
                mc.r, mc.g, mc.b);
        }
    Xlib::XFree(img);
    SDL_UpdateRect(surface, 0, 0, width, height);

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f FPS\n", 1/duration );


  }
  }



}

