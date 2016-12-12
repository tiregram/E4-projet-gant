#include "HelpCompo.hpp"
#include "HelpAction.hpp"

HelpCompo::HelpCompo()
  :BaseCompo("Help")
{

}

HelpCompo::~HelpCompo()
{

}


void  HelpCompo::getCommand(std::map<std::string,BaseAction*>& cmds)
{
  cmds["help"] = new HelpAction(this);
}
