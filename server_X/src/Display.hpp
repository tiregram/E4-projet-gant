#ifndef G_LIB_DISPLAY
#define G_LIB_DISPLAY

#include <string>
#include <vector>
#include <memory>


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


