#ifndef G_LIB_DISPLAY
#define G_LIB_DISPLAY

#include <map>
#include <string>

#include "App.hpp"

namespace G {

class Display
{
public:
  std::string name;
  std::map<std::string,G::App*> listApp;

public:
  Display(std::string& name);
  virtual ~Display();
  

};


}
#endif


