
#include <exception>
#include <memory.h>


#include <bitset>
#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>


namespace Xlib {
  extern "C" {
#include <X11/Xlib.h>
#include <X11/Xatom.h>
  }
}

using namespace Xlib;
#include "XDisplay.hpp"

#include "../Display.hpp"
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
          auto xw = std::make_shared<G::XWindow>(this,w);

          /////////////////////////////////////////////////////////////////////
          //                               test                              //
          /////////////////////////////////////////////////////////////////////
          Atom prop_desktop, prop_type, prop, da;
          char *an;
          int di;
          int status;
          unsigned char *prop_ret = NULL;
          unsigned long dl,dl2;

          prop_type = Xlib::XInternAtom(this->xdisplay_natif, "_NET_WM_PID", True);

          status = Xlib::XGetWindowProperty(this->xdisplay_natif, w, prop_type, 0L, sizeof (Atom), False,
                                      XA_CARDINAL, &da, &di, &dl, &dl2, &prop_ret);

          if (status == Success && prop_ret )
            {
            //   std::cout << "status:" << status
            //             << ", " << da
            //             << ", " << di
            //             << ", " << dl
            //             << ", " << dl2
            //             << ", " << *((long*)prop_ret)
            //             << "\n";
            //
            }

          Xlib::XFree(prop_ret);

        }

      Xlib::XFree(data);
    }
    else{
      std::cout <<"no o lapin"  << "\n";
    }

    cmap = DefaultColormap(this->xdisplay_natif,
                           DefaultScreen(this->xdisplay_natif));

  }

  std::vector<std::shared_ptr<G::Window>> XDisplay::get_windows_list()
  {
    std::vector<std::shared_ptr<G::Window>> ret_list;

    Atom a = XInternAtom(this->xdisplay_natif, "_NET_CLIENT_LIST" , true);
    Xlib::Window root = RootWindow(this->xdisplay_natif, DefaultScreen(this->xdisplay_natif));
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
      unsigned long* array = (unsigned long*) data;

      for (unsigned int k = 0; k < numItems; k++)
        {
          Xlib::Window w = (Xlib::Window) array[k];
          auto xw = std::make_shared<G::XWindow>(this,w);
          ret_list.push_back(xw);
        }
      Xlib::XFree(data);
    }
    else{
      std::cout <<"no win"  << "\n";
    }

    return ret_list;
  }

  XDisplay::~XDisplay()
  {
    free(this->col);
    Xlib::XCloseDisplay(this->xdisplay_natif);
  }

}

