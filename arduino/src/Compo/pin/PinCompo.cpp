#include "PinCompo.hpp"

#include "PinInitAction.hpp"
#include "PinReadAction.hpp"
#include "PinWriteAction.hpp"

PinCompo::PinCompo():BaseCompo("Pin")
{

}

PinCompo::~PinCompo()
{

}


void  PinCompo::getCommand(std::map<std::string,BaseAction*>& cmds)
{

  PinInitAction* pia = new PinInitAction(this);
  cmds["pininit"]  = pia;
  cmds["pini"]     = pia;
  cmds["pin_i"]    = pia;
  cmds["pin_init"] = pia;

  PinReadAction* pra = new PinReadAction(this);
  cmds["pinread"]  = pra;
  cmds["pinr"]     = pra;
  cmds["pin_r"]    = pra;
  cmds["pin_read"] = pra;

  PinWriteAction* pwa = new PinWriteAction(this);
  cmds["pinwrite"]  = pwa;
  cmds["pin_write"] = pwa;
  cmds["pinw"]      = pwa;
  cmds["pin_w"]     = pwa;
}
