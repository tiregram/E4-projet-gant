#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <memory>
#include "X/XDisplay.hpp"
#include "X/XWindow.hpp"

#include <ctime>

int main(int argc, char* argv[]) {

	std::string name = "xvfb";
	std::string addr = ":99";
	std::shared_ptr<G::Display> di;
  uint8_t data[100*100*4];

	try {
	    di = std::make_shared<G::XDisplay>(name, addr);

	    for(auto a : di->get_windows_list()) {
        clock_t begin = std::clock();

        a->get_screen(data);

        clock_t end = std::clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        std::cout <<"time: "<<elapsed_secs << " s"  << "\n";

	    }

	} catch(std::exception err) {
	    std::cerr << err.what() << "\n";
	}
}
