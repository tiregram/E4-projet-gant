
#include "../BaseAction.hpp"
#include "HelpAction.hpp"

HelpAction::HelpAction(BaseCompo* comp):BaseAction(comp)
{

}

HelpAction::~HelpAction()
{

}

std::string HelpAction::Do(const std::string& a)
{
  std::string b = "lapin";
  return b;
}
