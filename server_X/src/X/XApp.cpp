
#include <string>

#include "XApp.hpp"

namespace G {

	XApp::XApp(std::string name) : App(name) {}

	XApp::~XApp() {}

	G::Window* XApp::getWindow(std::string nameOfWindow) const { return NULL; }
}
