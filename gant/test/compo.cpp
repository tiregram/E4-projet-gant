#include "../src/Compo/BaseCompo.hpp"
#include <iostream>
int main(int argc, char *argv[])
{

  std::map<std::string,BaseCompo*> Compo;

  HelpCompo* hl = new  HelpCompo();
  Compo[hl->get__name()] = hl;



  std::string rep;

  do{

    
    std::getline(std::cin,rep);
  }
  while(rep!="y");

  return 0;
}

