#pragma once

#include <string>

namespace G {

	class Application {

	public:
		Application();
		~Application();

		std::string get_name();
		std::string get_comment();
		std::string get_exec();
		void set_name(std::string name);
		void set_comment(std::string comment);
		void set_exec(std::string exec);

	private:
		std::string name;
		std::string comment;
		std::string exec;
	};
}
