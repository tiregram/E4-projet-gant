#include "BaseCompo.hpp"

BaseCompo::BaseCompo(std::string name):_name(name){}

const std::string BaseCompo::get_name() const
{
  return _name;
}

void BaseCompo::set_name(const std::string _name)
{
  this->_name = _name;
}

BaseCompo::~BaseCompo()
{

}
