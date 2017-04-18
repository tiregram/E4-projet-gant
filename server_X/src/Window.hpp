#ifndef G_LIB_WINDOW
#define G_LIB_WINDOW

#include <string>

namespace G {
  class Window
  {
    double xyz[3];
  public:
    Window();
    virtual ~Window();
    virtual std::string  getName()= 0 ;
    virtual unsigned int getWidth()= 0 ;
    virtual unsigned int getHeight()= 0 ;
    virtual unsigned int getX()= 0 ;
    virtual unsigned int getY()= 0 ;

  };

}

#endif
