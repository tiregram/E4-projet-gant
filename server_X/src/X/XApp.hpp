#ifndef G_X_APP
#define G_X_APP

#include "../App.hpp"

namespace G {
  class XApp : public App
  {
    
  public:
    XApp(std::string name);
    virtual ~XApp();

    virtual G::Window* getWindow(std::string nameOfWindow)  const;
  };
}

#endif
