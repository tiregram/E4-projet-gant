#ifndef G_LIB_APP
#define G_LIB_APP

#include <vector>
#include "Window.hpp"
#include <string>

namespace G {

  class App
  {
  private:
    std::vector<G::Window*> listWindows;

  public:
    App(std::string name);
    virtual ~App();

    virtual G::Window* getWindow(std::string nameOfWindow) const = 0;
  };
}

#endif
