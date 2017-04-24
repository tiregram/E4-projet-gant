#pragma once

#include <ostream>
#include "../Geometry.hpp"

namespace G {
  class XWindow;

  class XGeometry : public G::Geometry
  {
  private:
    int x;
    int y;
    unsigned int width;
    unsigned int height;
    unsigned int border_width;
    unsigned int depth;
    XWindow& window;
  public:
    unsigned int get_depth() const {
      return depth;
    }

    void set_depth(const unsigned int depth) {
      this->depth = depth;
    }

    unsigned int get_border_width() const {
      return border_width;
    }

    void set_border_width(const unsigned int border_width) {
      this->border_width = border_width;
    }

    unsigned int get_height() const override {
      return height;
    }

    void set_height(const unsigned int height) override {
      this->height = height;
    }

    unsigned int get_width() const override {
      return width;
    }

    void set_width(const unsigned int width) override{
      this->width = width;
    }

    int get_y() const override {
      return y;
    }

    void set_y(const int y) override {
      this->y = y;
    }

    int get_x() const override {
      return x;
    }

    void set_x(const int x) {
      this->x = x;
    }

    void update();
    void apply() override;

    void print(std::ostream&) const override;

    XGeometry(XWindow& w);
    virtual ~XGeometry();
  };

}

std::ostream& operator<<(std::ostream& os, const G::XGeometry& c);
