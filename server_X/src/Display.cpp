#include <iostream>

#include "Display.hpp"


namespace G {
  Display::Display(std::string& pname):name(pname)
  {
    std::cout << "Création de " << this->name   << "\n";

  }

  Display::~Display() {
    std::cout << "Destruction de " << this->name   << "\n";
  }
}
