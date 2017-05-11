#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <memory>
#include "Launcher.hpp"

int main(int argc, char* argv[]) {

	std::shared_ptr<G::Launcher> launcher;
	try {
		launcher = std::make_shared<G::Launcher>();

		int rc = launcher->show_remote_files();
		// int rc = launcher->shell_session();

		std::cout << "Return Code From SSH Connection : " << rc << '\n';
	} catch(std::exception err) {
		std::cerr << err.what() << "\n";
	}
}
