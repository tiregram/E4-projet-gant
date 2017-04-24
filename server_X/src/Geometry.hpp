#pragma once

#include <ostream>

namespace G
{
  class Geometry
  {
  public:
    Geometry();
    ~Geometry();

    virtual unsigned int get_height() const= 0 ;
    virtual unsigned int get_width() const= 0 ;
    virtual int get_x() const= 0 ;
    virtual int get_y() const= 0 ;

    virtual void set_height(const unsigned int height)=0;
    virtual void set_width(const unsigned int width)=0;
    virtual void set_x(const int x)=0;
    virtual void set_y(const int y)=0;

    virtual void apply()=0;
    virtual void print(std::ostream&) const  =0;
  };
}

std::ostream& operator<<(std::ostream& os, const G::Geometry* c);
std::ostream& operator<<(std::ostream& os, const G::Geometry& c);
