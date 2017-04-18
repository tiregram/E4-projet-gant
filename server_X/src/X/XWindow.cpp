


#include "XWindow.hpp"

G::XWindow::XWindow(Xlib::Window win):window_natif(win)
{

}

G::XWindow::XWindow()
{

}

G::XWindow::~XWindow() {

}

std::string G::XWindow::getName() {
  std::string b;

  return b;
}

unsigned int G::XWindow::getWidth() {
  return 0;
}

unsigned int G::XWindow::getHeight() {
  return 0;
}

unsigned int G::XWindow::getX() {
  return 0;
}

unsigned int G::XWindow::getY() {
  return 0;
}
