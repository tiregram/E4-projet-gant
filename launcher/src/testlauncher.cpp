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
		launcher = std::make_shared<G::Launcher>("localhost", 22, "0");

		std::vector<std::shared_ptr<G::Application>> apps = launcher->get_applications_list();
		// int rc = launcher->shell_session();
		launcher->launch(apps[50]);
		// std::cout << "Return Code From SSH Connection : " << rc << '\n';
	} catch(std::exception err) {
		std::cerr << err.what() << "\n";
	}
}
