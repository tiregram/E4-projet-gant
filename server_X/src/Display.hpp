#ifndef G_LIB_DISPLAY
#define G_LIB_DISPLAY

#include <map>
#include <string>

#include "App.hpp"

namespace G {
  class Window;

  class Display
  {
  private:
    std::string name;
    std::map<std::string,G::App*> listApp;


  public:
    Display(std::string& name);
    virtual ~Display();

    void add_app(G::App& a);
    void add_exist(G::App& a);

  };


}
#endif


