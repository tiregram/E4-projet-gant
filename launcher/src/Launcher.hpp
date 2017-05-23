#pragma once

#include <libssh/libssh.h>
#include <vector>
#include <string>
#include <memory>

#include "Application.hpp"

namespace G {

	class Launcher {
	public:
		Launcher(const void* host, int port, std::string display);
		virtual ~Launcher();

		std::vector<std::shared_ptr<Application>> get_applications_list();

		int launch(std::shared_ptr<Application> app);

	private:
		int compute_application_list();

		// SSH

		ssh_session session;
		std::vector<ssh_channel> channels;
		std::vector<std::shared_ptr<Application>> applications;

		// Host Informations
		const void* host;
		std::string display;
		int port;
	};
}
