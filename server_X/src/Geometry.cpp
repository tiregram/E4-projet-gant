#include "Geometry.hpp"

G::Geometry::Geometry()
{

}

G::Geometry::~Geometry()
{

}


std::ostream& operator<<(std::ostream& os, const G::Geometry& c)
{
  c.print(os) ;
  return os;
}

std::ostream& operator<<(std::ostream& os, const G::Geometry* c)
{
  c->print(os) ;
  return os;
}
