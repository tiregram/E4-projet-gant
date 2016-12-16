#pragma once

#include "../nice.inc"
#include "BaseAction.hpp"

class BaseAction;

using ListCommand = std::map<std::string,BaseAction*>;

class BaseCompo
{
private:
  std::string _name;

public:

  virtual const std::string get_name() const;

  virtual void set_name(const std::string _name);

  BaseCompo(std::string name);

  virtual std::string getHelp(std::string str)
  {
    return "Help Is Undefined";
  }

  virtual void  getCommand(std::map<std::string,BaseAction*>& cmds)=0;
  virtual ~BaseCompo();
};


