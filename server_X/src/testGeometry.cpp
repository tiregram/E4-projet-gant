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
    int XX =0;
    for (auto a : di->get_windows_list()) {

      G::Geometry& g = a->get_geo_manager();
      g.set_x(XX);
      g.set_width(100);
      g.set_height(100);
      g.apply();

      XX+= 100;
    }
  }
  catch (std::exception err) {
    std::cerr << err.what() << "\n";
  }




}



