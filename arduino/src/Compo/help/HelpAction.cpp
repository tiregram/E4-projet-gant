
#include "../Action.hpp"
#include "HelpAction.hpp"

HelpAction::HelpAction(BaseCompo* comp)
  : BaseAction(comp)
{

}

std::string HelpAction::Do(const std::string& a)
{
  std::string b = "lapin";
  return b;
}

HelpAction::~HelpAction()
{

}
