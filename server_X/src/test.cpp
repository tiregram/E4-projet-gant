#include <string>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include "X/XDisplay.hpp"
#include "X/XWindow.hpp"


int main(int argc, char *argv[])
{

  std::string name = "xvfb";
  std::string addr = ":99";
  std::shared_ptr<G::Display> di;

  try {
    di = std::make_shared<G::XDisplay>(name,addr);

    for (auto a : di->get_windows_list()) {
      std::cout << *a << "\n"
                <<"event... \n";
      a->get_event_manager().key_press('a');
      a->get_event_manager().key_release('a');

      // G::Geometry& g = a->get_geo_manager();
      // g.set_width(100);
      // g.set_height(100);
      // g.apply();

    }
  }
  catch (std::exception err) {
    std::cerr << err.what() << "\n";
  }




}



