#pragma once

#include <libssh/libssh.h>
#include <vector>
#include <string>

namespace G {

	class Application {
	public:
		std::string name;
		std::string comment;
		std::string exec;

		Application(){

		};
		~Application(){

		};
	};

	class Launcher {
	public:
		Launcher();
		virtual ~Launcher();

		int show_remote_files();
		int shell_session();

		/*
		        void run(std::string cmd);
		        std::vector<std::string> getApplicationsList();
		*/
	private:
		ssh_session session;
		std::vector<ssh_channel> channels;
		std::vector<Application> applications;
	};
}
