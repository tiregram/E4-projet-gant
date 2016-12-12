#include "PinCompo.hpp"
#include "PinInitAction.hpp"

PinCompo::PinCompo():BaseCompo("Pin")
{

}

PinCompo::~PinCompo()
{

}


void  PinCompo::getCommand(std::map<std::string,BaseAction*>& cmds)
{
  cmds["pinInit"] = new PinInitAction(this);
}
