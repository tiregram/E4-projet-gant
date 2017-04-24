#ifndef G_LIB_DISPLAY
#define G_LIB_DISPLAY

#include <map>
#include <string>
#include <vector>
#include <memory>
#include "App.hpp"

namespace G {
  class Window;

  class Display
  {
  private:
    std::string name;

  public:
    Display(std::string& name);
    virtual ~Display();

    virtual
    std::vector<std::shared_ptr<G::Window>> get_windows_list()=0;
  };


}
#endif


