
extern "C" {
#include <SDL/SDL.h>
}

#include <exception>
	
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
    // TODO: gestion propre des couleurs
    this->col = (Mycolor*) malloc(sizeof(Mycolor)*1000);

    ///////////////////////////////////////////////////////////////////////////
    //                 open the connection with the X server                 //
    ///////////////////////////////////////////////////////////////////////////
    this->xdisplay_natif = Xlib::XOpenDisplay(paddr.c_str());

    if (this->xdisplay_natif == NULL)
      {
        std::cerr <<"Impossible d'ouvrir le Display"  << "\n";
        throw  std::runtime_error( "Erreur: Pas de display avec " + pname + " et addr :" + paddr);
      }

    for (int i = 0; i < 5; i++) {
      
    }

    ///////////////////////////////////////////////////////////////////////////
    //                      recuperation of the windows root                 //
    ///////////////////////////////////////////////////////////////////////////
    Xlib::Window root = RootWindow(this->xdisplay_natif, DefaultScreen(this->xdisplay_natif));

    Atom a = XInternAtom(this->xdisplay_natif, "_NET_CLIENT_LIST" , true);
    Atom actualType;
    int format;
    unsigned long numItems, bytesAfter;
    unsigned char *data =0;
    int status = XGetWindowProperty(this->xdisplay_natif,
                                    root,
                                    a,
                                    0L,
                                    (~0L),
                                    false,
                                    AnyPropertyType,
                                    &actualType,
                                    &format,
                                    &numItems,
                                    &bytesAfter,
                                    &data);

    if (status >= Success && numItems)
    {
        // success - we have data: Format should always be 32:
        //Q_ASSERT(format == 32);
        // cast to proper format, and iterate through values:
      unsigned long* array = (unsigned long*) data;

      for (unsigned int k = 0; k < numItems; k++)
        {
            // get window Id:
          Xlib::Window w = (Xlib::Window) array[k];

          std::cout << "window: " << w  << "\n";
        }
      Xlib::XFree(data);
    }
    else{
      std::cout <<"no o lapin"  << "\n";

    }
  }

  XDisplay::~XDisplay()
  {
    Xlib::XCloseDisplay(this->xdisplay_natif);
  }


}

