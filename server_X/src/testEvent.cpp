
#include <string>
#include <stdlib.h>
#include <iostream>
#include <memory>

#include "X/XDisplay.hpp"
#include "X/XWindow.hpp"


int main(int argc, char *argv[])
{

  std::string name = "xvfb";
  std::string addr = ":0";
  std::shared_ptr<G::Display> di;

  try {
    di = std::make_shared<G::XDisplay>(name,addr);

    for (auto a : di->get_windows_list()) {
      std::cout << *a
                <<"event... \n";

      a->get_event_manager().key_mouvement('a',true);
      a->get_event_manager().key_mouvement('a',false);

      a->get_event_manager().mouse_click(1,true,10,10);
      a->get_event_manager().mouse_click(1,false,10,10);

    }
  }
  catch (std::exception err) {
    std::cerr << err.what() << "\n";
  }
}
